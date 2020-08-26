/*
** EPITECH PROJECT, 2018
** my_put_nbr_base
** File description:
** convert base
*/

#include <unistd.h>
#include "include/my.h"

int my_put_nbr_base(unsigned int nbr, char const *base, int bol)
{
    int len = my_strlen(base);

    if (bol == 1) {
        if (nbr == 0) {
            my_putstr("(nil)");
            return (0);
        }
        my_putstr("0x");
    }
    if (nbr < len)
        write(1, &base[nbr], 1);
    else {
        my_put_nbr_base((nbr / len), base, 0);
        my_put_nbr_base((nbr % len), base, 0);
    }
    return (0);
}
