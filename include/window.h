#pragma once

/**
 * @file window.h
 * @brief 终端窗口大小结构体（Window Size Structure）
 * @note 包含终端窗口的行数、列数、宽度（像素）和高度（像素）
 */

#include "type.h"

/**
 * winsize - 终端窗口大小结构体（Window Size Structure）
 * @note 包含终端窗口的行数、列数、宽度（像素）和高度（像素）
 */
struct winsize {
    uint16_t ws_row;      // 终端行数
    uint16_t ws_col;      // 终端列数
    uint16_t ws_xpixel;   // 终端宽度（像素）
    uint16_t ws_ypixel;   // 终端高度（像素）

    winsize() : ws_row(0), ws_col(0), ws_xpixel(0), ws_ypixel(0) {}
    ~winsize() = default;
};