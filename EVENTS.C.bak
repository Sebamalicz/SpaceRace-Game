#include "includes/events.h"


void spaceship_move(Model *model, char key)
{	
	if (key == 'w')
	{
		move_ship(model, true);
	}
	else if(key == 's')
	{
		move_ship(model, false);
	}
}

void ship_respawn(Spaceship *ship)
{
	respawn(ship);
}

void ship_respawn_2(Spaceship *ship)
{
	respawn_2(ship);
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

void init_score_2(Model *model)
{
	restart_score_2(&model->score);
}	