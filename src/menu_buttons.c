/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** menu_buttons
*/

#include <SFML/Graphics.h>

void create_start(sfRenderWindow *window, sfVector2i mouse_pos, int click)
{
    sfRectangleShape *start = sfRectangleShape_create();
    sfVector2f position_start = {875.0, 490.0};
    sfVector2f size_start = {200.0, 90.0};

    sfRectangleShape_setPosition(start, position_start);
    sfRectangleShape_setSize(start, size_start);
    sfRectangleShape_setOutlineThickness(start, 1.0);
    sfRectangleShape_setOutlineColor(start, sfTransparent);
    if ((mouse_pos.x > 875 && mouse_pos.x < 1075) && (mouse_pos.y > 490
    && mouse_pos.y < 580))
        sfRectangleShape_setFillColor(start, (sfColor) {25, 25, 25, 20});
    else
        sfRectangleShape_setFillColor(start, sfTransparent);
    if (click == 1 && ((mouse_pos.x > 875 && mouse_pos.x < 1075)
    && (mouse_pos.y > 490 && mouse_pos.y < 580)))
        sfRectangleShape_setOutlineColor(start, sfBlack);
    sfRenderWindow_drawRectangleShape(window, start, NULL);
}

void create_how_to_play(sfRenderWindow *window, sfVector2i mouse_pos, int click)
{
    sfRectangleShape *how_to_play = sfRectangleShape_create();
    sfVector2f position_how_to_play = {775.0, 585.0};
    sfVector2f size_how_to_play = {400.0, 90.0};

    sfRectangleShape_setPosition(how_to_play, position_how_to_play);
    sfRectangleShape_setSize(how_to_play, size_how_to_play);
    sfRectangleShape_setOutlineThickness(how_to_play, 1.0);
    sfRectangleShape_setOutlineColor(how_to_play, sfTransparent);
    if ((mouse_pos.x > 775 && mouse_pos.x < 1175) && (mouse_pos.y > 585
    && mouse_pos.y < 675))
        sfRectangleShape_setFillColor(how_to_play, (sfColor) {25, 25, 25, 20});
    else
        sfRectangleShape_setFillColor(how_to_play, sfTransparent);
    if (click == 1 && ((mouse_pos.x > 775 && mouse_pos.x < 1175)
        && (mouse_pos.y > 585 && mouse_pos.y < 675)))
        sfRectangleShape_setOutlineColor(how_to_play, sfBlack);
    sfRenderWindow_drawRectangleShape(window, how_to_play, NULL);
}

void create_quit(sfRenderWindow *window, sfVector2i mouse_pos, int click)
{
    sfRectangleShape *quit = sfRectangleShape_create();
    sfVector2f position_quit = {895.0, 800.0};
    sfVector2f size_quit = {150.0, 75.0};

    sfRectangleShape_setPosition(quit, position_quit);
    sfRectangleShape_setSize(quit, size_quit);
    sfRectangleShape_setOutlineThickness(quit, 1.0);
    sfRectangleShape_setOutlineColor(quit, sfTransparent);
    if ((mouse_pos.x > 895 && mouse_pos.x < 1045) && (mouse_pos.y > 800
    && mouse_pos.y < 875))
        sfRectangleShape_setFillColor(quit, (sfColor) {25, 25, 25, 20});
    else
        sfRectangleShape_setFillColor(quit, sfTransparent);
    if (click == 1 && ((mouse_pos.x > 895 && mouse_pos.x < 1045)
    && (mouse_pos.y > 800 && mouse_pos.y < 875)))
        sfRectangleShape_setOutlineColor(quit, sfBlack);
    sfRenderWindow_drawRectangleShape(window, quit, NULL);
}
