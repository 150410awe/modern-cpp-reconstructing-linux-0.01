#pragma once

/**
 * file_control.h - 文件控制头文件
 * @note 包含文件控制相关的定义和函数声明
 */


#include <cstdint>

/**
 * open_mode - 文件打开模式枚举类
 * @note 包含文件打开模式相关的定义和函数声明
 */
enum class open_mode : uint16_t {
    O_ACCMODE = 00003, // 访问模式掩码，用于提取文件打开模式
    O_RDONLY = 00, // 只读模式
    O_WRONLY = 01, // 只写模式
    O_RDWR = 02, // 读写模式
    O_CREAT = 00100, // 创建文件（不存在时） not fcntl
    O_EXCL = 00200, // 与 O_CREAT 一起使用，确保创建新文件 not fcntl
    O_NOCTTY = 00400, // 不将文件作为控制终端 not fcntl
    O_TRUNC = 01000, // 截断文件为0长度 not fcntl
    O_APPEND = 02000, // 追加模式，写入时从文件末尾开始
    O_NONBLOCK = 04000, // 非阻塞模式 not fcntl
    O_NDELAY = O_NONBLOCK, // 同 O_NONBLOCK（兼容性定义）
};

/**
 * file_control - 文件控制操作枚举类
 * @note 包含文件控制操作相关的定义和函数声明
 */
enum class file_control : uint8_t {
    F_DUPFD = 0, // 复制文件描述符
    F_GETFD, // 获取文件描述符标志
    F_SETFD, // 设置文件描述符标志
    F_GETFL, // 获取文件状态标志
    F_SETFL, // 设置文件状态标志
    F_GETLK, // 获取文件锁信息（未实现）
    F_SETLK, // 设置文件锁
    F_SETLKW, // 设置文件锁（等待模式）
    null_, // 空操作（未使用）
};

/**
 * File_descriptor_flag - 文件描述符标志枚举类
 * @note 包含文件描述符标志相关的定义和函数声明
 */
enum class file_descriptor_flag : uint8_t {
    FD_CLOEXEC = 0x01, // 关闭执行时关闭文件描述符
};

/**
 * file_lock_type - 文件锁类型枚举类
 * @note 包含文件锁类型相关的定义和函数声明
 */
enum class file_lock_type : uint8_t {
    F_RDLCK = 0, // 读取锁
    F_WRLCK, // 写入锁
    F_UNLCK, // 解锁
    null_, // 空操作（未使用）
};

#include "../lmn_enum_struct_bit_mask.h"

struct open_mode_enum_struct : lmn_enum_struct_prototype<open_mode_enum_struct, open_mode> {
    using lmn_enum_struct_prototype::lmn_enum_struct_prototype;
};