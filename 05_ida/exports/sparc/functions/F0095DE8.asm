F0095DE8: 13000010                 sethi   0x4000, %o1
F0095DEC: 92a26010                 deccc   0x10, %o1
F0095DF0: c0a24180                 sta     %g0, [%o1]#ASI_NUCLEUS_LITTLE
F0095DF4: 12bffffe                 bne     loc_F0095DEC
F0095DF8: c0a241c0                 sta     %g0, [%o1]0xE
F0095DFC: 81c3e008                 retl
F0095E00: 01000000                 nop
