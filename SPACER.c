#include <osbind.h>
#include <stdio.h>

#include "includes/render.h"
#include "includes/video.h"
#include "includes/music.h"
#include "includes/psg.h"
#include "includes/isr.h"

const UINT8 second_buffer[32256]; /*Second Screen Buffer*/

extern bool RENDER_REQUEST;
extern int GAME_TIMER;

UINT8 *get_base(UINT8 *second_buffer);
void processSync();
void processAsync();

int main()
{
	
	Model model;
	UINT16 *base, *base2;
	bool quit, swap_screens, gameOver;
	char ch;
	
	inst_vectors();

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

	start_music();
	while(!quit && !gameOver)/*while q isn't pressed*/
	{
		/*Start Asynchronous*/
		if(Cconis()) /*Checks for user input*/
		{
			ch = (char)Cnecin();
			
			if(ch == 'q')
			{
				quit = true; 
			}
			
			spaceship_move(&model, ch);
		}
		/*End Asynchronous*/
		
		/*Start Synchronous*/
		if(GAME_TIMER > 0)
		{
			update_music(GAME_TIMER);
			move_asteroids(&model);
		}
		
		if(GAME_TIMER > 70)
		{
			gameOver = count_down(&model.time);
			GAME_TIMER = 0;
		}
		/*End Synchronous*/
		
		if(RENDER_REQUEST)
		{
			if(swap_screens)
			{
				clear_qk(base);
				render(&model, base);
				set_video_base(base);
			}
			else
			{
				clear_qk(base2);
				render(&model, base2);
				set_video_base(base2);
			}
		}
		
		RENDER_REQUEST = false;
		swap_screens = !swap_screens;

	}
	stop_sound();
	set_video_base(base);
	Cnecin();
	clear_qk(base);
	rem_vectors();
	
	return 0;
}

void processSync()
{
	
}

void processAsync()
{
	
}

UINT8 get_base(UINT8second_buffer)
{
    UINT8* base;
    UINT16 difference;
    base = second_buffer;
    difference = (int) base;
    difference %= 0x100;
    difference = 0x100 - difference;
    return base + difference;
}