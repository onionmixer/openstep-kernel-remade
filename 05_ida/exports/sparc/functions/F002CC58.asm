F002CC58: 9de3bf90                 save    %sp, -0x70, %sp
F002CC5C: d2060000                 ld      [%i0], %o1
F002CC60: a4062004                 add     %i0, 4, %l2
F002CC64: 80a26000                 cmp     %o1, 0
F002CC68: 0280000a                 be      loc_F002CC90
F002CC6C: ec162004                 lduh    [%i0+4], %l6
F002CC70: d002602c                 ld      [%o1+0x2C], %o0
F002CC74: 80a22000                 cmp     %o0, 0
F002CC78: 02800007                 be      loc_F002CC94
F002CC7C: 80a5a010                 cmp     %l6, 0x10
F002CC80: d0126024                 lduh    [%o1+0x24], %o0
F002CC84: 808a2001                 btst    1, %o0
F002CC88: 12800065                 bne     locret_F002CE1C
F002CC8C: 01000000                 nop
F002CC90: 80a5a010                 cmp     %l6, 0x10
F002CC94: 18800062                 bgu     locret_F002CE1C
F002CC98: 90100012                 mov     %l2, %o0
F002CC9C: 9207bff0                 add     %fp, var_10, %o1
F002CCA0: a32da003                 sll     %l6, 3, %l1
F002CCA4: 213c0430a0142150         set     _afswitch, %l0
F002CCAC: d4044010                 ld      [%l1+%l0], %o2! size_t
F002CCB0: 9fc28000                 call    %o2
F002CCB4: a8102001                 mov     1, %l4
F002CCB8: a2044010                 add     %l1, %l0, %l1
F002CCBC: e607bff0                 ld      [%fp+var_10], %l3
F002CCC0: 113c04d4                 sethi   %hi(_rthost), %o0
F002CCC4: f4046004                 ld      [%l1+4], %i2
F002CCC8: 4001a7f3                 call    _splnet
F002CCCC: b2122240                 or      %o0, %lo(_rthost), %i1
F002CCD0: aa100008                 mov     %o0, %l5
F002CCD4: 900ce007                 and     %l3, 7, %o0
F002CCD8: 912a2002                 sll     %o0, 2, %o0
F002CCDC: e2064008                 ld      [%i1+%o0], %l1
F002CCE0: 80a46000                 cmp     %l1, 0
F002CCE4: 02800039                 be      loc_F002CDC8
F002CCE8: 113c04d9                 sethi   %hi(_wildcard), %o0
F002CCEC: b6122060                 or      %o0, %lo(_wildcard), %i3
F002CCF0: 113c04d4ae122280         set     _rtstat, %l7
F002CCF8: d2046004                 ld      [%l1+4], %o1
F002CCFC: d0044009                 ld      [%l1+%o1], %o0
F002CD00: 80a20013                 cmp     %o0, %l3
F002CD04: 1280002d                 bne     loc_F002CDB8
F002CD08: a0044009                 add     %l1, %o1, %l0
F002CD0C: d0142024                 lduh    [%l0+0x24], %o0
F002CD10: 808a2001                 btst    1, %o0
F002CD14: 2280002a                 be,a    loc_F002CDBC
F002CD18: e2044000                 ld      [%l1], %l1
F002CD1C: d004202c                 ld      [%l0+0x2C], %o0
F002CD20: d012200c                 lduh    [%o0+0xC], %o0
F002CD24: 808a2001                 btst    1, %o0
F002CD28: 22800025                 be,a    loc_F002CDBC
F002CD2C: e2044000                 ld      [%l1], %l1
F002CD30: 80a52000                 cmp     %l4, 0
F002CD34: 1280000e                 bne     loc_F002CD6C
F002CD38: 90042004                 add     %l0, 4, %o0
F002CD3C: d0142004                 lduh    [%l0+4], %o0
F002CD40: 80a20016                 cmp     %o0, %l6
F002CD44: 3280001e                 bne,a   loc_F002CDBC
F002CD48: e2044000                 ld      [%l1], %l1
F002CD4C: 90042004                 add     %l0, 4, %o0! void *
F002CD50: 9fc68000                 call    %i2
F002CD54: 92100012                 mov     %l2, %o1
F002CD58: 80a22000                 cmp     %o0, 0
F002CD5C: 3280000b                 bne,a   loc_F002CD88
F002CD60: d2142026                 lduh    [%l0+0x26], %o1
F002CD64: 10800016                 ba      loc_F002CDBC
F002CD68: e2044000                 ld      [%l1], %l1
F002CD6C: 92100012                 mov     %l2, %o1! void *
F002CD70: 7fff647b                 call    _bcmp
F002CD74: 94102010                 mov     0x10, %o2
F002CD78: 80a22000                 cmp     %o0, 0
F002CD7C: 32800010                 bne,a   loc_F002CDBC
F002CD80: e2044000                 ld      [%l1], %l1
F002CD84: d2142026                 lduh    [%l0+0x26], %o1
F002CD88: 90100015                 mov     %l5, %o0
F002CD8C: 92026001                 inc     %o1
F002CD90: 4001a7e5                 call    _splx
F002CD94: d2342026                 sth     %o1, [%l0+0x26]
F002CD98: 80a4801b                 cmp     %l2, %i3
F002CD9C: 32800020                 bne,a   locret_F002CE1C
F002CDA0: e0260000                 st      %l0, [%i0]
F002CDA4: d015e008                 lduh    [%l7+8], %o0
F002CDA8: 90022001                 inc     %o0
F002CDAC: d035e008                 sth     %o0, [%l7+8]
F002CDB0: 1080001b                 ba      locret_F002CE1C
F002CDB4: e0260000                 st      %l0, [%i0]
F002CDB8: e2044000                 ld      [%l1], %l1
F002CDBC: 80a46000                 cmp     %l1, 0
F002CDC0: 32bfffcf                 bne,a   loc_F002CCFC
F002CDC4: d2046004                 ld      [%l1+4], %o1
F002CDC8: 80a52000                 cmp     %l4, 0
F002CDCC: 02800006                 be      loc_F002CDE4
F002CDD0: e607bff4                 ld      [%fp+var_C], %l3
F002CDD4: a8102000                 mov     0, %l4
F002CDD8: 113c04d4                 sethi   %hi(_rtnet), %o0
F002CDDC: 10bfffbe                 ba      loc_F002CCD4
F002CDE0: b2122260                 or      %o0, %lo(_rtnet), %i1
F002CDE4: 113c04d990122060         set     _wildcard, %o0
F002CDEC: 80a48008                 cmp     %l2, %o0
F002CDF0: 02800004                 be      loc_F002CE00
F002CDF4: a4100008                 mov     %o0, %l2
F002CDF8: 10bfffb7                 ba      loc_F002CCD4
F002CDFC: a6102000                 mov     0, %l3
F002CE00: 4001a7c9                 call    _splx
F002CE04: 90100015                 mov     %l5, %o0
F002CE08: 133c04d492126280         set     _rtstat, %o1
F002CE10: d0126006                 lduh    [%o1+6], %o0
F002CE14: 90022001                 inc     %o0
F002CE18: d0326006                 sth     %o0, [%o1+6]
F002CE1C: 81c7e008                 ret
F002CE20: 81e80000                 restore
