/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "include/my.h"
#include "include/matchstick.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

void display(char **board)
{
    for (int i = 0; board[i] != NULL; i++) {
        my_putstr(board[i]);
        my_putchar('\n');
    }
}

int get_line_left(game_t *game, int line)
{
    int left = 0;

    for (int i = 0; game->board[line][i] != '\0'; i++)
        if (game->board[line][i] == '|')
            left++;
    return (left);
}

int ask_line(game_t *game)
{
    char *buffer;
    int line;
    size_t size = 0;

    while (1) {
        my_putstr("Line: ");
        buffer = my_alloc(13);
        game->read = getline(&buffer, &size, stdin);
        line = my_getnbr(buffer);
        if (game->read == -1)
            return (-1);
        if (is_strnum(buffer) == 1 && line > 0 && line <= game->line &&
            left_on_line(line, game) > 0)
            break;
        else
            hold_error_line(buffer, game);
        free (buffer);
    }
    return (line);
}

int ask_match(int line, game_t *game)
{
    int left = get_line_left(game, line);
    char *buffer;
    int match = 0;
    size_t size = 0;

    while (1) {
        buffer = my_alloc(13);
        my_putstr("Matches: ");
        game->read = getline(&buffer, &size, stdin);
        if (game->read == -1)
            return (-1);
        match = my_getnbr(buffer);
        if (is_strnum(buffer) == 1 && match > 0
            && match <= left && match <= game->max)
            break;
        else
            hold_error_match(buffer, game, line, left);
        free (buffer);
    }
    return (match);
}

int start_game(game_t *game)
{
    int line = 0;
    int match = 0;

    game->read = 1;
    srand(time(0));
    display(game->board);
    while (game->left > 0 && game->read > 0) {
        my_putstr("\nYour turn:\n");
        if (player_turn(game) == -1)
            return (0);
        display(game->board);
        if (game->left == 0)
            return (game_over(game));
        my_putstr("\nAI's turn...\n");
        ai_turn(game);
        display(game->board);
        if (game->left == 0)
            return (game_win(game));
    }
    return (0);
}
