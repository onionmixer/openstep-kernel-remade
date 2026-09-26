F001EB6C: 9de3bf90                 save    %sp, -0x70, %sp
F001EB70: ba100019                 mov     %i1, %i5
F001EB74: c027bff4                 clr     [%fp+var_C]
F001EB78: a2102000                 mov     0, %l1
F001EB7C: d006200c                 ld      [%i0+0xC], %o0
F001EB80: a6102000                 mov     0, %l3
F001EB84: d012200a                 lduh    [%o0+0xA], %o0
F001EB88: 808a2001                 btst    1, %o0
F001EB8C: 02800012                 be      loc_F001EBD4
F001EB90: a8102001                 mov     1, %l4
F001EB94: d216203e                 lduh    [%i0+0x3E], %o1
F001EB98: d006a014                 ld      [%i2+0x14], %o0
F001EB9C: 80a20009                 cmp     %o0, %o1
F001EBA0: 0480000e                 ble     loc_F001EBD8
F001EBA4: 808ee004                 btst    4, %i3
F001EBA8: 10800145                 ba      locret_F001F0BC
F001EBAC: b0102028                 mov     0x28, %i0 ! '('
F001EBB0: 1080006f                 ba      loc_F001ED6C
F001EBB4: a6102020                 mov     0x20, %l3 ! ' '
F001EBB8: a6100008                 mov     %o0, %l3
F001EBBC: 1080006c                 ba      loc_F001ED6C
F001EBC0: c0362056                 clrh    [%i0+0x56]
F001EBC4: 1080006a                 ba      loc_F001ED6C
F001EBC8: a6102039                 mov     0x39, %l3 ! '9'
F001EBCC: 10800068                 ba      loc_F001ED6C
F001EBD0: a6102027                 mov     0x27, %l3 ! '''
F001EBD4: 808ee004                 btst    4, %i3
F001EBD8: 02800009                 be      loc_F001EBFC
F001EBDC: b2102000                 mov     0, %i1
F001EBE0: d0162002                 lduh    [%i0+2], %o0
F001EBE4: 808a2010                 btst    0x10, %o0
F001EBE8: 12800006                 bne     loc_F001EC00
F001EBEC: 113c04cf                 sethi   -0xFECC400, %o0
F001EBF0: d006200c                 ld      [%i0+0xC], %o0
F001EBF4: d012200a                 lduh    [%o0+0xA], %o0
F001EBF8: b20a2001                 and     %o0, 1, %i1
F001EBFC: 113c04cf                 sethi   -0xFECC400, %o0
F001EC00: d20221d8                 ld      [%o0+0x1D8], %o1
F001EC04: d00261a0                 ld      [%o1+0x1A0], %o0
F001EC08: 80a72000                 cmp     %i4, 0
F001EC0C: 90022001                 inc     %o0
F001EC10: 02800008                 be      loc_F001EC30
F001EC14: d02261a0                 st      %o0, [%o1+0x1A0]
F001EC18: 10800006                 ba      loc_F001EC30
F001EC1C: e2572008                 ldsh    [%i4+8], %l1
F001EC20: d0362050                 sth     %o0, [%i0+0x50]
F001EC24: 90062050                 add     %i0, 0x50, %o0 ! 'P'! unsigned int
F001EC28: 7fffce94                 call    _sleep
F001EC2C: 9210201a                 mov     0x1A, %o1
F001EC30: d0162050                 lduh    [%i0+0x50], %o0
F001EC34: 808a2001                 btst    1, %o0
F001EC38: 12bffffa                 bne     loc_F001EC20
F001EC3C: 90122002                 bset    2, %o0
F001EC40: d0162050                 lduh    [%i0+0x50], %o0
F001EC44: 90122001                 bset    1, %o0
F001EC48: d0362050                 sth     %o0, [%i0+0x50]
F001EC4C: 113c04d2aa1222f0         set     _mbstat, %l5
F001EC54: 4001e010                 call    _splnet
F001EC58: 01000000                 nop
F001EC5C: d6162006                 lduh    [%i0+6], %o3
F001EC60: 808ae010                 btst    0x10, %o3
F001EC64: 12bfffd3                 bne     loc_F001EBB0
F001EC68: a0100008                 mov     %o0, %l0
F001EC6C: d0162056                 lduh    [%i0+0x56], %o0
F001EC70: 80a22000                 cmp     %o0, 0
F001EC74: 12bfffd1                 bne     loc_F001EBB8
F001EC78: 808ae002                 btst    2, %o3
F001EC7C: 12800009                 bne     loc_F001ECA0
F001EC80: 808ee001                 btst    1, %i3
F001EC84: d006200c                 ld      [%i0+0xC], %o0
F001EC88: d012200a                 lduh    [%o0+0xA], %o0
F001EC8C: 808a2004                 btst    4, %o0
F001EC90: 12bfffcd                 bne     loc_F001EBC4
F001EC94: 80a76000                 cmp     %i5, 0
F001EC98: 02bfffcd                 be      loc_F001EBCC
F001EC9C: 808ee001                 btst    1, %i3
F001ECA0: 12800046                 bne     loc_F001EDB8
F001ECA4: a4102400                 mov     0x400, %l2
F001ECA8: d4162042                 lduh    [%i0+0x42], %o2
F001ECAC: d216203e                 lduh    [%i0+0x3E], %o1
F001ECB0: d816203c                 lduh    [%i0+0x3C], %o4
F001ECB4: d0162040                 lduh    [%i0+0x40], %o0
F001ECB8: a422400c                 sub     %o1, %o4, %l2
F001ECBC: 94228008                 sub     %o2, %o0, %o2
F001ECC0: 80a4800a                 cmp     %l2, %o2
F001ECC4: 34800002                 bg,a    loc_F001ECCC
F001ECC8: a410000a                 mov     %o2, %l2
F001ECCC: 80a48011                 cmp     %l2, %l1
F001ECD0: 24800016                 ble,a   loc_F001ED28
F001ECD4: d0162006                 lduh    [%i0+6], %o0
F001ECD8: d006200c                 ld      [%i0+0xC], %o0
F001ECDC: d012200a                 lduh    [%o0+0xA], %o0
F001ECE0: 808a2001                 btst    1, %o0
F001ECE4: 02800007                 be      loc_F001ED00
F001ECE8: d006a014                 ld      [%i2+0x14], %o0
F001ECEC: 90020011                 add     %o0, %l1, %o0
F001ECF0: 80a48008                 cmp     %l2, %o0
F001ECF4: 2680000d                 bl,a    loc_F001ED28
F001ECF8: d0162006                 lduh    [%i0+6], %o0
F001ECFC: d006a014                 ld      [%i2+0x14], %o0
F001ED00: 80a223ff                 cmp     %o0, 0x3FF
F001ED04: 0480002d                 ble     loc_F001EDB8
F001ED08: 80a4a3ff                 cmp     %l2, 0x3FF
F001ED0C: 1480002b                 bg      loc_F001EDB8
F001ED10: 80a323ff                 cmp     %o4, 0x3FF
F001ED14: 08800029                 bleu    loc_F001EDB8
F001ED18: 808ae100                 btst    0x100, %o3
F001ED1C: 12800027                 bne     loc_F001EDB8
F001ED20: 01000000                 nop
F001ED24: d0162006                 lduh    [%i0+6], %o0
F001ED28: 808a2100                 btst    0x100, %o0
F001ED2C: 02800014                 be      loc_F001ED7C
F001ED30: 80a52000                 cmp     %l4, 0
F001ED34: 0280000e                 be      loc_F001ED6C
F001ED38: 113c04cf                 sethi   %hi(_active_u), %o0
F001ED3C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F001ED40: d0020000                 ld      [%o0], %o0
F001ED44: d2022014                 ld      [%o0+0x14], %o1
F001ED48: 11000010                 sethi   0x4000, %o0
F001ED4C: 808a4008                 btst    %o0, %o1
F001ED50: 02800007                 be      loc_F001ED6C
F001ED54: a6102023                 mov     0x23, %l3 ! '#'
F001ED58: d216a010                 lduh    [%i2+0x10], %o1
F001ED5C: 11000008                 sethi   0x2000, %o0
F001ED60: 808a4008                 btst    %o0, %o1
F001ED64: 32800002                 bne,a   loc_F001ED6C
F001ED68: a610200b                 mov     0xB, %l3
F001ED6C: 4001dfee                 call    _splx
F001ED70: 90100010                 mov     %l0, %o0
F001ED74: 108000bb                 ba      loc_F001F060
F001ED78: d0162050                 lduh    [%i0+0x50], %o0
F001ED7C: d0162050                 lduh    [%i0+0x50], %o0
F001ED80: 900a3ffe                 and     %o0, -2, %o0
F001ED84: 808a2002                 btst    2, %o0
F001ED88: 02800006                 be      loc_F001EDA0
F001ED8C: d0362050                 sth     %o0, [%i0+0x50]
F001ED90: 900a3ffd                 and     %o0, -3, %o0
F001ED94: d0362050                 sth     %o0, [%i0+0x50]
F001ED98: 7fffd014                 call    _wakeup
F001ED9C: 90062050                 add     %i0, 0x50, %o0 ! 'P'
F001EDA0: 40000570                 call    _sbwait
F001EDA4: 9006203c                 add     %i0, 0x3C, %o0 ! '<'
F001EDA8: 4001dfdf                 call    _splx
F001EDAC: 90100010                 mov     %l0, %o0
F001EDB0: 10bfffa1                 ba      loc_F001EC34
F001EDB4: d0162050                 lduh    [%i0+0x50], %o0
F001EDB8: 4001dfdb                 call    _splx
F001EDBC: 90100010                 mov     %l0, %o0
F001EDC0: a4248011                 sub     %l2, %l1, %l2
F001EDC4: 80a4a000                 cmp     %l2, 0
F001EDC8: 0480007f                 ble     loc_F001EFC4
F001EDCC: a807bff4                 add     %fp, var_C, %l4
F001EDD0: 2d3c04d2                 sethi   -0xFECB800, %l6
F001EDD4: 113c04d2ae122360         set     _mclrefcnt, %l7
F001EDDC: 4001df77                 call    _spltty
F001EDE0: 01000000                 nop
F001EDE4: 053c04d3                 sethi   %hi(_mfree), %g2
F001EDE8: e200a168                 ld      [%g2+%lo(_mfree)], %l1
F001EDEC: 80a46000                 cmp     %l1, 0
F001EDF0: 02800017                 be      loc_F001EE4C
F001EDF4: a0100008                 mov     %o0, %l0
F001EDF8: d054600a                 ldsh    [%l1+0xA], %o0
F001EDFC: 80a22000                 cmp     %o0, 0
F001EE00: 02800004                 be      loc_F001EE10
F001EE04: 113c042f                 sethi   %hi(aMget_5), %o0! "mget"
F001EE08: 7fffd8da                 call    _panic
F001EE0C: 90122020                 bset    %lo(aMget_5), %o0! "mget"
F001EE10: 84102001                 mov     1, %g2
F001EE14: c434600a                 sth     %g2, [%l1+0xA]
F001EE18: d015601c                 lduh    [%l5+0x1C], %o0
F001EE1C: 053c04d3                 sethi   %hi(_mfree), %g2
F001EE20: d215601e                 lduh    [%l5+0x1E], %o1
F001EE24: 90023fff                 inc     -1, %o0
F001EE28: d035601c                 sth     %o0, [%l5+0x1C]
F001EE2C: 92026001                 inc     %o1
F001EE30: d235601e                 sth     %o1, [%l5+0x1E]
F001EE34: 9010200c                 mov     0xC, %o0
F001EE38: d2044000                 ld      [%l1], %o1
F001EE3C: d0246004                 st      %o0, [%l1+4]
F001EE40: d220a168                 st      %o1, [%g2+%lo(_mfree)]
F001EE44: 10800006                 ba      loc_F001EE5C
F001EE48: c0244000                 clr     [%l1]
F001EE4C: 90102001                 mov     1, %o0
F001EE50: 7ffffb47                 call    _m_more
F001EE54: 92102001                 mov     1, %o1
F001EE58: a2100008                 mov     %o0, %l1
F001EE5C: 4001dfb2                 call    _splx
F001EE60: 90100010                 mov     %l0, %o0
F001EE64: d006a014                 ld      [%i2+0x14], %o0
F001EE68: 80a221ff                 cmp     %o0, 0x1FF
F001EE6C: 04800034                 ble     loc_F001EF3C
F001EE70: 80a4a3ff                 cmp     %l2, 0x3FF
F001EE74: 04800033                 ble     loc_F001EF40
F001EE78: 80a22070                 cmp     %o0, 0x70 ! 'p'
F001EE7C: 4001df4f                 call    _spltty
F001EE80: 01000000                 nop
F001EE84: d205a358                 ld      [%l6+0x358], %o1
F001EE88: 80a26000                 cmp     %o1, 0
F001EE8C: 12800006                 bne     loc_F001EEA4
F001EE90: a6100008                 mov     %o0, %l3
F001EE94: 90102001                 mov     1, %o0
F001EE98: 92102001                 mov     1, %o1
F001EE9C: 7ffffa21                 call    _m_clalloc
F001EEA0: 94102000                 mov     0, %o2
F001EEA4: e005a358                 ld      [%l6+0x358], %l0
F001EEA8: 80a42000                 cmp     %l0, 0
F001EEAC: 0280000d                 be      loc_F001EEE0
F001EEB0: 113c04d2                 sethi   %hi(_mbutl), %o0
F001EEB4: d2022350                 ld      [%o0+%lo(_mbutl)], %o1
F001EEB8: 92240009                 sub     %l0, %o1, %o1
F001EEBC: 933a600a                 sra     %o1, 10, %o1
F001EEC0: d00a4017                 ldub    [%o1+%l7], %o0
F001EEC4: 90022001                 inc     %o0
F001EEC8: d02a4017                 stb     %o0, [%o1+%l7]
F001EECC: d005600c                 ld      [%l5+0xC], %o0
F001EED0: 90023fff                 inc     -1, %o0
F001EED4: d025600c                 st      %o0, [%l5+0xC]
F001EED8: d0040000                 ld      [%l0], %o0
F001EEDC: d025a358                 st      %o0, [%l6+0x358]
F001EEE0: 4001df91                 call    _splx
F001EEE4: 90100013                 mov     %l3, %o0
F001EEE8: 80a42000                 cmp     %l0, 0
F001EEEC: 02800008                 be      loc_F001EF0C
F001EEF0: 90240011                 sub     %l0, %l1, %o0
F001EEF4: d0246004                 st      %o0, [%l1+4]
F001EEF8: 90102400                 mov     0x400, %o0
F001EEFC: d0346008                 sth     %o0, [%l1+8]
F001EF00: 84102001                 mov     1, %g2
F001EF04: 10800004                 ba      loc_F001EF14
F001EF08: c434600c                 sth     %g2, [%l1+0xC]
F001EF0C: 90102070                 mov     0x70, %o0 ! 'p'
F001EF10: d0346008                 sth     %o0, [%l1+8]
F001EF14: d0546008                 ldsh    [%l1+8], %o0
F001EF18: 80a22400                 cmp     %o0, 0x400
F001EF1C: 12800008                 bne     loc_F001EF3C
F001EF20: d006a014                 ld      [%i2+0x14], %o0
F001EF24: 80a22400                 cmp     %o0, 0x400
F001EF28: 14800003                 bg      loc_F001EF34
F001EF2C: a0102400                 mov     0x400, %l0
F001EF30: a0100008                 mov     %o0, %l0
F001EF34: 10800012                 ba      loc_F001EF7C
F001EF38: a404bc00                 inc     -0x400, %l2
F001EF3C: 80a22070                 cmp     %o0, 0x70 ! 'p'
F001EF40: 14800007                 bg      loc_F001EF5C
F001EF44: 80a4a070                 cmp     %l2, 0x70 ! 'p'
F001EF48: 80a20012                 cmp     %o0, %l2
F001EF4C: 26800007                 bl,a    loc_F001EF68
F001EF50: d006a014                 ld      [%i2+0x14], %o0
F001EF54: 10800009                 ba      loc_F001EF78
F001EF58: a0100012                 mov     %l2, %l0
F001EF5C: 24800007                 ble,a   loc_F001EF78
F001EF60: a0100012                 mov     %l2, %l0
F001EF64: d006a014                 ld      [%i2+0x14], %o0
F001EF68: 80a22070                 cmp     %o0, 0x70 ! 'p'
F001EF6C: 14800003                 bg      loc_F001EF78
F001EF70: a0102070                 mov     0x70, %l0 ! 'p'
F001EF74: a0100008                 mov     %o0, %l0
F001EF78: a4248010                 sub     %l2, %l0, %l2
F001EF7C: 92100010                 mov     %l0, %o1
F001EF80: 94102001                 mov     1, %o2
F001EF84: d0046004                 ld      [%l1+4], %o0
F001EF88: 9610001a                 mov     %i2, %o3
F001EF8C: 7fffcce3                 call    _uiomove
F001EF90: 90044008                 add     %l1, %o0, %o0
F001EF94: a6100008                 mov     %o0, %l3
F001EF98: e0346008                 sth     %l0, [%l1+8]
F001EF9C: 80a4e000                 cmp     %l3, 0
F001EFA0: 1280002f                 bne     loc_F001F05C
F001EFA4: e2250000                 st      %l1, [%l4]
F001EFA8: d006a014                 ld      [%i2+0x14], %o0
F001EFAC: 80a22000                 cmp     %o0, 0
F001EFB0: 04800005                 ble     loc_F001EFC4
F001EFB4: a8100011                 mov     %l1, %l4
F001EFB8: 80a4a000                 cmp     %l2, 0
F001EFBC: 14bfff88                 bg      loc_F001EDDC
F001EFC0: 01000000                 nop
F001EFC4: 80a66000                 cmp     %i1, 0
F001EFC8: 02800005                 be      loc_F001EFDC
F001EFCC: 01000000                 nop
F001EFD0: d0162002                 lduh    [%i0+2], %o0
F001EFD4: 90122010                 bset    0x10, %o0
F001EFD8: d0362002                 sth     %o0, [%i0+2]
F001EFDC: 4001df2e                 call    _splnet
F001EFE0: 01000000                 nop
F001EFE4: a0100008                 mov     %o0, %l0
F001EFE8: 808ee001                 btst    1, %i3
F001EFEC: d806200c                 ld      [%i0+0xC], %o4
F001EFF0: 02800003                 be      loc_F001EFFC
F001EFF4: 92102009                 mov     9, %o1
F001EFF8: 9210200e                 mov     0xE, %o1
F001EFFC: 90100018                 mov     %i0, %o0
F001F000: da03201c                 ld      [%o4+0x1C], %o5
F001F004: 9610001d                 mov     %i5, %o3
F001F008: d407bff4                 ld      [%fp+var_C], %o2
F001F00C: 9fc34000                 call    %o5
F001F010: 9810001c                 mov     %i4, %o4
F001F014: a6100008                 mov     %o0, %l3
F001F018: 4001df43                 call    _splx
F001F01C: 90100010                 mov     %l0, %o0
F001F020: 80a66000                 cmp     %i1, 0
F001F024: 02800005                 be      loc_F001F038
F001F028: b8102000                 mov     0, %i4
F001F02C: d0162002                 lduh    [%i0+2], %o0
F001F030: 900a3fef                 and     %o0, -0x11, %o0
F001F034: d0362002                 sth     %o0, [%i0+2]
F001F038: a2102000                 mov     0, %l1
F001F03C: c027bff4                 clr     [%fp+var_C]
F001F040: 80a4e000                 cmp     %l3, 0
F001F044: 12800006                 bne     loc_F001F05C
F001F048: a8102000                 mov     0, %l4
F001F04C: d006a014                 ld      [%i2+0x14], %o0
F001F050: 80a22000                 cmp     %o0, 0
F001F054: 12bfff00                 bne     loc_F001EC54
F001F058: 01000000                 nop
F001F05C: d0162050                 lduh    [%i0+0x50], %o0
F001F060: 900a3ffe                 and     %o0, -2, %o0
F001F064: 808a2002                 btst    2, %o0
F001F068: 02800006                 be      loc_F001F080
F001F06C: d0362050                 sth     %o0, [%i0+0x50]
F001F070: 900a3ffd                 and     %o0, -3, %o0
F001F074: d0362050                 sth     %o0, [%i0+0x50]
F001F078: 7fffcf5c                 call    _wakeup
F001F07C: 90062050                 add     %i0, 0x50, %o0 ! 'P'
F001F080: d007bff4                 ld      [%fp+var_C], %o0
F001F084: 80a22000                 cmp     %o0, 0
F001F088: 02800005                 be      loc_F001F09C
F001F08C: 80a4e020                 cmp     %l3, 0x20 ! ' '
F001F090: 7ffffaf5                 call    _m_freem
F001F094: 01000000                 nop
F001F098: 80a4e020                 cmp     %l3, 0x20 ! ' '
F001F09C: 12800008                 bne     locret_F001F0BC
F001F0A0: b0100013                 mov     %l3, %i0
F001F0A4: 90102005                 mov     5, %o0
F001F0A8: 1300004092126001         set     0x10001, %o1
F001F0B0: 4001135b                 call    _exception_from_kernel
F001F0B4: 94102000                 mov     0, %o2
F001F0B8: b0100013                 mov     %l3, %i0
F001F0BC: 81c7e008                 ret
F001F0C0: 81e80000                 restore
