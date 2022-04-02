#include <osbind.h>
#include <stdio.h>

#include "includes/render.h"
#include "includes/video.h"

UINT32 get_time();
const UINT8 second_buffer[32256]; /*Second Screen Buffer*/
UINT8 *get_base(UINT8 *second_buffer);
void processSync();
void processAsync();

int main()
{
	
	Model model;
	UINT32 timeElapsed, timeThen, timeNow;
	UINT16 *base, *base2;
	bool quit, swap_screens, gameOver;
	char ch;

	base = get_video_base();
	base2 = (UINT16 *) get_base(second_buffer);

	clear_qk(base); /*Clears screen to ready for initialization*/

	render_splashScreen((UINT32 *)base);
	Cconin();
	ship_respawn(&model.user); /*Initializes all objects*/
	init_asteroids(&model);
	init_timebar(&model);
	init_score(&model);

	render(&model, base); /*render the first frame*/

	quit = false; 
	swap_screens = true;
	gameOver = false;
	timeElapsed = 0;
	timeThen = 0;
	timeNow = 0;

	
	while(!quit && !gameOver)/*while q isn't pressed*/
	{
		if(Cconis()) /*Checks for user input*/
		{
			ch = (char)Cnecin();
			
			if(ch == 'q')
			{
				quit = true; 
			}
			
			spaceship_move(&model, ch);
		}
		
		timeNow = get_time();
		timeElapsed = timeNow - timeThen;
		if(timeElapsed > 0)
		{
			move_asteroids(&model);
		}
		
		if(timeElapsed > 70)
		{
			gameOver = count_down(&model.time);
			timeThen = timeNow;
		}
		
		if(swap_screens)
		{
			clear_qk(base);
			render(&model, base);
			Vsync();
			set_video_base(base);
		}
		else
		{
			clear_qk(base2);
			render(&model, base2);
			Vsync();
			set_video_base(base2);
		}
		swap_screens = !swap_screens;

	}
	set_video_base(base);
	Cnecin();
	clear_qk(base);

	return 0;
}

UINT32 get_time()
{
	UINT32 timeNow;
	UINT32 *timer;
	long old_ssp;
	
	timer = (UINT32 *)0x462;
	
	old_ssp = Super(0);  /* enter privileged mode */
	timeNow = *timer;
	Super(old_ssp); /* exit privileged mode */
	
	return timeNow;
}

UINT8 *get_base(UINT8 *second_buffer)
{
	UINT8* base;
	UINT16 difference;
	base = second_buffer;
	difference = (int) base;
	difference %= 0x100;
	difference = 0x100 - difference;
	return base + difference;
}

void processSync()
{
	
}

void processAsync()
{
	
}