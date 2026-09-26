F00EE3F4: 9de3bf88                 save    %sp, -0x78, %sp
F00EE3F8: d406a004                 ld      [%i2+4], %o2
F00EE3FC: 9010001a                 mov     %i2, %o0
F00EE400: 9fc28000                 call    %o2
F00EE404: 92102010                 mov     0x10, %o1
F00EE408: a2100008                 mov     %o0, %l1
F00EE40C: 213c04bc                 sethi   %hi(dword_F012F0A8), %l0
F00EE410: d00420a8                 ld      [%l0+%lo(dword_F012F0A8)], %o0
F00EE414: 80a22000                 cmp     %o0, 0
F00EE418: 32800012                 bne,a   loc_F00EE460
F00EE41C: d0060000                 ld      [%i0], %o0
F00EE420: 113c04bc92122098         set     unk_F012F098, %o1
F00EE428: d0022098                 ld      [%o0+0x98], %o0
F00EE42C: d027bfe8                 st      %o0, [%fp+var_18]
F00EE430: d0026004                 ld      [%o1+4], %o0
F00EE434: d027bfec                 st      %o0, [%fp+var_14]
F00EE438: d0026008                 ld      [%o1+8], %o0
F00EE43C: d027bff0                 st      %o0, [%fp+var_10]
F00EE440: d002600c                 ld      [%o1+0xC], %o0
F00EE444: d027bff4                 st      %o0, [%fp+var_C]
F00EE448: 9007bfe8                 add     %fp, var_18, %o0! prototype
F00EE44C: 92102000                 mov     0, %o1! data
F00EE450: 7ffffb45                 call    _NXCreateHashTable
F00EE454: 94102000                 mov     0, %o2
F00EE458: d02420a8                 st      %o0, [%l0+0xA8]
F00EE45C: d0060000                 ld      [%i0], %o0
F00EE460: 80a22000                 cmp     %o0, 0
F00EE464: 0280000e                 be      loc_F00EE49C
F00EE468: 113c03f3                 sethi   -0xFF03400, %o0
F00EE46C: d0062004                 ld      [%i0+4], %o0
F00EE470: 80a22000                 cmp     %o0, 0
F00EE474: 0280000a                 be      loc_F00EE49C
F00EE478: 113c03f3                 sethi   -0xFF03400, %o0
F00EE47C: d0062008                 ld      [%i0+8], %o0
F00EE480: 80a22000                 cmp     %o0, 0
F00EE484: 02800006                 be      loc_F00EE49C
F00EE488: 113c03f3                 sethi   -0xFF03400, %o0
F00EE48C: d006200c                 ld      [%i0+0xC], %o0
F00EE490: 80a22000                 cmp     %o0, 0
F00EE494: 02800006                 be      loc_F00EE4AC
F00EE498: 113c03f3                 sethi   -0xFF03400, %o0
F00EE49C: 4000092b                 call    __NXLogError
F00EE4A0: 90122350                 bset    0x350, %o0
F00EE4A4: 10800031                 ba      locret_F00EE568
F00EE4A8: b0102000                 mov     0, %i0
F00EE4AC: 253c04bc                 sethi   %hi(dword_F012F0A8), %l2
F00EE4B0: d004a0a8                 ld      [%l2+%lo(dword_F012F0A8)], %o0! __size
F00EE4B4: 7ffffc82                 call    _NXHashGet
F00EE4B8: 92100018                 mov     %i0, %o1! data
F00EE4BC: a0920000                 orcc    %o0, %g0, %l0
F00EE4C0: 32800011                 bne,a   loc_F00EE504
F00EE4C4: e0244000                 st      %l0, [%l1]
F00EE4C8: 7ffde75a                 call    _malloc
F00EE4CC: 90102010                 mov     0x10, %o0
F00EE4D0: a0100008                 mov     %o0, %l0
F00EE4D4: d0060000                 ld      [%i0], %o0
F00EE4D8: d0240000                 st      %o0, [%l0]
F00EE4DC: d0062004                 ld      [%i0+4], %o0
F00EE4E0: d0242004                 st      %o0, [%l0+4]
F00EE4E4: d0062008                 ld      [%i0+8], %o0
F00EE4E8: d0242008                 st      %o0, [%l0+8]
F00EE4EC: d006200c                 ld      [%i0+0xC], %o0
F00EE4F0: d024200c                 st      %o0, [%l0+0xC]
F00EE4F4: d004a0a8                 ld      [%l2+0xA8], %o0! table
F00EE4F8: 7ffffce0                 call    _NXHashInsert
F00EE4FC: 92100010                 mov     %l0, %o1
F00EE500: e0244000                 st      %l0, [%l1]
F00EE504: c0246004                 clr     [%l1+4]
F00EE508: 7fffff89                 call    sub_F00EE32C
F00EE50C: 90100019                 mov     %i1, %o0
F00EE510: 90022001                 inc     %o0
F00EE514: a0102001                 mov     1, %l0
F00EE518: a12c0008                 sll     %l0, %o0, %l0
F00EE51C: 92043fff                 add     %l0, -1, %o1
F00EE520: d2246008                 st      %o1, [%l1+8]
F00EE524: d406a004                 ld      [%i2+4], %o2
F00EE528: 9010001a                 mov     %i2, %o0
F00EE52C: 9fc28000                 call    %o2
F00EE530: 932a6003                 sll     %o1, 3, %o1
F00EE534: a0043ffe                 inc     -2, %l0
F00EE538: 80a43fff                 cmp     %l0, -1
F00EE53C: 02800009                 be      loc_F00EE560
F00EE540: 92100008                 mov     %o0, %o1
F00EE544: 94103fff                 mov     -1, %o2
F00EE548: d4224000                 st      %o2, [%o1]
F00EE54C: c0226004                 clr     [%o1+4]
F00EE550: a0043fff                 inc     -1, %l0
F00EE554: 80a43fff                 cmp     %l0, -1
F00EE558: 12bffffc                 bne     loc_F00EE548
F00EE55C: 92026008                 inc     8, %o1
F00EE560: d024600c                 st      %o0, [%l1+0xC]
F00EE564: b0100011                 mov     %l1, %i0
F00EE568: 81c7e008                 ret
F00EE56C: 81e80000                 restore
