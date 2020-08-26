/*
** EPITECH PROJECT, 2018
** runner.h
** File description:
** runner
*/

#ifndef _RUNNER_H_
#define _RUNNER_H_

#define MUSIC_GAME_PATH "audio/music.ogg"
#define RUN_SOUND "audio/run.ogg"
#define JUMP_SOUND "audio/bark.ogg"
#define BACK_PATH "background/back.png"
#define MID_PATH "background/mid.png"
#define FRONT_PATH "background/front.png"
#define PLAYER_PATH "sprites/player.png"
#define OBSTACLE_PATH "sprites/obstacle.png"
#define GAME_OVER "background/gameover.png"
#define GAME_WIN "background/gamewin.png"

typedef enum types {
    BACK = 0,
    MID = 1,
    FRONT = 2,
} types_t;

typedef struct window {
    int width;
    int height;
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    sfTime time;
    float second;
    sfKeyCode key;
    sfClock *truc;
    sfTime tim;
    float sec;
    int end;
    sfMusic *music;
} window_t;

typedef struct player {
    int score;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f position;
    sfClock *clock;
    sfTime time;
    float second;
    int in_jump;
    int in_fall;
    sfMusic *jump;
    sfMusic *run;
} player_t;

typedef struct obstacle {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect rect;
    int speed;
    char **map;
    sfClock *clock;
    sfTime time;
    float second;
    int height_pl;
    int pos_pl;
} obs_t;

typedef struct background {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    int type;
    int speed;
} bg_t;

window_t configure_window(window_t);
player_t configure_player(player_t);
bg_t configure_background(bg_t *, int);
obs_t configure_obstacle(obs_t);
bg_t *move_parallax(bg_t *, window_t);
window_t draw_screen(window_t, bg_t *);
window_t put_obstacle(window_t, obs_t *, int);
obs_t move_obs(obs_t, window_t *, player_t *, bg_t *);
char **load_map(char **, char *);
window_t hold_obstacle(window_t, obs_t *, player_t *);
window_t put_player(window_t, player_t *, obs_t *, bg_t *);
window_t hold_event(window_t, player_t *, obs_t);
void check_pos(int, obs_t *);
window_t game_over(player_t *, obs_t *, window_t, bg_t *);
void game_win(window_t *, player_t *, bg_t *);
bg_t *configure_back(bg_t *, int);
window_t put_player_again(window_t, player_t *, obs_t *, bg_t *);
int destroy_game(window_t *, player_t *, bg_t *, obs_t *);
char **random_it(char **);
int no_bad_carac(char **, int);

#endif
