F0006D7C: 80924000                 tst     %o1
F0006D80: 32800003                 bne,a   loc_F0006D8C
F0006D84: 9de3bfa0                 save    %sp, -0x60, %sp
F0006D88: 3080003f                 ba,a    locret_F0006E84
F0006D8C: 90100018                 mov     %i0, %o0
F0006D90: d206c000                 ld      [%i3], %o1
F0006D94: 4000003e                 call    sub_F0006E8C
F0006D98: 94100019                 mov     %i1, %o2
F0006D9C: a4100000                 clr     %l2
F0006DA0: 80924000                 tst     %o1
F0006DA4: 22800006                 be,a    loc_F0006DBC
F0006DA8: b2100009                 mov     %o1, %i1
F0006DAC: 90100000                 clr     %o0
F0006DB0: 903a0000                 not     %o0
F0006DB4: a414a002                 bset    2, %l2
F0006DB8: b2100009                 mov     %o1, %i1
F0006DBC: d0268000                 st      %o0, [%i2]
F0006DC0: a6100008                 mov     %o0, %l3
F0006DC4: a8100008                 mov     %o0, %l4
F0006DC8: 90100013                 mov     %l3, %o0
F0006DCC: 10bfff97                 ba      loc_F0006C28
F0006DD0: b0102001                 mov     1, %i0
