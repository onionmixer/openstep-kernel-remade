F0049AE4: 9de3bf98                 save    %sp, -0x68, %sp
F0049AE8: 80a6a000                 cmp     %i2, 0
F0049AEC: 32800004                 bne,a   loc_F0049AFC
F0049AF0: d0062038                 ld      [%i0+0x38], %o0
F0049AF4: 10800092                 ba      loc_F0049D3C
F0049AF8: f4066028                 ld      [%i1+0x28], %i2
F0049AFC: d20620bc                 ld      [%i0+0xBC], %o1
F0049B00: 90200008                 neg     %o0
F0049B04: b40e8008                 and     %i2, %o0, %i2
F0049B08: 7ffef368                 call    _rem
F0049B0C: 9010001a                 mov     %i2, %o0
F0049B10: b4100008                 mov     %o0, %i2
F0049B14: 90100018                 mov     %i0, %o0
F0049B18: d4062060                 ld      [%i0+0x60], %o2
F0049B1C: 920663d8                 add     %i1, 0x3D8, %o1
F0049B20: 400019b9                 call    _isblock
F0049B24: 953e800a                 sra     %i2, %o2, %o2
F0049B28: 80a22000                 cmp     %o0, 0
F0049B2C: 1280008f                 bne     loc_F0049D68
F0049B30: a810001a                 mov     %i2, %l4
F0049B34: e206207c                 ld      [%i0+0x7C], %l1
F0049B38: 9010001a                 mov     %i2, %o0! int
F0049B3C: 7ffef271                 call    _umul
F0049B40: 92100011                 mov     %l1, %o1! int
F0049B44: a4100008                 mov     %o0, %l2
F0049B48: e00620ac                 ld      [%i0+0xAC], %l0
F0049B4C: 7ffef2af                 call    _div
F0049B50: 92100010                 mov     %l0, %o1
F0049B54: a6100008                 mov     %o0, %l3
F0049B58: 912ce002                 sll     %l3, 2, %o0
F0049B5C: 90020019                 add     %o0, %i1, %o0
F0049B60: d0022054                 ld      [%o0+0x54], %o0
F0049B64: 80a22000                 cmp     %o0, 0
F0049B68: 02800076                 be      loc_F0049D40
F0049B6C: 90100018                 mov     %i0, %o0
F0049B70: d0062358                 ld      [%i0+0x358], %o0
F0049B74: 80a22000                 cmp     %o0, 0
F0049B78: 1280000b                 bne     loc_F0049BA4
F0049B7C: 90100012                 mov     %l2, %o0
F0049B80: 90100010                 mov     %l0, %o0
F0049B84: 7ffef25f                 call    _umul
F0049B88: 92100013                 mov     %l3, %o1! int
F0049B8C: 90023fff                 inc     -1, %o0
F0049B90: 90020011                 add     %o0, %l1, %o0! int
F0049B94: 7ffef29d                 call    _div
F0049B98: 92100011                 mov     %l1, %o1
F0049B9C: 10800068                 ba      loc_F0049D3C
F0049BA0: b4100008                 mov     %o0, %i2
F0049BA4: 92100010                 mov     %l0, %o1
F0049BA8: 952ce004                 sll     %l3, 4, %o2
F0049BAC: 9402a0d4                 inc     0xD4, %o2
F0049BB0: 7ffef33e                 call    _rem
F0049BB4: a206400a                 add     %i1, %o2, %l1
F0049BB8: e00620a8                 ld      [%i0+0xA8], %l0
F0049BBC: 7ffef33b                 call    _rem
F0049BC0: 92100010                 mov     %l0, %o1! int
F0049BC4: 912a2003                 sll     %o0, 3, %o0! int
F0049BC8: 7ffef290                 call    _div
F0049BCC: 92100010                 mov     %l0, %o1
F0049BD0: a0100008                 mov     %o0, %l0
F0049BD4: 80a42007                 cmp     %l0, 7
F0049BD8: 1480000b                 bg      loc_F0049C04
F0049BDC: a4100010                 mov     %l0, %l2
F0049BE0: 932c2001                 sll     %l0, 1, %o1
F0049BE4: d0524011                 ldsh    [%o1+%l1], %o0
F0049BE8: 80a22000                 cmp     %o0, 0
F0049BEC: 14800007                 bg      loc_F0049C08
F0049BF0: 80a42008                 cmp     %l0, 8
F0049BF4: a0042001                 inc     %l0
F0049BF8: 80a42007                 cmp     %l0, 7
F0049BFC: 04bffffa                 ble     loc_F0049BE4
F0049C00: 92026002                 inc     2, %o1
F0049C04: 80a42008                 cmp     %l0, 8
F0049C08: 12800010                 bne     loc_F0049C48
F0049C0C: a92c2001                 sll     %l0, 1, %l4
F0049C10: a0102000                 mov     0, %l0
F0049C14: 80a40012                 cmp     %l0, %l2
F0049C18: 1680000c                 bge     loc_F0049C48
F0049C1C: a92c2001                 sll     %l0, 1, %l4
F0049C20: 92102000                 mov     0, %o1
F0049C24: d0524011                 ldsh    [%o1+%l1], %o0
F0049C28: 80a22000                 cmp     %o0, 0
F0049C2C: 14800007                 bg      loc_F0049C48
F0049C30: a92c2001                 sll     %l0, 1, %l4
F0049C34: a0042001                 inc     %l0
F0049C38: 80a40012                 cmp     %l0, %l2
F0049C3C: 06bffffa                 bl      loc_F0049C24
F0049C40: 92026002                 inc     2, %o1
F0049C44: a92c2001                 sll     %l0, 1, %l4
F0049C48: d0544014                 ldsh    [%l1+%l4], %o0
F0049C4C: 80a22000                 cmp     %o0, 0
F0049C50: 2480003c                 ble,a   loc_F0049D40
F0049C54: 90100018                 mov     %i0, %o0
F0049C58: d2062358                 ld      [%i0+0x358], %o1
F0049C5C: 7ffef313                 call    _rem
F0049C60: 90100013                 mov     %l3, %o0
F0049C64: a4100008                 mov     %o0, %l2
F0049C68: d20620ac                 ld      [%i0+0xAC], %o1
F0049C6C: 7ffef225                 call    _umul
F0049C70: 9024c012                 sub     %l3, %l2, %o0! int
F0049C74: d406207c                 ld      [%i0+0x7C], %o2
F0049C78: d2062060                 ld      [%i0+0x60], %o1! int
F0049C7C: 7ffef263                 call    _div
F0049C80: 932a8009                 sll     %o2, %o1, %o1
F0049C84: 932ca004                 sll     %l2, 4, %o1
F0049C88: 92024018                 add     %o1, %i0, %o1
F0049C8C: a2050009                 add     %l4, %o1, %l1
F0049C90: d254635c                 ldsh    [%l1+0x35C], %o1
F0049C94: 80a27fff                 cmp     %o1, -1
F0049C98: 1280000b                 bne     loc_F0049CC4
F0049C9C: a8100008                 mov     %o0, %l4
F0049CA0: 113c043990122320         set     aPosDIDFsS, %o0! "pos = %d, i = %d, fs = %s\n"
F0049CA8: 92100012                 mov     %l2, %o1
F0049CAC: 94100010                 mov     %l0, %o2
F0049CB0: 7fff2a6a                 call    _printf
F0049CB4: 960620d4                 add     %i0, 0xD4, %o3
F0049CB8: 113c0439                 sethi   %hi(aAlloccgblkCylG), %o0! "alloccgblk: cyl groups corrupted"
F0049CBC: 7fff2d2d                 call    _panic
F0049CC0: 90122340                 bset    %lo(aAlloccgblkCylG), %o0! "alloccgblk: cyl groups corrupted"
F0049CC4: e054635c                 ldsh    [%l1+0x35C], %l0
F0049CC8: 11000006a612229c         set     0x1A9C, %l3
F0049CD0: 90100018                 mov     %i0, %o0
F0049CD4: 920663d8                 add     %i1, 0x3D8, %o1
F0049CD8: a2050010                 add     %l4, %l0, %l1
F0049CDC: 4000194a                 call    _isblock
F0049CE0: 94100011                 mov     %l1, %o2
F0049CE4: 80a22000                 cmp     %o0, 0
F0049CE8: 3280001f                 bne,a   loc_F0049D64
F0049CEC: d0062060                 ld      [%i0+0x60], %o0
F0049CF0: 90060010                 add     %i0, %l0, %o0
F0049CF4: d20a2560                 ldub    [%o0+0x560], %o1
F0049CF8: 80a26000                 cmp     %o1, 0
F0049CFC: 04800008                 ble     loc_F0049D1C
F0049D00: 113c0439                 sethi   -0xFEF1C00, %o0
F0049D04: 9024c010                 sub     %l3, %l0, %o0
F0049D08: 80a24008                 cmp     %o1, %o0
F0049D0C: 18800004                 bgu     loc_F0049D1C
F0049D10: 113c0439                 sethi   -0xFEF1C00, %o0
F0049D14: 10bfffef                 ba      loc_F0049CD0
F0049D18: a0040009                 add     %l0, %o1, %l0
F0049D1C: 90122368                 bset    0x368, %o0! char *
F0049D20: 92100012                 mov     %l2, %o1
F0049D24: 94100010                 mov     %l0, %o2
F0049D28: 7fff2a4c                 call    _printf
F0049D2C: 960620d4                 add     %i0, 0xD4, %o3
F0049D30: 113c0439                 sethi   %hi(aAlloccgblkCanT), %o0! "alloccgblk: can't find blk in cyl"
F0049D34: 7fff2d0f                 call    _panic
F0049D38: 90122388                 bset    %lo(aAlloccgblkCanT), %o0! "alloccgblk: can't find blk in cyl"
F0049D3C: 90100018                 mov     %i0, %o0
F0049D40: 92100019                 mov     %i1, %o1
F0049D44: d6062038                 ld      [%i0+0x38], %o3
F0049D48: 400002df                 call    _mapsearch
F0049D4C: 9410001a                 mov     %i2, %o2
F0049D50: a8920000                 orcc    %o0, %g0, %l4
F0049D54: 36800005                 bge,a   loc_F0049D68
F0049D58: e8266028                 st      %l4, [%i1+0x28]
F0049D5C: 1080003f                 ba      locret_F0049E58
F0049D60: b0102000                 mov     0, %i0
F0049D64: a92c4008                 sll     %l1, %o0, %l4
F0049D68: 90100018                 mov     %i0, %o0
F0049D6C: d4062060                 ld      [%i0+0x60], %o2
F0049D70: 920663d8                 add     %i1, 0x3D8, %o1
F0049D74: 40001953                 call    _clrblock
F0049D78: 953d000a                 sra     %l4, %o2, %o2
F0049D7C: d006601c                 ld      [%i1+0x1C], %o0
F0049D80: 90023fff                 inc     -1, %o0
F0049D84: d026601c                 st      %o0, [%i1+0x1C]
F0049D88: d00620c4                 ld      [%i0+0xC4], %o0
F0049D8C: 90023fff                 inc     -1, %o0
F0049D90: d02620c4                 st      %o0, [%i0+0xC4]
F0049D94: d406600c                 ld      [%i1+0xC], %o2
F0049D98: d0062070                 ld      [%i0+0x70], %o0
F0049D9C: d206206c                 ld      [%i0+0x6C], %o1
F0049DA0: 913a8008                 sra     %o2, %o0, %o0
F0049DA4: 912a2002                 sll     %o0, 2, %o0
F0049DA8: 90020018                 add     %o0, %i0, %o0
F0049DAC: 922a8009                 andn    %o2, %o1, %o1
F0049DB0: d40222d8                 ld      [%o0+0x2D8], %o2
F0049DB4: 932a6004                 sll     %o1, 4, %o1
F0049DB8: 94028009                 add     %o2, %o1, %o2
F0049DBC: d002a004                 ld      [%o2+4], %o0
F0049DC0: 90023fff                 inc     -1, %o0
F0049DC4: d022a004                 st      %o0, [%o2+4]
F0049DC8: d206207c                 ld      [%i0+0x7C], %o1! int
F0049DCC: 7ffef1cd                 call    _umul
F0049DD0: 90100014                 mov     %l4, %o0! int
F0049DD4: a0100008                 mov     %o0, %l0
F0049DD8: e20620ac                 ld      [%i0+0xAC], %l1
F0049DDC: 7ffef20b                 call    _div
F0049DE0: 92100011                 mov     %l1, %o1
F0049DE4: a6100008                 mov     %o0, %l3
F0049DE8: 90100010                 mov     %l0, %o0
F0049DEC: 92100011                 mov     %l1, %o1
F0049DF0: a12ce004                 sll     %l3, 4, %l0
F0049DF4: 7ffef2ad                 call    _rem
F0049DF8: a0040019                 add     %l0, %i1, %l0
F0049DFC: e20620a8                 ld      [%i0+0xA8], %l1
F0049E00: 7ffef2aa                 call    _rem
F0049E04: 92100011                 mov     %l1, %o1! int
F0049E08: 912a2003                 sll     %o0, 3, %o0! int
F0049E0C: 7ffef1ff                 call    _div
F0049E10: 92100011                 mov     %l1, %o1
F0049E14: 912a2001                 sll     %o0, 1, %o0
F0049E18: 90020010                 add     %o0, %l0, %o0
F0049E1C: d21220d4                 lduh    [%o0+0xD4], %o1
F0049E20: 92027fff                 inc     -1, %o1
F0049E24: d23220d4                 sth     %o1, [%o0+0xD4]
F0049E28: 932ce002                 sll     %l3, 2, %o1
F0049E2C: 92024019                 add     %o1, %i1, %o1
F0049E30: d0026054                 ld      [%o1+0x54], %o0
F0049E34: 90023fff                 inc     -1, %o0
F0049E38: d0226054                 st      %o0, [%o1+0x54]
F0049E3C: d00e20d0                 ldub    [%i0+0xD0], %o0
F0049E40: d20620bc                 ld      [%i0+0xBC], %o1
F0049E44: 90022001                 inc     %o0
F0049E48: d02e20d0                 stb     %o0, [%i0+0xD0]
F0049E4C: 7ffef1ad                 call    _umul
F0049E50: d006600c                 ld      [%i1+0xC], %o0
F0049E54: b0020014                 add     %o0, %l4, %i0
F0049E58: 81c7e008                 ret
F0049E5C: 81e80000                 restore
