F00E53C4: 9de3bf78                 save    %sp, -0x88, %sp
F00E53C8: 90100019                 mov     %i1, %o0
F00E53CC: 133c03f2a01262b8         set     aAddress, %l0! "address"
F00E53D4: 92100010                 mov     %l0, %o1
F00E53D8: 173c04bb                 sethi   %hi(_sparcfbs), %o3
F00E53DC: 952e2004                 sll     %i0, 4, %o2
F00E53E0: 94028018                 add     %o2, %i0, %o2
F00E53E4: 952aa002                 sll     %o2, 2, %o2
F00E53E8: d602e364                 ld      [%o3+%lo(_sparcfbs)], %o3
F00E53EC: 9402a008                 inc     8, %o2
F00E53F0: 7fff26fb                 call    _prom_getproplen
F00E53F4: b002c00a                 add     %o3, %o2, %i0
F00E53F8: 80a22000                 cmp     %o0, 0
F00E53FC: 34800003                 bg,a    loc_F00E5408
F00E5400: 90102001                 mov     1, %o0
F00E5404: 90102000                 mov     0, %o0
F00E5408: 80a22000                 cmp     %o0, 0
F00E540C: 0280000a                 be      loc_F00E5434
F00E5410: 80a22004                 cmp     %o0, 4
F00E5414: 04800004                 ble     loc_F00E5424
F00E5418: 113c03f2                 sethi   %hi(aBufferTooSmall), %o0! "buffer too small\n"
F00E541C: 7ffcbc8f                 call    _printf
F00E5420: 901222c0                 bset    %lo(aBufferTooSmall), %o0! "buffer too small\n"
F00E5424: 90100019                 mov     %i1, %o0
F00E5428: 92100010                 mov     %l0, %o1
F00E542C: 7fff26f6                 call    _prom_getprop
F00E5430: 9407bfe4                 add     %fp, var_1C, %o2
F00E5434: 90100019                 mov     %i1, %o0
F00E5438: 133c03f2921262d8         set     aReg, %o1! "reg"
F00E5440: 7fff26f1                 call    _prom_getprop
F00E5444: 9407bfe8                 add     %fp, var_18, %o2
F00E5448: 90102001                 mov     1, %o0
F00E544C: d0260000                 st      %o0, [%i0]
F00E5450: c0262004                 clr     [%i0+4]
F00E5454: 90100019                 mov     %i1, %o0
F00E5458: 133c03f2a01262e0         set     aWidth, %l0! "width"
F00E5460: 7fff26df                 call    _prom_getproplen
F00E5464: 92100010                 mov     %l0, %o1
F00E5468: 80a22000                 cmp     %o0, 0
F00E546C: 2280000e                 be,a    loc_F00E54A4
F00E5470: 90102001                 mov     1, %o0
F00E5474: 0480000b                 ble     loc_F00E54A0
F00E5478: 80a22004                 cmp     %o0, 4
F00E547C: 02800004                 be      loc_F00E548C
F00E5480: 90100019                 mov     %i1, %o0
F00E5484: 10800008                 ba      loc_F00E54A4
F00E5488: 90102480                 mov     0x480, %o0
F00E548C: 92100010                 mov     %l0, %o1
F00E5490: 7fff26dd                 call    _prom_getprop
F00E5494: 9407bfdc                 add     %fp, var_24, %o2
F00E5498: 10800003                 ba      loc_F00E54A4
F00E549C: d007bfdc                 ld      [%fp+var_24], %o0
F00E54A0: 90102480                 mov     0x480, %o0
F00E54A4: d0262020                 st      %o0, [%i0+0x20]
F00E54A8: 90100019                 mov     %i1, %o0
F00E54AC: 133c03f2a01262e8         set     aHeight, %l0! "height"
F00E54B4: 7fff26ca                 call    _prom_getproplen
F00E54B8: 92100010                 mov     %l0, %o1
F00E54BC: 80a22000                 cmp     %o0, 0
F00E54C0: 2280000e                 be,a    loc_F00E54F8
F00E54C4: 90102001                 mov     1, %o0
F00E54C8: 0480000b                 ble     loc_F00E54F4
F00E54CC: 80a22004                 cmp     %o0, 4
F00E54D0: 02800004                 be      loc_F00E54E0
F00E54D4: 90100019                 mov     %i1, %o0
F00E54D8: 10800008                 ba      loc_F00E54F8
F00E54DC: 90102384                 mov     0x384, %o0
F00E54E0: 92100010                 mov     %l0, %o1
F00E54E4: 7fff26c8                 call    _prom_getprop
F00E54E8: 9407bfdc                 add     %fp, var_24, %o2
F00E54EC: 10800003                 ba      loc_F00E54F8
F00E54F0: d007bfdc                 ld      [%fp+var_24], %o0
F00E54F4: 90102384                 mov     0x384, %o0
F00E54F8: d0262024                 st      %o0, [%i0+0x24]
F00E54FC: d007bfe4                 ld      [%fp+var_1C], %o0
F00E5500: d0262014                 st      %o0, [%i0+0x14]
F00E5504: d007bfe4                 ld      [%fp+var_1C], %o0
F00E5508: d0262018                 st      %o0, [%i0+0x18]
F00E550C: e226200c                 st      %l1, [%i0+0xC]
F00E5510: d0062020                 ld      [%i0+0x20], %o0
F00E5514: d2062024                 ld      [%i0+0x24], %o1
F00E5518: 7ffc83fa                 call    _umul
F00E551C: 01000000                 nop
F00E5520: d026201c                 st      %o0, [%i0+0x1C]
F00E5524: 90102008                 mov     8, %o0
F00E5528: d0262030                 st      %o0, [%i0+0x30]
F00E552C: 90102001                 mov     1, %o0
F00E5530: d0262034                 st      %o0, [%i0+0x34]
F00E5534: d0062020                 ld      [%i0+0x20], %o0
F00E5538: d2062034                 ld      [%i0+0x34], %o1
F00E553C: 7ffc83f1                 call    _umul
F00E5540: 01000000                 nop
F00E5544: d0262038                 st      %o0, [%i0+0x38]
F00E5548: 81c7e008                 ret
F00E554C: 91e82000                 restore %g0, 0, %o0
