#ifndef SPACERACE_RENDER_H
#define SPACERACE_RENDER_H

#include "model.h"
#include "types.h"
#include "raster.h"
#include "events.h"
#include "clear_qk.h"

void render(Model *model, UINT16 *base);

void render_spaceship(Spaceship *ship, UINT16 *base);

void render_asteroids(Asteroid *asteroids, UINT8 *base);

void render_time(Time_bar *time, UINT8 *base);

void render_scoreboard(Scorebox *score, UINT16 *base);

void render_splashScreen(UINT32 *base);
#endif