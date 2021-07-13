/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create all music
*/

#include "main.h"
#include "tab_music.h"

void manage_music(sfMusic **music, int pist, int ismute)
{
    if (sfMusic_getStatus(music[pist]) == sfPlaying && ismute == 0)
        return;
    for (int i = 0; tab_zik[i].pathfile != NULL; ++i)
        if (sfMusic_getStatus(music[i]) == sfPlaying)
            sfMusic_stop(music[i]);
    if (ismute == 0)
        sfMusic_play(music[pist]);
}

sfSound **create_sound(sfSound **sound)
{
    sfSoundBuffer *buffer;
    int len = 0;

    for (; tab_snd[len].pathfile != NULL; ++len);
    sound = malloc(sizeof(sfSound *) * len);
    for (int i = 0; tab_snd[i].pathfile != NULL; ++i) {
        sound[i] = sfSound_create();
        buffer = sfSoundBuffer_createFromFile(tab_snd[i].pathfile);
        sfSound_setBuffer(sound[i], buffer);
        sfSound_setLoop(sound[i], tab_snd[i].loop);
        sfSound_setVolume(sound[i], tab_snd[i].volume);
        sfSoundBuffer_destroy(buffer);
    }
    return (sound);
}

sfMusic **create_music(sfMusic **music)
{
    int len = 0;

    for (; tab_zik[len].pathfile != NULL; ++len);
    music = malloc(sizeof(sfSound *) * len);
    for (int i = 0; tab_zik[i].pathfile != NULL; ++i) {
        music[i] = sfMusic_createFromFile(tab_zik[i].pathfile);
        sfMusic_setLoop(music[i], tab_zik[i].loop);
        sfMusic_setVolume(music[i], tab_zik[i].volume);
    }
    return (music);
}
