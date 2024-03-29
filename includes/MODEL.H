#ifndef SPACERACE_MODEL_H
#define SPACERACE_MODEL_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
typedef struct Hitbox
{
	unsigned int top_left_x;
	unsigned int top_left_y;
	unsigned int bottom_right_x;
	unsigned int bottom_right_y;
	bool hit;
}Hitbox;


typedef struct Asteroid 
{
	int x;
	int y;
	int speed;
	bool left;
	Hitbox hitbox;
}Asteroid;


typedef struct Time_bar
{
	int x1, x2;
	int y;
}Time_bar;


typedef struct Spaceship
{
	int x;
	int y;
	int speed;
	int direction; /*1 north(up), 0 south(down)*/
	Hitbox hitbox;
	
}Spaceship;


typedef struct Scorebox
{
	int x1, x2;
	int y;
	int score;
}Scorebox;


typedef struct Model
{
	Asteroid asteroids[40];
	Time_bar time;
	Spaceship user;
	Scorebox score;
}Model;


/*
Purpose: To move an array of asteroids

Details: The function will loop through an array which holds all
asteroids on screen and moves them left or right depending on their
screen position

*/

void move_asteroids(Model *model);


/*
Purpose: To decrement time bar every second

Details: The function will remove pixels of the time bar starting from the 
top by adding the value of 'speed' to the 'y' value of the time bar struct 
*/

bool count_down(Time_bar *time);


/*
Purpose: To change the direction of the ship

Details: The function will change the direction of the ship depending on the 
value of 'up' if 'up' is true the ships 'y' value will decrease by the value
of the ships 'speed' if 'up' is false the ships 'y' will increase by the value
of the ships 'speed'
*/
void move_ship(Model *model, bool up);

/*
Purpose: To reset the ship back to its original position

Details: This function will set the 'x' and 'y' values of the ship back to
the starting position
*/

void respawn(Spaceship *ship);

/*
Purpose: To spawn all asteroids on screen 

Details: This function will randomly spawn in asteroids on the screen, there
are allowed to be a maximum of 2 asteroids on the same x axis as well the 
function will randomize and set each asteroids 'speed' field, speeds vary
from 2-4 pixels(discrete integers). Asteroids can not spawn any lower than
the time bar(y = ??).
*/

void spawn_asteroids(Asteroid *asteroids);


/*
Purpose: To generate a randome integer between two numbers

Details: Using the rand() function this function will generate a random numbers
using min and max as bounds 

Status: Tested indirectly by using the spawn asteroids function

Parameters: 
min - the minimum the random number can be
max - this integer subtract 1 is the maximum number that can be generated 

*/
int bounded_random(int min, int max);


/*
Purpose: To increase the score when the conditions have been met

Details: This function is called when the ship crosses the top of the screen 
fulfilling the score condition

Status: Tested by calling function and checking the 'score' field

Parameters:
*scorebox - a Scorebox struct poniter which holds the 'score' field that
needs to be increased

*/

void update_score(Scorebox *scorebox);



/*
Purpose: To ensure the x and y position is in bounds with respect to the screen

Details: Checks if the x value is less than 640 but greater than 0 and y value 
is less than 400 but greater than 0

Status: Tested by setting the ship's x to 200 and y to 2 and calling move to move
up and checking the x and y value after the move 

Parameters: 
x - x position of the object
y - y position of the object 

*/

bool in_bounds(int x, int y);



/*
Purpose: Checks if two objects collide with each other

Details: Uses the hitbox fields of each objecct to check if the objects collide,
if a collision takes place and returns true if they collide false otherwise

Status: Tested by setting the ship's x equal to a asteroids x + 2 and y equal to 
the asteroid, while setting the asteroid's 'left' field to true making it move to
the right. After the positons have been set the move_asteroids function is called
to move the asteroid and check for collisions 

Parameters: 
box1 - hitbox for objecct 1
box2 - hitbox for object 2

*/
bool collides(Hitbox box1, Hitbox box2);

/*
This Function restarts the timebar back to the initial 60 second time limit
*/
void restart_timebar(Time_bar *time);

/*
This function restarts the score back to the initial 00 score
*/
void restart_score(Scorebox *score);

#endif

