/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** put_nbr
*/

#include <unistd.h>

void my_putchar(char a);
void my_putstr(char *str);

int my_put_nbr(long nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * -1);
    }
    else if (nb <= 9)
        my_putchar(nb + 48);
    else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return (0);
}
