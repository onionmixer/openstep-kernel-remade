F00B0E38: 9de3bf98                 save    %sp, -0x68, %sp
F00B0E3C: d206200c                 ld      [%i0+0xC], %o1
F00B0E40: e4062010                 ld      [%i0+0x10], %l2
F00B0E44: 113c0471                 sethi   %hi(aSD_0), %o0! "%s%d"
F00B0E48: e6062018                 ld      [%i0+0x18], %l3
F00B0E4C: 901221a0                 bset    %lo(aSD_0), %o0! "%s%d"
F00B0E50: d406202c                 ld      [%i0+0x2C], %o2
F00B0E54: 7ffd8e01                 call    _printf
F00B0E58: a2102000                 mov     0, %l1
F00B0E5C: 80a44012                 cmp     %l1, %l2
F00B0E60: 36800014                 bge,a   loc_F00B0EB0
F00B0E64: a2102000                 mov     0, %l1
F00B0E68: 2b3c0471                 sethi   -0xFEE3C00, %l5
F00B0E6C: 293c0471                 sethi   -0xFEE3C00, %l4
F00B0E70: a0102000                 mov     0, %l0
F00B0E74: 80a46000                 cmp     %l1, 0
F00B0E78: 12800003                 bne     loc_F00B0E84
F00B0E7C: 901521b0                 or      %l4, 0x1B0, %o0
F00B0E80: 901561a8                 or      %l5, 0x1A8, %o0! char *
F00B0E84: 7ffd8df5                 call    _printf
F00B0E88: a2046001                 inc     %l1
F00B0E8C: d2062014                 ld      [%i0+0x14], %o1
F00B0E90: d0024010                 ld      [%o1+%l0], %o0
F00B0E94: 92024010                 add     %o1, %l0, %o1
F00B0E98: 4000004b                 call    _decode_address
F00B0E9C: d2026004                 ld      [%o1+4], %o1
F00B0EA0: 80a44012                 cmp     %l1, %l2
F00B0EA4: 06bffff4                 bl      loc_F00B0E74
F00B0EA8: a004200c                 inc     0xC, %l0
F00B0EAC: a2102000                 mov     0, %l1
F00B0EB0: 80a44013                 cmp     %l1, %l3
F00B0EB4: 16800040                 bge     loc_F00B0FB4
F00B0EB8: 113c0471                 sethi   -0xFEE3C00, %o0
F00B0EBC: 113c0470a41223d4         set     _svimap, %l2
F00B0EC4: a0102000                 mov     0, %l0
F00B0EC8: 80a46000                 cmp     %l1, 0
F00B0ECC: 32800005                 bne,a   loc_F00B0EE0
F00B0ED0: 113c0471                 sethi   -0xFEE3C00, %o0
F00B0ED4: 113c0471                 sethi   %hi(asc_F011C5B8), %o0! " "
F00B0ED8: 10800003                 ba      loc_F00B0EE4
F00B0EDC: 901221b8                 bset    %lo(asc_F011C5B8), %o0! " "
F00B0EE0: 901221c0                 bset    0x1C0, %o0! char *
F00B0EE4: 7ffd8ddd                 call    _printf
F00B0EE8: 01000000                 nop
F00B0EEC: d206201c                 ld      [%i0+0x1C], %o1
F00B0EF0: 113c0471                 sethi   %hi(aPriD), %o0! "pri %d"
F00B0EF4: d2024010                 ld      [%o1+%l0], %o1
F00B0EF8: 901221c8                 bset    %lo(aPriD), %o0! "pri %d"
F00B0EFC: 7ffd8dd7                 call    _printf
F00B0F00: 920a600f                 and     %o1, 0xF, %o1
F00B0F04: d006201c                 ld      [%i0+0x1C], %o0
F00B0F08: d0020010                 ld      [%o0+%l0], %o0
F00B0F0C: 920a3ff0                 and     %o0, -0x10, %o1
F00B0F10: 80a26020                 cmp     %o1, 0x20 ! ' '
F00B0F14: 22800011                 be,a    loc_F00B0F58
F00B0F18: 113c0471                 sethi   -0xFEE3C00, %o0
F00B0F1C: 14800007                 bg      loc_F00B0F38
F00B0F20: 80a26030                 cmp     %o1, 0x30 ! '0'
F00B0F24: 80a26010                 cmp     %o1, 0x10
F00B0F28: 02800008                 be      loc_F00B0F48
F00B0F2C: 113c0471                 sethi   -0xFEE3C00, %o0
F00B0F30: 10800014                 ba      loc_F00B0F80
F00B0F34: d006201c                 ld      [%i0+0x1C], %o0
F00B0F38: 0280000c                 be      loc_F00B0F68
F00B0F3C: 900a200f                 and     %o0, 0xF, %o0
F00B0F40: 10800010                 ba      loc_F00B0F80
F00B0F44: d006201c                 ld      [%i0+0x1C], %o0! char *
F00B0F48: 7ffd8dc4                 call    _printf
F00B0F4C: 901221d0                 bset    0x1D0, %o0
F00B0F50: 1080000c                 ba      loc_F00B0F80
F00B0F54: d006201c                 ld      [%i0+0x1C], %o0! char *
F00B0F58: 7ffd8dc0                 call    _printf
F00B0F5C: 901221d8                 bset    0x1D8, %o0
F00B0F60: 10800008                 ba      loc_F00B0F80
F00B0F64: d006201c                 ld      [%i0+0x1C], %o0
F00B0F68: 912a2002                 sll     %o0, 2, %o0
F00B0F6C: d2020012                 ld      [%o0+%l2], %o1
F00B0F70: 113c0471                 sethi   %hi(aSbusLevelD), %o0! " (sbus level %d)"
F00B0F74: 7ffd8db9                 call    _printf
F00B0F78: 901221e8                 bset    %lo(aSbusLevelD), %o0! " (sbus level %d)"
F00B0F7C: d006201c                 ld      [%i0+0x1C], %o0
F00B0F80: 90020010                 add     %o0, %l0, %o0
F00B0F84: d2022004                 ld      [%o0+4], %o1
F00B0F88: 80a26000                 cmp     %o1, 0
F00B0F8C: 22800006                 be,a    loc_F00B0FA4
F00B0F90: a2046001                 inc     %l1
F00B0F94: 113c0471                 sethi   %hi(aVec0xX), %o0! " vec 0x%x"
F00B0F98: 7ffd8db0                 call    _printf
F00B0F9C: 90122200                 bset    %lo(aVec0xX), %o0! " vec 0x%x"
F00B0FA0: a2046001                 inc     %l1
F00B0FA4: 80a44013                 cmp     %l1, %l3
F00B0FA8: 06bfffc8                 bl      loc_F00B0EC8
F00B0FAC: a0042008                 inc     8, %l0
F00B0FB0: 113c0471                 sethi   -0xFEE3C00, %o0! char *
F00B0FB4: 7ffd8da9                 call    _printf
F00B0FB8: 90122210                 bset    0x210, %o0
F00B0FBC: 81c7e008                 ret
F00B0FC0: 81e80000                 restore
