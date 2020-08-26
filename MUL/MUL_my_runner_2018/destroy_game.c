/*
** EPITECH PROJECT, 2019
** destroy
** File description:
** misc
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio.h>
#include "include/my.h"
#include "include/runner.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int no_bad_carac(char **map, int i)
{
    for (int j = 0; map[i][j] != '\0' && map[i][j] != '\n'; j++)
        if (map[i][j] != ' ' && map[i][j] != '0' && map[i][j] != '1' &&
            map[i][j] != '\0' && map[i][j] != '\n')
            return (1);
    return (0);
}

int destroy_game(window_t *win, player_t *pl, bg_t *bg, obs_t *obs)
{
    sfMusic_destroy(win->music);
    sfSprite_destroy(obs->sprite);
    sfTexture_destroy(obs->texture);
    return (0);
}

char **random_it(char **map)
{
    int rando = 0;

    for (int i = 0; i < 6; i++)
        map[i][0] = ' ';
    map[5][0] = '0';
    for (int i = 1; i < 1000; i++) {
        map[0][i] = ' ';
        map[1][i] = ' ';
        map[2][i] = ' ';
        map[3][i] = ' ';
        map[5][i] = '0';
        rando = rand() % (100);
        if (map[4][i - 1] == ' ' && rando < 20)
            map[4][i] = '1';
        else
            map[4][i] = ' ';
    }
    return (map);
}
