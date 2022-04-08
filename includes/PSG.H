#ifndef SPACERACE_PSG_H
#define SPACERACE_PSG_H
#include "types.h"
#include <osbind.h>
#include <stdio.h>

#define CH_A_TONE 0x0
#define CH_B_TONE 0x2
#define CH_C_TONE 0x4

#define CH_A_ROUGH_TONE 0x1
#define CH_B_ROUGH_TONE 0x3
#define CH_C_ROUGH_TONE 0x5

#define CH_A_VOL 0x8
#define CH_B_VOL 0x9
#define CH_C_VOL 0xa

#define MIXER_ALL_OFF 0xff
#define MIXER_TONE_CH_A 0x3e
#define MIXER_TONE_CH_B 0x3d
#define MIXER_TONE_CH_C 0x3b
#define MIXER_NOISE_CH_A 0x37
#define MIXER_NOISE_CH_B 0x2f
#define MIXER_NOISE_CH_C 0x1f

#define NOISE_FREQUENCY_REG 0x6
#define MIXER_REG 0x7
#define ENVELOPE_FINE_REG 0xb
#define ENVELOPE_ROUGH_REG 0xc
#define ENVELOPE_SHAPE_CONTROL_REG 0xd

#define ENV_SAW_SHAPE 0xc
#define ENV_SAW_SHAPE_INV 0x8
#define ENV_SAW_PERIOD_SHAPE  0xf
#define ENV_TRIANGLE_SHAPE 0xe
#define ENV_TRIANGLE_INV_SHAPE 0xa
#define ENV_TRIANGLE_PERIOD_SHAPE  0xd
#define ENV_TRIANGLE_INV_PERIOD_SHAPE 0x00

#define reg_is_valid(reg) (reg >= 0 && reg <= 15)

extern volatile char* psg_reg_select = 0xFF8800;
extern volatile char* psg_reg_write  = 0xFF8802;

/* 0 = channel A, 1  = channel B, 2 = channel C*/

/*

Purpose: Writes a byte value to the PSG registers.

*/

void write_psg(int reg, UINT8 val);

/*

Purpose: Reads the value of a given PSG register.

*/

int read_psg(int reg);

/*

Purpose: Load the tone registers for a given channel with
the tune given.

*/

void set_tone(int channel, int tuning);

/*

Purpose: Load the volume register for a given channel

*/

void set_volume(int channel, int volume);

/*

Purpose: Sets a given channels noise/tone on or off.

*/

void enable_channel(int channel, int tone_on, int noise_on);

/*

Purpose: Stops all sound by slicencing PSG.

*/

void stop_sound();

/*

Purpose: Load noise register with given tune value.

*/

void set_noise(int tuning);

/*

Purpose: Set PSG envelope with given envelope shape and
sustain.

*/

void set_envelope(int shape, unsigned int sustain);

#endif
