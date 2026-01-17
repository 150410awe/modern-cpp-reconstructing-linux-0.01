#pragma once

#include <cstdint>


/*
 * files_and_directories_error - 文件和目录错误码（Files and Directories Error Codes）
 * 这些错误码表示在操作文件或目录时可能出现的错误情况。
*/
enum class files_and_directories_error : int32_t {
    null_error = 0, // 无错误（No error）
    enoent, // 没有该文件或目录（No such file or directory）
    enotdi, // 不是目录（Not a directory）
    eisdir, // 是目录（Is a directory）
    eexist, // 文件已存在（File exists）
    exdev, // 跨设备链接（Cross-device link）
    enametoolong, // 文件名过长（Name too long）
    enotempty, // 目录非空（Directory not empty）
    emlink, // 链接数过多（Too many links）
    ebig, // 文件太大（File too large）
    enospc, // 无空间（No space left on device）
};
