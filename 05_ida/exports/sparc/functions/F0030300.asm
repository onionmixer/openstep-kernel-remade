F0030300: 9de3bf90                 save    %sp, -0x70, %sp
F0030304: 90102001                 mov     1, %o0! __s
F0030308: d027bff4                 st      %o0, [%fp+var_C]
F003030C: a2102000                 mov     0, %l1
F0030310: a006a0f4                 add     %i2, 0xF4, %l0
F0030314: 7fff5c49                 call    _strlen
F0030318: 90100010                 mov     %l0, %o0
F003031C: 80a22037                 cmp     %o0, 0x37 ! '7'
F0030320: a4066108                 add     %i1, 0x108, %l2
F0030324: 08800003                 bleu    loc_F0030330
F0030328: a606a0ec                 add     %i2, 0xEC, %l3
F003032C: c02ea12b                 clrb    [%i2+0x12B]
F0030330: 113c043190122190         set     aS_1, %o0! "%s"
F0030338: 7fff90c8                 call    _printf
F003033C: 92100010                 mov     %l0, %o1
F0030340: 90102000                 mov     0, %o0
F0030344: 1320011d92126010         set     -0x7FFB8BF0, %o1
F003034C: 9407bff4                 add     %fp, var_C, %o2
F0030350: 40022d88                 call    _kmioctl
F0030354: 96102000                 mov     0, %o3
F0030358: b0920000                 orcc    %o0, %g0, %i0
F003035C: 12800034                 bne     locret_F003042C
F0030360: 01000000                 nop
F0030364: d00ea0f2                 ldub    [%i2+0xF2], %o0
F0030368: 80a22002                 cmp     %o0, 2
F003036C: 2280000b                 be,a    loc_F0030398
F0030370: a2102001                 mov     1, %l1
F0030374: 14800006                 bg      loc_F003038C
F0030378: 80a22003                 cmp     %o0, 3
F003037C: 80a22001                 cmp     %o0, 1
F0030380: 22800007                 be,a    loc_F003039C
F0030384: b0102000                 mov     0, %i0
F0030388: 30800029                 ba,a    locret_F003042C
F003038C: 02800025                 be      loc_F0030420
F0030390: 90103fff                 mov     -1, %o0
F0030394: 30800026                 ba,a    locret_F003042C
F0030398: b0102000                 mov     0, %i0
F003039C: a004a008                 add     %l2, 8, %l0
F00303A0: 90100010                 mov     %l0, %o0
F00303A4: 92100010                 mov     %l0, %o1
F00303A8: 4000007d                 call    sub_F003059C
F00303AC: 94100011                 mov     %l1, %o2
F00303B0: 80a46000                 cmp     %l1, 0
F00303B4: 02800004                 be      loc_F00303C4
F00303B8: 113c0431                 sethi   %hi(asc_F010C598), %o0! "\n"
F00303BC: 7fff90a7                 call    _printf
F00303C0: 90122198                 bset    %lo(asc_F010C598), %o0! "\n"
F00303C4: d04ca008                 ldsb    [%l2+8], %o0
F00303C8: 80a22000                 cmp     %o0, 0
F00303CC: 0280000e                 be      loc_F0030404
F00303D0: 92100010                 mov     %l0, %o1
F00303D4: d04a4000                 ldsb    [%o1], %o0
F00303D8: 80a2200a                 cmp     %o0, 0xA
F00303DC: 02800004                 be      loc_F00303EC
F00303E0: 80a2200d                 cmp     %o0, 0xD
F00303E4: 32800004                 bne,a   loc_F00303F4
F00303E8: 92026001                 inc     %o1
F00303EC: 10800006                 ba      loc_F0030404
F00303F0: c02a4000                 clrb    [%o1]
F00303F4: d04a4000                 ldsb    [%o1], %o0
F00303F8: 80a22000                 cmp     %o0, 0
F00303FC: 12bffff8                 bne     loc_F00303DC
F0030400: 80a2200a                 cmp     %o0, 0xA
F0030404: d006a014                 ld      [%i2+0x14], %o0
F0030408: d0266010                 st      %o0, [%i1+0x10]
F003040C: d00ce006                 ldub    [%l3+6], %o0
F0030410: d02ca006                 stb     %o0, [%l2+6]
F0030414: d00ce007                 ldub    [%l3+7], %o0
F0030418: 10800005                 ba      locret_F003042C
F003041C: d02ca007                 stb     %o0, [%l2+7]
F0030420: d0266010                 st      %o0, [%i1+0x10]
F0030424: c02e610e                 clrb    [%i1+0x10E]
F0030428: c02e610f                 clrb    [%i1+0x10F]
F003042C: 81c7e008                 ret
F0030430: 81e80000                 restore
