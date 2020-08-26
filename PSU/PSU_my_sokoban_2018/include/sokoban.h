/*
** EPITECH PROJECT, 2018
** bsq h
** File description:
** bsq header
*/

#ifndef _SOKOBAN_H_
#define _SOKOBAN_H_

int count_wall(int, int, char **);
void display_usage(void);
char *move_player(int, char *, char *);
char *check_status(char *, char *);
int is_lose(char *, int, char *);
char *no_wall(int, int, char *, char *);
int is_correct_size(char *);
int set_game(char *, char *, int);
int exit_game(char *, char *);
int count_box(char *, char *);
char *place_box(char *, char *);

typedef enum {
    ERROR = 84,
    USAGE = 0,
} error_t;

#endif
