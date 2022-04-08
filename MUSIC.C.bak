#include "includes/music.h"
#include "includes/psg.h"

static int current_note = 0;

const notes main_song[] = 
{
	{0x3c0, 3}, 
	{0x11d, 5},
	{0x0b4, 5},
	{0x10d, 5},
	{0x140, 5},
	{0x0f0, 5},
	{0x140, 5},
	{0x0d6, 5},
	{0x140, 5},
	{0x0f0, 5},
	{0x140, 5},
	{0x0b4, 1},
	{0x140, 1},
	{0x168, 1},
	{0x2cf, 1},
	{0x23b, 1},
	{0x1e0, 1},
	{0x1ac, 1},
	{0x08f, 5},
	{0x140, 5},
	{0x0d6, 5},
	{0x140, 5},
	{0x0b4, 5},
	{0x0d6, 5},
	{0x140, 5},
	{0x1ac, 5},
	{0x10d, 5},
	{0x140, 5},
	{0x1ac, 5},
	{0x1fc, 5},
	{0x281, 5},
	{0x2cf, 5},
	{0x59e, 1},
	{0x140, 5},
	{0x11d, 5},
	{0x11d, 3},
	{0x168, 3},
	{0x1ac, 3},
	{0x140, 5},
	{0x281, 5},
	{0x501, 5}
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
