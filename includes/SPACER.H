#ifndef SPACERACE_SPACER_H
#define SPACERACE_SPACER_H

#include <osbind.h>
#include <stdio.h>
#include "render.h"
#include "video.h"
#include "music.h"
#include "psg.h"
#include "isr.h"

/*

*/
void processSync();

/*

*/
void processAsync();

/*

*/
void setup_game(Model* model, void *base);

/*

*/
UINT8* get_base(UINT8* second_buffer);


#endif