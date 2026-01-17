#pragma once

#include <cstdint>


/**
 * file_type - 文件类型枚举（File Type Enumeration）
 * @note 表示文件的不同类型
*/
enum class file_type : uint16_t {
    S_IFMT = 00170000,  // 文件类型掩码
    S_IFREG = 0100000,   // 普通文件
    S_IFBLK = 0060000,   // 块设备文件
    S_IFDIR = 0040000,   // 目录文件
    S_IFCHR = 0020000,   // 字符设备文件
    S_IFIFO = 0010000,   // FIFO文件
    S_ISUID = 0004000,   // 设置用户ID位
    S_ISGID = 0002000,   // 设置组ID位
    S_ISVTX = 0001000    // 粘滞位
};

constexpr bool operator==(file_type a, file_type b) {
    return (static_cast<int64_t>(a) & static_cast<int64_t>(file_type::S_IFMT)) == (static_cast<int64_t>(b) & static_cast<int64_t>(file_type::S_IFMT));
}

/**
 * executable_file_type - 可执行文件类型枚举（Executable File Type Enumeration）
 * @note 表示可执行文件的不同类型
*/
enum class executable_file_type : uint16_t {
    null_executable_file_type = 0,
    OMAGIC, //不纯可执行文件
    NMAGIC, //纯可执行文件
    ZMAGIC, //按需分页可执行文件
};

#if 0
这真是太2b了, 这种要 3个宏判断, 3个 != 判断, 1个 == 判断 真的太2b了!
#define N_BADMAG(x) (N_MAGIC(x) != OMAGIC && N_MAGIC(x) != NMAGIC && N_MAGIC(x) != ZMAGIC)
static_cast<int64_t>(a) == static_cast<int64_t>(b);
直接判断是否相等, MSVC 会把static_cast<int64_t>(...)直接优化掉, 加inline 优化 比原来快多了!
#endif
constexpr bool operator==(executable_file_type a, executable_file_type b) {
    return static_cast<int64_t>(a) == static_cast<int64_t>(b);
}