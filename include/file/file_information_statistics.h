#pragma once

/**
 * file_Information_statistics.h - 文件系统使用统计信息头文件（File System Status Header File）
 * @note 包含文件系统使用统计信息相关的定义和函数声明
*/

#include "../type.h"

/*
 * file_Information_statistics - 存储文件系统的使用统计信息（File System Status）
 * @note 只是临时的类型定义
*/
struct file_Information_statistics {
    daddr_t num_available_file_blocks;  // 表示文件系统的可用块数
    ino_t file_available_inode_num;  // 表示文件系统的可用inode数
    int8_t file_system_name[6];  // 文件系统名称
    int8_t file_system_mount_point[6];  // 文件系统挂载点


    file_Information_statistics() : num_available_file_blocks(0), file_available_inode_num(0), file_system_name { 0 }, file_system_mount_point { 0 } {}

    ~file_Information_statistics() {}
};

