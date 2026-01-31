#pragma once

/**
 * time.h - 时间头文件
 * @note 包含时间相关的定义和函数声明
 * gmtime() 和 localtime() 的实现细节未明确,没有实现,我觉得没有必要实现
*/

#include "type.h"
#include <string_view>
/**
 * CLOCKS_PER_SEC - 每个秒的时钟滴答数
 * 用于计算程序运行时间,精度为 1 毫秒
 */
constexpr clock_t CLOCKS_PER_SEC = 1000;

struct time {
    uint8_t tm_sec;    // 秒 [0-59]
    uint8_t tm_min;    // 分 [0-59]
    uint8_t tm_hour;   // 时 [0-23]
    uint8_t tm_mday;   // 日 [1-31]
    uint8_t tm_mon;    // 月 [0-11]，0 表示一月
    uint8_t tm_year;   // 年，从 1900 开始的年数
    uint8_t tm_wday;   // 星期 [0-6]，0 表示星期日
    uint16_t tm_yday;   // 年内天数 [0-365]，0 表示一月一日
    int8_t tm_isdst;  // 夏令时标志，正数表示启用，0 表示禁用，负数表示未知

    time() : tm_sec(0), tm_min(0), tm_hour(0), tm_mday(1), tm_mon(0), tm_year(1900), tm_wday(0), tm_yday(0), tm_isdst(0) {}
    ~time() {}
    /**
     * get_clock - 获取时钟滴答数
     * @return 时钟滴答数
     */
    clock_t get_clock() const;
    /**
     * get_time - 获取时间戳
     * @param tp 可选参数，用于存储时间戳
     * @return 时间戳
     */
    time_t get_time() const;
    /**
     * difftime - 计算两个时间戳的差值（秒）
     * @param time2 时间戳2
     * @param time1 时间戳1
     * @return 时间戳2 与 时间戳1 的差值（秒）
     */
    double difftime(const time_t time2, const time_t time1) const { return time2 - time1; }
    /**
     * gmtime - 将时间戳转换为 UTC 时区的 struct time 结构体
     * @param tp 时间戳的引用
     * @return UTC 时区的 struct time 结构体指针
     */
    time gmtime(const time_t& tp) const;
    /**
     * localtime - 将时间戳转换为本地时区的 struct time 结构体
     * @param tp 时间戳的引用
     * @return 本地时区的 struct time 结构体
     */
    time localtime(const time_t& tp) const;

    /**
     * asctime - 将 struct time 转换为 ASCII 字符串
     * @param tp struct time 结构体的引用
     * @return 指向 ASCII 字符串的指针
     */
    std::string_view asctime(const time& tp) const;
    /**
     * ctime - 将时间戳转换为 ASCII 字符串
     * @param tp 时间戳的引用
     * @return 指向 ASCII 字符串的指针
     */
    std::string_view ctime(const time_t& tp) const;
    /**
     * strftime - 按指定格式格式化时间
     * @param smax 输出字符串的最大长度
     * @param fmt 格式化字符串的视图
     * @return 格式化后的字符串长度
     */
    std::string_view strftime(size_t smax, const std::string_view& fmt);
    /**
     * tzset - 初始化时区信息
     */
    void tzset();
};