/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** tower's attack
*/

#include "main.h"
#include "tab_sprite.h"
#include "tab_music.h"

static void change_life_mob(ntwr_t *ntower, int *score)
{
    if (ntower->target == NULL)
        return;
    ntower->target->life -= ntower->dmg;
    if (ntower->target->life <= 0) {
        if (ntower->target->mob == OGRE) {
            ntower->target->rect.left = 14 * 400;
            *score += 100;
        } else if (ntower->target->mob == GOBLIN) {
            ntower->target->rect.left = 16 * 350;
            *score += 50;
        } else {
            ntower->target->rect.left = 7 * 100;
            *score += 150;
        }
        ntower->target->action = DEAD;
    ntower->target = NULL;
    }
}

void attack_mob(ntwr_t *ntower, sfSound **sound, int *score)
{
    if (ntower->target == NULL)
        return;
    if (ntower->target->action == DEAD)
        ntower->target = NULL;
    if (ntower->twr == ARCHER && ntower->rect.left >= (20 * 720)) {
        ntower->rect.left = (10 * 720);
        sfSound_play(sound[MARROW]);
        change_life_mob(ntower, score);
    } else if (ntower->twr == PALADIN && ntower->rect.left >= (19 * 210)) {
        ntower->rect.left = (13 * 210);
        sfSound_play(sound[MSWORD]);
        change_life_mob(ntower, score);
    }
    if (ntower->twr == SORCERER && ntower->rect.left >= (19 * 600)) {
        ntower->rect.left = (11 * 600);
        sfSound_play(sound[MMAGIC]);
        change_life_mob(ntower, score);
    }
}

int mob_in_range(ntwr_t *ntower, nmob_t *temp)
{
    float posx = ntower->pos.x + 50;
    float posy = ntower->pos.y - 50;

    if (posx - carac_twr[ntower->twr].range < temp->pos.x
        && temp->pos.x < posx + carac_twr[ntower->twr].range
        && posy - carac_twr[ntower->twr].range < temp->pos.y
        && temp->pos.y < posy + 50 + carac_twr[ntower->twr].range) {
        if (temp->mob == GHOST && ntower->twr != SORCERER)
            return (0);
        if (ntower->twr == ARCHER && ntower->rect.left < (10 * 720))
            ntower->rect.left = (10 * 720);
        if (ntower->twr == PALADIN && ntower->rect.left < (14 * 210))
            ntower->rect.left = (14 * 210);
        if (ntower->twr == SORCERER && ntower->rect.left < (11 * 600))
            ntower->rect.left = (11 * 600);
        ntower->action = ACTION;
        ntower->target = temp;
        return (1);
    }
    return (0);
}

void change_status_tower(nmob_t *nmob, ntwr_t *ntower)
{
    for (int any_mob = 0; ntower != NULL; ntower = ntower->nxt) {
        if (ntower->twr == SPIKE || ntower->twr == -1)
            continue;
        for (nmob_t *temp = nmob; temp != NULL; temp = temp->nxt) {
            if (temp->action == DEAD)
                continue;
            any_mob = mob_in_range(ntower, temp);
            if (any_mob == 1)
                break;
        }
        if (any_mob == 0) {
            ntower->action = IDLE;
            ntower->target = NULL;
            any_mob = 0;
        }
        if (ntower->action == ACTION && ntower->target == NULL)
            ntower->action = IDLE;
    }
}
