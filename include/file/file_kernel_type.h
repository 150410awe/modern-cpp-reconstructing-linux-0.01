#pragma once

/*
 * kernel_file_type - 内核文件类型枚举（Kernel File Type Enumeration）
 * @note 表示内核内部使用的文件类型
*/

#include <cstdint>


/**
 * kernel_file_type - 内核文件类型枚举（Kernel File Type Enumeration）
 * @note 表示内核内部使用的文件类型
*/
enum class kernel_file_type : uint8_t {
    unknown = 0,    // 未知文件类型
    file_type,  // 文件类型
    ordinary,   // 普通文件
    block_device,       // 块设备文件
    directory,   // 目录文件
    character_device,   // 字符设备文件
    fifo,   // FIFO文件/命名管道
};


#if 0
#include "file_user_type.h"
转换机制通常在系统调用中, 这里提前写一下
constexpr bool operator==(user_file_type a, kernel_file_type b) {
    return static_cast<uint8_t>(a) == static_cast<uint8_t>(b);
}
constexpr bool operator==(kernel_file_type a, user_file_type b) {
    return static_cast<uint8_t>(a) == static_cast<uint8_t>(b);
}
constexpr bool operator!=(user_file_type a, kernel_file_type b) {
    return !(a == b);
}
constexpr bool operator!=(kernel_file_type a, user_file_type b) {
    return !(a == b);
}
// 内核类型转用户类型
constexpr user_file_type kernel_to_user(kernel_file_type kernel_type) {
    return static_cast<user_file_type>(static_cast<uint8_t>(kernel_type));
}
// 用户类型转内核类型
constexpr kernel_file_type user_to_kernel(user_file_type user_type) {
    return static_cast<kernel_file_type>(static_cast<uint8_t>(user_type));
}

#endif

constexpr bool operator==(kernel_file_type a, kernel_file_type b) {
    return static_cast<uint8_t>(a) == static_cast<uint8_t>(b);
}
constexpr bool operator!=(kernel_file_type a, kernel_file_type b) {
    return !(a == b);
}


#if 0
// 便捷的检查函数
constexpr bool is_regular_file(kernel_file_type type) {
    return type == kernel_file_type::ordinary;
}
constexpr bool is_directory(kernel_file_type type) {
    return type == kernel_file_type::directory;
}
constexpr bool is_device_file(kernel_file_type type) {
    return type == kernel_file_type::block_device ||
        type == kernel_file_type::character_device;
}
便捷 ? ? ?
我便捷你个头
不直接
constexpr bool operator==(kernel_file_type a, kernel_file_type b) {
    return static_cast<uint8_t>(a) == static_cast<uint8_t>(b);
}
还写怎么多2b检查函数, 写死我吧,cao死我算了
#endif

/**
 * executable_file_type - 可执行文件类型枚举（Executable File Type Enumeration）
 * @note 表示可执行文件的不同类型
*/
enum class executable_file_type : uint8_t {
    unknown = 0,    // 未知可执行文件类型
    OMAGIC, //不纯可执行文件
    NMAGIC, //纯可执行文件
    ZMAGIC, //按需分页可执行文件
};

#if 0
这真是太2b了, 这种要 3个宏判断, 3个 != 判断, 1个 == 判断 真的太2b了!
#define N_BADMAG(x) (N_MAGIC(x) != OMAGIC && N_MAGIC(x) != NMAGIC && N_MAGIC(x) != ZMAGIC)
static_cast<uint8_t>(a) == static_cast<uint8_t>(b);
直接判断是否相等, MSVC 会把static_cast<uint8_t>(...)直接优化掉, 加inline 优化 比原来快多了!
#endif

constexpr bool operator==(executable_file_type a, executable_file_type b) {
    return static_cast<uint8_t>(a) == static_cast<uint8_t>(b);
}
constexpr bool operator!=(executable_file_type a, executable_file_type b) {
    return !(a == b);
}

#if 0
// 可执行文件类型转换
constexpr executable_file_type magic_to_exec_type(uint16_t magic) {
    switch (magic) {
    case 0407: return executable_file_type::OMAGIC;  // 不纯可执行文件
    case 0410: return executable_file_type::NMAGIC;  // 纯可执行文件  
    case 0413: return executable_file_type::ZMAGIC;  // 按需分页可执行文件
    default: return executable_file_type::unknown;
    }
}谁记得住这些魔数？我应该不会忆得那一堆魔数....
我一般直接比较,&&更快
#endif