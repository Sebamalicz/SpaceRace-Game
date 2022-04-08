#ifndef SPACERACE_ISR_H
#define	SPACERACE_ISR_H

/*includes*/
#include "types.h"

/*Constants*/
#define VBL_ISR 28
#define IKBD_ISR 79
#define IKBD_BUFF_SIZE 256
#define IKBD_RX_DEF 0xfffc96
#define IKBD_RX_INTER_OFF 0xfffc16



/*

*/
void vbl_req();

/*

*/
void ikbd_req();

/*

*/
void inst_vectors();

/*

*/
void rem_vectors();

/*

*/
Vector inst_vector(int num, Vector vector);

/*

*/
bool ikbd_waiting();

/*

*/
void write_to_ikbd_buffer(UINT8 scancode);

/*

*/
UINT32 read_ikbd();

/*

*/
void clear_ikbd();

/*

*/
UINT8 get_repeat_key();

#endif
