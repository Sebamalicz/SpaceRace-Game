#ifndef SPACERACE_MUSIC_H
#define SPACERACE_MUSIC_H
#include "types.h"

#define NOTES_SZ 22 /*origially 168*/

typedef struct notes
{
    int freq;
    int duration;
} notes;

/*

Purpose: Loads first note from array into PSG to start playing song.

*/
void start_music();

/*

Purpose: To advance to the next note.

Details: The funciton moves on the next note depending on the time elapsed 
since the previous call. The time is given to the function by the caller.

*/
bool update_music(UINT32 time_elapsed);

#endif
