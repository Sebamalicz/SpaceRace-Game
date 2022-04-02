#include "psg.h"

void write_psg(int reg, UINT8 val)
{
	long old_ssp;
	old_ssp = Super(0);
	
	*psg_reg
}

UINT8 read_psg(int reg)
{
	UINT8 placeholder;
	return placeholder;
}

void set_tone(int channel, int tuning)
{
	
}

void set_volume(int channel, int volume)
{
	
}

void enable_channel(int channel, int tone_on, int noise_on)
{
	
}

void stop_sound()
{
	
}

void set_noise(int tuning)
{
	
}

void set_envelope(int shape, unsigned int sustain)
{
	
}
