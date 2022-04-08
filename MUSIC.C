#include "includes/music.h"
#include "includes/psg.h"

static int current_note = 0;

const notes main_song[] = 
{
	{0x3c0, 21}, 
	{0x11d, 35},
	{0x0b4, 35},
	{0x10d, 35},
	{0x140, 35},
	{0x0f0, 35},
	{0x140, 35},
	{0x0d6, 35},
	{0x140, 35},
	{0x0f0, 35},
	{0x140, 35},
	{0x0b4, 7},
	{0x140, 7},
	{0x168, 7},
	{0x2cf, 7},
	{0x23b, 7},
	{0x1e0, 7},
	{0x1ac, 7},
	{0x08f, 35},
	{0x140, 35},
	{0x0d6, 35},
	{0x140, 35},
	{0x0b4, 35},
	{0x0d6, 35},
	{0x140, 35},
	{0x1ac, 35},
	{0x10d, 35},
	{0x140, 35},
	{0x1ac, 35},
	{0x1fc, 35},
	{0x281, 35},
	{0x2cf, 35},
	{0x59e, 7},
	{0x140, 35},
	{0x11d, 35},
	{0x11d, 21},
	{0x168, 21},
	{0x1ac, 21},
	{0x140, 35},
	{0x281, 35},
	{0x501, 35}
};

void start_music()
{
	int sustain = 10;
  	int vol = 11;

  	set_envelope(ENV_TRIANGLE_INV_PERIOD_SHAPE, sustain);
  	enable_channel(2, true, false); /*ch_c*/
  	set_volume(2, vol); /*ch_c*/
}

bool update_music(UINT32 time_elapsed)
{
	 bool updated = false;

	  if (time_elapsed >= main_song[current_note].duration) {
	    current_note++;
	    updated = true;
	  }

	  if (current_note > (NOTES_SZ - 1))
	  {
	    current_note = 0;
	  }
	  
	  set_tone(2, main_song[current_note].freq); /*ch_c*/

	  return updated;
}
