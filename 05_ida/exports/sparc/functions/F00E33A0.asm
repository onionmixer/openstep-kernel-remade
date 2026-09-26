F00E33A0: 9de3bf98                 save    %sp, -0x68, %sp
F00E33A4: d4062004                 ld      [%i0+4], %o2
F00E33A8: 11000004                 sethi   0x1000, %o0
F00E33AC: 9202bf90                 add     %o2, -0x70, %o1
F00E33B0: 80a24008                 cmp     %o1, %o0
F00E33B4: 18800005                 bgu     loc_F00E33C8
F00E33B8: d00e2003                 ldub    [%i0+3], %o0
F00E33BC: 80a22001                 cmp     %o0, 1
F00E33C0: 22800005                 be,a    loc_F00E33D4
F00E33C4: d0062018                 ld      [%i0+0x18], %o0
F00E33C8: 90103ed0                 mov     -0x130, %o0
F00E33CC: 1080002c                 ba      locret_F00E347C
F00E33D0: d026601c                 st      %o0, [%i1+0x1C]
F00E33D4: 133c03e6                 sethi   %hi(dword_F00F9A24), %o1
F00E33D8: d2026224                 ld      [%o1+%lo(dword_F00F9A24)], %o1
F00E33DC: 80a20009                 cmp     %o0, %o1
F00E33E0: 1280001f                 bne     loc_F00E345C
F00E33E4: 90103ed0                 mov     -0x130, %o0
F00E33E8: d0062020                 ld      [%i0+0x20], %o0
F00E33EC: 133c03e6                 sethi   %hi(dword_F00F9A28), %o1
F00E33F0: d2026228                 ld      [%o1+%lo(dword_F00F9A28)], %o1
F00E33F4: 80a20009                 cmp     %o0, %o1
F00E33F8: 12800019                 bne     loc_F00E345C
F00E33FC: 90103ed0                 mov     -0x130, %o0
F00E3400: d0062064                 ld      [%i0+0x64], %o0
F00E3404: 900a200c                 and     %o0, 0xC, %o0
F00E3408: 80a2200c                 cmp     %o0, 0xC
F00E340C: 12800014                 bne     loc_F00E345C
F00E3410: 90103ed0                 mov     -0x130, %o0
F00E3414: d2062068                 ld      [%i0+0x68], %o1
F00E3418: 1100020090122008         set     0x80008, %o0
F00E3420: 80a24008                 cmp     %o1, %o0
F00E3424: 1280000e                 bne     loc_F00E345C
F00E3428: 90103ed0                 mov     -0x130, %o0
F00E342C: d806206c                 ld      [%i0+0x6C], %o4
F00E3430: 90032003                 add     %o4, 3, %o0
F00E3434: 900a3ffc                 and     %o0, -4, %o0
F00E3438: 90022070                 inc     0x70, %o0 ! 'p'
F00E343C: 80a28008                 cmp     %o2, %o0
F00E3440: 12800007                 bne     loc_F00E345C
F00E3444: 90103ed0                 mov     -0x130, %o0
F00E3448: d006200c                 ld      [%i0+0xC], %o0
F00E344C: 94062024                 add     %i0, 0x24, %o2 ! '$'
F00E3450: d206201c                 ld      [%i0+0x1C], %o1
F00E3454: 7fffc804                 call    _EvSetParameterChar
F00E3458: 96062070                 add     %i0, 0x70, %o3 ! 'p'
F00E345C: d026601c                 st      %o0, [%i1+0x1C]
F00E3460: d006601c                 ld      [%i1+0x1C], %o0
F00E3464: 80a22000                 cmp     %o0, 0
F00E3468: 12800005                 bne     locret_F00E347C
F00E346C: 94102020                 mov     0x20, %o2 ! ' '
F00E3470: 90102001                 mov     1, %o0
F00E3474: d02e6003                 stb     %o0, [%i1+3]
F00E3478: d4266004                 st      %o2, [%i1+4]
F00E347C: 81c7e008                 ret
F00E3480: 81e80000                 restore
