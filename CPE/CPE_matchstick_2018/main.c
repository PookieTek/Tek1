/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "include/my.h"
#include "include/matchstick.h"
#include <stdlib.h>

char *put_line(int i, char *line, int max)
{
    line[0] = '*';
    line[max] = '*';
    if (i == 0 || i == (max + 2) / 2) {
        for (int a = 1; a < max; a++)
            line[a] = '*';
        return (line);
    }
    for (int a = 1; a < max; a++)
        line[a] = ' ';
    for (int a = (max + 1) / 2, count = 0; a < max; a++, count++)
        if (count < i)
            line[a] = '|';
    for (int a = (max + 1) / 2, count = 0; a > 0; a--, count++)
        if (count < i)
            line[a] = '|';
    return (line);
}

void create_board(game_t *game)
{
    game->board = malloc(sizeof(char *) * (game->line + 3));
    game->board[game->line + 2] = NULL;
    for (int i = 0; i < game->line + 2; i++) {
        game->board[i] = my_alloc((game->line * 2 + 2));
        game->board[i] = put_line(i, game->board[i], game->line * 2);
    }
}

int check_error(game_t game)
{
    if (game.line < 2 || game.line > 99) {
        my_putstr("line should be between 1 and 100\n");
        return (84);
    }
    if (game.max < 1) {
        my_putstr("number of match to take should be over 1");
        return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    game_t game;
    int ret = 0;

    if (ac != 3 || is_spnum(av[1]) == 0 || is_spnum(av[2]) == 0) {
        my_putstr("Invalid Argument\n");
        return (84);
    }
    game.line = my_getnbr(av[1]);
    game.max = my_getnbr(av[2]);
    if (check_error(game) == 84)
        return (84);
    game.left = game.line * game.line;
    create_board(&game);
    ret = start_game(&game);
    return (ret);
}
