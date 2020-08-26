/*
** EPITECH PROJECT, 2018
** status
** File description:
** status
*/

#include <ncurses.h>
#include "include/my.h"
#include "include/sokoban.h"

char *place_box(char *str, char *stock)
{
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (stock[i] == 'O' && str[i] != 'X' && str[i] != 'P') {
             str[i] = 'O';
        }
    }
    return (str);
}

int count_box(char *str, char *stock)
{
    int box = 0;

    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] == 'X' && stock[i] != 'O')
            box = box + 1;
    }
    return (box);
}

int is_lose(char *str, int i, char *stock)
{
    int line = 0;

    if (str[i] != 'X' || stock[i] == 'O')
        return (0);
    for (; str[line] != '\n'; line = line + 1);
    line = line + 1;
    if (str[i + 1] == '#' && (str[i + line] == '#' || str[i - line] == '#'))
        return (1);
    if (str[i - 1] == '#' && (str[i + line] == '#' || str[i - line] == '#'))
        return (1);
    return (0);
}
