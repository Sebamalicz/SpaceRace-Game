#include "model.h"
#include "events.h"
#include <stdio.h>


int main()
{
	int i;
	Model test;
	test.user.speed = 2;
	test.score.score = 0;
	
	printf("------ Start testing ------\n");
	init_asteroids(&test);
	
	printf("------ After spawn ------\n");
	for(i = 0; i < 40; i++)
	{
		printf("Array element: %d", i);
		printf("\n");
		printf("x: %d", test.asteroids[i].x);
		printf("\n");
		printf("y: %d", test.asteroids[i].y);
		printf("\n");
		printf("speed: %d", test.asteroids[i].speed);
		printf("\n");
		if(test.asteroids[i].left)
		{
			printf("position: left");
			printf("\n");
		}
		else
		{
			printf("position: right");
			printf("\n");
		}
	}
	
	
	asteroids_move(&test);
	printf("------ After asteroid move ------\n");
	
	for(i = 0; i < 40; i++)
	{
		printf("Array element: %d", i);
		printf("\n");
		printf("x: %d", test.asteroids[i].x);
		printf("\n");
		printf("y: %d", test.asteroids[i].y);
		printf("\n");
		if(test.asteroids[i].left)
		{
			printf("position: left");
			printf("\n");
		}
		else
		{
			printf("position: right");
			printf("\n");
		}
	}
	
	ship_respawn(&test.user);
	printf("------ After ship spawn ------\n");
	printf("ship x: %d", test.user.x);
	printf("\n");
	printf("ship y: %d", test.user.y);
	printf("\n");
	printf("ship speed: %d", test.user.speed);
	printf("\n");
	printf("ship top left x and y hitbox: %d", test.user.hitbox.top_left_x);
	printf(" and %d", test.user.hitbox.top_left_y);
	printf("\n");
	printf("ship bottom right x and y hitbox: %d", test.user.hitbox.bottom_right_x);
	printf(" and %d", test.user.hitbox.bottom_right_y);
	printf("\n");
	
	
	printf("------ Before moving up -----\n");
	printf("ship x: %d", test.user.x);
	printf("\n");
	printf("ship y: %d", test.user.y);
	printf("\n");
	
	spaceship_move(&test, 'w');
	
	printf("------ After moving up ------\n");
	printf("ship x: %d", test.user.x);
	printf("\n");
	printf("ship y: %d", test.user.y);
	printf("\n");
	printf("ship speed: %d", test.user.speed);
	printf("\n");
	printf("ship top left x and y hitbox: %d", test.user.hitbox.top_left_x);
	printf(" and %d", test.user.hitbox.top_left_y);
	printf("\n");
	printf("ship bottom right x and y hitbox: %d", test.user.hitbox.bottom_right_x);
	printf(" and %d", test.user.hitbox.bottom_right_y);
	printf("\n");
	
	test.user.y = 200;
	printf("------ Before moving down -----\n");
	printf("ship x: %d", test.user.x);
	printf("\n");
	printf("ship y: %d", test.user.y);
	printf("\n");
	
	spaceship_move(&test, 's');
	
	printf("------ After moving down ------\n");
	printf("ship x: %d", test.user.x);
	printf("\n");
	printf("ship y: %d", test.user.y);
	printf("\n");
	printf("ship speed: %d", test.user.speed);
	printf("\n");
	printf("ship top left x and y hitbox: %d", test.user.hitbox.top_left_x);
	printf(" and %d", test.user.hitbox.top_left_y);
	printf("\n");
	printf("ship bottom right x and y hitbox: %d", test.user.hitbox.bottom_right_x);
	printf(" and %d", test.user.hitbox.bottom_right_y);
	printf("\n");
	
	
	printf("----- Test scoring a point -----\n");
	test.user.y = 1;
	printf("ship x and y before move: %d", test.user.x);
	printf(" %d\n", test.user.y);
	printf("score before move: %d\n", test.score.score);
	spaceship_move(&test, 'w');
	printf("score after move: %d\n", test.score.score);
	printf("ship x and y after move: %d", test.user.x);
	printf(" %d\n", test.user.y);
	
	
	printf("----- Test asteroid colliding with ship -----\n");
	test.asteroids[0].speed = 4;
	test.user.x = test.asteroids[0].x + 2;
	test.user.y = test.asteroids[0].y;
	test.user.hitbox.top_left_x = test.user.x;
	test.user.hitbox.top_left_y = test.user.y;
	test.user.hitbox.bottom_right_x = test.user.x + 16;
	test.user.hitbox.bottom_right_y = test.user.y + 16;
	test.user.hitbox.hit = false;
	asteroids_move(&test);
	printf("Ship should spawn back in the original pos\n");
	printf("ship x and y after collision: %d", test.user.x);
	printf(" %d\n", test.user.y);
	
	return 0;
	
	
	
	
}
