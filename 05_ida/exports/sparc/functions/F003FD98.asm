F003FD98: 9de3bf08                 save    %sp, -0xF8, %sp
F003FD9C: a2100018                 mov     %i0, %l1
F003FDA0: 80a6e001                 cmp     %i3, 1
F003FDA4: 12800010                 bne     loc_F003FDE4
F003FDA8: e407a05c                 ld      [%fp+arg_5C], %l2
F003FDAC: 90100011                 mov     %l1, %o0
F003FDB0: 92100019                 mov     %i1, %o1! size_t
F003FDB4: 9410001d                 mov     %i5, %o2
F003FDB8: 96100012                 mov     %l2, %o3
F003FDBC: 98102000                 mov     0, %o4
F003FDC0: 7fffff89                 call    sub_F003FBE4
F003FDC4: 9a102000                 mov     0, %o5
F003FDC8: 80a22000                 cmp     %o0, 0
F003FDCC: 32800007                 bne,a   loc_F003FDE8
F003FDD0: c0274000                 clr     [%i5]
F003FDD4: 7fffa364                 call    _vn_rele
F003FDD8: d0074000                 ld      [%i5], %o0
F003FDDC: 10800092                 ba      locret_F0040024
F003FDE0: b0102011                 mov     0x11, %i0
F003FDE4: c0274000                 clr     [%i5]
F003FDE8: 4000a0a2                 call    _kalloc
F003FDEC: 90102068                 mov     0x68, %o0! void *
F003FDF0: b6100008                 mov     %o0, %i3
F003FDF4: 40015419                 call    _bzero
F003FDF8: 92102068                 mov     0x68, %o1 ! 'h'
F003FDFC: 9007bfb0                 add     %fp, var_50, %o0
F003FE00: 92100019                 mov     %i1, %o1
F003FE04: 7ffff378                 call    _setdiropargs
F003FE08: 94100011                 mov     %l1, %o2
F003FE0C: 7ffff37f                 call    _setdirgid
F003FE10: 90100011                 mov     %l1, %o0
F003FE14: d2068000                 ld      [%i2], %o1
F003FE18: 80a26004                 cmp     %o1, 4
F003FE1C: 12800005                 bne     loc_F003FE30
F003FE20: d036a008                 sth     %o0, [%i2+8]
F003FE24: d016a004                 lduh    [%i2+4], %o0
F003FE28: 10800007                 ba      loc_F003FE44
F003FE2C: 13000008                 sethi   0x2000, %o1
F003FE30: 80a26003                 cmp     %o1, 3
F003FE34: 12800009                 bne     loc_F003FE58
F003FE38: 80a26008                 cmp     %o1, 8
F003FE3C: d016a004                 lduh    [%i2+4], %o0
F003FE40: 13000018                 sethi   0x6000, %o1
F003FE44: 90120009                 bset    %o1, %o0
F003FE48: d256a038                 ldsh    [%i2+0x38], %o1
F003FE4C: d036a004                 sth     %o0, [%i2+4]
F003FE50: 1080000f                 ba      loc_F003FE8C
F003FE54: d226a018                 st      %o1, [%i2+0x18]
F003FE58: 12800007                 bne     loc_F003FE74
F003FE5C: 80a26006                 cmp     %o1, 6
F003FE60: 90103fff                 mov     -1, %o0
F003FE64: d026a018                 st      %o0, [%i2+0x18]
F003FE68: d016a004                 lduh    [%i2+4], %o0
F003FE6C: 10800006                 ba      loc_F003FE84
F003FE70: 13000008                 sethi   0x2000, %o1
F003FE74: 32800007                 bne,a   loc_F003FE90
F003FE78: 9010001a                 mov     %i2, %o0
F003FE7C: d016a004                 lduh    [%i2+4], %o0
F003FE80: 13000030                 sethi   0xC000, %o1
F003FE84: 90120009                 bset    %o1, %o0
F003FE88: d036a004                 sth     %o0, [%i2+4]
F003FE8C: 9010001a                 mov     %i2, %o0
F003FE90: 9207bfd4                 add     %fp, var_2C, %o1
F003FE94: 7ffff33b                 call    _vattr_to_sattr
F003FE98: a007bfb0                 add     %fp, var_50, %l0
F003FE9C: 7ffff5e2                 call    _rlock
F003FEA0: d0046030                 ld      [%l1+0x30], %o0
F003FEA4: 90100011                 mov     %l1, %o0
F003FEA8: 7fff9760                 call    _dnlc_remove
F003FEAC: 92100019                 mov     %i1, %o1
F003FEB0: 92102009                 mov     9, %o1
F003FEB4: 153c01089412a330         set     _xdr_creatargs, %o2
F003FEBC: 96100010                 mov     %l0, %o3
F003FEC0: 193c0108                 sethi   %hi(_xdr_diropres), %o4
F003FEC4: d0046024                 ld      [%l1+0x24], %o0
F003FEC8: 98132284                 bset    %lo(_xdr_diropres), %o4
F003FECC: d0022128                 ld      [%o0+0x128], %o0
F003FED0: 9a10001b                 mov     %i3, %o5
F003FED4: 7ffff228                 call    _rfscall
F003FED8: e423a05c                 st      %l2, [%sp+0xF8+var_9C]
F003FEDC: b0100008                 mov     %o0, %i0
F003FEE0: d0046030                 ld      [%l1+0x30], %o0
F003FEE4: 80a62000                 cmp     %i0, 0
F003FEE8: 1280004a                 bne     loc_F0040010
F003FEEC: c02220c0                 clr     [%o0+0xC0]
F003FEF0: f006c000                 ld      [%i3], %i0
F003FEF4: 80a62000                 cmp     %i0, 0
F003FEF8: 12800040                 bne     loc_F003FFF8
F003FEFC: 80a62046                 cmp     %i0, 0x46 ! 'F'
F003FF00: 9006e004                 add     %i3, 4, %o0
F003FF04: a006e024                 add     %i3, 0x24, %l0 ! '$'
F003FF08: d4046024                 ld      [%l1+0x24], %o2
F003FF0C: 7ffff379                 call    _makenfsnode
F003FF10: 92100010                 mov     %l0, %o1
F003FF14: 92100008                 mov     %o0, %o1
F003FF18: d2274000                 st      %o1, [%i5]
F003FF1C: d006a018                 ld      [%i2+0x18], %o0
F003FF20: 80a22000                 cmp     %o0, 0
F003FF24: 3280000a                 bne,a   loc_F003FF4C
F003FF28: 113c0435                 sethi   -0xFEF2C00, %o0
F003FF2C: d0026030                 ld      [%o1+0x30], %o0
F003FF30: c0222098                 clr     [%o0+0x98]
F003FF34: d0074000                 ld      [%i5], %o0
F003FF38: 4000b1ef                 call    _mfs_trunc
F003FF3C: 92102000                 mov     0, %o1
F003FF40: 7fff952d                 call    _binvalfree
F003FF44: d0074000                 ld      [%i5], %o0
F003FF48: 113c0435                 sethi   -0xFEF2C00, %o0
F003FF4C: d0022304                 ld      [%o0+0x304], %o0
F003FF50: 80a22000                 cmp     %o0, 0
F003FF54: 02800006                 be      loc_F003FF6C
F003FF58: 90100011                 mov     %l1, %o0
F003FF5C: 92100019                 mov     %i1, %o1
F003FF60: d4074000                 ld      [%i5], %o2
F003FF64: 7fff95fe                 call    _dnlc_enter
F003FF68: 96100012                 mov     %l2, %o3
F003FF6C: d0074000                 ld      [%i5], %o0
F003FF70: 92100010                 mov     %l0, %o1
F003FF74: f216a008                 lduh    [%i2+8], %i1
F003FF78: 7fffe6ac                 call    _nattr_to_vattr
F003FF7C: 9410001a                 mov     %i2, %o2
F003FF80: 912e6010                 sll     %i1, 16, %o0
F003FF84: d256a008                 ldsh    [%i2+8], %o1
F003FF88: 913a2010                 sra     %o0, 16, %o0
F003FF8C: 80a20009                 cmp     %o0, %o1
F003FF90: 0280000a                 be      loc_F003FFB8
F003FF94: a007bf70                 add     %fp, var_90, %l0
F003FF98: 7fffa53f                 call    _vattr_null
F003FF9C: 90100010                 mov     %l0, %o0
F003FFA0: f237bf78                 sth     %i1, [%fp+var_88]
F003FFA4: d0074000                 ld      [%i5], %o0
F003FFA8: 92100010                 mov     %l0, %o1
F003FFAC: 7ffffdeb                 call    sub_F003F758
F003FFB0: 94100012                 mov     %l2, %o2
F003FFB4: f236a008                 sth     %i1, [%i2+8]
F003FFB8: d2074000                 ld      [%i5], %o1
F003FFBC: d4026028                 ld      [%o1+0x28], %o2
F003FFC0: 9002bffd                 add     %o2, -3, %o0
F003FFC4: 80a22001                 cmp     %o0, 1
F003FFC8: 08800004                 bleu    loc_F003FFD8
F003FFCC: 80a2a008                 cmp     %o2, 8
F003FFD0: 12800010                 bne     loc_F0040010
F003FFD4: 01000000                 nop
F003FFD8: 90100009                 mov     %o1, %o0
F003FFDC: 40001cef                 call    _specvp
F003FFE0: d252202c                 ldsh    [%o0+0x2C], %o1
F003FFE4: a0100008                 mov     %o0, %l0
F003FFE8: 7fffa2df                 call    _vn_rele
F003FFEC: d0074000                 ld      [%i5], %o0
F003FFF0: 10800008                 ba      loc_F0040010
F003FFF4: e0274000                 st      %l0, [%i5]
F003FFF8: 12800006                 bne     loc_F0040010
F003FFFC: 01000000                 nop
F0040000: 7fff953f                 call    _btrash
F0040004: 90100011                 mov     %l1, %o0
F0040008: 7fffe588                 call    _nfs_invalidate_caches
F004000C: 90100011                 mov     %l1, %o0
F0040010: 7ffff5a3                 call    _runlock
F0040014: d0046030                 ld      [%l1+0x30], %o0
F0040018: 9010001b                 mov     %i3, %o0
F004001C: 4000a061                 call    _kfree
F0040020: 92102068                 mov     0x68, %o1 ! 'h'
F0040024: 81c7e008                 ret
F0040028: 81e80000                 restore
