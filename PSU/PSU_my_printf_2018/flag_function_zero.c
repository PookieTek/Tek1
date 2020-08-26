/*
** EPITECH PROJECT, 2018
** flag_function
** File description:
** flag function
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "include/my.h"

int flag_d(va_list list)
{
    my_put_nbr(va_arg(list, long));
    return (1);
}

int flag_i(va_list list)
{
    my_put_nbr(va_arg(list, long));
    return (1);
}

int flag_c(va_list list)
{
    my_putchar(va_arg(list, int));
    return (1);
}

int flag_s(va_list list)
{
    my_putstr(va_arg(list, char *));
    return (1);
}

int flag_o(va_list list)
{
    my_put_nbr_base(va_arg(list, long), "01234567", 0);
    return (1);
}
