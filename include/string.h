#pragma once

/*
 * string.h - 字符串处理头文件
*/

#include "type.h"

namespace string_processing {
    inline char* strerror(/*int32_t errno*/);

    inline void move_char_end(char* dest) {
        while (*dest != '\0')
            dest++;
    }

    /**
     * strcpy - 复制字符串
     * @param dst 目标字符串指针
     * @param src 源字符串指针
     * @return 指向目标字符串的指针
     * @note 复制 src 指向的字符串到 dst 指向的内存中，包括 null 终止符
    */
    inline char* strcpy(char* dst, const char* src) {
        char* dst_start = dst;
        while (*src != '\0')
            *dst++ = *src++;
        return dst_start;
    }

    /**
     * strncpy - 复制字符串
     * @param dest 目标字符串指针
     * @param src 源字符串指针
     * @param count 要复制的字符数
     * @return 指向目标字符串的指针
     * @note 复制 src [0, count) 到 dest 中，包括 null 终止符
    */
    inline char* strncpy(char* dest, char* src, const size_t count) {
        char* dst_start = dest;
        char* src_strcpy_end = src + count;
        char src_strcpy_end_temp = *src_strcpy_end;
        *src_strcpy_end = '\0';

        strcpy(dest, src);

        *src_strcpy_end = src_strcpy_end_temp;

        return dst_start;
    }

    /**
     * strncpy - 复制字符串
     * @param dest 目标字符串指针
     * @param src 源字符串指针
     * @param count 要复制的字符数
     * @return 指向目标字符串的指针
     * @note 复制 src [0, count) 到 dest 中，包括 null 终止符
    */
    inline char* strncpy(char* dest, const char* src, const size_t count) {
        char* dst_start = dest;

        for (size_t i = 0; i < count; i++)
            dest[i] = src[i];
        dest[count] = '\0';

        return dst_start;
    }

    /**
     * strcat - 连接字符串
     * @param dest 目标字符串指针
     * @param src 源字符串指针
     * @return 指向目标字符串的指针
     * @note 连接 src 指向的字符串到 dest 指向的字符串末尾，包括 null 终止符
    */
    inline char* strcat(char* dest, const char* src) {
        char* dst_start = dest;

        move_char_end(dest);
        strcpy(dest, src);

        *dest = '\0';
        return dst_start;
    }

    /**
     * strncat - 连接字符串
     * @param dest 目标字符串指针
     * @param src 源字符串指针
     * @param count 要连接的字符数
     * @return 指向目标字符串的指针
     * @note 连接 src [0, count) 到 dest 指向的字符串末尾，包括 null 终止符
    */
    inline char* strncat(char* dest, const char* src, int32_t count) {
        char* dst_start = dest;

        move_char_end(dest);
        strncpy(dest, src, count);

        *dest = '\0';
        return dst_start;
    }

    /**
     * strcmp - 比较字符串
     * @param cs 第一个字符串指针
     * @param ct 第二个字符串指针
     * @return 比较结果
     * @note 比较 cs 和 ct 指向的字符串，返回值为：
     *       - 小于 0：cs 小于 ct
     *       - 等于 0：cs 等于 ct
     *       - 大于 0：cs 大于 ct
    */
    inline int32_t strcmp(const char* cs, const char* ct) {
        while (*cs == *ct) {
            if (*cs == '\0')
                return 0;
            cs++;
            ct++;
        }
        return *cs - *ct;
    }

    /**
     * strncmp - 比较字符串
     * @param cs 第一个字符串指针
     * @param ct 第二个字符串指针
     * @param count 要比较的字符数
     * @return 比较结果
     * @note 比较 cs [0, count) 和 ct [0, count) 指向的字符串，返回值为：
     *       - 小于 0：cs 小于 ct
     *       - 等于 0：cs 等于 ct
     *       - 大于 0：cs 大于 ct
    */
    inline int32_t strncmp(const char* cs, const char* ct, int32_t count) {
        while (count-- > 0) {
            if (*cs != *ct)
                return *cs - *ct;
            if (*cs == '\0')
                return 0;
            cs++;
            ct++;
        }
        return 0;
    }


