/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** destroy all mobs
*/

#include "tab_sprite.h"
#include "main.h"

static int is_it_in_the_base(nmob_t *nmob)
{
    if (40 < nmob->pos.x && nmob->pos.x < 300)
        if (800 < nmob->pos.y && nmob->pos.y < 1070)
            return (1);
    return (0);
}

static nmob_t *remove_node(nmob_t *nmob, int *life)
{
    nmob_t *temp_node = nmob;

    if (nmob->mob == GOBLIN)
        *life -= 50;
    if (nmob->mob == OGRE)
        *life -= 100;
    if (nmob->mob == GHOST)
        *life -= 150;
    nmob = nmob->nxt;
    free(temp_node);
    return (nmob);
}

void destroy_mobs_finish(nmob_t *nmob, sf_all_t *sf_all)
{
    nmob_t *nmob_faster;

    if (nmob == NULL)
        return;
    while (is_it_in_the_base(sf_all->nmob) == 1) {
        if (sf_all->nmob->nxt == NULL) {
            free(sf_all->nmob);
            sf_all->nmob = NULL;
            return;
        }
        sf_all->nmob = remove_node(nmob, &sf_all->life);
    }
    nmob_faster = nmob->nxt;
    while (nmob_faster != NULL)
        if (is_it_in_the_base(nmob_faster) == 1) {
            nmob_faster = remove_node(nmob_faster, &sf_all->life);
            nmob->nxt = nmob_faster;
        } else {
            nmob = nmob->nxt;
            nmob_faster = nmob_faster->nxt;
    }
}
