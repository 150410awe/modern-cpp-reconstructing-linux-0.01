#pragma once

/**
 * terminal_mode_flag.h - 定义终端模式标志位
 * @note 定义终端控制结构体中的模式标志位
 */

#include "type.h"

/**
 * @brief 输入模式标志位（Input Mode Flag）
 * @note 定义终端控制结构体中的输入模式标志位
 */
enum class input_mode_flag : uint16_t {
    IGNBRK = 0000001, // 忽略中断条件（Ignore Break Condition）
    BRKINT = 0000002, // 中断条件导致中断（Break Condition Causes Interrupt）
    IGNPAR = 0000004, // 忽略奇偶校验错误（Ignore Parity Errors）
    PARMRK = 0000010, // 标记奇偶校验错误（Mark Parity Errors）
    INPCK = 0000020,  // 启用输入奇偶校验（Enable Input Parity Check）
    ISTRIP = 0000040, // 剥离第八位（Strip eighth bit of input characters）
    INLCR = 0000100,  // 将 NL 转换为 CR
    IGNCR = 0000200,  // 忽略 CR
    ICRNL = 0000400,  // 将 CR 转换为 NL
    IXON = 0002000,   // 启用 XON / XOFF 流控制
    IXOFF = 0010000,  // 启用发送 XON / XOFF 流控制
};
/**
 * @brief 输出模式标志位（Output Mode Flag）
 * @note 定义终端控制结构体中的输出模式标志位
 */
enum class output_mode_flag : uint16_t {
    OPOST = 0000001, // 启用输出处理
    ONLCR = 0000004, // 将 NL 转换为 CR - NL
    OCRNL = 0000010, // 将 CR 转换为 NL
    OFILL = 0000100, // 使用填充字符而非延时
    OFDEL = 0000200, // 使用 DEL 作为填充字符
    OLCUC = 0000002, // 将小写字母转换为大写字母输出
    ONOCR = 0000020, // 行首的回车符不输出
    ONLRET = 0000040, // 换行符（NL）同时执行回车（CR）的功能
};

#if 0
输出延迟标志
现代终端速度快，许多延迟标志（如 NLDLY, CRDLY ）已不再使用...我不支持它们。
#define NLDLY	0000400
#define   NL0	0000000
#define   NL1	0000400
#define CRDLY	0003000
#define   CR0	0000000
#define   CR1	0001000
#define   CR2	0002000
#define   CR3	0003000
#define TABDLY	0014000
#define   TAB0	0000000
#define   TAB1	0004000
#define   TAB2	0010000
#define   TAB3	0014000
#define   XTABS	0014000
#define BSDLY	0020000
#define   BS0	0000000
#define   BS1	0020000
#define VTDLY	0040000
#define   VT0	0000000
#define   VT1	0040000
#define FFDLY	0040000
#define   FF0	0000000
#define   FF1	0040000
#endif

/**
 * @brief 控制模式标志位（Control Mode Flag）
 * @note 定义终端控制结构体中的控制模式标志位
 */
enum class control_mode_flag : uint32_t {
    CSIZE = 0000060, //字符大小掩码
    //5-8 位字符大小
    CS5 = 0000000,
    CS6 = 0000020,
    CS7 = 0000040,
    CS8 = 0000060,
    CSTOPB = 0000100, //使用两位停止位
    CREAD = 0000200,  //启用接收
    PARENB = 0000400, //启用奇偶校验
    PARODD = 0001000, //使用奇校验
    HUPCL = 0002000,  //关闭时挂断
    CLOCAL = 0004000, //忽略调制解调器状态线
    CRTSCTS = 020000000000, //启用硬件流控制
};
/**
 * @brief 波特率设置（Baud Rate Setting）
 * @note 定义终端控制结构体中的波特率设置
 */
enum class baud_rate : uint8_t {
    null_ = 0, // 无波特率 - 不设置波特率
    //各种波特率设置
    B0,
    B50,
    B75,
    B110,
    B134,
    B150,
    B200,
    B300,
    B600,
    B1200,
    B1800,
    B2400,
    B4800,
    B9600,
    B19200,
    B38400,
};
/**
 * @brief 调制解调器状态位（Modem Status Bit）
 * @note 定义终端控制结构体中的调制解调器状态位
 */
enum class modem_status_bit : uint16_t {
    TIOCM_LE = 0x001, // 线路空闲
    TIOCM_DTR = 0x002, // 数据终端就绪
    TIOCM_RTS = 0x004, // 请求发送
    TIOCM_CTS = 0x020, // 清除发送
    TIOCM_CAR = 0x040, // 载波检测
    TIOCM_DSR = 0x100, // 数据设备就绪
};
/**
 * @brief 本地模式标志位（Local Mode Flag）
 * @note 定义终端控制结构体中的本地模式标志位
 */
