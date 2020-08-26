/*
** EPITECH PROJECT, 2018
** configure
** File description:
** configure
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio.h>
#include "include/my.h"
#include "include/runner.h"

bg_t *configure_back(bg_t *background, int i)
{
    background[i].type = i;
    background[i].speed = (i + 1);
    background[i].rect.top = 0;
    background[i].rect.left = 0;
    background[i].rect.width = 1980;
    background[i].rect.height = 1080;
    background[i].sprite = sfSprite_create();
    sfSprite_setTexture(background[i].sprite, background[i].texture, sfTrue);
    return (background);
}
