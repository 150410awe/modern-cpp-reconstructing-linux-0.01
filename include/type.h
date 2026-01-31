#pragma once
/**
 * type.h - 底层类型定义
 *
 * 该文件定义了底层的类型，包括有符号整数和无符号整数。
 * 这些类型在不同的平台上可能有不同的大小和表示方式。
 * 本文件提供了一种统一的方式来定义这些类型，以便在不同平台上的代码能够一致地使用。
 */

#include <cstdint>
/**
 * u_char - 无符号字符类型
 * 用于表示无符号的字符
 */
using u_char = uint8_t;
 /**
  * size_t - 无符号整数类型
  * 用于表示对象的大小或数组的索引
  */
using size_t = uint64_t;
/*
 * time_t - 时间类型
*/
using time_t = uint64_t;
/**
 * clock_t - 时钟滴答类型，用于计算程序运行时间
*/
using clock_t = uint64_t;
/*
 * offset_t - 偏移量类型
*/
using offset_t = int64_t;
/*
 * address_t - 地址类型
*/
using address_t = uint64_t;

/**
 * pid_t - 进程标识符类型
*/
using pid_t = uint32_t;
/*
 * uid_t - 用户标识符类型
*/
using uid_t = uint32_t;
/*
 * gid_t - 组标识符类型
*/
using gid_t = uint32_t;


/*
 * mode_t - 文件模式类型
*/
using mode_t = uint32_t;
/*
 * dev_t - 设备号类型
*/
using dev_t = uint32_t;
/*
 * umode_t - 用户空间的文件模式类型（与 mode_t 类似，但用于用户空间）
*/
using umode_t = uint32_t;
/*
 * nlink_t - 硬链接数类型
*/
using nlink_t = uint8_t;
/*
 * ino_t - 索引节点号类型
 * 文件系统中唯一标识文件的元数据
*/
using ino_t = uint32_t;
/*
 * off_t - 文件中的位置偏移量类型
*/
using off_t = int64_t;
/*
 * daddr_t - 磁盘块地址类型
*/
using daddr_t = int64_t;
/*
 * ptrdiff_t - 指针差值类型
*/
using ptrdiff_t = int64_t;
/**
 * structure_offsetof - 计算结构体成员的偏移量
 * @param u 指向结构体成员的指针
 * @return 结构体成员的偏移量
 * @note 他太丑了,我也没什么好法子
*/
template<typename T, typename U>
constexpr offset_t structure_offsetof(U T::* u) {
  return reinterpret_cast<offset_t>(&(reinterpret_cast<T*>(nullptr)->*u));
}

/**
 * int_div_t - 表示整数除法的结果（Integer Division Result）
 * @note 临时的定义
*/
struct int_div_t {
    /**
     * quot - 表示商（Quotient）
    */
    int64_t quot;
    /**
     * rem - 表示余数（Remainder）
    */
    int64_t rem;

    /**
     * int_div_t - 构造函数
     * @param quot 商
     * @param rem 余数
    */
    int_div_t(int64_t quot, int64_t rem) : quot(quot), rem(rem) {}
    int_div_t() : quot(0), rem(0) {}

    /**
     * ~int_div_t - 析构函数
    */
    ~int_div_t() {}
};