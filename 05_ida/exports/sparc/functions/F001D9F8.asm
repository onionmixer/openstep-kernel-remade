F001D9F8: 9de3bf98                 save    %sp, -0x68, %sp
F001D9FC: 4001e46f                 call    _spltty
F001DA00: a0100018                 mov     %i0, %l0
F001DA04: 253c04d3                 sethi   %hi(_mfree), %l2
F001DA08: f004a168                 ld      [%l2+%lo(_mfree)], %i0
F001DA0C: 80a62000                 cmp     %i0, 0
F001DA10: 02800019                 be      loc_F001DA74
F001DA14: a2100008                 mov     %o0, %l1
F001DA18: d056200a                 ldsh    [%i0+0xA], %o0
F001DA1C: 80a22000                 cmp     %o0, 0
F001DA20: 02800004                 be      loc_F001DA30
F001DA24: 113c042e                 sethi   %hi(aMget_0), %o0! "mget"
F001DA28: 7fffddd2                 call    _panic
F001DA2C: 901222c0                 bset    %lo(aMget_0), %o0! "mget"
F001DA30: f236200a                 sth     %i1, [%i0+0xA]
F001DA34: 133c04d2921262f0         set     _mbstat, %o1
F001DA3C: d012601c                 lduh    [%o1+0x1C], %o0
F001DA40: 952e6001                 sll     %i1, 1, %o2
F001DA44: 90023fff                 inc     -1, %o0
F001DA48: d032601c                 sth     %o0, [%o1+0x1C]
F001DA4C: 9202601c                 inc     0x1C, %o1
F001DA50: d0128009                 lduh    [%o2+%o1], %o0
F001DA54: 90022001                 inc     %o0
F001DA58: d0328009                 sth     %o0, [%o2+%o1]
F001DA5C: 9010200c                 mov     0xC, %o0
F001DA60: d2060000                 ld      [%i0], %o1
F001DA64: d0262004                 st      %o0, [%i0+4]
F001DA68: d224a168                 st      %o1, [%l2+0x168]
F001DA6C: 10800006                 ba      loc_F001DA84
F001DA70: c0260000                 clr     [%i0]
F001DA74: 90100010                 mov     %l0, %o0
F001DA78: 4000003d                 call    _m_more
F001DA7C: 92100019                 mov     %i1, %o1
F001DA80: b0100008                 mov     %o0, %i0
F001DA84: 4001e4a8                 call    _splx
F001DA88: 90100011                 mov     %l1, %o0
F001DA8C: 80a62000                 cmp     %i0, 0
F001DA90: 02800006                 be      loc_F001DAA8
F001DA94: 92102070                 mov     0x70, %o1 ! 'p'! size_t
F001DA98: d0062004                 ld      [%i0+4], %o0! void *
F001DA9C: 4001dcef                 call    _bzero
F001DAA0: 90060008                 add     %i0, %o0, %o0
F001DAA4: 30800002                 ba,a    locret_F001DAAC
F001DAA8: b0102000                 mov     0, %i0
F001DAAC: 81c7e008                 ret
F001DAB0: 81e80000                 restore
