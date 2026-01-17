/**
 * error.h - 错误码（Error Code Definitions）
 * 改进了错误码定义，使其更清晰易读。
 * 这里主要是error集合,还有存错误的全局变量,没想好放在哪里的异常处理
*/

#include <cstdint>

/* 错误码定义（Error Code Definitions） */

/*
 * mathematical_calculation_error - 数学计算错误码（Mathematical Calculation Error Codes）
 * 这些错误码表示在进行数学计算时可能出现的错误情况。
*/
enum class mathematical_calculation_error : int32_t {
    null_error = 0, // 无错误（No error）
    edom, // 域错误，数学计算超出了定义的域范围
    erange, // 范围错误，数学计算结果超出了表示范围
};

/*
 * general_error - 通用错误码（General Error Codes）
 * 这些错误码表示在执行系统调用或函数时，未被分类的错误情况。
*/
enum class general_error : int32_t {
    null_error = 0, // 无错误（No error）
    error = 1, // 通用错误，未分类的错误
};


#include "process/process_error.h"
#include "file/file_error.h"
#include "system/system_error.h"

// 全局变量,用 inline 不知为什么，会报错

thread_local permission_error global_permission_error = permission_error::null_error;
thread_local files_and_directories_error global_files_and_directories_error = files_and_directories_error::null_error;
thread_local resources_error global_resources_error = resources_error::null_error;
thread_local equipment_error global_equipment_error = equipment_error::null_error;
thread_local system_call_error global_system_call_error = system_call_error::null_error;
thread_local process_error global_process_error = process_error::null_error;
thread_local mathematical_calculation_error global_mathematical_calculation_error = mathematical_calculation_error::null_error;
thread_local general_error global_general_error = general_error::null_error;
