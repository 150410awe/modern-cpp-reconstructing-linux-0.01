#pragma once

#include "type.h"
#include "file/file_kernel_type.h"

struct executable_header {
    executable_file_type file_type;    /* 标识文件类型 */
    size_t code_size;          /* 代码段长度（字节） */
    size_t data_size;          /* 数据段长度（字节） */
    size_t uninitialized_data_size;           /* 未初始化数据段长度（字节） */
    size_t syms_size;          /* 符号表数据长度（字节） */
    uint64_t entry_address;         /* 程序入口地址 */
    uint64_t code_relocation_size;        /* 代码段重定位信息长度 */
    uint64_t data_relocation_size;        /* 数据段重定位信息长度 */
};

#if 0
我觉得完全没必要,这种设备还能运行吗？还能支持这种设备的操作系统吗？我是不知道,所以我不支持
#if defined(vax) || defined(hp300) || defined(pyr)
constexpr size_t SEGMENT_SIZE = PAGE_SIZE;
#endif
#ifdef	hp300
constexpr size_t PAGE_SIZE = 4096;
#endif
#ifdef	sony
constexpr size_t SEGMENT_SIZE = 0x2000;
#endif	/* Sony.  */
#ifdef is68k
constexpr size_t SEGMENT_SIZE = 0x20000;
#endif
#if defined(m68k) && defined(PORTAR)
constexpr size_t PAGE_SIZE = 0x400;
constexpr size_t SEGMENT_SIZE = PAGE_SIZE;
#endif
#endif

/*
 * PAGE_SIZE - 页面大小（Page Size）
 * @note 表示内存分页的大小，通常为 4096 字节
*/
constexpr size_t PAGE_SIZE = 4096;
/*
 * SEGMENT_SIZE - 段大小（Segment Size）
 * @note 表示内存分页的大小，通常为 1024 字节
*/
constexpr size_t SEGMENT_SIZE = 1024;
/*
 * code_initial_address - 代码段初始地址（Code Initial Address）
 * @note 表示代码段在内存中的初始地址，通常为 0
*/
constexpr address_t code_initial_address = 0;

/*
 * ZMAGIC_computation - ZMAGIC 计算（ZMAGIC Computation）
 * @note 计算 ZMAGIC 类型可执行文件的头偏移量
*/
constexpr offset_t ZMAGIC_computation() {
    return SEGMENT_SIZE - sizeof(executable_header);
}

/*
 * code_offset - 代码段偏移量（Code Offset）
*/
inline address_t code_offset(const executable_header& header) {
    return header.file_type == executable_file_type::ZMAGIC ? ZMAGIC_computation() + sizeof(executable_header) : sizeof(executable_header);
}
/*
 * data_offset - 数据段偏移量（Data Offset）
*/
inline address_t data_offset(const executable_header& header) {
    return code_offset(header) + header.code_size;
}
/*
 * code_relocation_offset - 代码段重定位偏移量（Code Relocation Offset）
*/
inline address_t code_relocation_offset(const executable_header& header) {
    return data_offset(header) + header.data_size;
}
/*
 * data_relocation_offset - 数据段重定位偏移量（Data Relocation Offset）
*/
inline address_t data_relocation_offset(const executable_header& header) {
    return code_relocation_offset(header) + header.code_relocation_size;
}
/*
 * symbol_offset - 符号表偏移量（Symbol Offset）
*/
inline address_t symbol_offset(const executable_header& header) {
    return data_relocation_offset(header) + header.data_relocation_size;
}
/*
 * string_offset - 字符串表偏移量（String Offset）
*/
inline address_t string_offset(const executable_header& header) {
    return symbol_offset(header) + header.syms_size;
}



/*
 * address_alignment - 地址对齐（Address Alignment）
 * @note 计算地址对齐到 SEGMENT_SIZE 的倍数
*/
constexpr address_t address_alignment(const address_t address) {
    return (address + SEGMENT_SIZE - 1) & ~(SEGMENT_SIZE - 1);
}



/*
 * code_end_address - 代码段结束地址（Code End Address）
*/
inline address_t code_end_address(const executable_header& header) {
    return code_initial_address + header.code_size;
}
/*
 * data_start_address - 数据段开始地址（Data Start Address）
*/
inline address_t data_start_address(const executable_header& header) {
    return header.file_type == executable_file_type::OMAGIC ? code_end_address(header) : address_alignment(code_end_address(header));
}
/*
 * bss_start_address - BSS 段开始地址（BSS Start Address）
*/
inline address_t bss_start_address(const executable_header& header) {
    return data_start_address(header) + header.data_size;
}