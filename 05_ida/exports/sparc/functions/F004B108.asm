F004B108: 9de3bf98                 save    %sp, -0x68, %sp
F004B10C: a6102000                 mov     0, %l3
F004B110: a4102000                 mov     0, %l2
F004B114: 7ffef0c9                 call    _strlen
F004B118: 90100019                 mov     %i1, %o0
F004B11C: d2162064                 lduh    [%i0+0x64], %o1
F004B120: 1500003c                 sethi   0xF000, %o2
F004B124: 920a400a                 and     %o1, %o2, %o1
F004B128: 15000010                 sethi   0x4000, %o2
F004B12C: 80a2400a                 cmp     %o1, %o2
F004B130: 02800004                 be      loc_F004B140
F004B134: ac100008                 mov     %o0, %l6
F004B138: 108000f5                 ba      locret_F004B50C
F004B13C: b0102014                 mov     0x14, %i0
F004B140: 90100018                 mov     %i0, %o0
F004B144: 40000ff1                 call    _iaccess
F004B148: 92102040                 mov     0x40, %o1 ! '@'
F004B14C: a0920000                 orcc    %o0, %g0, %l0
F004B150: 328000ef                 bne,a   locret_F004B50C
F004B154: b0100010                 mov     %l0, %i0
F004B158: 9006200c                 add     %i0, 0xC, %o0
F004B15C: 92100019                 mov     %i1, %o1
F004B160: 7fff6a60                 call    _dnlc_lookup
F004B164: 94102000                 mov     0, %o2
F004B168: 94920000                 orcc    %o0, %g0, %o2
F004B16C: 22800020                 be,a    loc_F004B1EC
F004B170: d0162044                 lduh    [%i0+0x44], %o0
F004B174: d012a006                 lduh    [%o2+6], %o0
F004B178: d202a030                 ld      [%o2+0x30], %o1
F004B17C: 90022001                 inc     %o0
F004B180: d032a006                 sth     %o0, [%o2+6]
F004B184: d2268000                 st      %o1, [%i2]
F004B188: d0126044                 lduh    [%o1+0x44], %o0
F004B18C: 808a2001                 btst    1, %o0
F004B190: 0280000d                 be      loc_F004B1C4
F004B194: d2068000                 ld      [%i2], %o1
F004B198: d0126044                 lduh    [%o1+0x44], %o0
F004B19C: 90122010                 bset    0x10, %o0
F004B1A0: d0326044                 sth     %o0, [%o1+0x44]
F004B1A4: d0068000                 ld      [%i2], %o0! unsigned int
F004B1A8: 7fff1d34                 call    _sleep
F004B1AC: 9210200a                 mov     0xA, %o1
F004B1B0: d0068000                 ld      [%i2], %o0
F004B1B4: d0122044                 lduh    [%o0+0x44], %o0
F004B1B8: 808a2001                 btst    1, %o0
F004B1BC: 12bffff7                 bne     loc_F004B198
F004B1C0: d2068000                 ld      [%i2], %o1
F004B1C4: d0126044                 lduh    [%o1+0x44], %o0
F004B1C8: b0102000                 mov     0, %i0
F004B1CC: 90122001                 bset    1, %o0
F004B1D0: 108000cf                 ba      locret_F004B50C
F004B1D4: d0326044                 sth     %o0, [%o1+0x44]
F004B1D8: d0362044                 sth     %o0, [%i0+0x44]
F004B1DC: 90100018                 mov     %i0, %o0! unsigned int
F004B1E0: 7fff1d26                 call    _sleep
F004B1E4: 9210200a                 mov     0xA, %o1
F004B1E8: d0162044                 lduh    [%i0+0x44], %o0
F004B1EC: 808a2001                 btst    1, %o0
F004B1F0: 12bffffa                 bne     loc_F004B1D8
F004B1F4: 90122010                 bset    0x10, %o0
F004B1F8: d0162044                 lduh    [%i0+0x44], %o0
F004B1FC: d406204c                 ld      [%i0+0x4C], %o2
F004B200: d2062070                 ld      [%i0+0x70], %o1
F004B204: 90122001                 bset    1, %o0
F004B208: 80a28009                 cmp     %o2, %o1
F004B20C: 08800003                 bleu    loc_F004B218
F004B210: d0362044                 sth     %o0, [%i0+0x44]
F004B214: c026204c                 clr     [%i0+0x4C]
F004B218: d206204c                 ld      [%i0+0x4C], %o1
F004B21C: 80a26000                 cmp     %o1, 0
F004B220: 32800005                 bne,a   loc_F004B234
F004B224: d0062050                 ld      [%i0+0x50], %o0
F004B228: a2102000                 mov     0, %l1
F004B22C: 1080000d                 ba      loc_F004B260
F004B230: aa102001                 mov     1, %l5
F004B234: d0022048                 ld      [%o0+0x48], %o0
F004B238: a2100009                 mov     %o1, %l1
F004B23C: a4ac4008                 andncc  %l1, %o0, %l2
F004B240: 02800007                 be      loc_F004B25C
F004B244: 90100018                 mov     %i0, %o0
F004B248: 40000668                 call    _blkatoff
F004B24C: 94102000                 mov     0, %o2
F004B250: a6920000                 orcc    %o0, %g0, %l3
F004B254: 02800095                 be      loc_F004B4A8
F004B258: 113c04cf                 sethi   -0xFECC400, %o0
F004B25C: aa102002                 mov     2, %l5
F004B260: d0062070                 ld      [%i0+0x70], %o0
F004B264: 900223ff                 inc     0x3FF, %o0
F004B268: a80a3c00                 and     %o0, -0x400, %l4
F004B26C: 80a44014                 cmp     %l1, %l4
F004B270: 1a800087                 bcc     loc_F004B48C
F004B274: 80a56002                 cmp     %l5, 2
F004B278: 1100003fae1223fe         set     0xFFFE, %l7
F004B280: 1100003fb61223ef         set     0xFFEF, %i3
F004B288: d0062050                 ld      [%i0+0x50], %o0
F004B28C: d0022048                 ld      [%o0+0x48], %o0
F004B290: 80ac4008                 andncc  %l1, %o0, %g0
F004B294: 3280000f                 bne,a   loc_F004B2D0
F004B298: d004e020                 ld      [%l3+0x20], %o0
F004B29C: 80a4e000                 cmp     %l3, 0
F004B2A0: 02800005                 be      loc_F004B2B4
F004B2A4: 90100018                 mov     %i0, %o0
F004B2A8: 7fff6570                 call    _brelse
F004B2AC: 90100013                 mov     %l3, %o0
F004B2B0: 90100018                 mov     %i0, %o0
F004B2B4: 92100011                 mov     %l1, %o1
F004B2B8: 4000064c                 call    _blkatoff
F004B2BC: 94102000                 mov     0, %o2
F004B2C0: a6920000                 orcc    %o0, %g0, %l3
F004B2C4: 02800078                 be      loc_F004B4A4
F004B2C8: a4102000                 mov     0, %l2
F004B2CC: d004e020                 ld      [%l3+0x20], %o0
F004B2D0: a0020012                 add     %o0, %l2, %l0
F004B2D4: d0142004                 lduh    [%l0+4], %o0
F004B2D8: 80a22000                 cmp     %o0, 0
F004B2DC: 0280000e                 be      loc_F004B314
F004B2E0: 920ca3ff                 and     %l2, 0x3FF, %o1
F004B2E4: 113c043a                 sethi   %hi(_dirchk), %o0
F004B2E8: d0022208                 ld      [%o0+%lo(_dirchk)], %o0
F004B2EC: 80a22000                 cmp     %o0, 0
F004B2F0: 0280000c                 be      loc_F004B320
F004B2F4: 90100018                 mov     %i0, %o0
F004B2F8: 92100010                 mov     %l0, %o1
F004B2FC: 94100012                 mov     %l2, %o2! size_t
F004B300: 4000067e                 call    sub_F004CCF8
F004B304: 96100011                 mov     %l1, %o3
F004B308: 80a22000                 cmp     %o0, 0
F004B30C: 02800005                 be      loc_F004B320
F004B310: 920ca3ff                 and     %l2, 0x3FF, %o1
F004B314: 90102400                 mov     0x400, %o0
F004B318: 10800058                 ba      loc_F004B478
F004B31C: 90220009                 sub     %o0, %o1, %o0
F004B320: d0040000                 ld      [%l0], %o0
F004B324: 80a22000                 cmp     %o0, 0
F004B328: 22800054                 be,a    loc_F004B478
F004B32C: d0142004                 lduh    [%l0+4], %o0
F004B330: d0142006                 lduh    [%l0+6], %o0
F004B334: 80a20016                 cmp     %o0, %l6
F004B338: 32800050                 bne,a   loc_F004B478
F004B33C: d0142004                 lduh    [%l0+4], %o0
F004B340: d24e4000                 ldsb    [%i1], %o1
F004B344: d04c2008                 ldsb    [%l0+8], %o0
F004B348: 80a24008                 cmp     %o1, %o0
F004B34C: 3280004b                 bne,a   loc_F004B478
F004B350: d0142004                 lduh    [%l0+4], %o0
F004B354: 90100019                 mov     %i1, %o0! void *
F004B358: 92042008                 add     %l0, 8, %o1! void *
F004B35C: 7ffeeb00                 call    _bcmp
F004B360: 94100016                 mov     %l6, %o2
F004B364: 80a22000                 cmp     %o0, 0
F004B368: 32800044                 bne,a   loc_F004B478
F004B36C: d0142004                 lduh    [%l0+4], %o0
F004B370: 90100013                 mov     %l3, %o0
F004B374: e0040000                 ld      [%l0], %l0
F004B378: 7fff653c                 call    _brelse
F004B37C: a6102000                 mov     0, %l3
F004B380: 80a5a002                 cmp     %l6, 2
F004B384: 1280001c                 bne     loc_F004B3F4
F004B388: e226204c                 st      %l1, [%i0+0x4C]
F004B38C: d04e4000                 ldsb    [%i1], %o0
F004B390: 80a2202e                 cmp     %o0, 0x2E ! '.'
F004B394: 32800019                 bne,a   loc_F004B3F8
F004B398: d0062048                 ld      [%i0+0x48], %o0
F004B39C: d04e6001                 ldsb    [%i1+1], %o0
F004B3A0: 80a2202e                 cmp     %o0, 0x2E ! '.'
F004B3A4: 32800015                 bne,a   loc_F004B3F8
F004B3A8: d0062048                 ld      [%i0+0x48], %o0
F004B3AC: d0162044                 lduh    [%i0+0x44], %o0
F004B3B0: 900a0017                 and     %o0, %l7, %o0
F004B3B4: 808a2010                 btst    0x10, %o0
F004B3B8: 02800006                 be      loc_F004B3D0
F004B3BC: d0362044                 sth     %o0, [%i0+0x44]
F004B3C0: 900a001b                 and     %o0, %i3, %o0
F004B3C4: d0362044                 sth     %o0, [%i0+0x44]
F004B3C8: 7fff1e88                 call    _wakeup
F004B3CC: 90100018                 mov     %i0, %o0
F004B3D0: d0562046                 ldsh    [%i0+0x46], %o0
F004B3D4: d2062050                 ld      [%i0+0x50], %o1
F004B3D8: 40000a40                 call    _iget
F004B3DC: 94100010                 mov     %l0, %o2
F004B3E0: a0920000                 orcc    %o0, %g0, %l0
F004B3E4: 3280001e                 bne,a   loc_F004B45C
F004B3E8: e0268000                 st      %l0, [%i2]
F004B3EC: 10800032                 ba      loc_F004B4B4
F004B3F0: 113c04cf                 sethi   -0xFECC400, %o0
F004B3F4: d0062048                 ld      [%i0+0x48], %o0
F004B3F8: 80a20010                 cmp     %o0, %l0
F004B3FC: 32800007                 bne,a   loc_F004B418
F004B400: d0562046                 ldsh    [%i0+0x46], %o0
F004B404: d0162012                 lduh    [%i0+0x12], %o0
F004B408: a0100018                 mov     %i0, %l0
F004B40C: 90022001                 inc     %o0
F004B410: 10800012                 ba      loc_F004B458
F004B414: d0362012                 sth     %o0, [%i0+0x12]
F004B418: d2062050                 ld      [%i0+0x50], %o1
F004B41C: 40000a2f                 call    _iget
F004B420: 94100010                 mov     %l0, %o2
F004B424: d2162044                 lduh    [%i0+0x44], %o1
F004B428: a0100008                 mov     %o0, %l0
F004B42C: 900a4017                 and     %o1, %l7, %o0
F004B430: 808a2010                 btst    0x10, %o0
F004B434: 02800006                 be      loc_F004B44C
F004B438: d0362044                 sth     %o0, [%i0+0x44]
F004B43C: 900a001b                 and     %o0, %i3, %o0
F004B440: d0362044                 sth     %o0, [%i0+0x44]
F004B444: 7fff1e69                 call    _wakeup
F004B448: 90100018                 mov     %i0, %o0
F004B44C: 80a42000                 cmp     %l0, 0
F004B450: 02800019                 be      loc_F004B4B4
F004B454: 113c04cf                 sethi   -0xFECC400, %o0
F004B458: e0268000                 st      %l0, [%i2]
F004B45C: 9006200c                 add     %i0, 0xC, %o0
F004B460: 92100019                 mov     %i1, %o1
F004B464: 9404200c                 add     %l0, 0xC, %o2
F004B468: 7fff68bd                 call    _dnlc_enter
F004B46C: 96102000                 mov     0, %o3
F004B470: 10800027                 ba      locret_F004B50C
F004B474: b0102000                 mov     0, %i0
F004B478: a2044008                 add     %l1, %o0, %l1
F004B47C: 80a44014                 cmp     %l1, %l4
F004B480: 0abfff82                 bcs     loc_F004B288
F004B484: a4048008                 add     %l2, %o0, %l2
F004B488: 80a56002                 cmp     %l5, 2
F004B48C: 1280000d                 bne     loc_F004B4C0
F004B490: a0102002                 mov     2, %l0
F004B494: aa102001                 mov     1, %l5
F004B498: e806204c                 ld      [%i0+0x4C], %l4
F004B49C: 10bfff74                 ba      loc_F004B26C
F004B4A0: a2102000                 mov     0, %l1
F004B4A4: 113c04cf                 sethi   -0xFECC400, %o0
F004B4A8: d00221dc                 ld      [%o0+0x1DC], %o0
F004B4AC: 10800005                 ba      loc_F004B4C0
F004B4B0: e04a2038                 ldsb    [%o0+0x38], %l0
F004B4B4: d00221dc                 ld      [%o0+0x1DC], %o0
F004B4B8: 1080000f                 ba      loc_F004B4F4
F004B4BC: e04a2038                 ldsb    [%o0+0x38], %l0
F004B4C0: d2162044                 lduh    [%i0+0x44], %o1
F004B4C4: 1100003f901223fe         set     0xFFFE, %o0
F004B4CC: 920a4008                 and     %o1, %o0, %o1
F004B4D0: 808a6010                 btst    0x10, %o1
F004B4D4: 02800008                 be      loc_F004B4F4
F004B4D8: d2362044                 sth     %o1, [%i0+0x44]
F004B4DC: 1100003f901223ef         set     0xFFEF, %o0
F004B4E4: 900a4008                 and     %o1, %o0, %o0
F004B4E8: d0362044                 sth     %o0, [%i0+0x44]
F004B4EC: 7fff1e3f                 call    _wakeup
F004B4F0: 90100018                 mov     %i0, %o0
F004B4F4: 80a4e000                 cmp     %l3, 0
F004B4F8: 02800005                 be      locret_F004B50C
F004B4FC: b0100010                 mov     %l0, %i0
F004B500: 7fff64da                 call    _brelse
F004B504: 90100013                 mov     %l3, %o0
F004B508: b0100010                 mov     %l0, %i0
F004B50C: 81c7e008                 ret
F004B510: 81e80000                 restore
