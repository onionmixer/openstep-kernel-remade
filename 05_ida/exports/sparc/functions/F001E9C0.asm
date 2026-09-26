F001E9C0: 9de3bf98                 save    %sp, -0x68, %sp
F001E9C4: 4001e0b4                 call    _splnet
F001E9C8: 01000000                 nop
F001E9CC: d2162006                 lduh    [%i0+6], %o1
F001E9D0: 808a6001                 btst    1, %o1
F001E9D4: 12800005                 bne     loc_F001E9E8
F001E9D8: a0100008                 mov     %o0, %l0
F001E9DC: 113c042f                 sethi   %hi(aSoacceptNofdre), %o0! "soaccept: !NOFDREF"
F001E9E0: 7fffd9e4                 call    _panic
F001E9E4: 90122008                 bset    %lo(aSoacceptNofdre), %o0! "soaccept: !NOFDREF"
F001E9E8: 90100018                 mov     %i0, %o0
F001E9EC: 94102000                 mov     0, %o2
F001E9F0: d2162006                 lduh    [%i0+6], %o1
F001E9F4: 96100019                 mov     %i1, %o3
F001E9F8: d802200c                 ld      [%o0+0xC], %o4
F001E9FC: 920a7ffe                 and     %o1, -2, %o1
F001EA00: d2322006                 sth     %o1, [%o0+6]
F001EA04: da03201c                 ld      [%o4+0x1C], %o5
F001EA08: 92102005                 mov     5, %o1
F001EA0C: 9fc34000                 call    %o5
F001EA10: 98102000                 mov     0, %o4
F001EA14: b0100008                 mov     %o0, %i0
F001EA18: 4001e0c3                 call    _splx
F001EA1C: 90100010                 mov     %l0, %o0
F001EA20: 81c7e008                 ret
F001EA24: 81e80000                 restore
