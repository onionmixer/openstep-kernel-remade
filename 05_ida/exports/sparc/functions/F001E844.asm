F001E844: 9de3bf98                 save    %sp, -0x68, %sp
F001E848: 4001e113                 call    _splnet
F001E84C: a0102000                 mov     0, %l0
F001E850: d2162002                 lduh    [%i0+2], %o1
F001E854: 808a6002                 btst    2, %o1
F001E858: 02800012                 be      loc_F001E8A0
F001E85C: a2100008                 mov     %o0, %l1
F001E860: 10800005                 ba      loc_F001E874
F001E864: d0062014                 ld      [%i0+0x14], %o0
F001E868: 4000004b                 call    _soabort
F001E86C: d0062014                 ld      [%i0+0x14], %o0
F001E870: d0062014                 ld      [%i0+0x14], %o0
F001E874: 80a20018                 cmp     %o0, %i0
F001E878: 12bffffc                 bne     loc_F001E868
F001E87C: 01000000                 nop
F001E880: 10800005                 ba      loc_F001E894
F001E884: d006201c                 ld      [%i0+0x1C], %o0
F001E888: 40000043                 call    _soabort
F001E88C: d006201c                 ld      [%i0+0x1C], %o0
F001E890: d006201c                 ld      [%i0+0x1C], %o0
F001E894: 80a20018                 cmp     %o0, %i0
F001E898: 12bffffc                 bne     loc_F001E888
F001E89C: 01000000                 nop
F001E8A0: d0062008                 ld      [%i0+8], %o0
F001E8A4: 80a22000                 cmp     %o0, 0
F001E8A8: 0280002c                 be      loc_F001E958
F001E8AC: d0162006                 lduh    [%i0+6], %o0
F001E8B0: 808a2002                 btst    2, %o0
F001E8B4: 0280001a                 be      loc_F001E91C
F001E8B8: 808a2008                 btst    8, %o0
F001E8BC: 32800008                 bne,a   loc_F001E8DC
F001E8C0: d0162002                 lduh    [%i0+2], %o0
F001E8C4: 40000090                 call    _sodisconnect
F001E8C8: 90100018                 mov     %i0, %o0
F001E8CC: a0920000                 orcc    %o0, %g0, %l0
F001E8D0: 32800014                 bne,a   loc_F001E920
F001E8D4: d0062008                 ld      [%i0+8], %o0
F001E8D8: d0162002                 lduh    [%i0+2], %o0
F001E8DC: 808a2080                 btst    0x80, %o0
F001E8E0: 22800010                 be,a    loc_F001E920
F001E8E4: d0062008                 ld      [%i0+8], %o0
F001E8E8: d0062004                 ld      [%i0+4], %o0
F001E8EC: 900a2108                 and     %o0, 0x108, %o0
F001E8F0: 80a22108                 cmp     %o0, 0x108
F001E8F4: 2280000b                 be,a    loc_F001E920
F001E8F8: d0062008                 ld      [%i0+8], %o0
F001E8FC: 10800005                 ba      loc_F001E910
F001E900: d0162006                 lduh    [%i0+6], %o0! unsigned int
F001E904: 7fffcf5d                 call    _sleep
F001E908: 9210201a                 mov     0x1A, %o1
F001E90C: d0162006                 lduh    [%i0+6], %o0
F001E910: 808a2002                 btst    2, %o0
F001E914: 12bffffc                 bne     loc_F001E904
F001E918: 90062054                 add     %i0, 0x54, %o0 ! 'T'
F001E91C: d0062008                 ld      [%i0+8], %o0
F001E920: 80a22000                 cmp     %o0, 0
F001E924: 0280000c                 be      loc_F001E954
F001E928: 90100018                 mov     %i0, %o0
F001E92C: 92102001                 mov     1, %o1
F001E930: d806200c                 ld      [%i0+0xC], %o4
F001E934: 94102000                 mov     0, %o2
F001E938: da03201c                 ld      [%o4+0x1C], %o5
F001E93C: 96102000                 mov     0, %o3
F001E940: 9fc34000                 call    %o5
F001E944: 98102000                 mov     0, %o4
F001E948: 80a42000                 cmp     %l0, 0
F001E94C: 22800002                 be,a    loc_F001E954
F001E950: a0100008                 mov     %o0, %l0
F001E954: d0162006                 lduh    [%i0+6], %o0
F001E958: 808a2001                 btst    1, %o0
F001E95C: 22800006                 be,a    loc_F001E974
F001E960: d2162006                 lduh    [%i0+6], %o1
F001E964: 113c042e                 sethi   %hi(aSocloseNofdref), %o0! "soclose: NOFDREF"
F001E968: 7fffda02                 call    _panic
F001E96C: 901223f0                 bset    %lo(aSocloseNofdref), %o0! "soclose: NOFDREF"
F001E970: d2162006                 lduh    [%i0+6], %o1
F001E974: 90100018                 mov     %i0, %o0
F001E978: 92126001                 bset    1, %o1
F001E97C: 7fffff8e                 call    _sofree
F001E980: d2322006                 sth     %o1, [%o0+6]
F001E984: 4001e0e8                 call    _splx
F001E988: 90100011                 mov     %l1, %o0
F001E98C: 81c7e008                 ret
F001E990: 91e80010                 restore %g0, %l0, %o0
