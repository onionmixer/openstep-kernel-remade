F0033E48: 9de3bf98                 save    %sp, -0x68, %sp
F0033E4C: a0100018                 mov     %i0, %l0
F0033E50: b0102000                 mov     0, %i0
F0033E54: 80a6a000                 cmp     %i2, 0
F0033E58: f2066008                 ld      [%i1+8], %i1
F0033E5C: 12800043                 bne     loc_F0033F68
F0033E60: 9010001b                 mov     %i3, %o0
F0033E64: 80a42000                 cmp     %l0, 0
F0033E68: 02800018                 be      loc_F0033EC8
F0033E6C: 80a42001                 cmp     %l0, 1
F0033E70: 12800040                 bne     loc_F0033F70
F0033E74: 01000000                 nop
F0033E78: 80a22001                 cmp     %o0, 1
F0033E7C: 12800007                 bne     loc_F0033E98
F0033E80: 01000000                 nop
F0033E84: d2070000                 ld      [%i4], %o1
F0033E88: 40000044                 call    _ip_pcbopts
F0033E8C: 90066038                 add     %i1, 0x38, %o0 ! '8'
F0033E90: 10800040                 ba      locret_F0033F90
F0033E94: b0100008                 mov     %o0, %i0
F0033E98: 06800034                 bl      loc_F0033F68
F0033E9C: 80a22007                 cmp     %o0, 7
F0033EA0: 14800033                 bg      loc_F0033F6C
F0033EA4: b0102016                 mov     0x16, %i0
F0033EA8: 80a22003                 cmp     %o0, 3
F0033EAC: 06800031                 bl      loc_F0033F70
F0033EB0: 80a42001                 cmp     %l0, 1
F0033EB4: d4070000                 ld      [%i4], %o2
F0033EB8: 40000095                 call    _ip_setmoptions
F0033EBC: 9206603c                 add     %i1, 0x3C, %o1 ! '<'
F0033EC0: 1080002b                 ba      loc_F0033F6C
F0033EC4: b0100008                 mov     %o0, %i0
F0033EC8: 80a22001                 cmp     %o0, 1
F0033ECC: 2280000b                 be,a    loc_F0033EF8
F0033ED0: 90102001                 mov     1, %o0
F0033ED4: 06800025                 bl      loc_F0033F68
F0033ED8: 80a22007                 cmp     %o0, 7
F0033EDC: 14800024                 bg      loc_F0033F6C
F0033EE0: b0102016                 mov     0x16, %i0
F0033EE4: 80a22003                 cmp     %o0, 3
F0033EE8: 06800022                 bl      loc_F0033F70
F0033EEC: 80a42001                 cmp     %l0, 1
F0033EF0: 1080001a                 ba      loc_F0033F58
F0033EF4: d206603c                 ld      [%i1+0x3C], %o1
F0033EF8: 7fffa699                 call    _m_get
F0033EFC: 9210200a                 mov     0xA, %o1
F0033F00: 92100008                 mov     %o0, %o1
F0033F04: d2270000                 st      %o1, [%i4]
F0033F08: d0066038                 ld      [%i1+0x38], %o0
F0033F0C: 80a22000                 cmp     %o0, 0
F0033F10: 22800017                 be,a    loc_F0033F6C
F0033F14: c0326008                 clrh    [%o1+8]
F0033F18: d0022004                 ld      [%o0+4], %o0
F0033F1C: d0226004                 st      %o0, [%o1+4]
F0033F20: d0066038                 ld      [%i1+0x38], %o0
F0033F24: d2070000                 ld      [%i4], %o1
F0033F28: d0122008                 lduh    [%o0+8], %o0
F0033F2C: d0326008                 sth     %o0, [%o1+8]
F0033F30: d2070000                 ld      [%i4], %o1! void *
F0033F34: d0066038                 ld      [%i1+0x38], %o0
F0033F38: d4526008                 ldsh    [%o1+8], %o2! size_t
F0033F3C: d6022004                 ld      [%o0+4], %o3
F0033F40: d8026004                 ld      [%o1+4], %o4
F0033F44: 9002000b                 add     %o0, %o3, %o0! void *
F0033F48: 400182f2                 call    _bcopy
F0033F4C: 9202400c                 add     %o1, %o4, %o1
F0033F50: 10800008                 ba      loc_F0033F70
F0033F54: 80a42001                 cmp     %l0, 1
F0033F58: 400001c2                 call    _ip_getmoptions
F0033F5C: 9410001c                 mov     %i4, %o2
F0033F60: 10800003                 ba      loc_F0033F6C
F0033F64: b0100008                 mov     %o0, %i0
F0033F68: b0102016                 mov     0x16, %i0
F0033F6C: 80a42001                 cmp     %l0, 1
F0033F70: 12800008                 bne     locret_F0033F90
F0033F74: 01000000                 nop
F0033F78: d0070000                 ld      [%i4], %o0
F0033F7C: 80a22000                 cmp     %o0, 0
F0033F80: 02800004                 be      locret_F0033F90
F0033F84: 01000000                 nop
F0033F88: 7fffa6cb                 call    _m_free
F0033F8C: 01000000                 nop
F0033F90: 81c7e008                 ret
F0033F94: 81e80000                 restore
