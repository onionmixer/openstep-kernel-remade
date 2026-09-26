F002E9CC: 9de3bf88                 save    %sp, -0x78, %sp
F002E9D0: a0102000                 mov     0, %l0
F002E9D4: 80a6e000                 cmp     %i3, 0
F002E9D8: 0280000f                 be      loc_F002EA14
F002E9DC: b010001a                 mov     %i2, %i0
F002E9E0: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F002E9E4: e0022070                 ld      [%o0+%lo(_in_ifaddr)], %l0
F002E9E8: 80a42000                 cmp     %l0, 0
F002E9EC: 0280000b                 be      loc_F002EA18
F002E9F0: 1120081a                 sethi   -0x7FDF9800, %o0
F002E9F4: d0042020                 ld      [%l0+0x20], %o0
F002E9F8: 80a2001b                 cmp     %o0, %i3
F002E9FC: 22800007                 be,a    loc_F002EA18
F002EA00: 1120081a                 sethi   -0x7FDF9800, %o0
F002EA04: e0042040                 ld      [%l0+0x40], %l0
F002EA08: 80a42000                 cmp     %l0, 0
F002EA0C: 32bffffb                 bne,a   loc_F002E9F8
F002EA10: d0042020                 ld      [%l0+0x20], %o0
F002EA14: 1120081a                 sethi   -0x7FDF9800, %o0
F002EA18: 90122113                 bset    0x113, %o0
F002EA1C: 80a64008                 cmp     %i1, %o0
F002EA20: 0280005c                 be      loc_F002EB90
F002EA24: 01000000                 nop
F002EA28: 14800009                 bg      loc_F002EA4C
F002EA2C: 1120081a                 sethi   -0x7FDF9800, %o0
F002EA30: 1120081a9012210c         set     -0x7FDF96F4, %o0
F002EA38: 80a64008                 cmp     %i1, %o0
F002EA3C: 02800016                 be      loc_F002EA94
F002EA40: 1120081a                 sethi   -0x7FDF9800, %o0
F002EA44: 1080000a                 ba      loc_F002EA6C
F002EA48: 9012210e                 bset    0x10E, %o0
F002EA4C: 90122122                 bset    0x122, %o0
F002EA50: 80a64008                 cmp     %i1, %o0
F002EA54: 02800010                 be      loc_F002EA94
F002EA58: 01000000                 nop
F002EA5C: 14800008                 bg      loc_F002EA7C
F002EA60: 1130081a                 sethi   -0x3FDF9800, %o0
F002EA64: 1120081a90122116         set     -0x7FDF96EA, %o0
F002EA6C: 80a64008                 cmp     %i1, %o0
F002EA70: 02800009                 be      loc_F002EA94
F002EA74: 80a42000                 cmp     %l0, 0
F002EA78: 3080004f                 ba,a    loc_F002EBB4
F002EA7C: 90122121                 bset    0x121, %o0
F002EA80: 80a64008                 cmp     %i1, %o0
F002EA84: 02800051                 be      loc_F002EBC8
F002EA88: 1120081a                 sethi   -0x7FDF9800, %o0
F002EA8C: 1080004a                 ba      loc_F002EBB4
F002EA90: 80a42000                 cmp     %l0, 0
F002EA94: 7fff83b6                 call    _suser
F002EA98: 01000000                 nop
F002EA9C: 80a22000                 cmp     %o0, 0
F002EAA0: 02800041                 be      loc_F002EBA4
F002EAA4: 80a6e000                 cmp     %i3, 0
F002EAA8: 12800006                 bne     loc_F002EAC0
F002EAAC: 80a42000                 cmp     %l0, 0
F002EAB0: 113c0431                 sethi   %hi(aInControl), %o0! "in_control"
F002EAB4: 7fff99af                 call    _panic
F002EAB8: 901220b0                 bset    %lo(aInControl), %o0! "in_control"
F002EABC: 80a42000                 cmp     %l0, 0
F002EAC0: 12800042                 bne     loc_F002EBC8
F002EAC4: 1120081a                 sethi   -0x7FDF9800, %o0
F002EAC8: 90102001                 mov     1, %o0
F002EACC: 7fffbbcb                 call    _m_getclr
F002EAD0: 9210200d                 mov     0xD, %o1
F002EAD4: 94920000                 orcc    %o0, %g0, %o2
F002EAD8: 12800004                 bne     loc_F002EAE8
F002EADC: 133c04d9                 sethi   -0xFEC9C00, %o1
F002EAE0: 10800140                 ba      locret_F002EFE0
F002EAE4: b0102037                 mov     0x37, %i0 ! '7'
F002EAE8: e0026070                 ld      [%o1+0x70], %l0
F002EAEC: 80a42000                 cmp     %l0, 0
F002EAF0: 2280000c                 be,a    loc_F002EB20
F002EAF4: d002a004                 ld      [%o2+4], %o0
F002EAF8: 10800003                 ba      loc_F002EB04
F002EAFC: d0042040                 ld      [%l0+0x40], %o0
F002EB00: d0042040                 ld      [%l0+0x40], %o0
F002EB04: 80a22000                 cmp     %o0, 0
F002EB08: 32bffffe                 bne,a   loc_F002EB00
F002EB0C: e0042040                 ld      [%l0+0x40], %l0
F002EB10: d002a004                 ld      [%o2+4], %o0
F002EB14: 90028008                 add     %o2, %o0, %o0
F002EB18: 10800004                 ba      loc_F002EB28
F002EB1C: d0242040                 st      %o0, [%l0+0x40]
F002EB20: 90028008                 add     %o2, %o0, %o0
F002EB24: d0226070                 st      %o0, [%o1+0x70]
F002EB28: d002a004                 ld      [%o2+4], %o0
F002EB2C: d206e018                 ld      [%i3+0x18], %o1
F002EB30: 80a26000                 cmp     %o1, 0
F002EB34: 0280000a                 be      loc_F002EB5C
F002EB38: a0028008                 add     %o2, %o0, %l0
F002EB3C: 10800003                 ba      loc_F002EB48
F002EB40: d0026024                 ld      [%o1+0x24], %o0
F002EB44: d0026024                 ld      [%o1+0x24], %o0
F002EB48: 80a22000                 cmp     %o0, 0
F002EB4C: 32bffffe                 bne,a   loc_F002EB44
F002EB50: d2026024                 ld      [%o1+0x24], %o1
F002EB54: 10800003                 ba      loc_F002EB60
F002EB58: e0226024                 st      %l0, [%o1+0x24]
F002EB5C: e026e018                 st      %l0, [%i3+0x18]
F002EB60: f6242020                 st      %i3, [%l0+0x20]
F002EB64: 90102002                 mov     2, %o0
F002EB68: d0340000                 sth     %o0, [%l0]
F002EB6C: d016e00c                 lduh    [%i3+0xC], %o0
F002EB70: 808a2008                 btst    8, %o0
F002EB74: 12800015                 bne     loc_F002EBC8
F002EB78: 1120081a                 sethi   -0x7FDF9800, %o0
F002EB7C: 133c04d9                 sethi   %hi(_in_interfaces), %o1
F002EB80: d0026098                 ld      [%o1+%lo(_in_interfaces)], %o0
F002EB84: 90022001                 inc     %o0
F002EB88: 1080000f                 ba      loc_F002EBC4
F002EB8C: d0226098                 st      %o0, [%o1+%lo(_in_interfaces)]
F002EB90: 7fff8377                 call    _suser
F002EB94: 01000000                 nop
F002EB98: 80a22000                 cmp     %o0, 0
F002EB9C: 12800006                 bne     loc_F002EBB4
F002EBA0: 80a42000                 cmp     %l0, 0
F002EBA4: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F002EBA8: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F002EBAC: 1080010d                 ba      locret_F002EFE0
F002EBB0: f04a2038                 ldsb    [%o0+0x38], %i0
F002EBB4: 12800005                 bne     loc_F002EBC8
F002EBB8: 1120081a                 sethi   -0x7FDF9800, %o0
F002EBBC: 10800109                 ba      locret_F002EFE0
F002EBC0: b0102031                 mov     0x31, %i0 ! '1'
F002EBC4: 1120081a                 sethi   -0x7FDF9800, %o0
F002EBC8: 90122122                 bset    0x122, %o0
F002EBCC: 80a64008                 cmp     %i1, %o0
F002EBD0: 228000db                 be,a    loc_F002EF3C
F002EBD4: d004203c                 ld      [%l0+0x3C], %o0
F002EBD8: 1480001a                 bg      loc_F002EC40
F002EBDC: 1130081a                 sethi   -0x3FDF9800, %o0
F002EBE0: 1120081a9012210e         set     -0x7FDF96F2, %o0
F002EBE8: 80a64008                 cmp     %i1, %o0
F002EBEC: 22800057                 be,a    loc_F002ED48
F002EBF0: d016e00c                 lduh    [%i3+0xC], %o0
F002EBF4: 14800009                 bg      loc_F002EC18
F002EBF8: 1120081a                 sethi   -0x7FDF9800, %o0
F002EBFC: 1120081a9012210c         set     -0x7FDF96F4, %o0
F002EC04: 80a64008                 cmp     %i1, %o0
F002EC08: 028000b5                 be      loc_F002EEDC
F002EC0C: 9010001b                 mov     %i3, %o0
F002EC10: 108000e8                 ba      loc_F002EFB0
F002EC14: 80a6e000                 cmp     %i3, 0
F002EC18: 90122113                 bset    0x113, %o0
F002EC1C: 80a64008                 cmp     %i1, %o0
F002EC20: 02800099                 be      loc_F002EE84
F002EC24: 1120081a                 sethi   -0x7FDF9800, %o0
F002EC28: 90122116                 bset    0x116, %o0
F002EC2C: 80a64008                 cmp     %i1, %o0
F002EC30: 228000b4                 be,a    loc_F002EF00
F002EC34: d004203c                 ld      [%l0+0x3C], %o0
F002EC38: 108000de                 ba      loc_F002EFB0
F002EC3C: 80a6e000                 cmp     %i3, 0
F002EC40: 9012210f                 bset    0x10F, %o0
F002EC44: 80a64008                 cmp     %i1, %o0
F002EC48: 22800028                 be,a    loc_F002ECE8
F002EC4C: d016e00c                 lduh    [%i3+0xC], %o0
F002EC50: 14800009                 bg      loc_F002EC74
F002EC54: 1130081a                 sethi   -0x3FDF9800, %o0
F002EC58: 1130081a9012210d         set     -0x3FDF96F3, %o0
F002EC60: 80a64008                 cmp     %i1, %o0
F002EC64: 2280000e                 be,a    loc_F002EC9C
F002EC68: d0140000                 lduh    [%l0], %o0
F002EC6C: 108000d1                 ba      loc_F002EFB0
F002EC70: 80a6e000                 cmp     %i3, 0
F002EC74: 90122112                 bset    0x112, %o0
F002EC78: 80a64008                 cmp     %i1, %o0
F002EC7C: 02800018                 be      loc_F002ECDC
F002EC80: 1130081a                 sethi   -0x3FDF9800, %o0
F002EC84: 90122115                 bset    0x115, %o0
F002EC88: 80a64008                 cmp     %i1, %o0
F002EC8C: 0280002b                 be      loc_F002ED38
F002EC90: 90102002                 mov     2, %o0
F002EC94: 108000c7                 ba      loc_F002EFB0
F002EC98: 80a6e000                 cmp     %i3, 0
F002EC9C: d0362010                 sth     %o0, [%i0+0x10]
F002ECA0: d0142002                 lduh    [%l0+2], %o0
F002ECA4: d0362012                 sth     %o0, [%i0+0x12]
F002ECA8: d0142004                 lduh    [%l0+4], %o0
F002ECAC: d0362014                 sth     %o0, [%i0+0x14]
F002ECB0: d0142006                 lduh    [%l0+6], %o0
F002ECB4: d0362016                 sth     %o0, [%i0+0x16]
F002ECB8: d0142008                 lduh    [%l0+8], %o0
F002ECBC: d0362018                 sth     %o0, [%i0+0x18]
F002ECC0: d014200a                 lduh    [%l0+0xA], %o0
F002ECC4: d036201a                 sth     %o0, [%i0+0x1A]
F002ECC8: d014200c                 lduh    [%l0+0xC], %o0
F002ECCC: d036201c                 sth     %o0, [%i0+0x1C]
F002ECD0: d014200e                 lduh    [%l0+0xE], %o0
F002ECD4: 108000c2                 ba      loc_F002EFDC
F002ECD8: d036201e                 sth     %o0, [%i0+0x1E]
F002ECDC: d016e00c                 lduh    [%i3+0xC], %o0
F002ECE0: 10800003                 ba      loc_F002ECEC
F002ECE4: 808a2002                 btst    2, %o0
F002ECE8: 808a2010                 btst    0x10, %o0
F002ECEC: 228000bd                 be,a    locret_F002EFE0
F002ECF0: b0102016                 mov     0x16, %i0
F002ECF4: d0142010                 lduh    [%l0+0x10], %o0
F002ECF8: d0362010                 sth     %o0, [%i0+0x10]
F002ECFC: d0142012                 lduh    [%l0+0x12], %o0
F002ED00: d0362012                 sth     %o0, [%i0+0x12]
F002ED04: d0142014                 lduh    [%l0+0x14], %o0
F002ED08: d0362014                 sth     %o0, [%i0+0x14]
F002ED0C: d0142016                 lduh    [%l0+0x16], %o0
F002ED10: d0362016                 sth     %o0, [%i0+0x16]
F002ED14: d0142018                 lduh    [%l0+0x18], %o0
F002ED18: d0362018                 sth     %o0, [%i0+0x18]
F002ED1C: d014201a                 lduh    [%l0+0x1A], %o0
F002ED20: d036201a                 sth     %o0, [%i0+0x1A]
F002ED24: d014201c                 lduh    [%l0+0x1C], %o0
F002ED28: d036201c                 sth     %o0, [%i0+0x1C]
F002ED2C: d014201e                 lduh    [%l0+0x1E], %o0
F002ED30: 108000ab                 ba      loc_F002EFDC
F002ED34: d036201e                 sth     %o0, [%i0+0x1E]
F002ED38: d0362010                 sth     %o0, [%i0+0x10]
F002ED3C: d0042034                 ld      [%l0+0x34], %o0
F002ED40: 108000a7                 ba      loc_F002EFDC
F002ED44: d0262014                 st      %o0, [%i0+0x14]
F002ED48: 808a2010                 btst    0x10, %o0
F002ED4C: 228000a5                 be,a    locret_F002EFE0
F002ED50: b0102016                 mov     0x16, %i0
F002ED54: d0142010                 lduh    [%l0+0x10], %o0
F002ED58: d037bfe8                 sth     %o0, [%fp+var_18]
F002ED5C: d0142012                 lduh    [%l0+0x12], %o0
F002ED60: d037bfea                 sth     %o0, [%fp+var_16]
F002ED64: d0142014                 lduh    [%l0+0x14], %o0
F002ED68: d037bfec                 sth     %o0, [%fp+var_14]
F002ED6C: d0142016                 lduh    [%l0+0x16], %o0
F002ED70: d037bfee                 sth     %o0, [%fp+var_12]
F002ED74: d0142018                 lduh    [%l0+0x18], %o0
F002ED78: d037bff0                 sth     %o0, [%fp+var_10]
F002ED7C: d014201a                 lduh    [%l0+0x1A], %o0
F002ED80: d037bff2                 sth     %o0, [%fp+var_E]
F002ED84: d014201c                 lduh    [%l0+0x1C], %o0
F002ED88: d037bff4                 sth     %o0, [%fp+var_C]
F002ED8C: d014201e                 lduh    [%l0+0x1E], %o0
F002ED90: d037bff6                 sth     %o0, [%fp+var_A]
F002ED94: d0162010                 lduh    [%i0+0x10], %o0
F002ED98: d0342010                 sth     %o0, [%l0+0x10]
F002ED9C: d0162012                 lduh    [%i0+0x12], %o0
F002EDA0: d0342012                 sth     %o0, [%l0+0x12]
F002EDA4: d0162014                 lduh    [%i0+0x14], %o0
F002EDA8: d0342014                 sth     %o0, [%l0+0x14]
F002EDAC: d0162016                 lduh    [%i0+0x16], %o0
F002EDB0: d0342016                 sth     %o0, [%l0+0x16]
F002EDB4: d0162018                 lduh    [%i0+0x18], %o0
F002EDB8: d0342018                 sth     %o0, [%l0+0x18]
F002EDBC: d016201a                 lduh    [%i0+0x1A], %o0
F002EDC0: d034201a                 sth     %o0, [%l0+0x1A]
F002EDC4: d016201c                 lduh    [%i0+0x1C], %o0
F002EDC8: d034201c                 sth     %o0, [%l0+0x1C]
F002EDCC: d016201e                 lduh    [%i0+0x1E], %o0
F002EDD0: d034201e                 sth     %o0, [%l0+0x1E]
F002EDD4: d006e038                 ld      [%i3+0x38], %o0
F002EDD8: 80a22000                 cmp     %o0, 0
F002EDDC: 02800019                 be      loc_F002EE40
F002EDE0: 9010001b                 mov     %i3, %o0
F002EDE4: 92100019                 mov     %i1, %o1
F002EDE8: 7ffff39a                 call    _if_ioctl
F002EDEC: 94100010                 mov     %l0, %o2
F002EDF0: 92920000                 orcc    %o0, %g0, %o1
F002EDF4: 02800013                 be      loc_F002EE40
F002EDF8: d017bfe8                 lduh    [%fp+var_18], %o0
F002EDFC: d0342010                 sth     %o0, [%l0+0x10]
F002EE00: d017bfea                 lduh    [%fp+var_16], %o0
F002EE04: d0342012                 sth     %o0, [%l0+0x12]
F002EE08: d017bfec                 lduh    [%fp+var_14], %o0
F002EE0C: d0342014                 sth     %o0, [%l0+0x14]
F002EE10: d017bfee                 lduh    [%fp+var_12], %o0
F002EE14: d0342016                 sth     %o0, [%l0+0x16]
F002EE18: d017bff0                 lduh    [%fp+var_10], %o0
F002EE1C: d0342018                 sth     %o0, [%l0+0x18]
F002EE20: d017bff2                 lduh    [%fp+var_E], %o0
F002EE24: d034201a                 sth     %o0, [%l0+0x1A]
F002EE28: d017bff4                 lduh    [%fp+var_C], %o0
F002EE2C: d034201c                 sth     %o0, [%l0+0x1C]
F002EE30: d017bff6                 lduh    [%fp+var_A], %o0
F002EE34: b0100009                 mov     %o1, %i0
F002EE38: 1080006a                 ba      locret_F002EFE0
F002EE3C: d034201e                 sth     %o0, [%l0+0x1E]
F002EE40: d004203c                 ld      [%l0+0x3C], %o0
F002EE44: 808a2001                 btst    1, %o0
F002EE48: 02800065                 be      loc_F002EFDC
F002EE4C: 9007bfe8                 add     %fp, var_18, %o0
F002EE50: 92100010                 mov     %l0, %o1
F002EE54: 15200c1c9412a20b         set     -0x7FCF8DF5, %o2
F002EE5C: 7ffff971                 call    _rtinit
F002EE60: 96102004                 mov     4, %o3
F002EE64: 90042010                 add     %l0, 0x10, %o0
F002EE68: 92100010                 mov     %l0, %o1
F002EE6C: 15200c1c9412a20a         set     -0x7FCF8DF6, %o2
F002EE74: 7ffff96b                 call    _rtinit
F002EE78: 96102005                 mov     5, %o3
F002EE7C: 10800059                 ba      locret_F002EFE0
F002EE80: b0102000                 mov     0, %i0
F002EE84: d016e00c                 lduh    [%i3+0xC], %o0
F002EE88: 808a2002                 btst    2, %o0
F002EE8C: 32800004                 bne,a   loc_F002EE9C
F002EE90: d0162010                 lduh    [%i0+0x10], %o0
F002EE94: 10800053                 ba      locret_F002EFE0
F002EE98: b0102016                 mov     0x16, %i0
F002EE9C: d0342010                 sth     %o0, [%l0+0x10]
F002EEA0: d0162012                 lduh    [%i0+0x12], %o0
F002EEA4: d0342012                 sth     %o0, [%l0+0x12]
F002EEA8: d0162014                 lduh    [%i0+0x14], %o0
F002EEAC: d0342014                 sth     %o0, [%l0+0x14]
F002EEB0: d0162016                 lduh    [%i0+0x16], %o0
F002EEB4: d0342016                 sth     %o0, [%l0+0x16]
F002EEB8: d0162018                 lduh    [%i0+0x18], %o0
F002EEBC: d0342018                 sth     %o0, [%l0+0x18]
F002EEC0: d016201a                 lduh    [%i0+0x1A], %o0
F002EEC4: d034201a                 sth     %o0, [%l0+0x1A]
F002EEC8: d016201c                 lduh    [%i0+0x1C], %o0
F002EECC: d034201c                 sth     %o0, [%l0+0x1C]
F002EED0: d016201e                 lduh    [%i0+0x1E], %o0
F002EED4: 10800042                 ba      loc_F002EFDC
F002EED8: d034201e                 sth     %o0, [%l0+0x1E]
F002EEDC: 92100010                 mov     %l0, %o1
F002EEE0: 94062010                 add     %i0, 0x10, %o2
F002EEE4: d812200c                 lduh    [%o0+0xC], %o4
F002EEE8: 173fffe0                 sethi   -0x8000, %o3
F002EEEC: 962b000b                 andn    %o4, %o3, %o3
F002EEF0: 4000003e                 call    _in_ifinit
F002EEF4: d632200c                 sth     %o3, [%o0+0xC]
F002EEF8: 1080003a                 ba      locret_F002EFE0
F002EEFC: b0100008                 mov     %o0, %i0
F002EF00: 900a3ff9                 and     %o0, -7, %o0
F002EF04: d024203c                 st      %o0, [%l0+0x3C]
F002EF08: d0062014                 ld      [%i0+0x14], %o0
F002EF0C: 80a22000                 cmp     %o0, 0
F002EF10: 02800033                 be      loc_F002EFDC
F002EF14: d0242034                 st      %o0, [%l0+0x34]
F002EF18: 9010001b                 mov     %i3, %o0
F002EF1C: 92102012                 mov     0x12, %o1
F002EF20: d604203c                 ld      [%l0+0x3C], %o3
F002EF24: 94102000                 mov     0, %o2
F002EF28: 9612e002                 bset    2, %o3
F002EF2C: 40000ae5                 call    _icmp_sendMaskPacket
F002EF30: d624203c                 st      %o3, [%l0+0x3C]
F002EF34: 1080002b                 ba      locret_F002EFE0
F002EF38: b0102000                 mov     0, %i0
F002EF3C: 920a3ffd                 and     %o0, -3, %o1
F002EF40: d224203c                 st      %o1, [%l0+0x3C]
F002EF44: d016e00c                 lduh    [%i3+0xC], %o0
F002EF48: 808a2001                 btst    1, %o0
F002EF4C: 02800017                 be      loc_F002EFA8
F002EF50: 90126004                 or      %o1, 4, %o0
F002EF54: d024203c                 st      %o0, [%l0+0x3C]
F002EF58: b0102000                 mov     0, %i0
F002EF5C: b2102001                 mov     1, %i1
F002EF60: 80a62005                 cmp     %i0, 5
F002EF64: 14800004                 bg      loc_F002EF74
F002EF68: 94102020                 mov     0x20, %o2 ! ' '
F002EF6C: 912e4018                 sll     %i1, %i0, %o0
F002EF70: 953a2001                 sra     %o0, 1, %o2
F002EF74: 9010001b                 mov     %i3, %o0
F002EF78: 40000ad2                 call    _icmp_sendMaskPacket
F002EF7C: 92102011                 mov     0x11, %o1
F002EF80: 92920000                 orcc    %o0, %g0, %o1
F002EF84: 32800017                 bne,a   locret_F002EFE0
F002EF88: b0100009                 mov     %o1, %i0
F002EF8C: d004203c                 ld      [%l0+0x3C], %o0
F002EF90: 808a2004                 btst    4, %o0
F002EF94: 02800012                 be      loc_F002EFDC
F002EF98: b0062001                 inc     %i0
F002EF9C: 80a62004                 cmp     %i0, 4
F002EFA0: 04bffff1                 ble     loc_F002EF64
F002EFA4: 80a62005                 cmp     %i0, 5
F002EFA8: 1080000e                 ba      locret_F002EFE0
F002EFAC: b0102032                 mov     0x32, %i0 ! '2'
F002EFB0: 0280000c                 be      locret_F002EFE0
F002EFB4: b010202d                 mov     0x2D, %i0 ! '-'
F002EFB8: d006e038                 ld      [%i3+0x38], %o0
F002EFBC: 80a22000                 cmp     %o0, 0
F002EFC0: 02800008                 be      locret_F002EFE0
F002EFC4: 9010001b                 mov     %i3, %o0
F002EFC8: 92100019                 mov     %i1, %o1
F002EFCC: 7ffff321                 call    _if_ioctl
F002EFD0: 9410001a                 mov     %i2, %o2
F002EFD4: 10800003                 ba      locret_F002EFE0
F002EFD8: b0100008                 mov     %o0, %i0
F002EFDC: b0102000                 mov     0, %i0
F002EFE0: 81c7e008                 ret
F002EFE4: 81e80000                 restore
