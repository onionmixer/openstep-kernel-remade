F002FCC4: 9de3bf90                 save    %sp, -0x70, %sp
F002FCC8: aa07bff4                 add     %fp, var_C, %l5
F002FCCC: a4102148                 mov     0x148, %l2
F002FCD0: 353c04d3                 sethi   -0xFECB400, %i2
F002FCD4: b2102001                 mov     1, %i1
F002FCD8: 113c04d2a81222f0         set     _mbstat, %l4
F002FCE0: 2d3c04d2                 sethi   -0xFECB800, %l6
F002FCE4: 113c04d2ae122360         set     _mclrefcnt, %l7
F002FCEC: 40019bb3                 call    _spltty
F002FCF0: 01000000                 nop
F002FCF4: e206a168                 ld      [%i2+0x168], %l1
F002FCF8: 80a46000                 cmp     %l1, 0
F002FCFC: 02800015                 be      loc_F002FD50
F002FD00: a0100008                 mov     %o0, %l0
F002FD04: d054600a                 ldsh    [%l1+0xA], %o0
F002FD08: 80a22000                 cmp     %o0, 0
F002FD0C: 02800004                 be      loc_F002FD1C
F002FD10: 113c0431                 sethi   %hi(aMget_8), %o0! "mget"
F002FD14: 7fff9517                 call    _panic
F002FD18: 901220d8                 bset    %lo(aMget_8), %o0! "mget"
F002FD1C: f234600a                 sth     %i1, [%l1+0xA]
F002FD20: d015201c                 lduh    [%l4+0x1C], %o0
F002FD24: d215201e                 lduh    [%l4+0x1E], %o1
F002FD28: 90023fff                 inc     -1, %o0
F002FD2C: d035201c                 sth     %o0, [%l4+0x1C]
F002FD30: 92026001                 inc     %o1
F002FD34: d235201e                 sth     %o1, [%l4+0x1E]
F002FD38: 9010200c                 mov     0xC, %o0
F002FD3C: d2044000                 ld      [%l1], %o1
F002FD40: d0246004                 st      %o0, [%l1+4]
F002FD44: d226a168                 st      %o1, [%i2+0x168]
F002FD48: 10800006                 ba      loc_F002FD60
F002FD4C: c0244000                 clr     [%l1]
F002FD50: 90102001                 mov     1, %o0
F002FD54: 7fffb786                 call    _m_more
F002FD58: 92102001                 mov     1, %o1
F002FD5C: a2100008                 mov     %o0, %l1
F002FD60: 40019bf1                 call    _splx
F002FD64: 90100010                 mov     %l0, %o0
F002FD68: 80a4a1ff                 cmp     %l2, 0x1FF
F002FD6C: 0480002e                 ble     loc_F002FE24
F002FD70: 80a4a070                 cmp     %l2, 0x70 ! 'p'
F002FD74: 40019b91                 call    _spltty
F002FD78: 01000000                 nop
F002FD7C: d205a358                 ld      [%l6+0x358], %o1
F002FD80: 80a26000                 cmp     %o1, 0
F002FD84: 12800006                 bne     loc_F002FD9C
F002FD88: a6100008                 mov     %o0, %l3
F002FD8C: 90102001                 mov     1, %o0
F002FD90: 92102001                 mov     1, %o1
F002FD94: 7fffb663                 call    _m_clalloc
F002FD98: 94102000                 mov     0, %o2
F002FD9C: e005a358                 ld      [%l6+0x358], %l0
F002FDA0: 80a42000                 cmp     %l0, 0
F002FDA4: 0280000d                 be      loc_F002FDD8
F002FDA8: 113c04d2                 sethi   %hi(_mbutl), %o0
F002FDAC: d2022350                 ld      [%o0+%lo(_mbutl)], %o1
F002FDB0: 92240009                 sub     %l0, %o1, %o1
F002FDB4: 933a600a                 sra     %o1, 10, %o1
F002FDB8: d00a4017                 ldub    [%o1+%l7], %o0
F002FDBC: 90022001                 inc     %o0
F002FDC0: d02a4017                 stb     %o0, [%o1+%l7]
F002FDC4: d005200c                 ld      [%l4+0xC], %o0
F002FDC8: 90023fff                 inc     -1, %o0
F002FDCC: d025200c                 st      %o0, [%l4+0xC]
F002FDD0: d0040000                 ld      [%l0], %o0
F002FDD4: d025a358                 st      %o0, [%l6+0x358]
F002FDD8: 40019bd3                 call    _splx
F002FDDC: 90100013                 mov     %l3, %o0
F002FDE0: 80a42000                 cmp     %l0, 0
F002FDE4: 02800007                 be      loc_F002FE00
F002FDE8: 90240011                 sub     %l0, %l1, %o0
F002FDEC: d0246004                 st      %o0, [%l1+4]
F002FDF0: 90102400                 mov     0x400, %o0
F002FDF4: d0346008                 sth     %o0, [%l1+8]
F002FDF8: 10800004                 ba      loc_F002FE08
F002FDFC: f234600c                 sth     %i1, [%l1+0xC]
F002FE00: 90102070                 mov     0x70, %o0 ! 'p'
F002FE04: d0346008                 sth     %o0, [%l1+8]
F002FE08: d0546008                 ldsh    [%l1+8], %o0
F002FE0C: 80a22400                 cmp     %o0, 0x400
F002FE10: 12800005                 bne     loc_F002FE24
F002FE14: 80a4a070                 cmp     %l2, 0x70 ! 'p'
F002FE18: 80a4a400                 cmp     %l2, 0x400
F002FE1C: 10800003                 ba      loc_F002FE28
F002FE20: a0102400                 mov     0x400, %l0
F002FE24: a0102070                 mov     0x70, %l0 ! 'p'
F002FE28: 24800002                 ble,a   loc_F002FE30
F002FE2C: a0100012                 mov     %l2, %l0
F002FE30: 90100018                 mov     %i0, %o0! void *
F002FE34: 94100010                 mov     %l0, %o2! size_t
F002FE38: a4248010                 sub     %l2, %l0, %l2
F002FE3C: d2046004                 ld      [%l1+4], %o1! void *
F002FE40: b0060010                 add     %i0, %l0, %i0
F002FE44: 40019333                 call    _bcopy
F002FE48: 92044009                 add     %l1, %o1, %o1
F002FE4C: e0346008                 sth     %l0, [%l1+8]
F002FE50: e2254000                 st      %l1, [%l5]
F002FE54: 80a4a000                 cmp     %l2, 0
F002FE58: 14bfffa5                 bg      loc_F002FCEC
F002FE5C: aa100011                 mov     %l1, %l5
F002FE60: d007bff4                 ld      [%fp+var_C], %o0
F002FE64: d4022004                 ld      [%o0+4], %o2
F002FE68: 92102014                 mov     0x14, %o1
F002FE6C: a002000a                 add     %o0, %o2, %l0
F002FE70: 4001a406                 call    _in_cksum
F002FE74: c034200a                 clrh    [%l0+0xA]
F002FE78: d034200a                 sth     %o0, [%l0+0xA]
F002FE7C: f007bff4                 ld      [%fp+var_C], %i0
F002FE80: 81c7e008                 ret
F002FE84: 81e80000                 restore
