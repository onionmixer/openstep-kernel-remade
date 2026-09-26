F00C1548: 9de3bf98                 save    %sp, -0x68, %sp
F00C154C: f027a044                 st      %i0, [%fp+arg_44]
F00C1550: 7ffffe69                 call    sub_F00C0EF4
F00C1554: 9007a044                 add     %fp, arg_44, %o0
F00C1558: 92920000                 orcc    %o0, %g0, %o1
F00C155C: 02800007                 be      locret_F00C1578
F00C1560: 01000000                 nop
F00C1564: d00a6003                 ldub    [%o1+3], %o0
F00C1568: 80a2207f                 cmp     %o0, 0x7F
F00C156C: 02800003                 be      locret_F00C1578
F00C1570: 9010207f                 mov     0x7F, %o0
F00C1574: d02a6003                 stb     %o0, [%o1+3]
F00C1578: 81c7e008                 ret
F00C157C: 81e80000                 restore
