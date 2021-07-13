/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** task05 day 4
*/

int my_getnbr(char *str)
{
    int nb = 0;
    int isneg = 1;
    int i = 0;

    for (; str[i] == '+' || str[i] == '-'; ++i)
        if (str[i] == '-')
            isneg = isneg * -1;
    for (; str[i] != '\0'; ++i)
        if ('0' <= str[i] && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
        } else
            return (nb * isneg);
    return (nb * isneg);
}
