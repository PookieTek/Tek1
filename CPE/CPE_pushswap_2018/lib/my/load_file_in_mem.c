/*
** EPITECH PROJECT, 2018
** load_file_in_mem
** File description:
** load file in mem
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

char *load_file_in_mem(char const *filepath)
{
    struct stat st;
    char *dest;
    int fd = open(filepath, O_RDONLY);

    stat(filepath, &st);
    dest = malloc(st.st_size);
    read(fd, dest, st.st_size);
    return (dest);
}
