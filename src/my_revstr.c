/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** task03 d6
*/

#include <stdio.h>

char *my_revstr(char *str)
{
    int f = 0, z = 0;
    char letter;

    if (str[1] == '\0')
        return (str);
    while (str[f + 1] != '\0')
        f++;
    for (int i = (f / 2) + 1; i != 0; f--, z++, --i) {
        letter = str[z];
        str[z] = str[f];
        str[f] = letter;
    }
    return (str);
}
