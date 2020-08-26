/*
** EPITECH PROJECT, 2018
** configure
** File description:
** configure
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio.h>
#include "include/my.h"
#include "include/runner.h"

window_t configure_window(window_t window)
{
    sfVideoMode mode = {1920, 1080, 32};

    window.width = 1920;
    window.height = 1080;
    window.window = sfRenderWindow_create(mode, "Runner",
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window.window, 60);
    window.clock = sfClock_create();
    sfRenderWindow_setMouseCursorVisible(window.window, sfFalse);
    window.end = 0;
    window.music = sfMusic_createFromFile(MUSIC_GAME_PATH);
    sfMusic_setLoop(window.music, sfTrue);
    sfMusic_setVolume(window.music, 30.0);
    return (window);
}

player_t configure_player(player_t player)
{
    player.score = 0;
    player.texture = sfTexture_createFromFile(PLAYER_PATH, NULL);
    player.rect.top = 0;
    player.rect.left = 0;
    player.rect.width = 172;
    player.rect.height = 155;
    player.clock = sfClock_create();
    player.position.x = 30;
    player.position.y = 630;
    player.in_jump = 0;
    player.in_fall = 0;
    player.sprite = sfSprite_create();
    sfSprite_setTexture(player.sprite, player.texture, sfTrue);
    player.jump = sfMusic_createFromFile(JUMP_SOUND);
    player.run = sfMusic_createFromFile(RUN_SOUND);
    sfMusic_setLoop(player.run, sfTrue);
    return (player);
}

bg_t configure_background(bg_t *background, int i)
{
    switch (i) {
    case 0 :
        background[i].texture = sfTexture_createFromFile(BACK_PATH, NULL);
        break;
    case 1 :
        background[i].texture = sfTexture_createFromFile(MID_PATH, NULL);
        break;
    case 2 :
        background[i].texture = sfTexture_createFromFile(FRONT_PATH, NULL);
        break;
    case 3 :
        background[i].texture = sfTexture_createFromFile(GAME_OVER, NULL);
        break;
    case 4 :
        background[i].texture = sfTexture_createFromFile(GAME_WIN, NULL);
        break;
    }
    background = configure_back(background, i);
    return (background[i]);
}

obs_t configure_obstacle(obs_t obstacle)
{
    obstacle.texture = sfTexture_createFromFile(OBSTACLE_PATH, NULL);
    obstacle.map = malloc(sizeof(char *) * 6);
    obstacle.rect.top = 0;
    obstacle.rect.left = 0;
    obstacle.rect.width = 150;
    obstacle.rect.height = 150;
    obstacle.position.x = 0;
    obstacle.position.y = 900;
    obstacle.sprite = sfSprite_create();
    sfSprite_setTexture(obstacle.sprite, obstacle.texture, sfTrue);
    obstacle.clock = sfClock_create();
    return (obstacle);
}
