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

Purpose: Set up game by clearing screen and initializing model and
rendering the initial state.

*/

void setup_game(Model* model, void *base);

/*

Purpose: Get 256 byte aligned memory

*/

UINT8* get_base(UINT8* second_buffer);


#endif
