F00E5D7C: 9de3bf90                 save    %sp, -0x70, %sp
F00E5D80: 80a6200f                 cmp     %i0, 0xF
F00E5D84: 133c04bb                 sethi   %hi(_sparcfbs), %o1
F00E5D88: e2166004                 lduh    [%i1+4], %l1
F00E5D8C: 912e2004                 sll     %i0, 4, %o0
F00E5D90: e4166006                 lduh    [%i1+6], %l2
F00E5D94: 90020018                 add     %o0, %i0, %o0
F00E5D98: ec164000                 lduh    [%i1], %l6
F00E5D9C: 912a2002                 sll     %o0, 2, %o0
F00E5DA0: d2026364                 ld      [%o1+%lo(_sparcfbs)], %o1
F00E5DA4: 90022008                 inc     8, %o0
F00E5DA8: ea166002                 lduh    [%i1+2], %l5
F00E5DAC: 18800006                 bgu     loc_F00E5DC4
F00E5DB0: a6024008                 add     %o1, %o0, %l3
F00E5DB4: d0024008                 ld      [%o1+%o0], %o0
F00E5DB8: 80a22000                 cmp     %o0, 0
F00E5DBC: 12800004                 bne     loc_F00E5DCC
F00E5DC0: 01000000                 nop
F00E5DC4: 10800096                 ba      locret_F00E601C
F00E5DC8: b0103d40                 mov     -0x2C0, %i0
F00E5DCC: d204e034                 ld      [%l3+0x34], %o1
F00E5DD0: 7ffc81cc                 call    _umul
F00E5DD4: 90100011                 mov     %l1, %o0
F00E5DD8: 7ffc81ca                 call    _umul
F00E5DDC: 92100012                 mov     %l2, %o1
F00E5DE0: 133c04bb                 sethi   %hi(dword_F012EF6C), %o1
F00E5DE4: 96102000                 mov     0, %o3
F00E5DE8: d202636c                 ld      [%o1+%lo(dword_F012EF6C)], %o1
F00E5DEC: a0022004                 add     %o0, 4, %l0
F00E5DF0: 80a26000                 cmp     %o1, 0
F00E5DF4: 0280000c                 be      loc_F00E5E24
F00E5DF8: d227bff4                 st      %o1, [%fp+var_C]
F00E5DFC: d207bff4                 ld      [%fp+var_C], %o1
F00E5E00: d0026018                 ld      [%o1+0x18], %o0
F00E5E04: 80a20010                 cmp     %o0, %l0
F00E5E08: 16800008                 bge     loc_F00E5E28
F00E5E0C: d407bff4                 ld      [%fp+var_C], %o2
F00E5E10: 96100009                 mov     %o1, %o3
F00E5E14: d0026008                 ld      [%o1+8], %o0
F00E5E18: 80a22000                 cmp     %o0, 0
F00E5E1C: 12bffff8                 bne     loc_F00E5DFC
F00E5E20: d027bff4                 st      %o0, [%fp+var_C]
F00E5E24: d407bff4                 ld      [%fp+var_C], %o2
F00E5E28: 80a2a000                 cmp     %o2, 0
F00E5E2C: 0280000e                 be      loc_F00E5E64
F00E5E30: 133c04bb                 sethi   %hi(dword_F012EF74), %o1
F00E5E34: d0026374                 ld      [%o1+%lo(dword_F012EF74)], %o0
F00E5E38: 80a2e000                 cmp     %o3, 0
F00E5E3C: 90023fff                 inc     -1, %o0
F00E5E40: 02800005                 be      loc_F00E5E54
F00E5E44: d0226374                 st      %o0, [%o1+%lo(dword_F012EF74)]
F00E5E48: d002a008                 ld      [%o2+8], %o0
F00E5E4C: 10800018                 ba      loc_F00E5EAC
F00E5E50: d022e008                 st      %o0, [%o3+8]
F00E5E54: d202a008                 ld      [%o2+8], %o1
F00E5E58: 113c04bb                 sethi   %hi(dword_F012EF6C), %o0
F00E5E5C: 10800014                 ba      loc_F00E5EAC
F00E5E60: d222236c                 st      %o1, [%o0+%lo(dword_F012EF6C)]
F00E5E64: 133c04bb                 sethi   %hi(dword_F012EF78), %o1
F00E5E68: d0026378                 ld      [%o1+%lo(dword_F012EF78)], %o0
F00E5E6C: 80a40008                 cmp     %l0, %o0
F00E5E70: 0480000b                 ble     loc_F00E5E9C
F00E5E74: 113c04d1                 sethi   %hi(_kernel_map), %o0
F00E5E78: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F00E5E7C: 9207bff4                 add     %fp, var_C, %o1
F00E5E80: 7ffe7661                 call    _kmem_alloc_wired
F00E5E84: 9404201c                 add     %l0, 0x1C, %o2
F00E5E88: 80a22000                 cmp     %o0, 0
F00E5E8C: 02800009                 be      loc_F00E5EB0
F00E5E90: 193c04bb                 sethi   -0xFED1400, %o4
F00E5E94: 10800062                 ba      locret_F00E601C
F00E5E98: b0103fff                 mov     -1, %i0
F00E5E9C: 113c04cc901220e4         set     unk_F01330E4, %o0
F00E5EA4: d027bff4                 st      %o0, [%fp+var_C]
F00E5EA8: c0226378                 clr     [%o1+0x378]
F00E5EAC: 193c04bb                 sethi   -0xFED1400, %o4
F00E5EB0: d4032370                 ld      [%o4+0x370], %o2
F00E5EB4: d207bff4                 ld      [%fp+var_C], %o1
F00E5EB8: 173c04bb                 sethi   %hi(dword_F012EF68), %o3
F00E5EBC: d002e368                 ld      [%o3+%lo(dword_F012EF68)], %o0
F00E5EC0: 9402a001                 inc     %o2
F00E5EC4: d4224000                 st      %o2, [%o1]
F00E5EC8: e0226018                 st      %l0, [%o1+0x18]
F00E5ECC: f0226004                 st      %i0, [%o1+4]
F00E5ED0: d0226008                 st      %o0, [%o1+8]
F00E5ED4: d004e034                 ld      [%l3+0x34], %o0
F00E5ED8: d022600c                 st      %o0, [%o1+0xC]
F00E5EDC: d0164000                 lduh    [%i1], %o0
F00E5EE0: d0326010                 sth     %o0, [%o1+0x10]
F00E5EE4: d0166002                 lduh    [%i1+2], %o0
F00E5EE8: d0326012                 sth     %o0, [%o1+0x12]
F00E5EEC: d0166004                 lduh    [%i1+4], %o0
F00E5EF0: d0326014                 sth     %o0, [%o1+0x14]
F00E5EF4: d0166006                 lduh    [%i1+6], %o0
F00E5EF8: d0326016                 sth     %o0, [%o1+0x16]
F00E5EFC: d004e038                 ld      [%l3+0x38], %o0! int
F00E5F00: d222e368                 st      %o1, [%o3+0x368]
F00E5F04: d204e034                 ld      [%l3+0x34], %o1! int
F00E5F08: 7ffc81c0                 call    _div
F00E5F0C: d4232370                 st      %o2, [%o4+0x370]
F00E5F10: d204e034                 ld      [%l3+0x34], %o1
F00E5F14: 80a26001                 cmp     %o1, 1
F00E5F18: 02800007                 be      loc_F00E5F34
F00E5F1C: a8220011                 sub     %o0, %l1, %l4
F00E5F20: 80a26004                 cmp     %o1, 4
F00E5F24: 02800021                 be      loc_F00E5FA8
F00E5F28: d407bff4                 ld      [%fp+var_C], %o2
F00E5F2C: 1080003b                 ba      loc_F00E6018
F00E5F30: d007bff4                 ld      [%fp+var_C], %o0
F00E5F34: d407bff4                 ld      [%fp+var_C], %o2
F00E5F38: 90100015                 mov     %l5, %o0
F00E5F3C: d204e038                 ld      [%l3+0x38], %o1
F00E5F40: 7ffc8170                 call    _umul
F00E5F44: b002a01c                 add     %o2, 0x1C, %i0
F00E5F48: 94100008                 mov     %o0, %o2
F00E5F4C: e004e014                 ld      [%l3+0x14], %l0
F00E5F50: 90100016                 mov     %l6, %o0
F00E5F54: d204e034                 ld      [%l3+0x34], %o1
F00E5F58: 7ffc816a                 call    _umul
F00E5F5C: a004000a                 add     %l0, %o2, %l0
F00E5F60: a484bfff                 inccc   -1, %l2
F00E5F64: 0c80002c                 bneg    loc_F00E6014
F00E5F68: a0040008                 add     %l0, %o0, %l0
F00E5F6C: e2166004                 lduh    [%i1+4], %l1
F00E5F70: a2847fff                 inccc   -1, %l1
F00E5F74: 2c800009                 bneg,a  loc_F00E5F98
F00E5F78: a484bfff                 inccc   -1, %l2
F00E5F7C: d00c0000                 ldub    [%l0], %o0
F00E5F80: a2847fff                 inccc   -1, %l1
F00E5F84: d02e0000                 stb     %o0, [%i0]
F00E5F88: a0042001                 inc     %l0
F00E5F8C: 1cbffffc                 bpos    loc_F00E5F7C
F00E5F90: b0062001                 inc     %i0
F00E5F94: a484bfff                 inccc   -1, %l2
F00E5F98: 1cbffff5                 bpos    loc_F00E5F6C
F00E5F9C: a0040014                 add     %l0, %l4, %l0
F00E5FA0: 1080001e                 ba      loc_F00E6018
F00E5FA4: d007bff4                 ld      [%fp+var_C], %o0
F00E5FA8: 90100015                 mov     %l5, %o0
F00E5FAC: d204e038                 ld      [%l3+0x38], %o1
F00E5FB0: 7ffc8154                 call    _umul
F00E5FB4: b002a01c                 add     %o2, 0x1C, %i0
F00E5FB8: 94100008                 mov     %o0, %o2
F00E5FBC: e004e018                 ld      [%l3+0x18], %l0
F00E5FC0: 90100016                 mov     %l6, %o0
F00E5FC4: d204e034                 ld      [%l3+0x34], %o1
F00E5FC8: 7ffc814e                 call    _umul
F00E5FCC: a004000a                 add     %l0, %o2, %l0
F00E5FD0: a484bfff                 inccc   -1, %l2
F00E5FD4: 0c800010                 bneg    loc_F00E6014
F00E5FD8: a0040008                 add     %l0, %o0, %l0
F00E5FDC: 932d2002                 sll     %l4, 2, %o1
F00E5FE0: e2166004                 lduh    [%i1+4], %l1
F00E5FE4: a2847fff                 inccc   -1, %l1
F00E5FE8: 2c800009                 bneg,a  loc_F00E600C
F00E5FEC: a484bfff                 inccc   -1, %l2
F00E5FF0: d0040000                 ld      [%l0], %o0
F00E5FF4: a2847fff                 inccc   -1, %l1
F00E5FF8: d0260000                 st      %o0, [%i0]
F00E5FFC: a0042004                 inc     4, %l0
F00E6000: 1cbffffc                 bpos    loc_F00E5FF0
F00E6004: b0062004                 inc     4, %i0
F00E6008: a484bfff                 inccc   -1, %l2
F00E600C: 1cbffff5                 bpos    loc_F00E5FE0
F00E6010: a0040009                 add     %l0, %o1, %l0
F00E6014: d007bff4                 ld      [%fp+var_C], %o0
F00E6018: f0020000                 ld      [%o0], %i0
F00E601C: 81c7e008                 ret
F00E6020: 81e80000                 restore
