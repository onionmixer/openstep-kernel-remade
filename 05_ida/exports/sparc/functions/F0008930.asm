F0008930: 9de3bed0                 save    %sp, -0x130, %sp! int
F0008934: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0008938: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F000893C: ea022024                 ld      [%o0+0x24], %l5
F0008940: ae102000                 mov     0, %l7
F0008944: d005600c                 ld      [%l5+0xC], %o0
F0008948: 80a22000                 cmp     %o0, 0
F000894C: 16800020                 bge     loc_F00089CC
F0008950: b0102000                 mov     0, %i0
F0008954: 400245d1                 call    _machine_table_setokay
F0008958: d0054000                 ld      [%l5], %o0
F000895C: 80a22000                 cmp     %o0, 0
F0008960: 2280000d                 be,a    loc_F0008994
F0008964: 113c04cf                 sethi   -0xFECC400, %o0
F0008968: 14800007                 bg      loc_F0008984
F000896C: 80a22001                 cmp     %o0, 1
F0008970: 80a23fff                 cmp     %o0, -1
F0008974: 0280019d                 be      loc_F0008FE8
F0008978: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F000897C: 10800006                 ba      loc_F0008994
F0008980: 113c04cf                 sethi   -0xFECC400, %o0
F0008984: 32800004                 bne,a   loc_F0008994
F0008988: 113c04cf                 sethi   -0xFECC400, %o0
F000898C: 1080000d                 ba      loc_F00089C0
F0008990: d005600c                 ld      [%l5+0xC], %o0
F0008994: 10800195                 ba      loc_F0008FE8
F0008998: d20221dc                 ld      [%o0+0x1DC], %o1
F000899C: c0240000                 clr     [%l0]
F00089A0: 113c04cf                 sethi   -0xFECC400, %o0
F00089A4: d20221dc                 ld      [%o0+0x1DC], %o1
F00089A8: 90102003                 mov     3, %o0
F00089AC: 108001ca                 ba      locret_F00090D4
F00089B0: d02a6038                 stb     %o0, [%o1+0x38]
F00089B4: d00221dc                 ld      [%o0+0x1DC], %o0
F00089B8: 108001c7                 ba      locret_F00090D4
F00089BC: ee2a2038                 stb     %l7, [%o0+0x38]
F00089C0: b0062001                 inc     %i0
F00089C4: 90200008                 neg     %o0
F00089C8: d025600c                 st      %o0, [%l5+0xC]
F00089CC: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00089D0: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F00089D4: c0226030                 clr     [%o1+0x30]
F00089D8: d2054000                 ld      [%l5], %o1
F00089DC: 80a26001                 cmp     %o1, 1
F00089E0: 128001b9                 bne     loc_F00090C4
F00089E4: 901221dc                 bset    %lo(dword_F0133DDC), %o0
F00089E8: d0023ffc                 ld      [%o0-4], %o0
F00089EC: d2056004                 ld      [%l5+4], %o1
F00089F0: d0020000                 ld      [%o0], %o0
F00089F4: d0522030                 ldsh    [%o0+0x30], %o0
F00089F8: 80a24008                 cmp     %o1, %o0
F00089FC: 02800004                 be      loc_F0008A0C
F0008A00: 80a26000                 cmp     %o1, 0
F0008A04: 12800174                 bne     loc_F0008FD4
F0008A08: 113c04cf                 sethi   -0xFECC400, %o0
F0008A0C: d005600c                 ld      [%l5+0xC], %o0
F0008A10: 80a22001                 cmp     %o0, 1
F0008A14: 12800170                 bne     loc_F0008FD4
F0008A18: 113c04cf                 sethi   -0xFECC400, %o0
F0008A1C: 108001ab                 ba      loc_F00090C8
F0008A20: d605600c                 ld      [%l5+0xC], %o3
F0008A24: d2056004                 ld      [%l5+4], %o1
F0008A28: a4102000                 mov     0, %l2
F0008A2C: d4056008                 ld      [%l5+8], %o2
F0008A30: ac102000                 mov     0, %l6
F0008A34: d8056010                 ld      [%l5+0x10], %o4
F0008A38: 4002459b                 call    _machine_table
F0008A3C: 9a100018                 mov     %i0, %o5
F0008A40: 80a22000                 cmp     %o0, 0
F0008A44: 22800008                 be,a    loc_F0008A64
F0008A48: d0054000                 ld      [%l5], %o0
F0008A4C: 04800161                 ble     def_F0008A80! jumptable F0008A80 default case, cases 3,6-8,13
F0008A50: 80a22001                 cmp     %o0, 1
F0008A54: 12800160                 bne     loc_F0008FD4
F0008A58: 113c04cf                 sethi   -0xFECC400, %o0
F0008A5C: 1080018c                 ba      loc_F000908C
F0008A60: d2056008                 ld      [%l5+8], %o1
F0008A64: 92023fff                 add     %o0, -1, %o1
F0008A68: 80a2600e                 cmp     %o1, 0xE! switch 15 cases
F0008A6C: 18800159                 bgu     def_F0008A80! jumptable F0008A80 default case, cases 3,6-8,13
F0008A70: 113c0022                 sethi   %hi(jpt_F0008A80), %o0
F0008A74: 90122288                 bset    %lo(jpt_F0008A80), %o0
F0008A78: 932a6002                 sll     %o1, 2, %o1
F0008A7C: d0024008                 ld      [%o1+%o0], %o0
F0008A80: 81c20000                 jmp     %o0! switch jump
F0008A84: 01000000                 nop
F0008AC4: 113c04cf                 sethi   %hi(_active_u), %o0! jumptable F0008A80 case 0
F0008AC8: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F0008ACC: d0026164                 ld      [%o1+0x164], %o0
F0008AD0: 80a22000                 cmp     %o0, 0
F0008AD4: 12800005                 bne     loc_F0008AE8
F0008AD8: a6026168                 add     %o1, 0x168, %l3
F0008ADC: 90103fff                 mov     -1, %o0
F0008AE0: d037bf46                 sth     %o0, [%fp+var_BA]
F0008AE4: a607bf46                 add     %fp, var_BA, %l3
F0008AE8: 10800143                 ba      loc_F0008FF4
F0008AEC: a8102002                 mov     2, %l4
F0008AF0: d0056004                 ld      [%l5+4], %o0! jumptable F0008A80 case 2
F0008AF4: 80a22000                 cmp     %o0, 0
F0008AF8: 12800137                 bne     loc_F0008FD4
F0008AFC: 113c04cf                 sethi   -0xFECC400, %o0
F0008B00: d005600c                 ld      [%l5+0xC], %o0
F0008B04: 80a22001                 cmp     %o0, 1
F0008B08: 32800133                 bne,a   loc_F0008FD4
F0008B0C: 113c04cf                 sethi   -0xFECC400, %o0
F0008B10: 113c043f                 sethi   %hi(_avenrun), %o0
F0008B14: 108000bc                 ba      loc_F0008E04
F0008B18: 9012201c                 bset    %lo(_avenrun), %o0
F0008B1C: d0056004                 ld      [%l5+4], %o0! jumptable F0008A80 case 4
F0008B20: a007bfe8                 add     %fp, var_18, %l0
F0008B24: 4000016e                 call    _table_fsparam
F0008B28: 92100010                 mov     %l0, %o1
F0008B2C: 80a22000                 cmp     %o0, 0
F0008B30: 02800129                 be      loc_F0008FD4
F0008B34: 113c04cf                 sethi   -0xFECC400, %o0
F0008B38: 108000ba                 ba      loc_F0008E20
F0008B3C: a6100010                 mov     %l0, %l3
F0008B40: 40001660                 call    _pfind! jumptable F0008A80 case 1
F0008B44: d0056004                 ld      [%l5+4], %o0
F0008B48: a0920000                 orcc    %o0, %g0, %l0
F0008B4C: 02bfff96                 be      loc_F00089A4
F0008B50: 113c04cf                 sethi   -0xFECC400, %o0
F0008B54: e0042068                 ld      [%l0+0x68], %l0
F0008B58: d0040000                 ld      [%l0], %o0
F0008B5C: 80a22000                 cmp     %o0, 0
F0008B60: 12bffffe                 bne     loc_F0008B58
F0008B64: 01000000                 nop
F0008B68: 400238d0                 call    _simple_lock_try
F0008B6C: 90100010                 mov     %l0, %o0
F0008B70: 80a22000                 cmp     %o0, 0
F0008B74: 02bffff9                 be      loc_F0008B58
F0008B78: 01000000                 nop
F0008B7C: d0042024                 ld      [%l0+0x24], %o0
F0008B80: 80a22000                 cmp     %o0, 0
F0008B84: 04bfff86                 ble     loc_F000899C
F0008B88: a81027cc                 mov     0x7CC, %l4
F0008B8C: e204201c                 ld      [%l0+0x1C], %l1
F0008B90: 4001af29                 call    _thread_reference
F0008B94: 90100011                 mov     %l1, %o0
F0008B98: c0240000                 clr     [%l0]
F0008B9C: 253c04d0                 sethi   %hi(_page_mask), %l2
F0008BA0: d404a0d8                 ld      [%l2+%lo(_page_mask)], %o2
F0008BA4: 113c04d0                 sethi   %hi(_kernel_pageable_map), %o0
F0008BA8: d00220c0                 ld      [%o0+%lo(_kernel_pageable_map)], %o0
F0008BAC: 9202a7cc                 add     %o2, 0x7CC, %o1
F0008BB0: 4001ecc5                 call    _kmem_alloc_wait
F0008BB4: 922a400a                 bclr    %o2, %o1
F0008BB8: a0100008                 mov     %o0, %l0
F0008BBC: 4002064e                 call    _fake_u
F0008BC0: 92100011                 mov     %l1, %o1
F0008BC4: 4001adfa                 call    _thread_deallocate
F0008BC8: 90100011                 mov     %l1, %o0
F0008BCC: d204a0d8                 ld      [%l2+%lo(_page_mask)], %o1
F0008BD0: a6100010                 mov     %l0, %l3
F0008BD4: a4100013                 mov     %l3, %l2
F0008BD8: 900267cc                 add     %o1, 0x7CC, %o0
F0008BDC: 922a0009                 andn    %o0, %o1, %o1
F0008BE0: 10800105                 ba      loc_F0008FF4
F0008BE4: ac048009                 add     %l2, %o1, %l6
F0008BE8: 40001636                 call    _pfind! jumptable F0008A80 case 5
F0008BEC: d0056004                 ld      [%l5+4], %o0
F0008BF0: a0920000                 orcc    %o0, %g0, %l0
F0008BF4: 02bfff6c                 be      loc_F00089A4
F0008BF8: 113c04cf                 sethi   -0xFECC400, %o0
F0008BFC: d0042068                 ld      [%l0+0x68], %o0
F0008C00: e2056010                 ld      [%l5+0x10], %l1
F0008C04: 80a46000                 cmp     %l1, 0
F0008C08: 028000f2                 be      def_F0008A80! jumptable F0008A80 default case, cases 3,6-8,13
F0008C0C: e602200c                 ld      [%o0+0xC], %l3
F0008C10: e0042084                 ld      [%l0+0x84], %l0
F0008C14: 80a42000                 cmp     %l0, 0
F0008C18: 028000ee                 be      def_F0008A80! jumptable F0008A80 default case, cases 3,6-8,13
F0008C1C: 90100013                 mov     %l3, %o0
F0008C20: 4001ed68                 call    _vm_map_reference
F0008C24: a0240011                 sub     %l0, %l1, %l0
F0008C28: 2d3c04d0                 sethi   %hi(_page_mask), %l6
F0008C2C: d405a0d8                 ld      [%l6+%lo(_page_mask)], %o2
F0008C30: 293c04d0                 sethi   %hi(_kernel_pageable_map), %l4
F0008C34: d00520c0                 ld      [%l4+%lo(_kernel_pageable_map)], %o0
F0008C38: 9204400a                 add     %l1, %o2, %o1
F0008C3C: 4001eca2                 call    _kmem_alloc_wait
F0008C40: 922a400a                 bclr    %o2, %o1
F0008C44: c023a05c                 clr     [%sp+0x130+var_D4]
F0008C48: 92100013                 mov     %l3, %o1
F0008C4C: a4100008                 mov     %o0, %l2
F0008C50: 94100012                 mov     %l2, %o2
F0008C54: 9a102000                 mov     0, %o5
F0008C58: de05a0d8                 ld      [%l6+%lo(_page_mask)], %o7
F0008C5C: 84048011                 add     %l2, %l1, %g2
F0008C60: d00520c0                 ld      [%l4+%lo(_kernel_pageable_map)], %o0
F0008C64: 8638000f                 xnor    %g0, %o7, %g3
F0008C68: 9604400f                 add     %l1, %o7, %o3
F0008C6C: 960ac003                 and     %o3, %g3, %o3
F0008C70: 980c0003                 and     %l0, %g3, %o4
F0008C74: 8400800f                 add     %g2, %o7, %g2
F0008C78: 4001f26e                 call    _vm_map_copy
F0008C7C: a0088003                 and     %g2, %g3, %l0
F0008C80: 80a22000                 cmp     %o0, 0
F0008C84: 0280000b                 be      loc_F0008CB0
F0008C88: d605a0d8                 ld      [%l6+0xD8], %o3
F0008C8C: 92100012                 mov     %l2, %o1
F0008C90: d00520c0                 ld      [%l4+0xC0], %o0
F0008C94: 9404400b                 add     %l1, %o3, %o2
F0008C98: 4001ecc0                 call    _kmem_free_wakeup
F0008C9C: 942a800b                 bclr    %o3, %o2! size_t
F0008CA0: 4001ed5b                 call    _vm_map_deallocate
F0008CA4: 90100013                 mov     %l3, %o0
F0008CA8: 108000cb                 ba      loc_F0008FD4
F0008CAC: 113c04cf                 sethi   -0xFECC400, %o0
F0008CB0: 4001ed57                 call    _vm_map_deallocate
F0008CB4: 90100013                 mov     %l3, %o0
F0008CB8: a6240011                 sub     %l0, %l1, %l3
F0008CBC: a8100011                 mov     %l1, %l4
F0008CC0: d0043ff4                 ld      [%l0-0xC], %o0
F0008CC4: 80a22000                 cmp     %o0, 0
F0008CC8: 0280000a                 be      loc_F0008CF0
F0008CCC: 92043ff4                 add     %l0, -0xC, %o1
F0008CD0: 80a24013                 cmp     %o1, %l3
F0008CD4: 02800008                 be      loc_F0008CF4
F0008CD8: 90100013                 mov     %l3, %o0
F0008CDC: 92027ffc                 inc     -4, %o1! size_t
F0008CE0: d0024000                 ld      [%o1], %o0
F0008CE4: 80a22000                 cmp     %o0, 0
F0008CE8: 12bffffb                 bne     loc_F0008CD4
F0008CEC: 80a24013                 cmp     %o1, %l3
F0008CF0: 90100013                 mov     %l3, %o0! void *
F0008CF4: 40023059                 call    _bzero
F0008CF8: 92224013                 sub     %o1, %l3, %o1! size_t
F0008CFC: 108000be                 ba      loc_F0008FF4
F0008D00: ac100010                 mov     %l0, %l6
F0008D04: d0056004                 ld      [%l5+4], %o0! jumptable F0008A80 case 9
F0008D08: 80a22000                 cmp     %o0, 0
F0008D0C: 16800003                 bge     loc_F0008D18
F0008D10: 90200008                 neg     %o0
F0008D14: d0256004                 st      %o0, [%l5+4]
F0008D18: 400015ea                 call    _pfind
F0008D1C: d0056004                 ld      [%l5+4], %o0
F0008D20: a0920000                 orcc    %o0, %g0, %l0
F0008D24: 02bfff20                 be      loc_F00089A4
F0008D28: 113c04cf                 sethi   -0xFECC400, %o0
F0008D2C: d04c2013                 ldsb    [%l0+0x13], %o0
F0008D30: 80a22000                 cmp     %o0, 0
F0008D34: 32800007                 bne,a   loc_F0008D50
F0008D38: d054202c                 ldsh    [%l0+0x2C], %o0
F0008D3C: 9007bfa8                 add     %fp, var_58, %o0! void *
F0008D40: 40023046                 call    _bzero
F0008D44: 92102030                 mov     0x30, %o1 ! '0'
F0008D48: 10800022                 ba      loc_F0008DD0
F0008D4C: c027bfbc                 clr     [%fp+var_44]
F0008D50: d027bfa8                 st      %o0, [%fp+var_58]
F0008D54: d0542030                 ldsh    [%l0+0x30], %o0
F0008D58: d027bfac                 st      %o0, [%fp+var_54]
F0008D5C: d0542032                 ldsh    [%l0+0x32], %o0
F0008D60: d027bfb0                 st      %o0, [%fp+var_50]
F0008D64: d054202e                 ldsh    [%l0+0x2E], %o0
F0008D68: d027bfb4                 st      %o0, [%fp+var_4C]
F0008D6C: d0042028                 ld      [%l0+0x28], %o0
F0008D70: d027bfc0                 st      %o0, [%fp+var_40]
F0008D74: d0042068                 ld      [%l0+0x68], %o0
F0008D78: 80a22000                 cmp     %o0, 0
F0008D7C: 32800004                 bne,a   loc_F0008D8C
F0008D80: d2022038                 ld      [%o0+0x38], %o1
F0008D84: 10800012                 ba      loc_F0008DCC
F0008D88: 90102003                 mov     3, %o0
F0008D8C: d0026164                 ld      [%o1+0x164], %o0
F0008D90: 80a22000                 cmp     %o0, 0
F0008D94: 32800003                 bne,a   loc_F0008DA0
F0008D98: d0526168                 ldsh    [%o1+0x168], %o0
F0008D9C: 90103fff                 mov     -1, %o0
F0008DA0: d027bfb8                 st      %o0, [%fp+var_48]
F0008DA4: 90026008                 add     %o1, 8, %o0! void *
F0008DA8: 9207bfc4                 add     %fp, var_3C, %o1! void *
F0008DAC: 40022f59                 call    _bcopy
F0008DB0: 94102010                 mov     0x10, %o2! size_t
F0008DB4: c02fbfd4                 clrb    [%fp+var_2C]
F0008DB8: d0042028                 ld      [%l0+0x28], %o0
F0008DBC: 808a2400                 btst    0x400, %o0
F0008DC0: 12800003                 bne     loc_F0008DCC
F0008DC4: 90102002                 mov     2, %o0
F0008DC8: 90102001                 mov     1, %o0
F0008DCC: d027bfbc                 st      %o0, [%fp+var_44]
F0008DD0: a607bfa8                 add     %fp, var_58, %l3
F0008DD4: 10800088                 ba      loc_F0008FF4
F0008DD8: a8102030                 mov     0x30, %l4 ! '0'
F0008DDC: d0056004                 ld      [%l5+4], %o0! jumptable F0008A80 case 10
F0008DE0: 80a22000                 cmp     %o0, 0
F0008DE4: 1280007c                 bne     loc_F0008FD4
F0008DE8: 113c04cf                 sethi   -0xFECC400, %o0
F0008DEC: d005600c                 ld      [%l5+0xC], %o0
F0008DF0: 80a22001                 cmp     %o0, 1
F0008DF4: 12800078                 bne     loc_F0008FD4
F0008DF8: 113c04cf                 sethi   -0xFECC400, %o0
F0008DFC: 113c043f90122028         set     _mach_factor, %o0! void *
F0008E04: a007bfd8                 add     %fp, var_28, %l0
F0008E08: 92100010                 mov     %l0, %o1! void *
F0008E0C: 40022f41                 call    _bcopy
F0008E10: 9410200c                 mov     0xC, %o2
F0008E14: 901023e8                 mov     0x3E8, %o0
F0008E18: d027bfe4                 st      %o0, [%fp+var_1C]
F0008E1C: a6100010                 mov     %l0, %l3
F0008E20: 10800075                 ba      loc_F0008FF4
F0008E24: a8102010                 mov     0x10, %l4
F0008E28: d0056004                 ld      [%l5+4], %o0! jumptable F0008A80 case 11
F0008E2C: 80a22000                 cmp     %o0, 0
F0008E30: 12800069                 bne     loc_F0008FD4
F0008E34: 113c04cf                 sethi   -0xFECC400, %o0
F0008E38: d005600c                 ld      [%l5+0xC], %o0
F0008E3C: 80a22001                 cmp     %o0, 1
F0008E40: 12800065                 bne     loc_F0008FD4
F0008E44: 113c04cf                 sethi   -0xFECC400, %o0
F0008E48: c027bf94                 clr     [%fp+var_6C]
F0008E4C: 113c04d0                 sethi   %hi(_cp_time), %o0
F0008E50: 9607bf80                 add     %fp, var_80, %o3
F0008E54: a610000b                 mov     %o3, %l3
F0008E58: 173c04cf                 sethi   %hi(_cnt), %o3
F0008E5C: d802e3c0                 ld      [%o3+%lo(_cnt)], %o4
F0008E60: 90122040                 bset    %lo(_cp_time), %o0! void *
F0008E64: 9612e3c0                 bset    %lo(_cnt), %o3
F0008E68: da02e00c                 ld      [%o3+0xC], %o5! int
F0008E6C: 9207bf98                 add     %fp, var_68, %o1! void *
F0008E70: d827bf80                 st      %o4, [%fp+var_80]
F0008E74: d802e008                 ld      [%o3+8], %o4
F0008E78: 94102010                 mov     0x10, %o2! size_t
F0008E7C: da27bf84                 st      %o5, [%fp+var_7C]
F0008E80: d827bf88                 st      %o4, [%fp+var_78]
F0008E84: d802e004                 ld      [%o3+4], %o4! int
F0008E88: a8102028                 mov     0x28, %l4 ! '('
F0008E8C: 173c043e                 sethi   %hi(_hz), %o3
F0008E90: d602e3e0                 ld      [%o3+%lo(_hz)], %o3
F0008E94: d827bf8c                 st      %o4, [%fp+var_74]
F0008E98: 40022f1e                 call    _bcopy
F0008E9C: d627bf90                 st      %o3, [%fp+var_70]
F0008EA0: 10800056                 ba      loc_F0008FF8
F0008EA4: d0056010                 ld      [%l5+0x10], %o0
F0008EA8: d0056004                 ld      [%l5+4], %o0! jumptable F0008A80 case 12
F0008EAC: 80a22000                 cmp     %o0, 0
F0008EB0: 12800049                 bne     loc_F0008FD4
F0008EB4: 113c04cf                 sethi   -0xFECC400, %o0
F0008EB8: d005600c                 ld      [%l5+0xC], %o0
F0008EBC: 80a22001                 cmp     %o0, 1
F0008EC0: 12800045                 bne     loc_F0008FD4
F0008EC4: 113c04cf                 sethi   -0xFECC400, %o0
F0008EC8: 113c04d0                 sethi   %hi(_ifnet), %o0
F0008ECC: d40220b8                 ld      [%o0+%lo(_ifnet)], %o2
F0008ED0: 113c04d0                 sethi   %hi(_tk_nin), %o0
F0008ED4: d2022218                 ld      [%o0+%lo(_tk_nin)], %o1
F0008ED8: 96102000                 mov     0, %o3
F0008EDC: 113c04d0                 sethi   %hi(_tk_nout), %o0
F0008EE0: d0022220                 ld      [%o0+%lo(_tk_nout)], %o0
F0008EE4: d227bf68                 st      %o1, [%fp+var_98]
F0008EE8: d027bf6c                 st      %o0, [%fp+var_94]
F0008EEC: 113c04d0                 sethi   %hi(_dk_busy), %o0
F0008EF0: d2022050                 ld      [%o0+%lo(_dk_busy)], %o1
F0008EF4: 80a2a000                 cmp     %o2, 0
F0008EF8: 113c0429                 sethi   %hi(_dk_ndrive), %o0
F0008EFC: d00223d0                 ld      [%o0+%lo(_dk_ndrive)], %o0
F0008F00: d227bf70                 st      %o1, [%fp+var_90]
F0008F04: 02800006                 be      loc_F0008F1C
F0008F08: d027bf74                 st      %o0, [%fp+var_8C]
F0008F0C: d402a05c                 ld      [%o2+0x5C], %o2
F0008F10: 80a2a000                 cmp     %o2, 0
F0008F14: 12bffffe                 bne     loc_F0008F0C
F0008F18: 9602e001                 inc     %o3
F0008F1C: d627bf78                 st      %o3, [%fp+var_88]
F0008F20: a607bf68                 add     %fp, var_98, %l3
F0008F24: 10800034                 ba      loc_F0008FF4
F0008F28: a8102014                 mov     0x14, %l4
F0008F2C: 113c04d0                 sethi   %hi(_ifnet), %o0! jumptable F0008A80 case 14
F0008F30: e20220b8                 ld      [%o0+%lo(_ifnet)], %l1
F0008F34: 80a46000                 cmp     %l1, 0
F0008F38: 0280000a                 be      loc_F0008F60
F0008F3C: d0056004                 ld      [%l5+4], %o0
F0008F40: 80a22000                 cmp     %o0, 0
F0008F44: 02800007                 be      loc_F0008F60
F0008F48: 80a46000                 cmp     %l1, 0
F0008F4C: e204605c                 ld      [%l1+0x5C], %l1
F0008F50: 80a46000                 cmp     %l1, 0
F0008F54: 12bffffb                 bne     loc_F0008F40
F0008F58: 90023fff                 inc     -1, %o0
F0008F5C: 80a46000                 cmp     %l1, 0
F0008F60: 0280001c                 be      def_F0008A80! jumptable F0008A80 default case, cases 3,6-8,13
F0008F64: a007bf5c                 add     %fp, var_A4, %l0
F0008F68: d0046044                 ld      [%l1+0x44], %o0
F0008F6C: d027bf48                 st      %o0, [%fp+var_B8]
F0008F70: d0046048                 ld      [%l1+0x48], %o0! __dst
F0008F74: d027bf4c                 st      %o0, [%fp+var_B4]
F0008F78: d204604c                 ld      [%l1+0x4C], %o1
F0008F7C: 94102006                 mov     6, %o2! __n
F0008F80: d227bf50                 st      %o1, [%fp+var_B0]
F0008F84: d2046050                 ld      [%l1+0x50], %o1
F0008F88: a810201c                 mov     0x1C, %l4
F0008F8C: d227bf54                 st      %o1, [%fp+var_AC]
F0008F90: 9207bf48                 add     %fp, var_B8, %o1
F0008F94: d6046054                 ld      [%l1+0x54], %o3! int
F0008F98: a6100009                 mov     %o1, %l3
F0008F9C: d627bf58                 st      %o3, [%fp+var_A8]
F0008FA0: d2044000                 ld      [%l1], %o1! __src
F0008FA4: 7ffffa5e                 call    _strncpy
F0008FA8: 90100010                 mov     %l0, %o0! __s
F0008FAC: 7ffff923                 call    _strlen
F0008FB0: 90100010                 mov     %l0, %o0
F0008FB4: 9407bff8                 add     %fp, var_8, %o2
F0008FB8: d20c6009                 ldub    [%l1+9], %o1
F0008FBC: 94028008                 add     %o2, %o0, %o2! int
F0008FC0: 92026030                 inc     0x30, %o1 ! '0'
F0008FC4: d22abf64                 stb     %o1, [%o2-0x9C]
F0008FC8: 1080000b                 ba      loc_F0008FF4
F0008FCC: c02abf65                 clrb    [%o2-0x9B]
F0008FD0: 113c04cf                 sethi   -0xFECC400, %o0! jumptable F0008A80 default case, cases 3,6-8,13
F0008FD4: d20221dc                 ld      [%o0+0x1DC], %o1
F0008FD8: d0026030                 ld      [%o1+0x30], %o0
F0008FDC: 80a22000                 cmp     %o0, 0
F0008FE0: 1280003d                 bne     locret_F00090D4
F0008FE4: 01000000                 nop
F0008FE8: 90102016                 mov     0x16, %o0
F0008FEC: 1080003a                 ba      locret_F00090D4
F0008FF0: d02a6038                 stb     %o0, [%o1+0x38]
F0008FF4: d0056010                 ld      [%l5+0x10], %o0
F0008FF8: 80a50008                 cmp     %l4, %o0
F0008FFC: 38800002                 bgu,a   loc_F0009004
F0009000: a8100008                 mov     %o0, %l4
F0009004: 80a52000                 cmp     %l4, 0
F0009008: 02800016                 be      loc_F0009060
F000900C: 80a62000                 cmp     %i0, 0
F0009010: 0280000f                 be      loc_F000904C
F0009014: a007bf38                 add     %fp, var_C8, %l0
F0009018: d0056008                 ld      [%l5+8], %o0! int
F000901C: 92100010                 mov     %l0, %o1! int
F0009020: 40023c0e                 call    _copyin
F0009024: 94100014                 mov     %l4, %o2! size_t
F0009028: ae920000                 orcc    %o0, %g0, %l7
F000902C: 1280000e                 bne     loc_F0009064
F0009030: 80a4a000                 cmp     %l2, 0
F0009034: 90100010                 mov     %l0, %o0! void *
F0009038: 92100013                 mov     %l3, %o1! void *
F000903C: 40022eb5                 call    _bcopy
F0009040: 94100014                 mov     %l4, %o2! int
F0009044: 10800008                 ba      loc_F0009064
F0009048: 80a4a000                 cmp     %l2, 0
F000904C: 90100013                 mov     %l3, %o0! int
F0009050: d2056008                 ld      [%l5+8], %o1! int
F0009054: 40023c1e                 call    _copyout
F0009058: 94100014                 mov     %l4, %o2
F000905C: ae100008                 mov     %o0, %l7
F0009060: 80a4a000                 cmp     %l2, 0
F0009064: 02800006                 be      loc_F000907C
F0009068: 113c04d0                 sethi   %hi(_kernel_pageable_map), %o0
F000906C: d00220c0                 ld      [%o0+%lo(_kernel_pageable_map)], %o0
F0009070: 92100012                 mov     %l2, %o1
F0009074: 4001ebc9                 call    _kmem_free_wakeup
F0009078: 94258009                 sub     %l6, %o1, %o2
F000907C: 80a5e000                 cmp     %l7, 0
F0009080: 12bffe4d                 bne     loc_F00089B4
F0009084: 113c04cf                 sethi   -0xFECC400, %o0
F0009088: d2056008                 ld      [%l5+8], %o1
F000908C: d0056010                 ld      [%l5+0x10], %o0
F0009090: d405600c                 ld      [%l5+0xC], %o2
F0009094: 92024008                 add     %o1, %o0, %o1
F0009098: d2256008                 st      %o1, [%l5+8]
F000909C: 9402bfff                 inc     -1, %o2
F00090A0: d0056004                 ld      [%l5+4], %o0
F00090A4: d425600c                 st      %o2, [%l5+0xC]
F00090A8: 90022001                 inc     %o0
F00090AC: d0256004                 st      %o0, [%l5+4]
F00090B0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00090B4: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F00090B8: d0026030                 ld      [%o1+0x30], %o0
F00090BC: 90022001                 inc     %o0
F00090C0: d0226030                 st      %o0, [%o1+0x30]
F00090C4: d605600c                 ld      [%l5+0xC], %o3
F00090C8: 80a2e000                 cmp     %o3, 0
F00090CC: 34bffe56                 bg,a    loc_F0008A24
F00090D0: d0054000                 ld      [%l5], %o0
F00090D4: 81c7e008                 ret
F00090D8: 81e80000                 restore
