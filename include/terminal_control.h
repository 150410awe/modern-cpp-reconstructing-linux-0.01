#pragma once

/**
 * @file terminal_control.h
 * @brief 终端控制结构体（Terminal Control Structure）
 * @note 包含终端输入、输出、控制和本地模式标志，以及控制字符
 */

#include "type.h"
#include "control_char_type.h"
#include "terminal_mode_flag.h"
#include "file_control.h"

/**
 * @brief 控制字符数量（Number of Control Characters）
 * @note 定义终端控制结构体中的控制字符数组大小
 */

 /**
 * termios - 终端控制结构体（Terminal Control Structure）
 * @note 包含终端输入、输出、控制和本地模式标志，以及控制字符
 */
struct termios {
    input_mode_flag_enum_struct input_mode;      // 输入模式标志
    output_mode_flag_enum_struct output_mode;      // 输出模式标志
    control_mode_flag_enum_struct control_mode;      // 控制模式标志
    local_mode_flag_enum_struct local_mode;      // 本地模式标志
    operating_procedures line_discipline;       // 线路规程（Line discipline）
    baud_rate input_baud_rate;     // 输入波特率（Input baud rate）
    baud_rate output_baud_rate;     // 输出波特率（Output baud rate）

    u_char control_characters[NCCS];   // 控制字符

    termios() : input_mode(), output_mode(), control_mode(), local_mode(), line_discipline(operating_procedures::default_), control_characters { 0 } {}
    ~termios() = default;

    //波特率控制函数

    /**
     * @brief 获取输入波特率
     * @return 输入波特率
     */
    baud_rate get_input_baud_rate() const;
    /**
     * @brief 获取输出波特率
     * @return 输出波特率
     */
    baud_rate get_output_baud_rate() const;
    /**
     * @brief 设置输入波特率
     * @param speed 输入波特率
     */
    void set_input_baud_rate(baud_rate speed);
    /**
     * @brief 设置输出波特率
     * @param speed 输出波特率
     */
    void set_output_baud_rate(baud_rate speed);



    //终端控制函数
    /**
     * @brief 等待输出完成 - 阻塞直到所有待发送的输出数据都已发送到终端
     * @param fildes 终端文件描述符
     * @return 返回 terminal_error
     */
    terminal_error waiting_output(open_mode_enum_struct fildes);
    /**
     * @brief 控制终端流 - 根据 action 参数控制终端的输入输出流（如 TCOOFF 、 TCOON 等）
     * @param fildes 终端文件描述符
     * @param action 控制流操作（如 TCOOFF 、 TCOON 等）
     * @return 返回 terminal_error
     */
    terminal_error control_terminal(open_mode_enum_struct fildes, terminal_control_flow action);
    /**
     * @brief 刷新终端队列 - 根据 queue_selector 参数刷新终端的输入输出队列（如 TCIFLUSH 、 TCOFLUSH 等）
     * @param fildes 终端文件描述符
     * @param queue_selector 刷新队列选择器（如 TCIFLUSH 、 TCOFLUSH 等）
     * @return 返回 terminal_error
     */
    terminal_error refresh_terminal_queue(open_mode_enum_struct fildes, terminal_refresh queue_selector);
    /**
     * @brief 获取终端属性 - 读取终端的当前属性到 termios 结构体
     * @param fildes 终端文件描述符
     * @return 终端属性结构体
     */
    const termios& get_termios(open_mode_enum_struct fildes);
    /**
     * @brief 发送中断条件 - 向终端发送连续的 0 位流，模拟终端中断
     * @param fildes 终端文件描述符
     * @param duration 持续时间（单位：毫秒）
     * @return 返回 terminal_error
     */
    terminal_error send_interruption_condition(open_mode_enum_struct fildes, int duration);
    /**
     * @brief 设置终端属性 - 根据 optional_actions 参数应用新的终端属性（如 TCSANOW 、 TCSADRAIN 等）
     * @param fildes 终端文件描述符
     * @param optional_actions 可选操作标志（如 TCSANOW 、 TCSADRAIN 等）
     * @return 返回 terminal_error
     */
    terminal_error set_termios(open_mode_enum_struct fildes, timing_setting_terminal_attributes optional_actions);
};


