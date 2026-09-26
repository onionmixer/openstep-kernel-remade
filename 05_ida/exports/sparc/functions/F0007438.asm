F0007438: 92100008                 mov     %o0, %o1
F000743C: 968a6003                 andcc   %o1, 3, %o3
F0007440: 0280001a                 be      loc_F00074A8
F0007444: 90100000                 clr     %o0
F0007448: 80a2e002                 cmp     %o3, 2
F000744C: 02800009                 be      loc_F0007470
F0007450: 80a2e003                 cmp     %o3, 3
F0007454: d60a4000                 ldub    [%o1], %o3
F0007458: 92026001                 inc     %o1
F000745C: 02800010                 be      loc_F000749C
F0007460: 8092c000                 tst     %o3
F0007464: 32800003                 bne,a   loc_F0007470
F0007468: 90022001                 inc     %o0
F000746C: 3080001f                 ba,a    locret_F00074E8
F0007470: d6124000                 lduh    [%o1], %o3
F0007474: 92026002                 inc     2, %o1
F0007478: 9932e008                 srl     %o3, 8, %o4
F000747C: 80930000                 tst     %o4
F0007480: 32800003                 bne,a   loc_F000748C
F0007484: 90022001                 inc     %o0
F0007488: 30800018                 ba,a    locret_F00074E8
F000748C: 968ae0ff                 andcc   %o3, 0xFF, %o3
F0007490: 32800006                 bne,a   loc_F00074A8
F0007494: 90022001                 inc     %o0
F0007498: 30800014                 ba,a    locret_F00074E8
F000749C: 32800003                 bne,a   loc_F00074A8
F00074A0: 90022001                 inc     %o0
F00074A4: 30800011                 ba,a    locret_F00074E8
F00074A8: 171fbfbf9612e2ff         set     0x7EFEFEFF, %o3
F00074B0: 1920404098132100         set     -0x7EFEFF00, %o4
F00074B8: d4024000                 ld      [%o1], %o2
F00074BC: 92026004                 inc     4, %o1
F00074C0: 9a02800b                 add     %o2, %o3, %o5
F00074C4: 9a1b400a                 btog    %o2, %o5
F00074C8: 9a0b400c                 and     %o5, %o4, %o5
F00074CC: 80a3400c                 cmp     %o5, %o4
F00074D0: 22bffffa                 be,a    loc_F00074B8
F00074D4: 90022004                 inc     4, %o0
F00074D8: 1b3fc000                 sethi   -0x1000000, %o5
F00074DC: 808a800d                 btst    %o5, %o2
F00074E0: 12800004                 bne     loc_F00074F0
F00074E4: 9b336008                 srl     %o5, 8, %o5
F00074E8: 81c3e008                 retl
F00074EC: 01000000                 nop
F00074F0: 808a800d                 btst    %o5, %o2
F00074F4: 12800004                 bne     loc_F0007504
F00074F8: 9b336008                 srl     %o5, 8, %o5
F00074FC: 81c3e008                 retl
F0007500: 90022001                 inc     %o0
F0007504: 808a800d                 btst    %o5, %o2
F0007508: 12800004                 bne     loc_F0007518
F000750C: 808aa0ff                 btst    0xFF, %o2
F0007510: 81c3e008                 retl
F0007514: 90022002                 inc     2, %o0
F0007518: 32bfffe8                 bne,a   loc_F00074B8
F000751C: 90022004                 inc     4, %o0
F0007520: 81c3e008                 retl
F0007524: 90022003                 inc     3, %o0
