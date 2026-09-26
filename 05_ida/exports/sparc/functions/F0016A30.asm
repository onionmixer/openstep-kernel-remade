F0016A30: 9de3bf98                 save    %sp, -0x68, %sp
F0016A34: 40020061                 call    _spltty
F0016A38: 01000000                 nop
F0016A3C: 808e6001                 btst    1, %i1
F0016A40: 02800009                 be      loc_F0016A64
F0016A44: a0100008                 mov     %o0, %l0
F0016A48: 40001720                 call    _getc
F0016A4C: 9006200c                 add     %i0, 0xC, %o0
F0016A50: 80a22000                 cmp     %o0, 0
F0016A54: 16bffffd                 bge     loc_F0016A48
F0016A58: 01000000                 nop
F0016A5C: 7ffff0e3                 call    _wakeup
F0016A60: 90100018                 mov     %i0, %o0
F0016A64: 808e6002                 btst    2, %i1
F0016A68: 0280001a                 be      loc_F0016AD0
F0016A6C: 808e6001                 btst    1, %i1
F0016A70: 7ffff0de                 call    _wakeup
F0016A74: 90062018                 add     %i0, 0x18, %o0
F0016A78: d2062040                 ld      [%i0+0x40], %o1
F0016A7C: d4162038                 lduh    [%i0+0x38], %o2
F0016A80: 920a7eff                 and     %o1, -0x101, %o1
F0016A84: d2262040                 st      %o1, [%i0+0x40]
F0016A88: 9532a008                 srl     %o2, 8, %o2
F0016A8C: 932aa001                 sll     %o2, 1, %o1
F0016A90: 9202400a                 add     %o1, %o2, %o1
F0016A94: 932a6002                 sll     %o1, 2, %o1
F0016A98: 9222400a                 sub     %o1, %o2, %o1
F0016A9C: 932a6002                 sll     %o1, 2, %o1
F0016AA0: 153c04729412a1f0         set     _cdevsw, %o2
F0016AA8: 9202400a                 add     %o1, %o2, %o1
F0016AAC: d4026014                 ld      [%o1+0x14], %o2
F0016AB0: 90100018                 mov     %i0, %o0! FILE *
F0016AB4: 9fc28000                 call    %o2
F0016AB8: 92100019                 mov     %i1, %o1
F0016ABC: 40001703                 call    _getc
F0016AC0: 90062018                 add     %i0, 0x18, %o0! FILE *
F0016AC4: 80a22000                 cmp     %o0, 0
F0016AC8: 16bffffd                 bge     loc_F0016ABC
F0016ACC: 808e6001                 btst    1, %i1
F0016AD0: 0280000c                 be      loc_F0016B00
F0016AD4: 01000000                 nop
F0016AD8: 400016fc                 call    _getc
F0016ADC: 90100018                 mov     %i0, %o0
F0016AE0: 80a22000                 cmp     %o0, 0
F0016AE4: 16bffffd                 bge     loc_F0016AD8
F0016AE8: 11002fc0                 sethi   0xBF0000, %o0
F0016AEC: c02e204b                 clrb    [%i0+0x4B]
F0016AF0: c02e204c                 clrb    [%i0+0x4C]
F0016AF4: d2062040                 ld      [%i0+0x40], %o1
F0016AF8: 902a4008                 andn    %o1, %o0, %o0
F0016AFC: d0262040                 st      %o0, [%i0+0x40]
F0016B00: 40020089                 call    _splx
F0016B04: 90100010                 mov     %l0, %o0
F0016B08: 81c7e008                 ret
F0016B0C: 81e80000                 restore
