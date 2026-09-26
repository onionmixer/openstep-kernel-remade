F0029C5C: 9de3bf98                 save    %sp, -0x68, %sp
F0029C60: 1120091a90122120         set     -0x7FDB96E0, %o0
F0029C68: 80a64008                 cmp     %i1, %o0
F0029C6C: 02800018                 be      loc_F0029CCC
F0029C70: 01000000                 nop
F0029C74: 14800008                 bg      loc_F0029C94
F0029C78: 1130021a                 sethi   -0x3FF79800, %o0
F0029C7C: 1120091a9012211e         set     -0x7FDB96E2, %o0
F0029C84: 80a64008                 cmp     %i1, %o0
F0029C88: 02800011                 be      loc_F0029CCC
F0029C8C: 01000000                 nop
F0029C90: 30800018                 ba,a    loc_F0029CF0
F0029C94: 90122114                 bset    0x114, %o0
F0029C98: 80a64008                 cmp     %i1, %o0
F0029C9C: 02800007                 be      loc_F0029CB8
F0029CA0: 1130091a                 sethi   -0x3FDB9800, %o0
F0029CA4: 9012211f                 bset    0x11F, %o0
F0029CA8: 80a64008                 cmp     %i1, %o0
F0029CAC: 0280000d                 be      loc_F0029CE0
F0029CB0: 90100019                 mov     %i1, %o0
F0029CB4: 3080000f                 ba,a    loc_F0029CF0
F0029CB8: 90100019                 mov     %i1, %o0
F0029CBC: 400000a0                 call    _ifconf
F0029CC0: 9210001a                 mov     %i2, %o1
F0029CC4: 1080009c                 ba      locret_F0029F34
F0029CC8: b0100008                 mov     %o0, %i0
F0029CCC: 7fff9728                 call    _suser
F0029CD0: 01000000                 nop
F0029CD4: 80a22000                 cmp     %o0, 0
F0029CD8: 0280007c                 be      loc_F0029EC8
F0029CDC: 90100019                 mov     %i1, %o0
F0029CE0: 400010dc                 call    _arpioctl
F0029CE4: 9210001a                 mov     %i2, %o1
F0029CE8: 10800093                 ba      locret_F0029F34
F0029CEC: b0100008                 mov     %o0, %i0
F0029CF0: 7fffffa6                 call    _ifunit
F0029CF4: 9010001a                 mov     %i2, %o0
F0029CF8: a2920000                 orcc    %o0, %g0, %l1
F0029CFC: 12800004                 bne     loc_F0029D0C
F0029D00: a410001a                 mov     %i2, %l2
F0029D04: 1080008c                 ba      locret_F0029F34
F0029D08: b0102006                 mov     6, %i0
F0029D0C: 1120081a9012217d         set     -0x7FDF9683, %o0
F0029D14: 80a64008                 cmp     %i1, %o0
F0029D18: 22800071                 be,a    loc_F0029EDC
F0029D1C: d0046038                 ld      [%l1+0x38], %o0
F0029D20: 1480001a                 bg      loc_F0029D88
F0029D24: 1130081a                 sethi   -0x3FDF9800, %o0
F0029D28: 1120081a90122118         set     -0x7FDF96E8, %o0
F0029D30: 80a64008                 cmp     %i1, %o0
F0029D34: 02800058                 be      loc_F0029E94
F0029D38: 01000000                 nop
F0029D3C: 14800009                 bg      loc_F0029D60
F0029D40: 1120081a                 sethi   -0x7FDF9800, %o0
F0029D44: 1120081a90122110         set     -0x7FDF96F0, %o0
F0029D4C: 80a64008                 cmp     %i1, %o0
F0029D50: 0280002d                 be      loc_F0029E04
F0029D54: 01000000                 nop
F0029D58: 10800069                 ba      loc_F0029EFC
F0029D5C: d606200c                 ld      [%i0+0xC], %o3
F0029D60: 90122132                 bset    0x132, %o0
F0029D64: 80a64008                 cmp     %i1, %o0
F0029D68: 34800065                 bg,a    loc_F0029EFC
F0029D6C: d606200c                 ld      [%i0+0xC], %o3
F0029D70: 1120081a90122131         set     -0x7FDF96CF, %o0
F0029D78: 80a64008                 cmp     %i1, %o0
F0029D7C: 26800060                 bl,a    loc_F0029EFC
F0029D80: d606200c                 ld      [%i0+0xC], %o3
F0029D84: 3080004c                 ba,a    loc_F0029EB4
F0029D88: 90122117                 bset    0x117, %o0
F0029D8C: 80a64008                 cmp     %i1, %o0
F0029D90: 2280001b                 be,a    loc_F0029DFC
F0029D94: d0046010                 ld      [%l1+0x10], %o0
F0029D98: 1480000d                 bg      loc_F0029DCC
F0029D9C: 1130081a                 sethi   -0x3FDF9800, %o0
F0029DA0: 1120081a9012217f         set     -0x7FDF9681, %o0
F0029DA8: 80a64008                 cmp     %i1, %o0
F0029DAC: 0280004b                 be      loc_F0029ED8
F0029DB0: 1130081a                 sethi   -0x3FDF9800, %o0
F0029DB4: 90122111                 bset    0x111, %o0
F0029DB8: 80a64008                 cmp     %i1, %o0
F0029DBC: 2280000e                 be,a    loc_F0029DF4
F0029DC0: d014600c                 lduh    [%l1+0xC], %o0
F0029DC4: 1080004e                 ba      loc_F0029EFC
F0029DC8: d606200c                 ld      [%i0+0xC], %o3
F0029DCC: 9012217c                 bset    0x17C, %o0
F0029DD0: 80a64008                 cmp     %i1, %o0
F0029DD4: 02800041                 be      loc_F0029ED8
F0029DD8: 1130081a                 sethi   -0x3FDF9800, %o0
F0029DDC: 9012217e                 bset    0x17E, %o0
F0029DE0: 80a64008                 cmp     %i1, %o0
F0029DE4: 2280003e                 be,a    loc_F0029EDC
F0029DE8: d0046038                 ld      [%l1+0x38], %o0
F0029DEC: 10800044                 ba      loc_F0029EFC
F0029DF0: d606200c                 ld      [%i0+0xC], %o3
F0029DF4: 1080004f                 ba      loc_F0029F30
F0029DF8: d036a010                 sth     %o0, [%i2+0x10]
F0029DFC: 1080004d                 ba      loc_F0029F30
F0029E00: d026a010                 st      %o0, [%i2+0x10]
F0029E04: 7fff96da                 call    _suser
F0029E08: 01000000                 nop
F0029E0C: 80a22000                 cmp     %o0, 0
F0029E10: 0280002f                 be      loc_F0029ECC
F0029E14: 113c04cf                 sethi   -0xFECC400, %o0
F0029E18: d014600c                 lduh    [%l1+0xC], %o0
F0029E1C: 808a2001                 btst    1, %o0
F0029E20: 0280000e                 be      loc_F0029E58
F0029E24: 90100011                 mov     %l1, %o0
F0029E28: d016a010                 lduh    [%i2+0x10], %o0
F0029E2C: 808a2001                 btst    1, %o0
F0029E30: 1280000a                 bne     loc_F0029E58
F0029E34: 90100011                 mov     %l1, %o0
F0029E38: 4001b360                 call    _spltty
F0029E3C: 01000000                 nop
F0029E40: a0100008                 mov     %o0, %l0
F0029E44: 7fffff20                 call    _if_down
F0029E48: 90100011                 mov     %l1, %o0
F0029E4C: 4001b3b6                 call    _splx
F0029E50: 90100010                 mov     %l0, %o0
F0029E54: 90100011                 mov     %l1, %o0
F0029E58: 92100019                 mov     %i1, %o1
F0029E5C: 9410001a                 mov     %i2, %o2
F0029E60: 173ffff2                 sethi   -0x3800, %o3
F0029E64: da12200c                 lduh    [%o0+0xC], %o5
F0029E68: 9612e052                 bset    0x52, %o3 ! 'R'
F0029E6C: d814a010                 lduh    [%l2+0x10], %o4
F0029E70: 9a0b400b                 and     %o5, %o3, %o5
F0029E74: 1700000d9612e3ad         set     0x37AD, %o3
F0029E7C: 980b000b                 and     %o4, %o3, %o4
F0029E80: 9a13400c                 bset    %o4, %o5
F0029E84: 40000773                 call    _if_ioctl
F0029E88: da32200c                 sth     %o5, [%o0+0xC]
F0029E8C: 1080002a                 ba      locret_F0029F34
F0029E90: b0102000                 mov     0, %i0
F0029E94: 7fff96b6                 call    _suser
F0029E98: 01000000                 nop
F0029E9C: 80a22000                 cmp     %o0, 0
F0029EA0: 0280000b                 be      loc_F0029ECC
F0029EA4: 113c04cf                 sethi   -0xFECC400, %o0
F0029EA8: d006a010                 ld      [%i2+0x10], %o0
F0029EAC: 10800021                 ba      loc_F0029F30
F0029EB0: d0246010                 st      %o0, [%l1+0x10]
F0029EB4: 7fff96ae                 call    _suser
F0029EB8: 01000000                 nop
F0029EBC: 80a22000                 cmp     %o0, 0
F0029EC0: 32800007                 bne,a   loc_F0029EDC
F0029EC4: d0046038                 ld      [%l1+0x38], %o0
F0029EC8: 113c04cf                 sethi   -0xFECC400, %o0
F0029ECC: d00221dc                 ld      [%o0+0x1DC], %o0
F0029ED0: 10800019                 ba      locret_F0029F34
F0029ED4: f04a2038                 ldsb    [%o0+0x38], %i0
F0029ED8: d0046038                 ld      [%l1+0x38], %o0
F0029EDC: 80a22000                 cmp     %o0, 0
F0029EE0: 0280000a                 be      loc_F0029F08
F0029EE4: 90100011                 mov     %l1, %o0
F0029EE8: 92100019                 mov     %i1, %o1
F0029EEC: 40000759                 call    _if_ioctl
F0029EF0: 9410001a                 mov     %i2, %o2
F0029EF4: 10800010                 ba      locret_F0029F34
F0029EF8: b0100008                 mov     %o0, %i0
F0029EFC: 80a2e000                 cmp     %o3, 0
F0029F00: 12800004                 bne     loc_F0029F10
F0029F04: 90100018                 mov     %i0, %o0
F0029F08: 1080000b                 ba      locret_F0029F34
F0029F0C: b010202d                 mov     0x2D, %i0 ! '-'
F0029F10: 9210200b                 mov     0xB, %o1
F0029F14: 94100019                 mov     %i1, %o2
F0029F18: da02e01c                 ld      [%o3+0x1C], %o5
F0029F1C: 98100011                 mov     %l1, %o4
F0029F20: 9fc34000                 call    %o5
F0029F24: 9610001a                 mov     %i2, %o3
F0029F28: 10800003                 ba      locret_F0029F34
F0029F2C: b0100008                 mov     %o0, %i0
F0029F30: b0102000                 mov     0, %i0
F0029F34: 81c7e008                 ret
F0029F38: 81e80000                 restore
