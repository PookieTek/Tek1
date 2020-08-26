/*
** EPITECH PROJECT, 2018
** function flag
** File description:
** function flag
*/

#include "include/my.h"
#include <stdarg.h>
#include <stdio.h>

int flag_m(va_list list)
{
    return (1);
}

int flag_percent(va_list list)
{
    my_putchar('%');
    return (1);
}

int flag_ss(va_list list)
{
    char *str = va_arg(list, char *);

    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] < 32 || str[i] > 126) {
            my_putchar('\\');
            my_put_nbr_base(str[i], "0123456789ABCDEF", 0);
        }
        else
            my_putchar(str[i]);
    }
    return (1);
}
