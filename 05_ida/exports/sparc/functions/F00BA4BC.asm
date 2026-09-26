F00BA4BC: 9de3bf98                 save    %sp, -0x68, %sp
F00BA4C0: 7fff71ab                 call    _splzs
F00BA4C4: e0062034                 ld      [%i0+0x34], %l0
F00BA4C8: a2100008                 mov     %o0, %l1
F00BA4CC: d20c2025                 ldub    [%l0+0x25], %o1
F00BA4D0: 90102002                 mov     2, %o0
F00BA4D4: d4042010                 ld      [%l0+0x10], %o2
F00BA4D8: b00a6082                 and     %o1, 0x82, %i0
F00BA4DC: 92102010                 mov     0x10, %o1
F00BA4E0: d22a8000                 stb     %o1, [%o2]
F00BA4E4: 7fff74df                 call    _us_spin
F00BA4E8: 01000000                 nop
F00BA4EC: d0042010                 ld      [%l0+0x10], %o0
F00BA4F0: d00a0000                 ldub    [%o0], %o0
F00BA4F4: 80a6a001                 cmp     %i2, 1
F00BA4F8: 900a2028                 and     %o0, 0x28, %o0
F00BA4FC: 0280000f                 be      loc_F00BA538
F00BA500: b0160008                 bset    %o0, %i0
F00BA504: 80a6a001                 cmp     %i2, 1
F00BA508: 14800007                 bg      loc_F00BA524
F00BA50C: 80a6a002                 cmp     %i2, 2
F00BA510: 80a6a000                 cmp     %i2, 0
F00BA514: 2280000c                 be,a    loc_F00BA544
F00BA518: b0100019                 mov     %i1, %i0
F00BA51C: 1080000b                 ba      loc_F00BA548
F00BA520: 900e3f82                 and     %i0, -0x7E, %o0
F00BA524: 02800007                 be      loc_F00BA540
F00BA528: 80a6a003                 cmp     %i2, 3
F00BA52C: 02800010                 be      loc_F00BA56C
F00BA530: 900e3f82                 and     %i0, -0x7E, %o0
F00BA534: 30800005                 ba,a    loc_F00BA548
F00BA538: 10800003                 ba      loc_F00BA544
F00BA53C: b0160019                 bset    %i1, %i0
F00BA540: b02e0019                 bclr    %i1, %i0
F00BA544: 900e3f82                 and     %i0, -0x7E, %o0
F00BA548: d40c2025                 ldub    [%l0+0x25], %o2
F00BA54C: 92102005                 mov     5, %o1
F00BA550: 940aa07d                 and     %o2, 0x7D, %o2
F00BA554: d42c2025                 stb     %o2, [%l0+0x25]
F00BA558: 94128008                 bset    %o0, %o2
F00BA55C: d42c2025                 stb     %o2, [%l0+0x25]
F00BA560: d0042010                 ld      [%l0+0x10], %o0
F00BA564: 40000400                 call    _zszwrite
F00BA568: 940aa0ff                 and     %o2, 0xFF, %o2
F00BA56C: 7fff71ee                 call    _splx
F00BA570: 90100011                 mov     %l1, %o0
F00BA574: 81c7e008                 ret
F00BA578: 81e80000                 restore
