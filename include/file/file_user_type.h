#pragma once


/**
 * file_user_type - 文件用户类型枚举（File User Type Enumeration）
 * @note 表示文件的不同用户类型
*/

#include "../type.h"


/**
 * user_file_type - 用户文件类型枚举（User File Type Enumeration）
 * @note 表示文件的不同类型
*/
enum class user_file_type : uint8_t {
    unknown = 0,    // 未知文件类型
    file_type,  // 文件类型
    ordinary,   // 普通文件
    block_device,       // 块设备文件
    directory,   // 目录文件
    character_device,   // 字符设备文件
    fifo,   // FIFO文件/命名管道
};


constexpr bool operator==(user_file_type a, user_file_type b) {
    return static_cast<uint8_t>(a) == static_cast<uint8_t>(b);
}
constexpr bool operator!=(user_file_type a, user_file_type b) {
    return !(a == b);
}
