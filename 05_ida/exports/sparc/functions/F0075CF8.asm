F0075CF8: 9de3bf98                 save    %sp, -0x68, %sp
F0075CFC: 80a62000                 cmp     %i0, 0
F0075D00: 02800006                 be      loc_F0075D18
F0075D04: 80a66000                 cmp     %i1, 0
F0075D08: 02800004                 be      loc_F0075D18
F0075D0C: 80a6a01f                 cmp     %i2, 0x1F
F0075D10: 08800004                 bleu    loc_F0075D20
F0075D14: 01000000                 nop
F0075D18: 10800021                 ba      locret_F0075D9C
F0075D1C: b0102004                 mov     4, %i0
F0075D20: 4000839a                 call    _splusclock
F0075D24: b2062020                 add     %i0, 0x20, %i1 ! ' '
F0075D28: a0100008                 mov     %o0, %l0
F0075D2C: d0064000                 ld      [%i1], %o0
F0075D30: 80a22000                 cmp     %o0, 0
F0075D34: 12bffffe                 bne     loc_F0075D2C
F0075D38: 01000000                 nop
F0075D3C: 4000845b                 call    _simple_lock_try
F0075D40: 90100019                 mov     %i1, %o0
F0075D44: 80a22000                 cmp     %o0, 0
F0075D48: 02bffff9                 be      loc_F0075D2C
F0075D4C: 01000000                 nop
F0075D50: d0062050                 ld      [%i0+0x50], %o0
F0075D54: 80a2001a                 cmp     %o0, %i2
F0075D58: 04800007                 ble     loc_F0075D74
F0075D5C: f4262054                 st      %i2, [%i0+0x54]
F0075D60: f4262050                 st      %i2, [%i0+0x50]
F0075D64: 90100018                 mov     %i0, %o0
F0075D68: 7fffeef7                 call    _compute_priority
F0075D6C: 92102001                 mov     1, %o1
F0075D70: 30800007                 ba,a    loc_F0075D8C
F0075D74: d0062064                 ld      [%i0+0x64], %o0
F0075D78: 80a22000                 cmp     %o0, 0
F0075D7C: 06800004                 bl      loc_F0075D8C
F0075D80: 80a2001a                 cmp     %o0, %i2
F0075D84: 34800002                 bg,a    loc_F0075D8C
F0075D88: f4262064                 st      %i2, [%i0+0x64]
F0075D8C: c0262020                 clr     [%i0+0x20]
F0075D90: 400083e5                 call    _splx
F0075D94: 90100010                 mov     %l0, %o0
F0075D98: b0102000                 mov     0, %i0
F0075D9C: 81c7e008                 ret
F0075DA0: 81e80000                 restore
