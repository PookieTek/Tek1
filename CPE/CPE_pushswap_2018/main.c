/*
** EPITECH PROJECT, 2018
** pushswap
** File description:
** pushswa
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/pushswap.h"

int get_min(int *la, int size)
{
    int stock = la[0];

    for (int i = 0; i < size; i++) {
        if (stock > la[i] && la[i] != VAL_NULL)
            stock = la[i];
    }
    return (stock);
}

void sort_function(int *la, int *lb, int size)
{
    int min = 0;

    while (la[0] != VAL_NULL && size > 1) {
        min = get_min(la, size);
        if (la[0] == min)
            function_pb(la, lb, size);
        else
            function_rra(la, lb, size);
        my_putchar(' ');
    }
    for (int i = 0; i < size; i++) {
        function_pa(la, lb, size);
        if (i < size - 1)
            my_putchar(' ');
    }
}

int main(int ac, char **av)
{
    int *la = wap_alloc(ac - 1);
    int *lb = wap_alloc(ac - 1);

    if (!la || !lb)
        return (ERROR);
    for (int i = 1; i < ac; i++)
        la[i - 1] = my_getnbr(av[i]);
    sort_function(la, lb, ac - 1);
    free(la);
    free(lb);
    my_putchar('\n');
    return (0);
}
