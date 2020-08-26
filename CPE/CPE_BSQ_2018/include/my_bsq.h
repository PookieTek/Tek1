/*
** EPITECH PROJECT, 2018
** bsq h
** File description:
** bsq header
*/

#ifndef _MY_BSQ_H_
#define _MY_BSQ_H_

void change_carac(char **, int, int);
char **mem_alloc_2d_array(int, int);
int fs_get_number_from_first_line(char const *);
int get_nbr_fs(char const *, int);
char *load_file_in_mem(char const *);
int check_square(int **, int, int);
int compare_value(int, int);
char **put_square(char **, int **, int, int);
int get_item(int, int, char **);
int get_coord(int *, int *, int **, int *);
void display_bsq(char **, int, int);

typedef enum {
    ERROR_BSQ = 84,
} error_t;

#endif

