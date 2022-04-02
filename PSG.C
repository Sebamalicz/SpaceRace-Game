#include "psg.h"

void write_psg(int reg, UINT8 val)
{
	long old_ssp;
	if(reg >= 0 && reg <= 15)
	{
		old_ssp = Super(0);
		
		*psg_reg_select = reg;
		*psg_reg_write = val;
		
		Super(old_ssp);
	}
}

UINT8 read_psg(int reg)
{
	long old_ssp;
  	int val = -1;

  	old_ssp = Super(0);

  	if (reg_is_valid(reg)) {
    		*psg_reg_select = reg;
    		val = *psg_reg_select;
  	}

  	Super(old_ssp);
  	return val;
}

void set_tone(int channel, int tuning)
{
	switch(channel)
	{
		case 0:
			write_psg(CH_A_TONE, tuning);
			break;
		case 1:
			write_psg(CH_B_TONE, tuning);
			break;
		case 2:
			write_psg(CH_C_TONE, tuning);
			break;
	}
	
}

void set_volume(int channel, int volume)
{
	switch(channel)
	{
		case 0:
			write_psg(CH_A_VOL, tuning);
			break;
		case 1:
			write_psg(CH_B_VOL, tuning);
			break;
		case 2:
			write_psg(CH_C_VOL, tuning);
			break;
	}
	
}

void enable_channel(int channel, int tone_on, int noise_on)
{
	bool tone_only = tone_on && !noise_on;
  bool noise_only = !tone_on && noise_on;
  bool tone_and_noise = tone_on && noise_on;
  int existing_mixer_val = read_psg(MIXER_REG);
  int channel_val;

  switch(channel) {
    case ch_a:
      if (tone_only)
        channel_val = existing_mixer_val != -1 ?
                      existing_mixer_val & MIXER_TONE_CH_A : MIXER_TONE_CH_A;
      else if (noise_only)
        channel_val = existing_mixer_val != -1 ?
                      existing_mixer_val & MIXER_NOISE_CH_A : MIXER_NOISE_CH_A;
      else if (tone_and_noise)
        channel_val = existing_mixer_val != -1 ?
                      existing_mixer_val & (MIXER_TONE_CH_A & MIXER_NOISE_CH_A) :
                      (MIXER_TONE_CH_A & MIXER_NOISE_CH_A);
          break;
    case ch_b:
      if (tone_only)
        channel_val = existing_mixer_val != -1 ?
                      existing_mixer_val & MIXER_TONE_CH_B : MIXER_TONE_CH_B;
      else if (noise_only)
        channel_val = existing_mixer_val != -1 ?
                      existing_mixer_val & MIXER_NOISE_CH_B : MIXER_NOISE_CH_B;
      else if (tone_and_noise)
        channel_val = existing_mixer_val != -1 ?
                      existing_mixer_val & (MIXER_TONE_CH_B & MIXER_NOISE_CH_B) :
                      (MIXER_TONE_CH_B & MIXER_NOISE_CH_B);
          break;
    case ch_c:
      if (tone_only)
        channel_val = existing_mixer_val != -1 ?
                      existing_mixer_val & MIXER_TONE_CH_C : MIXER_TONE_CH_C;
      else if (noise_only)
        channel_val = existing_mixer_val != -1 ?
                      existing_mixer_val & MIXER_NOISE_CH_C : MIXER_NOISE_CH_C;
      else if (tone_and_noise)
        channel_val = existing_mixer_val != -1 ?
                      existing_mixer_val & (MIXER_TONE_CH_C & MIXER_NOISE_CH_C) :
                      (MIXER_TONE_CH_C & MIXER_NOISE_CH_C);
          break;
  }

  write_psg(MIXER_REG, channel_val);
	
}

void stop_sound()
{
	write_psg(MIXER_REG, 0x00);
	write_psg(NOISE_FREQUENCY_REG, 0x00);
	write_psg(ENVELOPE_FINE_REG, 0x00);
	write_psg(ENVELOPE_ROUGH_REG, 0x00);
	write_psg(ENVELOPE_SHAPE_CONTROL_REG, 0x00);

	set_volume(0, 0);
	set_volume(1, 0);
	set_volume(2, 0);
	
}

void set_noise(int tuning)
{
	wrtie_psg(NOISE_FREQUENCY_REG, tuning);
	
}

void set_envelope(int shape, unsigned int sustain)
{
	int shape_val;
  	write_psg(ENVELOPE_FINE_REG, sustain);
  	write_psg(ENVELOPE_ROUGH_REG, sustain);

  	switch(shape) {
    	case saw:
      		shape_val = ENV_SAW_SHAPE;
          	break;
    	case saw_inv:
      		shape_val = ENV_SAW_SHAPE_INV;
          	break;
    	case saw_period:
      		shape_val = ENV_SAW_PERIOD_SHAPE;
		break;
    	case triangle:
      		shape_val = ENV_TRIANGLE_SHAPE;
          	break;
    	case triangle_inv:
      		shape_val = ENV_TRIANGLE_INV_SHAPE;
          	break;
    	case triangle_period:
      		shape_val = ENV_TRIANGLE_PERIOD_SHAPE;
          	break;
    	case triangle_inv_period:
      		shape_val = ENV_TRIANGLE_INV_PERIOD_SHAPE;
         	 break;
  	}

  	write_psg(ENVELOPE_SHAPE_CONTROL_REG, shape_val);
		
}
