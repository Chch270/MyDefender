
/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** display upgrade and sell buttons
*/

#include "main.h"

void display_shop_button(sfSprite **button, sfRenderWindow *window)
{
    sfSprite_setPosition(button[0], (sfVector2f) {400, 150});
    sfSprite_setPosition(button[1], (sfVector2f) {410, 250});
    sfRenderWindow_drawSprite(window, button[0], NULL);
    sfRenderWindow_drawSprite(window, button[1], NULL);
}

void display_rectangle_button(sfRenderWindow *window, int upgrade)
{
    sfRectangleShape *rectangle;
    sfVector2f size = {75, 75};

    if (upgrade == 1 || upgrade == 2) {
        rectangle = sfRectangleShape_create();
        if (upgrade == 1)
            sfRectangleShape_setPosition(rectangle, (sfVector2f) {400, 150});
        else
            sfRectangleShape_setPosition(rectangle, (sfVector2f) {410, 250});
        sfRectangleShape_setSize(rectangle, size);
        sfRectangleShape_setFillColor(rectangle, sfTransparent);
        sfRectangleShape_setOutlineThickness(rectangle, 2.0);
        sfRectangleShape_setOutlineColor(rectangle, (sfColor) {0, 0, 0, 255});
        sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
        sfRectangleShape_destroy(rectangle);
    }
}
