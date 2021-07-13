/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** upgrading all tower
*/

#include "main.h"
#include "tab_sprite.h"

static void upgrade_damage(ntwr_t *ntower, unsigned int *purse)
{
    if (ntower->twr == SPIKE)
        return;
    if (my_getnbr(carac_twr[ntower->twr].upgrade) > (int) *purse)
        return;
    *purse -= my_getnbr(carac_twr[ntower->twr].upgrade);
    if (ntower->twr == ARCHER)
        ntower->dmg += 50;
    else if (ntower->twr == PALADIN)
        ntower->dmg += 60;
    else
        ntower->dmg += 80;
}

static void sell_tower(ntwr_t *ntower, unsigned int *purse)
{
    ntower->nplace = UNKNOW;
    ntower->dmg = UNKNOW;
    *purse += (my_getnbr(carac_twr[ntower->twr].price) / 2);
    ntower->twr = UNKNOW;
}

void change_function_click(sfVector2i pos, int *upgrade, ntwr_t *ntower,
                            unsigned int *purse)
{
    int place = 0;

    if (400 < pos.x && pos.x < 480) {
        if (150 < pos.y && pos.y < 230)
            *upgrade = 1;
        else if (250 < pos.y && pos.y < 330)
            *upgrade = 2;
        return;
    }
    if (*upgrade == 0)
        return;
    while (ntower != NULL) {
        place = find_place(pos, ntower->twr);
        if (place == ntower->nplace && *upgrade == 1)
            upgrade_damage(ntower, purse);
        else if (place == ntower->nplace && *upgrade == 2)
            sell_tower(ntower, purse);
        ntower = ntower->nxt;
    }
    *upgrade = 0;
}
