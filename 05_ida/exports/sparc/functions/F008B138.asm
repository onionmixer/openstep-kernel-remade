F008B138: 9de3bf90                 save    %sp, -0x70, %sp
F008B13C: 92100019                 mov     %i1, %o1
F008B140: 153c04f4                 sethi   %hi(_page_shift), %o2
F008B144: d402a348                 ld      [%o2+%lo(_page_shift)], %o2
F008B148: 90100018                 mov     %i0, %o0
F008B14C: a132400a                 srl     %o1, %o2, %l0
F008B150: 7fffffd6                 call    sub_F008B0A8
F008B154: 9410001b                 mov     %i3, %o2
F008B158: 80a6a001                 cmp     %i2, 1
F008B15C: 12800006                 bne     loc_F008B174
F008B160: 80a22000                 cmp     %o0, 0
F008B164: 80a00008                 cmp     %g0, %o0
F008B168: b0403fff                 addc    %g0, -1, %i0
F008B16C: 108000d7                 ba      locret_F008B4C8
F008B170: b00e2005                 and     %i0, 5, %i0
F008B174: 02800010                 be      loc_F008B1B4
F008B178: 133c04c3                 sethi   %hi(unk_F0130F70), %o1
F008B17C: d00ec000                 ldub    [%i3], %o0
F008B180: 92126370                 bset    %lo(unk_F0130F70), %o1
F008B184: 912a2002                 sll     %o0, 2, %o0
F008B188: d2020009                 ld      [%o0+%o1], %o1
F008B18C: d406c000                 ld      [%i3], %o2
F008B190: 113fc000                 sethi   -0x1000000, %o0
F008B194: d2026024                 ld      [%o1+0x24], %o1
F008B198: 902a8008                 andn    %o2, %o0, %o0
F008B19C: 80a24008                 cmp     %o1, %o0
F008B1A0: 368000ca                 bge,a   locret_F008B4C8
F008B1A4: b0102000                 mov     0, %i0
F008B1A8: d427bff4                 st      %o2, [%fp+var_C]
F008B1AC: 7fffff40                 call    sub_F008AEAC
F008B1B0: 9007bff4                 add     %fp, var_C, %o0
F008B1B4: d2062010                 ld      [%i0+0x10], %o1! size_t
F008B1B8: 90042001                 add     %l0, 1, %o0
F008B1BC: 80a20009                 cmp     %o0, %o1
F008B1C0: 08800092                 bleu    loc_F008B408
F008B1C4: a2100008                 mov     %o0, %l1
F008B1C8: 912c6002                 sll     %l1, 2, %o0
F008B1CC: 80a22040                 cmp     %o0, 0x40 ! '@'
F008B1D0: 08800069                 bleu    loc_F008B374
F008B1D4: 80a26000                 cmp     %o1, 0
F008B1D8: 3280000e                 bne,a   loc_F008B210
F008B1DC: 912a6002                 sll     %o1, 2, %o0
F008B1E0: 91342004                 srl     %l0, 4, %o0
F008B1E4: 90022001                 inc     %o0
F008B1E8: b52a2002                 sll     %o0, 2, %i2
F008B1EC: 7fff7378                 call    _kalloc_noblock
F008B1F0: 9010001a                 mov     %i2, %o0
F008B1F4: b2920000                 orcc    %o0, %g0, %i1
F008B1F8: 02800042                 be      loc_F008B300
F008B1FC: 90100019                 mov     %i1, %o0! void *
F008B200: 40002716                 call    _bzero
F008B204: 9210001a                 mov     %i2, %o1! size_t
F008B208: 1080007f                 ba      loc_F008B404
F008B20C: f2262008                 st      %i1, [%i0+8]
F008B210: 80a22040                 cmp     %o0, 0x40 ! '@'
F008B214: 0880002a                 bleu    loc_F008B2BC
F008B218: 91342004                 srl     %l0, 4, %o0
F008B21C: 90022001                 inc     %o0
F008B220: b52a2002                 sll     %o0, 2, %i2
F008B224: 90027fff                 add     %o1, -1, %o0
F008B228: 91322004                 srl     %o0, 4, %o0
F008B22C: 90022001                 inc     %o0
F008B230: 912a2002                 sll     %o0, 2, %o0
F008B234: 80a68008                 cmp     %i2, %o0
F008B238: 22800074                 be,a    loc_F008B408
F008B23C: e2262010                 st      %l1, [%i0+0x10]
F008B240: 7fff7363                 call    _kalloc_noblock
F008B244: 9010001a                 mov     %i2, %o0
F008B248: b2920000                 orcc    %o0, %g0, %i1
F008B24C: 0280002d                 be      loc_F008B300
F008B250: 90100019                 mov     %i1, %o0! void *
F008B254: 40002701                 call    _bzero
F008B258: 9210001a                 mov     %i2, %o1
F008B25C: d0062010                 ld      [%i0+0x10], %o0
F008B260: 90023fff                 inc     -1, %o0
F008B264: 91322004                 srl     %o0, 4, %o0
F008B268: 80a23fff                 cmp     %o0, -1
F008B26C: 0280000e                 be      loc_F008B2A4
F008B270: 96102000                 mov     0, %o3
F008B274: 92102000                 mov     0, %o1
F008B278: d0062008                 ld      [%i0+8], %o0
F008B27C: d0020009                 ld      [%o0+%o1], %o0
F008B280: 9602e001                 inc     %o3
F008B284: d0224019                 st      %o0, [%o1+%i1]
F008B288: d0062010                 ld      [%i0+0x10], %o0
F008B28C: 90023fff                 inc     -1, %o0
F008B290: 91322004                 srl     %o0, 4, %o0
F008B294: 90022001                 inc     %o0
F008B298: 80a2c008                 cmp     %o3, %o0
F008B29C: 0abffff7                 bcs     loc_F008B278
F008B2A0: 92026004                 inc     4, %o1
F008B2A4: d2062010                 ld      [%i0+0x10], %o1
F008B2A8: d0062008                 ld      [%i0+8], %o0
F008B2AC: 92027fff                 inc     -1, %o1
F008B2B0: 93326004                 srl     %o1, 4, %o1! size_t
F008B2B4: 10800051                 ba      loc_F008B3F8
F008B2B8: 92026001                 inc     %o1
F008B2BC: 90022001                 inc     %o0
F008B2C0: b52a2002                 sll     %o0, 2, %i2
F008B2C4: 7fff7342                 call    _kalloc_noblock
F008B2C8: 9010001a                 mov     %i2, %o0
F008B2CC: b2920000                 orcc    %o0, %g0, %i1
F008B2D0: 0280000c                 be      loc_F008B300
F008B2D4: 90100019                 mov     %i1, %o0! void *
F008B2D8: 400026e0                 call    _bzero
F008B2DC: 9210001a                 mov     %i2, %o1
F008B2E0: 7fff733b                 call    _kalloc_noblock
F008B2E4: 90102040                 mov     0x40, %o0 ! '@'
F008B2E8: 80a22000                 cmp     %o0, 0
F008B2EC: 12800007                 bne     loc_F008B308
F008B2F0: d0264000                 st      %o0, [%i1]
F008B2F4: 90100019                 mov     %i1, %o0
F008B2F8: 7fff73aa                 call    _kfree
F008B2FC: 9210001a                 mov     %i2, %o1
F008B300: 10800072                 ba      locret_F008B4C8
F008B304: b0102005                 mov     5, %i0
F008B308: d0062010                 ld      [%i0+0x10], %o0
F008B30C: 96102000                 mov     0, %o3
F008B310: 80a2c008                 cmp     %o3, %o0
F008B314: 3680000d                 bge,a   loc_F008B348
F008B318: d6062010                 ld      [%i0+0x10], %o3
F008B31C: d4064000                 ld      [%i1], %o2
F008B320: d0062008                 ld      [%i0+8], %o0
F008B324: 932ae002                 sll     %o3, 2, %o1
F008B328: d0020009                 ld      [%o0+%o1], %o0
F008B32C: d0228009                 st      %o0, [%o2+%o1]
F008B330: d0062010                 ld      [%i0+0x10], %o0
F008B334: 9602e001                 inc     %o3
F008B338: 80a2c008                 cmp     %o3, %o0
F008B33C: 26bffff9                 bl,a    loc_F008B320
F008B340: d4064000                 ld      [%i1], %o2
F008B344: d6062010                 ld      [%i0+0x10], %o3
F008B348: 80a2e00f                 cmp     %o3, 0xF
F008B34C: 3880002a                 bgu,a   loc_F008B3F4
F008B350: d2062010                 ld      [%i0+0x10], %o1
F008B354: 932ae002                 sll     %o3, 2, %o1
F008B358: 9602e001                 inc     %o3
F008B35C: d0064000                 ld      [%i1], %o0
F008B360: 80a2e00f                 cmp     %o3, 0xF
F008B364: 08bffffc                 bleu    loc_F008B354
F008B368: c02a0009                 clrb    [%o0+%o1]
F008B36C: 10800022                 ba      loc_F008B3F4
F008B370: d2062010                 ld      [%i0+0x10], %o1
F008B374: 7fff7316                 call    _kalloc_noblock
F008B378: 01000000                 nop
F008B37C: b2920000                 orcc    %o0, %g0, %i1
F008B380: 02bfffe0                 be      loc_F008B300
F008B384: 96102000                 mov     0, %o3
F008B388: d0062010                 ld      [%i0+0x10], %o0
F008B38C: 80a2c008                 cmp     %o3, %o0
F008B390: 3680000c                 bge,a   loc_F008B3C0
F008B394: d6062010                 ld      [%i0+0x10], %o3
F008B398: 92102000                 mov     0, %o1
F008B39C: d0062008                 ld      [%i0+8], %o0
F008B3A0: d0020009                 ld      [%o0+%o1], %o0
F008B3A4: 9602e001                 inc     %o3
F008B3A8: d0224019                 st      %o0, [%o1+%i1]
F008B3AC: d0062010                 ld      [%i0+0x10], %o0
F008B3B0: 80a2c008                 cmp     %o3, %o0
F008B3B4: 06bffffa                 bl      loc_F008B39C
F008B3B8: 92026004                 inc     4, %o1
F008B3BC: d6062010                 ld      [%i0+0x10], %o3
F008B3C0: 80a2c011                 cmp     %o3, %l1
F008B3C4: 36800009                 bge,a   loc_F008B3E8
F008B3C8: d2062010                 ld      [%i0+0x10], %o1
F008B3CC: 912ae002                 sll     %o3, 2, %o0
F008B3D0: c02a0019                 clrb    [%o0+%i1]
F008B3D4: 9602e001                 inc     %o3
F008B3D8: 80a2c011                 cmp     %o3, %l1
F008B3DC: 06bffffd                 bl      loc_F008B3D0
F008B3E0: 90022004                 inc     4, %o0
F008B3E4: d2062010                 ld      [%i0+0x10], %o1
F008B3E8: 80a26000                 cmp     %o1, 0
F008B3EC: 24800006                 ble,a   loc_F008B404
F008B3F0: f2262008                 st      %i1, [%i0+8]
F008B3F4: d0062008                 ld      [%i0+8], %o0
F008B3F8: 7fff736a                 call    _kfree
F008B3FC: 932a6002                 sll     %o1, 2, %o1
F008B400: f2262008                 st      %i1, [%i0+8]
F008B404: e2262010                 st      %l1, [%i0+0x10]
F008B408: d0062010                 ld      [%i0+0x10], %o0
F008B40C: 912a2002                 sll     %o0, 2, %o0
F008B410: 80a22040                 cmp     %o0, 0x40 ! '@'
F008B414: 08800022                 bleu    loc_F008B49C
F008B418: b5342004                 srl     %l0, 4, %i2
F008B41C: d0062008                 ld      [%i0+8], %o0
F008B420: b32ea002                 sll     %i2, 2, %i1
F008B424: d0020019                 ld      [%o0+%i1], %o0
F008B428: 80a22000                 cmp     %o0, 0
F008B42C: 12800013                 bne     loc_F008B478
F008B430: a00c200f                 and     %l0, 0xF, %l0
F008B434: 7fff72e6                 call    _kalloc_noblock
F008B438: 90102040                 mov     0x40, %o0 ! '@'
F008B43C: d2062008                 ld      [%i0+8], %o1
F008B440: d0224019                 st      %o0, [%o1+%i1]
F008B444: d0062008                 ld      [%i0+8], %o0
F008B448: d0020019                 ld      [%o0+%i1], %o0
F008B44C: 80a22000                 cmp     %o0, 0
F008B450: 02bfffac                 be      loc_F008B300
F008B454: 96102000                 mov     0, %o3
F008B458: 94100019                 mov     %i1, %o2
F008B45C: 912ae002                 sll     %o3, 2, %o0
F008B460: d2062008                 ld      [%i0+8], %o1
F008B464: 9602e001                 inc     %o3
F008B468: d202400a                 ld      [%o1+%o2], %o1
F008B46C: 80a2e00f                 cmp     %o3, 0xF
F008B470: 08bffffb                 bleu    loc_F008B45C
F008B474: c02a4008                 clrb    [%o1+%o0]
F008B478: d0062004                 ld      [%i0+4], %o0
F008B47C: 7ffffe65                 call    _vnode_pager_findpage
F008B480: 9210001b                 mov     %i3, %o1
F008B484: 80a22005                 cmp     %o0, 5
F008B488: 02bfff9e                 be      loc_F008B300
F008B48C: 912ea002                 sll     %i2, 2, %o0
F008B490: d2062008                 ld      [%i0+8], %o1
F008B494: 10800009                 ba      loc_F008B4B8
F008B498: d4024008                 ld      [%o1+%o0], %o2
F008B49C: d0062004                 ld      [%i0+4], %o0
F008B4A0: 7ffffe5c                 call    _vnode_pager_findpage
F008B4A4: 9210001b                 mov     %i3, %o1
F008B4A8: 80a22005                 cmp     %o0, 5
F008B4AC: 22800007                 be,a    locret_F008B4C8
F008B4B0: b0102005                 mov     5, %i0
F008B4B4: d4062008                 ld      [%i0+8], %o2
F008B4B8: d206c000                 ld      [%i3], %o1
F008B4BC: 912c2002                 sll     %l0, 2, %o0
F008B4C0: d2228008                 st      %o1, [%o2+%o0]
F008B4C4: b0102000                 mov     0, %i0
F008B4C8: 81c7e008                 ret
F008B4CC: 81e80000                 restore
