F004AAF4: 9de3bf98                 save    %sp, -0x68, %sp
F004AAF8: a4100018                 mov     %i0, %l2
F004AAFC: ba10001c                 mov     %i4, %i5
F004AB00: ac102000                 mov     0, %l6
F004AB04: 80a66000                 cmp     %i1, 0
F004AB08: 068000e8                 bl      loc_F004AEA8
F004AB0C: ae102000                 mov     0, %l7
F004AB10: 113c04eb                 sethi   %hi(_rablock), %o0
F004AB14: c0222170                 clr     [%o0+%lo(_rablock)]
F004AB18: 113c04eb                 sethi   %hi(_rasize), %o0
F004AB1C: c0222178                 clr     [%o0+%lo(_rasize)]
F004AB20: 808ea020                 btst    0x20, %i2 ! ' '
F004AB24: 02800003                 be      loc_F004AB30
F004AB28: e604a050                 ld      [%l2+0x50], %l3
F004AB2C: b40ebfdf                 and     %i2, -0x21, %i2
F004AB30: d404a070                 ld      [%l2+0x70], %o2
F004AB34: d204e050                 ld      [%l3+0x50], %o1
F004AB38: 80a6a000                 cmp     %i2, 0
F004AB3C: 12800049                 bne     loc_F004AC60
F004AB40: b1328009                 srl     %o2, %o1, %i0
F004AB44: 80a6200b                 cmp     %i0, 0xB
F004AB48: 14800047                 bg      loc_F004AC64
F004AB4C: 80a6600b                 cmp     %i1, 0xB
F004AB50: 80a60019                 cmp     %i0, %i1
F004AB54: 16800044                 bge     loc_F004AC64
F004AB58: 80a6600b                 cmp     %i1, 0xB
F004AB5C: 912e2002                 sll     %i0, 2, %o0
F004AB60: 90020012                 add     %o0, %l2, %o0
F004AB64: d002208c                 ld      [%o0+0x8C], %o0
F004AB68: 80a22000                 cmp     %o0, 0
F004AB6C: 0280003d                 be      loc_F004AC60
F004AB70: 80a6200b                 cmp     %i0, 0xB
F004AB74: 3480000f                 bg,a    loc_F004ABB0
F004AB78: e204e030                 ld      [%l3+0x30], %l1
F004AB7C: 90062001                 add     %i0, 1, %o0
F004AB80: 912a0009                 sll     %o0, %o1, %o0
F004AB84: 80a28008                 cmp     %o2, %o0
F004AB88: 2a800004                 bcs,a   loc_F004AB98
F004AB8C: d004e048                 ld      [%l3+0x48], %o0
F004AB90: 10800008                 ba      loc_F004ABB0
F004AB94: e204e030                 ld      [%l3+0x30], %l1
F004AB98: d204e034                 ld      [%l3+0x34], %o1
F004AB9C: 902a8008                 andn    %o2, %o0, %o0
F004ABA0: 90020009                 add     %o0, %o1, %o0
F004ABA4: d204e04c                 ld      [%l3+0x4C], %o1
F004ABA8: 90023fff                 inc     -1, %o0
F004ABAC: a20a0009                 and     %o0, %o1, %l1
F004ABB0: d004e030                 ld      [%l3+0x30], %o0
F004ABB4: 80a44008                 cmp     %l1, %o0
F004ABB8: 1a80002a                 bcc     loc_F004AC60
F004ABBC: 80a46000                 cmp     %l1, 0
F004ABC0: 02800028                 be      loc_F004AC60
F004ABC4: 92100018                 mov     %i0, %o1
F004ABC8: 90100012                 mov     %l2, %o0
F004ABCC: 94100018                 mov     %i0, %o2
F004ABD0: 972e2002                 sll     %i0, 2, %o3
F004ABD4: a802c012                 add     %o3, %l2, %l4
F004ABD8: e005208c                 ld      [%l4+0x8C], %l0
F004ABDC: 7ffff956                 call    _blkpref
F004ABE0: 9604a08c                 add     %l2, 0x8C, %o3
F004ABE4: 94100008                 mov     %o0, %o2
F004ABE8: 90100012                 mov     %l2, %o0
F004ABEC: 92100010                 mov     %l0, %o1
F004ABF0: d804e030                 ld      [%l3+0x30], %o4
F004ABF4: 7ffff7ea                 call    _realloccg
F004ABF8: 96100011                 mov     %l1, %o3
F004ABFC: a2920000                 orcc    %o0, %g0, %l1
F004AC00: 22800140                 be,a    locret_F004B100
F004AC04: b0103fff                 mov     -1, %i0
F004AC08: d204e030                 ld      [%l3+0x30], %o1
F004AC0C: 7ffeee3d                 call    _umul
F004AC10: 90062001                 add     %i0, 1, %o0
F004AC14: d024a070                 st      %o0, [%l2+0x70]
F004AC18: d0046024                 ld      [%l1+0x24], %o0
F004AC1C: d204e064                 ld      [%l3+0x64], %o1
F004AC20: 913a0009                 sra     %o0, %o1, %o0
F004AC24: d025208c                 st      %o0, [%l4+0x8C]
F004AC28: d014a044                 lduh    [%l2+0x44], %o0
F004AC2C: 80a76000                 cmp     %i5, 0
F004AC30: 90122042                 bset    0x42, %o0 ! 'B'
F004AC34: 02800009                 be      loc_F004AC58
F004AC38: d034a044                 sth     %o0, [%l2+0x44]
F004AC3C: 7fff66cb                 call    _bwrite
F004AC40: 90100011                 mov     %l1, %o0
F004AC44: 90100012                 mov     %l2, %o0
F004AC48: 40000e3f                 call    _iupdat
F004AC4C: 92102001                 mov     1, %o1
F004AC50: 10800005                 ba      loc_F004AC64
F004AC54: 80a6600b                 cmp     %i1, 0xB
F004AC58: 7fff66eb                 call    _bdwrite
F004AC5C: 90100011                 mov     %l1, %o0
F004AC60: 80a6600b                 cmp     %i1, 0xB
F004AC64: 1480007f                 bg      loc_F004AE60
F004AC68: aa102000                 mov     0, %l5
F004AC6C: 912e6002                 sll     %i1, 2, %o0
F004AC70: 90020012                 add     %o0, %l2, %o0
F004AC74: 80a6a001                 cmp     %i2, 1
F004AC78: 12800007                 bne     loc_F004AC94
F004AC7C: f002208c                 ld      [%o0+0x8C], %i0
F004AC80: 80a62000                 cmp     %i0, 0
F004AC84: 1280005d                 bne     loc_F004ADF8
F004AC88: 80a6600a                 cmp     %i1, 0xA
F004AC8C: 1080011d                 ba      locret_F004B100
F004AC90: b0103fff                 mov     -1, %i0
F004AC94: 80a62000                 cmp     %i0, 0
F004AC98: 22800025                 be,a    loc_F004AD2C
F004AC9C: e004e030                 ld      [%l3+0x30], %l0
F004ACA0: d204e030                 ld      [%l3+0x30], %o1
F004ACA4: 7ffeee17                 call    _umul
F004ACA8: 90066001                 add     %i1, 1, %o0
F004ACAC: d204a070                 ld      [%l2+0x70], %o1
F004ACB0: 80a24008                 cmp     %o1, %o0
F004ACB4: 1a800050                 bcc     loc_F004ADF4
F004ACB8: 80a62000                 cmp     %i0, 0
F004ACBC: 2280001c                 be,a    loc_F004AD2C
F004ACC0: e004e030                 ld      [%l3+0x30], %l0
F004ACC4: d004e048                 ld      [%l3+0x48], %o0
F004ACC8: d404a070                 ld      [%l2+0x70], %o2
F004ACCC: d204e034                 ld      [%l3+0x34], %o1
F004ACD0: 902a8008                 andn    %o2, %o0, %o0
F004ACD4: 90020009                 add     %o0, %o1, %o0
F004ACD8: 90023fff                 inc     -1, %o0
F004ACDC: 9206c009                 add     %i3, %o1, %o1
F004ACE0: d404e04c                 ld      [%l3+0x4C], %o2
F004ACE4: 92027fff                 inc     -1, %o1
F004ACE8: a20a000a                 and     %o0, %o2, %l1
F004ACEC: a00a400a                 and     %o1, %o2, %l0
F004ACF0: 80a40011                 cmp     %l0, %l1
F004ACF4: 08800040                 bleu    loc_F004ADF4
F004ACF8: 90100012                 mov     %l2, %o0
F004ACFC: 92100019                 mov     %i1, %o1
F004AD00: 94100019                 mov     %i1, %o2
F004AD04: 7ffff90c                 call    _blkpref
F004AD08: 9604a08c                 add     %l2, 0x8C, %o3
F004AD0C: 94100008                 mov     %o0, %o2
F004AD10: 90100012                 mov     %l2, %o0
F004AD14: 92100018                 mov     %i0, %o1
F004AD18: 96100011                 mov     %l1, %o3
F004AD1C: 7ffff7a0                 call    _realloccg
F004AD20: 98100010                 mov     %l0, %o4
F004AD24: 10800018                 ba      loc_F004AD84
F004AD28: a2100008                 mov     %o0, %l1
F004AD2C: 90066001                 add     %i1, 1, %o0
F004AD30: 7ffeedf4                 call    _umul
F004AD34: 92100010                 mov     %l0, %o1
F004AD38: d204a070                 ld      [%l2+0x70], %o1
F004AD3C: 80a24008                 cmp     %o1, %o0
F004AD40: 1a800008                 bcc     loc_F004AD60
F004AD44: 90100012                 mov     %l2, %o0
F004AD48: d004e034                 ld      [%l3+0x34], %o0
F004AD4C: d204e04c                 ld      [%l3+0x4C], %o1
F004AD50: 9006c008                 add     %i3, %o0, %o0
F004AD54: 90023fff                 inc     -1, %o0
F004AD58: a00a0009                 and     %o0, %o1, %l0
F004AD5C: 90100012                 mov     %l2, %o0
F004AD60: 92100019                 mov     %i1, %o1
F004AD64: 94100019                 mov     %i1, %o2
F004AD68: 7ffff8f3                 call    _blkpref
F004AD6C: 9604a08c                 add     %l2, 0x8C, %o3
F004AD70: 92100008                 mov     %o0, %o1
F004AD74: 90100012                 mov     %l2, %o0
F004AD78: 7ffff692                 call    _alloc
F004AD7C: 94100010                 mov     %l0, %o2
F004AD80: a2100008                 mov     %o0, %l1
F004AD84: 80a46000                 cmp     %l1, 0
F004AD88: 02bfffc1                 be      loc_F004AC8C
F004AD8C: 80a76000                 cmp     %i5, 0
F004AD90: d2046024                 ld      [%l1+0x24], %o1
F004AD94: d004e064                 ld      [%l3+0x64], %o0
F004AD98: 02800004                 be      loc_F004ADA8
F004AD9C: b13a4008                 sra     %o1, %o0, %i0
F004ADA0: 90102001                 mov     1, %o0
F004ADA4: d0274000                 st      %o0, [%i5]
F004ADA8: d014a064                 lduh    [%l2+0x64], %o0
F004ADAC: 1300003c                 sethi   0xF000, %o1
F004ADB0: 900a0009                 and     %o0, %o1, %o0
F004ADB4: 13000010                 sethi   0x4000, %o1
F004ADB8: 80a20009                 cmp     %o0, %o1
F004ADBC: 12800006                 bne     loc_F004ADD4
F004ADC0: 01000000                 nop
F004ADC4: 7fff6669                 call    _bwrite
F004ADC8: 90100011                 mov     %l1, %o0
F004ADCC: 10800005                 ba      loc_F004ADE0
F004ADD0: 912e6002                 sll     %i1, 2, %o0
F004ADD4: 7fff668c                 call    _bdwrite
F004ADD8: 90100011                 mov     %l1, %o0
F004ADDC: 912e6002                 sll     %i1, 2, %o0
F004ADE0: 90020012                 add     %o0, %l2, %o0
F004ADE4: f022208c                 st      %i0, [%o0+0x8C]
F004ADE8: d014a044                 lduh    [%l2+0x44], %o0
F004ADEC: 90122042                 bset    0x42, %o0 ! 'B'
F004ADF0: d034a044                 sth     %o0, [%l2+0x44]
F004ADF4: 80a6600a                 cmp     %i1, 0xA
F004ADF8: 148000c2                 bg      locret_F004B100
F004ADFC: 912e6002                 sll     %i1, 2, %o0
F004AE00: 90048008                 add     %l2, %o0, %o0
F004AE04: d2022090                 ld      [%o0+0x90], %o1
F004AE08: d404e064                 ld      [%l3+0x64], %o2
F004AE0C: 90066001                 add     %i1, 1, %o0
F004AE10: 80a2200b                 cmp     %o0, 0xB
F004AE14: 932a400a                 sll     %o1, %o2, %o1
F004AE18: 113c04eb                 sethi   %hi(_rablock), %o0
F004AE1C: 148000b6                 bg      loc_F004B0F4
F004AE20: d2222170                 st      %o1, [%o0+%lo(_rablock)]
F004AE24: d204e050                 ld      [%l3+0x50], %o1
F004AE28: 90066002                 add     %i1, 2, %o0
F004AE2C: d604a070                 ld      [%l2+0x70], %o3
F004AE30: 912a0009                 sll     %o0, %o1, %o0
F004AE34: 80a2c008                 cmp     %o3, %o0
F004AE38: 3a8000b0                 bcc,a   loc_F004B0F8
F004AE3C: d204e030                 ld      [%l3+0x30], %o1
F004AE40: d004e048                 ld      [%l3+0x48], %o0
F004AE44: d204e034                 ld      [%l3+0x34], %o1
F004AE48: 902ac008                 andn    %o3, %o0, %o0
F004AE4C: 90020009                 add     %o0, %o1, %o0
F004AE50: d204e04c                 ld      [%l3+0x4C], %o1
F004AE54: 90023fff                 inc     -1, %o0
F004AE58: 108000a8                 ba      loc_F004B0F8
F004AE5C: 920a0009                 and     %o0, %o1, %o1
F004AE60: a8102001                 mov     1, %l4
F004AE64: b8100019                 mov     %i1, %i4
F004AE68: b2073ff4                 add     %i4, -0xC, %i1
F004AE6C: b6102003                 mov     3, %i3
F004AE70: d204e074                 ld      [%l3+0x74], %o1
F004AE74: 7ffeeda3                 call    _umul
F004AE78: 90100014                 mov     %l4, %o0
F004AE7C: a8100008                 mov     %o0, %l4
F004AE80: 80a64014                 cmp     %i1, %l4
F004AE84: 06800007                 bl      loc_F004AEA0
F004AE88: 80a6e000                 cmp     %i3, 0
F004AE8C: b606ffff                 inc     -1, %i3
F004AE90: 80a6e000                 cmp     %i3, 0
F004AE94: 14bffff7                 bg      loc_F004AE70
F004AE98: b2264014                 sub     %i1, %l4, %i1
F004AE9C: 80a6e000                 cmp     %i3, 0
F004AEA0: 12800008                 bne     loc_F004AEC0
F004AEA4: 90102003                 mov     3, %o0
F004AEA8: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F004AEAC: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F004AEB0: b0102000                 mov     0, %i0
F004AEB4: 9010201b                 mov     0x1B, %o0
F004AEB8: 10800092                 ba      locret_F004B100
F004AEBC: d02a6038                 stb     %o0, [%o1+0x38]
F004AEC0: 9022001b                 sub     %o0, %i3, %o0
F004AEC4: 912a2002                 sll     %o0, 2, %o0
F004AEC8: a0020012                 add     %o0, %l2, %l0
F004AECC: f00420bc                 ld      [%l0+0xBC], %i0
F004AED0: 80a62000                 cmp     %i0, 0
F004AED4: 1280007b                 bne     loc_F004B0C0
F004AED8: 80a6e003                 cmp     %i3, 3
F004AEDC: 80a6a001                 cmp     %i2, 1
F004AEE0: 02bfff6b                 be      loc_F004AC8C
F004AEE4: 90100012                 mov     %l2, %o0
F004AEE8: 9210001c                 mov     %i4, %o1
F004AEEC: 94102000                 mov     0, %o2
F004AEF0: 7ffff891                 call    _blkpref
F004AEF4: 96102000                 mov     0, %o3
F004AEF8: aa100008                 mov     %o0, %l5
F004AEFC: 90100012                 mov     %l2, %o0
F004AF00: d404e030                 ld      [%l3+0x30], %o2
F004AF04: 7ffff62f                 call    _alloc
F004AF08: 92100015                 mov     %l5, %o1
F004AF0C: a2920000                 orcc    %o0, %g0, %l1
F004AF10: 3280000c                 bne,a   loc_F004AF40
F004AF14: d4046024                 ld      [%l1+0x24], %o2
F004AF18: 1080007a                 ba      locret_F004B100
F004AF1C: b0103fff                 mov     -1, %i0
F004AF20: 7fff6652                 call    _brelse
F004AF24: 90100011                 mov     %l1, %o0
F004AF28: 10800076                 ba      locret_F004B100
F004AF2C: b0102000                 mov     0, %i0
F004AF30: 7fff664e                 call    _brelse
F004AF34: 90100011                 mov     %l1, %o0
F004AF38: 10800072                 ba      locret_F004B100
F004AF3C: b0103fff                 mov     -1, %i0
F004AF40: d204e064                 ld      [%l3+0x64], %o1
F004AF44: 90100011                 mov     %l1, %o0
F004AF48: 7fff6608                 call    _bwrite
F004AF4C: b13a8009                 sra     %o2, %o1, %i0
F004AF50: f02420bc                 st      %i0, [%l0+0xBC]
F004AF54: d014a044                 lduh    [%l2+0x44], %o0
F004AF58: 80a76000                 cmp     %i5, 0
F004AF5C: 90122042                 bset    0x42, %o0 ! 'B'
F004AF60: 02800057                 be      loc_F004B0BC
F004AF64: d034a044                 sth     %o0, [%l2+0x44]
F004AF68: 90102001                 mov     1, %o0
F004AF6C: 10800054                 ba      loc_F004B0BC
F004AF70: d0274000                 st      %o0, [%i5]
F004AF74: d204e064                 ld      [%l3+0x64], %o1
F004AF78: d404e030                 ld      [%l3+0x30], %o2
F004AF7C: 7fff6569                 call    _bread
F004AF80: 932e0009                 sll     %i0, %o1, %o1! int
F004AF84: a2100008                 mov     %o0, %l1
F004AF88: d0044000                 ld      [%l1], %o0
F004AF8C: 808a2004                 btst    4, %o0
F004AF90: 12bfffe4                 bne     loc_F004AF20
F004AF94: 90100014                 mov     %l4, %o0! int
F004AF98: e004e074                 ld      [%l3+0x74], %l0
F004AF9C: ee046020                 ld      [%l1+0x20], %l7
F004AFA0: 7ffeed9a                 call    _div
F004AFA4: 92100010                 mov     %l0, %o1! int
F004AFA8: a8100008                 mov     %o0, %l4
F004AFAC: 90100019                 mov     %i1, %o0! int
F004AFB0: 7ffeed96                 call    _div
F004AFB4: 92100014                 mov     %l4, %o1
F004AFB8: 7ffeee3c                 call    _rem
F004AFBC: 92100010                 mov     %l0, %o1
F004AFC0: ac100008                 mov     %o0, %l6
F004AFC4: 912da002                 sll     %l6, 2, %o0
F004AFC8: f005c008                 ld      [%l7+%o0], %i0
F004AFCC: 80a62000                 cmp     %i0, 0
F004AFD0: 12800038                 bne     loc_F004B0B0
F004AFD4: 80a6a001                 cmp     %i2, 1
F004AFD8: 02bfffd6                 be      loc_F004AF30
F004AFDC: 80a56000                 cmp     %l5, 0
F004AFE0: 1280000f                 bne     loc_F004B01C
F004AFE4: 90100012                 mov     %l2, %o0
F004AFE8: 80a6e002                 cmp     %i3, 2
F004AFEC: 14800006                 bg      loc_F004B004
F004AFF0: 9210001c                 mov     %i4, %o1
F004AFF4: 90100012                 mov     %l2, %o0
F004AFF8: 94102000                 mov     0, %o2
F004AFFC: 10800004                 ba      loc_F004B00C
F004B000: 96102000                 mov     0, %o3
F004B004: 94100016                 mov     %l6, %o2
F004B008: 96100017                 mov     %l7, %o3
F004B00C: 7ffff84a                 call    _blkpref
F004B010: 01000000                 nop
F004B014: aa100008                 mov     %o0, %l5
F004B018: 90100012                 mov     %l2, %o0
F004B01C: d404e030                 ld      [%l3+0x30], %o2
F004B020: 7ffff5e8                 call    _alloc
F004B024: 92100015                 mov     %l5, %o1
F004B028: 94920000                 orcc    %o0, %g0, %o2
F004B02C: 02bfffc1                 be      loc_F004AF30
F004B030: 80a6e002                 cmp     %i3, 2
F004B034: d202a024                 ld      [%o2+0x24], %o1
F004B038: d004e064                 ld      [%l3+0x64], %o0
F004B03C: 0480000b                 ble     loc_F004B068
F004B040: b13a4008                 sra     %o1, %o0, %i0
F004B044: d014a064                 lduh    [%l2+0x64], %o0
F004B048: 1300003c                 sethi   0xF000, %o1
F004B04C: 900a0009                 and     %o0, %o1, %o0
F004B050: 13000010                 sethi   0x4000, %o1
F004B054: 80a20009                 cmp     %o0, %o1
F004B058: 02800004                 be      loc_F004B068
F004B05C: 80a76000                 cmp     %i5, 0
F004B060: 02800006                 be      loc_F004B078
F004B064: 01000000                 nop
F004B068: 7fff65c0                 call    _bwrite
F004B06C: 9010000a                 mov     %o2, %o0
F004B070: 10800005                 ba      loc_F004B084
F004B074: 912da002                 sll     %l6, 2, %o0
F004B078: 7fff65e3                 call    _bdwrite
F004B07C: 9010000a                 mov     %o2, %o0
F004B080: 912da002                 sll     %l6, 2, %o0
F004B084: 80a76000                 cmp     %i5, 0
F004B088: 02800006                 be      loc_F004B0A0
F004B08C: f025c008                 st      %i0, [%l7+%o0]
F004B090: 7fff65b6                 call    _bwrite
F004B094: 90100011                 mov     %l1, %o0
F004B098: 10800009                 ba      loc_F004B0BC
F004B09C: b606e001                 inc     %i3
F004B0A0: 7fff65d9                 call    _bdwrite
F004B0A4: 90100011                 mov     %l1, %o0
F004B0A8: 10800005                 ba      loc_F004B0BC
F004B0AC: b606e001                 inc     %i3
F004B0B0: 7fff65ee                 call    _brelse
F004B0B4: 90100011                 mov     %l1, %o0
F004B0B8: b606e001                 inc     %i3
F004B0BC: 80a6e003                 cmp     %i3, 3
F004B0C0: 24bfffad                 ble,a   loc_F004AF74
F004B0C4: d004a040                 ld      [%l2+0x40], %o0
F004B0C8: d004e074                 ld      [%l3+0x74], %o0
F004B0CC: 90023fff                 inc     -1, %o0
F004B0D0: 80a58008                 cmp     %l6, %o0
F004B0D4: 1680000b                 bge     locret_F004B100
F004B0D8: 912da002                 sll     %l6, 2, %o0
F004B0DC: 90020017                 add     %o0, %l7, %o0
F004B0E0: d0022004                 ld      [%o0+4], %o0
F004B0E4: d204e064                 ld      [%l3+0x64], %o1
F004B0E8: 912a0009                 sll     %o0, %o1, %o0
F004B0EC: 133c04eb                 sethi   %hi(_rablock), %o1
F004B0F0: d0226170                 st      %o0, [%o1+%lo(_rablock)]
F004B0F4: d204e030                 ld      [%l3+0x30], %o1
F004B0F8: 113c04eb                 sethi   %hi(_rasize), %o0
F004B0FC: d2222178                 st      %o1, [%o0+%lo(_rasize)]
F004B100: 81c7e008                 ret
F004B104: 81e80000                 restore
