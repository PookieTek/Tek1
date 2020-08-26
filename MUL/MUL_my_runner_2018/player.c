/*
** EPITECH PROJECT, 2019
** player
** File description:
** player
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio.h>
#include "include/my.h"
#include "include/runner.h"

void game_win(window_t *win, player_t *pl, bg_t *bg)
{
    sfSprite_destroy(pl->sprite);
    sfRenderWindow_drawSprite(win->window, bg[4].sprite, NULL);
    sfMusic_stop(pl->run);
    sfMusic_destroy(pl->jump);
    win->end = 1;
}

window_t hold_event(window_t win, player_t *player, obs_t obs)
{
    if (win.event.type == sfEvtClosed)
        sfRenderWindow_close(win.window);
    else if (sfKeyboard_isKeyPressed(sfKeySpace) && player->in_fall == 0 &&
            player->in_jump == 0 && win.end == 0) {
        sfMusic_stop(player->run);
        sfMusic_play(player->jump);
        player->rect.top = 155;
        player->rect.left = 0;
        player->in_jump = 1;
    }
    return (win);
}

window_t falling_player(player_t *player, obs_t *obs, window_t win, bg_t *bg)
{
    int pos = player->position.y;

    if (player->in_fall == 1 && player->second > 0.01) {
        player->position.y += 8;
        sfClock_restart(player->clock);
        if (player->position.y > 630) {
            player->in_jump = 0;
            player->in_fall = 0;
            sfMusic_play(player->run);
        }
    }
    if (obs->height_pl == 150 && pos >= 630)
        win = game_over(player, obs, win, bg);
    return (win);
}

window_t put_player(window_t win, player_t *player, obs_t *obs, bg_t *bg)
{
    if (win.end != 0)
        return (win);
    player->time = sfClock_getElapsedTime(player->clock);
    player->second = player->time.microseconds / 1000000.0;
    sfSprite_setTextureRect(player->sprite, player->rect);
    if (player->second > 0.1 && player->in_jump == 0 && player->in_fall == 0) {
        player->score++;
        player->rect.top = 0;
        if (player->rect.left < 172)
            player->rect.left += 172;
        else
            player->rect.left = 0;
        sfClock_restart(player->clock);
    }
    return (put_player_again(win, player, obs, bg));
}

window_t put_player_again(window_t win, player_t *player, obs_t *obs, bg_t *bg)
{
    if (player->second > 0.01 && player->in_jump > 0) {
        if (player->in_jump < 40 && player->in_fall == 0) {
            player->in_jump++;
            player->position.y -= 10;
        }
        else if (player->in_jump >= 40)
            player->in_fall = 1;
        sfClock_restart(player->clock);
    }
    win = falling_player(player, obs, win, bg);
    if (win.end == 0) {
        sfSprite_setPosition(player->sprite, player->position);
        sfRenderWindow_drawSprite(win.window, player->sprite, NULL);
    }
    return (win);
}
