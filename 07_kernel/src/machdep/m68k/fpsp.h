//
//	fpsp.h 1.6 10/8/90
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.

//	fpsp.h --- stack frame offsets during FPSP exception handling
//
//	These equates are used to access the exception frame, the fsave
//	frame and any local variables needed by the FPSP package.
//	
//	All FPSP handlers begin by executing:
//
//		link	a6,#-LOCAL_SIZE
//		fsave	-(a7)
//		movem.l	d0-d7,USER_D0(a6)
//		movem.l	a0-a1,USER_A0(a6)
//		fmovem.x fp0-fp1,USER_FP0(a6)
//		fmove.l	fpsr/fpcr/fpiar,USER_FPSR(a6)
//
//	After initialization, the stack looks like this:
//
//	A7 --->	+-------------------------------+
//		|				|
//		|	FPU fsave area		|
//		|				|
//		+-------------------------------+
//		|				|
//		|	FPSP Local Variables	|
//		|	     including		|
//		|	  saved registers	|
//		|				|
//		+-------------------------------+
//	A6 --->	|	Saved A6		|
//		+-------------------------------+
//		|				|
//		|	Exception Frame		|
//		|				|
//		|				|
//
//	Positive offsets from A6 refer to the exception frame.  Negative
//	offsets refer to the Local Variable area and the fsave area.
//	The fsave frame is also accessible 'from the top' via A7.
//
//	On exit, the handlers execute:
//
//		movem.l	USER_D0(a6),d0-d7
//		movem.l	USER_A0(a6),a0-a1
//		fmovem.x USER_FP0(a6),fp0-fp1
//		fmove.l	USER_FPSR(a6),fpsr/fpcr/fpiar
//		frestore (a7)+
//		unlk	a6
//
//	and then either 'bra fpsp_done' if the exception was completely handled
//	by the package, or 'bra real_xxxx' which is an external label
//	to a routine that will process a real exception of the type
//	that was generated.  Some handlers may omit the 'frestore'
//	if the FPU state after the exception is idle.
//
//	Sometimes the exception handler will transform the fsave area
//	because it needs to report an exception back to the user.  This
//	can happen if the package is entered for an unimplemented float
//	instruction that generates (say) an underflow.  Alternatively,
//	a second fsave frame can be pushed onto the stack and the handler
//	exit code will reload the new frame and discard the old.
//
//	The registers d0, d1, a0, a1, fp0 and fp1 are always saved and
//	restored from the 'local variable' area and can be used as
//	temporaries.  If a routine needs to change any
//	of these registers, it should modify the saved copy and let
//	the handler exit code restore the value.  Space is allocated
//	in the stack frame for d2-d7 so that the entire register set
//	can be available if needed.
//
//	NOTE:  The entry code currently saves all data registers so that
//	the dynamic K-factor and fmove(out) code can get to the
//	registers directly.  In the future, the USER_D2 through USER_D7
//	may only be saved when their values are needed.
//
//--------------------------------------------------------------------------
//
//	Local Variables on the stack
//
#define local_size 192
#define lv -local_size
//
#define user_d0 lv+0
#define user_d1 lv+4
#define user_d2 lv+8
#define user_d3 lv+12
#define user_d4 lv+16
#define user_d5 lv+20
#define user_d6 lv+24
#define user_d7 lv+28
#define user_a0 lv+32
#define user_a1 lv+36
#define user_fp0 lv+40
#define user_fp1 lv+52
#define user_fpcr lv+64
#define fpcr_enable user_fpcr+2
#define fpcr_mode user_fpcr+3
#define user_fpsr lv+68
#define fpsr_cc user_fpsr+0
#define fpsr_qbyte user_fpsr+1
#define fpsr_except user_fpsr+2
#define fpsr_aexcept user_fpsr+3
#define user_fpi lv+72
#define fp_scr1 lv+76
#define fp_scr2 lv+92
#define l_scr1 lv+108
#define l_scr2 lv+112
#define store_flg lv+116
#define bindec_flg lv+117
#define dnrm_flg lv+118
#define res_flg lv+119
#define dy_mo_flg lv+120
#define uflg_tmp lv+121
//
//NEXT		equ	LV+124
//
//--------------------------------------------------------------------------
//
//	fsave offsets and bit definitions
//
//	Offsets are defined from the end of an fsave because the last 10
//	words of a busy frame are the same as the unimplemented frame.
//
#define cu_savepc lv-92
//
#define wbtemp lv-76
#define wbtemp_ex wbtemp
#define wbtemp_hi wbtemp+4
#define wbtemp_lo wbtemp+8
//
#define wbtemp_sgn wbtemp+2
//
#define fpsr_shadow lv-64
//
#define fpicu lv-60
//
#define cmdreg3b lv-48
//
#define nmnexc lv-44
#define nmn_unsup_bit 1
#define nmn_snan_bit 0
//
#define nmcexc lv-43
#define nmn_operr_bit 7
#define nmn_ovfl_bit 6
#define nmn_unfl_bit 5
#define nmc_unsup_bit 4
#define nmc_snan_bit 3
#define nmc_operr_bit 2
#define nmc_ovfl_bit 1
#define nmc_unfl_bit 0
//
#define stag lv-40
#define wbtemp_grs lv-40
#define stag_mask 0xe0
#define denorm_bit 7
#define etemp15_bit 4
#define wbtemp66_bit 2
#define wbtemp1_bit 1
#define wbtemp0_bit 0
//
#define sticky lv-39
#define sticky_bit 7
//
#define cmdreg1b lv-36
#define kfact_bit 12
//					;on packed move out's.  NOTE: this
//					;equate only works when CMDREG1B is in
//					;a register.
//
#define cmdword lv-35
#define direction_bit 5
#define size_bit2 12
//
#define dtag lv-32
#define dtag_mask 0xe0
#define fptemp15_bit 4
//
#define wb_byte lv-31
#define wbtemp15_bit 4
//
#define e_byte lv-28
#define e1 2
#define e3 1
#define sflag 0
//
#define t_byte lv-27
#define xflag 7
#define uflag 5
#define tflag 4
//
#define fptemp lv-24
#define fptemp_ex fptemp
#define fptemp_hi fptemp+4
#define fptemp_lo fptemp+8
//
#define fptemp_sgn fptemp+2
//
#define etemp lv-12
#define etemp_ex etemp
#define etemp_hi etemp+4
#define etemp_lo etemp+8
//
#define etemp_sgn etemp+2
//
#define exc_sr 4
#define exc_pc 6
#define exc_vec 10
#define exc_ea 12
//
//--------------------------------------------------------------------------
//
//	FPSR/FPCR bits
//
#define neg_bit 3
#define z_bit 2
#define inf_bit 1
#define nan_bit 0
//
#define q_sn_bit 7
//
#define bsun_bit 7
#define snan_bit 6
#define operr_bit 5
#define ovfl_bit 4
#define unfl_bit 3
#define dz_bit 2
#define inex2_bit 1
#define inex1_bit 0
//
#define aiop_bit 7
#define aovfl_bit 6
#define aunfl_bit 5
#define adz_bit 4
#define ainex_bit 3
//
//	FPSR individual bit masks
//
#define neg_mask 0x08000000
#define z_mask 0x04000000
#define inf_mask 0x02000000
#define nan_mask 0x01000000
//
#define bsun_mask 0x00008000
#define snan_mask 0x00004000
#define operr_mask 0x00002000
#define ovfl_mask 0x00001000
#define unfl_mask 0x00000800
#define dz_mask 0x00000400
#define inex2_mask 0x00000200
#define inex1_mask 0x00000100
//
#define aiop_mask 0x00000080
#define aovfl_mask 0x00000040
#define aunfl_mask 0x00000020
#define adz_mask 0x00000010
#define ainex_mask 0x00000008
//
//	FPSR combinations used in the FPSP
//
#define dzinf_mask inf_mask+dz_mask+adz_mask
#define opnan_mask nan_mask+operr_mask+aiop_mask
#define nzi_mask 0x01ffffff
#define unfinx_mask unfl_mask+inex2_mask+aunfl_mask+ainex_mask
#define unf2inx_mask unfl_mask+inex2_mask+ainex_mask
#define ovfinx_mask ovfl_mask+inex2_mask+aovfl_mask+ainex_mask
#define inx1a_mask inex1_mask+ainex_mask
#define inx2a_mask inex2_mask+ainex_mask
#define snaniop_mask nan_mask+snan_mask+aiop_mask
#define naniop_mask nan_mask+aiop_mask
#define neginf_mask neg_mask+inf_mask
#define infaiop_mask inf_mask+aiop_mask
#define negz_mask neg_mask+z_mask
#define opaop_mask operr_mask+aiop_mask
#define unfl_inx_mask unfl_mask+aunfl_mask+inex2_mask+ainex_mask
//
//--------------------------------------------------------------------------
//
//	FPCR rounding modes
//
#define x_mode 0x00
#define s_mode 0x40
#define d_mode 0x80
//
#define rn_mode 0x00
#define rz_mode 0x10
#define rm_mode 0x20
#define rp_mode 0x30
//
//--------------------------------------------------------------------------
//
//	Miscellaneous equates
//
#define signan_bit 6
#define sign_bit 7
//
#define rnd_stky_bit 29
//				this can only be used if in a data register
//
#define local_ex 0
#define local_sgn 2
#define local_hi 4
#define local_lo 8
//
//
#define norm_tag 0x00
#define zero_tag 0x20
#define inf_tag 0x40
#define nan_tag 0x60
#define dnrm_tag 0x80
//
//	fsave sizes and formats
//
#define busy_size 100
#define busy_frame lv-busy_size
#define busy_fmt 0x40600000
//
#define unimp_size 44
#define unimp_frame lv-unimp_size
#define unimp_fmt 0x40280000
//
#define idle_size 4
#define idle_frame lv-idle_size
#define idle_fmt 0x40000000
//
//	exception vectors
//
#define trace_vec 0x2024
#define fline_vec 0x002c
#define unimp_vec 0x202c
#define inex_vec 0x00c4
//
#define dbl_thresh 0x3c01
#define sgl_thresh 0x3f81
//
