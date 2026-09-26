F001C188: 9de3bf98                 save    %sp, -0x68, %sp
F001C18C: 900e20ff                 and     %i0, 0xFF, %o0
F001C190: 912a2004                 sll     %o0, 4, %o0
F001C194: 133c04bc92126204         set     unk_F012F204, %o1
F001C19C: 90020009                 add     %o0, %o1, %o0
F001C1A0: 1320011d92126061         set     -0x7FFB8B9F, %o1
F001C1A8: e2022008                 ld      [%o0+8], %l1
F001C1AC: 80a64009                 cmp     %i1, %o1
F001C1B0: e002200c                 ld      [%o0+0xC], %l0
F001C1B4: 12800025                 bne     loc_F001C248
F001C1B8: a8100018                 mov     %i0, %l4
F001C1BC: d0068000                 ld      [%i2], %o0
F001C1C0: 80a22000                 cmp     %o0, 0
F001C1C4: 2280000f                 be,a    loc_F001C200
F001C1C8: d2046040                 ld      [%l1+0x40], %o1
F001C1CC: d0040000                 ld      [%l0], %o0
F001C1D0: 808a2008                 btst    8, %o0
F001C1D4: 22800008                 be,a    loc_F001C1F4
F001C1D8: d0046040                 ld      [%l1+0x40], %o0
F001C1DC: d20c200c                 ldub    [%l0+0xC], %o1
F001C1E0: 90100011                 mov     %l1, %o0
F001C1E4: 92126040                 bset    0x40, %o1 ! '@'
F001C1E8: 7ffffd5b                 call    _ptcwakeup
F001C1EC: d22c200c                 stb     %o1, [%l0+0xC]
F001C1F0: d0046040                 ld      [%l1+0x40], %o0
F001C1F4: 13001000                 sethi   0x400000, %o1
F001C1F8: 10800011                 ba      loc_F001C23C
F001C1FC: 90120009                 bset    %o1, %o0
F001C200: 11001000                 sethi   0x400000, %o0
F001C204: 808a4008                 btst    %o0, %o1
F001C208: 2280000c                 be,a    loc_F001C238
F001C20C: d2046040                 ld      [%l1+0x40], %o1
F001C210: d0040000                 ld      [%l0], %o0
F001C214: 808a2008                 btst    8, %o0
F001C218: 02800006                 be      loc_F001C230
F001C21C: 90100011                 mov     %l1, %o0
F001C220: d20c200c                 ldub    [%l0+0xC], %o1
F001C224: 92126040                 bset    0x40, %o1 ! '@'
F001C228: 7ffffd4b                 call    _ptcwakeup
F001C22C: d22c200c                 stb     %o1, [%l0+0xC]
F001C230: d2046040                 ld      [%l1+0x40], %o1
F001C234: 11001000                 sethi   0x400000, %o0
F001C238: 902a4008                 andn    %o1, %o0, %o0
F001C23C: d0246040                 st      %o0, [%l1+0x40]
F001C240: 10800120                 ba      locret_F001C6C0
F001C244: b0102000                 mov     0, %i0
F001C248: 932e2010                 sll     %i0, 16, %o1
F001C24C: 93326018                 srl     %o1, 24, %o1
F001C250: 912a6001                 sll     %o1, 1, %o0
F001C254: 90020009                 add     %o0, %o1, %o0
F001C258: 912a2002                 sll     %o0, 2, %o0
F001C25C: 90220009                 sub     %o0, %o1, %o0
F001C260: 912a2002                 sll     %o0, 2, %o0
F001C264: 133c0472921261f0         set     _cdevsw, %o1
F001C26C: d2020009                 ld      [%o0+%o1], %o1
F001C270: 113c006e90122034         set     _ptcopen, %o0
F001C278: 80a24008                 cmp     %o1, %o0
F001C27C: 12800077                 bne     loc_F001C458
F001C280: 90100011                 mov     %l1, %o0
F001C284: 1120011d90122070         set     -0x7FFB8B90, %o0
F001C28C: 80a64008                 cmp     %i1, %o0
F001C290: 22800035                 be,a    loc_F001C364
F001C294: d0068000                 ld      [%i2], %o0
F001C298: 1480001a                 bg      loc_F001C300
F001C29C: 1120091d                 sethi   -0x7FDB8C00, %o0
F001C2A0: 1120011d90122001         set     -0x7FFB8BFF, %o0
F001C2A8: 80a64008                 cmp     %i1, %o0
F001C2AC: 02800057                 be      loc_F001C408
F001C2B0: 01000000                 nop
F001C2B4: 14800009                 bg      loc_F001C2D8
F001C2B8: 1120011d                 sethi   -0x7FFB8C00, %o0
F001C2BC: 112001199012227e         set     -0x7FFB9982, %o0
F001C2C4: 80a64008                 cmp     %i1, %o0
F001C2C8: 22800048                 be,a    loc_F001C3E8
F001C2CC: d0068000                 ld      [%i2], %o0
F001C2D0: 10800062                 ba      loc_F001C458
F001C2D4: 90100011                 mov     %l1, %o0
F001C2D8: 90122066                 bset    0x66, %o0 ! 'f'
F001C2DC: 80a64008                 cmp     %i1, %o0
F001C2E0: 0280002b                 be      loc_F001C38C
F001C2E4: 1120011d                 sethi   -0x7FFB8C00, %o0
F001C2E8: 90122069                 bset    0x69, %o0 ! 'i'
F001C2EC: 80a64008                 cmp     %i1, %o0
F001C2F0: 22800032                 be,a    loc_F001C3B8
F001C2F4: d0068000                 ld      [%i2], %o0
F001C2F8: 10800058                 ba      loc_F001C458
F001C2FC: 90100011                 mov     %l1, %o0
F001C300: 90122016                 bset    0x16, %o0
F001C304: 80a64008                 cmp     %i1, %o0
F001C308: 14800011                 bg      loc_F001C34C
F001C30C: 1108001d                 sethi   0x20007400, %o0
F001C310: 1120091d90122014         set     -0x7FDB8BEC, %o0
F001C318: 80a64008                 cmp     %i1, %o0
F001C31C: 1680003b                 bge     loc_F001C408
F001C320: 1120019d                 sethi   -0x7FF98C00, %o0
F001C324: 9012200a                 bset    0xA, %o0
F001C328: 80a64008                 cmp     %i1, %o0
F001C32C: 1480004b                 bg      loc_F001C458
F001C330: 90100011                 mov     %l1, %o0
F001C334: 1120019d90122009         set     -0x7FF98BF7, %o0
F001C33C: 80a64008                 cmp     %i1, %o0
F001C340: 06800046                 bl      loc_F001C458
F001C344: 90100011                 mov     %l1, %o0
F001C348: 30800030                 ba,a    loc_F001C408
F001C34C: 9012205f                 bset    0x5F, %o0 ! '_'
F001C350: 80a64008                 cmp     %i1, %o0
F001C354: 22800033                 be,a    loc_F001C420
F001C358: d0068000                 ld      [%i2], %o0
F001C35C: 1080003f                 ba      loc_F001C458
F001C360: 90100011                 mov     %l1, %o0
F001C364: 80a22000                 cmp     %o0, 0
F001C368: 02800007                 be      loc_F001C384
F001C36C: d0040000                 ld      [%l0], %o0
F001C370: 808a2080                 btst    0x80, %o0
F001C374: 128000d3                 bne     locret_F001C6C0
F001C378: b0102016                 mov     0x16, %i0
F001C37C: 10800021                 ba      loc_F001C400
F001C380: 90122008                 bset    8, %o0
F001C384: 1080001f                 ba      loc_F001C400
F001C388: 900a3ff7                 and     %o0, -9, %o0
F001C38C: d0068000                 ld      [%i2], %o0
F001C390: 80a22000                 cmp     %o0, 0
F001C394: 02800007                 be      loc_F001C3B0
F001C398: d0040000                 ld      [%l0], %o0
F001C39C: 808a2008                 btst    8, %o0
F001C3A0: 128000c8                 bne     locret_F001C6C0
F001C3A4: b0102016                 mov     0x16, %i0
F001C3A8: 10800016                 ba      loc_F001C400
F001C3AC: 90122080                 bset    0x80, %o0
F001C3B0: 10800014                 ba      loc_F001C400
F001C3B4: 900a3f7f                 and     %o0, -0x81, %o0
F001C3B8: 80a22000                 cmp     %o0, 0
F001C3BC: 02800004                 be      loc_F001C3CC
F001C3C0: d0040000                 ld      [%l0], %o0
F001C3C4: 10800003                 ba      loc_F001C3D0
F001C3C8: 90122020                 bset    0x20, %o0 ! ' '
F001C3CC: 900a3fdf                 and     %o0, -0x21, %o0
F001C3D0: d0240000                 st      %o0, [%l0]
F001C3D4: 90100011                 mov     %l1, %o0
F001C3D8: 7fffe996                 call    _ttyflush
F001C3DC: 92102003                 mov     3, %o1
F001C3E0: 108000b8                 ba      locret_F001C6C0
F001C3E4: b0102000                 mov     0, %i0
F001C3E8: 80a22000                 cmp     %o0, 0
F001C3EC: 02800004                 be      loc_F001C3FC
F001C3F0: d0040000                 ld      [%l0], %o0
F001C3F4: 10800003                 ba      loc_F001C400
F001C3F8: 90122004                 bset    4, %o0
F001C3FC: 900a3ffb                 and     %o0, -5, %o0! FILE *
F001C400: 10bfff90                 ba      loc_F001C240
F001C404: d0240000                 st      %o0, [%l0]
F001C408: 400000b0                 call    _getc
F001C40C: 90046018                 add     %l1, 0x18, %o0
F001C410: 80a22000                 cmp     %o0, 0
F001C414: 16bffffd                 bge     loc_F001C408
F001C418: 90100011                 mov     %l1, %o0
F001C41C: 3080000f                 ba,a    loc_F001C458
F001C420: 80a2201f                 cmp     %o0, 0x1F
F001C424: 188000a7                 bgu     locret_F001C6C0
F001C428: b0102016                 mov     0x16, %i0
F001C42C: d004603c                 ld      [%l1+0x3C], %o0
F001C430: 80a22000                 cmp     %o0, 0
F001C434: 06800004                 bl      loc_F001C444
F001C438: 90100011                 mov     %l1, %o0
F001C43C: 7fffe97d                 call    _ttyflush
F001C440: 92102003                 mov     3, %o1
F001C444: d0546044                 ldsh    [%l1+0x44], %o0
F001C448: 7fffd425                 call    _gsignal
F001C44C: d2068000                 ld      [%i2], %o1
F001C450: 1080009c                 ba      locret_F001C6C0
F001C454: b0102000                 mov     0, %i0
F001C458: 92100019                 mov     %i1, %o1
F001C45C: 9410001a                 mov     %i2, %o2
F001C460: 273c042e                 sethi   %hi(_linesw), %l3
F001C464: d64c6047                 ldsb    [%l1+0x47], %o3
F001C468: a414e0cc                 or      %l3, %lo(_linesw), %l2
F001C46C: 992ae001                 sll     %o3, 1, %o4
F001C470: 9803000b                 add     %o4, %o3, %o4
F001C474: 992b2004                 sll     %o4, 4, %o4
F001C478: 98030012                 add     %o4, %l2, %o4
F001C47C: d8032010                 ld      [%o4+0x10], %o4
F001C480: 9fc30000                 call    %o4
F001C484: 9610001b                 mov     %i3, %o3
F001C488: b0920000                 orcc    %o0, %g0, %i0
F001C48C: 1680008d                 bge     locret_F001C6C0
F001C490: 90100011                 mov     %l1, %o0
F001C494: 92100019                 mov     %i1, %o1
F001C498: 9410001a                 mov     %i2, %o2
F001C49C: 7fffe9ca                 call    _ttioctl
F001C4A0: 9610001b                 mov     %i3, %o3
F001C4A4: d24c6047                 ldsb    [%l1+0x47], %o1
F001C4A8: 952a6001                 sll     %o1, 1, %o2
F001C4AC: 94028009                 add     %o2, %o1, %o2
F001C4B0: 952aa004                 sll     %o2, 4, %o2
F001C4B4: 94028012                 add     %o2, %l2, %o2
F001C4B8: d202a02c                 ld      [%o2+0x2C], %o1
F001C4BC: 80a26000                 cmp     %o1, 0
F001C4C0: 0280000c                 be      loc_F001C4F0
F001C4C4: b0100008                 mov     %o0, %i0
F001C4C8: 90100011                 mov     %l1, %o0
F001C4CC: d202a004                 ld      [%o2+4], %o1
F001C4D0: 9fc24000                 call    %o1
F001C4D4: b0102019                 mov     0x19, %i0
F001C4D8: c02c6047                 clrb    [%l1+0x47]
F001C4DC: 912d2010                 sll     %l4, 16, %o0
F001C4E0: 913a2010                 sra     %o0, 16, %o0
F001C4E4: d404e0cc                 ld      [%l3+0xCC], %o2
F001C4E8: 9fc28000                 call    %o2
F001C4EC: 92100011                 mov     %l1, %o1
F001C4F0: 80a62000                 cmp     %i0, 0
F001C4F4: 36800015                 bge,a   loc_F001C548
F001C4F8: d2046040                 ld      [%l1+0x40], %o1
F001C4FC: d0040000                 ld      [%l0], %o0
F001C500: 808a2080                 btst    0x80, %o0
F001C504: 0280000f                 be      loc_F001C540
F001C508: 920e7f00                 and     %i1, -0x100, %o1
F001C50C: 1108001d90122100         set     0x20007500, %o0
F001C514: 80a24008                 cmp     %o1, %o0
F001C518: 3280000b                 bne,a   loc_F001C544
F001C51C: b0102019                 mov     0x19, %i0
F001C520: 808e60ff                 btst    0xFF, %i1
F001C524: 02bfff47                 be      loc_F001C240
F001C528: 90100011                 mov     %l1, %o0
F001C52C: f22c200d                 stb     %i1, [%l0+0xD]
F001C530: 7ffffc89                 call    _ptcwakeup
F001C534: 92102001                 mov     1, %o1
F001C538: 10800062                 ba      locret_F001C6C0
F001C53C: b0102000                 mov     0, %i0
F001C540: b0102019                 mov     0x19, %i0
F001C544: d2046040                 ld      [%l1+0x40], %o1
F001C548: 11001000                 sethi   0x400000, %o0
F001C54C: 808a4008                 btst    %o0, %o1
F001C550: 22800031                 be,a    loc_F001C614
F001C554: d004603c                 ld      [%l1+0x3C], %o0
F001C558: d0040000                 ld      [%l0], %o0
F001C55C: 808a2008                 btst    8, %o0
F001C560: 0280002c                 be      loc_F001C610
F001C564: 1120019d                 sethi   -0x7FF98C00, %o0
F001C568: 9012200a                 bset    0xA, %o0
F001C56C: 80a64008                 cmp     %i1, %o0
F001C570: 1480000f                 bg      loc_F001C5AC
F001C574: 1120019d                 sethi   -0x7FF98C00, %o0
F001C578: 1120019d90122009         set     -0x7FF98BF7, %o0
F001C580: 80a64008                 cmp     %i1, %o0
F001C584: 36800021                 bge,a   loc_F001C608
F001C588: d00c200c                 ldub    [%l0+0xC], %o0
F001C58C: 1120011d9012207f         set     -0x7FFB8B81, %o0
F001C594: 80a64008                 cmp     %i1, %o0
F001C598: 3480001f                 bg,a    loc_F001C614
F001C59C: d004603c                 ld      [%l1+0x3C], %o0
F001C5A0: 1120011d                 sethi   -0x7FFB8C00, %o0
F001C5A4: 10800015                 ba      loc_F001C5F8
F001C5A8: 9012207d                 bset    0x7D, %o0 ! '}'
F001C5AC: 90122075                 bset    0x75, %o0 ! 'u'
F001C5B0: 80a64008                 cmp     %i1, %o0
F001C5B4: 22800015                 be,a    loc_F001C608
F001C5B8: d00c200c                 ldub    [%l0+0xC], %o0
F001C5BC: 14800009                 bg      loc_F001C5E0
F001C5C0: 1120091d                 sethi   -0x7FDB8C00, %o0
F001C5C4: 1120019d90122011         set     -0x7FF98BEF, %o0
F001C5CC: 80a64008                 cmp     %i1, %o0
F001C5D0: 2280000e                 be,a    loc_F001C608
F001C5D4: d00c200c                 ldub    [%l0+0xC], %o0
F001C5D8: 1080000f                 ba      loc_F001C614
F001C5DC: d004603c                 ld      [%l1+0x3C], %o0
F001C5E0: 90122016                 bset    0x16, %o0
F001C5E4: 80a64008                 cmp     %i1, %o0
F001C5E8: 3480000b                 bg,a    loc_F001C614
F001C5EC: d004603c                 ld      [%l1+0x3C], %o0
F001C5F0: 1120091d90122014         set     -0x7FDB8BEC, %o0
F001C5F8: 80a64008                 cmp     %i1, %o0
F001C5FC: 26800006                 bl,a    loc_F001C614
F001C600: d004603c                 ld      [%l1+0x3C], %o0
F001C604: d00c200c                 ldub    [%l0+0xC], %o0
F001C608: 90122040                 bset    0x40, %o0 ! '@'
F001C60C: d02c200c                 stb     %o0, [%l0+0xC]
F001C610: d004603c                 ld      [%l1+0x3C], %o0
F001C614: 808a2020                 btst    0x20, %o0 ! ' '
F001C618: 12800011                 bne     loc_F001C65C
F001C61C: b2102000                 mov     0, %i1
F001C620: 7ffffab2                 call    _ttynty
F001C624: 90100011                 mov     %l1, %o0
F001C628: d2022010                 ld      [%o0+0x10], %o1
F001C62C: 11010000                 sethi   0x4000000, %o0
F001C630: 808a4008                 btst    %o0, %o1
F001C634: 0280000a                 be      loc_F001C65C
F001C638: 13003fff                 sethi   0xFFFC00, %o1
F001C63C: d0046050                 ld      [%l1+0x50], %o0
F001C640: 92126300                 bset    0x300, %o1
F001C644: 900a0009                 and     %o0, %o1, %o0
F001C648: 1300044492126300         set     0x111300, %o1
F001C650: 901a0009                 btog    %o1, %o0
F001C654: 80a00008                 cmp     %g0, %o0
F001C658: b2603fff                 subc    %g0, -1, %i1
F001C65C: d0040000                 ld      [%l0], %o0
F001C660: 808a2040                 btst    0x40, %o0 ! '@'
F001C664: 0280000c                 be      loc_F001C694
F001C668: 80a66000                 cmp     %i1, 0
F001C66C: 02800015                 be      locret_F001C6C0
F001C670: 90100011                 mov     %l1, %o0
F001C674: d60c200c                 ldub    [%l0+0xC], %o3
F001C678: 92102001                 mov     1, %o1
F001C67C: d4040000                 ld      [%l0], %o2
F001C680: 960ae0ef                 and     %o3, 0xEF, %o3
F001C684: 9612e020                 bset    0x20, %o3 ! ' '
F001C688: d62c200c                 stb     %o3, [%l0+0xC]
F001C68C: 1080000b                 ba      loc_F001C6B8
F001C690: 940abfbf                 and     %o2, -0x41, %o2
F001C694: 1280000b                 bne     locret_F001C6C0
F001C698: 90100011                 mov     %l1, %o0
F001C69C: d60c200c                 ldub    [%l0+0xC], %o3
F001C6A0: 92102001                 mov     1, %o1
F001C6A4: d4040000                 ld      [%l0], %o2
F001C6A8: 960ae0df                 and     %o3, 0xDF, %o3
F001C6AC: 9612e010                 bset    0x10, %o3
F001C6B0: d62c200c                 stb     %o3, [%l0+0xC]
F001C6B4: 9412a040                 bset    0x40, %o2 ! '@'
F001C6B8: 7ffffc27                 call    _ptcwakeup
F001C6BC: d4240000                 st      %o2, [%l0]
F001C6C0: 81c7e008                 ret
F001C6C4: 81e80000                 restore
