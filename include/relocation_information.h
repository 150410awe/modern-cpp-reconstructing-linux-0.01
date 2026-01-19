#pragma once


#include "type.h"

/**
 * relocation_information.h - 重定位信息头文件,核心数据结构
 * @note 包含重定位信息相关的定义和函数声明
 */

/**
 * relocation_info - 重定位信息结构体
 * @note 包含重定位信息相关的字段
 */
struct relocation_info {
    int64_t relocation_address;           /* 段内需要重定位的地址 */
    uint32_t symbolnum : 24; /* 符号索引或段类型 */
    uint32_t is_relative_offset : 1;      /* 是否为PC相对偏移 */
    uint32_t relocation_length : 2;     /* 重定位字段长度（2的指数） */
    uint32_t extern_flag : 1;     /* 使用符号值还是段地址 */
    uint32_t retention_bit : 4;        /* 保留位 */

    relocation_info() : relocation_address(0), symbolnum(0), is_relative_offset(0), relocation_length(0), extern_flag(0), retention_bit(0) {}
    ~relocation_info() { };
};