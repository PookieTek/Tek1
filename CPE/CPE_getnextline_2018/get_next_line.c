/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#include "get_next_line.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char *concat(char *, char *, int);

char *get_rest(char *stock, char *str, char *rest, int line)
{
    int jump = 0;
    int i = 0;
    int j = 0;

    for (; jump != line  && str[i] != '\0'; i++) {
        if (str[i] == '\n')
            jump++;
    }
    for (j = 0; str[i] != '\n' && str[i] != '\0'; i++, j++)
        rest[j] = str[i];
    rest[j + 1] = '\0';
    stock = concat(stock, rest, line);
    return (stock);
}

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

char *concat(char *stock, char *str, int line)
{
    int lenght = my_strlen(stock);
    char *res = malloc(sizeof(char) * (READ_SIZE + lenght + 1));

    for (; stock[lenght] != '\0'; lenght++);
    for (int i = 0; stock[i] != '\0'; i++)
        res[i] = stock[i];
    for (int i = 0; str[i] != '\0'; i++, lenght++)
        res[lenght] = str[i];
    res[lenght] = '\0';
    return (res);
}

int is_line_over(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n') {
            str[i] = '\0';
            return (1);
        }
        return (0);
}

char *get_next_line(int fd)
{
    static char str[READ_SIZE + 1] = {'\0'};
    char *stock = malloc(sizeof(char) * READ_SIZE + 1);
    char *rest = malloc(sizeof(char) * READ_SIZE + 1);
    int reading = 1;
    static int line = 0;

    if (fd < 0 || READ_SIZE < 0)
        return (NULL);
    if (str[0] != '\0')
        stock = get_rest(stock, str, rest, line);
    while (reading > 0 && is_line_over(stock) == 0) {
        reading = read(fd, str, READ_SIZE);
        if (reading > 0)
            stock = concat(stock, str, line);
        if (reading < READ_SIZE)
            stock[my_strlen(stock) - READ_SIZE - reading + 1] = '\0';
    }
    line++;
    return (stock);
}
