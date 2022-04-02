/*
This is the implementation file for the functions that change/alter
the current screens state and plot new and various things onto the
screen. The functions in this file can plot various photos, pixels,
lines, and various other things as well as clear the screen of all
currently on pixels.
*/


#include "includes/raster.h"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define HEIGHT_16 16
#define HEIGHT_8 8
#define BITMAP_SIZE_1 1
#define BITMAP_SIZE_2 2
#define BASE_SIZE_1 1
#define BASE_SIZE_2 2
#define WIDTH_MIN 0
#define HEIGHT_MIN 0


void plot_bitmap_16(UINT16 *base, int x, int y,
		       const UINT16 *bitmap, unsigned int height)
{
	int i;
	int bitmap_size;
	int base_size;
	int offset;
	if(x < SCREEN_WIDTH && x >= WIDTH_MIN&&
	   y < SCREEN_HEIGHT && y >= HEIGHT_MIN){
	/*Check if x and y is within the Screen Height and Width*/
		
		if(height == HEIGHT_16){
		/*Checks if height of bitmap is correct*/
			bitmap_size = sizeof(*bitmap);
			if(bitmap_size == BITMAP_SIZE_2)
			{
			/*Check if size of bitmap is 2*/
				base_size = sizeof(*base);
				if(base_size == BASE_SIZE_2)
				{
				/*Checks if base size is 2*/
					offset = (x >> 4) + (y * 40);
					
					for(i = 0; i < height; i++)
					{
						*(base + offset + (40 * i)) = bitmap[i] >> (x & 15);
						*(base + offset + (40 * i) + 1) = bitmap[i] << 16 - (x & 15);
					}
				}
			}
		}
	}
				
	
	return;
	
}

void plot_bitmap_8(UINT8 *base, int x, int y,
		     const UINT8 *bitmap, unsigned int height)
{
	int i;
	int offset;
	int bitmap_size;
	long base_size;
	
	if(x < SCREEN_WIDTH && x >= WIDTH_MIN &&
	   y < SCREEN_HEIGHT && y >= HEIGHT_MIN)
	{
	/*Checks if x and y are within boundary*/
		if(height == HEIGHT_8)
		{			
		/*Checks is height is equal to bitmap height*/
			bitmap_size = sizeof(*bitmap);
			if(bitmap_size == BITMAP_SIZE_1)
			{
			/*Checks if bitmap size is correct*/
				base_size == sizeof(*base);
				offset = (x >> 3) + (y * 80);

				for(i = 0; i < height; i++)
				{
					*(base + offset + (80 * i)) = bitmap[i] >> (x & 7);
					*(base + offset + (80 * i) + 1) = bitmap[i] << 8 - (x & 7);
				}
			}
		}
	}
		
	return;
}

void clear_screen(UINT16 *base, unsigned int height)
{
	int i;
	int x;
	int y;
	int offset;
	int base_size;
	if(height == HEIGHT_16)
	{
		base_size = sizeof(*base);
		if(base_size == BASE_SIZE_2)
		{
			for(y = 0; y < SCREEN_HEIGHT; y += 16)
			{
				for(x = 0; x < SCREEN_WIDTH; x += 16)
				{
					for(i = 0; i < height; i++)
					{
						offset = (x >> 4) + (y * 40);
						*(base + offset + (40 * i)) = 0x0000;
					}
				}
			}
		}
	}
	return;
}

void plot_pixel(UINT8 *base, int x, int y)
{
	if(x >= WIDTH_MIN && x < SCREEN_WIDTH && 
	   y >= HEIGHT_MIN && y < SCREEN_HEIGHT)
	{
	/*Check if x and y is inside Screen boundaries*/
		*(base + (y * 80) + (x >> 3)) |= 1 << (7 - (x & 7));
	}

	return;
}

void plot_vline(UINT8 *base, int x, int y1, int y2)
{
	int temp;	
	UINT8 pattern;
	UINT8 *screen_byte;

	if(x >= WIDTH_MIN && x < SCREEN_WIDTH)
	{
		if(y1 > y2)
		{
			temp = y1;
			y1 = y2;
			y2 = temp; /*swap y1 and y2*/
		}
		if(y1 < 0)
		{
			y1 = 0;
		}

		if(y2 > SCREEN_HEIGHT - 1)
		{
			y2 = SCREEN_HEIGHT - 1;
		}
		
		pattern = 1 << (7 - (x & 7));
		screen_byte = base + (y1 * 80) + (x >> 3);
		for( ; y1 <= y2; y1++)
		{
			*screen_byte = pattern;
			screen_byte = screen_byte + 80;
		}
	}	
	return;
}

void plot_hline(UINT8 *base, int x1, int x2, int y)
{
	UINT8 p1, p2;
	int row1, row2, i;
	int shift_F, shift_B;
	UINT8 *place = base + (y * 80);

	row1 = x1 >> 3;
	row2 = x2 >> 3;
	shift_F = x1 * 7;
	shift_B = 7 - (x2 & 7);

	if(row1 == row2)
	{
		p1 = 0xFF >> shift_F;
		p2 = 0xFF << shift_B;
		*(place + row1) = p1 & p2;
	}
	else
	{
		p1 = 0xFF >> shift_F;
		p2 = 0xFF << shift_B;
		*(place + row1) = p1;
		for(i = row1 + 1; i < row2; i++)
		{
			*(place + i) = 0xFF;
		}	
		*(place + row2) = p2;
	}
	return;
}

void clear_hline(UINT8 *base, int x1, int x2, int y)
{
	UINT8 p1, p2;
	int row1, row2, i;
	int shift_F, shift_B;
	UINT8 *place = base + (y * 80);

	row1 = x1 >> 3;
	row2 = x2 >> 3;
	shift_F = x1 * 7;
	shift_B = 7 - (x2 & 7);

	if(row1 == row2)
	{
		p1 = 0x00 >> shift_F;
		p2 = 0x00 << shift_B;
		*(place + row1) = p1 & p2;
	}
	else
	{
		p1 = 0x00 >> shift_F;
		p2 = 0x00 << shift_B;
		*(place + row1) = p1;
		for(i = row1 + 1; i < row2; i++)
		{
			*(place + i) = 0x00;
		}	
		*(place + row2) = p2;
	}
	return;
}

void blank_screen()
{
	printf("\033E\033f\n");
	/*clears all elements of the screen*/
}

void plot_screen(UINT32* base, UINT32* bitmap)
{
	int i;
	for(i = 0; i < 8000; i++)
	{
		*(base + i) = bitmap[i];
	}
}