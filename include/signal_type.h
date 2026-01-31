#pragma once

/**
 * signal_processing - 信号处理结构体（Signal Processing Structure）
 * @note 包含信号处理函数指针、信号掩码等信息
*/

#include "type.h"

/**
 * signal_number - 信号编号枚举（Signal Number Enumeration）
 * @note 包含所有标准信号的编号
 * 原来linux 0.01 规定 信号编号 signo 对应 sigset_t 的第 signo-1 位
 * 这里直接从0开始编号， 不 -1
*/
enum class signal_number : uint8_t {
    SIGHUP = 0, // 终端挂起或控制进程终止
    SIGINT, // 中断信号（Ctrl + C）
    SIGQUIT, // 退出信号（Ctrl + \）
    SIGILL, // 非法指令
    SIGTRAP, // 跟踪陷阱
    SIGABRT, // 异常终止（abort()）
    SIGIOT, // 同 SIGABRT（兼容性定义）
    SIGUNUSED, // 未使用的信号
    SIGFPE, // 浮点异常
    SIGKILL, // 终止信号（不可捕获、不可忽略）
    SIGUSR1, // 用户定义信号1
    SIGSEGV, // 段错误（无效内存访问）
    SIGUSR2, // 用户定义信号2
    SIGPIPE, // 管道破裂
    SIGALRM, // 闹钟信号（alarm()）
    SIGTERM, // 终止信号（可捕获）
    SIGSTKFLT, // 协处理器栈错误
    SIGCHLD, // 子进程状态改变
    SIGCONT, // 继续执行（与SIGSTOP配合）
    SIGSTOP, // 停止执行（不可捕获、不可忽略）
    SIGTSTP, // 终端停止信号（Ctrl + Z）
    SIGTTIN, // 后台进程读终端
    SIGTTOU, // 后台进程写终端
    null_signal,
};

/**
 * sigprocmask_operation - 信号掩码操作类型（Signal Mask Operation Type）
 * @note 包含阻塞、解除阻塞、设置信号掩码等操作
*/
enum class sigprocmask_operation : int32_t {
    BLOCK = 0,  // 阻塞信号
    UNBLOCK,    // 解除阻塞信号
    SETMASK,    // 设置信号掩码
    null_operation,
};

/**
 * sa_flag - 信号处理标志（Signal Handler Flags）
 * @note 包含信号处理的各种标志位,Linux 0.01 版本 尚未完全实现 sigaction 功能，只是在头文件中保持了 POSIX 兼容性
 * 在后续的 Linux 版本中， sa_flags 会增加更多标志，如 SA_RESTART 、 SA_SIGINFO 等，但在 Linux 0.01 中这些都尚未实现...
*/
enum class signal_handler_flag : uint8_t {
    null_flag = 0,
    NOCLDSTOP,  // 子进程停止时不产生 SIGCHLD
    // 可以添加其他标志...
};

// 信号处理函数指针类型（Signal Handler Function Pointer Type）
using signal_handler_t = void(*)(int64_t);
constexpr signal_handler_t SIG_DFL = reinterpret_cast<signal_handler_t>(0);    // 默认信号处理
constexpr signal_handler_t SIG_IGN = reinterpret_cast<signal_handler_t>(1);    // 忽略信号

#if 0
#define SIG_DFL		((void (*)(int))0)	/* default signal handling */
#define SIG_IGN		((void (*)(int))1)	/* ignore signal */
一个字段表示三种不同的信号处理状态
- SIG_DFL((void (*)(int))0)：默认处理
- SIG_IGN((void (*)(int))1)：忽略信号
- 自定义函数指针：执行用户代码
我觉得这还不错, 上面我写的又改进了一下, auto 我写 void (* const)(int32_t) 不知为什么出错
#endif 

constexpr int32_t operator<<(int32_t shift, signal_number signo) {
    return static_cast<int32_t>(signo) << shift;
}

struct signal_mask {
    int32_t signal_mask;    // 信号掩码（Signal Mask）

    /**
     * clear - 清空信号掩码（所有位设为0）
     * @note 清空信号掩码，将所有位设为0
    */
    void clear() { signal_mask = 0; }
    /**
     * fillset - 填充信号掩码（所有位设为1）
     * @note 填充信号掩码，将所有位设为1
    */
    void sigfillset() {
        signal_mask = 0;
        signal_mask = ~signal_mask;
    }
    /**
     * addset - 添加信号到掩码（将信号 signo 添加到掩码）
     * @note 将信号 signo 添加到掩码中
    */
    void sigaddset(signal_number signo) { signal_mask |= (1 << signo); }
    /**
     * delset - 从掩码中删除信号（将信号 signo 从掩码中移除）
     * @note 将信号 signo 从掩码中移除
    */
    void sigdelset(signal_number signo) { signal_mask &= ~(1 << signo); }
    /**
     * ismember - 检查信号是否在掩码中（检查信号 signo 是否在掩码中）
     * @note 检查信号 signo 是否在掩码中
     * @return 如果信号 signo 在掩码中，返回 true；否则返回 false
    */
    bool sigismember(signal_number signo) { return signal_mask & (1 << signo); }
};
