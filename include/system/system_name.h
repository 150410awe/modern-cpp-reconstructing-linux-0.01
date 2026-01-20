#pragma once

/*
 * system_name.h - 系统名称头文件（System Name Header File）
 * @note 包含系统名称相关的定义和函数声明
*/

/**
 * system_name - 系统名称结构体（System Name Structure）
 * @note 包含系统的标识信息
*/
struct system_name {
    char system_name[9];    // 操作系统名称（如 "Linux"）
    char node_name[9];   // 网络节点名称（主机名）
    char release[9];    // 操作系统发布版本（如 "0.01"）
    char version[9];    // 操作系统版本（编译时间等）
    char machine[9];    // 硬件架构（如 "i386"）
};

/**
 * get_system_name - 获取系统标识信息 (Get System Identity Information)
 * @param utsbuf 存储系统名称信息的结构体引用（Reference to system_name structure to store system name information）
*/
inline void get_system_name(const system_name& utsbuf);
