F002E248: 9de3bf80                 save    %sp, -0x80, %sp
F002E24C: d2066004                 ld      [%i1+4], %o1
F002E250: d0166008                 lduh    [%i1+8], %o0
F002E254: 92026004                 inc     4, %o1
F002E258: d2266004                 st      %o1, [%i1+4]
F002E25C: 90023ffc                 inc     -4, %o0
F002E260: d0366008                 sth     %o0, [%i1+8]
F002E264: 912a2010                 sll     %o0, 16, %o0
F002E268: 80a22000                 cmp     %o0, 0
F002E26C: 3280002f                 bne,a   loc_F002E328
F002E270: d0166008                 lduh    [%i1+8], %o0
F002E274: 4001a251                 call    _spltty
F002E278: 01000000                 nop
F002E27C: d256600a                 ldsh    [%i1+0xA], %o1
F002E280: 80a26000                 cmp     %o1, 0
F002E284: 12800005                 bne     loc_F002E298
F002E288: a2100008                 mov     %o0, %l1
F002E28C: 113c0431                 sethi   %hi(aMfree_6), %o0! "mfree"
F002E290: 7fff9bb8                 call    _panic
F002E294: 90122030                 bset    %lo(aMfree_6), %o0! "mfree"
F002E298: 153c04d2                 sethi   %hi(word_F0134B0C), %o2
F002E29C: d256600a                 ldsh    [%i1+0xA], %o1
F002E2A0: 9612a30c                 or      %o2, %lo(word_F0134B0C), %o3
F002E2A4: 932a6001                 sll     %o1, 1, %o1
F002E2A8: d012400b                 lduh    [%o1+%o3], %o0
F002E2AC: 90023fff                 inc     -1, %o0
F002E2B0: d032400b                 sth     %o0, [%o1+%o3]
F002E2B4: d012a30c                 lduh    [%o2+%lo(word_F0134B0C)], %o0
F002E2B8: 90022001                 inc     %o0
F002E2BC: d032a30c                 sth     %o0, [%o2+%lo(word_F0134B0C)]
F002E2C0: d0066004                 ld      [%i1+4], %o0
F002E2C4: 80a2207f                 cmp     %o0, 0x7F
F002E2C8: 08800004                 bleu    loc_F002E2D8
F002E2CC: c036600a                 clrh    [%i1+0xA]
F002E2D0: 7fffc04e                 call    _mclput
F002E2D4: 90100019                 mov     %i1, %o0
F002E2D8: c0266004                 clr     [%i1+4]
F002E2DC: c026607c                 clr     [%i1+0x7C]
F002E2E0: 133c04d3                 sethi   %hi(_mfree), %o1
F002E2E4: e0064000                 ld      [%i1], %l0
F002E2E8: 90100011                 mov     %l1, %o0
F002E2EC: d4026168                 ld      [%o1+%lo(_mfree)], %o2! size_t
F002E2F0: a2126168                 or      %o1, %lo(_mfree), %l1
F002E2F4: d4264000                 st      %o2, [%i1]
F002E2F8: 4001a28b                 call    _splx
F002E2FC: f2226168                 st      %i1, [%o1+%lo(_mfree)]
F002E300: 133c04d2                 sethi   %hi(_m_want), %o1
F002E304: d00262e8                 ld      [%o1+%lo(_m_want)], %o0
F002E308: 80a22000                 cmp     %o0, 0
F002E30C: 02800006                 be      loc_F002E324
F002E310: b2100010                 mov     %l0, %i1
F002E314: c02262e8                 clr     [%o1+%lo(_m_want)]
F002E318: 7fff92b4                 call    _wakeup
F002E31C: 90100011                 mov     %l1, %o0
F002E320: b2100010                 mov     %l0, %i1
F002E324: d0166008                 lduh    [%i1+8], %o0
F002E328: d2066004                 ld      [%i1+4], %o1
F002E32C: 80a2201b                 cmp     %o0, 0x1B
F002E330: 0880006e                 bleu    loc_F002E4E8
F002E334: a4064009                 add     %i1, %o1, %l2
F002E338: d016200c                 lduh    [%i0+0xC], %o0
F002E33C: 808a2080                 btst    0x80, %o0
F002E340: 1280006a                 bne     loc_F002E4E8
F002E344: 01000000                 nop
F002E348: d014a002                 lduh    [%l2+2], %o0
F002E34C: 80a22800                 cmp     %o0, 0x800
F002E350: 12800066                 bne     loc_F002E4E8
F002E354: 113c0431                 sethi   %hi(_revarp), %o0
F002E358: d0022028                 ld      [%o0+%lo(_revarp)], %o0
F002E35C: 80a22000                 cmp     %o0, 0
F002E360: 02800062                 be      loc_F002E4E8
F002E364: 01000000                 nop
F002E368: d014a006                 lduh    [%l2+6], %o0
F002E36C: 80a22003                 cmp     %o0, 3
F002E370: 1280005e                 bne     loc_F002E4E8
F002E374: 113c04d5                 sethi   %hi(_arptab), %o0
F002E378: a2122270                 or      %o0, %lo(_arptab), %l1
F002E37C: 90046d5c                 add     %l1, 0xD5C, %o0
F002E380: 80a44008                 cmp     %l1, %o0
F002E384: 3a800014                 bcc,a   loc_F002E3D4
F002E388: 113c04d8                 sethi   -0xFECA000, %o0
F002E38C: a6100008                 mov     %o0, %l3
F002E390: a0046004                 add     %l1, 4, %l0
F002E394: d00c2007                 ldub    [%l0+7], %o0
F002E398: 808a2004                 btst    4, %o0
F002E39C: 2280000a                 be,a    loc_F002E3C4
F002E3A0: a2046014                 inc     0x14, %l1
F002E3A4: 90100010                 mov     %l0, %o0! void *
F002E3A8: 9204a012                 add     %l2, 0x12, %o1! void *
F002E3AC: 7fff5eec                 call    _bcmp
F002E3B0: 94102006                 mov     6, %o2! size_t
F002E3B4: 80a22000                 cmp     %o0, 0
F002E3B8: 02800007                 be      loc_F002E3D4
F002E3BC: 113c04d8                 sethi   -0xFECA000, %o0
F002E3C0: a2046014                 inc     0x14, %l1
F002E3C4: 80a44013                 cmp     %l1, %l3
F002E3C8: 0abffff3                 bcs     loc_F002E394
F002E3CC: a0042014                 inc     0x14, %l0
F002E3D0: 113c04d8                 sethi   -0xFECA000, %o0
F002E3D4: 901223cc                 bset    0x3CC, %o0
F002E3D8: 80a44008                 cmp     %l1, %o0
F002E3DC: 1a800043                 bcc     loc_F002E4E8
F002E3E0: 9004a008                 add     %l2, 8, %o0! void *
F002E3E4: a607bfe2                 add     %fp, var_1E, %l3
F002E3E8: 92100013                 mov     %l3, %o1! void *
F002E3EC: 400199c9                 call    _bcopy
F002E3F0: 94102006                 mov     6, %o2! size_t
F002E3F4: 90100011                 mov     %l1, %o0! void *
F002E3F8: 9204a018                 add     %l2, 0x18, %o1! void *
F002E3FC: 400199c5                 call    _bcopy
F002E400: 94102004                 mov     4, %o2! size_t
F002E404: e0062018                 ld      [%i0+0x18], %l0
F002E408: 80a42000                 cmp     %l0, 0
F002E40C: 0280000b                 be      loc_F002E438
F002E410: 92100018                 mov     %i0, %o1
F002E414: d0042020                 ld      [%l0+0x20], %o0
F002E418: 80a20009                 cmp     %o0, %o1
F002E41C: 22800011                 be,a    loc_F002E460
F002E420: 90042004                 add     %l0, 4, %o0
F002E424: e0042024                 ld      [%l0+0x24], %l0
F002E428: 80a42000                 cmp     %l0, 0
F002E42C: 32bffffb                 bne,a   loc_F002E418
F002E430: d0042020                 ld      [%l0+0x20], %o0
F002E434: 80a42000                 cmp     %l0, 0
F002E438: 3280000f                 bne,a   loc_F002E474
F002E43C: a0062060                 add     %i0, 0x60, %l0 ! '`'
F002E440: 113c0431                 sethi   %hi(_revarpdebug), %o0
F002E444: d002202c                 ld      [%o0+%lo(_revarpdebug)], %o0
F002E448: 80a22000                 cmp     %o0, 0
F002E44C: 02800027                 be      loc_F002E4E8
F002E450: 113c0431                 sethi   %hi(aRevarpCanTFind), %o0! "revarp: can't find ifaddr\n"
F002E454: 7fff9881                 call    _printf
F002E458: 90122038                 bset    %lo(aRevarpCanTFind), %o0! "revarp: can't find ifaddr\n"
F002E45C: 30800023                 ba,a    loc_F002E4E8
F002E460: 9204a00e                 add     %l2, 0xE, %o1! void *
F002E464: 400199ab                 call    _bcopy
F002E468: 94102004                 mov     4, %o2! size_t
F002E46C: 10bffff3                 ba      loc_F002E438
F002E470: 80a42000                 cmp     %l0, 0
F002E474: 90100010                 mov     %l0, %o0! void *
F002E478: 9204a008                 add     %l2, 8, %o1! void *
F002E47C: 400199a5                 call    _bcopy
F002E480: 94102006                 mov     6, %o2! size_t
F002E484: 90100010                 mov     %l0, %o0! void *
F002E488: 9204e006                 add     %l3, 6, %o1! void *
F002E48C: 400199a1                 call    _bcopy
F002E490: 94102006                 mov     6, %o2
F002E494: 1100002090122035         set     0x8035, %o0
F002E49C: d034e00c                 sth     %o0, [%l3+0xC]
F002E4A0: 90102004                 mov     4, %o0
F002E4A4: d034a006                 sth     %o0, [%l2+6]
F002E4A8: 113c0431                 sethi   %hi(_revarpdebug), %o0
F002E4AC: d002202c                 ld      [%o0+%lo(_revarpdebug)], %o0
F002E4B0: 80a22000                 cmp     %o0, 0
F002E4B4: 02800007                 be      loc_F002E4D0
F002E4B8: c037bfe0                 clrh    [%fp+var_20]
F002E4BC: d204a018                 ld      [%l2+0x18], %o1
F002E4C0: 113c0431                 sethi   %hi(aRevarpReplyToX), %o0! "revarp reply to %X from %X\n"
F002E4C4: d404a00e                 ld      [%l2+0xE], %o2
F002E4C8: 7fff9864                 call    _printf
F002E4CC: 90122058                 bset    %lo(aRevarpReplyToX), %o0! "revarp reply to %X from %X\n"
F002E4D0: 90100018                 mov     %i0, %o0
F002E4D4: 92100019                 mov     %i1, %o1
F002E4D8: d6022034                 ld      [%o0+0x34], %o3
F002E4DC: 9fc2c000                 call    %o3
F002E4E0: 9407bfe0                 add     %fp, var_20, %o2
F002E4E4: 30800003                 ba,a    locret_F002E4F0
F002E4E8: 7fffbddf                 call    _m_freem
F002E4EC: 90100019                 mov     %i1, %o0
F002E4F0: 81c7e008                 ret
F002E4F4: 81e80000                 restore
