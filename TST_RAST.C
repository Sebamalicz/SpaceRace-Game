#include <osbind.h>
#include "raster.h"
#include <stdio.h>

int main()
{
	UINT16 *base;
	UINT8 *base_8;
	UINT32 *false_base;
	unsigned int height_16;
	unsigned int height_8;
	unsigned int false_height;
	int i;
	
	UINT16 spaceship_bitmap[16] =
	{
		0x0180,
		0x0240,
		0x0420,
		0x0810,
		0x1008,
		0x0C30,
		0x0420,
		0x0420,
		0x0420,
		0x0810,
		0x1008,
		0x2004,
		0x4002,
		0x399C,
		0x0990,
		0x0660
	};

	UINT8 asteroid_bitmap[8] =
	{
		0x00,
		0x18,
		0x3C,
		0x7E,
		0x7E,
		0x3C,
		0x18,
		0x00
	};

	UINT16* false_bitmap[10] = 
	{
		0x0000,
		0x0230,
		0x0000,
		0x0110,
		0x0000,
		0x0000,
		0x0420,
		0x0000,
		0x0000,
		0x0000
	};	
	
	UINT8 time_bitmap[8] = 
	{
		0x3C,
		0x3C,
		0x3C,
		0x3C,
		0x3C,
		0x3C,
		0x3C,
		0x3C
	};
	
	height_16 = 16;
	height_8 = 8;
	false_height = 10;
	base = (UINT16 *) Physbase();
	false_base = (UINT32 *) Physbase();
	base_8 = (UINT8 *) Physbase();
	
	printf("----------------------------------------------- \n");
	printf("Starting plot_bitmap_16 tests Begin \n");
	printf("Plot on Edge of screen \n");
	plot_bitmap_16(base, 0, 0, spaceship_bitmap,
			height_16);
	printf("Plot Central \n");
	plot_bitmap_16(base, 320, 200, spaceship_bitmap,
			height_16);
	printf("Plot Random \n");
	plot_bitmap_16(base, 456, 134, spaceship_bitmap,
			height_16);
	printf("Plot Outside Screen \n");
	plot_bitmap_16(base, 720, 500, spaceship_bitmap,
			height_16);
	printf("Bitmap Height different than bitmap size \n");
	plot_bitmap_16(base, 400, 200, spaceship_bitmap, 
			false_height);
	printf("Bitmap Size different than bitmap height \n");
	plot_bitmap_16(base, 500, 200, false_bitmap,
			height_16);
	printf("Invalid Base \n");
	plot_bitmap_16(false_base, 600, 200, spaceship_bitmap,
			height_16);
	printf("Plot_Bitmap_16 tests Complete \n");
	
	
	
	printf("------------------------------------------------ \n");
	printf("Plot_Bitmap_8 tests Begin \n");
	printf("Plot on Edge of screen \n");
	plot_bitmap_8(base_8, 0, 0, asteroid_bitmap, height_8);
	printf("Plot Central \n");
	plot_bitmap_8(base_8, 320, 200, asteroid_bitmap, height_8);
	printf("Plot Random \n");
	plot_bitmap_8(base_8, 456, 134, asteroid_bitmap, height_8);
	printf("Plot Outside Screen \n");
	plot_bitmap_8(base_8, 720, 500, asteroid_bitmap, height_8);
	printf("Bitmap Height different than bitmap size \n");
	plot_bitmap_8(base_8, 400, 200, asteroid_bitmap, 
					false_height);
	printf("Bitmap Size different than bitmap height \n");
	plot_bitmap_8(base_8, 600, 200, false_bitmap,
					height_8);
	printf("Invalid Base \n");
	plot_bitmap_8(false_base, 600, 200, asteroid_bitmap, 
					height_8);
	printf("Plot_bitmap_8 tests Complete \n");
	
	
	
	printf("--------------------------------------------------- \n");
	printf("Clear Screen Tests Begin \n");
	printf("Correct Height \n");
	clear_screen(base, height_16);
	printf("Invalid Height \n");
	clear_screen(base, false_height);
	printf("Invalid Base \n");
	clear_screen(false_base, height_16);
	printf("Clear Screen Tests Complete \n");
	
	
	
	printf("---------------------------------------------------- \n");
	printf("Plot Pixel Tests Begin \n");
	printf("Plot on Edge of screen \n");
	plot_pixel(base_8, 0, 0);
	printf("Plot Central \n");
	plot_pixel(base_8, 320, 200);
	printf("Plot Random \n");
	plot_pixel(base_8, 456, 134);
	printf("Plot Outside Screen \n");
	plot_pixel(base_8, 720, 500);
	printf("Invalid Base \n");
	plot_pixel(false_base, 320, 200);
	printf("Plot Pixel tests complete \n");
	
	
	
	printf("------------------------------------------------------- \n");
	printf("Plot Vertical Line tests Begin \n");
	printf("Plot on Edge of Screen \n");
	plot_vline(base_8, 0, 0, 399);
	printf("Plot Central \n");
	plot_vline(base_8, 320, 0, 399);
	printf("Plot Random \n");
	plot_vline(base_8, 456, 60, 250);
	printf("Plot Correct x, correct y1, incorrect y2 \n");
	plot_vline(base_8, 320, 60, 600);
	printf("Plot Correct x, incorrect y1, correct y2 \n");
	plot_vline(base_8, 320, 700, 200);
	printf("Plot incorrect x, correct y1, correct y2 \n");
	plot_vline(base_8, 650, 60, 250);
	printf("Invalid Base \n");
	plot_vline(false_base, 320, 0, 399);
	printf("Plot Vertical Line tests Complete \n");
	
	
	
	printf("--------------------------------------------------------- \n");
	printf("Plot Horizontal Line tests Begin \n");
	printf("Plot on Edge of Screen \n");
	plot_hline(base_8, 0, 639, 0);
	printf("Plot Central \n");
	plot_hline(base_8, 0, 639, 200);
	printf("Plot Random \n");
	plot_hline(base_8, 60, 400, 343);
	printf("Plot correct x1, correct x2, incorrect y \n");
	plot_hline(base_8, 40, 400, 900);
	printf("Plot correct x1, incorrect x2, correct y \n");
	plot_hline(base_8, 40, 650, 200);
	printf("Plot incorrect x1, correct x2, correct y \n");
	plot_hline(base_8, 650, 40, 200);
	printf("Invalid Base \n");
	plot_vline(false_base, 0, 320, 200);
	printf("Plot Horizontal Line tests Complete \n");
	printf("---------------------------------------------------------- \n");



	clear_screen(base, height_16);
	printf("All Tests Complete \n");
	
	for(i = 0; i < 8; i++)
	{
		plot_bitmap_8(base_8, 320, 200 + (i * 8), time_bitmap, 8);
	}


	for(i = 0; i < 32; i++)
	{
		clear_hline(base_8, 320, 328, 200 + i);
	}
	
	return 0;
}

