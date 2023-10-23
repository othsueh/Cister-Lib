/**
 * @file erase.h
 * @author othsueh (github.com/othsueh)
 * @brief The erase header file of Cister Lib.
 * @version 
 * @date 
 * 
 * @copyright Copyright (c) 2023 This work by othsueh is licensed under CC BY-NC-SA 4.0 
 * 
 */

#ifndef __CISTER_UTILS_ERASE_H_
#define __CISTER_UTILS_ERASE_H_
#include <stdio.h>
#define CSI "\x1b["
void __erase_display()
{
    printf(CSI "J");
}
void __erase_entire()
{
    printf(CSI "2J");
}
void __erase_line()
{
    printf(CSI "K");
}
void __erase_line_back()
{
    printf(CSI "1K");
}
void __erase_line_entire()
{
    printf(CSI "2K");
}

struct {
    void (*display)();
    void (*entire)();
    void (*line)();
    void (*line_back)();
    void (*line_entire)();
} Erase = {
    .display = __erase_display,
    .entire = __erase_entire,
    .line = __erase_line,
    .line_back = __erase_line_back,
    .line_entire = __erase_line_entire
};

#endif