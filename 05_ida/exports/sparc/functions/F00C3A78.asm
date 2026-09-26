F00C3A78: 9de3bf98                 save    %sp, -0x68, %sp
F00C3A7C: 80a62000                 cmp     %i0, 0
F00C3A80: 02800028                 be      locret_F00C3B20
F00C3A84: 01000000                 nop
F00C3A88: d0060000                 ld      [%i0], %o0
F00C3A8C: 80a22000                 cmp     %o0, 0
F00C3A90: 02800024                 be      locret_F00C3B20
F00C3A94: 293c04ba                 sethi   -0xFED1800, %l4
F00C3A98: 273c0504                 sethi   -0xFEBF000, %l3
F00C3A9C: 113c0504                 sethi   %hi(paProbe), %o0! name
F00C3AA0: e2022368                 ld      [%o0+%lo(paProbe)], %l1
F00C3AA4: 253c04ba                 sethi   -0xFED1800, %l2
F00C3AA8: 4000b897                 call    _objc_getClass
F00C3AAC: d0060000                 ld      [%i0], %o0
F00C3AB0: a0920000                 orcc    %o0, %g0, %l0
F00C3AB4: 12800007                 bne     loc_F00C3AD0
F00C3AB8: 90100010                 mov     %l0, %o0! char *
F00C3ABC: d2060000                 ld      [%i0], %o1
F00C3AC0: 7ffd42e6                 call    _printf
F00C3AC4: 901520e0                 or      %l4, 0xE0, %o0! id
F00C3AC8: 10800012                 ba      loc_F00C3B10
F00C3ACC: b0062004                 inc     4, %i0
F00C3AD0: d204e270                 ld      [%l3+0x270], %o1! SEL
F00C3AD4: 4000b767                 call    _objc_msgSend
F00C3AD8: 94100011                 mov     %l1, %o2
F00C3ADC: 912a2018                 sll     %o0, 24, %o0
F00C3AE0: 80a22000                 cmp     %o0, 0
F00C3AE4: 12800007                 bne     loc_F00C3B00
F00C3AE8: 90100010                 mov     %l0, %o0! char *
F00C3AEC: d2060000                 ld      [%i0], %o1
F00C3AF0: 7ffd42da                 call    _printf
F00C3AF4: 9014a110                 or      %l2, 0x110, %o0! id
F00C3AF8: 10800006                 ba      loc_F00C3B10
F00C3AFC: b0062004                 inc     4, %i0
F00C3B00: 92100011                 mov     %l1, %o1! SEL
F00C3B04: 4000b75b                 call    _objc_msgSend
F00C3B08: 94100019                 mov     %i1, %o2
F00C3B0C: b0062004                 inc     4, %i0
F00C3B10: d0060000                 ld      [%i0], %o0
F00C3B14: 80a22000                 cmp     %o0, 0
F00C3B18: 12bfffe4                 bne     loc_F00C3AA8
F00C3B1C: 01000000                 nop
F00C3B20: 81c7e008                 ret
F00C3B24: 81e80000                 restore
