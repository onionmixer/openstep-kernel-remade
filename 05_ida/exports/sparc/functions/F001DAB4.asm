F001DAB4: 9de3bf98                 save    %sp, -0x68, %sp
F001DAB8: 4001e440                 call    _spltty
F001DABC: 01000000                 nop
F001DAC0: d256200a                 ldsh    [%i0+0xA], %o1
F001DAC4: 80a26000                 cmp     %o1, 0
F001DAC8: 12800005                 bne     loc_F001DADC
F001DACC: a2100008                 mov     %o0, %l1
F001DAD0: 113c042e                 sethi   %hi(aMfree), %o0! "mfree"
F001DAD4: 7fffdda7                 call    _panic
F001DAD8: 901222c8                 bset    %lo(aMfree), %o0! "mfree"
F001DADC: 153c04d2                 sethi   %hi(word_F0134B0C), %o2
F001DAE0: d256200a                 ldsh    [%i0+0xA], %o1
F001DAE4: 9612a30c                 or      %o2, %lo(word_F0134B0C), %o3
F001DAE8: 932a6001                 sll     %o1, 1, %o1
F001DAEC: d012400b                 lduh    [%o1+%o3], %o0
F001DAF0: 90023fff                 inc     -1, %o0
F001DAF4: d032400b                 sth     %o0, [%o1+%o3]
F001DAF8: d012a30c                 lduh    [%o2+%lo(word_F0134B0C)], %o0
F001DAFC: 90022001                 inc     %o0
F001DB00: d032a30c                 sth     %o0, [%o2+%lo(word_F0134B0C)]
F001DB04: d0062004                 ld      [%i0+4], %o0
F001DB08: 80a2207f                 cmp     %o0, 0x7F
F001DB0C: 08800004                 bleu    loc_F001DB1C
F001DB10: c036200a                 clrh    [%i0+0xA]
F001DB14: 4000023d                 call    _mclput
F001DB18: 90100018                 mov     %i0, %o0
F001DB1C: c0262004                 clr     [%i0+4]
F001DB20: c026207c                 clr     [%i0+0x7C]
F001DB24: e0060000                 ld      [%i0], %l0
F001DB28: 133c04d3                 sethi   %hi(_mfree), %o1
F001DB2C: d4026168                 ld      [%o1+%lo(_mfree)], %o2
F001DB30: 90100011                 mov     %l1, %o0
F001DB34: d4260000                 st      %o2, [%i0]
F001DB38: f0226168                 st      %i0, [%o1+%lo(_mfree)]
F001DB3C: 4001e47a                 call    _splx
F001DB40: b0126168                 or      %o1, %lo(_mfree), %i0
F001DB44: 133c04d2                 sethi   %hi(_m_want), %o1
F001DB48: d00262e8                 ld      [%o1+%lo(_m_want)], %o0
F001DB4C: 80a22000                 cmp     %o0, 0
F001DB50: 02800005                 be      locret_F001DB64
F001DB54: 01000000                 nop
F001DB58: c02262e8                 clr     [%o1+%lo(_m_want)]
F001DB5C: 7fffd4a3                 call    _wakeup
F001DB60: 90100018                 mov     %i0, %o0
F001DB64: 81c7e008                 ret
F001DB68: 91e80010                 restore %g0, %l0, %o0
