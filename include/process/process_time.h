#pragma once
/*
 * process_time.h - 时间函数头文件
 *
 * 该文件定义了时间函数的相关数据结构和函数原型。
 * 时间函数用于获取进程的CPU时间和系统时间。
 */

#include "../type.h"

 /*
  * struct process_time - 进程时间结构体
  *
  * 该结构体用于存储进程的CPU时间和系统时间信息。
  * tms_utime - 用户CPU时间（进程自身执行时间）
  * tms_stime - 系统CPU时间（进程内核执行时间）
  * tms_cutime - 子进程用户CPU时间（已终止子进程）
  * tms_cstime - 子进程系统CPU时间（已终止子进程）
  */
struct process_time {
    time_t self_execution_time;   // 用户CPU时间（进程自身执行时间）
    time_t kernel_execution_time;   // 系统CPU时间（进程内核执行时间）
    time_t children_user_execution_time;  // 累计的子进程用户时间 （Children User Time）
    time_t children_system_execution_time;  // 累计的子进程系统时间 （Children System Time）

    process_time() : self_execution_time(0), kernel_execution_time(0), children_user_execution_time(0), children_system_execution_time(0) {}
    ~process_time() {}
};

/**
 * get_process_time - 获取进程时间统计信息 (Get Process Time Statistics)
 * @param tp 存储时间信息的结构体引用（Reference to process_time structure to store time information）
 * @return 进程的CPU时间（Process CPU time）
*/
inline time_t get_process_time(const process_time& tp);
