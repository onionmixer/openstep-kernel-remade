F001DD44: 9de3bf90                 save    %sp, -0x70, %sp
F001DD48: 80a6a000                 cmp     %i2, 0
F001DD4C: 0280007c                 be      loc_F001DF3C
F001DD50: 80a66000                 cmp     %i1, 0
F001DD54: 06800004                 bl      loc_F001DD64
F001DD58: 80a6a000                 cmp     %i2, 0
F001DD5C: 16800006                 bge     loc_F001DD74
F001DD60: 80a66000                 cmp     %i1, 0
F001DD64: 113c042e                 sethi   %hi(aMCopy), %o0! "m_copy"
F001DD68: 7fffdd02                 call    _panic
F001DD6C: 901222e8                 bset    %lo(aMCopy), %o0! "m_copy"
F001DD70: 80a66000                 cmp     %i1, 0
F001DD74: 04800011                 ble     loc_F001DDB8
F001DD78: a407bff4                 add     %fp, var_C, %l2
F001DD7C: 213c042e                 sethi   -0xFEF4800, %l0
F001DD80: 80a62000                 cmp     %i0, 0
F001DD84: 32800005                 bne,a   loc_F001DD98
F001DD88: d0562008                 ldsh    [%i0+8], %o0! char *
F001DD8C: 7fffdcf9                 call    _panic
F001DD90: 901422f0                 or      %l0, 0x2F0, %o0
F001DD94: d0562008                 ldsh    [%i0+8], %o0
F001DD98: 80a64008                 cmp     %i1, %o0
F001DD9C: 06800007                 bl      loc_F001DDB8
F001DDA0: a407bff4                 add     %fp, var_C, %l2
F001DDA4: b2264008                 sub     %i1, %o0, %i1
F001DDA8: 80a66000                 cmp     %i1, 0
F001DDAC: 14bffff5                 bg      loc_F001DD80
F001DDB0: f0060000                 ld      [%i0], %i0
F001DDB4: a407bff4                 add     %fp, var_C, %l2
F001DDB8: 80a6a000                 cmp     %i2, 0
F001DDBC: 0480005c                 ble     loc_F001DF2C
F001DDC0: c027bff4                 clr     [%fp+var_C]
F001DDC4: 110ee6b2ac122200         set     0x3B9ACA00, %l6
F001DDCC: 2b3c04d3                 sethi   -0xFECB400, %l5
F001DDD0: 113c04d2a61222f0         set     _mbstat, %l3
F001DDD8: a804e01c                 add     %l3, 0x1C, %l4
F001DDDC: 80a62000                 cmp     %i0, 0
F001DDE0: 12800008                 bne     loc_F001DE00
F001DDE4: 80a68016                 cmp     %i2, %l6
F001DDE8: 02800051                 be      loc_F001DF2C
F001DDEC: 113c042e                 sethi   %hi(aMCopy_0), %o0! "m_copy"
F001DDF0: 7fffdce0                 call    _panic
F001DDF4: 901222f8                 bset    %lo(aMCopy_0), %o0! "m_copy"
F001DDF8: 10800052                 ba      locret_F001DF40
F001DDFC: f007bff4                 ld      [%fp+var_C], %i0
F001DE00: 4001e36e                 call    _spltty
F001DE04: 01000000                 nop
F001DE08: e0056168                 ld      [%l5+0x168], %l0
F001DE0C: 80a42000                 cmp     %l0, 0
F001DE10: 02800018                 be      loc_F001DE70
F001DE14: a2100008                 mov     %o0, %l1
F001DE18: d054200a                 ldsh    [%l0+0xA], %o0
F001DE1C: 80a22000                 cmp     %o0, 0
F001DE20: 02800004                 be      loc_F001DE30
F001DE24: 113c042e                 sethi   %hi(aMget_2), %o0! "mget"
F001DE28: 7fffdcd2                 call    _panic
F001DE2C: 90122300                 bset    %lo(aMget_2), %o0! "mget"
F001DE30: d016200a                 lduh    [%i0+0xA], %o0
F001DE34: d034200a                 sth     %o0, [%l0+0xA]
F001DE38: d014e01c                 lduh    [%l3+0x1C], %o0
F001DE3C: 90023fff                 inc     -1, %o0
F001DE40: d034e01c                 sth     %o0, [%l3+0x1C]
F001DE44: d256200a                 ldsh    [%i0+0xA], %o1
F001DE48: 932a6001                 sll     %o1, 1, %o1
F001DE4C: d0124014                 lduh    [%o1+%l4], %o0
F001DE50: 90022001                 inc     %o0
F001DE54: d0324014                 sth     %o0, [%o1+%l4]
F001DE58: 9010200c                 mov     0xC, %o0
F001DE5C: d2040000                 ld      [%l0], %o1
F001DE60: d0242004                 st      %o0, [%l0+4]
F001DE64: d2256168                 st      %o1, [%l5+0x168]
F001DE68: 10800006                 ba      loc_F001DE80
F001DE6C: c0240000                 clr     [%l0]
F001DE70: d256200a                 ldsh    [%i0+0xA], %o1
F001DE74: 7fffff3e                 call    _m_more
F001DE78: 90102000                 mov     0, %o0
F001DE7C: a0100008                 mov     %o0, %l0
F001DE80: 4001e3a9                 call    _splx
F001DE84: 90100011                 mov     %l1, %o0
F001DE88: 80a42000                 cmp     %l0, 0
F001DE8C: 0280002a                 be      loc_F001DF34
F001DE90: e0248000                 st      %l0, [%l2]
F001DE94: d0562008                 ldsh    [%i0+8], %o0
F001DE98: 90220019                 sub     %o0, %i1, %o0
F001DE9C: 80a68008                 cmp     %i2, %o0
F001DEA0: 04800003                 ble     loc_F001DEAC
F001DEA4: 9210001a                 mov     %i2, %o1
F001DEA8: 92100008                 mov     %o0, %o1
F001DEAC: d2342008                 sth     %o1, [%l0+8]
F001DEB0: d0062004                 ld      [%i0+4], %o0
F001DEB4: 80a2207c                 cmp     %o0, 0x7C ! '|'
F001DEB8: 0880000d                 bleu    loc_F001DEEC
F001DEBC: 912a6010                 sll     %o1, 16, %o0
F001DEC0: 913a2010                 sra     %o0, 16, %o0
F001DEC4: 80a22070                 cmp     %o0, 0x70 ! 'p'
F001DEC8: 04800009                 ble     loc_F001DEEC
F001DECC: 90100018                 mov     %i0, %o0
F001DED0: 92100010                 mov     %l0, %o1
F001DED4: 4000017c                 call    _mcldup
F001DED8: 94100019                 mov     %i1, %o2
F001DEDC: d0042004                 ld      [%l0+4], %o0
F001DEE0: 90020019                 add     %o0, %i1, %o0
F001DEE4: 10800009                 ba      loc_F001DF08
F001DEE8: d0242004                 st      %o0, [%l0+4]
F001DEEC: d0062004                 ld      [%i0+4], %o0
F001DEF0: d4542008                 ldsh    [%l0+8], %o2! size_t
F001DEF4: d2042004                 ld      [%l0+4], %o1! void *
F001DEF8: 90060008                 add     %i0, %o0, %o0
F001DEFC: 90020019                 add     %o0, %i1, %o0! void *
F001DF00: 4001db04                 call    _bcopy
F001DF04: 92040009                 add     %l0, %o1, %o1
F001DF08: 80a68016                 cmp     %i2, %l6
F001DF0C: 02800004                 be      loc_F001DF1C
F001DF10: b2102000                 mov     0, %i1
F001DF14: d0542008                 ldsh    [%l0+8], %o0
F001DF18: b4268008                 sub     %i2, %o0, %i2
F001DF1C: f0060000                 ld      [%i0], %i0
F001DF20: 80a6a000                 cmp     %i2, 0
F001DF24: 14bfffae                 bg      loc_F001DDDC
F001DF28: a4100010                 mov     %l0, %l2
F001DF2C: 10800005                 ba      locret_F001DF40
F001DF30: f007bff4                 ld      [%fp+var_C], %i0
F001DF34: 7fffff4c                 call    _m_freem
F001DF38: d007bff4                 ld      [%fp+var_C], %o0
F001DF3C: b0102000                 mov     0, %i0
F001DF40: 81c7e008                 ret
F001DF44: 81e80000                 restore
