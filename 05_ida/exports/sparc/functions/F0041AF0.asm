F0041AF0: 9de3bf98                 save    %sp, -0x68, %sp
F0041AF4: 40015431                 call    _spltty
F0041AF8: 01000000                 nop
F0041AFC: d2062004                 ld      [%i0+4], %o1
F0041B00: 80a26000                 cmp     %o1, 0
F0041B04: 12800009                 bne     loc_F0041B28
F0041B08: a0100008                 mov     %o0, %l0
F0041B0C: 90100018                 mov     %i0, %o0! unsigned int
F0041B10: 7fff42da                 call    _sleep
F0041B14: 92102018                 mov     0x18, %o1
F0041B18: d0062004                 ld      [%i0+4], %o0
F0041B1C: 80a22000                 cmp     %o0, 0
F0041B20: 22bffffc                 be,a    loc_F0041B10
F0041B24: 90100018                 mov     %i0, %o0
F0041B28: 4001547f                 call    _splx
F0041B2C: 90100010                 mov     %l0, %o0
F0041B30: d0062008                 ld      [%i0+8], %o0
F0041B34: d402201c                 ld      [%o0+0x1C], %o2
F0041B38: d402a05c                 ld      [%o2+0x5C], %o2
F0041B3C: 9fc28000                 call    %o2
F0041B40: d206200c                 ld      [%i0+0xC], %o1
F0041B44: 7fff9c08                 call    _vn_rele
F0041B48: d0062008                 ld      [%i0+8], %o0
F0041B4C: 4001541b                 call    _spltty
F0041B50: b00e3f80                 and     %i0, -0x80, %i0
F0041B54: d216200a                 lduh    [%i0+0xA], %o1
F0041B58: 80a26000                 cmp     %o1, 0
F0041B5C: 12800005                 bne     loc_F0041B70
F0041B60: a0100008                 mov     %o0, %l0
F0041B64: 113c0436                 sethi   %hi(aMfree_8), %o0! "mfree"
F0041B68: 7fff4d82                 call    _panic
F0041B6C: 90122100                 bset    %lo(aMfree_8), %o0! "mfree"
F0041B70: 153c04d2                 sethi   %hi(word_F0134B0C), %o2
F0041B74: d216200a                 lduh    [%i0+0xA], %o1
F0041B78: 9612a30c                 or      %o2, %lo(word_F0134B0C), %o3
F0041B7C: 932a6010                 sll     %o1, 16, %o1
F0041B80: 933a600f                 sra     %o1, 15, %o1
F0041B84: d012400b                 lduh    [%o1+%o3], %o0
F0041B88: 90023fff                 inc     -1, %o0
F0041B8C: d032400b                 sth     %o0, [%o1+%o3]
F0041B90: d012a30c                 lduh    [%o2+%lo(word_F0134B0C)], %o0
F0041B94: 90022001                 inc     %o0
F0041B98: d032a30c                 sth     %o0, [%o2+%lo(word_F0134B0C)]
F0041B9C: d0062004                 ld      [%i0+4], %o0
F0041BA0: 80a2207f                 cmp     %o0, 0x7F
F0041BA4: 08800004                 bleu    loc_F0041BB4
F0041BA8: c036200a                 clrh    [%i0+0xA]
F0041BAC: 7fff7217                 call    _mclput
F0041BB0: 90100018                 mov     %i0, %o0
F0041BB4: c0262004                 clr     [%i0+4]
F0041BB8: c026207c                 clr     [%i0+0x7C]
F0041BBC: 133c04d3                 sethi   %hi(_mfree), %o1
F0041BC0: 90100010                 mov     %l0, %o0
F0041BC4: d4026168                 ld      [%o1+%lo(_mfree)], %o2
F0041BC8: a0126168                 or      %o1, %lo(_mfree), %l0
F0041BCC: d4260000                 st      %o2, [%i0]
F0041BD0: 40015455                 call    _splx
F0041BD4: f0226168                 st      %i0, [%o1+%lo(_mfree)]
F0041BD8: 133c04d2                 sethi   %hi(_m_want), %o1
F0041BDC: d00262e8                 ld      [%o1+%lo(_m_want)], %o0
F0041BE0: 80a22000                 cmp     %o0, 0
F0041BE4: 02800005                 be      locret_F0041BF8
F0041BE8: 01000000                 nop
F0041BEC: c02262e8                 clr     [%o1+%lo(_m_want)]
F0041BF0: 7fff447e                 call    _wakeup
F0041BF4: 90100010                 mov     %l0, %o0
F0041BF8: 81c7e008                 ret
F0041BFC: 81e80000                 restore
