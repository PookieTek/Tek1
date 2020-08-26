/*
** EPITECH PROJECT, 2018
** sort_func2
** File description:
** sort_func2
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/pushswap.h"

void function_ra(int *l_a, int *l_b, int size)
{
    int i = 0;
    int stock = l_a[0];

    for (; l_a[i] != VAL_NULL; i++)
        l_a[i] = l_a[i + 1];
    l_a[i - 1] = stock;
    my_putstr("ra");
}

void function_rb(int *l_a, int *l_b, int size)
{
    int i = 0;
    int stock = l_b[0];

    for (; l_b[i] != VAL_NULL; i++)
        l_b[i] = l_b[i + 1];
    l_b[i - 1] = stock;
    my_putstr("rb");
}

void function_rr(int *l_a, int *l_b, int size)
{
    int i = 0;
    int stock_a = l_a[0];
    int stock_b = l_b[0];
    int a = limit_list(l_a);
    int b = limit_list(l_b);

    for (; l_a[i] != VAL_NULL; i++) {
        if (i <= b)
            l_b[i] = l_b[i + 1];
        l_a[i] = l_a[i + 1];
    }
    l_a[a - 1] = stock_a;
    l_b[b - 1] = stock_b;
    my_putstr("rr");
}

void function_rra(int *l_a, int *l_b, int size)
{
    int a = limit_list(l_a);
    int stock = l_a[a - 1];

    for (int i = a; i > 0; i--)
        l_a[i] = l_a[i - 1];
    l_a[0] = stock;
    l_a[a] = VAL_NULL;
    my_putstr("rra");
}

void function_rrb(int *l_a, int *l_b, int size)
{
    int b = limit_list(l_b);
    int stock = l_b[b - 1];

    for (int i = size; i > 0; i--)
        l_b[i] = l_b[i - 1];
    l_b[0] = stock;
    l_b[b] = VAL_NULL;
    my_putstr("rrb");
}
