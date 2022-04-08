#ifndef SPACERACE_ISR_H
#define	SPACERACE_ISR_H

/*includes*/
#include "types.h"
#include "vbl.h"
#include <osbind.h>
#include <osbind>

/*typedefs*/
typedef UINT8 SCANCODE;
typedef void (*Vector) ();

/*Constants*/
/*VBL*/
#define VBL_ISR 28
/*IKBD*/
#define IKBD_ISR 79
#define IKBD_BUFF_SIZE 256
#define IKBD_RX_DEF 0xfffc96
#define IKBD_RX_INTER_OFF 0xfffc16
#define MFB_BIT_6_MASK_ON 0x40
#define MFB_BIT_6_MASK_OFF 0xbf


/*

Purpose: Update timer on VBL IRQ.

Details: times any synchronous events such as page flipping for double
buffered graphics and the playing of music.

*/
void vbl_req();

/*

Purpose: Processes keyboard input on IKBD IRQ.

Details: handles key scancodes and key repeats(checking for break code).

*/

void ikbd_req();

/*

Purpose: Install vbl and ikbd vectors.

*/

void inst_vectors();

/*

Purpose: Remove vbl and ikbd vectors.

*/

void rem_vectors();

/*

Purpose: Install a single vector, used for vbl and ikbd and returns original vector.

*/

Vector inst_vector(int num, Vector vector);

/*

Purpose: Checks if keybaord is waiting for input.

*/

bool ikbd_waiting();

/*

Purpose: Takes key code and writes it to keyboard buffer.

*/

void write_to_ikbd_buffer(UINT8 scancode);

/*

Purpose: Reads key code from keyboard buffer.

*/

UINT32 read_ikbd();

/*

Purpose: Clears keyboard buffer.

*/

void clear_ikbd();

/*

*/

UINT8 get_repeat_key();



#endif
