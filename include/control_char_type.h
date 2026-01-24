#pragma once

/**
 * @brief 控制字符类型（Control Character Type）
 * @note 定义终端控制结构体中的控制字符类型
 */

#include "type.h"

enum class control_character : uint8_t {
    VINTR = 0, // 中断字符（Interrupt Character）
    VQUIT,     // 退出字符（Quit Character）
    VERASE,    // 删除字符（Erase Character）
    VKILL,     // 杀死字符（Kill Character）
    VEOF,      // 文件结束字符（End-of-File Character）
    VTIME,     // 读取超时（十分之一秒）(Timeout Character)
    VMIN,      // 最小字符数（Minimum Character Count）
    VSWTC,     // 交换终端字符（已废弃）
    VSTART,    // 开始字符（Start Character）
    VSTOP,     // 停止字符（Stop Character）
    VSUSP,     // 挂起字符（Suspend Character）
    VEOL,      // 行结束字符（End-of-Line Character）
    VREPRINT,  // 重新打印字符（Reprint Character）
    VDISCARD,  // 丢弃字符（Discard Character）
    VWERASE,   // 擦除单词字符（Erase Word Character）
    VLNEXT,    // 下一行字符（Line Next Character）
    VEOL2,     // 第二行结束字符（End-of-Line Character）
    NULL_CHAR, // 空字符（Null Character）
};

constexpr uint8_t NCCS = static_cast<uint8_t>(control_character::NULL_CHAR) + 1;
