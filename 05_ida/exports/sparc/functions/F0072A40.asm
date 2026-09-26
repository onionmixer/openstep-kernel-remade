F0072A40: 9de3bf98                 save    %sp, -0x68, %sp
F0072A44: 90100019                 mov     %i1, %o0
F0072A48: 133c043e                 sethi   %hi(_hz), %o1
F0072A4C: d20263e0                 ld      [%o1+%lo(_hz)], %o1
F0072A50: 7ffe4eac                 call    _umul
F0072A54: b2062020                 add     %i0, 0x20, %i1 ! ' '
F0072A58: 900223e7                 inc     0x3E7, %o0
F0072A5C: 7ffe4ee9                 call    _udiv
F0072A60: 921023e8                 mov     0x3E8, %o1
F0072A64: 40009049                 call    _splusclock
F0072A68: a0100008                 mov     %o0, %l0
F0072A6C: a2100008                 mov     %o0, %l1
F0072A70: d0064000                 ld      [%i1], %o0
F0072A74: 80a22000                 cmp     %o0, 0
F0072A78: 12bffffe                 bne     loc_F0072A70
F0072A7C: 01000000                 nop
F0072A80: 4000910a                 call    _simple_lock_try
F0072A84: 90100019                 mov     %i1, %o0
F0072A88: 80a22000                 cmp     %o0, 0
F0072A8C: 02bffff9                 be      loc_F0072A70
F0072A90: 01000000                 nop
F0072A94: d0062184                 ld      [%i0+0x184], %o0
F0072A98: 80a22000                 cmp     %o0, 0
F0072A9C: 22800005                 be,a    loc_F0072AB0
F0072AA0: c0262058                 clr     [%i0+0x58]
F0072AA4: 7fffdbec                 call    _reset_timeout
F0072AA8: 90062150                 add     %i0, 0x150, %o0
F0072AAC: c0262058                 clr     [%i0+0x58]
F0072AB0: d0062050                 ld      [%i0+0x50], %o0
F0072AB4: 80a42000                 cmp     %l0, 0
F0072AB8: d0262064                 st      %o0, [%i0+0x64]
F0072ABC: 02800005                 be      loc_F0072AD0
F0072AC0: c0262050                 clr     [%i0+0x50]
F0072AC4: 90062150                 add     %i0, 0x150, %o0
F0072AC8: 7fffdbc2                 call    _set_timeout
F0072ACC: 92100010                 mov     %l0, %o1
F0072AD0: c0262020                 clr     [%i0+0x20]
F0072AD4: 40009094                 call    _splx
F0072AD8: 90100011                 mov     %l1, %o0
F0072ADC: 81c7e008                 ret
F0072AE0: 81e80000                 restore
