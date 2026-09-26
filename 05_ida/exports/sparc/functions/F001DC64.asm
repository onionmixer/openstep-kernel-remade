F001DC64: 9de3bf98                 save    %sp, -0x68, %sp
F001DC68: 80a62000                 cmp     %i0, 0
F001DC6C: 02800034                 be      locret_F001DD3C
F001DC70: 01000000                 nop
F001DC74: 4001e3d1                 call    _spltty
F001DC78: 2f3c042e                 sethi   -0xFEF4800, %l7
F001DC7C: ac100008                 mov     %o0, %l6
F001DC80: 273c04d2aa14e30c         set     word_F0134B0C, %l5
F001DC88: 253c04d3                 sethi   -0xFECB400, %l2
F001DC8C: 293c04d2                 sethi   -0xFECB800, %l4
F001DC90: 4001e3ca                 call    _spltty
F001DC94: 01000000                 nop
F001DC98: d256200a                 ldsh    [%i0+0xA], %o1
F001DC9C: 80a26000                 cmp     %o1, 0
F001DCA0: 12800005                 bne     loc_F001DCB4
F001DCA4: a2100008                 mov     %o0, %l1
F001DCA8: 7fffdd32                 call    _panic
F001DCAC: 9015e2e0                 or      %l7, 0x2E0, %o0
F001DCB0: d256200a                 ldsh    [%i0+0xA], %o1
F001DCB4: 932a6001                 sll     %o1, 1, %o1
F001DCB8: d0124015                 lduh    [%o1+%l5], %o0
F001DCBC: 90023fff                 inc     -1, %o0
F001DCC0: d0324015                 sth     %o0, [%o1+%l5]
F001DCC4: d014e30c                 lduh    [%l3+0x30C], %o0
F001DCC8: 90022001                 inc     %o0
F001DCCC: d034e30c                 sth     %o0, [%l3+0x30C]
F001DCD0: d0062004                 ld      [%i0+4], %o0
F001DCD4: 80a2207f                 cmp     %o0, 0x7F
F001DCD8: 08800004                 bleu    loc_F001DCE8
F001DCDC: c036200a                 clrh    [%i0+0xA]
F001DCE0: 400001ca                 call    _mclput
F001DCE4: 90100018                 mov     %i0, %o0
F001DCE8: c0262004                 clr     [%i0+4]
F001DCEC: e0060000                 ld      [%i0], %l0
F001DCF0: c026207c                 clr     [%i0+0x7C]
F001DCF4: d204a168                 ld      [%l2+0x168], %o1
F001DCF8: 90100011                 mov     %l1, %o0
F001DCFC: d2260000                 st      %o1, [%i0]
F001DD00: 4001e409                 call    _splx
F001DD04: f024a168                 st      %i0, [%l2+0x168]
F001DD08: d00522e8                 ld      [%l4+0x2E8], %o0
F001DD0C: 80a22000                 cmp     %o0, 0
F001DD10: 02800006                 be      loc_F001DD28
F001DD14: b0100010                 mov     %l0, %i0
F001DD18: c02522e8                 clr     [%l4+0x2E8]
F001DD1C: 7fffd433                 call    _wakeup
F001DD20: 9014a168                 or      %l2, 0x168, %o0
F001DD24: b0100010                 mov     %l0, %i0
F001DD28: 80a62000                 cmp     %i0, 0
F001DD2C: 12bfffd9                 bne     loc_F001DC90
F001DD30: 01000000                 nop
F001DD34: 4001e3fc                 call    _splx
F001DD38: 90100016                 mov     %l6, %o0
F001DD3C: 81c7e008                 ret
F001DD40: 81e80000                 restore
