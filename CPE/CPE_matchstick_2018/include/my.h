/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** prototypes
*/

#ifndef _MY_H_
#define _MY_H_

void my_putchar(char);
int my_put_nbr_base(int, char const *);
int my_put_nbr(int);
int my_putstr(char const *);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
char *my_strdup(char const *);
int my_strlen(char const *);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int, int);
char *my_strncpy(char *, char const *, int);
int isleter2(char);
int count_str(char const *);
char *my_strupcase(char *);
int is_alpha(char);
int is_num(char);
int my_getnbr(char const *str);
char *my_alloc(int);

#endif
