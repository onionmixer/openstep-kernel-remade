F0020DB8: 9de3bf98                 save    %sp, -0x68, %sp
F0020DBC: e006200c                 ld      [%i0+0xC], %l0
F0020DC0: 80a42000                 cmp     %l0, 0
F0020DC4: 0280003d                 be      locret_F0020EB8
F0020DC8: 293c04d2                 sethi   %hi(word_F0134B0C), %l4
F0020DCC: ac15230c                 or      %l4, %lo(word_F0134B0C), %l6
F0020DD0: 273c04d3                 sethi   -0xFECB400, %l3
F0020DD4: d004207c                 ld      [%l0+0x7C], %o0
F0020DD8: 2b3c04d2                 sethi   -0xFECB800, %l5
F0020DDC: d026200c                 st      %o0, [%i0+0xC]
F0020DE0: d2160000                 lduh    [%i0], %o1
F0020DE4: d0142008                 lduh    [%l0+8], %o0
F0020DE8: 92224008                 sub     %o1, %o0, %o1
F0020DEC: d0162004                 lduh    [%i0+4], %o0
F0020DF0: d2360000                 sth     %o1, [%i0]
F0020DF4: 92023f80                 add     %o0, -0x80, %o1
F0020DF8: d2362004                 sth     %o1, [%i0+4]
F0020DFC: d0042004                 ld      [%l0+4], %o0
F0020E00: 80a2207c                 cmp     %o0, 0x7C ! '|'
F0020E04: 08800003                 bleu    loc_F0020E10
F0020E08: 90027c00                 add     %o1, -0x400, %o0
F0020E0C: d0362004                 sth     %o0, [%i0+4]
F0020E10: 4001d76a                 call    _spltty
F0020E14: 01000000                 nop
F0020E18: d254200a                 ldsh    [%l0+0xA], %o1
F0020E1C: 80a26000                 cmp     %o1, 0
F0020E20: 12800006                 bne     loc_F0020E38
F0020E24: a4100008                 mov     %o0, %l2
F0020E28: 113c042f                 sethi   %hi(aMfree_5), %o0! "mfree"
F0020E2C: 7fffd0d1                 call    _panic
F0020E30: 901220e0                 bset    %lo(aMfree_5), %o0! "mfree"
F0020E34: d254200a                 ldsh    [%l0+0xA], %o1
F0020E38: 932a6001                 sll     %o1, 1, %o1
F0020E3C: d0124016                 lduh    [%o1+%l6], %o0
F0020E40: 90023fff                 inc     -1, %o0
F0020E44: d0324016                 sth     %o0, [%o1+%l6]
F0020E48: d015230c                 lduh    [%l4+0x30C], %o0
F0020E4C: 90022001                 inc     %o0
F0020E50: d035230c                 sth     %o0, [%l4+0x30C]
F0020E54: d0042004                 ld      [%l0+4], %o0
F0020E58: 80a2207f                 cmp     %o0, 0x7F
F0020E5C: 08800004                 bleu    loc_F0020E6C
F0020E60: c034200a                 clrh    [%l0+0xA]
F0020E64: 7ffff569                 call    _mclput
F0020E68: 90100010                 mov     %l0, %o0
F0020E6C: c0242004                 clr     [%l0+4]
F0020E70: e2040000                 ld      [%l0], %l1
F0020E74: c024207c                 clr     [%l0+0x7C]
F0020E78: d204e168                 ld      [%l3+0x168], %o1
F0020E7C: 90100012                 mov     %l2, %o0
F0020E80: d2240000                 st      %o1, [%l0]
F0020E84: 4001d7a8                 call    _splx
F0020E88: e024e168                 st      %l0, [%l3+0x168]
F0020E8C: d00562e8                 ld      [%l5+0x2E8], %o0
F0020E90: 80a22000                 cmp     %o0, 0
F0020E94: 02800006                 be      loc_F0020EAC
F0020E98: a0100011                 mov     %l1, %l0
F0020E9C: c02562e8                 clr     [%l5+0x2E8]
F0020EA0: 7fffc7d2                 call    _wakeup
F0020EA4: 9014e168                 or      %l3, 0x168, %o0
F0020EA8: a0100011                 mov     %l1, %l0
F0020EAC: 80a42000                 cmp     %l0, 0
F0020EB0: 32bfffcd                 bne,a   loc_F0020DE4
F0020EB4: d2160000                 lduh    [%i0], %o1
F0020EB8: 81c7e008                 ret
F0020EBC: 81e80000                 restore
