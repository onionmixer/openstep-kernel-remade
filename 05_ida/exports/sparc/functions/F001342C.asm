F001342C: 9de3bf90                 save    %sp, -0x70, %sp
F0013430: 90100018                 mov     %i0, %o0! unsigned int
F0013434: 7ffff850                 call    _psignal
F0013438: 9210200e                 mov     0xE, %o1
F001343C: d0062054                 ld      [%i0+0x54], %o0
F0013440: 80a22000                 cmp     %o0, 0
F0013444: 12800009                 bne     loc_F0013468
F0013448: 01000000                 nop
F001344C: d0062058                 ld      [%i0+0x58], %o0
F0013450: 80a22000                 cmp     %o0, 0
F0013454: 12800005                 bne     loc_F0013468
F0013458: 01000000                 nop
F001345C: c0262060                 clr     [%i0+0x60]
F0013460: 10800037                 ba      locret_F001353C
F0013464: c026205c                 clr     [%i0+0x5C]
F0013468: 7ffffec9                 call    _getthetime
F001346C: 9007bff0                 add     %fp, var_10, %o0
F0013470: 40020dd2                 call    _spltty
F0013474: 01000000                 nop
F0013478: d407bff0                 ld      [%fp+var_10], %o2
F001347C: a2100008                 mov     %o0, %l1
F0013480: d206205c                 ld      [%i0+0x5C], %o1
F0013484: 9002bff6                 add     %o2, -0xA, %o0
F0013488: 80a24008                 cmp     %o1, %o0
F001348C: 1680000b                 bge     loc_F00134B8
F0013490: 9006205c                 add     %i0, 0x5C, %o0 ! '\'
F0013494: d426205c                 st      %o2, [%i0+0x5C]
F0013498: d207bff4                 ld      [%fp+var_C], %o1
F001349C: 213c004da014202c         set     _realitexpire, %l0
F00134A4: 7fffdaf2                 call    _hzto
F00134A8: d2262060                 st      %o1, [%i0+0x60]
F00134AC: 94100008                 mov     %o0, %o2
F00134B0: 1080001b                 ba      loc_F001351C
F00134B4: 90100010                 mov     %l0, %o0
F00134B8: 40020e1b                 call    _splx
F00134BC: 90100011                 mov     %l1, %o0
F00134C0: a006205c                 add     %i0, 0x5C, %l0 ! '\'
F00134C4: 253c004d                 sethi   -0xFFECC00, %l2
F00134C8: 40020dbc                 call    _spltty
F00134CC: 01000000                 nop
F00134D0: a2100008                 mov     %o0, %l1
F00134D4: 90100010                 mov     %l0, %o0
F00134D8: 40000069                 call    _timevaladd
F00134DC: 92062054                 add     %i0, 0x54, %o1 ! 'T'
F00134E0: d206205c                 ld      [%i0+0x5C], %o1
F00134E4: d007bff0                 ld      [%fp+var_10], %o0
F00134E8: 80a24008                 cmp     %o1, %o0
F00134EC: 14800008                 bg      loc_F001350C
F00134F0: 01000000                 nop
F00134F4: 1280000f                 bne     loc_F0013530
F00134F8: d007bff4                 ld      [%fp+var_C], %o0
F00134FC: d2062060                 ld      [%i0+0x60], %o1
F0013500: 80a24008                 cmp     %o1, %o0
F0013504: 0480000b                 ble     loc_F0013530
F0013508: 01000000                 nop
F001350C: 7fffdad8                 call    _hzto
F0013510: 90100010                 mov     %l0, %o0
F0013514: 94100008                 mov     %o0, %o2
F0013518: 9014a02c                 or      %l2, 0x2C, %o0! int
F001351C: 7fffdac3                 call    _timeout
F0013520: 92100018                 mov     %i0, %o1
F0013524: 40020e00                 call    _splx
F0013528: 90100011                 mov     %l1, %o0
F001352C: 30800004                 ba,a    locret_F001353C
F0013530: 40020dfd                 call    _splx
F0013534: 90100011                 mov     %l1, %o0
F0013538: 30bfffe4                 ba,a    loc_F00134C8
F001353C: 81c7e008                 ret
F0013540: 81e80000                 restore
