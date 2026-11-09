// Hybrid reconstruction of the m68k FPSP region [0x409ab9c, 0x40a5510) of the original mach_kernel (plans 767-771, user decision D174).
// NeXTMach parts: lines of the FPSP sources fpsp/<name>.sa of NeXTMach (https://github.com/johnsonjh/NeXTMach.git, commit f6bdb9c3268f0eadc545d41bcc0564453b17001e,
// directory mk-108.1/fpsp), converted to NeXT as syntax by the NeXTMach converter fpsp/conv.c (SHA-256 e4f26864f86f3246fc9179f63e8672dace2d9f5d8a523a9b4a72feda0f527b42)
// built from the project copy conv_fixed.c (SHA-256 823f390374317c35a3891bd1e7d65b1c4a7556d724166fa87c7fb68fb4eec81e; 16 diff lines: a strcpy definition, <string.h>, three
// bounds guards); fpsp.h is the conversion of fpsp/fpsp.sa
// (Makefile rule fpsp.h: fpsp.sa conv).  Sources with adopted lines (35): bindec, binstr, decbin, do_func, gen_except, get_op, kernel_ex, res_func, sacos, sasin, satan,
// satanh, scosh, setox, sint, skeleton, slog2, slogn, srem_mod, ssin, ssinh, stan, stanh, sto_res, stwotox, util, x_bsun, x_fline, x_operr, x_ovfl, x_snan, x_store, x_unfl,
// x_unimp, x_unsupp.
// The comment text of each of these sources that carries the Motorola notice ("Copyright (C) Motorola, Inc. 1990", "All Rights Reserved", "THIS IS UNPUBLISHED PROPRIETARY
// SOURCE CODE OF MOTOROLA", "The copyright notice above does not evidence any actual or intended publication of such source code."), is kept below unchanged.
// Project changes to the NeXTMach lines: the section directive .data of 11 converted files was changed to .text; operand symbols were rewritten to the label of the original
// address (the original symbol name or ADR_<hex>); non-numeric label definitions, .globl/xdef lines and conditional directives were removed (numeric local labels are kept; NeXT true, FP_DEBUG false);
// file-local #define lines were moved to the top; labels were inserted.  For 133 lines whose NeXTMach label has no counterpart (plan 771) the operand target was read from the
// original bytes (list: 06_reconstruction/evidence/m68k-fpsp-ofb.tsv).
// Parts written by this project (user decision D174, D024): every label, instruction row and .word dump that is not a NeXTMach line was written from the original bytes
// (NeXT otool disassembly of the original mach_kernel).  The names ADR_<hex> are project-chosen local labels and are not original symbols; original symbols keep their names.
// Later Motorola FPSP sources were not imported.  The __text of the object assembled from this file, with relocations resolved at the original addresses, equals the original bytes of the region.
// A NeXTMach line was adopted when its assembled bytes equal the original bytes at the mapped address: a byte match, not a proof that it is the same source line of the
// original.  Limits: of the 133 lines with an operand read from the original bytes, 97 have no name anchor; 260 adopted units (1574 bytes) have a byte string that occurs
// more than once in the original.
// Provenance: 07_kernel/PROVENANCE.tsv, 07_kernel/MODIFICATIONS.md, 06_reconstruction/evidence/m68k-fpsp.md and m68k-fpsp-units.tsv.  D013 is a user decision on committing
// NeXTMach-derived code, not a license grant.
#include "fpsp.h"
#define edigits 2
#define estrt 4
#define ten 10
#define fstrt 0
#define fnibs 7
	.text
//
//	bindec.sa 1.14 10/9/90
//
//	bindec
//
//	Description:
//		Converts an input in extended precision format
//		to bcd format.
//
//	Input:
//		a0 points to the input extended precision value
//		value in memory; d0 contains the k-factor sign-extended
//		to 32-bits.  The input may be either normalized,
//		unnormalized, or denormalized.
//
//	Output:	result in the FP_SCR1 space on the stack.
//
//	Saves and Modifies: D2-D7,A2,FP2
//
//	Algorithm:
//
//	A1.	Set RM and size ext;  Set SIGMA = sign of input.  
//		The k-factor is saved for use in d7. Clear the
//		BINDEC_FLG for separating normalized/denormalized
//		input.  If input is unnormalized or denormalized,
//       normalize it.
//
//	A2.	Set X = abs(input).
//
//	A3.	Compute ILOG.
//		ILOG is the log base 10 of the input value.  It is
//		approximated by adding e + 0.f when the original 
//		value is viewed as 2^^e * 1.f in extended precision.  
//		This value is stored in d6.
//
//	A4.	Clr INEX bit.
//		The operation in A3 above may have set INEX2.  
//
//	A5.	Set ICTR = 0;
//		ICTR is a flag used in A13.  It must be set before the 
//		loop entry A6.
//
//	A6.	Calculate LEN.
//		LEN is the number of digits to be displayed.  The
//		k-factor can dictate either the total number of digits,
//		if it is a positive number, or the number of digits
//		after the decimal point which are to be included as
//		significant.  See the 68882 manual for examples.
//		If LEN is computed to be greater than 17, set OPERR in
//		USER_FPSR.  LEN is stored in d4.
//
//	A7.	Calculate SCALE.
//		SCALE is equal to 10^ISCALE, where ISCALE is the number
//		of decimal places needed to insure LEN integer digits
//		in the output before conversion to bcd. LAMBDA is the
//		sign of ISCALE, used in A9. Fp1 contains
//		10^^(abs(ISCALE)) using a rounding mode which is a
//		function of the original rounding mode and the signs
//		of ISCALE and X.  A table is given in the code.
//
//	A8.	Clr INEX; Force RZ.
//		The operation in A3 above may have set INEX2.  
//		RZ mode is forced for the scaling operation to insure
//		only one rounding error.  The grs bits are collected in 
//		the INEX flag for use in A10.
//
//	A9.	Scale X -> Y.
//		The mantissa is scaled to the desired number of
//		significant digits.  The excess digits are collected
//		in INEX2.
//
//	A10.	Or in INEX.
//		If INEX is set, round error occured.  This is
//		compensated for by 'or-ing' in the INEX2 flag to
//		the lsb of Y.
//
//	A11.	Restore original FPCR; set size ext.
//		Perform FINT operation in the user's rounding mode.
//		Keep the size to extended.
//
//	A12.	Calculate YINT = FINT(Y) according to user's rounding
//		mode.  The FPSP routine sintd0 is used.  The output
//		is in fp0.
//
//	A13.	Check for LEN digits.
//		If the int operation results in more than LEN digits,
//		or less than LEN -1 digits, adjust ILOG and repeat from
//		A6.  This test occurs only on the first pass.  If the
//		result is exactly 10^LEN, decrement ILOG and divide
//		the mantissa by 10.
//
//	A14.	Convert the mantissa to bcd.
//		The binstr routine is used to convert the LEN digit 
//		mantissa to bcd in memory.  The input to binstr is
//		to be a fraction; i.e. (mantissa)/10^LEN and adjusted
//		such that the decimal point is to the left of bit 63.
//		The bcd digits are stored in the correct position in 
//		the final string area in memory.
//
//	A15.	Convert the exponent to bcd.
//		As in A14 above, the exp is converted to bcd and the
//		digits are stored in the final string.
//		Test the length of the final exponent string.  If the
//		length is 4, set operr.
//
//	A16.	Write sign bits to final string.
//
//	Implementation Notes:
//
//	The registers are used as follows:
//
//		d0: scratch; LEN input to binstr
//		d1: scratch
//		d2: upper 32-bits of mantissa for binstr
//		d3: scratch;lower 32-bits of mantissa for binstr
//		d4: LEN
//      		d5: LAMBDA/ICTR
//		d6: ILOG
//		d7: k-factor
//		a0: ptr for original operand/final result
//		a1: scratch pointer
//		a2: pointer to FP_X; abs(original value) in ext
//		fp0: scratch
//		fp1: scratch
//		fp2: scratch
//		F_SCR1:
//		F_SCR2:
//		L_SCR1:
//		L_SCR2:

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



// Constants in extended precision
ADR_409ab9c:
  	.int	0x3ffd0000,0x9a209a84,0xfbcff798,0x00000000
ADR_409abac:
 	.int	0x3ffd0000,0x9a209a84,0xfbcff799,0x00000000

// Constants in single precision
ADR_409abbc:
  	.int	0x3f800000,0x00000000,0x00000000,0x00000000
 	.int	0x40000000,0x00000000,0x00000000,0x00000000
ADR_409abdc:
  	.int	0x41200000,0x00000000,0x00000000,0x00000000
ADR_409abec:
 	.int	0x459a2800,0x00000000,0x00000000,0x00000000

ADR_409abfc:
  	.byte	0,0,0,0
	.byte	3,3,2,2
	.byte	3,2,2,3
	.byte	2,3,3,2


	

	
	
	

// bindec:
	.globl	bindec
bindec:
	moveml	d2-d7/a2,a7@-
	fmovemx fp0-fp2,a7@-

// A1. Set RM and size ext. Set SIGMA = sign input;
//     Clear The k-factor is saved for use in d7.  BINDEC_FLG for
//     separating  normalized/denormalized input.  If the input
//     is a denormalized number, set the BINDEC_FLG memory word
//     to signal denorm.  If the input is unnormalized, normalize
//     the input and test for denormalized result.  
//
	fmovel	#rm_mode,fpcr	//set rm and ext
	movel	a0@,a6@(l_scr2)	//save exponent for sign check
	movel	d0,d7		//move k-factor to d7
	clrb	a6@(bindec_flg)	//clr norm/denorm flag
	movew	a6@(stag),d0	//get stag
	andiw	#0xe000,d0	//isolate stag bits
	beq	ADR_409ac6a		//if zero, input is norm
//
// Normalize the denorm
//
// un_de_norm:
	movew	a0@,d0
	andiw	#0x7fff,d0	//strip sign of normalized exp
	movel	a0@(4),d1
	movel	a0@(8),d2
// norm_loop:
ADR_409ac42:
	subw	#1,d0
	lsll	#1,d2
	roxll	#1,d1
	tstl	d1
	bge	ADR_409ac42
//
// Test if the normalized input is denormalized
//
	tstw	d0
	bgt	ADR_409ac5c		//if greater than zero, it is a norm
	st	a6@(bindec_flg)	//set flag for denorm
// pos_exp:
ADR_409ac5c:
	andiw	#0x7fff,d0	//strip sign of normalized exp
	movew	d0,a0@
	movel	d1,a0@(4)
	movel	d2,a0@(8)

// A2. Set X = abs(input).
//
// a2_str:
ADR_409ac6a:
	movel	a0@,a6@(fp_scr2) // move input to work space
	movel	a0@(4),a6@(fp_scr2+4) // move input to work space
	movel	a0@(8),a6@(fp_scr2+8) // move input to work space
	andil	#0x7fffffff,a6@(fp_scr2) //create abs(x)

// A3. Compute ILOG.
//     ILOG is the log base 10 of the input value.  It is approx-
//     imated by adding e + 0.f when the original value is viewed
//     as 2^^e * 1.f in extended precision.  This value is stored
//     in d6.
//
// Register usage:
//	Input/Output
//	d0: k-factor/exponent
//	d2: x/x
//	d3: x/x
//	d4: x/x
//	d5: x/x
//	d6: x/ILOG
//	d7: k-factor/Unchanged
//	a0: ptr for original operand/final result
//	a1: x/x
//	a2: x/x
//	fp0: x/float(ILOG)
//	fp1: x/x
//	fp2: x/x
//	F_SCR1:x/x
//	F_SCR2:Abs(X)/Abs(X) with $3fff exponent
//	L_SCR1:x/x
//	L_SCR2:first word of X packed/Unchanged

	tstb	a6@(bindec_flg)	//check for denorm
	beq	ADR_409ac98		//if clr, continue with norm
	movel	#-4933,d6	//force ilog = -4933
	bra	ADR_409acdc
// a3_cont:
ADR_409ac98:
	movew	a6@(fp_scr2),d0	//move exp to d0
	movew	#0x3fff,a6@(fp_scr2) //replace exponent with 0x3fff
	fmovex	a6@(fp_scr2),fp0	//now fp0 has 1f
	subw	#0x3fff,d0	//strip off bias
	faddw	d0,fp0		//add in exp
	fsubs	ADR_409abbc,fp0	//subtract off 10
	fbge	ADR_409acd0		//if pos, branch 
	fmulx	ADR_409abac,fp0	//if neg, mul by log2up1
	fmovel	fp0,d6		//put ilog in d6 as a lword
	bra	ADR_409acdc		//go move out ilog
// pos_res:
ADR_409acd0:
	fmulx	ADR_409ab9c,fp0	//if pos, mul by log2
	fmovel	fp0,d6		//put ilog in d6 as a lword


// A4. Clr INEX bit.
//     The operation in A3 above may have set INEX2.  

// a4_str:	
ADR_409acdc:
	fmovel	#0,fpsr		//zero all of fpsr - nothing needed


// A5. Set ICTR = 0;
//     ICTR is a flag used in A13.  It must be set before the 
//     loop entry A6. The lower word of d5 is used for ICTR.

	clrw	d5		//clear ictr


// A6. Calculate LEN.
//     LEN is the number of digits to be displayed.  The k-factor
//     can dictate either the total number of digits, if it is
//     a positive number, or the number of digits after the
//     original decimal point which are to be included as
//     significant.  See the 68882 manual for examples.
//     If LEN is computed to be greater than 17, set OPERR in
//     USER_FPSR.  LEN is stored in d4.
//
// Register usage:
//	Input/Output
//	d0: exponent/Unchanged
//	d2: x/x/scratch
//	d3: x/x
//	d4: exc picture/LEN
//	d5: ICTR/Unchanged
//	d6: ILOG/Unchanged
//	d7: k-factor/Unchanged
//	a0: ptr for original operand/final result
//	a1: x/x
//	a2: x/x
//	fp0: float(ILOG)/Unchanged
//	fp1: x/x
//	fp2: x/x
//	F_SCR1:x/x
//	F_SCR2:Abs(X) with $3fff exponent/Unchanged
//	L_SCR1:x/x
//	L_SCR2:first word of X packed/Unchanged

// a6_str:	
ADR_409ace6:
	tstl	d7		//branch on sign of k
	ble	ADR_409acf6		//if k <= 0, len = ilog + 1 - k
	movel	d7,d4		//if k > 0, len = k
	bra	ADR_409acfc		//skip to len check
// k_neg:
ADR_409acf6:
	movel	d6,d4		//first load ilog to d4
	subl	d7,d4		//subtract off k
	addql	#1,d4		//add in the 1
// len_ck:
ADR_409acfc:
	tstl	d4		//len check: branch on sign of len
	ble	ADR_409ad28		//if neg, set len = 1
	cmpl	#17,d4		//test if len > 17
	ble	ADR_409ad2a		//if not, forget it
	movel	#17,d4		//set max len = 17
	tstl	d7		//if negative, never set operr
	ble	ADR_409ad2a:l
	orl	#opaop_mask,a6@(user_fpsr) //set operr & aiop in user_fpsr
	bra	ADR_409ad2a		//finished here
// len_ng:
ADR_409ad28:
	moveql	#1,d4		//min len is 1


// A7. Calculate SCALE.
//     SCALE is equal to 10^ISCALE, where ISCALE is the number
//     of decimal places needed to insure LEN integer digits
//     in the output before conversion to bcd. LAMBDA is the sign
//     of ISCALE, used in A9.  Fp1 contains 10^^(abs(ISCALE)) using
//     the rounding mode as given in the following table (see
//     Coonen, p. 7.23 as ref.; however, the SCALE variable is
//     of opposite sign in bindec.sa from Coonen).
//
//	Initial					USE
//	FPCR[6:5]	LAMBDA	SIGN(X)		FPCR[6:5]
//	----------------------------------------------
//	 RN	00	   0	   0		00/0	RN
//	 RN	00	   0	   1		00/0	RN
//	 RN	00	   1	   0		00/0	RN
//	 RN	00	   1	   1		00/0	RN
//	 RZ	01	   0	   0		11/3	RP
//	 RZ	01	   0	   1		11/3	RP
//	 RZ	01	   1	   0		10/2	RM
//	 RZ	01	   1	   1		10/2	RM
//	 RM	10	   0	   0		11/3	RP
//	 RM	10	   0	   1		10/2	RM
//	 RM	10	   1	   0		10/2	RM
//	 RM	10	   1	   1		11/3	RP
//	 RP	11	   0	   0		10/2	RM
//	 RP	11	   0	   1		11/3	RP
//	 RP	11	   1	   0		11/3	RP
//	 RP	11	   1	   1		10/2	RM
//
// Register usage:
//	Input/Output
//	d0: exponent/scratch - final is 0
//	d2: x/0 or 24 for A9
//	d3: x/scratch - offset ptr into PTENRM array
//	d4: LEN/Unchanged
//	d5: 0/ICTR:LAMBDA
//	d6: ILOG/ILOG or k if ((k<=0)&(ILOG<k))
//	d7: k-factor/Unchanged
//	a0: ptr for original operand/final result
//	a1: x/ptr to PTENRM array
//	a2: x/x
//	fp0: float(ILOG)/Unchanged
//	fp1: x/10^ISCALE
//	fp2: x/x
//	F_SCR1:x/x
//	F_SCR2:Abs(X) with $3fff exponent/Unchanged
//	L_SCR1:x/x
//	L_SCR2:first word of X packed/Unchanged

// a7_str:	
ADR_409ad2a:
	tstl	d7		//test sign of k
	bgt	ADR_409ad3c		//if pos and > 0, skip this
	cmpl	d6,d7		//test k - ilog
	blt	ADR_409ad3c		//if ilog >= k, skip this
	movel	d7,d6		//if ((k<0) & (ilog < k)) ilog = k
// k_pos:	
ADR_409ad3c:
	movel	d6,d0		//calc ilog + 1 - len in d0
	addql	#1,d0		//add the 1
	subl	d4,d0		//sub off len
	swap	d5		//use upper word of d5 for lambda
	clrw	d5		//set it zero initially
	clrw	d2		//set up d2 for very small case
	tstl	d0		//test sign of iscale
	bge	ADR_409ad68		//if pos, skip next inst
	addqw	#1,d5		//if neg, set lambda true
	cmpl	#0xffffecd4,d0	//test iscale <= -4908
	bgt	ADR_409ad66		//if false, skip rest
	addil	#24,d0		//add in 24 to iscale
	movel	#24,d2		//put 24 in d2 for a9
// no_inf:	
ADR_409ad66:
	negl	d0		//and take abs of iscale
// iscale:	
ADR_409ad68:
	fmoves	ADR_409abbc,fp1	//init fp1 to 1
	bfextu	a6@(user_fpcr){#26:#2},d1 //get initial rmode bits
	lslw	#1,d1		//put them in bits 2:1
	addw	d5,d1		//add in lambda
	lslw	#1,d1		//put them in bits 3:1
	tstl	a6@(l_scr2)	//test sign of original x
	bge	ADR_409ad88		//if pos, don't set bit 0
	addql	#1,d1		//if neg, set bit 0
// x_pos:
ADR_409ad88:
	lea	ADR_409abfc,a2	//load rbdtbl base
	moveb	a2@(d1),d3	//load d3 with new rmode
	lsll	#4,d3		//put bits in proper position
	fmovel	d3,fpcr		//load bits into fpu
	lsrl	#4,d3		//put bits in proper position
	tstb	d3		//decode new rmode for pten table
	bne	ADR_409adae		//if zero, it is rn
	lea	ptenrn,a1	//load a1 with rn table base
	bra	ADR_409adc8		//exit decode
// not_rn:
ADR_409adae:
	lsrb	#1,d3		//get lsb in carry
	bcc	ADR_409adc2		//if carry clear, it is rm
	lea	ptenrp,a1	//load a1 with rp table base
	bra	ADR_409adc8		//exit decode
// not_rp:
ADR_409adc2:
	lea	ptenrm,a1	//load a1 with rm table base
// rmode:
ADR_409adc8:
	clrl	d3		//clr table index
// e_loop:	
ADR_409adca:
	lsrl	#1,d0		//shift next bit into carry
	bcc	ADR_409add8		//if zero, skip the mul
	fmulx	a1@(d3),fp1	//mul by 10**(d3_bit_no)
// e_next:	
ADR_409add8:
	addl	#12,d3		//inc d3 to next pwrten table entry
	tstl	d0		//test if iscale is zero
	bne	ADR_409adca		//if not, loop


// A8. Clr INEX; Force RZ.
//     The operation in A3 above may have set INEX2.  
//     RZ mode is forced for the scaling operation to insure
//     only one rounding error.  The grs bits are collected in 
//     the INEX flag for use in A10.
//
// Register usage:
//	Input/Output

	fmovel	#0,fpsr		//clr inex 
	fmovel	#rz_mode,fpcr	//set rz rounding mode


// A9. Scale X -> Y.
//     The mantissa is scaled to the desired number of significant
//     digits.  The excess digits are collected in INEX2. If mul,
//     Check d2 for excess 10 exponential value.  If not zero, 
//     the iscale value would have caused the pwrten calculation
//     to overflow.  Only a negative iscale can cause this, so
//     multiply by 10^(d2), which is now only allowed to be 24,
//     with a multiply by 10^8 and 10^16, which is exact since
//     10^24 is exact.  If the input was denormalized, we must
//     create a busy stack frame with the mul command and the
//     two operands, and allow the fpu to complete the multiply.
//
// Register usage:
//	Input/Output
//	d0: FPCR with RZ mode/Unchanged
//	d2: 0 or 24/unchanged
//	d3: x/x
//	d4: LEN/Unchanged
//	d5: ICTR:LAMBDA
//	d6: ILOG/Unchanged
//	d7: k-factor/Unchanged
//	a0: ptr for original operand/final result
//	a1: ptr to PTENRM array/Unchanged
//	a2: x/x
//	fp0: float(ILOG)/X adjusted for SCALE (Y)
//	fp1: 10^ISCALE/Unchanged
//	fp2: x/x
//	F_SCR1:x/x
//	F_SCR2:Abs(X) with $3fff exponent/Unchanged
//	L_SCR1:x/x
//	L_SCR2:first word of X packed/Unchanged

// a9_str:	
	fmovex	a0@,fp0	//load x from memory
	fabsx	fp0		//use abs(x)
	tstw	d5		//lambda is in lower word of d5
	bne	sc_mul		//if neg (lambda = 1), scale by mul
	fdivx	fp1,fp0		//calculate x / scale -> y to fp0
	bra	ADR_409ae78		//branch to a10
// sc_mul:
	.globl	sc_mul
sc_mul:
	tstb	a6@(bindec_flg)	//check for denorm
	beq	ADR_409ae60		//if norm, continue with mul
	fmovemx fp1-fp1,a7@-	//load etemp with 10^iscale
	movel	a0@(8),a7@-	//load fptemp with input arg
	movel	a0@(4),a7@-
	movel	a0@,a7@-
	moveq	#18,d3
// a9_loop:
ADR_409ae2a:
	clrl	a7@-		//clear lword on stack
	dbf	d3,ADR_409ae2a	
	moveb	a6@(-69:w),sp@
	moveb	#0x60:b,sp@(1:w)
	moveb	#0x10,a7@(0x44)	//set fcefpte[15] bit
	movew	#0x0023,a7@(0x40)	//load cmdreg1b with mul command
	moveb	#0xfe,a7@(0x8)	//load all 1s to cu savepc
	frestore a7@+		//restore frame to fpu for completion
	fmulx	a1@(36),fp0	//multiply fp0 by 10^8
	fmulx	a1@(48),fp0	//multiply fp0 by 10^16
	bra	ADR_409ae78
// a9_norm:
ADR_409ae60:
	tstw	d2		//test for small exp case
	beq	ADR_409ae74		//if zero, continue as normal
	fmulx	a1@(36),fp0	//multiply fp0 by 10^8
	fmulx	a1@(48),fp0	//multiply fp0 by 10^16
// a9_con:
ADR_409ae74:
	fmulx	fp1,fp0		//calculate x * scale -> y to fp0


// A10. Or in INEX.
//      If INEX is set, round error occured.  This is compensated
//      for by 'or-ing' in the INEX2 flag to the lsb of Y.
//
// Register usage:
//	Input/Output
//	d0: FPCR with RZ mode/FPSR with INEX2 isolated
//	d2: x/x
//	d3: x/x
//	d4: LEN/Unchanged
//	d5: ICTR:LAMBDA
//	d6: ILOG/Unchanged
//	d7: k-factor/Unchanged
//	a0: ptr for original operand/final result
//	a1: ptr to PTENxx array/Unchanged
//	a2: x/ptr to FP_SCR2(a6)
//	fp0: Y/Y with lsb adjusted
//	fp1: 10^ISCALE/Unchanged
//	fp2: x/x

// a10_st:	
ADR_409ae78:
	fmovel	fpsr,d0		//get fpsr
	fmovex	fp0,a6@(fp_scr2)	//move y to memory
	lea	a6@(fp_scr2),a2	//load a2 with ptr to fp_scr2
	btst	#9,d0		//check if inex2 set
	beq	ADR_409ae9e		//if clear, skip rest
	oril	#1,a2@(8)	//or in 1 to lsb of mantissa
	fmovex	a6@(fp_scr2),fp0	//write adjusted y back to fpu


// A11. Restore original FPCR; set size ext.
//      Perform FINT operation in the user's rounding mode.  Keep
//      the size to extended.  The sintdo entry point in the sint
//      routine expects the FPCR value to be in USER_FPCR for
//      mode and precision.  The original FPCR is saved in L_SCR1.

// a11_st:	
ADR_409ae9e:
	movel	a6@(user_fpcr),a6@(l_scr1) //save it for later
	andil	#0x00000030,a6@(user_fpcr) //set size to ext, 
//					;block exceptions


// A12. Calculate YINT = FINT(Y) according to user's rounding mode.
//      The FPSP routine sintd0 is used.  The output is in fp0.
//
// Register usage:
//	Input/Output
//	d0: FPSR with AINEX cleared/FPCR with size set to ext
//	d2: x/x/scratch
//	d3: x/x
//	d4: LEN/Unchanged
//	d5: ICTR:LAMBDA/Unchanged
//	d6: ILOG/Unchanged
//	d7: k-factor/Unchanged
//	a0: ptr for original operand/src ptr for sintdo
//	a1: ptr to PTENxx array/Unchanged
//	a2: ptr to FP_SCR2(a6)/Unchanged
//	a6: temp pointer to FP_SCR2(a6) - orig value saved and restored
//	fp0: Y/YINT
//	fp1: 10^ISCALE/Unchanged
//	fp2: x/x
//	F_SCR1:x/x
//	F_SCR2:Y adjusted for inex/Y with original exponent
//	L_SCR1:x/original USER_FPCR
//	L_SCR2:first word of X packed/Unchanged

// a12_st:
	moveml	d0-d1/a0-a1,a7@-	//save regs used by sintd0	
	movel	a6@(l_scr1),a7@-
	movel	a6@(l_scr2),a7@-
	lea	a6@(fp_scr2),a0		//a0 is ptr to f_scr2(a6)
	fmovex	fp0,a0@		//move y to memory at fp_scr2(a6)
	tstl	a6@(l_scr2)		//test sign of original operand
	bge	ADR_409aed0:l
	orl	#0x80000000,a0@		//if neg, use -y
ADR_409aed0:
	movel	a6@(-124:w),sp@-
// do_fint:
	bsr	sintdo			//sint routine returns int in fp0
	moveb	sp@,a6@(-124:w)
	addql	#0x4,sp
	movel	a7@+,a6@(l_scr2)
	movel	a7@+,a6@(l_scr1)
	moveml	a7@+,d0-d1/a0-a1	//restore regs used by sint	
	movel	a6@(l_scr2),a6@(fp_scr2)	//restore original exponent
	movel	a6@(l_scr1),a6@(user_fpcr) //restore user's fpcr


// A13. Check for LEN digits.
//      If the int operation results in more than LEN digits,
//      or less than LEN -1 digits, adjust ILOG and repeat from
//      A6.  This test occurs only on the first pass.  If the
//      result is exactly 10^LEN, decrement ILOG and divide
//      the mantissa by 10.  The calculation of 10^LEN cannot
//      be inexact, since all powers of ten upto 10^27 are exact
//      in extended precision, so the use of a previous power-of-ten
//      table will introduce no error.
//
//
// Register usage:
//	Input/Output
//	d0: FPCR with size set to ext/scratch final = 0
//	d2: x/x
//	d3: x/scratch final = x
//	d4: LEN/LEN adjusted
//	d5: ICTR:LAMBDA/LAMBDA:ICTR
//	d6: ILOG/ILOG adjusted
//	d7: k-factor/Unchanged
//	a0: pointer into memory for packed bcd string formation
//	a1: ptr to PTENxx array/Unchanged
//	a2: ptr to FP_SCR2(a6)/Unchanged
//	fp0: int portion of Y/abs(YINT) adjusted
//	fp1: 10^ISCALE/Unchanged
//	fp2: x/10^LEN
//	F_SCR1:x/x
//	F_SCR2:Y with original exponent/Unchanged
//	L_SCR1:original USER_FPCR/Unchanged
//	L_SCR2:first word of X packed/Unchanged

// a13_st:	
	swap	d5		//put ictr in lower word of d5
	tstw	d5		//check if ictr = 0
	bne	ADR_409afa6		//if non-zero, go to second test
//
// Compute 10^(LEN-1)
//
	fmoves	ADR_409abbc,fp2	//init fp2 to 10
	movel	d4,d0		//put len in d0
	subql	#1,d0		//d0 = len -1
	clrl	d3		//clr table index
// l_loop:	
ADR_409af10:
	lsrl	#1,d0		//shift next bit into carry
	bcc	ADR_409af1e		//if zero, skip the mul
	fmulx	a1@(d3),fp2	//mul by 10**(d3_bit_no)
// l_next:
ADR_409af1e:
	addl	#12,d3		//inc d3 to next pwrten table entry
	tstl	d0		//test if len is zero
	bne	ADR_409af10		//if not, loop
//
// 10^LEN-1 is computed for this test and A14.  If the input was
// denormalized, check only the case in which YINT > 10^LEN.
//
	tstb	a6@(bindec_flg)	//check if input was norm
	beq	ADR_409af40		//if norm, continue with checking
	fabsx	fp0		//take abs of yint
	bra	ADR_409af6a
//
// Compare abs(YINT) to 10^(LEN-1) and 10^LEN
//
// a13_con:
ADR_409af40:
	fabsx	fp0		//take abs of yint
	fcmpx	fp2,fp0		//compare abs(yint) with 10^(len-1)
	fbge	ADR_409af6a		//if greater, do next test
	subql	#1,d6		//subtract 1 from ilog
	movew	#1,d5		//set ictr
	fmovel	#rm_mode,fpcr	//set rmode to rm
	fmuls	ADR_409abdc,fp2	//compute 10^len 
	bra	ADR_409ace6		//return to a6 and recompute yint
// test_2:
ADR_409af6a:
	fmuls	ADR_409abdc,fp2	//compute 10^len
	fcmpx	fp2,fp0		//compare abs(yint) with 10^len
	fblt	ADR_409aff0		//if less, all is ok, go to a14
	fbgt	ADR_409af92		//if greater, fix and redo
	fdivs	ADR_409abdc,fp0	//if equal, divide by 10
	addql	#1,d6		// and inc ilog
	bra	ADR_409aff0		// and continue elsewhere
// fix_ex:
ADR_409af92:
	addql	#1,d6		//increment ilog by 1
	movew	#1,d5		//set ictr
	fmovel	#rm_mode,fpcr	//set rmode to rm
	bra	ADR_409ace6		//return to a6 and recompute yint
//
// Since ICTR <> 0, we have already been through one adjustment, 
// and shouldn't have another; this is to check if abs(YINT) = 10^LEN
// 10^LEN is again computed using whatever table is in a1 since the
// value calculated cannot be inexact.
//
// not_zr:
ADR_409afa6:
	fmoves	ADR_409abbc,fp2	//init fp2 to 10
	movel	d4,d0		//put len in d0
	clrl	d3		//clr table index
// z_loop:
ADR_409afb2:
	lsrl	#1,d0		//shift next bit into carry
	bcc	ADR_409afc0		//if zero, skip the mul
	fmulx	a1@(d3),fp2	//mul by 10**(d3_bit_no)
// z_next:
ADR_409afc0:
	addl	#12,d3		//inc d3 to next pwrten table entry
	tstl	d0		//test if len is zero
	bne	ADR_409afb2		//if not, loop
	fabsx	fp0		//get abs(yint)
	fcmpx	fp2,fp0		//check if abs(yint) = 10^len
	fbne	ADR_409aff0		//if not, skip this
	fdivs	ADR_409abdc,fp0	//divide abs(yint) by 10
	addql	#1,d6		//and inc ilog by 1
	addql	#1,d4		// and inc len
	fmuls	ADR_409abdc,fp2	// if len++, the get 10^^len


// A14. Convert the mantissa to bcd.
//      The binstr routine is used to convert the LEN digit 
//      mantissa to bcd in memory.  The input to binstr is
//      to be a fraction; i.e. (mantissa)/10^LEN and adjusted
//      such that the decimal point is to the left of bit 63.
//      The bcd digits are stored in the correct position in 
//      the final string area in memory.
//
//
// Register usage:
//	Input/Output
//	d0: x/LEN call to binstr - final is 0
//	d1: x/0
//	d2: x/ms 32-bits of mant of abs(YINT)
//	d3: x/ls 32-bits of mant of abs(YINT)
//	d4: LEN/Unchanged
//	d5: ICTR:LAMBDA/LAMBDA:ICTR
//	d6: ILOG
//	d7: k-factor/Unchanged
//	a0: pointer into memory for packed bcd string formation
//	    /ptr to first mantissa byte in result string
//	a1: ptr to PTENxx array/Unchanged
//	a2: ptr to FP_SCR2(a6)/Unchanged
//	fp0: int portion of Y/abs(YINT) adjusted
//	fp1: 10^ISCALE/Unchanged
//	fp2: 10^LEN/Unchanged
//	F_SCR1:x/Work area for final result
//	F_SCR2:Y with original exponent/Unchanged
//	L_SCR1:original USER_FPCR/Unchanged
//	L_SCR2:first word of X packed/Unchanged

// a14_st:	
ADR_409aff0:
	fmovel	#rz_mode,fpcr	//force rz for conversion
	fdivx	fp2,fp0		//divide abs(yint) by 10^len
	lea	a6@(fp_scr1),a0
	fmovex	fp0,a0@	//move abs(yint)/10^len to memory
	movel	a0@(4),d2	//move 2nd word of fp_res to d2
	movel	a0@(8),d3	//move 3rd word of fp_res to d3
	clrl	a0@(4)		//zero word 2 of fp_res
	clrl	a0@(8)		//zero word 3 of fp_res
	movel	a0@,d0		//move exponent to d0
	swap	d0		//put exponent in lower word
	beq	ADR_409b036:l
	subil	#0x3ffd,d0	//sub bias less 2 to make fract
	tstl	d0		//check if > 1
	bgt	ADR_409b036		//if so, don't shift
	negl	d0		//make exp positive
// m_loop:
ADR_409b02e:
	lsrl	#1,d2		//shift d2:d3 right, add 0s 
	roxrl	#1,d3		//the number of places
	dbf	d0,ADR_409b02e	//given in d0
// no_sft:
ADR_409b036:
	tstl	d2		//check for mantissa of zero
	bne	ADR_409b046		//if not, go on
	tstl	d3		//continue zero check
	beq	ADR_409b056		//if zero, go directly to binstr
// no_zr:
ADR_409b046:
	clrl	d1		//put zero in d1 for addx
	addil	#0x00000080,d3	//inc at bit 7
	addxl	d1,d2		//continue inc
	andil	#0xffffff80,d3	//strip off lsb not used by 882
// zer_m:
ADR_409b056:
	movel	d4,d0		//put len in d0 for binstr call
	addql	#3,a0		//a0 points to m16 byte in result
	bsr	binstr		//call binstr to convert mant


// A15. Convert the exponent to bcd.
//      As in A14 above, the exp is converted to bcd and the
//      digits are stored in the final string.
//
//      Digits are stored in L_SCR1(a6) on return from BINDEC as:
//
//  	 32               16 15                0
//	-----------------------------------------
//  	|  0 | e3 | e2 | e1 | e4 |  X |  X |  X |
//	-----------------------------------------
//
// And are moved into their proper places in FP_SCR1.  If digit e4
// is non-zero, OPERR is signaled.  In all cases, all 4 digits are
// written as specified in the 881/882 manual for packed decimal.
//
// Register usage:
//	Input/Output
//	d0: x/LEN call to binstr - final is 0
//	d1: x/scratch (0);shift count for final exponent packing
//	d2: x/ms 32-bits of exp fraction/scratch
//	d3: x/ls 32-bits of exp fraction
//	d4: LEN/Unchanged
//	d5: ICTR:LAMBDA/LAMBDA:ICTR
//	d6: ILOG
//	d7: k-factor/Unchanged
//	a0: ptr to result string/ptr to L_SCR1(a6)
//	a1: ptr to PTENxx array/Unchanged
//	a2: ptr to FP_SCR2(a6)/Unchanged
//	fp0: abs(YINT) adjusted/float(ILOG)
//	fp1: 10^ISCALE/Unchanged
//	fp2: 10^LEN/Unchanged
//	F_SCR1:Work area for final result/BCD result
//	F_SCR2:Y with original exponent/ILOG/10^4
//	L_SCR1:original USER_FPCR/Exponent digits on return from binstr
//	L_SCR2:first word of X packed/Unchanged

// a15_st:	
	tstb	a6@(bindec_flg)	//check for denorm
	beq	ADR_409b0a6
	ftstx	fp0		//test for zero
	fbeq	ADR_409b082	//if zero, use k-factor or 4933
	fmovel	d6,fp0		//float ilog
	fabsx	fp0		//get abs of ilog
	bra	ADR_409b0c6
// den_zero:
ADR_409b082:
	tstl	d7		//check sign of the k-factor
	blt	ADR_409b098	//if negative, use ilog
	fmoves	ADR_409abec,fp0	//force exponent to 4933
	bra	ADR_409b0c6		//do it
// use_ilog:
ADR_409b098:
	fmovel	d6,fp0		//float ilog
	fabsx	fp0		//get abs of ilog
	bra	ADR_409b0c6
// not_denorm:
ADR_409b0a6:
	ftstx	fp0		//test for zero
	fbne	ADR_409b0be	//if zero, force exponent
	fmoves	ADR_409abbc,fp0	//force exponent to 1
	bra	ADR_409b0c6		//do it
// not_zero:	
ADR_409b0be:
	fmovel	d6,fp0		//float ilog
	fabsx	fp0		//get abs of ilog
// convrt:
ADR_409b0c6:
	fdivx	a1@(24),fp0	//compute ilog/10^4
	fmovex	fp0,a6@(fp_scr2)	//store fp0 in memory
	movel	a2@(4),d2	//move word 2 to d2
	movel	a2@(8),d3	//move word 3 to d3
	movew	a2@,d0
	beq	ADR_409b0f0:l
	subiw	#0x3ffd,d0	//subtract off bias
	negw	d0		//make exp positive
// x_loop:
ADR_409b0e8:
	lsrl	#1,d2		//shift d2:d3 right 
	roxrl	#1,d3		//the number of places
	dbf	d0,ADR_409b0e8	//given in d0
ADR_409b0f0:
	clrl	d1		//put zero in d1 for addx
	addil	#0x00000080,d3	//inc at bit 6
	addxl	d1,d2		//continue inc
	andil	#0xffffff80,d3	//strip off lsb not used by 882
	movel	#4,d0		//put 4 in d0 for binstr call
	lea	a6@(l_scr1),a0	//a0 is ptr to l_scr1 for exp digits
	bsr	binstr		//call binstr to convert exp
	movel	a6@(l_scr1),d0	//load l_scr1 lword to d0 
	movel	#12,d1		//use d1 for shift count
	lsrl	d1,d0		//shift d0 right by 12
	bfins	d0,a6@(fp_scr1){#4:#12} //put e3:e2:e1 in fp_scr1
	lsrl	d1,d0		//shift d0 right by 12
	bfins	d0,a6@(fp_scr1){#16:#4} //put e4 in fp_scr1 
	tstb	d0		//check if e4 is zero
	beq	ADR_409b132		//if zero, skip rest
	orl	#opaop_mask,a6@(user_fpsr) //set operr & aiop in user_fpsr


// A16. Write sign bits to final string.
//	   Sigma is bit 31 of initial value; RHO is bit 31 of d6 (ILOG).
//
// Register usage:
//	Input/Output
//	d0: x/scratch - final is x
//	d2: x/x
//	d3: x/x
//	d4: LEN/Unchanged
//	d5: ICTR:LAMBDA/LAMBDA:ICTR
//	d6: ILOG/ILOG adjusted
//	d7: k-factor/Unchanged
//	a0: ptr to L_SCR1(a6)/Unchanged
//	a1: ptr to PTENxx array/Unchanged
//	a2: ptr to FP_SCR2(a6)/Unchanged
//	fp0: float(ILOG)/Unchanged
//	fp1: 10^ISCALE/Unchanged
//	fp2: 10^LEN/Unchanged
//	F_SCR1:BCD result with correct signs
//	F_SCR2:ILOG/10^4
//	L_SCR1:Exponent digits on return from binstr
//	L_SCR2:first word of X packed/Unchanged

// a16_st:
ADR_409b132:
	clrl	d0		//clr d0 for collection of signs
	andib	#0x0f,a6@(fp_scr1) //clear first nibble of fp_scr1 
	tstl	a6@(l_scr2)	//check sign of original mantissa
	bge	ADR_409b146		//if pos, don't set sm
	moveql	#2,d0		//move 2 in to d0 for sm
// mant_p:
ADR_409b146:
	tstl	d6		//check sign of ilog
	bge	ADR_409b150		//if pos, don't set se
	addql	#1,d0		//set bit 0 in d0 for se 
// wr_sgn:
ADR_409b150:
	bfins	d0,a6@(fp_scr1){#0:#2} //insert sm and se into fp_scr1

// Clean up and restore all registers used.

	fmovel	#0,fpsr		//clear possible inex2/ainex bits
	fmovemx a7@+,fp0-fp2
	moveml	a7@+,d2-d7/a2
	rts
//
//	binstr.sa 1.3 10/1/90
//
//	Description: Converts a 64-bit binary integer to bcd.
//
//	Input: 64-bit binary integer in d2:d3, desired length (LEN) in
//          d0, and a  pointer to start in memory for bcd characters
//          in d0. (This pointer must point to byte 4 of the first
//          lword of the packed decimal memory string.)
//
//	Output:	LEN bcd digits representing the 64-bit integer.
//
//	Algorithm:
//		The 64-bit binary is assumed to have a decimal point before
//		bit 63.  The fraction is multiplied by 10 using a mul by 2
//		shift and a mul by 8 shift.  The bits shifted out of the
//		msb form a decimal digit.  This process is iterated until
//		LEN digits are formed.
//
//	A1. Init d7 to 1.  D7 is the byte digit counter, and if 1, the
//		digit formed will be assumed the least significant.  This is
//		to force the first byte formed to have a 0 in the upper 4 bits.
//
//	A2. Beginning of the loop:
//		Copy the fraction in d2:d3 to d4:d5.
//
//	A3. Multiply the fraction in d2:d3 by 8 using bit-field
//		extracts and shifts.  The three msbs from d2 will go into
//		d1.
//
//	A4. Multiply the fraction in d4:d5 by 2 using shifts.  The msb
//		will be collected by the carry.
//
//	A5. Add using the carry the 64-bit quantities in d2:d3 and d4:d5
//		into d2:d3.  D1 will contain the bcd digit formed.
//
//	A6. Test d7.  If zero, the digit formed is the ms digit.  If non-
//		zero, it is the ls digit.  Put the digit in its place in the
//		upper word of d0.  If it is the ls digit, write the word
//		from d0 to memory.
//
//	A7. Decrement d6 (LEN counter) and repeat the loop until zero.
//
//	Implementation Notes:
//
//	The registers are used as follows:
//
//		d0: LEN counter
//		d1: temp used to form the digit
//		d2: upper 32-bits of fraction for mul by 8
//		d3: lower 32-bits of fraction for mul by 8
//		d4: upper 32-bits of fraction for mul by 2
//		d5: lower 32-bits of fraction for mul by 2
//		d6: temp for bit-field extracts
//		d7: byte digit formation word;digit count {0,1}
//		a0: pointer into memory for packed bcd string formation
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



	

// binstr:
	.globl	binstr
binstr:
	moveml	d0-d7,a7@-
//
// A1: Init d7
//
	moveql	#1,d7			//init d7 for second digit
	subql	#1,d0			//for dbf d0 would have len+1 passes
//
// A2. Copy d2:d3 to d4:d5.  Start loop.
//
// loop:
ADR_409b170:
	movel	d2,d4			//copy the fraction before muls
	movel	d3,d5			//to d4:d5
//
// A3. Multiply d2:d3 by 8; extract msbs into d1.
//
	bfextu	d2{#0:#3},d1		//copy 3 msbs of d2 into d1
	asll	#3,d2			//shift d2 left by 3 places
	bfextu	d3{#0:#3},d6		//copy 3 msbs of d3 into d6
	asll	#3,d3			//shift d3 left by 3 places
	orl	d6,d2			//or in msbs from d3 into d2
//
// A4. Multiply d4:d5 by 2; add carry out to d1.
//
	asll	#1,d5			//mul d5 by 2
	roxll	#1,d4			//mul d4 by 2
	swap	d6			//put 0 in d6 lower word
	addxw	d6,d1			//add in extend from mul by 2
//
// A5. Add mul by 8 to mul by 2.  D1 contains the digit formed.
//
	addl	d5,d3			//add lower 32 bits
	nop				//errata //fix #13 (rev 12 6/6/90)
	addxl	d4,d2			//add with extend upper 32 bits
	nop				//errata //fix #13 (rev 12 6/6/90)
	addxw	d6,d1			//add in extend from add to d1
	swap	d6			//with d6 = 0// put 0 in upper word
//
// A6. Test d7 and branch.
//
	tstw	d7			//if zero, store digit & to loop
	beq	ADR_409b1b4			//if non-zero, form byte & write
// sec_d:
	swap	d7			//bring first digit to word d7b
	aslw	#4,d7			//first digit in upper 4 bits d7b
	addw	d1,d7			//add in ls digit to d7b
	moveb	d7,a0@+		//store d7b byte in memory
	swap	d7			//put len counter in word d7a
	clrw	d7			//set d7a to signal no digits done
	dbf	d0,ADR_409b170			//do loop some more!
	bra	ADR_409b1c6		//finished, so exit
// first_d:
ADR_409b1b4:
	swap	d7			//put digit word in d7b
	movew	d1,d7			//put new digit in d7b
	swap	d7			//put len counter in word d7a
	addqw	#1,d7			//set d7a to signal first digit done
	dbf	d0,ADR_409b170			//do loop some more!
	swap	d7			//put last digit in string
	lslw	#4,d7			//move it to upper 4 bits
	moveb	d7,a0@+		//store it in memory string
//
// Clean up and return with result in fp0.
//
// end_bstr:
ADR_409b1c6:
	moveml	a7@+,d0-d7
	rts
	.globl	b1238_fix
b1238_fix:
	cmpb	#0x40,sp@(4:w)
	bne	ADR_409b4ec:l
	moveb	a6@(-284:w),d0
	andb	#0xfe,d0
	beq	ADR_409b4ec:l
	movew	a6@(-228:w),d0
	andw	#0xe000,d0
	bne	ADR_409b370:l
	bfextu	a6@(-228:w){#3,#3},d0
	bfextu	a6@(-240:w){#6,#3},d1
	cmpb	d0,d1
	beq	ADR_409b238:l
	bfextu	a6@(-228:w){#6,#3},d0
	cmpb	d0,d1
	beq	ADR_409b238:l
	bfextu	a6@(-244:w){#6,#3},d1
	cmpb	d0,d1
	beq	ADR_409b27a:l
	bfextu	a6@(-228:w){#3,#3},d0
	cmpb	d0,d1
	beq	ADR_409b27a:l
	bne	ADR_409b4ec:l
ADR_409b238:
	bfextu	a6@(-228:w){#3,#3},d0
	moveq	#7,d1
	subl	d0,d1
	clrl	d0
	bset	d1,d0
	fmovemx	d0,a6@(-204:w)
	moveb	#0x12:b,d0
	bfins	d0,a6@(-228:w){#0,#6}
	btst	#6,a6@(-204:w)
	beq	ADR_409b26e:l
	bclr	#4,a6@(-232:w)
	bra	ADR_409b4ec:l
ADR_409b26e:
	bset	#4,a6@(-232:w)
	bra	ADR_409b4ec:l
ADR_409b27a:
	movel	a6@(-232:w),a6@(-84:w)
	movel	a6@(-228:w),a6@(-80:w)
	movel	a6@(-224:w),a6@(-68:w)
	andl	#0xe0000000,a6@(-68:w)
	moveb	#0x0:b,a6@(-284:w)
	movel	sp@+,d1
	frestore	sp@+
	fsave	sp@-
	cmpw	#0x4060,sp@
	beq	ADR_409b36a:l
	bfextu	a6@(-244:w){#6,#3},d0
	cmpl	#0x3,d0
	bgt	ADR_409b2fe:l
	beq	ADR_409b2f8:l
	cmpl	#0x1,d0
	blt	ADR_409b2ec:l
	beq	ADR_409b2e0:l
	.word	0xf22e
	.word	0xf020
	.word	0xff68
	bra	ADR_409b2fe:l
ADR_409b2e0:
	.word	0xf22e
	.word	0xf040
	.word	0xff5c
	bra	ADR_409b2fe:l
ADR_409b2ec:
	.word	0xf22e
	.word	0xf080
	.word	0xff50
	bra	ADR_409b2fe:l
ADR_409b2f8:
	.word	0xf22e
	.word	0xf010
	.word	0xff74
ADR_409b2fe:
	moveq	#22,d0
	clrl	sp@
ADR_409b302:
	clrl	sp@-
	dbf	d0,ADR_409b302
	movel	#0x40600000:l,sp@-
	movel	a6@(-84:w),a6@(-232:w)
	movel	a6@(-80:w),a6@(-228:w)
	movel	a6@(-68:w),a6@(-224:w)
	moveb	#0x6:b,a6@(-284:w)
	movel	d1,sp@-
	bfextu	a6@(-228:w){#3,#3},d0
	moveq	#7,d1
	subl	d0,d1
	clrl	d0
	bset	d1,d0
	fmovemx	d0,a6@(-204:w)
	moveb	#0x12:b,d0
	bfins	d0,a6@(-228:w){#0,#6}
	btst	#6,a6@(-204:w)
	beq	ADR_409b35e:l
	bclr	#4,a6@(-232:w)
	bra	ADR_409b4ec:l
ADR_409b35e:
	bset	#4,a6@(-232:w)
	bra	ADR_409b4ec:l
ADR_409b36a:
	.word	0x4ef9
	.word	0x040a
	.word	0x0cd2
ADR_409b370:
	movew	a6@(-228:w),d0
	andw	#0xfc00,d0
	cmpw	#0x4400,d0
	bne	ADR_409b4ec:l
	bfextu	a6@(-228:w){#6,#3},d0
	bfextu	a6@(-240:w){#6,#3},d1
	cmpb	d0,d1
	beq	ADR_409b47c:l
	bfextu	a6@(-244:w){#6,#3},d1
	cmpb	d0,d1
	bne	ADR_409b4ec:l
	movel	a6@(-232:w),a6@(-84:w)
	movel	a6@(-228:w),a6@(-80:w)
	movel	a6@(-224:w),a6@(-68:w)
	andl	#0xe0000000,a6@(-68:w)
	moveb	#0x0:b,a6@(-284:w)
	movel	a6@(-204:w),a6@(-100:w)
	movel	a6@(-200:w),a6@(-96:w)
	movel	a6@(-196:w),a6@(-92:w)
	movel	sp@+,d1
	frestore	sp@+
	fsave	sp@-
	cmpw	#0x4060,sp@
	beq	ADR_409b4e6:l
	bfextu	a6@(-244:w){#6,#3},d0
	cmpl	#0x3,d0
	bgt	ADR_409b43a:l
	beq	ADR_409b434:l
	cmpl	#0x1,d0
	blt	ADR_409b428:l
	beq	ADR_409b41c:l
	.word	0xf22e
	.word	0xf020
	.word	0xff68
	bra	ADR_409b43a:l
ADR_409b41c:
	.word	0xf22e
	.word	0xf040
	.word	0xff5c
	bra	ADR_409b43a:l
ADR_409b428:
	.word	0xf22e
	.word	0xf080
	.word	0xff50
	bra	ADR_409b43a:l
ADR_409b434:
	.word	0xf22e
	.word	0xf010
	.word	0xff74
ADR_409b43a:
	moveq	#22,d0
	clrl	sp@
ADR_409b43e:
	clrl	sp@-
	dbf	d0,ADR_409b43e
	movel	#0x40600000:l,sp@-
	movel	a6@(-84:w),a6@(-232:w)
	movel	a6@(-80:w),a6@(-228:w)
	movel	a6@(-68:w),a6@(-224:w)
	moveb	#0x6:b,a6@(-284:w)
	movel	a6@(-100:w),a6@(-204:w)
	movel	a6@(-96:w),a6@(-200:w)
	movel	a6@(-92:w),a6@(-196:w)
	movel	d1,sp@-
	bra	ADR_409b47c:l
ADR_409b47c:
	moveb	#0x15:b,d0
	bfins	d0,a6@(-228:w){#0,#6}
	cmpw	#0x407f,a6@(-204:w)
	bne	ADR_409b49e:l
	movew	#0x43ff:w,a6@(-204:w)
	bra	ADR_409b4ec:l
ADR_409b49e:
	cmpw	#0xc07f,a6@(-204:w)
	bne	ADR_409b4b6:l
	movew	#0xc3ff:w,a6@(-204:w)
	bra	ADR_409b4ec:l
ADR_409b4b6:
	cmpw	#0x3f80,a6@(-204:w)
	bne	ADR_409b4ce:l
	movew	#0x3c00:w,a6@(-204:w)
	bra	ADR_409b4ec:l
ADR_409b4ce:
	cmpw	#0xbf80,a6@(-204:w)
	bne	ADR_409b4ec:l
	movew	#0xbc00:w,a6@(-204:w)
	bra	ADR_409b4ec:l
ADR_409b4e6:
	.word	0x4ef9
	.word	0x040a
	.word	0x0cd2
ADR_409b4ec:
	rts
//
//	decbin.sa 1.7 10/2/90
//
//	Description: Converts normalized packed bcd value pointed to by
//	register A6 to extended-precision value in FP0.
//
//	Input: Normalized packed bcd value in ETEMP(a6).
//
//	Output:	Exact floating-point representation of the packed bcd value.
//
//	Saves and Modifies: D2-D5
//
//	Speed: The program decbin takes ??? cycles to execute.
//
//	Object Size:
//
//	External Reference(s): None.
//
//	Algorithm:
//	Expected is a normal bcd (i.e. non-exceptional; all inf, zero,
//	and NaN operands are dispatched without entering this routine)
//	value in 68881/882 format at location ETEMP(A6).
//
//	A1.	Convert the bcd exponent to binary by successive adds and muls.
//	Set the sign according to SE. Subtract 16 to compensate
//	for the mantissa which is to be interpreted as 17 integer
//	digits, rather than 1 integer and 16 fraction digits.
//	Note: this operation can never overflow.
//
//	A2. Convert the bcd mantissa to binary by successive
//	adds and muls in FP0. Set the sign according to SM.
//	The mantissa digits will be converted with the decimal point
//	assumed following the least-significant digit.
//	Note: this operation can never overflow.
//
//	A3. Count the number of leading/trailing zeros in the
//	bcd string.  If SE is positive, count the leading zeros;
//	if negative, count the trailing zeros.  Set the adjusted
//	exponent equal to the exponent from A1 and the zero count
//	added if SM = 1 and subtracted if SM = 0.  Scale the
//	mantissa the equivalent of forcing in the bcd value:
//
//	SM = 0	a non-zero digit in the integer position
//	SM = 1	a non-zero digit in Mant0, lsd of the fraction
//
//	this will insure that any value, regardless of its
//	representation (ex. 0.1E2, 1E1, 10E0, 100E-1), is converted
//	consistently.
//
//	A4. Calculate the factor 10^exp in FP1 using a table of
//	10^(2^n) values.  To reduce the error in forming factors
//	greater than 10^27, a directed rounding scheme is used with
//	tables rounded to RN, RM, and RP, according to the table
//	in the comments of the pwrten section.
//
//	A5. Form the final binary number by scaling the mantissa by
//	the exponent factor.  This is done by multiplying the
//	mantissa in FP0 by the factor in FP1 if the adjusted
//	exponent sign is positive, and dividing FP0 by FP1 if
//	it is negative.
//
//	Clean up and return.  Check if the final mul or div resulted
//	in an inex2 exception.  If so, set inex1 in the fpsr and 
//	check if the inex1 exception is enabled.  If so, set d7 upper
//	word to $0100.  This will signal unimp.sa that an enabled inex1
//	exception occured.  Unimp will fix the stack.
//	

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



//
//	PTENRN, PTENRM, and PTENRP are arrays of powers of 10 rounded
//	to nearest, minus, and plus, respectively.  The tables include
//	10**{1,2,4,8,16,32,64,128,256,512,1024,2048,4096}.  No rounding
//	is required until the power is greater than 27, however, all
//	tables include the first 5 for ease of indexing.
//
	
	
	

ADR_409b4ee:
 	.byte	0,0,0,0
	.byte	2,3,2,3
	.byte	2,3,3,2
	.byte	3,2,2,3


	

//
//
//
// Constants in single precision
ADR_409b4fe:
  	.int	0x00000000
ADR_409b502:
  	.int	0x3f800000
ADR_409b506:
  	.int	0x41200000
	.globl	decbin
decbin:
	.word	0xf23c
	.word	0x9000
	.word	0x0000
	.word	0x0000


//
// decbin:
	moveml	d2-d5,a7@-
//
// Calculate exponent:
//  1. Copy bcd value in memory for use as a working copy.
//  2. Calculate absolute value of exponent in d1 by mul and add.
//  3. Correct for exponent sign.
//  4. Subtract 16 to compensate for interpreting the mant as all integer digits.
//     (i.e., all digits assumed left of the decimal point.)
//
// Register usage:
//
//  calc_e:
//	(*)  d0: temp digit storage
//	(*)  d1: accumulator for binary exponent
//	(*)  d2: digit count
//	(*)  d3: offset pointer
//	( )  d4: first word of bcd
//	( )  a0: pointer to working bcd value
//	( )  a6: pointer to original bcd value
//	(*)  FP_SCR1: working copy of original bcd value
//	(*)  L_SCR1: copy of original exponent word
//
// calc_e:
	.globl	calc_e
calc_e:
	movel	#edigits,d2	//# of nibbles (digits) in fraction part
	moveql	#estrt,d3	//counter to pick up digits
	lea	a6@(fp_scr1),a0	//load tmp bcd storage address
	movel	a6@(etemp),a0@	//save input bcd value
	movel	a6@(etemp_hi),a0@(4) //save words 2 and 3
	movel	a6@(etemp_lo),a0@(8) //and work with these
	movel	a0@,d4		//get first word of bcd
	clrl	d1		//zero d1 for accumulator
// e_gd:
ADR_409b532:
	mulul	#ten,d1		//mul partial product by one digit place
	bfextu	d4{d3:#4},d0	//get the digit and zero extend into d0
	addl	d0,d1		//d1 = d1 + d0
	addqb	#4,d3		//advance d3 to the next digit
	dbf	d2,ADR_409b532		//if we have used all 3 digits, exit loop
	btst	#30,d4		//get se
	beq	ADR_409b552		//don't negate if pos
	negl	d1		//negate before subtracting
// e_pos:
ADR_409b552:
	subl	#16,d1		//sub to compensate for shift of mant
	bge	ADR_409b56c		//if still pos, do not neg
	negl	d1		//now negative, make pos and set se
	orl	#0x40000000,d4	//set se in d4,
	orl	#0x40000000,a0@	//and in working bcd
// e_save:
ADR_409b56c:
	movel	d1,a6@(l_scr1)	//save exp in memory
//
//
// Calculate mantissa:
//  1. Calculate absolute value of mantissa in fp0 by mul and add.
//  2. Correct for mantissa sign.
//     (i.e., all digits assumed left of the decimal point.)
//
// Register usage:
//
//  calc_m:
//	(*)  d0: temp digit storage
//	(*)  d1: lword counter
//	(*)  d2: digit count
//	(*)  d3: offset pointer
//	( )  d4: words 2 and 3 of bcd
//	( )  a0: pointer to working bcd value
//	( )  a6: pointer to original bcd value
//	(*) fp0: mantissa accumulator
//	( )  FP_SCR1: working copy of original bcd value
//	( )  L_SCR1: copy of original exponent word
//
// calc_m:
	.globl	calc_m
calc_m:
	moveql	#1,d1		//word counter, init to 1
	fmoves	ADR_409b4fe,fp0	//accumulator
//
//
//  Since the packed number has a long word between the first & second parts,
//  get the integer digit then skip down & get the rest of the
//  mantissa.  We will unroll the loop once.
//
	bfextu	a0@{#28:#4},d0	//integer part is ls digit in long word
	faddb	d0,fp0		//add digit to sum in fp0
//
//
//  Get the rest of the mantissa.
//
// loadlw:
ADR_409b582:
	movel	a0@(d1:l:4),d4	//load mantissa lonqword into d4
	moveql	#fstrt,d3	//counter to pick up digits
	moveql	#fnibs,d2	//reset number of digits per a0 ptr
// md2b:
ADR_409b58a:
	fmuls	ADR_409b506,fp0	//fp0 = fp0 * 10
	bfextu	d4{d3:#4},d0	//get the digit and zero extend
	faddb	d0,fp0		//fp0 = fp0 + digit
//
//
//  If all the digits (8) in that long word have been converted (d2=0),
//  then inc d1 (=2) to point to the next long word and reset d3 to 0
//  to initialize the digit offset, and set d2 to 7 for the digit count;
//  else continue with this long word.
//
	addqb	#4,d3		//advance d3 to the next digit
	dbf	d2,ADR_409b58a		//check for last digit in this lw
// nextlw:
	addql	#1,d1		//inc lw pointer in mantissa
	cmpl	#2,d1		//test for last lw
	ble	ADR_409b582		//if not, get last one
	
//
//  Check the sign of the mant and make the value in fp0 the same sign.
//
// m_sign:
	btst	#31,a0@	//test sign of the mantissa
	beq	ap_st_z		//if clear, go to append/strip zeros
	fnegx	fp0		//if set, negate fp0
	
//
// Append/strip zeros:
//
//  For adjusted exponents which have an absolute value greater than 27*,
//  this routine calculates the amount needed to normalize the mantissa
//  for the adjusted exponent.  That number is subtracted from the exp
//  if the exp was positive, and added if it was negative.  The purpose
//  of this is to reduce the value of the exponent and the possibility
//  of error in calculation of pwrten.
//
//  1. Branch on the sign of the adjusted exponent.
//  2p.(positive exp)
//   2. Check M16 and the digits in lwords 2 and 3 in decending order.
//   3. Add one for each zero encountered until a non-zero digit.
//   4. Subtract the count from the exp.
//   5. Check if the exp has crossed zero in #3 above; make the exp abs
//	   and set SE.
//	6. Multiply the mantissa by 10**count.
//  2n.(negative exp)
//   2. Check the digits in lwords 3 and 2 in decending order.
//   3. Add one for each zero encountered until a non-zero digit.
//   4. Add the count to the exp.
//   5. Check if the exp has crossed zero in #3 above; clear SE.
//   6. Divide the mantissa by 10**count.
//
//  *Why 27?  If the adjusted exponent is within -28 < expA < 28, than
//   any adjustment due to append/strip zeros will drive the resultane
//   exponent towards zero.  Since all pwrten constants with a power
//   of 27 or less are exact, there is no need to use this routine to
//   attempt to lessen the resultant exponent.
//
// Register usage:
//
//  ap_st_z:
//	(*)  d0: temp digit storage
//	(*)  d1: zero count
//	(*)  d2: digit count
//	(*)  d3: offset pointer
//	( )  d4: first word of bcd
//	(*)  d5: lword counter
//	( )  a0: pointer to working bcd value
//	( )  FP_SCR1: working copy of original bcd value
//	( )  L_SCR1: copy of original exponent word
//
//
// First check the absolute value of the exponent to see if this
// routine is necessary.  If so, then check the sign of the exponent
// and do append (+) or strip (-) zeros accordingly.
// This section handles a positive adjusted exponent.
//
// ap_st_z:
	.globl	ap_st_z
ap_st_z:
	movel	a6@(l_scr1),d1	//load expa for range test
	cmpl	#27,d1		//test is with 27
	ble	pwrten		//if abs(expa) <28, skip ap/st zeros
	btst	#30,a0@	//check sign of exp
	bne	ap_st_n		//if neg, go to neg side
	clrl	d1		//zero count reg
	movel	a0@,d4		//load lword 1 to d4
	bfextu	d4{#28:#4},d0	//get m16 in d0
	bne	ADR_409b610		//if m16 is non-zero, go fix exp
	addql	#1,d1		//inc zero count
	moveql	#1,d5		//init lword counter
	movel	a0@(d5:l:4),d4	//get lword 2 to d4
	bne	ADR_409b5fa		//if lw 2 is zero, skip it
	addql	#8,d1		//and inc count by 8
	addql	#1,d5		//inc lword counter
	movel	a0@(d5:l:4),d4	//get lword 3 to d4
// ap_p_cl:
ADR_409b5fa:
	clrl	d3		//init offset reg
	moveql	#7,d2		//init digit counter
// ap_p_gd:
ADR_409b5fe:
	bfextu	d4{d3:#4},d0	//get digit
	bne	ADR_409b610		//if non-zero, go to fix exp
	addql	#4,d3		//point to next digit
	addql	#1,d1		//inc digit counter
	dbf	d2,ADR_409b5fe	//get next digit
// ap_p_fx:
ADR_409b610:
	movel	d1,d0		//copy counter to d2
	movel	a6@(l_scr1),d1	//get adjusted exp from memory
	subl	d0,d1		//subtract count from exp
	bge	ADR_409b62e		//if still pos, go to pwrten
	negl	d1		//now its neg// get abs
	movel	a0@,d4		//load lword 1 to d4
	orl	#0x40000000,d4	// and set se in d4
	orl	#0x40000000,a0@	// and in memory
//
// Calculate the mantissa multiplier to compensate for the striping of
// zeros from the mantissa.
//
// ap_p_fm:
ADR_409b62e:
	movel	#ptenrn,a1	//get address of power-of-ten table
	clrl	d3		//init table index
	fmoves	ADR_409b502,fp1	//init fp1 to 1
	moveql	#3,d2		//init d2 to count bits in counter
// ap_p_el:
ADR_409b640:
	asrl	#1,d0		//shift lsb into carry
	bcc	ADR_409b64e		//if 1, mul fp1 by pwrten factor
	fmulx	a1@(d3),fp1	//mul by 10**(d3_bit_no)
// ap_p_en:
ADR_409b64e:
	addl	#12,d3		//inc d3 to next rtable entry
	tstl	d0		//check if d0 is zero
	bne	ADR_409b640		//if not, get next bit
	fmulx	fp1,fp0		//mul mantissa by 10**(no_bits_shifted)
	bra	pwrten		//go calc pwrten
//
// This section handles a negative adjusted exponent.
//
// ap_st_n:
	.globl	ap_st_n
ap_st_n:
	clrl	d1		//clr counter
	moveql	#2,d5		//set up d5 to point to lword 3
	movel	a0@(d5:l:4),d4	//get lword 3
	bne	ADR_409b67c		//if not zero, check digits
	subl	#1,d5		//dec d5 to point to lword 2
	addql	#8,d1		//inc counter by 8
	movel	a0@(d5:l:4),d4	//get lword 2
// ap_n_cl:
ADR_409b67c:
	movel	#28,d3		//point to last digit
	moveql	#7,d2		//init digit counter
// ap_n_gd:
ADR_409b680:
	bfextu	d4{d3:#4},d0	//get digit
	bne	ADR_409b692		//if non-zero, go to exp fix
	subql	#4,d3		//point to previous digit
	addql	#1,d1		//inc digit counter
	dbf	d2,ADR_409b680	//get next digit
// ap_n_fx:
ADR_409b692:
	movel	d1,d0		//copy counter to d0
	movel	a6@(l_scr1),d1	//get adjusted exp from memory
	subl	d0,d1		//subtract count from exp
	bgt	ADR_409b6b0		//if still pos, go fix mantissa
	negl	d1		//take abs of exp and clr se
	movel	a0@,d4		//load lword 1 to d4
	andl	#0xbfffffff,d4	// and clr se in d4
	andl	#0xbfffffff,a0@	// and in memory
//
// Calculate the mantissa multiplier to compensate for the appending of
// zeros to the mantissa.
//
// ap_n_fm:
ADR_409b6b0:
	movel	#ptenrn,a1	//get address of power-of-ten table
	clrl	d3		//init table index
	fmoves	ADR_409b502,fp1	//init fp1 to 1
	moveql	#3,d2		//init d2 to count bits in counter
// ap_n_el:
ADR_409b6c2:
	asrl	#1,d0		//shift lsb into carry
	bcc	ADR_409b6d0		//if 1, mul fp1 by pwrten factor
	fmulx	a1@(d3),fp1	//mul by 10**(d3_bit_no)
// ap_n_en:
ADR_409b6d0:
	addl	#12,d3		//inc d3 to next rtable entry
	tstl	d0		//check if d0 is zero
	bne	ADR_409b6c2		//if not, get next bit
	fdivx	fp1,fp0		//div mantissa by 10**(no_bits_shifted)
//
//
// Calculate power-of-ten factor from adjusted and shifted exponent.
//
// Register usage:
//
//  pwrten:
//	(*)  d0: temp
//	( )  d1: exponent
//	(*)  d2: {FPCR[6:5],SM,SE} as index in RTABLE; temp
//	(*)  d3: FPCR work copy
//	( )  d4: first word of bcd
//	(*)  a1: RTABLE pointer
//  calc_p:
//	(*)  d0: temp
//	( )  d1: exponent
//	(*)  d3: PWRTxx table index
//	( )  a0: pointer to working copy of bcd
//	(*)  a1: PWRTxx pointer
//	(*) fp1: power-of-ten accumulator
//
// Pwrten calculates the exponent factor in the selected rounding mode
// according to the following table:
//	
//	Sign of Mant  Sign of Exp  Rounding Mode  PWRTEN Rounding Mode
//
//	ANY	  ANY	RN	RN
//
//	 +	   +	RP	RP
//	 -	   +	RP	RM
//	 +	   -	RP	RM
//	 -	   -	RP	RP
//
//	 +	   +	RM	RM
//	 -	   +	RM	RP
//	 +	   -	RM	RP
//	 -	   -	RM	RM
//
//	 +	   +	RZ	RM
//	 -	   +	RZ	RM
//	 +	   -	RZ	RP
//	 -	   -	RZ	RP
//
//
// pwrten:
	.globl	pwrten
pwrten:
	movel	a6@(user_fpcr),d3 //get user's fpcr
	bfextu	d3{#26:#2},d2	//isolate rounding mode bits
	movel	a0@,d4		//reload 1st bcd word to d4
	asll	#2,d2		//format d2 to be
	bfextu	d4{#0:#2},d0	// {fpcr[6],fpcr[5],sm,se}
	addl	d0,d2		//in d2 as index into rtable
	lea	ADR_409b4ee,a1	//load rtable base
	moveb	a1@(d2),d0	//load new rounding bits from table
	clrl	d3			//clear d3 to force no exc and extended
	bfins	d0,d3{#26:#2}	//stuff new rounding bits in fpcr
	fmovel	d3,fpcr		//write new fpcr
	asrl	#1,d0		//write correct ptenxx table
	bcc	ADR_409b71c		//to a1
	lea	ptenrp,a1	//it is rp
	bra	ADR_409b736		//go to init section
// not_rp:
ADR_409b71c:
	asrl	#1,d0		//keep checking
	bcc	ADR_409b730
	lea	ptenrm,a1	//it is rm
	bra	ADR_409b736		//go to init section
// not_rm:
ADR_409b730:
	lea	ptenrn,a1	//it is rn
// calc_p:
ADR_409b736:
	movel	d1,d0		//copy exp to d0//use d0
	bpl	ADR_409b746		//if exp is negative,
	negl	d0		//invert it
	orl	#0x40000000,a0@	//and set se bit
// no_neg:
ADR_409b746:
	clrl	d3		//table index
	fmoves	ADR_409b502,fp1	//init fp1 to 1
// e_loop:
ADR_409b750:
	asrl	#1,d0		//shift next bit into carry
	bcc	ADR_409b75e		//if zero, skip the mul
	fmulx	a1@(d3),fp1	//mul by 10**(d3_bit_no)
// e_next:
ADR_409b75e:
	addl	#12,d3		//inc d3 to next rtable entry
	tstl	d0		//check if d0 is zero
	bne	ADR_409b750		//not zero, continue shifting
//
//
//  Check the sign of the adjusted exp and make the value in fp0 the
//  same sign. If the exp was pos then multiply fp1*fp0;
//  else divide fp0/fp1.
//
// Register Usage:
//  norm:
//	( )  a0: pointer to working bcd value
//	(*) fp0: mantissa accumulator
//	( ) fp1: scaling factor - 10**(abs(exp))
//
// norm:
	.globl	norm
norm:
	btst	#30,a0@	//test the sign of the exponent
	beq	ADR_409b780		//if clear, go to multiply
// div:
	fdivx	fp1,fp0		//exp is negative, so divide mant by exp
	bra	ADR_409b784
// mul:
ADR_409b780:
	fmulx	fp1,fp0		//exp is positive, so multiply by exp
//
//
// Clean up and return with result in fp0.
//
// If the final mul/div in decbin incurred an inex exception,
// it will be inex2, but will be reported as inex1 by get_op.
//
// end_dec:
ADR_409b784:
	fmovel	fpsr,d0		//get status register	
	bclr	#inex2_bit+8,d0	//test for inex2 and clear it
	fmovel	d0,fpsr		//return status reg w/o inex2
	beq	ADR_409b79e		//skip this if no exc
	orl	#inx1a_mask,a6@(user_fpsr) //set inex1/ainex
// no_exc:
ADR_409b79e:
	moveml	a7@+,d2-d5
	rts
ADR_409b7a4:
	.word	0x3fff
	.word	0x0000
	.word	0x8000
	.word	0x0000
	.word	0x0000
	.word	0x0000
ADR_409b7b0:
	.word	0xbfff
	.word	0x0000
	.word	0x8000
	.word	0x0000
	.word	0x0000
	.word	0x0000
ADR_409b7bc:
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
ADR_409b7c8:
	.word	0x8000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
ADR_409b7d4:
	.word	0x7fff
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
ADR_409b7e0:
	.word	0xffff
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
ADR_409b7ec:
	.word	0x7fff
	.word	0x0000
	.word	0xffff
	.word	0xffff
	.word	0xffff
	.word	0xffff
ADR_409b7f8:
	.word	0x3fff
	.word	0x0000
	.word	0xc90f
	addl	a2@-,d5
	.word	0x2168
	.word	0xc235
ADR_409b804:
	.word	0xbfff
	.word	0x0000
	.word	0xc90f
	addl	a2@-,d5
	.word	0x2168
	.word	0xc235
	.globl	do_func
do_func:
	.word	0x422e
	.word	0xffba
	.word	0xe9ee
	.word	0x0006
	.word	0xff1c
	.word	0x0c80
	.word	0x0000
	.word	0x0017
	.word	0x66ff
	.word	0x0000
	.word	0x000a
	.word	0x4ef9
	.word	0x040a
	.word	0x1a9a
//
//	do_func.sa 1.15 10/9/90
//
// Do_func performs the unimplemented operation.  The operation
// to be performed is determined from the lower 7 bits of the
// extension word (except in the case of fmovecr and fsincos).
// The opcode and tag bits form an index into a jump table in 
// tbldo.sa.  Cases of zero, infinity and NaN are handled in 
// do_func by forcing the default result.  Normalized and
// denormalized (there are no unnormalized numbers at this
// point) are passed onto the emulation code.  
//
// CMDREG1B and STAG are extracted from the fsave frame
// and combined to form the table index.  The function called
// will start with a0 pointing to the ETEMP operand.  Dyadic
// functions can find FPTEMP at -12(a0).
//
// Called functions return their result in fp0.  Sincos returns
// sin(x) in fp0 and cos(x) in fp1.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



// do_func:
	movew	a6@(cmdreg1b),d0
	andl	#0x7f,d0
	cmpil	#0x38,d0		//if the extension is >= 0x38, 
	bge	serror		//it is illegal
	bfextu	a6@(stag){#0:#3},d1
	lsll	#3,d0		//make room for stag
	addl	d1,d0		//combine for final index into table


	lea	tblpre,a1	//start of monster jump table
	movel	a1@(d0:w:4),a1	//real target address
	lea	a6@(etemp),a0	//a0 is pointer to src op
	.word	0x222e
	.word	0xff80
	.word	0x0281
	.word	0x0000
	.word	0x00ff
	.word	0xf23c
	.word	0x9000
	.word	0x0000
	.word	0x0000
	jmp	a1@
//
//	ERROR
//
// serror:
	.globl	serror
serror:
	st	a6@(store_flg)
	rts
//
// These routines load forced values into fp0.  They are called
// by index into tbldo.
//
// Load a signed zero to fp0 and set inex2/ainex
//
// snzrinx:
	.globl	snzrinx
snzrinx:
	btst	#sign_bit,a0@(local_ex)	//get sign of source operand
	bne	ADR_409b88c	//if negative, branch
	bsr	ld_pzero	//bsr so we can return and set inx
	bra	t_inx2		//now, set the inx for the next inst
// ld_mzinx:
ADR_409b88c:
	bsr	ld_mzero	//if neg, load neg zero, return here
	bra	t_inx2		//now, set the inx for the next inst
//
// Load a signed zero to fp0; do not set inex2/ainex 
//
// szero:
	.globl	szero
szero:
	btst	#sign_bit,a0@(local_ex) //get sign of source operand
	bne	ld_mzero	//if neg, load neg zero
	bra	ld_pzero	//load positive zero
//
// Load a signed infinity to fp0; do not set inex2/ainex 
//
// sinf:
	.globl	sinf
sinf:
	btst	#sign_bit,a0@(local_ex)		//get sign of source operand
	bne	ld_minf		//if negative branch
	bra	ld_pinf
//
// Load a signed one to fp0; do not set inex2/ainex 
//
// sone:
	.globl	sone
sone:
	btst	#sign_bit,a0@(local_ex)		//check sign of source
	bne	ld_mone
	bra	ld_pone
//
// Load a signed pi/2 to fp0; do not set inex2/ainex 
//
// spi_2:
	.globl	spi_2
spi_2:
	btst	#sign_bit,a0@(local_ex)		//check sign of source
	bne	ld_mpi2
	bra	ld_ppi2
//
// Load either a +0 or +inf for plus/minus operand
//
// szr_inf:
	.globl	szr_inf
szr_inf:
	btst	#sign_bit,a0@(local_ex)		//check sign of source
	bne	ld_pzero
	bra	ld_pinf
//
// Result is either an operr or +inf for plus/minus operand
// [Used by slogn, slognp1, slog10, and slog2]
//
// sopr_inf:
	.globl	sopr_inf
sopr_inf:
	btst	#sign_bit,a0@(local_ex)		//check sign of source
	bne	t_operr
	bra	ld_pinf
//
//	FLOGNP1 
//
// sslognp1:
	.globl	sslognp1
sslognp1:
	fmovemx a0@,fp0-fp0
	fcmpb	#-1,fp0
	//  gnu //assembler generates bad floating pt branch to external symbols!
	fble	0f
	jmp	slognp1
0:
	fbne	1f
	jmp	t_dz2		//if = -1, divide by zero exception
1:
	fmovel	#0,fpsr		//clr n flag
	bra	t_operr		//take care of operands < -1
//
//	FETOXM1
//
// setoxm1i:
	.globl	setoxm1i
setoxm1i:
	btst	#sign_bit,a0@(local_ex)	//check sign of source
	bne	ld_mone
	bra	ld_pinf
//
//	FLOGN
//
// sslogn:
	.globl	sslogn
sslogn:
	btst	#sign_bit,a0@(local_ex) 
	bne	t_operr:l
	cmpw	#0x3fff,a0@(0:w)
	.word	0x66ff
	.word	0x0000
	.word	0x5e02
	cmpl	#0x80000000,a0@(4:w)
	.word	0x66ff
	.word	0x0000
	.word	0x5df4
	tstl	a0@(8:w)
	.word	0x66ff
	.word	0x0000
	.word	0x5dea
	fmovex	ADR_409b7bc:l,fp0
	rts
	.globl	sslognd
sslognd:
	btst	#7,a0@(0:w)
	.word	0x67ff
	.word	0x0000
	.word	0x5d3e
	bra	t_operr		//take care of operands < 0
	.globl	sslog10
sslog10:
	btst	#7,a0@(0:w)
	bne	t_operr:l
	cmpw	#0x3fff,a0@(0:w)
	.word	0x66ff
	.word	0x0000
	.word	0x53d6
	cmpl	#0x80000000,a0@(4:w)
	.word	0x66ff
	.word	0x0000
	.word	0x53c8
	tstl	a0@(8:w)
	.word	0x66ff
	.word	0x0000
	.word	0x53be
	fmovex	ADR_409b7bc:l,fp0
	rts
	.globl	sslog10d
sslog10d:
	btst	#7,a0@(0:w)
	.word	0x67ff
	.word	0x0000
	.word	0x5384
	bra	t_operr		//take care of operands < 0
	.globl	sslog2
sslog2:
	btst	#7,a0@(0:w)
	bne	t_operr:l
	cmpw	#0x3fff,a0@(0:w)
	.word	0x66ff
	.word	0x0000
	.word	0x53d2
	cmpl	#0x80000000,a0@(4:w)
	.word	0x66ff
	.word	0x0000
	.word	0x53c4
	tstl	a0@(8:w)
	.word	0x66ff
	.word	0x0000
	.word	0x53ba
	fmovex	ADR_409b7bc:l,fp0
	rts
	.globl	sslog2d
sslog2d:
	btst	#7,a0@(0:w)
	.word	0x67ff
	.word	0x0000
	.word	0x5380
	bra	t_operr:l
ADR_409ba26:
	.long	smod
	.long	ADR_409ba96
	.long	ADR_409bac6
	.long	ADR_409ba8a
	.long	ADR_409ba9c
	.long	ADR_409ba96
	.long	ADR_409ba9c
	.long	ADR_409ba8a
	.long	ADR_409ba96
	.long	ADR_409ba96
	.long	ADR_409ba96
	.long	ADR_409ba8a
	.long	ADR_409ba90
	.long	ADR_409ba90
	.long	ADR_409ba90
	.long	ADR_409ba90

// pmod:
	.globl	pmod
pmod:
	bfextu	a6@(stag){#0:#3},d0 //stag = d0
	bfextu	a6@(dtag){#0:#3},d1 //dtag = d1

	bclr	#2,d0		//alias extended denorm to normal(for table jump)
	bclr	#2,d1		//alias extended denorm to normal(for table jump)

	lslb	#2,d1
	orb	d0,d1		//d1{#3:#2} = dtag, d1{#1:#0} = stag
//				;Tag values:
//				;00 = norm or denorm
//				;01 = zero
//				;10 = inf
//				;11 = nan
	lea	ADR_409ba26,a1
	movel	a1@(d1:w:4),a1
	jmp	a1@

// smod_snan:
ADR_409ba8a:
	bra	src_nan
// smod_dnan:
ADR_409ba90:
	bra	dst_nan
// smod_oper:
ADR_409ba96:
	bra	t_operr
// smod_zro:
ADR_409ba9c:
	moveb	a6@(etemp),d1	//get sign of src op
	moveb	a6@(fptemp),d0	//get sign of dst op
	eorb	d0,d1		//get exor of sign bits
	btst	#7,d1		//test for sign
	beq	ADR_409bab6	//if clr, do not set sign big
	bset	#q_sn_bit,a6@(fpsr_qbyte) //set q-byte sign bit
// smod_zsn:
ADR_409bab6:
	btst	#7,d0		//test if + or -
	beq	ld_pzero	//if pos then load +0
	bra	ld_mzero	//else neg load -0
	
// smod_fpn:
ADR_409bac6:
	moveb	a6@(etemp),d1	//get sign of src op
	moveb	a6@(fptemp),d0	//get sign of dst op
	eorb	d0,d1		//get exor of sign bits
	btst	#7,d1		//test for sign
	beq	ADR_409bae0:l
	bset	#q_sn_bit,a6@(fpsr_qbyte) //set q-byte sign bit
ADR_409bae0:
	tstb	a6@(-224:w)
	bpl	ADR_409baf4:l
	lea	a6@(-216:w),a0
	bra	t_resdnrm:l
ADR_409baf4:
	fmoveml	a6@(-128:w),fpc
// smod_fsn:
	fmovex a6@(fptemp),fp0	//load dest operand to fp0
	rts
ADR_409bb02:
	.long	srem
	.long	ADR_409bb72
	.long	ADR_409bba2
	.long	ADR_409bb66
	.long	ADR_409bb78
	.long	ADR_409bb72
	.long	ADR_409bb78
	.long	ADR_409bb66
	.long	ADR_409bb72
	.long	ADR_409bb72
	.long	ADR_409bb72
	.long	ADR_409bb66
	.long	ADR_409bb6c
	.long	ADR_409bb6c
	.long	ADR_409bb6c
	.long	ADR_409bb6c

// prem:

	.globl	prem
prem:
	bfextu	a6@(stag){#0:#3},d0 //stag = d0
	bfextu	a6@(dtag){#0:#3},d1 //dtag = d1

	bclr	#2,d0		//alias extended denorm to normal(for table jump)
	bclr	#2,d1		//alias extended denorm to normal(for table jump)

	lslb	#2,d1
	orb	d0,d1		//d1{#3:#2} = dtag, d1{#1:#0} = stag
//				;Tag values:
//				;00 = norm or denorm
//				;01 = zero
//				;10 = inf
//				;11 = nan
	lea	ADR_409bb02,a1
	movel	a1@(d1:w:4),a1
	jmp	a1@
	
// srem_snan:
ADR_409bb66:
	bra	src_nan
// srem_dnan:
ADR_409bb6c:
	bra	dst_nan
// srem_oper:
ADR_409bb72:
	bra	t_operr
// srem_zro:
ADR_409bb78:
	moveb	a6@(etemp),d1	//get sign of src op
	moveb	a6@(fptemp),d0	//get sign of dst op
	eorb	d0,d1		//get exor of sign bits
	btst	#7,d1		//test for sign
	beq	ADR_409bb92	//if clr, do not set sign big
	bset	#q_sn_bit,a6@(fpsr_qbyte) //set q-byte sign bit
// srem_zsn:
ADR_409bb92:
	btst	#7,d0		//test if + or -
	beq	ld_pzero	//if pos then load +0
	bra	ld_mzero	//else neg load -0
	
// srem_fpn:
ADR_409bba2:
	moveb	a6@(etemp),d1	//get sign of src op
	moveb	a6@(fptemp),d0	//get sign of dst op
	eorb	d0,d1		//get exor of sign bits
	btst	#7,d1		//test for sign
	beq	ADR_409bbbc:l
	bset	#q_sn_bit,a6@(fpsr_qbyte) //set q-byte sign bit
ADR_409bbbc:
	tstb	a6@(-224:w)
	bpl	ADR_409bbd0:l
	lea	a6@(-216:w),a0
	bra	t_resdnrm:l
ADR_409bbd0:
	fmoveml	a6@(-128:w),fpc
// srem_fsn:
	fmovex a6@(fptemp),fp0	//return dest to fp0
	rts
ADR_409bbde:
	.long	sscale
	.long	sscale
	.long	ADR_409bc42
	.long	ADR_409bc72
	.long	ADR_409bc4e
	.long	ADR_409bc4e
	.long	ADR_409bc42
	.long	ADR_409bc72
	.long	ADR_409bc60
	.long	ADR_409bc60
	.long	ADR_409bc42
	.long	ADR_409bc72
	.long	ADR_409bc48
	.long	ADR_409bc48
	.long	ADR_409bc48
	.long	ADR_409bc48
	.globl	pscale
pscale:
	bfextu	a6@(-232:w){#0,#3},d0
	bfextu	a6@(-224:w){#0,#3},d1
	bclr	#2,d0
	bclr	#2,d1
	lslb	#2,d1
	orb	d0,d1		//d1{#4:#2} = dtag, d1{#1:#0} = stag
//
	lea	ADR_409bbde,a1	//load start of jump table
	movel	a1@(d1:w:4),a1	//load a1 with routine label depending on tag
	jmp	a1@		//go to the routine

// scl_opr:
ADR_409bc42:
	bra	t_operr

// scl_dnan:
ADR_409bc48:
	bra	dst_nan

// scl_zro:
ADR_409bc4e:
	btst	#sign_bit,a6@(fptemp_ex)	//test if + or -
	beq	ld_pzero		//if pos then load +0
	bra	ld_mzero		//if neg then load -0
// scl_inf:
ADR_409bc60:
	btst	#sign_bit,a6@(fptemp_ex)	//test if + or -
	beq	ld_pinf			//if pos then load +inf
	bra	ld_minf			//else neg load -inf
// scl_snan:
ADR_409bc72:
	bra	src_nan
//
//	FSINCOS
//
// ssincosz:
	.globl	ssincosz
ssincosz:
	btst	#sign_bit,a6@(etemp)	//get sign
	beq	ADR_409bc92
	fmovex	ADR_409b7c8,fp0
	bra	ADR_409bc9a
// sincosp:
ADR_409bc92:
	fmovex ADR_409b7bc,fp0
// sincoscom:
ADR_409bc9a:
  	fmovemx ADR_409b7a4,fp1-fp1	//do not allow fpsr to be affected
	bra	sto_cos		//store cosine result

// ssincosi:
	.globl	ssincosi
ssincosi:
	fmovex ADR_409b7ec,fp1	//load nan
	bsr	sto_cos		//store cosine result
	fmovex ADR_409b7ec,fp0	//load nan
	bra	t_operr

// ssincosnan:
	.globl	ssincosnan
ssincosnan:
	movel	a6@(etemp_ex),a6@(fp_scr1)
	movel	a6@(etemp_hi),a6@(fp_scr1+4)
	movel	a6@(etemp_lo),a6@(fp_scr1+8)
	bset	#signan_bit,a6@(fp_scr1+4)
	fmovemx a6@(fp_scr1),fp1-fp1
	bsr	sto_cos
	bra	src_nan:l
//
// This code forces default values for the zero, inf, and nan cases 
// in the transcendentals code.  The CC bits must be set in the
// stacked FPSR to be correctly reported.
//
//**Returns +PI/2
// ld_ppi2:
	.globl	ld_ppi2
ld_ppi2:
	fmovex ADR_409b7f8,fp0		//load +pi/2
	bra	t_inx2			//set inex2 exc

//**Returns -PI/2
// ld_mpi2:
	.globl	ld_mpi2
ld_mpi2:
	fmovex ADR_409b804,fp0		//load -pi/2
	orl	#neg_mask,a6@(user_fpsr)	//set n bit
	bra	t_inx2			//set inex2 exc

//**Returns +inf
// ld_pinf:
	.globl	ld_pinf
ld_pinf:
	fmovex ADR_409b7d4,fp0		//load +inf
	orl	#inf_mask,a6@(user_fpsr)	//set i bit
	rts

//**Returns -inf
// ld_minf:
	.globl	ld_minf
ld_minf:
	fmovex ADR_409b7e0,fp0		//load -inf
	orl	#neg_mask+inf_mask,a6@(user_fpsr)	//set n and i bits
	rts

//**Returns +1
// ld_pone:
	.globl	ld_pone
ld_pone:
	fmovex ADR_409b7a4,fp0		//load +1
	rts

//**Returns -1
// ld_mone:
	.globl	ld_mone
ld_mone:
	fmovex ADR_409b7b0,fp0		//load -1
	orl	#neg_mask,a6@(user_fpsr)	//set n bit
	rts

//**Returns +0
// ld_pzero:
	.globl	ld_pzero
ld_pzero:
	fmovex ADR_409b7bc,fp0		//load +0
	orl	#z_mask,a6@(user_fpsr)	//set z bit
	rts

//**Returns -0
// ld_mzero:
	.globl	ld_mzero
ld_mzero:
	fmovex ADR_409b7c8,fp0		//load -0
	orl	#neg_mask+z_mask,a6@(user_fpsr)	//set n and z bits
	rts
ADR_409bd76:
	.long	ADR_409bec8
	.long	ADR_409bece
	.long	ADR_409bece
	.long	ADR_409bf8a
	.long	ADR_409bf8a
	.long	ADR_409bece
	.long	ADR_409beda
	.long	ADR_409beda
	.long	ADR_409bf3e
	.globl	gen_except
gen_except:
	cmpb	#0x0,sp@(1:w)
//
//	gen_except.sa 1.18 10/8/90
//
//	gen_except --- FPSP routine to detect reportable exceptions
//	
//	This routine compares the exception enable byte of the
//	user_fpcr on the stack with the exception status byte
//	of the user_fpsr. 
//
//	Any routine which may report an exceptions must load
//	the stack frame in memory with the exceptional operand(s).
//
//	Priority for exceptions is:
//
//	Highest:	bsun
//			snan
//			operr
//			ovfl
//			unfl
//			dz
//			inex2
//	Lowest:		inex1
//
//	Note: The IEEE standard specifies that inex2 is to be
//	reported if ovfl occurs and the ovfl enable bit is not
//	set but the inex2 enable bit is.  
//
//
//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.


	beq	ADR_409be62		//go handle idle frame
	cmpb	#0x28,sp@(1:w)
	beq	ADR_409be28:l
	cmpb	#0x30,sp@(1:w)
	beq	ADR_409be28:l
	cmpb	#0x60,sp@(1:w)
	.word	0x66ff
	.word	0x0000
	.word	0x4f0c
	lea	a7@(busy_size+local_size),a1 //init a1 so fpsph
//					;equates will work
// Fix up the new busy frame with entries from the unimp frame
//
	movel	a6@(etemp_ex),a1@(etemp_ex) //copy etemp from unimp
	movel	a6@(etemp_hi),a1@(etemp_hi) //frame to busy frame
	movel	a6@(etemp_lo),a1@(etemp_lo) 
	movel	a6@(cmdreg1b),a1@(cmdreg1b) //set inst in frame to unimp
	movel	a6@(cmdreg1b),d0		//fix cmd1b to make it
	andl	#0x3c30000,d0
	bfextu	a6@(-228:w){#13,#1},d1
	lsll	#5,d1
	swap	d1
	orl	d1,d0
	bfextu	a6@(-228:w){#10,#3},d1
	lsll	#2,d1
	swap	d1
	orl	d1,d0
	movel	d0,a1@(cmdreg3b)		//in the busy frame
//
// Or in the FPSR from the emulation with the USER_FPSR on the stack.
//
	fmovel	fpsr,d0		
	orl	d0,a6@(user_fpsr)
	movel	a6@(-124:w),a1@(-256:w)
	orl	#0x1800000,a1@(-220:w)
//
// On a busy frame, we must clear the nmnexc bits.
//
// These next 3 instructions will function on d43b.
//	move.l		USER_FPSR(a6),FPSR_SHADOW(a1) ;set exc bits
//	bset.b		#SFLAG,E_BYTE(a1)	;set s
//	bset.b		#XFLAG,T_BYTE(a1)	;set x
//	cmpi.l		#BUSY_FMT,(a7)		;check frame type
//	bne.b		busy_fr			;if busy, clr nmnexc
//	clr.w		NMNEXC(a1)		;clr nmnexc & nmcexc
// busy_fr:
	bra	ADR_409c064
ADR_409be28:
	cmpb	#0x28,sp@(1:w)
	bne	ADR_409be3e:l

//
// Frame is an unimp frame possible resulting from an fmove <ea>,fp0
// that caused an exception
//
// unimp_x:
	lea	a7@(unimp_size+local_size),a1 //init a1 so fpsph
	bra	ADR_409be4e:l
ADR_409be3e:
	cmpb	#0x30,sp@(1:w)
	.word	0x66ff
	.word	0x0000
	.word	0x4e8c
	lea	sp@(244:w),a1
ADR_409be4e:
	movel	a6@(cmdreg1b),a1@(cmdreg1b) //set inst in frame to unimp
//
// Or in the FPSR from the emulation with the USER_FPSR on the stack.
//
	fmovel	fpsr,d0		
	orl	d0,a6@(user_fpsr)
	bra	ADR_409c064

//
// Frame is idle, so check for exceptions reported through
// USER_FPSR and set the unimp frame accordingly.  
// A7 must be incremented to the point before the
// idle fsave vector to the unimp vector.
//
	
// do_check:
ADR_409be62:
	addl	#4,a7			//point a7 back to unimp frame
//
// Or in the FPSR from the emulation with the USER_FPSR on the stack.
//
	fmovel	fpsr,d0		
	orl	d0,a6@(user_fpsr)
	cmpb	#0x60,sp@(1:w)
	bne		ADR_409be9c		//if busy, clr nmnexc
	clrw		a6@(nmnexc)		//clr nmnexc & nmcexc
	btst	#5,a6@(-228:w)
	bne	ADR_409beac:l
	movel	a6@(-124:w),a6@(-256:w)
	orl	#0x1800000,a6@(-220:w)
	bra	ADR_409beac:l
ADR_409be9c:
	cmpb	#0x28,sp@(1:w)
	beq	ADR_409beac:l
	clrw	a6@(-236:w)
ADR_409beac:
	moveb	a6@(fpcr_enable),d0	//get fpcr enable byte
	andb	a6@(fpsr_except),d0	//and in the fpsr exc byte
	bfffo	d0{#24,#8},d1
	lea	ADR_409bd76,a0		//load jmp table address
	subib	#24,d1			//normalize bit offset to 0-8
	movel	a0@(d1:w:4),a0		//load routine address based
//					;based on first enabled exc
	jmp	a0@			//jump to routine
//
// Bsun is not possible in unimp or unsupp
//
// bsun_exc:
ADR_409bec8:
	bra	ADR_409c064
//
// The typical work to be done to the unimp frame to report an 
// exception is to set the E1/E3 byte and clr the U flag.
// commonE1 does this for E1 exceptions, which are snan, 
// operr, and dz.  commonE3 does this for E3 exceptions, which 
// are inex2 and inex1, and also clears the E1 exception bit
// left over from the unimp exception.
//
// commone1:
ADR_409bece:
	bset	#e1,a6@(e_byte)		//set e1 flag
	bra	ADR_409bf32			//go clean and exit

// commone3:
//
// Temporary D43B fix for unimp frame stacked as a busy frame.
// Check bits in the flag UFLG_TMP, used in place of UFLAG on 
// the fsave stack, for the calling state.
//
ADR_409beda:
	tstb	a6@(uflg_tmp)		//test flag for unsup/unimp state
	bne	ADR_409bef6
//
// Uncomment the following 2 lines after the d43b errata is
// fixed.
//	btst.b	#UFLAG,T_BYTE(a6)	;check if unsupp or unimp
//	beq.b	unsE3			;branch if unsupp
// unie3:
	bset	#e3,a6@(e_byte)		//set e3 flag
	bclr	#e1,a6@(e_byte)		//clr e1 from unimp
	bra	ADR_409bf32

// unse3:
ADR_409bef6:
	tstb	a6@(res_flg)
	bne	ADR_409bf06	
// unse3_1:
	bset	#e3,a6@(e_byte)		//set e3 flag
// unse3_0:
ADR_409bf06:
	bclr	#e1,a6@(e_byte)		//clr e1 flag
	movel	a6@(cmdreg1b),d0
	andl	#0x3c30000,d0
	bfextu	a6@(-228:w){#13,#1},d1
	lsll	#5,d1
	swap	d1
	orl	d1,d0
	bfextu	a6@(-228:w){#10,#3},d1
	lsll	#2,d1
	swap	d1
	orl	d1,d0
	movel	d0,a6@(cmdreg3b)		//in the busy frame

// commone:
ADR_409bf32:
	bclr	#uflag,a6@(t_byte)	//clr u flag from unimp
	bra	ADR_409c064		//go clean and exit
//
// No bits in the enable byte match existing exceptions.  Check for
// the case of the ovfl exc without the ovfl enabled, but with
// inex2 enabled.
//
// no_match:
ADR_409bf3e:
	btst	#inex2_bit,a6@(fpcr_enable) //check for ovfl/inex2 case
	beq	ADR_409bf5c			//if clear, exit
	btst	#ovfl_bit,a6@(fpsr_except) //now check ovfl
	beq	ADR_409bf5c			//if clear, exit
	bra	ADR_409bf8a		//go to unfl_ovfl to determine if
//					;it is an unsupp or unimp exception
	
// No exceptions are to be reported.  If the instruction was 
// unimplemented, no FPU restore is necessary.  If it was
// unsupported, we must perform the restore.
// no_exc:
//
// Temporary D43B fix for unimp frame stacked as a busy frame.
// Check bits in the flag UFLG_TMP, used in place of UFLAG on 
// the fsave stack, for the calling state.
//
ADR_409bf5c:
	tstb	a6@(uflg_tmp)	//test flag for unsupp/unimp state
	beq	ADR_409bf70
//
// Uncomment the following 2 lines after the d43b errata is
// fixed.
//	btst.b		#UFLAG,T_BYTE(a6)
//	bne.b		uni_no_exc

// uns_no_exc:
	tstb		a6@(res_flg)	//check if frestore is needed
	bne		ADR_409c064 	//if clear, no frestore needed
ADR_409bf70:
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(user_fpcr),fpcr/fpsr/fpi
	unlk		a6
	bra		ADR_409c0e2
//
// Unsupported Data Type Handler:
// Ovfl:
//   An fmoveout that results in an overflow is reported this way.
// Unfl:
//   An fmoveout that results in an underflow is reported this way.
//
// Unimplemented Instruction Handler:
// Ovfl:
//   Only scosh, ssinh, stwotox, and scale can set overflow in 
//   this manner.
// Unfl:
//   Stwotox and scale can set underflow in this manner.
//   Any of the other Library Routines such that f(x)=x in which
//   x is an extended denorm can report an underflow exception. 
//   It is the responsibility of the exception-causing exception 
//   to make sure that WBTEMP is correct.
//
// ovfl_unfl:
//
// Temporary D43B fix for unimp frame stacked as a busy frame.
// Check bits in the flag UFLG_TMP, used in place of UFLAG on 
// the fsave stack, for the calling state.
//
ADR_409bf8a:
	tstb	a6@(uflg_tmp)	//test flag for unsupp/unimp state
	beq	ADR_409bfcc:l
	tstb	a6@(-70:w)
	beq	ADR_409bef6:l
	clrb	a6@(-284:w)
	bset	#2,a6@(-220:w)
	movew	a6@(-204:w),a6@(-216:w)
	movel	a6@(-200:w),a6@(-212:w)
	movel	a6@(-196:w),a6@(-208:w)
	bset	#4,a6@(-224:w)
	bclr	#5,a6@(-219:w)
	bra	ADR_409c064:l
ADR_409bfcc:
	moveb	sp@,a6@(-69:w)
	cmpb	#0x60,sp@(1:w)
	beq	ADR_409c00c:l
	cmpb	#0x40,sp@
	bne	ADR_409bfee:l
	moveq	#13,d0
	bra	ADR_409bffa:l
ADR_409bfee:
	cmpb	#0x41,sp@
	.word	0x66ff
	.word	0x0000
	.word	0x4cde
	moveq	#11,d0

ADR_409bffa:
	clrl	a7@
// loop:
ADR_409bffc:
	clrl	a7@-			//clear and dec a7
	dbra	d0,ADR_409bffc
	moveb	a6@(-69:w),sp@
	moveb	#0x60:b,sp@(1:w)

ADR_409c00c:
	movel	a6@(fp_scr1),a6@(wbtemp_ex) 	//write
	movel	a6@(fp_scr1+4),a6@(wbtemp_hi)	//exceptional op into
	movel	a6@(fp_scr1+8),a6@(wbtemp_lo)	//wbtemp
	bset	#e3,a6@(e_byte)		//set e3 flag
	bclr	#2,a6@(-220:w)
	bclr	#uflag,a6@(t_byte)	//clr u flag
	movel	a6@(user_fpsr),a6@(fpsr_shadow)
	orl	#0x1800000,a6@(-220:w)
	movel	a6@(cmdreg1b),d0		//fix cmd1b to make it
	andl	#0x3c30000,d0
	bfextu	a6@(-228:w){#13,#1},d1
	lsll	#5,d1
	swap	d1
	orl	d1,d0
	bfextu	a6@(-228:w){#10,#3},d1
	lsll	#2,d1
	swap	d1
	orl	d1,d0
	movel	d0,a6@(cmdreg3b)		//in the busy frame
ADR_409c064:
	cmpb	#0x28,sp@(1:w)
	bne	ADR_409c078:l
	moveq	#13,d0
	bra	ADR_409c086:l
ADR_409c078:
	cmpb	#0x30,sp@(1:w)
	bne	ADR_409c0cc:l
	moveq	#11,d0
ADR_409c086:
	moveb	sp@,a6@(-69:w)
	clrl	sp@
ADR_409c08c:
	clrl	sp@-
	dbf	d0,ADR_409c08c
	lea	sp@(292:w),a1
	moveb	a6@(-69:w),sp@
	moveb	#0x60:b,sp@(1:w)
	movel	a6@(-116:w),a1@(-268:w)
	movel	a6@(-112:w),a1@(-264:w)
	movel	a6@(-108:w),a1@(-260:w)
	bfextu	a6@(-124:w){#17,#4},d0
	bfins	d0,a1@(-235:w){#4,#4}
	movel	a6@(-124:w),a1@(-256:w)
	orl	#0x1800000,a1@(-220:w)
ADR_409c0cc:
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(user_fpcr),fpcr/fpsr/fpi
	frestore	a7@+
	unlk		a6
//
// If trace mode enabled, then go to trace handler.  This handler 
// cannot have any fp instructions.  If there are fp inst's and an 
// exception has been restored into the machine then the exception 
// will occur upon execution of the fp inst.  This is not desirable 
// in the kernel (supervisor mode).  See MC68040 manual Section 9.3.8.
//
// finish_up:
ADR_409c0e2:
	btst	#7,a7@		//test t1 in sr
	bne	ADR_409c0fc
	btst	#6,a7@		//test t0 in sr
	bne	ADR_409c0fc
	.word	0x60ff
	.word	0xfff6
	.word	0x6126
ADR_409c0fc:
	bftst	sp@(6:w){#0,#4}
	bne	ADR_409c126			// no, we're done
	subqw	#0x4,sp
	movel	a7@(4),a7@			// shift saved d0 up one
	movel	a7@(8),a7@(4)			// shift sr and hi pc
	subaw	#0x64:w,sp
	fsave	sp@
	fmoveml	fpi,sp@(108:w)
	frestore	sp@
	addaw	#0x64:w,sp
ADR_409c126:
	movew	#trace_vec,a7@(exc_vec-4)
	bra	real_trace
//
//	get_op.sa 1.21 10/8/90
//
//  Description: This routine is called by the unsupported format/data
// type exception handler ('unsupp' - vector 55) and the unimplemented
// instruction exception handler ('unimp' - vector 11).  'get_op'
// determines the opclass (0, 2, or 3) and branches to the
// opclass handler routine.  See 68881/2 User's Manual table 4-11
// for a description of the opclasses.
//
// For UNSUPPORTED data/format (exception vector 55) and for
// UNIMPLEMENTED instructions (exception vector 11) the following
// applies:
//
// - For unnormormalized numbers (opclass 0, 2, or 3) the
// number(s) is normalized and the operand type tag is updated.
//		
// - For a packed number (opclass 2) the number is unpacked and the
// operand type tag is updated.
//
// - For denormalized numbers (opclass 0 or 2) the number(s) is not
// changed but passed to the next module.  The next module for
// unimp is do_func, the next module for unsupp is res_func.
//
// For UNSUPPORTED data/format (exception vector 55) only the
// following applies:
//
// - If there is a move out with a packed number (opclass 3) the
// number is packed and written to user memory.  For the other
// opclasses the number(s) are written back to the fsave stack
// and the instruction is then restored back into the '040.  The
// '040 is then able to complete the instruction.
//
// For example:
// fadd.x fpm,fpn where the fpm contains an unnormalized number.
// The '040 takes an unsupported data trap and gets to this
// routine.  The number is normalized, put back on the stack and
// then an frestore is done to restore the instruction back into
// the '040.  The '040 then re-executes the fadd.x fpm,fpn with
// a normalized number in the source and the instruction is
// successful.
//		
// Next consider if in the process of normalizing the un-
// normalized number it becomes a denormalized number.  The
// routine which converts the unnorm to a norm (called mk_norm)
// detects this and tags the number as a denorm.  The routine
// res_func sees the denorm tag and converts the denorm to a
// norm.  The instruction is then restored back into the '040
// which re_executess the instruction.
//
//
//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



	

// pirn:
	.globl	pirn
pirn:
	.int 0x40000000,0xc90fdaa2,0x2168c235    //pi
// pirzrm:
	.globl	pirzrm
pirzrm:
	.int 0x40000000,0xc90fdaa2,0x2168c234    //pi
// pirp:
	.globl	pirp
pirp:
	.int 0x40000000,0xc90fdaa2,0x2168c235    //pi

//round to nearest
// smalrn:
	.globl	smalrn
smalrn:
	.int 0x3ffd0000,0x9a209a84,0xfbcff798    //log10(2)
	.int 0x40000000,0xadf85458,0xa2bb4a9a    //e
	.int 0x3fff0000,0xb8aa3b29,0x5c17f0bc    //log2(e)
	.int 0x3ffd0000,0xde5bd8a9,0x37287195    //log10(e)
	.int 0x00000000,0x00000000,0x00000000    //00
// round to zero;round to negative infinity
// smalrzrm:
	.globl	smalrzrm
smalrzrm:
	.int 0x3ffd0000,0x9a209a84,0xfbcff798    //log10(2)
	.int 0x40000000,0xadf85458,0xa2bb4a9a    //e
	.int 0x3fff0000,0xb8aa3b29,0x5c17f0bb    //log2(e)
	.int 0x3ffd0000,0xde5bd8a9,0x37287195    //log10(e)
	.int 0x00000000,0x00000000,0x00000000    //00
// round to positive infinity
// smalrp:
	.globl	smalrp
smalrp:
	.int 0x3ffd0000,0x9a209a84,0xfbcff799    //log10(2)
	.int 0x40000000,0xadf85458,0xa2bb4a9b    //e
	.int 0x3fff0000,0xb8aa3b29,0x5c17f0bc    //log2(e)
	.int 0x3ffd0000,0xde5bd8a9,0x37287195    //log10(e)
	.int 0x00000000,0x00000000,0x00000000    //00

//round to nearest
// bigrn:
	.globl	bigrn
bigrn:
	.int 0x3ffe0000,0xb17217f7,0xd1cf79ac    //ln(2)
	.int 0x40000000,0x935d8ddd,0xaaa8ac17    //ln(10)
	.int 0x3fff0000,0x80000000,0x00000000    //10 ^ 0

// ptenrn:
	.globl	ptenrn
ptenrn:
	.int 0x40020000,0xa0000000,0x00000000    //10 ^ 1
	.int 0x40050000,0xc8000000,0x00000000    //10 ^ 2
	.int 0x400c0000,0x9c400000,0x00000000    //10 ^ 4
	.int 0x40190000,0xbebc2000,0x00000000    //10 ^ 8
	.int 0x40340000,0x8e1bc9bf,0x04000000    //10 ^ 16
	.int 0x40690000,0x9dc5ada8,0x2b70b59e    //10 ^ 32
	.int 0x40d30000,0xc2781f49,0xffcfa6d5    //10 ^ 64
	.int 0x41a80000,0x93ba47c9,0x80e98ce0    //10 ^ 128
	.int 0x43510000,0xaa7eebfb,0x9df9de8e    //10 ^ 256
	.int 0x46a30000,0xe319a0ae,0xa60e91c7    //10 ^ 512
	.int 0x4d480000,0xc9767586,0x81750c17    //10 ^ 1024
	.int 0x5a920000,0x9e8b3b5d,0xc53d5de5    //10 ^ 2048
	.int 0x75250000,0xc4605202,0x8a20979b    //10 ^ 4096
//round to minus infinity
// bigrzrm:
	.globl	bigrzrm
bigrzrm:
	.int 0x3ffe0000,0xb17217f7,0xd1cf79ab    //ln(2)
	.int 0x40000000,0x935d8ddd,0xaaa8ac16    //ln(10)
	.int 0x3fff0000,0x80000000,0x00000000    //10 ^ 0

// ptenrm:
	.globl	ptenrm
ptenrm:
	.int 0x40020000,0xa0000000,0x00000000    //10 ^ 1
	.int 0x40050000,0xc8000000,0x00000000    //10 ^ 2
	.int 0x400c0000,0x9c400000,0x00000000    //10 ^ 4
	.int 0x40190000,0xbebc2000,0x00000000    //10 ^ 8
	.int 0x40340000,0x8e1bc9bf,0x04000000    //10 ^ 16
	.int 0x40690000,0x9dc5ada8,0x2b70b59d    //10 ^ 32
	.int 0x40d30000,0xc2781f49,0xffcfa6d5    //10 ^ 64
	.int 0x41a80000,0x93ba47c9,0x80e98cdf    //10 ^ 128
	.int 0x43510000,0xaa7eebfb,0x9df9de8d    //10 ^ 256
	.int 0x46a30000,0xe319a0ae,0xa60e91c6    //10 ^ 512
	.int 0x4d480000,0xc9767586,0x81750c17    //10 ^ 1024
	.int 0x5a920000,0x9e8b3b5d,0xc53d5de5    //10 ^ 2048
	.int 0x75250000,0xc4605202,0x8a20979a    //10 ^ 4096
//round to positive infinity
// bigrp:
	.globl	bigrp
bigrp:
	.int 0x3ffe0000,0xb17217f7,0xd1cf79ac    //ln(2)
	.int 0x40000000,0x935d8ddd,0xaaa8ac17    //ln(10)
	.int 0x3fff0000,0x80000000,0x00000000    //10 ^ 0

// ptenrp:
	.globl	ptenrp
ptenrp:
	.int 0x40020000,0xa0000000,0x00000000    //10 ^ 1
	.int 0x40050000,0xc8000000,0x00000000    //10 ^ 2
	.int 0x400c0000,0x9c400000,0x00000000    //10 ^ 4
	.int 0x40190000,0xbebc2000,0x00000000    //10 ^ 8
	.int 0x40340000,0x8e1bc9bf,0x04000000    //10 ^ 16
	.int 0x40690000,0x9dc5ada8,0x2b70b59e    //10 ^ 32
	.int 0x40d30000,0xc2781f49,0xffcfa6d6    //10 ^ 64
	.int 0x41a80000,0x93ba47c9,0x80e98ce0    //10 ^ 128
	.int 0x43510000,0xaa7eebfb,0x9df9de8e    //10 ^ 256
	.int 0x46a30000,0xe319a0ae,0xa60e91c7    //10 ^ 512
	.int 0x4d480000,0xc9767586,0x81750c18    //10 ^ 1024
	.int 0x5a920000,0x9e8b3b5d,0xc53d5de6    //10 ^ 2048
	.int 0x75250000,0xc4605202,0x8a20979b    //10 ^ 4096
	.globl	get_op
get_op:
	clrb	a6@(-72:w)

	
	
	
	

// get_op:
//
//	Temporary D43B fix for unimp frame stacked as a busy frame.
//	Check bits in the flag UFLG_TMP, used in place of UFLAG on 
//	the fsave stack, for the calling state.
//
	tstb	a6@(uflg_tmp)	//test flag for unsupp/unimp state
	beq	uni_getop
//
//	Uncomment the following 2 lines after the d43b errata is
//	fixed.
//
//	btst.b	#UFLAG,T_BYTE(a6)
//	bne.b	uni_getop

// uns_getop:
	.globl	uns_getop
uns_getop:
	btst	#direction_bit,a6@(cmdreg1b)
	bne	ADR_409c5fe	//branch if a fmove out (any kind)
	btst	#6,a6@(-228:w)
	beq	ADR_409c480:l

	bfextu	a6@(cmdreg1b){#3:#3},d0
	cmpb	#3,d0
	beq	ADR_409c594	//check for a packed src op, branch if so

ADR_409c480:
	bsr	ADR_409c614	//set the dyadic/monadic flag
	tstb	a6@(dy_mo_flg)
	beq	ADR_409c50c	//if monadic, go check src op
//				;else, check dst op (fall through)

	btst	#7,a6@(dtag)
	beq	ADR_409c50c	//if dst op is norm, check src op
	bra	ADR_409c4ee	//else, handle destination unnorm/dnrm

// uni_getop:
	.globl	uni_getop
uni_getop:
	bfextu	a6@(cmdreg1b){#0:#6},d0 //get source format
	cmpil	#0x17,d0		//if op class and size fields are 0x17, 
	bne	ADR_409c4b6:l
	rts

ADR_409c4b6:
	btst	#e1,a6@(e_byte)	//if set, there is a packed operand
	bne	ADR_409c594	//check for packed src op, branch if so

// The following lines of are coded to optimize on normalized operands
	moveb	a6@(stag),d0
	orb	a6@(dtag),d0	//check if either of stag/dtag msb set
	bmi	ADR_409c4d2	//if so,
//				;there is an unsupported data type.
	rts			//end_getop //if neither source or destination are 
//				;any of the unsupported data types

// dest_op_ck:
ADR_409c4d2:
	btst	#7,a6@(dtag)	//check if there are unsupported data types in
	beq	ADR_409c50c	//the destination, if not, check src op

	bsr	ADR_409c614	//set dyadic/monadic flag
	tstb	a6@(dy_mo_flg)	//
	beq	ADR_409c50c	//if monadic, no need to fix destination operand
//				;go ahead and check src op
//
// at this point, destination has an extended denorm or unnorm
// dst_ex_dnrm:
ADR_409c4ee:
	movew	a6@(fptemp_ex),d0 //get destination exponent
	andiw	#0x7fff,d0	//mask sign, check if exp = 0000
	beq	ADR_409c50c	//if denorm then go check source op, denorms 
//				;are taken care of in res_func 
//				;(unsupp) or do_func (unimp)
//				;else unnorm fall through
	lea	a6@(fptemp),a0	//point a0 to dop - used in mk_norm
	bsr	ADR_409c646		//go normalize - mk_norm returns:
//				;L_SCR1{7:5} = operand tag 
//				;	(000 = norm, 100 = denorm)
//				;L_SCR1{4} = fpte15 or ete15 
//				;	0 = exp >  $3fff
//				;	1 = exp <= $3fff
//				;and puts the normalized num back 
//				;on the fsave stack
//
	moveb a6@(l_scr1),a6@(dtag) //write the new tag & fpte15 
//				;to the fsave stack and fall 
//				;through to check source operand
//
// src_op_ck:
ADR_409c50c:
	btst	#7,a6@(stag)
	beq	ADR_409c612	//check for unsupported data types on the
//				;source operand
	btst	#5,a6@(stag)
	bne	ADR_409c544	//if bit 5 set, handle single/double denorms
//
// At this point only unnorms or extended denorms possible
// src_ex_dnrm:
ADR_409c524:
	movew	a6@(etemp_ex),d0 //get source exponent
	andiw	#0x7fff,d0	//mask sign, check if exp = 0000
	beq	ADR_409c612	//if denorm then exit, denorms are handled in
//				;do_func
	lea	a6@(etemp),a0	//point a0 to sop - used in mk_norm
	bsr	ADR_409c646		//go normalize - mk_norm returns:
//				;L_SCR1{7:5} = operand tag 
//				;	(000 = norm, 100 = denorm)
//				;L_SCR1{4} = fpte15 or ete15 
//				;	0 = exp >  $3fff
//				;	1 = exp <= $3fff
//				;and puts the normalized num back 
//				;on the fsave stack
//
	moveb	a6@(l_scr1),a6@(stag) //write the new tag & ete15 
	rts			//end_getop

	
// src_sd_dnrm:
ADR_409c544:
	btst	#4,a6@(cmdreg1b)	//differentiate between sgl/dbl denorm
	bne	ADR_409c55a
// is_single:
	movew	#0x3f81,d1	//write bias for sgl denorm
	bra	ADR_409c55e		//goto the common code
// is_double:
ADR_409c55a:
	movew	#0x3c01,d1	//write the bias for a dbl denorm
// common:
ADR_409c55e:
	btst	#sign_bit,a6@(etemp_ex) //grab sign bit of mantissa
	beq	ADR_409c56e	
	bset	#15,d1		//set sign bit because it is negative
// pos:
ADR_409c56e:
	movew	d1,a6@(etemp_ex)
//				;put exponent on stack

	movew	a6@(cmdreg1b),d1
	andw	#0xe3ff,d1	//clear out source specifier
	orw	#0x0800,d1	//set source specifier to extended prec
	movew	d1,a6@(cmdreg1b)	//write back to the command word in stack
//				;this is needed to fix unsupp data stack

	lea	a6@(etemp),a0	//point a0 to sop - used in mk_norm
	bsr	ADR_409c646		//convert sgl/dbl denorm to norm
	moveb	a6@(l_scr1),a6@(stag) //put tag into source tag reg - d0
	rts			//end_getop

	
	
//
// at this point, the source is definitely packed, whether instruction is 
// dyadic or monadic is still unknown
// pack_source:
ADR_409c594:
	movel	a6@(fptemp_lo),a6@(etemp)	//write ms part of packed number 
	bsr	ADR_409c614:l
	bsr	ADR_409c714:l
	tstb	a6@(dy_mo_flg)
	beq	ADR_409c612	//if monadic, exit
//				;else, fix FPTEMP
// pack_dya:
	bfextu	a6@(cmdreg1b){#6:#3},d0 //extract dest fp reg
	movel	#7,d1
	subl	d0,d1
	clrl	d0
	bset	d1,d0		//set up d0 as a dynamic register mask
	fmovemx d0,a6@(fptemp)	//write to fptemp

	btst	#7,a6@(dtag)	//check destination tag for unnorm or denorm
	bne	ADR_409c4ee:l
	moveb	a6@(-224:w),d0
	andb	#0xf0,d0
	tstb	d0
	bne	ADR_409c612:l
	movew	a6@(-216:w),d0
	andw	#0x7fff,d0
	cmpw	#0x3fff,d0
	bge	ADR_409c612:l
	orb	#0x10,a6@(-224:w)
	bra	ADR_409c612:l

//
// At this point, it is either an fmoveout packed, unnorm or denorm
//
// opclass3:
ADR_409c5fe:
	clrb	a6@(dy_mo_flg)	//set dyadic/monadic flag to monadic
	bfextu	a6@(cmdreg1b){#4:#2},d0
	cmpib	#3,d0
	bne	ADR_409c524	//if not equal, must be unnorm or denorm
//				;else it is a packed move out
//				;exit
// end_getop:
ADR_409c612:
	rts

//
// sets the DY_MO_FLG correctly. This is used only on if it is an
// unuspported data type exception.
//
// chk_dy_mo:
ADR_409c614:
	movew	a6@(cmdreg1b),d0	
	btst	#5,d0		//testing extension command word
	beq	ADR_409c640		//if bit 5 = 0 then monadic
	btst	#4,d0		//know that bit 5 = 1
	beq	ADR_409c63a		//if bit 4 = 0 then dyadic
	andiw	#0x007f,d0	//get rid of all but extension bits {#6:#0}
	cmpiw 	#0x0038,d0	//if extension = 0x38 then fcmp (dyadic)
	bne	ADR_409c640
// set_dya:
ADR_409c63a:
	st	a6@(dy_mo_flg)	//set the inst flag type to dyadic
	rts
// set_mon:
ADR_409c640:
	clrb	a6@(dy_mo_flg)	//set the inst flag type to monadic
	rts
//
//	MK_NORM
//
// Normalizes unnormalized numbers, sets tag to norm or denorm, sets unfl
// exception if denorm.
//
// CASE opclass 0x0 unsupp
//	mk_norm till msb set
//	set tag = norm
//
// CASE opclass 0x0 unimp
//	mk_norm till msb set or exp = 0
//	if integer bit = 0
//	   tag = denorm
//	else
//	   tag = norm
//
// CASE opclass 011 unsupp
//	mk_norm till msb set or exp = 0
//	if integer bit = 0
//	   tag = denorm
//	   set unfl_nmcexe = 1
//	else
//	   tag = norm
//
// if exp <= $3fff
//   set ete15 or fpte15 = 1
// else set ete15 or fpte15 = 0

// input:
//	a0 = points to operand to be normalized
// output:
//	L_SCR1{7:5} = operand tag (000 = norm, 100 = denorm)
//	L_SCR1{4}   = fpte15 or ete15 (0 = exp > $3fff, 1 = exp <=$3fff)
//	the normalized operand is placed back on the fsave stack
// mk_norm:	
ADR_409c646:
	clrl	a6@(l_scr1)
	bclr	#sign_bit,a0@(local_ex)
	sne	a0@(local_sgn)	//transform into internal extended format

	cmpib	#0x2c,a6@(1+exc_vec) //check if unimp
	bne	ADR_409c66c	//branch if unsupp
	bsr	ADR_409c6f2	//call if unimp (opclass 0x0)
	bra	ADR_409c68a
// uns_data:
ADR_409c66c:
	btst	#direction_bit,a6@(cmdreg1b) //check transfer direction
	bne	ADR_409c684		//branch if set (opclass 011)
	bsr	ADR_409c6d0		//call if opclass 0x0
	bra	ADR_409c68a
// bit_set:
ADR_409c684:
	bsr	ADR_409c6b0		//opclass 011
// reload:
ADR_409c68a:
	cmpw	#0x3fff,a0@(local_ex) //if exp > 0x3fff
	bgt	ADR_409c69c		//   fpte15/ete15 already set to 0
	bset	#4,a6@(l_scr1)	//else set fpte15/ete15 to 1
//				;calling routine actually sets the 
//				;value on the stack (along with the 
//				;tag), since this routine doesn't 
//				;know if it should set ete15 or fpte15
//				;ie, it doesn't know if this is the 
//				;src op or dest op.
// end_mk:
ADR_409c69c:
	bfclr	a0@(local_sgn){#0:#8}
	beq	ADR_409c6ae
	bset	#sign_bit,a0@(local_ex) //convert back to ieee format
// end_mk_pos:
ADR_409c6ae:
	rts
//
//     CASE opclass 011 unsupp
//
// uns_op3:
ADR_409c6b0:
	bsr	nrm_zero	//normalize till msb = 1 or exp = zero
	btst	#7,a0@(local_hi)	//if msb = 1
	bne	ADR_409c6ce		//then branch
// set_unfl:
	orw	#dnrm_tag,a6@(l_scr1) //set denorm tag
	bset	#unfl_bit,a6@(fpsr_except) //set unfl exception bit
// no_unfl:
ADR_409c6ce:
	rts
ADR_409c6d0:
	bsr	nrm_zero:l
	btst	#7,a0@(4:w)
	beq	ADR_409c6ea:l
	orb	#0x0,a6@(-84:w)
	rts
ADR_409c6ea:
	orb	#0x80,a6@(-84:w)
	rts
//
//     CASE opclass 0x0 unimp
//
// uni_inst:
ADR_409c6f2:
	bsr	nrm_zero
	btst	#7,a0@(local_hi)	//check if integer bit (j-bit) is set 
	beq	ADR_409c70c		//if clear then now have a denorm
	orb	#0x0,a6@(-84:w)
	rts
ADR_409c70c:
	orb	#0x80,a6@(-84:w)
	rts
ADR_409c714:
	movew	a6@(-228:w),d0
	andw	#0x3b,d0
	beq	ADR_409c7ee:l
	movew	a6@(-204:w),d0
	bfextu	d0{#20,#12},d1
	cmpw	#0xfff,d1
	bne	ADR_409c776:l
	bfextu	d0{#17,#3},d1
	cmpw	#0x7,d1
	bne	ADR_409c776:l
	tstl	a6@(-200:w)
	bne	ADR_409c75c:l
	tstl	a6@(-196:w)
	bne	ADR_409c75c:l
	bra	ADR_409c908:l
ADR_409c75c:
	btst	#6,a6@(-200:w)
	bne	ADR_409c908:l
	orl	#0x1004080,a6@(-124:w)
	bra	ADR_409c908:l
ADR_409c776:
	movew	a6@(-202:w),d0
	andw	#0xf,d0
	tstw	d0
	bne	ADR_409c7cc:l
	tstl	a6@(-200:w)
	bne	ADR_409c7cc:l
	tstl	a6@(-196:w)
	bne	ADR_409c7cc:l
	tstl	a6@(-204:w)
	bge	ADR_409c7ba:l
	movel	#0x80000000:l,a6@(-204:w)
	clrl	a6@(-200:w)
	clrl	a6@(-196:w)
	bra	ADR_409c908:l
ADR_409c7ba:
	clrl	a6@(-204:w)
	clrl	a6@(-200:w)
	clrl	a6@(-196:w)
	bra	ADR_409c908:l
ADR_409c7cc:
	.word	0xf227
	.word	0xe001
	bsr	decbin:l
	fmovex	fp0,a6@(-204:w)
	.word	0xf21f
	.word	0xd080
	fmoveml	#0x0:l,fps
	bra	ADR_409c908:l

//
//	Decimal to binary conversion
//
// Special cases of inf and NaNs are completed outside of decbin.  
// input:
//	ETEMP(a6)	- points to packed decimal string in memory
// output:
//	fp0	- contains packed string converted to extended precision
//	ETEMP	- same as fp0
// unpack:
ADR_409c7ee:
	movew	a6@(etemp),d0	//get word with inf information
	bfextu	d0{#20:#12},d1	//get exponent into d1
	cmpiw	#0x0fff,d1	//test for inf or nan
	bne	ADR_409c88e	//if not equal, it is not special
	bfextu	d0{#17:#3},d1	//get se and y bits into d1
	cmpiw	#7,d1		//se and y bits must be on for special
	bne	ADR_409c88e	//if not on, it is not special
//input is of the special cases of inf and NaN
	tstl	a6@(etemp_hi)	//check ms mantissa
	bne	ADR_409c842		//if non-zero, it is a nan
	tstl	a6@(etemp_lo)	//check ls mantissa
	bne	ADR_409c842		//if non-zero, it is a nan
//input is inf
	orl	#inf_mask,a6@(user_fpsr) //set i bit
	tstl	a6@(etemp)	//check sign
	bge	ADR_409c908:l
	orl	#neg_mask,a6@(user_fpsr) //set n bit
// i_sign:
	bra	ADR_409c908		//special already on stack
// fix_nan:
ADR_409c842:
	orl	#nan_mask,a6@(user_fpsr) //set nan bit
	moveb	#0x60:b,a6@(-232:w)
	btst	#6,a6@(-200:w)
	bne	ADR_409c876		//if clear, it is an snan
	orl	#snaniop_mask,a6@(user_fpsr) //set snan bit
	btst	#6,a6@(-126:w)
	bne	ADR_409c876:l
	bset	#6,a6@(-200:w)
// n_snan:
ADR_409c876:
	tstl	a6@(etemp)	//check for sign
	bge	ADR_409c908		//if clr, go on
	orl	#neg_mask,a6@(user_fpsr) //set n bit
//				;put the unpacked sop in the fsave stack
	bra	ADR_409c908

// try_zero:
ADR_409c88e:
	movew	a6@(etemp_ex+2),d0 //get word 4
	andiw	#0x000f,d0	//clear all but last ni(y)bble
	tstw	d0		//check for zero
	bne	ADR_409c8f4:l
	tstl	a6@(etemp_hi)	//check words 3 and 2
	bne	ADR_409c8f4:l
	tstl	a6@(etemp_lo)	//check words 1 and 0
	bne	ADR_409c8f4:l
	tstl	a6@(etemp)	//test sign of the zero
	bge	ADR_409c8da
	orl	#0xc000000,a6@(-124:w)
	movel	#0x80000000,a6@(etemp) //write neg zero to etemp
	clrl	a6@(-200:w)
	clrl	a6@(-196:w)
	bra	ADR_409c908:l
// fin_zero:
ADR_409c8da:
	orl	#z_mask,a6@(user_fpsr) //set z
	clrl	a6@(-204:w)
	clrl	a6@(etemp_hi)
	clrl	a6@(etemp_lo)
	bra	ADR_409c908:l
ADR_409c8f4:
	.word	0xf227
	.word	0xe001
	bsr	decbin:l
	fmovex	fp0,a6@(-204:w)
	.word	0xf21f
	.word	0xd080
// finish:
ADR_409c908:
	movew	a6@(cmdreg1b),d0	//get the command word
	andw	#0xfbff,d0	//change the source specifier field to 
//				;extended (was packed).
	movew	d0,a6@(cmdreg1b)	//write command word back to fsave stack
//				;we need to do this so the 040 will 
//				;re-execute the inst. without taking 
//				;another packed trap.

// fix_stag:
//Converted result is now in etemp on fsave stack, now set the source 
//tag (stag) 
//	if (ete =$7fff) then INF or NAN
//		if (etemp = $x.0----0) then
//			stag = INF
//		else
//			stag = NAN
//	else
//		if (ete = $0000) then
//			stag = ZERO
//		else
//			stag = NORM
//
// Note also that the etemp_15 bit (just right of the stag) must
// be set accordingly.  
//
	movew		a6@(etemp_ex),d1
	andiw		#0x7fff,d1   //strip sign
	cmpw  		#0x7fff,d1
	bne  		ADR_409c94e
	movel		a6@(etemp_hi),d1
	bne		ADR_409c944
	movel		a6@(etemp_lo),d1
	bne		ADR_409c944
// is_inf:
	moveb		#0x40,a6@(stag)
	movel		#0x40,d0
	rts
// is_nan:
ADR_409c944:
	moveb		#0x60,a6@(stag)
	movel		#0x60,d0
	rts
// z_or_nrm:
ADR_409c94e:
	tstw		d1  
	bne		ADR_409c960
// is_zro:
// For a zero, set etemp_15
	moveb		#0x30,a6@(stag)
	movel		#0x20,d0
	rts
// is_nrm:
// For a norm, check if the exp <= $3fff; if so, set etemp_15
ADR_409c960:
	cmpiw		#0x3fff,d1
	ble		ADR_409c976
	moveb		#0,a6@(stag)
	bra		ADR_409c97c
// set_bit15:
ADR_409c976:
	moveb		#0x10,a6@(stag)
// end_is_nrm:
ADR_409c97c:
	movel		#0,d0
// end_fix:
	rts
 
// end_get:
	rts
//
//	kernel_ex.sa 1.20 10/4/90 
//
// This file contains routines to force exception status in the 
// fpu for exceptional cases detected or reported within the
// transcendental functions.  Typically, the t_xx routine will
// set the appropriate bits in the USER_FPSR word on the stack.
// The bits are tested in unimp.sa to determine if an exceptional
// situation needs to be created on return from the FPSP. 
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



ADR_409c982:
   .int 0xffff0000,0x00000000,0x00000000
ADR_409c98e:
   .int 0x7fff0000,0x00000000,0x00000000
ADR_409c99a:
       .int 0x7fff0000,0xffffffff,0xffffffff
      .int 0x7ffe0000,0xffffffff,0xffffffff


	

	
	
	

//
//	DZ exception
//
//
//	if dz trap disabled
//		store properly signed inf (use sign of etemp) into fp0
//		set FPSR exception status dz bit, condition code 
//		inf bit, and accrued dz bit
//		return
//		frestore the frame into the machine (done by unimp_hd)
//
//	else dz trap enabled
//		set exception status bit & accrued bits in FPSR
//		set flag to disable sto_res from corrupting fp register
//		return
//		frestore the frame into the machine (done by unimp_hd)
//
// t_dz2 is used by monadic functions such as flogn (from do_func).
// t_dz is used by monadic functions such as satanh (from the 
// transcendental function).
//
// t_dz2:
	.globl	t_dz2
t_dz2:
	bset	#neg_bit,a6@(fpsr_cc)	//set neg bit in fpsr
	fmovel	#0,fpsr			//clr status bits (z set)
	btst	#dz_bit,a6@(fpcr_enable)	//test fpcr for dz exc enabled
	bne	ADR_409ca2a
	bra	ADR_409c9f2			//flogx always returns -inf
// t_dz:
	.globl	t_dz
t_dz:
	fmovel	#0,fpsr			//clr status bits (z set)
	btst	#dz_bit,a6@(fpcr_enable)	//test fpcr for dz exc enabled
	bne	ADR_409ca18
//
//	dz disabled
//
	btst	#sign_bit,a6@(etemp_ex)	//check sign for neg or pos
	beq	ADR_409ca06			//branch if pos sign

// m_inf:
ADR_409c9f2:
	fmovemx ADR_409c982,fp0-fp0		//load -inf
	bset	#neg_bit,a6@(fpsr_cc)	//set neg bit in fpsr
	bra	ADR_409ca0e
// p_inf:
ADR_409ca06:
	fmovemx ADR_409c98e,fp0-fp0		//load +inf
// set_fpsr:
ADR_409ca0e:
	orl	#dzinf_mask,a6@(user_fpsr) //set i,dz,adz
	rts
//
//	dz enabled
//
// dz_ena:
ADR_409ca18:
	btst	#sign_bit,a6@(etemp_ex)	//check sign for neg or pos
	beq	ADR_409ca2a
	bset	#neg_bit,a6@(fpsr_cc)	//set neg bit in fpsr
// dz_ena_end:
ADR_409ca2a:
	orl	#dzinf_mask,a6@(user_fpsr) //set i,dz,adz
	st	a6@(store_flg)
	rts
//
//	OPERR exception
//
//	if (operr trap disabled)
//		set FPSR exception status operr bit, condition code 
//		nan bit; Store default NAN into fp0
//		frestore the frame into the machine (done by unimp_hd)
//	
//	else (operr trap enabled)
//		set FPSR exception status operr bit, accrued operr bit
//		set flag to disable sto_res from corrupting fp register
//		frestore the frame into the machine (done by unimp_hd)
//
// t_operr:
	.globl	t_operr
t_operr:
	orl	#opnan_mask,a6@(user_fpsr) //set nan, operr, aiop

	btst	#operr_bit,a6@(fpcr_enable) //test fpcr for operr enabled
	bne	ADR_409ca56

	fmovemx ADR_409c99a,fp0-fp0		//load default nan
	rts
// op_ena:
ADR_409ca56:
	st	a6@(store_flg)		//do not corrupt destination
	rts
	.globl	t_unfl
t_unfl:
	clrl	a6@(-116:w)
	clrl	a6@(-112:w)
	clrl	a6@(-108:w)
	tstb	a0@
	bpl	ADR_409ca76:l
	bset	#7,a6@(-116:w)
ADR_409ca76:
	lea	a6@(-116:w),a0
	orl	#0xa28,a6@(-124:w)
	btst	#3,a6@(-126:w)
	beq	ADR_409caa6:l

	bfclr	a6@(stag){#5:#3}		//clear wbtm66,wbtm1,wbtm0
	bset	#wbtemp15_bit,a6@(wb_byte) //set wbtemp15
	bset	#sticky_bit,a6@(sticky)	//set sticky bit

	bclr	#e1,a6@(e_byte)

// unfl_dis:
ADR_409caa6:
	bfextu	a6@(fpcr_mode){#0:#2},d0	//get round precision
	
	bclr	#sign_bit,a0@(local_ex)
	sne	a0@(local_sgn)		//convert to internal extended format

	bsr	unf_sub			//returns ieee result pointed by a0
//					;sets FPSR_CC accordingly
	
	bfclr	a0@(local_sgn){#0:#8}	//convert back to ieee extended format
	beq	ADR_409cad4

	bset	#sign_bit,a0@(local_ex)
	bset	#sign_bit,a6@(fp_scr1)	//set sign bit of exceptional operand

// unfpos:
ADR_409cad4:
	fmovemx a0@,fp0-fp0		//store result in fp0
	rts
	.globl	t_ovfl2
t_ovfl2:
	orl	#0x1048,a6@(-124:w)
	movel	a6@(-204:w),a6@(-116:w)
	movel	a6@(-200:w),a6@(-112:w)
	movel	a6@(-196:w),a6@(-108:w)
	moveb	a6@(-125:w),d0
	andb	#0xc0,d0
	beq	ADR_409cb52:l
	cmpb	#0x40,d0
	bne	ADR_409cb2c:l
	tstb	a6@(-196:w)
	bne	ADR_409cb3c:l
	movel	a6@(-200:w),d0
	andl	#0xff,d0
	bne	ADR_409cb3c:l
	bra	ADR_409cb52:l
ADR_409cb2c:
	movel	a6@(-196:w),d0
	andl	#0x7ff,d0
	beq	ADR_409cb52:l
ADR_409cb3c:
	orl	#0x200,a6@(-124:w)
	bra	ADR_409cb52:l
	.globl	t_ovfl
t_ovfl:
	orl	#0x1248,a6@(-124:w)
	

//
//	t_ovfl --- OVFL exception
//
//** Note: the exc operand is expected in fp_scr1,
// t_ovfl:
ADR_409cb52:
	btst	#ovfl_bit,a6@(fpcr_enable) //test fpcr for ovfl enabled
	beq	ADR_409cb82

// ovf_ena:
	clrl	a6@(fp_scr1)		//set exceptional operand
	clrl	a6@(fp_scr1+4)
	clrl	a6@(fp_scr1+8)

	bfclr	a6@(stag){#5:#3}		//clear wbtm66,wbtm1,wbtm0
	bclr	#wbtemp15_bit,a6@(wb_byte) //clear wbtemp15
	bset	#sticky_bit,a6@(sticky)	//set sticky bit

	bclr	#e1,a6@(e_byte)
//					;fall through to disabled case

// For disabled overflow call 'ovf_r_k'.
// This routine loads the correct result based on the
// rounding precision, destination format, rounding mode and sign.
//
// ovf_dis:
ADR_409cb82:
	bsr	ovf_r_k			//returns unsigned etemp_ex
//					;sets FPSR_CC accordingly
//					;need to ETEMP_SGN (ETS) into answer
	bfclr	a6@(etemp_sgn){#0:#8}
	beq	ADR_409cba0
	bset	#sign_bit,a6@(etemp_ex)
	bset	#sign_bit,a6@(fp_scr1)	//set exceptional operand sign
// ovf_pos:
ADR_409cba0:
	fmovemx a6@(etemp),fp0-fp0		//move the result to fp0
	rts


//
//	INEX2 exception
//
// The inex2 and ainex bits are set.
//
// t_inx2:
	.globl	t_inx2
t_inx2:
	orl	#inx2a_mask,a6@(user_fpsr) //set inex2, ainex
	rts

//
//	Force Inex2
//
// This routine is called by the transcendental routines to force
// the inex2 exception bits set in the FPSR.  If the underflow bit
// is set, but the underflow trap was not taken, the aunfl bit in
// the FPSR must be set.
//
// t_frcinx:
	.globl	t_frcinx
t_frcinx:
	orl	#inx2a_mask,a6@(user_fpsr) //set inex2, ainex
	btst	#unfl_bit,a6@(fpsr_except) //test for unfl bit set
	beq	ADR_409cbcc		//if clear, do not set aunfl
	bset	#aunfl_bit,a6@(fpsr_aexcept)
// no_uacc1:
ADR_409cbcc:
	rts

//
//	DST_NAN
//
// Determine if the destination nan is signalling or non-signalling,
// and set the FPSR bits accordingly.  See the MC68040 User's Manual 
// section 3.2.2.5 NOT-A-NUMBERS.
//
// dst_nan:
	.globl	dst_nan
dst_nan:
	btst	#sign_bit,a6@(fptemp_ex) //test sign of nan
	beq	ADR_409cbe0			//if clr, it was positive
	bset	#neg_bit,a6@(fpsr_cc)	//set n bit
// dst_pos:
ADR_409cbe0:
	btst	#signan_bit,a6@(fptemp_hi) //check if signalling 
	beq	ADR_409cc1e		//branch if signalling
	fmoveml	d1,fpc

	fmovex a6@(fptemp),fp0		//return the non-signalling nan
//
// Check the source nan.  If it is signalling, snan will be reported.
//
	moveb	a6@(stag),d0
	andib	#0xe0,d0
	cmpib	#0x60,d0
	bne	ADR_409cc1c
	btst	#signan_bit,a6@(etemp_hi) //check if signalling 
	bne	ADR_409cc1c
	orl	#snaniop_mask,a6@(user_fpsr) //set nan, snan, aiop
// no_snan:
ADR_409cc1c:
	rts	

// dst_snan:
ADR_409cc1e:
	btst	#snan_bit,a6@(fpcr_enable) //check if trap enabled 
	beq	ADR_409cc3e			//branch if disabled

	orb	#nan_tag,a6@(dtag)	//set up dtag for nan
	st	a6@(store_flg)		//do not store a result
	orl	#snaniop_mask,a6@(user_fpsr) //set nan, snan, aiop
	rts

// dst_dis:
ADR_409cc3e:
	bset	#signan_bit,a6@(fptemp_hi) //set snan bit in sop 
	fmoveml	d1,fpc
	fmovex a6@(fptemp),fp0		//load non-sign nan 
	orl	#snaniop_mask,a6@(user_fpsr) //set nan, snan, aiop
	rts

//
//	SRC_NAN
//
// Determine if the source nan is signalling or non-signalling,
// and set the FPSR bits accordingly.  See the MC68040 User's Manual 
// section 3.2.2.5 NOT-A-NUMBERS.
//
// src_nan:
	.globl	src_nan
src_nan:
	btst	#sign_bit,a6@(etemp_ex) //test sign of nan
	beq	ADR_409cc6a			//if clr, it was positive
	bset	#neg_bit,a6@(fpsr_cc)	//set n bit
// src_pos:
ADR_409cc6a:
	btst	#signan_bit,a6@(etemp_hi) //check if signalling 
	beq	ADR_409cc82		//branch if signalling
	fmoveml	d1,fpc
	fmovex a6@(etemp),fp0		//return the non-signalling nan
	rts	

// src_snan:
ADR_409cc82:
	btst	#snan_bit,a6@(fpcr_enable) //check if trap enabled 
	beq	ADR_409ccae			//branch if disabled
	bset	#signan_bit,a6@(etemp_hi) //set snan bit in sop 
	orb	#norm_tag,a6@(dtag)	//set up dtag for norm
	orb	#nan_tag,a6@(stag)	//set up stag for nan
	st	a6@(store_flg)		//do not store a result
	orl	#snaniop_mask,a6@(user_fpsr) //set nan, snan, aiop
	rts

// src_dis:
ADR_409ccae:
	bset	#signan_bit,a6@(etemp_hi) //set snan bit in sop 
	fmoveml	d1,fpc
	fmovex a6@(etemp),fp0		//load non-sign nan 
	orl	#snaniop_mask,a6@(user_fpsr) //set nan, snan, aiop
	rts
	.globl	t_extdnrm
t_extdnrm:
	orl	#0xa28,a6@(-124:w)
	bra	ADR_409ccde:l
	.globl	t_resdnrm
t_resdnrm:
	orl	#0x800,a6@(-124:w)

//
// For all functions that have a denormalized input and that f(x)=x,
// this is the entry point
//
// t_extdnrm:

ADR_409ccde:
	btst	#unfl_bit,a6@(fpcr_enable)
	beq	ADR_409cd4e

//
// If exceptions are enabled, the additional task of setting up WBTEMP
// is needed so that when the underflow exception handler is entered,
// the user perceives no difference between what the 040 provides vs.
// what the FPSP provides.
//
// xdnrm_ena:
	movel	a0,a7@-

	movel	a0@(local_ex),a6@(fp_scr1)
	movel	a0@(local_hi),a6@(fp_scr1+4)
	movel	a0@(local_lo),a6@(fp_scr1+8)

	lea	a6@(fp_scr1),a0

	bclr	#sign_bit,a0@(local_ex)
	sne	a0@(local_sgn)		//convert to internal extended format
	tstw	a0@(0:w)
	beq	ADR_409cd1c:l
	
	bsr	nrm_set			//normalize the result (exponent will be *					//negative
ADR_409cd1c:
	bclr	#sign_bit,a0@(local_ex)	//take off false sign

	bfclr	a0@(local_sgn){#0:#8}	//change back to ieee ext format
	beq	ADR_409cd34
	bset	#sign_bit,a0@(local_ex)
// xdep:	
ADR_409cd34:
	bfclr	a6@(stag){#5:#3}		//clear wbtm66,wbtm1,wbtm0
	bset	#wbtemp15_bit,a6@(wb_byte) //set wbtemp15
	bclr	#sticky_bit,a6@(sticky)	//clear sticky bit

	bclr	#e1,a6@(e_byte)
	
	movel	a7@+,a0

// xdnrm_dis:
ADR_409cd4e:
	bfextu	a6@(fpcr_mode){#0:#2},d0	//get round precision
	bne	ADR_409cd72			//if not round extended, store ieee
//					;defaults

// is_ext:
	btst	#sign_bit,a0@(local_ex)
	beq	ADR_409cd94

	bset	#neg_bit,a6@(fpsr_cc)	//set n bit in fpsr_cc

	bra	ADR_409cd94

// not_ext:
ADR_409cd72:
	bclr	#sign_bit,a0@(local_ex)
	sne	a0@(local_sgn)		//convert to internal extended format

	bsr	unf_sub			//returns ieee result pointed by a0
//					;sets FPSR_CC accordingly
	
	bfclr	a0@(local_sgn){#0:#8}	//convert back to ieee extended format
	beq	ADR_409cd94
	bset	#sign_bit,a0@(local_ex)

// xdnrm_store:
ADR_409cd94:
	fmovemx a0@,fp0-fp0		//store result in fp0
	rts

//
// This subroutine is used for dyadic operations that use an extended denorm
// within the kernel. The approach used is to capture the frame, fix/restore.
//
// t_avoid_unsupp:
	.globl	t_avoid_unsupp
t_avoid_unsupp:
	link	a2,#-local_size		//so that a2 fpsph negative offsets 
//					;may be used
	fsave	a7@-
	tstb	sp@(1:w)
	beq	ADR_409ce48
	btst	#e1,a2@(e_byte)		//check for an e1 exception if enabled,
//					;it means that there is an unsupp. trap
	beq	ADR_409ce42		//else, exit
	btst	#7,a2@(dtag)		//check for denorm destination
	beq	ADR_409ce00			//else, must be a source denorm

// handle destination denorm
	lea	a2@(fptemp),a0
	btst	#sign_bit,a0@(local_ex)
	sne	a0@(local_sgn)		//convert to internal extended format
	bclr	#7,a2@(dtag)		//set dtag to norm
	bsr	nrm_set			//normalize result, exponent will become
//					;negative
	bclr	#sign_bit,a0@(local_ex)	//get rid of fake sign

	bfclr	a0@(local_sgn){#0:#8}	//convert back to ieee extended format
	beq	ADR_409cdf4		//check if source is also a denorm
	bset	#sign_bit,a0@(local_ex)

// ck_src_den:
ADR_409cdf4:
	btst	#7,a2@(stag)
	beq	ADR_409ce42
// src_den:
ADR_409ce00:
	lea	a2@(etemp),a0
	btst	#sign_bit,a0@(local_ex)
	sne	a0@(local_sgn)		//convert to internal extended format
	bclr	#7,a2@(stag)		//set stag to norm
	bsr	nrm_set			//normalize result, exponent will become
//					;negative
	bclr	#sign_bit,a0@(local_ex)	//get rid of fake sign

	bfclr	a0@(local_sgn){#0:#8}	//convert back to ieee extended format
	beq	ADR_409ce32
	bset	#sign_bit,a0@(local_ex)
// den_com:
ADR_409ce32:
	moveb	#0xfe,a2@(cu_savepc)	//set continue frame
	clrw	a2@(nmnexc)		//clear nmnexc
	bclr	#e1,a2@(e_byte)
// end_avun:
ADR_409ce42:
	frestore a7@+
	unlk	a2
	rts
// idle_end:
ADR_409ce48:
	addl	#4,a7
	unlk	a2
	rts
ADR_409ce4e:
	.word	0x41df
	.word	0xffff
	.word	0xffc0
	.word	0x0000
ADR_409ce56:
	.word	0xc1e0
	.word	0x0000
	.word	0x0000
	.word	0x0000
ADR_409ce5e:
	.word	0x41df
	.word	0xffff
	.word	0xffe0
	.word	0x0000
ADR_409ce66:
	.word	0xc1e0
	orb	#0x10,d0
	.word	0x0000
ADR_409ce6e:
	.word	0x3f81
	.word	0x407e
	.word	0x3f6a
	.word	0x0000
ADR_409ce76:
	.word	0x3c01
	.word	0x43fe
//
//	res_func.sa 1.20 10/8/90
//
// Normalizes denormalized numbers if necessary and updates the
// stack frame.  The function is then restored back into the
// machine and the 040 completes the operation.  This routine
// is only used by the unsupported data type/format handler.
// (Exception vector 55).
//
// For packed move out (fmove.p fpm,<ea>) the operation is
// completed here; data is packed and moved to user memory. 
// The stack is restored to the 040 only in the case of a
// reportable exception in the conversion.
//
//
//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.


		.word	0x3bcd,0x0000

	
	
	
	
	
	
	
	
	
	
	


// res_func:
	.globl	res_func
res_func:
	clrb	a6@(dnrm_flg)
	clrb	a6@(res_flg)
	.word	0x422e
	.word	0xffba
	tstb	a6@(dy_mo_flg)
	.word	0x67ff
	.word	0x0000
	.word	0x004e
// dyadic:
	btst	#7,a6@(dtag)	//if dop = norm=000, zero=001, inf=010 or nan=011
	.word	0x67ff
	.word	0x0000
	.word	0x0042
//				;else denorm
// HANDLE DESTINATION DENORM HERE
//				;set dtag to norm
//				;write the tag & fpte15 to the fsave stack
	lea	a6@(fptemp),a0

	bclr	#sign_bit,a0@(local_ex)
	sne	a0@(local_sgn)

	bsr	nrm_set		//normalize number (exponent will go negative)
	bclr	#sign_bit,a0@(local_ex) //get rid of false sign

	bfclr	a0@(local_sgn){#0:#8}	//change back to ieee ext format
	beq	ADR_409cecc
	bset	#sign_bit,a0@(local_ex)
// dpos:
ADR_409cecc:
	bfclr	a6@(dtag){#0:#4}	//set tag to normalized, fpte15 = 0
	bset	#4,a6@(dtag)	//set fpte15
	orb	#0x0f,a6@(dnrm_flg)
	.word	0x41ee
	.word	0xff34
// monadic:
	btst	#direction_bit,a6@(cmdreg1b)	//check direction
	.word	0x66ff
	.word	0x0000
	.word	0x10c0
//
// At this point, only oplcass 0 and 2 possible
//
	btst	#7,a6@(stag)	//if sop = norm=000, zero=001, inf=010 or nan=011
	.word	0x66ff
	.word	0x0000
	.word	0x0362

//
// At this point, check for the cases in which normalizing the 
// denorm produces incorrect results.
//
	tstb	a6@(dy_mo_flg)	//all cases of dyadic instructions would
	.word	0x66ff
	.word	0x0000
	.word	0x03ba

// At this point:
//	monadic instructions:	fabs  = $18  fneg   = $1a  ftst   = $3a
//				fmove = $00  fsmove = $40  fdmove = $44
//				fsqrt = $04  fssqrt = $41  fdsqrt = $45
//
	movew	a6@(cmdreg1b),d0	//get command register
	.word	0x0280
	.word	0x0000
	.word	0x007f
	.word	0x0800
	.word	0x0000
	.word	0x66ff
	.word	0x0000
	.word	0x03a6
	.word	0x50ee
	.word	0xffba
	.word	0x302e
	.word	0xff1c
	.word	0x0200
	.word	0x003b
	.word	0x4a00
	.word	0x67ff
	.word	0x0000
	.word	0x00b6
	.word	0x0c00
	.word	0x0018
	.word	0x67ff
	.word	0x0000
	.word	0x007e
	.word	0x0c00
	.word	0x001a
	.word	0x67ff
	.word	0x0000
	.word	0x008e
	.word	0x3028
	.word	0x0000
	.word	0x0880
	.word	0x000f
	.word	0x56e8
	.word	0x0002
	.word	0x67ff
	.word	0x0000
	.word	0x000c
	.word	0x00ae
	.word	0x0800
	.word	0x0000
	.word	0xff84
	.word	0x0c40
	.word	0x7fff
	.word	0x66ff
	.word	0x0000
	.word	0x0032
	.word	0x4aa8
	.word	0x0004
	.word	0x66ff
	.word	0x0000
	.word	0x0018
	.word	0x4aa8
	.word	0x0008
	.word	0x66ff
	.word	0x0000
	.word	0x000e
	.word	0x00ae
	.word	0x0200
	.word	0x0000
	.word	0xff84
	.word	0x4e75
	.word	0x00ae
	.word	0x0100
	.word	0x0000
	.word	0xff84
	.word	0x2d6e
	.word	0xff34
	.word	0xff28
	.word	0x4e75
	.word	0x4aa8
	.word	0x0004
	.word	0x66ff
	.word	0x0000
	.word	0x0016
	.word	0x4aa8
	.word	0x0008
	.word	0x66ff
	.word	0x0000
	.word	0x000c
	.word	0x00ae
	.word	0x0400
	.word	0x0000
	.word	0xff84
	.word	0x4e75
	.word	0x102e
	.word	0xff18
	.word	0x0800
	.word	0x0005
	.word	0x66ff
	.word	0x0000
	.word	0x0e9e
	.word	0x08a8
	.word	0x0007
	.word	0x0000
	.word	0x60ff
	.word	0x0000
	.word	0x0018
	.word	0x102e
	.word	0xff18
	.word	0x0800
	.word	0x0005
	.word	0x66ff
	.word	0x0000
	.word	0x0e84
	.word	0x0868
	.word	0x0007
	.word	0x0000
	.word	0x102e
	.word	0xff18
	.word	0x0200
	.word	0x00e0
	.word	0x66ff
	.word	0x0000
	.word	0x0e70
	.word	0x082e
	.word	0x0002
	.word	0xff1d
	.word	0x66ff
	.word	0x0000
	.word	0x0028
	.word	0x082e
	.word	0x0006
	.word	0xff1d
	.word	0x66ff
	.word	0x0000
	.word	0x0078
	.word	0xe9ee
	.word	0x0002
	.word	0xff83
	.word	0x4a00
	.word	0x67ff
	.word	0x0000
	.word	0x0214
	.word	0x0c00
	.word	0x0001
	.word	0x67ff
	.word	0x0000
	.word	0x0060
	.word	0x7002
	.word	0x3228
	.word	0x0000
	.word	0x0241
	.word	0x7fff
	.word	0x0c41
	.word	0x3c01
	.word	0x63ff
	.word	0x0000
	.word	0x00ae
	.word	0xe9ee
	.word	0x1082
	.word	0xff83
	.word	0x0081
	.word	0x0002
	.word	0x0000
	.word	0x4280
	.word	0x08a8
	.word	0x0007
	.word	0x0000
	.word	0x56e8
	.word	0x0002
	.word	0x61ff
	.word	0x0000
	.word	0x1660
	.word	0xece8
	.word	0x0008
	.word	0x0002
	.word	0x67ff
	.word	0x0000
	.word	0x000a
	.word	0x08e8
	.word	0x0007
	.word	0x0000
	.word	0x3228
	.word	0x0000
	.word	0x0241
	.word	0x7fff
	.word	0x0c41
	.word	0x43ff
	.word	0x6cff
	.word	0x0000
	.word	0x0060
	.word	0x60ff
	.word	0x0000
	.word	0x01ae
	.word	0x7001
	.word	0x3228
	.word	0x0000
	.word	0x0241
	.word	0x7fff
	.word	0x0c41
	.word	0x3f81
	.word	0x63ff
	.word	0x0000
	.word	0x0052
	.word	0xe9ee
	.word	0x1082
	.word	0xff83
	.word	0x0081
	.word	0x0001
	.word	0x0000
	.word	0x4280
	.word	0x08a8
	.word	0x0007
	.word	0x0000
	.word	0x56e8
	.word	0x0002
	.word	0x61ff
	.word	0x0000
	.word	0x1604
	.word	0xece8
	.word	0x0008
	.word	0x0002
	.word	0x67ff
	.word	0x0000
	.word	0x000a
	.word	0x08e8
	.word	0x0007
	.word	0x0000
	.word	0x3228
	.word	0x0000
	.word	0x0241
	.word	0x7fff
	.word	0x0c41
	.word	0x407f
	.word	0x6dff
	.word	0x0000
	.word	0x0158
	.word	0x61ff
	.word	0xffff
	.word	0xfa7a
	.word	0x60ff
	.word	0x0000
	.word	0x014c
	.word	0x08a8
	.word	0x0007
	.word	0x0000
	.word	0x56e8
	.word	0x0002
	.word	0x61ff
	.word	0x0000
	.word	0x18a6
	.word	0xece8
	.word	0x0008
	.word	0x0002
	.word	0x67ff
	.word	0x0000
	.word	0x000a
	.word	0x08e8
	.word	0x0007
	.word	0x0000
	.word	0xe9ee
	.word	0x1082
	.word	0xff83
	.word	0x082e
	.word	0x0002
	.word	0xff1d
	.word	0x66ff
	.word	0x0000
	.word	0x0020
	.word	0x082e
	.word	0x0006
	.word	0xff1d
	.word	0x66ff
	.word	0x0000
	.word	0x0020
	.word	0x4841
	.word	0x122e
	.word	0xff83
	.word	0xec09
	.word	0x4841
	.word	0x60ff
	.word	0x0000
	.word	0x0016
	.word	0x0081
	.word	0x0002
	.word	0x0000
	.word	0x60ff
	.word	0x0000
	.word	0x000a
	.word	0x0081
	.word	0x0001
	.word	0x0000
	.word	0x08a8
	.word	0x0007
	.word	0x0000
	.word	0x56e8
	.word	0x0002
	.word	0x61ff
	.word	0x0000
	.word	0x1562
	.word	0xece8
	.word	0x0008
	.word	0x0002
	.word	0x67ff
	.word	0x0000
	.word	0x000a
	.word	0x08e8
	.word	0x0007
	.word	0x0000
	.word	0x082e
	.word	0x0001
	.word	0xff86
	.word	0x67ff
	.word	0x0000
	.word	0x000c
	.word	0x00ae
	.word	0x0000
	.word	0x0020
	.word	0xff84
	.word	0x4aa8
	.word	0x0004
	.word	0x66ff
	.word	0x0000
	.word	0x0092
	.word	0x4aa8
	.word	0x0008
	.word	0x66ff
	.word	0x0000
	.word	0x0088
	.word	0x202e
	.word	0xff80
	.word	0x0280
	.word	0x0000
	.word	0x0030
	.word	0x0c80
	.word	0x0000
	.word	0x0020
	.word	0x6dff
	.word	0x0000
	.word	0x0058
	.word	0x66ff
	.word	0x0000
	.word	0x0020
	.word	0x4a68
	.word	0x0000
	.word	0x6cff
	.word	0x0000
	.word	0x0048
	.word	0x082e
	.word	0x0007
	.word	0xff83
	.word	0x67ff
	.word	0x0000
	.word	0x002e
	.word	0x60ff
	.word	0x0000
	.word	0x001a
	.word	0x4a68
	.word	0x0000
	.word	0x6dff
	.word	0x0000
	.word	0x002c
	.word	0x082e
	.word	0x0007
	.word	0xff83
	.word	0x67ff
	.word	0x0000
	.word	0x0012
	.word	0x00a8
	.word	0x0000
	.word	0x0800
	.word	0x0008
	.word	0x60ff
	.word	0x0000
	.word	0x002c
	.word	0x00a8
	.word	0x0000
	.word	0x0100
	.word	0x0004
	.word	0x60ff
	.word	0x0000
	.word	0x001e
	.word	0x00ae
	.word	0x0400
	.word	0x0000
	.word	0xff84
	.word	0x102e
	.word	0xff18
	.word	0x0200
	.word	0x00e0
	.word	0x0c00
	.word	0x0040
	.word	0x67ff
	.word	0x0000
	.word	0x000c
	.word	0x00ae
	.word	0x0000
	.word	0x0800
	.word	0xff84
	.word	0x2d50
	.word	0xff34
	.word	0x2d68
	.word	0x0004
	.word	0xff38
	.word	0x2d68
	.word	0x0008
	.word	0xff3c
	.word	0x4a68
	.word	0x0000
	.word	0x67ff
	.word	0x0000
	.word	0x0010
	.word	0x0c68
	.word	0x8000
	.word	0x0000
	.word	0x66ff
	.word	0x0000
	.word	0x000c
	.word	0x00ae
	.word	0x0400
	.word	0x0000
	.word	0xff84
	.word	0x4a68
	.word	0x0000
	.word	0x6aff
	.word	0x0000
	.word	0x0c12
	.word	0x00ae
	.word	0x0800
	.word	0x0000
	.word	0xff84
	.word	0x60ff
	.word	0x0000
	.word	0x0c04
	.word	0x4a2e
	.word	0xffb8
	.word	0x66ff
	.word	0x0000
	.word	0x0022
	.word	0x302e
	.word	0xff1c
	.word	0x0280
	.word	0x0000
	.word	0x007f
	.word	0x0800
	.word	0x0000
	.word	0x66ff
	.word	0x0000
	.word	0x000e
	.word	0x50ee
	.word	0xffba
	.word	0x60ff
	.word	0x0000
	.word	0x005e

	bclr	#sign_bit,a0@(local_ex)
	sne	a0@(local_sgn)

	bsr	nrm_set		//normalize number (exponent will go 
//				; negative)
	bclr	#sign_bit,a0@(local_ex) //get rid of false sign

	bfclr	a0@(local_sgn){#0:#8}	//change back to ieee ext format
	beq	ADR_409d2a8
	bset	#sign_bit,a0@(local_ex)
// spos:
ADR_409d2a8:
	bfclr	a6@(stag){#0:#4}	//set tag to normalized, fpte15 = 0
	bset	#4,a6@(stag)	//set ete15
	orb	#0xf0,a6@(dnrm_flg)
//				;(all zeros)  branch out for possible 
//				;optimization here
	tstb	a6@(dnrm_flg)	//check if any of the ops were denorms
	.word	0x66ff
	.word	0x0000
	.word	0x02b4
// fix_stk:
ADR_409d2c4:
	moveb	#0xfe,a6@(cu_savepc)
	bclr	#e1,a6@(e_byte)

	clrw	a6@(nmnexc)

	st	a6@(res_flg)	//indicate that a restore is needed
	rts
	.word	0x50ee
	.word	0xffba
	.word	0x302e
	.word	0xff1c
	.word	0x0200
	.word	0x003b
	.word	0x4a00
	beq	ADR_409d384		//if a multiply branch out
	.word	0x0c00
	.word	0x0018
	.word	0x67ff
	.word	0x0000
	.word	0x007e
	.word	0x0c00
	.word	0x001a
	.word	0x67ff
	.word	0x0000
	.word	0x0080
	.word	0x3028
	.word	0x0000
	.word	0x0880
	.word	0x000f
	.word	0x56e8
	.word	0x0002
	.word	0x67ff
	.word	0x0000
	.word	0x000c
	.word	0x00ae
	.word	0x0800
	.word	0x0000
	.word	0xff84
	.word	0x0c40
	.word	0x7fff
	.word	0x66ff
	.word	0x0000
	.word	0x0032
	.word	0x4aa8
	.word	0x0004
	.word	0x66ff
	.word	0x0000
	.word	0x0018
	.word	0x4aa8
	.word	0x0008
	.word	0x66ff
	.word	0x0000
	.word	0x000e
	.word	0x00ae
	.word	0x0200
	.word	0x0000
	.word	0xff84
	.word	0x4e75
	.word	0x00ae
	.word	0x0100
	.word	0x0000
	.word	0xff84
	.word	0x2d6e
	.word	0xff34
	.word	0xff28
	.word	0x4e75
	.word	0x4aa8
	.word	0x0004
	.word	0x66ff
	.word	0x0000
	.word	0x0016
	.word	0x4aa8
	.word	0x0008
	.word	0x66ff
	.word	0x0000
	.word	0x000c
	.word	0x00ae
	.word	0x0400
	.word	0x0000
	.word	0xff84
	.word	0x4e75
	.word	0x08a8
	.word	0x0007
	.word	0x0000
	.word	0x60ff
	.word	0x0000
	.word	0x000a
	.word	0x0868
	.word	0x0007
	.word	0x0000
ADR_409d384:
	.word	0x082e
	.word	0x0002
	.word	0xff1d
	.word	0x66ff
	.word	0x0000
	.word	0x0028
	.word	0x082e
	.word	0x0006
	.word	0xff1d
	.word	0x66ff
	.word	0x0000
	.word	0x004c
	.word	0xe9ee
	.word	0x0002
	.word	0xff83
	.word	0x4a00
	.word	0x67ff
	.word	0x0000
	.word	0x006e
	.word	0x0c00
	.word	0x0001
	.word	0x67ff
	.word	0x0000
	.word	0x0034
	.word	0xe9ee
	.word	0x1082
	.word	0xff83
	.word	0x4a68
	.word	0x0000
	.word	0x6dff
	.word	0x0000
	.word	0x0014
	.word	0x0c01
	.word	0x0003
	.word	0x66ff
	.word	0x0000
	.word	0x006a
	.word	0x60ff
	.word	0x0000
	.word	0x008a
	.word	0x0c01
	.word	0x0002
	.word	0x66ff
	.word	0x0000
	.word	0x00a2
	.word	0x60ff
	.word	0x0000
	.word	0x00ca
	.word	0xe9ee
	.word	0x1082
	.word	0xff83
	.word	0x4a68
	.word	0x0000
	.word	0x6dff
	.word	0x0000
	.word	0x0014
	.word	0x0c01
	.word	0x0003
	.word	0x66ff
	.word	0x0000
	.word	0x00da
	.word	0x60ff
	.word	0x0000
	.word	0x00fa
	.word	0x0c01
	.word	0x0002
	.word	0x66ff
	.word	0x0000
	.word	0x0112
	.word	0x60ff
	.word	0x0000
	.word	0x013a
	.word	0x00ae
	.word	0x0000
	.word	0x0800
	.word	0xff84
	.word	0x4a68
	.word	0x0000
	.word	0x67ff
	.word	0x0000
	.word	0x0a36
	.word	0x00ae
	.word	0x0800
	.word	0x0000
	.word	0xff84
	.word	0x60ff
	.word	0x0000
	.word	0x0a28
	.word	0x217c
	.word	0x3c01
	.word	0x0000
	.word	0x0000
	.word	0x42a8
	.word	0x0004
	.word	0x42a8
	.word	0x0008
	.word	0x00ae
	.word	0x0400
	.word	0x0000
	.word	0xff84
	.word	0x00ae
	.word	0x0000
	.word	0x0a28
	.word	0xff84
	.word	0x60ff
	.word	0x0000
	.word	0x0a02
	.word	0x217c
	.word	0x3c01
	.word	0x0000
	.word	0x0000
	.word	0x42a8
	.word	0x0004
	.word	0x217c
	.word	0x0000
	.word	0x0800
	.word	0x0008
	.word	0x00ae
	.word	0x0000
	.word	0x0a28
	.word	0xff84
	.word	0x60ff
	.word	0x0000
	.word	0x09e0
	.word	0x217c
	.word	0xbc01
	.word	0x0000
	.word	0x0000
	.word	0x42a8
	.word	0x0004
	.word	0x42a8
	.word	0x0008
	.word	0x00ae
	.word	0x0400
	.word	0x0000
	.word	0xff84
	.word	0x00ae
	.word	0x0800
	.word	0x0000
	.word	0xff84
	.word	0x00ae
	.word	0x0000
	.word	0x0a28
	.word	0xff84
	.word	0x60ff
	.word	0x0000
	.word	0x09b2
	.word	0x217c
	.word	0xbc01
	.word	0x0000
	.word	0x0000
	.word	0x42a8
	.word	0x0004
	.word	0x217c
	.word	0x0000
	.word	0x0800
	.word	0x0008
	.word	0x00ae
	.word	0x0800
	.word	0x0000
	.word	0xff84
	.word	0x00ae
	.word	0x0000
	.word	0x0a28
	.word	0xff84
	.word	0x60ff
	.word	0x0000
	.word	0x0988
	.word	0x217c
	.word	0x3f81
	.word	0x0000
	.word	0x0000
	.word	0x42a8
	.word	0x0004
	.word	0x42a8
	.word	0x0008
	.word	0x00ae
	.word	0x0400
	.word	0x0000
	.word	0xff84
	.word	0x00ae
	.word	0x0000
	.word	0x0a28
	.word	0xff84
	.word	0x60ff
	.word	0x0000
	.word	0x0962
	.word	0x217c
	.word	0x3f81
	.word	0x0000
	.word	0x0000
	.word	0x217c
	.word	0x0000
	.word	0x0100
	.word	0x0004
	.word	0x42a8
	.word	0x0008
	.word	0x00ae
	.word	0x0000
	.word	0x0a28
	.word	0xff84
	.word	0x60ff
	.word	0x0000
	.word	0x0940
	.word	0x217c
	.word	0xbf81
	.word	0x0000
	.word	0x0000
	.word	0x42a8
	.word	0x0004
	.word	0x42a8
	.word	0x0008
	.word	0x00ae
	.word	0x0400
	.word	0x0000
	.word	0xff84
	.word	0x00ae
	.word	0x0800
	.word	0x0000
	.word	0xff84
	.word	0x00ae
	.word	0x0000
	.word	0x0a28
	.word	0xff84
	.word	0x60ff
	.word	0x0000
	.word	0x0912
	.word	0x217c
	.word	0xbf81
	.word	0x0000
	.word	0x0000
	.word	0x217c
	.word	0x0000
	.word	0x0100
	.word	0x0004
	.word	0x42a8
	.word	0x0008
	.word	0x00ae
	.word	0x0800
	.word	0x0000
	.word	0xff84
	.word	0x00ae
	.word	0x0000
	.word	0x0a28
	.word	0xff84
	.word	0x60ff
	.word	0x0000
	.word	0x08e8
	.word	0x4a2e
	.word	0xffb8
	.word	0x67ff
	.word	0xffff
	.word	0xfd4a
	.word	0x302e
	.word	0xff1c
	.word	0x0240
	.word	0x003b
	.word	0x0c40
	.word	0x0022
	.word	0x67ff
	.word	0x0000
	.word	0x015e
	.word	0x0c40
	.word	0x0028
	.word	0x67ff
	.word	0x0000
	.word	0x03e0
	.word	0x0c40
	.word	0x0023
	.word	0x67ff
	.word	0x0000
	.word	0x06ee
	.word	0x0c40
	.word	0x0038
	.word	0x67ff
	.word	0x0000
	.word	0x065e

	cmpb	#0xff,a6@(dnrm_flg)	//if both src and dest were
	.word	0x67ff
	.word	0xffff
	.word	0xfd0e
	.word	0x0c2e
	.word	0x000f
	.word	0xffb6
	.word	0x66ff
	.word	0x0000
	.word	0x0084
	.word	0x61ff
	.word	0x0000
	.word	0x0046
	.word	0x66ff
	.word	0xffff
	.word	0xfcf6
	.word	0xe9ee
	.word	0x004f
	.word	0xff34
	.word	0xebee
	.word	0x104f
	.word	0xff28
	.word	0x9081
	.word	0x0c80
	.word	0x0000
	.word	0x7fff
	.word	0x6dff
	.word	0xffff
	.word	0xfcdc
	.word	0x422e
	.word	0xfef6
	.word	0x302e
	.word	0xff34
	.word	0x322e
	.word	0xff28
	.word	0xb340
	.word	0x0240
	.word	0x8000
	.word	0x67ff
	.word	0x0000
	.word	0x06ec
	.word	0x50ee
	.word	0xfef6
	.word	0x60ff
	.word	0x0000
	.word	0x06e2
ADR_409d60e:
	moveb	a6@(-232:w),d0
	bra	ADR_409d61c:l
ADR_409d618:
	moveb	a6@(-224:w),d0
ADR_409d61c:
	andb	#0x60,d0
	cmpb	#0x40,d0
	beq	ADR_409d642:l
	cmpb	#0x60,d0
	beq	ADR_409d642:l
	cmpb	#0x20,d0
	beq	ADR_409d642:l
	clrl	d0
	rts
ADR_409d642:
	moveq	#-1,d0
	rts
	bsr	ADR_409d618:l
	bne	ADR_409d2c4:l
	bfextu	a6@(-216:w){#1,#15},d0
	bfexts	a6@(-204:w){#1,#15},d1
	subl	d1,d0
	cmpl	#0x8000,d0
	blt	ADR_409d2c4:l
	clrb	a6@(-266:w)
	movew	a6@(-204:w),d0
	movew	a6@(-216:w),d1
	eorw	d1,d0
	andw	#0x8000,d0
	beq	ADR_409d688:l
	st	a6@(-266:w)
ADR_409d688:
	bclr	#2,a6@(-220:w)
	orl	#0x1048,a6@(-124:w)
	clrw	a6@(-236:w)
	lea	a6@(-268:w),a0
	movew	a6@(-228:w),d0
	btst	#6,d0
	beq	ADR_409d6c6:l
	btst	#2,d0
	bne	ADR_409d6be:l
	moveq	#1,d0
	bra	ADR_409d6cc:l
ADR_409d6be:
	moveq	#2,d0
	bra	ADR_409d6cc:l
ADR_409d6c6:
	bfextu	a6@(-125:w){#0,#2},d0
ADR_409d6cc:
	.word	0x61ff
	.word	0x0000
	.word	0x6ac0
	bfclr	a6@(-266:w){#0,#8}
	beq	ADR_409ddca:l
	bset	#7,a6@(-268:w)
	bra	ADR_409ddca:l
	cmpb	#0xff,a6@(-74:w)
	beq	ADR_409d2c4:l
	cmpb	#0xf,a6@(-74:w)
	bne	ADR_409d72e:l
	bsr	ADR_409d60e:l
	bne	ADR_409d2c4:l
// gusxp:
	bfextu	a6@(etemp_ex){#1:#15},d0
	bfexts	a6@(-216:w){#1,#15},d1
	subl	d1,d0
	cmpl	#0x8000,d0
	blt	ADR_409d2c4:l
	bra	ADR_409d754:l
ADR_409d72e:
	bsr	ADR_409d618:l
	bne	ADR_409d2c4:l
	bfextu	a6@(-216:w){#1,#15},d0
	bfexts	a6@(-204:w){#1,#15},d1
	subl	d1,d0
	cmpl	#0x8000,d0
	blt	ADR_409d2c4:l
ADR_409d754:
	movew	a6@(-204:w),d0
	movew	a6@(-216:w),d1
	eorw	d1,d0
	andw	#0x8000,d0
	beq	ADR_409d864:l
	cmpb	#0xf,a6@(-74:w)
	bne	ADR_409d7ec:l
	movew	a6@(-216:w),d0
	andw	#0x8000,d0
	orw	#0x3fff,d0
	movew	d0,a6@(-216:w)
	movel	a6@(-128:w),d0
	andl	#0x30,d0
	fmoveml	d0,fpc
	fmovex	a6@(-204:w),fp0
	faddx	a6@(-216:w),fp0
	lea	a6@(-268:w),a0
	fmoveml	fps,d1
	orl	d1,a6@(-124:w)
	fmovex	fp0,a6@(-268:w)
	lsrl	#4,d0
	movel	a6@(-128:w),d1
	andl	#0xc0,d1
	lsrl	#6,d1
	swap	d1
	orl	d0,d1
	clrl	d0
	bclr	#7,a6@(-268:w)
	sne	a6@(-266:w)
	bsr	round:l
	bfclr	a6@(-266:w){#0,#8}
	beq	ADR_409dd6a:l
	bset	#7,a6@(-268:w)
	bra	ADR_409dd6a:l
ADR_409d7ec:
	movew	a6@(-204:w),d0
	andw	#0x8000,d0
	orw	#0x3fff,d0
	movew	d0,a6@(-204:w)
	movel	a6@(-128:w),d0
	andl	#0x30,d0
	fmoveml	d0,fpc
	fmovex	a6@(-204:w),fp0
	faddx	a6@(-216:w),fp0
	fmoveml	fps,d1
	orl	d1,a6@(-124:w)
	lea	a6@(-268:w),a0
	fmovex	fp0,a6@(-268:w)
	lsrl	#4,d0
	movel	a6@(-128:w),d1
	andl	#0xc0,d1
	lsrl	#6,d1
	swap	d1
	orl	d0,d1
	clrl	d0
	bclr	#7,a6@(-268:w)
	sne	a6@(-266:w)
	bsr	round:l
	bfclr	a6@(-266:w){#0,#8}
	beq	ADR_409dd6a:l
	bset	#7,a6@(-268:w)
	bra	ADR_409dd6a:l
ADR_409d864:
	cmpb	#0xf,a6@(-74:w)
	bne	ADR_409d8e4:l
	lea	a6@(-204:w),a0
	movel	a6@(-128:w),d0
	andl	#0x30,d0
	lsrl	#4,d0
	movel	a6@(-128:w),d1
	andl	#0xc0,d1
	lsrl	#6,d1
	swap	d1
	orl	d0,d1
	movel	#0x20000000:l,d0
	bclr	#7,a6@(-204:w)
	sne	a6@(-202:w)
	bsr	round:l
	bfclr	a6@(-202:w){#0,#8}
	beq	ADR_409d8b8:l
	bset	#7,a6@(-204:w)
ADR_409d8b8:
	lea	a6@(-268:w),a0
	movel	a6@(-204:w),a0@
	movel	a6@(-200:w),a0@(4:w)
	movel	a6@(-196:w),a0@(8:w)
	tstw	a6@(-204:w)
	bgt	ADR_409d952:l
	orl	#0x8000000,a6@(-124:w)
	bra	ADR_409d952:l
ADR_409d8e4:
	lea	a6@(-216:w),a0
	movel	a6@(-128:w),d0
	andl	#0x30,d0
	lsrl	#4,d0
	movel	a6@(-128:w),d1
	andl	#0xc0,d1
	lsrl	#6,d1
	swap	d1
	orl	d0,d1
	movel	#0x20000000:l,d0
	bclr	#7,a6@(-216:w)
	sne	a6@(-214:w)
	bsr	round:l
	bfclr	a6@(-214:w){#0,#8}
	beq	ADR_409d92c:l
	bset	#7,a6@(-216:w)
ADR_409d92c:
	lea	a6@(-268:w),a0
	movel	a6@(-216:w),a0@
	movel	a6@(-212:w),a0@(4:w)
	movel	a6@(-208:w),a0@(8:w)
	tstw	a6@(-216:w)
	bgt	ADR_409d952:l
	orl	#0x8000000,a6@(-124:w)
ADR_409d952:
	movew	a6@(-268:w),d0
	andw	#0x7fff,d0
	cmpw	#0x7fff,d0
	bne	ADR_409dd6a:l
	orl	#0x2001048,a6@(-124:w)
	clrl	a0@(4:w)
	bra	ADR_409dd6a:l
	cmpb	#0xff,a6@(-74:w)
	beq	ADR_409d2c4:l
	cmpb	#0xf,a6@(-74:w)
	bne	ADR_409d9ba:l
	bsr	ADR_409d60e:l
	bne	ADR_409d2c4:l
	bfextu	a6@(-204:w){#1,#15},d0
	bfexts	a6@(fptemp_ex){#1:#15},d1
	subl	d1,d0
	cmpl	#0x8000,d0
	blt	ADR_409d2c4:l
	bra	ADR_409d9e0
ADR_409d9ba:
	bsr	ADR_409d618:l
	bne	ADR_409d2c4:l
	bfextu	a6@(-216:w){#1,#15},d0
	bfexts	a6@(-204:w){#1,#15},d1
	subl	d1,d0
	cmpl	#0x8000,d0
	blt	ADR_409d2c4:l
ADR_409d9e0:
	movew	a6@(-204:w),d0
	movew	a6@(-216:w),d1
	eorw	d1,d0
	andw	#0x8000,d0
	bne	ADR_409daf0:l
	cmpb	#0xf,a6@(-74:w)
	bne	ADR_409da78:l
	movew	a6@(-216:w),d0
	andw	#0x8000,d0
	orw	#0x3fff,d0
	movew	d0,a6@(-216:w)
	movel	a6@(-128:w),d0
	andl	#0x30,d0
	fmoveml	d0,fpc
	fmovex	a6@(-216:w),fp0
	fsubx	a6@(-204:w),fp0
	fmoveml	fps,d1
	orl	d1,a6@(-124:w)
	lea	a6@(-268:w),a0
	fmovex	fp0,a6@(-268:w)
	lsrl	#4,d0
	movel	a6@(-128:w),d1
	andl	#0xc0,d1
	lsrl	#6,d1
	swap	d1
	orl	d0,d1
	clrl	d0
	bclr	#7,a6@(-268:w)
	sne	a6@(-266:w)
	bsr	round:l
	bfclr	a6@(-266:w){#0,#8}
	beq	ADR_409dd6a:l
	bset	#7,a6@(-268:w)
	bra	ADR_409dd6a:l
ADR_409da78:
	movew	a6@(-204:w),d0
	andw	#0x8000,d0
	orw	#0x3fff,d0
	movew	d0,a6@(-204:w)
	movel	a6@(-128:w),d0
	andl	#0x30,d0
	fmoveml	d0,fpc
	fmovex	a6@(-216:w),fp0
	fsubx	a6@(-204:w),fp0
	fmoveml	fps,d1
	orl	d1,a6@(-124:w)
	lea	a6@(-268:w),a0
	fmovex	fp0,a6@(-268:w)
	lsrl	#4,d0
	movel	a6@(-128:w),d1
	andl	#0xc0,d1
	lsrl	#6,d1
	swap	d1
	orl	d0,d1
	clrl	d0
	bclr	#7,a6@(-268:w)
	sne	a6@(-266:w)
	bsr	round:l
	bfclr	a6@(-266:w){#0,#8}
	beq	ADR_409dd6a:l
	bset	#7,a6@(-268:w)
	bra	ADR_409dd6a:l
ADR_409daf0:
	cmpb	#0xf,a6@(-74:w)
	bne	ADR_409db76:l
	lea	a6@(-204:w),a0
	movel	a6@(-128:w),d0
	andl	#0x30,d0
	lsrl	#4,d0
	movel	a6@(-128:w),d1
	andl	#0xc0,d1
	lsrl	#6,d1
	swap	d1
	orl	d0,d1
	movel	#0x20000000:l,d0
	eorw	#0x8000,a6@(-204:w)
	tstw	a6@(-204:w)
	bgt	ADR_409db3a:l
	orl	#0x8000000,a6@(-124:w)
ADR_409db3a:
	bclr	#7,a6@(-204:w)
	sne	a6@(-202:w)
	bsr	round:l
	bfclr	a6@(-202:w){#0,#8}
	beq	ADR_409db5c:l
	bset	#7,a6@(-204:w)
ADR_409db5c:
	lea	a6@(-268:w),a0
	movel	a6@(-204:w),a0@
	movel	a6@(-200:w),a0@(4:w)
	movel	a6@(-196:w),a0@(8:w)
	bra	ADR_409dbe4:l
ADR_409db76:
	lea	a6@(-216:w),a0
	movel	a6@(-128:w),d0
	andl	#0x30,d0
	lsrl	#4,d0
	movel	a6@(-128:w),d1
	andl	#0xc0,d1
	lsrl	#6,d1
	swap	d1
	orl	d0,d1
	movel	#0x20000000:l,d0
	bclr	#7,a6@(-216:w)
	sne	a6@(-214:w)
	bsr	round:l
	bfclr	a6@(-214:w){#0,#8}
	beq	ADR_409dbbe:l
	bset	#7,a6@(-216:w)
ADR_409dbbe:
	lea	a6@(-268:w),a0
	movel	a6@(-216:w),a0@
	movel	a6@(-212:w),a0@(4:w)
	movel	a6@(-208:w),a0@(8:w)
	tstw	a6@(-216:w)
	bgt	ADR_409dbe4:l
	orl	#0x8000000,a6@(-124:w)
ADR_409dbe4:
	movew	a6@(-268:w),d0
	andw	#0x7fff,d0
	cmpw	#0x7fff,d0
	bne	ADR_409dd6a:l
	orl	#0x2001048,a6@(-124:w)
	clrl	a0@(4:w)
	bra	ADR_409dd6a:l
	cmpb	#0xff,a6@(-74:w)
	beq	ADR_409d2c4:l

// pre_div:
	cmpb	#0x0f,a6@(dnrm_flg)	//if destination is denorm,
	bne	ADR_409dc52:l
	bsr	ADR_409d60e:l
//					;check for wrap-around condition
	bne	ADR_409d2c4
	bfextu	a6@(etemp_ex){#1:#15},d0	//source is norm
	bfexts	a6@(fptemp_ex){#1:#15},d1	//destination is denorm
	subl	d1,d0
	cmpl	#0x8000,d0
	blt	ADR_409d2c4:l
	tstw	a6@(-204:w)
	bge	ADR_409dc84:l
	rts
ADR_409dc52:
	bsr	ADR_409d618:l
	bne	ADR_409d2c4:l
	bfextu	a6@(-216:w){#1,#15},d0
	bfexts	a6@(-204:w){#1,#15},d1
	subl	d1,d0
	cmpl	#0x8000,d0
	blt	ADR_409d2c4:l
	tstw	a6@(-216:w)
	blt	ADR_409dc84:l
	rts
ADR_409dc84:
	orl	#0x8000000,a6@(-124:w)
	rts
	cmpb	#0xff,a6@(-74:w)
	beq	ADR_409dcec:l
	cmpb	#0xf,a6@(-74:w)
	bne	ADR_409dccc:l
	bsr	ADR_409d60e:l
	bne	ADR_409d2c4:l
	bfextu	a6@(-204:w){#1,#15},d0
	bfexts	a6@(-216:w){#1,#15},d1
	addl	d1,d0
	bgt	ADR_409d2c4:l
	bra	ADR_409dcec:l
ADR_409dccc:
	bsr	ADR_409d618:l
	bne	ADR_409d2c4:l
	bfextu	a6@(-216:w){#1,#15},d0
	bfexts	a6@(-204:w){#1,#15},d1
	addl	d1,d0
	bgt	ADR_409d2c4:l

// force_unf:
ADR_409dcec:
	bclr	#e1,a6@(e_byte)
	orl	#unfl_inx_mask,a6@(user_fpsr)
	clrw	a6@(nmnexc)

	clrb	a6@(wbtemp_sgn)
	movew	a6@(etemp_ex),d0		//find the sign of the result
	movew	a6@(fptemp_ex),d1
	eorw	d1,d0
	andiw	#0x8000,d0
	beq	ADR_409dd1a
	st	a6@(wbtemp_sgn)
// frcunfcont:

ADR_409dd1a:
	lea	a6@(wbtemp),a0		//point a0 to memory location
	movew	a6@(-228:w),d0
	btst	#6,d0
	beq	ADR_409dd46:l
	btst	#2,d0
	bne	ADR_409dd3e:l
	moveq	#1,d0
	bra	ADR_409dd4c:l
ADR_409dd3e:
	moveq	#2,d0
	bra	ADR_409dd4c:l
ADR_409dd46:
	bfextu	a6@(-125:w){#0,#2},d0
ADR_409dd4c:
	.word	0x61ff
	.word	0x0000
	.word	0x67b6
	bfclr	a6@(-266:w){#0,#8}
	beq	ADR_409ddca:l
	bset	#7,a6@(-268:w)
	bra	ADR_409ddca:l
ADR_409dd6a:
	movew	a6@(-228:w),d0
	btst	#6,d0
	beq	ADR_409dd92:l
	btst	#2,d0
	bne	ADR_409dd8a:l
	moveq	#1,d0
	bra	ADR_409dda0:l
ADR_409dd8a:
	moveq	#2,d0
	bra	ADR_409dda0:l
ADR_409dd92:
	bfextu	a6@(fpcr_mode){#0:#2},d0	//get round precision
	tstb	d0
	beq	ADR_409ddca:l
ADR_409dda0:
	bclr	#7,a6@(-268:w)
	sne	a6@(-266:w)
	.word	0x61ff
	.word	0x0000
	.word	0x63e2
//					;round precision/mode.  This 
//					;sets FPSR_CC correctly

	bfclr	a6@(wbtemp_sgn){#0:#8}	//convert back to ieee ext format
	beq	ADR_409ddc2:l
	bset	#sign_bit,a6@(wbtemp_ex)
ADR_409ddc2:
	orl	#0x1248,a6@(-124:w)
// frcpos:
ADR_409ddca:
	bfextu	a6@(cmdreg1b){#6:#3},d0	//extract fp destination register
	cmpb	#0x3,d0
	ble	ADR_409ddea:l
	movel	#7,d1
	subl	d0,d1
	clrl	d0
	bset	d1,d0
	fmovemx a6@(wbtemp),d0
	rts
ADR_409ddea:
	cmpb	#0x0,d0
	beq	ADR_409de44:l
	cmpb	#0x1,d0
	beq	ADR_409de30:l
	cmpb	#0x2,d0
	beq	ADR_409de1c:l
// fp1_dst:
	movel	a6@(wbtemp_ex),a6@(user_fp1)
	movel	a6@(wbtemp_hi),a6@(user_fp1+4)
	movel	a6@(wbtemp_lo),a6@(user_fp1+8)
// frc_u_done:
	rts
ADR_409de1c:
	movel	a6@(-268:w),a6@(-152:w)
	movel	a6@(-264:w),a6@(-148:w)
	movel	a6@(-260:w),a6@(-144:w)
	rts
ADR_409de30:
	movel	a6@(-268:w),a6@(-164:w)
	movel	a6@(-264:w),a6@(-160:w)
	movel	a6@(-260:w),a6@(-156:w)
	rts
ADR_409de44:
	movel	a6@(-268:w),a6@(-176:w)
	movel	a6@(-264:w),a6@(-172:w)
	movel	a6@(-260:w),a6@(-168:w)
	rts
	btst	#6,a6@(-122:w)
	beq	ADR_409de8c:l
	btst	#6,a6@(-126:w)
	beq	ADR_409de8c:l
	movel	a6@(-204:w),a6@(-216:w)
	tstb	a6@(-204:w)
	blt	ADR_409de82:l
	rts
ADR_409de82:
	orl	#0x3,a6@(-124:w)
	rts
//					;let the 040 finish

ADR_409de8c:
	clrw	a6@(nmnexc)
	bclr	#e1,a6@(e_byte)
	moveb	a6@(-232:w),d0
	andb	#0xe0,d0
	cmpb	#0x40,d0
	bne	ADR_409dec8:l
	orl	#0x2000000,a6@(-124:w)
	tstw	a0@(0:w)
	bge	ADR_409df1c:l
	orl	#0x8000000,a6@(-124:w)
	bra	ADR_409df1c:l
ADR_409dec8:
	cmpb	#0x60,d0
	bne	ADR_409def8:l
	orl	#0x1000000,a6@(-124:w)
	movel	a6@(-204:w),a6@(-216:w)
	tstw	a0@(0:w)
	bge	ADR_409df1c:l
	orl	#0x8000000,a6@(-124:w)
	bra	ADR_409df1c:l
ADR_409def8:
	cmpb	#0x20,d0
	bne	ADR_409df1c:l
	orl	#0x4000000,a6@(-124:w)
	tstw	a0@(0:w)
	bge	ADR_409df1c:l
	orl	#0x8000000,a6@(-124:w)

ADR_409df1c:
	bfextu	a6@(cmdreg1b){#6:#3},d0	//extract fp destination register
	cmpb	#0x3,d0
	ble	ADR_409df3c:l
	movel	#7,d1
	subl	d0,d1
	clrl	d0
	bset	d1,d0
	fmovemx a6@(etemp),d0
	rts
ADR_409df3c:
	cmpb	#0x0,d0
	beq	ADR_409df96:l
	cmpb	#0x1,d0
	beq	ADR_409df82:l
	cmpb	#0x2,d0
	beq	ADR_409df6e:l
// fp1_dest:
	movel	a6@(etemp_ex),a6@(user_fp1)
	movel	a6@(etemp_hi),a6@(user_fp1+4)
	movel	a6@(etemp_lo),a6@(user_fp1+8)
	rts
ADR_409df6e:
	movel	a6@(-204:w),a6@(-152:w)
	movel	a6@(-200:w),a6@(-148:w)
	movel	a6@(-196:w),a6@(-144:w)
	rts
ADR_409df82:
	movel	a6@(-204:w),a6@(-164:w)
	movel	a6@(-200:w),a6@(-160:w)
	movel	a6@(-196:w),a6@(-156:w)
	rts
ADR_409df96:
	movel	a6@(-204:w),a6@(-176:w)
	movel	a6@(-200:w),a6@(-172:w)
	movel	a6@(-196:w),a6@(-168:w)
// fmovein_done:
	rts
	st	a6@(-70:w)
	

// opclass3:
	movew	a6@(cmdreg1b),d0	//check if packed moveout
	andiw	#0x0c00,d0	//isolate last 2 bits of size field
	cmpiw	#0x0c00,d0	//if size is 011 or 111, it is packed
	beq	ADR_409e5c4	//else it is norm or denorm
	bra	ADR_409dfe6
ADR_409dfc6:
	.long	ADR_409e062
	.long	ADR_409e30c
	.long	ADR_409e2ea
	.long	ADR_409dff8
	.long	ADR_409e0f8
	.long	ADR_409e34a
	.long	ADR_409e18a
	.long	ADR_409dff8
// mv_out:
ADR_409dfe6:
	bfextu	a6@(cmdreg1b){#3:#3},d1	//put source specifier in d1
	lea	ADR_409dfc6,a0
	movel	a0@(d1:l:4),a0
	jmp	a0@

//
// This exit is for move-out to memory.  The aunfl bit is 
// set if the result is inex.
//
// mvout_end:
ADR_409dff8:
	btst	#inex2_bit,a6@(fpsr_except)
	beq	ADR_409e016:l
	btst	#3,a6@(-122:w)
	beq	ADR_409e016
	bset	#aunfl_bit,a6@(fpsr_aexcept)
// no_aufl:
ADR_409e016:
	clrw	a6@(nmnexc)
	bclr	#e1,a6@(e_byte)
	fmovel	#0,fpsr			//clear any cc bits from res_func 
	bfclr	a6@(-202:w){#0,#8}
	beq	ADR_409e03a:l
	bset	#7,a6@(-204:w)
ADR_409e03a:
	rts
//
// This exit is for move-out to int register.  The aunfl bit is 
// not set in any case for this move.
//
// mvouti_end:
ADR_409e03c:
	clrw	a6@(nmnexc)
	bclr	#e1,a6@(e_byte)
	fmovel	#0,fpsr			//clear any cc bits from res_func 
	bfclr	a6@(-202:w){#0,#8}
	beq	ADR_409e060:l
	bset	#7,a6@(-204:w)
ADR_409e060:
	rts
//
// li is used to handle a long integer source specifier
//

// li:
ADR_409e062:
	moveql	#4,d0		//set byte count

	btst	#7,a6@(stag)	//check for extended denorm
	bne	ADR_409e21c	//if so, branch

	fmovemx a6@(etemp),fp0-fp0
	fcmpd	ADR_409ce4e,fp0
	fbge	ADR_409e0b4	
	fcmpd	ADR_409ce56,fp0
	fble	ADR_409e0d6
	movel	a6@(-128:w),d1
	andl	#0x30,d1
	fmoveml	d1,fpc
//
// at this point, the answer is between the largest pos and neg values
//
	fmovel	fp0,a6@(l_scr1)	//let the 040 perform conversion
	fmoveml	fps,d1
	orl	d1,a6@(-124:w)
	bra	ADR_409e288


// lo_plrg:
ADR_409e0b4:
	movel	#0x7fffffff,a6@(l_scr1)	//answer is largest positive int
	fbeq	ADR_409e288			//exact answer
	fcmpd	ADR_409ce5e,fp0
	fbge	ADR_409e27a		//set operr
	bra	ADR_409e26c			//set inexact

// lo_nlrg:
ADR_409e0d6:
	movel	#0x80000000,a6@(l_scr1)
	fbeq	ADR_409e288			//exact answer
	fcmpd	ADR_409ce66,fp0
	fblt	ADR_409e27a		//set operr
	bra	ADR_409e26c			//set inexact

//
// wi is used to handle a word integer source specifier
//

// wi:
ADR_409e0f8:
	moveql	#2,d0		//set byte count

	btst	#7,a6@(stag)	//check for extended denorm
	bne	ADR_409e21c	//branch if so

	fmovemx a6@(etemp),fp0-fp0
	fcmps	#0s32767,fp0
// 46fffe00 in sgl prec = 400d0000fffe000000000000 in ext prec
	fbge	ADR_409e14a	
	fcmps	#0s-32768,fp0
// c7000000 in sgl prec = c00e00008000000000000000 in ext prec
	fble	ADR_409e16a
	movel	a6@(-128:w),d1
	andl	#0x30,d1
	fmoveml	d1,fpc

//
// at this point, the answer is between the largest pos and neg values
//
	fmovew	fp0,a6@(l_scr1)	//let the 040 perform conversion
	fmoveml	fps,d1
	orl	d1,a6@(-124:w)
	bra	ADR_409e288

// wo_plrg:
ADR_409e14a:
	movew	#0x7fff,a6@(l_scr1)	//answer is largest positive int
	fbeq	ADR_409e288			//exact answer
	fcmps	#0s32767.5,fp0
// 46ffff00 in sgl prec = 400d0000ffff000000000000 in ext prec
	fbge	ADR_409e27a		//set operr
	bra	ADR_409e26c			//set inexact

// wo_nlrg:
ADR_409e16a:
	movew	#0x8000,a6@(l_scr1)
	fbeq	ADR_409e288			//exact answer
	fcmps	#0s-32768.5,fp0
// c7000080 in sgl prec = c00e00008000800000000000 in ext prec
	fblt	ADR_409e27a		//set operr
	bra	ADR_409e26c			//set inexact

//
// bi is used to handle a byte integer source specifier
//

// bi:
ADR_409e18a:
	moveql	#1,d0		//set byte count

	btst	#7,a6@(stag)	//check for extended denorm
	bne	ADR_409e21c	//branch if so

	fmovemx a6@(etemp),fp0-fp0
	fcmps	#0s127,fp0
// 42fe0000 in sgl prec = 40050000fe00000000000000 in ext prec
	fbge	ADR_409e1dc	
	fcmps	#0s-128,fp0
// c3000000 in sgl prec = c00600008000000000000000 in ext prec
	fble	ADR_409e1fc
	movel	a6@(-128:w),d1
	andl	#0x30,d1
	fmoveml	d1,fpc

//
// at this point, the answer is between the largest pos and neg values
//
	fmoveb	fp0,a6@(l_scr1)	//let the 040 perform conversion
	fmoveml	fps,d1
	orl	d1,a6@(-124:w)
	bra	ADR_409e288

// by_plrg:
ADR_409e1dc:
	moveb	#0x7f,a6@(l_scr1)		//answer is largest positive int
	fbeq	ADR_409e288			//exact answer
	fcmps	#0s127.5,fp0
// 42ff0000 in sgl prec = 40050000ff00000000000000 in ext prec
	fbge	ADR_409e27a		//set operr
	bra	ADR_409e26c			//set inexact

// by_nlrg:
ADR_409e1fc:
	moveb	#0x80,a6@(l_scr1)
	fbeq	ADR_409e288			//exact answer
	fcmps	#0s-128.5,fp0
// c3008000 in sgl prec = c00600008080000000000000 in ext prec
	fblt	ADR_409e27a		//set operr
	bra	ADR_409e26c			//set inexact

//
// Common integer routines
//

// int_dnrm:
ADR_409e21c:
	movel	#0,a6@(l_scr1)	//if extended denorm, answer is zero
	bfextu	a6@(-125:w){#2,#2},d1
	cmpb	#0x2,d1
	bmi	ADR_409e26c:l
	bne	ADR_409e252:l
	tstw	a6@(-204:w)
	bpl	ADR_409e26c:l
	movel	#0xffffffff:l,a6@(-84:w)
	bra	ADR_409e26c:l
ADR_409e252:
	tstw	a6@(-204:w)
	bmi	ADR_409e26c:l
	lea	a6@(-84:w),a1
	addal	d0,a1
	subal	#0x1:l,a1
	bset	#0,a1@
//				;fall through to  int_inx
// int_inx:
ADR_409e26c:
	oril	#inx2a_mask,a6@(user_fpsr)
	bra	ADR_409e288
// int_operr:
ADR_409e27a:
	fmovemx fp0-fp0,a6@(fptemp)	//fptemp must contain the extended
	orl	#0x2080,a6@(-124:w)
//				;fall through to perform int_wrt

// int_wrt: 
ADR_409e288:
	movel	a6@(exc_ea),a1	//load destination address
	tstl	a1		//check to see if it is a dest register
	beq	ADR_409e2a4		//write data register 

	lea	a6@(l_scr1),a0	//point to supervisor source address
	.word	0x61ff
	.word	0x0000
	.word	0x2a3e
	bra	ADR_409e03c

// wrt_dn:
ADR_409e2a4:
	movel	d0,sp@-	//d0 currently contains the size to write
	bsr	get_fline	//get fline returns in d1 lower word
	andiw	#0x7,d0		//isolate register
	movel	sp@+,d1
	cmpl	#0x4,d1
	beq	ADR_409e2d6:l
	cmpl	#0x2,d1
	bne	ADR_409e2dc:l
	orl	#0x8,d0
	bra	ADR_409e2dc:l
ADR_409e2d6:
	orl	#0x10,d0
ADR_409e2dc:
	movel	d0,d1
	.word	0x61ff
	.word	0x0000
	.word	0x6432
	bra	ADR_409e03c:l

// xp:
ADR_409e2ea:
	lea	a6@(etemp),a0
	bclr	#sign_bit,a0@(local_ex)
	sne	a0@(local_sgn)
	
	btst	#7,a6@(stag)	//check for extended denorm
	bne	ADR_409e3d4
	
	clrl	d0
	
	bra	ADR_409e382		//do normal case

// sgp:
ADR_409e30c:
	lea	a6@(etemp),a0
	bclr	#sign_bit,a0@(local_ex)
	sne	a0@(local_sgn)

	btst	#7,a6@(stag)	//check for extended denorm
	bne	ADR_409e458	//branch if so

	movew	a0@(local_ex),d0
	lea	ADR_409ce6e,a1

	cmpw	a1@,d0
	blt	ADR_409e3f8
	cmpw	a1@(2),d0
	bgt	ADR_409e4b8
	
	movel	#1,d0		//set destination format to single
	
	bra	ADR_409e382		//do normal case

// dp:
ADR_409e34a:
	lea	a6@(etemp),a0
	bclr	#sign_bit,a0@(local_ex)
	sne	a0@(local_sgn)

	btst	#7,a6@(stag)	//check for extended denorm
	bne	ADR_409e488	//branch if so

	movew	a0@(local_ex),d0
	lea	ADR_409ce76,a1

	cmpw	a1@,d0
	blt	ADR_409e428
	cmpw	a1@(2),d0
	bgt	ADR_409e4f6
	
	movel	#2,d0		//set destination format to double
//				;fall through to do_fp
//
// do_fp:
ADR_409e382:
	bfextu	a6@(fpcr_mode){#2:#2},d1	//rnd mode in d1
	swap	d0			//rnd prec in upper word
	addl	d0,d1			//d1 has prec/mode info
	
	clrl	d0			//clear g,r,s 

	bsr	round			//round 

	movel	a0,a1
	movel	a6@(exc_ea),a0

	bfextu	a6@(cmdreg1b){#3:#3},d1	//extract destination format
//					;at this point only the dest
//					;formats sgl, dbl, ext are
//					;possible
	cmpb	#2,d1
	bgt	ADR_409e3c8			//double=5, extended=2, single=1
	bne	ADR_409e3bc
//					;fall through to dext
// dext:
	bsr	dest_ext
	bra	ADR_409dff8
// dsgl:
ADR_409e3bc:
	bsr	dest_sgl
	bra	ADR_409dff8
// ddbl:
ADR_409e3c8:
	bsr	dest_dbl
	bra	ADR_409dff8

//
// Handle possible denorm or catastrophic underflow cases here
//
// xdnrm:
ADR_409e3d4:
	bsr	ADR_409e564		//initialize wbtemp
	bset	#wbtemp15_bit,a6@(wb_byte) //set wbtemp15

	movel	a0,a1
	movel	a6@(exc_ea),a0	//a0 has the destination pointer
	bsr	dest_ext	//store to memory
	bset	#unfl_bit,a6@(fpsr_except)
	bra	ADR_409dff8
ADR_409e3f8:
	bset	#4,a6@(-232:w)

	cmpw	a1@(4),d0
	blt	ADR_409e458:l

	movel	#1,d0		//load in round precision
	movel	#sgl_thresh,d1	//load in single denorm threshold
	bsr	ADR_409e534	//expects d1 to have the proper
//				;denorm threshold
	bsr	dest_sgl	//stores value to destination
	bset	#unfl_bit,a6@(fpsr_except)
	bra	ADR_409dff8	//exit
ADR_409e428:
	bset	#4,a6@(-232:w)

	cmpw	a1@(4),d0
	blt	ADR_409e488:l
		
	movel	#dbl_thresh,d1	//load in double precision threshold
	movel	#2,d0		
	bsr	ADR_409e534	//expects d1 to have proper
//				;denorm threshold
//				;expects d0 to have round precision
	bsr	dest_dbl	//store value to destination
	bset	#unfl_bit,a6@(fpsr_except)
	bra	ADR_409dff8	//exit

//
// Handle catastrophic underflow cases here
//
// sp_catas:
// Temp fix for z bit set in unf_sub
ADR_409e458:
	movel	a6@(user_fpsr),a7@-

	movel	#1,d0		//set round precision to sgl

	bsr	unf_sub		//a0 points to result

	movel	a7@+,a6@(user_fpsr)

	movel	#1,d0
	subw	d0,a0@(local_ex) //account for difference between
//				;denorm/norm bias

	movel	a0,a1		//a1 has the operand input
	movel	a6@(exc_ea),a0	//a0 has the destination pointer
	
	bsr	dest_sgl	//store the result
	oril	#unfl_inx_mask,a6@(user_fpsr)
	bra	ADR_409dff8
	
// dp_catas:
// Temp fix for z bit set in unf_sub
ADR_409e488:
	movel	a6@(user_fpsr),a7@-

	movel	#2,d0		//set round precision to dbl
	bsr	unf_sub		//a0 points to result

	movel	a7@+,a6@(user_fpsr)

	movel	#1,d0
	subw	d0,a0@(local_ex) //account for difference between 
//				;denorm/norm bias

	movel	a0,a1		//a1 has the operand input
	movel	a6@(exc_ea),a0	//a0 has the destination pointer
	
	bsr	dest_dbl	//store the result
	oril	#unfl_inx_mask,a6@(user_fpsr)
	bra	ADR_409dff8

//
// Handle catastrophic overflow cases here
//
// sp_over:
// Temp fix for z bit set in unf_sub
ADR_409e4b8:
	movel	a6@(user_fpsr),a7@-

	movel	#1,d0
	lea	a6@(-116:w),a0
	movel	a6@(-204:w),a0@
	movel	a6@(-200:w),a0@(4:w)
	movel	a6@(-196:w),a0@(8:w)
	bsr	ovf_res

	movel	a7@+,a6@(user_fpsr)

	movel	a0,a1
	movel	a6@(exc_ea),a0
	bsr	dest_sgl
	orl	#ovfinx_mask,a6@(user_fpsr)
	bra	ADR_409dff8

// dp_over:
// Temp fix for z bit set in unf_sub
ADR_409e4f6:
	movel	a6@(user_fpsr),a7@-
	movel	#2,d0
	lea	a6@(-116:w),a0
	movel	a6@(-204:w),a0@
	movel	a6@(-200:w),a0@(4:w)
	movel	a6@(-196:w),a0@(8:w)
	bsr	ovf_res

	movel	a7@+,a6@(user_fpsr)

	movel	a0,a1
	movel	a6@(exc_ea),a0
	bsr	dest_dbl
	orl	#ovfinx_mask,a6@(user_fpsr)
	bra	ADR_409dff8

//
// 	DPSPDNRM
//
// This subroutine takes an extended normalized number and denormalizes
// it to the given round precision. This subroutine also decrements
// the input operand's exponent by 1 to account for the fact that
// dest_sgl or dest_dbl expects a normalized number's bias.
//
// Input: a0  points to a normalized number in internal extended format
//	 d0  is the round precision (=1 for sgl; =2 for dbl)
//	 d1  is the the single precision or double precision
//	     denorm threshold
//
// Output: (In the format for dest_sgl or dest_dbl)
//	 a0   points to the destination
//   	 a1   points to the operand
//
// Exceptions: Reports inexact 2 exception by setting USER_FPSR bits
//
// dpspdnrm:
ADR_409e534:
	movel	d0,a7@-	//save round precision
	clrl	d0		//clear initial g,r,s
	bsr	dnrm_lp		//careful with d0, it's needed by round

	bfextu	a6@(fpcr_mode){#2:#2},d1 //get rounding mode
	swap	d1
	movew	a7@(2),d1	//set rounding precision 
	swap	d1		//at this point d1 has prec/mode info
	bsr	round		//round result, sets the inex bit in
//				;USER_FPSR if needed

	movew	#1,d0
	subw	d0,a0@(local_ex) //account for difference in denorm
//				;vs norm bias

	movel	a0,a1		//a1 has the operand input
	movel	a6@(exc_ea),a0	//a0 has the destination pointer
	addw	#4,a7		//pop stack
	rts
//
// SET_XOP initialized WBTEMP with the value pointed to by a0
// input: a0 points to input operand in the internal extended format
//
// set_xop:
ADR_409e564:
	movel	a0@(local_ex),a6@(wbtemp_ex)
	movel	a0@(local_hi),a6@(wbtemp_hi)
	movel	a0@(local_lo),a6@(wbtemp_lo)
	bfclr	a6@(wbtemp_sgn){#0:#8}
	beq	ADR_409e588
	bset	#sign_bit,a6@(wbtemp_ex)
// sxop:
ADR_409e588:
	bfclr	a6@(stag){#5:#4}	//clear wbtm66,wbtm1,wbtm0,sbit
	rts
ADR_409e590:
	.long	p_move
	.long	ADR_409e62c
	.long	ADR_409e642
	.long	ADR_409e658
	.long	p_move
ADR_409e5a4:
	.long	ADR_409e666
	.long	ADR_409e670
	.long	ADR_409e67a
	.long	ADR_409e682
	.long	ADR_409e68a
	.long	ADR_409e692
	.long	ADR_409e69a
	.long	ADR_409e6a2

// pack_out:
ADR_409e5c4:
 	lea	ADR_409e590,a0	//load jmp table address
	movew	a6@(stag),d0	//get source tag
	bfextu	d0{#16:#3},d0	//isolate source bits
	movel	a0@(d0:w:4),a0	//load a0 with routine label for tag
	jmp	a0@		//go to the routine

// p_write:
ADR_409e5d8:
	movel	#0x0c,d0 	//get byte count
	movel	a6@(exc_ea),a1	//get the destination address
	.word	0x61ff
	.word	0x0000
	.word	0x26f8
	moveb	#0,a6@(cu_savepc) //set the cu save pc to all 0's

//
// Also note that the dtag must be set to norm here - this is because 
// the 040 uses the dtag to execute the correct microcode.
//
        bfclr    a6@(dtag){#0:#3}  //set dtag to norm

	rts

// Notes on handling of special case (zero, inf, and nan) inputs:
//	1. Operr is not signalled if the k-factor is greater than 18.
//	2. Per the manual, status bits are not set.
//

// p_move:
	.globl	p_move
p_move:
	movew	a6@(cmdreg1b),d0
	btst	#kfact_bit,d0	//test for dynamic k-factor
	beq	ADR_409e610		//if clear, k-factor is static
	bfextu	d0{#25:#3},d0	//isolate register for dynamic k-factor
	lea	ADR_409e5a4:l,a0
	movel	a0@(0:b,d0:l:4),a0
	jmp	a0@
// statick:
ADR_409e610:
	andiw	#0x007f,d0	//get k-factor
	bfexts	d0{#25:#7},d0	//sign extend d0 for bindec
	lea	a6@(etemp),a0	//a0 will point to the packed decimal
	bsr	bindec		//perform the convert// data at a6
	lea	a6@(fp_scr1),a0	//load a0 with result address
	bra	ADR_409e5d8
// p_movez:
ADR_409e62c:
	lea	a6@(etemp),a0	//a0 will point to the packed decimal
	clrw	a0@(2)		//clear lower word of exp
	clrl	a0@(4)		//load second lword of zero
	clrl	a0@(8)		//load third lword of zero
	bra	ADR_409e5d8		//go write results
// p_movei:
ADR_409e642:
	fmovel	#0,fpsr		//clear aiop
	lea	a6@(etemp),a0	//a0 will point to the packed decimal
	clrw	a0@(2)		//clear lower word of exp
	bra	ADR_409e5d8		//go write the result
// p_moven:
ADR_409e658:
	lea	a6@(etemp),a0	//a0 will point to the packed decimal
	clrw	a0@(2)		//clear lower word of exp
	bra	ADR_409e5d8:l
ADR_409e666:
	movel	a6@(-192:w),d0
	bra	ADR_409e610:l
ADR_409e670:
	movel	a6@(-188:w),d0
	bra	ADR_409e610:l
ADR_409e67a:
	movel	d2,d0
	bra	ADR_409e610:l
ADR_409e682:
	movel	d3,d0
	bra	ADR_409e610:l
ADR_409e68a:
	movel	d4,d0
	bra	ADR_409e610:l
ADR_409e692:
	movel	d5,d0
	bra	ADR_409e610:l
ADR_409e69a:
	movel	d6,d0
	bra	ADR_409e610:l
ADR_409e6a2:
	movel	d7,d0
	bra	ADR_409e610:l
	.globl	round
round:
	bsr	ADR_409e736:l
	tstl	d0
	bne	ADR_409e6c0:l
	swap	d1
	bra	ADR_409e892:l
ADR_409e6c0:
	orl	#0x208,a6@(-124:w)
	lea	ADR_409e6d4:l,a1
	movel	a1@(0:b,d1:w:4),a1
	jmp	a1@
ADR_409e6d4:
	.long	ADR_409e720
	.long	ADR_409e718
	.long	ADR_409e6fe
	.long	ADR_409e6e4
ADR_409e6e4:
	swap	d1
	tstb	a0@(2:w)
	bmi	ADR_409e892:l
	moveq	#-1,d0
	lea	ADR_409e7be:l,a1
	movel	a1@(0:b,d1:w:4),a1
	jmp	a1@
ADR_409e6fe:
	swap	d1
	tstb	a0@(2:w)
	bpl	ADR_409e892:l
	moveq	#-1,d0
	lea	ADR_409e7be:l,a1
	movel	a1@(0:b,d1:w:4),a1
	jmp	a1@
ADR_409e718:
	swap	d1
	bra	ADR_409e892:l
ADR_409e720:
	swap	d1
	asll	#1,d0
	bcc	ADR_409e892:l
	lea	ADR_409e7be:l,a1
	movel	a1@(0:b,d1:w:4),a1
	jmp	a1@
ADR_409e736:
	swap	d1
	cmpw	#0x0,d1
	bne	ADR_409e748:l
	bra	ADR_409e7ba:l
ADR_409e748:
	moveml	d2/d3,sp@-
	cmpw	#0x1,d1
	bne	ADR_409e788:l
	bfextu	a0@(4:w){#24,#2},d3
	moveq	#30,d2
	lsll	d2,d3
	movel	a0@(4:w),d2
	andl	#0x3f,d2
	bne	ADR_409e7b0:l
	tstl	a0@(8:w)
	bne	ADR_409e7b0:l
	tstl	d0
	bne	ADR_409e7b0:l
	bra	ADR_409e7b4:l
ADR_409e788:
	bfextu	a0@(8:w){#21,#2},d3
	moveq	#30,d2
	lsll	d2,d3
	movel	a0@(8:w),d2
	andl	#0x1ff,d2
	bne	ADR_409e7b0:l
	tstl	d0
	bne	ADR_409e7b0:l
	bra	ADR_409e7b4:l
ADR_409e7b0:
	bset	#29,d3
ADR_409e7b4:
	movel	d3,d0
	moveml	sp@+,d2/d3
ADR_409e7ba:
	swap	d1
	rts
ADR_409e7be:
	.long	ADR_409e804
	.long	ADR_409e7ce
	.long	ADR_409e83c
	.long	ADR_409e83c
ADR_409e7ce:
	addl	#0x100,a0@(4:w)
	bcc	ADR_409e7e8:l
	roxrw	a0@(4:w)
	roxrw	a0@(6:w)
	addqw	#0x1,a0@(0:w)
ADR_409e7e8:
	tstl	d0
	bne	ADR_409e7f6:l
	andw	#0xfe00,a0@(6:w)
ADR_409e7f6:
	andl	#0xffffff00,a0@(4:w)
	clrl	a0@(8:w)
	rts
ADR_409e804:
	addql	#0x1,a0@(8:w)
	bcc	ADR_409e82c:l
	addql	#0x1,a0@(4:w)
	bcc	ADR_409e82c:l
	roxrw	a0@(4:w)
	roxrw	a0@(6:w)
	roxrw	a0@(8:w)
	roxrw	a0@(10:w)
	addqw	#0x1,a0@(0:w)
ADR_409e82c:
	tstl	d0
	bne	ADR_409e83a:l
	andb	#0xfe,a0@(11:w)
ADR_409e83a:
	rts
ADR_409e83c:
	addl	#0x800,a0@(8:w)
	bcc	ADR_409e868:l
	addql	#0x1,a0@(4:w)
	bcc	ADR_409e868:l
	roxrw	a0@(4:w)
	roxrw	a0@(6:w)
	roxrw	a0@(8:w)
	roxrw	a0@(10:w)
	addqw	#0x1,a0@(0:w)
ADR_409e868:
	tstl	d0
	bne	ADR_409e876:l
	andw	#0xf000,a0@(10:w)
ADR_409e876:
	andl	#0xfffff800,a0@(8:w)
	rts
	rts
ADR_409e882:
	.long	ADR_409e89e
	.long	ADR_409e7f6
	.long	ADR_409e876
	.long	ADR_409e876
ADR_409e892:
	lea	ADR_409e882:l,a1
	movel	a1@(0:b,d1:w:4),a1
	jmp	a1@
ADR_409e89e:
	rts
	.globl	nrm_zero
nrm_zero:
	movew	a0@(0:w),d0
	cmpw	#0x40,d0
	bmi	ADR_409e8b6:l
	bsr	nrm_set:l
	rts
ADR_409e8b6:
	moveml	d2/d3/d5/d6,sp@-
	movel	a0@(4:w),d1
	movel	a0@(8:w),d2
	bfffo	d1{#0,#0},d3
	beq	ADR_409e902:l
	cmpw	d3,d0
	bmi	ADR_409e8e0:l
	bsr	nrm_set:l
	moveml	sp@+,d2/d3/d5/d6
	rts
ADR_409e8e0:
	movel	d2,d6
	lsll	d0,d2
	lsll	d0,d1
	moveq	#32,d5
	subl	d0,d5
	lsrl	d5,d6
	orl	d6,d1
	moveq	#0,d0
	movew	d0,a0@(0:w)
	movel	d1,a0@(4:w)
	movel	d2,a0@(8:w)
	moveml	sp@+,d2/d3/d5/d6
	rts
ADR_409e902:
	bfffo	d2{#0,#0},d3
	beq	ADR_409e924:l
	addw	#0x20,d3
	cmpw	d3,d0
	bmi	ADR_409e8e0:l
	bsr	nrm_set:l
	moveml	sp@+,d2/d3/d5/d6
	rts
ADR_409e924:
	movew	#0x0:w,a0@(0:w)
	moveml	sp@+,d2/d3/d5/d6
	rts
	.globl	nrm_set
nrm_set:
	movel	d7,sp@-
	bfffo	a0@(4:w){#0,#0},d7
	beq	ADR_409e968:l
	movel	d6,sp@-
	subw	d7,a0@(0:w)
	movel	a0@(4:w),d0
	movel	a0@(8:w),d1
	lsll	d7,d0
	movel	d1,d6
	lsll	d7,d6
	movel	d6,a0@(8:w)
	moveq	#32,d6
	subl	d7,d6
	lsrl	d6,d1
	orl	d1,d0
	movel	d0,a0@(4:w)
	moveml	sp@+,d6/d7
	rts
ADR_409e968:
	movew	a0@(0:w),d0
	movel	a0@(8:w),d1
	subw	#0x20,d0
	bfffo	d1{#0,#0},d7
	subw	d7,d0
	lsll	d7,d1
	movew	d0,a0@(0:w)
	movel	d1,a0@(4:w)
	clrl	a0@(8:w)
	movel	sp@+,d7
	rts
	.globl	denorm
denorm:
	btst	#6,a0@(0:w)
	beq	ADR_409e99e:l
	bset	#7,a0@(0:w)
ADR_409e99e:
	cmpb	#0x0,d0
	bne	ADR_409e9c0:l
	clrl	d1
	clrl	d0
	bsr	dnrm_lp:l
	tstb	d1
	beq	ADR_409ea66:l
	bra	ADR_409ea5e:l
ADR_409e9c0:
	cmpl	#0x1,d0
	beq	ADR_409e9f6:l
	movew	#0x3c01:w,d1
	movel	d1,d0
	subw	a0@(0:w),d0
	cmpw	#0x43,d0
	bpl	ADR_409ea20:l
	clrl	d0
	bsr	dnrm_lp:l
	tstb	d1
	beq	ADR_409ea66:l
	bra	ADR_409ea5e:l
ADR_409e9f6:
	movew	#0x3f81:w,d1
	movel	d1,d0
	subw	a0@(0:w),d0
	cmpw	#0x43,d0
	bpl	ADR_409ea20:l
	clrl	d0
	bsr	dnrm_lp:l
	tstb	d1
	beq	ADR_409ea66:l
	bra	ADR_409ea5e:l
ADR_409ea20:
	tstl	a0@(4:w)
	bne	ADR_409ea3a:l
	tstl	a0@(8:w)
	bne	ADR_409ea3a:l
	bra	ADR_409ea48:l
ADR_409ea3a:
	orl	#0x208,a6@(-124:w)
	movel	#0x20000000:l,d0
ADR_409ea48:
	movew	d1,a0@(0:w)
	movel	#0x0:l,a0@(4:w)
	movel	#0x0:l,a0@(8:w)
	rts
ADR_409ea5e:
	orl	#0x208,a6@(-124:w)
ADR_409ea66:
	rts
	.globl	dnrm_lp
dnrm_lp:
	movel	d2,sp@-
	btst	#1,a6@(-220:w)
	beq	ADR_409ea82:l
	bfextu	a6@(-232:w){#6,#3},d2
	moveq	#29,d0
	lsll	d0,d2
	movel	d2,d0
ADR_409ea82:
	movel	sp@+,d2
	movel	a0@(8:w),a6@(-92:w)
	movel	d0,a6@(-88:w)
	movel	d1,d0
	subw	a0@(0:w),d1
	ble	ADR_409eab4:l
	cmpw	#0x20,d1
	blt	ADR_409eabc:l
	cmpw	#0x40,d1
	blt	ADR_409eb18:l
	bra	ADR_409eb88:l
ADR_409eab4:
	clrb	d1
	movel	a6@(-88:w),d0
	rts
ADR_409eabc:
	movel	d2,sp@-
	movew	d0,a0@(0:w)
	moveq	#32,d0
	subw	d1,d0
	bfextu	a0@(0:w){d0,#0},d2
	bfextu	d2{d1,d0},d2
	bfextu	a0@(4:w){d0,#0},d1
	bfextu	a6@(-92:w){d0,#0},d0
	movel	d2,a0@(4:w)
	movel	d1,a0@(8:w)
	clrb	d1
	bftst	d0{#2,#30}
	beq	ADR_409eaf6:l
	bset	#29,d0
	st	d1
ADR_409eaf6:
	movel	a6@(-88:w),d2
	andl	#0xe0000000,d2
	tstl	d2
	beq	ADR_409eb0e:l
	orl	#0x20000000,d0
ADR_409eb0e:
	andl	#0xe0000000,d0
	movel	sp@+,d2
	rts
ADR_409eb18:
	movel	d2,sp@-
	movew	d0,a0@(0:w)
	subw	#0x20,d1
	moveq	#32,d0
	subw	d1,d0
	bfextu	a0@(0:w){d0,#0},d2
	bfextu	d2{d1,d0},d2
	bfextu	a0@(4:w){d0,#0},d1
	bftst	d1{#2,#30}
	bne	ADR_409eb56:l
	bftst	a6@(-92:w){d0,#0}
	bne	ADR_409eb56:l
	movel	d1,d0
	clrb	d1
	bra	ADR_409eb5e:l
ADR_409eb56:
	movel	d1,d0
	bset	#29,d0
	st	d1
ADR_409eb5e:
	clrl	a0@(4:w)
	movel	d2,a0@(8:w)
	movel	a6@(-88:w),d2
	andl	#0xe0000000,d2
	tstl	d2
	beq	ADR_409eb7e:l
	orl	#0x20000000,d0
ADR_409eb7e:
	andl	#0xe0000000,d0
	movel	sp@+,d2
	rts
ADR_409eb88:
	movew	d0,a0@(0:w)
	tstw	a0@(2:w)
	bge	ADR_409eb9e:l
	orl	#0x80000000,a0@(0:w)
ADR_409eb9e:
	cmpw	#0x40,d1
	beq	ADR_409ebc4:l
	cmpw	#0x41,d1
	beq	ADR_409ebd8:l
	clrl	a0@(4:w)
	clrl	a0@(8:w)
	movel	#0x20000000:l,d0
	st	d1
	rts
ADR_409ebc4:
	movel	a0@(4:w),d0
	bfextu	d0{#2,#30},d1
	andl	#0xc0000000,d0
	bra	ADR_409ebe8:l
ADR_409ebd8:
	movel	a0@(4:w),d0
	bfextu	d0{#1,#31},d1
	andl	#0x80000000,d0
	lsrl	#1,d0
ADR_409ebe8:
	tstl	d1
	bne	ADR_409ec0c:l
	tstl	a0@(8:w)
	bne	ADR_409ec0c:l
	tstb	a6@(-88:w)
	bne	ADR_409ec0c:l
	clrb	d1
	bra	ADR_409ec12:l
ADR_409ec0c:
	bset	#29,d0
	st	d1
ADR_409ec12:
	clrl	a0@(4:w)
	clrl	a0@(8:w)
	rts
ADR_409ec1c:
	negxb	d0
	.word	0x0000
	.word	0xc90f
	addl	a2@-,d5
	movel	a0@(-15819:w),a0@(0:w)
	.word	0x0000
ADR_409ec2c:
	.word	0x3fff
	.word	0x0000
	.word	0xc90f
	addl	a2@-,d5
	movel	a0@(-15819:w),a0@(0:w)
	.word	0x0000
	.globl	sacosd
sacosd:
	.word	0xf201
	.word	0x9000
//
//	sacos.sa 1.4 10/1/90
//
//	Description: The entry point sAcos computes the inverse cosine of
//		an input argument; sAcosd does the same except for denormalized
//		input.
//
//	Input: Double-extended number X in location pointed to
//		by address register a0.
//
//	Output: The value arccos(X) returned in floating-point register Fp0.
//
//	Accuracy and Monotonicity: The returned result is within 3 ulps in
//		64 significant bit, i.e. within 0.5001 ulp to 53 bits if the
//		result is subsequently rounded to double precision. The 
//		result is provably monotonic in double precision.
//
//	Speed: The program sCOS takes approximately 310 cycles.
//
//	Algorithm:
//
//	ACOS
//	1. If |X| >= 1, go to 3.
//
//	2. (|X| < 1) Calculate acos(X) by
//		z := (1-X) / (1+X)
//		acos(X) = 2 * atan( sqrt(z) ).
//		Exit.
//
//	3. If |X| > 1, go to 5.
//
//	4. (|X| = 1) If X > 0, return 0. Otherwise, return Pi. Exit.
//
//	5. (|X| > 1) Generate an invalid operation by 0 * infinity.
//		Exit.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



	
	
	

// sacosd:
//--ACOS(X) = PI/2 FOR DENORMALIZED X
	fmovex		ADR_409ec2c,fp0
	bra		t_frcinx
	.globl	sacos
sacos:
	fmovex		a0@,fp0	// load input

	movel		a0@,d0		// pack exponent with upper 16 fraction
	movew		a0@(4),d0
	andil		#0x7fffffff,d0
	cmpil		#0x3fff8000,d0
	bge		ADR_409eca6
	fmoves	#0s1,fp1
	faddx		fp0,fp1	 	// 1+x
	fnegx		fp0	 	//  -x
	fadds	#0s1,fp0
	fdivx		fp1,fp0	 	// (1-x)/(1+x)
	fsqrtx		fp0		// sqrt((1-x)/(1+x))
	fmovemx	fp0-fp0,a0@	// overwrite input
	movel		d1,sp@-	//save original users fpcr
	clrl	d1
	bsr		satan		// atan(sqrt([1-x]/[1+x]))
	fmovel		sp@+,fpcr	//restore users exceptions
	faddx		fp0,fp0	 	// 2 * atan( stuff )
	bra		t_frcinx

// acosbig:
ADR_409eca6:
	fabsx		fp0
	fcmps	#0s1,fp0
	//  gnu //assembler generates bad floating pt branch to external symbols!
	fble	0f
	jmp		t_operr		//cause an operr exception
0:

//--|X| = 1, ACOS(X) = 0 OR PI
	movel		a0@,d0		// pack exponent with upper 16 fraction
	movew		a0@(4),d0
	cmpl		#0,d0		//d0 has original exponent+fraction
	bgt		ADR_409ece8

//--X = -1
//Returns PI and inexact exception
	fmovex		ADR_409ec1c,fp0
	fmovel		d1,fpcr
	.word	0xf23c
	.word	0x4422
	.word	0x0080
	.word	0x0000
//					;into the 040 - will not trap until next
//					;fp inst.
	bra		t_frcinx

// acosp1:
ADR_409ece8:
	fmovel		d1,fpcr
	fmoves		#0x00000000,fp0
	rts				//facos //of +1 is exact	
ADR_409ecf6:
	.word	0x3fff
	.word	0x0000
	.word	0xc90f
	addl	a2@-,d5
	movel	a0@(-15819:w),a0@(0:w)
	.word	0x0000
	.globl	sasind
sasind:
	.word	0x60ff
	.word	0xffff
	.word	0xdfc0
//
//	sasin.sa 1.5 10/1/90
//
//	Description: The entry point sAsin computes the inverse sine of
//		an input argument; sAsind does the same except for denormalized
//		input.
//
//	Input: Double-extended number X in location pointed to
//		by address register a0.
//
//	Output: The value arcsin(X) returned in floating-point register Fp0.
//
//	Accuracy and Monotonicity: The returned result is within 3 ulps in
//		64 significant bit, i.e. within 0.5001 ulp to 53 bits if the
//		result is subsequently rounded to double precision. The 
//		result is provably monotonic in double precision.
//
//	Speed: The program sASIN takes approximately 310 cycles.
//
//	Algorithm:
//
//	ASIN
//	1. If |X| >= 1, go to 3.
//
//	2. (|X| < 1) Calculate asin(X) by
//		z := sqrt( [1-X][1+X] )
//		asin(X) = atan( x / z ).
//		Exit.
//
//	3. If |X| > 1, go to 5.
//
//	4. (|X| = 1) sgn := sign(X), return asin(X) := sgn * Pi/2. Exit.
//
//	5. (|X| > 1) Generate an invalid operation by 0 * infinity.
//		Exit.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.


	.globl	sasin
sasin:
	fmovex		a0@,fp0	// load input

	movel		a0@,d0
	movew		a0@(4),d0
	andil		#0x7fffffff,d0
	cmpil		#0x3fff8000,d0
	bge		ADR_409ed64
	fmoves	#0s1,fp1
	fsubx		fp0,fp1		// 1-x
	fmovemx	fp2-fp2,a7@-
	fmoves	#0s1,fp2
	faddx		fp0,fp2		// 1+x
	fmulx		fp2,fp1		// (1+x)(1-x)
	fmovemx	a7@+,fp2-fp2
	fsqrtx		fp1		// sqrt([1-x][1+x])
	fdivx		fp1,fp0	 	// x/sqrt([1-x][1+x])
	fmovemx	fp0-fp0,a0@
	bsr		satan
	bra		t_frcinx

// asinbig:
ADR_409ed64:
	fabsx		fp0	 // |x|
	fcmps	#0s1,fp0
	.word	0xf295
	.word	0x0008
	jmp		t_operr		//cause an operr exception
0:

//--|X| = 1, ASIN(X) = +- PI/2.

	fmovex		ADR_409ecf6,fp0
	movel		a0@,d0
	andil		#0x80000000,d0	// sign bit of x
	oril		#0x3f800000,d0	// +-1 in sgl format
	movel		d0,sp@-	// push sign(x) in sgl-fmt
	fmovel		d1,fpcr		
	fmuls		sp@+,fp0
	bra		t_frcinx
//
//	satan.sa 1.5 10/1/90
//
//	The entry point satan computes the arctagent of an
//	input value. satand does the same except the input value is a
//	denormalized number.
//
//	Input: Double-extended value in memory location pointed to by address
//		register a0.
//
//	Output:	Arctan(X) returned in floating-point register Fp0.
//
//	Accuracy and Monotonicity: The returned result is within 2 ulps in
//		64 significant bit, i.e. within 0.5001 ulp to 53 bits if the
//		result is subsequently rounded to double precision. The
//		result is provably monotonic in double precision.
//
//	Speed: The program satan takes approximately 160 cycles for input
//		argument X such that 1/16 < |X| < 16. For the other arguments,
//		the program will run no worse than 10% slower.
//
//	Algorithm:
//	Step 1. If |X| >= 16 or |X| < 1/16, go to Step 5.
//
//	Step 2. Let X = sgn * 2**k * 1.xxxxxxxx...x. Note that k = -4, -3,..., or 3.
//		Define F = sgn * 2**k * 1.xxxx1, i.e. the first 5 significant bits
//		of X with a bit-1 attached at the 6-th bit position. Define u
//		to be u = (X-F) / (1 + X*F).
//
//	Step 3. Approximate arctan(u) by a polynomial poly.
//
//	Step 4. Return arctan(F) + poly, arctan(F) is fetched from a table of values
//		calculated beforehand. Exit.
//
//	Step 5. If |X| >= 16, go to Step 7.
//
//	Step 6. Approximate arctan(X) by an odd polynomial in X. Exit.
//
//	Step 7. Define X' = -1/X. Approximate arctan(X') by an odd polynomial in X'.
//		Arctan(X) = sign(X)*Pi/2 + arctan(X'). Exit.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



 	.int 0x3ffb8000,0x4002ffff
 	.int 0x3f800000

 	.int 0x00000000

ADR_409edb0:
 	.int 0xbff6687e,0x314987d8
ADR_409edb8:
 	.int 0x4002ac69,0x34a26db3

ADR_409edc0:
 	.int 0xbfc2476f,0x4e1da28e
ADR_409edc8:
 	.int 0x3fb34444,0x7f876989

ADR_409edd0:
 	.int 0xbfb744ee,0x7faf45db
ADR_409edd8:
 	.int 0x3fbc71c6,0x46940220

ADR_409ede0:
 	.int 0xbfc24924,0x921872f9
ADR_409ede8:
 	.int 0x3fc99999,0x99998fa9

ADR_409edf0:
 	.int 0xbfd55555,0x55555555
ADR_409edf8:
 	.int 0xbfb70bf3,0x98539e6a

ADR_409ee00:
 	.int 0x3fbc7187,0x962d1d7d
ADR_409ee08:
 	.int 0xbfc24924,0x827107b8

ADR_409ee10:
 	.int 0x3fc99999,0x9996263e
ADR_409ee18:
 	.int 0xbfd55555,0x55555536

ADR_409ee20:
 	.int 0x3fff0000,0xc90fdaa2,0x2168c235,0x00000000
	.word	0xbfff
	.word	0x0000
	.word	0xc90f
	addl	a2@-,d5
	movel	a0@(-15819:w),a0@(0:w)
	orb	#0x1,d0
	.word	0x0000
	.word	0x8000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x8001
	.word	0x0000
	.word	0x8000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000

// atantbl:
ADR_409ee60:
	.int	0x3ffb0000,0x83d152c5,0x060b7a51,0x00000000
	.int	0x3ffb0000,0x8bc85445,0x65498b8b,0x00000000
	.int	0x3ffb0000,0x93be4060,0x17626b0d,0x00000000
	.int	0x3ffb0000,0x9bb3078d,0x35aec202,0x00000000
	.int	0x3ffb0000,0xa3a69a52,0x5ddce7de,0x00000000
	.int	0x3ffb0000,0xab98e943,0x62765619,0x00000000
	.int	0x3ffb0000,0xb389e502,0xf9c59862,0x00000000
	.int	0x3ffb0000,0xbb797e43,0x6b09e6fb,0x00000000
	.int	0x3ffb0000,0xc367a5c7,0x39e5f446,0x00000000
	.int	0x3ffb0000,0xcb544c61,0xcff7d5c6,0x00000000
	.int	0x3ffb0000,0xd33f62f8,0x2488533e,0x00000000
	.int	0x3ffb0000,0xdb28da81,0x62404c77,0x00000000
	.word	0x3ffb
	.word	0x0000
	roxlb	#1,d0
	.word	0xa407
	divu	a3@,d5
	chkl	a0@+,d7
	.word	0x0000
ADR_409ef2e:
	.word	0x0000
	.int	0x3ffb0000,0xeaf6b0a8,0x188ee1eb,0x00000000
	.int	0x3ffb0000,0xf2daf194,0x9dbe79d5,0x00000000
	.word	0x3ffb
	.word	0x0000
	.word	0xfabd
	addqb	#0x4,a3@
	bsr	ADR_409ef2e:b
	moveq	#62,d7
	.word	0x0000
	.word	0x0000
	.int	0x3ffc0000,0x8346ac21,0x0959ecc4,0x00000000
	.int	0x3ffc0000,0x8b232a08,0x304282d8,0x00000000
	.int	0x3ffc0000,0x92fb70b8,0xd29ae2f9,0x00000000
	.int	0x3ffc0000,0x9acf476f,0x5ccd1cb4,0x00000000
	.int	0x3ffc0000,0xa29e7630,0x4954f23f,0x00000000
	.int	0x3ffc0000,0xaa68c5d0,0x8ab85230,0x00000000
	.int	0x3ffc0000,0xb22dfffd,0x9d539f83,0x00000000
	.word	0x3ffc
	.word	0x0000
	cmpl	a5@(-4283:w),a4
	movew	a0@,sp@
	movesl	a5@-,d0
	.word	0x0000
	.int	0x3ffc0000,0xc1a85f1c,0xc75e3ea5,0x00000000
	.int	0x3ffc0000,0xc95d1be8,0x28138de6,0x00000000
	.int	0x3ffc0000,0xd10bf300,0x840d2de4,0x00000000
	.int	0x3ffc0000,0xd8b4b2ba,0x6bc05e7a,0x00000000
	.int	0x3ffc0000,0xe0572a6b,0xb42335f6,0x00000000
	.int	0x3ffc0000,0xe7f32a70,0xea9caa8f,0x00000000
	.int	0x3ffc0000,0xef888432,0x64ecefaa,0x00000000
	.int	0x3ffc0000,0xf7170a28,0xecc06666,0x00000000
	.int	0x3ffd0000,0x812fd288,0x332dad32,0x00000000
	.int	0x3ffd0000,0x88a8d1b1,0x218e4d64,0x00000000
	.int	0x3ffd0000,0x9012ab3f,0x23e4aee8,0x00000000
	.int	0x3ffd0000,0x976cc3d4,0x11e7f1b9,0x00000000
	.int	0x3ffd0000,0x9eb68949,0x3889a227,0x00000000
	.int	0x3ffd0000,0xa5ef72c3,0x4487361b,0x00000000
	.int	0x3ffd0000,0xad1700ba,0xf07a7227,0x00000000
	.int	0x3ffd0000,0xb42cbcfa,0xfd37efb7,0x00000000
	.int	0x3ffd0000,0xbb303a94,0x0ba80f89,0x00000000
	.int	0x3ffd0000,0xc22115c6,0xfcaebbaf,0x00000000
	.int	0x3ffd0000,0xc8fef3e6,0x86331221,0x00000000
	.int	0x3ffd0000,0xcfc98330,0xb4000c70,0x00000000
	.int	0x3ffd0000,0xd6807aa1,0x102c5bf9,0x00000000
	.int	0x3ffd0000,0xdd2399bc,0x31252aa3,0x00000000
	.int	0x3ffd0000,0xe3b2a855,0x6b8fc517,0x00000000
	.int	0x3ffd0000,0xea2d764f,0x64315989,0x00000000
	.int	0x3ffd0000,0xf3bf5bf8,0xbad1a21d,0x00000000
	.int	0x3ffe0000,0x801ce39e,0x0d205c9a,0x00000000
	.int	0x3ffe0000,0x8630a2da,0xda1ed066,0x00000000
	.int	0x3ffe0000,0x8c1ad445,0xf3e09b8c,0x00000000
	.int	0x3ffe0000,0x91db8f16,0x64f350e2,0x00000000
	.int	0x3ffe0000,0x97731420,0x365e538c,0x00000000
	.int	0x3ffe0000,0x9ce1c8e6,0xa0b8cdba,0x00000000
	.int	0x3ffe0000,0xa22832db,0xcadaae09,0x00000000
	.int	0x3ffe0000,0xa746f2dd,0xb7602294,0x00000000
	.int	0x3ffe0000,0xac3ec0fb,0x997dd6a2,0x00000000
	.int	0x3ffe0000,0xb110688a,0xebdc6f6a,0x00000000
	.int	0x3ffe0000,0xb5bcc490,0x59ecc4b0,0x00000000
	.int	0x3ffe0000,0xba44bc7d,0xd470782f,0x00000000
	.int	0x3ffe0000,0xbea94144,0xfd049aac,0x00000000
	.int	0x3ffe0000,0xc2eb4abb,0x661628b6,0x00000000
	.int	0x3ffe0000,0xc70bd54c,0xe602ee14,0x00000000
	.int	0x3ffe0000,0xcd000549,0xadec7159,0x00000000
	.int	0x3ffe0000,0xd48457d2,0xd8ea4ea3,0x00000000
	.int	0x3ffe0000,0xdb948da7,0x12dece3b,0x00000000
	.int	0x3ffe0000,0xe23855f9,0x69e8096a,0x00000000
	.int	0x3ffe0000,0xe8771129,0xc4353259,0x00000000
	.int	0x3ffe0000,0xee57c16e,0x0d379c0d,0x00000000
	.int	0x3ffe0000,0xf3e10211,0xa87c3779,0x00000000
	.int	0x3ffe0000,0xf919039d,0x758b8d41,0x00000000
	.int	0x3ffe0000,0xfe058b8f,0x64935fb3,0x00000000
	.int	0x3fff0000,0x8155fb49,0x7b685d04,0x00000000
	.int	0x3fff0000,0x83889e35,0x49d108e1,0x00000000
	.int	0x3fff0000,0x859cfa76,0x511d724b,0x00000000
	.int	0x3fff0000,0x87952ecf,0xff8131e7,0x00000000
	.int	0x3fff0000,0x89732fd1,0x9557641b,0x00000000
	.int	0x3fff0000,0x8b38cad1,0x01932a35,0x00000000
	.int	0x3fff0000,0x8ce7a8d8,0x301ee6b5,0x00000000
	.int	0x3fff0000,0x8f46a39e,0x2eae5281,0x00000000
	.int	0x3fff0000,0x922da7d7,0x91888487,0x00000000
	.int	0x3fff0000,0x94d19fcb,0xdedf5241,0x00000000
	.int	0x3fff0000,0x973ab944,0x19d2a08b,0x00000000
	.int	0x3fff0000,0x996ff00e,0x08e10b96,0x00000000
	.int	0x3fff0000,0x9b773f95,0x12321da7,0x00000000
	.int	0x3fff0000,0x9d55cc32,0x0f935624,0x00000000
	.int	0x3fff0000,0x9f100575,0x006cc571,0x00000000
	.int	0x3fff0000,0xa0a9c290,0xd97cc06c,0x00000000
	.int	0x3fff0000,0xa22659eb,0xebc0630a,0x00000000
	.int	0x3fff0000,0xa388b4af,0xf6ef0ec9,0x00000000
	.int	0x3fff0000,0xa4d35f10,0x61d292c4,0x00000000
	.int	0x3fff0000,0xa60895dc,0xfbe3187e,0x00000000
	.int	0x3fff0000,0xa72a51dc,0x7367beac,0x00000000
	.int	0x3fff0000,0xa83a5153,0x0956168f,0x00000000
	.int	0x3fff0000,0xa93a2007,0x7539546e,0x00000000
	.int	0x3fff0000,0xaa9e7245,0x023b2605,0x00000000
	.int	0x3fff0000,0xac4c84ba,0x6fe4d58f,0x00000000
	.int	0x3fff0000,0xadce4a4a,0x606b9712,0x00000000
	.int	0x3fff0000,0xaf2a2dcd,0x8d263c9c,0x00000000
	.int	0x3fff0000,0xb0656f81,0xf22265c7,0x00000000
	.int	0x3fff0000,0xb1846515,0x0f71496a,0x00000000
	.int	0x3fff0000,0xb28aaa15,0x6f9ada35,0x00000000
	.int	0x3fff0000,0xb37b44ff,0x3766b895,0x00000000
	.int	0x3fff0000,0xb458c3dc,0xe9630433,0x00000000
	.int	0x3fff0000,0xb525529d,0x562246bd,0x00000000
	.int	0x3fff0000,0xb5e2cca9,0x5f9d88cc,0x00000000
	.int	0x3fff0000,0xb692cada,0x7aca1ada,0x00000000
	.int	0x3fff0000,0xb736aea7,0xa6925838,0x00000000
	.int	0x3fff0000,0xb7cfab28,0x7e9f7b36,0x00000000
	.int	0x3fff0000,0xb85ecc66,0xcb219835,0x00000000
	.int	0x3fff0000,0xb8e4fd5a,0x20a593da,0x00000000
	.int	0x3fff0000,0xb99f41f6,0x4aff9bb5,0x00000000
	.int	0x3fff0000,0xba7f1e17,0x842bbe7b,0x00000000
	.int	0x3fff0000,0xbb471285,0x7637e17d,0x00000000
	.int	0x3fff0000,0xbbfabe8a,0x4788df6f,0x00000000
	.int	0x3fff0000,0xbc9d0fad,0x2b689d79,0x00000000
	.int	0x3fff0000,0xbd306a39,0x471ecd86,0x00000000
	.int	0x3fff0000,0xbdb6c731,0x856af18a,0x00000000
	.int	0x3fff0000,0xbe31cac5,0x02e80d70,0x00000000
	.int	0x3fff0000,0xbea2d55c,0xe33194e2,0x00000000
	.int	0x3fff0000,0xbf0b10b7,0xc03128f0,0x00000000
	.int	0x3fff0000,0xbf6b7a18,0xdacb778d,0x00000000
	.int	0x3fff0000,0xbfc4ea46,0x63fa18f6,0x00000000
	.int	0x3fff0000,0xc0181bde,0x8b89a454,0x00000000
	.int	0x3fff0000,0xc065b066,0xcfbf6439,0x00000000
	.int	0x3fff0000,0xc0ae345f,0x56340ae6,0x00000000
	.int	0x3fff0000,0xc0f22291,0x9cb9e6a7,0x00000000
	.globl	satand
satand:
	.word	0x60ff
	.word	0xffff
	.word	0xd666

	.globl	satan
satan:
	fmovex		a0@,fp0	// load input
	movel	a0@,d0
	movew	a0@(4:w),d0
	fmovex	fp0,a6@(-116:w)

	andil		#0x7fffffff,d0
	cmpl	#0x3ffb8000,d0
	bge	ADR_409f68e:l
	bra	ADR_409f76a:l
ADR_409f68e:
	cmpl	#0x4002ffff,d0
	ble	ADR_409f6a0:l
	bra	ADR_409f800:l
ADR_409f6a0:
	movew	#0x0:w,a6@(-114:w)
	andl	#0xf8000000,a6@(-112:w)
	orl	#0x4000000,a6@(-112:w)
	movel	#0x0:l,a6@(-108:w)

	fmovex		fp0,fp1		// fp1 is x
	fmulx	a6@(-116:w),fp1
	fsubx	a6@(-116:w),fp0
	fadds	#0s1,fp1
	fdivx		fp1,fp0		// fp0 is u = (x-f)/(1+x*f)

//--WHILE THE DIVISION IS TAKING ITS TIME, WE FETCH ATAN(|F|)
//--CREATE ATAN(F) AND STORE IT IN ATANF, AND
//--SAVE REGISTERS FP2.

	movel		d2,a7@-	// save d2 temporarily
	movel		d0,d2		// the expo and 16 bits of x
	andil		#0x00007800,d0	// 4 varying bits of f's fraction
	andil		#0x7fff0000,d2	// exponent of f
	subil		#0x3ffb0000,d2	// k+4
	asrl		#1,d2
	addl		d2,d0		// the 7 bits identifying f
	asrl		#7,d0		// index into tbl of atan(|f|)
	lea		ADR_409ee60,a1
	addal		d0,a1		// address of atan(|f|)
	movel	a1@+,a6@(-100:w)
	movel	a1@+,a6@(-96:w)
	movel	a1@+,a6@(-92:w)
	movel	a6@(-116:w),d0
	andil		#0x80000000,d0	// sign(f)
	orl	d0,a6@(-100:w)
	movel		a7@+,d2	// restore d2
	fmovex		fp0,fp1
	fmulx		fp1,fp1
	fmoved		ADR_409edb0,fp2
	faddx		fp1,fp2		// a3+v
	fmulx		fp1,fp2		// v*(a3+v)
	fmulx		fp0,fp1		// u*v
	faddd		ADR_409edb8,fp2	// a2+v*(a3+v)
	fmuld		ADR_409edc0,fp1	// a1*u*v
	fmulx		fp2,fp1		// a1*u*v*(a2+v*(a3+v))
	faddx		fp1,fp0		// atan(u), fp1 released
	fmovel		d1,fpcr		//restore users exceptions
	faddx	a6@(-100:w),fp0
	bra		t_frcinx

// atanbors:
//--|X| IS IN d0 IN COMPACT FORM. FP1, d0 SAVED.
//--FP0 IS X AND |X| <= 1/16 OR |X| >= 16.
	cmpil		#0x3fff8000,d0
	bgt		ADR_409f800	// ie |x| >= 16

//--|X| <= 1/16
//--IF |X| < 2^(-40), RETURN X AS ANSWER. OTHERWISE, APPROXIMATE
//--ATAN(X) BY X + X*Y*(B1+Y*(B2+Y*(B3+Y*(B4+Y*(B5+Y*B6)))))
//--WHICH IS X + X*Y*( [B1+Z*(B3+Z*B5)] + [Y*(B2+Z*(B4+Z*B6)] )
//--WHERE Y = X*X, AND Z = Y*Y.

ADR_409f76a:
	cmpil		#0x3fd78000,d0
	blt		ADR_409f7ea
//--COMPUTE POLYNOMIAL
	fmulx		fp0,fp0	// fp0 is y = x*x
	movew	#0x0:w,a6@(-114:w)

	fmovex		fp0,fp1
	fmulx		fp1,fp1		// fp1 is z = y*y

	fmoved		ADR_409edc8,fp2
	fmoved		ADR_409edd0,fp3

	fmulx		fp1,fp2		// z*b6
	fmulx		fp1,fp3		// z*b5

	faddd		ADR_409edd8,fp2	// b4+z*b6
	faddd		ADR_409ede0,fp3	// b3+z*b5

	fmulx		fp1,fp2		// z*(b4+z*b6)
	fmulx		fp3,fp1		// z*(b3+z*b5)

	faddd		ADR_409ede8,fp2	// b2+z*(b4+z*b6)
	faddd		ADR_409edf0,fp1	// b1+z*(b3+z*b5)

	fmulx		fp0,fp2		// y*(b2+z*(b4+z*b6))
	fmulx	a6@(-116:w),fp0

	faddx		fp2,fp1		// [b1+z*(b3+z*b5)]+[y*(b2+z*(b4+z*b6))]

	fmulx		fp1,fp0	// x*y*([b1+z*(b3+z*b5)]+[y*(b2+z*(b4+z*b6))])

	fmovel		d1,fpcr		//restore users exceptions
	faddx	a6@(-116:w),fp0

	bra		t_frcinx
ADR_409f7ea:
	movew	#0x0:w,a6@(-114:w)

	fmovel		d1,fpcr		//restore users exceptions
	fmovex	a6@(-116:w),fp0

	bra		t_frcinx

// atanbig:
//--IF |X| > 2^(100), RETURN	SIGN(X)*(PI/2 - TINY). OTHERWISE,
//--RETURN SIGN(X)*PI/2 + ATAN(-1/X).
ADR_409f800:
	cmpil		#0x40638000,d0
	bgt		ADR_409f8a4
	fmoves	#0s-1,fp1
	fdivx		fp0,fp1		// fp1 is -1/x
//--DIVIDE IS STILL CRANKING

	fmovex		fp1,fp0		// fp0 is x'
	fmulx		fp0,fp0		// fp0 is y = x'*x'
	fmovex	fp1,a6@(-116:w)

	fmovex		fp0,fp1
	fmulx		fp1,fp1		// fp1 is z = y*y

	fmoved		ADR_409edf8,fp3
	fmoved		ADR_409ee00,fp2

	fmulx		fp1,fp3		// z*c5
	fmulx		fp1,fp2		// z*b4

	faddd		ADR_409ee08,fp3	// c3+z*c5
	faddd		ADR_409ee10,fp2	// c2+z*c4

	fmulx		fp3,fp1		// z*(c3+z*c5), fp3 released
	fmulx		fp0,fp2		// y*(c2+z*c4)

	faddd		ADR_409ee18,fp1	// c1+z*(c3+z*c5)
	fmulx	a6@(-116:w),fp0

	faddx		fp2,fp1		// [y*(c2+z*c4)]+[c1+z*(c3+z*c5)]

	fmulx		fp1,fp0		// x'*y*([b1+z*(b3+z*b5)]
	faddx	a6@(-116:w),fp0
	fmoveml	d1,fpc
	btst	#7,a0@
	beq	ADR_409f896:l
	.word	0xf239
	.word	0x4822
	.word	0x0409
	.word	0xee30
	.word	0x60ff
	.word	0xffff
	.word	0xd320
ADR_409f896:
	faddx		ADR_409ee20,fp0
	bra		t_frcinx
ADR_409f8a4:
	btst	#7,a0@
	beq	ADR_409f8c8:l
	.word	0xf239
	.word	0x4800
	.word	0x0409
	.word	0xee30

	fmovel		d1,fpcr		//restore users exceptions
	.word	0xf239
	.word	0x4828
	.word	0x0409
	.word	0xee50
	bra		t_frcinx
ADR_409f8c8:
	.word	0xf239
	.word	0x4800
	.word	0x0409
	.word	0xee20
	fmoveml	d1,fpc
	.word	0xf239
	.word	0x4828
	.word	0x0409
	.word	0xee40
	.word	0x60ff
	.word	0xffff
	.word	0xd2d4
	.globl	satanhd
satanhd:
	.word	0x60ff
	.word	0xffff
	.word	0xd3e4
//
//	satanh.sa 1.5 10/1/90
//
//	The entry point satanh computes the inverse
//	hyperbolic tangent of
//	an input argument; satanhd does the same except for denormalized
//	input.
//
//	Input: Double-extended number X in location pointed to
//		by address register a0.
//
//	Output: The value arctanh(X) returned in floating-point register Fp0.
//
//	Accuracy and Monotonicity: The returned result is within 3 ulps in
//		64 significant bit, i.e. within 0.5001 ulp to 53 bits if the
//		result is subsequently rounded to double precision. The 
//		result is provably monotonic in double precision.
//
//	Speed: The program satanh takes approximately 270 cycles.
//
//	Algorithm:
//
//	ATANH
//	1. If |X| >= 1, go to 3.
//
//	2. (|X| < 1) Calculate atanh(X) by
//		sgn := sign(X)
//		y := |X|
//		z := 2y/(1-y)
//		atanh(X) := sgn * (1/2) * logp1(z)
//		Exit.
//
//	3. If |X| > 1, go to 5.
//
//	4. (|X| = 1) Generate infinity with an appropriate sign and
//		divide-by-zero by	
//		sgn := sign(X)
//		atan(X) := sgn / (+0).
//		Exit.
//
//	5. (|X| > 1) Generate an invalid operation by 0 * infinity.
//		Exit.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.


	.globl	satanh
satanh:
	movel		a0@,d0
	movew		a0@(4),d0
	andil		#0x7fffffff,d0
	cmpil		#0x3fff8000,d0
	bge		ADR_409f948

//--THIS IS THE USUAL CASE, |X| < 1
//--Y = |X|, Z = 2Y/(1-Y), ATANH(X) = SIGN(X) * (1/2) * LOG1P(Z).

	fabsx		a0@,fp0	// y = |x|
	fmovex		fp0,fp1
	fnegx		fp1		// -y
	faddx		fp0,fp0		// 2y
	fadds	#0s1,fp1
	fdivx		fp1,fp0		// 2y/(1-y)
	movel		a0@,d0
	andil		#0x80000000,d0
	oril		#0x3f000000,d0	// sign(x)*half
	movel		d0,sp@-

	fmovemx	fp0-fp0,a0@	// overwrite input
	movel		d1,sp@-
	clrl	d1
	bsr		slognp1		// log1p(z)
	fmovel		sp@+,fpcr
	fmuls		sp@+,fp0
	bra		t_frcinx

// atanhbig:
ADR_409f948:
	fabsx		a0@,fp0	// |x|
	fcmps	#0s1,fp0
	fble	ADR_409f95e:w
	jmp		t_operr		//cause an operr exception
ADR_409f95e:
	.word	0x60ff
	.word	0xffff
	.word	0xd072
	.word	0x3fff
	.word	0x400c
	.globl	sscale
sscale:
	fmoveml	#0x0:l,fpc
	clrl	d1
	movew	a6@(-216:w),d1
	smi	a6@(-84:w)
	andl	#0x7fff,d1
	movew	a6@(-204:w),d0
	andw	#0x7fff,d0
	.word	0x02f9
	.word	0x0000
	.word	0x0409
	.word	0xf964
	bcc	ADR_409f9d4:l
	cmpw	#0x400c,d0
	.word	0x6cff
	.word	0x0000
	.word	0x038c
	moveb	a6@(-224:w),d0
	andb	#0xe0,d0
	tstb	d0
	beq	ADR_409f9c6:l
	st	a6@(-76:w)
	orl	#0x800,a6@(-124:w)
	lea	a6@(-216:w),a0
	.word	0x60ff
	.word	0xffff
	.word	0xd314
ADR_409f9c6:
	fmoveml	a6@(-128:w),fpc
	fmovex	a6@(-216:w),fp0
	rts
ADR_409f9d4:
	fmovex	a6@(-204:w),fp0
	fmoveml	#0x10:l,fpc
	fmovel	fp0,d0
	fmoveml	#0x0:l,fps
	tstw	a6@(-204:w)
	blt	ADR_409faa6:l
	tstw	d1
	beq	ADR_409fc82:l
	addl	d0,d1
	beq	ADR_409fa5a:l
	cmpl	#0x7fff,d1
	bge	ADR_409fa34:l
	tstb	a6@(-84:w)
	beq	ADR_409fa22:l
	orw	#0x8000,d1
ADR_409fa22:
	movew	d1,a6@(-216:w)
	fmoveml	a6@(-128:w),fpc
	fmovex	a6@(-216:w),fp0
	rts
ADR_409fa34:
	tstb	a6@(-84:w)
	beq	ADR_409fa42:l
	orw	#0x8000,d1
ADR_409fa42:
	movew	a6@(-216:w),a6@(-204:w)
	movel	a6@(-212:w),a6@(-200:w)
	movel	a6@(-208:w),a6@(-196:w)
	.word	0x60ff
	.word	0xffff
	.word	0xd084
ADR_409fa5a:
	tstb	a6@(-84:w)
	beq	ADR_409fa68:l
	orw	#0x8000,d1
ADR_409fa68:
	tstl	a6@(-212:w)
	blt	ADR_409fa94:l
	movew	d1,a6@(-204:w)
	movel	a6@(-212:w),a6@(-200:w)
	movel	a6@(-208:w),a6@(-196:w)
	orl	#0x3,a6@(-124:w)
	lea	a6@(-204:w),a0
	.word	0x60ff
	.word	0xffff
	.word	0xd246
ADR_409fa94:
	movew	d1,a6@(-216:w)
	fmoveml	a6@(-128:w),fpc
	fmovex	a6@(-216:w),fp0
	rts
ADR_409faa6:
	addl	d0,d1
	beq	ADR_409fa5a:l
	blt	ADR_409fad4:l
	tstb	a6@(-84:w)
	beq	ADR_409fac2:l
	orw	#0x8000,d1
ADR_409fac2:
	movew	d1,a6@(-216:w)
	fmoveml	a6@(-128:w),fpc
	fmovex	a6@(-216:w),fp0
	rts
ADR_409fad4:
	cmpw	#0xffc0,d1
	blt	ADR_409fbe2:l
	movew	d1,d0
	movel	d2,sp@-
	movel	a6@(-212:w),d1
	movel	a6@(-208:w),d2
	clrl	a6@(-80:w)
ADR_409faee:
	addqw	#0x1,d0
	lsrl	#1,d1
	roxrl	#1,d2
	bcc	ADR_409fafe:l
	st	a6@(-80:w)
ADR_409fafe:
	tstw	d0
	blt	ADR_409faee:l
	tstb	a6@(-80:w)
	beq	ADR_409fb18:l
	orl	#0x828,a6@(-124:w)
ADR_409fb18:
	clrw	a6@(-216:w)
	tstb	a6@(-84:w)
	beq	ADR_409fb2c:l
	orw	#0x8000,a6@(-216:w)
ADR_409fb2c:
	movel	d1,a6@(-212:w)
	movel	d2,a6@(-208:w)
	movel	sp@+,d2
	tstl	d1
	bne	ADR_409fbc2:l
	tstl	a6@(-208:w)
	bne	ADR_409fbc2:l
	btst	#5,a6@(-125:w)
	beq	ADR_409fb98:l
	btst	#4,a6@(-125:w)
	beq	ADR_409fb78:l
	tstb	a6@(-84:w)
	bne	ADR_409fb98:l
	movel	#0x1:l,a6@(-208:w)
	bra	ADR_409fba6:l
ADR_409fb78:
	tstb	a6@(-84:w)
	beq	ADR_409fb98:l
	movel	#0x1:l,a6@(-208:w)
	orl	#0x8000000,a6@(-124:w)
	bra	ADR_409fba6:l
ADR_409fb98:
	fmoveml	a6@(-128:w),fpc
	fmovex	a6@(-216:w),fp0
	rts
ADR_409fba6:
	movel	a6@(-216:w),a6@(-204:w)
	movel	a6@(-212:w),a6@(-200:w)
	movel	a6@(-208:w),a6@(-196:w)
	lea	a6@(-204:w),a0
	.word	0x60ff
	.word	0xffff
	.word	0xd118
ADR_409fbc2:
	orl	#0x800,a6@(-124:w)
	tstb	a6@(-84:w)
	beq	ADR_409fbdc:l
	orl	#0x8000000,a6@(-124:w)
ADR_409fbdc:
	bra	ADR_409fba6:l
ADR_409fbe2:
	orl	#0x828,a6@(-124:w)
	btst	#5,a6@(-125:w)
	beq	ADR_409fc4c:l
	btst	#4,a6@(-125:w)
	beq	ADR_409fc22:l
	tstb	a6@(-84:w)
	bne	ADR_409fc4c:l
	clrl	a6@(-216:w)
	clrl	a6@(-212:w)
	movel	#0x1:l,a6@(-208:w)
	bra	ADR_409fba6:l
ADR_409fc22:
	tstb	a6@(-84:w)
	beq	ADR_409fc4c:l
	movew	#0x8000:w,a6@(-216:w)
	clrl	a6@(-212:w)
	movel	#0x1:l,a6@(-208:w)
	orl	#0x8000000,a6@(-124:w)
	bra	ADR_409fba6:l
ADR_409fc4c:
	tstb	a6@(-84:w)
	bge	ADR_409fc6c:l
	clrl	a6@(-116:w)
	clrl	a6@(-112:w)
	clrl	a6@(-108:w)
	.word	0xf23c
	.word	0x4400
	.word	0x8000
	.word	0x0000
	rts
ADR_409fc6c:
	clrl	a6@(-116:w)
	clrl	a6@(-112:w)
	clrl	a6@(-108:w)
	fmoves	#0s0,fp0
	rts
ADR_409fc82:
	moveml	d2/d3,sp@-
	movew	a6@(-216:w),d1
	movel	a6@(-212:w),d2
	movel	a6@(-208:w),d3
	tstl	d2
	.word	0x6dff
	.word	0x0000
	.word	0x001c
	tstl	d0
	.word	0x67ff
	.word	0x0000
	.word	0x004a
	.word	0x0480
	.word	0x0000
	.word	0x0001
	lsll	#1,d3
	roxll	#1,d2
	.word	0x60ff
	.word	0xffff
	.word	0xffe4
	addw	d0,d1
	tstb	a6@(-84:w)
	beq	ADR_409fcc4:l
	orl	#0x8000,d1
ADR_409fcc4:
	movemw	d1,a6@(-216:w)
	moveml	d2,a6@(-212:w)
	moveml	d3,a6@(-208:w)
	fmoveml	a6@(-128:w),fpc
	fmovex	a6@(-216:w),fp0
	moveml	sp@+,d2/d3
	rts
	tstb	a6@(-84:w)
	beq	ADR_409fd00:l
	orl	#0x8000000,a6@(-124:w)
	orl	#0x8000,d1
ADR_409fd00:
	movemw	d1,a6@(-204:w)
	moveml	d2,a6@(-200:w)
	moveml	d3,a6@(-196:w)
	orl	#0x800,a6@(-124:w)
	moveml	sp@+,d2/d3
	lea	a6@(-204:w),a0
	.word	0x60ff
	.word	0xffff
	.word	0xcfb2
	tstb	a6@(-84:w)
	beq	ADR_409fd38:l
	orl	#0x8000,d1
ADR_409fd38:
	movel	a6@(-212:w),a6@(-200:w)
	movel	a6@(-208:w),a6@(-196:w)
	tstw	a6@(-204:w)
	blt	ADR_409fd58:l
	movew	d1,a6@(-204:w)
	.word	0x60ff
	.word	0xffff
	.word	0xcd86
ADR_409fd58:
	movew	d1,a6@(-204:w)
	lea	a6@(-204:w),a0
	.word	0x60ff
	.word	0xffff
	.word	0xccfa
ADR_409fd66:
	movew	sr,d6
	movel	0xd3d6:w,a6@-
	.word	0x4634
ADR_409fd6e:
	.word	0x3d6f
	.word	0x90ae
	.word	0xb1e7
	.word	0x5cc7
ADR_409fd76:
	.word	0x7ffb
	.word	0x0000
	.word	0x8000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.globl	scoshd
scoshd:
	.word	0xf23c
	.word	0x4400
	.word	0x3f80
	.word	0x0000
//
//	scosh.sa 1.5 10/4/90
//
//	The entry point sCosh computes the hyperbolic cosine of
//	an input argument; sCoshd does the same except for denormalized
//	input.
//
//	Input: Double-extended number X in location pointed to
//		by address register a0.
//
//	Output: The value cosh(X) returned in floating-point register Fp0.
//
//	Accuracy and Monotonicity: The returned result is within 3 ulps in
//		64 significant bit, i.e. within 0.5001 ulp to 53 bits if the
//		result is subsequently rounded to double precision. The
//		result is provably monotonic in double precision.
//
//	Speed: The program sCOSH takes approximately 250 cycles.
//
//	Algorithm:
//
//	COSH
//	1. If |X| > 16380 log2, go to 3.
//
//	2. (|X| <= 16380 log2) Cosh(X) is obtained by the formulae
//		y = |X|, z = exp(Y), and
//		cosh(X) = (1/2)*( z + 1/z ).
//		Exit.
//
//	3. (|X| > 16380 log2). If |X| > 16480 log2, go to 5.
//
//	4. (16380 log2 < |X| <= 16480 log2)
//		cosh(X) = sign(X) * exp(|X|)/2.
//		However, invoking exp(|X|) may cause premature overflow.
//		Thus, we calculate sinh(X) as follows:
//		Y	:= |X|
//		Fact	:=	2**(16380)
//		Y'	:= Y - 16381 log2
//		cosh(X) := Fact * exp(Y').
//		Exit.
//
//	5. (|X| > 16480 log2) sinh(X) must overflow. Return
//		Huge*Huge to generate overflow and an infinity with
//		the appropriate sign. Huge is the largest finite number in
//		extended format. Exit.
//
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



	fmovel		d1,fpcr
	.word	0xf23c
	.word	0x4422
	.word	0x0080
	.word	0x0000
	bra		t_frcinx

	.globl	scosh
scosh:
	fmovex		a0@,fp0	// load input

	movel		a0@,d0
	movew		a0@(4),d0
	andil		#0x7fffffff,d0
	cmpil		#0x400cb167,d0
	bgt		ADR_409fdf2

//--THIS IS THE USUAL CASE, |X| < 16380 LOG2
//--COSH(X) = (1/2) * ( EXP(X) + 1/EXP(X) )

	fabsx		fp0		// |x|

	movel		d1,sp@-
	clrl	d1
	fmovemx	fp0-fp0,a0@	//pass parameter to setox
	bsr		setox		// fp0 is exp(|x|)
	fmuls	#0s0.5,fp0
	movel		sp@+,d1
	fmoves	#0s0.25,fp1
	fdivx		fp0,fp1	 	// 1/(2 exp(|x|))

	fmovel		d1,fpcr
	faddx		fp1,fp0

	bra		t_frcinx

// coshbig:
ADR_409fdf2:
	cmpil		#0x400cb2b3,d0
	bgt	ADR_409fe32:l

	fabsx		fp0
	fsubd		ADR_409fd66,fp0			// (|x|-16381log2_lead)
	fsubd		ADR_409fd6e,fp0			// |x| - 16381 log2, accurate

	movel		d1,sp@-
	clrl	d1
	fmovemx	fp0-fp0,a0@
	bsr		setox
	fmovel		sp@+,fpcr

	fmulx		ADR_409fd76,fp0
	bra		t_frcinx
ADR_409fe32:
	fmoveml	#0x0:l,fps

// coshhuge:
	bclr		#7,a0@		//always return positive value
	.word	0xf210
	.word	0xd080
	.word	0x60ff
	.word	0xffff
	.word	0xcd06
//
//	setox.sa 1.5 10/1/90
//
//	The entry point setox computes the exponential of a value.
//	setoxd does the same except the input value is a denormalized
//	number.	setoxm1 computes exp(X)-1, and setoxm1d computes
//	exp(X)-1 for denormalized X.
//
//	INPUT
//	-----
//	Double-extended value in memory location pointed to by address
//	register a0.
//
//	OUTPUT
//	------
//	exp(X) or exp(X)-1 returned in floating-point register fp0.
//
//	ACCURACY and MONOTONICITY
//	-------------------------
//	The returned result is within 0.85 ulps in 64 significant bit, i.e.
//	within 0.5001 ulp to 53 bits if the result is subsequently rounded
//	to double precision. The result is provably monotonic in double
//	precision.
//
//	SPEED
//	-----
//	Two timings are measured, both in the copy-back mode. The
//	first one is measured when the function is invoked the first time
//	(so the instructions and data are not in cache), and the
//	second one is measured when the function is reinvoked at the same
//	input argument.
//
//	The program setox takes approximately 210/190 cycles for input
//	argument X whose magnitude is less than 16380 log2, which
//	is the usual situation.	For the less common arguments,
//	depending on their values, the program may run faster or slower --
//	but no worse than 10% slower even in the extreme cases.
//
//	The program setoxm1 takes approximately ???/??? cycles for input
//	argument X, 0.25 <= |X| < 70log2. For |X| < 0.25, it takes
//	approximately ???/??? cycles. For the less common arguments,
//	depending on their values, the program may run faster or slower --
//	but no worse than 10% slower even in the extreme cases.
//
//	ALGORITHM and IMPLEMENTATION NOTES
//	----------------------------------
//
//	setoxd
//	------
//	Step 1.	Set ans := 1.0
//
//	Step 2.	Return	ans := ans + sign(X)*2^(-126). Exit.
//	Notes:	This will always generate one exception -- inexact.
//
//
//	setox
//	-----
//
//	Step 0.	Save FPCR in D1. Set FPCR to default.
//	Notes:	Default means round-to-nearest mode, no floating-point
//		 traps, and precision control = double extended.
//
//	Step 1.	Filter out extreme cases of input argument.
//		1.1	If |X| >= 2^(-65), go to Step 1.3.
//		1.2	Go to Step 7.
//		1.3	If |X| < 16380 log(2), go to Step 2.
//		1.4	Go to Step 8.
//	Notes:	The usual case should take the branches 1.1 -> 1.3 -> 2.
//		 To avoid the use of floating-point comparisons, a
//		 compact representation of |X| is used. This format is a
//		 32-bit integer, the upper (more significant) 16 bits are
//		 the sign and biased exponent field of |X|; the lower 16
//		 bits are the 16 most significant fraction (including the
//		 explicit bit) bits of |X|. Consequently, the comparisons
//		 in Steps 1.1 and 1.3 can be performed by integer comparison.
//		 Note also that the constant 16380 log(2) used in Step 1.3
//		 is also in the compact form. Thus taking the branch
//		 to Step 2 guarantees |X| < 16380 log(2). There is no harm
//		 to have a small number of cases where |X| is less than,
//		 but close to, 16380 log(2) and the branch to Step 9 is
//		 taken.
//
//	Step 2.	Calculate N = round-to-nearest-int( X * 64/log2 ).
//		2.1	Set AdjFlag := 0 (indicates the branch 1.3 -> 2 was taken)
//		2.2	N := round-to-nearest-integer( X * 64/log2 ).
//		2.3	Calculate	J = N mod 64; so J = 0,1,2,..., or 63.
//		2.4	Calculate	M = (N - J)/64; so N = 64M + J.
//		2.5	Calculate the address of the stored value of 2^(J/64).
//		2.6	Create the value Scale = 2^M.
//	Notes:	The calculation in 2.2 is really performed by
//
//			Z := X * constant
//			N := round-to-nearest-integer(Z)
//
//		 where
//
//			constant := single-precision( 64/log 2 ).
//
//		 Using a single-precision constant avoids memory access.
//		 Another effect of using a single-precision "constant" is
//		 that the calculated value Z is
//
//			Z = X*(64/log2)*(1+eps), |eps| <= 2^(-24).
//
//		 This error has to be considered later in Steps 3 and 4.
//
//	Step 3.	Calculate X - N*log2/64.
//		3.1	R := X + N*L1, where L1 := single-precision(-log2/64).
//		3.2	R := R + N*L2, L2 := extended-precision(-log2/64 - L1).
//	Notes:	a) The way L1 and L2 are chosen ensures L1+L2 approximate
//		 the value	-log2/64	to 88 bits of accuracy.
//		 b) N*L1 is exact because N is no longer than 22 bits and
//		 L1 is no longer than 24 bits.
//		 c) The calculation X+N*L1 is also exact due to cancellation.
//		 Thus, R is practically X+N(L1+L2) to full 64 bits.
//		 d) It is important to estimate how large can |R| be after
//		 Step 3.2.
//
//			N = rnd-to-int( X*64/log2 (1+eps) ), |eps|<=2^(-24)
//			X*64/log2 (1+eps)	=	N + f,	|f| <= 0.5
//			X*64/log2 - N	=	f - eps*X 64/log2
//			X - N*log2/64	=	f*log2/64 - eps*X
//
//
//		 Now |X| <= 16446 log2, thus
//
//			|X - N*log2/64| <= (0.5 + 16446/2^(18))*log2/64
//					<= 0.57 log2/64.
//		 This bound will be used in Step 4.
//
//	Step 4.	Approximate exp(R)-1 by a polynomial
//			p = R + R*R*(A1 + R*(A2 + R*(A3 + R*(A4 + R*A5))))
//	Notes:	a) In order to reduce memory access, the coefficients are
//		 made as "short" as possible: A1 (which is 1/2), A4 and A5
//		 are single precision; A2 and A3 are double precision.
//		 b) Even with the restrictions above,
//			|p - (exp(R)-1)| < 2^(-68.8) for all |R| <= 0.0062.
//		 Note that 0.0062 is slightly bigger than 0.57 log2/64.
//		 c) To fully utilize the pipeline, p is separated into
//		 two independent pieces of roughly equal complexities
//			p = [ R + R*S*(A2 + S*A4) ]	+
//				[ S*(A1 + S*(A3 + S*A5)) ]
//		 where S = R*R.
//
//	Step 5.	Compute 2^(J/64)*exp(R) = 2^(J/64)*(1+p) by
//				ans := T + ( T*p + t)
//		 where T and t are the stored values for 2^(J/64).
//	Notes:	2^(J/64) is stored as T and t where T+t approximates
//		 2^(J/64) to roughly 85 bits; T is in extended precision
//		 and t is in single precision. Note also that T is rounded
//		 to 62 bits so that the last two bits of T are zero. The
//		 reason for such a special form is that T-1, T-2, and T-8
//		 will all be exact --- a property that will give much
//		 more accurate computation of the function EXPM1.
//
//	Step 6.	Reconstruction of exp(X)
//			exp(X) = 2^M * 2^(J/64) * exp(R).
//		6.1	If AdjFlag = 0, go to 6.3
//		6.2	ans := ans * AdjScale
//		6.3	Restore the user FPCR
//		6.4	Return ans := ans * Scale. Exit.
//	Notes:	If AdjFlag = 0, we have X = Mlog2 + Jlog2/64 + R,
//		 |M| <= 16380, and Scale = 2^M. Moreover, exp(X) will
//		 neither overflow nor underflow. If AdjFlag = 1, that
//		 means that
//			X = (M1+M)log2 + Jlog2/64 + R, |M1+M| >= 16380.
//		 Hence, exp(X) may overflow or underflow or neither.
//		 When that is the case, AdjScale = 2^(M1) where M1 is
//		 approximately M. Thus 6.2 will never cause over/underflow.
//		 Possible exception in 6.4 is overflow or underflow.
//		 The inexact exception is not generated in 6.4. Although
//		 one can argue that the inexact flag should always be
//		 raised, to simulate that exception cost to much than the
//		 flag is worth in practical uses.
//
//	Step 7.	Return 1 + X.
//		7.1	ans := X
//		7.2	Restore user FPCR.
//		7.3	Return ans := 1 + ans. Exit
//	Notes:	For non-zero X, the inexact exception will always be
//		 raised by 7.3. That is the only exception raised by 7.3.
//		 Note also that we use the FMOVEM instruction to move X
//		 in Step 7.1 to avoid unnecessary trapping. (Although
//		 the FMOVEM may not seem relevant since X is normalized,
//		 the precaution will be useful in the library version of
//		 this code where the separate entry for denormalized inputs
//		 will be done away with.)
//
//	Step 8.	Handle exp(X) where |X| >= 16380log2.
//		8.1	If |X| > 16480 log2, go to Step 9.
//		(mimic 2.2 - 2.6)
//		8.2	N := round-to-integer( X * 64/log2 )
//		8.3	Calculate J = N mod 64, J = 0,1,...,63
//		8.4	K := (N-J)/64, M1 := truncate(K/2), M = K-M1, AdjFlag := 1.
//		8.5	Calculate the address of the stored value 2^(J/64).
//		8.6	Create the values Scale = 2^M, AdjScale = 2^M1.
//		8.7	Go to Step 3.
//	Notes:	Refer to notes for 2.2 - 2.6.
//
//	Step 9.	Handle exp(X), |X| > 16480 log2.
//		9.1	If X < 0, go to 9.3
//		9.2	ans := Huge, go to 9.4
//		9.3	ans := Tiny.
//		9.4	Restore user FPCR.
//		9.5	Return ans := ans * ans. Exit.
//	Notes:	Exp(X) will surely overflow or underflow, depending on
//		 X's sign. "Huge" and "Tiny" are respectively large/tiny
//		 extended-precision numbers whose square over/underflow
//		 with an inexact result. Thus, 9.5 always raises the
//		 inexact together with either overflow or underflow.
//
//
//	setoxm1d
//	--------
//
//	Step 1.	Set ans := 0
//
//	Step 2.	Return	ans := X + ans. Exit.
//	Notes:	This will return X with the appropriate rounding
//		 precision prescribed by the user FPCR.
//
//	setoxm1
//	-------
//
//	Step 0.	Save FPCR in d1. Set FPCR to default.
//	Notes:	Default means round-to-nearest mode, no floating-point
//		 traps, and precision control = double extended.
//
//	Step 1.	Check |X|
//		1.1	If |X| >= 1/4, go to Step 1.3.
//		1.2	Go to Step 7.
//		1.3	If |X| < 70 log(2), go to Step 2.
//		1.4	Go to Step 10.
//	Notes:	The usual case should take the branches 1.1 -> 1.3 -> 2.
//		 However, it is conceivable |X| can be small very often
//		 because EXPM1 is intended to evaluate exp(X)-1 accurately
//		 when |X| is small. For further details on the comparisons,
//		 see the notes on Step 1 of setox.
//
//	Step 2.	Calculate N = round-to-nearest-int( X * 64/log2 ).
//		2.1	N := round-to-nearest-integer( X * 64/log2 ).
//		2.2	Calculate	J = N mod 64; so J = 0,1,2,..., or 63.
//		2.3	Calculate	M = (N - J)/64; so N = 64M + J.
//		2.4	Calculate the address of the stored value of 2^(J/64).
//		2.5	Create the values Sc = 2^M and OnebySc := -2^(-M).
//	Notes:	See the notes on Step 2 of setox.
//
//	Step 3.	Calculate X - N*log2/64.
//		3.1	R := X + N*L1, where L1 := single-precision(-log2/64).
//		3.2	R := R + N*L2, L2 := extended-precision(-log2/64 - L1).
//	Notes:	Applying the analysis of Step 3 of setox in this case
//		 shows that |R| <= 0.0055 (note that |X| <= 70 log2 in
//		 this case).
//
//	Step 4.	Approximate exp(R)-1 by a polynomial
//			p = R+R*R*(A1+R*(A2+R*(A3+R*(A4+R*(A5+R*A6)))))
//	Notes:	a) In order to reduce memory access, the coefficients are
//		 made as "short" as possible: A1 (which is 1/2), A5 and A6
//		 are single precision; A2, A3 and A4 are double precision.
//		 b) Even with the restriction above,
//			|p - (exp(R)-1)| <	|R| * 2^(-72.7)
//		 for all |R| <= 0.0055.
//		 c) To fully utilize the pipeline, p is separated into
//		 two independent pieces of roughly equal complexity
//			p = [ R*S*(A2 + S*(A4 + S*A6)) ]	+
//				[ R + S*(A1 + S*(A3 + S*A5)) ]
//		 where S = R*R.
//
//	Step 5.	Compute 2^(J/64)*p by
//				p := T*p
//		 where T and t are the stored values for 2^(J/64).
//	Notes:	2^(J/64) is stored as T and t where T+t approximates
//		 2^(J/64) to roughly 85 bits; T is in extended precision
//		 and t is in single precision. Note also that T is rounded
//		 to 62 bits so that the last two bits of T are zero. The
//		 reason for such a special form is that T-1, T-2, and T-8
//		 will all be exact --- a property that will be exploited
//		 in Step 6 below. The total relative error in p is no
//		 bigger than 2^(-67.7) compared to the final result.
//
//	Step 6.	Reconstruction of exp(X)-1
//			exp(X)-1 = 2^M * ( 2^(J/64) + p - 2^(-M) ).
//		6.1	If M <= 63, go to Step 6.3.
//		6.2	ans := T + (p + (t + OnebySc)). Go to 6.6
//		6.3	If M >= -3, go to 6.5.
//		6.4	ans := (T + (p + t)) + OnebySc. Go to 6.6
//		6.5	ans := (T + OnebySc) + (p + t).
//		6.6	Restore user FPCR.
//		6.7	Return ans := Sc * ans. Exit.
//	Notes:	The various arrangements of the expressions give accurate
//		 evaluations.
//
//	Step 7.	exp(X)-1 for |X| < 1/4.
//		7.1	If |X| >= 2^(-65), go to Step 9.
//		7.2	Go to Step 8.
//
//	Step 8.	Calculate exp(X)-1, |X| < 2^(-65).
//		8.1	If |X| < 2^(-16312), goto 8.3
//		8.2	Restore FPCR; return ans := X - 2^(-16382). Exit.
//		8.3	X := X * 2^(140).
//		8.4	Restore FPCR; ans := ans - 2^(-16382).
//		 Return ans := ans*2^(140). Exit
//	Notes:	The idea is to return "X - tiny" under the user
//		 precision and rounding modes. To avoid unnecessary
//		 inefficiency, we stay away from denormalized numbers the
//		 best we can. For |X| >= 2^(-16312), the straightforward
//		 8.2 generates the inexact exception as the case warrants.
//
//	Step 9.	Calculate exp(X)-1, |X| < 1/4, by a polynomial
//			p = X + X*X*(B1 + X*(B2 + ... + X*B12))
//	Notes:	a) In order to reduce memory access, the coefficients are
//		 made as "short" as possible: B1 (which is 1/2), B9 to B12
//		 are single precision; B3 to B8 are double precision; and
//		 B2 is double extended.
//		 b) Even with the restriction above,
//			|p - (exp(X)-1)| < |X| 2^(-70.6)
//		 for all |X| <= 0.251.
//		 Note that 0.251 is slightly bigger than 1/4.
//		 c) To fully preserve accuracy, the polynomial is computed
//		 as	X + ( S*B1 +	Q ) where S = X*X and
//			Q	=	X*S*(B2 + X*(B3 + ... + X*B12))
//		 d) To fully utilize the pipeline, Q is separated into
//		 two independent pieces of roughly equal complexity
//			Q = [ X*S*(B2 + S*(B4 + ... + S*B12)) ] +
//				[ S*S*(B3 + S*(B5 + ... + S*B11)) ]
//
//	Step 10.	Calculate exp(X)-1 for |X| >= 70 log 2.
//		10.1 If X >= 70log2 , exp(X) - 1 = exp(X) for all practical
//		 purposes. Therefore, go to Step 1 of setox.
//		10.2 If X <= -70log2, exp(X) - 1 = -1 for all practical purposes.
//		 ans := -1
//		 Restore user FPCR
//		 Return ans := ans + 2^(-126). Exit.
//	Notes:	10.2 will always create an inexact and return -1 + tiny
//		 in the user rounding precision and mode.
//
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.


ADR_409fe48:
 	.int	0x3fdc0000,0x82e30865,0x4361c4c6
	.word	0x0000
	.word	0x0000
ADR_409fe58:
	.word	0x3fa5
	.word	0x5555
	subqw	#0x2,a5@
	.word	0x4431
ADR_409fe60:
	.word	0x3fc5
	subqw	#0x2,a5@
	subqw	#0x2,a5@
	negxb	a0@+
	.word	0x7ffe
	.word	0x0000
	.word	0xffff
	.word	0xffff
	.word	0xffff
	.word	0xffff
	.word	0x0000
	.word	0x0000
	orb	#0x0,d1
	.word	0xffff
	.word	0xffff
	.word	0xffff
	.word	0xffff
	.word	0x0000
	.word	0x0000

ADR_409fe88:
 	.int	0x3f811111,0x11174385
ADR_409fe90:
 	.int	0x3fa55555,0x55554f5a

ADR_409fe98:
 	.int	0x3fc55555,0x55555555,0x00000000,0x00000000

ADR_409fea8:
 	.int	0x3ec71de3,0xa5774682
ADR_409feb0:
 	.int	0x3efa01a0,0x19d7cb68

ADR_409feb8:
 	.int	0x3f2a01a0,0x1a019df3
ADR_409fec0:
 	.int	0x3f56c16c,0x16c170e2

ADR_409fec8:
 	.int	0x3f811111,0x11111111
ADR_409fed0:
 	.int	0x3fa55555,0x55555555

ADR_409fed8:
 	.int	0x3ffc0000,0xaaaaaaaa,0xaaaaaaab
	.word	0x0000
	.word	0x0000

ADR_409fee8:
 	.int	0x48b00000,0x00000000
ADR_409fef0:
 	.int	0x37300000,0x00000000

// exptbl: 
ADR_409fef8:
	.int	0x3fff0000,0x80000000,0x00000000,0x00000000
	.int	0x3fff0000,0x8164d1f3,0xbc030774,0x9f841a9b
	.int	0x3fff0000,0x82cd8698,0xac2ba1d8,0x9fc1d5b9
	.int	0x3fff0000,0x843a28c3,0xacde4048,0xa0728369
	.int	0x3fff0000,0x85aac367,0xcc487b14,0x1fc5c95c
	.int	0x3fff0000,0x871f6196,0x9e8d1010,0x1ee85c9f
	.word	0x3fff
	.word	0x0000
	.word	0x8898
	.word	0x0e80
	.word	0x92da
	orb	d2,a0@(-24670:w)
	btst	d3,a1@(16383:w)
	.word	0x0000
	.word	0x8a14
	.word	0xd575
	.word	0x496e
	.word	0xfd9c
	.word	0xa07b
	.word	0xf9af
	.int	0x3fff0000,0x8b95c1e3,0xea8bd6e8,0xa0020dcf
	.int	0x3fff0000,0x8d1adf5b,0x7e5ba9e4,0x205a63da
	.int	0x3fff0000,0x8ea4398b,0x45cd53c0,0x1eb70051
	.int	0x3fff0000,0x9031dc43,0x1466b1dc,0x1f6eb029
	.int	0x3fff0000,0x91c3d373,0xab11c338,0xa0781494
	.int	0x3fff0000,0x935a2b2f,0x13e6e92c,0x9eb319b0
	.int	0x3fff0000,0x94f4efa8,0xfef70960,0x2017457d
	.int	0x3fff0000,0x96942d37,0x20185a00,0x1f11d537
	.int	0x3fff0000,0x9837f051,0x8db8a970,0x9fb952dd
	.int	0x3fff0000,0x99e04593,0x20b7fa64,0x1fe43087
	.int	0x3fff0000,0x9b8d39b9,0xd54e5538,0x1fa2a818
	.int	0x3fff0000,0x9d3ed9a7,0x2cffb750,0x1fde494d
	.int	0x3fff0000,0x9ef53260,0x91a111ac,0x20504890
	.int	0x3fff0000,0xa0b0510f,0xb9714fc4,0xa073691c
	.int	0x3fff0000,0xa2704303,0x0c496818,0x1f9b7a05
	.word	0x3fff
	.word	0x0000
	.word	0xa435
	.word	0x15ae
	.word	0x09e6
	.word	0x80a0
	.word	0xa079
	.word	0x7126
	.word	0x3fff
	.word	0x0000
	.word	0xa5fe
	addl	a1@(-20143:w),d3
	movew	a4@(-24463:w),a4@+
	.word	0xa140
	.int	0x3fff0000,0xa7cd93b4,0xe9653568,0x204f62da
	.int	0x3fff0000,0xa9a15ab4,0xea7c0ef8,0x1f283c4a
	.int	0x3fff0000,0xab7a39b5,0xa93ed338,0x9f9a7fdc
	.int	0x3fff0000,0xad583eea,0x42a14ac8,0xa05b3fac
	.int	0x3fff0000,0xaf3b78ad,0x690a4374,0x1fdf2610
	.word	0x3fff
	.word	0x0000
	.word	0xb123
	.word	0xf581
	addl	a4@(9616:w),d1
	subw	d7,@(0,d5:l:8)
	.int	0x3fff0000,0xb311c412,0xa9112488,0x201f678a
	.int	0x3fff0000,0xb504f333,0xf9de6484,0x1f32fb13
	.int	0x3fff0000,0xb6fd91e3,0x28d17790,0x20038b30
	.int	0x3fff0000,0xb8fbaf47,0x62fb9ee8,0x200dc3cc
	.int	0x3fff0000,0xbaff5ab2,0x133e45fc,0x9f8b2ae6
	.int	0x3fff0000,0xbd08a39f,0x580c36c0,0xa02bbf70
	.int	0x3fff0000,0xbf1799b6,0x7a731084,0xa00bf518
	.int	0x3fff0000,0xc12c4cca,0x66709458,0xa041dd41
	.int	0x3fff0000,0xc346ccda,0x24976408,0x9fdf137b
	.word	0x3fff
	.word	0x0000
	.word	0xc567
	.word	0x2a11
	.word	0x5506
	.word	0xdadc
	movel	sp@+,d0
	moveb	a0@(16383:w),a2@(0:w)
	exg	d3,a5
	moveq	#-56,d2
	.word	0xabb9
	eorw	d0,a4@+
	.word	0x1fc1
	movew	a6@(16383:w),d5
	.word	0x0000
	.word	0xc9b9
	eorl	d6,d6
	.word	0x6e2f
	movel	a4@-,a3@(63:b,a2:w:1)
	sbcd	d3,d7
	.int	0x3fff0000,0xcbec14fe,0xf2727c5c,0x1ff4907d
	.int	0x3fff0000,0xce248c15,0x1f8480e4,0x9e6e53e4
	.int	0x3fff0000,0xd06333da,0xef2b2594,0x1fd6d45c
	.int	0x3fff0000,0xd2a81d91,0xf12ae45c,0xa076edb9
	.int	0x3fff0000,0xd4f35aab,0xcfedfa20,0x9fa6de21
	.int	0x3fff0000,0xd744fcca,0xd69d6af4,0x1ee69a2f
	.int	0x3fff0000,0xd99d15c2,0x78afd7b4,0x207f439f
	.int	0x3fff0000,0xdbfbb797,0xdaf23754,0x201ec207
	.int	0x3fff0000,0xde60f482,0x5e0e9124,0x9e8be175
	.int	0x3fff0000,0xe0ccdeec,0x2a94e110,0x20032c4b
	.int	0x3fff0000,0xe33f8972,0xbe8a5a50,0x2004dff5
	.int	0x3fff0000,0xe5b906e7,0x7c8348a8,0x1e72f47a
	.int	0x3fff0000,0xe8396a50,0x3c4bdc68,0x1f722f22
	.int	0x3fff0000,0xeac0c6e7,0xdd243930,0xa017e945
	.int	0x3fff0000,0xed4f301e,0xd9942b84,0x1f401a5b
	.int	0x3fff0000,0xefe4b99b,0xdcdaf5cc,0x9fb9a9e3
	.int	0x3fff0000,0xf281773c,0x59ffb138,0x20744c05
	.word	0x3fff
	.word	0x0000
	.word	0xf525
	.word	0x7d15
	movel	d6,a2@
	andb	a4@(8055:w),d6
	movew	a1@+,d5
	.int	0x3fff0000,0xf7d0df73,0x0ad13bb8,0x1ffe90d5
	.int	0x3fff0000,0xfa83b2db,0x722a033c,0xa041ed22
	.int	0x3fff0000,0xfd3e0c0c,0xf486c174,0x1f853f3a
	.globl	setoxd
setoxd:
	movel		a0@,d0
	andil		#0x80000000,d0
	oril		#0x00800000,d0		// sign(x)*2^(-126)
	movel		d0,sp@-
	.word	0xf23c
	.word	0x4400
	.word	0x3f80
	.word	0x0000
	fmovel		d1,fpcr
	fadds		sp@+,fp0
	bra		t_frcinx

//--Step 1.
	.globl	setox
setox:
	movel		a0@,d0	 // load part of input x
	andil		#0x7fff0000,d0	// biased expo of x
	cmpil		#0x3fbe0000,d0	// 2^(-65)
	bge		ADR_40a0338		// normal case
	bra		ADR_40a044e

// expc1:
//--The case |X| >= 2^(-65)
ADR_40a0338:
	movew		a0@(4),d0	// expo and partial sig of |x|
	cmpil		#0x400cb167,d0	// 16380 log2 trunc 16 bits
	blt		ADR_40a034e	 // normal case
	bra		ADR_40a0464

// expmain:
//--Step 2.
//--This is the normal branch:	2^(-65) <= |X| < 16380 log2.
ADR_40a034e:
	fmovex		a0@,fp0	// load input from (a0)

	fmovex		fp0,fp1
	fmuls	#0s92.332481,fp0
	fmovemx	fp2/fp3,sp@-
	movel	#0x0:l,a6@(-80:w)
	fmovel		fp0,d0		// n = int( x * 64/log2 )
	lea		ADR_409fef8,a1
	fmovel		d0,fp0		// convert to floating-format

	movel		d0,a6@(l_scr1)	// save n temporarily
	andil		#0x3f,d0		// d0 is j = n mod 64
	lsll		#4,d0
	addal		d0,a1		// address of 2^(j/64)
	movel		a6@(l_scr1),d0
	asrl		#6,d0		// d0 is m
	addiw		#0x3fff,d0	// biased expo of 2^(m)
	movew		ADR_409fe48,a6@(l_scr1)	// prefetch l2, no need in cb

// expcont1:
//--Step 3.
//--fp1,fp2 saved on the stack. fp0 is N, fp1 is X,
//--a0 points to 2^(J/64), D0 is biased expo. of 2^(M)
ADR_40a0398:
	fmovex		fp0,fp2
	.word	0xf23c
	.word	0x4423
	.word	0xbc31
	.word	0x7218
	fmulx		ADR_409fe48,fp2		// n * l2, l1+l2 = -log2/64
	faddx		fp1,fp0	 	// x + n*l1
	faddx		fp2,fp0		// fp0 is r, reduced arg

//--Step 4.
//--WE NOW COMPUTE EXP(R)-1 BY A POLYNOMIAL
//-- R + R*R*(A1 + R*(A2 + R*(A3 + R*(A4 + R*A5))))
//--TO FULLY UTILIZE THE PIPELINE, WE COMPUTE S = R*R
//--[R+R*S*(A2+S*A4)] + [S*(A1+S*(A3+S*A5))]

	fmovex		fp0,fp1
	fmulx		fp1,fp1	 	// fp1 is s = r*r
	.word	0xf23c
	.word	0x4500
	.word	0x3ab6
	.word	0x0b70

	fmulx		fp1,fp2	 	// fp2 is s*a5
	fmovex		fp1,fp3
	.word	0xf23c
	.word	0x45a3
	.word	0x3c08
	.word	0x8895

	faddd		ADR_409fe58,fp2	// fp2 is a3+s*a5
	faddd		ADR_409fe60,fp3	// fp3 is a2+s*a4

	fmulx		fp1,fp2	 	// fp2 is s*(a3+s*a5)
	movew	d0,a6@(-116:w)
	clrw	a6@(-114:w)
	movel	#0x80000000:l,a6@(-112:w)
	clrl	a6@(-108:w)
	fmulx		fp1,fp3	 	// fp3 is s*(a2+s*a4)
	fadds	#0s0.5,fp2
	fmulx		fp0,fp3	 	// fp3 is r*s*(a2+s*a4)

	fmulx		fp1,fp2	 	// fp2 is s*(a1+s*(a3+s*a5))
	faddx		fp3,fp0	 	// fp0 is r+r*s*(a2+s*a4),
//					...fp3 released

	fmovex		a1@+,fp1	// fp1 is lead pt of 2^(j/64)
	faddx		fp2,fp0	 	// fp0 is exp(r) - 1

//--Step 5
//--final reconstruction process
//--EXP(X) = 2^M * ( 2^(J/64) + 2^(J/64)*(EXP(R)-1) )

	fmulx		fp1,fp0	 	// 2^(j/64)*(exp(r)-1)
	fmovemx	sp@+,fp2/fp3
	fadds		a1@,fp0	// accurate 2^(j/64)

	faddx		fp1,fp0	 	// 2^(j/64) + 2^(j/64)*// 
	movel	a6@(-80:w),d0

//--Step 6
	tstl		d0
	beq		ADR_40a043e
	fmulx	a6@(-100:w),fp0
// normal:
ADR_40a043e:
	fmovel		d1,fpcr	 	// restore user fpcr
	fmulx	a6@(-116:w),fp0
	bra		t_frcinx

// expsm:
//--Step 7
ADR_40a044e:
	fmovemx	a0@,fp0-fp0	// in case x is denormalized
	fmovel		d1,fpcr
	fadds	#0s1,fp0
	bra		t_frcinx

// expbig:
//--Step 8
ADR_40a0464:
	cmpil		#0x400cb27c,d0	// 16480 log2
	bgt		ADR_40a04de
//--Steps 8.2 -- 8.6
	fmovex		a0@,fp0	// load input from (a0)

	fmovex		fp0,fp1
	fmuls	#0s92.332481,fp0
	fmovemx	fp2/fp3,sp@-
	movel	#0x1:l,a6@(-80:w)
	fmovel		fp0,d0		// n = int( x * 64/log2 )
	lea		ADR_409fef8,a1
	fmovel		d0,fp0		// convert to floating-format
	movel		d0,a6@(l_scr1)			// save n temporarily
	andil		#0x3f,d0		 // d0 is j = n mod 64
	lsll		#4,d0
	addal		d0,a1			// address of 2^(j/64)
	movel		a6@(l_scr1),d0
	asrl		#6,d0			// d0 is k
	movel		d0,a6@(l_scr1)			// save k temporarily
	asrl		#1,d0			// d0 is m1
	subl		d0,a6@(l_scr1)			// a1 is m
	addiw		#0x3fff,d0		// biased expo of 2^(m1)
	movew	d0,a6@(-100:w)
	clrw	a6@(-98:w)
	movel	#0x80000000:l,a6@(-96:w)
	clrl	a6@(-92:w)
	movel		a6@(l_scr1),d0			// d0 is m
	addiw		#0x3fff,d0		// biased expo of 2^(m)
	bra		ADR_40a0398		// go back to step 3

// exp2big:
//--Step 9
ADR_40a04de:
	fmovel		d1,fpcr
	movel		a0@,d0
	bclr	#7,a0@
	cmpil		#0,d0
	blt		t_unfl
	.word	0x60ff
	.word	0xffff
	.word	0xc654
	.globl	setoxm1d
setoxm1d:
	.word	0x60ff
	.word	0xffff
	.word	0xc7cc

//--Step 1.
//--Step 1.1
	.globl	setoxm1
setoxm1:
	movel		a0@,d0	 // load part of input x
	andil		#0x7fff0000,d0	// biased expo of x
	cmpil		#0x3ffd0000,d0	// 1/4
	bge		ADR_40a051a	 // |x| >= 1/4
	bra		ADR_40a0692

// em1con1:
//--Step 1.3
//--The case |X| >= 1/4
ADR_40a051a:
	movew		a0@(4),d0	// expo and partial sig of |x|
	cmpil		#0x4004c215,d0	// 70log2 rounded up to 16 bits
	ble		ADR_40a0530	 // 1/4 <= |x| <= 70log2
	bra		ADR_40a07c4

// em1main:
//--Step 2.
//--This is the case:	1/4 <= |X| <= 70 log2.
ADR_40a0530:
	fmovex		a0@,fp0	// load input from (a0)

	fmovex		fp0,fp1
	fmuls	#0s92.332481,fp0
	fmovemx	fp2/fp3,sp@-
	fmovel		fp0,d0		// n = int( x * 64/log2 )
	lea		ADR_409fef8,a1
	fmovel		d0,fp0		// convert to floating-format

	movel		d0,a6@(l_scr1)			// save n temporarily
	andil		#0x3f,d0		 // d0 is j = n mod 64
	lsll		#4,d0
	addal		d0,a1			// address of 2^(j/64)
	movel		a6@(l_scr1),d0
	asrl		#6,d0			// d0 is m
	movel		d0,a6@(l_scr1)			// save a copy of m

//--Step 3.
//--fp1,fp2 saved on the stack. fp0 is N, fp1 is X,
//--a0 points to 2^(J/64), D0 and a1 both contain M
	fmovex		fp0,fp2
	.word	0xf23c
	.word	0x4423
	.word	0xbc31
	.word	0x7218
	fmulx		ADR_409fe48,fp2		// n * l2, l1+l2 = -log2/64
	faddx		fp1,fp0	 // x + n*l1
	faddx		fp2,fp0	 // fp0 is r, reduced arg
	addiw		#0x3fff,d0		// d0 is biased expo of 2^m

//--Step 4.
//--WE NOW COMPUTE EXP(R)-1 BY A POLYNOMIAL
//-- R + R*R*(A1 + R*(A2 + R*(A3 + R*(A4 + R*(A5 + R*A6)))))
//--TO FULLY UTILIZE THE PIPELINE, WE COMPUTE S = R*R
//--[R*S*(A2+S*(A4+S*A6))] + [R+S*(A1+S*(A3+S*A5))]

	fmovex		fp0,fp1
	fmulx		fp1,fp1		// fp1 is s = r*r
	.word	0xf23c
	.word	0x4500
	.word	0x3950
	.word	0x097b

	fmulx		fp1,fp2		// fp2 is s*a6
	fmovex		fp1,fp3
	.word	0xf23c
	.word	0x45a3
	.word	0x3ab6
	.word	0x0b6a

	faddd		ADR_409fe88,fp2	// fp2 is a4+s*a6
	faddd		ADR_409fe90,fp3	// fp3 is a3+s*a5
	movew	d0,a6@(-64:w)
	clrw	a6@(-62:w)
	movel	#0x80000000:l,a6@(-60:w)
	clrl	a6@(-56:w)

	fmulx		fp1,fp2		// fp2 is s*(a4+s*a6)
	movel		a6@(l_scr1),d0		// d0 is	m
	negw		d0		// d0 is -m
	fmulx		fp1,fp3		// fp3 is s*(a3+s*a5)
	addiw		#0x3fff,d0	// biased expo of 2^(-m)
	faddd		ADR_409fe98,fp2	// fp2 is a2+s*(a4+s*a6)
	fadds	#0s0.5,fp3

	fmulx		fp1,fp2		// fp2 is s*(a2+s*(a4+s*a6))
	oriw		#0x8000,d0	// signed/expo of -2^(-m)
	movew	d0,a6@(-48:w)
	clrw	a6@(-46:w)
	movel	#0x80000000:l,a6@(-44:w)
	clrl	a6@(-40:w)
	fmulx		fp3,fp1		// fp1 is s*(a1+s*(a3+s*a5))
//					...fp3 released

	fmulx		fp0,fp2		// fp2 is r*s*(a2+s*(a4+s*a6))
	faddx		fp1,fp0		// fp0 is r+s*(a1+s*(a3+s*a5))

	faddx		fp2,fp0		// fp0 is exp(r)-1
	fmovemx	sp@+,fp2/fp3

//--Step 5
//--Compute 2^(J/64)*p

	fmulx		a1@,fp0	// 2^(j/64)*(exp(r)-1)

//--Step 6
//--Step 6.1
	movel		a6@(l_scr1),d0		// retrieve m
	cmpil		#63,d0
	ble		ADR_40a064e
//--Step 6.2	M >= 64
	fmoves		a1@(12),fp1	// fp1 is t
	faddx	a6@(-48:w),fp1
	faddx		fp1,fp0		// p+(t+onebysc), fp1 released
	faddx		a1@,fp0	// t+(p+(t+onebysc))
	bra		ADR_40a0682
// mle63:
//--Step 6.3	M <= 63
ADR_40a064e:
	cmpil		#-3,d0
	bge		ADR_40a0670
// mltn3:
//--Step 6.4	M <= -4
	fadds		a1@(12),fp0	// p+t
	faddx		a1@,fp0	// t+(p+t)
	faddx	a6@(-48:w),fp0
	bra		ADR_40a0682
// mgen3:
//--Step 6.5	-3 <= M <= 63
ADR_40a0670:
	fmovex		a1@+,fp1	// fp1 is t
	fadds		a1@,fp0	// fp0 is p+t
	faddx	a6@(-48:w),fp1
	faddx		fp1,fp0		// (t+onebysc)+(p+t)

// em1scale:
//--Step 6.6
ADR_40a0682:
	fmovel		d1,fpcr
	fmulx	a6@(-64:w),fp0

	bra		t_frcinx

// em1sm:
//--Step 7	|X| < 1/4.
ADR_40a0692:
	cmpil		#0x3fbe0000,d0	// 2^(-65)
	bge		ADR_40a070a

// em1tiny:
//--Step 8	|X| < 2^(-65)
	cmpil		#0x00330000,d0	// 2^(-16312)
	blt		ADR_40a06d2
	movel	#0x80010000:l,a6@(-64:w)
	movel	#0x80000000:l,a6@(-60:w)
	clrl	a6@(-56:w)
	fmovex		a0@,fp0
	fmovel		d1,fpcr
	faddx	a6@(-64:w),fp0

	bra		t_frcinx

// em12tiny:
//--Step 8.3
ADR_40a06d2:
	fmovex		a0@,fp0
	fmuld		ADR_409fee8,fp0
	movel	#0x80010000:l,a6@(-64:w)
	movel	#0x80000000:l,a6@(-60:w)
	clrl	a6@(-56:w)
	faddx	a6@(-64:w),fp0
	fmovel		d1,fpcr
	fmuld		ADR_409fef0,fp0

	bra		t_frcinx

// em1poly:
//--Step 9	exp(X)-1 by a simple polynomial
ADR_40a070a:
	fmovex		a0@,fp0	// fp0 is x
	fmulx		fp0,fp0		// fp0 is s := x*x
	fmovemx	fp2/fp3,sp@-
	.word	0xf23c
	.word	0x4480
	.word	0x2f30
	.word	0xcaa8
	fmulx		fp0,fp1		// fp1 is s*b12
	.word	0xf23c
	.word	0x4500
	.word	0x310f
	.word	0x8290
	.word	0xf23c
	.word	0x44a2
	.word	0x32d7
	.word	0x3220

	fmulx		fp0,fp2		// fp2 is s*b11
	fmulx		fp0,fp1		// fp1 is s*(b10 + // 
	.word	0xf23c
	.word	0x4522
	.word	0x3493
	.word	0xf281
	faddd		ADR_409fea8,fp1	// fp1 is b8+s*// 

	fmulx		fp0,fp2		// fp2 is s*(b9+// 
	fmulx		fp0,fp1		// fp1 is s*(b8+// 

	faddd		ADR_409feb0,fp2	// fp2 is b7+s*// 
	faddd		ADR_409feb8,fp1	// fp1 is b6+s*// 

	fmulx		fp0,fp2		// fp2 is s*(b7+// 
	fmulx		fp0,fp1		// fp1 is s*(b6+// 

	faddd		ADR_409fec0,fp2	// fp2 is b5+s*// 
	faddd		ADR_409fec8,fp1	// fp1 is b4+s*// 

	fmulx		fp0,fp2		// fp2 is s*(b5+// 
	fmulx		fp0,fp1		// fp1 is s*(b4+// 

	faddd		ADR_409fed0,fp2	// fp2 is b3+s*// 
	faddx		ADR_409fed8,fp1	// fp1 is b2+s*// 

	fmulx		fp0,fp2		// fp2 is s*(b3+// 
	fmulx		fp0,fp1		// fp1 is s*(b2+// 

	fmulx		fp0,fp2		// fp2 is s*s*(b3+// )
	fmulx		a0@,fp1	// fp1 is x*s*(b2// 
	fmuls	#0s0.5,fp0
	faddx		fp2,fp1		// fp1 is q
	fmovemx	sp@+,fp2/fp3

	faddx		fp1,fp0		// fp0 is s*b1+q

	fmovel		d1,fpcr
	faddx		a0@,fp0

	bra		t_frcinx

// em1big:
//--Step 10	|X| > 70 log2
ADR_40a07c4:
	movel		a0@,d0
	cmpil		#0,d0
	bgt		ADR_40a0338
	fmoves	#0s-1,fp0
	fmovel		d1,fpcr
	.word	0xf23c
	.word	0x4422
	.word	0x0080
	.word	0x0000

	bra		t_frcinx
	.globl	sgetexp
sgetexp:
	movew	a0@(0:w),d0
	bclr	#15,d0
	subw	#0x3fff,d0
	fmovew	d0,fp0
	rts
	.globl	sgetexpd
sgetexpd:
	bclr	#7,a0@(0:w)
	.word	0x61ff
	.word	0xffff
	.word	0xe12a
	movew	a0@(0:w),d0
	subw	#0x3fff,d0
	fmovew	d0,fp0
	rts
	.globl	sgetman
sgetman:
	movel	a6@(-128:w),d0
	andl	#0xffffff00,d0
	fmoveml	d0,fpc
	movew	a0@(0:w),d0
	orw	#0x7fff,d0
	bclr	#14,d0
	movew	d0,a0@(0:w)
	fmovex	a0@,fp0
	rts
	.globl	sgetmand
sgetmand:
	movel	a0@(4:w),d0
	movel	a0@(8:w),d1
	bsr	ADR_40a0858:l
	movel	d0,a0@(4:w)
	movel	d1,a0@(8:w)
	bra	sgetman:l
ADR_40a0858:
	tstl	d0
	bne	ADR_40a0880:l
	tstl	d1
	bne	ADR_40a086e:l
	bra	ADR_40a089a:l
ADR_40a086e:
	movel	d3,sp@-
	exg	d0,d1
	bfffo	d0{#0,#0},d3
	lsll	d3,d0
	movel	sp@+,d3
	bra	ADR_40a089a:l
ADR_40a0880:
	moveml	d3/d5/d6,sp@-
	bfffo	d0{#0,#0},d3
	lsll	d3,d0
	movel	d1,d6
	lsll	d3,d1
	moveq	#32,d5
	subl	d3,d5
	lsrl	d5,d6
	orl	d6,d0
	moveml	sp@+,d3/d5/d6
ADR_40a089a:
	rts
//
//	sint.sa 1.9 10/1/90
//
//	The entry point sINT computes the rounded integer 
//	equivalent of the input argument, sINTRZ computes 
//	the integer rounded to zero of the input argument.
//
//	Entry points sint and sintrz are called from do_func
//	to emulate the fint and fintrz unimplemented instructions,
//	respectively.  Entry point sintdo is used by bindec.
//
//	Input: (Entry points sint and sintrz) Double-extended
//		number X in the ETEMP space in the floating-point
//		save stack.
//	       (Entry point sintdo) Double-extended number X in
//		location pointed to by the address register a0.
//
//	Output: The function returns int(X) or intrz(X) in fp0.
//
//	Modifies: fp0.
//
//	Algorithm:
//
//	1. If exp(X) >= 63, return X. 
//	
//	2. (X is in range) set rsc = 63 - exp(X). Unnormalize the
//	   result to the exponent $403e.
//
//	3. Round the result in the mode given in USER_FPCR.
//
//	4. Normalize the rounded result; store in fp0.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.


	.globl	sint
sint:
	bfextu	a6@(fpcr_mode){#2:#2},d1	//use user's mode for rounding
//					;implicity has extend precision
//					;in upper word. 
	movel	d1,a6@(l_scr1)		//save mode bits
	bra	ADR_40a0924			
	.globl	sintd
sintd:
	btst	#5,a6@(-125:w)
	.word	0x67ff
	.word	0xffff
	.word	0xafc0
	btst	#4,a6@(-125:w)
	beq	ADR_40a08dc:l
	btst	#7,a0@(0:w)
	bne	ADR_40a0900:l
	.word	0x61ff
	.word	0xffff
	.word	0xb464
	.word	0x60ff
	.word	0xffff
	.word	0xc2d0
ADR_40a08dc:
	btst	#7,a0@(0:w)
	beq	ADR_40a08f4:l
	.word	0x61ff
	.word	0xffff
	.word	0xb456
	.word	0x60ff
	.word	0xffff
	.word	0xc2b8
ADR_40a08f4:
	.word	0x61ff
	.word	0xffff
	.word	0xb45c
	.word	0x60ff
	.word	0xffff
	.word	0xc2ac
ADR_40a0900:
	.word	0x61ff
	.word	0xffff
	.word	0xb462
	.word	0x60ff
	.word	0xffff
	.word	0xc2a0
	.globl	sintrz
sintrz:
	movel	#1,a6@(l_scr1)		//use rz mode for rounding
//					;implicity has extend precision
//					;in upper word. 
	bra	ADR_40a0924			
//
//	SINTDO
//
//	Input:	a0 points to an IEEE extended format operand
// 	Output:	fp0 has the result 
//
// Exeptions:
//
// If the subroutine results in an inexact operation, the inx2 and
// ainx bits in the USER_FPSR are set.
//
//
// sintdo:
	.globl	sintdo
sintdo:
	bfextu	a6@(fpcr_mode){#2:#2},d1	//use user's mode for rounding
//					;implicity has extend precision
//					;in upper word. 
	movel	d1,a6@(l_scr1)		//save mode bits
//
// Real work of sint is in sintexc
//
// sintexc:
ADR_40a0924:
	bclr	#sign_bit,a0@(local_ex)	//convert to internal extended
//					;format
	sne	a0@(local_sgn)		
	cmpw	#0x403e,a0@(local_ex)	//check if (unbiased) exp > 63
	bgt	ADR_40a09c6:l
	cmpw	#0x3ffd,a0@(0:w)
	bgt	ADR_40a09f0:l
	btst	#1,a6@(-81:w)
	beq	ADR_40a09a4:l
	tstb	a0@(2:w)
	bne	ADR_40a0980:l
	cmpb	#0x3,a6@(-81:w)
	beq	ADR_40a0974:l
	.word	0x61ff
	.word	0xffff
	.word	0xb3e8
	.word	0x60ff
	.word	0xffff
	.word	0xc238
ADR_40a0974:
	.word	0x61ff
	.word	0xffff
	.word	0xb3c0
	.word	0x60ff
	.word	0xffff
	.word	0xc22c
ADR_40a0980:
	cmpb	#0x2,a6@(-81:w)
	beq	ADR_40a0998:l
	.word	0x61ff
	.word	0xffff
	.word	0xb3d6
	.word	0x60ff
	.word	0xffff
	.word	0xc214
ADR_40a0998:
	.word	0x61ff
	.word	0xffff
	.word	0xb3a6
	.word	0x60ff
	.word	0xffff
	.word	0xc208
ADR_40a09a4:
	tstb	a0@(2:w)
	bne	ADR_40a09ba:l
	.word	0x61ff
	.word	0xffff
	.word	0xb3a2
	.word	0x60ff
	.word	0xffff
	.word	0xc1f2
ADR_40a09ba:
	.word	0x61ff
	.word	0xffff
	.word	0xb3a8
	.word	0x60ff
	.word	0xffff
	.word	0xc1e6

ADR_40a09c6:
	bfclr	a0@(local_sgn){#0:#8}	//change back to ieee ext format
	beq	ADR_40a09d8
	bset	#sign_bit,a0@(local_ex)
// intps:
ADR_40a09d8:
	fmovel	fpcr,sp@-
	fmovel	#0,fpcr
	fmovex a0@(local_ex),fp0	//if exp > 63
//					;then return X to the user
//					;there are no fraction bits
	fmovel	sp@+,fpcr
	rts

// in_rnge:
// 					;shift off fraction bits
ADR_40a09f0:
	clrl	d0			//clear d0 - initial g,r,s for
//					;dnrm_lp
	movel	#0x403e,d1		//set threshold for dnrm_lp
//					;assumes a0 points to operand
	bsr	dnrm_lp
//					;returns unnormalized number
//					;pointed by a0
//					;output d0 supplies g,r,s
//					;used by round
	movel	a6@(l_scr1),d1		//use selected rounding mode
	.word	0x61ff
	.word	0xffff
	.word	0xdca6

//
//	NRM_RND
//input:
//	a0 = pointer to operand
//output:
//	fp0 = result
//
// nrm_rnd:
	bsr	nrm_set			//normalize the unnorm
//					;Input: a0 points to operand to
//					;be normalized
//					;Output: a0 points to normalized
//					;result
	bfclr	a0@(local_sgn){#0:#8}
	beq	ADR_40a0a20
	bset	#sign_bit,a0@(local_ex)	//return to ieee extended format
// nrmrndp:
ADR_40a0a20:
	fmovel	fpcr,sp@-
	fmovel	#0,fpcr
	fmovex a0@(local_ex),fp0	//move result to fp0
	fmovel	sp@+,fpcr
	rts
	movel	d0,sp@-
	fsave	sp@-
	moveb	sp@,d0
	beq	ADR_40a0a50:l
	clrl	d0
	moveb	sp@(1:w),d0
	bset	#3,sp@(0:b,d0:l:1)
ADR_40a0a50:
	frestore	sp@+
	movel	sp@+,d0
	jmp	std_trap:l
	.globl	dz
dz:
	cmpb	#0x0,_cpu_type:l
	bne	real_dz:b
	.word	0x4ef9
	.word	0x040a
	.word	0x0a38
//
//	skeleton.sa 1.6 10/2/90
//
//	This file contains code that is system dependent and will
//	need to be modified to install the FPSP.
//
//	Each entry point for exception 'xxxx' begins with a 'jmp fpsp_xxxx'.
//	Put any target system specific handling that must be done immediately
//	before the jump instruction.  If there no handling necessary, then
//	the 'fpsp_xxxx' handler entry point should be placed in the exception
//	table so that the 'jmp' can be eliminated. If the FPSP determines that the
//	exception is one that must be reported then there will be a
//	return from the package by a 'jmp real_xxxx'.  At that point
//	the machine state will be identical to the state before
//	the FPSP was entered.  In particular, whatever condition
//	that caused the exception will still be pending when the FPSP
//	package returns.  Thus, there will be system specific code
//	to handle the exception.
//
//	If the exception was completely handled by the package, then
//	the return will be via a 'jmp fpsp_done'.  Unless there is 
//	OS specific work to be done (such as handling a context switch or
//	interrupt) the user program can be resumed via 'rte'.
//
//	In the following skeleton code, some typical 'real_xxxx' handling
//	code is shown.  This code may need to be moved to an appropriate
//	place in the target system, or rewritten.
//	

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



	

//
//	Divide by Zero exception
//
//	All dz exceptions are 'real', hence no fpsp_dz entry point.
//
// real_dz:
	.globl	real_dz
real_dz:
	link		a6,#-local_size
	fsave		sp@-
	bclr		#e1,a6@(e_byte)
	frestore	sp@+
	unlk		a6
	addql	#0x1,fpsp_cnt3:l
	jmp	std_trap:l
	.globl	inex
inex:
	cmpb	#0x0,_cpu_type:l
	bne	ADR_40a0a96:b
	.word	0x4ef9
	.word	0x040a
	.word	0x0a38
ADR_40a0a96:
	linkw	a6,#0xff40
	fsave	sp@-
	cmpb	#0x40,sp@
	bne	ADR_40a0b10:l
	fmoveml	fps,sp@-
	btst	#2,a6@(-220:w)
	beq	ADR_40a0afe:l
	btst	#6,sp@(2:w)
	beq	ADR_40a0ace:l
	addql	#0x4,sp
// inex_done:
	frestore	sp@+
	unlk		a6
	bra	snan:l
ADR_40a0ace:
	btst	#4,sp@(2:w)
	beq	ADR_40a0ae6:l
	addql	#0x4,sp
	frestore	sp@+
	unlk	a6
	bra	ovfl:l
ADR_40a0ae6:
	btst	#3,sp@(2:w)
	beq	ADR_40a0afe:l
	addql	#0x4,sp
	frestore	sp@+
	unlk	a6
	bra	unfl:l
ADR_40a0afe:
	addql	#0x4,sp
	frestore	sp@+
	unlk	a6
	.globl	real_inex
real_inex:
	addql	#0x1,fpsp_cnt2:l
	linkw	a6,#0xff40
	fsave	sp@-
ADR_40a0b10:
	bclr	#1,a6@(-220:w)
	beq	ADR_40a0b3e:l
	moveml	d0/d1,a6@(-192:w)
	bfextu	a6@(-228:w){#6,#3},d0
	bclr	d0,a6@(-283:w)
	.word	0x61ff
	.word	0xffff
	.word	0xa69e
	moveml	a6@(-192:w),d0/d1
	bra	ADR_40a0b44:l
ADR_40a0b3e:
	bclr		#e1,a6@(e_byte)
// ovfl_done:
ADR_40a0b44:
	frestore	sp@+
	unlk		a6
	jmp	std_trap:l
	.globl	ovfl
ovfl:
	cmpb	#0x0,_cpu_type:l
	bne	ADR_40a0b5e:b
	.word	0x4ef9
	.word	0x040a
	.word	0x0a38
ADR_40a0b5e:
	.word	0x4ef9
	.word	0x040a
	.word	0x4c48
	.globl	real_ovfl
real_ovfl:
	addql	#0x1,fpsp_cnt5:l
	linkw	a6,#0xff40
	fsave	sp@-
	bclr	#1,a6@(-220:w)
	bne	ADR_40a0b82:l
	bclr	#2,a6@(-220:w)
ADR_40a0b82:
	frestore	sp@+
	unlk	a6
	jmp	std_trap:l
	.globl	unfl
unfl:
	cmpb	#0x0,_cpu_type:l
	bne	ADR_40a0b9c:b
	.word	0x4ef9
	.word	0x040a
	.word	0x0a38
ADR_40a0b9c:
	.word	0x4ef9
	.word	0x040a
	.word	0x520e
	.globl	real_unfl
real_unfl:
	addql	#0x1,fpsp_cnt4:l
	linkw	a6,#0xff40
	fsave	sp@-
	bclr	#1,a6@(-220:w)
	bne	ADR_40a0bc0:l
	bclr		#e1,a6@(e_byte)	//snan is always an e1 exception
ADR_40a0bc0:
	frestore	sp@+
	unlk		a6
	jmp	std_trap:l
	.globl	snan
snan:
	cmpb	#0x0,_cpu_type:l
	bne	ADR_40a0bda:b
	.word	0x4ef9
	.word	0x040a
	.word	0x0a38
ADR_40a0bda:
	.word	0x4ef9
	.word	0x040a
	.word	0x4dce
	.globl	real_snan
real_snan:
	linkw	a6,#0xff40
	fsave	sp@-
	bclr	#2,a6@(-220:w)
	frestore	sp@+
	unlk	a6
	addql	#0x1,fpsp_cnt7:l
	jmp	std_trap:l
	.globl	operr
operr:
	cmpb	#0x0,_cpu_type:l
	bne	ADR_40a0c0c:b
	.word	0x4ef9
	.word	0x040a
	.word	0x0a38
ADR_40a0c0c:
	.word	0x4ef9
	.word	0x040a
	.word	0x48d2
	.globl	real_operr
real_operr:
	linkw	a6,#0xff40
	fsave	sp@-
	bclr	#2,a6@(-220:w)
	frestore	sp@+
	unlk		a6
	addql	#0x1,fpsp_cnt6:l
	jmp	std_trap:l
	.globl	bsun
bsun:
	cmpb	#0x0,_cpu_type:l
	bne	ADR_40a0c66:b
	movel	d0,sp@-
	fsave	sp@-
	moveb	sp@,d0
	beq	ADR_40a0c5c:l
	clrl	d0
	moveb	sp@(1:w),d0
	bset	#3,sp@(0:b,d0:l:1)
	fmoveml	fps,sp@-
	bclr	#0,sp@
	fmoveml	sp@+,fps
ADR_40a0c5c:
	frestore	sp@+
	movel	sp@+,d0
	jmp	std_trap:l
ADR_40a0c66:
	.word	0x4ef9
	.word	0x040a
	.word	0x47ba
	.globl	real_bsun
real_bsun:
	linkw	a6,#0xff40
	fsave	sp@-
	bclr	#2,a6@(-220:w)
	fmoveml	fps,sp@-
	bclr	#0,sp@
	fmoveml	sp@+,fps
	frestore	sp@+
	unlk		a6
	addql	#0x1,fpsp_cnt1:l
	jmp	std_trap:l
	.globl	fline
fline:
	cmpb	#0x0,_cpu_type:l
	bne	ADR_40a0ca4:b
	.globl	real_fline
real_fline:
	jmp	std_trap:l
ADR_40a0ca4:
	.word	0x4ef9
	.word	0x040a
	.word	0x47f4
	.globl	unsupp
unsupp:
	cmpb	#0x0,_cpu_type:l
	bne	ADR_40a0cba:b
	jmp	std_trap:l
ADR_40a0cba:
	.word	0x4ef9
	.word	0x040a
	.word	0x5492

//
//	Trace exception
//
// real_trace:
	.globl	real_trace
real_trace:
	subl	 #8,a7			//allocate work space
	movel	 a0,a7@		//save a0
	movec	 vbr,a0			//get current exception table base addr
	movel	 a0@(0x24),a7@(4)		//get trace handler addr & put on stack
	moveal	 a7@+,a0		//restore a0
	rts				//go //to trap handler (trust me)
	.globl	fpsp_fmt_error
fpsp_fmt_error:
	jmp	fpsp_frame_err:l
	.globl	mem_write
mem_write:
	btst	#5,a6@(4:w)
	beq	ADR_40a0cf0:l
ADR_40a0ce4:
	moveb	a0@+,a1@+
	subql	#0x1,d0
	bne	ADR_40a0ce4:l
	rts
ADR_40a0cf0:
	movel	d1,sp@-

//
//	mem_write --- write to user address space
//
// Writes to user memory while in supervisor mode.  copyout accomplishes
// this via a 'moves' instruction.  copyout is a UNIX SVR3 (and later) function.
// If you don't have copyout, use the local copy of the function below.
//
//	a0 - supervisor source address
//	a1 - user destination address
//	d0 - number of bytes to write (maximum count is 12)
//
// The supervisor source address is guaranteed to point into the supervisor
// stack.  In addition, no calls to mem_write are made by the FPSP until
// all global data areas are no longer needed.  The result is that a UNIX
// process is allowed to sleep as a consequence of a page fault during
// copyout.  The probability of a page fault is exceedingly small because
// the 68040 always reads the destination address and thus the page
// faults should have already been handled.
//
// mem_write:
	movel	d0,sp@-
	movel	a1,sp@-
	movel	a0,sp@-
	jsr	_copyout:l
	addw	#12,sp
	movel	sp@+,d1
	rts
	.globl	mem_read
mem_read:
	btst	#5,a6@(4:w)
	beq	ADR_40a0d1e:l
ADR_40a0d12:
	moveb	a0@+,a1@+
	subql	#0x1,d0
	bne	ADR_40a0d12:l
	rts
ADR_40a0d1e:
	movel	d1,sp@-
//
//	mem_read --- read from user address space
//
// Reads from user memory while in supervisor mode.  copyin accomplishes
// this via a 'moves' instruction.  copyin is a UNIX SVR3 (and later) function.
// If you don't have copyin, use the local copy of the function below.
//
// The FPSP calls mem_read to read the original F-line instruction in order
// to extract the data register number when the 'Dn' addressing mode is
// used.
//
//Input:
//	a0 - user source address
//	a1 - supervisor destination address
//	d0 - number of bytes to read (maximum count is 12)
//
// Like mem_write, mem_read always reads from user space to an address on
// the supervisor stack.  Calls to mem_read ocurr before any global variables
// are affected so a sleep in copyin is allowable.
//
// mem_read:
	movel	d0,sp@-
	movel	a1,sp@-
	movel	a0,sp@-
	jsr	_copyin:l
	addw	#12,sp
	movel	sp@+,d1
	rts
//
//	slog2.sa 1.4 10/1/90
//
//       The entry point slog10 computes the base-10 
//	logarithm of an input argument X.
//	slog10d does the same except the input value is a 
//	denormalized number.  
//	sLog2 and sLog2d are the base-2 analogues.
//
//       INPUT:	Double-extended value in memory location pointed to 
//		by address register a0.
//
//       OUTPUT: log_10(X) or log_2(X) returned in floating-point 
//		register fp0.
//
//       ACCURACY and MONOTONICITY: The returned result is within 1.7 
//		ulps in 64 significant bit, i.e. within 0.5003 ulp 
//		to 53 bits if the result is subsequently rounded 
//		to double precision. The result is provably monotonic 
//		in double precision.
//
//       SPEED:	Two timings are measured, both in the copy-back mode. 
//		The first one is measured when the function is invoked 
//		the first time (so the instructions and data are not 
//		in cache), and the second one is measured when the 
//		function is reinvoked at the same input argument.
//
//       ALGORITHM and IMPLEMENTATION NOTES:
//
//       slog10d:
//
//       Step 0.   If X < 0, create a NaN and raise the invalid operation
//                 flag. Otherwise, save FPCR in D1; set FpCR to default.
//       Notes:    Default means round-to-nearest mode, no floating-point
//                 traps, and precision control = double extended.
//
//       Step 1.   Call slognd to obtain Y = log(X), the natural log of X.
//       Notes:    Even if X is denormalized, log(X) is always normalized.
//
//       Step 2.   Compute log_10(X) = log(X) * (1/log(10)).
//            2.1  Restore the user FPCR
//            2.2  Return ans := Y * INV_L10.
//
//
//       slog10: 
//
//       Step 0.   If X < 0, create a NaN and raise the invalid operation
//                 flag. Otherwise, save FPCR in D1; set FpCR to default.
//       Notes:    Default means round-to-nearest mode, no floating-point
//                 traps, and precision control = double extended.
//
//       Step 1.   Call sLogN to obtain Y = log(X), the natural log of X.
//
//       Step 2.   Compute log_10(X) = log(X) * (1/log(10)).
//            2.1  Restore the user FPCR
//            2.2  Return ans := Y * INV_L10.
//
//
//       sLog2d:
//
//       Step 0.   If X < 0, create a NaN and raise the invalid operation
//                 flag. Otherwise, save FPCR in D1; set FpCR to default.
//       Notes:    Default means round-to-nearest mode, no floating-point
//                 traps, and precision control = double extended.
//
//       Step 1.   Call slognd to obtain Y = log(X), the natural log of X.
//       Notes:    Even if X is denormalized, log(X) is always normalized.
//
//       Step 2.   Compute log_10(X) = log(X) * (1/log(2)).
//            2.1  Restore the user FPCR
//            2.2  Return ans := Y * INV_L2.
//
//
//       sLog2:
//
//       Step 0.   If X < 0, create a NaN and raise the invalid operation
//                 flag. Otherwise, save FPCR in D1; set FpCR to default.
//       Notes:    Default means round-to-nearest mode, no floating-point
//                 traps, and precision control = double extended.
//
//       Step 1.   If X is not an integer power of two, i.e., X != 2^k,
//                 go to Step 3.
//
//       Step 2.   Return k.
//            2.1  Get integer k, X = 2^k.
//            2.2  Restore the user FPCR.
//            2.3  Return ans := convert-to-double-extended(k).
//
//       Step 3.   Call sLogN to obtain Y = log(X), the natural log of X.
//
//       Step 4.   Compute log_2(X) = log(X) * (1/log(2)).
//            4.1  Restore the user FPCR
//            4.2  Return ans := Y * INV_L2.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



	
	
	
	

ADR_40a0d34:
   .int 0x3ffd0000,0xde5bd8a9,0x37287195,0x00000000

ADR_40a0d44:
    .int 0x3fff0000,0xb8aa3b29,0x5c17f0bc,0x00000000

// slog10d:
//--entry point for Log10(X), X is denormalized
	.globl	slog10d
slog10d:
	movel		a0@,d0
	blt		ADR_40a0e1c
	movel		d1,sp@-
	.word	0x4281
	bsr		slognd			// log(x), x denorm
	.word	0xf21f
	.word	0x9000
	fmulx		ADR_40a0d34,fp0
	bra		t_frcinx

// slog10:
//--entry point for Log10(X), X is normalized

	.globl	slog10
slog10:
	movel		a0@,d0
	blt		ADR_40a0e1c
	movel		d1,sp@-
	clrl	d1
	bsr		slogn			// log(x), x normal
	fmoveml	sp@+,fpc
	fmulx		ADR_40a0d34,fp0
	bra		t_frcinx


// slog2d:
//--entry point for Log2(X), X is denormalized

	.globl	slog2d
slog2d:
	movel		a0@,d0
	blt		ADR_40a0e1c
	movel		d1,sp@-
	clrl	d1
	bsr		slognd			// log(x), x denorm
	fmoveml	sp@+,fpc
	fmulx		ADR_40a0d44,fp0
	bra		t_frcinx

// slog2:
//--entry point for Log2(X), X is normalized
	.globl	slog2
slog2:
	movel		a0@,d0
	blt		ADR_40a0e1c

	movel		a0@(8),d0
	bne		ADR_40a0e00		// x is not 2^k

	movel		a0@(4),d0
	andl		#0x7fffffff,d0
	tstl		d0
	bne		ADR_40a0e00

//--X = 2^k.
	movew		a0@,d0
	andl		#0x00007fff,d0
	subl		#0x3fff,d0
	fmovel		d1,fpcr
	fmovel		d0,fp0
	bra		t_frcinx

// continue:
ADR_40a0e00:
	movel		d1,sp@-
	clrl	d1
	bsr		slogn			// log(x), x normal
	fmoveml	sp@+,fpc
	fmulx		ADR_40a0d44,fp0
	bra		t_frcinx

// invalid:
ADR_40a0e1c:
	bra		t_operr
//
//	slogn.sa 1.9 10/3/90
//
//	slogn computes the natural logarithm of an
//	input value. slognd does the same except the input value is a
//	denormalized number. slognp1 computes log(1+X), and slognp1d
//	computes log(1+X) for denormalized X.
//
//	Input: Double-extended value in memory location pointed to by address
//		register a0.
//
//	Output:	log(X) or log(1+X) returned in floating-point register Fp0.
//
//	Accuracy and Monotonicity: The returned result is within 2 ulps in
//		64 significant bit, i.e. within 0.5001 ulp to 53 bits if the
//		result is subsequently rounded to double precision. The 
//		result is provably monotonic in double precision.
//
//	Speed: The program slogn takes approximately 190 cycles for input 
//		argument X such that |X-1| >= 1/16, which is the the usual 
//		situation. For those arguments, slognp1 takes approximately
//		 210 cycles. For the less common arguments, the program will
//		 run no worse than 10% slower.
//
//	Algorithm:
//	LOGN:
//	Step 1. If |X-1| < 1/16, approximate log(X) by an odd polynomial in
//		u, where u = 2(X-1)/(X+1). Otherwise, move on to Step 2.
//
//	Step 2. X = 2**k * Y where 1 <= Y < 2. Define F to be the first seven
//		significant bits of Y plus 2**(-7), i.e. F = 1.xxxxxx1 in base
//		2 where the six "x" match those of Y. Note that |Y-F| <= 2**(-7).
//
//	Step 3. Define u = (Y-F)/F. Approximate log(1+u) by a polynomial in u,
//		log(1+u) = poly.
//
//	Step 4. Reconstruct log(X) = log( 2**k * Y ) = k*log(2) + log(F) + log(1+u)
//		by k*log(2) + (log(F) + poly). The values of log(F) are calculated
//		beforehand and stored in the program.
//
//	lognp1:
//	Step 1: If |X| < 1/16, approximate log(1+X) by an odd polynomial in
//		u where u = 2X/(2+X). Otherwise, move on to Step 2.
//
//	Step 2: Let 1+X = 2**k * Y, where 1 <= Y < 2. Define F as done in Step 2
//		of the algorithm for LOGN and compute log(1+X) as
//		k*log(2) + log(F) + poly where poly approximates log(1+u),
//		u = (Y-F)/F. 
//
//	Implementation Notes:
//	Note 1. There are 64 different possible values for F, thus 64 log(F)'s
//		need to be tabulated. Moreover, the values of 1/F are also 
//		tabulated so that the division in (Y-F)/F can be performed by a
//		multiplication.
//
//	Note 2. In Step 2 of lognp1, in order to preserved accuracy, the value
//		Y-F has to be calculated carefully when 1/2 <= X < 3/2. 
//
//	Note 3. To fully exploit the pipeline, polynomials are usually separated
//		into two parts evaluated independently before being added up.
//	

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



ADR_40a0e22:
   .int 0x3ffef07d,0x3fff8841
ADR_40a0e2a:
   .int 0x3ffe8000,0x3fffc000
	.word	0x3ffe
 	.word 0x0000
	.word	0xb172
	.word	0x17f7
	.word	0xd1cf
	.word	0x79ac
	.word	0x0000
	.word	0x0000

ADR_40a0e42:
 	.int 0x3f800000
ADR_40a0e46:
 	.int 0x00000000
 	.int 0x7f800000
ADR_40a0e4e:
 	.int 0xbf800000

ADR_40a0e52:
 	.int 0x3fc2499a,0xb5e4040b
ADR_40a0e5a:
 	.int 0xbfc555b5,0x848cb7db

ADR_40a0e62:
 	.int 0x3fc99999,0x987d8730
ADR_40a0e6a:
 	.int 0xbfcfffff,0xff6f7e97

ADR_40a0e72:
 	.int 0x3fd55555,0x555555a4
ADR_40a0e7a:
 	.int 0xbfe00000,0x00000008

ADR_40a0e82:
 	.int 0x3f175496,0xadd7dad6
ADR_40a0e8a:
 	.int 0x3f3c71c2,0xfe80c7e0

ADR_40a0e92:
 	.int 0x3f624924,0x928bccff
ADR_40a0e9a:
 	.int 0x3f899999,0x999995ec

ADR_40a0ea2:
 	.int 0x3fb55555,0x55555555
ADR_40a0eaa:
 	.int 0x40000000,0x00000000

ADR_40a0eb2:
 	.int 0x3f990000,0x80000000,0x00000000,0x00000000

// logtbl:
ADR_40a0ec2:
	.int  0x3ffe0000,0xfe03f80f,0xe03f80fe,0x00000000
	.int  0x3ff70000,0xff015358,0x833c47e2,0x00000000
	.int  0x3ffe0000,0xfa232cf2,0x52138ac0,0x00000000
	.int  0x3ff90000,0xbdc8d83e,0xad88d549,0x00000000
	.int  0x3ffe0000,0xf6603d98,0x0f6603da,0x00000000
	.int  0x3ffa0000,0x9cf43dcf,0xf5eafd48,0x00000000
	.int  0x3ffe0000,0xf2b9d648,0x0f2b9d65,0x00000000
	.int  0x3ffa0000,0xda16eb88,0xcb8df614,0x00000000
	.int  0x3ffe0000,0xef2eb71f,0xc4345238,0x00000000
	.int  0x3ffb0000,0x8b29b775,0x1bd70743,0x00000000
	.int  0x3ffe0000,0xebbdb2a5,0xc1619c8c,0x00000000
	.int  0x3ffb0000,0xa8d839f8,0x30c1fb49,0x00000000
	.int  0x3ffe0000,0xe865ac7b,0x7603a197,0x00000000
	.int  0x3ffb0000,0xc61a2eb1,0x8cd907ad,0x00000000
	.int  0x3ffe0000,0xe525982a,0xf70c880e,0x00000000
	.int  0x3ffb0000,0xe2f2a47a,0xde3a18af,0x00000000
	.int  0x3ffe0000,0xe1fc780e,0x1fc780e2,0x00000000
	.int  0x3ffb0000,0xff64898e,0xdf55d551,0x00000000
	.int  0x3ffe0000,0xdee95c4c,0xa037ba57,0x00000000
	.word	0x3ffc
	.word	0x0000
	.word	0x8db9
	.word	0x56a9
	.word	0x7b3d
	movepl	(0x0,a0),d0
	.word	0x0000
	.int  0x3ffe0000,0xdbeb61ee,0xd19c5958,0x00000000
	.int  0x3ffc0000,0x9b8fe100,0xf47ba1de,0x00000000
	.int  0x3ffe0000,0xd901b203,0x6406c80e,0x00000000
	.int  0x3ffc0000,0xa9372f1d,0x0da1bd17,0x00000000
	.int  0x3ffe0000,0xd62b80d6,0x2b80d62c,0x00000000
	.int  0x3ffc0000,0xb6b07f38,0xce90e46b,0x00000000
	.int  0x3ffe0000,0xd3680d36,0x80d3680d,0x00000000
	.int  0x3ffc0000,0xc3fd0329,0x06488481,0x00000000
	.int  0x3ffe0000,0xd0b69fcb,0xd2580d0b,0x00000000
	.int  0x3ffc0000,0xd11de0ff,0x15ab18ca,0x00000000
	.int  0x3ffe0000,0xce168a77,0x25080ce1,0x00000000
	.int  0x3ffc0000,0xde1433a1,0x6c66b150,0x00000000
	.int  0x3ffe0000,0xcb8727c0,0x65c393e0,0x00000000
	.int  0x3ffc0000,0xeae10b5a,0x7ddc8add,0x00000000
	.int  0x3ffe0000,0xc907da4e,0x871146ad,0x00000000
	.int  0x3ffc0000,0xf7856e5e,0xe2c9b291,0x00000000
	.int  0x3ffe0000,0xc6980c69,0x80c6980c,0x00000000
	.int  0x3ffd0000,0x82012ca5,0xa68206d7,0x00000000
	.int  0x3ffe0000,0xc4372f85,0x5d824ca6,0x00000000
	.int  0x3ffd0000,0x882c5fcd,0x7256a8c5,0x00000000
	.int  0x3ffe0000,0xc1e4bbd5,0x95f6e947,0x00000000
	.word	0x3ffd
	.word	0x0000
	.word	0x8e44
	.word	0xc60b
	.word	0x4ccf
	.word	0xd7de
	.word	0x0000
	.word	0x0000
	.int  0x3ffe0000,0xbfa02fe8,0x0bfa02ff,0x00000000
	.int  0x3ffd0000,0x944ad09e,0xf4351af6,0x00000000
	.int  0x3ffe0000,0xbd691047,0x07661aa3,0x00000000
	.int  0x3ffd0000,0x9a3eecd4,0xc3eaa6b2,0x00000000
	.int  0x3ffe0000,0xbb3ee721,0xa54d880c,0x00000000
	.int  0x3ffd0000,0xa0218434,0x353f1de8,0x00000000
	.int  0x3ffe0000,0xb92143fa,0x36f5e02e,0x00000000
	.int  0x3ffd0000,0xa5f2fcab,0xbbc506da,0x00000000
	.int  0x3ffe0000,0xb70fbb5a,0x19be3659,0x00000000
	.int  0x3ffd0000,0xabb3b8ba,0x2ad362a5,0x00000000
	.int  0x3ffe0000,0xb509e68a,0x9b94821f,0x00000000
	.int  0x3ffd0000,0xb1641795,0xce3ca97b,0x00000000
	.int  0x3ffe0000,0xb30f6352,0x8917c80b,0x00000000
	.int  0x3ffd0000,0xb7047551,0x5d0f1c61,0x00000000
	.int  0x3ffe0000,0xb11fd3b8,0x0b11fd3c,0x00000000
	.int  0x3ffd0000,0xbc952afe,0xea3d13e1,0x00000000
	.int  0x3ffe0000,0xaf3addc6,0x80af3ade,0x00000000
	.word	0x3ffd
	.word	0x0000
	.word	0xc216
	divu	a0@,d7
	cinva	dc
	cmpw	a2,d5
	.word	0x0000
	.word	0x0000
	.word	0x3ffe
	.word	0x0000
	.word	0xad60
	movel	a0@+,a5@(2774:w)
	.word	0x02b6
	.word	0x0000
	.word	0x0000
	.int  0x3ffd0000,0xc788f439,0xb3163bf1,0x00000000
	.int  0x3ffe0000,0xab8f69e2,0x8359cd11,0x00000000
	.int  0x3ffd0000,0xccecac08,0xbf04565d,0x00000000
	.int  0x3ffe0000,0xa9c84a47,0xa07f5638,0x00000000
	.word	0x3ffd
	.word	0x0000
	.word	0xd242
	.word	0x0487
	.word	0x2dd8
	.word	0x5160
	.word	0x0000
	.word	0x0000
	.int  0x3ffe0000,0xa80a80a8,0x0a80a80b,0x00000000
	.int  0x3ffd0000,0xd7894992,0x3bc3588a,0x00000000
	.int  0x3ffe0000,0xa655c439,0x2d7b73a8,0x00000000
	.int  0x3ffd0000,0xdcc2c4b4,0x9887dacc,0x00000000
	.int  0x3ffe0000,0xa4a9cf1d,0x96833751,0x00000000
	.int  0x3ffd0000,0xe1eebd3e,0x6d6a6b9e,0x00000000
	.int  0x3ffe0000,0xa3065e3f,0xae7cd0e0,0x00000000
	.int  0x3ffd0000,0xe70d785c,0x2f9f5bdc,0x00000000
	.int  0x3ffe0000,0xa16b312e,0xa8fc377d,0x00000000
	.word	0x3ffd
	.word	0x0000
	.word	0xec1f
	movew	a4@(20857:w),a4@-
	.word	0xf283
	.word	0x0000
	.word	0x0000
	.word	0x3ffe
	.word	0x0000
	.word	0x9fd8
	.word	0x09fd
	orl	sp@+,d0
	.word	0xd80a
	.word	0x0000
	.word	0x0000
	.int  0x3ffd0000,0xf12440d3,0xe36130e6,0x00000000
	.word	0x3ffe
	.word	0x0000
	.word	0x9e4c
	.word	0xad23
	addw	d6,sp@+
	movew	a0@-,d5
	.word	0x0000
	.word	0x0000
	.int  0x3ffd0000,0xf61cce92,0x346600bb,0x00000000
	.int  0x3ffe0000,0x9cc8e160,0xc3fb19b9,0x00000000
	.int  0x3ffd0000,0xfb091fd3,0x8145630a,0x00000000
	.int  0x3ffe0000,0x9b4c6f9e,0xf03a3caa,0x00000000
	.int  0x3ffd0000,0xffe97042,0xbfa4c2ad,0x00000000
	.int  0x3ffe0000,0x99d722da,0xbde58f06,0x00000000
	.int  0x3ffe0000,0x825efced,0x49369330,0x00000000
	.int  0x3ffe0000,0x9868c809,0x868c8098,0x00000000
	.int  0x3ffe0000,0x84c37a7a,0xb9a905c9,0x00000000
	.int  0x3ffe0000,0x97012e02,0x5c04b809,0x00000000
	.int  0x3ffe0000,0x87224c2e,0x8e645fb7,0x00000000
	.int  0x3ffe0000,0x95a02568,0x095a0257,0x00000000
	.int  0x3ffe0000,0x897b8cac,0x9f7de298,0x00000000
	.int  0x3ffe0000,0x94458094,0x45809446,0x00000000
	.int  0x3ffe0000,0x8bcf55de,0xc4cd05fe,0x00000000
	.int  0x3ffe0000,0x92f11384,0x0497889c,0x00000000
	.int  0x3ffe0000,0x8e1dc0fb,0x89e125e5,0x00000000
	.int  0x3ffe0000,0x91a2b3c4,0xd5e6f809,0x00000000
	.int  0x3ffe0000,0x9066e68c,0x955b6c9b,0x00000000
	.int  0x3ffe0000,0x905a3863,0x3e06c43b,0x00000000
	.int  0x3ffe0000,0x92aade74,0xc7be59e0,0x00000000
	.int  0x3ffe0000,0x8f1779d9,0xfdc3a219,0x00000000
	.int  0x3ffe0000,0x94e9bff6,0x15845643,0x00000000
	.int  0x3ffe0000,0x8dda5202,0x37694809,0x00000000
	.int  0x3ffe0000,0x9723a1b7,0x20134203,0x00000000
	.int  0x3ffe0000,0x8ca29c04,0x6514e023,0x00000000
	.word	0x3ffe
	.word	0x0000
	.word	0x9958
	subal	a0,a4
	subaw	a3@(-30320:w),a0
	.word	0x0000
	.word	0x0000
	.int  0x3ffe0000,0x8b70344a,0x139bc75a,0x00000000
	.int  0x3ffe0000,0x9b88bdaa,0x3a3dae2f,0x00000000
	.int  0x3ffe0000,0x8a42f870,0x5669db46,0x00000000
	.int  0x3ffe0000,0x9db4224f,0xffe1157c,0x00000000
	.int  0x3ffe0000,0x891ac73a,0xe9819b50,0x00000000
	.int  0x3ffe0000,0x9fdadc26,0x8b7a12da,0x00000000
	.int  0x3ffe0000,0x87f78087,0xf78087f8,0x00000000
	.int  0x3ffe0000,0xa1fcff17,0xce733bd4,0x00000000
	.int  0x3ffe0000,0x86d90544,0x7a34acc6,0x00000000
	.int  0x3ffe0000,0xa41a9e8f,0x5446fb9f,0x00000000
	.int  0x3ffe0000,0x85bf3761,0x2cee3c9b,0x00000000
	.int  0x3ffe0000,0xa633cd7e,0x6771cd8b,0x00000000
	.int  0x3ffe0000,0x84a9f9c8,0x084a9f9d,0x00000000
	.int  0x3ffe0000,0xa8489e60,0x0b435a5e,0x00000000
	.int  0x3ffe0000,0x83993052,0x3fbe3368,0x00000000
	.int  0x3ffe0000,0xaa59233c,0xcca4bd49,0x00000000
	.int  0x3ffe0000,0x828cbfbe,0xb9a020a3,0x00000000
	.int  0x3ffe0000,0xac656dae,0x6bcc4985,0x00000000
	.int  0x3ffe0000,0x81848da8,0xfaf0d277,0x00000000
	.int  0x3ffe0000,0xae6d8ee3,0x60bb2468,0x00000000
	.int  0x3ffe0000,0x80808080,0x80808081,0x00000000
	.int  0x3ffe0000,0xb07197a2,0x3c46c654,0x00000000
	.globl	slognd
slognd:
	movel	#0xffffff9c:l,a6@(-84:w)
	moveml	d2/d3/d4/d5/d6/d7,sp@-
	moveq	#0,d3
	movel	a0@(4:w),d4
	movel	a0@(8:w),d5
	clrl	d2
	tstl	d4
	bne	ADR_40a1718:l
	movel	d5,d4
	clrl	d5
	moveq	#32,d2
	clrl	d6
	bfffo	d4{#0,#0},d6
	lsll	d6,d4
	addl	d6,d2
	movel	d3,a6@(-116:w)
	movel	d4,a6@(-112:w)
	movel	d5,a6@(-108:w)
	negl	d2
	movel	d2,a6@(-84:w)
	fmovex	a6@(-116:w),fp0
	moveml	sp@+,d2/d3/d4/d5/d6/d7
	lea	a6@(-116:w),a0
	bra		ADR_40a1764
ADR_40a1718:
	clrl	d6
	bfffo	d4{#0,#0},d6
	movel	d6,d2
	lsll	d6,d4
	movel	d5,d7
	lsll	d6,d5
	negl	d6
	addl	#0x20,d6
	lsrl	d6,d7
	orl	d7,d4
	movel	d3,a6@(-116:w)
	movel	d4,a6@(-112:w)
	movel	d5,a6@(-108:w)
	negl	d2
	movel	d2,a6@(-84:w)
	fmovex	a6@(-116:w),fp0
	moveml	sp@+,d2/d3/d4/d5/d6/d7
	lea	a6@(-116:w),a0
	bra	ADR_40a1764:l

	.globl	slogn
slogn:
	fmovex		a0@,fp0	// load input
	movel	#0x0:l,a6@(-84:w)

// logbgn:
//--FPCR SAVED AND CLEARED, INPUT IS 2^(ADJK)*FP0, FP0 CONTAINS
//--A FINITE, NON-ZERO, NORMALIZED NUMBER.

ADR_40a1764:
	movel	a0@,d0
	movew	a0@(4),d0
	movel	a0@,a6@(-116:w)
	movel	a0@(4:w),a6@(-112:w)
	movel	a0@(8:w),a6@(-108:w)

//	FMOVE.X	FP0,X
//	MOVE.W	XFRAC,XDCARE	...LONG WORD AT X HAS 16 SIG. BITS OF X
//	MOVE.L	X,D0
	cmpil	#0,d0		// check if x is negative
	blt	ADR_40a1916		// log of negative argument is invalid
	cmp2l	ADR_40a0e22,d0	// x is positive, check if x is near 1
	bcc	ADR_40a1884	// bounds is roughly [15/16, 17/16]

// logmain:
//--THIS SHOULD BE THE USUAL CASE, X NOT VERY CLOSE TO 1

//--X = 2^(K) * Y, 1 <= Y < 2. THUS, Y = 1.XXXXXXXX....XX IN BINARY.
//--WE DEFINE F = 1.XXXXXX1, I.E. FIRST 7 BITS OF Y AND ATTACH A 1.
//--THE IDEA IS THAT LOG(X) = K*LOG2 + LOG(Y)
//--			 = K*LOG2 + LOG(F) + LOG(1 + (Y-F)/F).
//--NOTE THAT U = (Y-F)/F IS VERY SMALL AND THUS APPROXIMATING
//--LOG(1+U) CAN BE VERY EFFICIENT.
//--ALSO NOTE THAT THE VALUE 1/F IS STORED IN A TABLE SO THAT NO
//--DIVISION IS NEEDED TO CALCULATE (Y-F)/F. 

//--GET K, Y, F, AND ADDRESS OF 1/F.
ADR_40a1794:
	asrl	#8,d0
	asrl	#8,d0		// shifted 16 bits, biased expo of x
	subil	#0x3fff,d0 	// this is k
	addl	a6@(-84:w),d0
	lea	ADR_40a0ec2,a0 	// base address of 1/f and log(f)
	fmovel	d0,fp1
	movel	#0x3fff0000:l,a6@(-116:w)
	movel	a6@(-112:w),a6@(-96:w)
	andl	#0xfe000000,a6@(-96:w)
	orl	#0x1000000,a6@(-96:w)
	movel	a6@(-96:w),d0
	andil	#0x7e000000,d0	
	asrl	#8,d0
	asrl	#8,d0
	asrl	#4,d0		// shifted 20, d0 is the displacement
	addal	d0,a0		// a0 is the address for 1/f
	fmovex	a6@(-116:w),fp0
	movel	#0x3fff0000:l,a6@(-100:w)
	clrl	a6@(-92:w)
	fsubx	a6@(-100:w),fp0
	fmovemx	fp2/fp3,sp@-
//--SUMMARY: FP0 IS Y-F, A0 IS ADDRESS OF 1/F, FP1 IS K
//--REGISTERS SAVED: FPCR, FP1, FP2

// lp1cont1:
//--AN RE-ENTRY POINT FOR LOGNP1
ADR_40a17f8:
	fmulx	a0@,fp0	// fp0 is u = (y-f)/f
	.word	0xf239
	.word	0x48a3
	.word	0x040a
	.word	0x0e32
	fmovex	fp0,fp2
	fmulx	fp2,fp2		// fp2 is v=u*u
	fmovex	fp1,a6@(-64:w)

//--LOG(1+U) IS APPROXIMATED BY
//--U + V*(A1+U*(A2+U*(A3+U*(A4+U*(A5+U*A6))))) WHICH IS
//--[U + V*(A1+V*(A3+V*A5))]  +  [U*V*(A2+V*(A4+V*A6))]

	fmovex	fp2,fp3
	fmovex	fp2,fp1	

	fmuld	ADR_40a0e52,fp1	// v*a6
	fmuld	ADR_40a0e5a,fp2	// v*a5

	faddd	ADR_40a0e62,fp1	// a4+v*a6
	faddd	ADR_40a0e6a,fp2	// a3+v*a5

	fmulx	fp3,fp1		// v*(a4+v*a6)
	fmulx	fp3,fp2		// v*(a3+v*a5)

	faddd	ADR_40a0e72,fp1	// a2+v*(a4+v*a6)
	faddd	ADR_40a0e7a,fp2	// a1+v*(a3+v*a5)

	fmulx	fp3,fp1		// v*(a2+v*(a4+v*a6))
	addal	#16,a0		// address of log(f)
	fmulx	fp3,fp2		// v*(a1+v*(a3+v*a5)), fp3 released

	fmulx	fp0,fp1		// u*v*(a2+v*(a4+v*a6))
	faddx	fp2,fp0		// u+v*(a1+v*(a3+v*a5)), fp2 released

	faddx	a0@,fp1	// log(f)+u*v*(a2+v*(a4+v*a6))
	fmovemx	sp@+,fp2/fp3
	faddx	fp1,fp0		// fp0 is log(f) + log(1+u)

	fmovel	d1,fpcr
	faddx	a6@(-64:w),fp0
	bra	t_frcinx


// lognear1:
//--REGISTERS SAVED: FPCR, FP1. FP0 CONTAINS THE INPUT.
ADR_40a1884:
	fmovex	fp0,fp1
	fsubs	ADR_40a0e42,fp1		// fp1 is x-1
	fadds	ADR_40a0e42,fp0		// fp0 is x+1
	faddx	fp1,fp1		// fp1 is 2(x-1)
//--LOG(X) = LOG(1+U/2)-LOG(1-U/2) WHICH IS AN ODD POLYNOMIAL
//--IN U, U = 2(X-1)/(X+1) = FP1/FP0

// lp1cont2:
//--THIS IS AN RE-ENTRY POINT FOR LOGNP1
ADR_40a189c:
	fdivx	fp0,fp1		// fp1 is u
	fmovemx	fp2/fp3,sp@-
//--REGISTERS SAVED ARE NOW FPCR,FP1,FP2,FP3
//--LET V=U*U, W=V*V, CALCULATE
//--U + U*V*(B1 + V*(B2 + V*(B3 + V*(B4 + V*B5)))) BY
//--U + U*V*(  [B1 + W*(B3 + W*B5)]  +  [V*(B2 + W*B4)]  )
	fmovex	fp1,fp0
	fmulx	fp0,fp0	// fp0 is v
	fmovex	fp1,a6@(-48:w)
	fmovex	fp0,fp1	
	fmulx	fp1,fp1	// fp1 is w

	fmoved	ADR_40a0e82,fp3
	fmoved	ADR_40a0e8a,fp2

	fmulx	fp1,fp3	// w*b5
	fmulx	fp1,fp2	// w*b4

	faddd	ADR_40a0e92,fp3 // b3+w*b5
	faddd	ADR_40a0e9a,fp2 // b2+w*b4

	fmulx	fp3,fp1	// w*(b3+w*b5), fp3 released

	fmulx	fp0,fp2	// v*(b2+w*b4)

	faddd	ADR_40a0ea2,fp1 // b1+w*(b3+w*b5)
	fmulx	a6@(-48:w),fp0

	faddx	fp2,fp1	// b1+w*(b3+w*b5) + v*(b2+w*b4), fp2 released
	fmovemx	sp@+,fp2/fp3

	fmulx	fp1,fp0	// u*v*( [b1+w*(b3+w*b5)] + [v*(b2+w*b4)] )

	fmovel	d1,fpcr
	faddx	a6@(-48:w),fp0
	.word	0x60ff
	.word	0xffff
	.word	0xb2a2
0:
	rts

// logneg:
//--REGISTERS SAVED FPCR. LOG(-VE) IS INVALID
ADR_40a1916:
	bra	t_operr
	.globl	slognp1d
slognp1d:
	.word	0x60ff
	.word	0xffff
	.word	0xb3aa

	.globl	slognp1
slognp1:
	fmovex	a0@,fp0	// load input
	fabsx	fp0		//test magnitude
	fcmpx	ADR_40a0eb2,fp0	//compare with min threshold
	fbgt	ADR_40a194e		//if greater, continue
	fmovel	#0,fpsr		//clr n flag from compare
	fmovel	d1,fpcr
	fmovex	a0@,fp0
	bra	t_frcinx

// lp1real:
ADR_40a194e:
	fmovex	a0@,fp0	// load input
	movel	#0x0:l,a6@(-84:w)
	fmovex	fp0,fp1	// fp1 is input z
	fadds	ADR_40a0e42,fp0	// x := round(1+z)
	fmovex	fp0,a6@(-116:w)
	movew	a6@(-112:w),a6@(-114:w)
	movel	a6@(-116:w),d0
	cmpil	#0,d0
	ble	ADR_40a1a66	// log of zero or -ve
	cmp2l	ADR_40a0e2a,d0
	bcs	ADR_40a1794	// bounds2 is [1/2,3/2]
//--IF 1+Z > 3/2 OR 1+Z < 1/2, THEN X, WHICH IS ROUNDING 1+Z,
//--CONTAINS AT LEAST 63 BITS OF INFORMATION OF Z. IN THAT CASE,
//--SIMPLY INVOKE LOG(X) FOR LOG(1+Z).

// lp1near1:
//--NEXT SEE IF EXP(-1/16) < X < EXP(1/16)
	cmp2l	ADR_40a0e22,d0
	bcs	ADR_40a19b0

// lp1one16:
//--EXP(-1/16) < X < EXP(1/16). LOG(1+Z) = LOG(1+U/2) - LOG(1-U/2)
//--WHERE U = 2Z/(2+Z) = 2Z/(1+X).
	faddx	fp1,fp1	// fp1 is 2z
	fadds	ADR_40a0e42,fp0	// fp0 is 1+x
//--U = FP1/FP0
	bra	ADR_40a189c
ADR_40a19b0:
	movel	a6@(-112:w),a6@(-96:w)
	andl	#0xfe000000,a6@(-96:w)
	orl	#0x1000000,a6@(-96:w)
	cmpil	#0x3fff8000,d0	// see if 1+z > 1
	bge	ADR_40a1a1e

// kisneg1:
	fmoves	ADR_40a0eaa,fp0
	movel	#0x3fff0000:l,a6@(-100:w)
	clrl	a6@(-92:w)
	fsubx	a6@(-100:w),fp0
	movel	a6@(-96:w),d0
	andil	#0x7e000000,d0
	asrl	#8,d0
	asrl	#8,d0
	asrl	#4,d0		// d0 contains displacement for 1/f
	faddx	fp1,fp1		// get 2z
	fmovemx	fp2/fp3,sp@-
	faddx	fp1,fp0		// fp0 is y-f = (2-f)+2z
	lea	ADR_40a0ec2,a0	// a0 is address of 1/f
	addal	d0,a0
	fmoves	ADR_40a0e4e,fp1	// fp1 is k = -1
	bra	ADR_40a17f8

// kiszero:
ADR_40a1a1e:
	fmoves	ADR_40a0e42,fp0
	movel	#0x3fff0000:l,a6@(-100:w)
	clrl	a6@(-92:w)
	fsubx	a6@(-100:w),fp0
	movel	a6@(-96:w),d0
	andil	#0x7e000000,d0
	asrl	#8,d0
	asrl	#8,d0
	asrl	#4,d0
	faddx	fp1,fp0		// fp0 is y-f
	fmovemx	fp2/fp3,sp@-
	lea	ADR_40a0ec2,a0
	addal	d0,a0	 	// a0 is address of 1/f
	fmoves	ADR_40a0e46,fp1	// fp1 is k = 0
	bra	ADR_40a17f8

// lp1neg0:
//--FPCR SAVED. D0 IS X IN COMPACT FORM.
ADR_40a1a66:
	cmpil	#0,d0
	blt	ADR_40a1a84
// lp1zero:
	fmoves	ADR_40a0e4e,fp0

	fmovel	d1,fpcr
	bra t_dz

// lp1neg:
ADR_40a1a84:
	fmoves	ADR_40a0e46,fp0

	fmovel	d1,fpcr
	bra	t_operr
	.word	0x0000
	.word	0x0000
	.globl	smovcr
smovcr:
	bfextu	a6@(-228:w){#9,#7},d0
	bfextu	a6@(-128:w){#26,#2},d1
	tstb	d0
	beq	ADR_40a1ae0:l
	cmpb	#0xa,d0
	ble	ADR_40a1ad6:l
	cmpb	#0xe,d0
	ble	ADR_40a1b16:l
	cmpb	#0x2f,d0
	ble	ADR_40a1ad6:l
	cmpb	#0x3f,d0
	ble	ADR_40a1b70:l
ADR_40a1ad6:
	.word	0xf239
	.word	0x4400
	.word	0x040a
	.word	0x1a96
	rts
ADR_40a1ae0:
	tstb	d1
	beq	ADR_40a1afe:l
	cmpb	#0x3,d1
	beq	ADR_40a1b0a:l
	lea	pirzrm:l,a0
	bra	ADR_40a1be2:l
ADR_40a1afe:
	lea	pirn:l,a0
	bra	ADR_40a1be2:l
ADR_40a1b0a:
	lea	pirp:l,a0
	bra	ADR_40a1be2:l
ADR_40a1b16:
	subl	#0xb,d0
	tstb	d1
	beq	ADR_40a1b44:l
	cmpb	#0x3,d1
	beq	ADR_40a1b5a:l
	lea	smalrzrm:l,a0
	cmpb	#0x2,d0
	ble	ADR_40a1be2:l
	bra	ADR_40a1bea:l
ADR_40a1b44:
	lea	smalrn:l,a0
	cmpb	#0x2,d0
	ble	ADR_40a1be2:l
	bra	ADR_40a1bea:l
ADR_40a1b5a:
	lea	smalrp:l,a0
	cmpb	#0x2,d0
	ble	ADR_40a1be2:l
	bra	ADR_40a1bea:l
ADR_40a1b70:
	subl	#0x30,d0
	tstb	d1
	beq	ADR_40a1ba8:l
	cmpb	#0x3,d1
	beq	ADR_40a1bc8:l
	lea	bigrzrm:l,a0
	cmpb	#0x1,d0
	ble	ADR_40a1be2:l
	cmpb	#0x7,d0
	ble	ADR_40a1bea:l
	bra	ADR_40a1be2:l
ADR_40a1ba8:
	lea	bigrn:l,a0
	cmpb	#0x1,d0
	ble	ADR_40a1be2:l
	cmpb	#0x7,d0
	ble	ADR_40a1bea:l
	bra	ADR_40a1be2:l
ADR_40a1bc8:
	lea	bigrp:l,a0
	cmpb	#0x1,d0
	ble	ADR_40a1be2:l
	cmpb	#0x7,d0
	ble	ADR_40a1bea:l
ADR_40a1be2:
	orl	#0x208,a6@(-124:w)
ADR_40a1bea:
	mulul	#0xc:l,d0
	movel	d1,a6@(-84:w)
	bfextu	a6@(-128:w){#24,#2},d1
	tstl	d1
	bne	ADR_40a1c0c:l
	.word	0xf230
	.word	0xd080
	.word	0x0800
	rts
ADR_40a1c0c:
	swap	d1
	addl	a6@(-84:w),d1
	movel	a0@(0:b,d0:l:1),a6@(-116:w)
	movel	a0@(4:b,d0:l:1),a6@(-112:w)
	movel	a0@(8:b,d0:l:1),a6@(-108:w)
	clrl	d0
	lea	a6@(-116:w),a0
	btst	#7,a0@(0:w)
	sne	a0@(2:w)
	.word	0x61ff
	.word	0xffff
	.word	0xca74
	bfclr	a0@(2:w){#0,#8}
	beq	ADR_40a1c4c:l
	bset	#7,a0@(0:w)
ADR_40a1c4c:
	.word	0xf210
	.word	0xd080
	rts
ADR_40a1c52:
	orb	#0x0,d1
	orb	d0,d0
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.globl	smod
smod:
	.word	0x2d7c
	.word	0x0000
	.word	0x0000
	.word	0xffbc
//
//	srem_mod.sa 1.10 10/3/90
//
//      The entry point sMOD computes the floating point MOD of the
//      input values X and Y. The entry point sREM computes the floating
//      point (IEEE) REM of the input values X and Y.
//
//      INPUT
//      -----
//      Double-extended value Y is pointed to by address in register
//      A0. Double-extended value X is located in -12(A0). The values
//      of X and Y are both nonzero and finite; although either or both
//      of them can be denormalized. The special cases of zeros, NaNs,
//      and infinities are handled elsewhere.
//
//      OUTPUT
//      ------
//      FREM(X,Y) or FMOD(X,Y), depending on entry point.
//
//       ALGORITHM
//       ---------
//
//       Step 1.  Save and strip signs of X and Y: signX := sign(X),
//                signY := sign(Y), X := |X|, Y := |Y|, 
//                signQ := signX EOR signY. Record whether MOD or REM
//                is requested.
//
//       Step 2.  Set L := expo(X)-expo(Y), k := 0, Q := 0.
//                If (L < 0) then
//                   R := X, go to Step 4.
//                else
//                   R := 2^(-L)X, j := L.
//                endif
//
//       Step 3.  Perform MOD(X,Y)
//            3.1 If R = Y, go to Step 9.
//            3.2 If R > Y, then { R := R - Y, Q := Q + 1}
//            3.3 If j = 0, go to Step 4.
//            3.4 k := k + 1, j := j - 1, Q := 2Q, R := 2R. Go to
//                Step 3.1.
//
//       Step 4.  At this point, R = X - QY = MOD(X,Y). Set
//                Last_Subtract := false (used in Step 7 below). If
//                MOD is requested, go to Step 6. 
//
//       Step 5.  R = MOD(X,Y), but REM(X,Y) is requested.
//            5.1 If R < Y/2, then R = MOD(X,Y) = REM(X,Y). Go to
//                Step 6.
//            5.2 If R > Y/2, then { set Last_Subtract := true,
//                Q := Q + 1, Y := signY*Y }. Go to Step 6.
//            5.3 This is the tricky case of R = Y/2. If Q is odd,
//                then { Q := Q + 1, signX := -signX }.
//
//       Step 6.  R := signX*R.
//
//       Step 7.  If Last_Subtract = true, R := R - Y.
//
//       Step 8.  Return signQ, last 7 bits of Q, and R as required.
//
//       Step 9.  At this point, R = 2^(-j)*X - Q Y = Y. Thus,
//                X = 2^(j)*(Q+1)Y. set Q := 2^(j)*(Q+1),
//                R := 0. Return signQ, last 7 bits of Q, and R.
//
//                
             
//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.


   bra                ADR_40a1c78
	.globl	srem
srem:
	movel	#0x1:l,a6@(-68:w)

// mod_rem:
//..Save sign of X and Y
ADR_40a1c78:
   moveml              d2-d7,a7@-     // save data registers
   movew               a0@,d3
	movew	d3,a6@(-60:w)
   andil               #0x00007fff,d3   // y := |y|

//
   movel               a0@(4),d4
   movel               a0@(8),d5        // (d3,d4,d5) is |y|

   tstl                d3
   bne                ADR_40a1ce0
	movel	#0x3ffe:l,d3
   tstl                d4
   bne                ADR_40a1cc0

// hiy_0:
   movel               d5,d4
   clrl                d5
   subil               #32,d3
   clrl                d6
   bfffo                d4{#0:#32},d6
   lsll                d6,d4
   subl                d6,d3           // (d3,d4,d5) is normalized
//                                       ...with bias $7FFD
   bra                ADR_40a1ce6

// hiy_not0:
ADR_40a1cc0:
   clrl                d6
   bfffo                d4{#0:#32},d6
   subl                d6,d3
   lsll                d6,d4
   movel               d5,d7           // a copy of d5
   lsll                d6,d5
   negl                d6
   addil               #32,d6
   lsrl                d6,d7
   orl                 d7,d4           // (d3,d4,d5) normalized
//                                       ...with bias $7FFD
   bra                ADR_40a1ce6

// y_normal:
ADR_40a1ce0:
   addil               #0x00003ffe,d3   // (d3,d4,d5) normalized
//                                       ...with bias $7FFD

// chk_x:
ADR_40a1ce6:
   movew               a0@(-12),d0
	movew	d0,a6@(-56:w)
	movew	a6@(-60:w),d1
   eorl                d0,d1
   andil               #0x00008000,d1
	movew	d1,a6@(-52:w)
   andil               #0x00007fff,d0
   movel               a0@(-8),d1
   movel               a0@(-4),d2       // (d0,d1,d2) is |x|
   tstl                d0
   bne                ADR_40a1d5c
	movel	#0x3ffe:l,d0
   tstl                d1
   bne                ADR_40a1d3c

// hix_0:
   movel               d2,d1
   clrl                d2
   subil               #32,d0
   clrl                d6
   bfffo                d1{#0:#32},d6
   lsll                d6,d1
   subl                d6,d0           // (d0,d1,d2) is normalized
//                                       ...with bias $7FFD
   bra                ADR_40a1d62

// hix_not0:
ADR_40a1d3c:
   clrl                d6
   bfffo                d1{#0:#32},d6
   subl                d6,d0
   lsll                d6,d1
   movel               d2,d7           // a copy of d2
   lsll                d6,d2
   negl                d6
   addil               #32,d6
   lsrl                d6,d7
   orl                 d7,d1           // (d0,d1,d2) normalized
//                                       ...with bias $7FFD
   bra                ADR_40a1d62

// x_normal:
ADR_40a1d5c:
   addil               #0x00003ffe,d0   // (d0,d1,d2) normalized
//                                       ...with bias $7FFD

// init:
//
ADR_40a1d62:
   movel               d3,a6@(l_scr1)   // save biased expo(y)
   movel		d0,a6@(l_scr2)	//save d0
   subl                d3,d0           // l := expo(x)-expo(y)
   clrl                d6              // d6 := carry <- 0
   clrl                d3              // d3 is q
   moveal              #0,a1           // a1 is k// j+k=l, q=0

//..(Carry,D1,D2) is R
   tstl                d0
   bge                ADR_40a1d88

//..expo(X) < expo(Y). Thus X = mod(X,Y)
//
   movel		a6@(l_scr2),d0	//restore d0
   bra                ADR_40a1e14

//..At this point  R = 2^(-L)X; Q = 0; k = 0; and  k+j = L


// mod_loop:
ADR_40a1d88:
   tstl                d6              // test carry bit
   bgt                ADR_40a1dac

//..At this point carry = 0, R = (D1,D2), Y = (D4,D5)
   cmpl                d4,d1           // compare hi(r) and hi(y)
   bne                ADR_40a1da6
   cmpl                d5,d2           // compare lo(r) and lo(y)
   bne                ADR_40a1da6

//..At this point, R = Y
   bra                ADR_40a1f32

// r_ne_y:
//..use the borrow of the previous compare
ADR_40a1da6:
   bcs                ADR_40a1db4          // borrow is set iff r < y

// r_gt_y:
//..If Carry is set, then Y < (Carry,D1,D2) < 2Y. Otherwise, Carry = 0
//..and Y < (D1,D2) < 2Y. Either way, perform R - Y
ADR_40a1dac:
   subl                d5,d2           // lo(r) - lo(y)
   subxl               d4,d1           // hi(r) - hi(y)
   clrl                d6              // clear carry
   addql               #1,d3           // q := q + 1

// r_lt_y:
//..At this point, Carry=0, R < Y. R = 2^(k-L)X - QY; k+j = L; j >= 0.
ADR_40a1db4:
   tstl                d0              // see if j = 0
   beq                ADR_40a1dce

   addl                d3,d3           // q := 2q
   addl                d2,d2           // lo(r) = 2lo(r)
   roxll               #1,d1           // hi(r) = 2hi(r) + carry
   scs                  d6              // set carry if 2(r) overflows
   addql               #1,a1           // k := k+1
   subql               #1,d0           // j := j - 1
//..At this point, R=(Carry,D1,D2) = 2^(k-L)X - QY, j+k=L, j >= 0, R < 2Y.

   bra                ADR_40a1d88

// postloop:
//..k = L, j = 0, Carry = 0, R = (D1,D2) = X - QY, R < Y.

//..normalize R.
ADR_40a1dce:
   movel               a6@(l_scr1),d0           // new biased expo of r
   tstl                d1
   bne                ADR_40a1df4

// hir_0:
   movel               d2,d1
   clrl                d2
   subil               #32,d0
   clrl                d6
   bfffo                d1{#0:#32},d6
   lsll                d6,d1
   subl                d6,d0           // (d0,d1,d2) is normalized
//                                       ...with bias $7FFD
   bra                ADR_40a1e14

// hir_not0:
ADR_40a1df4:
   clrl                d6
   bfffo                d1{#0:#32},d6
   bmi                ADR_40a1e14         // already normalized
   subl                d6,d0
   lsll                d6,d1
   movel               d2,d7           // a copy of d2
   lsll                d6,d2
   negl                d6
   addil               #32,d6
   lsrl                d6,d7
   orl                 d7,d1           // (d0,d1,d2) normalized

//
// get_mod:
ADR_40a1e14:
   cmpil		#0x000041fe,d0
   bge		ADR_40a1e58
	movew	d0,a6@(-100:w)
	clrw	a6@(-98:w)
	movel	d1,a6@(-96:w)
	movel	d2,a6@(-92:w)
   movel		a6@(l_scr1),d6
	movew	d6,a6@(-116:w)
	clrw	a6@(-114:w)
	movel	d4,a6@(-112:w)
	movel	d5,a6@(-108:w)
	fmovex	a6@(-100:w),fp0
	movel	#0x1:l,a6@(-48:w)
   bra		ADR_40a1e96
ADR_40a1e58:
	movel	d1,a6@(-96:w)
	movel	d2,a6@(-92:w)
   subil		#0x3ffe,d0
	movew	d0,a6@(-100:w)
	clrw	a6@(-98:w)
   movel		a6@(l_scr1),d6
   subil		#0x3ffe,d6
   movel		d6,a6@(l_scr1)
	fmovex	a6@(-100:w),fp0
	movew	d6,a6@(-116:w)
	movel	d4,a6@(-112:w)
	movel	d5,a6@(-108:w)
	movel	#0x0:l,a6@(-48:w)
ADR_40a1e96:
	movel	a6@(-68:w),d6
   beq                ADR_40a1ed8

   movel               a6@(l_scr1),d6           // new biased expo(y)
   subql               #1,d6           // biased expo(y/2)
   cmpl                d6,d0
   blt                ADR_40a1ed8
   bgt                ADR_40a1ed0

   cmpl                d4,d1
   bne                ADR_40a1eca
   cmpl                d5,d2
   bne                ADR_40a1eca
   bra                ADR_40a1f60

// not_eq:
ADR_40a1eca:
   bcs                ADR_40a1ed8
ADR_40a1ed0:
	fsubx	a6@(-116:w),fp0
   addql               #1,d3           // q := q + 1
ADR_40a1ed8:
	movew	a6@(-56:w),d6
   bge		ADR_40a1ee6
   fnegx		fp0

//..Get Q
//
// get_q:
ADR_40a1ee6:
   clrl		d6		
	movew	a6@(-52:w),d6
   movel               #8,d7
   lsrl                d7,d6           
   andil               #0x0000007f,d3   // 7 bits of q
   orl                 d6,d3           // sign and bits of q
   swap                 d3
   fmovel              fpsr,d6
   andil               #0xff00ffff,d6
   orl                 d3,d6
   fmovel              d6,fpsr         // put q in fpsr

//
// restore:
   moveml              a7@+,d2-d7
	fmoveml	a6@(-128:w),fpc
	movel	a6@(-48:w),d0
	beq	ADR_40a1f2c:l
   fmulx		ADR_40a1c52,fp0	// may cause underflow
   bra			t_avoid_unsupp	//check for denorm as a
ADR_40a1f2c:
	fmovex	fp0
//					;result of the scaling

// finish:
	rts

// rem_is_0:
//..R = 2^(-j)X - Q Y = Y, thus R = 0 and quotient = 2^j (Q+1)
ADR_40a1f32:
   addql               #1,d3
   cmpil               #8,d0           // d0 is j 
   bge                ADR_40a1f48

   lsll                d0,d3
   bra                ADR_40a1f4a

// q_big:
ADR_40a1f48:
   clrl                d3

// set_r_0:
ADR_40a1f4a:
   fmoves		#0x00000000,fp0
	movel	#0x0:l,a6@(-48:w)
   bra                ADR_40a1ed8

// tie_case:
//..Check parity of Q
ADR_40a1f60:
   movel               d3,d6
   andil               #0x00000001,d6
   tstl                d6
   beq                ADR_40a1ed8	// q is even

//..Q is odd, Q := Q + 1, signX := -signX
   addql               #1,d3
	movew	a6@(-56:w),d6
   eoril               #0x00008000,d6
	movew	d6,a6@(-56:w)
   bra                ADR_40a1ed8
//
//	ssin.sa 1.8 10/11/90
//
//	The entry point sSIN computes the sine of an input argument
//	sCOS computes the cosine, and sSINCOS computes both. The
//	corresponding entry points with a "d" computes the same
//	corresponding function values for denormalized inputs.
//
//	Input: Double-extended number X in location pointed to
//		by address register a0.
//
//	Output: The funtion value sin(X) or cos(X) returned in Fp0 if SIN or
//		COS is requested. Otherwise, for SINCOS, sin(X) is returned
//		in Fp0, and cos(X) is returned in Fp1.
//
//	Modifies: Fp0 for SIN or COS; both Fp0 and Fp1 for SINCOS.
//
//	Accuracy and Monotonicity: The returned result is within 1 ulp in
//		64 significant bit, i.e. within 0.5001 ulp to 53 bits if the
//		result is subsequently rounded to double precision. The
//		result is provably monotonic in double precision.
//
//	Speed: The programs sSIN and sCOS take approximately 150 cycles for
//		input argument X such that |X| < 15Pi, which is the the usual
//		situation. The speed for sSINCOS is approximately 190 cycles.
//
//	Algorithm:
//
//	SIN and COS:
//	1. If SIN is invoked, set AdjN := 0; otherwise, set AdjN := 1.
//
//	2. If |X| >= 15Pi or |X| < 2**(-40), go to 7.
//
//	3. Decompose X as X = N(Pi/2) + r where |r| <= Pi/4. Let
//		k = N mod 4, so in particular, k = 0,1,2,or 3. Overwirte
//		k by k := k + AdjN.
//
//	4. If k is even, go to 6.
//
//	5. (k is odd) Set j := (k-1)/2, sgn := (-1)**j. Return sgn*cos(r)
//		where cos(r) is approximated by an even polynomial in r,
//		1 + r*r*(B1+s*(B2+ ... + s*B8)),	s = r*r.
//		Exit.
//
//	6. (k is even) Set j := k/2, sgn := (-1)**j. Return sgn*sin(r)
//		where sin(r) is approximated by an odd polynomial in r
//		r + r*s*(A1+s*(A2+ ... + s*A7)),	s = r*r.
//		Exit.
//
//	7. If |X| > 1, go to 9.
//
//	8. (|X|<2**(-40)) If SIN is invoked, return X; otherwise return 1.
//
//	9. Overwrite X by X := X rem 2Pi. Now that |X| <= Pi, go back to 3.
//
//	SINCOS:
//	1. If |X| >= 15Pi or |X| < 2**(-40), go to 6.
//
//	2. Decompose X as X = N(Pi/2) + r where |r| <= Pi/4. Let
//		k = N mod 4, so in particular, k = 0,1,2,or 3.
//
//	3. If k is even, go to 5.
//
//	4. (k is odd) Set j1 := (k-1)/2, j2 := j1 (EOR) (k mod 2), i.e.
//		j1 exclusive or with the l.s.b. of k.
//		sgn1 := (-1)**j1, sgn2 := (-1)**j2.
//		SIN(X) = sgn1 * cos(r) and COS(X) = sgn2*sin(r) where
//		sin(r) and cos(r) are computed as odd and even polynomials
//		in r, respectively. Exit
//
//	5. (k is even) Set j1 := k/2, sgn1 := (-1)**j1.
//		SIN(X) = sgn1 * sin(r) and COS(X) = sgn1*cos(r) where
//		sin(r) and cos(r) are computed as odd and even polynomials
//		in r, respectively. Exit
//
//	6. If |X| > 1, go to 8.
//
//	7. (|X|<2**(-40)) SIN(X) = X and COS(X) = 1. Exit.
//
//	8. Overwrite X by X := X rem 2Pi. Now that |X| <= Pi, go back to 2.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



 	.int 0x3fd78000,0x4004bc7e
ADR_40a1f8e:
 	.int 0x3fe45f30,0x6dc9c883

ADR_40a1f96:
 	.int 0xbd6aaa77,0xccc994f5
ADR_40a1f9e:
 	.int 0x3de61209,0x7aae8da1

ADR_40a1fa6:
 	.int 0xbe5ae645,0x2a118ae4
ADR_40a1fae:
 	.int 0x3ec71de3,0xa5341531

ADR_40a1fb6:
 	.int 0xbf2a01a0,0x1a018b59,0x00000000,0x00000000
ADR_40a1fc6:
	.word	0x3ff8
	.word	0x0000
	.word	0x8888
	.word	0x8888
	.word	0x8888
	subql	#0x4,sp@(0:w)
	.word	0x0000

ADR_40a1fd6:
 	.int 0xbffc0000,0xaaaaaaaa,0xaaaaaa99,0x00000000

ADR_40a1fe6:
 	.int 0x3d2ac4d0,0xd6011ee3
ADR_40a1fee:
 	.int 0xbda9396f,0x9f45ac19

ADR_40a1ff6:
 	.int 0x3e21eed9,0x0612c972
ADR_40a1ffe:
 	.int 0xbe927e4f,0xb79d9fcf

ADR_40a2006:
 	.int 0x3efa01a0,0x1a01d423,0x00000000,0x00000000

ADR_40a2016:
 	.int 0xbff50000,0xb60b60b6,0x0b61d438,0x00000000

ADR_40a2026:
 	.int 0x3ffa0000,0xaaaaaaaa,0xaaaaab5e
ADR_40a2032:
 	.int 0xbf000000
	.word	0x3ffc
	.word	0x0000
	.word	0xa2f9
	orw	d1,a6@(20036:w)
	moveb	a2@(16385:w),a2@-
	.word	0x0000
	.word	0xc90f
	addl	a2@-,d5
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x3fdf
	.word	0x0000
	.word	0x85a3
	bset	#0,a4@
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.globl	ssind
ssind:
	.word	0x60ff
	.word	0xffff
	.word	0xac64
	.globl	scosd
scosd:
	fmoves	#0s1,fp0
//
//	9D25B Fix: Sometimes the previous fmove.s sets fpsr bits
//
	fmovel		#0,fpsr
//
	bra		t_frcinx
	.globl	ssin
ssin:
	movel	#0x0:l,a6@(-68:w)
	bra		ADR_40a2094
	.globl	scos
scos:
	movel	#0x1:l,a6@(-68:w)

ADR_40a2094:
	fmovex		a0@,fp0	// load input
	movel	a0@,d0
	movew	a0@(4:w),d0
	fmovex	fp0,a6@(-32:w)
	andil		#0x7fffffff,d0
	cmpl	#0x3fd78000,d0
	bge	ADR_40a20bc:l
	bra	ADR_40a2248:l
ADR_40a20bc:
	cmpl	#0x4004bc7e,d0
	blt	ADR_40a20ce:l
	bra	ADR_40a2288:l

// sinmain:
//--THIS IS THE USUAL CASE, |X| <= 15 PI.
//--THE ARGUMENT REDUCTION IS DONE BY TABLE LOOK UP.
ADR_40a20ce:
	fmovex		fp0,fp1
	fmuld		ADR_40a1f8e,fp1	// x*2/pi
	.word	0x43f9
	.word	0x040a
	.word	0x2ab6
	fmovel	fp1,a6@(-80:w)
	movel	a6@(-80:w),d0
	asll		#4,d0
	addal		d0,a1	// a1 is the address of n*piby2
//				...WHICH IS IN TWO PIECES Y1 & Y2

	fsubx		a1@+,fp0	// x-y1
	fsubs		a1@,fp0	// fp0 is r = (x-y1)-y2
ADR_40a20f6:
	movel	a6@(-80:w),d0
	addl	a6@(-68:w),d0
	rorl		#1,d0	// d0 was odd iff d0 is negative
	cmpil		#0,d0
	blt		ADR_40a2198
	fmovex	fp0,a6@(-32:w)
	fmulx		fp0,fp0	// fp0 is s
//---HIDE THE NEXT TWO WHILE WAITING FOR FP0
	fmoved		ADR_40a1f96,fp3
	fmoved		ADR_40a1f9e,fp2
//--FP0 IS NOW READY
	fmovex		fp0,fp1
	fmulx		fp1,fp1	// fp1 is t
//--HIDE THE NEXT TWO WHILE WAITING FOR FP1

	rorl		#1,d0
	andil		#0x80000000,d0
	eorl	d0,a6@(-32:w)

	fmulx		fp1,fp3	// ta7
	fmulx		fp1,fp2	// ta6

	faddd		ADR_40a1fa6,fp3 // a5+ta7
	faddd		ADR_40a1fae,fp2 // a4+ta6

	fmulx		fp1,fp3	// t(a5+ta7)
	fmulx		fp1,fp2	// t(a4+ta6)

	faddd		ADR_40a1fb6,fp3 // a3+t(a5+ta7)
	faddx		ADR_40a1fc6,fp2 // a2+t(a4+ta6)

	fmulx		fp3,fp1	// t(a3+t(a5+ta7))

	fmulx		fp0,fp2	// s(a2+t(a4+ta6))
	faddx		ADR_40a1fd6,fp1 // a1+t(a3+t(a5+ta7))
	fmulx	a6@(-32:w),fp0

	faddx		fp2,fp1	// [a1+t(a3+t(a5+ta7))]+[s(a2+t(a4+ta6))]

	fmulx		fp1,fp0		// sin(r')-r'

	fmovel		d1,fpcr		//restore users exceptions
	faddx	a6@(-32:w),fp0
	bra		t_frcinx


// cospoly:
//--LET J BE THE LEAST SIG. BIT OF D0, LET SGN := (-1)**J.
//--THEN WE RETURN	SGN*COS(R). SGN*COS(R) IS COMPUTED BY
//--SGN + S'*(B1 + S(B2 + S(B3 + S(B4 + ... + SB8)))), WHERE
//--S=R*R AND S'=SGN*S. THIS CAN BE REWRITTEN AS
//--SGN + S'*([B1+T(B3+T(B5+TB7))] + [S(B2+T(B4+T(B6+TB8)))])
//--WHERE T=S*S.
//--NOTE THAT B4 THROUGH B8 ARE STORED IN DOUBLE PRECISION
//--WHILE B2 AND B3 ARE IN DOUBLE-EXTENDED FORMAT, B1 IS -1/2
//--AND IS THEREFORE STORED AS SINGLE PRECISION.

ADR_40a2198:
	fmulx		fp0,fp0	// fp0 is s
//---HIDE THE NEXT TWO WHILE WAITING FOR FP0
	fmoved		ADR_40a1fe6,fp2
	fmoved		ADR_40a1fee,fp3
//--FP0 IS NOW READY
	fmovex		fp0,fp1
	fmulx		fp1,fp1	// fp1 is t
	fmovex	fp0,a6@(-32:w)
	rorl		#1,d0
	andil		#0x80000000,d0
//			...LEAST SIG. BIT OF D0 IN SIGN POSITION

	fmulx		fp1,fp2	// tb8
	eorl	d0,a6@(-32:w)
	andil		#0x80000000,d0

	fmulx		fp1,fp3	// tb7
//--HIDE THE NEXT TWO WHILE WAITING FOR THE XU
	oril		#0x3f800000,d0	// d0 is sgn in single
	movel	d0,a6@(-84:w)

	faddd		ADR_40a1ff6,fp2 // b6+tb8
	faddd		ADR_40a1ffe,fp3 // b5+tb7

	fmulx		fp1,fp2	// t(b6+tb8)
	fmulx		fp1,fp3	// t(b5+tb7)

	faddd		ADR_40a2006,fp2 // b4+t(b6+tb8)
	faddx		ADR_40a2016,fp3 // b3+t(b5+tb7)

	fmulx		fp1,fp2	// t(b4+t(b6+tb8))
	fmulx		fp3,fp1	// t(b3+t(b5+tb7))

	faddx		ADR_40a2026,fp2 // b2+t(b4+t(b6+tb8))
	fadds		ADR_40a2032,fp1 // b1+t(b3+t(b5+tb7))

	fmulx		fp2,fp0	// s(b2+t(b4+t(b6+tb8)))

	faddx		fp1,fp0
	fmulx	a6@(-32:w),fp0

	fmovel		d1,fpcr		//restore users exceptions
	fadds	a6@(-84:w),fp0
	bra		t_frcinx


// sinbors:
//--IF |X| > 15PI, WE USE THE GENERAL ARGUMENT REDUCTION.
//--IF |X| < 2**(-40), RETURN X OR 1.
	cmpil		#0x3fff8000,d0
	bgt		ADR_40a2288
ADR_40a2248:
	movel	a6@(-68:w),d0
	cmpil		#0,d0
	bgt		ADR_40a226e
	movew	#0x0:w,a6@(-30:w)
	fmovel		d1,fpcr		//restore users exceptions
	fmovex	a6@(-32:w),fp0
	bra		t_frcinx
ADR_40a226e:
	fmoves	#0s1,fp0

	fmovel		d1,fpcr		//restore users exceptions
	.word	0xf23c
	.word	0x4428
	.word	0x0080
	.word	0x0000
	bra		t_frcinx
ADR_40a2288:
	fmovemx	fp2/fp3/fp4/fp5,sp@-
	movel		d2,a7@-
	fmoves	#0s0,fp1
	cmpl	#0x7ffeffff,d0
	bne	ADR_40a22fa:l
	movel	#0x7ffe0000:l,a6@(-100:w)
	movel	#0xc90fdaa2:l,a6@(-96:w)
	clrl	a6@(-92:w)
	ftstx	fp0
	movel	#0x7fdc0000:l,a6@(-64:w)
	movel	#0x85a308d3:l,a6@(-60:w)
	clrl	a6@(-56:w)
	fblt	ADR_40a22e0:l
	orw	#0x8000,a6@(-100:w)
	orw	#0x8000,a6@(-64:w)
ADR_40a22e0:
	faddx	a6@(-100:w),fp0
	fmovex	fp0,fp1
	faddx	a6@(-64:w),fp0
	fsubx	fp0,fp1
	faddx	a6@(-64:w),fp1
ADR_40a22fa:
	fmovex	fp0,a6@(-48:w)
	movew	a6@(-48:w),d0
	movel	d0,a1
	andil		#0x00007fff,d0
	subil		#0x00003fff,d0	// d0 is k
	cmpil		#28,d0
	ble		ADR_40a2332
	subl	#0x1b,d0
	movel	#0x0:l,a6@(-80:w)
	bra		ADR_40a233c
// lastloop:
ADR_40a2332:
	clrl		d0		// d0 is l := 0
	movel	#0x1:l,a6@(-80:w)
ADR_40a233c:
	movel	#0x3ffe:l,d2
	subl		d0,d2		// biased expo of 2**(-l)*invtwopi
	movel	#0xa2f9836e:l,a6@(-112:w)
	movel	#0x4e44152a:l,a6@(-108:w)
	movew	d2,a6@(-116:w)
	fmovex	fp0,fp2
	fmulx	a6@(-116:w),fp2
	movel	a1,d2
	swap	d2
	andil		#0x80000000,d2
	oril		#0x5f000000,d2	// d2 is sign(inarg)*2**63 in sgl
	movel	d2,a6@(-84:w)

	movel		d0,d2
	addl	#0x3fff,d2
	fadds	a6@(-84:w),fp2
	movew	d2,a6@(-100:w)
	clrw	a6@(-98:w)
	movel	#0xc90fdaa2:l,a6@(-96:w)
	clrl	a6@(-92:w)
	fsubs	a6@(-84:w),fp2
	addl	#0x3fdd,d0
	movew	d0,a6@(-64:w)
	clrw	a6@(-62:w)
	movel	#0x85a308d3:l,a6@(-60:w)
	clrl	a6@(-56:w)
	movel	a6@(-80:w),d0
	fmovex	fp2,fp4
	fmulx	a6@(-100:w),fp4
	fmovex	fp2,fp5
	fmulx	a6@(-64:w),fp5
	fmovex	fp4,fp3
	faddx	fp5,fp3
	fsubx	fp3,fp4
	fsubx	fp3,fp0
	faddx	fp5,fp4
	fmovex	fp0,fp3
	fsubx	fp4,fp1
	faddx	fp1,fp0
//--FP0 IS X REM 2**L * 2PI
	cmpil		#0,d0
	bgt	ADR_40a240a:l
	fsubx	fp0,fp3
	faddx	fp3,fp1
	bra	ADR_40a22fa:l
ADR_40a240a:
	fmovel	fp2,a6@(-80:w)

// restore:
	movel		a7@+,d2
	fmovemx	sp@+,fp2/fp3/fp4/fp5
	movel	a6@(-68:w),d0
	cmpil		#4,d0
	blt	ADR_40a20f6:l
	bra	ADR_40a24aa:l
	.globl	ssincosd
ssincosd:
	fmoves	#0s1,fp1
	bsr		sto_cos		//store cosine result
	.word	0x60ff
	.word	0xffff
	.word	0xa88c
	.globl	ssincos
ssincos:
	movel	#0x4:l,a6@(-68:w)

	fmovex		a0@,fp0	// load input
	movel	a0@,d0
	movew	a0@(4:w),d0
	fmovex	fp0,a6@(-32:w)
	andil		#0x7fffffff,d0
	cmpl	#0x3fd78000,d0
	bge	ADR_40a2470:l
	bra	ADR_40a26fc:l
ADR_40a2470:
	cmpl	#0x4004bc7e,d0
	blt	ADR_40a2482:l
	bra	ADR_40a2288:l

// scmain:
//--THIS IS THE USUAL CASE, |X| <= 15 PI.
//--THE ARGUMENT REDUCTION IS DONE BY TABLE LOOK UP.
ADR_40a2482:
	fmovex		fp0,fp1
	fmuld		ADR_40a1f8e,fp1	// x*2/pi
	.word	0x43f9
	.word	0x040a
	.word	0x2ab6
	fmovel	fp1,a6@(-80:w)
	movel	a6@(-80:w),d0
	asll		#4,d0
	addal		d0,a1		// address of n*piby2, in y1, y2

	fsubx		a1@+,fp0	// x-y1

	fsubs		a1@,fp0	// fp0 is r = (x-y1)-y2
ADR_40a24aa:
	movel	a6@(-80:w),d0
	rorl	#1,d0
	cmpil		#0,d0		// d0 < 0 iff n is odd
	bge		ADR_40a25e2
	fmovex	fp0,a6@(-116:w)
	fmulx		fp0,fp0	 // fp0 is s = r*r
	fmoved		ADR_40a1f96,fp1	// a7
	fmoved		ADR_40a1fe6,fp2	// b8
	fmulx		fp0,fp1	 // sa7
	movel		d2,a7@-
	movel		d0,d2
	fmulx		fp0,fp2	 // sb8
	rorl		#1,d2
	andil		#0x80000000,d2

	faddd		ADR_40a1f9e,fp1	// a6+sa7
	eorl		d0,d2
	andil		#0x80000000,d2
	faddd		ADR_40a1fee,fp2	// b7+sb8

	fmulx		fp0,fp1	 // s(a6+sa7)
	eorl	d2,a6@(-116:w)
	movel		a7@+,d2
	fmulx		fp0,fp2	 // s(b7+sb8)
	rorl		#1,d0
	andil		#0x80000000,d0

	faddd		ADR_40a1fa6,fp1	// a5+s(a6+sa7)
	movel	#0x3f800000:l,a6@(-84:w)
	eorl	d0,a6@(-84:w)
	faddd		ADR_40a1ff6,fp2	// b6+s(b7+sb8)

	fmulx		fp0,fp1	 // s(a5+s(a6+sa7))
	fmulx		fp0,fp2	 // s(b6+s(b7+sb8))
	fmovex	fp0,a6@(-100:w)

	faddd		ADR_40a1fae,fp1	// a4+s(a5+s(a6+sa7))
	eorl	d0,a6@(-100:w)
	faddd		ADR_40a1ffe,fp2	// b5+s(b6+s(b7+sb8))

	fmulx		fp0,fp1	 // s(a4+// )
	fmulx		fp0,fp2	 // s(b5+// )

	faddd		ADR_40a1fb6,fp1	// a3+s(a4+// )
	faddd		ADR_40a2006,fp2	// b4+s(b5+// )

	fmulx		fp0,fp1	 // s(a3+// )
	fmulx		fp0,fp2	 // s(b4+// )

	faddx		ADR_40a1fc6,fp1	// a2+s(a3+// )
	faddx		ADR_40a2016,fp2	// b3+s(b4+// )

	fmulx		fp0,fp1	 // s(a2+// )
	fmulx		fp0,fp2	 // s(b3+// )

	faddx		ADR_40a1fd6,fp1	// a1+s(a2+// )
	faddx		ADR_40a2026,fp2	// b2+s(b3+// )

	fmulx		fp0,fp1	 // s(a1+// )
	fmulx		fp2,fp0	 // s(b2+// )
	fmulx	a6@(-116:w),fp1
	fadds		ADR_40a2032,fp0	// b1+s(b2// )
	fmulx	a6@(-100:w),fp0
	movel	d1,sp@-
	andl	#0xff,d1

	fmovel		d1,fpcr		//restore users exceptions
	faddx	a6@(-116:w),fp1
	bsr		sto_cos		//store cosine result
	fmoveml	sp@+,fpc
	fadds	a6@(-84:w),fp0

	bra		t_frcinx
ADR_40a25e2:
	fmovex	fp0,a6@(-116:w)
	fmulx		fp0,fp0	 // fp0 is s = r*r
	fmoved		ADR_40a1fe6,fp1			// b8
	fmoved		ADR_40a1f96,fp2			// a7
	fmulx		fp0,fp1	 // sb8
	fmovex	fp0,a6@(-100:w)
	fmulx		fp0,fp2	 // sa7
	rorl		#1,d0
	andil		#0x80000000,d0
	faddd		ADR_40a1fee,fp1	// b7+sb8
	faddd		ADR_40a1f9e,fp2	// a6+sa7
	eorl	d0,a6@(-116:w)
	eorl	d0,a6@(-100:w)
	fmulx		fp0,fp1	 // s(b7+sb8)
	oril		#0x3f800000,d0
	movel	d0,a6@(-84:w)
	fmulx		fp0,fp2	 // s(a6+sa7)

	faddd		ADR_40a1ff6,fp1	// b6+s(b7+sb8)
	faddd		ADR_40a1fa6,fp2	// a5+s(a6+sa7)

	fmulx		fp0,fp1	 // s(b6+s(b7+sb8))
	fmulx		fp0,fp2	 // s(a5+s(a6+sa7))

	faddd		ADR_40a1ffe,fp1	// b5+s(b6+s(b7+sb8))
	faddd		ADR_40a1fae,fp2	// a4+s(a5+s(a6+sa7))

	fmulx		fp0,fp1	 // s(b5+// )
	fmulx		fp0,fp2	 // s(a4+// )

	faddd		ADR_40a2006,fp1	// b4+s(b5+// )
	faddd		ADR_40a1fb6,fp2	// a3+s(a4+// )

	fmulx		fp0,fp1	 // s(b4+// )
	fmulx		fp0,fp2	 // s(a3+// )

	faddx		ADR_40a2016,fp1	// b3+s(b4+// )
	faddx		ADR_40a1fc6,fp2	// a2+s(a3+// )

	fmulx		fp0,fp1	 // s(b3+// )
	fmulx		fp0,fp2	 // s(a2+// )

	faddx		ADR_40a2026,fp1	// b2+s(b3+// )
	faddx		ADR_40a1fd6,fp2	// a1+s(a2+// )

	fmulx		fp0,fp1	 // s(b2+// )
	fmulx		fp2,fp0	 // s(a1+// )
	fadds		ADR_40a2032,fp1	// b1+s(b2// )
	fmulx	a6@(-116:w),fp0
	fmulx	a6@(-100:w),fp1
	movel	d1,sp@-
	andl	#0xff,d1

	fmovel		d1,fpcr		//restore users exceptions
	fadds	a6@(-84:w),fp1
	bsr		sto_cos		//store cosine result
	fmoveml	sp@+,fpc
	faddx	a6@(-116:w),fp0

	bra		t_frcinx

// scbors:
	cmpil		#0x3fff8000,d0
	bgt		ADR_40a2288
ADR_40a26fc:
	movew	#0x0:w,a6@(-30:w)
	fmoves	#0s1,fp1
	movel	d1,sp@-
	andl	#0xff,d1

	fmovel		d1,fpcr		//restore users exceptions
	.word	0xf23c
	.word	0x44a8
	.word	0x0080
	.word	0x0000
	bsr		sto_cos		//store cosine result
	fmoveml	sp@+,fpc
	fmovex	a6@(-32:w),fp0
	bra		t_frcinx
//
//	ssinh.sa 1.4 10/1/90
//
//       The entry point sSinh computes the hyperbolic sine of
//       an input argument; sSinhd does the same except for denormalized
//       input.
//
//       Input: Double-extended number X in location pointed to 
//		by address register a0.
//
//       Output: The value sinh(X) returned in floating-point register Fp0.
//
//       Accuracy and Monotonicity: The returned result is within 3 ulps in
//               64 significant bit, i.e. within 0.5001 ulp to 53 bits if the
//               result is subsequently rounded to double precision. The
//               result is provably monotonic in double precision.
//
//       Speed: The program sSINH takes approximately 280 cycles.
//
//       Algorithm:
//
//       SINH
//       1. If |X| > 16380 log2, go to 3.
//
//       2. (|X| <= 16380 log2) Sinh(X) is obtained by the formulae
//               y = |X|, sgn = sign(X), and z = expm1(Y),
//               sinh(X) = sgn*(1/2)*( z + z/(1+z) ).
//          Exit.
//
//       3. If |X| > 16480 log2, go to 5.
//
//       4. (16380 log2 < |X| <= 16480 log2)
//               sinh(X) = sign(X) * exp(|X|)/2.
//          However, invoking exp(|X|) may cause premature overflow.
//          Thus, we calculate sinh(X) as follows:
//             Y       := |X|
//             sgn     := sign(X)
//             sgnFact := sgn * 2**(16380)
//             Y'      := Y - 16381 log2
//             sinh(X) := sgnFact * exp(Y').
//          Exit.
//
//       5. (|X| > 16480 log2) sinh(X) must overflow. Return
//          sign(X)*Huge*Huge to generate overflow and an infinity with
//          the appropriate sign. Huge is the largest finite number in
//          extended format. Exit.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



ADR_40a2734:
 	.int 0x40c62d38,0xd3d64634 //  16381 log2 lead
ADR_40a273c:
 	.int 0x3d6f90ae,0xb1e75cc7 //  16381 log2 trail
	.globl	ssinhd
ssinhd:
	.word	0x60ff
	.word	0xffff
	.word	0xa582

	.globl	ssinh
ssinh:
	fmovex	a0@,fp0	// load input

	movel	a0@,d0
	movew	a0@(4),d0
	movel	d0,a1		//save a copy of original compacted operand
	andl	#0x7fffffff,d0
	cmpl	#0x400cb167,d0
	bgt	ADR_40a27be

//--THIS IS THE USUAL CASE, |X| < 16380 LOG2
//--Y = |X|, Z = EXPM1(Y), SINH(X) = SIGN(X)*(1/2)*( Z + Z/(1+Z) )

	fabsx	fp0		// y = |x|

	moveml	a1/d1,sp@-
	fmovemx fp0-fp0,a0@
	clrl	d1
	bsr	setoxm1	 	// fp0 is z = expm1(y)
	fmoveml	#0x0:l,fpc
	moveml	sp@+,a1/d1

	fmovex	fp0,fp1
	fadds	#0s1,fp1
	fmovex	fp0,sp@-
	fdivx	fp1,fp0		// z/(1+z)
	movel	a1,d0
	andl	#0x80000000,d0
	orl	#0x3f000000,d0
	faddx	sp@+,fp0
	movel	d0,sp@-

	fmovel	d1,fpcr
	fmuls	sp@+,fp0	//last fp inst - possible exceptions set

	bra	t_frcinx

// sinhbig:
ADR_40a27be:
	cmpl	#0x400cb2b3,d0
	.word	0x6eff
	.word	0xffff
	.word	0xa384
	fabsx	fp0
	fsubd	ADR_40a2734,fp0		// (|x|-16381log2_lead)
	movel	#0,sp@-
	movel	#0x80000000,sp@-
	movel	a1,d0
	andl	#0x80000000,d0
	orl	#0x7ffb0000,d0
	movel	d0,sp@-	// extended fmt
	fsubd	ADR_40a273c,fp0		// |x| - 16381 log2, accurate

	movel	d1,sp@-
	clrl	d1
	fmovemx fp0-fp0,a0@
	bsr	setox
	fmoveml	sp@+,fpc
	fmulx	sp@+,fp0	//possible exception
	bra	t_frcinx
//
//	stan.sa 1.4 10/1/90
//
//	The entry point stan computes the tangent of
//	an input argument;
//	stand does the same except for denormalized input.
//
//	Input: Double-extended number X in location pointed to
//		by address register a0.
//
//	Output: The value tan(X) returned in floating-point register Fp0.
//
//	Accuracy and Monotonicity: The returned result is within 3 ulp in
//		64 significant bit, i.e. within 0.5001 ulp to 53 bits if the
//		result is subsequently rounded to double precision. The
//		result is provably monotonic in double precision.
//
//	Speed: The program sTAN takes approximately 170 cycles for
//		input argument X such that |X| < 15Pi, which is the the usual
//		situation.
//
//	Algorithm:
//
//	1. If |X| >= 15Pi or |X| < 2**(-40), go to 6.
//
//	2. Decompose X as X = N(Pi/2) + r where |r| <= Pi/4. Let
//		k = N mod 2, so in particular, k = 0 or 1.
//
//	3. If k is odd, go to 5.
//
//	4. (k is even) Tan(X) = tan(r) and tan(r) is approximated by a
//		rational function U/V where
//		U = r + r*s*(P1 + s*(P2 + s*P3)), and
//		V = 1 + s*(Q1 + s*(Q2 + s*(Q3 + s*Q4))),  s = r*r.
//		Exit.
//
//	4. (k is odd) Tan(X) = -cot(r). Since tan(r) is approximated by a
//		rational function U/V where
//		U = r + r*s*(P1 + s*(P2 + s*P3)), and
//		V = 1 + s*(Q1 + s*(Q2 + s*(Q3 + s*Q4))), s = r*r,
//		-Cot(r) = -V/U. Exit.
//
//	6. If |X| > 1, go to 8.
//
//	7. (|X|<2**(-40)) Tan(X) = X. Exit.
//
//	8. Overwrite X by X := X rem 2Pi. Now that |X| <= Pi, go back to 2.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



 	.int 0x3fd78000,0x4004bc7e
ADR_40a281e:
 	.int 0x3fe45f30,0x6dc9c883

ADR_40a2826:
 	.int 0x3ea0b759,0xf50f8688
ADR_40a282e:
 	.int 0xbef2baa5,0xa8924f04

ADR_40a2836:
 	.int 0xbf346f59,0xb39ba65f,0x00000000,0x00000000

ADR_40a2846:
 	.int 0x3ff60000,0xe073d3fc,0x199c4a00,0x00000000

ADR_40a2856:
 	.int 0x3ff90000,0xd23cd684,0x15d95fa1,0x00000000

ADR_40a2866:
 	.int 0xbffc0000,0x8895a6c5,0xfb423bca,0x00000000

ADR_40a2876:
 	.int 0xbffd0000,0xeef57e0d,0xa84bc8ce,0x00000000
	.word	0x3ffc
	.word	0x0000
	.word	0xa2f9
	orw	d1,a6@(20036:w)
	moveb	a2@(0:w),a2@-
	.word	0x0000
	.word	0x4001
	.word	0x0000
	.word	0xc90f
	addl	a2@-,d5
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x3fdf
	.word	0x0000
	.word	0x85a3
	bset	#0,a4@
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.globl	pitbl
pitbl:
	.word	0xc004
	.word	0x0000
	.word	0xc90f
	.word	0xdaa2
	.word	0x2168
	.word	0xc235
	.word	0x2180
	.word	0x0000
	.word	0xc004
	.word	0x0000
	.word	0xc2c7
	.word	0x5bcd
	.word	0x105d
	.word	0x7c23
	.word	0xa0d0
	.word	0x0000
	.word	0xc004
	.word	0x0000
	.word	0xbc7e
	.word	0xdcf7
	.word	0xff52
	.word	0x3611
	.word	0xa1e8
	.word	0x0000
	.word	0xc004
	.word	0x0000
	.word	0xb636
	.word	0x5e22
	.word	0xee46
	.word	0xf000
	.word	0x2148
	.word	0x0000
	.word	0xc004
	.word	0x0000
	.word	0xafed
	.word	0xdf4d
	.word	0xdd3b
	.word	0xa9ee
	.word	0xa120
	.word	0x0000
	.word	0xc004
	.word	0x0000
	.word	0xa9a5
	.word	0x6078
	.word	0xcc30
	.word	0x63dd
	.word	0x21fc
	.word	0x0000
	.word	0xc004
	.word	0x0000
	.word	0xa35c
	.word	0xe1a3
	.word	0xbb25
	.word	0x1dcb
	.word	0x2110
	.word	0x0000
	.word	0xc004
	.word	0x0000
	.word	0x9d14
	.word	0x62ce
	.word	0xaa19
	.word	0xd7b9
	.word	0xa158
	.word	0x0000
	.word	0xc004
	.word	0x0000
	.word	0x96cb
	.word	0xe3f9
	.word	0x990e
	.word	0x91a8
	.word	0x21e0
	.word	0x0000
	.word	0xc004
	.word	0x0000
	.word	0x9083
	.word	0x6524
	.word	0x8803
	.word	0x4b96
	.word	0x20b0
	.word	0x0000
	.word	0xc004
	.word	0x0000
	.word	0x8a3a
	.word	0xe64f
	.word	0x76f8
	.word	0x0584
	.word	0xa188
	.word	0x0000
	.word	0xc004
	.word	0x0000
	.word	0x83f2
	.word	0x677a
	.word	0x65ec
	.word	0xbf73
	.word	0x21c4
	.word	0x0000
	.word	0xc003
	.word	0x0000
	.word	0xfb53
	.word	0xd14a
	.word	0xa9c2
	.word	0xf2c2
	.word	0x2000
	.word	0x0000
	.word	0xc003
	.word	0x0000
	.word	0xeec2
	.word	0xd3a0
	.word	0x87ac
	.word	0x669f
	.word	0x2138
	.word	0x0000
	.word	0xc003
	.word	0x0000
	.word	0xe231
	.word	0xd5f6
	.word	0x6595
	.word	0xda7b
	.word	0xa130
	.word	0x0000
	.word	0xc003
	.word	0x0000
	.word	0xd5a0
	.word	0xd84c
	.word	0x437f
	.word	0x4e58
	.word	0x9fc0
	.word	0x0000
	.word	0xc003
	.word	0x0000
	.word	0xc90f
	.word	0xdaa2
	.word	0x2168
	.word	0xc235
	.word	0x2100
	.word	0x0000
	.word	0xc003
	.word	0x0000
	.word	0xbc7e
	.word	0xdcf7
	.word	0xff52
	.word	0x3611
	.word	0xa168
	.word	0x0000
	.word	0xc003
	.word	0x0000
	.word	0xafed
	.word	0xdf4d
	.word	0xdd3b
	.word	0xa9ee
	.word	0xa0a0
	.word	0x0000
	.word	0xc003
	.word	0x0000
	.word	0xa35c
	.word	0xe1a3
	.word	0xbb25
	.word	0x1dcb
	.word	0x2090
	.word	0x0000
	.word	0xc003
	.word	0x0000
	.word	0x96cb
	.word	0xe3f9
	.word	0x990e
	.word	0x91a8
	.word	0x2160
	.word	0x0000
	.word	0xc003
	.word	0x0000
	.word	0x8a3a
	.word	0xe64f
	.word	0x76f8
	.word	0x0584
	.word	0xa108
	.word	0x0000
	.word	0xc002
	.word	0x0000
	.word	0xfb53
	.word	0xd14a
	.word	0xa9c2
	.word	0xf2c2
	.word	0x1f80
	.word	0x0000
	.word	0xc002
	.word	0x0000
	.word	0xe231
	.word	0xd5f6
	.word	0x6595
	.word	0xda7b
	.word	0xa0b0
	.word	0x0000
	.word	0xc002
	.word	0x0000
	.word	0xc90f
	.word	0xdaa2
	.word	0x2168
	.word	0xc235
	.word	0x2080
	.word	0x0000
	.word	0xc002
	.word	0x0000
	.word	0xafed
	.word	0xdf4d
	.word	0xdd3b
	.word	0xa9ee
	.word	0xa020
	.word	0x0000
	.word	0xc002
	.word	0x0000
	.word	0x96cb
	.word	0xe3f9
	.word	0x990e
	.word	0x91a8
	.word	0x20e0
	.word	0x0000
	.word	0xc001
	.word	0x0000
	.word	0xfb53
	.word	0xd14a
	.word	0xa9c2
	.word	0xf2c2
	.word	0x1f00
	.word	0x0000
	.word	0xc001
	.word	0x0000
	.word	0xc90f
	.word	0xdaa2
	.word	0x2168
	.word	0xc235
	.word	0x2000
	.word	0x0000
	.word	0xc001
	.word	0x0000
	.word	0x96cb
	.word	0xe3f9
	.word	0x990e
	.word	0x91a8
	.word	0x2060
	.word	0x0000
	.word	0xc000
	.word	0x0000
	.word	0xc90f
	.word	0xdaa2
	.word	0x2168
	.word	0xc235
	.word	0x1f80
	.word	0x0000
	.word	0xbfff
	.word	0x0000
	.word	0xc90f
	.word	0xdaa2
	.word	0x2168
	.word	0xc235
	.word	0x1f00
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x0000
	.word	0x3fff
	.word	0x0000
	.word	0xc90f
	.word	0xdaa2
	.word	0x2168
	.word	0xc235
	.word	0x9f00
	.word	0x0000
	.word	0x4000
	.word	0x0000
	.word	0xc90f
	.word	0xdaa2
	.word	0x2168
	.word	0xc235
	.word	0x9f80
	.word	0x0000
	.word	0x4001
	.word	0x0000
	.word	0x96cb
	.word	0xe3f9
	.word	0x990e
	.word	0x91a8
	.word	0xa060
	.word	0x0000
	.word	0x4001
	.word	0x0000
	.word	0xc90f
	.word	0xdaa2
	.word	0x2168
	.word	0xc235
	.word	0xa000
	.word	0x0000
	.word	0x4001
	.word	0x0000
	.word	0xfb53
	.word	0xd14a
	.word	0xa9c2
	.word	0xf2c2
	.word	0x9f00
	.word	0x0000
	.word	0x4002
	.word	0x0000
	.word	0x96cb
	.word	0xe3f9
	.word	0x990e
	.word	0x91a8
	.word	0xa0e0
	.word	0x0000
	.word	0x4002
	.word	0x0000
	.word	0xafed
	.word	0xdf4d
	.word	0xdd3b
	.word	0xa9ee
	.word	0x2020
	.word	0x0000
	.word	0x4002
	.word	0x0000
	.word	0xc90f
	.word	0xdaa2
	.word	0x2168
	.word	0xc235
	.word	0xa080
	.word	0x0000
	.word	0x4002
	.word	0x0000
	.word	0xe231
	.word	0xd5f6
	.word	0x6595
	.word	0xda7b
	.word	0x20b0
	.word	0x0000
	.word	0x4002
	.word	0x0000
	.word	0xfb53
	.word	0xd14a
	.word	0xa9c2
	.word	0xf2c2
	.word	0x9f80
	.word	0x0000
	.word	0x4003
	.word	0x0000
	.word	0x8a3a
	.word	0xe64f
	.word	0x76f8
	.word	0x0584
	.word	0x2108
	.word	0x0000
	.word	0x4003
	.word	0x0000
	.word	0x96cb
	.word	0xe3f9
	.word	0x990e
	.word	0x91a8
	.word	0xa160
	.word	0x0000
	.word	0x4003
	.word	0x0000
	.word	0xa35c
	.word	0xe1a3
	.word	0xbb25
	.word	0x1dcb
	.word	0xa090
	.word	0x0000
	.word	0x4003
	.word	0x0000
	.word	0xafed
	.word	0xdf4d
	.word	0xdd3b
	.word	0xa9ee
	.word	0x20a0
	.word	0x0000
	.word	0x4003
	.word	0x0000
	.word	0xbc7e
	.word	0xdcf7
	.word	0xff52
	.word	0x3611
	.word	0x2168
	.word	0x0000
	.word	0x4003
	.word	0x0000
	.word	0xc90f
	.word	0xdaa2
	.word	0x2168
	.word	0xc235
	.word	0xa100
	.word	0x0000
	.word	0x4003
	.word	0x0000
	.word	0xd5a0
	.word	0xd84c
	.word	0x437f
	.word	0x4e58
	.word	0x1fc0
	.word	0x0000
	.word	0x4003
	.word	0x0000
	.word	0xe231
	.word	0xd5f6
	.word	0x6595
	.word	0xda7b
	.word	0x2130
	.word	0x0000
	.word	0x4003
	.word	0x0000
	.word	0xeec2
	.word	0xd3a0
	.word	0x87ac
	.word	0x669f
	.word	0xa138
	.word	0x0000
	.word	0x4003
	.word	0x0000
	.word	0xfb53
	.word	0xd14a
	.word	0xa9c2
	.word	0xf2c2
	.word	0xa000
	.word	0x0000
	.word	0x4004
	.word	0x0000
	.word	0x83f2
	.word	0x677a
	.word	0x65ec
	.word	0xbf73
	.word	0xa1c4
	.word	0x0000
	.word	0x4004
	.word	0x0000
	.word	0x8a3a
	.word	0xe64f
	.word	0x76f8
	.word	0x0584
	.word	0x2188
	.word	0x0000
	.word	0x4004
	.word	0x0000
	.word	0x9083
	.word	0x6524
	.word	0x8803
	.word	0x4b96
	.word	0xa0b0
	.word	0x0000
	.word	0x4004
	.word	0x0000
	.word	0x96cb
	.word	0xe3f9
	.word	0x990e
	.word	0x91a8
	.word	0xa1e0
	.word	0x0000
	.word	0x4004
	.word	0x0000
	.word	0x9d14
	.word	0x62ce
	.word	0xaa19
	.word	0xd7b9
	.word	0x2158
	.word	0x0000
	.word	0x4004
	.word	0x0000
	.word	0xa35c
	.word	0xe1a3
	.word	0xbb25
	.word	0x1dcb
	.word	0xa110
	.word	0x0000
	.word	0x4004
	.word	0x0000
	.word	0xa9a5
	.word	0x6078
	.word	0xcc30
	.word	0x63dd
	.word	0xa1fc
	.word	0x0000
	.word	0x4004
	.word	0x0000
	.word	0xafed
	.word	0xdf4d
	.word	0xdd3b
	.word	0xa9ee
	.word	0x2120
	.word	0x0000
	.word	0x4004
	.word	0x0000
	.word	0xb636
	.word	0x5e22
	.word	0xee46
	.word	0xf000
	.word	0xa148
	.word	0x0000
	.word	0x4004
	.word	0x0000
	.word	0xbc7e
	.word	0xdcf7
	.word	0xff52
	.word	0x3611
	.word	0x21e8
	.word	0x0000
	.word	0x4004
	.word	0x0000
	.word	0xc2c7
	.word	0x5bcd
	.word	0x105d
	.word	0x7c23
	.word	0x20d0
	.word	0x0000
	.word	0x4004
	.word	0x0000
	.word	0xc90f
	.word	0xdaa2
	.word	0x2168
	.word	0xc235
	.word	0xa180
	.word	0x0000
	.globl	stand
stand:
	.word	0x60ff
	.word	0xffff
	.word	0xa000

	.globl	stan
stan:
	fmovex		a0@,fp0	// load input

	movel		a0@,d0
	movew		a0@(4),d0
	andil		#0x7fffffff,d0
	cmpl	#0x3fd78000,d0
	bge	ADR_40a2cee:l
	bra	ADR_40a2e40:l
ADR_40a2cee:
	cmpl	#0x4004bc7e,d0
	blt	ADR_40a2d00:l
	bra	ADR_40a2e52:l

// tanmain:
//--THIS IS THE USUAL CASE, |X| <= 15 PI.
//--THE ARGUMENT REDUCTION IS DONE BY TABLE LOOK UP.
ADR_40a2d00:
	fmovex		fp0,fp1
	fmuld		ADR_40a281e,fp1	// x*2/pi
	.word	0x43f9
	.word	0x040a
	.word	0x2ab6
	fmovel	fp1,d0
	asll		#4,d0
	addal		d0,a1		// address n*piby2 in y1, y2

	fsubx		a1@+,fp0	// x-y1
	fsubs		a1@,fp0	// fp0 is r = (x-y1)-y2
	rorl		#5,d0
	andil		#0x80000000,d0	// d0 was odd iff d0 < 0
ADR_40a2d2a:
	cmpil		#0,d0
	blt		ADR_40a2db0

	fmovex		fp0,fp1
	fmulx		fp1,fp1	 	// s = r*r

	fmoved		ADR_40a2826,fp3
	fmoved		ADR_40a282e,fp2

	fmulx		fp1,fp3	 	// sq4
	fmulx		fp1,fp2	 	// sp3

	faddd		ADR_40a2836,fp3	// q3+sq4
	faddx		ADR_40a2846,fp2	// p2+sp3

	fmulx		fp1,fp3	 	// s(q3+sq4)
	fmulx		fp1,fp2	 	// s(p2+sp3)

	faddx		ADR_40a2856,fp3	// q2+s(q3+sq4)
	faddx		ADR_40a2866,fp2	// p1+s(p2+sp3)

	fmulx		fp1,fp3	 	// s(q2+s(q3+sq4))
	fmulx		fp1,fp2	 	// s(p1+s(p2+sp3))

	faddx		ADR_40a2876,fp3	// q1+s(q2+s(q3+sq4))
	fmulx		fp0,fp2	 	// rs(p1+s(p2+sp3))

	fmulx		fp3,fp1	 	// s(q1+s(q2+s(q3+sq4)))

	faddx		fp2,fp0	 	// r+rs(p1+s(p2+sp3))
	fadds	#0s1,fp1

	fmovel		d1,fpcr		//restore users exceptions
	fdivx		fp1,fp0		//last inst - possible exception set

	bra		t_frcinx

// nodd:
ADR_40a2db0:
	fmovex		fp0,fp1
	fmulx		fp0,fp0	 	// s = r*r

	fmoved		ADR_40a2826,fp3
	fmoved		ADR_40a282e,fp2

	fmulx		fp0,fp3	 	// sq4
	fmulx		fp0,fp2	 	// sp3

	faddd		ADR_40a2836,fp3	// q3+sq4
	faddx		ADR_40a2846,fp2	// p2+sp3

	fmulx		fp0,fp3	 	// s(q3+sq4)
	fmulx		fp0,fp2	 	// s(p2+sp3)

	faddx		ADR_40a2856,fp3	// q2+s(q3+sq4)
	faddx		ADR_40a2866,fp2	// p1+s(p2+sp3)

	fmulx		fp0,fp3	 	// s(q2+s(q3+sq4))
	fmulx		fp0,fp2	 	// s(p1+s(p2+sp3))

	faddx		ADR_40a2876,fp3	// q1+s(q2+s(q3+sq4))
	fmulx		fp1,fp2	 	// rs(p1+s(p2+sp3))

	fmulx		fp3,fp0	 	// s(q1+s(q2+s(q3+sq4)))

	faddx		fp2,fp1	 	// r+rs(p1+s(p2+sp3))
	fadds	#0s1,fp0

	fmovex		fp1,sp@-
	eoril		#0x80000000,sp@

	fmovel		d1,fpcr	 	//restore users exceptions
	fdivx		sp@+,fp0	//last inst - possible exception set

	bra		t_frcinx

// tanbors:
//--IF |X| > 15PI, WE USE THE GENERAL ARGUMENT REDUCTION.
//--IF |X| < 2**(-40), RETURN X OR 1.
	cmpil		#0x3fff8000,d0
	bgt		ADR_40a2e52

ADR_40a2e40:
	fmovex		fp0,sp@-
	fmovel		d1,fpcr		 //restore users exceptions
	fmovex		sp@+,fp0	//last inst - posibble exception set

	bra		t_frcinx
ADR_40a2e52:
	fmovemx	fp2/fp3/fp4/fp5,sp@-
	movel		d2,sp@-
	fmoves	#0s0,fp1
	cmpl	#0x7ffeffff,d0
	bne	ADR_40a2ec4:l
	movel	#0x7ffe0000:l,a6@(-100:w)
	movel	#0xc90fdaa2:l,a6@(-96:w)
	clrl	a6@(-92:w)
	ftstx	fp0
	movel	#0x7fdc0000:l,a6@(-64:w)
	movel	#0x85a308d3:l,a6@(-60:w)
	clrl	a6@(-56:w)
	fblt	ADR_40a2eaa:l
	orw	#0x8000,a6@(-100:w)
	orw	#0x8000,a6@(-64:w)
ADR_40a2eaa:
	faddx	a6@(-100:w),fp0
	fmovex	fp0,fp1
	faddx	a6@(-64:w),fp0
	fsubx	fp0,fp1
	faddx	a6@(-64:w),fp1
ADR_40a2ec4:
	fmovex	fp0,a6@(-48:w)
	movew	a6@(-48:w),d0
	movel	d0,a1
	andil		#0x00007fff,d0
	subil		#0x00003fff,d0	// d0 is k
	cmpil		#28,d0
	ble		ADR_40a2efc
	subl	#0x1b,d0
	movel	#0x0:l,a6@(-80:w)
	bra		ADR_40a2f06
// lastloop:
ADR_40a2efc:
	clrl		d0		// d0 is l := 0
	movel	#0x1:l,a6@(-80:w)
ADR_40a2f06:
	movel	#0x3ffe:l,d2
	subl		d0,d2		// biased expo 2**(-l)*invtwopi
	movel	#0xa2f9836e:l,a6@(-112:w)
	movel	#0x4e44152a:l,a6@(-108:w)
	movew	d2,a6@(-116:w)
	fmovex	fp0,fp2
	fmulx	a6@(-116:w),fp2
	movel	a1,d2
	swap	d2
	andil		#0x80000000,d2
	oril		#0x5f000000,d2	// d2 is sign(inarg)*2**63 in sgl
	movel	d2,a6@(-84:w)

	movel		d0,d2
	addl	#0x3fff,d2
	fadds	a6@(-84:w),fp2
	movew	d2,a6@(-100:w)
	clrw	a6@(-98:w)
	movel	#0xc90fdaa2:l,a6@(-96:w)
	clrl	a6@(-92:w)
	fsubs	a6@(-84:w),fp2
	addl	#0x3fdd,d0
	movew	d0,a6@(-64:w)
	clrw	a6@(-62:w)
	movel	#0x85a308d3:l,a6@(-60:w)
	clrl	a6@(-56:w)
	movel	a6@(-80:w),d0
	fmovex	fp2,fp4
	fmulx	a6@(-100:w),fp4
	fmovex	fp2,fp5
	fmulx	a6@(-64:w),fp5
	fmovex	fp4,fp3
	faddx	fp5,fp3
	fsubx	fp3,fp4
	fsubx	fp3,fp0
	faddx	fp5,fp4
	fmovex	fp0,fp3
	fsubx	fp4,fp1
	faddx	fp1,fp0
//--FP0 IS X REM 2**L * 2PI
	cmpil		#0,d0
	bgt	ADR_40a2fd4:l
	fsubx	fp0,fp3
	faddx	fp3,fp1
	bra	ADR_40a2ec4:l
ADR_40a2fd4:
	fmovel	fp2,a6@(-68:w)

	movel		sp@+,d2
	fmovemx	sp@+,fp2/fp3/fp4/fp5
	movel	a6@(-68:w),d0
	rorl	#1,d0
	bra	ADR_40a2d2a:l
//
//	stanh.sa 1.4 10/1/90
//
//	The entry point sTanh computes the hyperbolic tangent of
//	an input argument; sTanhd does the same except for denormalized
//	input.
//
//	Input: Double-extended number X in location pointed to
//		by address register a0.
//
//	Output: The value tanh(X) returned in floating-point register Fp0.
//
//	Accuracy and Monotonicity: The returned result is within 3 ulps in
//		64 significant bit, i.e. within 0.5001 ulp to 53 bits if the
//		result is subsequently rounded to double precision. The
//		result is provably monotonic in double precision.
//
//	Speed: The program stanh takes approximately 270 cycles.
//
//	Algorithm:
//
//	TANH
//	1. If |X| >= (5/2) log2 or |X| <= 2**(-40), go to 3.
//
//	2. (2**(-40) < |X| < (5/2) log2) Calculate tanh(X) by
//		sgn := sign(X), y := 2|X|, z := expm1(Y), and
//		tanh(X) = sgn*( z/(2+z) ).
//		Exit.
//
//	3. (|X| <= 2**(-40) or |X| >= (5/2) log2). If |X| < 1,
//		go to 7.
//
//	4. (|X| >= (5/2) log2) If |X| >= 50 log2, go to 6.
//
//	5. ((5/2) log2 <= |X| < 50 log2) Calculate tanh(X) by
//		sgn := sign(X), y := 2|X|, z := exp(Y),
//		tanh(X) = sgn - [ sgn*2/(1+z) ].
//		Exit.
//
//	6. (|X| >= 50 log2) Tanh(X) = +-1 (round to nearest). Thus, we
//		calculate Tanh(X) by
//		sgn := sign(X), Tiny := 2**(-126),
//		tanh(X) := sgn - sgn*Tiny.
//		Exit.
//
//	7. (|X| < 2**(-40)). Tanh(X) = X.	Exit.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.




ADR_40a2fec:
 	.int 0x3fd78000,0x3fffddce //  2^(-40), (5/2)log2
	.globl	stanhd
stanhd:
	.word	0x60ff
	.word	0xffff
	.word	0x9cd2

	.globl	stanh
stanh:
	fmovex		a0@,fp0	// load input
	fmovex	fp0,a6@(-32:w)
	movel		a0@,d0
	movew		a0@(4),d0
	movel	d0,a6@(-32:w)
	andl		#0x7fffffff,d0
	cmp2l		ADR_40a2fec,d0	// 2**(-40) < |x| < (5/2)log2 ?
	bcs		ADR_40a3082
	movel	a6@(-32:w),d0
	movel	d0,a6@(-68:w)
	andl		#0x7fff0000,d0
	addl		#0x00010000,d0	// exponent of 2|x|
	movel	d0,a6@(-32:w)
	andl	#0x80000000,a6@(-68:w)
	fmovex	a6@(-32:w),fp0

	movel		d1,a7@-
	clrl	d1
	fmovemx	fp0-fp0,a0@
	bsr		setoxm1	 	// fp0 is z = expm1(y)
	movel		a7@+,d1

	fmovex		fp0,fp1
	fadds	#0s2,fp1
	movel	a6@(-68:w),d0
	fmovex	fp1,a6@(-16:w)
	eorl	d0,a6@(-16:w)

	fmovel		d1,fpcr		//restore users exceptions
	fdivx	a6@(-16:w),fp0
	bra		t_frcinx

// tanhbors:
ADR_40a3082:
	cmpl		#0x3fff8000,d0
	blt		ADR_40a310a

	cmpl		#0x40048aa1,d0
	bgt		ADR_40a3120
	movel	a6@(-32:w),d0
	movel	d0,a6@(-68:w)
	andl		#0x7fff0000,d0
	addl		#0x00010000,d0	// expo of 2|x|
	movel	d0,a6@(-32:w)
	andl	#0x80000000,a6@(-68:w)
	movel	a6@(-68:w),d0
	fmovex	a6@(-32:w),fp0

	movel		d1,a7@-
	clrl	d1
	fmovemx	fp0-fp0,a0@
	bsr		setox		// fp0 is exp(y)
	movel		a7@+,d1
	movel	a6@(-68:w),d0
	fadds	#0s1,fp0

	eorl		#0xc0000000,d0	// -sign(x)*2
	fmoves		d0,fp1		// -sign(x)*2 in sgl fmt
	fdivx		fp0,fp1	 	// -sign(x)2 / [exp(y)+1 ]
	movel	a6@(-68:w),d0
	orl		#0x3f800000,d0	// sgn
	fmoves		d0,fp0		// sgn in sgl fmt

	fmovel		d1,fpcr		//restore users exceptions
	faddx		fp1,fp0

	bra		t_frcinx
ADR_40a310a:
	movew	#0x0:w,a6@(-30:w)

	fmovel		d1,fpcr		//restore users exceptions
	fmovex	a6@(-32:w),fp0

	bra		t_frcinx
ADR_40a3120:
	movel	a6@(-32:w),d0
	andl		#0x80000000,d0
	orl		#0x3f800000,d0
	fmoves		d0,fp0
	andl		#0x80000000,d0
	eorl		#0x80800000,d0	// -sign(x)*eps

	fmovel		d1,fpcr		//restore users exceptions
	fadds		d0,fp0

	bra		t_frcinx
//
//	sto_res.sa 1.6 10/4/90
//
//	Takes the result and puts it in where the user expects it.
//	Library functions return result in fp0.	If fp0 is not the
//	users destination register then fp0 is moved to the the
//	correct floating-point destination register.  fp0 and fp1
//	are then restored to the original contents. 
//
//	Input:	result in fp0,fp1 
//
//		d2 & a0 should be kept unmodified
//
//	Output:	moves the result to the true destination reg or mem
//
//	Modifies: destination floating point register
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.




	

// sto_cos:
	.globl	sto_cos
sto_cos:
	bfextu		a6@(cmdreg1b){#13:#3},d0	//extract cos destination
	cmpb	#0x3,d0
	ble	ADR_40a3170:l
	fmovemx	 fp1-fp1,a7@-
	moveql		#7,d1
	subl		d0,d1		//d1 = 7- (dest reg no)
	clrl		d0
	bset		d1,d0		//d0 is dynamic register mask
	fmovemx	a7@+,d0
	rts
ADR_40a3170:
	cmpb	#0x0,d0
	beq	ADR_40a31a6:l
	cmpb	#0x1,d0
	beq	ADR_40a319e:l
	cmpb	#0x2,d0
	beq	ADR_40a3196:l
	.word	0xf22e
	.word	0xf040
	.word	0xff74
	rts
ADR_40a3196:
	fmovemx	fp1-fp1,a6@(user_fp0)
	rts
ADR_40a319e:
	.word	0xf22e
	.word	0xf040
	.word	0xff5c
	rts
ADR_40a31a6:
	.word	0xf22e
	.word	0xf040
	.word	0xff50
	rts


// sto_res:
	.globl	sto_res
sto_res:
	bfextu		a6@(cmdreg1b){#6:#3},d0	//extract destination register
	cmpb	#0x3,d0
	ble	ADR_40a31d0:l
	fmovemx	fp0-fp0,a7@-
	moveql		#7,d1
	subl		d0,d1		//d1 = 7- (dest reg no)
	clrl		d0
	bset		d1,d0		//d0 is dynamic register mask
	fmovemx	a7@+,d0
	rts
ADR_40a31d0:
	cmpb	#0x0,d0
	beq	ADR_40a3206:l
	cmpb	#0x1,d0
	beq	ADR_40a31fe:l
	cmpb	#0x2,d0
	beq	ADR_40a31f6:l
	.word	0xf22e
	.word	0xf080
	.word	0xff74
	rts
ADR_40a31f6:
	fmovemx	fp0-fp0,a6@(user_fp0)
	rts
ADR_40a31fe:
	.word	0xf22e
	.word	0xf080
	.word	0xff5c
	rts
ADR_40a3206:
	.word	0xf22e
	.word	0xf080
	.word	0xff50
	rts
//
//	stwotox.sa 1.6 10/1/90
//
//	stwotox  --- 2**X
//	stwotoxd --- 2**X for denormalized X
//	stentox  --- 10**X
//	stentoxd --- 10**X for denormalized X
//
//	Input: Double-extended number X in location pointed to
//		by address register a0.
//
//	Output: The function values are returned in Fp0.
//
//	Accuracy and Monotonicity: The returned result is within 2 ulps in
//		64 significant bit, i.e. within 0.5001 ulp to 53 bits if the
//		result is subsequently rounded to double precision. The
//		result is provably monotonic in double precision.
//
//	Speed: The program stwotox takes approximately 190 cycles and the
//		program stentox takes approximately 200 cycles.
//
//	Algorithm:
//
//	twotox
//	1. If |X| > 16480, go to ExpBig.
//
//	2. If |X| < 2**(-70), go to ExpSm.
//
//	3. Decompose X as X = N/64 + r where |r| <= 1/128. Furthermore
//		decompose N as
//		 N = 64(M + M') + j,  j = 0,1,2,...,63.
//
//	4. Overwrite r := r * log2. Then
//		2**X = 2**(M') * 2**(M) * 2**(j/64) * exp(r).
//		Go to expr to compute that expression.
//
//	tentox
//	1. If |X| > 16480*log_10(2) (base 10 log of 2), go to ExpBig.
//
//	2. If |X| < 2**(-70), go to ExpSm.
//
//	3. Set y := X*log_2(10)*64 (base 2 log of 10). Set
//		N := round-to-int(y). Decompose N as
//		 N = 64(M + M') + j,  j = 0,1,2,...,63.
//
//	4. Define r as
//		r := ((X - N*L1)-N*L2) * L10
//		where L1, L2 are the leading and trailing parts of log_10(2)/64
//		and L10 is the natural log of 10. Then
//		10**X = 2**(M') * 2**(M) * 2**(j/64) * exp(r).
//		Go to expr to compute that expression.
//
//	expr
//	1. Fetch 2**(j/64) from table as Fact1 and Fact2.
//
//	2. Overwrite Fact1 and Fact2 by
//		Fact1 := 2**(M) * Fact1
//		Fact2 := 2**(M) * Fact2
//		Thus Fact1 + Fact2 = 2**(M) * 2**(j/64).
//
//	3. Calculate P where 1 + P approximates exp(r):
//		P = r + r*r*(A1+r*(A2+...+r*A5)).
//
//	4. Let AdjFact := 2**(M'). Return
//		AdjFact * ( Fact1 + ((Fact1*P) + Fact2) ).
//		Exit.
//
//	ExpBig
//	1. Generate overflow by Huge * Huge if X > 0; otherwise, generate
//		underflow by Tiny * Tiny.
//
//	ExpSm
//	1. Return 1 + X.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



 	.int 0x3fb98000,0x400d80c0 //  2^(-70),16480
 	.int 0x3fb98000,0x400b9b07 //  2^(-70),16480 log2/log10

ADR_40a321e:
 	.int 0x406a934f,0x0979a371 //  64log10/log2
ADR_40a3226:
 	.int 0x3f734413,0x509f8000 //  log2/64log10

ADR_40a322e:
 	.int 0xbfcd0000,0xc0219dc1,0xda994fd2,0x00000000

ADR_40a323e:
 	.int 0x40000000,0x935d8ddd,0xaaa8ac17,0x00000000

ADR_40a324e:
 	.int 0x3ffe0000,0xb17217f7,0xd1cf79ac,0x00000000

ADR_40a325e:
 	.int 0x3f56c16d,0x6f7bd0b2
ADR_40a3266:
 	.int 0x3f811112,0x302c712c
ADR_40a326e:
 	.int 0x3fa55555,0x55554cc1
ADR_40a3276:
 	.int 0x3fc55555,0x55554a54
ADR_40a327e:
 	.int 0x3fe00000,0x00000000,0x00000000,0x00000000
	.word	0x7ffe
	.word	0x0000
	.word	0xffff
	.word	0xffff
	.word	0xffff
	.word	0xffff
	.word	0x0000
	.word	0x0000
 	.int 0x00010000,0xffffffff,0xffffffff,0x00000000

// exptbl: 
ADR_40a32ae:
	.int  0x3fff0000,0x80000000,0x00000000,0x3f738000
	.int  0x3fff0000,0x8164d1f3,0xbc030773,0x3fbef7ca
	.int  0x3fff0000,0x82cd8698,0xac2ba1d7,0x3fbdf8a9
	.int  0x3fff0000,0x843a28c3,0xacde4046,0x3fbcd7c9
	.int  0x3fff0000,0x85aac367,0xcc487b15,0xbfbde8da
	.int  0x3fff0000,0x871f6196,0x9e8d1010,0x3fbde85c
	.int  0x3fff0000,0x88980e80,0x92da8527,0x3fbebbf1
	.int  0x3fff0000,0x8a14d575,0x496efd9a,0x3fbb80ca
	.int  0x3fff0000,0x8b95c1e3,0xea8bd6e7,0xbfba8373
	.int  0x3fff0000,0x8d1adf5b,0x7e5ba9e6,0xbfbe9670
	.int  0x3fff0000,0x8ea4398b,0x45cd53c0,0x3fbdb700
	.int  0x3fff0000,0x9031dc43,0x1466b1dc,0x3fbeeeb0
	.int  0x3fff0000,0x91c3d373,0xab11c336,0x3fbbfd6d
	.int  0x3fff0000,0x935a2b2f,0x13e6e92c,0xbfbdb319
	.int  0x3fff0000,0x94f4efa8,0xfef70961,0x3fbdba2b
	.int  0x3fff0000,0x96942d37,0x20185a00,0x3fbe91d5
	.int  0x3fff0000,0x9837f051,0x8db8a96f,0x3fbe8d5a
	.int  0x3fff0000,0x99e04593,0x20b7fa65,0xbfbcde7b
	.int  0x3fff0000,0x9b8d39b9,0xd54e5539,0xbfbebaaf
	.int  0x3fff0000,0x9d3ed9a7,0x2cffb751,0xbfbd86da
	.int  0x3fff0000,0x9ef53260,0x91a111ae,0xbfbebedd
	.int  0x3fff0000,0xa0b0510f,0xb9714fc2,0x3fbcc96e
	.int  0x3fff0000,0xa2704303,0x0c496819,0xbfbec90b
	.int  0x3fff0000,0xa43515ae,0x09e6809e,0x3fbbd1db
	.int  0x3fff0000,0xa5fed6a9,0xb15138ea,0x3fbce5eb
	.int  0x3fff0000,0xa7cd93b4,0xe965356a,0xbfbec274
	.int  0x3fff0000,0xa9a15ab4,0xea7c0ef8,0x3fbea83c
	.int  0x3fff0000,0xab7a39b5,0xa93ed337,0x3fbecb00
	.int  0x3fff0000,0xad583eea,0x42a14ac6,0x3fbe9301
	.int  0x3fff0000,0xaf3b78ad,0x690a4375,0xbfbd8367
	.word	0x3fff
	.word	0x0000
	.word	0xb123
	.word	0xf581
	addl	a4@(9616:w),d1
	.word	0xbfbe
	.word	0xf05f
	.int  0x3fff0000,0xb311c412,0xa9112489,0x3fbdfb3c
	.int  0x3fff0000,0xb504f333,0xf9de6484,0x3fbeb2fb
	.int  0x3fff0000,0xb6fd91e3,0x28d17791,0x3fbae2cb
	.int  0x3fff0000,0xb8fbaf47,0x62fb9ee9,0x3fbcdc3c
	.int  0x3fff0000,0xbaff5ab2,0x133e45fb,0x3fbee9aa
	.int  0x3fff0000,0xbd08a39f,0x580c36bf,0xbfbeaefd
	.int  0x3fff0000,0xbf1799b6,0x7a731083,0xbfbcbf51
	.int  0x3fff0000,0xc12c4cca,0x66709456,0x3fbef88a
	.int  0x3fff0000,0xc346ccda,0x24976407,0x3fbd83b2
	.int  0x3fff0000,0xc5672a11,0x5506dadd,0x3fbdf8ab
	.int  0x3fff0000,0xc78d74c8,0xabb9b15d,0xbfbdfb17
	.int  0x3fff0000,0xc9b9bd86,0x6e2f27a3,0xbfbefe3c
	.int  0x3fff0000,0xcbec14fe,0xf2727c5d,0xbfbbb6f8
	.int  0x3fff0000,0xce248c15,0x1f8480e4,0xbfbcee53
	.int  0x3fff0000,0xd06333da,0xef2b2595,0xbfbda4ae
	.int  0x3fff0000,0xd2a81d91,0xf12ae45a,0x3fbc9124
	.int  0x3fff0000,0xd4f35aab,0xcfedfa1f,0x3fbeb243
	.int  0x3fff0000,0xd744fcca,0xd69d6af4,0x3fbde69a
	.int  0x3fff0000,0xd99d15c2,0x78afd7b6,0xbfb8bc61
	.int  0x3fff0000,0xdbfbb797,0xdaf23755,0x3fbdf610
	.int  0x3fff0000,0xde60f482,0x5e0e9124,0xbfbd8be1
	.int  0x3fff0000,0xe0ccdeec,0x2a94e111,0x3fbacb12
	.int  0x3fff0000,0xe33f8972,0xbe8a5a51,0x3fbb9bfe
	.int  0x3fff0000,0xe5b906e7,0x7c8348a8,0x3fbcf2f4
	.int  0x3fff0000,0xe8396a50,0x3c4bdc68,0x3fbef22f
	.int  0x3fff0000,0xeac0c6e7,0xdd24392f,0xbfbdbf4a
	.int  0x3fff0000,0xed4f301e,0xd9942b84,0x3fbec01a
	.int  0x3fff0000,0xefe4b99b,0xdcdaf5cb,0x3fbe8cac
	.int  0x3fff0000,0xf281773c,0x59ffb13a,0xbfbcbb3f
	.word	0x3fff
	.word	0x0000
	.word	0xf525
	.word	0x7d15
	movel	d6,a2@
	andb	a4@(16318:w),d6
	.word	0xf73a
	.int  0x3fff0000,0xf7d0df73,0x0ad13bb9,0xbfb8b795
	.int  0x3fff0000,0xfa83b2db,0x722a033a,0x3fbef84b
	.int  0x3fff0000,0xfd3e0c0c,0xf486c175,0xbfbef581
	.globl	stwotoxd
stwotoxd:
	.word	0xf201
	.word	0x9000
	.word	0xf23c
	.word	0x4400
	.word	0x3f80
	.word	0x0000
	movel		a0@,d0
	orl		#0x00800001,d0
	fadds		d0,fp0
	bra		t_frcinx
	.globl	stwotox
stwotox:
	.word	0xf210
	.word	0xd080
	movel	a0@,d0
	movew	a0@(4:w),d0
	fmovex	fp0,a6@(-116:w)
	andil		#0x7fffffff,d0
	cmpl	#0x3fb98000,d0
	bge	ADR_40a36f4:l
	bra	ADR_40a378c:l
ADR_40a36f4:
	cmpl	#0x400d80c0,d0
	ble	ADR_40a3706:l
	bra	ADR_40a378c:l

//--USUAL CASE, 2^(-70) <= |X| <= 16480

ADR_40a3706:
	fmovex		fp0,fp1
	fmuls	#0s64,fp1
	fmovel	fp1,a6@(-84:w)
	movel		d2,sp@-
	lea		ADR_40a32ae,a1 	// load address of table of 2^(j/64)
	fmovel	a6@(-84:w),fp1
	movel	a6@(-84:w),d0
	movel		d0,d2
	andil		#0x3f,d0		// d0 is j
	asll		#4,d0		// displacement for 2^(j/64)
	addal		d0,a1		// address for 2^(j/64)
	asrl		#6,d2		// d2 is l, n = 64l + j
	movel		d2,d0
	asrl		#1,d0		// d0 is m
	subl		d0,d2		// d2 is m', n = 64(m+m') + j
	addil		#0x3fff,d2
	movew	d2,a6@(-100:w)
	movel		sp@+,d2
	fmuls	#0s0.015625,fp1
	movel	a1@+,a6@(-64:w)
	movel	a1@+,a6@(-60:w)
	movel	a1@+,a6@(-56:w)
	movew	a1@+,a6@(-48:w)
	clrw	a6@(-46:w)
	fsubx		fp1,fp0	 	// x - (1/64)*int(64 x)
	movew	a1@+,a6@(-44:w)
	clrw	a6@(-42:w)
	clrl	a6@(-40:w)
	addw	d0,a6@(-64:w)
	fmulx		ADR_40a324e,fp0	// fp0 is r
	addw	d0,a6@(-48:w)
	bra		ADR_40a38b6

// expbors:
//--FPCR, D0 SAVED
ADR_40a378c:
	cmpil		#0x3fff8000,d0
	bgt		ADR_40a37aa

// expsm:
//--|X| IS SMALL, RETURN 1 + X

	fmovel		d1,fpcr		//restore users exceptions
	fadds	#0s1,fp0

	bra		t_frcinx
ADR_40a37aa:
	movel	a6@(-116:w),d0
	cmpil		#0,d0
	blt		ADR_40a37c4

	bclr		#7,a0@		//t_ovfl expects positive value
	.word	0x60ff
	.word	0xffff
	.word	0x938a

// expneg:
ADR_40a37c4:
	bclr		#7,a0@		//t_unfl expects positive value
	bra		t_unfl
	.globl	stentoxd
stentoxd:
	fmoveml	d1,fpc
	fmoves	#0s1,fp0
	movel		a0@,d0
	orl		#0x00800001,d0
	fadds		d0,fp0
	bra		t_frcinx
	.globl	stentox
stentox:
	.word	0xf210
	.word	0xd080
	movel	a0@,d0
	movew	a0@(4:w),d0
	fmovex	fp0,a6@(-116:w)
	andil		#0x7fffffff,d0
	cmpl	#0x3fb98000,d0
	bge	ADR_40a3814:l
	bra	ADR_40a378c:l
ADR_40a3814:
	cmpl	#0x400b9b07,d0
	ble	ADR_40a3826:l
	bra	ADR_40a378c:l

//--USUAL CASE, 2^(-70) <= |X| <= 16480 LOG 2 / LOG 10

ADR_40a3826:
	fmovex		fp0,fp1
	fmuld		ADR_40a321e,fp1	// x*64*log10/log2
	fmovel	fp1,a6@(-84:w)
	movel		d2,sp@-
	lea		ADR_40a32ae,a1 	// load address of table of 2^(j/64)
	fmovel	a6@(-84:w),fp1
	movel	a6@(-84:w),d0
	movel		d0,d2
	andil		#0x3f,d0		// d0 is j
	asll		#4,d0		// displacement for 2^(j/64)
	addal		d0,a1		// address for 2^(j/64)
	asrl		#6,d2		// d2 is l, n = 64l + j
	movel		d2,d0
	asrl		#1,d0		// d0 is m
	subl		d0,d2		// d2 is m', n = 64(m+m') + j
	addil		#0x3fff,d2
	movew	d2,a6@(-100:w)
	movel		sp@+,d2

//--SUMMARY: a1 IS ADDRESS FOR THE LEADING PORTION OF 2^(J/64),
//--D0 IS M WHERE N = 64(M+M') + J. NOTE THAT |M| <= 16140 BY DESIGN.
//--ADJFACT = 2^(M').
//--REGISTERS SAVED SO FAR ARE (IN ORDER) FPCR, D0, FP1, a1, AND FP2.

	fmovex		fp1,fp2
	fmuld		ADR_40a3226,fp1	// n*(log2/64log10)_lead
	movel	a1@+,a6@(-64:w)
	fmulx		ADR_40a322e,fp2	// n*(log2/64log10)_trail
	movel	a1@+,a6@(-60:w)
	movel	a1@+,a6@(-56:w)
	fsubx		fp1,fp0		// x - n l_lead
	movew	a1@+,a6@(-48:w)
	fsubx		fp2,fp0		// x - n l_trail
	clrw	a6@(-46:w)
	movew	a1@+,a6@(-44:w)
	clrw	a6@(-42:w)
	clrl	a6@(-40:w)
	fmulx		ADR_40a323e,fp0	// fp0 is r
	addw	d0,a6@(-64:w)
	addw	d0,a6@(-48:w)

// expr:
//--FPCR, FP2, FP3 ARE SAVED IN ORDER AS SHOWN.
//--ADJFACT CONTAINS 2**(M'), FACT1 + FACT2 = 2**(M) * 2**(J/64).
//--FP0 IS R. THE FOLLOWING CODE COMPUTES
//--	2**(M'+M) * 2**(J/64) * EXP(R)

ADR_40a38b6:
	fmovex		fp0,fp1
	fmulx		fp1,fp1		// fp1 is s = r*r

	fmoved		ADR_40a325e,fp2	// fp2 is a5
	fmoved		ADR_40a3266,fp3	// fp3 is a4

	fmulx		fp1,fp2		// fp2 is s*a5
	fmulx		fp1,fp3		// fp3 is s*a4

	faddd		ADR_40a326e,fp2	// fp2 is a3+s*a5
	faddd		ADR_40a3276,fp3	// fp3 is a2+s*a4

	fmulx		fp1,fp2		// fp2 is s*(a3+s*a5)
	fmulx		fp1,fp3		// fp3 is s*(a2+s*a4)

	faddd		ADR_40a327e,fp2	// fp2 is a1+s*(a3+s*a5)
	fmulx		fp0,fp3		// fp3 is r*s*(a2+s*a4)

	fmulx		fp1,fp2		// fp2 is s*(a1+s*(a3+s*a5))
	faddx		fp3,fp0		// fp0 is r+r*s*(a2+s*a4)
	faddx		fp2,fp0		// fp0 is exp(r) - 1
	fmulx	a6@(-64:w),fp0
	faddx	a6@(-48:w),fp0
	faddx	a6@(-64:w),fp0

	fmovel		d1,fpcr		//restore users exceptions
	clrw	a6@(-98:w)
	movel	#0x80000000:l,a6@(-96:w)
	clrl	a6@(-92:w)
	fmulx	a6@(-100:w),fp0

	bra		t_frcinx
	.globl	tblpre
tblpre:
	.long	smovcr
	.long	smovcr
	.long	smovcr
	.long	smovcr
	.long	smovcr
	.long	smovcr
	.long	smovcr
	.long	smovcr
	.long	sint
	.long	szero
	.long	sinf
	.long	src_nan
	.long	sintd
	.long	serror
	.long	serror
	.long	serror
	.long	ssinh
	.long	szero
	.long	sinf
	.long	src_nan
	.long	ssinhd
	.long	serror
	.long	serror
	.long	serror
	.long	sintrz
	.long	szero
	.long	sinf
	.long	src_nan
	.long	snzrinx
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	sslognp1
	.long	szero
	.long	sopr_inf
	.long	src_nan
	.long	slognp1d
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	setoxm1
	.long	szero
	.long	setoxm1i
	.long	src_nan
	.long	setoxm1d
	.long	serror
	.long	serror
	.long	serror
	.long	stanh
	.long	szero
	.long	sone
	.long	src_nan
	.long	stanhd
	.long	serror
	.long	serror
	.long	serror
	.long	satan
	.long	szero
	.long	spi_2
	.long	src_nan
	.long	satand
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	sasin
	.long	szero
	.long	t_operr
	.long	src_nan
	.long	sasind
	.long	serror
	.long	serror
	.long	serror
	.long	satanh
	.long	szero
	.long	t_operr
	.long	src_nan
	.long	satanhd
	.long	serror
	.long	serror
	.long	serror
	.long	ssin
	.long	szero
	.long	t_operr
	.long	src_nan
	.long	ssind
	.long	serror
	.long	serror
	.long	serror
	.long	stan
	.long	szero
	.long	t_operr
	.long	src_nan
	.long	stand
	.long	serror
	.long	serror
	.long	serror
	.long	setox
	.long	ld_pone
	.long	szr_inf
	.long	src_nan
	.long	setoxd
	.long	serror
	.long	serror
	.long	serror
	.long	stwotox
	.long	ld_pone
	.long	szr_inf
	.long	src_nan
	.long	stwotoxd
	.long	serror
	.long	serror
	.long	serror
	.long	stentox
	.long	ld_pone
	.long	szr_inf
	.long	src_nan
	.long	stentoxd
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	sslogn
	.long	t_dz2
	.long	sopr_inf
	.long	src_nan
	.long	sslognd
	.long	serror
	.long	serror
	.long	serror
	.long	sslog10
	.long	t_dz2
	.long	sopr_inf
	.long	src_nan
	.long	sslog10d
	.long	serror
	.long	serror
	.long	serror
	.long	sslog2
	.long	t_dz2
	.long	sopr_inf
	.long	src_nan
	.long	sslog2d
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	scosh
	.long	ld_pone
	.long	ld_pinf
	.long	src_nan
	.long	scoshd
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	sacos
	.long	ld_ppi2
	.long	t_operr
	.long	src_nan
	.long	sacosd
	.long	serror
	.long	serror
	.long	serror
	.long	scos
	.long	ld_pone
	.long	t_operr
	.long	src_nan
	.long	scosd
	.long	serror
	.long	serror
	.long	serror
	.long	sgetexp
	.long	szero
	.long	t_operr
	.long	src_nan
	.long	sgetexpd
	.long	serror
	.long	serror
	.long	serror
	.long	sgetman
	.long	szero
	.long	t_operr
	.long	src_nan
	.long	sgetmand
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	pmod
	.long	pmod
	.long	pmod
	.long	pmod
	.long	pmod
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	prem
	.long	prem
	.long	prem
	.long	prem
	.long	prem
	.long	serror
	.long	serror
	.long	serror
	.long	pscale
	.long	pscale
	.long	pscale
	.long	pscale
	.long	pscale
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	serror
	.long	ssincos
	.long	ssincosz
	.long	ssincosi
	.long	ssincosnan
	.long	ssincosd
	.long	serror
	.long	serror
	.long	serror
	.long	ssincos
	.long	ssincosz
	.long	ssincosi
	.long	ssincosnan
	.long	ssincosd
	.long	serror
	.long	serror
	.long	serror
	.long	ssincos
	.long	ssincosz
	.long	ssincosi
	.long	ssincosnan
	.long	ssincosd
	.long	serror
	.long	serror
	.long	serror
	.long	ssincos
	.long	ssincosz
	.long	ssincosi
	.long	ssincosnan
	.long	ssincosd
	.long	serror
	.long	serror
	.long	serror
	.long	ssincos
	.long	ssincosz
	.long	ssincosi
	.long	ssincosnan
	.long	ssincosd
	.long	serror
	.long	serror
	.long	serror
	.long	ssincos
	.long	ssincosz
	.long	ssincosi
	.long	ssincosnan
	.long	ssincosd
	.long	serror
	.long	serror
	.long	serror
	.long	ssincos
	.long	ssincosz
	.long	ssincosi
	.long	ssincosnan
	.long	ssincosd
	.long	serror
	.long	serror
	.long	serror
	.long	ssincos
	.long	ssincosz
	.long	ssincosi
	.long	ssincosnan
	.long	ssincosd
	.long	serror
	.long	serror
	.long	serror
//
//	util.sa 1.12 10/10/90
//
//	This file contains routines used by other programs.
//
//	ovf_res: used by overflow to force the correct
//		 result. ovf_r_k, ovf_r_x2, ovf_r_x3 are 
//		 derivatives of this routine.
//	denorm:	 used by underflow to denormalize the
//		 intermediate result.
//	round:	 used by underflow to round an extended
//		 precision value to a specified rounding
//		 precision and size.
//	get_fline: get user's opcode word
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



	

	

//
// Final result table for ovf_res. Note that the negative counterparts
// are unnecessary as ovf_res always returns the sign separately from
// the exponent.
//					;+inf
 	.int	0x7fff0000,0x00000000,0x00000000,0x00000000	
//					;largest +ext
 	.int	0x7ffe0000,0xffffffff,0xffffffff,0x00000000	
//					;largest magnitude +sgl in ext
 	.int	0x407e0000,0xffffff00,0x00000000,0x00000000	
//					;largest magnitude +dbl in ext
 	.int	0x43fe0000,0xffffffff,0xfffff800,0x00000000	
	.long	ADR_40a41a4
	.long	ADR_40a41b6
	.long	ADR_40a41c2
	.long	ADR_40a41ec
	.long	ADR_40a4290
	.long	ADR_40a42a2
	.long	ADR_40a42ae
	.long	ADR_40a42d8
	.long	ADR_40a421a
	.long	ADR_40a422c
	.long	ADR_40a4238
	.long	ADR_40a4262
	.long	ADR_40a432a
	.long	ADR_40a432a
	.long	ADR_40a432a
	.long	ADR_40a432a

//
//	ovf_r_k --- overflow result calculation
//
// This entry point is used by kernel_ex.  
// This forces the destination precision to be extended
//
// Input:	none
// Output:	a result is in ETEMP (internal extended format)
//
// ovf_r_k:
	.globl	ovf_r_k
ovf_r_k:
	lea	a6@(etemp),a0	//a0 points to source operand	
	bclr	#sign_bit,a6@(etemp_ex)
	sne	a6@(etemp_sgn)	//convert to internal ieee format
	.globl	ovf_r_x2
ovf_r_x2:
	btst	#1,a6@(-220:w)
	beq	ADR_40a411a:l
	movew	a6@(-240:w),d0
	andw	#0x60,d0
	cmpl	#0x40,d0
	beq	ADR_40a416c:l
	cmpl	#0x60,d0
	beq	ADR_40a4174:l
	movew	a6@(-240:w),d0
	andl	#0x7f,d0
	cmpl	#0x33,d0
	beq	ADR_40a4164:l
	cmpl	#0x30,d0
	beq	ADR_40a4164:l
	bra	ADR_40a417c:l
ADR_40a411a:
	movew	a6@(-228:w),d0
	andl	#0x44,d0
	cmpl	#0x40,d0
	beq	ADR_40a416c:l
	cmpl	#0x44,d0
	beq	ADR_40a4174:l
	movew	a6@(-228:w),d0
	andl	#0x7f,d0
	cmpl	#0x27,d0
	beq	ADR_40a4164:l
	cmpl	#0x24,d0
	beq	ADR_40a4164:l
	bra	ADR_40a417c:l
ADR_40a4164:
	clrl	d0
	bra	ovf_res:l
ADR_40a416c:
	moveq	#1,d0
	bra	ovf_res:l
ADR_40a4174:
	moveq	#2,d0
	bra	ovf_res:l
ADR_40a417c:
	bfextu	a6@(-125:w){#0,#2},d0
	bra	ovf_res:l
	.globl	ovf_r_x3
ovf_r_x3:
	bsr	g_dfmtou:l
	.globl	ovf_res
ovf_res:
	lsll	#2,d0
	bfextu	a6@(-125:w){#2,#2},d1
	orl	d1,d0
	.word	0x43f9
	.word	0x040a
	.word	0x4078
	movel	a1@(0:b,d0:l:4),a1
	jmp	a1@
ADR_40a41a4:
	.word	0x43f9
	.word	0x040a
	.word	0x4038
	bset	#1,a6@(-124:w)
	bra	ADR_40a4306:l
ADR_40a41b6:
	.word	0x43f9
	.word	0x040a
	.word	0x4048
	bra	ADR_40a4306:l
ADR_40a41c2:
	tstb	a0@(2:w)
	beq	ADR_40a41e0:l
	.word	0x43f9
	.word	0x040a
	.word	0x4038
	orl	#0xa000000,a6@(-124:w)
	bra	ADR_40a4316:l
ADR_40a41e0:
	.word	0x43f9
	.word	0x040a
	.word	0x4048
	bra	ADR_40a4316:l
ADR_40a41ec:
	tstb	a0@(2:w)
	beq	ADR_40a4208:l
	.word	0x43f9
	.word	0x040a
	.word	0x4048
	bset	#3,a6@(-124:w)
	bra	ADR_40a4316:l
ADR_40a4208:
	.word	0x43f9
	.word	0x040a
	.word	0x4038
	bset	#1,a6@(-124:w)
	bra	ADR_40a4316:l
ADR_40a421a:
	.word	0x43f9
	.word	0x040a
	.word	0x4038
	bset	#1,a6@(-124:w)
	bra	ADR_40a4306:l
ADR_40a422c:
	.word	0x43f9
	.word	0x040a
	.word	0x4068
	bra	ADR_40a4306:l
ADR_40a4238:
	tstb	a0@(2:w)
	beq	ADR_40a4256:l
	.word	0x43f9
	.word	0x040a
	.word	0x4038
	orl	#0xa000000,a6@(-124:w)
	bra	ADR_40a4316:l
ADR_40a4256:
	.word	0x43f9
	.word	0x040a
	.word	0x4068
	bra	ADR_40a4316:l
ADR_40a4262:
	tstb	a0@(2:w)
	beq	ADR_40a427e:l
	.word	0x43f9
	.word	0x040a
	.word	0x4068
	bset	#3,a6@(-124:w)
	bra	ADR_40a4316:l
ADR_40a427e:
	.word	0x43f9
	.word	0x040a
	.word	0x4038
	bset	#1,a6@(-124:w)
	bra	ADR_40a4316:l
ADR_40a4290:
	.word	0x43f9
	.word	0x040a
	.word	0x4038
	bset	#1,a6@(-124:w)
	bra	ADR_40a4306:l
ADR_40a42a2:
	.word	0x43f9
	.word	0x040a
	.word	0x4058
	bra	ADR_40a4306:l
ADR_40a42ae:
	tstb	a0@(2:w)
	beq	ADR_40a42cc:l
	.word	0x43f9
	.word	0x040a
	.word	0x4038
	orl	#0xa000000,a6@(-124:w)
	bra	ADR_40a4316:l
ADR_40a42cc:
	.word	0x43f9
	.word	0x040a
	.word	0x4058
	bra	ADR_40a4316:l
ADR_40a42d8:
	tstb	a0@(2:w)
	beq	ADR_40a42f4:l
	.word	0x43f9
	.word	0x040a
	.word	0x4058
	bset	#3,a6@(-124:w)
	bra	ADR_40a4316:l
ADR_40a42f4:
	.word	0x43f9
	.word	0x040a
	.word	0x4038
	bset	#1,a6@(-124:w)
	bra	ADR_40a4316:l
ADR_40a4306:
	tstb	a0@(2:w)
	beq	ADR_40a4316:l
	bset	#3,a6@(-124:w)
ADR_40a4316:
	movew	a1@(0:w),a0@(0:w)
	movel	a1@(4:w),a0@(4:w)
	movel	a1@(8:w),a0@(8:w)
	rts
ADR_40a432a:
	rts
	.globl	get_fline
get_fline:
	movel	a6@(-120:w),a0
	movel	#0x0:l,sp@-
	lea	sp@(2:w),a1
	moveq	#2,d0
	.word	0x61ff
	.word	0xffff
	.word	0xc9c8
	movel	sp@+,d0
	rts
	.globl	g_rndpr
g_rndpr:
	bsr	g_opcls:l
	cmpw	#0x3,d0
	bne	ADR_40a435e		//else branch
	bsr	g_dfmtou:l
	rts
ADR_40a435e:
	btst	#1,a6@(-220:w)
	beq	ADR_40a43b2:l
	movel	a6@(-240:w),d0
	bfextu	d0{#9,#2},d0
	cmpl	#0x2,d0
	beq	ADR_40a43fc:l
	cmpl	#0x3,d0
	beq	ADR_40a4400:l
	movew	a6@(-240:w),d0
	andl	#0x7f,d0
	cmpl	#0x33,d0
	beq	ADR_40a4404:l
	cmpl	#0x30,d0
	beq	ADR_40a4404:l
	bra	ADR_40a4408:l
ADR_40a43b2:
	movel	a6@(-228:w),d0
	andl	#0x440000,d0
	cmpl	#0x400000,d0
	beq	ADR_40a43fc:l
	cmpl	#0x440000,d0
	beq	ADR_40a4400:l
	movel	a6@(-228:w),d0
	andl	#0x7f0000,d0
	cmpl	#0x270000,d0
	beq	ADR_40a4404:l
	cmpl	#0x240000,d0
	beq	ADR_40a4404:l
	bra	ADR_40a4408:l
ADR_40a43fc:
	moveq	#1,d0
	rts
ADR_40a4400:
	movl	#2,d0		// dbl
	rts
ADR_40a4404:
	moveq	#0,d0
	rts
//
//get rounding precision set in FPCR{7:6}
//
// rnd_e1:
ADR_40a4408:
	movel	a6@(user_fpcr),d0
	bfextu	d0{#24:#2},d0	//move the rounding prec bits d0{#7:#6} to d0{#1:#0}
	rts
//
//	g_opcls --- put opclass in d0{2:0}
//
// g_opcls:
	.globl	g_opcls
g_opcls:
	btst	#e3,a6@(e_byte)
	beq	ADR_40a4422		//if set, go to cmdreg1b
// opc_3b:
	clrl	d0		//if e3, only opclass 0x0 is possible
	rts
// opc_1b:
ADR_40a4422:
	movel	a6@(cmdreg1b),d0
	bfextu	d0{#0:#3},d0	//shift opclass bits d0{#31:#29} to d0{#2:#0}
	rts
//
//	g_dfmtou --- put destination format in d0{1:0}
//
//	If E1, the format is from cmdreg1b{12:10}
//	If E3, the format is extended.
//
//	Dest. Fmt.	
//		extended  010 -> 00
//		single    001 -> 01
//		double    101 -> 10
//
// g_dfmtou:
	.globl	g_dfmtou
g_dfmtou:
	btst	#e3,a6@(e_byte)
	beq	ADR_40a443c
	clrl	d0		//if e1, size is always ext
	rts
// op011:
ADR_40a443c:
	movel	a6@(cmdreg1b),d0
	bfextu	d0{#3:#3},d0	//dest fmt from cmdreg1b{#12:#10}
	cmpb	#1,d0		//check for single
	bne	ADR_40a4452
	movel	#1,d0
	rts
// not_sgl:
ADR_40a4452:
	cmpb	#5,d0		//check for double
	bne	ADR_40a4460
	movel	#2,d0
	rts
// not_dbl:
ADR_40a4460:
	clrl	d0		//must be extended
	rts

//
//
// Final result table for ovf_res. Note that the negative counterparts
// are unnecessary as ovf_res always returns the sign separately from
// the exponent.
//					;+zero
ADR_40a4464:
 	.int	0x00000000,0x00000000,0x00000000,0x00000000	
//					;+zero
ADR_40a4474:
 	.int	0x3f810000,0x00000000,0x00000000,0x00000000	
//					;+zero
ADR_40a4484:
 	.int	0x3c010000,0x00000000,0x00000000,0x00000000	
//					;smallest +ext denorm
ADR_40a4494:
 	.int	0x00000000,0x00000000,0x00000001,0x00000000	
//					;smallest +sgl denorm
ADR_40a44a4:
 	.int	0x3f810000,0x00000100,0x00000000,0x00000000	
//					;smallest +dbl denorm
ADR_40a44b4:
 	.int	0x3c010000,0x00000000,0x00000800,0x00000000	
ADR_40a44c4:
	.word	0x040a
	.word	0x451a
	.long	ADR_40a452c
	.long	ADR_40a453e
	.long	ADR_40a456c
	.long	ADR_40a4612
	.long	ADR_40a4624
	.long	ADR_40a4636
	.long	ADR_40a4664
	.long	ADR_40a4596
	.long	ADR_40a45a8
	.long	ADR_40a45ba
	.long	ADR_40a45e8
	.long	ADR_40a4596
	.long	ADR_40a45a8
	.long	ADR_40a45ba
	.long	ADR_40a45e8

// unf_sub:
	.globl	unf_sub
unf_sub:
	lsll	#2,d0		//move round precision to d0{#3:#2}
	bfextu	a6@(fpcr_mode){#2:#2},d1 //set round mode
	orl	d1,d0		//index is fmt:mode in d0{#3:#0}
	lea	ADR_40a44c4,a1	//load a1 with table address
	movel	a1@(d0:l:4),a1	//use d0 as index to the table
	jmp	a1@		//go to the correct routine
//
//case DEST_FMT = EXT
//
// uext_rn:
ADR_40a451a:
	lea	ADR_40a4464,a1	//answer is +/- zero
	bset	#z_bit,a6@(fpsr_cc)
	bra	ADR_40a468e	//now go set the sign	
// uext_rz:
ADR_40a452c:
	lea	ADR_40a4464,a1	//answer is +/- zero
	bset	#z_bit,a6@(fpsr_cc)
	bra	ADR_40a468e	//now go set the sign
// uext_rm:
ADR_40a453e:
	tstb	a0@(local_sgn)	//if negative underflow
	beq	ADR_40a455a
// ue_rm_neg:
	lea	ADR_40a4494,a1	//answer is negative smallest denorm
	bset	#neg_bit,a6@(fpsr_cc)
	bra	ADR_40a469e
// ue_rm_pos:
ADR_40a455a:
	lea	ADR_40a4464,a1	//answer is positive zero
	bset	#z_bit,a6@(fpsr_cc)
	bra	ADR_40a469e
// uext_rp:
ADR_40a456c:
	tstb	a0@(local_sgn)	//if negative underflow
	beq	ADR_40a458a
// ue_rp_neg:
	lea	ADR_40a4464,a1	//answer is negative zero
	oril	#negz_mask,a6@(user_fpsr)
	bra	ADR_40a469e
// ue_rp_pos:
ADR_40a458a:
	lea	ADR_40a4494,a1	//answer is positive smallest denorm
	bra	ADR_40a469e
//
//case DEST_FMT = DBL
//
// udbl_rn:
ADR_40a4596:
	lea	ADR_40a4484,a1	//answer is +/- zero
	bset	#z_bit,a6@(fpsr_cc)
	bra	ADR_40a468e
// udbl_rz:
ADR_40a45a8:
	lea	ADR_40a4484,a1	//answer is +/- zero
	bset	#z_bit,a6@(fpsr_cc)
	bra	ADR_40a468e	//now go set the sign
// udbl_rm:
ADR_40a45ba:
	tstb	a0@(local_sgn)	//if negative overflow
	beq	ADR_40a45d6
// ud_rm_neg:
	lea	ADR_40a44b4,a1	//answer is smallest denormalized negative
	bset	#neg_bit,a6@(fpsr_cc)
	bra	ADR_40a469e
// ud_rm_pos:
ADR_40a45d6:
	lea	ADR_40a4484,a1	//answer is positive zero
	bset	#z_bit,a6@(fpsr_cc)
	bra	ADR_40a469e
// udbl_rp:
ADR_40a45e8:
	tstb	a0@(local_sgn)	//if negative overflow
	beq	ADR_40a4606
// ud_rp_neg:
	lea	ADR_40a4484,a1	//answer is negative zero
	oril	#negz_mask,a6@(user_fpsr)
	bra	ADR_40a469e
// ud_rp_pos:
ADR_40a4606:
	lea	ADR_40a44b4,a1	//answer is smallest denormalized negative
	bra	ADR_40a469e
//
//case DEST_FMT = SGL
//
// usgl_rn:
ADR_40a4612:
	lea	ADR_40a4474,a1	//answer is +/- zero
	bset	#z_bit,a6@(fpsr_cc)
	bra	ADR_40a468e
// usgl_rz:
ADR_40a4624:
	lea	ADR_40a4474,a1	//answer is +/- zero
	bset	#z_bit,a6@(fpsr_cc)
	bra	ADR_40a468e
// usgl_rm:
ADR_40a4636:
	tstb	a0@(local_sgn)	//if negative overflow
	beq	ADR_40a4652
// us_rm_neg:
	lea	ADR_40a44a4,a1	//answer is smallest denormalized negative
	bset	#neg_bit,a6@(fpsr_cc)
	bra	ADR_40a469e
// us_rm_pos:
ADR_40a4652:
	lea	ADR_40a4474,a1	//answer is positive zero
	bset	#z_bit,a6@(fpsr_cc)
	bra	ADR_40a469e
// usgl_rp:
ADR_40a4664:
	tstb	a0@(local_sgn)	//if negative overflow
	beq	ADR_40a4682
// us_rp_neg:
	lea	ADR_40a4474,a1	//answer is negative zero
	oril	#negz_mask,a6@(user_fpsr)
	bra	ADR_40a469e
// us_rp_pos:
ADR_40a4682:
	lea	ADR_40a44a4,a1	//answer is smallest denormalized positive
	bra	ADR_40a469e

// uset_sign:
ADR_40a468e:
	tstb	a0@(local_sgn)	//if negative overflow
	beq	ADR_40a469e
// uneg_sign:
	bset	#neg_bit,a6@(fpsr_cc)

// end_unfr:
ADR_40a469e:
	movew	a1@(local_ex),a0@(local_ex) //be careful not to overwrite sign
	movel	a1@(local_hi),a0@(local_hi)
	movel	a1@(local_lo),a0@(local_lo)
	rts
	.long	ADR_40a471e
	.long	ADR_40a4726
	.long	ADR_40a472e
	.long	ADR_40a4734
	.long	ADR_40a473a
	.long	ADR_40a4740
	.long	ADR_40a4746
	.long	ADR_40a474c
	.long	ADR_40a4752
	.long	ADR_40a475a
	.long	ADR_40a4762
	.long	ADR_40a4768
	.long	ADR_40a476e
	.long	ADR_40a4774
	.long	ADR_40a477a
	.long	ADR_40a4780
	.long	ADR_40a4786
	.long	ADR_40a478e
	.long	ADR_40a4796
	.long	ADR_40a479c
	.long	ADR_40a47a2
	.long	ADR_40a47a8
	.long	ADR_40a47ae
	.long	ADR_40a47b4
	.globl	reg_dest
reg_dest:
	.word	0x41f9
	.word	0x040a
	.word	0x46b2
	movel	a0@(0:b,d1:l:4),a0
	jmp	a0@
ADR_40a471e:
	moveb	a6@(-84:w),a6@(-189:w)
	rts
ADR_40a4726:
	moveb	a6@(-84:w),a6@(-185:w)
	rts	
ADR_40a472e:
	moveb	a6@(-84:w),d2
	rts
ADR_40a4734:
	moveb	a6@(-84:w),d3
	rts
ADR_40a473a:
	moveb	a6@(-84:w),d4
	rts
ADR_40a4740:
	moveb	a6@(-84:w),d5
	rts
ADR_40a4746:
	moveb	a6@(-84:w),d6
	rts
ADR_40a474c:
	moveb	a6@(-84:w),d7
	rts
ADR_40a4752:
	movew	a6@(-84:w),a6@(-190:w)
	rts
ADR_40a475a:
	movew	a6@(-84:w),a6@(-186:w)
	rts
ADR_40a4762:
	movew	a6@(-84:w),d2
	rts
ADR_40a4768:
	movew	a6@(-84:w),d3
	rts
ADR_40a476e:
	movew	a6@(-84:w),d4
	rts
ADR_40a4774:
	movew	a6@(-84:w),d5
	rts
ADR_40a477a:
	movew	a6@(-84:w),d6
	rts
ADR_40a4780:
	movew	a6@(-84:w),d7
	rts
ADR_40a4786:
	movel	a6@(-84:w),a6@(-192:w)
	rts
ADR_40a478e:
	movel	a6@(-84:w),a6@(-188:w)
	rts
ADR_40a4796:
	movel	a6@(-84:w),d2
	rts
ADR_40a479c:
	movel	a6@(-84:w),d3
	rts
ADR_40a47a2:
	movel	a6@(-84:w),d4
	rts
ADR_40a47a8:
	movel	a6@(-84:w),d5
	rts
ADR_40a47ae:
	movel	a6@(-84:w),d6
	rts
ADR_40a47b4:
	movel	a6@(-84:w),d7
	rts
//
//	x_bsun.sa 1.3 10/1/90
//
//	fpsp_bsun --- FPSP handler for branch/set on unordered exception
//
//	Copy the PC to FPIAR to maintain 881/882 compatability
//
//	The real_bsun handler will need to perform further corrective
//	measures as outlined in the 040 User's Manual on pages
//	9-41f, section 9.8.3.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



	

	

// fpsp_bsun:
//
	.globl	fpsp_bsun
fpsp_bsun:
	link		a6,#-local_size
	fsave		a7@-
	moveml	d0/d1/a0/a1,a6@(-192:w)
	fmovemx	fp0/fp1/fp2/fp3,a6@(-176:w)
	fmoveml	fpcr/fpsr/fpi,a6@(user_fpcr)
//
	movel		a6@(exc_pc),a6@(user_fpi)
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(user_fpcr),fpcr/fpsr/fpi
	frestore	a7@+
	unlk		a6
	.word	0x60ff
	.word	0xffff
	.word	0xc47c
//
//	x_fline.sa 1.4 10/1/90
//
//	fpsp_fline --- FPSP handler for fline exception
//
//	First determine if the exception is one of the unimplemented
//	floating point instructions.  If so, let fpsp_unimp handle it.
//	Next, determine if the instruction is an fmovecr with a non-zero
//	<ea> field.  If so, handle here and return.  Otherwise, it
//	must be a real F-line exception.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



	

	
	
	
	

// fpsp_fline:
//
//	check for unimplemented vector first.  Use EXC_VEC-4 because
//	the equate is valid only after a 'link a6' has pushed one more
//	long onto the stack.
//
	.globl	fpsp_fline
fpsp_fline:
	cmpw	#unimp_vec,a7@(exc_vec-4)
	beq	fpsp_unimp

//
//	fmovecr with non-zero <ea> handling here
//
	subl	#4,a7		//4 accounts for 2-word difference between
//				;six word frame (unimp) and four word frame
	link	a6,#-local_size
	fsave	sp@-
	moveml	d0/d1/a0/a1,a6@(-192:w)
	moveal	a6@(exc_pc+4),a0	//get address of fline instruction
	lea	a6@(l_scr1),a1	//use l_scr1 as scratch
	movel	#4,d0
	addql	#0x4,a6
	.word	0x61ff
	.word	0xffff
	.word	0xc4ea
	subql	#0x4,a6
	movel	a6@(l_scr1),d0	//d0 now contains the fline and command word
	bfextu	d0{#4:#3},d1	//extract coprocessor id
	cmpib	#1,d1		//check if cpid=1
	bne	ADR_40a48c0	//exit if not
	bfextu	d0{#16:#6},d1
	cmpib	#0x17,d1		//check if it is an fmovecr encoding
	bne	ADR_40a48c0	
	cmpb	#0x40,sp@
	bne	ADR_40a4866:l
	subal	#0x28:l,sp
	moveb	#0x40:b,sp@
	moveb	#0x28:b,sp@(1:w)
	clrw	sp@(2:w)
	bra	ADR_40a4884:l
ADR_40a4866:
	cmpb	#0x41,sp@
	.word	0x66ff
	.word	0xffff
	.word	0xc466
	subal	#0x30:l,sp
	moveb	#0x41:b,sp@
	moveb	#0x30:b,sp@(1:w)
	clrw	sp@(2:w)

ADR_40a4884:
	movew	a6@(exc_sr+4),a6@(exc_sr) //move stacked sr to new position

	movel	a6@(exc_pc+4),a6@(exc_pc) //move stacked pc to new position

	fmovel	a6@(exc_pc),fpi	//point fpi to fline instruction

	movel	#4,d1
	addl	d1,a6@(exc_pc)	//increment stacked pc value to next instruction

	movew	#0x202c,a6@(exc_vec) //make vector look like an unimp vector

	clrl	a6@(exc_ea)	//clear the exc_ea field

	movew	d0,a6@(cmdreg1b) //move the lower word into cmdreg1b

	clrl	a6@(e_byte)
	bset	#uflag,a6@(t_byte)
	moveml	a6@(-192:w),d0/d1/a0/a1
	bra	uni_2
ADR_40a48c0:
	moveml	a6@(-192:w),d0/d1/a0/a1
	frestore	sp@+
	unlk	a6
	addl	#4,a7
	.word	0x60ff
	.word	0xffff
	.word	0xc3d0
//
//	x_operr.sa 1.15 10/9/90
//
//	fpsp_operr --- FPSP handler for operand error exception
//
//	See 68040 User's Manual pp. 9-44f
//
// Note 1: For trap disabled 040 does the following:
// If the dest is a fp reg, then an extended precision non_signaling
// NAN is stored in the dest reg.  If the dest format is b, w, or l and
// the source op is a NAN, then garbage is stored as the result (actually
// the upper 32 bits of the mantissa are sent to the integer unit). If
// the dest format is integer (b, w, l) and the operr is caused by
// integer overflow, or the source op is inf, then the result stored is
// garbage.
// There are three cases in which operr is incorrectly signaled on the 
// 040.  This occurs for move_out of format b, w, or l for the largest 
// negative integer (-2^7 for b, -2^15 for w, -2^31 for l).
//
//	  On opclass = 011 fmove.(b,w,l) that causes a conversion
//	  overflow -> OPERR, the exponent in wbte (and fpte) is:
//		byte    56 - (62 - exp)
//		word    48 - (62 - exp)
//		long    32 - (62 - exp)
//
//			where exp = (true exp) - 1
//
//  So, wbtemp and fptemp will contain the following on erroneoulsy
//	  signalled operr:
//			fpts = 1
//			fpte = $4000  (15 bit externally)
//		byte	fptm = $ffffffff ffffff80
//		word	fptm = $ffffffff ffff8000
//		long	fptm = $ffffffff 80000000
//
// Note 2: For trap enabled 040 does the following:
// If the inst is move_out, then same as Note 1.
// If the inst is not move_out, the dest is not modified.
// The exceptional operand is not defined for integer overflow 
// during a move_out.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



	

	
	
	
	

// fpsp_operr:
//
	.globl	fpsp_operr
fpsp_operr:
	link		a6,#-local_size
	fsave		a7@-
	moveml	d0/d1/a0/a1,a6@(-192:w)
	fmovemx	fp0/fp1/fp2/fp3,a6@(-176:w)
	fmoveml	fpcr/fpsr/fpi,a6@(user_fpcr)
//
// Check if this is an opclass 3 instruction.
//  If so, fall through, else branch to operr_end
//
	btst	#tflag,a6@(t_byte)
	beq	ADR_40a491c
//


//
// If the destination size is B,W,or L, the operr must be 
// handled here.
//
	movel	a6@(cmdreg1b),d0
	bfextu	d0{#3:#3},d0	//0=long, 4=word, 6=byte
	cmpib	#0,d0		//determine size// check long
	beq	ADR_40a4944
	cmpib	#4,d0		//check word
	beq	ADR_40a4a04
	cmpib	#6,d0		//check byte
	beq	ADR_40a4a6a

//
// The size is not B,W,or L, so the operr is handled by the 
// kernel handler.  Set the operr bits and clean up, leaving
// only the integer exception frame on the stack, and the 
// fpu in the original exceptional state.
//
// operr_end:
ADR_40a491c:
	bset		#operr_bit,a6@(fpsr_except)
	bset		#aiop_bit,a6@(fpsr_aexcept)
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(user_fpcr),fpcr/fpsr/fpi
	frestore	a7@+
	unlk		a6
	.word	0x60ff
	.word	0xffff
	.word	0xc2d2

// operr_long:
ADR_40a4944:
	moveql	#4,d1		//write size to d1
	moveb	a6@(stag),d0	//test stag for nan
	andib	#0xe0,d0		//clr all but tag
	cmpib	#0x60,d0		//check for nan
	beq	ADR_40a4ad2	
	cmpil	#0x80000000,a6@(fptemp_lo) //test if ls lword is special
	bne	ADR_40a4986:l
	bsr	ADR_40a4b96	//check if exp and ms mant are special
	tstl	d0
	bne	ADR_40a4986:l
	movel	#0x80000000,d0	//store special case result
	bsr	ADR_40a4b34:l
	bra	ADR_40a4bec:l
ADR_40a4986:
	movew	a6@(-216:w),d0
	andw	#0x7fff,d0
	cmpw	#0x3ffe,d0
	bne	ADR_40a49a8:l
ADR_40a4998:
	movel	a6@(-208:w),d0
	bsr	ADR_40a4b34
	bra	ADR_40a4bec:l
ADR_40a49a8:
	movew	a6@(-216:w),d0
	andw	#0x7fff,d0
	cmpw	#0x4000,d0
	bhi	ADR_40a4aea:l
	beq	ADR_40a4aea:l
	movel	a6@(-208:w),d0
	andl	#0x7fff0000,d0
	cmpl	#0x7fff0000,d0
	beq	ADR_40a4998:l
	tstl	a6@(-208:w)
	bpl	ADR_40a49f4:l
	cmpl	#0xffffffff,a6@(-212:w)
	beq	ADR_40a4998:l
	bra	ADR_40a4aea:l
ADR_40a49f4:
	tstl	a6@(-212:w)
	beq	ADR_40a4998:l
	bra	ADR_40a4aea:l

// operr_word:
ADR_40a4a04:
	moveql	#2,d1		//write size to d1
	moveb	a6@(stag),d0	//test stag for nan
	andib	#0xe0,d0		//clr all but tag
	cmpib	#0x60,d0		//check for nan
	beq	ADR_40a4ad2	
	cmpil	#0xffff8000,a6@(fptemp_lo) //test if ls lword is special
	bne	ADR_40a4a46:l
	bsr	ADR_40a4b96	//check if exp and ms mant are special
	tstl	d0
	bne	ADR_40a4a46:l
	movel	#0x80000000,d0	//store special case result
	bsr	ADR_40a4b34:l
	bra	ADR_40a4bec:l
ADR_40a4a46:
	movew	a6@(-216:w),d0
	andw	#0x7fff,d0
	cmpw	#0x3ffe,d0
	bne	ADR_40a4aea:l
	movel	a6@(-208:w),d0
	swap	d0
	bsr	ADR_40a4b34
	bra	ADR_40a4bec	//clean and exit

// operr_byte:
ADR_40a4a6a:
	moveql	#1,d1		//write size to d1
	moveb	a6@(stag),d0	//test stag for nan
	andib	#0xe0,d0		//clr all but tag
	cmpib	#0x60,d0		//check for nan
	beq	ADR_40a4ad2	
	cmpil	#0xffffff80,a6@(fptemp_lo) //test if ls lword is special
	bne	ADR_40a4aac:l
	bsr	ADR_40a4b96	//check if exp and ms mant are special
	tstl	d0
	bne	ADR_40a4aac:l
	movel	#0x80000000,d0	//store special case result
	bsr	ADR_40a4b34:l
	bra	ADR_40a4bec:l
ADR_40a4aac:
	movew	a6@(-216:w),d0
	andw	#0x7fff,d0
	cmpw	#0x3ffe,d0
	bne	ADR_40a4aea:l
	movel	a6@(-208:w),d0
	asll	#8,d0
	swap	d0
	bsr	ADR_40a4b34
	bra	ADR_40a4bec	//clean and exit
//
// This operr condition is not of the special case.  Set operr
// and aiop and write the portion of the nan to memory for the
// given size.
//
// operr_nan:
ADR_40a4ad2:
	orl	#opaop_mask,a6@(user_fpsr) //set operr & aiop

	movel	a6@(etemp_hi),d0	//output will be from upper 32 bits
	bsr	ADR_40a4b34
	bra	ADR_40a4bc4
//
// Store_max loads the max pos or negative for the size, sets
// the operr and aiop bits, and clears inex and ainex, incorrectly
// set by the 040.
//
// store_max:
ADR_40a4aea:
	orl	#opaop_mask,a6@(user_fpsr) //set operr & aiop
	bclr	#inex2_bit,a6@(fpsr_except)
	bclr	#ainex_bit,a6@(fpsr_aexcept)
	fmoveml	#0x0:l,fps
	tstw	a6@(-216:w)
	blt	ADR_40a4b22
	movel	#0x7fffffff,d0
	bsr	ADR_40a4b34
	bra	ADR_40a4bc4
// load_neg:
ADR_40a4b22:
	movel	#0x80000000,d0
	bsr	ADR_40a4b34
	bra	ADR_40a4bc4
ADR_40a4b34:
	movel	d0,a6@(-84:w)
	movel	d1,sp@-
	bsr	get_fline	//fline returned in d0
	movel	sp@+,d1
	bftst	d0{#26,#3}
	bne	ADR_40a4b84
//
// Destination is Dn.  Get register number from d0. Data is on
// the stack at (a7).
//
	andil	#7,d0		//isolate register number
	cmpil	#4,d1		//select move size
	beq	ADR_40a4b76
	cmpil	#2,d1
	bne	ADR_40a4b7c:l
	orl	#0x8,d0
	bra	ADR_40a4b7c:l
ADR_40a4b76:
	orl	#0x10,d0
ADR_40a4b7c:
	movel	d0,d1
	bra	reg_dest:l
ADR_40a4b84:
	lea	a6@(-84:w),a0
	movel	a6@(exc_ea),a1	//put user destination address in a1
	movel	d1,d0		//put size in d0
	.word	0x61ff
	.word	0xffff
	.word	0xc148
	rts

ADR_40a4b96:
	cmpil	#0xffffffff,a6@(fptemp_hi) //check if first byte is all 1's
	bne	ADR_40a4bbc	//if not all 1's then was true operr
	cmpw	#0xc000,a6@(-216:w)
	beq	ADR_40a4bc0:l
	cmpw	#0xbfff,a6@(-216:w)
	beq	ADR_40a4bc0:l

// true_operr:
ADR_40a4bbc:
	movel	#1,d0		//signal real operr
	rts
ADR_40a4bc0:
	clrl	d0
	rts

//
// End_operr tests for operr enabled.  If not, it cleans up the stack
// and does an rte.  If enabled, it cleans up the stack and branches
// to the kernel operr handler with only the integer exception
// frame on the stack and the fpu in the original exceptional state
// with correct data written to the destination.
//
// end_operr:
ADR_40a4bc4:
	btst		#operr_bit,a6@(fpcr_enable)
	beq		ADR_40a4bec
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(user_fpcr),fpcr/fpsr/fpi
	frestore	a7@+
	unlk		a6
	.word	0x60ff
	.word	0xffff
	.word	0xc02a
ADR_40a4bec:
	moveb	a6@(-126:w),d0
	andb	a6@(-122:w),d0
	andb	#0x3,d0
	beq	ADR_40a4c2e:l
	moveb	#0xc4:b,a6@(11:w)
	movel	a6@(-124:w),a6@(-256:w)
	orl	#0x1800000,a6@(-220:w)
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(-128:w),fpc/fps/fpi
	frestore	sp@+
	unlk	a6
	.word	0x60ff
	.word	0xffff
	.word	0xbeda
ADR_40a4c2e:
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(user_fpcr),fpcr/fpsr/fpi
//	frestore	(a7)+
	unlk		a6
	.word	0x60ff
	.word	0xfff5
	.word	0xd5da
//
//	x_ovfl.sa 1.6 10/1/90
//
//	fpsp_ovfl --- FPSP handler for overflow exception
//
//	Overflow occurs when a floating-point intermediate result is
//	too large to be represented in a floating-point data register,
//	or when storing to memory, the contents of a floating-point
//	data register are too large to be represented in the
//	destination format.
//		
// Trap disabled results
//
//	If the instruction is move_out, then garbage is stored in the
//destination.  If the instruction is not move_out, then the destination is not
//affected.  For 68881 compatibility, the following values should be stored at
//the destination, based on the current rounding mode:
//
//  RN	Infinity with the sign of the intermediate result.
//  RZ	Largest magnitude number, with the sign of the intermediate result.
//  RM   For pos overflow, the largest pos number. For neg overflow, -infinity
//  RP   For pos overflow, +infinity. For neg overflow, the largest neg number
//
// Trap enabled results
//	All trap disabled code applies.  In addition the exceptional operand
//needs to be made available to the users exception handler with a bias of $6000
//subtracted from the exponent.
//
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



	

	
	
	
	
	
	
	

// fpsp_ovfl:
	.globl	fpsp_ovfl
fpsp_ovfl:
	link		a6,#-local_size
	fsave		a7@-
	moveml	d0/d1/a0/a1,a6@(-192:w)
	fmovemx	fp0/fp1/fp2/fp3,a6@(-176:w)
	fmoveml	fpcr/fpsr/fpi,a6@(user_fpcr)
//
//	The 040 doesn't set the AINEX bit in the FPSR, the following line
//	temporarily rectifies this error.
//
	bset	#ainex_bit,a6@(fpsr_aexcept)
//
	bsr	ADR_40a4d76		//denormalize, round & store interm op
//
//	if overflow traps not enabled check for inexact exception
//
	btst	#ovfl_bit,a6@(fpcr_enable)
	beq	ADR_40a4cbe	
	btst	#1,a6@(-220:w)
	beq	ADR_40a4ca2:l
	bfextu	a6@(-240:w){#6,#3},d0
	bclr	d0,a6@(-283:w)
	.word	0x61ff
	.word	0xffff
	.word	0x653c
	movel	a6@(-124:w),a6@(-256:w)
	orl	#0x1800000,a6@(-220:w)
ADR_40a4ca2:
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(user_fpcr),fpcr/fpsr/fpi
	frestore	a7@+
	unlk		a6
	.word	0x60ff
	.word	0xffff
	.word	0xbeaa
//
// If inexact trap not enabled, then we are done
//
// ck_inex:
ADR_40a4cbe:
	btst	#inex2_bit,a6@(fpcr_enable)
	beq	ADR_40a4d16
	btst	#1,a6@(-220:w)
	beq	ADR_40a4cf4:l
	bfextu	a6@(-240:w){#6,#3},d0
	bclr	d0,a6@(-283:w)
	.word	0x61ff
	.word	0xffff
	.word	0x64ea
	movel	a6@(-124:w),a6@(-256:w)
	orl	#0x1800000,a6@(-220:w)
//
// Inexact enabled and reported, and we must take an inexact exception
//
ADR_40a4cf4:
	moveb		#inex_vec,a6@(exc_vec+1)
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(user_fpcr),fpcr/fpsr/fpi
	frestore	a7@+
	unlk		a6
	.word	0x60ff
	.word	0xffff
	.word	0xbdf2

ADR_40a4d16:
	bclr	#e3,a6@(e_byte)	//test and clear e3 bit
	beq	ADR_40a4d5c:l
	bfextu	a6@(-240:w){#6,#3},d0
	bclr	d0,a6@(-283:w)
	.word	0x61ff
	.word	0xffff
	.word	0x649e
	movel	a6@(-124:w),a6@(-256:w)
	orl	#0x1800000,a6@(-220:w)
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(-128:w),fpc/fps/fpi
//
	frestore	a7@+
	unlk	a6
	.word	0x60ff
	.word	0xfff5
	.word	0xd4c6
ADR_40a4d5c:
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(-128:w),fpc/fps/fpi
// e1_set:
	unlk		a6
	.word	0x60ff
	.word	0xfff5
	.word	0xd4ac

//
//	ovf_adj
//
// ovf_adj:
//
// Have a0 point to the correct operand. 
//
ADR_40a4d76:
	btst	#e3,a6@(e_byte)	//test e3 bit
	beq	ADR_40a4d8c

	lea	a6@(wbtemp),a0
	bra	ADR_40a4d90
ADR_40a4d8c:
	lea	a6@(-204:w),a0

// ovf_com:
ADR_40a4d90:
	bclr	#sign_bit,a0@(local_ex)
	sne	a0@(local_sgn)

	bsr	g_opcls		//returns opclass in d0
	cmpiw	#3,d0		//check for opclass3
	bne	ADR_40a4dc2

// FPSR_CC is saved and restored because ovf_r_x3 affects it. The FPSR_CC is
// defined to be 'not affected' for the opclass3 instruction.
	moveb	a6@(fpsr_cc),a6@(l_scr1)
 	bsr	ovf_r_x3	//returns a0 pointing to result, affects fpsr
	moveb	a6@(l_scr1),a6@(fpsr_cc)
	bra	store		//stores to memory or register
ADR_40a4dc2:
	bsr	ovf_r_x2:l
	bra	store		//stores to memory or register
//
//	x_snan.sa 1.6 10/1/90
//
//	fpsp_snan --- FPSP handler for signalling NAN exception
//
//	SNAN for float -> integer conversions (integer conversion of
//	an SNAN) is a non-maskable run-time exception.
//
//	For trap disabled 040 does the following:
//	If the dest data format is s, d, or x, then the SNAN bit in the NAN
//	is set to one and the resulting non-signaling NAN (truncated if
//	necessary) is transferred to the dest.  If the dest format is b, w,
//	or l, then garbage is written to the dest (actually the upper 32 bits
//	of the mantissa are sent to the integer unit).
//
//	For trap enabled 040 does the following:
// 	If the inst is move_out, then the results are the same as for trap 
//	disabled with the exception posted.  If the instruction is not move_
//    	out, the dest. is not modified, and the exception is posted.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



	

	
	
	
	

// fpsp_snan:
	.globl	fpsp_snan
fpsp_snan:
	link		a6,#-local_size
	fsave		a7@-
	moveml	d0/d1/a0/a1,a6@(-192:w)
	fmovemx	fp0/fp1/fp2/fp3,a6@(-176:w)
	fmoveml	fpcr/fpsr/fpi,a6@(user_fpcr)

//**check if trap enabled
	btst	#snan_bit,a6@(fpcr_enable)	//if snan enabled
	bne	ADR_40a4e2c				//then branch

	bsr	ADR_40a4eec	//else snan disabled
	moveb	a6@(-126:w),d0
	andb	a6@(-122:w),d0
	andb	#0x3,d0
	beq	ADR_40a4e92:l
	moveb	#0xc4:b,a6@(11:w)
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(-128:w),fpc/fps/fpi
	frestore	sp@+
	unlk	a6
	.word	0x60ff
	.word	0xffff
	.word	0xbcdc
ADR_40a4e2c:
	btst	#5,a6@(-228:w)
	beq	ADR_40a4fce

	bsr	ADR_40a4eec
ADR_40a4e3e:
	moveb	sp@,a6@(-69:w)
	cmpb	#0x40,sp@
	bne	ADR_40a4e54:l
	moveq	#13,d0
	bra	ADR_40a4e56:l
ADR_40a4e54:
	moveq	#11,d0
ADR_40a4e56:
	clrl	sp@
ADR_40a4e58:
	clrl	sp@-
	dbf	d0,ADR_40a4e58
	moveb	a6@(-69:w),sp@
	moveb	#0x60:b,sp@(1:w)
	movel	a6@(-124:w),a6@(-256:w)
	orl	#0x1800000,a6@(-220:w)
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(user_fpcr),fpcr/fpsr/fpi
	frestore	a7@+
	unlk		a6
	.word	0x60ff
	.word	0xffff
	.word	0xbd52

// end_snan:
ADR_40a4e92:
	bclr		#e1,a6@(e_byte)
	moveb	sp@,a6@(-69:w)
	cmpb	#0x40,sp@
	bne	ADR_40a4eae:l
	moveq	#13,d0
	bra	ADR_40a4eb0:l
ADR_40a4eae:
	moveq	#11,d0
ADR_40a4eb0:
	clrl	sp@
ADR_40a4eb2:
	clrl	sp@-
	dbf	d0,ADR_40a4eb2
	moveb	a6@(-69:w),sp@
	moveb	#0x60:b,sp@(1:w)
	movel	a6@(-124:w),a6@(-256:w)
	orl	#0x1800000,a6@(-220:w)
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(user_fpcr),fpcr/fpsr/fpi
	frestore	a7@+
	unlk		a6
	.word	0x60ff
	.word	0xfff5
	.word	0xd336

// move_out expects the cmd1b register value in d6 on entry
// move_out:
ADR_40a4eec:
	movel	a6@(exc_ea),a0	//get the address from the exception frame
	bfextu	a6@(-228:w){#3,#3},d0
	cmpl	#0x0,d0
	beq	ADR_40a4f1c	//branch if move_out long
	cmpl	#0x4,d0
	beq	ADR_40a4f3e	//branch if move_out word
	cmpl	#0x6,d0
	beq	ADR_40a4f60	//branch if move_out byte
	
//not byte, word or long
	rts
	
// sto_long:
//get the 32 most significant bits of etemp mantissa
ADR_40a4f1c:
	movel	a6@(etemp_hi),d1
	moveq	#4,d0

//set signalling nan bit
	bset	#30,d1			

//store to the users destination address
	tstl	a0		//check if destination address is 0
	beq	ADR_40a4f82:l
	movel	d1,a7@-	//move the snan onto the stack
	movel	a0,a1		//load dest addr into a1
	movel	a7,a0		//load source addr of snan into a0
	.word	0x61ff
	.word	0xffff
	.word	0xbda2
	movel	a7@+,d1	//clear off stack
	rts

// sto_word:
//get the 16 most significant bits of etemp mantissa
ADR_40a4f3e:
	movel	a6@(etemp_hi),d1
	moveq	#2,d0
	
//set signalling nan bit
	bset	#30,d1			

//store to the users destination address
	tstl	a0		//check if destination address is 0
	beq	ADR_40a4f82:l
	movel	d1,a7@-	//move the snan onto the stack
	movel	a0,a1		//load dest addr into a1
	movel	sp,a0
	.word	0x61ff
	.word	0xffff
	.word	0xbd80
	movel	a7@+,d1	//clear off stack
	rts

// sto_byte:
//get the 8 most significant bits of etemp mantissa
ADR_40a4f60:
	movel	a6@(etemp_hi),d1
	moveq	#1,d0

//set signalling nan bit
	bset	#30,d1			

//store to the users destination address
	tstl	a0		//check if destination address is 0
	beq	ADR_40a4f82:l
	movel	d1,a7@-	//move the snan onto the stack
	movel	a0,a1		//load dest addr into a1
	movel	sp,a0
	.word	0x61ff
	.word	0xffff
	.word	0xbd5e
	movel	a7@+,d1	//clear off stack
	rts
ADR_40a4f82:
	movel	d1,a6@(-84:w)
	movel	d0,sp@-
	bsr	get_fline:l
	movel	d0,d1
	andl	#0x7,d1
	movel	sp@+,d0
	cmpl	#0x4,d0
	beq	ADR_40a4fbc:l
	cmpl	#0x2,d0
	bne	ADR_40a4fc8:l
	orl	#0x8,d1
	bra	reg_dest:l
ADR_40a4fbc:
	orl	#0x10,d1
	bra	reg_dest:l
ADR_40a4fc8:
	bra	reg_dest:l
ADR_40a4fce:
	movel	a6@(-224:w),d0
	bfextu	d0{#0,#3},d0
	cmpb	#0x3,d0
	bne	ADR_40a4ff6:l
	btst	#6,a6@(-212:w)
	bne	ADR_40a4ff6:l
	movew	a6@(-216:w),d0
	bra	ADR_40a4ffa:l
ADR_40a4ff6:
	movew	a6@(-204:w),d0
ADR_40a4ffa:
	btst	#15,d0
	beq	ADR_40a5010:l
	bset	#3,a6@(-124:w)
	bra	ADR_40a4e3e
// clr_neg:
ADR_40a5010:
	bclr	#neg_bit,a6@(fpsr_cc)
	bra	ADR_40a4e3e
//
//	x_store.sa 1.4 10/1/90
//
//	store --- store operand to memory or register
//
//	Used by underflow and overflow handlers.
//
//	a0 = points to fp value to be stored.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



// fpreg_mask:
ADR_40a501c:
	.byte	0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01

	

	
	
	
	


// store:
	.globl	store
store:
	btst	#e3,a6@(e_byte)
	beq	ADR_40a50a0
// e3_sto:
	movel	a6@(cmdreg3b),d0
	bfextu	d0{#6:#3},d0		//isolate dest reg from cmdreg3b
// sto_fp:
ADR_40a5038:
	lea	ADR_40a501c,a1
	moveb	a1@(d0:w),d0		//convert reg# to dynamic register mask
	tstb	a0@(local_sgn)
	beq	ADR_40a5052
	bset	#sign_bit,a0@(local_ex)
// is_pos:
ADR_40a5052:
	fmovemx a0@,d0		//move to correct register
//
//	if fp0 or fp1 is being modified, we must put a copy
//	in the USER_FPn variable on the stack because all exception
//	handlers restore fp0 and fp1 from there.
//
	cmpb	#0x80,d0		
	bne	ADR_40a5068
	.word	0xf22e
	.word	0xf080
	.word	0xff50
	rts
// not_fp0:
ADR_40a5068:
	cmpb	#0x40,d0
	bne	ADR_40a507a:l
	.word	0xf22e
	.word	0xf040
	.word	0xff5c
	rts
ADR_40a507a:
	cmpb	#0x20,d0
	bne	ADR_40a508c:l
	.word	0xf22e
	.word	0xf020
	.word	0xff68
	rts
ADR_40a508c:
	cmpb	#0x10,d0
	bne	ADR_40a509e:l
	.word	0xf22e
	.word	0xf010
	.word	0xff74
	rts
// not_fp1:
ADR_40a509e:
	rts

// e1_sto:
ADR_40a50a0:
	bsr	g_opcls		//returns opclass in d0
	cmpib	#3,d0
	beq	ADR_40a50be		//branch if opclass 3
	movel	a6@(cmdreg1b),d0
	bfextu	d0{#6:#3},d0	//extract destination register
	bra	ADR_40a5038

// opc011:
ADR_40a50be:
	bsr	g_dfmtou	//returns dest format in d0
//				;ext=00, sgl=01, dbl=10
	movel	a0,a1		//save source addr in a1
	movel	a6@(exc_ea),a0	//get the address
	cmpil	#0,d0		//if dest format is extended
	beq	dest_ext	//then branch
	cmpil	#1,d0		//if dest format is single
	beq	dest_sgl	//then branch
//
//	fall through to dest_dbl
//

//
//	dest_dbl --- write double precision value to user space
//
//Input
//	a0 -> destination address
//	a1 -> source in extended precision
//Output
//	a0 -> ???
//	a1 -> ???
//
//Changes extended precision to double precision.
// Note: no attempt is made to round the extended value to double.
//	dbl_sign = ext_sign
//	dbl_exp = ext_exp - $3fff(ext bias) + $7ff(dbl bias)
//	get rid of ext integer bit
//	dbl_mant = ext_mant{62:12}
//
//			d0		d1		   d2
//	    	---------------   ---------------    ---------------
//  extended ->  |s|    exp    |   |1| ms mant   |    | ls mant     |
//	    	---------------   ---------------    ---------------
//	   	 95	    64    63 62	      32      31     11	  0
//				     |			     |
//				     |			     |
//				     |			     |
//		 	             v  d0		d1   v
//	    		      ---------------   ---------------
//  double   ->  	      |s|exp| mant  |   |  mant       |
//	    		      ---------------   ---------------
//	   	 	      63     51   32   31	       0
//
// dest_dbl:
	.globl	dest_dbl
dest_dbl:
	clrl	d0		//clear d0
	movew	a1@(local_ex),d0	//get exponent
	subw	#0x3fff,d0	//subtract extended precision bias
	cmpw	#0x4000,d0	//check if inf
	beq	ADR_40a5112		//if so, special case
	addw	#0x3ff,d0	//add double precision bias
	swap	d0		//d0 now in upper word
	lsll	#4,d0		//d0 now in proper place for dbl prec exp
	tstb	a1@(local_sgn)	
	beq	ADR_40a5134	//if postive, go process mantissa
	bset	#31,d0		//if negative, put in sign information before
//				;continuing
	bra	ADR_40a5134	//go process mantissa
// inf:
ADR_40a5112:
	movel	#0x7ff00000,d0	//load dbl inf exponent
	clrl	a1@(local_hi)	//clear msb
	tstb	a1@(local_sgn)
	beq	ADR_40a512a:l
	bset	#31,d0		//if negative put in sign information
ADR_40a512a:
	movel	d0,a1@(0:w)
	bra	ADR_40a515a:l
ADR_40a5134:
	movel	a1@(local_hi),d1	//get ms mantissa
	bfextu	d1{#1,#20},d1
	orl	d1,d0
// dbl_wrt:
	movel	d0,a1@(local_ex)	//put the new exp back on the stack
	movel	a1@(4:w),d1
	moveq	#21,d0
	lsll	d0,d1
	movel	d1,a1@(4:w)
	movel	a1@(8:w),d1
	bfextu	d1{#0,#21},d0
	orl	d0,a1@(4:w)
ADR_40a515a:
	movel	#0x8,d0		//byte count for double precision number
	exg	a0,a1		//a0=supervisor source, a1=user dest
	.word	0x61ff
	.word	0xffff
	.word	0xbb78
	rts
	.globl	dest_sgl
dest_sgl:
	clrl	d0
	movew	a1@(0:w),d0
	subw	#0x3fff,d0
	cmpw	#0x4000,d0
	beq	ADR_40a5196:l
	addw	#0x7f,d0
	swap	d0
	lsll	#7,d0
	tstb	a1@(2:w)
	beq	ADR_40a51b0:l
	bset	#31,d0
	bra	ADR_40a51b0:l
ADR_40a5196:
	movel	#0x7f800000:l,d0
	tstb	a1@(2:w)
	beq	ADR_40a51ba		//if positive, continue
	bset	#31,d0		//if negative, put in sign info
	bra	ADR_40a51ba

// get_sman:
ADR_40a51b0:
	movel	a1@(local_hi),d1	//get ms mantissa
	bfextu	d1{#1:#23},d1	//get upper 23 bits of ms
	orl	d1,d0		//put these bits in ms word of single
ADR_40a51ba:
	movel	d0,a6@(-84:w)
	movel	#0x4,d0		//byte count for single precision number
	tstl	a0		//users destination address
	beq	ADR_40a51d6:l
	exg	a0,a1		//a0=supervisor source, a1=user dest
	lea	a6@(-84:w),a0
	.word	0x61ff
	.word	0xffff
	.word	0xbb08
	rts
ADR_40a51d6:
	bsr	get_fline:l
	andw	#0x7,d0
	movel	d0,d1
	orl	#0x10,d1
	bra	reg_dest:l
// dest_ext:
	.globl	dest_ext
dest_ext:
	tstb	a1@(local_sgn)	//put back sign into exponent word
	beq	ADR_40a51fe
	bset	#sign_bit,a1@(local_ex)
// dstx_cont:
ADR_40a51fe:
	clrb	a1@(local_sgn)	//clear out the sign byte

	movel	#0x0c,d0		//byte count for extended precision number
	exg	a0,a1		//a0=supervisor source, a1=user dest
	.word	0x61ff
	.word	0xffff
	.word	0xbad0
	rts
//
//	x_unfl.sa 1.7 10/4/90
//
//	fpsp_unfl --- FPSP handler for underflow exception
//
// Trap disabled results
//	For 881/2 compatibility, sw must denormalize the intermediate 
// result, then store the result.  Denormalization is accomplished 
// by taking the intermediate result (which is always normalized) and 
// shifting the mantissa right while incrementing the exponent until 
// it is equal to the denormalized exponent for the destination 
// format.  After denormalizatoin, the result is rounded to the 
// destination format.
//		
// Trap enabled results
// 	All trap disabled code applies.	In addition the exceptional 
// operand needs to made available to the user with a bias of $6000 
// added to the exponent.
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



	

	
	
	
	
	
	
	
	
	
	

// fpsp_unfl:
	.globl	fpsp_unfl
fpsp_unfl:
	link		a6,#-local_size
	fsave		a7@-
	moveml	d0/d1/a0/a1,a6@(-192:w)
	fmovemx	fp0/fp1/fp2/fp3,a6@(-176:w)
	fmoveml	fpcr/fpsr/fpi,a6@(user_fpcr)
	bsr	ADR_40a533c:l
//
//	if underflow exceptions are not enabled, check for inexact
//	exception
//
	btst		#unfl_bit,a6@(fpcr_enable)
	beq		ADR_40a527e
	btst	#1,a6@(-220:w)
	beq	ADR_40a5262:l
	bfextu	a6@(-240:w){#6,#3},d0
	bclr	d0,a6@(-283:w)
	.word	0x61ff
	.word	0xffff
	.word	0x5f7c
	movel	a6@(-124:w),a6@(-256:w)
	orl	#0x1800000,a6@(-220:w)
ADR_40a5262:
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(user_fpcr),fpcr/fpsr/fpi
	frestore	a7@+
	unlk		a6
	.word	0x60ff
	.word	0xffff
	.word	0xb928
ADR_40a527e:
	moveb	a6@(-126:w),d0
	andb	a6@(-122:w),d0
	andb	#0x3,d0
	beq		ADR_40a52dc
	btst	#1,a6@(-220:w)
	beq	ADR_40a52ba:l
	bfextu	a6@(-240:w){#6,#3},d0
	bclr	d0,a6@(-283:w)
	.word	0x61ff
	.word	0xffff
	.word	0x5f24
	movel	a6@(-124:w),a6@(-256:w)
	orl	#0x1800000,a6@(-220:w)

//
// Inexact enabled and reported, and we must take an inexact exception
//
ADR_40a52ba:
	moveb		#inex_vec,a6@(exc_vec+1)
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml        a6@(user_fpcr),fpcr/fpsr/fpi
	frestore        a7@+
	unlk            a6
	.word	0x60ff
	.word	0xffff
	.word	0xb82c
ADR_40a52dc:
	bclr		#e3,a6@(e_byte)
	beq	ADR_40a5322:l
	bfextu	a6@(-240:w){#6,#3},d0
	bclr	d0,a6@(-283:w)
	.word	0x61ff
	.word	0xffff
	.word	0x5ed8
	movel	a6@(-124:w),a6@(-256:w)
	orl	#0x1800000,a6@(-220:w)
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(-128:w),fpc/fps/fpi

	frestore	a7@+
	unlk	a6
	.word	0x60ff
	.word	0xfff5
	.word	0xcf00
ADR_40a5322:
	moveml	a6@(-192:w),d0/d1/a0/a1
	fmovemx	a6@(-176:w),fp0/fp1/fp2/fp3
	fmoveml	a6@(-128:w),fpc/fps/fpi
// e1_set:
	unlk		a6
	.word	0x60ff
	.word	0xfff5
	.word	0xcee6
ADR_40a533c:
	bsr	g_rndpr:l
	movew	#0x0:w,sp@-
	movew	d0,sp@-
//
//	unf_res --- underflow result calculation
//
// unf_res:

	btst		#e3,a6@(e_byte)
	beq		ADR_40a5380
// unf_e3:
	lea		a6@(wbtemp),a0	//a0 now points to operand
	movew	a6@(-240:w),d1
	andw	#0x7f,d1
	cmpw	#0x30,d1
	beq	ADR_40a5374:l
	cmpw	#0x33,d1
	bne	ADR_40a5384:l
ADR_40a5374:
	clrl	d0
	movew	#0x1:w,sp@
	bra		ADR_40a5384
// unf_e1:
ADR_40a5380:
	lea		a6@(fptemp),a0	//a0 now points to operand
// unf_cont:
ADR_40a5384:
	bclr		#sign_bit,a0@(local_ex)	//clear sign bit
	sne		a0@(local_sgn)		//store sign
//
	bsr		denorm		//returns denorm, a0 points to it
//
//WARNING:
//				;d0 has guard,round sticky bit
//				;make sure that it is not corrupted
//				;before it reaches the round subroutine
//				;also ensure that a0 isn't corrupted

//
//	set up d1 for round subroutine
// 	d1 contains the PREC/MODE information respectively on upper/
// 	lower register halves.
//
	bfextu		a6@(fpcr_mode){#2:#2},d1	//get mode from fpcr
	addl	sp@+,d1
//
//WARNING: a0 and d0 are assumed to be intact between the denorm and
//	round subroutines. All code between these two subroutines
//	must not corrupt a0 and d0.
//
//
// Perform Round	
//	Input:		a0 points to input operand
//			d0{31:29} has guard, round, sticky
//			d1{01:00} has rounding mode
//			d1{17:16} has rounding precision
//	Output:		a0 points to rounded operand
//

	bsr		round		//returns rounded denorm at (a0)
//
// Differentiate between store to memory vs. store to register
//
	bsr		g_opcls		//returns opclass in d0{#2:#0}
	cmpib		#0x3,d0
	bne		ADR_40a53da
//
// At this point, a store to memory is pending
//
// opc011:
	bsr		g_dfmtou
	tstb		d0
	beq		ADR_40a53ce	//if extended, do not subtract
	tstb	a0@(4:w)
	bmi	ADR_40a53ce:l
// 				;If destination format is sgl/dbl, 
	subqw		#1,a0@(local_ex)	//account for denorm bias vs
//				;normalized bias
//				;          normalized   denormalized
//				;single       $7f           $7e
//				;double       $3ff          $3fe
//
// ext_opc011:
ADR_40a53ce:
	bsr		store		//stores to memory
	bra		ADR_40a540c	//finish up

//
// At this point, a store to a float register is pending
//
// not_opc011:
ADR_40a53da:
	bsr		store	//stores to float register
//				;a0 is not corrupted on a store to a
//				;float register.
//
// Set the condition codes according to result
//
	tstl		a0@(local_hi)	//check upper mantissa
	bne		ADR_40a53fa
	tstl		a0@(local_lo)	//check lower mantissa
	bne		ADR_40a53fa
	bset		#z_bit,a6@(fpsr_cc) //set condition codes if zero
// ck_sgn:
ADR_40a53fa:
	btst 		#sign_bit,a0@(local_ex)	//check the sign bit
	beq		ADR_40a540c
	bset		#neg_bit,a6@(fpsr_cc)

//
// Finish.  
//
// unf_done:
ADR_40a540c:
	btst		#inex2_bit,a6@(fpsr_except)
	beq		ADR_40a541e
	bset		#aunfl_bit,a6@(fpsr_aexcept)
// no_aunfl:
ADR_40a541e:
	rts
//
//	x_unimp.sa 1.7 10/8/90
//
//	fpsp_unimp --- FPSP handler for unimplemented instruction	
//	exception.
//
//	Invoked when the user program encounters a floating-point
//	op-code that hardware does not support.  Trap vector# 11
//	(See table 8-1 MC68030 User's Manual).
//
// 
//	Note: An fsave for an unimplemented inst. will create a short
//	fsave stack.
//
//  Input: 1. Six word stack frame for unimplemented inst, four word
//            for illegal
//            (See table 8-7 MC68030 User's Manual).
//         2. Unimp (short) fsave state frame created here by fsave
//            instruction.
//
//
//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



	

	
	
	
	

// fpsp_unimp:
	.globl	fpsp_unimp
fpsp_unimp:
	link		a6,#-local_size
	fsave		a7@-
	.globl	uni_2
uni_2:
	moveml	d0/d1/a0/a1,a6@(-192:w)
	fmovemx	fp0/fp1/fp2/fp3,a6@(-176:w)
	fmoveml	fpcr/fpsr/fpi,a6@(user_fpcr)
	moveb	sp@,d0
	andb	#0xf0,d0
	cmpb	#0x40,d0
	.word	0x66ff
	.word	0xffff
	.word	0xb88e
//
//	Temporary D25B Fix
//	The following lines are used to ensure that the FPSR
//	exception byte and condition codes are clear before proceeding
//
	movel		a6@(user_fpsr),d0
	andl		#0xff,d0	//clear all but accrued exceptions
	movel		d0,a6@(user_fpsr)
	fmoveml	#0x0:l,fps
	fmoveml	#0x0:l,fpc
//	fmove.l		#0,FPCR	;clear all user exceptions for FPSP
//
//
//	Temporary D43B fix for unimp frame stacked as a busy frame.
//	Set bits in the flag UFLG_TMP, used in place of UFLAG on 
//	the fsave stack.
//
	clrb		a6@(uflg_tmp)	//clr flag for unsupp data
	.word	0x61ff
	.word	0xffff
	.word	0x6fde
	clrb		a6@(store_flg)
	.word	0x61ff
	.word	0xffff
	.word	0x639a
	fsave		a7@-		//capture possible exc state
	tstb		a6@(store_flg)
	bne		ADR_40a548c	//if store_flg is set, no store
	bsr		sto_res		//store the result in user space
// no_store:
ADR_40a548c:
	bra		gen_except	//post any exceptions and return
//
//	x_unsupp.sa 1.7 10/8/90
//
//	fpsp_unsupp --- FPSP handler for unsupported data type/format exception
//
//	Trap vector #55	(See table 8-1 Mc68030 User's manual).	
//	Invoked when the user program encounters a data format (packed) that
//	hardware does not support or a data type (denormalized numbers or un-
//	normalized numbers).
//	Normalizes denorms and unnorms, unpacks packed numbers then stores 
//	them back into the machine to let the 040 finish the operation.  
//
//	Unsupp calls two routines:
//		1. get_op -  gets the operand(s)
//		2. res_func - restore the function back into the 040 or
//				if fmove.p fpm,<ea> then pack source (fpm)
//				and store in users memory <ea>.
//
//  Input: Long fsave stack frame
//
//

//		Copyright (C) Motorola, Inc. 1990
//			All Rights Reserved
//
//	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MOTOROLA 
//	The copyright notice above does not evidence any  
//	actual or intended publication of such source code.



	

	
	
	

// fpsp_unsupp:
//
	.globl	fpsp_unsupp
fpsp_unsupp:
	link		a6,#-local_size
	fsave		a7@-
	moveml	d0/d1/a0/a1,a6@(-192:w)
	fmovemx	fp0/fp1/fp2/fp3,a6@(-176:w)
	fmoveml	fpcr/fpsr/fpi,a6@(user_fpcr)
	moveb	sp@,a6@(-69:w)
	moveb	sp@,d0
	andb	#0xf0,d0
	cmpb	#0x40,d0
	.word	0x66ff
	.word	0xffff
	.word	0xb818
// fix_con:
	fmovel		#0,fpsr	//clear all user status bits for fpsp
	fmovel		#0,fpcr	//clear all user exceptions for fpsp
	movel	a6@(-124:w),d1
	btst	#5,a6@(-228:w)
	bne	ADR_40a54ea:l
	andl	#0xff00ff,d1
	bra	ADR_40a54f0:l
ADR_40a54ea:
	andl	#0xfff40ff,d1
ADR_40a54f0:
	movel	d1,a6@(-124:w)

//
//	Temporary D43B fix for unimp frame stacked as a busy frame.
//	Set bits in the flag UFLG_TMP, used in place of UFLAG on 
//	the fsave stack.
//
	st		a6@(uflg_tmp)	//set flag for unsupp data
	.word	0x61ff
	.word	0xffff
	.word	0x6f50
	bsr	res_func	//fix up stack frame so can restore it
	clrl	sp@-
	moveb	a6@(-69:w),sp@
	bra	gen_except
ADR_40a5510:
/* plan 779 (D178): the nine counters the real_* handlers increment (original [0x40b30ec, 0x40b3110), plan 778.19); provisional names (D178, D024) */
	.data
fpsp_cnt0:
	.long	0
fpsp_cnt1:
	.long	0
fpsp_cnt2:
	.long	0
fpsp_cnt3:
	.long	0
fpsp_cnt4:
	.long	0
fpsp_cnt5:
	.long	0
fpsp_cnt6:
	.long	0
fpsp_cnt7:
	.long	0
fpsp_cnt8:
	.long	0
