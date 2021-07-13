/*
** EPITECH PROJECT, 2020
** get_env
** File description:
** PSU minishell
*/

#include "main.h"

static int search_name_env(char *name, char *str_to_find)
{
    for (int i = 0; str_to_find[i] != '\0'; ++i)
        if (name[i] != str_to_find[i])
            return (0);
    return (1);
}

static char *find_elem(char *nenv, char *elem)
{
    if (search_name_env(nenv, elem) == 1) {
        return (nenv);
    } else
        return (NULL);
}

char *my_getenv(char **nenv, char *elem)
{
    char *path = NULL;

    for (int i = 0; nenv[i] != NULL; ++i) {
        path = find_elem(nenv[i], elem);
        if (path != NULL)
            break;
    }
    return (path);
}
