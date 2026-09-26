F00AA2A4: 9de3bf98                 save    %sp, -0x68, %sp
F00AA2A8: 113c0447                 sethi   %hi(_page_size), %o0
F00AA2AC: e002213c                 ld      [%o0+%lo(_page_size)], %l0
F00AA2B0: 90067fff                 add     %i1, -1, %o0
F00AA2B4: 90020010                 add     %o0, %l0, %o0
F00AA2B8: 7ffd70d2                 call    _udiv
F00AA2BC: 92100010                 mov     %l0, %o1
F00AA2C0: 7ffd7090                 call    _umul
F00AA2C4: 92100010                 mov     %l0, %o1
F00AA2C8: d2062018                 ld      [%i0+0x18], %o1
F00AA2CC: a4100008                 mov     %o0, %l2
F00AA2D0: 80a48009                 cmp     %l2, %o1
F00AA2D4: 22800066                 be,a    locret_F00AA46C
F00AA2D8: f2262014                 st      %i1, [%i0+0x14]
F00AA2DC: 16800028                 bge     loc_F00AA37C
F00AA2E0: 80a24012                 cmp     %o1, %l2
F00AA2E4: 133c04cf901262b8         set     unk_F0133EB8, %o0
F00AA2EC: e00262b8                 ld      [%o1+0x2B8], %l0
F00AA2F0: 90023ff4                 inc     -0xC, %o0
F00AA2F4: 80a40008                 cmp     %l0, %o0
F00AA2F8: 2280005d                 be,a    locret_F00AA46C
F00AA2FC: f2262014                 st      %i1, [%i0+0x14]
F00AA300: 7fffb22e                 call    _spltty
F00AA304: 01000000                 nop
F00AA308: d4042010                 ld      [%l0+0x10], %o2
F00AA30C: d204200c                 ld      [%l0+0xC], %o1
F00AA310: d222a00c                 st      %o1, [%o2+0xC]
F00AA314: d404200c                 ld      [%l0+0xC], %o2
F00AA318: d2042010                 ld      [%l0+0x10], %o1
F00AA31C: d222a010                 st      %o1, [%o2+0x10]
F00AA320: d2040000                 ld      [%l0], %o1
F00AA324: 92126008                 bset    8, %o1
F00AA328: 7fffb27f                 call    _splx
F00AA32C: d2240000                 st      %o1, [%l0]
F00AA330: d2042020                 ld      [%l0+0x20], %o1
F00AA334: d0062020                 ld      [%i0+0x20], %o0
F00AA338: d4062018                 ld      [%i0+0x18], %o2
F00AA33C: 90020012                 add     %o0, %l2, %o0
F00AA340: 7fffffd2                 call    _pagemove
F00AA344: 94228012                 sub     %o2, %l2, %o2
F00AA348: 90100010                 mov     %l0, %o0
F00AA34C: d2062018                 ld      [%i0+0x18], %o1
F00AA350: 15000040                 sethi   0x10000, %o2
F00AA354: 92224012                 sub     %o1, %l2, %o1
F00AA358: d2222018                 st      %o1, [%o0+0x18]
F00AA35C: e4262018                 st      %l2, [%i0+0x18]
F00AA360: d2020000                 ld      [%o0], %o1
F00AA364: c0222014                 clr     [%o0+0x14]
F00AA368: 9212400a                 bset    %o2, %o1
F00AA36C: 7ffde93f                 call    _brelse
F00AA370: d2220000                 st      %o1, [%o0]
F00AA374: 1080003e                 ba      locret_F00AA46C
F00AA378: f2262014                 st      %i1, [%i0+0x14]
F00AA37C: 3680003c                 bge,a   locret_F00AA46C
F00AA380: f2262014                 st      %i1, [%i0+0x14]
F00AA384: 113c04cfa61222ac         set     unk_F0133EAC, %l3
F00AA38C: d0062018                 ld      [%i0+0x18], %o0
F00AA390: 7ffdeae3                 call    _getnewbuf
F00AA394: a2248008                 sub     %l2, %o0, %l1
F00AA398: a0100008                 mov     %o0, %l0
F00AA39C: d0042018                 ld      [%l0+0x18], %o0
F00AA3A0: 80a44008                 cmp     %l1, %o0
F00AA3A4: 36800002                 bge,a   loc_F00AA3AC
F00AA3A8: a2100008                 mov     %o0, %l1
F00AA3AC: d8042020                 ld      [%l0+0x20], %o4
F00AA3B0: 94100011                 mov     %l1, %o2
F00AA3B4: d6062020                 ld      [%i0+0x20], %o3
F00AA3B8: 90220011                 sub     %o0, %l1, %o0
F00AA3BC: d2062018                 ld      [%i0+0x18], %o1
F00AA3C0: 90030008                 add     %o4, %o0, %o0
F00AA3C4: 7fffffb1                 call    _pagemove
F00AA3C8: 9202c009                 add     %o3, %o1, %o1
F00AA3CC: d0062018                 ld      [%i0+0x18], %o0
F00AA3D0: 90020011                 add     %o0, %l1, %o0
F00AA3D4: d0262018                 st      %o0, [%i0+0x18]
F00AA3D8: d0042018                 ld      [%l0+0x18], %o0
F00AA3DC: 94220011                 sub     %o0, %l1, %o2
F00AA3E0: d0042014                 ld      [%l0+0x14], %o0
F00AA3E4: 80a2000a                 cmp     %o0, %o2
F00AA3E8: 04800003                 ble     loc_F00AA3F4
F00AA3EC: d4242018                 st      %o2, [%l0+0x18]
F00AA3F0: d4242014                 st      %o2, [%l0+0x14]
F00AA3F4: d0042018                 ld      [%l0+0x18], %o0
F00AA3F8: 80a22000                 cmp     %o0, 0
F00AA3FC: 14800015                 bg      loc_F00AA450
F00AA400: 01000000                 nop
F00AA404: d2042008                 ld      [%l0+8], %o1
F00AA408: d0042004                 ld      [%l0+4], %o0
F00AA40C: d0226004                 st      %o0, [%o1+4]
F00AA410: d2042004                 ld      [%l0+4], %o1
F00AA414: d0042008                 ld      [%l0+8], %o0
F00AA418: d0226008                 st      %o0, [%o1+8]
F00AA41C: d004e004                 ld      [%l3+4], %o0
F00AA420: d0242004                 st      %o0, [%l0+4]
F00AA424: e6242008                 st      %l3, [%l0+8]
F00AA428: d004e004                 ld      [%l3+4], %o0
F00AA42C: 13000040                 sethi   0x10000, %o1
F00AA430: e0222008                 st      %l0, [%o0+8]
F00AA434: e024e004                 st      %l0, [%l3+4]
F00AA438: 90103fff                 mov     -1, %o0
F00AA43C: d034201e                 sth     %o0, [%l0+0x1E]
F00AA440: d0040000                 ld      [%l0], %o0
F00AA444: c034201c                 clrh    [%l0+0x1C]
F00AA448: 90120009                 bset    %o1, %o0
F00AA44C: d0240000                 st      %o0, [%l0]
F00AA450: 7ffde906                 call    _brelse
F00AA454: 90100010                 mov     %l0, %o0
F00AA458: d0062018                 ld      [%i0+0x18], %o0
F00AA45C: 80a20012                 cmp     %o0, %l2
F00AA460: 06bfffcb                 bl      loc_F00AA38C
F00AA464: 01000000                 nop
F00AA468: f2262014                 st      %i1, [%i0+0x14]
F00AA46C: 81c7e008                 ret
F00AA470: 91e82001                 restore %g0, 1, %o0
