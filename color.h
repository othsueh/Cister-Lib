/**
 * @file color.h
 * @author othsueh (github.com/othsueh)
 * @brief The color header file of Cister Lib.
 * @version 
 * @date 
 * 
 * @copyright Copyright (c) 2023 This work by othsueh is licensed under CC BY-NC-SA 4.0 
 * 
 */

#ifndef __CISTER_UTILS_COLOR_H_
#define __CISTER_UTILS_COLOR_H_
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#define CSI "\x1b["
#define RES CSI "0m"
typedef uint8_t u8;

typedef enum _Graphic{
    GDEFAULT = 0,
    BOLD,
    DIM,
    ITALIC,
    UNDERLINE,
    BLINK,
    REVERSE=7,
    HIDE,
    STRIKE
}_Graphic;

_Graphic graphic;
typedef enum _Color {
    CDEFAULT = 0,
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
}_Color;
_Color foreground, background;

typedef enum _ColorMode {
    MDEFAULT = 0,
    BIRGHT,
}_ColorMode;
typedef struct {
    u8 r, g, b;
}RGB; 
char * __color_pick(_Graphic graphic_choice, _Color foreground_choice, _Color background_choice, _ColorMode mode_choice)
{
    u8 graphic_pick = 0, foreground_pick = 0, background_pick = 0, mode_pick = 0; 
    char *color_pick_str = (char *)malloc(sizeof(char) * 20);
    for(graphic = (_Graphic)GDEFAULT; graphic <= STRIKE; graphic++)
    {
        if(graphic_choice == graphic)
        {
            graphic_pick = graphic;
            break;
        }
    }
    for(foreground = (_Color)CDEFAULT; foreground <= WHITE; foreground++)
    {
        if(foreground_choice == foreground)
        {
            if(foreground_choice == GDEFAULT)
                foreground_pick = 39;
            else
                foreground_pick = foreground + 29;
            break;
        }
    }
    for(background = (_Color)CDEFAULT; background <= WHITE; background++)
    {
        if(background_choice == background)
        {
            if(background_choice == CDEFAULT)
                background_pick = 49;
            else
                background_pick = background + 39;
            break;
        }
    }
    if(mode_choice == BIRGHT){
        if(foreground_pick != 39)
            foreground_pick += 60;
        if(background_pick != 49)
            background_pick += 60;
    }
    snprintf(color_pick_str, 20, CSI "%d;%d;%dm", graphic_pick, foreground_pick, background_pick);
    return color_pick_str;
}

char * __color_pick_256(_Graphic graphic_choice, u8 foreground_choice, u8 background_choice)
{
    u8 graphic_pick = 0;
    char *color_pick_str = (char *)malloc(sizeof(char) * 20);
    for(graphic = (_Graphic)GDEFAULT; graphic <= STRIKE; graphic++)
    {
        if(graphic_choice == graphic)
        {
            graphic_pick = graphic;
            break;
        }
    }
    if(foreground_choice == 0)
        foreground_choice = 7;
    if(background_choice == 0)
        background_choice = 234;
    snprintf(color_pick_str, 20, CSI "%d;38;5;%d;48;5;%dm", graphic_pick, foreground_choice, background_choice);
    return color_pick_str;
}
char * __color_pick_rgb(_Graphic graphic_choice, const char * foreground_rgb, const char * background_rgb)
{
    RGB foreground = {0,0,0};
    RGB background = {0,0,0};
    char *color_pick_str = (char *)malloc(sizeof(char) * 50);
    u8 graphic_pick = 0;
    for(graphic = (_Graphic)GDEFAULT; graphic <= STRIKE; graphic++)
    {
        if(graphic_choice == graphic)
        {
            graphic_pick = graphic;
            break;
        }
    }
    int _ = sscanf(foreground_rgb, "%02x%02x%02x", &foreground.r, &foreground.g, &foreground.b);
    int __ = sscanf(background_rgb, "%02x%02x%02x", &background.r, &background.g, &background.b);
    snprintf(color_pick_str, 50, CSI "%d;38;2;%d;%d;%d;48;2;%d;%d;%dm", graphic_pick, foreground.r, foreground.g, foreground.b, background.r, background.g, background.b);
    return color_pick_str;
}


struct {
    char * (*pick)(_Graphic graphic_choice, _Color foreground_choice, _Color background_choice, _ColorMode mode_choice);
    char * (*pick256)(_Graphic graphic_choice, u8 foreground_choice, u8 background_choice);
    char * (*pickrgb)(_Graphic graphic_choice, const char *foreground_rgb, const char *background_rgb);
} Color = {
    .pick = __color_pick,
    .pick256 = __color_pick_256,
    .pickrgb = __color_pick_rgb
};
#endif