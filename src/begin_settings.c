/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** control all settings
*/

#include "main.h"
#include "tab_sprite.h"

allsp_t create_all_sprites(allsp_t sprites)
{
    sprites.background = create_all_bg(sprites.background);
    sprites.entities = malloc(sizeof(entity_t * ) * 3);
    sprites.entities[MOBS] = create_all_entity(sprites.entities[MOBS],
                                                tab_mstr);
    sprites.entities[TOWERS] = create_all_entity(sprites.entities[TOWERS],
                                                    tab_twr);
    sprites.entities[GOLD] = create_gold(sprites.entities[GOLD]);
    sprites.twrs_shop = create_towershop_sprite(sprites.entities[TOWERS]);
    sprites.buttons = create_sprite_buttons(sprites.buttons);
    return (sprites);
}

static sfSprite *create_cursor(void)
{
    sfSprite *cursor = sfSprite_create();
    sfTexture *tex = sfTexture_createFromFile("assets/cursor.png", NULL);

    sfSprite_setTexture(cursor, tex, sfTrue);
    return (cursor);
}

void setting_begin(sf_all_t *sf_all)
{
    sf_all->upgrade = 0;
    sf_all->twr_m.ntwr = -1;
    sf_all->twr_m.sprt = NULL;
    free_all_node(sf_all->ntower, sf_all->nmob);
    sf_all->ntower = NULL;
    sf_all->nmob = NULL;
    sf_all->wave = 1;
    sf_all->purse = 200;
    sf_all->life = 1000;
    sfClock_restart(sf_all->clock_twrs);
    sfClock_restart(sf_all->clock_wave);
}

sf_all_t default_settings(void)
{
    sf_all_t sf_all;
    sfVideoMode mode = (sfVideoMode) {1920, 1080, 32};

    sf_all.twr_m.circle = sfCircleShape_create();
    sf_all.cursor = create_cursor();
    sf_all.clock_twrs = sfClock_create();
    sf_all.clock_wave = sfClock_create();
    sf_all.text = sfText_create();
    sf_all.ismute = 0;
    sf_all.ntower = NULL;
    sf_all.nmob = NULL;
    sf_all.sound = create_sound(sf_all.sound);
    sf_all.music = create_music(sf_all.music);
    sfText_setFont(sf_all.text, sfFont_createFromFile("assets/insula.ttf"));
    sf_all.allsp = create_all_sprites(sf_all.allsp);
    sf_all.window = sfRenderWindow_create(mode, "Ghosts 'n Goblins",
                                            sfDefaultStyle, NULL);
    return (sf_all);
}
