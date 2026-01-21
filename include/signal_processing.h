#pragma once

/*
 * signal_processing.h - 信号处理头文件（Signal Processing Header File）
 * @note 包含信号处理相关的定义和函数声明
*/

//typedef int sig_atomic_t;
//typedef unsigned int sigset_t;		/* 32 bits */
#include "type.h"
#include "signal_type.h"

/**
 * signal_processing - 信号处理结构体（Signal Processing Structure）
 * @note 包含信号处理相关的信息
 * @param signal_handler 信号处理函数指针（Signal Handler Function Pointer）
 * @param signal_mask 信号掩码（Signal Mask）
 * @param signal_flags 信号处理标志（Signal Processing Flags）
*/
struct signal_processing {
    signal_handler_t signal_handler; // 信号处理函数指针（Signal Handler Function Pointer）
    signal_mask_t signal_mask; // 信号掩码（Signal Mask）
    sa_flag signal_flags; // 信号处理标志（Signal Processing Flags）

    signal_processing() : signal_handler(SIG_DFL), signal_mask(0), signal_flags(sa_flag::null_flag) {}
    ~signal_processing() = default;
};


/**
 * signal_processing_set - 信号处理设置命名空间（Signal Processing Set Namespace）
 * @note 包含信号处理设置相关的函数声明,set 有集合的意思...
*/
namespace signal_processing_set {
    /**
     * signal - 设置信号处理函数（Set Signal Handler Function）
     * @param sig 信号编号（Signal Number）
     * @param func 信号处理函数指针（Signal Handler Function Pointer）
     * @return 之前的信号处理函数指针（Previous Signal Handler Function Pointer）
     * @note 原来的 void (*signal(int _sig, void (*_func)(int)))(int); 看着想死
     * 传统的信号处理设置，简单易用但功能有限
    */
    inline signal_handler_t signal(signal_number sig, signal_handler_t func);
    /**
     * raise - 发送信号（Raise Signal）
     * @param sig 信号编号（Signal Number）
     * @return 是否成功发送信号,成功返回 0，失败返回非 0（True if Signal Raised Successfully, False Otherwise）
     * @note 发送信号给当前进程,进程内部自我触发信号（如测试信号处理逻辑）
    */
    inline int32_t raise(signal_number sig);
    /**
     * kill - 发送信号给进程（Send Signal to Process）
     * @param pid 进程ID（Process ID）
     * @param sig 信号编号（Signal Number）
     * @return 是否成功发送信号,成功返回 0，失败返回 -1（True if Signal Killed Successfully, False Otherwise）
     * @note 发送信号给指定进程,进程间通信，通过信号控制其他进程
    */
    inline int32_t kill(pid_t pid, signal_number sig);
    /**
     * sigaddset - 添加信号到信号掩码（Add Signal to Signal Mask）
     * @param mask 信号掩码引用（Signal Mask Reference）
     * @param signo 信号编号（Signal Number）
     * @return 是否成功添加信号到掩码,成功返回 0，失败返回非 0（True if Signal Added to Mask Successfully, False Otherwise）
     * @note 将指定信号添加到信号掩码中,用于阻塞或解除阻塞该信号
    */
    inline int32_t sigaddset(signal_mask_t& mask, signal_number signo);
    /**
     * sigdelset - 从信号掩码中删除信号（Delete Signal from Signal Mask）
     * @param mask 信号掩码引用（Signal Mask Reference）
     * @param signo 信号编号（Signal Number）
     * @return 是否成功从掩码中删除信号,成功返回 0，失败返回非 0（True if Signal Removed from Mask Successfully, False Otherwise）
     * @note 将指定信号从信号掩码中删除,用于解除阻塞该信号
    */
    inline int32_t sigdelset(signal_mask_t& mask, signal_number signo);
    /**
     * sigemptyset - 清空信号掩码（Empty Signal Mask）
     * @param mask 信号掩码引用（Signal Mask Reference）
     * @return 是否成功清空掩码,成功返回 0，失败返回非 0（True if Mask Emptied Successfully, False Otherwise）
     * @note 将信号掩码清空,不包含任何信号
    */
    inline int32_t sigemptyset(signal_mask_t& mask);
    /**
     * sigfillset - 填充信号掩码（Fill Signal Mask）
     * @param mask 信号掩码引用（Signal Mask Reference）
     * @return 是否成功填充掩码,成功返回 0，失败返回非 0（True if Mask Filled Successfully, False Otherwise）
     * @note 将信号掩码填充,包含所有信号
    */
    inline int32_t sigfillset(signal_mask_t& mask);
    /**
     * sigismember - 检查信号是否在掩码中（Check if Signal is in Mask）
     * @param mask 信号掩码引用（Signal Mask Reference）
     * @param signo 信号编号（Signal Number）
     * @return 是否信号在掩码中,1 - 是, 0 - 否, -1 - 错误（True if Signal is in Mask, False if Not, -1 on Error）
     * @note 检查指定信号是否在信号掩码中
    */
    inline int32_t sigismember(const signal_mask_t& mask, signal_number signo);
    /**
     * sigpending - 获取当前挂起的信号（Get Pending Signals）
     * @param set 信号掩码引用（Signal Mask Reference）
     * @return 是否成功获取挂起信号,成功返回 0，失败返回非 0（True if Pending Signals Retrieved Successfully, False Otherwise）
     * @note 获取当前进程挂起的信号,不包含已处理但未执行的信号
    */
    inline int32_t sigpending(signal_mask_t& set);
    /**
     * sigismember - 检查信号是否在掩码中（Check if Signal is in Mask）
     * @param mask 信号掩码引用（Signal Mask Reference）
     * @param signo 信号编号（Signal Number）
     * @return 是否信号在掩码中,1 - 是, 0 - 否, -1 - 错误（True if Signal is in Mask, False if Not, -1 on Error）
     * @note 检查指定信号是否在信号掩码中
    */
    inline int32_t sigismember(const signal_mask_t& mask, signal_number signo); /* 1 - is, 0 - not, -1 error */
    /**
     * sigpending - 获取当前挂起的信号（Get Pending Signals）
     * @param set 信号掩码引用（Signal Mask Reference）
     * @return 是否成功获取挂起信号,成功返回 0，失败返回非 0（True if Pending Signals Retrieved Successfully, False Otherwise）
     * @note 获取当前进程挂起的信号,不包含已处理但未执行的信号
    */
    inline int32_t sigpending(signal_mask_t& set);
    /**
     * sigprocmask - 改变当前进程的信号掩码（Change Process Signal Mask）
     * @param how 操作方式（Operation How）
     * @param set 新信号掩码引用（New Signal Mask Reference）
     * @param oldset 旧信号掩码指针（Old Signal Mask Pointer）
     * @return 是否成功改变信号掩码,成功返回 0，失败返回非 0（True if Signal Mask Changed Successfully, False Otherwise）
     * @note 改变当前进程的信号掩码,用于阻塞或解除阻塞信号
    */
    inline int32_t sigprocmask(sigprocmask_operation how, signal_mask_t& set, signal_mask_t* oldset);
    /**
     * sigsuspend - 挂起进程,直到收到指定信号（Suspend Process Until Signal Received）
     * @param sigmask 信号掩码引用（Signal Mask Reference）
     * @return 总是返回 -1，并设置 errno 为 EINTR （Always Returns -1, Sets errno to EINTR）
     * @note 挂起当前进程,直到收到指定信号,常用于等待信号处理完成
    */
    inline int32_t sigsuspend(const signal_mask_t& sigmask);
    /**
     * sigaction - 设置信号处理函数（Set Signal Handler Function）
     * @param sig 信号编号（Signal Number）
     * @param act 信号处理结构体引用（Signal Action Structure Reference）
     * @param oldact 旧信号处理结构体指针（Old Signal Action Structure Pointer）
     * @return 是否成功设置信号处理函数,成功返回 0，失败返回非 0（True if Signal Handler Set Successfully, False Otherwise）
     * @note 更灵活的信号处理设置,可以设置信号处理函数、信号掩码等
    */
    inline int32_t set_signal_processing(signal_number sig, const signal_processing& act, signal_processing* oldact);
}