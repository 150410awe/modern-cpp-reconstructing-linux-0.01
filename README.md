# modern-cpp-reconstructing-linux-0.01

## 项目简介

我承认我是一个傻逼，妈的想用linux0.01的镜像....太傻逼了，真的让人红温，还有代码里让人看着就想死的各种宏

所以我准备用现代C++重写linux0.01，我觉得这会非常非常有意思

我可能也不创镜像，我只是非常想写代码

## 设计哲学与特点

- **清晰分离**
- **类型安全**
- **简单直接**
- **模块化**

对了,还有很慢(我说更新),对了,这是一个学习项目,学习.

## 项目结构

[项目文件结构.txt](项目文件结构.txt)

## 技术栈

[配置.txt](配置.txt) - 技术栈

## 值得注意的地方

- **底层类型**：[include/type.h](include/type.h) - 统一的类型系统
- **错误定义**：
[include/file/file_error.h](include/file/file_error.h)
[include/process/process_error.h](include/process/process_error.h)
[include/system/system_error.h](include/system/system_error.h)
[include/error.h](include/error.h)
--分类清晰的错误码
- **可执行文件**：[include/executable_header.h](include/executable_header.h) - 文件头部管理
- **符号和重定位**：[include/relocation_information.h](include/relocation_information.h) - 重定位信息管理
[include/symbol_table.h](include/symbol_table.h) - 符号表管理
- **文件类型**：[include/file/file_kernel_type.h](include/file/file_kernel_type.h) - 内核文件类型管理
[include/file/file_user_type.h](include/file/file_user_type.h) - 用户文件类型管理
- **lmn_enum_struct_bit_mask**：[include/lmn_enum_struct_bit_mask.h](include/lmn_enum_struct_bit_mask.h) - 枚举结构体位掩码管理
- **终端模式**：[include/terminal_mode_flag.h](include/terminal_mode_flag.h) - 终端模式管理

## 未来计划

等我回来有时间...

## 总结

我觉得 namespace constexpr using inline & && 太伟大了，不然我就像老一辈程序员一样吃屎了
这个项目不是一个完整的Linux系统，而是一个学习和实践现代C++的项目，通过重写Linux 0.01的核心功能，来理解操作系统的基本原理，同时体验现代C++的强大特性
