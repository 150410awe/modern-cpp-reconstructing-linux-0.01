#pragma once

#include <cstdint>

/*
 * permission_error - 权限错误码（Permission Error Codes）
 * 这些错误码表示在执行系统调用或函数时，由于权限不足而导致的错误。
*/
enum class permission_error : int32_t {
    null_error = 0, // 无错误（No error）
    eperm, // 权限不足（Permission denied）
    eacces, // 权限被拒绝（Permission denied）
};


/*
 * resources_error - 资源错误码（Resources Error Codes）
 * 这些错误码表示在系统调用或函数执行过程中，由于资源不足而导致的错误。
*/
enum class resources_error : int32_t {
    null_error = 0, // 无错误（No error）
    enomem, // 内存不足，系统无法分配足够的内存
    enfile, // 系统中打开的文件太多，达到系统级限制
    emfile, // 进程打开的文件太多，达到进程级限制
    eagain, // 资源暂时不可用，通常用于非阻塞操作
    enolck, // 没有可用的锁，系统无法获取所需的锁
    e2big, // 参数列表太长，传递给函数的参数超过系统限制
};


/*
 * system_call_error - 系统调用错误码（System Call Error Codes）
 * 这些错误码表示在执行系统调用时可能出现的错误情况。
*/
enum class system_call_error : int32_t {
    null_error = 0, // 无错误（No error）
    eintr, // 系统调用被中断，系统调用执行过程中收到信号
    ebadf, // 错误的文件描述符，使用了无效的文件描述符
    enoexec, // 执行格式错误，可执行文件格式不正确
    efault, // 错误的地址，访问了无效的内存地址
    enotty, // 不适当的I / O控制操作，在非终端设备上执行终端操作
    epipe, // 管道破裂，向已关闭读取端的管道写入
    edeadlk, // 避免死锁条件，系统检测到可能的死锁
    enosys, // 功能未实现，请求的系统调用或功能未实现
};

/*
 * equipment_error - 设备错误码（Equipment Error Codes）
 * 这些错误码表示在操作设备时可能出现的错误情况。
*/
enum class equipment_error : int32_t {
    null_error = 0, // 无错误（No error）
    eio, // I/O错误，硬件I/O操作失败
    enxio, // 没有这样的设备或地址，设备不存在或地址无效
    enotblk, // 不是块设备，期望块设备但得到了其他类型设备
    ebusy, // 设备或资源忙，设备正在被使用
    enodev, // 没有这样的设备，指定的设备不存在
    etxtbsy, // 文本文件忙，试图修改正在执行的可执行文件
    espipe, // 非法的seek操作，在管道或FIFO上尝试seek操作
};