    /**
     * strchr - 查找字符
     * @param s 字符串指针
     * @param c 要查找的字符
     * @return 指向第一个出现的字符的指针
     * @note 查找 s 指向的字符串中第一个出现的字符 c，返回其指针
    */
    inline const char* strchr(const char* s, char c) {
        while (*s != '\0') {
            if (*s == c)
                return s;
            s++;
        }
        return nullptr;
    }

    /**
     * strrchr - 查找字符
     * @param s 字符串指针
     * @param c 要查找的字符
     * @return 指向最后一个出现的字符的指针
     * @note 查找 s 指向的字符串中最后一个出现的字符 c，返回其指针
    */
    inline const char* strrchr(const char* s, char c) {
        const char* last = nullptr;
        while (*s != '\0') {
            if (*s == c)
                last = s;
            s++;
        }
        return last;
    }

    /**
     * strspn - 计算字符串的前缀长度
     * @param cs 字符串指针
     * @param ct 字符集指针
     * @return 前缀长度
     * @note 计算 cs 指向的字符串中，从开头开始连续出现的字符都在 ct 指向的字符集中的字符数
    */
    inline int32_t strspn(const char* cs, const char* ct) {
        const char* s = cs;
        const char* t;

        while (*s) {
            for (t = ct; *t; t++)
                if (*s == *t)
                    break;
            if (*t == '\0')
                break;
            s++;
        }

        return s - cs;
    }

    /**
     * strcspn - 计算字符串前缀中不包含指定字符集的长度
     * @param cs 字符串指针
     * @param ct 字符集指针
     * @return 前缀长度
     * @note 计算 cs 指向的字符串中，从开头开始连续出现的字符都不在 ct 指向的字符集中的字符数
    */
    inline int32_t strcspn(const char* cs, const char* ct) {
        const char* s = cs;
        const char* t;

        while (*s) {
            for (t = ct; *t; t++)
                if (*s == *t)
                    return s - cs;
            s++;
        }

        return s - cs;
    }

    /**
     * strpbrk - 查找字符串中第一个出现的字符集中的字符
     * @param cs 字符串指针
     * @param ct 字符集指针
     * @return 指向第一个出现的字符的指针
     * @note 查找 cs 指向的字符串中第一个出现的字符都在 ct 指向的字符集中的字符，返回其指针
    */
    inline const char* strpbrk(const char* cs, const char* ct) {
        const char* s = cs;
        const char* t;

        while (*s) {
            for (t = ct; *t; t++)
                if (*s == *t)
                    return s;
            s++;
        }

        return nullptr;
    }

    /**
     * strstr - 查找子字符串
     * @param cs 字符串指针
     * @param ct 子字符串指针
     * @return 指向子字符串第一次出现的指针
     * @note 在 cs 指向的字符串中查找 ct 指向的子字符串，返回其指针
    */
    inline const char* strstr(const char* cs, const char* ct) {
        if (*ct == '\0')
            return cs;


        const char* s = cs;
        while (*s) {
            const char* p = s;
            const char* q = ct;

            while (*p && *q && *p == *q) {
                p++;
                q++;
            }

            if (*q == '\0')
                return s;

            s++;
        }

        return nullptr;
    }

    /**
     * strlen - 计算字符串长度
     * @param s 字符串指针
     * @return 字符串长度
     * @note 计算 s 指向的字符串的长度，不包括 null 终止符
    */
    inline int32_t strlen(const char* s) {
        const char* p = s;

        while (*p)
            p++;

        return p - s;
    }

