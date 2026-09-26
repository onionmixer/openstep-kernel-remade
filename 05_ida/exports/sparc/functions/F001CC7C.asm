F001CC7C: 9de3bf98                 save    %sp, -0x68, %sp
F001CC80: a4100018                 mov     %i0, %l2
F001CC84: b0964000                 orcc    %i1, %g0, %i0
F001CC88: 14800004                 bg      loc_F001CC98
F001CC8C: 01000000                 nop
F001CC90: 10800049                 ba      locret_F001CDB4
F001CC94: b0102000                 mov     0, %i0
F001CC98: 4001e7c8                 call    _spltty
F001CC9C: ac100018                 mov     %i0, %l6
F001CCA0: e206a008                 ld      [%i2+8], %l1
F001CCA4: 80a46000                 cmp     %l1, 0
F001CCA8: 02800006                 be      loc_F001CCC0
F001CCAC: aa100008                 mov     %o0, %l5
F001CCB0: d0068000                 ld      [%i2], %o0
F001CCB4: 80a22000                 cmp     %o0, 0
F001CCB8: 16800013                 bge     loc_F001CD04
F001CCBC: 80a62000                 cmp     %i0, 0
F001CCC0: 1b3c043c                 sethi   %hi(_cfreelist), %o5
F001CCC4: e003638c                 ld      [%o5+%lo(_cfreelist)], %l0
F001CCC8: 80a42000                 cmp     %l0, 0
F001CCCC: 02800033                 be      loc_F001CD98
F001CCD0: 90042004                 add     %l0, 4, %o0! void *
F001CCD4: 92102008                 mov     8, %o1! size_t
F001CCD8: a204200c                 add     %l0, 0xC, %l1
F001CCDC: d8040000                 ld      [%l0], %o4
F001CCE0: 173c043c                 sethi   %hi(_cfreecount), %o3
F001CCE4: d402e390                 ld      [%o3+%lo(_cfreecount)], %o2
F001CCE8: d823638c                 st      %o4, [%o5+%lo(_cfreelist)]
F001CCEC: 9402bfcc                 inc     -0x34, %o2
F001CCF0: 4001e05a                 call    _bzero
F001CCF4: d422e390                 st      %o2, [%o3+%lo(_cfreecount)]
F001CCF8: c0240000                 clr     [%l0]
F001CCFC: e226a004                 st      %l1, [%i2+4]
F001CD00: 80a62000                 cmp     %i0, 0
F001CD04: 22800026                 be,a    loc_F001CD9C
F001CD08: e226a008                 st      %l1, [%i2+8]
F001CD0C: 273c043c                 sethi   -0xFEF1000, %l3
F001CD10: 333c043c                 sethi   -0xFEF1000, %i1
F001CD14: a8102040                 mov     0x40, %l4 ! '@'
F001CD18: 808c603f                 btst    0x3F, %l1 ! '?'
F001CD1C: 12800012                 bne     loc_F001CD64
F001CD20: 900c603f                 and     %l1, 0x3F, %o0
F001CD24: d004e38c                 ld      [%l3+0x38C], %o0
F001CD28: 80a22000                 cmp     %o0, 0
F001CD2C: 0280001b                 be      loc_F001CD98
F001CD30: d0247fc0                 st      %o0, [%l1-0x40]
F001CD34: a0100008                 mov     %o0, %l0
F001CD38: 90042004                 add     %l0, 4, %o0! void *
F001CD3C: 92102008                 mov     8, %o1! size_t
F001CD40: d6040000                 ld      [%l0], %o3
F001CD44: a204200c                 add     %l0, 0xC, %l1
F001CD48: d4066390                 ld      [%i1+0x390], %o2
F001CD4C: d624e38c                 st      %o3, [%l3+0x38C]
F001CD50: 9402bfcc                 inc     -0x34, %o2! size_t
F001CD54: 4001e041                 call    _bzero
F001CD58: d4266390                 st      %o2, [%i1+0x390]
F001CD5C: c0240000                 clr     [%l0]
F001CD60: 900c603f                 and     %l1, 0x3F, %o0
F001CD64: 90250008                 sub     %l4, %o0, %o0
F001CD68: 80a60008                 cmp     %i0, %o0
F001CD6C: 0a800003                 bcs     loc_F001CD78
F001CD70: a0100018                 mov     %i0, %l0
F001CD74: a0100008                 mov     %o0, %l0
F001CD78: 90100012                 mov     %l2, %o0! void *
F001CD7C: 92100011                 mov     %l1, %o1! void *
F001CD80: 4001df64                 call    _bcopy
F001CD84: 94100010                 mov     %l0, %o2
F001CD88: a4048010                 add     %l2, %l0, %l2
F001CD8C: b0a60010                 subcc   %i0, %l0, %i0
F001CD90: 12bfffe2                 bne     loc_F001CD18
F001CD94: a2044010                 add     %l1, %l0, %l1
F001CD98: e226a008                 st      %l1, [%i2+8]
F001CD9C: 90100015                 mov     %l5, %o0
F001CDA0: d2068000                 ld      [%i2], %o1
F001CDA4: 94258018                 sub     %l6, %i0, %o2
F001CDA8: 9202400a                 add     %o1, %o2, %o1
F001CDAC: 4001e7de                 call    _splx
F001CDB0: d2268000                 st      %o1, [%i2]
F001CDB4: 81c7e008                 ret
F001CDB8: 81e80000                 restore
