/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** main
*/

#include <SFML/Graphics.h>
#include "main.h"
#include "tab_sprite.h"

static int find_display(char **env)
{
    if (my_getenv(env, "DISPLAY") == NULL)
        return (0);
    return (1);
}

int main(int ac, char **av, char **env)
{
    sf_all_t sf_all;

    (void) av;
    (void) ac;
    if (env == NULL || find_display(env) == 0)
        return (84);
    if (verif_pathfile() == 0)
        return (84);
    sf_all = default_settings();
    if (!sf_all.window)
        return (84);
    show_window(&sf_all);
    free_destroy_sf_all(&sf_all);
    return (0);
}
