/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** verify pathfile
*/

#include "main.h"
#include "tab_sprite.h"

int verif_pathfile(void)
{
    for (int i = 0; path_bg[i].pathfile != NULL; ++i)
        if (sfTexture_createFromFile(path_bg[i].pathfile, NULL) == NULL)
            return (0);
    for	(int i = 0; tab_mstr[i].pathfile != NULL; ++i)
        if (sfTexture_createFromFile(tab_mstr[i].pathfile, NULL) == NULL)
            return (0);
    for (int i = 0; tab_twr[i].pathfile != NULL; ++i)
        if (sfTexture_createFromFile(tab_twr[i].pathfile, NULL) == NULL)
            return (0);
    if (sfTexture_createFromFile("assets/one_piece.png", NULL) == NULL)
        return (0);
    if (sfTexture_createFromFile("assets/buttons.png", NULL) == NULL)
        return (0);
    return (1);
}
