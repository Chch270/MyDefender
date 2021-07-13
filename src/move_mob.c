/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** move mobs in the map
*/

#include "main.h"
#include "tab_sprite.h"

sfVector2f move_road0(sfVector2f pos, int speed, int mob)
{
    if (mob == OGRE) {
        if (pos.x < 100)
            pos.y += speed;
        else if (pos.x > 1050 || pos.y > 570)
            pos.x -= speed;
        else
            pos.y += speed;
    } else if (mob == GOBLIN) {
        if (pos.x < 140)
            pos.y += speed;
        else if (pos.x > 1100 || pos.y > 570)
            pos.x -= speed;
        else
            pos.y += speed;
    }
    return (pos);
}

sfVector2f move_road1(sfVector2f pos, int speed, int mob)
{
    if (mob == OGRE) {
        if (pos.y < 800)
            pos.y += speed;
        if (pos.y >= 800)
            pos.x -= speed;
    } else if (mob == GOBLIN) {
        if (pos.y < 850)
            pos.y += speed;
        if (pos.y >= 850)
            pos.x -= speed;
    }
    return (pos);
}

sfVector2f travel_ghost(sfVector2f pos, int speed)
{
    if (pos.x > 200)
        pos.x -= speed;
    if (pos.y < 850)
        pos.y += speed / 1.7;
    return (pos);
}

void travel_mobs(nmob_t *nmob)
{
    while (nmob != NULL) {
        while (nmob != NULL && nmob->action == DEAD)
            nmob = nmob->nxt;
        if (nmob == NULL)
            return;
        if (nmob->mob == GHOST)
            nmob->pos = travel_ghost(nmob->pos, nmob->speed);
        else if (nmob->road == 0)
            nmob->pos = move_road0(nmob->pos, nmob->speed, nmob->mob);
        else
            nmob->pos = move_road1(nmob->pos, nmob->speed, nmob->mob);
        sfSprite_setPosition(nmob->sprite, nmob->pos);
        nmob = nmob->nxt;
    }
}
