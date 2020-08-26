/*
** EPITECH PROJECT, 2018
** sort_func3
** File description:
** sort_func3
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/pushswap.h"

void function_rrr(int *l_a, int *l_b, int size)
{
    int a = limit_list(l_a);
    int b = limit_list(l_b);
    int stock_a = l_a[a - 1];
    int stock_b = l_b[b - 1];

    for (int i = size; i > 0; i--) {
        l_a[i] = l_a[i - 1];
        l_b[i] = l_b[i - 1];
    }
    l_a[0] = stock_a;
    l_a[a] = VAL_NULL;
    l_b[0] = stock_b;
    l_b[b] = VAL_NULL;
    my_putstr(" rrr");
}
