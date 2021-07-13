/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** change hi_score
*/

#include "main.h"

static int my_strlen(char const *str)
{
    int len = 0;

    for (; str[len] != '\0'; ++len);
    return (len);
}

static void change_current_hiscore(int score, int line)
{
    char *trash;
    FILE *fd = fopen("hi-score.txt", "r+");
    size_t n = 0;

    for (int i = 0; i != line; ++i)
        getline(&trash, &n, fd);
    trash = my_itoa(score);
    fwrite(trash, my_strlen(trash), 1, fd);
    fclose(fd);
}

void change_hiscore(int score)
{
    FILE *fd = fopen("hi-score.txt", "r+");
    char *str_hiscore;
    int	line = 0;
    size_t n = 0;

    if (fd == NULL)
        return;
    for (; getline(&str_hiscore, &n, fd) != -1; ++line)
        if (my_getnbr(str_hiscore) <= score) {
            change_current_hiscore(score, line);
            break;
        }
    fclose(fd);
}
