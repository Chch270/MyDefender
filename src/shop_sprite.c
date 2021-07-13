/*
** EPITECH PROJECT, 2020
** shop_sprite
** File description:
** display tower sprite
*/

#include "main.h"
#include "tab_sprite.h"
#include "placement_tower.h"

static int return_tower_inmouse(sfVector2i pos, int ntwr)
{
    if (pos.x > tab_twr[ARCHER].pos.x + 60 &&
        pos.x < tab_twr[ARCHER].pos.x + 140) {
        if (pos.y > tab_twr[ARCHER].pos.y + 90 &&
            pos.y < tab_twr[ARCHER].pos.y + 160)
            return (ARCHER);
        if (pos.y > tab_twr[PALADIN].pos.y  + 60 &&
            pos.y < tab_twr[PALADIN].pos.y + 140)
            return (PALADIN);
        if (pos.y > tab_twr[SORCERER].pos.y + 10 &&
            pos.y < tab_twr[SORCERER].pos.y + 109)
            return (SORCERER);
        if (pos.y > tab_twr[SPIKE].pos.y &&
            pos.y < tab_twr[SPIKE].pos.y + 160)
            return (SPIKE);
    }
    return (ntwr);
}

sprite_mouse_t sprt_follow_mse(sfVector2i pos, sprite_mouse_t twr_m,
                                int purse, sfSprite **towers)
{
    twr_m.ntwr = return_tower_inmouse(pos, twr_m.ntwr);
    if (twr_m.ntwr == -1);
    else if (my_getnbr(carac_twr[twr_m.ntwr].price) > purse)
        twr_m.ntwr = -1;
    else
        twr_m.sprt = sfSprite_copy(towers[twr_m.ntwr]);
    return (twr_m);
}

void move_coin(entity_t *gold)
{
    gold->rect.left += 216;
    if (gold->rect.left >= (216 * 36))
        gold->rect.left = 0;
    sfSprite_setTextureRect(gold->sprite, gold->rect);
}

void display_shop(sfSprite **towers, sfSprite *gold, sfRenderWindow *window)
{
    int len_twr = len_sprite(tab_twr);

    for (int i = 0; i != len_twr; ++i)
        sfRenderWindow_drawSprite(window, towers[i], NULL);
    for (int i = 0; cost[i].price.x != 0; ++i) {
        sfSprite_setPosition(gold, cost[i].price);
        sfRenderWindow_drawSprite(window, gold, NULL);
    }
}

sfSprite **create_towershop_sprite(entity_t *entities)
{
    int len_twr = len_sprite(tab_twr);
    sfSprite **towers = malloc(sizeof(sfSprite *) * len_twr);

    for (int i = 0; entities[i].sprite != NULL; ++i) {
        towers[i] = sfSprite_copy(entities[i].sprite);
        sfSprite_setPosition(towers[i], tab_twr[i].pos);
    }
    return (towers);
}
