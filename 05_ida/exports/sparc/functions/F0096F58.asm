F0096F58: 033c0464                 sethi   %hi(_cache), %g1
F0096F5C: c2006330                 ld      [%g1+%lo(_cache)], %g1
F0096F60: 80a06003                 cmp     %g1, 3
F0096F64: 32800012                 bne,a   locret_F0096FAC
F0096F68: d0820400                 lda     [%o0]0x20, %o0
F0096F6C: 9b480000                 rdhpr   %hpstate, %o5
F0096F70: 822b6020                 andn    %o5, 0x20, %g1
F0096F74: 81884000                 saved
F0096F78: 01000000                 nop
F0096F7C: 01000000                 nop
F0096F80: 01000000                 nop
F0096F84: d8800080                 lda     [%g0]#ASI_NUCLEUS, %o4
F0096F88: 0300002082130001         set     0x8000, %g1
F0096F90: c2a00080                 sta     %g1, [%g0]#ASI_NUCLEUS
F0096F94: d0820400                 lda     [%o0]0x20, %o0
F0096F98: d8a00080                 sta     %o4, [%g0]#ASI_NUCLEUS
F0096F9C: 818b4000                 saved
F0096FA0: 01000000                 nop
F0096FA4: 01000000                 nop
F0096FA8: 01000000                 nop
F0096FAC: 81c3e008                 retl
F0096FB0: 01000000                 nop
