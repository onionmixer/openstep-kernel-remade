F0015EFC: 9de3bf90                 save    %sp, -0x70, %sp
F0015F00: aa102000                 mov     0, %l5
F0015F04: b6102000                 mov     0, %i3
F0015F08: 3b3c04cf9a1761d8         set     _active_u, %o5
F0015F10: 98102009                 mov     9, %o4
F0015F14: ac102000                 mov     0, %l6
F0015F18: a6102000                 mov     0, %l3
F0015F1C: 053c042d8410a158         set     unk_F010B558, %g2
F0015F24: 80a4c01a                 cmp     %l3, %i2
F0015F28: 1680003b                 bge     loc_F0016014
F0015F2C: ee058002                 ld      [%l6+%g2], %l7
F0015F30: b8100018                 mov     %i0, %i4
F0015F34: a8100019                 mov     %i1, %l4
F0015F38: 9134e005                 srl     %l3, 5, %o0
F0015F3C: 912a2002                 sll     %o0, 2, %o0
F0015F40: e2070008                 ld      [%i4+%o0], %l1
F0015F44: 80a46000                 cmp     %l1, 0
F0015F48: 22800030                 be,a    loc_F0016008
F0015F4C: a604e020                 inc     0x20, %l3 ! ' '
F0015F50: a4102000                 mov     0, %l2
F0015F54: 808c6001                 btst    1, %l1
F0015F58: 12800004                 bne     loc_F0015F68
F0015F5C: a004c012                 add     %l3, %l2, %l0
F0015F60: 10800025                 ba      loc_F0015FF4
F0015F64: a33c6001                 sra     %l1, 1, %l1
F0015F68: 80a4001a                 cmp     %l0, %i2
F0015F6C: 16800026                 bge     loc_F0016004
F0015F70: d20761d8                 ld      [%i5+0x1D8], %o1
F0015F74: d0026158                 ld      [%o1+0x158], %o0
F0015F78: 80a40008                 cmp     %l0, %o0
F0015F7C: 16800022                 bge     loc_F0016004
F0015F80: 912c2002                 sll     %l0, 2, %o0
F0015F84: d202614c                 ld      [%o1+0x14C], %o1
F0015F88: d0024008                 ld      [%o1+%o0], %o0
F0015F8C: 80a22000                 cmp     %o0, 0
F0015F90: 32800005                 bne,a   loc_F0015FA4
F0015F94: d2022014                 ld      [%o0+0x14], %o1
F0015F98: d0036004                 ld      [%o5+4], %o0
F0015F9C: 1080001a                 ba      loc_F0016004
F0015FA0: d82a2038                 stb     %o4, [%o0+0x38]
F0015FA4: d4026008                 ld      [%o1+8], %o2
F0015FA8: d83fbff0                 std     %o4, [%fp+var_10]
F0015FAC: 9fc28000                 call    %o2
F0015FB0: 92100017                 mov     %l7, %o1
F0015FB4: 80a22000                 cmp     %o0, 0
F0015FB8: 0280000b                 be      loc_F0015FE4
F0015FBC: d81fbff0                 ldd     [%fp+var_10], %o4
F0015FC0: aa056001                 inc     %l5
F0015FC4: 95342005                 srl     %l0, 5, %o2
F0015FC8: 952aa002                 sll     %o2, 2, %o2
F0015FCC: 960c201f                 and     %l0, 0x1F, %o3
F0015FD0: 90102001                 mov     1, %o0
F0015FD4: d205000a                 ld      [%l4+%o2], %o1
F0015FD8: 912a000b                 sll     %o0, %o3, %o0
F0015FDC: 92124008                 bset    %o0, %o1
F0015FE0: d225000a                 st      %o1, [%l4+%o2]
F0015FE4: a33c6001                 sra     %l1, 1, %l1
F0015FE8: 80a46000                 cmp     %l1, 0
F0015FEC: 22800007                 be,a    loc_F0016008
F0015FF0: a604e020                 inc     0x20, %l3 ! ' '
F0015FF4: a404a001                 inc     %l2
F0015FF8: 80a4a01f                 cmp     %l2, 0x1F
F0015FFC: 08bfffd7                 bleu    loc_F0015F58
F0016000: 808c6001                 btst    1, %l1
F0016004: a604e020                 inc     0x20, %l3 ! ' '
F0016008: 80a4c01a                 cmp     %l3, %i2
F001600C: 06bfffcc                 bl      loc_F0015F3C
F0016010: 9134e005                 srl     %l3, 5, %o0
F0016014: b2066020                 inc     0x20, %i1 ! ' '
F0016018: b0062020                 inc     0x20, %i0 ! ' '
F001601C: b606e001                 inc     %i3
F0016020: 80a6e002                 cmp     %i3, 2
F0016024: 04bfffbd                 ble     loc_F0015F18
F0016028: ac05a004                 inc     4, %l6
F001602C: 81c7e008                 ret
F0016030: 91e80015                 restore %g0, %l5, %o0
