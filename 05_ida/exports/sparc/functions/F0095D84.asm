F0095D84: 13000010                 sethi   0x4000, %o1
F0095D88: 92a26010                 deccc   0x10, %o1
F0095D8C: c0a24180                 sta     %g0, [%o1]#ASI_NUCLEUS_LITTLE
F0095D90: 12bffffe                 bne     loc_F0095D88
F0095D94: c0a241c0                 sta     %g0, [%o1]0xE
F0095D98: 81c3e008                 retl
F0095D9C: 01000000                 nop
