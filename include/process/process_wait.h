#pragma once

/**
 * wait.h - 等待头文件（Wait Header File）
 * @note 包含等待相关的定义和函数声明
*/

#include "../type.h"
#include "process_status.h"

#if 0
这真的太复杂了, linus 为了一点点系统资源, 干这种事
缓存友好 ? 我真不觉得现在的 cache 命中率怎么低, 且他也不是高频调用, 根本没必要优化
#define _LOW(v)		( (v) & 0377)
#define _HIGH(v)	( ((v) >> 8) & 0377)
#endif


#if 0
/* options for waitpid, WUNTRACED not supported */
#define WNOHANG		1
#define WUNTRACED	2
#endif

/**
 * WIFEXITED - 检查进程是否正常退出
 * @param s: 进程状态
 * @return: 如果进程正常退出, 返回 true, 否则返回 false
*/
inline bool WIFEXITED(process_status s) { return s == process_status::exited; }
/**
 * WIFSTOPPED - 检查进程是否被信号停止
 * @param s: 进程状态
 * @return: 如果进程被信号停止, 返回 true, 否则返回 false
*/
inline bool WIFSTOPPED(process_status s) { return s == process_status::stopped; }
/**
 * WIFSIGNALED - 检查进程是否被信号终止
 * @param s: 进程状态
 * @return: 如果进程被信号终止, 返回 true, 否则返回 false
*/  
inline bool WIFSIGNALED(process_status s) { return s == process_status::signaled; }

/*
 * wait - 等待子进程退出
 * @param stat_loc: 用于存储子进程退出状态的引用
 * @return: 子进程的 PID, 如果出错则返回 -1
*/
inline pid_t wait(int& stat_loc);
/**
 * waitpid - 等待指定子进程退出
 * @param pid: 子进程的 PID, 如果为 -1, 则等待任意子进程
 * @param stat_loc: 用于存储子进程退出状态的引用
 * @param options: 等待选项, 可以是 WNOHANG 或 WUNTRACED
 * @return: 子进程的 PID, 如果出错则返回 -1
*/
inline pid_t waitpid(pid_t pid, int& stat_loc, int options);
