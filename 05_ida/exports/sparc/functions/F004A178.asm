F004A178: 9de3bf88                 save    %sp, -0x78, %sp
F004A17C: e4062050                 ld      [%i0+0x50], %l2
F004A180: d404a030                 ld      [%l2+0x30], %o2
F004A184: 80a6800a                 cmp     %i2, %o2
F004A188: 18800006                 bgu     loc_F004A1A0
F004A18C: 113c043a                 sethi   -0xFEF1800, %o0
F004A190: d004a04c                 ld      [%l2+0x4C], %o0
F004A194: 80ae8008                 andncc  %i2, %o0, %g0
F004A198: 0280000a                 be      loc_F004A1C0
F004A19C: 113c043a                 sethi   -0xFEF1800, %o0
F004A1A0: 90122018                 bset    0x18, %o0! char *
F004A1A4: d2562046                 ldsh    [%i0+0x46], %o1
F004A1A8: 9610001a                 mov     %i2, %o3
F004A1AC: 7fff292b                 call    _printf
F004A1B0: 9804a0d4                 add     %l2, 0xD4, %o4
F004A1B4: 113c043a                 sethi   %hi(aFreeBlockBadSi), %o0! "free_block: bad size"
F004A1B8: 7fff2bee                 call    _panic
F004A1BC: 90122048                 bset    %lo(aFreeBlockBadSi), %o0! "free_block: bad size"
F004A1C0: d204a0bc                 ld      [%l2+0xBC], %o1! int
F004A1C4: 7ffef111                 call    _div
F004A1C8: 90100019                 mov     %i1, %o0
F004A1CC: ae100008                 mov     %o0, %l7
F004A1D0: 90100012                 mov     %l2, %o0
F004A1D4: 400017fb                 call    _badblock
F004A1D8: 92100019                 mov     %i1, %o1
F004A1DC: 80a22000                 cmp     %o0, 0
F004A1E0: 02800007                 be      loc_F004A1FC
F004A1E4: 113c043a                 sethi   %hi(aBadBlockDInoD), %o0! "bad block %d, ino %d\n"
F004A1E8: 90122060                 bset    %lo(aBadBlockDInoD), %o0! "bad block %d, ino %d\n"
F004A1EC: d4062048                 ld      [%i0+0x48], %o2
F004A1F0: 7fff291a                 call    _printf
F004A1F4: 92100019                 mov     %i1, %o1
F004A1F8: 3080011d                 ba,a    locret_F004A66C
F004A1FC: d004a0bc                 ld      [%l2+0xBC], %o0
F004A200: 7ffef0c0                 call    _umul
F004A204: 92100017                 mov     %l7, %o1
F004A208: d404a018                 ld      [%l2+0x18], %o2
F004A20C: a0100008                 mov     %o0, %l0
F004A210: d204a01c                 ld      [%l2+0x1C], %o1
F004A214: 9010000a                 mov     %o2, %o0
F004A218: 7ffef0ba                 call    _umul
F004A21C: 922dc009                 andn    %l7, %o1, %o1
F004A220: d404a0a0                 ld      [%l2+0xA0], %o2
F004A224: 96100008                 mov     %o0, %o3
F004A228: d2062040                 ld      [%i0+0x40], %o1
F004A22C: a004000b                 add     %l0, %o3, %l0
F004A230: d804a00c                 ld      [%l2+0xC], %o4
F004A234: 90100009                 mov     %o1, %o0
F004A238: d204a064                 ld      [%l2+0x64], %o1
F004A23C: a004000c                 add     %l0, %o4, %l0
F004A240: 7fff68b8                 call    _bread
F004A244: 932c0009                 sll     %l0, %o1, %o1
F004A248: d027bfec                 st      %o0, [%fp+var_14]
F004A24C: c607bfec                 ld      [%fp+var_14], %g3
F004A250: d0020000                 ld      [%o0], %o0
F004A254: 808a2004                 btst    4, %o0
F004A258: 12800008                 bne     loc_F004A278
F004A25C: ea00e020                 ld      [%g3+0x20], %l5
F004A260: d20563d4                 ld      [%l5+0x3D4], %o1
F004A264: 1100024090122255         set     0x90255, %o0
F004A26C: 80a24008                 cmp     %o1, %o0
F004A270: 02800005                 be      loc_F004A284
F004A274: 01000000                 nop
F004A278: 7fff697c                 call    _brelse
F004A27C: d007bfec                 ld      [%fp+var_14], %o0
F004A280: 308000fb                 ba,a    locret_F004A66C
F004A284: 7fff2342                 call    _getthetime
F004A288: 9007bff0                 add     %fp, var_10, %o0
F004A28C: d007bff0                 ld      [%fp+var_10], %o0
F004A290: d0256008                 st      %o0, [%l5+8]
F004A294: d204a0bc                 ld      [%l2+0xBC], %o1
F004A298: 7ffef184                 call    _rem
F004A29C: 90100019                 mov     %i1, %o0
F004A2A0: d204a030                 ld      [%l2+0x30], %o1
F004A2A4: 80a68009                 cmp     %i2, %o1
F004A2A8: 1280002d                 bne     loc_F004A35C
F004A2AC: b2100008                 mov     %o0, %i1
F004A2B0: 90100012                 mov     %l2, %o0
F004A2B4: a00563d8                 add     %l5, 0x3D8, %l0
F004A2B8: d404a060                 ld      [%l2+0x60], %o2
F004A2BC: 92100010                 mov     %l0, %o1
F004A2C0: 400017d1                 call    _isblock
F004A2C4: 953e400a                 sra     %i1, %o2, %o2
F004A2C8: 80a22000                 cmp     %o0, 0
F004A2CC: 0280000a                 be      loc_F004A2F4
F004A2D0: 94100019                 mov     %i1, %o2
F004A2D4: 113c043a90122078         set     aDev0xXBlockDFs, %o0! "dev = 0x%x, block = %d, fs = %s\n"
F004A2DC: d2562046                 ldsh    [%i0+0x46], %o1
F004A2E0: 7fff28de                 call    _printf
F004A2E4: 9604a0d4                 add     %l2, 0xD4, %o3
F004A2E8: 113c043a                 sethi   %hi(aFreeBlockFreei), %o0! "free_block: freeing free block"
F004A2EC: 7fff2ba1                 call    _panic
F004A2F0: 901220a0                 bset    %lo(aFreeBlockFreei), %o0! "free_block: freeing free block"
F004A2F4: 90100012                 mov     %l2, %o0
F004A2F8: d404a060                 ld      [%l2+0x60], %o2
F004A2FC: 92100010                 mov     %l0, %o1
F004A300: 40001819                 call    _setblock
F004A304: 953e400a                 sra     %i1, %o2, %o2
F004A308: d005601c                 ld      [%l5+0x1C], %o0
F004A30C: 90022001                 inc     %o0
F004A310: d025601c                 st      %o0, [%l5+0x1C]
F004A314: d204a0c4                 ld      [%l2+0xC4], %o1
F004A318: d004a070                 ld      [%l2+0x70], %o0
F004A31C: 92026001                 inc     %o1
F004A320: d224a0c4                 st      %o1, [%l2+0xC4]
F004A324: 913dc008                 sra     %l7, %o0, %o0
F004A328: 912a2002                 sll     %o0, 2, %o0
F004A32C: d204a06c                 ld      [%l2+0x6C], %o1
F004A330: 90020012                 add     %o0, %l2, %o0
F004A334: d40222d8                 ld      [%o0+0x2D8], %o2
F004A338: 922dc009                 andn    %l7, %o1, %o1
F004A33C: 932a6004                 sll     %o1, 4, %o1
F004A340: 94028009                 add     %o2, %o1, %o2
F004A344: d002a004                 ld      [%o2+4], %o0
F004A348: 90022001                 inc     %o0
F004A34C: d022a004                 st      %o0, [%o2+4]
F004A350: d204a07c                 ld      [%l2+0x7C], %o1
F004A354: 10800093                 ba      loc_F004A5A0
F004A358: 90100019                 mov     %i1, %o0
F004A35C: c404a038                 ld      [%l2+0x38], %g2
F004A360: 9000bfff                 add     %g2, -1, %o0
F004A364: ac2e4008                 andn    %i1, %o0, %l6
F004A368: 80a5a000                 cmp     %l6, 0
F004A36C: 16800003                 bge     loc_F004A378
F004A370: 92100016                 mov     %l6, %o1
F004A374: 9205a007                 add     %l6, 7, %o1
F004A378: 90100012                 mov     %l2, %o0
F004A37C: 94056034                 add     %l5, 0x34, %o2 ! '4'
F004A380: 96103fff                 mov     -1, %o3
F004A384: 933a6003                 sra     %o1, 3, %o1
F004A388: 98054009                 add     %l5, %o1, %o4
F004A38C: 932a6003                 sll     %o1, 3, %o1
F004A390: da0b23d8                 ldub    [%o4+0x3D8], %o5
F004A394: 92258009                 sub     %l6, %o1, %o1
F004A398: 9b3b4009                 sra     %o5, %o1, %o5
F004A39C: 98102008                 mov     8, %o4
F004A3A0: 98230002                 sub     %o4, %g2, %o4
F004A3A4: 921020ff                 mov     0xFF, %o1
F004A3A8: 933a400c                 sra     %o1, %o4, %o1
F004A3AC: 4000174b                 call    _fragacct
F004A3B0: 920b4009                 and     %o5, %o1, %o1
F004A3B4: d004a054                 ld      [%l2+0x54], %o0
F004A3B8: a6102000                 mov     0, %l3
F004A3BC: b5368008                 srl     %i2, %o0, %i2
F004A3C0: 80a4c01a                 cmp     %l3, %i2
F004A3C4: 36800021                 bge,a   loc_F004A448
F004A3C8: d0056024                 ld      [%l5+0x24], %o0
F004A3CC: 3b3c043a                 sethi   -0xFEF1800, %i5
F004A3D0: 393c043a                 sethi   -0xFEF1800, %i4
F004A3D4: b6102001                 mov     1, %i3
F004A3D8: a0064013                 add     %i1, %l3, %l0
F004A3DC: 80a42000                 cmp     %l0, 0
F004A3E0: 16800003                 bge     loc_F004A3EC
F004A3E4: 90100010                 mov     %l0, %o0
F004A3E8: 90042007                 add     %l0, 7, %o0
F004A3EC: 913a2003                 sra     %o0, 3, %o0
F004A3F0: a2020015                 add     %o0, %l5, %l1
F004A3F4: d24c63d8                 ldsb    [%l1+0x3D8], %o1
F004A3F8: 912a2003                 sll     %o0, 3, %o0
F004A3FC: a8240008                 sub     %l0, %o0, %l4
F004A400: 933a4014                 sra     %o1, %l4, %o1
F004A404: 808a6001                 btst    1, %o1
F004A408: 02800008                 be      loc_F004A428
F004A40C: 901760c0                 or      %i5, 0xC0, %o0! char *
F004A410: d2562046                 ldsh    [%i0+0x46], %o1
F004A414: 94100010                 mov     %l0, %o2
F004A418: 7fff2890                 call    _printf
F004A41C: 9604a0d4                 add     %l2, 0xD4, %o3
F004A420: 7fff2b54                 call    _panic
F004A424: 901720e8                 or      %i4, 0xE8, %o0
F004A428: a604e001                 inc     %l3
F004A42C: 80a4c01a                 cmp     %l3, %i2
F004A430: d00c63d8                 ldub    [%l1+0x3D8], %o0
F004A434: 932ec014                 sll     %i3, %l4, %o1
F004A438: 90120009                 bset    %o1, %o0
F004A43C: 06bfffe7                 bl      loc_F004A3D8
F004A440: d02c63d8                 stb     %o0, [%l1+0x3D8]
F004A444: d0056024                 ld      [%l5+0x24], %o0
F004A448: 90020013                 add     %o0, %l3, %o0
F004A44C: d0256024                 st      %o0, [%l5+0x24]
F004A450: d204a0cc                 ld      [%l2+0xCC], %o1
F004A454: 98100016                 mov     %l6, %o4
F004A458: d004a070                 ld      [%l2+0x70], %o0
F004A45C: 92024013                 add     %o1, %l3, %o1
F004A460: d224a0cc                 st      %o1, [%l2+0xCC]
F004A464: 913dc008                 sra     %l7, %o0, %o0
F004A468: 912a2002                 sll     %o0, 2, %o0
F004A46C: d204a06c                 ld      [%l2+0x6C], %o1
F004A470: 90020012                 add     %o0, %l2, %o0
F004A474: d40222d8                 ld      [%o0+0x2D8], %o2
F004A478: 922dc009                 andn    %l7, %o1, %o1
F004A47C: 932a6004                 sll     %o1, 4, %o1
F004A480: 94028009                 add     %o2, %o1, %o2
F004A484: d002a00c                 ld      [%o2+0xC], %o0
F004A488: 80a5a000                 cmp     %l6, 0
F004A48C: 90020013                 add     %o0, %l3, %o0
F004A490: 16800003                 bge     loc_F004A49C
F004A494: d022a00c                 st      %o0, [%o2+0xC]
F004A498: 9805a007                 add     %l6, 7, %o4
F004A49C: 90100012                 mov     %l2, %o0
F004A4A0: 94056034                 add     %l5, 0x34, %o2 ! '4'
F004A4A4: 96102001                 mov     1, %o3
F004A4A8: 933b2003                 sra     %o4, 3, %o1
F004A4AC: 98054009                 add     %l5, %o1, %o4
F004A4B0: 932a6003                 sll     %o1, 3, %o1
F004A4B4: da0b23d8                 ldub    [%o4+0x3D8], %o5
F004A4B8: 92258009                 sub     %l6, %o1, %o1
F004A4BC: 9b3b4009                 sra     %o5, %o1, %o5
F004A4C0: d204a038                 ld      [%l2+0x38], %o1
F004A4C4: 98102008                 mov     8, %o4
F004A4C8: 98230009                 sub     %o4, %o1, %o4
F004A4CC: 921020ff                 mov     0xFF, %o1
F004A4D0: 933a400c                 sra     %o1, %o4, %o1
F004A4D4: 40001701                 call    _fragacct
F004A4D8: 920b4009                 and     %o5, %o1, %o1
F004A4DC: 90100012                 mov     %l2, %o0
F004A4E0: d404a060                 ld      [%l2+0x60], %o2
F004A4E4: 920563d8                 add     %l5, 0x3D8, %o1
F004A4E8: 40001747                 call    _isblock
F004A4EC: 953d800a                 sra     %l6, %o2, %o2
F004A4F0: 80a22000                 cmp     %o0, 0
F004A4F4: 22800048                 be,a    loc_F004A614
F004A4F8: d20ca0d0                 ldub    [%l2+0xD0], %o1
F004A4FC: d0056024                 ld      [%l5+0x24], %o0
F004A500: d204a038                 ld      [%l2+0x38], %o1
F004A504: 90220009                 sub     %o0, %o1, %o0
F004A508: d0256024                 st      %o0, [%l5+0x24]
F004A50C: d204a0cc                 ld      [%l2+0xCC], %o1
F004A510: d004a038                 ld      [%l2+0x38], %o0
F004A514: 92224008                 sub     %o1, %o0, %o1
F004A518: d004a070                 ld      [%l2+0x70], %o0
F004A51C: d224a0cc                 st      %o1, [%l2+0xCC]
F004A520: d204a06c                 ld      [%l2+0x6C], %o1
F004A524: 913dc008                 sra     %l7, %o0, %o0
F004A528: 912a2002                 sll     %o0, 2, %o0
F004A52C: 90020012                 add     %o0, %l2, %o0
F004A530: 922dc009                 andn    %l7, %o1, %o1
F004A534: d40222d8                 ld      [%o0+0x2D8], %o2
F004A538: 932a6004                 sll     %o1, 4, %o1
F004A53C: 94028009                 add     %o2, %o1, %o2
F004A540: d002a00c                 ld      [%o2+0xC], %o0
F004A544: d204a038                 ld      [%l2+0x38], %o1
F004A548: 90220009                 sub     %o0, %o1, %o0
F004A54C: d022a00c                 st      %o0, [%o2+0xC]
F004A550: d005601c                 ld      [%l5+0x1C], %o0
F004A554: 90022001                 inc     %o0
F004A558: d025601c                 st      %o0, [%l5+0x1C]
F004A55C: d204a0c4                 ld      [%l2+0xC4], %o1
F004A560: d004a070                 ld      [%l2+0x70], %o0
F004A564: 92026001                 inc     %o1
F004A568: d224a0c4                 st      %o1, [%l2+0xC4]
F004A56C: 913dc008                 sra     %l7, %o0, %o0
F004A570: 912a2002                 sll     %o0, 2, %o0
F004A574: d204a06c                 ld      [%l2+0x6C], %o1
F004A578: 90020012                 add     %o0, %l2, %o0
F004A57C: d40222d8                 ld      [%o0+0x2D8], %o2
F004A580: 922dc009                 andn    %l7, %o1, %o1
F004A584: 932a6004                 sll     %o1, 4, %o1
F004A588: 94028009                 add     %o2, %o1, %o2
F004A58C: d002a004                 ld      [%o2+4], %o0
F004A590: 90022001                 inc     %o0
F004A594: d022a004                 st      %o0, [%o2+4]
F004A598: d204a07c                 ld      [%l2+0x7C], %o1! int
F004A59C: 90100016                 mov     %l6, %o0! int
F004A5A0: 7ffeefd8                 call    _umul
F004A5A4: 01000000                 nop
F004A5A8: a0100008                 mov     %o0, %l0
F004A5AC: e204a0ac                 ld      [%l2+0xAC], %l1
F004A5B0: 7ffef016                 call    _div
F004A5B4: 92100011                 mov     %l1, %o1
F004A5B8: a6100008                 mov     %o0, %l3
F004A5BC: 90100010                 mov     %l0, %o0
F004A5C0: 92100011                 mov     %l1, %o1
F004A5C4: a12ce004                 sll     %l3, 4, %l0
F004A5C8: 7ffef0b8                 call    _rem
F004A5CC: a0040015                 add     %l0, %l5, %l0
F004A5D0: e204a0a8                 ld      [%l2+0xA8], %l1
F004A5D4: 7ffef0b5                 call    _rem
F004A5D8: 92100011                 mov     %l1, %o1! int
F004A5DC: 912a2003                 sll     %o0, 3, %o0! int
F004A5E0: 7ffef00a                 call    _div
F004A5E4: 92100011                 mov     %l1, %o1
F004A5E8: 912a2001                 sll     %o0, 1, %o0
F004A5EC: 90020010                 add     %o0, %l0, %o0
F004A5F0: d21220d4                 lduh    [%o0+0xD4], %o1
F004A5F4: 92026001                 inc     %o1
F004A5F8: d23220d4                 sth     %o1, [%o0+0xD4]
F004A5FC: 932ce002                 sll     %l3, 2, %o1
F004A600: 92024015                 add     %o1, %l5, %o1
F004A604: d0026054                 ld      [%o1+0x54], %o0
F004A608: 90022001                 inc     %o0
F004A60C: d0226054                 st      %o0, [%o1+0x54]
F004A610: d20ca0d0                 ldub    [%l2+0xD0], %o1
F004A614: d007bfec                 ld      [%fp+var_14], %o0
F004A618: 92026001                 inc     %o1
F004A61C: 7fff687a                 call    _bdwrite
F004A620: d22ca0d0                 stb     %o1, [%l2+0xD0]
F004A624: d00ca0d3                 ldub    [%l2+0xD3], %o0
F004A628: 808a2001                 btst    1, %o0
F004A62C: 02800010                 be      locret_F004A66C
F004A630: 01000000                 nop
F004A634: d004a0c4                 ld      [%l2+0xC4], %o0
F004A638: d204a060                 ld      [%l2+0x60], %o1
F004A63C: d404a0cc                 ld      [%l2+0xCC], %o2
F004A640: 912a0009                 sll     %o0, %o1, %o0
F004A644: d204a088                 ld      [%l2+0x88], %o1
F004A648: 9002000a                 add     %o0, %o2, %o0
F004A64C: 80a20009                 cmp     %o0, %o1
F004A650: 04800007                 ble     locret_F004A66C
F004A654: 01000000                 nop
F004A658: 7fff21e4                 call    _wakeup
F004A65C: 9004a0cc                 add     %l2, 0xCC, %o0
F004A660: d00ca0d3                 ldub    [%l2+0xD3], %o0
F004A664: 900a3ffe                 and     %o0, -2, %o0
F004A668: d02ca0d3                 stb     %o0, [%l2+0xD3]
F004A66C: 81c7e008                 ret
F004A670: 81e80000                 restore
