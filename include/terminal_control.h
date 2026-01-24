#pragma once

/**
 * @file terminal_control.h
 * @brief 终端控制结构体（Terminal Control Structure）
 * @note 包含终端输入、输出、控制和本地模式标志，以及控制字符
 */

#include "type.h"
#include "control_char_type.h"
#include "terminal_mode_flag.h"

/**
 * @brief 控制字符数量（Number of Control Characters）
 * @note 定义终端控制结构体中的控制字符数组大小
 */

 /**
 * termios - 终端控制结构体（Terminal Control Structure）
 * @note 包含终端输入、输出、控制和本地模式标志，以及控制字符
 */
struct termios {
    input_mode_flag_enum_struct c_iflag;      // 输入模式标志（64位）
    output_mode_flag_enum_struct c_oflag;      // 输出模式标志（64位）
    control_mode_flag_enum_struct c_cflag;      // 控制模式标志（64位）
    local_mode_flag_enum_struct c_lflag;      // 本地模式标志（64位）
    operating_procedures c_line;       // 线路规程（Line discipline）
    baud_rate c_ispeed;     // 输入波特率（Input baud rate）
    baud_rate c_ospeed;     // 输出波特率（Output baud rate）

    unsigned char c_cc[NCCS];   // 控制字符

    termios() : c_iflag(), c_oflag(), c_cflag(), c_lflag(), c_line(operating_procedures::default_), c_cc(0) { }
    ~termios() = default;
};