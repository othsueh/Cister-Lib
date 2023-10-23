/**
 * @file cursor.h
 * @author othsueh (github.com/othsueh)
 * @brief The cursor header file of Cister Lib.
 * @version 
 * @date 
 * 
 * @copyright Copyright (c) 2023 This work by othsueh is licensed under CC BY-NC-SA 4.0 
 * 
 */

#ifndef __CISTER_UTILS_CURSOR_H
#define __CISTER_UTILS_CURSOR_H
#include <stdint.h>
#define ESC "\x1b"
#define CSI "\x1b["

void __cursor_origin()
{
    printf(CSI "H");
}
void __cursor_to_pos(uint16_t x,uint16_t y)
{
    printf(CSI "%d;%dH",x,y);
}
void __cursor_get_pos()
{
    printf(CSI "6n");
}
void __cursor_up(uint16_t n)
{
    printf(CSI "%dA",n);
}
void __cursor_down(uint16_t n)
{
    printf(CSI "%dB",n);
}
void __cursor_forward(uint16_t n)
{
    printf(CSI "%dC",n);
}
void __cursor_backward(uint16_t n)
{
    printf(CSI "%dD",n);
}
void __cursor_next_line(uint16_t n)
{
    printf(CSI "%dE",n);
}
void __cursor_prev_line(uint16_t n)
{
    printf(CSI "%dF",n);
}
void __cursor_horiz_abs(uint16_t n)
{
    printf(CSI "%dG",n);
}
void __cursor_save_pos()
{
    printf(ESC "7");
}
void __cursor_restore_pos()
{
    printf(ESC "8");
}

struct {
    void (*origin)();
    void (*to_pos)(uint16_t x,uint16_t y);
    void (*get_pos)();
    void (*up)(uint16_t n);
    void (*down)(uint16_t n);
    void (*forward)(uint16_t n);
    void (*backward)(uint16_t n);
    void (*next_line)(uint16_t n);
    void (*prev_line)(uint16_t n);
    void (*horiz_abs)(uint16_t n);
    void (*save_pos)();
    void (*restore_pos)();
} Cursor = {
    .origin = __cursor_origin,
    .to_pos = __cursor_to_pos,
    .get_pos = __cursor_get_pos,
    .up = __cursor_up,
    .down = __cursor_down,
    .forward = __cursor_forward,
    .backward = __cursor_backward,
    .next_line = __cursor_next_line,
    .prev_line = __cursor_prev_line,
    .horiz_abs = __cursor_horiz_abs,
    .save_pos = __cursor_save_pos,
    .restore_pos = __cursor_restore_pos
};
#endif // __CISTER_UTILS_CURSOR_H