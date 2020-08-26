/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** sokoban
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include "include/my.h"
#include "include/sokoban.h"

int get_position_player(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i = i + 1) {
        if (str[i] == 'P')
            break;
    }
    return (i);
}

char *move_player(int key, char *str, char *stock)
{
    int line = get_position_player(str);
    int row = 0;

    for (; str[row] != '\n'; row = row + 1);
    switch (key) {
    case KEY_LEFT :
        return (no_wall(line - 1, line, str, stock));
    case KEY_RIGHT :
        return (no_wall(line + 1, line, str, stock));
    case KEY_UP :
        return (no_wall(line - row - 1, line, str, stock));
    case KEY_DOWN :
        return (no_wall(row + line + 1, line, str, stock));
    case 32 :
        return (stock);
    }
    return (str);
}

int check_map(char *map)
{
    for (int i = 0; i < my_strlen(map); i = i + 1) {
        if (map[i] != '#' && map[i] != ' ' && map[i] != '\n' && map[i] != 'X' &&
            map[i] != 'O' && map[i] != 'P')
            return (0);
        if (map[i] == '\n' && map[i - 1] != '#')
            return (0);
    }
    return (1);
}

int set_game(char *stock, char *str, int key)
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    while (key != 27) {
        erase();
        printw(str);
        str = my_strdup(check_status(str, stock));
        if (check_map(str) != 0) {
            key = getch();
            str = my_strdup(move_player(key, str, stock));
        }
        else if (my_strcmp(str, "game over") == 0 ||
                my_strcmp(str, "victory") == 0) {
            endwin();
            break;
        }
    }
    return (exit_game(str, stock));
}

int main(int ac, char **av)
{
    char *str;
    int key;
    char *stock;

    if (ac != 2)
        return (ERROR);
    else if (my_strcmp("-h", av[1]) == 0) {
        display_usage();
        return (USAGE);
    }
    str = load_file_in_mem(av[1]);
    stock = my_strdup(str);
    if (!check_map(str))
        return (ERROR);
    return (set_game(stock, str, key));
}
