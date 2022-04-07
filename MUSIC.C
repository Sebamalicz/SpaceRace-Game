#include "music.h"


static int current_note = 0;


const notes main_song[] = 
{
	{3c0, 0.3},
	{11d, 0.5},
	{0b4, 0.5},
	{10d, 0.5},
	{140, 0.5},
	{0f0, 0.5},
	{140, 0.5},
	{0d6, 0.5},
	{140, 0.5},
	{0f0, 0.5},
	{140, 0.5},
	{0b4, 0.1},
	{140, 0.1},
	{168, 0.1},
	{2cf, 0.1},
	{23b, 0.1},
	{1e0, 0.1},
	{1ac, 0.1},
	{08f, 0.5},
	{140, 0.5},
	{0d6, 0.5},
	{140, 0.5},
	{0b4, 0.5},
	{0d6, 0.5},
	{140, 0.5},
	{1ac, 0.5},
	{10d, 0.5},
	{140, 0.5},
	{1ac, 0.5},
	{1fc, 0.5},
	{281, 0.5},
	{2cf, 0.5},
	{59e, 0.1},
	{140, 0.5},
	{11d, 0.5},
	{11d, 0.3},
	{168, 0.3},
	{1ac, 0.3},
	{140, 0.5},
	{281, 0.5},
	{501, 0.5}
};

void start_music()
{
	int sustain = 10;
  	int vol = 11;

  	set_envelope(triangle_inv_period, sustain);
  	enable_channel(ch_c, true, false);
  	set_volume(ch_c, vol);
	
}

void update_music(UINT32 time_elapsed)
{
	 bool updated = false;

	  if (time_elapsed >= main_song[current_note].duration) {
	    current_note++;
	    updated = true;
	  }

	  if (current_note > (NOTES_SZ - 1))
	    current_note = 0;

	  set_tone(ch_c, main_song[current_note].freq);

	  return updated;
}
