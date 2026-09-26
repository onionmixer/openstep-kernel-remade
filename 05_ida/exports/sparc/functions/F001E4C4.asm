F001E4C4: 9de3bf98                 save    %sp, -0x68, %sp
F001E4C8: d056200c                 ldsh    [%i0+0xC], %o0
F001E4CC: 80a22001                 cmp     %o0, 1
F001E4D0: 02800006                 be      loc_F001E4E8
F001E4D4: 80a22002                 cmp     %o0, 2
F001E4D8: 22800014                 be,a    loc_F001E528
F001E4DC: d0566008                 ldsh    [%i1+8], %o0
F001E4E0: 1080002a                 ba      loc_F001E588
F001E4E4: 113c042e                 sethi   -0xFEF4800, %o0
F001E4E8: d2062004                 ld      [%i0+4], %o1
F001E4EC: 94102001                 mov     1, %o2
F001E4F0: 92060009                 add     %i0, %o1, %o1
F001E4F4: 90224019                 sub     %o1, %i1, %o0
F001E4F8: d0266004                 st      %o0, [%i1+4]
F001E4FC: 113c04d2                 sethi   %hi(_mbutl), %o0
F001E500: d436600c                 sth     %o2, [%i1+0xC]
F001E504: 153c04d2                 sethi   %hi(_mclrefcnt), %o2
F001E508: d0022350                 ld      [%o0+%lo(_mbutl)], %o0
F001E50C: 9412a360                 bset    %lo(_mclrefcnt), %o2
F001E510: 92224008                 sub     %o1, %o0, %o1
F001E514: 933a600a                 sra     %o1, 10, %o1
F001E518: d00a400a                 ldub    [%o1+%o2], %o0
F001E51C: 90022001                 inc     %o0
F001E520: 1080001c                 ba      locret_F001E590
F001E524: d02a400a                 stb     %o0, [%o1+%o2]
F001E528: 400126d2                 call    _kalloc
F001E52C: 90022004                 inc     4, %o0
F001E530: d2566008                 ldsh    [%i1+8], %o1
F001E534: a0100008                 mov     %o0, %l0
F001E538: 92026004                 inc     4, %o1
F001E53C: d2240000                 st      %o1, [%l0]
F001E540: d0062004                 ld      [%i0+4], %o0
F001E544: 92042004                 add     %l0, 4, %o1! void *
F001E548: d4566008                 ldsh    [%i1+8], %o2! size_t
F001E54C: 90060008                 add     %i0, %o0, %o0! void *
F001E550: 4001d970                 call    _bcopy
F001E554: 9002001a                 add     %o0, %i2, %o0
F001E558: 90067ffc                 add     %i1, -4, %o0
F001E55C: 90240008                 sub     %l0, %o0, %o0
F001E560: 9022001a                 sub     %o0, %i2, %o0
F001E564: d0266004                 st      %o0, [%i1+4]
F001E568: 90102002                 mov     2, %o0
F001E56C: d036600c                 sth     %o0, [%i1+0xC]
F001E570: 113c0079901220ac         set     sub_F001E4AC, %o0! char *
F001E578: d0266010                 st      %o0, [%i1+0x10]
F001E57C: e0266014                 st      %l0, [%i1+0x14]
F001E580: 10800004                 ba      locret_F001E590
F001E584: c0266018                 clr     [%i1+0x18]
F001E588: 7fffdafa                 call    _panic
F001E58C: 90122320                 bset    0x320, %o0
F001E590: 81c7e008                 ret
F001E594: 81e80000                 restore
