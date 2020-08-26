/*
** EPITECH PROJECT, 2018
** itoa
** File description:
** itoa
*/

char *my_alloc(int);

char *my_revstr(char *);

char *my_itoa(int base)
{
    char *result = my_alloc(13);
    int i = 0;

    result[i] = '0';
    for (; base > 9; i++) {
        result[i] = (base % 10) + 48;
        base = base / 10;
    }
    if (base != 0) {
        result[i] = base + 48;
        i++;
    }
    return (my_revstr(result));
}
