F0027D50: 9de3be90                 save    %sp, -0x170, %sp
F0027D54: e0062010                 ld      [%i0+0x10], %l0
F0027D58: 80a42000                 cmp     %l0, 0
F0027D5C: 22800072                 be,a    locret_F0027F24
F0027D60: b0102000                 mov     0, %i0
F0027D64: d0066008                 ld      [%i1+8], %o0! __s
F0027D68: e6066014                 ld      [%i1+0x14], %l3
F0027D6C: 90200008                 neg     %o0
F0027D70: 80a4e000                 cmp     %l3, 0
F0027D74: 0280006b                 be      loc_F0027F20
F0027D78: a8023c00                 add     %o0, -0x400, %l4
F0027D7C: a2102000                 mov     0, %l1
F0027D80: 80a44014                 cmp     %l1, %l4
F0027D84: 1a800016                 bcc     loc_F0027DDC
F0027D88: a4100010                 mov     %l0, %l2
F0027D8C: 80a4a000                 cmp     %l2, 0
F0027D90: 02800065                 be      locret_F0027F24
F0027D94: b0102000                 mov     0, %i0
F0027D98: 7fff7da8                 call    _strlen
F0027D9C: 9004a020                 add     %l2, 0x20, %o0 ! ' '
F0027DA0: d037bef6                 sth     %o0, [%fp+var_10A]
F0027DA4: 912a2010                 sll     %o0, 16, %o0
F0027DA8: 91322010                 srl     %o0, 16, %o0
F0027DAC: 90022004                 inc     4, %o0
F0027DB0: 900a3ffc                 and     %o0, -4, %o0
F0027DB4: 92022008                 add     %o0, 8, %o1! __src
F0027DB8: 940c7c00                 and     %l1, -0x400, %o2
F0027DBC: 90028009                 add     %o2, %o1, %o0
F0027DC0: 80a22400                 cmp     %o0, 0x400
F0027DC4: 08800003                 bleu    loc_F0027DD0
F0027DC8: a2044009                 add     %l1, %o1, %l1
F0027DCC: a202a400                 add     %o2, 0x400, %l1
F0027DD0: 80a44014                 cmp     %l1, %l4
F0027DD4: 0abfffee                 bcs     loc_F0027D8C
F0027DD8: e404a120                 ld      [%l2+0x120], %l2
F0027DDC: 80a4a000                 cmp     %l2, 0
F0027DE0: 02800051                 be      locret_F0027F24
F0027DE4: b0102000                 mov     0, %i0
F0027DE8: ac100013                 mov     %l3, %l6
F0027DEC: 400100a1                 call    _kalloc
F0027DF0: 90100016                 mov     %l6, %o0
F0027DF4: aa100008                 mov     %o0, %l5
F0027DF8: b0100015                 mov     %l5, %i0
F0027DFC: 80a5a000                 cmp     %l6, 0
F0027E00: 02800039                 be      loc_F0027EE4
F0027E04: a2102000                 mov     0, %l1
F0027E08: ae102400                 mov     0x400, %l7
F0027E0C: 90103fff                 mov     -1, %o0! __s
F0027E10: d0260000                 st      %o0, [%i0]
F0027E14: a004a020                 add     %l2, 0x20, %l0 ! ' '
F0027E18: 7fff7d88                 call    _strlen
F0027E1C: 90100010                 mov     %l0, %o0
F0027E20: d0362006                 sth     %o0, [%i0+6]
F0027E24: 90062008                 add     %i0, 8, %o0! __dst
F0027E28: 7fff7dc0                 call    _strcpy
F0027E2C: 92100010                 mov     %l0, %o1
F0027E30: e404a120                 ld      [%l2+0x120], %l2
F0027E34: 80a4a000                 cmp     %l2, 0
F0027E38: 02800022                 be      loc_F0027EC0
F0027E3C: 9025c011                 sub     %l7, %l1, %o0! __s
F0027E40: 7fff7d7e                 call    _strlen
F0027E44: 9004a020                 add     %l2, 0x20, %o0 ! ' '
F0027E48: d037bef6                 sth     %o0, [%fp+var_10A]
F0027E4C: 912a2010                 sll     %o0, 16, %o0
F0027E50: 91322010                 srl     %o0, 16, %o0
F0027E54: 90022004                 inc     4, %o0
F0027E58: 900a3ffc                 and     %o0, -4, %o0
F0027E5C: 90020011                 add     %o0, %l1, %o0
F0027E60: d4162006                 lduh    [%i0+6], %o2
F0027E64: 90022010                 inc     0x10, %o0
F0027E68: 9202a004                 add     %o2, 4, %o1
F0027E6C: 920a7ffc                 and     %o1, -4, %o1
F0027E70: 90020009                 add     %o0, %o1, %o0
F0027E74: 80a22400                 cmp     %o0, 0x400
F0027E78: 08800005                 bleu    loc_F0027E8C
F0027E7C: 9025c011                 sub     %l7, %l1, %o0
F0027E80: d0362004                 sth     %o0, [%i0+4]
F0027E84: 1080000b                 ba      loc_F0027EB0
F0027E88: a2102000                 mov     0, %l1
F0027E8C: 9002a004                 add     %o2, 4, %o0
F0027E90: 900a3ffc                 and     %o0, -4, %o0
F0027E94: 90022008                 inc     8, %o0
F0027E98: d0362004                 sth     %o0, [%i0+4]
F0027E9C: d0162006                 lduh    [%i0+6], %o0
F0027EA0: 92046008                 add     %l1, 8, %o1
F0027EA4: 90022004                 inc     4, %o0
F0027EA8: 900a3ffc                 and     %o0, -4, %o0
F0027EAC: a2024008                 add     %o1, %o0, %l1
F0027EB0: d0162004                 lduh    [%i0+4], %o0
F0027EB4: a624c008                 sub     %l3, %o0, %l3
F0027EB8: 10800008                 ba      loc_F0027ED8
F0027EBC: a8050008                 add     %l4, %o0, %l4
F0027EC0: d0362004                 sth     %o0, [%i0+4]
F0027EC4: 912a2010                 sll     %o0, 16, %o0
F0027EC8: 91322010                 srl     %o0, 16, %o0
F0027ECC: a624c008                 sub     %l3, %o0, %l3
F0027ED0: 10800005                 ba      loc_F0027EE4
F0027ED4: a8050008                 add     %l4, %o0, %l4
F0027ED8: 80a4e000                 cmp     %l3, 0
F0027EDC: 12bfffcc                 bne     loc_F0027E0C
F0027EE0: b0060008                 add     %i0, %o0, %i0
F0027EE4: d2066014                 ld      [%i1+0x14], %o1
F0027EE8: 90100015                 mov     %l5, %o0
F0027EEC: 94102000                 mov     0, %o2
F0027EF0: 96100019                 mov     %i1, %o3
F0027EF4: 7fffa909                 call    _uiomove
F0027EF8: 92224013                 sub     %o1, %l3, %o1
F0027EFC: b0100008                 mov     %o0, %i0
F0027F00: 90100015                 mov     %l5, %o0
F0027F04: 400100a7                 call    _kfree
F0027F08: 92100016                 mov     %l6, %o1
F0027F0C: 80a62000                 cmp     %i0, 0
F0027F10: 12800005                 bne     locret_F0027F24
F0027F14: 90052400                 add     %l4, 0x400, %o0
F0027F18: 90200008                 neg     %o0
F0027F1C: d0266008                 st      %o0, [%i1+8]
F0027F20: b0102000                 mov     0, %i0
F0027F24: 81c7e008                 ret
F0027F28: 81e80000                 restore
