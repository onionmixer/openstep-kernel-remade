F001B8EC: 9de3bf98                 save    %sp, -0x68, %sp
F001B8F0: b00e20ff                 and     %i0, 0xFF, %i0
F001B8F4: b12e2004                 sll     %i0, 4, %i0
F001B8F8: 113c04bca6122204         set     unk_F012F204, %l3
F001B900: a0060013                 add     %i0, %l3, %l0
F001B904: e4042008                 ld      [%l0+8], %l2
F001B908: d44ca047                 ldsb    [%l2+0x47], %o2
F001B90C: e204200c                 ld      [%l0+0xC], %l1
F001B910: 932aa001                 sll     %o2, 1, %o1
F001B914: 9202400a                 add     %o1, %o2, %o1
F001B918: 932a6004                 sll     %o1, 4, %o1
F001B91C: 153c042e9412a0cc         set     _linesw, %o2
F001B924: 9202400a                 add     %o1, %o2, %o1
F001B928: d4026024                 ld      [%o1+0x24], %o2
F001B92C: 90100012                 mov     %l2, %o0
F001B930: 9fc28000                 call    %o2
F001B934: 92102000                 mov     0, %o1
F001B938: d0042004                 ld      [%l0+4], %o0
F001B93C: 808a2001                 btst    1, %o0
F001B940: 02800006                 be      loc_F001B958
F001B944: 01000000                 nop
F001B948: 4000340c                 call    _forceclose
F001B94C: d0560013                 ldsh    [%i0+%l3], %o0
F001B950: 7ffffe8d                 call    _ptsclose
F001B954: d0560013                 ldsh    [%i0+%l3], %o0
F001B958: 4001ec98                 call    _spltty
F001B95C: 01000000                 nop
F001B960: d2046004                 ld      [%l1+4], %o1
F001B964: 80a26000                 cmp     %o1, 0
F001B968: 02800004                 be      loc_F001B978
F001B96C: a0100008                 mov     %o0, %l0
F001B970: 7fffe9d9                 call    _selthreadclear
F001B974: 90046004                 add     %l1, 4, %o0
F001B978: d0046008                 ld      [%l1+8], %o0
F001B97C: 80a22000                 cmp     %o0, 0
F001B980: 02800004                 be      loc_F001B990
F001B984: 01000000                 nop
F001B988: 7fffe9d3                 call    _selthreadclear
F001B98C: 90046008                 add     %l1, 8, %o0
F001B990: 4001ece5                 call    _splx
F001B994: 90100010                 mov     %l0, %o0
F001B998: c024a024                 clr     [%l2+0x24]
F001B99C: 7ffffdd3                 call    _ttynty
F001B9A0: 90100012                 mov     %l2, %o0
F001B9A4: c0222008                 clr     [%o0+8]
F001B9A8: 81c7e008                 ret
F001B9AC: 81e80000                 restore
