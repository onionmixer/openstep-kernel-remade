F00BA2E0: 9de3bf98                 save    %sp, -0x68, %sp
F00BA2E4: e6062034                 ld      [%i0+0x34], %l3
F00BA2E8: 7fff7234                 call    _spltty
F00BA2EC: e404e018                 ld      [%l3+0x18], %l2
F00BA2F0: d4062040                 ld      [%i0+0x40], %o2
F00BA2F4: 808aa129                 btst    0x129, %o2
F00BA2F8: 12800058                 bne     loc_F00BA458
F00BA2FC: a8100008                 mov     %o0, %l4
F00BA300: 113c042d                 sethi   %hi(_ttlowat), %o0
F00BA304: d20e204a                 ldub    [%i0+0x4A], %o1
F00BA308: 90122360                 bset    %lo(_ttlowat), %o0
F00BA30C: 920a601f                 and     %o1, 0x1F, %o1
F00BA310: 932a6001                 sll     %o1, 1, %o1
F00BA314: d2524008                 ldsh    [%o1+%o0], %o1
F00BA318: d0062018                 ld      [%i0+0x18], %o0
F00BA31C: 80a20009                 cmp     %o0, %o1
F00BA320: 14800016                 bg      loc_F00BA378
F00BA324: 80a22000                 cmp     %o0, 0
F00BA328: 808aa040                 btst    0x40, %o2 ! '@'
F00BA32C: 02800005                 be      loc_F00BA340
F00BA330: 900abfbf                 and     %o2, -0x41, %o0
F00BA334: d0262040                 st      %o0, [%i0+0x40]
F00BA338: 7ffd62ac                 call    _wakeup
F00BA33C: 90062018                 add     %i0, 0x18, %o0
F00BA340: d006202c                 ld      [%i0+0x2C], %o0
F00BA344: 80a22000                 cmp     %o0, 0
F00BA348: 0280000a                 be      loc_F00BA370
F00BA34C: 13000004                 sethi   0x1000, %o1
F00BA350: d4062040                 ld      [%i0+0x40], %o2
F00BA354: 7ffd6f70                 call    _selwakeup
F00BA358: 920a8009                 and     %o2, %o1, %o1
F00BA35C: c026202c                 clr     [%i0+0x2C]
F00BA360: d2062040                 ld      [%i0+0x40], %o1
F00BA364: 11000004                 sethi   0x1000, %o0
F00BA368: 902a4008                 andn    %o1, %o0, %o0
F00BA36C: d0262040                 st      %o0, [%i0+0x40]
F00BA370: d0062018                 ld      [%i0+0x18], %o0
F00BA374: 80a22000                 cmp     %o0, 0
F00BA378: 02800038                 be      loc_F00BA458
F00BA37C: 01000000                 nop
F00BA380: d054a118                 ldsh    [%l2+0x118], %o0
F00BA384: 80a22000                 cmp     %o0, 0
F00BA388: 34800032                 bg,a    loc_F00BA450
F00BA38C: d0062040                 ld      [%i0+0x40], %o0
F00BA390: d206203c                 ld      [%i0+0x3C], %o1
F00BA394: 1100080090122020         set     0x200020, %o0
F00BA39C: 808a4008                 btst    %o0, %o1
F00BA3A0: 12800014                 bne     loc_F00BA3F0
F00BA3A4: 90062018                 add     %i0, 0x18, %o0
F00BA3A8: a2062018                 add     %i0, 0x18, %l1
F00BA3AC: 90100011                 mov     %l1, %o0! FILE *
F00BA3B0: 7ffd8971                 call    _ndqb
F00BA3B4: 92102080                 mov     0x80, %o1
F00BA3B8: a0920000                 orcc    %o0, %g0, %l0
F00BA3BC: 12800010                 bne     loc_F00BA3FC
F00BA3C0: 01000000                 nop
F00BA3C4: 7ffd88c1                 call    _getc
F00BA3C8: 90100011                 mov     %l1, %o0
F00BA3CC: 133c005a                 sethi   %hi(_ttrstrt), %o1
F00BA3D0: 940a207f                 and     %o0, 0x7F, %o2
F00BA3D4: 90126310                 or      %o1, %lo(_ttrstrt), %o0! int
F00BA3D8: 92100018                 mov     %i0, %o1
F00BA3DC: 7ffd3f13                 call    _timeout
F00BA3E0: 9402a006                 inc     6, %o2
F00BA3E4: d0062040                 ld      [%i0+0x40], %o0
F00BA3E8: 1080001b                 ba      loc_F00BA454
F00BA3EC: 90122001                 bset    1, %o0
F00BA3F0: 7ffd8961                 call    _ndqb
F00BA3F4: 92102000                 mov     0, %o1
F00BA3F8: a0100008                 mov     %o0, %l0
F00BA3FC: 7fff71dc                 call    _splzs
F00BA400: 01000000                 nop
F00BA404: d006201c                 ld      [%i0+0x1C], %o0
F00BA408: d024a114                 st      %o0, [%l2+0x114]
F00BA40C: 90100010                 mov     %l0, %o0
F00BA410: d034a118                 sth     %o0, [%l2+0x118]
F00BA414: d034a11a                 sth     %o0, [%l2+0x11A]
F00BA418: d404e010                 ld      [%l3+0x10], %o2
F00BA41C: d00a8000                 ldub    [%o2], %o0
F00BA420: 808a2004                 btst    4, %o0
F00BA424: 2280000b                 be,a    loc_F00BA450
F00BA428: d0062040                 ld      [%i0+0x40], %o0
F00BA42C: d204a114                 ld      [%l2+0x114], %o1
F00BA430: 90026001                 add     %o1, 1, %o0
F00BA434: d024a114                 st      %o0, [%l2+0x114]
F00BA438: d00a4000                 ldub    [%o1], %o0
F00BA43C: d02aa002                 stb     %o0, [%o2+2]
F00BA440: d014a118                 lduh    [%l2+0x118], %o0
F00BA444: 90023fff                 inc     -1, %o0
F00BA448: d034a118                 sth     %o0, [%l2+0x118]
F00BA44C: d0062040                 ld      [%i0+0x40], %o0
F00BA450: 90122020                 bset    0x20, %o0 ! ' '
F00BA454: d0262040                 st      %o0, [%i0+0x40]
F00BA458: 7fff7233                 call    _splx
F00BA45C: 90100014                 mov     %l4, %o0
F00BA460: 81c7e008                 ret
F00BA464: 81e80000                 restore
