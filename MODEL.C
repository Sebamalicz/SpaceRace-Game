#include "includes/model.h"

void move_asteroids (Model *model)
{
	int i;
	int random;
	Asteroid *asteroids_array = model->asteroids;
	
	for (i = 0; i < 40; i++) 
	{
		if (asteroids_array[i].left)
		{
			
			if(asteroids_array[i].x + asteroids_array[i].speed >= 640)
			{
				asteroids_array[i].x = 0;
				asteroids_array[i].left = true;
				random = bounded_random(2, 4);
				asteroids_array[i].speed = random;
				
			}
			else
			{
				asteroids_array[i].x += asteroids_array[i].speed;
				asteroids_array[i].hitbox.top_left_x = asteroids_array[i].x;
				asteroids_array[i].hitbox.bottom_right_x = asteroids_array[i].x + 8;
				
			}
		}
		else
		{
			
			if(asteroids_array[i].x - asteroids_array[i].speed <= 0)
			{
				asteroids_array[i].x = 632;
				asteroids_array[i].left = false;
				random = bounded_random(2, 4);/*2, 4*/
				asteroids_array[i].speed = random;
			}
			else
			{
				asteroids_array[i].x -= asteroids_array[i].speed;
				asteroids_array[i].hitbox.top_left_x = asteroids_array[i].x;
				asteroids_array[i].hitbox.bottom_right_x = asteroids_array[i].x + 8;
			}
		}
		
		if(collides(asteroids_array[i].hitbox, model->user.hitbox))
		{
			respawn(&model->user);
		}
		
	}
	
}



void respawn (Spaceship *ship)
{
	ship->x = 288;
	ship->y = 384;
	
	ship->speed = 3;
	ship->direction = 1;

	
	ship->hitbox.top_left_x = ship->x;
	ship->hitbox.top_left_y = ship->y;
	ship->hitbox.bottom_right_x = ship->x + 16;
	ship->hitbox.bottom_right_y = ship->y + 16;
	ship->hitbox.hit = false;
}

bool count_down (Time_bar *time)
{
	bool timeOver = false;
	time->y += 1; 
	
	if(time->y == 399)
	{
		timeOver = true;
	}
	
	return timeOver;
}

void move_ship (Model *model, bool up)
{
	if(up)
	{
		if(in_bounds(model->user.x, model->user.y - model->user.speed))
		{	
			model->user.y -= model->user.speed;
		}
		else
		{
			/* ship has crossed the top of the screen earning a point*/
			respawn(&model->user);
			update_score(&model->score);
		}
	}
	else
	{
		if(model->user.y + model->user.speed < 384)
		{
			model->user.y += model->user.speed;
		}
	}
	model->user.hitbox.top_left_y = model->user.y;
	model->user.hitbox.bottom_right_y = model->user.y + 16;
	return;
}


void spawn_asteroids(Asteroid *asteroids)
{
	int i;
	int j;
	int check_dup[40];
	int dups = 0;
	int x_pos;
	int y_pos;
	int random;
	
	for (i = 0; i < 40; i++)
	{
		asteroids[i].speed = bounded_random(2, 4);
		
	}
	
	/* fills a temp array and checks for dupicate y values ensuring no
	more than 2 asteroids are in the same row*/
	
	for (i = 0; i < 40; i++) 
	{
		y_pos = bounded_random(0, 44) * 8;
		check_dup[i] = y_pos;
		for (j = 0; j < i && dups != 2; j++)
		{
			if(check_dup[j] == y_pos)
			{
				dups++;
			}
			
		}
		if(dups == 2)
		{
			i--;	/* i-- because if dups = 2 the i'th position holds a number that is already in the array twice
					thus we need to generate another number for i'th position*/
		}
		dups = 0;
	}
	
	for (i = 0; i < 40; i++) 
	{
		asteroids[i].y = check_dup[i];
		asteroids[i].hitbox.top_left_y = check_dup[i];
		asteroids[i].hitbox.bottom_right_y = check_dup[i] + 8;
		asteroids[i].hitbox.hit = false;
		
	}
	
	/* set X positoin for each asteroid making sure 20 are on one half of
	screen while 20 on the other half*/
	for (i = 0; i < 20; i++) 
	{
		x_pos = bounded_random(0, 20) * 16;
		asteroids[i].x = x_pos;
		random = bounded_random(500,0);
		if((random % 2) == 0)
		{
			asteroids[i].left = true;
		}
		else
		{
			asteroids[i].left = false;
		}
		asteroids[i].hitbox.top_left_x = x_pos;
		asteroids[i].hitbox.bottom_right_x = x_pos + 8;

		
		
	}
	
	for (i = 20; i < 40; i++) 
	{
		x_pos = bounded_random(20, 39) * 16;
		asteroids[i].x = x_pos;
		random = bounded_random(500,0);
		if((random % 2) == 0)
		{
			asteroids[i].left = true;
		}
		else
		{
			asteroids[i].left = false;
		}
		asteroids[i].hitbox.top_left_x = x_pos;
		asteroids[i].hitbox.bottom_right_x = x_pos + 8;
	}
}


int bounded_random(int min, int max)
{
	int random, distance, x;
	distance = max - min;
	random = (rand() % distance) + min;
	
	return random;
}

void update_score(Scorebox *scorebox)
{
	scorebox->score += 1;
}


bool in_bounds(int x, int y)
{
	if (x < 640 && y < 400 && x >= 0 && y >= 0)
	{
		return true;
	}
	return false;
}

bool collides(Hitbox box1, Hitbox box2)
{
	if(box1.top_left_x < box2.bottom_right_x &&
	box1.bottom_right_x > box2.top_left_x &&
	box1.top_left_y < box2.bottom_right_y &&
	box1.bottom_right_y > box2.top_left_y)
	{
		return true;
	}
	return false;
}

void restart_timebar(Time_bar *time)
{
	time->x1 = 402;
	time->x2 = 410;
	time->y = 339;
}

void restart_score(Scorebox *score)
{
	score->x1 = 234;
	score->x2 = 256;
	score->y = 374;
	score->score = 0;
}