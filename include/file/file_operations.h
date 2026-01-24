#pragma once

/**
 * file_operations.h - 文件操作头文件（File Operations Header File）
 * @note 包含文件操作相关的定义和函数声明
*/

#include "file_control.h"
#include <string_view>

namespace file_operations {
    /**
     * creat - 创建文件（Create File）
     * @param filename 文件名（Filename）
     * @param mode 文件模式（File Mode）文件的权限和属性
     * @return 文件描述符（File Descriptor）
    */
    inline int32_t creat(std::string_view filename, open_mode_enum_struct mode);
    /**
     * fcntl - 文件控制（File Control）
     * @param fildes 文件描述符（File Descriptor）
     * @param cmd 命令（Command）文件描述符的各种属性
     * @return 结果（Result）
    */
    inline int32_t fcntl(int32_t fildes, file_control cmd/*, ...*/);
    /**
     * open - 打开文件（Open File）
     * @param filename 文件名（Filename）
     * @param flags 打开标志（Open Flags）文件的打开方式和创建模式
     * @return 文件描述符（File Descriptor）
    */
    inline int32_t open(std::string_view filename, open_mode_enum_struct flags/*, ...*/);
}
