/*
** EPITECH PROJECT, 2019
** atch
** File description:
** match
*/

#include "include/my.h"
#include "include/matchstick.h"
#include <unistd.h>
#include <stdlib.h>

int player_turn(game_t *game)
{
    int line = 0;
    int match = 0;

    line = ask_line(game);
    if (line == - 1)
        return (-1);
    match = ask_match(line, game);
    if (match == - 1)
        return (-1);
    remove_match(line, match, game, my_strdup("Player"));
    return (0);
}

int game_win(game_t *game)
{
    my_putstr("I lost... snif... but I'll get you next time!!\n");
    return (1);
}

int game_over(game_t *game)
{
    my_putstr("You lost, too bad...\n");
    return (2);
}

void remove_match(int line, int match, game_t *game, char *player)
{
    int pos = 0;
    char *stock = my_alloc(my_strlen(game->board[line]));

    my_strcpy(stock, game->board[line]);
    for (pos = my_strlen(stock); stock[pos] != '|' && pos != 0; pos--);
    for (int i = pos; i > pos - match; i--)
        stock[i] = ' ';
    game->board[line] = stock;
    my_putstr(player);
    my_putstr(" removed ");
    my_put_nbr(match);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putstr("\n");
    game->left -= match;
}
