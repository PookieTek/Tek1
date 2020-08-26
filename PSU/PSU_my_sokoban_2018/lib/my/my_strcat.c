/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** concatenates strings
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    while (dest[i] != '\0')
        i = i + 1;
    for (int a = 0; src[a] != '\0'; a = a + 1) {
        dest[i] = src[a];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
