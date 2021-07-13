/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** mute sounds
*/

#include "main.h"

void display_mute(sfRenderWindow *window, sfSprite *button, int ismute)
{
    sfSprite_setPosition(button, (sfVector2f) {0, 0});
    if (ismute == 1)
        sfSprite_setTextureRect(button, (sfIntRect) {130, 0, 130, 130});
    else
        sfSprite_setTextureRect(button, (sfIntRect) {0, 0, 130, 130});
    sfRenderWindow_drawSprite(window, button, NULL);
}

void is_mute_button(int *ismute, sfVector2i mouse_position)
{
    if (0 < mouse_position.x && mouse_position.x < 130 &&
        0 < mouse_position.y && mouse_position.y < 130) {
        if (*ismute == 0)
            *ismute = 1;
        else
            *ismute = 0;
    }
}
