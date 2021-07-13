/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** menu
*/

#ifndef MENU_H_
#define MENU_H_

#include <SFML/Graphics.h>

void create_start(sfRenderWindow *window, sfVector2i mouse_pos, int click);
void create_how_to_play(sfRenderWindow *window, sfVector2i mouse_pos, int click);
void create_quit(sfRenderWindow *window, sfVector2i mouse_pos, int click);

#endif /* !MENU_H_ */
