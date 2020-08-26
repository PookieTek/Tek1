/*
** EPITECH PROJECT, 2018
** sort_func1
** File description:
** sort_func1
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/pushswap.h"

void function_sa(int *l_a, int *l_b, int size)
{
    int stock;

    stock = l_a[0];
    l_a[0] = l_a[1];
    l_a[1] = stock;
    my_putstr("sa");
}

void function_sb(int *l_a, int *l_b, int size)
{
    int stock;

    stock = l_b[0];
    l_b[0] = l_b[1];
    l_b[1] = stock;
    my_putstr("sb");
}

void function_sc(int *l_a, int *l_b, int size)
{
    int stock;

    stock = l_a[0];
    l_a[0] = l_a[1];
    l_a[1] = stock;
    stock = l_b[0];
    l_b[0] = l_b[1];
    l_b[1] = stock;
    my_putstr("sc");
}

void function_pa(int *l_a, int *l_b, int size)
{
    int a = limit_list(l_a);

    if (l_b[0] != VAL_NULL) {
        for (int i = a; i > 0; i--) {
            l_a[i] = l_a[i - 1];
        }
        l_a[0] = l_b[0];
        for (int i = 0; i < size - 1; i++) {
            l_b[i] = l_b[i + 1];
        }
        l_b[size - 1] = VAL_NULL;
        my_putstr("pa");
    }
}

void function_pb(int *l_a, int *l_b, int size)
{
    int b = limit_list(l_b);

    if (l_a[0] != VAL_NULL) {
        for (int i = b; i > 0; i--)
            l_b[i] = l_b[i - 1];
        l_b[0] = l_a[0];
        for (int i = 0; i < size - 1; i++)
            l_a[i] = l_a[i + 1];
        l_a[size - 1] = VAL_NULL;
        my_putstr("pb");
    }
}
