F0006CE0: 80924000                 tst     %o1
F0006CE4: 32800003                 bne,a   loc_F0006CF0
F0006CE8: 9de3bfa0                 save    %sp, -0x60, %sp
F0006CEC: 30800066                 ba,a    locret_F0006E84
F0006CF0: 90100018                 mov     %i0, %o0
F0006CF4: d206c000                 ld      [%i3], %o1
F0006CF8: 40000068                 call    sub_F0006E98
F0006CFC: 94100019                 mov     %i1, %o2
F0006D00: 80924000                 tst     %o1
F0006D04: 3680000e                 bge,a   loc_F0006D3C
F0006D08: 01000000                 nop
F0006D0C: a2103fff                 mov     -1, %l1
F0006D10: 80a44009                 cmp     %l1, %o1
F0006D14: 32800006                 bne,a   loc_F0006D2C
F0006D18: 01000000                 nop
F0006D1C: 23200000                 sethi   0x80000000, %l1
F0006D20: 80920000                 tst     %o0
F0006D24: 2c800012                 bneg,a  loc_F0006D6C
F0006D28: b2100000                 clr     %i1
F0006D2C: 23200000                 sethi   0x80000000, %l1
F0006D30: 90100011                 mov     %l1, %o0
F0006D34: 1080000e                 ba      loc_F0006D6C
F0006D38: b2100000                 clr     %i1
F0006D3C: 80924000                 tst     %o1
F0006D40: 12800007                 bne     loc_F0006D5C
F0006D44: 01000000                 nop
F0006D48: 231fffffa21463ff         set     0x7FFFFFFF, %l1
F0006D50: 80a20011                 cmp     %o0, %l1
F0006D54: 28800006                 bleu,a  loc_F0006D6C
F0006D58: b2100009                 mov     %o1, %i1
F0006D5C: 111fffff901223ff         set     0x7FFFFFFF, %o0
F0006D64: 10800002                 ba      loc_F0006D6C
F0006D68: b2100000                 clr     %i1
F0006D6C: d0268000                 st      %o0, [%i2]
F0006D70: b0102001                 mov     1, %i0
F0006D74: 81c7e008                 ret
F0006D78: 81e80000                 restore
