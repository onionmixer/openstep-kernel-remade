F0009D04: 9de3bf98                 save    %sp, -0x68, %sp
F0009D08: 90100019                 mov     %i1, %o0! int
F0009D0C: a2102000                 mov     0, %l1
F0009D10: b2102000                 mov     0, %i1
F0009D14: 80a22000                 cmp     %o0, 0
F0009D18: 02800006                 be      loc_F0009D30
F0009D1C: a12e2006                 sll     %i0, 6, %l0
F0009D20: 1300000f                 sethi   0x3C00, %o1! int
F0009D24: 7ffff239                 call    _div
F0009D28: 92126109                 bset    0x109, %o1
F0009D2C: a0040008                 add     %l0, %o0, %l0
F0009D30: 11000007901223ff         set     0x1FFF, %o0
F0009D38: 80a40008                 cmp     %l0, %o0
F0009D3C: 04800008                 ble     loc_F0009D5C
F0009D40: 80a66000                 cmp     %i1, 0
F0009D44: b20c2004                 and     %l0, 4, %i1
F0009D48: a13c2003                 sra     %l0, 3, %l0
F0009D4C: 80a40008                 cmp     %l0, %o0
F0009D50: 14bffffd                 bg      loc_F0009D44
F0009D54: a2046001                 inc     %l1
F0009D58: 80a66000                 cmp     %i1, 0
F0009D5C: 02800009                 be      loc_F0009D80
F0009D60: 11000007                 sethi   0x1C00, %o0
F0009D64: a0042001                 inc     %l0
F0009D68: 901223ff                 bset    0x3FF, %o0
F0009D6C: 80a40008                 cmp     %l0, %o0
F0009D70: 24800005                 ble,a   locret_F0009D84
F0009D74: b12c600d                 sll     %l1, 13, %i0
F0009D78: a13c2003                 sra     %l0, 3, %l0
F0009D7C: a2046001                 inc     %l1
F0009D80: b12c600d                 sll     %l1, 13, %i0
F0009D84: 81c7e008                 ret
F0009D88: 91ee0010                 restore %i0, %l0, %o0
