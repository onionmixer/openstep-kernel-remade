F0024F1C: 9de3bf98                 save    %sp, -0x68, %sp
F0024F20: 4001c71a                 call    _splusclock
F0024F24: 01000000                 nop
F0024F28: 133c04cfb0126268         set     unk_F0133E68, %i0
F0024F30: 92063f78                 add     %i0, -0x88, %o1
F0024F34: 80a60009                 cmp     %i0, %o1
F0024F38: 0880000a                 bleu    loc_F0024F60
F0024F3C: a0100008                 mov     %o0, %l0
F0024F40: d006200c                 ld      [%i0+0xC], %o0
F0024F44: 80a20018                 cmp     %o0, %i0
F0024F48: 12800007                 bne     loc_F0024F64
F0024F4C: 153c04cf                 sethi   -0xFECC400, %o2
F0024F50: b0063fbc                 inc     -0x44, %i0
F0024F54: 80a60009                 cmp     %i0, %o1
F0024F58: 38bffffb                 bgu,a   loc_F0024F44
F0024F5C: d006200c                 ld      [%i0+0xC], %o0
F0024F60: 153c04cf                 sethi   -0xFECC400, %o2
F0024F64: 9012a1e0                 or      %o2, 0x1E0, %o0
F0024F68: 80a60008                 cmp     %i0, %o0
F0024F6C: 1280000a                 bne     loc_F0024F94
F0024F70: d202a1e0                 ld      [%o2+0x1E0], %o1
F0024F74: 90100018                 mov     %i0, %o0! unsigned int
F0024F78: 92126040                 bset    0x40, %o1 ! '@'
F0024F7C: d222a1e0                 st      %o1, [%o2+0x1E0]
F0024F80: 7fffb5be                 call    _sleep
F0024F84: 92102015                 mov     0x15, %o1
F0024F88: 4001c767                 call    _splx
F0024F8C: 90100010                 mov     %l0, %o0
F0024F90: 30bfffe4                 ba,a    loc_F0024F20
F0024F94: 4001c764                 call    _splx
F0024F98: 90100010                 mov     %l0, %o0
F0024F9C: 4001c707                 call    _spltty
F0024FA0: f006200c                 ld      [%i0+0xC], %i0
F0024FA4: d4062010                 ld      [%i0+0x10], %o2
F0024FA8: d206200c                 ld      [%i0+0xC], %o1
F0024FAC: d222a00c                 st      %o1, [%o2+0xC]
F0024FB0: d406200c                 ld      [%i0+0xC], %o2
F0024FB4: d2062010                 ld      [%i0+0x10], %o1
F0024FB8: d222a010                 st      %o1, [%o2+0x10]
F0024FBC: d2060000                 ld      [%i0], %o1
F0024FC0: 92126008                 bset    8, %o1
F0024FC4: 4001c758                 call    _splx
F0024FC8: d2260000                 st      %o1, [%i0]
F0024FCC: d0060000                 ld      [%i0], %o0
F0024FD0: 808a2200                 btst    0x200, %o0
F0024FD4: 02800006                 be      loc_F0024FEC
F0024FD8: 90122100                 bset    0x100, %o0
F0024FDC: d0260000                 st      %o0, [%i0]
F0024FE0: 7ffffde2                 call    _bwrite
F0024FE4: 90100018                 mov     %i0, %o0
F0024FE8: 30bfffce                 ba,a    loc_F0024F20
F0024FEC: 90102008                 mov     8, %o0
F0024FF0: d0260000                 st      %o0, [%i0]
F0024FF4: 81c7e008                 ret
F0024FF8: 81e80000                 restore
