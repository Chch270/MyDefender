/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create mob in node
*/

#include "tab_sprite.h"
#include "main.h"

void display_mobs(nmob_t *nmob, sfRenderWindow *window)
{
    nmob_t *cpy = nmob;

    if (nmob == NULL)
        return;
    while (cpy != NULL) {
        sfRenderWindow_drawSprite(window, cpy->sprite, NULL);
        cpy = cpy->nxt;
    }
}

static nmob_t *add_mob(nmob_t *nmob, int mob, int wave, entity_t *monsters)
{
    nmob_t *new_mob = malloc(sizeof(nmob_t));

    new_mob->sprite = sfSprite_copy(monsters[mob].sprite);
    new_mob->rect = sfSprite_getTextureRect(monsters[mob].sprite);
    new_mob->pos = carac_mstr[mob].ini_pos;
    new_mob->mob = mob;
    new_mob->action = IDLE;
    new_mob->life = carac_mstr[mob].life + (10 * wave);
    new_mob->speed = carac_mstr[mob].speed;
    new_mob->road = (rand() % 2);
    sfSprite_setPosition(new_mob->sprite, new_mob->pos);
    new_mob->nxt = nmob;
    if (nmob != NULL)
        nmob->pvs = new_mob;
    new_mob->pvs = NULL;
    return (new_mob);
}

nmob_t *create_nmob(nmob_t *nmob, int wave, entity_t *monsters)
{
    int mob = 0;
    int nbmob = my_nodelen_mob(nmob);

    srand(nbmob);
    mob = (rand() % 3);
    nmob = add_mob(nmob, mob, wave, monsters);
    return (nmob);
}
