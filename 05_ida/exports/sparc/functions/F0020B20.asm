F0020B20: 9de3bf98                 save    %sp, -0x68, %sp
F0020B24: e006200c                 ld      [%i0+0xC], %l0
F0020B28: 80a42000                 cmp     %l0, 0
F0020B2C: 02800003                 be      loc_F0020B38
F0020B30: a6102000                 mov     0, %l3
F0020B34: e604207c                 ld      [%l0+0x7C], %l3
F0020B38: 80a66000                 cmp     %i1, 0
F0020B3C: 0480004b                 ble     loc_F0020C68
F0020B40: 80a42000                 cmp     %l0, 0
F0020B44: 2b3c04d2ae15630c         set     word_F0134B0C, %l7
F0020B4C: 293c04d3                 sethi   -0xFECB400, %l4
F0020B50: 2d3c04d2                 sethi   -0xFECB800, %l6
F0020B54: 3280000b                 bne,a   loc_F0020B80
F0020B58: d0542008                 ldsh    [%l0+8], %o0
F0020B5C: 80a4e000                 cmp     %l3, 0
F0020B60: 12800006                 bne     loc_F0020B78
F0020B64: a0100013                 mov     %l3, %l0
F0020B68: 113c042f                 sethi   %hi(aSbdrop), %o0! "sbdrop"
F0020B6C: 7fffd181                 call    _panic
F0020B70: 901220c8                 bset    %lo(aSbdrop), %o0! "sbdrop"
F0020B74: a0100013                 mov     %l3, %l0
F0020B78: 10800038                 ba      loc_F0020C58
F0020B7C: e604e07c                 ld      [%l3+0x7C], %l3
F0020B80: 80a20019                 cmp     %o0, %i1
F0020B84: 14800082                 bg      loc_F0020D8C
F0020B88: 92100008                 mov     %o0, %o1
F0020B8C: b2264008                 sub     %i1, %o0, %i1
F0020B90: d0160000                 lduh    [%i0], %o0
F0020B94: 90220009                 sub     %o0, %o1, %o0
F0020B98: d2162004                 lduh    [%i0+4], %o1
F0020B9C: d0360000                 sth     %o0, [%i0]
F0020BA0: 92027f80                 inc     -0x80, %o1
F0020BA4: d2362004                 sth     %o1, [%i0+4]
F0020BA8: d0042004                 ld      [%l0+4], %o0
F0020BAC: 80a2207c                 cmp     %o0, 0x7C ! '|'
F0020BB0: 08800003                 bleu    loc_F0020BBC
F0020BB4: 90027c00                 add     %o1, -0x400, %o0
F0020BB8: d0362004                 sth     %o0, [%i0+4]
F0020BBC: 4001d7ff                 call    _spltty
F0020BC0: 01000000                 nop
F0020BC4: d254200a                 ldsh    [%l0+0xA], %o1
F0020BC8: 80a26000                 cmp     %o1, 0
F0020BCC: 12800006                 bne     loc_F0020BE4
F0020BD0: a4100008                 mov     %o0, %l2
F0020BD4: 113c042f                 sethi   %hi(aMfree_3), %o0! "mfree"
F0020BD8: 7fffd166                 call    _panic
F0020BDC: 901220d0                 bset    %lo(aMfree_3), %o0! "mfree"
F0020BE0: d254200a                 ldsh    [%l0+0xA], %o1
F0020BE4: 932a6001                 sll     %o1, 1, %o1
F0020BE8: d0124017                 lduh    [%o1+%l7], %o0
F0020BEC: 90023fff                 inc     -1, %o0
F0020BF0: d0324017                 sth     %o0, [%o1+%l7]
F0020BF4: d015630c                 lduh    [%l5+0x30C], %o0
F0020BF8: 90022001                 inc     %o0
F0020BFC: d035630c                 sth     %o0, [%l5+0x30C]
F0020C00: d0042004                 ld      [%l0+4], %o0
F0020C04: 80a2207f                 cmp     %o0, 0x7F
F0020C08: 08800004                 bleu    loc_F0020C18
F0020C0C: c034200a                 clrh    [%l0+0xA]
F0020C10: 7ffff5fe                 call    _mclput
F0020C14: 90100010                 mov     %l0, %o0
F0020C18: c0242004                 clr     [%l0+4]
F0020C1C: e2040000                 ld      [%l0], %l1
F0020C20: c024207c                 clr     [%l0+0x7C]
F0020C24: d2052168                 ld      [%l4+0x168], %o1
F0020C28: 90100012                 mov     %l2, %o0
F0020C2C: d2240000                 st      %o1, [%l0]
F0020C30: 4001d83d                 call    _splx
F0020C34: e0252168                 st      %l0, [%l4+0x168]
F0020C38: d005a2e8                 ld      [%l6+0x2E8], %o0
F0020C3C: 80a22000                 cmp     %o0, 0
F0020C40: 02800006                 be      loc_F0020C58
F0020C44: a0100011                 mov     %l1, %l0
F0020C48: c025a2e8                 clr     [%l6+0x2E8]
F0020C4C: 7fffc867                 call    _wakeup
F0020C50: 90152168                 or      %l4, 0x168, %o0
F0020C54: a0100011                 mov     %l1, %l0
F0020C58: 80a66000                 cmp     %i1, 0
F0020C5C: 14bfffbe                 bg      loc_F0020B54
F0020C60: 80a42000                 cmp     %l0, 0
F0020C64: 80a42000                 cmp     %l0, 0
F0020C68: 02800044                 be      loc_F0020D78
F0020C6C: 80a42000                 cmp     %l0, 0
F0020C70: d0542008                 ldsh    [%l0+8], %o0
F0020C74: 80a22000                 cmp     %o0, 0
F0020C78: 1280003f                 bne     loc_F0020D74
F0020C7C: d2142008                 lduh    [%l0+8], %o1
F0020C80: 293c04d2ac15230c         set     word_F0134B0C, %l6
F0020C88: 333c04d3                 sethi   -0xFECB400, %i1
F0020C8C: 2b3c04d2                 sethi   -0xFECB800, %l5
F0020C90: d0160000                 lduh    [%i0], %o0
F0020C94: 90220009                 sub     %o0, %o1, %o0
F0020C98: d2162004                 lduh    [%i0+4], %o1
F0020C9C: d0360000                 sth     %o0, [%i0]
F0020CA0: 92027f80                 inc     -0x80, %o1
F0020CA4: d2362004                 sth     %o1, [%i0+4]
F0020CA8: d0042004                 ld      [%l0+4], %o0
F0020CAC: 80a2207c                 cmp     %o0, 0x7C ! '|'
F0020CB0: 08800003                 bleu    loc_F0020CBC
F0020CB4: 90027c00                 add     %o1, -0x400, %o0
F0020CB8: d0362004                 sth     %o0, [%i0+4]
F0020CBC: 4001d7bf                 call    _spltty
F0020CC0: 01000000                 nop
F0020CC4: d254200a                 ldsh    [%l0+0xA], %o1
F0020CC8: 80a26000                 cmp     %o1, 0
F0020CCC: 12800006                 bne     loc_F0020CE4
F0020CD0: a4100008                 mov     %o0, %l2
F0020CD4: 113c042f                 sethi   %hi(aMfree_4), %o0! "mfree"
F0020CD8: 7fffd126                 call    _panic
F0020CDC: 901220d8                 bset    %lo(aMfree_4), %o0! "mfree"
F0020CE0: d254200a                 ldsh    [%l0+0xA], %o1
F0020CE4: 932a6001                 sll     %o1, 1, %o1
F0020CE8: d0124016                 lduh    [%o1+%l6], %o0
F0020CEC: 90023fff                 inc     -1, %o0
F0020CF0: d0324016                 sth     %o0, [%o1+%l6]
F0020CF4: d015230c                 lduh    [%l4+0x30C], %o0
F0020CF8: 90022001                 inc     %o0
F0020CFC: d035230c                 sth     %o0, [%l4+0x30C]
F0020D00: d0042004                 ld      [%l0+4], %o0
F0020D04: 80a2207f                 cmp     %o0, 0x7F
F0020D08: 08800004                 bleu    loc_F0020D18
F0020D0C: c034200a                 clrh    [%l0+0xA]
F0020D10: 7ffff5be                 call    _mclput
F0020D14: 90100010                 mov     %l0, %o0
F0020D18: c0242004                 clr     [%l0+4]
F0020D1C: e2040000                 ld      [%l0], %l1
F0020D20: c024207c                 clr     [%l0+0x7C]
F0020D24: d2066168                 ld      [%i1+0x168], %o1
F0020D28: 90100012                 mov     %l2, %o0
F0020D2C: d2240000                 st      %o1, [%l0]
F0020D30: 4001d7fd                 call    _splx
F0020D34: e0266168                 st      %l0, [%i1+0x168]
F0020D38: d00562e8                 ld      [%l5+0x2E8], %o0
F0020D3C: 80a22000                 cmp     %o0, 0
F0020D40: 02800006                 be      loc_F0020D58
F0020D44: a0100011                 mov     %l1, %l0
F0020D48: c02562e8                 clr     [%l5+0x2E8]
F0020D4C: 7fffc827                 call    _wakeup
F0020D50: 90166168                 or      %i1, 0x168, %o0
F0020D54: a0100011                 mov     %l1, %l0
F0020D58: 80a42000                 cmp     %l0, 0
F0020D5C: 22800015                 be,a    locret_F0020DB0
F0020D60: e626200c                 st      %l3, [%i0+0xC]
F0020D64: d0542008                 ldsh    [%l0+8], %o0
F0020D68: 80a22000                 cmp     %o0, 0
F0020D6C: 02bfffc9                 be      loc_F0020C90
F0020D70: d2142008                 lduh    [%l0+8], %o1
F0020D74: 80a42000                 cmp     %l0, 0
F0020D78: 2280000e                 be,a    locret_F0020DB0
F0020D7C: e626200c                 st      %l3, [%i0+0xC]
F0020D80: e026200c                 st      %l0, [%i0+0xC]
F0020D84: 1080000b                 ba      locret_F0020DB0
F0020D88: e624207c                 st      %l3, [%l0+0x7C]
F0020D8C: 92224019                 sub     %o1, %i1, %o1
F0020D90: d0042004                 ld      [%l0+4], %o0
F0020D94: d2342008                 sth     %o1, [%l0+8]
F0020D98: 90020019                 add     %o0, %i1, %o0
F0020D9C: d0242004                 st      %o0, [%l0+4]
F0020DA0: d0160000                 lduh    [%i0], %o0
F0020DA4: 90220019                 sub     %o0, %i1, %o0
F0020DA8: 10bfffaf                 ba      loc_F0020C64
F0020DAC: d0360000                 sth     %o0, [%i0]
F0020DB0: 81c7e008                 ret
F0020DB4: 81e80000                 restore
