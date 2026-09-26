F00C13FC: 9de3bf98                 save    %sp, -0x68, %sp
F00C1400: f027a044                 st      %i0, [%fp+arg_44]
F00C1404: 7ffffebc                 call    sub_F00C0EF4
F00C1408: 9007a044                 add     %fp, arg_44, %o0
F00C140C: 92920000                 orcc    %o0, %g0, %o1
F00C1410: 02800010                 be      locret_F00C1450
F00C1414: 900e600f                 and     %i1, 0xF, %o0
F00C1418: d02a4000                 stb     %o0, [%o1]
F00C141C: 90102003                 mov     3, %o0
F00C1420: d02a6001                 stb     %o0, [%o1+1]
F00C1424: 808e6040                 btst    0x40, %i1 ! '@'
F00C1428: 02800004                 be      loc_F00C1438
F00C142C: c0226008                 clr     [%o1+8]
F00C1430: 90102001                 mov     1, %o0
F00C1434: d0226008                 st      %o0, [%o1+8]
F00C1438: 113c0476                 sethi   %hi(_keytables), %o0
F00C143C: d002223c                 ld      [%o0+%lo(_keytables)], %o0
F00C1440: c0226004                 clr     [%o1+4]
F00C1444: d022600c                 st      %o0, [%o1+0xC]
F00C1448: 9010207f                 mov     0x7F, %o0
F00C144C: d02a6003                 stb     %o0, [%o1+3]
F00C1450: 81c7e008                 ret
F00C1454: 81e80000                 restore
