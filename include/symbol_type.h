#pragma once

/**
 * symbol_type.h - 符号类型头文件
 * @note 包含符号类型相关的定义和函数声明
 */


#include "type.h"

/**
 * basic_symbol_type - 基本符号类型枚举
 * @note 包含基本符号类型的相关定义
 */
enum class basic_symbol_type : uint8_t {
    null_flag = 0,
    N_UNDF,    /* 未定义符号 */
    N_ABS,    /* 绝对地址符号 */
    N_TEXT,    /* 代码段符号 */
    N_DATA,    /* 数据段符号 */
    N_BSS,    /* BSS段符号 */
    N_COMM,    /* 公共符号 */
    N_FN,    /* 文件名符号 */
};

/* 典型的调试符号定义（在 Linux 0.01 中缺失） */

/*
 * 调试符号类型（Debugging Symbol Type）
 * @note 包含调试符号的相关定义和函数声明
 * 原来的调试符号类型定义在 Linux 0.01 怎么还他奶的没有
*/
enum class debugging_symbol_type : uint8_t {
    null_flag = 0,
    N_GSYM,    /* 全局变量 */
    N_FNAME,    /* 函数名称 */
    N_FUN,    /* 函数 */
    N_STSYM,    /* 静态变量 */
    N_LCSYM,    /* 局部变量 */
    N_MAIN,    /* 主函数名 */
    N_SLINE,    /* 源代码行号 */
    N_SO,    /* 源文件名称 */
    N_LSYM,    /* 局部变量 */
    N_PSYM,    /* 参数符号 */
    N_RSYM,    /* 寄存器符号 */
    N_LBRAC,    /* 左括号 (块开始) */
    N_RBRAC,    /* 右括号 (块结束) */
};

/**
 * special_symbols - 特殊符号枚举
 * @note 包含特殊符号的相关定义
 */
enum class special_symbols : uint8_t {
    null_flag = 0,
    N_INDR,   /* 间接引用符号 */
    N_SETA,  /* 绝对集合元素符号 */
    N_SETT,  /* 代码集合元素符号 */
    N_SETD,  /* 数据集合元素符号 */
    N_SETB,  /* BSS集合元素符号 */
    N_SETV,  /* 集合向量指针 */
};

/**
 * attribute_flag - 属性标志枚举
 * @note 包含符号属性的相关定义
 */
enum class attribute_flag : uint8_t {
    null_flag = 0,
    N_EXT,    /* 外部符号 */
};



#if 0
linus日常怎么用, 又是一个变量存怎么多东西, 还要 & 或 | 把其他东西去掉, 上面的代码直接 == 对比
没有& 或 | ,开悄
#ifndef N_UNDF
#define N_UNDF 0
#endif
#ifndef N_ABS
#define N_ABS 2
#endif
#ifndef N_TEXT
#define N_TEXT 4
#endif
#ifndef N_DATA
#define N_DATA 6
#endif
#ifndef N_BSS
#define N_BSS 8
#endif
#ifndef N_COMM
#define N_COMM 18
#endif
#ifndef N_FN
#define N_FN 15
#endif

#ifndef N_EXT
#define N_EXT 1
#endif
#ifndef N_TYPE
#define N_TYPE 036
#endif
#ifndef N_STAB
#define N_STAB 0340
#endif

#define N_INDR 0xa
#define	N_SETA	0x14		/* Absolute set element symbol */
#define	N_SETT	0x16		/* Text set element symbol */
#define	N_SETD	0x18		/* Data set element symbol */
#define	N_SETB	0x1A		/* Bss set element symbol */
#define N_SETV	0x1C		/* Pointer to set vector in data area.  */
#endif

