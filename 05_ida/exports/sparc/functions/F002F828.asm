F002F828: 9de3bf70                 save    %sp, -0x90, %sp! int
F002F82C: a2100018                 mov     %i0, %l1
F002F830: a6102000                 mov     0, %l3
F002F834: a4102000                 mov     0, %l2
F002F838: c027bfd0                 clr     [%fp+var_30]
F002F83C: a007bfd8                 add     %fp, var_28, %l0
F002F840: e023a040                 st      %l0, [%sp+0x90+var_50]
F002F844: 90100011                 mov     %l1, %o0
F002F848: 92100019                 mov     %i1, %o1
F002F84C: 4000032a                 call    sub_F00304F4
F002F850: 01000000                 nop
F002F854: 00000020                 illtrap
F002F858: 90100011                 mov     %l1, %o0
F002F85C: 92100010                 mov     %l0, %o1
F002F860: 40000074                 call    sub_F002FA30
F002F864: 9407bfd4                 add     %fp, var_2C, %o2
F002F868: b0920000                 orcc    %o0, %g0, %i0
F002F86C: 02800012                 be      loc_F002F8B4
F002F870: 80a63fff                 cmp     %i0, -1
F002F874: 12800049                 bne     loc_F002F998
F002F878: 80a62000                 cmp     %i0, 0
F002F87C: d007bfd4                 ld      [%fp+var_2C], %o0
F002F880: 1320081a9212610c         set     -0x7FDF96F4, %o1
F002F888: 7fffe8f5                 call    _ifioctl
F002F88C: 94100010                 mov     %l0, %o2! size_t
F002F890: b0920000                 orcc    %o0, %g0, %i0
F002F894: 12800005                 bne     loc_F002F8A8
F002F898: 9007bfe8                 add     %fp, var_18, %o0! void *
F002F89C: 92100019                 mov     %i1, %o1! void *
F002F8A0: 4001949c                 call    _bcopy
F002F8A4: 94102010                 mov     0x10, %o2
F002F8A8: 7fffbbe7                 call    _soclose
F002F8AC: d007bfd4                 ld      [%fp+var_2C], %o0
F002F8B0: 3080005e                 ba,a    locret_F002FA28
F002F8B4: 90100011                 mov     %l1, %o0
F002F8B8: 92100019                 mov     %i1, %o1
F002F8BC: 400000c8                 call    sub_F002FBDC
F002F8C0: 9410001a                 mov     %i2, %o2
F002F8C4: a6100008                 mov     %o0, %l3
F002F8C8: 4000e1ea                 call    _kalloc
F002F8CC: 9010212c                 mov     0x12C, %o0
F002F8D0: a4100008                 mov     %o0, %l2
F002F8D4: a804a0ec                 add     %l2, 0xEC, %l4
F002F8D8: a007bfd0                 add     %fp, var_30, %l0
F002F8DC: 90100011                 mov     %l1, %o0! int
F002F8E0: d207bfd4                 ld      [%fp+var_2C], %o1! int
F002F8E4: 94100013                 mov     %l3, %o2! int
F002F8E8: 96100012                 mov     %l2, %o3! int
F002F8EC: 9810001a                 mov     %i2, %o4! int
F002F8F0: 40000183                 call    sub_F002FEFC
F002F8F4: 9a100010                 mov     %l0, %o5
F002F8F8: b0920000                 orcc    %o0, %g0, %i0
F002F8FC: 12800027                 bne     loc_F002F998
F002F900: 01000000                 nop
F002F904: d00d2006                 ldub    [%l4+6], %o0
F002F908: 80a22000                 cmp     %o0, 0
F002F90C: 02800011                 be      loc_F002F950
F002F910: d007bfd0                 ld      [%fp+var_30], %o0
F002F914: 80a22000                 cmp     %o0, 0
F002F918: 12800008                 bne     loc_F002F938
F002F91C: 92100013                 mov     %l3, %o1
F002F920: 4000024e                 call    sub_F0030258
F002F924: 90100010                 mov     %l0, %o0
F002F928: b0920000                 orcc    %o0, %g0, %i0
F002F92C: 1280001b                 bne     loc_F002F998
F002F930: d007bfd0                 ld      [%fp+var_30], %o0
F002F934: 92100013                 mov     %l3, %o1
F002F938: 40000272                 call    sub_F0030300
F002F93C: 94100012                 mov     %l2, %o2
F002F940: b0920000                 orcc    %o0, %g0, %i0
F002F944: 12800015                 bne     loc_F002F998
F002F948: 90100011                 mov     %l1, %o0
F002F94C: 30bfffe5                 ba,a    loc_F002F8E0
F002F950: 80a22000                 cmp     %o0, 0
F002F954: 22800006                 be,a    loc_F002F96C
F002F958: 90100011                 mov     %l1, %o0
F002F95C: 40000263                 call    sub_F00302E8
F002F960: 01000000                 nop
F002F964: c027bfd0                 clr     [%fp+var_30]
F002F968: 90100011                 mov     %l1, %o0
F002F96C: 9207bfd8                 add     %fp, var_28, %o1
F002F970: d407bfd4                 ld      [%fp+var_2C], %o2! size_t
F002F974: 400002b0                 call    sub_F0030434
F002F978: 9604a010                 add     %l2, 0x10, %o3
F002F97C: b0920000                 orcc    %o0, %g0, %i0
F002F980: 12800006                 bne     loc_F002F998
F002F984: 9007bfe8                 add     %fp, var_18, %o0! void *
F002F988: 92100019                 mov     %i1, %o1! void *
F002F98C: 40019461                 call    _bcopy
F002F990: 94102010                 mov     0x10, %o2
F002F994: 80a62000                 cmp     %i0, 0
F002F998: 0280000b                 be      loc_F002F9C4
F002F99C: d007bfd4                 ld      [%fp+var_2C], %o0
F002F9A0: 80a22000                 cmp     %o0, 0
F002F9A4: 02800008                 be      loc_F002F9C4
F002F9A8: 1320081a                 sethi   -0x7FDF9800, %o1
F002F9AC: 92126110                 bset    0x110, %o1
F002F9B0: d614600c                 lduh    [%l1+0xC], %o3
F002F9B4: 9407bfd8                 add     %fp, var_28, %o2
F002F9B8: 960afffe                 and     %o3, -2, %o3
F002F9BC: 7fffe8a8                 call    _ifioctl
F002F9C0: d637bfe8                 sth     %o3, [%fp+var_18]
F002F9C4: d214600c                 lduh    [%l1+0xC], %o1
F002F9C8: 113fffd0                 sethi   -0xC000, %o0
F002F9CC: 902a4008                 andn    %o1, %o0, %o0
F002F9D0: d207bfd4                 ld      [%fp+var_2C], %o1
F002F9D4: d034600c                 sth     %o0, [%l1+0xC]
F002F9D8: 80a26000                 cmp     %o1, 0
F002F9DC: 02800005                 be      loc_F002F9F0
F002F9E0: 80a4e000                 cmp     %l3, 0
F002F9E4: 7fffbb98                 call    _soclose
F002F9E8: 90100009                 mov     %o1, %o0
F002F9EC: 80a4e000                 cmp     %l3, 0
F002F9F0: 02800004                 be      loc_F002FA00
F002F9F4: 90100013                 mov     %l3, %o0
F002F9F8: 4000e1ea                 call    _kfree
F002F9FC: 92102148                 mov     0x148, %o1
F002FA00: 80a4a000                 cmp     %l2, 0
F002FA04: 02800004                 be      loc_F002FA14
F002FA08: 90100012                 mov     %l2, %o0
F002FA0C: 4000e1e5                 call    _kfree
F002FA10: 9210212c                 mov     0x12C, %o1
F002FA14: 80a62000                 cmp     %i0, 0
F002FA18: 12800004                 bne     locret_F002FA28
F002FA1C: 01000000                 nop
F002FA20: 40000232                 call    sub_F00302E8
F002FA24: d007bfd0                 ld      [%fp+var_30], %o0
F002FA28: 81c7e008                 ret
F002FA2C: 81e80000                 restore
