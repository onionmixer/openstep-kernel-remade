F002C804: 9de3bf98                 save    %sp, -0x68, %sp
F002C808: 4001a8ec                 call    _spltty
F002C80C: 01000000                 nop
F002C810: 133c04d0                 sethi   %hi(_rawintrq), %o1
F002C814: ea026160                 ld      [%o1+%lo(_rawintrq)], %l5
F002C818: 96100008                 mov     %o0, %o3
F002C81C: 80a56000                 cmp     %l5, 0
F002C820: 0280000b                 be      loc_F002C84C
F002C824: 94126160                 or      %o1, %lo(_rawintrq), %o2! size_t
F002C828: d005607c                 ld      [%l5+0x7C], %o0
F002C82C: 80a22000                 cmp     %o0, 0
F002C830: 12800003                 bne     loc_F002C83C
F002C834: d0226160                 st      %o0, [%o1+%lo(_rawintrq)]
F002C838: c022a004                 clr     [%o2+4]
F002C83C: c025607c                 clr     [%l5+0x7C]
F002C840: d002a008                 ld      [%o2+8], %o0
F002C844: 90023fff                 inc     -1, %o0
F002C848: d022a008                 st      %o0, [%o2+8]
F002C84C: 4001a936                 call    _splx
F002C850: 9010000b                 mov     %o3, %o0
F002C854: 80a56000                 cmp     %l5, 0
F002C858: 0280005e                 be      locret_F002C9D0
F002C85C: a8102000                 mov     0, %l4
F002C860: 113c04d8                 sethi   %hi(_rawcb), %o0
F002C864: e20223f0                 ld      [%o0+%lo(_rawcb)], %l1
F002C868: 921223f0                 or      %o0, %lo(_rawcb), %o1
F002C86C: d0056004                 ld      [%l5+4], %o0
F002C870: 80a44009                 cmp     %l1, %o1
F002C874: 02800041                 be      loc_F002C978
F002C878: a6054008                 add     %l5, %o0, %l3
F002C87C: ac100009                 mov     %o1, %l6
F002C880: d214602c                 lduh    [%l1+0x2C], %o1
F002C884: d014c000                 lduh    [%l3], %o0
F002C888: 80a24008                 cmp     %o1, %o0
F002C88C: 32800038                 bne,a   loc_F002C96C
F002C890: e2044000                 ld      [%l1], %l1
F002C894: d214602e                 lduh    [%l1+0x2E], %o1
F002C898: 80a26000                 cmp     %o1, 0
F002C89C: 22800007                 be,a    loc_F002C8B8
F002C8A0: d014604c                 lduh    [%l1+0x4C], %o0
F002C8A4: d014e002                 lduh    [%l3+2], %o0
F002C8A8: 80a24008                 cmp     %o1, %o0
F002C8AC: 32800030                 bne,a   loc_F002C96C
F002C8B0: e2044000                 ld      [%l1], %l1
F002C8B4: d014604c                 lduh    [%l1+0x4C], %o0
F002C8B8: 808a2001                 btst    1, %o0
F002C8BC: 02800008                 be      loc_F002C8DC
F002C8C0: 9004601c                 add     %l1, 0x1C, %o0! void *
F002C8C4: 9204e004                 add     %l3, 4, %o1! void *
F002C8C8: 7fff65a5                 call    _bcmp
F002C8CC: 94102010                 mov     0x10, %o2! size_t
F002C8D0: 80a22000                 cmp     %o0, 0
F002C8D4: 32800026                 bne,a   loc_F002C96C
F002C8D8: e2044000                 ld      [%l1], %l1
F002C8DC: d014604c                 lduh    [%l1+0x4C], %o0
F002C8E0: 808a2002                 btst    2, %o0
F002C8E4: 02800008                 be      loc_F002C904
F002C8E8: 9004600c                 add     %l1, 0xC, %o0! void *
F002C8EC: 9204e014                 add     %l3, 0x14, %o1! void *
F002C8F0: 7fff659b                 call    _bcmp
F002C8F4: 94102010                 mov     0x10, %o2
F002C8F8: 80a22000                 cmp     %o0, 0
F002C8FC: 3280001c                 bne,a   loc_F002C96C
F002C900: e2044000                 ld      [%l1], %l1
F002C904: 80a52000                 cmp     %l4, 0
F002C908: 02800017                 be      loc_F002C964
F002C90C: 150ee6b2                 sethi   0x3B9AC800, %o2
F002C910: d0054000                 ld      [%l5], %o0
F002C914: 92102000                 mov     0, %o1
F002C918: 7fffc50b                 call    _m_copy
F002C91C: 9412a200                 bset    0x200, %o2
F002C920: a0920000                 orcc    %o0, %g0, %l0
F002C924: 02800010                 be      loc_F002C964
F002C928: 94100010                 mov     %l0, %o2
F002C92C: a4052024                 add     %l4, 0x24, %l2 ! '$'
F002C930: 90100012                 mov     %l2, %o0
F002C934: 9204e014                 add     %l3, 0x14, %o1
F002C938: 7fffcf41                 call    _sbappendaddr
F002C93C: 96102000                 mov     0, %o3
F002C940: 80a22000                 cmp     %o0, 0
F002C944: 12800006                 bne     loc_F002C95C
F002C948: 90100014                 mov     %l4, %o0
F002C94C: 7fffc4c6                 call    _m_freem
F002C950: 90100010                 mov     %l0, %o0
F002C954: 10800005                 ba      loc_F002C968
F002C958: e8046008                 ld      [%l1+8], %l4
F002C95C: 7fffceac                 call    _sowakeup
F002C960: 92100012                 mov     %l2, %o1
F002C964: e8046008                 ld      [%l1+8], %l4
F002C968: e2044000                 ld      [%l1], %l1
F002C96C: 80a44016                 cmp     %l1, %l6
F002C970: 32bfffc5                 bne,a   loc_F002C884
F002C974: d214602c                 lduh    [%l1+0x2C], %o1
F002C978: 80a52000                 cmp     %l4, 0
F002C97C: 02800012                 be      loc_F002C9C4
F002C980: a0052024                 add     %l4, 0x24, %l0 ! '$'
F002C984: 90100010                 mov     %l0, %o0
F002C988: 9204e014                 add     %l3, 0x14, %o1
F002C98C: d4054000                 ld      [%l5], %o2
F002C990: 7fffcf2b                 call    _sbappendaddr
F002C994: 96102000                 mov     0, %o3
F002C998: 80a22000                 cmp     %o0, 0
F002C99C: 12800005                 bne     loc_F002C9B0
F002C9A0: 90100014                 mov     %l4, %o0
F002C9A4: 7fffc4b0                 call    _m_freem
F002C9A8: d0054000                 ld      [%l5], %o0
F002C9AC: 30800003                 ba,a    loc_F002C9B8
F002C9B0: 7fffce97                 call    _sowakeup
F002C9B4: 92100010                 mov     %l0, %o1
F002C9B8: 7fffc43f                 call    _m_free
F002C9BC: 90100015                 mov     %l5, %o0
F002C9C0: 30bfff92                 ba,a    loc_F002C808
F002C9C4: 7fffc4a8                 call    _m_freem
F002C9C8: 90100015                 mov     %l5, %o0
F002C9CC: 30bfff8f                 ba,a    loc_F002C808
F002C9D0: 81c7e008                 ret
F002C9D4: 81e80000                 restore
