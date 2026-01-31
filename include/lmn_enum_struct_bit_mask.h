#pragma once

#include "type.h"

/**
 * lmn_enum_struct_prototype - 枚举结构体位掩码（Enum Struct Bit Mask）
 * @note 用于表示枚举类型的位掩码，支持按位操作
 * @tparam struct_t - 枚举结构体类型（Enum Struct Type）
 * @tparam enum_t - 枚举类型（Enum Type）
 * @note lmn - 我的网名, enum - 强调 枚举类型 struct - 强调 结构体类型 prototype - 强调 原始实现
 * 我觉得这是非常不错.
 */
template <typename struct_t, typename enum_t>
struct lmn_enum_struct_prototype {
    lmn_enum_struct_prototype(int64_t data) : data { data } {}
    lmn_enum_struct_prototype() : data { 0 } {}
    constexpr struct_t operator|= (enum_t a) { return this->data |= static_cast<int64_t>(a); }
    constexpr struct_t operator|(enum_t a) const { return struct_t { this->data | static_cast<int64_t>(a) }; }
    constexpr struct_t operator&= (enum_t a) { return this->data &= static_cast<int64_t>(a); }
    constexpr struct_t operator&(enum_t a) const { return struct_t { this->data & static_cast<int64_t>(a) }; }
    constexpr struct_t operator^(enum_t a) const { return struct_t { this->data ^ static_cast<int64_t>(a) }; }
    constexpr struct_t operator~(void) const { return struct_t { ~this->data }; }
    constexpr struct_t operator=(enum_t a) { return this->data = static_cast<int64_t>(a); }
    constexpr bool operator!(void) const { return this->data == 0; }
    constexpr bool operator==(lmn_enum_struct_prototype a) const { return this->data == a.data; }
    constexpr bool operator!=(lmn_enum_struct_prototype a) const { return !(*this == a); }
    int64_t data;
};