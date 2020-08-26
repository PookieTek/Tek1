/*
** EPITECH PROJECT, 2019
** matshic
** File description:
** matchstick
*/

#ifndef _MATCHSTICK_H_
#define _MATCHSTICK_H_

typedef struct game{
    int line;
    int max;
    int left;
    char **board;
    int read;
}game_t;

void hold_error_line(char *, game_t *);
void hold_error_match(char *, game_t *, int, int);
int is_strnum(char *);
int start_game(game_t *);
void remove_match(int, int, game_t *, char *);
int game_over(game_t *);
int game_win(game_t *);
int left_on_line(int, game_t *);
void ai_turn(game_t *);
int player_turn(game_t *);
int ask_line(game_t *);
int ask_match(int, game_t *);
int is_spnum(char *);

#endif
