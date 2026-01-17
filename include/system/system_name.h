#pragma once

/*
 * system_name.h - 系统名称头文件（System Name Header File）
 * @note 包含系统名称相关的定义和函数声明
*/

#include <cstdint>

/**
 * system_name - 系统名称结构体（System Name Structure）
 * @note 包含系统的标识信息
*/
struct system_name {
    int8_t system_name[9];    // 操作系统名称（如 "Linux"）
    int8_t node_name[9];   // 网络节点名称（主机名）
    int8_t release[9];    // 操作系统发布版本（如 "0.01"）
    int8_t version[9];    // 操作系统版本（编译时间等）
    int8_t machine[9];    // 硬件架构（如 "i386"）
};

/**
 * get_system_name - 获取系统标识信息 (Get System Identity Information)
 * @param utsbuf 存储系统名称信息的结构体引用（Reference to system_name structure to store system name information）
*/
inline void get_system_name(const system_name& utsbuf);
