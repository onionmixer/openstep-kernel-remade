F005DEA0: 9de3bf98                 save    %sp, -0x68, %sp
F005DEA4: 253c04ef                 sethi   %hi(_ipc_space_zone), %l2
F005DEA8: 40006c89                 call    _zalloc
F005DEAC: d004a340                 ld      [%l2+%lo(_ipc_space_zone)], %o0
F005DEB0: a0920000                 orcc    %o0, %g0, %l0
F005DEB4: 32800004                 bne,a   loc_F005DEC4
F005DEB8: d0060000                 ld      [%i0], %o0
F005DEBC: 10800030                 ba      locret_F005DF7C
F005DEC0: b0102006                 mov     6, %i0
F005DEC4: 40000381                 call    _ipc_table_alloc
F005DEC8: 912a2004                 sll     %o0, 4, %o0
F005DECC: a2920000                 orcc    %o0, %g0, %l1
F005DED0: 32800007                 bne,a   loc_F005DEEC
F005DED4: e4060000                 ld      [%i0], %l2
F005DED8: d004a340                 ld      [%l2+0x340], %o0
F005DEDC: 40006cbd                 call    _zfree
F005DEE0: 92100010                 mov     %l0, %o1! size_t
F005DEE4: 10800026                 ba      locret_F005DF7C
F005DEE8: b0102006                 mov     6, %i0
F005DEEC: 90100011                 mov     %l1, %o0! void *
F005DEF0: 4000dbda                 call    _bzero
F005DEF4: 932ca004                 sll     %l2, 4, %o1
F005DEF8: 92102000                 mov     0, %o1
F005DEFC: 80a24012                 cmp     %o1, %l2
F005DF00: 1a800009                 bcc     loc_F005DF24
F005DF04: 153fc000                 sethi   -0x1000000, %o2
F005DF08: 912a6004                 sll     %o1, 4, %o0
F005DF0C: d4244008                 st      %o2, [%l1+%o0]
F005DF10: 90044008                 add     %l1, %o0, %o0
F005DF14: 92026001                 inc     %o1
F005DF18: 80a24012                 cmp     %o1, %l2
F005DF1C: 0abffffb                 bcs     loc_F005DF08
F005DF20: d2222008                 st      %o1, [%o0+8]
F005DF24: 912ca004                 sll     %l2, 4, %o0
F005DF28: 90020011                 add     %o0, %l1, %o0
F005DF2C: c0223ff8                 clr     [%o0-8]
F005DF30: c0240000                 clr     [%l0]
F005DF34: 90102002                 mov     2, %o0
F005DF38: d0242004                 st      %o0, [%l0+4]
F005DF3C: c0242008                 clr     [%l0+8]
F005DF40: 90102001                 mov     1, %o0
F005DF44: d024200c                 st      %o0, [%l0+0xC]
F005DF48: c0242010                 clr     [%l0+0x10]
F005DF4C: e2242014                 st      %l1, [%l0+0x14]
F005DF50: e4242018                 st      %l2, [%l0+0x18]
F005DF54: 90062004                 add     %i0, 4, %o0
F005DF58: d024201c                 st      %o0, [%l0+0x1C]
F005DF5C: 400000e6                 call    _ipc_splay_tree_init
F005DF60: 90042020                 add     %l0, 0x20, %o0 ! ' '
F005DF64: c0242038                 clr     [%l0+0x38]
F005DF68: c024203c                 clr     [%l0+0x3C]
F005DF6C: c0242040                 clr     [%l0+0x40]
F005DF70: c0242044                 clr     [%l0+0x44]
F005DF74: e0264000                 st      %l0, [%i1]
F005DF78: b0102000                 mov     0, %i0
F005DF7C: 81c7e008                 ret
F005DF80: 81e80000                 restore
