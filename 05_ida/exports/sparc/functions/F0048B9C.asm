F0048B9C: 9de3bf98                 save    %sp, -0x68, %sp
F0048BA0: a4100018                 mov     %i0, %l2
F0048BA4: e204a050                 ld      [%l2+0x50], %l1
F0048BA8: d2046030                 ld      [%l1+0x30], %o1
F0048BAC: 80a6c009                 cmp     %i3, %o1
F0048BB0: 1880000d                 bgu     loc_F0048BE4
F0048BB4: 113c0439                 sethi   -0xFEF1C00, %o0
F0048BB8: d004604c                 ld      [%l1+0x4C], %o0
F0048BBC: 90380008                 xnor    %g0, %o0, %o0
F0048BC0: 808ec008                 btst    %o0, %i3
F0048BC4: 32800008                 bne,a   loc_F0048BE4
F0048BC8: 113c0439                 sethi   -0xFEF1C00, %o0
F0048BCC: 80a70009                 cmp     %i4, %o1
F0048BD0: 18800004                 bgu     loc_F0048BE0
F0048BD4: 808f0008                 btst    %o0, %i4
F0048BD8: 2280000e                 be,a    loc_F0048C10
F0048BDC: 113c04cf                 sethi   -0xFECC400, %o0
F0048BE0: 113c0439                 sethi   -0xFEF1C00, %o0
F0048BE4: 901221c8                 bset    0x1C8, %o0! char *
F0048BE8: 9610001b                 mov     %i3, %o3
F0048BEC: d254a046                 ldsh    [%l2+0x46], %o1
F0048BF0: 9810001c                 mov     %i4, %o4
F0048BF4: d4046030                 ld      [%l1+0x30], %o2
F0048BF8: 7fff2e98                 call    _printf
F0048BFC: 9a0460d4                 add     %l1, 0xD4, %o5
F0048C00: 113c0439                 sethi   %hi(aRealloccgBadSi), %o0! "realloccg: bad size"
F0048C04: 7fff315b                 call    _panic
F0048C08: 90122208                 bset    %lo(aRealloccgBadSi), %o0! "realloccg: bad size"
F0048C0C: 113c04cf                 sethi   -0xFECC400, %o0
F0048C10: d00221d8                 ld      [%o0+0x1D8], %o0
F0048C14: d002201c                 ld      [%o0+0x1C], %o0
F0048C18: d0522002                 ldsh    [%o0+2], %o0
F0048C1C: 80a22000                 cmp     %o0, 0
F0048C20: 02800010                 be      loc_F0048C60
F0048C24: 80a66000                 cmp     %i1, 0
F0048C28: d204603c                 ld      [%l1+0x3C], %o1! int
F0048C2C: e00460c4                 ld      [%l1+0xC4], %l0
F0048C30: d0046028                 ld      [%l1+0x28], %o0! int
F0048C34: d6046060                 ld      [%l1+0x60], %o3
F0048C38: d40460cc                 ld      [%l1+0xCC], %o2
F0048C3C: a12c000b                 sll     %l0, %o3, %l0
F0048C40: 7ffef630                 call    _umul
F0048C44: a004000a                 add     %l0, %o2, %l0
F0048C48: 7ffef670                 call    _div
F0048C4C: 92102064                 mov     0x64, %o1 ! 'd'
F0048C50: a0240008                 sub     %l0, %o0, %l0
F0048C54: 80a42000                 cmp     %l0, 0
F0048C58: 048000ba                 ble     loc_F0048F40
F0048C5C: 80a66000                 cmp     %i1, 0
F0048C60: 3280000d                 bne,a   loc_F0048C94
F0048C64: d20460bc                 ld      [%l1+0xBC], %o1
F0048C68: 113c043990122220         set     aDev0xXBsizeDBp, %o0! "dev = 0x%x, bsize = %d, bprev = %d, fs "...
F0048C70: d254a046                 ldsh    [%l2+0x46], %o1
F0048C74: 96102000                 mov     0, %o3
F0048C78: d4046030                 ld      [%l1+0x30], %o2
F0048C7C: 7fff2e77                 call    _printf
F0048C80: 980460d4                 add     %l1, 0xD4, %o4
F0048C84: 113c0439                 sethi   %hi(aRealloccgBadBp), %o0! "realloccg: bad bprev"
F0048C88: 7fff313a                 call    _panic
F0048C8C: 90122250                 bset    %lo(aRealloccgBadBp), %o0! "realloccg: bad bprev"
F0048C90: d20460bc                 ld      [%l1+0xBC], %o1! int
F0048C94: 7ffef65d                 call    _div
F0048C98: 90100019                 mov     %i1, %o0
F0048C9C: a0100008                 mov     %o0, %l0
F0048CA0: 90100012                 mov     %l2, %o0
F0048CA4: 92100010                 mov     %l0, %o1
F0048CA8: 94100019                 mov     %i1, %o2
F0048CAC: 9610001b                 mov     %i3, %o3
F0048CB0: 400001f3                 call    _fragextend
F0048CB4: 9810001c                 mov     %i4, %o4
F0048CB8: a6920000                 orcc    %o0, %g0, %l3
F0048CBC: 22800020                 be,a    loc_F0048D3C
F0048CC0: d0046024                 ld      [%l1+0x24], %o0
F0048CC4: d2046064                 ld      [%l1+0x64], %o1
F0048CC8: 9410001b                 mov     %i3, %o2
F0048CCC: d004a040                 ld      [%l2+0x40], %o0
F0048CD0: 7fff6e14                 call    _bread
F0048CD4: 932cc009                 sll     %l3, %o1, %o1
F0048CD8: b0100008                 mov     %o0, %i0
F0048CDC: d0060000                 ld      [%i0], %o0
F0048CE0: 808a2004                 btst    4, %o0
F0048CE4: 12800093                 bne     loc_F0048F30
F0048CE8: 90100018                 mov     %i0, %o0
F0048CEC: 7fff7000                 call    _brealloc
F0048CF0: 9210001c                 mov     %i4, %o1
F0048CF4: 80a22000                 cmp     %o0, 0
F0048CF8: 22bffff4                 be,a    loc_F0048CC8
F0048CFC: d2046064                 ld      [%l1+0x64], %o1
F0048D00: a027001b                 sub     %i4, %i3, %l0
F0048D04: d4060000                 ld      [%i0], %o2
F0048D08: 92100010                 mov     %l0, %o1! size_t
F0048D0C: d0062020                 ld      [%i0+0x20], %o0! void *
F0048D10: 9412a002                 bset    2, %o2
F0048D14: d4260000                 st      %o2, [%i0]
F0048D18: 40013050                 call    _bzero
F0048D1C: 9002001b                 add     %o0, %i3, %o0
F0048D20: d004a028                 ld      [%l2+0x28], %o0
F0048D24: d2022080                 ld      [%o0+0x80], %o1
F0048D28: 9fc24000                 call    %o1
F0048D2C: 9004a00c                 add     %l2, 0xC, %o0
F0048D30: 92100008                 mov     %o0, %o1
F0048D34: 10800076                 ba      loc_F0048F0C
F0048D38: 90100010                 mov     %l0, %o0
F0048D3C: 80a68008                 cmp     %i2, %o0
F0048D40: 36800002                 bge,a   loc_F0048D48
F0048D44: b4102000                 mov     0, %i2
F0048D48: d0046080                 ld      [%l1+0x80], %o0
F0048D4C: 80a22000                 cmp     %o0, 0
F0048D50: 02800017                 be      loc_F0048DAC
F0048D54: 80a22001                 cmp     %o0, 1
F0048D58: 32800027                 bne,a   loc_F0048DF4
F0048D5C: 90102001                 mov     1, %o0
F0048D60: d204603c                 ld      [%l1+0x3C], %o1! int
F0048D64: 80a26004                 cmp     %o1, 4
F0048D68: 04800025                 ble     loc_F0048DFC
F0048D6C: a810001c                 mov     %i4, %l4
F0048D70: 7ffef5e4                 call    _umul
F0048D74: d0046028                 ld      [%l1+0x28], %o0! int
F0048D78: 7ffef624                 call    _div
F0048D7C: 921020c8                 mov     0xC8, %o1
F0048D80: d20460cc                 ld      [%l1+0xCC], %o1
F0048D84: 80a24008                 cmp     %o1, %o0
F0048D88: 1480001e                 bg      loc_F0048E00
F0048D8C: 90100012                 mov     %l2, %o0
F0048D90: 90102005                 mov     5, %o0! __x
F0048D94: 133c043992126268         set     aSOptimizationC, %o1! "%s: optimization changed from SPACE to "...
F0048D9C: 7fff2e86                 call    _log
F0048DA0: 940460d4                 add     %l1, 0xD4, %o2
F0048DA4: 10800016                 ba      loc_F0048DFC
F0048DA8: c0246080                 clr     [%l1+0x80]
F0048DAC: d204603c                 ld      [%l1+0x3C], %o1
F0048DB0: d0046028                 ld      [%l1+0x28], %o0! int
F0048DB4: 7ffef5d3                 call    _umul
F0048DB8: 92027ffe                 inc     -2, %o1! int
F0048DBC: 7ffef613                 call    _div
F0048DC0: 92102064                 mov     0x64, %o1 ! 'd'
F0048DC4: d20460cc                 ld      [%l1+0xCC], %o1
F0048DC8: 80a24008                 cmp     %o1, %o0
F0048DCC: 0680000c                 bl      loc_F0048DFC
F0048DD0: e8046030                 ld      [%l1+0x30], %l4
F0048DD4: 90102005                 mov     5, %o0! __x
F0048DD8: 133c043992126298         set     aSOptimizationC_0, %o1! "%s: optimization changed from TIME to S"...
F0048DE0: 7fff2e75                 call    _log
F0048DE4: 940460d4                 add     %l1, 0xD4, %o2
F0048DE8: 90102001                 mov     1, %o0
F0048DEC: 10800004                 ba      loc_F0048DFC
F0048DF0: d0246080                 st      %o0, [%l1+0x80]
F0048DF4: d0246080                 st      %o0, [%l1+0x80]
F0048DF8: a810001c                 mov     %i4, %l4
F0048DFC: 90100012                 mov     %l2, %o0
F0048E00: 92100010                 mov     %l0, %o1
F0048E04: 9410001a                 mov     %i2, %o2
F0048E08: 96100014                 mov     %l4, %o3
F0048E0C: 193c0125                 sethi   %hi(_alloccg), %o4
F0048E10: 4000015f                 call    _hashalloc
F0048E14: 98132348                 bset    %lo(_alloccg), %o4
F0048E18: a6920000                 orcc    %o0, %g0, %l3
F0048E1C: 04800049                 ble     loc_F0048F40
F0048E20: 9410001b                 mov     %i3, %o2
F0048E24: d2046064                 ld      [%l1+0x64], %o1
F0048E28: d004a040                 ld      [%l2+0x40], %o0
F0048E2C: 7fff6dbd                 call    _bread
F0048E30: 932e4009                 sll     %i1, %o1, %o1
F0048E34: a0100008                 mov     %o0, %l0
F0048E38: d0040000                 ld      [%l0], %o0
F0048E3C: 808a2004                 btst    4, %o0
F0048E40: 22800006                 be,a    loc_F0048E58
F0048E44: d2046064                 ld      [%l1+0x64], %o1
F0048E48: 7fff6e88                 call    _brelse
F0048E4C: 90100010                 mov     %l0, %o0
F0048E50: 10800040                 ba      locret_F0048F50
F0048E54: b0102000                 mov     0, %i0
F0048E58: 9410001c                 mov     %i4, %o2! size_t
F0048E5C: d004a040                 ld      [%l2+0x40], %o0
F0048E60: 7fff6f02                 call    _getblk
F0048E64: 932cc009                 sll     %l3, %o1, %o1
F0048E68: b0100008                 mov     %o0, %i0
F0048E6C: d0042020                 ld      [%l0+0x20], %o0! void *
F0048E70: d2062020                 ld      [%i0+0x20], %o1! void *
F0048E74: 40012f27                 call    _bcopy
F0048E78: 9410001b                 mov     %i3, %o2
F0048E7C: b427001b                 sub     %i4, %i3, %i2
F0048E80: d0062020                 ld      [%i0+0x20], %o0! void *
F0048E84: 9210001a                 mov     %i2, %o1! size_t
F0048E88: 40012ff4                 call    _bzero
F0048E8C: 9002001b                 add     %o0, %i3, %o0
F0048E90: d0040000                 ld      [%l0], %o0
F0048E94: 808a2200                 btst    0x200, %o0
F0048E98: 02800008                 be      loc_F0048EB8
F0048E9C: 900a3dff                 and     %o0, -0x201, %o0
F0048EA0: d0240000                 st      %o0, [%l0]
F0048EA4: 113c04cf                 sethi   %hi(_active_u), %o0
F0048EA8: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F0048EAC: d002619c                 ld      [%o1+0x19C], %o0
F0048EB0: 90023fff                 inc     -1, %o0
F0048EB4: d022619c                 st      %o0, [%o1+0x19C]
F0048EB8: 7fff6e6c                 call    _brelse
F0048EBC: 90100010                 mov     %l0, %o0
F0048EC0: 90100012                 mov     %l2, %o0
F0048EC4: 92100019                 mov     %i1, %o1
F0048EC8: 400004ac                 call    _free_block
F0048ECC: 9410001b                 mov     %i3, %o2
F0048ED0: 80a70014                 cmp     %i4, %l4
F0048ED4: 36800009                 bge,a   loc_F0048EF8
F0048ED8: d004a028                 ld      [%l2+0x28], %o0
F0048EDC: 90100012                 mov     %l2, %o0
F0048EE0: d2046054                 ld      [%l1+0x54], %o1
F0048EE4: 9425001c                 sub     %l4, %i4, %o2
F0048EE8: 933f0009                 sra     %i4, %o1, %o1
F0048EEC: 400004a3                 call    _free_block
F0048EF0: 9204c009                 add     %l3, %o1, %o1
F0048EF4: d004a028                 ld      [%l2+0x28], %o0
F0048EF8: d2022080                 ld      [%o0+0x80], %o1
F0048EFC: 9fc24000                 call    %o1
F0048F00: 9004a00c                 add     %l2, 0xC, %o0
F0048F04: 92100008                 mov     %o0, %o1! int
F0048F08: 9010001a                 mov     %i2, %o0! int
F0048F0C: 7ffef5bf                 call    _div
F0048F10: 01000000                 nop
F0048F14: d204a0cc                 ld      [%l2+0xCC], %o1
F0048F18: 92024008                 add     %o1, %o0, %o1
F0048F1C: d014a044                 lduh    [%l2+0x44], %o0
F0048F20: d224a0cc                 st      %o1, [%l2+0xCC]
F0048F24: 90122042                 bset    0x42, %o0 ! 'B'
F0048F28: 1080000a                 ba      locret_F0048F50
F0048F2C: d034a044                 sth     %o0, [%l2+0x44]
F0048F30: 7fff6e4e                 call    _brelse
F0048F34: 90100018                 mov     %i0, %o0
F0048F38: 10800006                 ba      locret_F0048F50
F0048F3C: b0102000                 mov     0, %i0
F0048F40: 90100011                 mov     %l1, %o0
F0048F44: 7ffffe83                 call    _fsfull
F0048F48: 92102001                 mov     1, %o1
F0048F4C: b0102000                 mov     0, %i0
F0048F50: 81c7e008                 ret
F0048F54: 81e80000                 restore
