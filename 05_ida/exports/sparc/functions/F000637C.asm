F000637C: 9a100008                 mov     %o0, %o5
F0006380: 80a2a007                 cmp     %o2, 7
F0006384: 06800012                 bl      loc_F00063CC
F0006388: 808b6003                 btst    3, %o5
F000638C: 02800006                 be      loc_F00063A4
F0006390: 962aa003                 andn    %o2, 3, %o3
F0006394: 9422a001                 dec     %o2
F0006398: d22b4000                 stb     %o1, [%o5]
F000639C: 10bffffb                 ba      loc_F0006388
F00063A0: 9a036001                 inc     %o5
F00063A4: 920a60ff                 and     %o1, 0xFF, %o1
F00063A8: 992a6008                 sll     %o1, 8, %o4
F00063AC: 9212400c                 bset    %o4, %o1
F00063B0: 992a6010                 sll     %o1, 16, %o4
F00063B4: 9212400c                 bset    %o4, %o1
F00063B8: d2234000                 st      %o1, [%o5]
F00063BC: 96a2e004                 deccc   4, %o3
F00063C0: 12bffffe                 bne     loc_F00063B8
F00063C4: 9a036004                 inc     4, %o5
F00063C8: 940aa003                 and     %o2, 3, %o2
F00063CC: 94a2a001                 deccc   %o2
F00063D0: 9a036001                 inc     %o5
F00063D4: 36bffffe                 bge,a   loc_F00063CC
F00063D8: d22b7fff                 stb     %o1, [%o5-1]
F00063DC: 81c3e008                 retl
F00063E0: 01000000                 nop
