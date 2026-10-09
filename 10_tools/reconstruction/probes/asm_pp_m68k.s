# asm_pp_m68k.s -- probe (plan 412): m68k (MIT syntax); KR_VAL is 5 in the code only
# when cc runs the C preprocessor on .s files.
#define KR_VAL 5
	.text
	.globl	_kr_pp
_kr_pp:
	movel	sp@(4),d0
	addql	#KR_VAL,d0
	movel	d0,sp@-
	jsr	_kr_pp_ext
	addql	#4,sp
	rts
	.data
	.globl	_kr_pp_data
_kr_pp_data:
	.long	KR_VAL
	.long	_kr_pp
