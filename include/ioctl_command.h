#pragma once

/**
 * ioctl_command.h - IOCTL 命令（IO Control Command）
 * @note 定义终端控制结构体中的 IOCTL 命令
 */

#include "type.h"

/**
 * TTY_BUF_SIZE - 终端缓冲区大小1024字节（Terminal Buffer Size）
 * @note 限制终端一次能缓存的最大输入字符数，防止缓冲区溢出,现代Linux终端缓冲区通常更大，且可动态调整
 */
constexpr uint16_t TTY_BUF_SIZE = 1024;

/**
 * ioctl_command_cardinal_number - 魔法数（Magic Number）0x6C6D6E -
 * 设计目的: 使终端ioctl命令在系统中保持唯一性，避免与其他设备的ioctl命令冲突
 */
constexpr uint32_t ioctl_command_cardinal_number = 0x6C6D6E;

/**
 * ioctl_command - IOCTL 命令（IO Control Command）
 * @note 定义终端控制结构体中的 IOCTL 命令
 * 每个ioctl命令 = 魔术数字 + 序号，格式为 0x6C6D6E
 */
enum class ioctl_command : uint32_t {
    TCGETS, // 获取终端状态 - 读取终端的termios结构体
    TCSETS, // 设置终端状态 - 立即生效
    TCSETSW, // 设置终端状态 - 等待所有输出完成后生效
    TCSETSF, // 设置终端状态 - 刷新输入输出后生效
    /*
    TCGETA, // 获取旧版termio结构体（兼容System V）
    TCSETA, // 设置旧版termio结构体（立即生效）
    TCSETAW, // 设置旧版termio结构体（等待输出完成）
    TCSETAF, // 设置旧版termio结构体（刷新I / O后生效）
    */
    TCSBRK, // 发送中断条件 - 用于产生中断信号
    TCXONC, // 控制输出流 - 启动 / 停止终端输出
    TCFLSH, // 刷新终端缓冲区 - 清空输入 / 输出缓冲区
    TIOCEXCL, // 独占模式 - 设置终端为独占访问模式
    TIOCNXCL, // 取消独占模式 - 解除终端独占访问
    TIOCSCTTY, // 设置控制终端 - 使终端成为进程组的控制终端
    TIOCGPGRP, // 获取进程组ID - 读取终端关联的进程组ID
    TIOCSPGRP, // 设置进程组ID - 设置终端关联的进程组ID
    TIOCOUTQ, // 获取输出队列长度 - 读取未发送的输出字节数
    TIOCSTI, // 插入输入字符 - 向终端输入队列插入字符
    TIOCGWINSZ, // 获取窗口大小 - 读取终端窗口的行数和列数
    TIOCSWINSZ, // 设置窗口大小 - 设置终端窗口的行数和列数
    TIOCMGET, // 获取调制解调器状态 - 读取串口线路状态
    TIOCMBIS, // 设置调制解调器位 - 置位串口控制位
    TIOCMBIC, // 清除调制解调器位 - 清除串口控制位
    TIOCMSET, // 设置调制解调器状态 - 设置完整的串口状态
    TIOCGSOFTCAR, // 获取软载波检测 - 读取软载波检测状态
    TIOCSSOFTCAR, // 设置软载波检测 - 设置软载波检测状态
};