/*
** EPITECH PROJECT, 2018
** gam
** File description:
** game
*/

#include <ncurses.h>
#include "include/my.h"
#include "include/sokoban.h"
#include <stdlib.h>

char *check_status(char *str, char *stock)
{
    int i = 0;
    int count = 0;
    int lose = 0;

    for (; str[i] != '\0'; i = i + 1) {
        if (is_lose(str, i, stock) == 1)
            lose = lose + 1;
        if (str[i] == 'X' && stock[i] == 'O')
            count = count + 1;
    }
    if (count_box(str, stock) == 0)
        return ("victory");
    if (lose == count_box(str, stock))
        return ("game over");
    str = place_box(str, stock);
    return (str);
}

char *move_pattern(int actual, int aim, char *str)
{
    str[actual] = ' ';
    str[aim] = 'P';
    return (str);
}

char *no_wall(int aim, int actual, char *str, char *stock)
{
    int next_pos = aim * 2 - actual;

    if (str[aim] != '#' && str[aim] != 'X') {
        str = move_pattern(actual, aim, str);
    }
    else if (str[aim] == 'X') {
        if (str[next_pos] == '#')
            return (str);
        else if (str[next_pos] == 'O') {
            str[next_pos] = 'X';
            str = move_pattern(actual, aim, str);
        }
        else if (str[next_pos] != '#' && str[next_pos] != 'X') {
            str[next_pos] = 'X';
            str = move_pattern(actual, aim, str);
        }
    }
    return (str);
}

void display_usage(void)
{
    my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, containing ‘#’ ");
    my_putstr("for walls, \n           ‘P’ for the player, ‘X’ for boxes and ");
    my_putstr("‘O’ for storage locations.");
}

int exit_game(char *str, char *stock)
{
    int ret = 0;

    free(stock);
    if (my_strcmp(str, "game over") == 0)
        ret = 1;
    free(str);
    return (ret);
}
