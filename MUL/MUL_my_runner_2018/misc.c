/*
** EPITECH PROJECT, 2019
** misc
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

window_t game_over(player_t *player, obs_t *obs, window_t win, bg_t *bg)
{
    sfSprite_destroy(player->sprite);
    sfRenderWindow_drawSprite(win.window, bg[3].sprite, NULL);
    sfClock_destroy(win.clock);
    sfClock_destroy(player->clock);
    sfClock_destroy(obs->clock);
    sfMusic_destroy(player->run);
    sfMusic_destroy(player->jump);
    win.end = 1;
    return (win);
}

void check_pos(int i, obs_t *obs)
{
    int x = obs->position.x;
    int y = obs->position.y;

    if (i == 4 && obs->position.x < 200 && obs->position.x > 0)
        obs->height_pl = 150;
    else if (i == 4 && obs->position.x < 0)
        obs->height_pl = 0;
}

char **load_map(char **map, char *path)
{
    FILE *file;
    size_t size = 0;
    int a = 0;
    char c;

    if (my_strcmp(path, "-i") != 0)
        file = fopen(path, "r");
    for (int i = 0; i < 7; i++)
        map[i] = my_alloc(1000);
    if (my_strcmp(path, "-i") != 0) {
        while (getline(&map[a], &size, file) != -1 && a < 7 &&
                no_bad_carac(map, a) == 0) {
            a++;
        }
    }
    else if (a < 6)
        map = random_it(map);
    return (map);
}

obs_t move_obs(obs_t obs, window_t *win, player_t *pl, bg_t *bg)
{
    obs.time = sfClock_getElapsedTime(obs.clock);
    obs.second = obs.time.microseconds / 1000000.0;
    if (obs.second > 0.01) {
        obs.position.x -= 6;
        obs.pos_pl -= 6;
        sfClock_restart(obs.clock);
    }
    if (obs.position.x < - (my_strlen(obs.map[0]) - 2) * 150)
        game_win(win, pl, bg);
    return (obs);
}

window_t hold_obstacle(window_t win, obs_t *obs, player_t *player)
{
    for (int i = 0; obs->map[0][i] != '\0'; i++) {
        win = put_obstacle(win, obs, i);
        obs->position.x += 151;
    }
    obs->position.x -= 151 * my_strlen(obs->map[0]);
    return (win);
}
