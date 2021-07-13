/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** display mob's life
*/

#include "main.h"
#include "tab_sprite.h"

void display_moblife(sfRenderWindow *window, nmob_t *nmob, sfText *text)
{
    while (nmob != NULL) {
        if (nmob->action == DEAD) {
            nmob = nmob->nxt;
            continue;
        }
        if (nmob->mob == OGRE)
            sfText_setPosition(text, (sfVector2f) {nmob->pos.x + 100,
                                                    nmob->pos.y});
        else if (nmob->mob == GOBLIN)
            sfText_setPosition(text, (sfVector2f) {nmob->pos.x,
                                                    nmob->pos.y - 50});
        else
            sfText_setPosition(text, (sfVector2f) {nmob->pos.x,
                                                    nmob->pos.y - 20});
        sfText_setString(text, my_itoa(nmob->life));
        sfText_setScale(text, (sfVector2f) {1, 1});
        sfText_setFillColor(text, (sfColor) {0, 0, 0, 100});
        sfRenderWindow_drawText(window, text, NULL);
        nmob = nmob->nxt;
    }
}

void display_game_life(sfRenderWindow *window, sfText *text, int life)
{
    sfText_setPosition(text, (sfVector2f) {10, 750});
    sfText_setString(text, my_itoa(life));
    sfText_setScale(text, (sfVector2f) {1, 1});
    sfText_setFillColor(text, (sfColor) {0, 0, 0, 100});
    sfRenderWindow_drawText(window, text, NULL);
}
