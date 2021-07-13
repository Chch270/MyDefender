/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_towers
*/

#include "placement_tower.h"
#include "main.h"
#include "tab_sprite.h"

sfCircleShape *create_circle(sfCircleShape *circle, int twr)
{
    sfCircleShape_setFillColor(circle, (sfColor) {100, 0, 0, 50});
    sfCircleShape_setOutlineThickness(circle, 2.0);
    sfCircleShape_setRadius(circle, carac_twr[twr].range);
    sfCircleShape_setOutlineColor(circle, (sfColor) {255, 0, 0, 255});
    return (circle);
}

static sfCircleShape *setting_circle_twr(ntwr_t *new_tower, int twr)
{
    new_tower->circle = sfCircleShape_create();
    new_tower->circle = create_circle(new_tower->circle, new_tower->twr);
    if (twr == SORCERER)
        sfCircleShape_setPosition(new_tower->circle,
                                (sfVector2f) {new_tower->pos.x -
                                carac_twr[SORCERER].range+ 70, new_tower->pos.y
                                - carac_twr[SORCERER].range + 70});
    else if (twr == ARCHER)
        sfCircleShape_setPosition(new_tower->circle,
                                (sfVector2f) {new_tower->pos.x
                                - carac_twr[ARCHER].range + 80, new_tower->pos.y
                                - carac_twr[ARCHER].range + 80});
    else
        sfCircleShape_setPosition(new_tower->circle,
                                (sfVector2f) {new_tower->pos.x -
                                carac_twr[PALADIN].range + 60, new_tower->pos.y
                                - carac_twr[PALADIN].range + 60});
    return (new_tower->circle);
}

static ntwr_t *create_spike_twr(int nbplace, ntwr_t *ntower,
                                sprite_mouse_t twr_m)
{
    ntwr_t *new_tower = malloc(sizeof(ntwr_t));

    new_tower->sprite = sfSprite_copy(twr_m.sprt);
    new_tower->twr = twr_m.ntwr;
    new_tower->rect = (sfIntRect) {0, 0, 100, 100};
    new_tower->pos = spike[nbplace - 6].strt;
    new_tower->nplace = nbplace;
    new_tower->action = IDLE;
    new_tower->circle = NULL;
    sfSprite_setPosition(new_tower->sprite, new_tower->pos);
    new_tower->nxt = ntower;
    return (new_tower);
}

static ntwr_t *setup_new_tower(ntwr_t *new_tower, int nbplace,
                                sprite_mouse_t twr_m)
{
    new_tower->sprite = sfSprite_copy(twr_m.sprt);
    new_tower->rect = sfSprite_getTextureRect(twr_m.sprt);
    new_tower->twr = twr_m.ntwr;
    new_tower->dmg = carac_twr[twr_m.ntwr].damage;
    new_tower->pos = place[nbplace].strt;
    new_tower->nplace = nbplace;
    new_tower->action = IDLE;
    new_tower->circle = setting_circle_twr(new_tower, new_tower->twr);
    if (twr_m.ntwr == ARCHER) {
        new_tower->pos.x -= 40;
        new_tower->pos.y -= 60;
    }
    if (twr_m.ntwr == PALADIN) {
        new_tower->pos.x -= 30;
        new_tower->pos.y -= 50;
    }
    return (new_tower);
}

ntwr_t *create_new_tower(int nbplace, ntwr_t *ntower, sprite_mouse_t twr_m)
{
    ntwr_t *new_tower = malloc(sizeof(ntwr_t));

    if (twr_m.ntwr == SPIKE)
        return (create_spike_twr(nbplace, ntower, twr_m));
    new_tower = setup_new_tower(new_tower, nbplace, twr_m);
    sfSprite_setPosition(new_tower->sprite, new_tower->pos);
    new_tower->target = NULL;
    new_tower->nxt = ntower;
    if (ntower != NULL)
        ntower->pvs = new_tower;
    new_tower->pvs = NULL;
    return (new_tower);
}
