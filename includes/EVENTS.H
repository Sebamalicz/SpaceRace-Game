#ifndef SPACERACE_EVENTS_H
#define SPACERACE_EVENTS_H
#include "model.h"
#include "types.h"

/*

Purpose: to move the spaceship up or down

Details: the function will move the ship up if 'key' equals
'w' and down if 'key' equals 's'

Parameters: 
*model - a poiter to the main model struct
key - a char type variable that indicates the direction the ship will move

*/
void spaceship_move(Model *model, char key);

/*

Purpose: to set the ships x, y and hitbox coordinates to the starting position

Details: sets the fields of the Spaceship struct to the inital settings

Parameters:
*ship - a pointer to a Spaceship struct

*/
void ship_respawn(Spaceship *ship);
<<<<<<< HEAD
=======


void ship_respawn_2(Spaceship *ship);

>>>>>>> 615c68b3d2a4ec0f85a1157d523e95ea72b47bf7
/*

Purpose: to initialize the asteroids starting positions and speeds

Details: this function ensures no more than 2 asteroids spawn on the same
y axis by generating a random number then checking a temp array to see if it is 
a duplicate, if it isn't it is placed in the temp array and looped until finished.
It also randomizes the speed(2-4) and the direction each asteroid moves

Parameters:
*model - a poiter to the main model struct

*/

void init_asteroids(Model *model);

/*

Purpose: to move each asteroid in the array 

Details: this function loops through each asteroid in the array
and moves it depending on its direction(if left then increase x, if !left
then decrease x) and depending on its speed. If any asteroid hits the edge of
the screen it will respawn on the other side with a new random speed

Parameters:
*model - a poiter to the main model struct

*/

void asteroids_move(Model *model);

/*

Purpose: to initialize the time bar's fields

Details: sets the time bar's x1, x2, and y coordinates
to the appropiate values

Parameters:
*model - a poiter to the main model struct

*/
void init_timebar(Model *model);

/*

Purpose: to initialize the scorebox's fields

Details: sets the scorebox's x1, x2, y coordinates, 
and the inital score to the appropiate values 

Parameters:
*model - a poiter to the main model struct

*/
void init_score(Model *model);

/*

*/
bool has_user_input();

/*

*/
UINT32 get_user_input();

/*

*/
bool has_mouse_input();

#endif
