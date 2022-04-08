#include "includes/spacer.h"

const UINT8 second_buffer[32256]; /*Second Screen Buffer*/

extern bool RENDER_REQUEST;
extern int GAME_TIMER;
extern bool key_repeat;

bool gameOver = false;

int main()
{
	
	Model model;
	UINT16 *base, *base2;
	bool quit, swap_screens, start;
	char direction;
	UINT32 input;
	start = false;
	
	inst_vectors();

	base = get_video_base();
	base2 = (UINT16 *) get_base(second_buffer);

	clear_qk(base); /*Clears screen to ready for initialization*/
	
	
	disable_cursor();
	render_splashScreen((UINT32 *)base);
	/*while(!start)
	{
		if(has_user_input())
		{
			start = true;
		}
	}*/

	ship_respawn(&model.user); /*Initializes all objects*/
	init_asteroids(&model);
	init_timebar(&model);
	init_score(&model);

	render(&model, base); /*render the first frame*/

	quit = false; 
	swap_screens = true;

	start_music();
	while(!quit && !gameOver)/*while q isn't pressed*/
	{
		/*Start Asynchronous*/
		if(has_user_input())
		{
			input = get_user_input();
			if(input == QKEY)
			{
				gameOver = true;
			}
			if(key_repeat)
			{
				spaceship_move(&model, input);
			}
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

UINT8* get_base(UINT8* second_buffer)
{
    UINT8* base;
    UINT16 difference;
    base = second_buffer;
    difference = (int) base;
    difference %= 0x100;
    difference = 0x100 - difference;
    return base + difference;
}