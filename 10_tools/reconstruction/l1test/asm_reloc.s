# asm_reloc.s -- L1 self-test material: addends, local data refs, cross-section call.
	.text
	.globl	_kr_reloc_a
_kr_reloc_a:
Lkr_base:
	call	_kr_ext+4
	movl	_kr_global+8,%eax
	movl	$Lkr_data,%eax
	movl	Lkr_data+4,%eax
	call	_kr_other_sect
	ret
	.section __TEXT,__kr_text2
	.globl	_kr_other_sect
_kr_other_sect:
	movl	$Lkr_data,%eax
	ret
	.data
Lkr_data:
	.long	0x11111111
	.long	0x22222222
	.long	_kr_leaf
	.long	_kr_other_sect+2
	.long	_kr_other_sect-Lkr_base
	.long	Lkr_data-Lkr_base
