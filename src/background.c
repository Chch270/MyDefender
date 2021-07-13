/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_backgrouds
*/

#include "main.h"
#include "tab_sprite.h"

static sfSprite *create_background(char *path, sfSprite *sprite_bg)
{
    sfTexture *texture_bg = sfTexture_createFromFile(path, NULL);

    sprite_bg = sfSprite_create();
    sfSprite_setTexture(sprite_bg, texture_bg, sfFalse);
    return (sprite_bg);
}

sfSprite **create_all_bg(sfSprite **background)
{
    background = malloc(sizeof(sfSprite *) * 4);
    for (int i = 0; path_bg[i].pathfile != NULL; ++i)
        background[i] = create_background(path_bg[i].pathfile, background[i]);
    return (background);
}
