F003898C: 9de3bf98                 save    %sp, -0x68, %sp
F0038990: a0964000                 orcc    %i1, %g0, %l0
F0038994: 02800007                 be      loc_F00389B0
F0038998: a2102000                 mov     0, %l1
F003899C: d0542008                 ldsh    [%l0+8], %o0
F00389A0: e0040000                 ld      [%l0], %l0
F00389A4: 80a42000                 cmp     %l0, 0
F00389A8: 12bffffd                 bne     loc_F003899C
F00389AC: a2044008                 add     %l1, %o0, %l1
F00389B0: 40017882                 call    _spltty
F00389B4: 273c04d3                 sethi   %hi(_mfree), %l3
F00389B8: e004e168                 ld      [%l3+%lo(_mfree)], %l0
F00389BC: 80a42000                 cmp     %l0, 0
F00389C0: 02800018                 be      loc_F0038A20
F00389C4: a4100008                 mov     %o0, %l2
F00389C8: d054200a                 ldsh    [%l0+0xA], %o0
F00389CC: 80a22000                 cmp     %o0, 0
F00389D0: 02800004                 be      loc_F00389E0
F00389D4: 113c0432                 sethi   %hi(aMget_12), %o0! "mget"
F00389D8: 7fff71e6                 call    _panic
F00389DC: 90122188                 bset    %lo(aMget_12), %o0! "mget"
F00389E0: 90102002                 mov     2, %o0
F00389E4: d034200a                 sth     %o0, [%l0+0xA]
F00389E8: 153c04d29412a2f0         set     _mbstat, %o2
F00389F0: d012a01c                 lduh    [%o2+0x1C], %o0
F00389F4: d212a020                 lduh    [%o2+0x20], %o1
F00389F8: 90023fff                 inc     -1, %o0
F00389FC: d032a01c                 sth     %o0, [%o2+0x1C]
F0038A00: 92026001                 inc     %o1
F0038A04: d232a020                 sth     %o1, [%o2+0x20]
F0038A08: 9010200c                 mov     0xC, %o0
F0038A0C: d2040000                 ld      [%l0], %o1
F0038A10: d0242004                 st      %o0, [%l0+4]
F0038A14: d224e168                 st      %o1, [%l3+0x168]
F0038A18: 10800006                 ba      loc_F0038A30
F0038A1C: c0240000                 clr     [%l0]
F0038A20: 90102000                 mov     0, %o0
F0038A24: 7fff9452                 call    _m_more
F0038A28: 92102002                 mov     2, %o1
F0038A2C: a0100008                 mov     %o0, %l0
F0038A30: 400178bd                 call    _splx
F0038A34: 90100012                 mov     %l2, %o0
F0038A38: 80a42000                 cmp     %l0, 0
F0038A3C: 12800006                 bne     loc_F0038A54
F0038A40: 90102060                 mov     0x60, %o0 ! '`'
F0038A44: 7fff9488                 call    _m_freem
F0038A48: 90100019                 mov     %i1, %o0
F0038A4C: 10800037                 ba      locret_F0038B28
F0038A50: b0102037                 mov     0x37, %i0 ! '7'
F0038A54: d0242004                 st      %o0, [%l0+4]
F0038A58: 9010201c                 mov     0x1C, %o0
F0038A5C: d0342008                 sth     %o0, [%l0+8]
F0038A60: d0042004                 ld      [%l0+4], %o0
F0038A64: f2240000                 st      %i1, [%l0]
F0038A68: b2040008                 add     %l0, %o0, %i1
F0038A6C: c0266004                 clr     [%i1+4]
F0038A70: c0240008                 clr     [%l0+%o0]
F0038A74: c02e6008                 clrb    [%i1+8]
F0038A78: 90102011                 mov     0x11, %o0
F0038A7C: d02e6009                 stb     %o0, [%i1+9]
F0038A80: 90046008                 add     %l1, 8, %o0
F0038A84: d036600a                 sth     %o0, [%i1+0xA]
F0038A88: d0062014                 ld      [%i0+0x14], %o0
F0038A8C: d026600c                 st      %o0, [%i1+0xC]
F0038A90: d006200c                 ld      [%i0+0xC], %o0
F0038A94: d0266010                 st      %o0, [%i1+0x10]
F0038A98: d2162018                 lduh    [%i0+0x18], %o1
F0038A9C: 113c0432                 sethi   %hi(_udpcksum), %o0
F0038AA0: d0022170                 ld      [%o0+%lo(_udpcksum)], %o0
F0038AA4: d2366014                 sth     %o1, [%i1+0x14]
F0038AA8: d2162010                 lduh    [%i0+0x10], %o1
F0038AAC: 80a22000                 cmp     %o0, 0
F0038AB0: d016600a                 lduh    [%i1+0xA], %o0
F0038AB4: d2366016                 sth     %o1, [%i1+0x16]
F0038AB8: d0366018                 sth     %o0, [%i1+0x18]
F0038ABC: 0280000c                 be      loc_F0038AEC
F0038AC0: c036601a                 clrh    [%i1+0x1A]
F0038AC4: 90100010                 mov     %l0, %o0
F0038AC8: 400180f0                 call    _in_cksum
F0038ACC: 9204601c                 add     %l1, 0x1C, %o1
F0038AD0: d036601a                 sth     %o0, [%i1+0x1A]
F0038AD4: 912a2010                 sll     %o0, 16, %o0
F0038AD8: 80a22000                 cmp     %o0, 0
F0038ADC: 12800005                 bne     loc_F0038AF0
F0038AE0: 9204601c                 add     %l1, 0x1C, %o1
F0038AE4: 90103fff                 mov     -1, %o0
F0038AE8: d036601a                 sth     %o0, [%i1+0x1A]
F0038AEC: 9204601c                 add     %l1, 0x1C, %o1
F0038AF0: 113c0432                 sethi   %hi(_udp_ttl), %o0
F0038AF4: d0022174                 ld      [%o0+%lo(_udp_ttl)], %o0
F0038AF8: d2366002                 sth     %o1, [%i1+2]
F0038AFC: d02e6008                 stb     %o0, [%i1+8]
F0038B00: d006201c                 ld      [%i0+0x1C], %o0
F0038B04: d2062038                 ld      [%i0+0x38], %o1
F0038B08: d6122002                 lduh    [%o0+2], %o3
F0038B0C: 94062024                 add     %i0, 0x24, %o2 ! '$'
F0038B10: d806203c                 ld      [%i0+0x3C], %o4
F0038B14: 90100010                 mov     %l0, %o0
F0038B18: 960ae030                 and     %o3, 0x30, %o3
F0038B1C: 7fffea59                 call    _ip_output
F0038B20: 9612e002                 bset    2, %o3
F0038B24: b0100008                 mov     %o0, %i0
F0038B28: 81c7e008                 ret
F0038B2C: 81e80000                 restore
