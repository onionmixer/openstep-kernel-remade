F0034A20: 9de3bf98                 save    %sp, -0x68, %sp
F0034A24: a0100018                 mov     %i0, %l0
F0034A28: 92100019                 mov     %i1, %o1
F0034A2C: b0102000                 mov     0, %i0
F0034A30: 80a6a000                 cmp     %i2, 0
F0034A34: f4026008                 ld      [%o1+8], %i2
F0034A38: 12800046                 bne     loc_F0034B50
F0034A3C: 9010001b                 mov     %i3, %o0
F0034A40: 80a42000                 cmp     %l0, 0
F0034A44: 0280001b                 be      loc_F0034AB0
F0034A48: 80a42001                 cmp     %l0, 1
F0034A4C: 12800043                 bne     loc_F0034B58
F0034A50: 01000000                 nop
F0034A54: 80a22001                 cmp     %o0, 1
F0034A58: 12800007                 bne     loc_F0034A74
F0034A5C: 01000000                 nop
F0034A60: d2070000                 ld      [%i4], %o1
F0034A64: 7ffffd4d                 call    _ip_pcbopts
F0034A68: 9006a034                 add     %i2, 0x34, %o0 ! '4'
F0034A6C: 10800043                 ba      locret_F0034B78
F0034A70: b0100008                 mov     %o0, %i0
F0034A74: 0680000b                 bl      loc_F0034AA0
F0034A78: 80a22007                 cmp     %o0, 7
F0034A7C: 14800009                 bg      loc_F0034AA0
F0034A80: 80a22003                 cmp     %o0, 3
F0034A84: 06800007                 bl      loc_F0034AA0
F0034A88: 01000000                 nop
F0034A8C: d4070000                 ld      [%i4], %o2
F0034A90: 7ffffd9f                 call    _ip_setmoptions
F0034A94: 9206a050                 add     %i2, 0x50, %o1 ! 'P'
F0034A98: 1080002f                 ba      loc_F0034B54
F0034A9C: b0100008                 mov     %o0, %i0
F0034AA0: 400012d1                 call    _ip_mrouter_cmd
F0034AA4: d4070000                 ld      [%i4], %o2
F0034AA8: 1080002b                 ba      loc_F0034B54
F0034AAC: b0100008                 mov     %o0, %i0
F0034AB0: 80a22001                 cmp     %o0, 1
F0034AB4: 2280000b                 be,a    loc_F0034AE0
F0034AB8: 90102001                 mov     1, %o0
F0034ABC: 06800025                 bl      loc_F0034B50
F0034AC0: 80a22007                 cmp     %o0, 7
F0034AC4: 14800024                 bg      loc_F0034B54
F0034AC8: b0102016                 mov     0x16, %i0
F0034ACC: 80a22003                 cmp     %o0, 3
F0034AD0: 06800022                 bl      loc_F0034B58
F0034AD4: 80a42001                 cmp     %l0, 1
F0034AD8: 1080001a                 ba      loc_F0034B40
F0034ADC: d206a050                 ld      [%i2+0x50], %o1
F0034AE0: 7fffa39f                 call    _m_get
F0034AE4: 9210200a                 mov     0xA, %o1
F0034AE8: 92100008                 mov     %o0, %o1
F0034AEC: d2270000                 st      %o1, [%i4]
F0034AF0: d006a034                 ld      [%i2+0x34], %o0
F0034AF4: 80a22000                 cmp     %o0, 0
F0034AF8: 22800017                 be,a    loc_F0034B54
F0034AFC: c0326008                 clrh    [%o1+8]
F0034B00: d0022004                 ld      [%o0+4], %o0
F0034B04: d0226004                 st      %o0, [%o1+4]
F0034B08: d006a034                 ld      [%i2+0x34], %o0
F0034B0C: d2070000                 ld      [%i4], %o1
F0034B10: d0122008                 lduh    [%o0+8], %o0
F0034B14: d0326008                 sth     %o0, [%o1+8]
F0034B18: d2070000                 ld      [%i4], %o1! void *
F0034B1C: d006a034                 ld      [%i2+0x34], %o0
F0034B20: d4526008                 ldsh    [%o1+8], %o2! size_t
F0034B24: d6022004                 ld      [%o0+4], %o3
F0034B28: d8026004                 ld      [%o1+4], %o4
F0034B2C: 9002000b                 add     %o0, %o3, %o0! void *
F0034B30: 40017ff8                 call    _bcopy
F0034B34: 9202400c                 add     %o1, %o4, %o1
F0034B38: 10800008                 ba      loc_F0034B58
F0034B3C: 80a42001                 cmp     %l0, 1
F0034B40: 7ffffec8                 call    _ip_getmoptions
F0034B44: 9410001c                 mov     %i4, %o2
F0034B48: 10800003                 ba      loc_F0034B54
F0034B4C: b0100008                 mov     %o0, %i0
F0034B50: b0102016                 mov     0x16, %i0
F0034B54: 80a42001                 cmp     %l0, 1
F0034B58: 12800008                 bne     locret_F0034B78
F0034B5C: 01000000                 nop
F0034B60: d0070000                 ld      [%i4], %o0
F0034B64: 80a22000                 cmp     %o0, 0
F0034B68: 02800004                 be      locret_F0034B78
F0034B6C: 01000000                 nop
F0034B70: 7fffa3d1                 call    _m_free
F0034B74: 01000000                 nop
F0034B78: 81c7e008                 ret
F0034B7C: 81e80000                 restore
