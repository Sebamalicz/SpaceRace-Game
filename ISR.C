#include "isr.h"



/*Global Variables*/
bool RENDER_REQUEST = true;
int GAME_TIMER = 0;
int AST_MOVE_TIMER = 0;
int KEY_REPEAT_TICKS = 0;
bool RENDER_REQUEST = true;
uint8 ikbd_buffer[256];
unsigned int buff_head = 0;
unsigned int buff_tail = 0;
uint8 repeated_key = 0;
bool key_repeat = false;

/*Vectors*/
Vector vbl_vector;
Vector ikbd_vector;

/*Volatiles*/
volatile UINT8* const ikbd_control = 0xfffc00;
volatile UINT8* const ikbd_status = 0xfffc00;
volatile UINT8* const ikbd_reader = 0xfffc02;
volatile UINT8* const isrb_mfp = 0xfffa11;
volatile UINT8* const ascii_table = 0xFFFE829C;


void vbl_req()
{
	GAME_TIMER++;
	AST_MOVE_TIMER++;
	KEY_REPEAT_TICKS++;
	RENDER_REQUEST = true;

}

void ikbd_req()
{
	uint8 scancode;

  	*ikbd_control = 0x16;
	  /* check if data was recieved */
	  if (*ikbd_status & 0x1) 
	  {
	    scancode = *ikbd_reader;
	    if (mouse_state == MOUSE_STATE_FIRST_PACKET) 
	    {
	      
		    if ((scancode & 0x80) == 0x00) 
		    { 
			    /* check if it's a make code */
			    write_to_ikbd_buffer(scancode);
			    key_repeat = true;
		    }
		    if ((scancode & 0x80) == 0x80) 
		    { 
			    /* check if it's a break code */
			    key_repeat = false;
		    }
	      }

	    *isrb_mfp_register &= MFB_BIT_6_MASK_OFF; /* clear bit 6 */
	  }

	  *ikbd_control = 0x96;
}

void inst_vectors()
{
	vbl_vector = install_vector(VBL_ISR, vbl_isr);
  	ikbd_vector = install_vector(IKBD_ISR, ikbd_isr);
}

void rem_vectors()
{
	install_vector(VBL_ISR, vbl_vector);
  	install_vector(IKBD_ISR, ikbd_vector);
	
}

Vector inst_vector(int num, Vector vector)
{
	Vector* vectptr = (Vector *) ((long) num << 2);
	Vector orig;
	long old_ssp = Super(0);

	orig = *vectptr;
	*vectptr = vector;

	Super(old_ssp);
	return orig;
}

bool ikbd_waiting()
{
	if(buff_head != buff_tail)
	{
		return true;
	}
	
	return false;
}

void write_to_ikbd_buffer(UINT8 scancode)
{
	if (buff_tail == IKBD_BUFFER_SIZE - 1)
	{
		buff_tail = 0;
	}

  	ikbd_buffer[buff_tail] = scancode;
  	buff_tail++;
	
}

UINT32 read_ikbd()
{
	  
	unsigned long ch;
  	long old_ssp = Super(0);

	  if (buff_head == IKBD_BUFFER_SIZE - 1)
	  {
	    buff_head = 0;
	  }

	  *isrb_mfp_register &= MFB_BIT_6_MASK_OFF;

	  ch = ikbd_buffer[buff_head];
	  ch = ch << 16;
	  ch = ch + *(ascii_table + ikbd_buffer[buff_head++]);

	  *isrb_mfp_register |= MFB_BIT_6_MASK_ON; /* turn bit 6 back on */

	  Super(old_ssp);
	  return ch;
	}

void clear_ikbd()
{
	while(ikbd_is_waiting()) 
	{
	    buff_head++;
	}

	ikbd_buffer[buff_tail] = 0x00;
}

UINT8 get_repeat_key()
{
	return repeated_key;
}
