/*
** EPITECH PROJECT, 2020
** tab_prite
** File description:
** tab_sprite
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "main.h"

typedef struct bg
{
    char *pathfile;
} bg_t;

static const bg_t path_bg[] =
{
    {"assets/menu.jpg"},
    {"assets/map.jpg"},
    {"assets/option_.jpeg"},
    {"assets/end.png"},
    {NULL},
};

typedef struct button
{
    char *pathfile;
    sfVector2f scale;
    sfIntRect rect;
} button_t;

static const button_t tab_button[] =
{
    {"assets/buttons.png", (sfVector2f) {0.5, 0.5},
        (sfIntRect) {0, 0, 150, 190}},
    {"assets/buttons.png", (sfVector2f) {0.5, 0.5},
        (sfIntRect) {160, 0, 150, 190}},
    {"assets/sound.png", (sfVector2f) {0.8, 0.8},
        (sfIntRect) {0, 0, 130, 130}},
    {NULL, (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 0, 0}},
};

typedef struct tab_sprite
{
    char *pathfile;
    sfIntRect rect;
    sfVector2f scale;
    sfVector2f pos;
} sprite_t;

typedef enum butons
{
    UPGRADE,
    SELL,
    MUTE,
} butons_t;

static const sprite_t tab_mstr[] =
{
    {"assets/goblin.png", (sfIntRect) {0, 0, 350, 325},
        (sfVector2f) {0.2, 0.2}, (sfVector2f) {0, 0}},
    {"assets/ogre.png", (sfIntRect) {0, 0, 400, 300},
        (sfVector2f) {0.5, 0.5}, (sfVector2f) {0, 0}},
    {"assets/ghost.png", (sfIntRect) {0, 0, 100, 100},
        (sfVector2f) {1, 1}, (sfVector2f) {0, 0}},
    {NULL, (sfIntRect) {0, 0, 0, 0}, (sfVector2f) {0, 0}, (sfVector2f) {0, 0}},
};

typedef enum monsters
{
    GOBLIN,
    OGRE,
    GHOST,
} monsters_t;

static const sprite_t tab_twr[] =
{
    {"assets/archer.png", (sfIntRect) {0, 0, 720, 720},
        (sfVector2f) {0.25, 0.25}, (sfVector2f) {40, 0}},
    {"assets/paladin.png", (sfIntRect) {0, 0, 210, 160},
        (sfVector2f) {0.9, 0.9}, (sfVector2f) {60, 140}},
    {"assets/sorcerer.png", (sfIntRect) {0, 0, 600, 600},
        (sfVector2f) {0.2, 0.2}, (sfVector2f) {75, 280}},
    {"assets/spike.png", (sfIntRect) {0, 0, 100, 100},
        (sfVector2f) {0.7, 0.7}, (sfVector2f) {100, 380}},
    {NULL, (sfIntRect) {0, 0, 0, 0}, (sfVector2f) {0, 0}, (sfVector2f) {0, 0}},
};

typedef struct carac_twr
{
    int range;
    char *price;
    int damage;
    char *upgrade;
} caractwr_t;

static const caractwr_t carac_twr[] =
{
    {300, "70", 50, "110"},
    {120, "150", 100, "170"},
    {200, "200", 70, "240"},
    {0, "125", 0, NULL},
    {0, NULL, 0, NULL},
};

typedef enum twr
{
    ARCHER,
    PALADIN,
    SORCERER,
    SPIKE,
} twr_t;

typedef struct carac_mob
{
    sfVector2f ini_pos;
    int life;
    int speed;
} caracmob_t;

static const caracmob_t carac_mstr[] =
{
    {(sfVector2f) {1750, 40}, 50, 4},
    {(sfVector2f) {1650, 0}, 100, 3},
    {(sfVector2f) {1700, 80}, 25, 2},
};

entity_t *create_all_entity(entity_t *entities, const sprite_t *tab_sprt);
int len_sprite(const sprite_t *tab_sprite);
