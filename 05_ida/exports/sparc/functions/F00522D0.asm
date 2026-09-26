F00522D0: 9de3bf90                 save    %sp, -0x70, %sp
F00522D4: 92100019                 mov     %i1, %o1
F00522D8: e0062030                 ld      [%i0+0x30], %l0
F00522DC: 9407bff4                 add     %fp, var_C, %o2
F00522E0: 7fffe38a                 call    _dirlook
F00522E4: 90100010                 mov     %l0, %o0
F00522E8: d2142044                 lduh    [%l0+0x44], %o1
F00522EC: 808a6046                 btst    0x46, %o1 ! 'F'
F00522F0: 0280001d                 be      loc_F0052364
F00522F4: b0100008                 mov     %o0, %i0
F00522F8: 90126008                 or      %o1, 8, %o0
F00522FC: d0342044                 sth     %o0, [%l0+0x44]
F0052300: 333c04d4                 sethi   %hi(_iuniqtime), %i1
F0052304: 400070b3                 call    _microtime
F0052308: 90166148                 or      %i1, %lo(_iuniqtime), %o0
F005230C: d0142044                 lduh    [%l0+0x44], %o0
F0052310: 808a2004                 btst    4, %o0
F0052314: 02800003                 be      loc_F0052320
F0052318: d0066148                 ld      [%i1+%lo(_iuniqtime)], %o0
F005231C: d0242074                 st      %o0, [%l0+0x74]
F0052320: d0142044                 lduh    [%l0+0x44], %o0
F0052324: 808a2002                 btst    2, %o0
F0052328: 02800003                 be      loc_F0052334
F005232C: d0066148                 ld      [%i1+0x148], %o0
F0052330: d024207c                 st      %o0, [%l0+0x7C]
F0052334: d0142044                 lduh    [%l0+0x44], %o0
F0052338: 808a2040                 btst    0x40, %o0 ! '@'
F005233C: 22800006                 be,a    loc_F0052354
F0052340: d2142044                 lduh    [%l0+0x44], %o1
F0052344: c024204c                 clr     [%l0+0x4C]
F0052348: d0066148                 ld      [%i1+0x148], %o0
F005234C: d0242084                 st      %o0, [%l0+0x84]
F0052350: d2142044                 lduh    [%l0+0x44], %o1
F0052354: 1100003f901223b9         set     0xFFB9, %o0
F005235C: 920a4008                 and     %o1, %o0, %o1
F0052360: d2342044                 sth     %o1, [%l0+0x44]
F0052364: 80a62000                 cmp     %i0, 0
F0052368: 12800043                 bne     locret_F0052474
F005236C: e007bff4                 ld      [%fp+var_C], %l0
F0052370: 9004200c                 add     %l0, 0xC, %o0
F0052374: d0268000                 st      %o0, [%i2]
F0052378: d0042064                 ld      [%l0+0x64], %o0
F005237C: 13109000                 sethi   0x42400000, %o1
F0052380: 900a0009                 and     %o0, %o1, %o0
F0052384: 13008000                 sethi   0x2000000, %o1
F0052388: 80a20009                 cmp     %o0, %o1
F005238C: 3280000b                 bne,a   loc_F00523B8
F0052390: d0142044                 lduh    [%l0+0x44], %o0
F0052394: 113c043c                 sethi   %hi(_stickyhack), %o0
F0052398: d00221ec                 ld      [%o0+%lo(_stickyhack)], %o0
F005239C: 80a22000                 cmp     %o0, 0
F00523A0: 22800006                 be,a    loc_F00523B8
F00523A4: d0142044                 lduh    [%l0+0x44], %o0
F00523A8: d0142010                 lduh    [%l0+0x10], %o0
F00523AC: 90122080                 bset    0x80, %o0
F00523B0: d0342010                 sth     %o0, [%l0+0x10]
F00523B4: d0142044                 lduh    [%l0+0x44], %o0
F00523B8: 808a2046                 btst    0x46, %o0 ! 'F'
F00523BC: 0280001c                 be      loc_F005242C
F00523C0: 90122008                 bset    8, %o0
F00523C4: d0342044                 sth     %o0, [%l0+0x44]
F00523C8: 333c04d4                 sethi   %hi(_iuniqtime), %i1
F00523CC: 40007081                 call    _microtime
F00523D0: 90166148                 or      %i1, %lo(_iuniqtime), %o0
F00523D4: d0142044                 lduh    [%l0+0x44], %o0
F00523D8: 808a2004                 btst    4, %o0
F00523DC: 02800003                 be      loc_F00523E8
F00523E0: d0066148                 ld      [%i1+%lo(_iuniqtime)], %o0
F00523E4: d0242074                 st      %o0, [%l0+0x74]
F00523E8: d0142044                 lduh    [%l0+0x44], %o0
F00523EC: 808a2002                 btst    2, %o0
F00523F0: 02800003                 be      loc_F00523FC
F00523F4: d0066148                 ld      [%i1+0x148], %o0
F00523F8: d024207c                 st      %o0, [%l0+0x7C]
F00523FC: d0142044                 lduh    [%l0+0x44], %o0
F0052400: 808a2040                 btst    0x40, %o0 ! '@'
F0052404: 22800006                 be,a    loc_F005241C
F0052408: d2142044                 lduh    [%l0+0x44], %o1
F005240C: c024204c                 clr     [%l0+0x4C]
F0052410: d0066148                 ld      [%i1+0x148], %o0
F0052414: d0242084                 st      %o0, [%l0+0x84]
F0052418: d2142044                 lduh    [%l0+0x44], %o1
F005241C: 1100003f901223b9         set     0xFFB9, %o0
F0052424: 920a4008                 and     %o1, %o0, %o1
F0052428: d2342044                 sth     %o1, [%l0+0x44]
F005242C: 7ffff327                 call    _iunlock
F0052430: 90100010                 mov     %l0, %o0
F0052434: d2068000                 ld      [%i2], %o1
F0052438: d4026028                 ld      [%o1+0x28], %o2
F005243C: 9002bffd                 add     %o2, -3, %o0
F0052440: 80a22001                 cmp     %o0, 1
F0052444: 08800006                 bleu    loc_F005245C
F0052448: 90100009                 mov     %o1, %o0
F005244C: 9002bff8                 add     %o2, -8, %o0
F0052450: 80a22001                 cmp     %o0, 1
F0052454: 18800008                 bgu     locret_F0052474
F0052458: 90100009                 mov     %o1, %o0
F005245C: 7fffd3cf                 call    _specvp
F0052460: d252202c                 ldsh    [%o0+0x2C], %o1
F0052464: a0100008                 mov     %o0, %l0
F0052468: 7fff59bf                 call    _vn_rele
F005246C: d0068000                 ld      [%i2], %o0
F0052470: e0268000                 st      %l0, [%i2]
F0052474: 81c7e008                 ret
F0052478: 81e80000                 restore
