F002174C: 9de3bf78                 save    %sp, -0x88, %sp
F0021750: 40000320                 call    _getsock
F0021754: 90100018                 mov     %i0, %o0
F0021758: a4920000                 orcc    %o0, %g0, %l2
F002175C: 0280006a                 be      locret_F0021904
F0021760: a2102000                 mov     0, %l1
F0021764: d0066008                 ld      [%i1+8], %o0
F0021768: d027bfe0                 st      %o0, [%fp+var_20]
F002176C: d006600c                 ld      [%i1+0xC], %o0
F0021770: d027bfe4                 st      %o0, [%fp+var_1C]
F0021774: c027bfec                 clr     [%fp+var_14]
F0021778: c027bfe8                 clr     [%fp+var_18]
F002177C: c027bff4                 clr     [%fp+var_C]
F0021780: c037bff0                 clrh    [%fp+var_10]
F0021784: d006600c                 ld      [%i1+0xC], %o0
F0021788: 80a44008                 cmp     %l1, %o0
F002178C: 16800018                 bge     loc_F00217EC
F0021790: f0066008                 ld      [%i1+8], %i0
F0021794: a0062004                 add     %i0, 4, %l0
F0021798: d2040000                 ld      [%l0], %o1
F002179C: 80a26000                 cmp     %o1, 0
F00217A0: 06800036                 bl      loc_F0021878
F00217A4: 113c04cf                 sethi   -0xFECC400, %o0
F00217A8: 2280000c                 be,a    loc_F00217D8
F00217AC: a2046001                 inc     %l1
F00217B0: d0060000                 ld      [%i0], %o0
F00217B4: 4001a185                 call    _useracc
F00217B8: 94102001                 mov     1, %o2
F00217BC: 80a22000                 cmp     %o0, 0
F00217C0: 02800032                 be      loc_F0021888
F00217C4: d007bff4                 ld      [%fp+var_C], %o0
F00217C8: d2040000                 ld      [%l0], %o1
F00217CC: 90020009                 add     %o0, %o1, %o0
F00217D0: d027bff4                 st      %o0, [%fp+var_C]
F00217D4: a2046001                 inc     %l1
F00217D8: a0042008                 inc     8, %l0
F00217DC: d006600c                 ld      [%i1+0xC], %o0
F00217E0: 80a44008                 cmp     %l1, %o0
F00217E4: 06bfffed                 bl      loc_F0021798
F00217E8: b0062008                 inc     8, %i0
F00217EC: d2064000                 ld      [%i1], %o1
F00217F0: 80a26000                 cmp     %o1, 0
F00217F4: 0280000f                 be      loc_F0021830
F00217F8: 9007bfdc                 add     %fp, var_24, %o0
F00217FC: d4066004                 ld      [%i1+4], %o2
F0021800: 400002da                 call    _sockargs
F0021804: 96102008                 mov     8, %o3
F0021808: 153c04cf                 sethi   %hi(dword_F0133DDC), %o2
F002180C: d202a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o1
F0021810: d02a6038                 stb     %o0, [%o1+0x38]
F0021814: d002a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o0
F0021818: d04a2038                 ldsb    [%o0+0x38], %o0
F002181C: 80a22000                 cmp     %o0, 0
F0021820: 12800039                 bne     locret_F0021904
F0021824: 01000000                 nop
F0021828: 10800004                 ba      loc_F0021838
F002182C: d2066010                 ld      [%i1+0x10], %o1
F0021830: c027bfdc                 clr     [%fp+var_24]
F0021834: d2066010                 ld      [%i1+0x10], %o1
F0021838: 80a26000                 cmp     %o1, 0
F002183C: 02800018                 be      loc_F002189C
F0021840: 9007bfd8                 add     %fp, var_28, %o0
F0021844: d4066014                 ld      [%i1+0x14], %o2
F0021848: 400002c8                 call    _sockargs
F002184C: 9610200c                 mov     0xC, %o3
F0021850: 153c04cf                 sethi   %hi(dword_F0133DDC), %o2
F0021854: d202a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o1
F0021858: d02a6038                 stb     %o0, [%o1+0x38]
F002185C: d002a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o0
F0021860: d04a2038                 ldsb    [%o0+0x38], %o0
F0021864: 80a22000                 cmp     %o0, 0
F0021868: 12800022                 bne     loc_F00218F0
F002186C: d007bfdc                 ld      [%fp+var_24], %o0
F0021870: 1080000d                 ba      loc_F00218A4
F0021874: d004a018                 ld      [%l2+0x18], %o0
F0021878: d20221dc                 ld      [%o0+0x1DC], %o1
F002187C: 90102016                 mov     0x16, %o0
F0021880: 10800021                 ba      locret_F0021904
F0021884: d02a6038                 stb     %o0, [%o1+0x38]
F0021888: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F002188C: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F0021890: 9010200e                 mov     0xE, %o0
F0021894: 1080001c                 ba      locret_F0021904
F0021898: d02a6038                 stb     %o0, [%o1+0x38]
F002189C: c027bfd8                 clr     [%fp+var_28]
F00218A0: d004a018                 ld      [%l2+0x18], %o0
F00218A4: d207bfdc                 ld      [%fp+var_24], %o1
F00218A8: e007bff4                 ld      [%fp+var_C], %l0
F00218AC: 9407bfe0                 add     %fp, var_20, %o2
F00218B0: d807bfd8                 ld      [%fp+var_28], %o4
F00218B4: 7ffff4ae                 call    _sosend
F00218B8: 9610001a                 mov     %i2, %o3
F00218BC: 153c04cf                 sethi   %hi(dword_F0133DDC), %o2
F00218C0: d202a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o1
F00218C4: d02a6038                 stb     %o0, [%o1+0x38]
F00218C8: d007bff4                 ld      [%fp+var_C], %o0
F00218CC: d202a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o1
F00218D0: a0240008                 sub     %l0, %o0, %l0
F00218D4: d007bfd8                 ld      [%fp+var_28], %o0
F00218D8: 80a22000                 cmp     %o0, 0
F00218DC: 02800004                 be      loc_F00218EC
F00218E0: e0226030                 st      %l0, [%o1+0x30]
F00218E4: 7ffff0e0                 call    _m_freem
F00218E8: 01000000                 nop
F00218EC: d007bfdc                 ld      [%fp+var_24], %o0
F00218F0: 80a22000                 cmp     %o0, 0
F00218F4: 02800004                 be      locret_F0021904
F00218F8: 01000000                 nop
F00218FC: 7ffff0da                 call    _m_freem
F0021900: 01000000                 nop
F0021904: 81c7e008                 ret
F0021908: 81e80000                 restore
