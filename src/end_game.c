/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** end game avengers !
*/

#include "main.h"
#include "tab_music.h"

static void display_end_game(sfRenderWindow *window, sf_all_t *sf_all)
{
    sfRenderWindow_drawSprite(window, sf_all->allsp.background[END], NULL);
    sfText_setPosition(sf_all->text, (sfVector2f) {900, 200});
    sfText_setString(sf_all->text, my_itoa(sf_all->score));
    sfText_setScale(sf_all->text, (sfVector2f) {2, 2});
    sfText_setFillColor(sf_all->text, (sfColor) {255, 255, 255, 100});
    sfRenderWindow_drawText(window, sf_all->text, NULL);
}

static void event_end_game(sfRenderWindow *window, int *game, sf_all_t *sf_all)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow(window);
    sfEvent event;

    while (sfRenderWindow_pollEvent(sf_all->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyReleased) {
            if (event.key.code == sfKeyEscape)
                sfRenderWindow_close(window);
            else if (event.key.code == sfKeyEnter)
                *game = MENU;
        }
    }
    display_cursor(sf_all->cursor, mouse_position, window);
}

static char *remove_dots(char *score)
{
    for (int i = 0; score[i] != '\0'; ++i)
        if (score[i] == '.') {
            score[i] = '\0';
            return (score);
        }
    return (score);
}

static void display_hiscore(sfRenderWindow *window, sfText *text, int score)
{
    char *str_score;
    FILE *fd = fopen("hi-score.txt", "r");
    size_t n = 0;

    for (int i = 0; getline(&str_score, &n, fd) != -1; ++i) {
        str_score = remove_dots(str_score);
        sfText_setPosition(text, (sfVector2f) {700, 425 + (90 * i)});
        sfText_setString(text, str_score);
        sfText_setScale(text, (sfVector2f) {2, 2});
        if (my_getnbr(str_score) == score)
            sfText_setFillColor(text, (sfColor) {0, 255, 0, 100});
        else
            sfText_setFillColor(text, (sfColor) {255, 255, 255, 100});
        sfRenderWindow_drawText(window, text, NULL);
    }
    fclose(fd);
}

void end_game(sf_all_t *sf_all, int *game)
{
    change_hiscore(sf_all->score);
    manage_music(sf_all->music, MMENU, sf_all->ismute);
    display_end_game(sf_all->window, sf_all);
    display_hiscore(sf_all->window, sf_all->text, sf_all->score);
    event_end_game(sf_all->window, game, sf_all);
}
