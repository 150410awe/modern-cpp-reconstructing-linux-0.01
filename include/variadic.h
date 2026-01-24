#pragma once

/**
 * stdarg.h - 可变参数头文件（Variadic Header File）
 * @note 包含可变参数相关的定义和函数声明
*/

#include "type.h"

struct variadic {
    char* ap;

    variadic(char* ap) : ap(ap) {}
    ~variadic() {}   //va_end(AP)
};

namespace variadic_parameter {
    /**
     * calculate_alignment_space - 计算类型的对齐空间（Alignment Space）
     * @tparam type_t 类型参数（Type Parameter）
     * @return size_t 对齐空间大小（Alignment Space Size）
    */
    template<typename type_t>
    constexpr size_t calculate_alignment_space() {
        return ((sizeof(type_t) + sizeof(int64_t) - 1) / sizeof(int64_t)) * sizeof(int64_t);
    }

    /**
     * initialization_va_list - 初始化 variadic 指针（Initialize va_list Pointer）
     * @param ap variadic 指针（va_list Pointer）
     * @param lastarg 最后一个参数（Last Argument）
     * @note 初始化 variadic 指针，将其指向最后一个参数之后的对齐空间（Alignment Space）
    */
    template<typename type_t>
    inline void initialization_va_list(variadic& ap, type_t& lastarg) {
        ap.ap = static_cast<char*>(&lastarg) + calculate_alignment_space<type_t>();
    }

    /**
     * next_parameter - 获取下一个参数的地址（Get Address of Next Parameter）
     * @param ap variadic 指针（va_list Pointer）
     * @tparam next_t 下一个参数的类型（Type of Next Parameter）
     * @return const next_t& 下一个参数的地址（Address of Next Parameter）
     * @note 获取下一个参数的地址，将 variadic 指针移动到下一个参数的对齐空间（Alignment Space）, 注意生命周期约束!!!不然会导致悬空指针
    */
    template<typename next_t>
    inline const next_t& next_parameter(variadic& ap) {
        const next_t& ret = *reinterpret_cast<const next_t*>(ap.ap);
        ap.ap += calculate_alignment_space<next_t>();
        return ret;
    }

#if 0
    const next_t& next_parameter(...)...
        关与const next_t& 与C的返回 拷贝
        你怎么知道next_t可以返回副本, 比如class把考贝禁了呢 ? 还有用户不一定要副本, const next_t& 就是没有考贝成本, 你要考贝才有考贝成本没有就没有, 这不是很c++ ?

#define va_arg(AP, TYPE)						\
 (AP += __va_rounded_size (TYPE),					\
  *((TYPE *) (AP - __va_rounded_size (TYPE))))
#endif

    /**
     * next_parameter_value - 获取下一个参数的值（Get Value of Next Parameter）
     * @param ap variadic 指针（va_list Pointer）
     * @tparam next_t 下一个参数的类型（Type of Next Parameter）
     * @return next_t 下一个参数的值（Value of Next Parameter）
     * @note 获取下一个参数的值，利用拷贝构造函数（Copy Constructor）返回副本（如果类型支持），否则返回引用（如果类型不支持）
     */
    template<typename next_t>
    inline next_t next_parameter_value(variadic & ap) {
        return next_parameter<next_t>(ap); // 利用拷贝构造
    }
}