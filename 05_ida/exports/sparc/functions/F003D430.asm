F003D430: 9de3bf98                 save    %sp, -0x68, %sp
F003D434: 113c04eaa41222a0         set     _rtable, %l2
F003D43C: 9004a100                 add     %l2, 0x100, %o0
F003D440: 80a48008                 cmp     %l2, %o0
F003D444: 1a800023                 bcc     locret_F003D4D0
F003D448: a8100008                 mov     %o0, %l4
F003D44C: e0048000                 ld      [%l2], %l0
F003D450: 80a42000                 cmp     %l0, 0
F003D454: 2280001c                 be,a    loc_F003D4C4
F003D458: a404a004                 inc     4, %l2
F003D45C: d0042030                 ld      [%l0+0x30], %o0
F003D460: a204200c                 add     %l0, 0xC, %l1
F003D464: 80a20018                 cmp     %o0, %i0
F003D468: 12800013                 bne     loc_F003D4B4
F003D46C: e6042008                 ld      [%l0+8], %l3
F003D470: 7ffffeef                 call    _rp_rmhash
F003D474: 90100010                 mov     %l0, %o0
F003D478: d2142012                 lduh    [%l0+0x12], %o1
F003D47C: 90100011                 mov     %l1, %o0
F003D480: 92026001                 inc     %o1
F003D484: 7fff9fdc                 call    _binvalfree
F003D488: d2342012                 sth     %o1, [%l0+0x12]
F003D48C: 7fffa226                 call    _dnlc_purge_vp
F003D490: 90100011                 mov     %l1, %o0
F003D494: d0142012                 lduh    [%l0+0x12], %o0
F003D498: 80a22001                 cmp     %o0, 1
F003D49C: 08800004                 bleu    loc_F003D4AC
F003D4A0: 01000000                 nop
F003D4A4: 7ffffe94                 call    sub_F003CEF4
F003D4A8: 90100010                 mov     %l0, %o0
F003D4AC: 7fffadae                 call    _vn_rele
F003D4B0: 90100011                 mov     %l1, %o0
F003D4B4: a094c000                 orcc    %l3, %g0, %l0
F003D4B8: 32bfffea                 bne,a   loc_F003D460
F003D4BC: d0042030                 ld      [%l0+0x30], %o0
F003D4C0: a404a004                 inc     4, %l2
F003D4C4: 80a48014                 cmp     %l2, %l4
F003D4C8: 2abfffe2                 bcs,a   loc_F003D450
F003D4CC: e0048000                 ld      [%l2], %l0
F003D4D0: 81c7e008                 ret
F003D4D4: 81e80000                 restore
