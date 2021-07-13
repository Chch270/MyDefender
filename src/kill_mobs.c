/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** let's kill da ho biiitchi
*/

#include "main.h"
#include "tab_sprite.h"
#include "placement_tower.h"

static int is_in_spike(nmob_t *nmob)
{
    for (int i = 0; spike[i].strt.x != 0 && nmob != NULL; ++i)
        if (spike[i].strt.x - 100 < nmob->pos.x
            && nmob->pos.x < spike[i].end.x - 100
            && spike[i].strt.y - 100 < nmob->pos.y
            && nmob->pos.y < spike[i].end.y + 100)
            return (i);
    return (UNKNOW);
}

static void find_spike_in(nmob_t *nmob, ntwr_t *ntower, int place, int *score)
{
    while (ntower != NULL) {
        if (ntower->twr == SPIKE && ntower->nplace - 6 == place) {
            ntower->nplace = UNKNOW;
            ntower->twr = UNKNOW;
            if (nmob->mob == OGRE) {
                nmob->rect.left = 14 * 400;
                *score += 50;
            } else if (nmob->mob == GOBLIN) {
                nmob->rect.left = 16 * 350;
                *score += 100;
            } else
                *score += 150;
            nmob->action = DEAD;
            return;
        }
        ntower = ntower->nxt;
    }
}

void kill_mob_spike(nmob_t *nmob, ntwr_t *ntower, int *score)
{
    int place = UNKNOW;

    if (nmob == NULL)
        return;
    while (nmob != NULL) {
        if (nmob->mob == GHOST || nmob->action == DEAD) {
            nmob = nmob->nxt;
            continue;
        }
        place = is_in_spike(nmob);
        if (place != UNKNOW)
            find_spike_in(nmob, ntower, place, score);
        nmob = nmob->nxt;
    }
}
