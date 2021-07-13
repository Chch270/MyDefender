/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** all the game in there
*/

#include "main.h"
#include "tab_music.h"

void window_inside(sf_all_t *sf_all, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, sf_all->allsp.background[GAME], NULL);
    display_shop(sf_all->allsp.twrs_shop, sf_all->allsp.entities[GOLD]->sprite,
                    window);
    display_price(sf_all->purse, sf_all->text, window);
    display_towers(sf_all->ntower, window);
    display_mobs(sf_all->nmob, window);
    display_damage(window, sf_all->ntower, sf_all->text);
    display_moblife(window, sf_all->nmob, sf_all->text);
    display_shop_button(sf_all->allsp.buttons, window);
    display_rectangle_button(window, sf_all->upgrade);
    display_game_life(window, sf_all->text, sf_all->life);
}
