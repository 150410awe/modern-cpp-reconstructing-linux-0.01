#pragma once

/**
 * file_lock.h - 文件锁头文件（File Lock Header File）
 * @note 包含文件锁相关的定义和函数声明
*/

#include "file_control.h"

/**
 * file_lock - 文件锁结构体（File Lock Structure）
 * @note 包含文件锁相关的字段和函数声明
*/
#if 0

struct file_lock {
    file_locking_type type; // 文件锁类型
    uint16_t whence; // 锁的起始位置
    off_t start; // 锁的起始偏移量
    off_t len; // 锁的长度
    pid_t pid; // 加锁进程的PID
};

#endif
