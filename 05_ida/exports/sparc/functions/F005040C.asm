F005040C: 9de3bf98                 save    %sp, -0x68, %sp
F0050410: 92100018                 mov     %i0, %o1
F0050414: 113c043c                 sethi   %hi(_mounttab), %o0
F0050418: f00220ac                 ld      [%o0+%lo(_mounttab)], %i0
F005041C: 80a62000                 cmp     %i0, 0
F0050420: 0280001c                 be      loc_F0050490
F0050424: 912a6010                 sll     %o1, 16, %o0
F0050428: 973a2010                 sra     %o0, 16, %o3
F005042C: 1100004698122154         set     0x11954, %o4
F0050434: 1b3c043b                 sethi   -0xFEF1400, %o5
F0050438: 213c043b                 sethi   -0xFEF1400, %l0
F005043C: d406200c                 ld      [%i0+0xC], %o2
F0050440: 80a2a000                 cmp     %o2, 0
F0050444: 22800010                 be,a    loc_F0050484
F0050448: f0062020                 ld      [%i0+0x20], %i0
F005044C: d2562004                 ldsh    [%i0+4], %o1
F0050450: 80a2400b                 cmp     %o1, %o3
F0050454: 3280000c                 bne,a   loc_F0050484
F0050458: f0062020                 ld      [%i0+0x20], %i0
F005045C: d402a020                 ld      [%o2+0x20], %o2
F0050460: d002a55c                 ld      [%o2+0x55C], %o0
F0050464: 80a2000c                 cmp     %o0, %o4
F0050468: 0280000b                 be      locret_F0050494
F005046C: 901361a0                 or      %o5, 0x1A0, %o0! char *
F0050470: 7fff107a                 call    _printf
F0050474: 9402a0d4                 inc     0xD4, %o2
F0050478: 7fff133e                 call    _panic
F005047C: 901421b8                 or      %l0, 0x1B8, %o0
F0050480: 30800005                 ba,a    locret_F0050494
F0050484: 80a62000                 cmp     %i0, 0
F0050488: 32bfffee                 bne,a   loc_F0050440
F005048C: d406200c                 ld      [%i0+0xC], %o2
F0050490: b0102000                 mov     0, %i0
F0050494: 81c7e008                 ret
F0050498: 81e80000                 restore