    /**
     * strtok - 字符串分割
     * @param s 字符串指针
     * @param ct 分隔符字符集
     * @return 指向分割后的子字符串的指针
     * @note 使用 ct 指向的字符集分割 s 指向的字符串，返回分割后的子字符串指针
    */
    inline char* strtok(char* s, const char* ct) {

        static char* strtok;

        if (!s)
            s = strtok;
        if (!s)
            return nullptr;


        // 跳过开头的分隔符
        while (*s) {
            bool is_delim = false;
            for (const char* t = ct; *t; t++)
                if (*s == *t) {
                    is_delim = true;
                    break;
                }

            if (!is_delim)
                break;

            s++;
        }

        if (*s == '\0') {
            strtok = nullptr;
            return nullptr;
        }

        char* start = s;

        // 查找下一个分隔符
        while (*s) {
            bool is_delim = false;
            for (const char* t = ct; *t; t++)
                if (*s == *t) {
                    is_delim = true;
                    break;
                }

            if (is_delim) {
                *s = '\0';
                strtok = s + 1;
                return start;
            }
            s++;
        }

        strtok = nullptr;
        return start;
    }

    /**
     * memcpy - 内存复制
     * @param dest 目标内存指针
     * @param src 源内存指针
     * @param n 要复制的字节数
     * @return 指向目标内存的指针
     * @note 复制 src 指向的内存中的 n 个字节到 dest 指向的内存中
    */
    inline void* memcpy(void* dest, const void* src, int32_t n) {
        char* d = static_cast<char*>(dest);
        const char* s = static_cast<const char*>(src);

        for (int32_t i = 0; i < n; i++)
            d[i] = s[i];


        return dest;
    }

    /**
     * memmove - 内存移动
     * @param dest 目标内存指针
     * @param src 源内存指针
     * @param n 要移动的字节数
     * @return 指向目标内存的指针
     * @note 移动 src 指向的内存中的 n 个字节到 dest 指向的内存中，支持重叠内存
    */
    inline void* memmove(void* dest, const void* src, int32_t n) {
        char* d = static_cast<char*>(dest);
        const char* s = static_cast<const char*>(src);

        if (d < s || d >= s + n)
            // 没有重叠，直接复制
            for (int32_t i = 0; i < n; i++)
                d[i] = s[i];

        else
            // 有重叠，从后往前复制
            for (int32_t i = n - 1; i >= 0; i--)
                d[i] = s[i];



        return dest;
    }

    /**
     * memcmp - 内存比较
     * @param cs 第一个内存块指针
     * @param ct 第二个内存块指针
     * @param count 要比较的字节数
     * @return 比较结果
     * @note 比较 cs 和 ct 指向的内存块中的 count 个字节，返回值为：
     *       - 小于 0：cs 小于 ct
     *       - 等于 0：cs 等于 ct
     *       - 大于 0：cs 大于 ct
    */
    inline int32_t memcmp(const void* cs, const void* ct, int32_t count) {
        const u_char* c1 = static_cast<const u_char*>(cs);
        const u_char* c2 = static_cast<const u_char*>(ct);

        for (int32_t i = 0; i < count; i++)
            if (c1[i] != c2[i])
                return c1[i] - c2[i];

        return 0;
    }

    /**
     * memchr - 查找内存中的字符
     * @param cs 内存块指针
     * @param c 要查找的字符
     * @param count 要查找的字节数
     * @return 指向第一个出现的字符的指针
     * @note 在 cs 指向的内存块中查找字符 c，返回其指针
    */
    inline void* memchr(const void* cs, char c, int32_t count) {
        const u_char* p = static_cast<const u_char*>(cs);
        u_char uc = static_cast<u_char>(c);

        for (int32_t i = 0; i < count; i++)
            if (p[i] == uc)
                return const_cast<void*>(static_cast<const void*>(p + i));

        return nullptr;
    }

    /**
     * memset - 内存设置
     * @param s 内存块指针
     * @param c 要设置的字符
     * @param count 要设置的字节数
     * @return 指向内存块的指针
     * @note 将 s 指向的内存块中的 count 个字节设置为字符 c
    */
    inline void* memset(void* s, char c, int32_t count) {
        u_char* p = static_cast<u_char*>(s);
        u_char uc = static_cast<u_char>(c);

        for (int32_t i = 0; i < count; i++)
            p[i] = uc;

        return s;
    }

}