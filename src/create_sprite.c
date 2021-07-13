/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_sprite
*/

#include "main.h"
#include "tab_sprite.h"

static entity_t create_entity(sprite_t tab_sprite)
{
    sfTexture *texture = sfTexture_createFromFile(tab_sprite.pathfile, NULL);
    entity_t entity;

    entity.rect = tab_sprite.rect;
    entity.sprite = sfSprite_create();
    sfSprite_setScale(entity.sprite, tab_sprite.scale);
    sfSprite_setTexture(entity.sprite, texture, sfFalse);
    sfSprite_setTextureRect(entity.sprite, entity.rect);
    return (entity);
}

int len_sprite(const sprite_t *tab_sprite)
{
    int len = 0;

    for (int r = 0; tab_sprite[r].pathfile != NULL; ++r)
        ++len;
    return (len);
}

entity_t *create_all_entity(entity_t *entities, const sprite_t *tab_sprt)
{
    int r = 0;

    entities = malloc(sizeof(entity_t) * (len_sprite(tab_sprt) + 1));
    for (; tab_sprt[r].pathfile != NULL; ++r)
        entities[r] = create_entity(tab_sprt[r]);
    entities[r].sprite = NULL;
    return (entities);
}

entity_t *create_gold(entity_t *entities)
{
    sfTexture *texture = sfTexture_createFromFile("assets/one_piece.png", NULL);

    entities = malloc(sizeof(entity_t));
    entities[0].rect = (sfIntRect) {0, 0, 216, 221};
    entities[0].sprite = sfSprite_create();
    sfSprite_setScale(entities[0].sprite, (sfVector2f) {0.15, 0.15});
    sfSprite_setTexture(entities[0].sprite, texture, sfFalse);
    sfSprite_setTextureRect(entities[0].sprite, entities[0].rect);
    return (entities);
}

sfSprite **create_sprite_buttons(sfSprite **buttons)
{
    sfTexture *tex_up = sfTexture_createFromFile("assets/buttons.png", NULL);

    buttons = malloc(sizeof(sfSprite *) * 3);
    for (int i = 0; tab_button[i].pathfile != NULL; ++i) {
        tex_up = sfTexture_createFromFile(tab_button[i].pathfile, NULL);
        buttons[i] = sfSprite_create();
        sfSprite_setTexture(buttons[i], tex_up, sfFalse);
        sfSprite_setScale(buttons[i], tab_button[i].scale);
        sfSprite_setTextureRect(buttons[i], tab_button[i].rect);
    }
    return (buttons);
}
