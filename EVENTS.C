#include "includes/events.h"


void spaceship_move(Model *model, UINT32 key)
{	
	if (key == WKEY)
	{
		move_ship(model, true);
	}
	else if(key == SKEY)
	{
		move_ship(model, false);
	}
}

void ship_respawn(Spaceship *ship)
{
	respawn(ship);
}

void init_asteroids(Model *model)
{
	spawn_asteroids(model->asteroids);
}

void asteroids_move(Model *model)
{
	move_asteroids(model);
}

void init_timebar(Model *model)
{
	restart_timebar(&model->time);
}

void init_score(Model *model)
{
	restart_score(&model->score);
}

bool has_user_input()
{
	return ikbd_waiting();
}

UINT32 get_user_input()
{
	return read_ikbd();
}