F001B258: 9de3bf98                 save    %sp, -0x68, %sp
F001B25C: 900e20ff                 and     %i0, 0xFF, %o0
F001B260: 80a2201f                 cmp     %o0, 0x1F
F001B264: 04800004                 ble     loc_F001B274
F001B268: a4100018                 mov     %i0, %l2
F001B26C: 10800044                 ba      locret_F001B37C
F001B270: b0102006                 mov     6, %i0
F001B274: 912e2010                 sll     %i0, 16, %o0
F001B278: 7fffffd9                 call    _pty_alloc
F001B27C: 913a2010                 sra     %o0, 16, %o0
F001B280: a2100008                 mov     %o0, %l1
F001B284: e0046008                 ld      [%l1+8], %l0
F001B288: e4344000                 sth     %l2, [%l1]
F001B28C: d0042040                 ld      [%l0+0x40], %o0
F001B290: 808a2004                 btst    4, %o0
F001B294: 0280000b                 be      loc_F001B2C0
F001B298: 808a2080                 btst    0x80, %o0
F001B29C: 0280000f                 be      loc_F001B2D8
F001B2A0: 113c04cf                 sethi   %hi(_active_u), %o0
F001B2A4: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F001B2A8: d002201c                 ld      [%o0+0x1C], %o0
F001B2AC: d0522002                 ldsh    [%o0+2], %o0
F001B2B0: 80a22000                 cmp     %o0, 0
F001B2B4: 02800009                 be      loc_F001B2D8
F001B2B8: b0102010                 mov     0x10, %i0
F001B2BC: 30800030                 ba,a    locret_F001B37C
F001B2C0: 7fffed83                 call    _ttychars
F001B2C4: 90100010                 mov     %l0, %o0
F001B2C8: 9010200f                 mov     0xF, %o0
F001B2CC: d02c204a                 stb     %o0, [%l0+0x4A]
F001B2D0: d02c2049                 stb     %o0, [%l0+0x49]
F001B2D4: c024203c                 clr     [%l0+0x3C]
F001B2D8: d0042024                 ld      [%l0+0x24], %o0
F001B2DC: 80a22000                 cmp     %o0, 0
F001B2E0: 02800005                 be      loc_F001B2F4
F001B2E4: 808e6004                 btst    4, %i1
F001B2E8: d0042040                 ld      [%l0+0x40], %o0
F001B2EC: 90122010                 bset    0x10, %o0
F001B2F0: d0242040                 st      %o0, [%l0+0x40]
F001B2F4: 0280000b                 be      loc_F001B320
F001B2F8: d0042040                 ld      [%l0+0x40], %o0
F001B2FC: 13000020                 sethi   0x8000, %o1
F001B300: 90120009                 bset    %o1, %o0
F001B304: 1080000a                 ba      loc_F001B32C
F001B308: d0242040                 st      %o0, [%l0+0x40]
F001B30C: d0242040                 st      %o0, [%l0+0x40]
F001B310: 90100010                 mov     %l0, %o0! unsigned int
F001B314: 7fffdcd9                 call    _sleep
F001B318: 9210201c                 mov     0x1C, %o1
F001B31C: d0042040                 ld      [%l0+0x40], %o0
F001B320: 808a2010                 btst    0x10, %o0
F001B324: 02bffffa                 be      loc_F001B30C
F001B328: 90122002                 bset    2, %o0
F001B32C: d24c2047                 ldsb    [%l0+0x47], %o1
F001B330: 912ca010                 sll     %l2, 16, %o0
F001B334: 952a6001                 sll     %o1, 1, %o2
F001B338: 94028009                 add     %o2, %o1, %o2
F001B33C: 952aa004                 sll     %o2, 4, %o2
F001B340: 133c042e921260cc         set     _linesw, %o1
F001B348: d4028009                 ld      [%o2+%o1], %o2
F001B34C: 913a2010                 sra     %o0, 16, %o0
F001B350: 9fc28000                 call    %o2
F001B354: 92100010                 mov     %l0, %o1
F001B358: b0920000                 orcc    %o0, %g0, %i0
F001B35C: 12800006                 bne     loc_F001B374
F001B360: 90100010                 mov     %l0, %o0
F001B364: d0046004                 ld      [%l1+4], %o0
F001B368: 90122001                 bset    1, %o0
F001B36C: d0246004                 st      %o0, [%l1+4]
F001B370: 90100010                 mov     %l0, %o0
F001B374: 400000f8                 call    _ptcwakeup
F001B378: 92102003                 mov     3, %o1
F001B37C: 81c7e008                 ret
F001B380: 81e80000                 restore
