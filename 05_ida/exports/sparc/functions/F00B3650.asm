F00B3650: 9de3bf98                 save    %sp, -0x68, %sp
F00B3654: 7ffff3c8                 call    _atou
F00B3658: 90100019                 mov     %i1, %o0
F00B365C: d24e4000                 ldsb    [%i1], %o1
F00B3660: a2100008                 mov     %o0, %l1
F00B3664: 80a26000                 cmp     %o1, 0
F00B3668: 02800009                 be      loc_F00B368C
F00B366C: d40e4000                 ldub    [%i1], %o2
F00B3670: 80a2a02c                 cmp     %o2, 0x2C ! ','
F00B3674: 02800006                 be      loc_F00B368C
F00B3678: b2066001                 inc     %i1
F00B367C: d04e4000                 ldsb    [%i1], %o0
F00B3680: 80a22000                 cmp     %o0, 0
F00B3684: 12bffffb                 bne     loc_F00B3670
F00B3688: d40e4000                 ldub    [%i1], %o2
F00B368C: 7ffff3ba                 call    _atou
F00B3690: 90100019                 mov     %i1, %o0
F00B3694: a0100008                 mov     %o0, %l0
F00B3698: 133c0478                 sethi   %hi(aReg_4), %o1! "reg"
F00B369C: d0062028                 ld      [%i0+0x28], %o0
F00B36A0: 7ffff698                 call    _getproplen
F00B36A4: 92126138                 bset    %lo(aReg_4), %o1! "reg"
F00B36A8: a4100008                 mov     %o0, %l2
F00B36AC: 133c0478                 sethi   %hi(aReg_5), %o1! "reg"
F00B36B0: d0062028                 ld      [%i0+0x28], %o0
F00B36B4: 7ffff699                 call    _getlongprop
F00B36B8: 92126140                 bset    %lo(aReg_5), %o1! "reg"
F00B36BC: b2920000                 orcc    %o0, %g0, %i1
F00B36C0: 1280000b                 bne     loc_F00B36EC
F00B36C4: 113c0477                 sethi   %hi(dword_F011DFB8), %o0
F00B36C8: d00223b8                 ld      [%o0+%lo(dword_F011DFB8)], %o0
F00B36CC: 80a22000                 cmp     %o0, 0
F00B36D0: 02800005                 be      loc_F00B36E4
F00B36D4: 113c0478                 sethi   %hi(aNoAddrQualifie_0), %o0! "no addr qualifier (reg) for nodeid <%x>"...
F00B36D8: d2062028                 ld      [%i0+0x28], %o1
F00B36DC: 7ffd83df                 call    _printf
F00B36E0: 90122148                 bset    %lo(aNoAddrQualifie_0), %o0! "no addr qualifier (reg) for nodeid <%x>"...
F00B36E4: 10800018                 ba      locret_F00B3744
F00B36E8: b0102000                 mov     0, %i0
F00B36EC: d00223b8                 ld      [%o0+0x3B8], %o0
F00B36F0: 80a22000                 cmp     %o0, 0
F00B36F4: 02800009                 be      loc_F00B3718
F00B36F8: 113c0478                 sethi   %hi(aBustypeDAddrXR), %o0! "\tbustype %d addr %x; reg %d %x\n"
F00B36FC: d4062014                 ld      [%i0+0x14], %o2
F00B3700: d6028000                 ld      [%o2], %o3
F00B3704: 90122178                 bset    %lo(aBustypeDAddrXR), %o0! "\tbustype %d addr %x; reg %d %x\n"
F00B3708: d802a004                 ld      [%o2+4], %o4
F00B370C: 92100011                 mov     %l1, %o1
F00B3710: 7ffd83d2                 call    _printf
F00B3714: 94100010                 mov     %l0, %o2
F00B3718: d0064000                 ld      [%i1], %o0
F00B371C: 80a44008                 cmp     %l1, %o0
F00B3720: 12800006                 bne     loc_F00B3738
F00B3724: b0102000                 mov     0, %i0
F00B3728: d0066004                 ld      [%i1+4], %o0
F00B372C: 901c0008                 btog    %l0, %o0
F00B3730: 80a00008                 cmp     %g0, %o0
F00B3734: b0603fff                 subc    %g0, -1, %i0
F00B3738: 90100019                 mov     %i1, %o0
F00B373C: 7ffed299                 call    _kfree
F00B3740: 92100012                 mov     %l2, %o1
F00B3744: 81c7e008                 ret
F00B3748: 81e80000                 restore
