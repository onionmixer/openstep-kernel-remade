F00152F0: 9de3bf98                 save    %sp, -0x68, %sp
F00152F4: 808e6002                 btst    2, %i1
F00152F8: 02800019                 be      loc_F001535C
F00152FC: 808e6004                 btst    4, %i1
F0015300: 4002062e                 call    _spltty
F0015304: 01000000                 nop
F0015308: 80a6a000                 cmp     %i2, 0
F001530C: 02800011                 be      loc_F0015350
F0015310: a0100008                 mov     %o0, %l0
F0015314: d006a040                 ld      [%i2+0x40], %o0
F0015318: 900a2014                 and     %o0, 0x14, %o0
F001531C: 80a22014                 cmp     %o0, 0x14
F0015320: 1280000c                 bne     loc_F0015350
F0015324: 80a6200a                 cmp     %i0, 0xA
F0015328: 32800006                 bne,a   loc_F0015340
F001532C: 90100018                 mov     %i0, %o0
F0015330: 9010200d                 mov     0xD, %o0
F0015334: 40000f17                 call    _ttyoutput
F0015338: 9210001a                 mov     %i2, %o1
F001533C: 90100018                 mov     %i0, %o0
F0015340: 40000f14                 call    _ttyoutput
F0015344: 9210001a                 mov     %i2, %o1
F0015348: 4000060c                 call    _ttstart
F001534C: 9010001a                 mov     %i2, %o0
F0015350: 40020675                 call    _splx
F0015354: 90100010                 mov     %l0, %o0
F0015358: 808e6004                 btst    4, %i1
F001535C: 02800028                 be      loc_F00153FC
F0015360: 80a62000                 cmp     %i0, 0
F0015364: 02800026                 be      loc_F00153FC
F0015368: 80a6200d                 cmp     %i0, 0xD
F001536C: 02800024                 be      loc_F00153FC
F0015370: 80a6207f                 cmp     %i0, 0x7F
F0015374: 02800022                 be      loc_F00153FC
F0015378: 173c042d                 sethi   %hi(_pmsgbuf), %o3
F001537C: d402e08c                 ld      [%o3+%lo(_pmsgbuf)], %o2
F0015380: 1100018c                 sethi   0x63000, %o0
F0015384: d2028000                 ld      [%o2], %o1
F0015388: 90122061                 bset    0x61, %o0 ! 'a'
F001538C: 80a24008                 cmp     %o1, %o0
F0015390: 0280000d                 be      loc_F00153C4
F0015394: 92102000                 mov     0, %o1
F0015398: d0228000                 st      %o0, [%o2]
F001539C: c022a008                 clr     [%o2+8]
F00153A0: c022a004                 clr     [%o2+4]
F00153A4: 9410000b                 mov     %o3, %o2
F00153A8: d002a08c                 ld      [%o2+0x8C], %o0
F00153AC: 90020009                 add     %o0, %o1, %o0
F00153B0: 92026001                 inc     %o1
F00153B4: 80a26ff3                 cmp     %o1, 0xFF3
F00153B8: 08bffffc                 bleu    loc_F00153A8
F00153BC: c02a200c                 clrb    [%o0+0xC]
F00153C0: 173c042d                 sethi   -0xFEF4C00, %o3
F00153C4: d002e08c                 ld      [%o3+0x8C], %o0
F00153C8: d4022004                 ld      [%o0+4], %o2
F00153CC: 9202a001                 add     %o2, 1, %o1
F00153D0: d2222004                 st      %o1, [%o0+4]
F00153D4: 9002000a                 add     %o0, %o2, %o0
F00153D8: f02a200c                 stb     %i0, [%o0+0xC]
F00153DC: d202e08c                 ld      [%o3+0x8C], %o1
F00153E0: d0026004                 ld      [%o1+4], %o0
F00153E4: 80a22000                 cmp     %o0, 0
F00153E8: 06800004                 bl      loc_F00153F8
F00153EC: 80a22ff3                 cmp     %o0, 0xFF3
F00153F0: 08800004                 bleu    loc_F0015400
F00153F4: 808e6001                 btst    1, %i1
F00153F8: c0226004                 clr     [%o1+4]
F00153FC: 808e6001                 btst    1, %i1
F0015400: 02800006                 be      loc_F0015418
F0015404: 80a62000                 cmp     %i0, 0
F0015408: 02800005                 be      loc_F001541C
F001540C: 808e6008                 btst    8, %i1
F0015410: 400271f8                 call    _cnputc
F0015414: 90100018                 mov     %i0, %o0
F0015418: 808e6008                 btst    8, %i1
F001541C: 02800007                 be      locret_F0015438
F0015420: 01000000                 nop
F0015424: d0068000                 ld      [%i2], %o0
F0015428: f02a0000                 stb     %i0, [%o0]
F001542C: d0068000                 ld      [%i2], %o0
F0015430: 90022001                 inc     %o0
F0015434: d0268000                 st      %o0, [%i2]
F0015438: 81c7e008                 ret
F001543C: 81e80000                 restore
