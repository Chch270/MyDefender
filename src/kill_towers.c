/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** muda muda muda
*/

#include "main.h"
#include "tab_sprite.h"

static void free_tower(ntwr_t **fst_twr, ntwr_t **ntower)
{
    ntwr_t *temp;

    temp = *fst_twr;
    (*ntower)->nxt = (*fst_twr)->nxt;
    *fst_twr = (*fst_twr)->nxt;
    free(temp);
}

void kill_towers(ntwr_t *ntower, sf_all_t *sf_all)
{
    ntwr_t *temp;
    ntwr_t *fst_twr;

    while (ntower != NULL && ntower->twr == UNKNOW) {
        temp = ntower;
        sf_all->ntower = ntower->nxt;
        ntower = ntower->nxt;
        free(temp);
    }
    if (ntower == NULL)
        return;
    fst_twr = ntower->nxt;
    while (fst_twr != NULL)
        if (fst_twr->twr == UNKNOW)
            free_tower(&fst_twr, &ntower);
        else {
            ntower = ntower->nxt;
            fst_twr = fst_twr->nxt;
        }
}
