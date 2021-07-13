/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** display option in game
*/

#include "main.h"
#include "tab_sprite.h"

static int button_actions(sfRenderWindow *window, int game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if ((mouse_pos.x > 840 && mouse_pos.x < 1110)
    && (mouse_pos.y > 660 && mouse_pos.y < 740))
        return (GAME);
    if ((mouse_pos.x > 800 && mouse_pos.x < 1160)
    && (mouse_pos.y > 760 && mouse_pos.y < 840))
        return (MENU);
    if ((mouse_pos.x > 890 && mouse_pos.x < 1040)
    && (mouse_pos.y > 970 && mouse_pos.y < 1050))
        sfRenderWindow_close(window);
    return (game);
}

static void create_quit(sfRenderWindow *window, sfVector2i mouse_pos,
                        int click)
{
    sfRectangleShape *quit = sfRectangleShape_create();
    sfVector2f position_quit = {890.0, 970.0};
    sfVector2f size_quit = {150.0, 80.0};

    sfRectangleShape_setPosition(quit, position_quit);
    sfRectangleShape_setSize(quit, size_quit);
    sfRectangleShape_setOutlineThickness(quit, 1.0);
    sfRectangleShape_setOutlineColor(quit, sfTransparent);
    if ((mouse_pos.x > 890 && mouse_pos.x < 1040) && (mouse_pos.y > 970
    && mouse_pos.y < 1050))
        sfRectangleShape_setFillColor(quit, (sfColor) {255, 255, 255, 20});
    else
        sfRectangleShape_setFillColor(quit, sfTransparent);
    if (click == 1 && ((mouse_pos.x > 890 && mouse_pos.x < 1040)
    && (mouse_pos.y > 970 && mouse_pos.y < 1050)))
        sfRectangleShape_setOutlineColor(quit, sfWhite);
    sfRenderWindow_drawRectangleShape(window, quit, NULL);
}

static void create_main_menu(sfRenderWindow *window, sfVector2i mouse_pos,
                            int click)
{
    sfRectangleShape *main_menu = sfRectangleShape_create();
    sfVector2f position_main_menu = {800.0, 760.0};
    sfVector2f size_main_menu = {360.0, 80.0};

    sfRectangleShape_setPosition(main_menu, position_main_menu);
    sfRectangleShape_setSize(main_menu, size_main_menu);
    sfRectangleShape_setOutlineThickness(main_menu, 1.0);
    sfRectangleShape_setOutlineColor(main_menu, sfTransparent);
    if ((mouse_pos.x > 800 && mouse_pos.x < 1160) && (mouse_pos.y > 760
    && mouse_pos.y < 840))
        sfRectangleShape_setFillColor(main_menu, (sfColor) {255, 255, 255, 20});
    else
        sfRectangleShape_setFillColor(main_menu, sfTransparent);
    if (click == 1 && ((mouse_pos.x > 800 && mouse_pos.x < 1160)
    && (mouse_pos.y > 760 && mouse_pos.y < 840)))
        sfRectangleShape_setOutlineColor(main_menu, sfWhite);
    sfRenderWindow_drawRectangleShape(window, main_menu, NULL);
}

static void create_buttons(sfRenderWindow *window, sfVector2i mouse_pos,
                            int click)
{
    sfRectangleShape *resume = sfRectangleShape_create();
    sfVector2f position_resume = {840.0, 660.0};
    sfVector2f size_resume = {270.0, 80.0};

    sfRectangleShape_setPosition(resume, position_resume);
    sfRectangleShape_setSize(resume, size_resume);
    sfRectangleShape_setOutlineThickness(resume, 1.0);
    sfRectangleShape_setOutlineColor(resume, sfTransparent);
    if ((mouse_pos.x > 840 && mouse_pos.x < 1110) && (mouse_pos.y > 660
    && mouse_pos.y < 740))
        sfRectangleShape_setFillColor(resume, (sfColor) {255, 255, 255, 20});
    else
        sfRectangleShape_setFillColor(resume, sfTransparent);
    if (click == 1 && ((mouse_pos.x > 840 && mouse_pos.x < 1110)
    && (mouse_pos.y > 660 && mouse_pos.y < 740)))
        sfRectangleShape_setOutlineColor(resume, sfWhite);
    sfRenderWindow_drawRectangleShape(window, resume, NULL);
    create_main_menu(window, mouse_pos, click);
    create_quit(window, mouse_pos, click);
}

void option_game(sfSprite **background, sfRenderWindow *window, int *game,
                    sfSprite *cursor)
{
    sfEvent event;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    static int click = 0;

    sfRenderWindow_drawSprite(window, background[OPTION], NULL);
    display_cursor(cursor, mouse_pos, window);
    create_buttons(window, mouse_pos, click);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyReleased)
            (*game) = (event.key.code == sfKeyEscape ? 1 : *game);
        if (event.type == sfEvtMouseButtonPressed)
            click = 1;
        if (event.type == sfEvtMouseButtonReleased) {
            click = 0;
            *game = button_actions(window, *game);
        }
    }
}