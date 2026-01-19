#pragma once

/**
 * symbol_table.h - 符号表头文件
 * @note 包含符号表相关的定义和函数声明
 */

#include "type.h"
#include "symbol_type.h"


/**
 * symbol_table - 符号表结构体
 * @note 包含符号表项的相关信息
 */
struct symbol_table {
    /**
     * 符号名称联合体
     * 用于存储符号名称或相关信息
     */
    union {
        int8_t* symbol_name;        // 直接符号名称指针
        symbol_table* symbol_next;  // 符号链表中的下一个条目
        int64_t string_table_index; // 字符串表中的索引
    } symbol_un;

    basic_symbol_type basic;         // 基本符号类型
    attribute_flag attribute;        // 符号属性标识
    special_symbols special;         // 特殊符号标识
    debugging_symbol_type debugging; // 调试符号标识

    int16_t symbol_other;          // 辅助信息
    int32_t symbol_desc;          // 描述符（调试信息等）
    uint64_t symbol_value;        // 符号值/地址


    symbol_table() : symbol_un(), basic(basic_symbol_type::null_flag), attribute(attribute_flag::null_flag), special(special_symbols::null_flag), debugging(debugging_symbol_type::null_flag), symbol_other(0), symbol_desc(0), symbol_value(0) {}
    ~symbol_table() {};
};
