/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** clock for waves
*/

#include "main.h"

void clock_wave(sf_all_t *sf_all, sfClock *clock_wave)
{
    static int add_mob = 0;
    sfTime time_wave = sfClock_getElapsedTime(clock_wave);
    sfInt32 add_time = 2000 * sf_all->wave;

    if (sfTime_asMilliseconds(time_wave) >= 1000 + add_time) {
        sf_all->nmob = create_nmob(sf_all->nmob, sf_all->wave,
                                    sf_all->allsp.entities[MOBS]);
        if (add_mob == sf_all->wave) {
            sfClock_restart(clock_wave);
            ++sf_all->wave;
            add_mob = 0;
        }
        ++add_mob;
    }
}
