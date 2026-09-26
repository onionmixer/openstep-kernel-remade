F008099C: 9de3b7a0                 save    %sp, -0x860, %sp
F00809A0: d0062004                 ld      [%i0+4], %o0
F00809A4: 80a22028                 cmp     %o0, 0x28 ! '('
F00809A8: 12800011                 bne     loc_F00809EC
F00809AC: a0100019                 mov     %i1, %l0
F00809B0: d0060000                 ld      [%i0], %o0
F00809B4: 80a22000                 cmp     %o0, 0
F00809B8: 0680000d                 bl      loc_F00809EC
F00809BC: 133c0445                 sethi   %hi(dword_F01116DC), %o1
F00809C0: d0062018                 ld      [%i0+0x18], %o0
F00809C4: d20262dc                 ld      [%o1+%lo(dword_F01116DC)], %o1
F00809C8: 80a20009                 cmp     %o0, %o1
F00809CC: 12800009                 bne     loc_F00809F0
F00809D0: 90103ed0                 mov     -0x130, %o0
F00809D4: d0062020                 ld      [%i0+0x20], %o0
F00809D8: 133c0445                 sethi   %hi(dword_F01116E0), %o1
F00809DC: d20262e0                 ld      [%o1+%lo(dword_F01116E0)], %o1
F00809E0: 80a20009                 cmp     %o0, %o1
F00809E4: 02800005                 be      loc_F00809F8
F00809E8: 01000000                 nop
F00809EC: 90103ed0                 mov     -0x130, %o0
F00809F0: 10800073                 ba      locret_F0080BBC
F00809F4: d024201c                 st      %o0, [%l0+0x1C]
F00809F8: 7fff9bdf                 call    _convert_port_to_space
F00809FC: d0062008                 ld      [%i0+8], %o0
F0080A00: a4042048                 add     %l0, 0x48, %l2 ! 'H'
F0080A04: e427b80c                 st      %l2, [%fp+var_7F4]
F0080A08: 92102038                 mov     0x38, %o1 ! '8'
F0080A0C: d227b808                 st      %o1, [%fp+var_7F8]
F0080A10: d406201c                 ld      [%i0+0x1C], %o2
F0080A14: 80a2a038                 cmp     %o2, 0x38 ! '8'
F0080A18: 1a800003                 bcc     loc_F0080A24
F0080A1C: a2100008                 mov     %o0, %l1
F0080A20: d427b808                 st      %o2, [%fp+var_7F8]
F0080A24: a607b810                 add     %fp, var_7F0, %l3
F0080A28: e627b804                 st      %l3, [%fp+var_7FC]
F0080A2C: 9010202e                 mov     0x2E, %o0 ! '.'
F0080A30: f0062024                 ld      [%i0+0x24], %i0
F0080A34: 80a6202e                 cmp     %i0, 0x2E ! '.'
F0080A38: 1a800003                 bcc     loc_F0080A44
F0080A3C: d027b800                 st      %o0, [%fp+var_800]
F0080A40: f027b800                 st      %i0, [%fp+var_800]
F0080A44: 90100011                 mov     %l1, %o0! task
F0080A48: 92042024                 add     %l0, 0x24, %o1 ! '$'! space_info
F0080A4C: 9407b80c                 add     %fp, var_7F4, %o2! table_info
F0080A50: 9607b808                 add     %fp, var_7F8, %o3! table_infoCnt
F0080A54: 9807b804                 add     %fp, var_7FC, %o4! tree_info
F0080A58: 7fff79ad                 call    _mach_port_space_info
F0080A5C: 9a07b800                 add     %fp, var_800, %o5
F0080A60: d024201c                 st      %o0, [%l0+0x1C]
F0080A64: 7fff9c54                 call    _space_deallocate
F0080A68: 90100011                 mov     %l1, %o0
F0080A6C: d004201c                 ld      [%l0+0x1C], %o0
F0080A70: 80a22000                 cmp     %o0, 0
F0080A74: 12800052                 bne     locret_F0080BBC
F0080A78: 113c0445                 sethi   %hi(dword_F01116E4), %o0
F0080A7C: d00222e4                 ld      [%o0+%lo(dword_F01116E4)], %o0
F0080A80: 133c0445                 sethi   %hi(dword_F01116E8), %o1
F0080A84: d0242020                 st      %o0, [%l0+0x20]
F0080A88: d00262e8                 ld      [%o1+%lo(dword_F01116E8)], %o0
F0080A8C: d024203c                 st      %o0, [%l0+0x3C]
F0080A90: 921262e8                 bset    %lo(dword_F01116E8), %o1
F0080A94: d0026004                 ld      [%o1+4], %o0
F0080A98: a2102001                 mov     1, %l1
F0080A9C: d407b80c                 ld      [%fp+var_7F4], %o2
F0080AA0: d0242040                 st      %o0, [%l0+0x40]
F0080AA4: d0026008                 ld      [%o1+8], %o0
F0080AA8: 80a28012                 cmp     %o2, %l2
F0080AAC: 02800008                 be      loc_F0080ACC
F0080AB0: d0242044                 st      %o0, [%l0+0x44]
F0080AB4: d4242048                 st      %o2, [%l0+0x48]
F0080AB8: d004203c                 ld      [%l0+0x3C], %o0
F0080ABC: a2102000                 mov     0, %l1
F0080AC0: 900a3ff7                 and     %o0, -9, %o0
F0080AC4: 90122002                 bset    2, %o0
F0080AC8: d024203c                 st      %o0, [%l0+0x3C]
F0080ACC: d007b808                 ld      [%fp+var_7F8], %o0
F0080AD0: 94102004                 mov     4, %o2
F0080AD4: 932a2003                 sll     %o0, 3, %o1
F0080AD8: 92024008                 add     %o1, %o0, %o1
F0080ADC: d004203c                 ld      [%l0+0x3C], %o0
F0080AE0: 808a2008                 btst    8, %o0
F0080AE4: 02800003                 be      loc_F0080AF0
F0080AE8: d2242044                 st      %o1, [%l0+0x44]
F0080AEC: 952a6002                 sll     %o1, 2, %o2
F0080AF0: b002a054                 add     %o2, 0x54, %i0 ! 'T'
F0080AF4: 113c0445                 sethi   %hi(dword_F01116F4), %o0
F0080AF8: d20222f4                 ld      [%o0+%lo(dword_F01116F4)], %o1
F0080AFC: 9404000a                 add     %l0, %o2, %o2
F0080B00: d222a048                 st      %o1, [%o2+0x48]
F0080B04: 901222f4                 bset    %lo(dword_F01116F4), %o0
F0080B08: d2022004                 ld      [%o0+4], %o1
F0080B0C: a002b820                 add     %o2, -0x7E0, %l0
F0080B10: d807b804                 ld      [%fp+var_7FC], %o4
F0080B14: d222a04c                 st      %o1, [%o2+0x4C]
F0080B18: d0022008                 ld      [%o0+8], %o0
F0080B1C: 80a30013                 cmp     %o4, %l3
F0080B20: 02800009                 be      loc_F0080B44
F0080B24: d022a050                 st      %o0, [%o2+0x50]
F0080B28: d822a054                 st      %o4, [%o2+0x54]
F0080B2C: d002a048                 ld      [%o2+0x48], %o0
F0080B30: a2102000                 mov     0, %l1
F0080B34: 900a3ff7                 and     %o0, -9, %o0
F0080B38: 90122002                 bset    2, %o0
F0080B3C: 1080000b                 ba      loc_F0080B68
F0080B40: d022a048                 st      %o0, [%o2+0x48]
F0080B44: 9002a054                 add     %o2, 0x54, %o0 ! 'T'! __dst
F0080B48: d607b800                 ld      [%fp+var_800], %o3
F0080B4C: 9210000c                 mov     %o4, %o1! __src
F0080B50: 952ae001                 sll     %o3, 1, %o2
F0080B54: 9402800b                 add     %o2, %o3, %o2
F0080B58: 952aa002                 sll     %o2, 2, %o2
F0080B5C: 9422800b                 sub     %o2, %o3, %o2! __n
F0080B60: 7ffe19d0                 call    _memcpy
F0080B64: 952aa002                 sll     %o2, 2, %o2
F0080B68: d007b800                 ld      [%fp+var_800], %o0
F0080B6C: 932a2001                 sll     %o0, 1, %o1
F0080B70: 92024008                 add     %o1, %o0, %o1
F0080B74: 932a6002                 sll     %o1, 2, %o1
F0080B78: 92224008                 sub     %o1, %o0, %o1
F0080B7C: d0042828                 ld      [%l0+0x828], %o0
F0080B80: 808a2008                 btst    8, %o0
F0080B84: 02800005                 be      loc_F0080B98
F0080B88: d2242830                 st      %o1, [%l0+0x830]
F0080B8C: 912a6002                 sll     %o1, 2, %o0
F0080B90: 10800003                 ba      loc_F0080B9C
F0080B94: b0060008                 add     %i0, %o0, %i0
F0080B98: b0062004                 inc     4, %i0
F0080B9C: 80a46000                 cmp     %l1, 0
F0080BA0: 12800006                 bne     loc_F0080BB8
F0080BA4: a0100019                 mov     %i1, %l0
F0080BA8: d0040000                 ld      [%l0], %o0
F0080BAC: 13200000                 sethi   0x80000000, %o1
F0080BB0: 90120009                 bset    %o1, %o0
F0080BB4: d0240000                 st      %o0, [%l0]
F0080BB8: f0242004                 st      %i0, [%l0+4]
F0080BBC: 81c7e008                 ret
F0080BC0: 81e80000                 restore
