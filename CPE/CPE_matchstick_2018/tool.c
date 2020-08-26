/*
** EPITECH PROJECT, 2019
** tool
** File description:
** tool
*/

#include "include/my.h"
#include "include/matchstick.h"
#include <unistd.h>

void hold_error_line(char *str, game_t *game)
{
    int line = my_getnbr(str);

    if (is_strnum(str) == 0)
        my_putstr("Error: invalid input (positive number expected)\n");
    else if (line < 1 || line > game->line)
        my_putstr("Error: this line is out of range\n");
}

void hold_error_match(char *str, game_t *game, int line, int left)
{
    int match = my_getnbr(str);

    if (is_strnum(str) == 0)
        my_putstr("Error: invalid input (positive number expected)\n");
    else if (match < 1)
        my_putstr("Error: you have to remove at least one match\n");
    else if (match > left && match <= game->max)
        my_putstr("Error: not enough matches on this line\n");
    else {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(game->max);
        my_putstr(" matches per turn\n");
    }
}

int is_strnum(char *str)
{
    for (int i = 0; i < my_strlen(str) - 1; i++) {
        if (str[i] < 48 || str[i] > 57)
            return (0);
    }
    return (1);
}

int is_spnum(char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] < 48 || str[i] > 57)
            return (0);
    return (1);
}

int left_on_line(int line, game_t *game)
{
    int count = 0;

    for (int i = 0; game->board[line][i] != '\0'; i++)
        if (game->board[line][i] == '|')
            count++;
    return (count);
}
