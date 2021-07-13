/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** free them all
*/

#include "main.h"
#include "tab_music.h"
#include "tab_sprite.h"

void free_all_node(ntwr_t *ntower, nmob_t *nmob)
{
    ntwr_t *temp_twr;
    nmob_t *temp_nmob;

    while (ntower != NULL) {
        temp_twr = ntower;
        ntower = ntower->nxt;
        free(temp_twr);
    }
    while (nmob != NULL) {
        temp_nmob = nmob;
        nmob = nmob->nxt;
        free(temp_nmob);
    }
}

static void destroy_music(sfSound **sound, sfMusic **music)
{
    for (int i = 0; tab_zik[i].pathfile != NULL; ++i)
        sfMusic_destroy(music[i]);
    for	(int i = 0; tab_snd[i].pathfile != NULL; ++i)
        sfSound_destroy(sound[i]);
    free(sound);
    free(music);
}

static void destoy_all_sprite(allsp_t allsp)
{
    for (int i = 0; path_bg[i].pathfile != NULL; ++i)
        sfSprite_destroy(allsp.background[i]);
    free(allsp.background);
    for (int i = 0; tab_mstr[i].pathfile != NULL; ++i)
        sfSprite_destroy(allsp.entities[0][i].sprite);
    for	(int i = 0; tab_twr[i].pathfile != NULL; ++i) {
        sfSprite_destroy(allsp.entities[1][i].sprite);
        sfSprite_destroy(allsp.twrs_shop[i]);
    }
    for (int i = 0; tab_button[i].pathfile != NULL; ++i)
        sfSprite_destroy(allsp.buttons[i]);
    free(allsp.twrs_shop);
    free(allsp.entities);
    free(allsp.buttons);
}

void free_destroy_sf_all(sf_all_t *sf_all)
{
    sfSprite_destroy(sf_all->twr_m.sprt);
    sfSprite_destroy(sf_all->cursor);
    destroy_music(sf_all->sound, sf_all->music);
    free_all_node(sf_all->ntower, sf_all->nmob);
    destoy_all_sprite(sf_all->allsp);
    sfClock_destroy(sf_all->clock_twrs);
    sfClock_destroy(sf_all->clock_wave);
    sfText_destroy(sf_all->text);
}
