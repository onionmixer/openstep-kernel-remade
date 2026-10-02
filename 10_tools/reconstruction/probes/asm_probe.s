# asm_probe.s -- probe: one function and one data word (NeXT as, i386).
	.text
	.globl _kr_asm
_kr_asm:
	movl	4(%esp),%eax
	addl	$7,%eax
	ret
	.data
	.globl	_kr_asm_data
_kr_asm_data:
	.long	0x12345678
