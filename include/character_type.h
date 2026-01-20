#pragma once

/**
 * character_type.h - 字符类型头文件
 * @note 包含字符类型相关的定义和函数声明
 */

#include "type.h"
#include <cctype>


/**
 * character_type - 字符类型命名空间
 * @note 包含字符类型相关的定义和函数声明
 */
namespace character_type {
    /**
     * is_letters_or_numbers - 检查字符是否为字母或数字
     * @param c 要检查的字符
     * @return 如果字符为字母或数字则返回 true，否则返回 false
    */
    constexpr bool is_letters_or_numbers(uint8_t c) {
        return isalnum(c);
    }
    /**
     * is_letters - 检查字符是否为字母
     * @param c 要检查的字符
     * @return 如果字符为字母则返回 true，否则返回 false
    */
    constexpr bool is_letters(uint8_t c) {
        return isalpha(c);
    }
    /**
     * is_numbers - 检查字符是否为数字
     * @param c 要检查的字符
     * @return 如果字符为数字则返回 true，否则返回 false
    */
    constexpr bool is_numbers(uint8_t c) {
        return isdigit(c);
    }
    /**
     * is_control - 检查字符是否为控制字符
     * @param c 要检查的字符
     * @return 如果字符为控制字符则返回 true，否则返回 false
    */
    constexpr bool is_control(uint8_t c) {
        return iscntrl(c);
    }
    /**
     * is_punctuation - 检查字符是否为标点符号
     * @param c 要检查的字符
     * @return 如果字符为标点符号则返回 true，否则返回 false
    */
    constexpr bool is_punctuation(uint8_t c) {
        return ispunct(c);
    }
    /**
     * is_whitespace - 检查字符是否为空白字符
     * @param c 要检查的字符
     * @return 如果字符为空白字符则返回 true，否则返回 false
    */
    constexpr bool is_whitespace(uint8_t c) {
        return isspace(c);
    }
    /**
     * is_graph - 检查字符是否为可打印字符（除空格外）
     * @param c 要检查的字符
     * @return 如果字符为可打印字符（除空格外）则返回 true，否则返回 false
    */
    constexpr bool is_graph(uint8_t c) {
        return isgraph(c);
    }
    /**
     * is_lowercase - 检查字符是否为小写字母
     * @param c 要检查的字符
     * @return 如果字符为小写字母则返回 true，否则返回 false
    */
    constexpr bool is_lowercase(uint8_t c) {
        return islower(c);
    }
    /**
     * is_printable - 检查字符是否为可打印字符
     * @param c 要检查的字符
     * @return 如果字符为可打印字符则返回 true，否则返回 false
    */
    constexpr bool is_printable(uint8_t c) {
        return isprint(c);
    }
    /**
     * is_uppercase - 检查字符是否为大写字母
     * @param c 要检查的字符
     * @return 如果字符为大写字母则返回 true，否则返回 false
    */
    constexpr bool is_uppercase(uint8_t c) {
        return isupper(c);
    }
    /**
     * is_hexadecimal - 检查字符是否为十六进制数字
     * @param c 要检查的字符
     * @return 如果字符为十六进制数字则返回 true，否则返回 false
    */
    constexpr bool is_hexadecimal(uint8_t c) {
        return isxdigit(c);
    }
    /**
     * is_ascii - 检查字符是否为 ASCII 码
     * @param c 要检查的字符
     * @return 如果字符为 ASCII 码则返回 true，否则返回 false
    */
    constexpr bool is_ascii(uint8_t c) {
        return isascii(c);
    }
    /**
     * to_ascii - 将字符转换为 ASCII 码
     * @param c 要转换的字符
     * @return 转换后的 ASCII 码
    */
    constexpr uint8_t to_ascii(uint8_t c) {
        return toascii(c);
    }
    /**
     * to_lowercase - 将字符转换为小写字母
     * @param c 要转换的字符
     * @return 转换后的小写字母
    */
    constexpr uint8_t to_lowercase(uint8_t c) {
        return tolower(c);
    }
    /**
     * to_uppercase - 将字符转换为大写字母
     * @param c 要转换的字符
     * @return 转换后的大写字母
    */
    constexpr uint8_t to_uppercase(uint8_t c) {
        return toupper(c);
    }
}