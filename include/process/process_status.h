#pragma once

/**
 * status.h - 状态头文件（Status Header File）
 * @note 包含状态相关的定义和函数声明
*/

#include <cstdint>

enum class process_status : int32_t {
    null_status = 0,
    exited,  // 正常退出
    signaled,  // 信号终止
    stopped,  // 信号停止
    continued,  // 进程继续
};

enum class process_exit_code : int32_t {
    null_code = 0,
    success,     // 成功退出
    failed,      // 失败退出
};
