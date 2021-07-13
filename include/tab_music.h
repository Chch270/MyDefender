/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** path for music
*/

typedef struct music
{
    char *pathfile;
    sfBool loop;
    int volume;
} music_t;

static const music_t tab_zik[] =
{
    {"music/menu.ogg", sfTrue, 30},
    {"music/game.ogg", sfTrue, 30},
    {"music/end.ogg", sfTrue, 30},
    {NULL, sfFalse, 0},
};

static const music_t tab_snd[] =
{
    {"music/arrow.ogg", sfFalse, 50},
    {"music/sword.ogg", sfFalse, 50},
    {"music/magic.ogg", sfFalse, 50},
    {NULL, sfFalse, 0},
};

typedef enum zik
{
    MMENU,
    MGAME,
    MEND,
} zik_t;

typedef enum snd
{
    MARROW,
    MSWORD,
    MMAGIC,
} snd_t;
