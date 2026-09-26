F000AA40: 9de3bf78                 save    %sp, -0x88, %sp! int
F000AA44: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000AA48: d80221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o4
F000AA4C: e4032024                 ld      [%o4+0x24], %l2
F000AA50: 901221dc                 bset    %lo(dword_F0133DDC), %o0
F000AA54: d6023ffc                 ld      [%o0-4], %o3
F000AA58: d4048000                 ld      [%l2], %o2
F000AA5C: d002e158                 ld      [%o3+0x158], %o0
F000AA60: 80a28008                 cmp     %o2, %o0
F000AA64: 1a80000a                 bcc     loc_F000AA8C
F000AA68: 912aa002                 sll     %o2, 2, %o0
F000AA6C: d202e14c                 ld      [%o3+0x14C], %o1
F000AA70: e2024008                 ld      [%o1+%o0], %l1
F000AA74: 80a46000                 cmp     %l1, 0
F000AA78: 02800005                 be      loc_F000AA8C
F000AA7C: 113fffc0                 sethi   -0x10000, %o0
F000AA80: 80a44008                 cmp     %l1, %o0
F000AA84: 32800005                 bne,a   loc_F000AA98
F000AA88: d204a004                 ld      [%l2+4], %o1
F000AA8C: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000AA90: 108000ce                 ba      loc_F000ADC8
F000AA94: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F000AA98: d002e150                 ld      [%o3+0x150], %o0
F000AA9C: 80a26009                 cmp     %o1, 9! switch 10 cases
F000AAA0: 1880011a                 bgu     def_F000AAB8! jumptable F000AAB8 default case
F000AAA4: a602000a                 add     %o0, %o2, %l3
F000AAA8: 113c002a901222c0         set     jpt_F000AAB8, %o0
F000AAB0: 932a6002                 sll     %o1, 2, %o1
F000AAB4: d0024008                 ld      [%o1+%o0], %o0
F000AAB8: 81c20000                 jmp     %o0! switch jump
F000AABC: 01000000                 nop
F000AAE8: d604a008                 ld      [%l2+8], %o3! jumptable F000AAB8 case 0
F000AAEC: 80a2e0ff                 cmp     %o3, 0xFF
F000AAF0: 08800004                 bleu    loc_F000AB00
F000AAF4: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000AAF8: 108000d0                 ba      loc_F000AE38
F000AAFC: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F000AB00: 400001e4                 call    _ufalloc
F000AB04: 9010000b                 mov     %o3, %o0
F000AB08: 96920000                 orcc    %o0, %g0, %o3
F000AB0C: 06800101                 bl      locret_F000AF10
F000AB10: 153c04cf                 sethi   %hi(_active_u), %o2
F000AB14: d202a1d8                 ld      [%o2+%lo(_active_u)], %o1
F000AB18: d0048000                 ld      [%l2], %o0
F000AB1C: d202614c                 ld      [%o1+0x14C], %o1
F000AB20: 912a2002                 sll     %o0, 2, %o0
F000AB24: d0024008                 ld      [%o1+%o0], %o0
F000AB28: 80a44008                 cmp     %l1, %o0
F000AB2C: 02800006                 be      loc_F000AB44
F000AB30: 9412a1d8                 bset    %lo(_active_u), %o2
F000AB34: 912ae002                 sll     %o3, 2, %o0
F000AB38: c0224008                 clr     [%o1+%o0]
F000AB3C: 108000a3                 ba      loc_F000ADC8
F000AB40: d202a004                 ld      [%o2+4], %o1
F000AB44: 9010000b                 mov     %o3, %o0
F000AB48: d40cc000                 ldub    [%l3], %o2
F000AB4C: 92100011                 mov     %l1, %o1
F000AB50: 940abffe                 and     %o2, -2, %o2
F000AB54: 952aa018                 sll     %o2, 24, %o2
F000AB58: 7fffffa0                 call    _dupit
F000AB5C: 953aa018                 sra     %o2, 24, %o2
F000AB60: 308000ec                 ba,a    locret_F000AF10
F000AB64: d00cc000                 ldub    [%l3], %o0! jumptable F000AAB8 case 1
F000AB68: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F000AB6C: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F000AB70: 900a2001                 and     %o0, 1, %o0
F000AB74: 108000e7                 ba      locret_F000AF10
F000AB78: d0226030                 st      %o0, [%o1+0x30]
F000AB7C: d20cc000                 ldub    [%l3], %o1! jumptable F000AAB8 case 2
F000AB80: d004a008                 ld      [%l2+8], %o0
F000AB84: 920a7ffe                 and     %o1, -2, %o1
F000AB88: 900a2001                 and     %o0, 1, %o0
F000AB8C: 92124008                 bset    %o0, %o1
F000AB90: 108000e0                 ba      locret_F000AF10
F000AB94: d22cc000                 stb     %o1, [%l3]
F000AB98: d0046008                 ld      [%l1+8], %o0! jumptable F000AAB8 case 3
F000AB9C: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F000ABA0: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F000ABA4: 90023fff                 inc     -1, %o0
F000ABA8: 108000da                 ba      locret_F000AF10
F000ABAC: d0226030                 st      %o0, [%o1+0x30]
F000ABB0: 113c04cf                 sethi   %hi(_active_u), %o0! jumptable F000AAB8 case 4
F000ABB4: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F000ABB8: d0020000                 ld      [%o0], %o0
F000ABBC: d2022014                 ld      [%o0+0x14], %o1
F000ABC0: 11000010                 sethi   0x4000, %o0
F000ABC4: 808a4008                 btst    %o0, %o1
F000ABC8: 02800005                 be      loc_F000ABDC
F000ABCC: e0046008                 ld      [%l1+8], %l0
F000ABD0: 1110000c                 sethi   0x40003000, %o0
F000ABD4: 10800004                 ba      loc_F000ABE4
F000ABD8: 901221b3                 bset    0x1B3, %o0
F000ABDC: 11000008901221b3         set     0x21B3, %o0
F000ABE4: a00c0008                 and     %l0, %o0, %l0
F000ABE8: 90100011                 mov     %l1, %o0
F000ABEC: 292001199215227e         set     -0x7FFB9982, %o1
F000ABF4: a607bfdc                 add     %fp, var_24, %l3
F000ABF8: 94100013                 mov     %l3, %o2
F000ABFC: 173ffff7                 sethi   -0x2400, %o3
F000AC00: d804a008                 ld      [%l2+8], %o4
F000AC04: 9612e24c                 bset    0x24C, %o3
F000AC08: 98032001                 inc     %o4
F000AC0C: 980b000b                 and     %o4, %o3, %o4! int
F000AC10: a014000c                 bset    %o4, %l0
F000AC14: 97342002                 srl     %l0, 2, %o3
F000AC18: 960ae001                 and     %o3, 1, %o3
F000AC1C: 40000106                 call    _fioctl
F000AC20: d627bfdc                 st      %o3, [%fp+var_24]
F000AC24: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F000AC28: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F000AC2C: d02a6038                 stb     %o0, [%o1+0x38]
F000AC30: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F000AC34: d04a2038                 ldsb    [%o0+0x38], %o0
F000AC38: 80a22000                 cmp     %o0, 0
F000AC3C: 128000b5                 bne     locret_F000AF10
F000AC40: 91342006                 srl     %l0, 6, %o0
F000AC44: 900a2001                 and     %o0, 1, %o0
F000AC48: d027bfdc                 st      %o0, [%fp+var_24]
F000AC4C: 90100011                 mov     %l1, %o0
F000AC50: 132001199212627d         set     -0x7FFB9983, %o1
F000AC58: 400000f7                 call    _fioctl
F000AC5C: 94100013                 mov     %l3, %o2
F000AC60: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F000AC64: d02a6038                 stb     %o0, [%o1+0x38]
F000AC68: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F000AC6C: d04a2038                 ldsb    [%o0+0x38], %o0
F000AC70: 80a22000                 cmp     %o0, 0
F000AC74: 0280000a                 be      loc_F000AC9C
F000AC78: 90100011                 mov     %l1, %o0
F000AC7C: 9215227e                 or      %l4, 0x27E, %o1
F000AC80: d6022008                 ld      [%o0+8], %o3
F000AC84: 94100013                 mov     %l3, %o2
F000AC88: 9732e002                 srl     %o3, 2, %o3
F000AC8C: 960ae001                 and     %o3, 1, %o3! int
F000AC90: 400000e9                 call    _fioctl
F000AC94: d627bfdc                 st      %o3, [%fp+var_24]
F000AC98: 3080009e                 ba,a    locret_F000AF10
F000AC9C: 1080009d                 ba      locret_F000AF10
F000ACA0: e0246008                 st      %l0, [%l1+8]
F000ACA4: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0! jumptable F000AAB8 case 5
F000ACA8: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F000ACAC: 90100011                 mov     %l1, %o0
F000ACB0: 400000b0                 call    _fgetown
F000ACB4: 92026030                 inc     0x30, %o1 ! '0'
F000ACB8: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F000ACBC: 10800095                 ba      locret_F000AF10
F000ACC0: d02a6038                 stb     %o0, [%o1+0x38]
F000ACC4: d204a008                 ld      [%l2+8], %o1! jumptable F000AAB8 case 6
F000ACC8: 400000be                 call    _fsetown
F000ACCC: 90100011                 mov     %l1, %o0
F000ACD0: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F000ACD4: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F000ACD8: 1080008e                 ba      locret_F000AF10
F000ACDC: d02a6038                 stb     %o0, [%o1+0x38]
F000ACE0: d054600c                 ldsh    [%l1+0xC], %o0! jumptable F000AAB8 cases 7-9
F000ACE4: 80a22001                 cmp     %o0, 1
F000ACE8: 02800004                 be      loc_F000ACF8
F000ACEC: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000ACF0: 10800036                 ba      loc_F000ADC8
F000ACF4: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F000ACF8: 153c04cf                 sethi   %hi(_active_u), %o2! int
F000ACFC: d002a1d8                 ld      [%o2+%lo(_active_u)], %o0
F000AD00: d0020000                 ld      [%o0], %o0
F000AD04: d2022014                 ld      [%o0+0x14], %o1
F000AD08: 11000010                 sethi   0x4000, %o0
F000AD0C: 808a4008                 btst    %o0, %o1
F000AD10: 02800007                 be      loc_F000AD2C
F000AD14: a012a1d8                 or      %o2, %lo(_active_u), %l0
F000AD18: d0046018                 ld      [%l1+0x18], %o0
F000AD1C: d0022028                 ld      [%o0+0x28], %o0
F000AD20: 80a22001                 cmp     %o0, 1
F000AD24: 02800004                 be      loc_F000AD34
F000AD28: 9207bfe0                 add     %fp, var_20, %o1
F000AD2C: 10800043                 ba      loc_F000AE38
F000AD30: d2042004                 ld      [%l0+4], %o1! int
F000AD34: d004a008                 ld      [%l2+8], %o0! int
F000AD38: 400234c8                 call    _copyin
F000AD3C: 94102014                 mov     0x14, %o2
F000AD40: 932a2018                 sll     %o0, 24, %o1
F000AD44: d4042004                 ld      [%l0+4], %o2
F000AD48: 80a26000                 cmp     %o1, 0
F000AD4C: 12800071                 bne     locret_F000AF10
F000AD50: d02aa038                 stb     %o0, [%o2+0x38]
F000AD54: d057bfe0                 ldsh    [%fp+var_20], %o0
F000AD58: 80a22002                 cmp     %o0, 2
F000AD5C: 22800013                 be,a    loc_F000ADA8
F000AD60: d004a004                 ld      [%l2+4], %o0
F000AD64: 14800007                 bg      loc_F000AD80
F000AD68: 80a22003                 cmp     %o0, 3
F000AD6C: 80a22001                 cmp     %o0, 1
F000AD70: 22800008                 be,a    loc_F000AD90
F000AD74: d004a004                 ld      [%l2+4], %o0
F000AD78: 10800017                 ba      loc_F000ADD4
F000AD7C: 113c04cf                 sethi   -0xFECC400, %o0
F000AD80: 02800017                 be      loc_F000ADDC
F000AD84: 9007bfe0                 add     %fp, var_20, %o0
F000AD88: 10800013                 ba      loc_F000ADD4
F000AD8C: 113c04cf                 sethi   -0xFECC400, %o0
F000AD90: 80a22007                 cmp     %o0, 7
F000AD94: 02800012                 be      loc_F000ADDC
F000AD98: 9007bfe0                 add     %fp, var_20, %o0
F000AD9C: d0046008                 ld      [%l1+8], %o0
F000ADA0: 10800007                 ba      loc_F000ADBC
F000ADA4: 808a2001                 btst    1, %o0
F000ADA8: 80a22007                 cmp     %o0, 7
F000ADAC: 0280000c                 be      loc_F000ADDC
F000ADB0: 9007bfe0                 add     %fp, var_20, %o0
F000ADB4: d0046008                 ld      [%l1+8], %o0
F000ADB8: 808a2002                 btst    2, %o0
F000ADBC: 12800008                 bne     loc_F000ADDC
F000ADC0: 9007bfe0                 add     %fp, var_20, %o0
F000ADC4: d2042004                 ld      [%l0+4], %o1
F000ADC8: 90102009                 mov     9, %o0
F000ADCC: 10800051                 ba      locret_F000AF10
F000ADD0: d02a6038                 stb     %o0, [%o1+0x38]
F000ADD4: 10800019                 ba      loc_F000AE38
F000ADD8: d20221dc                 ld      [%o0+0x1DC], %o1
F000ADDC: 92100011                 mov     %l1, %o1
F000ADE0: 400001f4                 call    _rewhence
F000ADE4: 94102000                 mov     0, %o2
F000ADE8: 173c04cf                 sethi   %hi(dword_F0133DDC), %o3
F000ADEC: d402e1dc                 ld      [%o3+%lo(dword_F0133DDC)], %o2
F000ADF0: 932a2018                 sll     %o0, 24, %o1
F000ADF4: 80a26000                 cmp     %o1, 0
F000ADF8: 9812e1dc                 or      %o3, %lo(dword_F0133DDC), %o4
F000ADFC: 12800045                 bne     locret_F000AF10
F000AE00: d02aa038                 stb     %o0, [%o2+0x38]
F000AE04: d407bfe8                 ld      [%fp+var_18], %o2
F000AE08: 80a2a000                 cmp     %o2, 0
F000AE0C: 16800007                 bge     loc_F000AE28
F000AE10: d007bfe4                 ld      [%fp+var_1C], %o0
F000AE14: 9220000a                 neg     %o2, %o1
F000AE18: d227bfe8                 st      %o1, [%fp+var_18]
F000AE1C: 9002000a                 add     %o0, %o2, %o0
F000AE20: d027bfe4                 st      %o0, [%fp+var_1C]
F000AE24: d007bfe4                 ld      [%fp+var_1C], %o0
F000AE28: 80a22000                 cmp     %o0, 0
F000AE2C: 36800006                 bge,a   loc_F000AE44
F000AE30: d004a004                 ld      [%l2+4], %o0
F000AE34: d202e1dc                 ld      [%o3+0x1DC], %o1
F000AE38: 90102016                 mov     0x16, %o0
F000AE3C: 10800035                 ba      locret_F000AF10
F000AE40: d02a6038                 stb     %o0, [%o1+0x38]
F000AE44: 80a22007                 cmp     %o0, 7
F000AE48: 0280000d                 be      loc_F000AE7C
F000AE4C: d057bfe0                 ldsh    [%fp+var_20], %o0
F000AE50: 80a22003                 cmp     %o0, 3
F000AE54: 0280000a                 be      loc_F000AE7C
F000AE58: 13080000                 sethi   0x20000000, %o1
F000AE5C: d00cc000                 ldub    [%l3], %o0
F000AE60: 90122004                 bset    4, %o0
F000AE64: d02cc000                 stb     %o0, [%l3]
F000AE68: d0033ffc                 ld      [%o4-4], %o0
F000AE6C: d4020000                 ld      [%o0], %o2
F000AE70: d002a028                 ld      [%o2+0x28], %o0
F000AE74: 90120009                 bset    %o1, %o0
F000AE78: d022a028                 st      %o0, [%o2+0x28]
F000AE7C: d404a004                 ld      [%l2+4], %o2
F000AE80: d0046018                 ld      [%l1+0x18], %o0
F000AE84: 053c04cf                 sethi   %hi(_active_u), %g2
F000AE88: d200a1d8                 ld      [%g2+%lo(_active_u)], %o1
F000AE8C: d602201c                 ld      [%o0+0x1C], %o3
F000AE90: d8024000                 ld      [%o1], %o4
F000AE94: da02e060                 ld      [%o3+0x60], %o5! int
F000AE98: a007bfe0                 add     %fp, var_20, %l0
F000AE9C: d6046020                 ld      [%l1+0x20], %o3! int
F000AEA0: 92100010                 mov     %l0, %o1
F000AEA4: d8532030                 ldsh    [%o4+0x30], %o4! int
F000AEA8: 9fc34000                 call    %o5
F000AEAC: a210a1d8                 or      %g2, %lo(_active_u), %l1
F000AEB0: 932a2018                 sll     %o0, 24, %o1
F000AEB4: d4046004                 ld      [%l1+4], %o2
F000AEB8: 80a26000                 cmp     %o1, 0
F000AEBC: 12800015                 bne     locret_F000AF10
F000AEC0: d02aa038                 stb     %o0, [%o2+0x38]
F000AEC4: d004a004                 ld      [%l2+4], %o0
F000AEC8: 80a22007                 cmp     %o0, 7
F000AECC: 12800011                 bne     locret_F000AF10
F000AED0: d057bfe0                 ldsh    [%fp+var_20], %o0
F000AED4: 80a22003                 cmp     %o0, 3
F000AED8: 12800005                 bne     loc_F000AEEC
F000AEDC: 90100010                 mov     %l0, %o0! int
F000AEE0: d204a008                 ld      [%l2+8], %o1
F000AEE4: 10800004                 ba      loc_F000AEF4
F000AEE8: 94102002                 mov     2, %o2
F000AEEC: d204a008                 ld      [%l2+8], %o1! int
F000AEF0: 94102014                 mov     0x14, %o2! int
F000AEF4: 40023476                 call    _copyout
F000AEF8: 01000000                 nop
F000AEFC: d2046004                 ld      [%l1+4], %o1
F000AF00: 10800004                 ba      locret_F000AF10
F000AF04: d02a6038                 stb     %o0, [%o1+0x38]
F000AF08: 90102016                 mov     0x16, %o0! jumptable F000AAB8 default case
F000AF0C: d02b2038                 stb     %o0, [%o4+0x38]
F000AF10: 81c7e008                 ret
F000AF14: 81e80000                 restore
