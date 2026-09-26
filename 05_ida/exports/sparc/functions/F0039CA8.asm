F0039CA8: 9de3bf90                 save    %sp, -0x70, %sp! int
F0039CAC: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F0039CB0: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F0039CB4: 7fff572e                 call    _suser
F0039CB8: e6022024                 ld      [%o0+0x24], %l3
F0039CBC: 80a22000                 cmp     %o0, 0
F0039CC0: 12800006                 bne     loc_F0039CD8
F0039CC4: 92102000                 mov     0, %o1
F0039CC8: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F0039CCC: 90102001                 mov     1, %o0
F0039CD0: 1080008d                 ba      locret_F0039F04
F0039CD4: d02a6038                 stb     %o0, [%o1+0x38]
F0039CD8: 94102001                 mov     1, %o2
F0039CDC: 96102000                 mov     0, %o3! int
F0039CE0: d004c000                 ld      [%l3], %o0
F0039CE4: 7fffb338                 call    _lookupname
F0039CE8: 9807bff4                 add     %fp, var_C, %o4! int
F0039CEC: d204a1dc                 ld      [%l2+0x1DC], %o1
F0039CF0: d02a6038                 stb     %o0, [%o1+0x38]
F0039CF4: d004a1dc                 ld      [%l2+0x1DC], %o0
F0039CF8: d04a2038                 ldsb    [%o0+0x38], %o0
F0039CFC: 80a22000                 cmp     %o0, 0
F0039D00: 12800081                 bne     locret_F0039F04
F0039D04: d007bff4                 ld      [%fp+var_C], %o0
F0039D08: d402201c                 ld      [%o0+0x1C], %o2
F0039D0C: d402a064                 ld      [%o2+0x64], %o2
F0039D10: 9fc28000                 call    %o2
F0039D14: 9207bff0                 add     %fp, var_10, %o1
F0039D18: d204a1dc                 ld      [%l2+0x1DC], %o1
F0039D1C: d02a6038                 stb     %o0, [%o1+0x38]
F0039D20: d007bff4                 ld      [%fp+var_C], %o0
F0039D24: 7fffbb90                 call    _vn_rele
F0039D28: e0022024                 ld      [%o0+0x24], %l0
F0039D2C: d004a1dc                 ld      [%l2+0x1DC], %o0
F0039D30: d04a2038                 ldsb    [%o0+0x38], %o0
F0039D34: 80a22000                 cmp     %o0, 0
F0039D38: 12800073                 bne     locret_F0039F04
F0039D3C: 01000000                 nop
F0039D40: d004e004                 ld      [%l3+4], %o0
F0039D44: 80a22000                 cmp     %o0, 0
F0039D48: 1280000a                 bne     loc_F0039D70
F0039D4C: d207bff0                 ld      [%fp+var_10], %o1
F0039D50: 4000006f                 call    _unexport
F0039D54: 90042014                 add     %l0, 0x14, %o0
F0039D58: d204a1dc                 ld      [%l2+0x1DC], %o1
F0039D5C: d02a6038                 stb     %o0, [%o1+0x38]
F0039D60: d007bff0                 ld      [%fp+var_10], %o0
F0039D64: d2120000                 lduh    [%o0], %o1
F0039D68: 10800065                 ba      loc_F0039EFC
F0039D6C: 92026002                 inc     2, %o1
F0039D70: 4000b8c0                 call    _kalloc
F0039D74: 90102030                 mov     0x30, %o0 ! '0'
F0039D78: d2042014                 ld      [%l0+0x14], %o1
F0039D7C: a2100008                 mov     %o0, %l1
F0039D80: d007bff0                 ld      [%fp+var_10], %o0
F0039D84: d2246020                 st      %o1, [%l1+0x20]
F0039D88: d4042018                 ld      [%l0+0x18], %o2! int
F0039D8C: 92100011                 mov     %l1, %o1! int
F0039D90: d4246024                 st      %o2, [%l1+0x24]
F0039D94: d0246028                 st      %o0, [%l1+0x28]
F0039D98: d004e004                 ld      [%l3+4], %o0! int
F0039D9C: 400178af                 call    _copyin
F0039DA0: 94102020                 mov     0x20, %o2 ! ' '
F0039DA4: d204a1dc                 ld      [%l2+0x1DC], %o1
F0039DA8: d02a6038                 stb     %o0, [%o1+0x38]
F0039DAC: d204a1dc                 ld      [%l2+0x1DC], %o1
F0039DB0: d04a6038                 ldsb    [%o1+0x38], %o0
F0039DB4: 80a22000                 cmp     %o0, 0
F0039DB8: 3280004c                 bne,a   loc_F0039EE8
F0039DBC: d0046028                 ld      [%l1+0x28], %o0
F0039DC0: d0044000                 ld      [%l1], %o0
F0039DC4: 808a3ffc                 btst    -4, %o0
F0039DC8: 02800005                 be      loc_F0039DDC
F0039DCC: 808a2002                 btst    2, %o0
F0039DD0: 90102016                 mov     0x16, %o0
F0039DD4: 10800044                 ba      loc_F0039EE4
F0039DD8: d02a6038                 stb     %o0, [%o1+0x38]
F0039DDC: 2280000c                 be,a    loc_F0039E0C
F0039DE0: d0046008                 ld      [%l1+8], %o0
F0039DE4: 4000017e                 call    _loadaddrs
F0039DE8: 90046018                 add     %l1, 0x18, %o0
F0039DEC: d204a1dc                 ld      [%l2+0x1DC], %o1
F0039DF0: d02a6038                 stb     %o0, [%o1+0x38]
F0039DF4: d004a1dc                 ld      [%l2+0x1DC], %o0
F0039DF8: d04a2038                 ldsb    [%o0+0x38], %o0
F0039DFC: 80a22000                 cmp     %o0, 0
F0039E00: 3280003a                 bne,a   loc_F0039EE8
F0039E04: d0046028                 ld      [%l1+0x28], %o0
F0039E08: d0046008                 ld      [%l1+8], %o0
F0039E0C: 80a22001                 cmp     %o0, 1
F0039E10: 12800006                 bne     loc_F0039E28
F0039E14: d204a1dc                 ld      [%l2+0x1DC], %o1
F0039E18: 40000171                 call    _loadaddrs
F0039E1C: 9004600c                 add     %l1, 0xC, %o0
F0039E20: 10800003                 ba      loc_F0039E2C
F0039E24: d204a1dc                 ld      [%l2+0x1DC], %o1
F0039E28: 90102016                 mov     0x16, %o0
F0039E2C: d02a6038                 stb     %o0, [%o1+0x38]
F0039E30: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0039E34: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0039E38: d04a2038                 ldsb    [%o0+0x38], %o0
F0039E3C: 80a22000                 cmp     %o0, 0
F0039E40: 3280002a                 bne,a   loc_F0039EE8
F0039E44: d0046028                 ld      [%l1+0x28], %o0
F0039E48: 113c04ea                 sethi   %hi(_exported), %o0
F0039E4C: d20220c8                 ld      [%o0+%lo(_exported)], %o1
F0039E50: 80a26000                 cmp     %o1, 0
F0039E54: 02800021                 be      loc_F0039ED8
F0039E58: a01220c8                 or      %o0, %lo(_exported), %l0
F0039E5C: 92046020                 add     %l1, 0x20, %o1 ! ' '! void *
F0039E60: d0040000                 ld      [%l0], %o0! void *
F0039E64: 94102008                 mov     8, %o2! size_t
F0039E68: 7fff303d                 call    _bcmp
F0039E6C: 90022020                 inc     0x20, %o0 ! ' '
F0039E70: 80a22000                 cmp     %o0, 0
F0039E74: 12800014                 bne     loc_F0039EC4
F0039E78: d0040000                 ld      [%l0], %o0
F0039E7C: d2046028                 ld      [%l1+0x28], %o1! void *
F0039E80: d6022028                 ld      [%o0+0x28], %o3
F0039E84: d412c000                 lduh    [%o3], %o2! size_t
F0039E88: d0124000                 lduh    [%o1], %o0
F0039E8C: 80a28008                 cmp     %o2, %o0
F0039E90: 3280000d                 bne,a   loc_F0039EC4
F0039E94: d0040000                 ld      [%l0], %o0
F0039E98: 9002e002                 add     %o3, 2, %o0! void *
F0039E9C: 7fff3030                 call    _bcmp
F0039EA0: 92026002                 inc     2, %o1
F0039EA4: 80a22000                 cmp     %o0, 0
F0039EA8: 12800007                 bne     loc_F0039EC4
F0039EAC: d0040000                 ld      [%l0], %o0
F0039EB0: d202202c                 ld      [%o0+0x2C], %o1
F0039EB4: 40000167                 call    _exportfree
F0039EB8: d2240000                 st      %o1, [%l0]
F0039EBC: 10800004                 ba      loc_F0039ECC
F0039EC0: d0040000                 ld      [%l0], %o0
F0039EC4: a002202c                 add     %o0, 0x2C, %l0 ! ','
F0039EC8: d0040000                 ld      [%l0], %o0
F0039ECC: 80a22000                 cmp     %o0, 0
F0039ED0: 12bfffe4                 bne     loc_F0039E60
F0039ED4: 92046020                 add     %l1, 0x20, %o1 ! ' '
F0039ED8: c024602c                 clr     [%l1+0x2C]
F0039EDC: 1080000a                 ba      locret_F0039F04
F0039EE0: e2240000                 st      %l1, [%l0]
F0039EE4: d0046028                 ld      [%l1+0x28], %o0
F0039EE8: d2120000                 lduh    [%o0], %o1
F0039EEC: 4000b8ad                 call    _kfree
F0039EF0: 92026002                 inc     2, %o1
F0039EF4: 90100011                 mov     %l1, %o0
F0039EF8: 92102030                 mov     0x30, %o1 ! '0'
F0039EFC: 4000b8a9                 call    _kfree
F0039F00: 01000000                 nop
F0039F04: 81c7e008                 ret
F0039F08: 81e80000                 restore
