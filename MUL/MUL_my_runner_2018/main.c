/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** mainc
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio.h>
#include "include/my.h"
#include "include/runner.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

window_t put_text(window_t win, player_t player)
{
    sfFont *font = sfFont_createFromFile("sprites/stocky.ttf");
    sfText *text = sfText_create();
    sfVector2f pos;
    char *scor = my_alloc(10);

    scor = my_strdup("Score : ");
    my_strcat(scor, my_itoa(player.score));
    pos.x = 910;
    pos.y = 10;
    sfText_setFont(text, font);
    sfText_setString(text, scor);
    sfText_setCharacterSize(text, 50);
    sfText_setColor(text, sfBlue);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(win.window, text, NULL);
    return (win);
}

void display_usage(void)
{
    my_putstr("USAGE :\n You have to run and evade the obstacle.\n");
    my_putstr("\n You can change the map with the map file");
    my_putstr("\n\n\nCOMMAND :\n\n spacebar : Jump");
}

int check_arg(char *path)
{
    if (my_strcmp(path, "-h") == 0) {
        display_usage();
        return (0);
    }
    else if (my_strcmp(path, "-i") == 0)
        return (1);
    else
        return (open(path, O_RDONLY));
}

void start_game(window_t window, player_t player, bg_t *bg, obs_t obs)
{
    sfMusic_play(window.music);
    sfMusic_play(player.run);
    while (sfRenderWindow_isOpen(window.window)) {
        if (window.end != 1) {
            window = draw_screen(window, bg);
            window = hold_obstacle(window, &obs, &player);
            obs = move_obs(obs, &window, &player, bg);
            window = put_player(window, &player, &obs, bg);
        }
        while (sfRenderWindow_pollEvent(window.window, &window.event)) {
            window = hold_event(window, &player, obs);
        }
        window = put_text(window, player);
        if (window.end != 1)
            sfRenderWindow_drawSprite(window.window, bg[2].sprite, NULL);
        sfRenderWindow_display(window.window);
    }
    return;
}

int main(int ac, char **av)
{
    int fd = 0;
    window_t window = configure_window(window);
    player_t player = configure_player(player);
    bg_t *background = malloc(sizeof(bg_t) * 5);
    obs_t obstacle = configure_obstacle(obstacle);

    srand(time(0));
    if (ac > 1)
        fd = check_arg(av[1]);
    if (fd > 0 && ac > 1) {
        for (int i = 0; i < 5; i++)
            background[i] = configure_background(background, i);
        obstacle.map = load_map(obstacle.map, av[1]);
        start_game(window, player, background, obstacle);
    }
    return (destroy_game(&window, &player, background, &obstacle));
    if (fd <= 0 || ac < 1)
        return (84);
}
