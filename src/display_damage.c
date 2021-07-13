/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** display damage on the top of the tower
*/

#include "main.h"
#include "tab_sprite.h"

void display_damage(sfRenderWindow *window, ntwr_t *ntower, sfText *text)
{
    while (ntower != NULL) {
        if (ntower->dmg == 0) {
            ntower = ntower->nxt;
            continue;
        }
        if (ntower->twr == ARCHER)
            sfText_setPosition(text, (sfVector2f) {ntower->pos.x + 40,
                                                    ntower->pos.y + 60});
        else if (ntower->twr == PALADIN)
            sfText_setPosition(text, (sfVector2f) {ntower->pos.x + 35,
                                                    ntower->pos.y + 50});
        else
            sfText_setPosition(text, (sfVector2f) {ntower->pos.x,
                                                    ntower->pos.y});
        sfText_setString(text, my_itoa(ntower->dmg));
        sfText_setFillColor(text, (sfColor) {0, 0, 0, 100});
        sfRenderWindow_drawText(window, text, NULL);
        ntower = ntower->nxt;
    }
}
