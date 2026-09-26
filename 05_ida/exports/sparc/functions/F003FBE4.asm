F003FBE4: 9de3bf68                 save    %sp, -0x98, %sp
F003FBE8: a2100018                 mov     %i0, %l1
F003FBEC: 90100011                 mov     %l1, %o0
F003FBF0: 9210001b                 mov     %i3, %o1
F003FBF4: 7fffe685                 call    _nfs_validate_caches
F003FBF8: 94102000                 mov     0, %o2
F003FBFC: b0920000                 orcc    %o0, %g0, %i0
F003FC00: 12800064                 bne     locret_F003FD90
F003FC04: 01000000                 nop
F003FC08: 7ffff687                 call    _rlock
F003FC0C: d0046030                 ld      [%l1+0x30], %o0
F003FC10: 90100011                 mov     %l1, %o0
F003FC14: 92100019                 mov     %i1, %o1
F003FC18: 7fff97b2                 call    _dnlc_lookup
F003FC1C: 9410001b                 mov     %i3, %o2
F003FC20: 94920000                 orcc    %o0, %g0, %o2
F003FC24: 02800011                 be      loc_F003FC68
F003FC28: d4268000                 st      %o2, [%i2]
F003FC2C: d212a006                 lduh    [%o2+6], %o1
F003FC30: 92026001                 inc     %o1
F003FC34: d232a006                 sth     %o1, [%o2+6]
F003FC38: d404601c                 ld      [%l1+0x1C], %o2
F003FC3C: 90100011                 mov     %l1, %o0
F003FC40: d602a01c                 ld      [%o2+0x1C], %o3
F003FC44: 92102040                 mov     0x40, %o1 ! '@'! size_t
F003FC48: 9fc2c000                 call    %o3
F003FC4C: 9410001b                 mov     %i3, %o2
F003FC50: b0920000                 orcc    %o0, %g0, %i0
F003FC54: 0280003c                 be      loc_F003FD44
F003FC58: 01000000                 nop
F003FC5C: 7fffa3c2                 call    _vn_rele
F003FC60: d0068000                 ld      [%i2], %o0
F003FC64: 30800049                 ba,a    loc_F003FD88
F003FC68: 4000a102                 call    _kalloc
F003FC6C: 90102068                 mov     0x68, %o0! void *
F003FC70: a4100008                 mov     %o0, %l2
F003FC74: 40015479                 call    _bzero
F003FC78: 92102068                 mov     0x68, %o1 ! 'h'
F003FC7C: a007bfd0                 add     %fp, var_30, %l0
F003FC80: 90100010                 mov     %l0, %o0
F003FC84: 92100019                 mov     %i1, %o1
F003FC88: 7ffff3d7                 call    _setdiropargs
F003FC8C: 94100011                 mov     %l1, %o2
F003FC90: 92102004                 mov     4, %o1
F003FC94: 153c01089412a208         set     _xdr_diropargs, %o2
F003FC9C: 96100010                 mov     %l0, %o3
F003FCA0: 193c0108                 sethi   %hi(_xdr_diropres), %o4
F003FCA4: d0046024                 ld      [%l1+0x24], %o0
F003FCA8: 98132284                 bset    %lo(_xdr_diropres), %o4
F003FCAC: d0022128                 ld      [%o0+0x128], %o0
F003FCB0: 9a100012                 mov     %l2, %o5
F003FCB4: 7ffff2b0                 call    _rfscall
F003FCB8: f623a05c                 st      %i3, [%sp+0x98+var_3C]
F003FCBC: b0920000                 orcc    %o0, %g0, %i0
F003FCC0: 3280001d                 bne,a   loc_F003FD34
F003FCC4: c0268000                 clr     [%i2]
F003FCC8: f0048000                 ld      [%l2], %i0
F003FCCC: 80a62046                 cmp     %i0, 0x46 ! 'F'
F003FCD0: 12800007                 bne     loc_F003FCEC
F003FCD4: 80a62000                 cmp     %i0, 0
F003FCD8: 7fff9609                 call    _btrash
F003FCDC: 90100011                 mov     %l1, %o0
F003FCE0: 7fffe652                 call    _nfs_invalidate_caches
F003FCE4: 90100011                 mov     %l1, %o0
F003FCE8: 80a62000                 cmp     %i0, 0
F003FCEC: 32800012                 bne,a   loc_F003FD34
F003FCF0: c0268000                 clr     [%i2]
F003FCF4: 9004a004                 add     %l2, 4, %o0
F003FCF8: d4046024                 ld      [%l1+0x24], %o2
F003FCFC: 7ffff3fd                 call    _makenfsnode
F003FD00: 9204a024                 add     %l2, 0x24, %o1 ! '$'
F003FD04: 94100008                 mov     %o0, %o2
F003FD08: d4268000                 st      %o2, [%i2]
F003FD0C: 113c0435                 sethi   %hi(_nfs_dnlc), %o0
F003FD10: d0022304                 ld      [%o0+%lo(_nfs_dnlc)], %o0
F003FD14: 80a22000                 cmp     %o0, 0
F003FD18: 02800007                 be      loc_F003FD34
F003FD1C: 90100011                 mov     %l1, %o0
F003FD20: 92100019                 mov     %i1, %o1
F003FD24: 7fff968e                 call    _dnlc_enter
F003FD28: 9610001b                 mov     %i3, %o3
F003FD2C: 10800003                 ba      loc_F003FD38
F003FD30: 90100012                 mov     %l2, %o0
F003FD34: 90100012                 mov     %l2, %o0
F003FD38: 4000a11a                 call    _kfree
F003FD3C: 92102068                 mov     0x68, %o1 ! 'h'
F003FD40: 80a62000                 cmp     %i0, 0
F003FD44: 12800011                 bne     loc_F003FD88
F003FD48: 01000000                 nop
F003FD4C: d2068000                 ld      [%i2], %o1
F003FD50: d4026028                 ld      [%o1+0x28], %o2
F003FD54: 9002bffd                 add     %o2, -3, %o0
F003FD58: 80a22001                 cmp     %o0, 1
F003FD5C: 08800004                 bleu    loc_F003FD6C
F003FD60: 80a2a008                 cmp     %o2, 8
F003FD64: 12800009                 bne     loc_F003FD88
F003FD68: 01000000                 nop
F003FD6C: 90100009                 mov     %o1, %o0
F003FD70: 40001d8a                 call    _specvp
F003FD74: d252202c                 ldsh    [%o0+0x2C], %o1
F003FD78: a0100008                 mov     %o0, %l0
F003FD7C: 7fffa37a                 call    _vn_rele
F003FD80: d0068000                 ld      [%i2], %o0
F003FD84: e0268000                 st      %l0, [%i2]
F003FD88: 7ffff645                 call    _runlock
F003FD8C: d0046030                 ld      [%l1+0x30], %o0
F003FD90: 81c7e008                 ret
F003FD94: 81e80000                 restore
