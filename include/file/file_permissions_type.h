#pragma once


#include "../type.h"
#include <string_view>

/**
 * file_user_permissions_type - 文件权限枚举（File Permissions Enumeration）
 * @note 表示文件的不同权限,我为什么要符合Unix标准???我想怎么地怎么地,别错就okk了
 * 所有者权限 | 组权限 | 其他用户权限
*/
enum class file_permissions_type : uint16_t {
    none = 0,
    S_IRWXU = 00700,  // 用户读、写、执行权限
    S_IRUSR = 00400,  // 用户读权限
    S_IWUSR = 00200,  // 用户写权
    S_IXUSR = 00100,  // 用户执行权限

    S_IRWXO = 00007,  // 其他用户读、写、执行权限
    S_IRWXG = 00070,  // 组读、写、执行权限
    S_IRGRP = 00040,  // 组读权限
    S_IWGRP = 00020,  // 组写权限
    S_IXGRP = 00010,  // 组执行权限

    S_IRWXO = 00007,  // 其他用户读、写、执行权限
    S_IROTH = 00004,  // 其他用户读权限
    S_IWOTH = 00002,  // 其他用户写权限
    S_IXOTH = 00001,  // 其他用户执行权限

    /*
    set_user_id = 1 << 12, // 设置用户ID位
    set_group_id = 1 << 11,   // 设置组ID位
    sticky_bit = 1 << 10,    // 粘滞位
    all_permissions = read_write_execute | group_read_write_execute | other_read_write_execute,  // 所有权限
    */
};


#include "../lmn_enum_struct_bit_mask.h"

struct file_permissions_enum_struct : lmn_enum_struct_prototype<file_permissions_enum_struct, file_permissions_type> {
    using lmn_enum_struct_prototype<file_permissions_enum_struct, file_permissions_type>::lmn_enum_struct_prototype;
};
