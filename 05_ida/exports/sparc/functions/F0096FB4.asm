F0096FB4: 033c0464                 sethi   %hi(_cache), %g1
F0096FB8: c2006330                 ld      [%g1+%lo(_cache)], %g1
F0096FBC: 80a06003                 cmp     %g1, 3
F0096FC0: 32800012                 bne,a   locret_F0097008
F0096FC4: d2a20400                 sta     %o1, [%o0]0x20
F0096FC8: 9b480000                 rdhpr   %hpstate, %o5
F0096FCC: 822b6020                 andn    %o5, 0x20, %g1
F0096FD0: 81884000                 saved
F0096FD4: 01000000                 nop
F0096FD8: 01000000                 nop
F0096FDC: 01000000                 nop
F0096FE0: d8800080                 lda     [%g0]#ASI_NUCLEUS, %o4
F0096FE4: 0300002082130001         set     0x8000, %g1
F0096FEC: c2a00080                 sta     %g1, [%g0]#ASI_NUCLEUS
F0096FF0: d2a20400                 sta     %o1, [%o0]0x20
F0096FF4: d8a00080                 sta     %o4, [%g0]#ASI_NUCLEUS
F0096FF8: 818b4000                 saved
F0096FFC: 01000000                 nop
F0097000: 01000000                 nop
F0097004: 01000000                 nop
F0097008: 81c3e008                 retl
F009700C: 01000000                 nop
