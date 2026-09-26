F00F2974: c402200c                 ld      [%o0+0xC], %g2
F00F2978: 80a0a000                 cmp     %g2, 0
F00F297C: 02800007                 be      loc_F00F2998
F00F2980: c402600c                 ld      [%o1+0xC], %g2
F00F2984: 80a0a000                 cmp     %g2, 0
F00F2988: 12800005                 bne     loc_F00F299C
F00F298C: 01000000                 nop
F00F2990: 1080000d                 ba      locret_F00F29C4
F00F2994: 90103fff                 mov     -1, %o0
F00F2998: 80a0a000                 cmp     %g2, 0
F00F299C: 22800008                 be,a    loc_F00F29BC
F00F29A0: c4026014                 ld      [%o1+0x14], %g2
F00F29A4: c402200c                 ld      [%o0+0xC], %g2
F00F29A8: 80a0a000                 cmp     %g2, 0
F00F29AC: 32800004                 bne,a   loc_F00F29BC
F00F29B0: c4026014                 ld      [%o1+0x14], %g2
F00F29B4: 10800004                 ba      locret_F00F29C4
F00F29B8: 90102001                 mov     1, %o0
F00F29BC: d0022014                 ld      [%o0+0x14], %o0
F00F29C0: 90208008                 sub     %g2, %o0, %o0
F00F29C4: 81c3e008                 retl
F00F29C8: 01000000                 nop
