F001FCE8: 9de3bf98                 save    %sp, -0x68, %sp
F001FCEC: 94100019                 mov     %i1, %o2
F001FCF0: 1100003f901223ff         set     0xFFFF, %o0
F001FCF8: 80a28008                 cmp     %o2, %o0
F001FCFC: 02800010                 be      loc_F001FD3C
F001FD00: 90102001                 mov     1, %o0
F001FD04: d006200c                 ld      [%i0+0xC], %o0
F001FD08: 80a22000                 cmp     %o0, 0
F001FD0C: 22800084                 be,a    locret_F001FF1C
F001FD10: b010202a                 mov     0x2A, %i0 ! '*'
F001FD14: da022018                 ld      [%o0+0x18], %o5
F001FD18: 80a36000                 cmp     %o5, 0
F001FD1C: 0280007c                 be      loc_F001FF0C
F001FD20: 90102000                 mov     0, %o0
F001FD24: 92100018                 mov     %i0, %o1
F001FD28: 9610001a                 mov     %i2, %o3
F001FD2C: 9fc34000                 call    %o5
F001FD30: 9810001b                 mov     %i3, %o4
F001FD34: 1080007a                 ba      locret_F001FF1C
F001FD38: b0100008                 mov     %o0, %i0
F001FD3C: 7ffff708                 call    _m_get
F001FD40: 9210200a                 mov     0xA, %o1
F001FD44: 94100008                 mov     %o0, %o2
F001FD48: 90102004                 mov     4, %o0
F001FD4C: 80a6a100                 cmp     %i2, 0x100
F001FD50: 0280004d                 be      loc_F001FE84
F001FD54: d032a008                 sth     %o0, [%o2+8]
F001FD58: 80a6a100                 cmp     %i2, 0x100
F001FD5C: 3480001e                 bg,a    loc_F001FDD4
F001FD60: 11000004                 sethi   0x1000, %o0
F001FD64: 80a6a010                 cmp     %i2, 0x10
F001FD68: 22800048                 be,a    loc_F001FE88
F001FD6C: d0562002                 ldsh    [%i0+2], %o0
F001FD70: 1480000e                 bg      loc_F001FDA8
F001FD74: 80a6a040                 cmp     %i2, 0x40 ! '@'
F001FD78: 80a6a004                 cmp     %i2, 4
F001FD7C: 22800043                 be,a    loc_F001FE88
F001FD80: d0562002                 ldsh    [%i0+2], %o0
F001FD84: 14800006                 bg      loc_F001FD9C
F001FD88: 80a6a008                 cmp     %i2, 8
F001FD8C: 80a6a001                 cmp     %i2, 1
F001FD90: 2280003e                 be,a    loc_F001FE88
F001FD94: d0562002                 ldsh    [%i0+2], %o0
F001FD98: 3080005b                 ba,a    loc_F001FF04
F001FD9C: 2280003b                 be,a    loc_F001FE88
F001FDA0: d0562002                 ldsh    [%i0+2], %o0
F001FDA4: 30800058                 ba,a    loc_F001FF04
F001FDA8: 02800037                 be      loc_F001FE84
F001FDAC: 80a6a040                 cmp     %i2, 0x40 ! '@'
F001FDB0: 14800006                 bg      loc_F001FDC8
F001FDB4: 80a6a080                 cmp     %i2, 0x80
F001FDB8: 80a6a020                 cmp     %i2, 0x20 ! ' '
F001FDBC: 22800033                 be,a    loc_F001FE88
F001FDC0: d0562002                 ldsh    [%i0+2], %o0
F001FDC4: 30800050                 ba,a    loc_F001FF04
F001FDC8: 02800025                 be      loc_F001FE5C
F001FDCC: 90102008                 mov     8, %o0
F001FDD0: 3080004d                 ba,a    loc_F001FF04
F001FDD4: 90122004                 bset    4, %o0
F001FDD8: 80a68008                 cmp     %i2, %o0
F001FDDC: 22800040                 be,a    loc_F001FEDC
F001FDE0: d202a004                 ld      [%o2+4], %o1
F001FDE4: 1480000f                 bg      loc_F001FE20
F001FDE8: 11000004                 sethi   0x1000, %o0
F001FDEC: 1100000490122002         set     0x1002, %o0
F001FDF4: 80a68008                 cmp     %i2, %o0
F001FDF8: 22800033                 be,a    loc_F001FEC4
F001FDFC: d202a004                 ld      [%o2+4], %o1
F001FE00: 34800034                 bg,a    loc_F001FED0
F001FE04: d202a004                 ld      [%o2+4], %o1
F001FE08: 1100000490122001         set     0x1001, %o0
F001FE10: 80a68008                 cmp     %i2, %o0
F001FE14: 22800029                 be,a    loc_F001FEB8
F001FE18: d202a004                 ld      [%o2+4], %o1
F001FE1C: 3080003a                 ba,a    loc_F001FF04
F001FE20: 90122006                 bset    6, %o0
F001FE24: 80a68008                 cmp     %i2, %o0
F001FE28: 22800034                 be,a    loc_F001FEF8
F001FE2C: d202a004                 ld      [%o2+4], %o1
F001FE30: 0680002e                 bl      loc_F001FEE8
F001FE34: 11000004                 sethi   0x1000, %o0
F001FE38: 90122007                 bset    7, %o0
F001FE3C: 80a68008                 cmp     %i2, %o0
F001FE40: 02800019                 be      loc_F001FEA4
F001FE44: 11000004                 sethi   0x1000, %o0
F001FE48: 90122008                 bset    8, %o0
F001FE4C: 80a68008                 cmp     %i2, %o0
F001FE50: 22800012                 be,a    loc_F001FE98
F001FE54: d202a004                 ld      [%o2+4], %o1
F001FE58: 3080002b                 ba,a    loc_F001FF04
F001FE5C: d032a008                 sth     %o0, [%o2+8]
F001FE60: d0162002                 lduh    [%i0+2], %o0
F001FE64: d202a004                 ld      [%o2+4], %o1
F001FE68: 900a2080                 and     %o0, 0x80, %o0
F001FE6C: d0228009                 st      %o0, [%o2+%o1]
F001FE70: d002a004                 ld      [%o2+4], %o0
F001FE74: d2562004                 ldsh    [%i0+4], %o1
F001FE78: 90028008                 add     %o2, %o0, %o0
F001FE7C: 10800026                 ba      loc_F001FF14
F001FE80: d2222004                 st      %o1, [%o0+4]
F001FE84: d0562002                 ldsh    [%i0+2], %o0
F001FE88: d202a004                 ld      [%o2+4], %o1
F001FE8C: 900a001a                 and     %o0, %i2, %o0
F001FE90: 10800021                 ba      loc_F001FF14
F001FE94: d0228009                 st      %o0, [%o2+%o1]
F001FE98: d0560000                 ldsh    [%i0], %o0
F001FE9C: 1080001e                 ba      loc_F001FF14
F001FEA0: d0228009                 st      %o0, [%o2+%o1]
F001FEA4: d202a004                 ld      [%o2+4], %o1
F001FEA8: d0162056                 lduh    [%i0+0x56], %o0
F001FEAC: d0228009                 st      %o0, [%o2+%o1]
F001FEB0: 10800019                 ba      loc_F001FF14
F001FEB4: c0362056                 clrh    [%i0+0x56]
F001FEB8: d016203e                 lduh    [%i0+0x3E], %o0
F001FEBC: 10800016                 ba      loc_F001FF14
F001FEC0: d0228009                 st      %o0, [%o2+%o1]
F001FEC4: d0162026                 lduh    [%i0+0x26], %o0
F001FEC8: 10800013                 ba      loc_F001FF14
F001FECC: d0228009                 st      %o0, [%o2+%o1]
F001FED0: d0162044                 lduh    [%i0+0x44], %o0
F001FED4: 10800010                 ba      loc_F001FF14
F001FED8: d0228009                 st      %o0, [%o2+%o1]
F001FEDC: d016202c                 lduh    [%i0+0x2C], %o0
F001FEE0: 1080000d                 ba      loc_F001FF14
F001FEE4: d0228009                 st      %o0, [%o2+%o1]
F001FEE8: d202a004                 ld      [%o2+4], %o1
F001FEEC: d0562046                 ldsh    [%i0+0x46], %o0
F001FEF0: 10800009                 ba      loc_F001FF14
F001FEF4: d0228009                 st      %o0, [%o2+%o1]
F001FEF8: d056202e                 ldsh    [%i0+0x2E], %o0
F001FEFC: 10800006                 ba      loc_F001FF14
F001FF00: d0228009                 st      %o0, [%o2+%o1]
F001FF04: 7ffff6ec                 call    _m_free
F001FF08: 9010000a                 mov     %o2, %o0
F001FF0C: 10800004                 ba      locret_F001FF1C
F001FF10: b010202a                 mov     0x2A, %i0 ! '*'
F001FF14: d426c000                 st      %o2, [%i3]
F001FF18: b0102000                 mov     0, %i0
F001FF1C: 81c7e008                 ret
F001FF20: 81e80000                 restore
