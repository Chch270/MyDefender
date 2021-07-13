/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** animate_towers
*/

#include "main.h"
#include "tab_sprite.h"

static void move_twrs(ntwr_t *ntower)
{
    while (ntower != NULL) {
        if (ntower->twr == ARCHER)
            ntower->rect.left += 720;
        if (ntower->twr == PALADIN)
            ntower->rect.left += 210;
        if (ntower->twr == SORCERER)
            ntower->rect.left += 600;
        sfSprite_setTextureRect(ntower->sprite, ntower->rect);
        ntower = ntower->nxt;
    }
}

void move_mobs(nmob_t *nmob)
{
    while (nmob != NULL) {
        if (nmob->mob == GOBLIN)
            nmob->rect.left += 350;
        if (nmob->mob == OGRE)
            nmob->rect.left += 400;
        if (nmob->mob == GHOST)
            nmob->rect.left += 100;
        sfSprite_setTextureRect(nmob->sprite, nmob->rect);
        nmob = nmob->nxt;
    }
}

void restart_twrs(ntwr_t *ntower, sfSound **sound, int *score)
{
    while (ntower != NULL) {
        if (ntower->action == IDLE) {
            if (ntower->twr == ARCHER && ntower->rect.left >= (9 * 720))
                ntower->rect.left = 0;
            if (ntower->twr == PALADIN && ntower->rect.left >= (12 * 210))
                ntower->rect.left = 0;
            if (ntower->twr == SORCERER && ntower->rect.left >= (10 * 600))
                ntower->rect.left = 0;
        } else if (ntower->action == ACTION)
            attack_mob(ntower, sound, score);
        sfSprite_setTextureRect(ntower->sprite, ntower->rect);
        ntower = ntower->nxt;
    }
}

void restart_mobs(nmob_t *nmob)
{
    while (nmob != NULL) {
        if (nmob->action == IDLE) {
            if (nmob->mob == GHOST && nmob->rect.left >= (6 * 100))
                nmob->rect.left = 0;
            if (nmob->mob == GOBLIN && nmob->rect.left >= (15 * 350))
                nmob->rect.left = 0;
            if (nmob->mob == OGRE && nmob->rect.left >= (12 * 400))
                nmob->rect.left = 0;
        }
        sfSprite_setTextureRect(nmob->sprite, nmob->rect);
        nmob = nmob->nxt;
    }
}

void clock_twrs(sf_all_t *sf_all, sfClock *clock_twrs)
{
    sfTime time_twr = sfClock_getElapsedTime(clock_twrs);

    if (sfTime_asMilliseconds(time_twr) >= 115) {
        sf_all->purse += 2;
        sfClock_restart(clock_twrs);
        if (sf_all->nmob != NULL) {
            move_mobs(sf_all->nmob);
            restart_mobs(sf_all->nmob);
        }
        if (sf_all->ntower != NULL) {
            move_twrs(sf_all->ntower);
            restart_twrs(sf_all->ntower, sf_all->sound, &sf_all->score);
        }
        move_coin(sf_all->allsp.entities[GOLD]);
        clock_wave(sf_all, sf_all->clock_wave);
    }
}
