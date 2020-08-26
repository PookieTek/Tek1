/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** bsq
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/my_bsq.h"

int check_square(int **num, int a, int b)
{
    int i = num[a - 1][b];
    int j = num[a][b - 1];
    int k = num[a - 1][b - 1];

    if (num[a][b] <= 0 || i <= 0 || j <= 0 || k <= 0)
        return (0);
    else {
        if (i <= j && j <= k)
            return (i);
        else if (j <= i && j <= k)
            return (j);
        else
            return (k);
    }
}

int compare_value(int a, int b)
{
    if (a > b)
        b = a;
    return (b);
}

char **put_square(char **bsq, int **num, int dima, int dimb)
{
    int x = 0;
    int y = 0;
    int dim[2] = {dima, dimb};
    int sq_size = get_coord(&x, &y, num, dim);

    for (int a = y; a > y - sq_size; a--){
        for (int b = x; b > x -sq_size; b--)
            bsq[a][b] = 'x';
    }
    return (bsq);
}

int get_item(int a, int b, char **bsq)
{
    if (bsq[a][b] == 'o')
        return (0);
    else
        return (1);
}

void change_carac(char **bsq, int dima, int dimb)
{
    int **num = malloc(sizeof(int *) * dima + 1);

    for (int a = 0; a < dima; a = a + 1) {
        num[a] = malloc(sizeof(int) * dimb + 1);
        for (int b = 0; b < dimb; b = b + 1) {
            num[a][b] = get_item(a, b, bsq);
        }
    }
    bsq = put_square(bsq, num, dima, dimb);
    display_bsq(bsq, dima, dimb);
    for (int i = 0; i < dima; i = i + 1) {
        free(bsq[i]);
        free(num[i]);
    }
    free(bsq);
    free(num);
}
