F0032E60: 9de3bf98                 save    %sp, -0x68, %sp
F0032E64: 233c0431                 sethi   %hi(_ip_nhops), %l1
F0032E68: d00463cc                 ld      [%l1+%lo(_ip_nhops)], %o0
F0032E6C: 80a22000                 cmp     %o0, 0
F0032E70: 02800007                 be      loc_F0032E8C
F0032E74: 90102000                 mov     0, %o0
F0032E78: 7fffaab9                 call    _m_get
F0032E7C: 9210200a                 mov     0xA, %o1
F0032E80: b0920000                 orcc    %o0, %g0, %i0
F0032E84: 12800004                 bne     loc_F0032E94
F0032E88: 193c04bd                 sethi   -0xFED0C00, %o4
F0032E8C: 10800020                 ba      locret_F0032F0C
F0032E90: b0102000                 mov     0, %i0
F0032E94: a0132044                 or      %o4, 0x44, %l0
F0032E98: d20463cc                 ld      [%l1+0x3CC], %o1
F0032E9C: 90100010                 mov     %l0, %o0! void *
F0032EA0: d6062004                 ld      [%i0+4], %o3
F0032EA4: 932a6002                 sll     %o1, 2, %o1
F0032EA8: 94026004                 add     %o1, 4, %o2
F0032EAC: d4362008                 sth     %o2, [%i0+8]
F0032EB0: a2024010                 add     %o1, %l0, %l1
F0032EB4: d4024010                 ld      [%o1+%l0], %o2
F0032EB8: a2047ffc                 inc     -4, %l1
F0032EBC: d426000b                 st      %o2, [%i0+%o3]
F0032EC0: 92102001                 mov     1, %o1
F0032EC4: d22b2044                 stb     %o1, [%o4+0x44]
F0032EC8: d2062004                 ld      [%i0+4], %o1
F0032ECC: 94102004                 mov     4, %o2! size_t
F0032ED0: 92060009                 add     %i0, %o1, %o1! void *
F0032ED4: 4001870f                 call    _bcopy
F0032ED8: 92026004                 inc     4, %o1
F0032EDC: a0042004                 inc     4, %l0
F0032EE0: d0062004                 ld      [%i0+4], %o0
F0032EE4: 80a44010                 cmp     %l1, %l0
F0032EE8: 90060008                 add     %i0, %o0, %o0
F0032EEC: 0a800008                 bcs     locret_F0032F0C
F0032EF0: 92022008                 add     %o0, 8, %o1
F0032EF4: d0044000                 ld      [%l1], %o0
F0032EF8: d0224000                 st      %o0, [%o1]
F0032EFC: a2047ffc                 inc     -4, %l1
F0032F00: 80a44010                 cmp     %l1, %l0
F0032F04: 1abffffc                 bcc     loc_F0032EF4
F0032F08: 92026004                 inc     4, %o1
F0032F0C: 81c7e008                 ret
F0032F10: 81e80000                 restore
