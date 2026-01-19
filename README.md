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

## 技术特点

我基本放弃了原来的linux0.01的架构，我觉得那个太有问题了，还有名字，什么time.h,times.h,....看的让人头大!

- **现代C++设计**：使用enum class、constexpr、inline函数等现代C++特性
- **内核文档系统**：使用Kernel Doc格式的注释，清晰易读
- **模块化架构**：按功能分类的头文件结构，不再是一堆混乱的.h文件
- **统一错误处理**：基于错误分类的异常系统，告别混乱的错误码
- **MSVC兼容**：支持Win32和x64平台，方便在Windows上开发和调试
- **清晰的命名规范**：使用描述性的名称，不再是一堆缩写和宏

## 核心功能

我用cpp是因为我觉得他的有些东西可以更好的资源管理，且我写的比原来的还多几倍

- **底层类型定义**：统一的类型系统，支持不同平台
- **错误码系统**：分类清晰的错误定义
- **文件状态管理**：现代C++风格的文件状态结构体
- **进程时间管理**：进程CPU时间统计
- **系统名称管理**：系统标识信息
- **可执行文件头部**：ELF文件头部管理

## 技术栈

[配置.txt](配置.txt) - 技术栈

## 值得注意的地方

- **底层类型**：[include/type.h](include/type.h) - 统一的类型系统
- **错误定义**：
[include/file/file_error.h](include/file/file_error.h)
[include/process/process_error.h](include/process/process_error.h)
[include/system/system_error.h](include/system/system_error.h)
--分类清晰的错误码
- **可执行文件**：[include/executable_header.h](include/executable_header.h) - ELF文件头部管理

## 未来计划

等我回来有时间...

## 总结

我觉得 namespace constexpr using inline & && 太伟大了，不然我就像老一辈程序员一样吃屎了
这个项目不是一个完整的Linux系统，而是一个学习和实践现代C++的项目，通过重写Linux 0.01的核心功能，来理解操作系统的基本原理，同时体验现代C++的强大特性
