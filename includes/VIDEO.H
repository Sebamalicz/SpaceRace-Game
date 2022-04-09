#ifndef SPACERACE_VIDEO_H
#define	SPACERACE_VIDEO_H

#include "types.h"

/*
Equivalent to Physbase 
*/
UINT16* get_video_base();

/*
Equivalent to Setscreen
*/
void set_video_base(UINT16* base);

#endif
