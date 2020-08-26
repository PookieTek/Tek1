/*
** EPITECH PROJECT, 2018
** tool
** File description:
** tool
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/pushswap.h"

int limit_list(int *list)
{
    int i = 0;

    for (; list[i] != VAL_NULL; i++);
    return (i);
}

int *wap_alloc(int ac)
{
    int *buff = malloc(sizeof(int) * (ac + 1));

    if (!buff)
        return (NULL);
    for (int i = 0; i <= ac; i++)
        buff[i] = VAL_NULL;
    return (buff);
}
