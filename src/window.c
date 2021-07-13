/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** window
*/

#include <SFML/Graphics.h>
#include "main.h"
#include "tab_sprite.h"
#include "tab_music.h"

static void display_window(sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

static void window_game(sf_all_t *sf_all, sfRenderWindow *window, int *game)
{
    manage_music(sf_all->music, MGAME, sf_all->ismute);
    window_inside(sf_all, window);
    event_game(sf_all->allsp.twrs_shop, sf_all, game);
    clock_twrs(sf_all, sf_all->clock_twrs);
    travel_mobs(sf_all->nmob);
    destroy_mobs_finish(sf_all->nmob, sf_all);
    kill_mob_spike(sf_all->nmob, sf_all->ntower, &sf_all->score);
    change_status_tower(sf_all->nmob, sf_all->ntower);
    kill_towers(sf_all->ntower, sf_all);
    if (sf_all->life <= 0)
        *game = 3;
}

static int main_menu(sf_all_t *sf_all, int game)
{
    setting_begin(sf_all);
    manage_music(sf_all->music, MMENU, sf_all->ismute);
    display_mute(sf_all->window, sf_all->allsp.buttons[MUTE],
                    sf_all->ismute);
    game = menu_inside(sf_all, sf_all->window, game);
    return (game);
}

static void option_ingame(sf_all_t *sf_all, int *game)
{
    manage_music(sf_all->music, MMENU, sf_all->ismute);
    option_game(sf_all->allsp.background, sf_all->window, game,
                sf_all->cursor);
}

int show_window(sf_all_t *sf_all)
{
    int game = 0;

    sfRenderWindow_setMouseCursorVisible(sf_all->window, sfFalse);
    sfRenderWindow_setFramerateLimit(sf_all->window, 60);
    while (sfRenderWindow_isOpen(sf_all->window)) {
        if (game == 1)
            window_game(sf_all, sf_all->window, &game);
        else if (game == 0)
            game = main_menu(sf_all, game);
        if (game == 2)
            option_ingame(sf_all, &game);
        else if (game == 3)
            end_game(sf_all, &game);
        display_window(sf_all->window);
    }
    sfRenderWindow_destroy(sf_all->window);
    return (0);
}
