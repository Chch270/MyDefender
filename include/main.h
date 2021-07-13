/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>

typedef struct entity
{
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} entity_t;

typedef struct all_sprite
{
    sfSprite **background;
    entity_t **entities;
    sfSprite **twrs_shop;
    sfSprite **buttons;
} allsp_t;

typedef enum all_bg
{
    MENU,
    GAME,
    OPTION,
    END,
} all_bg;

typedef enum all_entities
{
    MOBS,
    TOWERS,
    GOLD,
} all_entities;

typedef struct sprite_mouse
{
    sfSprite *sprt;
    int ntwr;
    sfCircleShape *circle;
} sprite_mouse_t;

typedef struct nmob
{
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    int mob;
    int action;
    int life;
    int speed;
    int road;
    struct nmob *nxt;
    struct nmob *pvs;
} nmob_t;

typedef struct ntower
{
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfCircleShape *circle;
    int twr;
    int dmg;
    int action;
    int nplace;
    struct nmob *target;
    struct ntower *nxt;
    struct ntower *pvs;
} ntwr_t;

typedef enum all_action
{
    IDLE,
    ACTION,
    DEAD,
    UNKNOW = -1,
} all_action;

typedef struct sf_all
{
    sfRenderWindow *window;
    sprite_mouse_t twr_m;
    sfSound **sound;
    sfMusic **music;
    sfSprite *cursor;
    ntwr_t *ntower;
    nmob_t *nmob;
    allsp_t allsp;
    sfClock *clock_twrs;
    sfClock *clock_wave;
    sfText *text;
    int wave;
    int upgrade;
    int life;
    int ismute;
    int score;
    unsigned int purse;
} sf_all_t;

int find_place(sfVector2i pos, int twr);
int my_nodelen_mob(nmob_t *nmob);
void travel_mobs(nmob_t *nmob);

void clock_wave(sf_all_t *sf_all, sfClock *clock_wave);
void clock_twrs(sf_all_t *sf_all, sfClock *clock_twrs);

void move_coin(entity_t *gold);
void sprite_tower_mouse(sprite_mouse_t twr_m, sfRenderWindow *window);
sprite_mouse_t sprt_follow_mse(sfVector2i pos, sprite_mouse_t twr_m,
                                int purse, sfSprite **towers);

void change_hiscore(int score);
void change_function_click(sfVector2i pos, int *upgrade, ntwr_t *ntower,
                            unsigned int *purse);
void change_status_tower(nmob_t *nmob, ntwr_t *ntower);
void event_game(sfSprite **towers, sf_all_t *sf_all, int *game);
int event_pressed(sfEvent event, sf_all_t *sf_all, sfSprite **towers,
                    sfRenderWindow *window);
void event_mouse(sf_all_t *sf_all, sfRenderWindow *window);
void manage_music(sfMusic **music, int pist, int ismute);
void end_game(sf_all_t *sf_all, int *game);
void is_mute_button(int *ismute, sfVector2i mouse_position);

void display_game_life(sfRenderWindow *window, sfText *text, int life);
void display_rectangle_button(sfRenderWindow *window, int upgrade);
void display_shop_button(sfSprite **button, sfRenderWindow *window);
void display_damage(sfRenderWindow *window, ntwr_t *ntower, sfText *text);
void display_moblife(sfRenderWindow *window, nmob_t *nmob, sfText *text);
void display_cursor(sfSprite *cursor, sfVector2i pos, sfRenderWindow *window);
void option_game(sfSprite **background, sfRenderWindow *window, int *game,
                sfSprite *cursor);
void display_price(int purse, sfText *text, sfRenderWindow *window);
void display_towers(ntwr_t *ntower, sfRenderWindow *window);
void display_shop(sfSprite **towers, sfSprite *gold, sfRenderWindow *window);
void display_mobs(nmob_t *nmob, sfRenderWindow *window);
int show_window(sf_all_t *sf_all);
int menu_inside(sf_all_t *sf_all, sfRenderWindow *window, int game);
void window_inside(sf_all_t *sf_all, sfRenderWindow *window);
void display_mute(sfRenderWindow *window, sfSprite *button, int ismute);

void attack_mob(ntwr_t *ntower, sfSound **sound, int *score);
void destroy_mobs_finish(nmob_t *nmob, sf_all_t *sf_all);
void kill_mob_spike(nmob_t *nmob, ntwr_t *ntower, int *score);
void kill_towers(ntwr_t *ntower, sf_all_t *sf_all);

sfSprite **create_sprite_buttons(sfSprite **buttons);
nmob_t *add_nmobs(nmob_t *nmob, int wave, entity_t *monsters);
ntwr_t *placed_tower(sf_all_t *sf_all, sfVector2i pos);
sfCircleShape *create_circle(sfCircleShape *circle, int twr);
ntwr_t *create_new_tower(int nbplace, ntwr_t *ntower, sprite_mouse_t twr_m);
entity_t *create_gold(entity_t *entities);
sfSprite **create_towershop_sprite(entity_t *entities);
sfSprite **create_all_bg(sfSprite **background);
nmob_t *create_nmob(nmob_t *nmob, int wave, entity_t *monsters);
allsp_t create_all_sprites(allsp_t sprites);
void setting_begin(sf_all_t *sf_all);
sf_all_t default_settings(void);
sfSound **create_sound(sfSound **sound);
sfMusic **create_music(sfMusic **music);

void free_all_node(ntwr_t *ntower, nmob_t *nmob);
void free_destroy_sf_all(sf_all_t *sf_all);

char *my_getenv(char **nenv, char *elem);
int verif_pathfile(void);
char *my_revstr(char *str);
char *my_itoa(int nbr);
int my_getnbr(char *str);
#endif /* !MAIN_H_ */
