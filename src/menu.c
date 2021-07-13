/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** menu
*/

#include <SFML/Graphics.h>
#include "main.h"
#include "menu.h"
#include "tab_sprite.h"

static int launch_game(sfVector2i mouse_pos, int game)
{
    if ((mouse_pos.x > 875 && mouse_pos.x < 1075)
    && (mouse_pos.y > 490 && mouse_pos.y < 580))
        game = GAME;
    else
        game = MENU;
    return (game);
}

static void exit_game(sfVector2i mouse_pos, sfRenderWindow *window)
{
    if ((mouse_pos.x > 895 && mouse_pos.x < 1045)
    && (mouse_pos.y > 800 && mouse_pos.y < 875))
        sfRenderWindow_close(window);
}

static int show_how_to_play(sfVector2i mouse_pos, sfRenderWindow *window,
                            int show)
{
    sfText *how_to_play = sfText_create();
    sfVector2f text_position = {500.0, 150.0};

    sfText_setFont(how_to_play, sfFont_createFromFile("assets/insula.ttf"));
    sfText_setString(how_to_play, "To start click on Start Button\n"
    "You have to protect the human city from the enemies incomming\n"
    "You can place towers on the grey areas to kill the enemies\n"
    "Spikes have to be placed in the brown area. They one shot the enemies\n"
    "You must have enough money to buy them, money will come with time\n"
    "You can upgrade towers with the arrow button but it costs money\n"
    "You can press escape to pause the game");
    sfText_setPosition(how_to_play, text_position);
    if ((mouse_pos.x > 775 && mouse_pos.x < 1175)
    && (mouse_pos.y > 585 && mouse_pos.y < 675))
        show = 1;
    if (show == 1)
        sfRenderWindow_drawText(window, how_to_play, NULL);
    return (show);
}

static int event_menu(sfRenderWindow *window, int game, sfSprite *cursor,
                        int *ismute)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow(window);
    sfEvent event;
    static int show = 0;
    static int click = 0;

    create_start(window, mouse_position, click);
    create_how_to_play(window, mouse_position, click);
    create_quit(window, mouse_position, click);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed) {
            click = 1;
            show = show_how_to_play(mouse_position, window, show);
            is_mute_button(ismute, mouse_position);
        } else if (event.type == sfEvtMouseButtonReleased) {
            show = 0;
            click = 0;
            game = launch_game(mouse_position, game);
            exit_game(mouse_position, window);
        }
    }
    if (show == 1)
        show = show_how_to_play(mouse_position, window, show);
    display_cursor(cursor, mouse_position, window);
    return (game);
}

int menu_inside(sf_all_t *sf_all, sfRenderWindow *window, int game)
{
    sfRenderWindow_drawSprite(window, sf_all->allsp.background[MENU], NULL);
    display_mute(window, sf_all->allsp.buttons[MUTE], sf_all->ismute);
    game = event_menu(sf_all->window, game, sf_all->cursor, &sf_all->ismute);
    return (game);
}
