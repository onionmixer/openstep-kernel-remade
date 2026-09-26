F0020990: 9de3bf98                 save    %sp, -0x68, %sp
F0020994: 80a66000                 cmp     %i1, 0
F0020998: 02800041                 be      locret_F0020A9C
F002099C: 01000000                 nop
F00209A0: d4566008                 ldsh    [%i1+8], %o2! size_t
F00209A4: 80a2a000                 cmp     %o2, 0
F00209A8: 12800004                 bne     loc_F00209B8
F00209AC: 80a6a000                 cmp     %i2, 0
F00209B0: 10800024                 ba      loc_F0020A40
F00209B4: 90100019                 mov     %i1, %o0
F00209B8: 22800026                 be,a    loc_F0020A50
F00209BC: d2160000                 lduh    [%i0], %o1
F00209C0: d606a004                 ld      [%i2+4], %o3
F00209C4: 80a2e07c                 cmp     %o3, 0x7C ! '|'
F00209C8: 38800022                 bgu,a   loc_F0020A50
F00209CC: d2160000                 lduh    [%i0], %o1
F00209D0: da066004                 ld      [%i1+4], %o5
F00209D4: 80a3607c                 cmp     %o5, 0x7C ! '|'
F00209D8: 3880001e                 bgu,a   loc_F0020A50
F00209DC: d2160000                 lduh    [%i0], %o1
F00209E0: d856a008                 ldsh    [%i2+8], %o4
F00209E4: 9002c00c                 add     %o3, %o4, %o0
F00209E8: 9002000a                 add     %o0, %o2, %o0
F00209EC: 80a2207c                 cmp     %o0, 0x7C ! '|'
F00209F0: 38800018                 bgu,a   loc_F0020A50
F00209F4: d2160000                 lduh    [%i0], %o1
F00209F8: d256a00a                 ldsh    [%i2+0xA], %o1
F00209FC: d056600a                 ldsh    [%i1+0xA], %o0
F0020A00: 80a24008                 cmp     %o1, %o0
F0020A04: 32800013                 bne,a   loc_F0020A50
F0020A08: d2160000                 lduh    [%i0], %o1
F0020A0C: 9006400d                 add     %i1, %o5, %o0! void *
F0020A10: 9206800b                 add     %i2, %o3, %o1! void *
F0020A14: 4001d03f                 call    _bcopy
F0020A18: 9202400c                 add     %o1, %o4, %o1
F0020A1C: d016a008                 lduh    [%i2+8], %o0
F0020A20: d2166008                 lduh    [%i1+8], %o1
F0020A24: 90020009                 add     %o0, %o1, %o0
F0020A28: d036a008                 sth     %o0, [%i2+8]
F0020A2C: d2160000                 lduh    [%i0], %o1
F0020A30: d4166008                 lduh    [%i1+8], %o2
F0020A34: 90100019                 mov     %i1, %o0
F0020A38: 9202400a                 add     %o1, %o2, %o1
F0020A3C: d2360000                 sth     %o1, [%i0]
F0020A40: 7ffff41d                 call    _m_free
F0020A44: 01000000                 nop
F0020A48: 10bfffd3                 ba      loc_F0020994
F0020A4C: b2100008                 mov     %o0, %i1
F0020A50: d0166008                 lduh    [%i1+8], %o0
F0020A54: 92024008                 add     %o1, %o0, %o1
F0020A58: d0162004                 lduh    [%i0+4], %o0
F0020A5C: d2360000                 sth     %o1, [%i0]
F0020A60: 92022080                 add     %o0, 0x80, %o1
F0020A64: d2362004                 sth     %o1, [%i0+4]
F0020A68: d0066004                 ld      [%i1+4], %o0
F0020A6C: 80a2207c                 cmp     %o0, 0x7C ! '|'
F0020A70: 08800003                 bleu    loc_F0020A7C
F0020A74: 90026400                 add     %o1, 0x400, %o0
F0020A78: d0362004                 sth     %o0, [%i0+4]
F0020A7C: 80a6a000                 cmp     %i2, 0
F0020A80: 22800003                 be,a    loc_F0020A8C
F0020A84: f226200c                 st      %i1, [%i0+0xC]
F0020A88: f2268000                 st      %i1, [%i2]
F0020A8C: b4100019                 mov     %i1, %i2
F0020A90: f2064000                 ld      [%i1], %i1
F0020A94: 10bfffc0                 ba      loc_F0020994
F0020A98: c0268000                 clr     [%i2]
F0020A9C: 81c7e008                 ret
F0020AA0: 81e80000                 restore
