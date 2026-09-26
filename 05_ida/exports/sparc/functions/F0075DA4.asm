F0075DA4: 9de3bf98                 save    %sp, -0x68, %sp
F0075DA8: 80a62000                 cmp     %i0, 0
F0075DAC: 02800006                 be      loc_F0075DC4
F0075DB0: a2102000                 mov     0, %l1
F0075DB4: 90067fff                 add     %i1, -1, %o0
F0075DB8: 80a22003                 cmp     %o0, 3
F0075DBC: 08800004                 bleu    loc_F0075DCC
F0075DC0: 01000000                 nop
F0075DC4: 10800046                 ba      locret_F0075EDC
F0075DC8: b0102004                 mov     4, %i0
F0075DCC: 4000836f                 call    _splusclock
F0075DD0: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0075DD4: a4100008                 mov     %o0, %l2
F0075DD8: d0040000                 ld      [%l0], %o0
F0075DDC: 80a22000                 cmp     %o0, 0
F0075DE0: 12bffffe                 bne     loc_F0075DD8
F0075DE4: 01000000                 nop
F0075DE8: 40008430                 call    _simple_lock_try
F0075DEC: 90100010                 mov     %l0, %o0
F0075DF0: 80a22000                 cmp     %o0, 0
F0075DF4: 02bffff9                 be      loc_F0075DD8
F0075DF8: 01000000                 nop
F0075DFC: d0062060                 ld      [%i0+0x60], %o0
F0075E00: 80a64008                 cmp     %i1, %o0
F0075E04: 32800016                 bne,a   loc_F0075E5C
F0075E08: d0062190                 ld      [%i0+0x190], %o0
F0075E0C: 80a66002                 cmp     %i1, 2
F0075E10: 1280002f                 bne     loc_F0075ECC
F0075E14: 912ea005                 sll     %i2, 5, %o0
F0075E18: 9022001a                 sub     %o0, %i2, %o0
F0075E1C: 912a2002                 sll     %o0, 2, %o0
F0075E20: 9002001a                 add     %o0, %i2, %o0
F0075E24: a12a2003                 sll     %o0, 3, %l0
F0075E28: 113c043e                 sethi   %hi(_tick), %o0
F0075E2C: f20223e4                 ld      [%o0+%lo(_tick)], %i1
F0075E30: 90100010                 mov     %l0, %o0
F0075E34: 7ffe429d                 call    _rem
F0075E38: 92100019                 mov     %i1, %o1! int
F0075E3C: 80a22000                 cmp     %o0, 0
F0075E40: 32800002                 bne,a   loc_F0075E48
F0075E44: a0040019                 add     %l0, %i1, %l0
F0075E48: 90100010                 mov     %l0, %o0! int
F0075E4C: 7ffe41ef                 call    _div
F0075E50: 92100019                 mov     %i1, %o1
F0075E54: 1080001e                 ba      loc_F0075ECC
F0075E58: d026205c                 st      %o0, [%i0+0x5C]
F0075E5C: d0022168                 ld      [%o0+0x168], %o0
F0075E60: 808a0019                 btst    %i1, %o0
F0075E64: 12800004                 bne     loc_F0075E74
F0075E68: 80a66002                 cmp     %i1, 2
F0075E6C: 10800018                 ba      loc_F0075ECC
F0075E70: a2102005                 mov     5, %l1
F0075E74: 12800013                 bne     loc_F0075EC0
F0075E78: f2262060                 st      %i1, [%i0+0x60]
F0075E7C: 912ea005                 sll     %i2, 5, %o0
F0075E80: 9022001a                 sub     %o0, %i2, %o0
F0075E84: 912a2002                 sll     %o0, 2, %o0
F0075E88: 9002001a                 add     %o0, %i2, %o0
F0075E8C: a12a2003                 sll     %o0, 3, %l0
F0075E90: 113c043e                 sethi   %hi(_tick), %o0
F0075E94: f20223e4                 ld      [%o0+%lo(_tick)], %i1
F0075E98: 90100010                 mov     %l0, %o0
F0075E9C: 7ffe4283                 call    _rem
F0075EA0: 92100019                 mov     %i1, %o1! int
F0075EA4: 80a22000                 cmp     %o0, 0
F0075EA8: 32800002                 bne,a   loc_F0075EB0
F0075EAC: a0040019                 add     %l0, %i1, %l0
F0075EB0: 90100010                 mov     %l0, %o0! int
F0075EB4: 7ffe41d5                 call    _div
F0075EB8: 92100019                 mov     %i1, %o1
F0075EBC: d026205c                 st      %o0, [%i0+0x5C]
F0075EC0: 90100018                 mov     %i0, %o0
F0075EC4: 7fffeea0                 call    _compute_priority
F0075EC8: 92102001                 mov     1, %o1
F0075ECC: c0262020                 clr     [%i0+0x20]
F0075ED0: 40008395                 call    _splx
F0075ED4: 90100012                 mov     %l2, %o0
F0075ED8: b0100011                 mov     %l1, %i0
F0075EDC: 81c7e008                 ret
F0075EE0: 81e80000                 restore
