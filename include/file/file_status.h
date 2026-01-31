#pragma once

/**
 * file_status.h - 文件状态头文件（File Status Header File）
 * @note 包含文件状态相关的定义和函数声明
*/

#include "../type.h"
#include <string_view>
#include "file_control.h"
#include "file_permissions_type.h"

/**
 * file_status - 文件状态结构体（File Status Structure）
 * @note 包含文件的元数据信息
*/
struct file_status {
    dev_t   st_dev;     // 文件所在设备号
    ino_t   st_ino;     // 文件的索引节点号（i-node number）
    umode_t st_mode;    // 文件类型和权限
    nlink_t st_nlink;   // 硬链接数量
    uid_t   st_uid;     // 文件所有者的用户ID
    gid_t   st_gid;     // 文件所有者的组ID
    dev_t   st_rdev;    // 如果是设备文件，表示设备号
    off_t   st_size;    // 文件大小（字节）
    time_t  st_atime;   // 最后访问时间
    time_t  st_mtime;   // 最后修改时间
    time_t  st_ctime;   // 最后状态改变时间

    file_status() : st_dev(0), st_ino(0), st_mode(0), st_nlink(0), st_uid(0), st_gid(0), st_rdev(0), st_size(0), st_atime(0), st_mtime(0), st_ctime(0) {}
    ~file_status() {}
};


/**
 * chmod - 修改文件权限（Change File Permissions）
 * @param path 文件路径（Path to the file）
 * @param mode 新的权限模式（New permissions mode）
*/
void chmod(std::string_view path, file_permissions_enum_struct mode);
/**
 * fstat - 获取已打开文件状态（Get Status of an Open File）
 * @param fildes 文件描述符（File descriptor）
 * @param stat_buf 存储文件状态的结构体引用（Reference to file_status structure to store file status）
*/
void fstat(open_mode_enum_struct fildes, const file_status& stat_buf);
/**
 * mkdir - 创建目录（Create a Directory）
 * @param path 目录路径（Path to the directory）
 * @param mode 目录权限模式（Permissions mode for the directory）
*/
void mkdir(std::string_view path, mode_t mode);
/**
 * mkfifo - 创建FIFO文件（Create a FIFO File）
 * @param path FIFO文件路径（Path to the FIFO file）
 * @param mode FIFO文件权限模式（Permissions mode for the FIFO file）
*/
void mkfifo(std::string_view path, mode_t mode);
/**
 * get_file_status - 获取文件状态（Get File Status）
 * @param path 文件路径（Path to the file）
 * @param stat_buf 存储文件状态的结构体引用（Reference to file_status structure to store file status）
*/
void get_file_status(std::string_view path, const file_status& stat_buf);
/**
 * umask - 设置文件创建掩码（Set File Creation Mask）
 * @param mask 新的文件创建掩码（New file creation mask）
*/
//void umask(mode_t mask);