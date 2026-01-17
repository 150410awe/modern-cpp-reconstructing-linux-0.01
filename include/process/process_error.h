#pragma once

#include "../type.h"

/*
 * process_error - 进程错误码（Process Error Codes）
 * 这些错误码表示在操作进程时可能出现的错误情况。
*/
enum class process_error : int32_t {
    null_error = 0, // 无错误（No error）
    echild, // 没有子进程，wait()系统调用没有找到子进程
    esrch, // 没有找到进程，kill()或waitpid()等调用的进程不存在
};
