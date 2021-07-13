/*
** EPITECH PROJECT, 2020
** sprite_mouse
** File description:
** sprite locate in mouse
*/

#include "main.h"
#include "tab_sprite.h"

static sfCircleShape *move_circle(int twr, sfCircleShape *circle,
                                    sfVector2f posf)
{
    posf.x -= carac_twr[twr].range;
    posf.y -= carac_twr[twr].range;
    sfCircleShape_setPosition(circle, posf);
    return (circle);
}

static sfVector2f change_pos(sprite_mouse_t twr_m, sfVector2i pos)
{
    sfVector2f posf;

    if (twr_m.ntwr == ARCHER) {
        posf.x = pos.x - 100;
        posf.y = pos.y - 130;
    }
    if (twr_m.ntwr == PALADIN)
        posf.x = pos.x - 80;
        posf.y = pos.y - 100;
    if (twr_m.ntwr == SORCERER) {
        posf.x = pos.x - 70;
        posf.y = pos.y - 50;
    }
    if (twr_m.ntwr == SPIKE) {
        posf.x = pos.x - 30;
        posf.y = pos.y - 30;
    }
    return (posf);
}

void sprite_tower_mouse(sprite_mouse_t twr_m, sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f posf = (sfVector2f) {pos.x, pos.y};

    twr_m.circle = create_circle(twr_m.circle, twr_m.ntwr);
    twr_m.circle = move_circle(twr_m.ntwr, twr_m.circle, posf);
    posf = change_pos(twr_m, pos);
    sfSprite_setPosition(twr_m.sprt, posf);
    sfRenderWindow_drawSprite(window, twr_m.sprt, NULL);
    sfRenderWindow_drawCircleShape(window, twr_m.circle, NULL);
}
