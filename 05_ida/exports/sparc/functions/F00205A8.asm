F00205A8: 9de3bf98                 save    %sp, -0x68, %sp
F00205AC: 94964000                 orcc    %i1, %g0, %o2
F00205B0: 02800021                 be      locret_F0020634
F00205B4: 01000000                 nop
F00205B8: d606200c                 ld      [%i0+0xC], %o3
F00205BC: 80a2e000                 cmp     %o3, 0
F00205C0: 22800009                 be,a    loc_F00205E4
F00205C4: d2160000                 lduh    [%i0], %o1
F00205C8: 10800003                 ba      loc_F00205D4
F00205CC: d002e07c                 ld      [%o3+0x7C], %o0
F00205D0: d002e07c                 ld      [%o3+0x7C], %o0
F00205D4: 80a22000                 cmp     %o0, 0
F00205D8: 32bffffe                 bne,a   loc_F00205D0
F00205DC: d602e07c                 ld      [%o3+0x7C], %o3
F00205E0: d2160000                 lduh    [%i0], %o1
F00205E4: d012a008                 lduh    [%o2+8], %o0
F00205E8: 92024008                 add     %o1, %o0, %o1
F00205EC: d0162004                 lduh    [%i0+4], %o0
F00205F0: d2360000                 sth     %o1, [%i0]
F00205F4: 92022080                 add     %o0, 0x80, %o1
F00205F8: d2362004                 sth     %o1, [%i0+4]
F00205FC: d002a004                 ld      [%o2+4], %o0
F0020600: 80a2207c                 cmp     %o0, 0x7C ! '|'
F0020604: 08800003                 bleu    loc_F0020610
F0020608: 90026400                 add     %o1, 0x400, %o0
F002060C: d0362004                 sth     %o0, [%i0+4]
F0020610: 80a2e000                 cmp     %o3, 0
F0020614: 22800003                 be,a    loc_F0020620
F0020618: d426200c                 st      %o2, [%i0+0xC]
F002061C: d422e07c                 st      %o2, [%o3+0x7C]
F0020620: d6028000                 ld      [%o2], %o3
F0020624: 90100018                 mov     %i0, %o0
F0020628: c0228000                 clr     [%o2]
F002062C: 400000d9                 call    _sbcompress
F0020630: 9210000b                 mov     %o3, %o1
F0020634: 81c7e008                 ret
F0020638: 81e80000                 restore
