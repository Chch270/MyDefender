/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** display gold like our purse or the price
*/

#include "tab_sprite.h"

static void display_purse(int purse, sfText *text, sfRenderWindow *window)
{
    sfText_setPosition(text, (sfVector2f) {445, 105});
    sfText_setString(text, my_itoa(purse));
    sfText_setFillColor(text, (sfColor) {255, 255, 255, 100});
    sfRenderWindow_drawText(window, text, NULL);
}

void display_price(int purse, sfText *text, sfRenderWindow *window)
{
    for (int i = 0; carac_twr[i].price != NULL; ++i) {
        sfText_setPosition(text, (sfVector2f) {250, 110 + (100 * i)});
        sfText_setScale(text, (sfVector2f) {1, 1});
        sfText_setString(text, carac_twr[i].price);
        if (purse < my_getnbr(carac_twr[i].price))
            sfText_setFillColor(text, (sfColor) {255, 0, 0, 100});
        else
            sfText_setFillColor(text, (sfColor) {255, 255, 255, 100});
        sfRenderWindow_drawText(window, text, NULL);
    }
    display_purse(purse, text, window);
}
