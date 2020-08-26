/*
** EPITECH PROJECT, 2018
** main_bsq
** File description:
** bsq
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"
#include "include/my_bsq.h"

void free_str(char *str1, char *str2)
{
    free(str1);
    free(str2);
}

int get_dimension(char *str)
{
    int i = 0;
    int j = 0;

    for (; str[i] != '\n' && str[i] != '\0'; i = i + 1);
    i = i + 1;
    j = i;
    for (; str[i] != '\n' && str[i] != '\0'; i = i + 1);
    return (i - j);
}

void display_bsq(char **bsq, int dima, int dimb)
{
    for (int i = 0; i < dima; i = i + 1) {
        write(1, bsq[i], dimb);
        my_putchar('\n');
    }
}

int main(int ac, char **av)
{
    int dima = fs_get_number_from_first_line(av[1]);
    char *str = load_file_in_mem(av[1]);
    int dimb = get_dimension(str);
    char **bsq = mem_alloc_2d_array(dima, dimb);
    char *stock = my_alloc(dimb);
    int k = 0;
    int j = 0;

    if (ac != 2)
        return (ERROR_BSQ);
    for (; str[k] != '\n'; k++);
    for (int i = 0; i < dima; i = i + 1) {
        for (k++; str[k] != '\n'; k++, j++)
            stock[j] = str[k];
        j = 0;
        my_strcpy(bsq[i], stock);
    }
    free_str(stock, str);
    change_carac(bsq, dima, dimb);
    return (0);
}