enum class local_mode_flag : uint16_t {
    ISIG = 0000001, // 启用信号 - 允许 SIGINT 、 SIGQUIT 、 SIGSUSP 等信号
    ICANON = 0000002, // 启用规范模式 - 启用行缓冲和编辑功能
    XCASE = 0000004, // 大小写转换 - 规范模式下，输入小写字母映射到大写， \ 前缀取消转换
    ECHO = 0000010, // 启用回显 - 输入字符立即回显到终端
    ECHOE = 0000020, // 擦除回显 - 当输入 ERASE 字符时，显示退格 + 空格 + 退格
    ECHOK = 0000040, // 杀死回显 - 当输入 KILL 字符时，显示换行符
    ECHONL = 0000100, // 回显换行 - 即使 ECHO 未设置，也回显换行符
    NOFLSH = 0000200, // 禁用刷新 - 信号发生时不刷新输入输出队列
    TOSTOP = 0000400, // 后台输出停止 - 后台进程尝试输出时发送 SIGTTOU 信号
    ECHOCTL = 0001000, // 回显控制字符 - 控制字符显示为 ^C 形式，而非原样显示
    ECHOPRT = 0002000, // 擦除路径回显 - 配合 ECHOE ，显示擦除的字符路径
    ECHOKE = 0004000, // 杀死字符回显 - 以 ECHOE 方式处理 KILL 字符
    FLUSHO = 0010000, // 刷新输出 - 所有输出被丢弃，直到再次设置该标志
    PENDIN = 0040000, // 挂起输入 - 重新输出当前行，用于重印命令
    IEXTEN = 0100000, // 启用扩展输入处理 - 启用 LNEXT 、 REPRINT 等扩展功能
};
/**
 * @brief 控制流设置（Control Flow Setting）
 * @note 定义终端控制结构体中的控制流设置
 */
enum class terminal_control_flow : uint8_t {
    null_ = 0, // 无控制流 - 不启用任何控制流功能
    TCOOFF, // 停止输出 - 挂起终端输出，直到后续的 TCOON 命令
    TCOON, // 恢复输出 - 恢复被 TCOOFF 挂起的终端输出
    TCIOFF, // 传输停止 - 向终端发送 STOP 字符，要求终端停止发送数据
    TCION, // 传输开始 - 向终端发送 START 字符，要求终端恢复发送数据
};
/**
 * @brief 刷新设置（Refresh Setting）
 * @note 定义终端控制结构体中的刷新设置
 */
enum class terminal_refresh : uint8_t {
    null_ = 0, // 无刷新 - 不启用刷新功能
    TCIFLUSH, // 刷新输入队列 - 丢弃未读取的终端输入数据
    TCOFLUSH, // 刷新输出队列 - 丢弃未发送的终端输出数据
    TCIOFLUSH, // 刷新输入输出队列 - 同时丢弃输入和输出队列中的数据
};
/**
 * @brief 定时设置终端属性（Timing Setting Terminal Attributes）
 * @note 定义终端控制结构体中的定时设置终端属性
 */
enum class timing_setting_terminal_attributes : uint8_t {
    null_ = 0, // 无定时设置 - 不启用任何定时设置
    TCSANOW, // 立即生效 - 对所有后续操作立即生效，无需等待
    TCSADRAIN, // 等待完成 - 等待所有当前输出完成后生效
    TCSAFLUSH, // 刷新并生效 - 刷新输入输出队列并立即生效
};


#include "lmn_enum_struct_bit_mask.h"

/**
 * @brief 输入模式标志位（Input Mode Flag）
 * @note 定义终端控制结构体中的输入模式标志位
 */
struct input_mode_flag_enum_struct : lmn_enum_struct_prototype<input_mode_flag_enum_struct, input_mode_flag> {
    using lmn_enum_struct_prototype<input_mode_flag_enum_struct, input_mode_flag>::lmn_enum_struct_prototype;
};
/**
 * @brief 输出模式标志位（Output Mode Flag）
 * @note 定义终端控制结构体中的输出模式标志位
 */
struct output_mode_flag_enum_struct : lmn_enum_struct_prototype<output_mode_flag_enum_struct, output_mode_flag> {
    using lmn_enum_struct_prototype<output_mode_flag_enum_struct, output_mode_flag>::lmn_enum_struct_prototype;
};
/**
 * @brief 控制模式标志位（Control Mode Flag）
 * @note 定义终端控制结构体中的控制模式标志位
 */
struct control_mode_flag_enum_struct : lmn_enum_struct_prototype<control_mode_flag_enum_struct, control_mode_flag> {
    using lmn_enum_struct_prototype<control_mode_flag_enum_struct, control_mode_flag>::lmn_enum_struct_prototype;
};
/**
 * @brief 本地模式标志位（Local Mode Flag）
 * @note 定义终端控制结构体中的本地模式标志位
 */
struct local_mode_flag_enum_struct : lmn_enum_struct_prototype<local_mode_flag_enum_struct, local_mode_flag> {
    using lmn_enum_struct_prototype<local_mode_flag_enum_struct, local_mode_flag>::lmn_enum_struct_prototype;
};

/**
 * @brief 线路规程（Line discipline）
 * @note Linux 0.01 只实现了一种行规程 ，即 默认终端行规程 ， c_line 字段的作用非常有限。基本没有实际功能，始终为 0...
 */
enum class operating_procedures : uint8_t {
    default_ = 0, // 默认终端行规程
};

enum class terminal_error {
    SUCCESS,    // 成功
    INVALID_FD, // 无效文件描述符
    INVALID_PARAMETER,  // 无效参数
    IO_ERROR,    // 输入输出错误
};