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
  * size_t - 无符号整数类型
  * 用于表示对象的大小或数组的索引
  */
using size_t = uint64_t;
/*
 * time_t - 时间类型
*/
using time_t = uint64_t;
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
 * ustat - 存储文件系统的使用统计信息（File System Status）
 * @note 只是临时的类型定义
*/
struct ustat {
    /*
     * f_tfree - 表示文件系统的可用块数（Free Blocks）
    */
    daddr_t f_tfree;
    /*
     * f_tinode - 表示文件系统的可用inode数（Free Inodes）
    */
    ino_t f_tinode;

    //10,下面是临时的硬编码，后续会根据配置文件修改

    /*
     * f_fname - 表示文件系统的名称（File System Name）
    */
    int8_t f_fname[6];
    /*
     * f_fpack - 表示文件系统的挂载点（Mount Point）
    */
    int8_t f_fpack[6];

    /*
     * ustat - 构造函数
     * @param f_tfree 可用块数
     * @param f_tinode 可用inode数
    */
    ustat(daddr_t f_tfree, ino_t f_tinode) : f_tfree(f_tfree), f_tinode(f_tinode), f_fname{ 0 }, f_fpack{ 0 } {}
    ustat() : f_tfree(0), f_tinode(0), f_fname{ 0 }, f_fpack{ 0 } {}

    /**
     * ~ustat - 析构函数
    */
    ~ustat() {}
};

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