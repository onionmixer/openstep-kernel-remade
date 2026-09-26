F001E408: 9de3bf98                 save    %sp, -0x68, %sp
F001E40C: d056200c                 ldsh    [%i0+0xC], %o0
F001E410: 80a22001                 cmp     %o0, 1
F001E414: 02800006                 be      loc_F001E42C
F001E418: 80a22002                 cmp     %o0, 2
F001E41C: 2280001d                 be,a    loc_F001E490
F001E420: d2062010                 ld      [%i0+0x10], %o1
F001E424: 1080001e                 ba      loc_F001E49C
F001E428: 113c042e                 sethi   -0xFEF4800, %o0
F001E42C: d0062004                 ld      [%i0+4], %o0
F001E430: 133c04d2                 sethi   %hi(_mbutl), %o1
F001E434: d4026350                 ld      [%o1+%lo(_mbutl)], %o2
F001E438: 90060008                 add     %i0, %o0, %o0
F001E43C: b00a3c00                 and     %o0, -0x400, %i0
F001E440: 9426000a                 sub     %i0, %o2, %o2
F001E444: 133c04d2                 sethi   %hi(_mclrefcnt), %o1
F001E448: 953aa00a                 sra     %o2, 10, %o2
F001E44C: 92126360                 bset    %lo(_mclrefcnt), %o1
F001E450: d00a8009                 ldub    [%o2+%o1], %o0
F001E454: 90023fff                 inc     -1, %o0
F001E458: d02a8009                 stb     %o0, [%o2+%o1]
F001E45C: 912a2018                 sll     %o0, 24, %o0
F001E460: 80a22000                 cmp     %o0, 0
F001E464: 12800010                 bne     locret_F001E4A4
F001E468: 153c04d2                 sethi   %hi(_mclfree), %o2
F001E46C: 133c04d2                 sethi   %hi(_mbstat), %o1
F001E470: d002a358                 ld      [%o2+%lo(_mclfree)], %o0
F001E474: 921262f0                 bset    %lo(_mbstat), %o1
F001E478: d0260000                 st      %o0, [%i0]
F001E47C: d002600c                 ld      [%o1+0xC], %o0
F001E480: f022a358                 st      %i0, [%o2+%lo(_mclfree)]
F001E484: 90022001                 inc     %o0
F001E488: 10800007                 ba      locret_F001E4A4
F001E48C: d022600c                 st      %o0, [%o1+0xC]
F001E490: 9fc24000                 call    %o1
F001E494: d0062014                 ld      [%i0+0x14], %o0! char *
F001E498: 30800003                 ba,a    locret_F001E4A4
F001E49C: 7fffdb35                 call    _panic
F001E4A0: 90122318                 bset    0x318, %o0
F001E4A4: 81c7e008                 ret
F001E4A8: 81e80000                 restore
