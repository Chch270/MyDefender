/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** length of mobs
*/

#include "main.h"

int my_nodelen_mob(nmob_t *nmob)
{
    int len = 0;

    while (nmob != NULL) {
        ++len;
        nmob = nmob->nxt;
    }
    return (len);
}
