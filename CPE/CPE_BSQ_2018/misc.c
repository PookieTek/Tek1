/*
** EPITECH PROJECT, 2018
** misc
** File description:
** msic
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/my_bsq.h"

int get_coord(int *x, int *y, int **num, int *dimension)
{
    int store = 0;
    int sq_size = 0;

    for (int a = 1; a < dimension[0]; a = a + 1) {
        for (int b = 1; b < dimension[1]; b = b + 1) {
            store = check_square(num, a, b);
            num[a][b] = num[a][b] + store;
            sq_size = compare_value(num[a][b], sq_size);
        }
    }
    for (; num[*y][*x] != sq_size; *x = *x + 1) {
        if (*x == dimension[1] && *y < dimension[0]) {
            *x = 0;
            *y = *y + 1;
        }
        else if (*y == dimension[0])
            return (sq_size);
    }
    return (sq_size);
}
