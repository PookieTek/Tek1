/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** copy n string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    for (i = 0; i < n && src[i] != '\0'; i = i + 1)
        dest[i] = src[i];
    if (n > i)
        dest[i] = '\0';
    return (dest);
}
