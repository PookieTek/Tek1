/*
** EPITECH PROJECT, 2018
** flag_function
** File description:
** flag function
*/

#include "include/my.h"
#include <stdarg.h>

int flag_b(va_list list)
{
    my_put_nbr_base(va_arg(list, int), "01", 0);
    return (1);
}

int flag_x(va_list list)
{
    my_put_nbr_base(va_arg(list, long), "0123456789abcdef", 0);
    return (1);
}

int flag_xx(va_list list)
{
    my_put_nbr_base(va_arg(list, long), "0123456789ABCDEF", 0);
    return (1);
}

int flag_p(va_list list)
{
    my_put_nbr_base(va_arg(list, int), "0123456789abcdef", 1);
    return (1);
}

int flag_u(va_list list)
{
    my_put_nbr_base(va_arg(list, long), "0123456789", 0);
    return (1);
}
