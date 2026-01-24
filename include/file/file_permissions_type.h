#pragma once


#include "../type.h"
#include <string_view>

/**
 * file_user_permissions_type - 文件权限枚举（File Permissions Enumeration）
 * @note 表示文件的不同权限,我为什么要符合Unix标准???我想怎么地怎么地,别错就okk了
*/
enum class file_permissions_type : uint16_t {
    none = 0,
    read = 1 << 8,  // 用户读权限
    write = 1 << 7,  // 用户写权限  
    execute = 1 << 6,  // 用户执行权限
    read_write_execute = read | write | execute,  // 用户读、写、执行权限

    group_read = 1 << 5,  // 组读权限
    group_write = 1 << 4,  // 组写权限
    group_execute = 1 << 3,  // 组执行权限
    group_read_write_execute = group_read | group_write | group_execute,  // 组读、写、执行权限

    other_read = 1 << 2,  // 其他用户读权限
    other_write = 1 << 1,  // 其他用户写权限
    other_execute = 1 << 0,  // 其他用户执行权限
    other_read_write_execute = other_read | other_write | other_execute,  // 其他用户读、写、执行权限

    set_user_id = 1 << 12, // 设置用户ID位
    set_group_id = 1 << 11,   // 设置组ID位
    sticky_bit = 1 << 10,    // 粘滞位
    all_permissions = read_write_execute | group_read_write_execute | other_read_write_execute,  // 所有权限
};


#include "../lmn_enum_struct_bit_mask.h"

struct file_permissions_enum_struct : lmn_enum_struct_prototype<file_permissions_enum_struct, file_permissions_type> {
    using lmn_enum_struct_prototype<file_permissions_enum_struct, file_permissions_type>::lmn_enum_struct_prototype;
};

/**
 * chmod - 修改文件权限（Change File Permissions）
 * @param path 文件路径（Path to the file）
 * @param mode 新的权限模式（New permissions mode）
*/
void chmod(std::string_view path, file_permissions_enum_struct mode);
