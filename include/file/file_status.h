#pragma once

/**
 * file_status.h - 文件状态头文件（File Status Header File）
 * @note 包含文件状态相关的定义和函数声明
*/

#include "../type.h"

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
 * file_permissions_type - 文件权限枚举（File Permissions Enumeration）
 * @note 表示文件的不同权限
*/
enum class file_permissions_type : uint16_t {
    S_IRWXU = 00700,  // 用户读、写、执行权限
    S_IRUSR = 00400,  // 用户读权限
    S_IWUSR = 00200,  // 用户写权限  
    S_IXUSR = 00100,  // 用户执行权限

    S_IRWXG = 00070,  // 组读、写、执行权限
    S_IRGRP = 00040,  // 组读权限
    S_IWGRP = 00020,  // 组写权限
    S_IXGRP = 00010,  // 组执行权限

    S_IRWXO = 00007,  // 其他用户读、写、执行权限
    S_IROTH = 00004,  // 其他用户读权限
    S_IWOTH = 00002,  // 其他用户写权限
    S_IXOTH = 00001,  // 其他用户执行权限
};


/**
 * chmod - 修改文件权限（Change File Permissions）
 * @param path 文件路径（Path to the file）
 * @param mode 新的权限模式（New permissions mode）
*/
void chmod(const char* path, mode_t mode);
/**
 * fstat - 获取已打开文件状态（Get Status of an Open File）
 * @param fildes 文件描述符（File descriptor）
 * @param stat_buf 存储文件状态的结构体引用（Reference to file_status structure to store file status）
*/
void fstat(int fildes, const file_status& stat_buf);
/**
 * mkdir - 创建目录（Create a Directory）
 * @param path 目录路径（Path to the directory）
 * @param mode 目录权限模式（Permissions mode for the directory）
*/
void mkdir(const char* path, mode_t mode);
/**
 * mkfifo - 创建FIFO文件（Create a FIFO File）
 * @param path FIFO文件路径（Path to the FIFO file）
 * @param mode FIFO文件权限模式（Permissions mode for the FIFO file）
*/
void mkfifo(const char* path, mode_t mode);
/**
 * get_file_status - 获取文件状态（Get File Status）
 * @param path 文件路径（Path to the file）
 * @param stat_buf 存储文件状态的结构体引用（Reference to file_status structure to store file status）
*/
void get_file_status(const char* path, const file_status& stat_buf);
/**
 * umask - 设置文件创建掩码（Set File Creation Mask）
 * @param mask 新的文件创建掩码（New file creation mask）
*/
void umask(mode_t mask);