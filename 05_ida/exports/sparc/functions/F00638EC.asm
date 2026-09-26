F00638EC: 9de3bf98                 save    %sp, -0x68, %sp
F00638F0: 113c04d0                 sethi   %hi(_active_threads), %o0
F00638F4: 4000cca5                 call    _splusclock
F00638F8: e4022260                 ld      [%o0+%lo(_active_threads)], %l2
F00638FC: 133c04d2                 sethi   %hi(_processor_ptr), %o1
F0063900: da0261b0                 ld      [%o1+%lo(_processor_ptr)], %o5
F0063904: a6102000                 mov     0, %l3
F0063908: d2036114                 ld      [%o5+0x114], %o1
F006390C: 80a26001                 cmp     %o1, 1
F0063910: 0280000c                 be      loc_F0063940
F0063914: a8100008                 mov     %o0, %l4
F0063918: 80a26001                 cmp     %o1, 1
F006391C: 14800006                 bg      loc_F0063934
F0063920: 80a26003                 cmp     %o1, 3
F0063924: 80a26000                 cmp     %o1, 0
F0063928: 028000a9                 be      loc_F0063BCC
F006392C: 113c043e                 sethi   -0xFEF0800, %o0
F0063930: 308000a5                 ba,a    loc_F0063BC4
F0063934: 148000a4                 bg      loc_F0063BC4
F0063938: 113c043e                 sethi   -0xFEF0800, %o0
F006393C: 308000a4                 ba,a    loc_F0063BCC
F0063940: 113c04cf                 sethi   %hi(_active_u), %o0
F0063944: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0063948: d4020000                 ld      [%o0], %o2
F006394C: 80a2a000                 cmp     %o2, 0
F0063950: 02800020                 be      loc_F00639D0
F0063954: 113c04cf                 sethi   -0xFECC400, %o0
F0063958: d04aa017                 ldsb    [%o2+0x17], %o0
F006395C: 80a22000                 cmp     %o0, 0
F0063960: 12800015                 bne     loc_F00639B4
F0063964: 133c04cf                 sethi   -0xFECC400, %o1
F0063968: 80a4a000                 cmp     %l2, 0
F006396C: 02800019                 be      loc_F00639D0
F0063970: 113c04cf                 sethi   -0xFECC400, %o0
F0063974: d004a084                 ld      [%l2+0x84], %o0
F0063978: d202a018                 ld      [%o2+0x18], %o1
F006397C: d002204c                 ld      [%o0+0x4C], %o0
F0063980: 96924008                 orcc    %o1, %o0, %o3
F0063984: 02800013                 be      loc_F00639D0
F0063988: 113c04cf                 sethi   -0xFECC400, %o0
F006398C: d002a028                 ld      [%o2+0x28], %o0
F0063990: 808a2010                 btst    0x10, %o0
F0063994: 12800008                 bne     loc_F00639B4
F0063998: 133c04cf                 sethi   -0xFECC400, %o1
F006399C: d002a020                 ld      [%o2+0x20], %o0
F00639A0: d202a01c                 ld      [%o2+0x1C], %o1
F00639A4: 90120009                 bset    %o1, %o0
F00639A8: 80aac008                 andncc  %o3, %o0, %g0
F00639AC: 02800008                 be      loc_F00639CC
F00639B0: 133c04cf                 sethi   -0xFECC400, %o1
F00639B4: 92126160                 bset    0x160, %o1
F00639B8: 952ce002                 sll     %l3, 2, %o2
F00639BC: d0028009                 ld      [%o2+%o1], %o0
F00639C0: 90122020                 bset    0x20, %o0 ! ' '
F00639C4: d0228009                 st      %o0, [%o2+%o1]
F00639C8: d0028009                 ld      [%o2+%o1], %o0
F00639CC: 113c04cf                 sethi   -0xFECC400, %o0
F00639D0: 96122160                 or      %o0, 0x160, %o3
F00639D4: 952ce002                 sll     %l3, 2, %o2
F00639D8: d002800b                 ld      [%o2+%o3], %o0
F00639DC: d204a18c                 ld      [%l2+0x18C], %o1
F00639E0: 90120009                 bset    %o1, %o0
F00639E4: d022800b                 st      %o0, [%o2+%o3]
F00639E8: d002800b                 ld      [%o2+%o3], %o0
F00639EC: 9010000a                 mov     %o2, %o0
F00639F0: d002000b                 ld      [%o0+%o3], %o0
F00639F4: 80a22000                 cmp     %o0, 0
F00639F8: 12800075                 bne     loc_F0063BCC
F00639FC: 01000000                 nop
F0063A00: d004a04c                 ld      [%l2+0x4C], %o0
F0063A04: 808a2002                 btst    2, %o0
F0063A08: 12800006                 bne     loc_F0063A20
F0063A0C: 01000000                 nop
F0063A10: d0036108                 ld      [%o5+0x108], %o0
F0063A14: 80a22000                 cmp     %o0, 0
F0063A18: 24800007                 ble,a   loc_F0063A34
F0063A1C: d203612c                 ld      [%o5+0x12C], %o1
F0063A20: d002800b                 ld      [%o2+%o3], %o0
F0063A24: 90122004                 bset    4, %o0
F0063A28: d022800b                 st      %o0, [%o2+%o3]
F0063A2C: d002800b                 ld      [%o2+%o3], %o0
F0063A30: 30800067                 ba,a    loc_F0063BCC
F0063A34: d0026168                 ld      [%o1+0x168], %o0
F0063A38: 808a2002                 btst    2, %o0
F0063A3C: 2280002c                 be,a    loc_F0063AEC
F0063A40: d0036124                 ld      [%o5+0x124], %o0
F0063A44: d6026108                 ld      [%o1+0x108], %o3
F0063A48: d4026104                 ld      [%o1+0x104], %o2
F0063A4C: d8036124                 ld      [%o5+0x124], %o4
F0063A50: d004a060                 ld      [%l2+0x60], %o0
F0063A54: 80a22002                 cmp     %o0, 2
F0063A58: 02800008                 be      loc_F0063A78
F0063A5C: d204a058                 ld      [%l2+0x58], %o1
F0063A60: 80a22002                 cmp     %o0, 2
F0063A64: 14800006                 bg      loc_F0063A7C
F0063A68: 80a2e000                 cmp     %o3, 0
F0063A6C: 80a22001                 cmp     %o0, 1
F0063A70: 0280000e                 be      loc_F0063AA8
F0063A74: 80a32000                 cmp     %o4, 0
F0063A78: 80a2e000                 cmp     %o3, 0
F0063A7C: 02800012                 be      loc_F0063AC4
F0063A80: 80a28009                 cmp     %o2, %o1
F0063A84: 06800011                 bl      loc_F0063AC8
F0063A88: 90102000                 mov     0, %o0
F0063A8C: 1480000f                 bg      loc_F0063AC8
F0063A90: 90102001                 mov     1, %o0
F0063A94: 80a32000                 cmp     %o4, 0
F0063A98: 1280000c                 bne     loc_F0063AC8
F0063A9C: 90102000                 mov     0, %o0
F0063AA0: 1080000a                 ba      loc_F0063AC8
F0063AA4: 90102001                 mov     1, %o0
F0063AA8: 12800008                 bne     loc_F0063AC8
F0063AAC: 90102000                 mov     0, %o0
F0063AB0: 80a2e000                 cmp     %o3, 0
F0063AB4: 04800005                 ble     loc_F0063AC8
F0063AB8: 80a28009                 cmp     %o2, %o1
F0063ABC: 16800003                 bge     loc_F0063AC8
F0063AC0: 90102001                 mov     1, %o0
F0063AC4: 90102000                 mov     0, %o0
F0063AC8: 80a22000                 cmp     %o0, 0
F0063ACC: 12800037                 bne     loc_F0063BA8
F0063AD0: 133c04cf                 sethi   -0xFECC400, %o1
F0063AD4: d004a060                 ld      [%l2+0x60], %o0
F0063AD8: 80a22002                 cmp     %o0, 2
F0063ADC: 1280003c                 bne     loc_F0063BCC
F0063AE0: 90102001                 mov     1, %o0
F0063AE4: 1080003a                 ba      loc_F0063BCC
F0063AE8: d0236124                 st      %o0, [%o5+0x124]
F0063AEC: 80a22000                 cmp     %o0, 0
F0063AF0: 12800037                 bne     loc_F0063BCC
F0063AF4: a2100009                 mov     %o1, %l1
F0063AF8: d0046108                 ld      [%l1+0x108], %o0
F0063AFC: 80a22000                 cmp     %o0, 0
F0063B00: 04800033                 ble     loc_F0063BCC
F0063B04: 01000000                 nop
F0063B08: d0046104                 ld      [%l1+0x104], %o0
F0063B0C: 912a2003                 sll     %o0, 3, %o0
F0063B10: d2044008                 ld      [%l1+%o0], %o1
F0063B14: 94044008                 add     %l1, %o0, %o2
F0063B18: 80a28009                 cmp     %o2, %o1
F0063B1C: 3280001f                 bne,a   loc_F0063B98
F0063B20: d2046104                 ld      [%l1+0x104], %o1
F0063B24: a0046100                 add     %l1, 0x100, %l0
F0063B28: d0040000                 ld      [%l0], %o0
F0063B2C: 80a22000                 cmp     %o0, 0
F0063B30: 12bffffe                 bne     loc_F0063B28
F0063B34: 01000000                 nop
F0063B38: 4000ccdc                 call    _simple_lock_try
F0063B3C: 90100010                 mov     %l0, %o0
F0063B40: 80a22000                 cmp     %o0, 0
F0063B44: 02bffff9                 be      loc_F0063B28
F0063B48: 01000000                 nop
F0063B4C: d6046104                 ld      [%l1+0x104], %o3
F0063B50: d2046108                 ld      [%l1+0x108], %o1
F0063B54: 912ae003                 sll     %o3, 3, %o0
F0063B58: 80a26000                 cmp     %o1, 0
F0063B5C: 0480000d                 ble     loc_F0063B90
F0063B60: 94044008                 add     %l1, %o0, %o2
F0063B64: 9292c000                 orcc    %o3, %g0, %o1
F0063B68: 2680000a                 bl,a    loc_F0063B90
F0063B6C: d2246104                 st      %o1, [%l1+0x104]
F0063B70: d0028000                 ld      [%o2], %o0
F0063B74: 80a28008                 cmp     %o2, %o0
F0063B78: 32800006                 bne,a   loc_F0063B90
F0063B7C: d2246104                 st      %o1, [%l1+0x104]
F0063B80: 92827fff                 inccc   -1, %o1
F0063B84: 1cbffffb                 bpos    loc_F0063B70
F0063B88: 9402bff8                 inc     -8, %o2
F0063B8C: d2246104                 st      %o1, [%l1+0x104]
F0063B90: c0246100                 clr     [%l1+0x100]
F0063B94: d2046104                 ld      [%l1+0x104], %o1
F0063B98: d004a058                 ld      [%l2+0x58], %o0
F0063B9C: 80a24008                 cmp     %o1, %o0
F0063BA0: 0680000b                 bl      loc_F0063BCC
F0063BA4: 133c04cf                 sethi   -0xFECC400, %o1
F0063BA8: 92126160                 bset    0x160, %o1
F0063BAC: 952ce002                 sll     %l3, 2, %o2
F0063BB0: d0028009                 ld      [%o2+%o1], %o0
F0063BB4: 90122004                 bset    4, %o0
F0063BB8: d0228009                 st      %o0, [%o2+%o1]
F0063BBC: d0028009                 ld      [%o2+%o1], %o0! char *
F0063BC0: 30800003                 ba,a    loc_F0063BCC
F0063BC4: 7ffec56b                 call    _panic
F0063BC8: 90122088                 bset    0x88, %o0
F0063BCC: 4000cc56                 call    _splx
F0063BD0: 90100014                 mov     %l4, %o0
F0063BD4: 81c7e008                 ret
F0063BD8: 81e80000                 restore
