/*
** EPITECH PROJECT, 2020
** event_mouse
** File description:
** MUL
*/

#include "main.h"
#include "placement_tower.h"

void display_cursor(sfSprite *cursor, sfVector2i pos, sfRenderWindow *window)
{
    sfSprite_setPosition(cursor, (sfVector2f) {pos.x, pos.y});
    sfRenderWindow_drawSprite(window, cursor, NULL);
}

static void display_range(ntwr_t *ntower, sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    for (; ntower != NULL; ntower = ntower->nxt) {
        if (ntower->circle == NULL)
            continue;
        if (place[ntower->nplace].strt.x < pos.x
            && pos.x < place[ntower->nplace].end.x)
            if (place[ntower->nplace].strt.y < pos.y
                && pos.y < place[ntower->nplace].end.y)
                sfRenderWindow_drawCircleShape(window, ntower->circle, NULL);
    }
}

void event_mouse(sf_all_t *sf_all, sfRenderWindow *window)
{
    if (sf_all->twr_m.ntwr >= 0)
        sprite_tower_mouse(sf_all->twr_m, window);
    display_range(sf_all->ntower, sf_all->window);
}

static void in_event_game(sfSprite **towers, sf_all_t *sf_all, int *game,
                    sfEvent event)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(sf_all->window);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(sf_all->window);
    if (event.type == sfEvtMouseButtonPressed) {
        sf_all->twr_m = sprt_follow_mse(pos, sf_all->twr_m,
                                        sf_all->purse, towers);
        change_function_click(pos, &sf_all->upgrade, sf_all->ntower,
                                &sf_all->purse);
    }
    if (event.type == sfEvtMouseButtonReleased) {
        sf_all->ntower = placed_tower(sf_all, pos);
        sf_all->twr_m.ntwr = -1;
        sf_all->twr_m.sprt = NULL;
    }
    if (event.type == sfEvtKeyReleased)
        event.key.code == sfKeyEscape ? *game = 2 : 0;
}

void event_game(sfSprite **towers, sf_all_t *sf_all, int *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(sf_all->window);
    sfEvent event;

    while (sfRenderWindow_pollEvent(sf_all->window, &event))
        in_event_game(towers, sf_all, game, event);
    event_mouse(sf_all, sf_all->window);
    display_cursor(sf_all->cursor, pos, sf_all->window);
}
