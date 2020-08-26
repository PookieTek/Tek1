/*
** EPITECH PROJECT, 2018
** game
** File description:
** game
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

window_t put_obstacle(window_t window, obs_t *obstacle, int carac)
{
    int max = (my_strlen(obstacle->map[0]) - 1) * 150;

    obstacle->position.y = 30;
    for (int i = 0; i < 6; i++) {
        if (obstacle->map[i][carac] == '0')
            obstacle->rect.left = 0;
        else if (obstacle->map[i][carac] == '1')
            obstacle->rect.left = 150;
        if (obstacle->map[i][carac] == '1')
            obstacle->pos_pl = obstacle->position.x;
        if (obstacle->map[i][carac] != ' ' && obstacle->map[i][carac] != '\n') {
            sfSprite_setTextureRect(obstacle->sprite, obstacle->rect);
            sfSprite_setPosition(obstacle->sprite, obstacle->position);
            sfRenderWindow_drawSprite(window.window, obstacle->sprite, NULL);
            check_pos(i, obstacle);
        }
        obstacle->position.y += 150;
    }
    return (window);
}

bg_t *move_parallax(bg_t *bg, window_t window)
{
    for (int i = 0; i < 2; i++) {
        if (bg[i].rect.left < 3960)
            bg[i].rect.left += bg[i].speed;
        else
            bg[i].rect.left = 0;
        sfSprite_setTextureRect(bg[i].sprite, bg[i].rect);
    }
    if (bg[2].rect.top > 0)
        bg[2].rect.top -= bg[2].speed + 1;
    else
        bg[2].rect.top = 2160;
    sfSprite_setTextureRect(bg[2].sprite, bg[2].rect);
    return (bg);
}

window_t draw_screen(window_t window, bg_t *bg)
{
    window.time = sfClock_getElapsedTime(window.clock);
    window.second = window.time.microseconds / 1000000.0;
    if (window.second > 0.01) {
        bg = move_parallax(bg, window);
        sfClock_restart(window.clock);
    }
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawSprite(window.window, bg[i].sprite, NULL);
    }
    return (window);
}
