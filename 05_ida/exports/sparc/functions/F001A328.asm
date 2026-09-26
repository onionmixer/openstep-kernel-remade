F001A328: 9de3bf90                 save    %sp, -0x70, %sp
F001A32C: e2060000                 ld      [%i0], %l1
F001A330: d00c6057                 ldub    [%l1+0x57], %o0
F001A334: 80a220ff                 cmp     %o0, 0xFF
F001A338: 22800005                 be,a    loc_F001A34C
F001A33C: 9010200a                 mov     0xA, %o0
F001A340: 4000002d                 call    _ttyecho
F001A344: 92100018                 mov     %i0, %o1
F001A348: 9010200a                 mov     0xA, %o0
F001A34C: 7ffffb11                 call    _ttyoutput
F001A350: 92100011                 mov     %l1, %o1
F001A354: 4001f219                 call    _spltty
F001A358: 01000000                 nop
F001A35C: d2046010                 ld      [%l1+0x10], %o1
F001A360: a4100008                 mov     %o0, %l2
F001A364: a0027fff                 add     %o1, -1, %l0
F001A368: 9004600c                 add     %l1, 0xC, %o0
F001A36C: 92100010                 mov     %l0, %o1
F001A370: 40000aa6                 call    _nextc3
F001A374: 9407bff4                 add     %fp, var_C, %o2
F001A378: a0920000                 orcc    %o0, %g0, %l0
F001A37C: 02800006                 be      loc_F001A394
F001A380: d007bff4                 ld      [%fp+var_C], %o0
F001A384: 4000001c                 call    _ttyecho
F001A388: 92100018                 mov     %i0, %o1
F001A38C: 10bffff8                 ba      loc_F001A36C
F001A390: 9004600c                 add     %l1, 0xC, %o0
F001A394: d0046004                 ld      [%l1+4], %o0
F001A398: a0023fff                 add     %o0, -1, %l0
F001A39C: 90100011                 mov     %l1, %o0
F001A3A0: 92100010                 mov     %l0, %o1
F001A3A4: 40000a99                 call    _nextc3
F001A3A8: 9407bff4                 add     %fp, var_C, %o2
F001A3AC: a0920000                 orcc    %o0, %g0, %l0
F001A3B0: 02800006                 be      loc_F001A3C8
F001A3B4: d007bff4                 ld      [%fp+var_C], %o0
F001A3B8: 4000000f                 call    _ttyecho
F001A3BC: 92100018                 mov     %i0, %o1
F001A3C0: 10bffff8                 ba      loc_F001A3A0
F001A3C4: 90100011                 mov     %l1, %o0
F001A3C8: 90100012                 mov     %l2, %o0
F001A3CC: d2046040                 ld      [%l1+0x40], %o1
F001A3D0: 15000100                 sethi   0x40000, %o2
F001A3D4: 942a400a                 andn    %o1, %o2, %o2
F001A3D8: 4001f253                 call    _splx
F001A3DC: d4246040                 st      %o2, [%l1+0x40]
F001A3E0: d0044000                 ld      [%l1], %o0
F001A3E4: c02c604c                 clrb    [%l1+0x4C]
F001A3E8: d02c604b                 stb     %o0, [%l1+0x4B]
F001A3EC: 81c7e008                 ret
F001A3F0: 81e80000                 restore
