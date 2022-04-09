#include "includes/music.h"
#include "includes/psg.h"

static int current_note = 0;

const notes main_song0[] = 
{
	{1072, 21}, 
	{319, 21}, 
	{190, 35},
	{253, 21}, 
	{253, 21}, 
	{239, 35}, 
	{253, 35}, 
	{190, 7}, 
	{638, 7}, 
	{506, 7}, 
	{478, 7}, 
	{160, 35}, 
	{239, 35}, 
	{190, 35}, 
	{284, 35}, 
	{568, 35}, 
	{0, 35},
	{0, 35},
	{319, 21}, 
	{319, 14},
	{478, 14}, 
	{716, 35}
};
const notes main_song1[] = 
{
	{0, 21},
	{0, 21},
	{284, 35}, 
	{0, 21},
	{0 , 21},
	{0, 35},
	{0, 35},
	{379, 7},
	{0 , 7},
	{0 , 7},
	{0 , 7},
	{0, 35},
	{0, 35},
	{239, 35},
	{478, 35},
	{758, 35},
	{0, 35},
	{319, 35},
	{0, 21},
	{319, 14},
	{0, 14},
	{1432, 35}
};

const notes main_song2[] = 
{
	{0, 21},
	{0, 21},
	{358, 35}, 
	{0, 21},
	{358, 21}, 
	{358, 35},
	{358, 35},
	{358, 7},
	{0 , 7},
	{0 , 7},
	{0 , 7},
	{358, 35},
	{358, 35},
	{358, 35},
	{358, 35},
	{716, 35},
	{358, 35},
	{0, 35},
	{0, 21},
	{0, 14},
	{0, 14},
	{358, 35}
};

void start_music()
{
	int sustain = 3;
  	int vol = 7;

	stop_sound();

    set_envelope(2, sustain);
	
	/*enable all registers with only tune*/
  	enable_channel(2, true, false); 
	enable_channel(1, true, false);
	enable_channel(0, true, false);
	
	/*sets all register volumes to 7*/
	set_volume(2, vol); 
	set_volume(1, vol);
	set_volume(0, vol);
}

bool update_music(UINT32 time_elapsed)
{
	bool updated = false;
	int vol = 7;
	int off = 0;
	if (time_elapsed >= main_song0[current_note].duration) {
	   current_note++;
	   updated = true;
	}

	if (current_note > (NOTES_SZ - 1))
	{
	   current_note = 0;
	}
	  
	/*turns off volume for registers*/
	set_volume(2, off);
	set_volume(1, off);
	set_volume(0, off);
	  
	/*sets tone to next note*/
	set_tone(2, main_song0[current_note].freq); 
	set_tone(1, main_song1[current_note].freq); 
	set_tone(0, main_song2[current_note].freq);

	/*turns on volume for registers*/
	set_volume(2, vol); 
	set_volume(1, vol);
	set_volume(0, vol);

	return updated;
}
