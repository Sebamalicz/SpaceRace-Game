/*
This is the header for the various functions that will change/alter
the current screen. This includes plotting various pictures, pixels,
lines and/or clearing the screen in order to plot something new on
the screen.
*/
#ifndef RASTER_H
#define RASTER_H

#include "types.h"
#include <stdio.h>

/*
Purpose: the purpose of this function is to plot a bitmap of size 16
	at a given x and y coordinate.
Input Parameters:
	UINT16 *base:
	int x: the x location that the bitmap will be plotted at
	int y: the y location that the bitmap will be plotted at
	const UINT16 *bitmap: the bitmap to be plotted to the screen
	unsigned int height: the height of the bitmap
*/
void plot_bitmap_16(UINT16 *base, int x, int y, 
		    const UINT16 *bitmap, unsigned int height);

/*
Purpose: the purpose of this function is to plot the bitmap of size 8
	 at the given x and y coordinates
Input Parameters:
	UINT8 *base:
	int x: the x location the bitmap will be plotted at
	int y: the y location the bitmap will be plotted at
	const UINT8 *bitmap: the bitmap to be plotted
	unsigned int height: the height of the bitmap
*/
void plot_bitmap_8(UINT8 *base, int x, int y,
		    const UINT8 *bitmap, unsigned int height);

/*
Purpose: the purpose of this function is to clear the screen of any
		bits that are currently set on the screen.
Input Parameters:
	UINT16 *base:
	unsigned int height: the height of the bitmap that is printed which 
						 is all zero's.
*/
void clear_screen(UINT16 *base, unsigned int height);

/*
Purpose: The purpose of this function is to plot a single pixel to the 
		screen at the given x and y coordinate.
Input Parameters:
	UINT8 *base:
	int x: the x for the pixel to be plotted at
	int y: the y for the pixel to be plotted at0
*/
void plot_pixel(UINT8 *base, int x, int y);

/*
Purpose: The purpose of this function is to plot a vertical line from one
		y coordinate to the next at a specific x coordinate
Input Parameters:
	UINT8 *base:
	int x: the x for the line to be plotted at
	int y1: the first y to start the plot
	int y2: the second y where the plot should end
*/
void plot_vline(UINT8 *base, int x, int y1, int y2);

/*
Purpose: the purpose of this function is to draw a horizontal line
		from the first x to the last x at the given y coordinate
Input Parameters:
	UINT8 *base:
	int x1: the first x to start the plot at
	int x2: the x to plot the line to
	int y: the y coordinate to plot the line at
*/
void plot_hline(UINT8 *base, int x1, int x2, int y);

/*
Purpose: the purpose of this function is to clear a horizontal line
		from the first x to the last x at the given y coordinate

Input Parameters:
	UINT8 *base:
	int x1: the first x to start the clear at
	int x2: the x to clear the bits to
	int y: the y coordinate to plot the line at
*/
void clear_hline(UINT8 *base, int x1, int x2, int y);

/*
Purpose: the purpose of this function is to quickly clear the screen
		of all things(including the blinking cursor) 
*/
void blank_screen();

void plot_screen(UINT32* base, UINT32* bitmap);

#endif
