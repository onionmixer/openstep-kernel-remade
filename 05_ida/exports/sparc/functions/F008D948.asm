F008D948: 9de3bf90                 save    %sp, -0x70, %sp
F008D94C: 113c0504                 sethi   %hi(paResourcenames), %o0! id
F008D950: d2022074                 ld      [%o0+%lo(paResourcenames)], %o1! SEL
F008D954: 40018fc7                 call    _objc_msgSend
F008D958: 90100018                 mov     %i0, %o0! id
F008D95C: b0920000                 orcc    %o0, %g0, %i0
F008D960: 22800011                 be,a    locret_F008D9A4
F008D964: b010001a                 mov     %i2, %i0
F008D968: 213c0504                 sethi   -0xFEBF000, %l0
F008D96C: d4060000                 ld      [%i0], %o2
F008D970: 80a2a000                 cmp     %o2, 0
F008D974: 0280000b                 be      loc_F008D9A0
F008D978: d2042078                 ld      [%l0+0x78], %o1! SEL
F008D97C: 40018fbd                 call    _objc_msgSend
F008D980: 9010001a                 mov     %i2, %o0
F008D984: 80a22000                 cmp     %o0, 0
F008D988: 12800004                 bne     loc_F008D998
F008D98C: b0862004                 inccc   4, %i0
F008D990: 10800005                 ba      locret_F008D9A4
F008D994: b0102000                 mov     0, %i0
F008D998: 32bffff6                 bne,a   loc_F008D970
F008D99C: d4060000                 ld      [%i0], %o2
F008D9A0: b010001a                 mov     %i2, %i0
F008D9A4: 81c7e008                 ret
F008D9A8: 81e80000                 restore
