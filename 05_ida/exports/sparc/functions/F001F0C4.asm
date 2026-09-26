F001F0C4: 9de3bf90                 save    %sp, -0x70, %sp
F001F0C8: a6102000                 mov     0, %l3
F001F0CC: 80a72000                 cmp     %i4, 0
F001F0D0: 02800003                 be      loc_F001F0DC
F001F0D4: ec06200c                 ld      [%i0+0xC], %l6
F001F0D8: c0270000                 clr     [%i4]
F001F0DC: 80a66000                 cmp     %i1, 0
F001F0E0: 32800002                 bne,a   loc_F001F0E8
F001F0E4: c0264000                 clr     [%i1]
F001F0E8: 808ee001                 btst    1, %i3
F001F0EC: 02800030                 be      loc_F001F1AC
F001F0F0: 90102001                 mov     1, %o0
F001F0F4: 7ffffa1a                 call    _m_get
F001F0F8: 92102001                 mov     1, %o1
F001F0FC: a0100008                 mov     %o0, %l0
F001F100: 90100018                 mov     %i0, %o0
F001F104: 9210200d                 mov     0xD, %o1
F001F108: 94100010                 mov     %l0, %o2
F001F10C: 960ee002                 and     %i3, 2, %o3
F001F110: da05a01c                 ld      [%l6+0x1C], %o5
F001F114: 9fc34000                 call    %o5
F001F118: 98102000                 mov     0, %o4
F001F11C: a6920000                 orcc    %o0, %g0, %l3
F001F120: 1280001a                 bne     loc_F001F188
F001F124: 80a42000                 cmp     %l0, 0
F001F128: f206a014                 ld      [%i2+0x14], %i1
F001F12C: d0542008                 ldsh    [%l0+8], %o0
F001F130: 80a64008                 cmp     %i1, %o0
F001F134: 34800002                 bg,a    loc_F001F13C
F001F138: b2100008                 mov     %o0, %i1
F001F13C: 92100019                 mov     %i1, %o1
F001F140: 94102000                 mov     0, %o2
F001F144: d0042004                 ld      [%l0+4], %o0
F001F148: 9610001a                 mov     %i2, %o3
F001F14C: 7fffcc73                 call    _uiomove
F001F150: 90040008                 add     %l0, %o0, %o0
F001F154: a6100008                 mov     %o0, %l3
F001F158: 7ffffa57                 call    _m_free
F001F15C: 90100010                 mov     %l0, %o0
F001F160: d206a014                 ld      [%i2+0x14], %o1
F001F164: 80a26000                 cmp     %o1, 0
F001F168: 02800007                 be      loc_F001F184
F001F16C: a0100008                 mov     %o0, %l0
F001F170: 80a4e000                 cmp     %l3, 0
F001F174: 12800004                 bne     loc_F001F184
F001F178: 80a42000                 cmp     %l0, 0
F001F17C: 32bfffec                 bne,a   loc_F001F12C
F001F180: f206a014                 ld      [%i2+0x14], %i1
F001F184: 80a42000                 cmp     %l0, 0
F001F188: 028001e5                 be      locret_F001F91C
F001F18C: 01000000                 nop
F001F190: 7ffffab5                 call    _m_freem
F001F194: 90100010                 mov     %l0, %o0
F001F198: 308001e1                 ba,a    locret_F001F91C
F001F19C: d0362038                 sth     %o0, [%i0+0x38]
F001F1A0: 90062038                 add     %i0, 0x38, %o0 ! '8'! unsigned int
F001F1A4: 7fffcd35                 call    _sleep
F001F1A8: 9210201a                 mov     0x1A, %o1
F001F1AC: d0162038                 lduh    [%i0+0x38], %o0
F001F1B0: 808a2001                 btst    1, %o0
F001F1B4: 12bffffa                 bne     loc_F001F19C
F001F1B8: 90122002                 bset    2, %o0
F001F1BC: d0162038                 lduh    [%i0+0x38], %o0
F001F1C0: 90122001                 bset    1, %o0
F001F1C4: 4001deb4                 call    _splnet
F001F1C8: d0362038                 sth     %o0, [%i0+0x38]
F001F1CC: d2162024                 lduh    [%i0+0x24], %o1
F001F1D0: 80a26000                 cmp     %o1, 0
F001F1D4: 1280003a                 bne     loc_F001F2BC
F001F1D8: d027bff4                 st      %o0, [%fp+var_C]
F001F1DC: d0162056                 lduh    [%i0+0x56], %o0
F001F1E0: 80a22000                 cmp     %o0, 0
F001F1E4: 22800005                 be,a    loc_F001F1F8
F001F1E8: d0162006                 lduh    [%i0+6], %o0
F001F1EC: a6100008                 mov     %o0, %l3
F001F1F0: 108001c0                 ba      loc_F001F8F0
F001F1F4: c0362056                 clrh    [%i0+0x56]
F001F1F8: 808a2020                 btst    0x20, %o0 ! ' '
F001F1FC: 328001be                 bne,a   loc_F001F8F4
F001F200: d0162038                 lduh    [%i0+0x38], %o0
F001F204: 808a2002                 btst    2, %o0
F001F208: 32800009                 bne,a   loc_F001F22C
F001F20C: d006a014                 ld      [%i2+0x14], %o0
F001F210: d006200c                 ld      [%i0+0xC], %o0
F001F214: d012200a                 lduh    [%o0+0xA], %o0
F001F218: 808a2004                 btst    4, %o0
F001F21C: 22800004                 be,a    loc_F001F22C
F001F220: d006a014                 ld      [%i2+0x14], %o0
F001F224: 108001b3                 ba      loc_F001F8F0
F001F228: a6102039                 mov     0x39, %l3 ! '9'
F001F22C: 80a22000                 cmp     %o0, 0
F001F230: 228001b1                 be,a    loc_F001F8F4
F001F234: d0162038                 lduh    [%i0+0x38], %o0
F001F238: d0162006                 lduh    [%i0+6], %o0
F001F23C: 808a2100                 btst    0x100, %o0
F001F240: 02800010                 be      loc_F001F280
F001F244: 113c04cf                 sethi   %hi(_active_u), %o0
F001F248: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F001F24C: d0020000                 ld      [%o0], %o0
F001F250: d2022014                 ld      [%o0+0x14], %o1
F001F254: 11000010                 sethi   0x4000, %o0
F001F258: 808a4008                 btst    %o0, %o1
F001F25C: 028001a5                 be      loc_F001F8F0
F001F260: a6102023                 mov     0x23, %l3 ! '#'
F001F264: d216a010                 lduh    [%i2+0x10], %o1
F001F268: 11000008                 sethi   0x2000, %o0
F001F26C: 808a4008                 btst    %o0, %o1
F001F270: 328001a0                 bne,a   loc_F001F8F0
F001F274: a610200b                 mov     0xB, %l3
F001F278: 1080019f                 ba      loc_F001F8F4
F001F27C: d0162038                 lduh    [%i0+0x38], %o0
F001F280: d0162038                 lduh    [%i0+0x38], %o0
F001F284: 900a3ffe                 and     %o0, -2, %o0
F001F288: 808a2002                 btst    2, %o0
F001F28C: 02800006                 be      loc_F001F2A4
F001F290: d0362038                 sth     %o0, [%i0+0x38]
F001F294: 900a3ffd                 and     %o0, -3, %o0
F001F298: d0362038                 sth     %o0, [%i0+0x38]
F001F29C: 7fffced3                 call    _wakeup
F001F2A0: 90062038                 add     %i0, 0x38, %o0 ! '8'
F001F2A4: 4000042f                 call    _sbwait
F001F2A8: 90062024                 add     %i0, 0x24, %o0 ! '$'
F001F2AC: 4001de9e                 call    _splx
F001F2B0: d007bff4                 ld      [%fp+var_C], %o0
F001F2B4: 10bfffbf                 ba      loc_F001F1B0
F001F2B8: d0162038                 lduh    [%i0+0x38], %o0
F001F2BC: 113c04cf                 sethi   %hi(_active_u), %o0
F001F2C0: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F001F2C4: d00261a4                 ld      [%o1+0x1A4], %o0
F001F2C8: 90022001                 inc     %o0
F001F2CC: d02261a4                 st      %o0, [%o1+0x1A4]
F001F2D0: e0062030                 ld      [%i0+0x30], %l0
F001F2D4: 80a42000                 cmp     %l0, 0
F001F2D8: 32800006                 bne,a   loc_F001F2F0
F001F2DC: d015a00a                 lduh    [%l6+0xA], %o0
F001F2E0: 113c042f                 sethi   %hi(aReceive1), %o0! "receive 1"
F001F2E4: 7fffd7a3                 call    _panic
F001F2E8: 90122028                 bset    %lo(aReceive1), %o0! "receive 1"
F001F2EC: d015a00a                 lduh    [%l6+0xA], %o0
F001F2F0: 808a2002                 btst    2, %o0
F001F2F4: 02800059                 be      loc_F001F458
F001F2F8: ea04207c                 ld      [%l0+0x7C], %l5
F001F2FC: d054200a                 ldsh    [%l0+0xA], %o0
F001F300: 80a22008                 cmp     %o0, 8
F001F304: 02800006                 be      loc_F001F31C
F001F308: 808ee002                 btst    2, %i3
F001F30C: 113c042f                 sethi   %hi(aReceive1a), %o0! "receive 1a"
F001F310: 7fffd798                 call    _panic
F001F314: 90122038                 bset    %lo(aReceive1a), %o0! "receive 1a"
F001F318: 808ee002                 btst    2, %i3
F001F31C: 0280000a                 be      loc_F001F344
F001F320: 80a66000                 cmp     %i1, 0
F001F324: 02800006                 be      loc_F001F33C
F001F328: 90100010                 mov     %l0, %o0
F001F32C: d4542008                 ldsh    [%l0+8], %o2
F001F330: 7ffffa85                 call    _m_copy
F001F334: 92102000                 mov     0, %o1
F001F338: d0264000                 st      %o0, [%i1]
F001F33C: 10800047                 ba      loc_F001F458
F001F340: e0040000                 ld      [%l0], %l0
F001F344: d2162024                 lduh    [%i0+0x24], %o1
F001F348: d0142008                 lduh    [%l0+8], %o0
F001F34C: 92224008                 sub     %o1, %o0, %o1
F001F350: d0162028                 lduh    [%i0+0x28], %o0
F001F354: d2362024                 sth     %o1, [%i0+0x24]
F001F358: 92023f80                 add     %o0, -0x80, %o1
F001F35C: d2362028                 sth     %o1, [%i0+0x28]
F001F360: d0042004                 ld      [%l0+4], %o0
F001F364: 80a2207c                 cmp     %o0, 0x7C ! '|'
F001F368: 08800003                 bleu    loc_F001F374
F001F36C: 90027c00                 add     %o1, -0x400, %o0
F001F370: d0362028                 sth     %o0, [%i0+0x28]
F001F374: 80a66000                 cmp     %i1, 0
F001F378: 02800008                 be      loc_F001F398
F001F37C: 01000000                 nop
F001F380: e0264000                 st      %l0, [%i1]
F001F384: d0064000                 ld      [%i1], %o0
F001F388: e0040000                 ld      [%l0], %l0
F001F38C: c0220000                 clr     [%o0]
F001F390: 1080002f                 ba      loc_F001F44C
F001F394: e0262030                 st      %l0, [%i0+0x30]
F001F398: 4001de08                 call    _spltty
F001F39C: 01000000                 nop
F001F3A0: d254200a                 ldsh    [%l0+0xA], %o1
F001F3A4: 80a26000                 cmp     %o1, 0
F001F3A8: 12800005                 bne     loc_F001F3BC
F001F3AC: a2100008                 mov     %o0, %l1
F001F3B0: 113c042f                 sethi   %hi(aMfree_0), %o0! "mfree"
F001F3B4: 7fffd76f                 call    _panic
F001F3B8: 90122048                 bset    %lo(aMfree_0), %o0! "mfree"
F001F3BC: 153c04d2                 sethi   %hi(word_F0134B0C), %o2
F001F3C0: d254200a                 ldsh    [%l0+0xA], %o1
F001F3C4: 9612a30c                 or      %o2, %lo(word_F0134B0C), %o3
F001F3C8: 932a6001                 sll     %o1, 1, %o1
F001F3CC: d012400b                 lduh    [%o1+%o3], %o0
F001F3D0: 90023fff                 inc     -1, %o0
F001F3D4: d032400b                 sth     %o0, [%o1+%o3]
F001F3D8: d012a30c                 lduh    [%o2+%lo(word_F0134B0C)], %o0
F001F3DC: 90022001                 inc     %o0
F001F3E0: d032a30c                 sth     %o0, [%o2+%lo(word_F0134B0C)]
F001F3E4: d0042004                 ld      [%l0+4], %o0
F001F3E8: 80a2207f                 cmp     %o0, 0x7F
F001F3EC: 08800004                 bleu    loc_F001F3FC
F001F3F0: c034200a                 clrh    [%l0+0xA]
F001F3F4: 7ffffc05                 call    _mclput
F001F3F8: 90100010                 mov     %l0, %o0
F001F3FC: 90100011                 mov     %l1, %o0
F001F400: d6040000                 ld      [%l0], %o3
F001F404: 133c04d3                 sethi   %hi(_mfree), %o1
F001F408: d4026168                 ld      [%o1+%lo(_mfree)], %o2
F001F40C: d6262030                 st      %o3, [%i0+0x30]
F001F410: d4240000                 st      %o2, [%l0]
F001F414: c0242004                 clr     [%l0+4]
F001F418: c024207c                 clr     [%l0+0x7C]
F001F41C: e0226168                 st      %l0, [%o1+%lo(_mfree)]
F001F420: 4001de41                 call    _splx
F001F424: a0126168                 or      %o1, %lo(_mfree), %l0
F001F428: 133c04d2                 sethi   %hi(_m_want), %o1
F001F42C: d00262e8                 ld      [%o1+%lo(_m_want)], %o0
F001F430: 80a22000                 cmp     %o0, 0
F001F434: 22800006                 be,a    loc_F001F44C
F001F438: e0062030                 ld      [%i0+0x30], %l0
F001F43C: c02262e8                 clr     [%o1+%lo(_m_want)]
F001F440: 7fffce6a                 call    _wakeup
F001F444: 90100010                 mov     %l0, %o0
F001F448: e0062030                 ld      [%i0+0x30], %l0
F001F44C: 80a42000                 cmp     %l0, 0
F001F450: 32800003                 bne,a   loc_F001F45C
F001F454: ea24207c                 st      %l5, [%l0+0x7C]
F001F458: 80a42000                 cmp     %l0, 0
F001F45C: 0280005e                 be      loc_F001F5D4
F001F460: a4102000                 mov     0, %l2
F001F464: d054200a                 ldsh    [%l0+0xA], %o0
F001F468: 80a2200c                 cmp     %o0, 0xC
F001F46C: 1280005a                 bne     loc_F001F5D4
F001F470: 80a42000                 cmp     %l0, 0
F001F474: d015a00a                 lduh    [%l6+0xA], %o0
F001F478: 808a2010                 btst    0x10, %o0
F001F47C: 12800006                 bne     loc_F001F494
F001F480: 808ee002                 btst    2, %i3
F001F484: 113c042f                 sethi   %hi(aReceive2), %o0! "receive 2"
F001F488: 7fffd73a                 call    _panic
F001F48C: 90122050                 bset    %lo(aReceive2), %o0! "receive 2"
F001F490: 808ee002                 btst    2, %i3
F001F494: 0280000a                 be      loc_F001F4BC
F001F498: 80a72000                 cmp     %i4, 0
F001F49C: 02800006                 be      loc_F001F4B4
F001F4A0: 90100010                 mov     %l0, %o0
F001F4A4: d4542008                 ldsh    [%l0+8], %o2
F001F4A8: 7ffffa27                 call    _m_copy
F001F4AC: 92102000                 mov     0, %o1
F001F4B0: d0270000                 st      %o0, [%i4]
F001F4B4: 10800046                 ba      loc_F001F5CC
F001F4B8: e0040000                 ld      [%l0], %l0
F001F4BC: d2162024                 lduh    [%i0+0x24], %o1
F001F4C0: d0142008                 lduh    [%l0+8], %o0
F001F4C4: 92224008                 sub     %o1, %o0, %o1
F001F4C8: d0162028                 lduh    [%i0+0x28], %o0
F001F4CC: d2362024                 sth     %o1, [%i0+0x24]
F001F4D0: 92023f80                 add     %o0, -0x80, %o1
F001F4D4: d2362028                 sth     %o1, [%i0+0x28]
F001F4D8: d0042004                 ld      [%l0+4], %o0
F001F4DC: 80a2207c                 cmp     %o0, 0x7C ! '|'
F001F4E0: 08800003                 bleu    loc_F001F4EC
F001F4E4: 90027c00                 add     %o1, -0x400, %o0
F001F4E8: d0362028                 sth     %o0, [%i0+0x28]
F001F4EC: 80a72000                 cmp     %i4, 0
F001F4F0: 02800007                 be      loc_F001F50C
F001F4F4: 01000000                 nop
F001F4F8: e0270000                 st      %l0, [%i4]
F001F4FC: d0040000                 ld      [%l0], %o0
F001F500: d0262030                 st      %o0, [%i0+0x30]
F001F504: 1080002e                 ba      loc_F001F5BC
F001F508: c0240000                 clr     [%l0]
F001F50C: 4001ddab                 call    _spltty
F001F510: 01000000                 nop
F001F514: d254200a                 ldsh    [%l0+0xA], %o1
F001F518: 80a26000                 cmp     %o1, 0
F001F51C: 12800005                 bne     loc_F001F530
F001F520: a2100008                 mov     %o0, %l1
F001F524: 113c042f                 sethi   %hi(aMfree_1), %o0! "mfree"
F001F528: 7fffd712                 call    _panic
F001F52C: 90122060                 bset    %lo(aMfree_1), %o0! "mfree"
F001F530: 153c04d2                 sethi   %hi(word_F0134B0C), %o2
F001F534: d254200a                 ldsh    [%l0+0xA], %o1
F001F538: 9612a30c                 or      %o2, %lo(word_F0134B0C), %o3
F001F53C: 932a6001                 sll     %o1, 1, %o1
F001F540: d012400b                 lduh    [%o1+%o3], %o0
F001F544: 90023fff                 inc     -1, %o0
F001F548: d032400b                 sth     %o0, [%o1+%o3]
F001F54C: d012a30c                 lduh    [%o2+%lo(word_F0134B0C)], %o0
F001F550: 90022001                 inc     %o0
F001F554: d032a30c                 sth     %o0, [%o2+%lo(word_F0134B0C)]
F001F558: d0042004                 ld      [%l0+4], %o0
F001F55C: 80a2207f                 cmp     %o0, 0x7F
F001F560: 08800004                 bleu    loc_F001F570
F001F564: c034200a                 clrh    [%l0+0xA]
F001F568: 7ffffba8                 call    _mclput
F001F56C: 90100010                 mov     %l0, %o0
F001F570: 90100011                 mov     %l1, %o0
F001F574: d6040000                 ld      [%l0], %o3
F001F578: 133c04d3                 sethi   %hi(_mfree), %o1
F001F57C: d4026168                 ld      [%o1+%lo(_mfree)], %o2
F001F580: d6262030                 st      %o3, [%i0+0x30]
F001F584: d4240000                 st      %o2, [%l0]
F001F588: c0242004                 clr     [%l0+4]
F001F58C: c024207c                 clr     [%l0+0x7C]
F001F590: e0226168                 st      %l0, [%o1+%lo(_mfree)]
F001F594: 4001dde4                 call    _splx
F001F598: a0126168                 or      %o1, %lo(_mfree), %l0
F001F59C: 133c04d2                 sethi   %hi(_m_want), %o1
F001F5A0: d00262e8                 ld      [%o1+%lo(_m_want)], %o0
F001F5A4: 80a22000                 cmp     %o0, 0
F001F5A8: 22800006                 be,a    loc_F001F5C0
F001F5AC: e0062030                 ld      [%i0+0x30], %l0
F001F5B0: c02262e8                 clr     [%o1+%lo(_m_want)]
F001F5B4: 7fffce0d                 call    _wakeup
F001F5B8: 90100010                 mov     %l0, %o0
F001F5BC: e0062030                 ld      [%i0+0x30], %l0
F001F5C0: 80a42000                 cmp     %l0, 0
F001F5C4: 32800002                 bne,a   loc_F001F5CC
F001F5C8: ea24207c                 st      %l5, [%l0+0x7C]
F001F5CC: a4102000                 mov     0, %l2
F001F5D0: 80a42000                 cmp     %l0, 0
F001F5D4: 0280009a                 be      loc_F001F83C
F001F5D8: a8102000                 mov     0, %l4
F001F5DC: d006a014                 ld      [%i2+0x14], %o0
F001F5E0: 80a22000                 cmp     %o0, 0
F001F5E4: 04800096                 ble     loc_F001F83C
F001F5E8: 80a4e000                 cmp     %l3, 0
F001F5EC: 12800095                 bne     loc_F001F840
F001F5F0: 808ee002                 btst    2, %i3
F001F5F4: 3b3c04d2                 sethi   -0xFECB800, %i5
F001F5F8: 2f3c04d3                 sethi   -0xFECB400, %l7
F001F5FC: d014200a                 lduh    [%l0+0xA], %o0
F001F600: 90023fff                 inc     -1, %o0
F001F604: 912a2010                 sll     %o0, 16, %o0
F001F608: 91322010                 srl     %o0, 16, %o0
F001F60C: 80a22001                 cmp     %o0, 1
F001F610: 08800004                 bleu    loc_F001F620
F001F614: 113c042f                 sethi   %hi(aReceive3), %o0! "receive 3"
F001F618: 7fffd6d6                 call    _panic
F001F61C: 90122068                 bset    %lo(aReceive3), %o0! "receive 3"
F001F620: d0162006                 lduh    [%i0+6], %o0
F001F624: f206a014                 ld      [%i2+0x14], %i1
F001F628: d2162058                 lduh    [%i0+0x58], %o1
F001F62C: 900a3fbf                 and     %o0, -0x41, %o0
F001F630: 80a26000                 cmp     %o1, 0
F001F634: 02800006                 be      loc_F001F64C
F001F638: d0362006                 sth     %o0, [%i0+6]
F001F63C: 90224014                 sub     %o1, %l4, %o0
F001F640: 80a64008                 cmp     %i1, %o0
F001F644: 34800002                 bg,a    loc_F001F64C
F001F648: b2100008                 mov     %o0, %i1
F001F64C: d0542008                 ldsh    [%l0+8], %o0
F001F650: 90220012                 sub     %o0, %l2, %o0
F001F654: 80a64008                 cmp     %i1, %o0
F001F658: 34800002                 bg,a    loc_F001F660
F001F65C: b2100008                 mov     %o0, %i1
F001F660: 4001ddb1                 call    _splx
F001F664: d007bff4                 ld      [%fp+var_C], %o0
F001F668: 92100019                 mov     %i1, %o1
F001F66C: 94102000                 mov     0, %o2
F001F670: d0042004                 ld      [%l0+4], %o0
F001F674: 9610001a                 mov     %i2, %o3
F001F678: 90040008                 add     %l0, %o0, %o0
F001F67C: 7fffcb27                 call    _uiomove
F001F680: 90020012                 add     %o0, %l2, %o0
F001F684: 4001dd84                 call    _splnet
F001F688: a6100008                 mov     %o0, %l3
F001F68C: d2542008                 ldsh    [%l0+8], %o1
F001F690: d027bff4                 st      %o0, [%fp+var_C]
F001F694: 90224012                 sub     %o1, %l2, %o0
F001F698: 80a64008                 cmp     %i1, %o0
F001F69C: 12800042                 bne     loc_F001F7A4
F001F6A0: 808ee002                 btst    2, %i3
F001F6A4: 22800005                 be,a    loc_F001F6B8
F001F6A8: ea04207c                 ld      [%l0+0x7C], %l5
F001F6AC: e0040000                 ld      [%l0], %l0
F001F6B0: 10800049                 ba      loc_F001F7D4
F001F6B4: a4102000                 mov     0, %l2
F001F6B8: d0162024                 lduh    [%i0+0x24], %o0
F001F6BC: 90220009                 sub     %o0, %o1, %o0
F001F6C0: d2162028                 lduh    [%i0+0x28], %o1
F001F6C4: d0362024                 sth     %o0, [%i0+0x24]
F001F6C8: 92027f80                 inc     -0x80, %o1
F001F6CC: d2362028                 sth     %o1, [%i0+0x28]
F001F6D0: d0042004                 ld      [%l0+4], %o0
F001F6D4: 80a2207c                 cmp     %o0, 0x7C ! '|'
F001F6D8: 08800003                 bleu    loc_F001F6E4
F001F6DC: 90027c00                 add     %o1, -0x400, %o0
F001F6E0: d0362028                 sth     %o0, [%i0+0x28]
F001F6E4: 4001dd35                 call    _spltty
F001F6E8: 01000000                 nop
F001F6EC: d254200a                 ldsh    [%l0+0xA], %o1
F001F6F0: 80a26000                 cmp     %o1, 0
F001F6F4: 12800005                 bne     loc_F001F708
F001F6F8: a2100008                 mov     %o0, %l1
F001F6FC: 113c042f                 sethi   %hi(aMfree_2), %o0! "mfree"
F001F700: 7fffd69c                 call    _panic
F001F704: 90122078                 bset    %lo(aMfree_2), %o0! "mfree"
F001F708: 053c04d2                 sethi   %hi(word_F0134B0C), %g2
F001F70C: d254200a                 ldsh    [%l0+0xA], %o1
F001F710: 8410a30c                 bset    %lo(word_F0134B0C), %g2
F001F714: 932a6001                 sll     %o1, 1, %o1
F001F718: d0124002                 lduh    [%o1+%g2], %o0
F001F71C: 90023fff                 inc     -1, %o0
F001F720: d0324002                 sth     %o0, [%o1+%g2]
F001F724: d017630c                 lduh    [%i5+0x30C], %o0
F001F728: 90022001                 inc     %o0
F001F72C: d037630c                 sth     %o0, [%i5+0x30C]
F001F730: d0042004                 ld      [%l0+4], %o0
F001F734: 80a2207f                 cmp     %o0, 0x7F
F001F738: 08800004                 bleu    loc_F001F748
F001F73C: c034200a                 clrh    [%l0+0xA]
F001F740: 7ffffb32                 call    _mclput
F001F744: 90100010                 mov     %l0, %o0
F001F748: d4040000                 ld      [%l0], %o2
F001F74C: 90100011                 mov     %l1, %o0
F001F750: d205e168                 ld      [%l7+0x168], %o1
F001F754: d4262030                 st      %o2, [%i0+0x30]
F001F758: d2240000                 st      %o1, [%l0]
F001F75C: c0242004                 clr     [%l0+4]
F001F760: c024207c                 clr     [%l0+0x7C]
F001F764: 4001dd70                 call    _splx
F001F768: e025e168                 st      %l0, [%l7+0x168]
F001F76C: 053c04d2                 sethi   %hi(_m_want), %g2
F001F770: d000a2e8                 ld      [%g2+%lo(_m_want)], %o0
F001F774: 80a22000                 cmp     %o0, 0
F001F778: 22800006                 be,a    loc_F001F790
F001F77C: e0062030                 ld      [%i0+0x30], %l0
F001F780: c020a2e8                 clr     [%g2+%lo(_m_want)]
F001F784: 7fffcd99                 call    _wakeup
F001F788: 9015e168                 or      %l7, 0x168, %o0
F001F78C: e0062030                 ld      [%i0+0x30], %l0
F001F790: 80a42000                 cmp     %l0, 0
F001F794: 32800010                 bne,a   loc_F001F7D4
F001F798: ea24207c                 st      %l5, [%l0+0x7C]
F001F79C: 1080000f                 ba      loc_F001F7D8
F001F7A0: d0162058                 lduh    [%i0+0x58], %o0
F001F7A4: 22800004                 be,a    loc_F001F7B4
F001F7A8: d0042004                 ld      [%l0+4], %o0
F001F7AC: 1080000a                 ba      loc_F001F7D4
F001F7B0: a4048019                 add     %l2, %i1, %l2
F001F7B4: d2142008                 lduh    [%l0+8], %o1
F001F7B8: 90020019                 add     %o0, %i1, %o0
F001F7BC: d0242004                 st      %o0, [%l0+4]
F001F7C0: 92224019                 sub     %o1, %i1, %o1
F001F7C4: d2342008                 sth     %o1, [%l0+8]
F001F7C8: d0162024                 lduh    [%i0+0x24], %o0
F001F7CC: 90220019                 sub     %o0, %i1, %o0
F001F7D0: d0362024                 sth     %o0, [%i0+0x24]
F001F7D4: d0162058                 lduh    [%i0+0x58], %o0
F001F7D8: 80a22000                 cmp     %o0, 0
F001F7DC: 02800010                 be      loc_F001F81C
F001F7E0: 80a42000                 cmp     %l0, 0
F001F7E4: 808ee002                 btst    2, %i3
F001F7E8: 3280000c                 bne,a   loc_F001F818
F001F7EC: a8050019                 add     %l4, %i1, %l4
F001F7F0: 90220019                 sub     %o0, %i1, %o0
F001F7F4: d0362058                 sth     %o0, [%i0+0x58]
F001F7F8: 912a2010                 sll     %o0, 16, %o0
F001F7FC: 80a22000                 cmp     %o0, 0
F001F800: 12800007                 bne     loc_F001F81C
F001F804: 80a42000                 cmp     %l0, 0
F001F808: d0162006                 lduh    [%i0+6], %o0
F001F80C: 90122040                 bset    0x40, %o0 ! '@'
F001F810: 1080000b                 ba      loc_F001F83C
F001F814: d0362006                 sth     %o0, [%i0+6]
F001F818: 80a42000                 cmp     %l0, 0
F001F81C: 02800009                 be      loc_F001F840
F001F820: 808ee002                 btst    2, %i3
F001F824: d006a014                 ld      [%i2+0x14], %o0
F001F828: 80a22000                 cmp     %o0, 0
F001F82C: 04800004                 ble     loc_F001F83C
F001F830: 80a4e000                 cmp     %l3, 0
F001F834: 22bfff73                 be,a    loc_F001F600
F001F838: d014200a                 lduh    [%l0+0xA], %o0
F001F83C: 808ee002                 btst    2, %i3
F001F840: 3280002d                 bne,a   loc_F001F8F4
F001F844: d0162038                 lduh    [%i0+0x38], %o0
F001F848: 80a42000                 cmp     %l0, 0
F001F84C: 32800004                 bne,a   loc_F001F85C
F001F850: d015a00a                 lduh    [%l6+0xA], %o0
F001F854: 10800007                 ba      loc_F001F870
F001F858: ea262030                 st      %l5, [%i0+0x30]
F001F85C: 808a2001                 btst    1, %o0
F001F860: 22800005                 be,a    loc_F001F874
F001F864: d015a00a                 lduh    [%l6+0xA], %o0
F001F868: 40000554                 call    _sbdroprecord
F001F86C: 90062024                 add     %i0, 0x24, %o0 ! '$'
F001F870: d015a00a                 lduh    [%l6+0xA], %o0
F001F874: 808a2008                 btst    8, %o0
F001F878: 0280000d                 be      loc_F001F8AC
F001F87C: 80a4e000                 cmp     %l3, 0
F001F880: d0062008                 ld      [%i0+8], %o0
F001F884: 80a22000                 cmp     %o0, 0
F001F888: 02800008                 be      loc_F001F8A8
F001F88C: 90100018                 mov     %i0, %o0
F001F890: 92102008                 mov     8, %o1
F001F894: 94102000                 mov     0, %o2
F001F898: 96102000                 mov     0, %o3
F001F89C: da05a01c                 ld      [%l6+0x1C], %o5
F001F8A0: 9fc34000                 call    %o5
F001F8A4: 98102000                 mov     0, %o4
F001F8A8: 80a4e000                 cmp     %l3, 0
F001F8AC: 32800012                 bne,a   loc_F001F8F4
F001F8B0: d0162038                 lduh    [%i0+0x38], %o0
F001F8B4: 80a72000                 cmp     %i4, 0
F001F8B8: 2280000f                 be,a    loc_F001F8F4
F001F8BC: d0162038                 lduh    [%i0+0x38], %o0
F001F8C0: f8070000                 ld      [%i4], %i4
F001F8C4: 80a72000                 cmp     %i4, 0
F001F8C8: 2280000b                 be,a    loc_F001F8F4
F001F8CC: d0162038                 lduh    [%i0+0x38], %o0
F001F8D0: d005a004                 ld      [%l6+4], %o0
F001F8D4: d202200c                 ld      [%o0+0xC], %o1
F001F8D8: 80a26000                 cmp     %o1, 0
F001F8DC: 22800006                 be,a    loc_F001F8F4
F001F8E0: d0162038                 lduh    [%i0+0x38], %o0
F001F8E4: 9fc24000                 call    %o1
F001F8E8: 9010001c                 mov     %i4, %o0
F001F8EC: a6100008                 mov     %o0, %l3
F001F8F0: d0162038                 lduh    [%i0+0x38], %o0
F001F8F4: 900a3ffe                 and     %o0, -2, %o0
F001F8F8: 808a2002                 btst    2, %o0
F001F8FC: 02800006                 be      loc_F001F914
F001F900: d0362038                 sth     %o0, [%i0+0x38]
F001F904: 900a3ffd                 and     %o0, -3, %o0
F001F908: d0362038                 sth     %o0, [%i0+0x38]
F001F90C: 7fffcd37                 call    _wakeup
F001F910: 90062038                 add     %i0, 0x38, %o0 ! '8'
F001F914: 4001dd04                 call    _splx
F001F918: d007bff4                 ld      [%fp+var_C], %o0
F001F91C: 81c7e008                 ret
F001F920: 91e80013                 restore %g0, %l3, %o0
