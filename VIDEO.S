;-----------XREF's/XDEF's-----------------------;

	xdef	_get_video_base
	xdef	_set_video_base
	xref 	svisor_on
	xref	svisor_off

;-----------CONSTANTS---------------------------;

SCREEN 	equ	$FFFF8201	;screens starting address FFFF8201
OFFSET	equ	8

;-----------FUNCTIONS---------------------------;

_get_video_base:
	move.l	a0,-(sp)
	clr.l	d0

	move.l	d0,-(sp)
	clr.l	-(sp)
	move.w	#$20,-(sp)
	trap	#1
	addq.l	#6,sp
	move.l	d0,old_ssp
	move.l	(sp)+,d0
	
	lea	SCREEN,a0
	movep.w	(a0),d0
	lsl.l	#8,d0

	move.l	d0,-(sp)
	move.l	(old_ssp),-(sp)
	move.w	#$20,-(sp)
	trap	#1
	addq.l	#6,sp
	move.l	(sp)+,d0

	move.l	(sp)+,a0
	rts

_set_video_base:
	link	a6,#0
	movem.l	d0/a0,-(sp)

	move.l	d0,-(sp)
	clr.l	-(sp)
	move.w	#$20,-(sp)
	trap	#1
	addq.l	#6,sp
	move.l	d0,old_ssp
	move.l	(sp)+,d0
	
	move.l	OFFSET(a6),d0
	lsr.l	#8,d0
	lea		SCREEN,a0
	movep.w	d0,0(a0)

	move.l	d0,-(sp)
	move.l	(old_ssp),-(sp)
	move.w	#$20,-(sp)
	trap	#1
	addq.l	#6,sp
	move.l	(sp)+,d0
	
	movem.l	(sp)+,d0/a0
	unlk	a6
	rts

old_ssp:	ds.l	1	
