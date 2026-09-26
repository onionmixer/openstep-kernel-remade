F003489C: 9de3bf98                 save    %sp, -0x68, %sp
F00348A0: e0066008                 ld      [%i1+8], %l0
F00348A4: d054202e                 ldsh    [%l0+0x2E], %o0
F00348A8: 80a220ff                 cmp     %o0, 0xFF
F00348AC: 02800031                 be      loc_F0034970
F00348B0: a2102000                 mov     0, %l1
F00348B4: 80a22002                 cmp     %o0, 2
F00348B8: 0280002e                 be      loc_F0034970
F00348BC: 94100018                 mov     %i0, %o2
F00348C0: 80a2a000                 cmp     %o2, 0
F00348C4: 02800008                 be      loc_F00348E4
F00348C8: 90102000                 mov     0, %o0
F00348CC: d052a008                 ldsh    [%o2+8], %o0
F00348D0: d4028000                 ld      [%o2], %o2
F00348D4: 80a2a000                 cmp     %o2, 0
F00348D8: 12bffffd                 bne     loc_F00348CC
F00348DC: a2044008                 add     %l1, %o0, %l1
F00348E0: 90102000                 mov     0, %o0
F00348E4: 7fffa41e                 call    _m_get
F00348E8: 92102002                 mov     2, %o1
F00348EC: 94920000                 orcc    %o0, %g0, %o2
F00348F0: 12800005                 bne     loc_F0034904
F00348F4: 90102068                 mov     0x68, %o0 ! 'h'
F00348F8: 94100018                 mov     %i0, %o2
F00348FC: 10800045                 ba      loc_F0034A10
F0034900: b0102037                 mov     0x37, %i0 ! '7'
F0034904: d022a004                 st      %o0, [%o2+4]
F0034908: 90102014                 mov     0x14, %o0
F003490C: d032a008                 sth     %o0, [%o2+8]
F0034910: d002a004                 ld      [%o2+4], %o0
F0034914: f0228000                 st      %i0, [%o2]
F0034918: 96028008                 add     %o2, %o0, %o3
F003491C: c02ae001                 clrb    [%o3+1]
F0034920: c032e006                 clrh    [%o3+6]
F0034924: d014202e                 lduh    [%l0+0x2E], %o0
F0034928: d02ae009                 stb     %o0, [%o3+9]
F003492C: 90046014                 add     %l1, 0x14, %o0
F0034930: d032e002                 sth     %o0, [%o3+2]
F0034934: d014204c                 lduh    [%l0+0x4C], %o0
F0034938: 808a2001                 btst    1, %o0
F003493C: 22800008                 be,a    loc_F003495C
F0034940: c022e00c                 clr     [%o3+0xC]
F0034944: d054201c                 ldsh    [%l0+0x1C], %o0
F0034948: 80a22002                 cmp     %o0, 2
F003494C: 12800031                 bne     loc_F0034A10
F0034950: b010202f                 mov     0x2F, %i0 ! '/'
F0034954: d0042020                 ld      [%l0+0x20], %o0
F0034958: d022e00c                 st      %o0, [%o3+0xC]
F003495C: d0042010                 ld      [%l0+0x10], %o0
F0034960: d022e010                 st      %o0, [%o3+0x10]
F0034964: 901020ff                 mov     0xFF, %o0
F0034968: 10800020                 ba      loc_F00349E8
F003496C: d02ae008                 stb     %o0, [%o3+8]
F0034970: 94100018                 mov     %i0, %o2
F0034974: d002a004                 ld      [%o2+4], %o0
F0034978: 96028008                 add     %o2, %o0, %o3
F003497C: d802e00c                 ld      [%o3+0xC], %o4
F0034980: 80a32000                 cmp     %o4, 0
F0034984: 02800017                 be      loc_F00349E0
F0034988: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F003498C: d2022070                 ld      [%o0+%lo(_in_ifaddr)], %o1
F0034990: 80a26000                 cmp     %o1, 0
F0034994: 0280000e                 be      loc_F00349CC
F0034998: 90102000                 mov     0, %o0
F003499C: d0026004                 ld      [%o1+4], %o0
F00349A0: 80a2000c                 cmp     %o0, %o4
F00349A4: 02800007                 be      loc_F00349C0
F00349A8: 80a26000                 cmp     %o1, 0
F00349AC: d2026040                 ld      [%o1+0x40], %o1
F00349B0: 80a26000                 cmp     %o1, 0
F00349B4: 32bffffb                 bne,a   loc_F00349A0
F00349B8: d0026004                 ld      [%o1+4], %o0
F00349BC: 80a26000                 cmp     %o1, 0
F00349C0: 02800003                 be      loc_F00349CC
F00349C4: 90102000                 mov     0, %o0
F00349C8: d0026020                 ld      [%o1+0x20], %o0
F00349CC: 80a22000                 cmp     %o0, 0
F00349D0: 32800005                 bne,a   loc_F00349E4
F00349D4: d0042010                 ld      [%l0+0x10], %o0
F00349D8: 1080000e                 ba      loc_F0034A10
F00349DC: b0102031                 mov     0x31, %i0 ! '1'
F00349E0: d0042010                 ld      [%l0+0x10], %o0
F00349E4: d022e010                 st      %o0, [%o3+0x10]
F00349E8: d6166002                 lduh    [%i1+2], %o3
F00349EC: 9010000a                 mov     %o2, %o0
F00349F0: d2042034                 ld      [%l0+0x34], %o1
F00349F4: 94042038                 add     %l0, 0x38, %o2 ! '8'
F00349F8: d8042050                 ld      [%l0+0x50], %o4
F00349FC: 960ae010                 and     %o3, 0x10, %o3
F0034A00: 7ffffaa0                 call    _ip_output
F0034A04: 9612e022                 bset    0x22, %o3 ! '"'
F0034A08: 10800004                 ba      locret_F0034A18
F0034A0C: b0100008                 mov     %o0, %i0
F0034A10: 7fffa495                 call    _m_freem
F0034A14: 9010000a                 mov     %o2, %o0
F0034A18: 81c7e008                 ret
F0034A1C: 81e80000                 restore
