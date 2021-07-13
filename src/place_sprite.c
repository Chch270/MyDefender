/*
** EPITECH PROJECT, 2020
** place_sprite
** File description:
** place towers
*/

#include "placement_tower.h"
#include "main.h"
#include "tab_sprite.h"

void display_towers(ntwr_t *ntower, sfRenderWindow *window)
{
    if (ntower == NULL)
        return;
    while (ntower != NULL) {
        if (ntower->twr != -1)
            sfRenderWindow_drawSprite(window, ntower->sprite, NULL);
        ntower = ntower->nxt;
    }
}

int find_place(sfVector2i pos, int twr)
{
    if (twr == SPIKE) {
        for (int i = 0; spike[i].strt.x != 0; ++i)
            if (spike[i].strt.x < pos.x && pos.x < spike[i].end.x
                && spike[i].strt.y < pos.y && pos.y < spike[i].end.y)
                return (i + 6);
    } else {
        for (int i = 0; place[i].strt.x != 0; ++i)
            if (place[i].strt.x < pos.x && pos.x < place[i].end.x
                && place[i].strt.y < pos.y && pos.y < place[i].end.y)
                return (i);
    }
    return (-1);
}

static int same_place_tower(ntwr_t *ntower, int place)
{
    if (ntower == NULL)
        return (0);
    while (ntower->nxt != NULL) {
        if (place == ntower->nplace)
            return (1);
        ntower = ntower->nxt;
    }
    if (place == ntower->nplace)
        return (1);
    return (0);
}

ntwr_t *placed_tower(sf_all_t *sf_all, sfVector2i pos)
{
    int place;

    if (sf_all->twr_m.ntwr == -1)
        return (sf_all->ntower);
    place = find_place(pos, sf_all->twr_m.ntwr);
    if (place == -1)
        return (sf_all->ntower);
    if (same_place_tower(sf_all->ntower, place) == 1)
        return (sf_all->ntower);
    sf_all->purse -= my_getnbr(carac_twr[sf_all->twr_m.ntwr].price);
    return (create_new_tower(place, sf_all->ntower, sf_all->twr_m));
}
