/*
** EPITECH PROJECT, 2019
** ai
** File description:
** ai
*/

#include "include/my.h"
#include "include/matchstick.h"
#include <stdlib.h>

void ai_turn(game_t *game)
{
    int l_c = 0;
    int m_c = 0;
    int max = 0;
    int line = game->line;

    while (l_c <= 0 || l_c > line || left_on_line(l_c, game) == 0)
        l_c = rand() % (game->line) + 1;
    if (left_on_line(l_c, game) <= game->max)
        max = left_on_line(l_c, game);
    else
        max = game->max;
    m_c = rand() % (max) + 1;
    if (m_c != 1 && m_c == left_on_line(l_c, game))
        m_c--;
    remove_match(l_c, m_c, game, my_strdup("AI"));
}
