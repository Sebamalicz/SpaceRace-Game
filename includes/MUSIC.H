#ifndef SPACERACE_MUSIC_H
#define SPACERACE_MUSIC_H
#include "types.h"

typedef struct notes{
    int freq;
    int duration;
} notes;

void start_music();

void update_music(UINT32 time_elapsed);

#endif
