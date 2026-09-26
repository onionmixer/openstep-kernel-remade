F0094A78: 9de3bfa0                 save    %sp, -0x60, %sp
F0094A7C: a1480000                 rdhpr   %hpstate, %l0
F0094A80: a2142f00                 or      %l0, 0xF00, %l1
F0094A84: 818c4000                 saved
F0094A88: 01000000                 nop
F0094A8C: 01000000                 nop
F0094A90: 01000000                 nop
F0094A94: 7ffdc10e                 call    _reset_windows
F0094A98: 01000000                 nop
F0094A9C: f0062028                 ld      [%i0+0x28], %i0
F0094AA0: fe062000                 ld      [%i0], %i7
F0094AA4: fc062004                 ld      [%i0+4], %fp
F0094AA8: 9c27a060                 sub     %fp, 0x60, %sp ! '`'
F0094AAC: a1480000                 rdhpr   %hpstate, %l0
F0094AB0: a02c2f00                 bclr    0xF00, %l0
F0094AB4: e2062008                 ld      [%i0+8], %l1
F0094AB8: 29000004                 sethi   0x1000, %l4
F0094ABC: a02c0014                 bclr    %l4, %l0
F0094AC0: a20c6f00                 and     %l1, 0xF00, %l1
F0094AC4: a0140011                 bset    %l1, %l0
F0094AC8: 818c0000                 saved
F0094ACC: 01000000                 nop
F0094AD0: 01000000                 nop
F0094AD4: 01000000                 nop
F0094AD8: b0100019                 mov     %i1, %i0
F0094ADC: 81c7e008                 ret
F0094AE0: 81e80000                 restore
