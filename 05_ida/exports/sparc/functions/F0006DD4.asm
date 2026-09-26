F0006DD4: 80924000                 tst     %o1
F0006DD8: 32800003                 bne,a   loc_F0006DE4
F0006DDC: 9de3bfa0                 save    %sp, -0x60, %sp
F0006DE0: 30800029                 ba,a    locret_F0006E84
F0006DE4: 90100018                 mov     %i0, %o0
F0006DE8: d206c000                 ld      [%i3], %o1
F0006DEC: 4000002b                 call    sub_F0006E98
F0006DF0: 94100019                 mov     %i1, %o2
F0006DF4: a4100000                 clr     %l2
F0006DF8: 80924000                 tst     %o1
F0006DFC: 3680000f                 bge,a   loc_F0006E38
F0006E00: 01000000                 nop
F0006E04: a2103fff                 mov     -1, %l1
F0006E08: 80a44009                 cmp     %l1, %o1
F0006E0C: 32800006                 bne,a   loc_F0006E24
F0006E10: 01000000                 nop
F0006E14: 23200000                 sethi   0x80000000, %l1
F0006E18: 80920000                 tst     %o0
F0006E1C: 2c800014                 bneg,a  loc_F0006E6C
F0006E20: b2100000                 clr     %i1
F0006E24: a414a002                 bset    2, %l2
F0006E28: 23200000                 sethi   0x80000000, %l1
F0006E2C: 90100011                 mov     %l1, %o0
F0006E30: 1080000f                 ba      loc_F0006E6C
F0006E34: b2100000                 clr     %i1
F0006E38: 80924000                 tst     %o1
F0006E3C: 12800007                 bne     loc_F0006E58
F0006E40: 01000000                 nop
F0006E44: 231fffffa21463ff         set     0x7FFFFFFF, %l1
F0006E4C: 80a20011                 cmp     %o0, %l1
F0006E50: 28800007                 bleu,a  loc_F0006E6C
F0006E54: b2100009                 mov     %o1, %i1
F0006E58: a414a002                 bset    2, %l2
F0006E5C: 111fffff901223ff         set     0x7FFFFFFF, %o0
F0006E64: 10800002                 ba      loc_F0006E6C
F0006E68: b2100000                 clr     %i1
F0006E6C: a6100008                 mov     %o0, %l3
F0006E70: d0268000                 st      %o0, [%i2]
F0006E74: a8100008                 mov     %o0, %l4
F0006E78: 90100013                 mov     %l3, %o0
F0006E7C: 10bfff7b                 ba      loc_F0006C68
F0006E80: b0102001                 mov     1, %i0
F0006E84: 81c3e008                 retl
F0006E88: 90103ffe                 mov     -2, %o0
