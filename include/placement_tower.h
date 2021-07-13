/*
** EPITECH PROJECT, 2020
** placement_tower.h
** File description:
** tab_sprite
*/

#include <SFML/System.h>

typedef struct place_tower
{
    sfVector2f strt;
    sfVector2f end;
} place_t;

static const place_t place[] =
{
    {(sfVector2f) {596, 723}, (sfVector2f) {725, 845}},
    {(sfVector2f) {835, 920}, (sfVector2f) {955, 1080}},
    {(sfVector2f) {1023, 542}, (sfVector2f) {1143, 662}},
    {(sfVector2f) {1019, 720}, (sfVector2f) {1137, 845}},
    {(sfVector2f) {1620, 720}, (sfVector2f) {1740, 845}},
    {(sfVector2f) {1620, 920}, (sfVector2f) {1740, 1080}},
    {(sfVector2f) {0, 0}, (sfVector2f) {0, 0}},
};

static const place_t spike[] =
{
    {(sfVector2f) {540, 660}, (sfVector2f) {600, 720}},
    {(sfVector2f) {960, 660}, (sfVector2f) {1020, 720}},
    {(sfVector2f) {780, 900}, (sfVector2f) {840, 960}},
    {(sfVector2f) {1560, 900}, (sfVector2f) {1620, 960}},
    {(sfVector2f) {0, 0}, (sfVector2f) {0, 0}},
};

typedef struct place_gold
{
    sfVector2f price;
} placeg_t;

static const placeg_t cost[] =
{
    {(sfVector2f) {200, 110}},
    {(sfVector2f) {200, 210}},
    {(sfVector2f) {200, 320}},
    {(sfVector2f) {200, 400}},
    {(sfVector2f) {400, 110}},
    {(sfVector2f) {0, 0}},
};
