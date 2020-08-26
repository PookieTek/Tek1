/*
** EPITECH PROJECT, 2018
** printf
** File description:
** printf
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "include/my.h"
#include "include/print.h"

int call_function(int i, va_list list)
{
    int (*function_flag[13])(va_list);

    function_flag[0] = flag_d;
    function_flag[1] = flag_i;
    function_flag[2] = flag_c;
    function_flag[3] = flag_s;
    function_flag[4] = flag_ss;
    function_flag[5] = flag_o;
    function_flag[6] = flag_b;
    function_flag[7] = flag_x;
    function_flag[8] = flag_xx;
    function_flag[9] = flag_p;
    function_flag[10] = flag_u;
    function_flag[11] = flag_m;
    function_flag[12] = flag_percent;
    return ((*function_flag[i])(list));
}

int exec_arg(int i, va_list list, char c)
{
    char *carac = "dicsSobxXpum%";

    for (int i = 0; i < 13; i = i + 1) {
        if (carac[i] == c)
            return (call_function(i, list));
    }
    return (0);
}

int get_first_flag(int i, char *str)
{
    int a = 0;

    if (str[i + a + 1] == '+')
        my_putchar('+');
    while (str[i + a + 1] == 'h' || str[i + a + 1] == 'l')
        a = a + 1;
    return (a);
}

int my_printf(char *str, ...)
{
    va_list list;
    int i = 0;
    int a = 1;

    va_start(list, str);
    while (str[i] != '\0') {
        if (str[i] != '%')
            my_putchar(str[i]);
        if (str[i] == '%') {
            a = a + get_first_flag(i, str);
            i = i + exec_arg(i, list, str[i + a]);
        }
        if (a == 2) {
            a = 1;
            i = i + 1;
        }
        i = i + 1;
    }
    va_end(list);
    return (0);
}
