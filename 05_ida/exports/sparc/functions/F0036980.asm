F0036980: 9de3bf98                 save    %sp, -0x68, %sp
F0036984: d0062050                 ld      [%i0+0x50], %o0
F0036988: d2062024                 ld      [%i0+0x24], %o1
F003698C: 901a0009                 btog    %o1, %o0
F0036990: 80a00008                 cmp     %g0, %o0
F0036994: d0062020                 ld      [%i0+0x20], %o0
F0036998: b8603fff                 subc    %g0, -1, %i4
F003699C: 80a72000                 cmp     %i4, 0
F00369A0: 02800009                 be      loc_F00369C4
F00369A4: ea02201c                 ld      [%o0+0x1C], %l5
F00369A8: d2562058                 ldsh    [%i0+0x58], %o1
F00369AC: d0562014                 ldsh    [%i0+0x14], %o0
F00369B0: 80a24008                 cmp     %o1, %o0
F00369B4: 26800005                 bl,a    loc_F00369C8
F00369B8: d416203c                 lduh    [%i0+0x3C], %o2
F00369BC: d0162018                 lduh    [%i0+0x18], %o0
F00369C0: d0362054                 sth     %o0, [%i0+0x54]
F00369C4: d416203c                 lduh    [%i0+0x3C], %o2
F00369C8: d2062028                 ld      [%i0+0x28], %o1
F00369CC: d6162054                 lduh    [%i0+0x54], %o3
F00369D0: b6102000                 mov     0, %i3
F00369D4: d0062024                 ld      [%i0+0x24], %o0
F00369D8: 80a2800b                 cmp     %o2, %o3
F00369DC: 08800003                 bleu    loc_F00369E8
F00369E0: b2224008                 sub     %o1, %o0, %i1
F00369E4: 9410000b                 mov     %o3, %o2
F00369E8: d04e201a                 ldsb    [%i0+0x1A], %o0
F00369EC: 80a22000                 cmp     %o0, 0
F00369F0: 02800008                 be      loc_F0036A10
F00369F4: a610000a                 mov     %o2, %l3
F00369F8: 80a4e000                 cmp     %l3, 0
F00369FC: 32800004                 bne,a   loc_F0036A0C
F0036A00: c036200c                 clrh    [%i0+0xC]
F0036A04: 10800003                 ba      loc_F0036A10
F0036A08: a6102001                 mov     1, %l3
F0036A0C: c0362012                 clrh    [%i0+0x12]
F0036A10: d415603c                 lduh    [%l5+0x3C], %o2
F0036A14: 113c0432                 sethi   %hi(_tcp_outflags), %o0
F0036A18: d2562008                 ldsh    [%i0+8], %o1
F0036A1C: 901220c8                 bset    %lo(_tcp_outflags), %o0
F0036A20: 80a28013                 cmp     %o2, %l3
F0036A24: 04800003                 ble     loc_F0036A30
F0036A28: e80a4008                 ldub    [%o1+%o0], %l4
F0036A2C: 94100013                 mov     %l3, %o2
F0036A30: a2a28019                 subcc   %o2, %i1, %l1
F0036A34: 3c800009                 bpos,a  loc_F0036A58
F0036A38: d8162018                 lduh    [%i0+0x18], %o4
F0036A3C: 80a4e000                 cmp     %l3, 0
F0036A40: 12800005                 bne     loc_F0036A54
F0036A44: a2102000                 mov     0, %l1
F0036A48: d0062024                 ld      [%i0+0x24], %o0
F0036A4C: c036200a                 clrh    [%i0+0xA]
F0036A50: d0262028                 st      %o0, [%i0+0x28]
F0036A54: d8162018                 lduh    [%i0+0x18], %o4
F0036A58: 80a4400c                 cmp     %l1, %o4
F0036A5C: 04800004                 ble     loc_F0036A6C
F0036A60: d2062028                 ld      [%i0+0x28], %o1
F0036A64: a210000c                 mov     %o4, %l1
F0036A68: b6102001                 mov     1, %i3
F0036A6C: da15603c                 lduh    [%l5+0x3C], %o5
F0036A70: d0062024                 ld      [%i0+0x24], %o0
F0036A74: 92024011                 add     %o1, %l1, %o1
F0036A78: 9002000d                 add     %o0, %o5, %o0
F0036A7C: 80a24008                 cmp     %o1, %o0
F0036A80: 2c800002                 bneg,a  loc_F0036A88
F0036A84: a80d3ffe                 and     %l4, -2, %l4
F0036A88: d615602a                 lduh    [%l5+0x2A], %o3
F0036A8C: d4156026                 lduh    [%l5+0x26], %o2
F0036A90: d0156024                 lduh    [%l5+0x24], %o0
F0036A94: d2156028                 lduh    [%l5+0x28], %o1
F0036A98: a6228008                 sub     %o2, %o0, %l3
F0036A9C: 9622c009                 sub     %o3, %o1, %o3
F0036AA0: 80a4c00b                 cmp     %l3, %o3
F0036AA4: 34800002                 bg,a    loc_F0036AAC
F0036AA8: a610000b                 mov     %o3, %l3
F0036AAC: 80a46000                 cmp     %l1, 0
F0036AB0: 0280001b                 be      loc_F0036B1C
F0036AB4: 80a4400c                 cmp     %l1, %o4
F0036AB8: 02800051                 be      loc_F0036BFC
F0036ABC: 80a72000                 cmp     %i4, 0
F0036AC0: 12800006                 bne     loc_F0036AD8
F0036AC4: 90044019                 add     %l1, %i1, %o0
F0036AC8: d00e201b                 ldub    [%i0+0x1B], %o0
F0036ACC: 808a2004                 btst    4, %o0
F0036AD0: 02800005                 be      loc_F0036AE4
F0036AD4: 90044019                 add     %l1, %i1, %o0
F0036AD8: 80a2000d                 cmp     %o0, %o5
F0036ADC: 16800049                 bge     loc_F0036C00
F0036AE0: ac102000                 mov     0, %l6
F0036AE4: d04e201a                 ldsb    [%i0+0x1A], %o0
F0036AE8: 80a22000                 cmp     %o0, 0
F0036AEC: 12800045                 bne     loc_F0036C00
F0036AF0: ac102000                 mov     0, %l6
F0036AF4: d0162066                 lduh    [%i0+0x66], %o0
F0036AF8: 91322001                 srl     %o0, 1, %o0
F0036AFC: 80a44008                 cmp     %l1, %o0
F0036B00: 16800041                 bge     loc_F0036C04
F0036B04: 808d2002                 btst    2, %l4
F0036B08: d2062028                 ld      [%i0+0x28], %o1
F0036B0C: d0062050                 ld      [%i0+0x50], %o0
F0036B10: 80a24008                 cmp     %o1, %o0
F0036B14: 0c80003c                 bneg    loc_F0036C04
F0036B18: 808d2002                 btst    2, %l4
F0036B1C: 80a4e000                 cmp     %l3, 0
F0036B20: 24800011                 ble,a   loc_F0036B64
F0036B24: d40e201b                 ldub    [%i0+0x1B], %o2
F0036B28: d006204c                 ld      [%i0+0x4C], %o0
F0036B2C: d2062040                 ld      [%i0+0x40], %o1
F0036B30: 90220009                 sub     %o0, %o1, %o0
F0036B34: d2162018                 lduh    [%i0+0x18], %o1
F0036B38: 9024c008                 sub     %l3, %o0, %o0
F0036B3C: 932a6001                 sll     %o1, 1, %o1
F0036B40: 80a20009                 cmp     %o0, %o1
F0036B44: 3680002f                 bge,a   loc_F0036C00
F0036B48: ac102000                 mov     0, %l6
F0036B4C: d2156026                 lduh    [%l5+0x26], %o1
F0036B50: 912a2001                 sll     %o0, 1, %o0
F0036B54: 80a20009                 cmp     %o0, %o1
F0036B58: 3680002a                 bge,a   loc_F0036C00
F0036B5C: ac102000                 mov     0, %l6
F0036B60: d40e201b                 ldub    [%i0+0x1B], %o2
F0036B64: 808aa001                 btst    1, %o2
F0036B68: 32800026                 bne,a   loc_F0036C00
F0036B6C: ac102000                 mov     0, %l6
F0036B70: 808d2006                 btst    6, %l4
F0036B74: 32800023                 bne,a   loc_F0036C00
F0036B78: ac102000                 mov     0, %l6
F0036B7C: d006202c                 ld      [%i0+0x2C], %o0
F0036B80: d2062024                 ld      [%i0+0x24], %o1
F0036B84: 90220009                 sub     %o0, %o1, %o0
F0036B88: 80a22000                 cmp     %o0, 0
F0036B8C: 3480001d                 bg,a    loc_F0036C00
F0036B90: ac102000                 mov     0, %l6
F0036B94: 808d2001                 btst    1, %l4
F0036B98: 02800008                 be      loc_F0036BB8
F0036B9C: 808aa010                 btst    0x10, %o2
F0036BA0: 22800018                 be,a    loc_F0036C00
F0036BA4: ac102000                 mov     0, %l6
F0036BA8: d0062028                 ld      [%i0+0x28], %o0
F0036BAC: 80a20009                 cmp     %o0, %o1
F0036BB0: 22800014                 be,a    loc_F0036C00
F0036BB4: ac102000                 mov     0, %l6
F0036BB8: d015603c                 lduh    [%l5+0x3C], %o0
F0036BBC: 80a22000                 cmp     %o0, 0
F0036BC0: 2280016e                 be,a    locret_F0037178
F0036BC4: b0102000                 mov     0, %i0
F0036BC8: d056200a                 ldsh    [%i0+0xA], %o0
F0036BCC: 80a22000                 cmp     %o0, 0
F0036BD0: 3280016a                 bne,a   locret_F0037178
F0036BD4: b0102000                 mov     0, %i0
F0036BD8: d056200c                 ldsh    [%i0+0xC], %o0
F0036BDC: 80a22000                 cmp     %o0, 0
F0036BE0: 32800166                 bne,a   locret_F0037178
F0036BE4: b0102000                 mov     0, %i0
F0036BE8: c0362012                 clrh    [%i0+0x12]
F0036BEC: 40000165                 call    _tcp_setpersist
F0036BF0: 90100018                 mov     %i0, %o0
F0036BF4: 10800161                 ba      locret_F0037178
F0036BF8: b0102000                 mov     0, %i0
F0036BFC: ac102000                 mov     0, %l6
F0036C00: 808d2002                 btst    2, %l4
F0036C04: 0280000d                 be      loc_F0036C38
F0036C08: b4102028                 mov     0x28, %i2 ! '('
F0036C0C: d00e201b                 ldub    [%i0+0x1B], %o0
F0036C10: 808a2008                 btst    8, %o0
F0036C14: 12800009                 bne     loc_F0036C38
F0036C18: 90100018                 mov     %i0, %o0
F0036C1C: ac102004                 mov     4, %l6
F0036C20: b410202c                 mov     0x2C, %i2 ! ','
F0036C24: 92102000                 mov     0, %o1
F0036C28: 153c0432                 sethi   %hi(_tcp_initopt), %o2
F0036C2C: 7ffffef7                 call    _tcp_mss
F0036C30: ba12a0d8                 or      %o2, %lo(_tcp_initopt), %i5
F0036C34: d0376002                 sth     %o0, [%i5+2]
F0036C38: 40017fe0                 call    _spltty
F0036C3C: 2f3c04d3                 sethi   %hi(_mfree), %l7
F0036C40: e405e168                 ld      [%l7+%lo(_mfree)], %l2
F0036C44: 80a4a000                 cmp     %l2, 0
F0036C48: 02800018                 be      loc_F0036CA8
F0036C4C: a0100008                 mov     %o0, %l0
F0036C50: d054a00a                 ldsh    [%l2+0xA], %o0
F0036C54: 80a22000                 cmp     %o0, 0
F0036C58: 02800004                 be      loc_F0036C68
F0036C5C: 113c0432                 sethi   %hi(aMget_11), %o0! "mget"
F0036C60: 7fff7944                 call    _panic
F0036C64: 901220e0                 bset    %lo(aMget_11), %o0! "mget"
F0036C68: 90102002                 mov     2, %o0
F0036C6C: d034a00a                 sth     %o0, [%l2+0xA]
F0036C70: 153c04d29412a2f0         set     _mbstat, %o2
F0036C78: d012a01c                 lduh    [%o2+0x1C], %o0
F0036C7C: d212a020                 lduh    [%o2+0x20], %o1
F0036C80: 90023fff                 inc     -1, %o0
F0036C84: d032a01c                 sth     %o0, [%o2+0x1C]
F0036C88: 92026001                 inc     %o1
F0036C8C: d232a020                 sth     %o1, [%o2+0x20]
F0036C90: 9010200c                 mov     0xC, %o0
F0036C94: d2048000                 ld      [%l2], %o1
F0036C98: d024a004                 st      %o0, [%l2+4]
F0036C9C: d225e168                 st      %o1, [%l7+0x168]
F0036CA0: 10800006                 ba      loc_F0036CB8
F0036CA4: c0248000                 clr     [%l2]
F0036CA8: 90102000                 mov     0, %o0
F0036CAC: 7fff9bb0                 call    _m_more
F0036CB0: 92102002                 mov     2, %o1
F0036CB4: a4100008                 mov     %o0, %l2
F0036CB8: 4001801b                 call    _splx
F0036CBC: 90100010                 mov     %l0, %o0
F0036CC0: 80a4a000                 cmp     %l2, 0
F0036CC4: 12800004                 bne     loc_F0036CD4
F0036CC8: 90102054                 mov     0x54, %o0 ! 'T'
F0036CCC: 1080012b                 ba      locret_F0037178
F0036CD0: b0102037                 mov     0x37, %i0 ! '7'
F0036CD4: 90220016                 sub     %o0, %l6, %o0
F0036CD8: d024a004                 st      %o0, [%l2+4]
F0036CDC: 80a46000                 cmp     %l1, 0
F0036CE0: 02800032                 be      loc_F0036DA8
F0036CE4: f434a008                 sth     %i2, [%l2+8]
F0036CE8: d04e201a                 ldsb    [%i0+0x1A], %o0
F0036CEC: 80a22000                 cmp     %o0, 0
F0036CF0: 0280000a                 be      loc_F0036D18
F0036CF4: 80a46001                 cmp     %l1, 1
F0036CF8: 32800009                 bne,a   loc_F0036D1C
F0036CFC: d2062028                 ld      [%i0+0x28], %o1
F0036D00: 133c04e9921263a0         set     _tcpstat, %o1
F0036D08: d0026054                 ld      [%o1+0x54], %o0
F0036D0C: 90022001                 inc     %o0
F0036D10: 10800016                 ba      loc_F0036D68
F0036D14: d0226054                 st      %o0, [%o1+0x54]
F0036D18: d2062028                 ld      [%i0+0x28], %o1
F0036D1C: d0062050                 ld      [%i0+0x50], %o0
F0036D20: 80a24008                 cmp     %o1, %o0
F0036D24: 1c80000a                 bpos    loc_F0036D4C
F0036D28: 113c04e9                 sethi   %hi(_tcpstat), %o0
F0036D2C: 901223a0                 bset    %lo(_tcpstat), %o0
F0036D30: d2022048                 ld      [%o0+0x48], %o1
F0036D34: d402204c                 ld      [%o0+0x4C], %o2
F0036D38: 92026001                 inc     %o1
F0036D3C: d2222048                 st      %o1, [%o0+0x48]
F0036D40: 94028011                 add     %o2, %l1, %o2
F0036D44: 10800009                 ba      loc_F0036D68
F0036D48: d422204c                 st      %o2, [%o0+0x4C]
F0036D4C: 901223a0                 bset    0x3A0, %o0
F0036D50: d2022040                 ld      [%o0+0x40], %o1
F0036D54: d4022044                 ld      [%o0+0x44], %o2
F0036D58: 92026001                 inc     %o1
F0036D5C: d2222040                 st      %o1, [%o0+0x40]
F0036D60: 94028011                 add     %o2, %l1, %o2
F0036D64: d4222044                 st      %o2, [%o0+0x44]
F0036D68: d0056048                 ld      [%l5+0x48], %o0
F0036D6C: 92100019                 mov     %i1, %o1
F0036D70: 7fff9bf5                 call    _m_copy
F0036D74: 94100011                 mov     %l1, %o2! size_t
F0036D78: 80a22000                 cmp     %o0, 0
F0036D7C: 12800004                 bne     loc_F0036D8C
F0036D80: d0248000                 st      %o0, [%l2]
F0036D84: 10800028                 ba      loc_F0036E24
F0036D88: a2102000                 mov     0, %l1
F0036D8C: d215603c                 lduh    [%l5+0x3C], %o1
F0036D90: 90064011                 add     %i1, %l1, %o0
F0036D94: 80a20009                 cmp     %o0, %o1
F0036D98: 22800023                 be,a    loc_F0036E24
F0036D9C: a8152008                 bset    8, %l4
F0036DA0: 10800022                 ba      loc_F0036E28
F0036DA4: d006201c                 ld      [%i0+0x1C], %o0
F0036DA8: d00e201b                 ldub    [%i0+0x1B], %o0
F0036DAC: 808a2001                 btst    1, %o0
F0036DB0: 02800007                 be      loc_F0036DCC
F0036DB4: 133c04e9                 sethi   %hi(_tcpstat), %o1
F0036DB8: 921263a0                 bset    %lo(_tcpstat), %o1
F0036DBC: d0026050                 ld      [%o1+0x50], %o0
F0036DC0: 90022001                 inc     %o0
F0036DC4: 10800018                 ba      loc_F0036E24
F0036DC8: d0226050                 st      %o0, [%o1+0x50]
F0036DCC: 808d2007                 btst    7, %l4
F0036DD0: 02800006                 be      loc_F0036DE8
F0036DD4: 921263a0                 bset    0x3A0, %o1
F0036DD8: d0026060                 ld      [%o1+0x60], %o0
F0036DDC: 90022001                 inc     %o0
F0036DE0: 10800011                 ba      loc_F0036E24
F0036DE4: d0226060                 st      %o0, [%o1+0x60]
F0036DE8: d006202c                 ld      [%i0+0x2C], %o0
F0036DEC: d2062024                 ld      [%i0+0x24], %o1
F0036DF0: 90220009                 sub     %o0, %o1, %o0
F0036DF4: 80a22000                 cmp     %o0, 0
F0036DF8: 04800007                 ble     loc_F0036E14
F0036DFC: 133c04e9                 sethi   %hi(_tcpstat), %o1
F0036E00: 921263a0                 bset    %lo(_tcpstat), %o1
F0036E04: d0026058                 ld      [%o1+0x58], %o0
F0036E08: 90022001                 inc     %o0
F0036E0C: 10800006                 ba      loc_F0036E24
F0036E10: d0226058                 st      %o0, [%o1+0x58]
F0036E14: 921263a0                 bset    0x3A0, %o1
F0036E18: d002605c                 ld      [%o1+0x5C], %o0
F0036E1C: 90022001                 inc     %o0
F0036E20: d022605c                 st      %o0, [%o1+0x5C]
F0036E24: d006201c                 ld      [%i0+0x1C], %o0
F0036E28: d204a004                 ld      [%l2+4], %o1
F0036E2C: 80a22000                 cmp     %o0, 0
F0036E30: 12800005                 bne     loc_F0036E44
F0036E34: a0048009                 add     %l2, %o1, %l0
F0036E38: 113c0432                 sethi   %hi(aTcpOutput), %o0! "tcp_output"
F0036E3C: 7fff78cd                 call    _panic
F0036E40: 901220e8                 bset    %lo(aTcpOutput), %o0! "tcp_output"
F0036E44: d006201c                 ld      [%i0+0x1C], %o0! void *
F0036E48: 92100010                 mov     %l0, %o1! void *
F0036E4C: 40017731                 call    _bcopy
F0036E50: 94102028                 mov     0x28, %o2 ! '('! size_t
F0036E54: 808d2001                 btst    1, %l4
F0036E58: 2280000e                 be,a    loc_F0036E90
F0036E5C: d0062028                 ld      [%i0+0x28], %o0
F0036E60: d00e201b                 ldub    [%i0+0x1B], %o0
F0036E64: 808a2010                 btst    0x10, %o0
F0036E68: 2280000a                 be,a    loc_F0036E90
F0036E6C: d0062028                 ld      [%i0+0x28], %o0
F0036E70: d2062028                 ld      [%i0+0x28], %o1
F0036E74: d0062050                 ld      [%i0+0x50], %o0
F0036E78: 80a24008                 cmp     %o1, %o0
F0036E7C: 32800005                 bne,a   loc_F0036E90
F0036E80: d0062028                 ld      [%i0+0x28], %o0
F0036E84: 90027fff                 add     %o1, -1, %o0
F0036E88: d0262028                 st      %o0, [%i0+0x28]
F0036E8C: d0062028                 ld      [%i0+0x28], %o0
F0036E90: d0242018                 st      %o0, [%l0+0x18]
F0036E94: d0062040                 ld      [%i0+0x40], %o0
F0036E98: 80a5a000                 cmp     %l6, 0
F0036E9C: 0280000d                 be      loc_F0036ED0
F0036EA0: d024201c                 st      %o0, [%l0+0x1C]
F0036EA4: 9010001d                 mov     %i5, %o0! void *
F0036EA8: 92042028                 add     %l0, 0x28, %o1 ! '('! void *
F0036EAC: 40017719                 call    _bcopy
F0036EB0: 94100016                 mov     %l6, %o2
F0036EB4: d0042020                 ld      [%l0+0x20], %o0
F0036EB8: 133c0000                 sethi   -0x10000000, %o1
F0036EBC: 922a0009                 andn    %o0, %o1, %o1
F0036EC0: 9005a014                 add     %l6, 0x14, %o0
F0036EC4: 912a201a                 sll     %o0, 26, %o0
F0036EC8: 92124008                 bset    %o0, %o1
F0036ECC: d2242020                 st      %o1, [%l0+0x20]
F0036ED0: e82c2021                 stb     %l4, [%l0+0x21]
F0036ED4: d0156026                 lduh    [%l5+0x26], %o0
F0036ED8: 91322002                 srl     %o0, 2, %o0
F0036EDC: 80a4c008                 cmp     %l3, %o0
F0036EE0: 16800007                 bge     loc_F0036EFC
F0036EE4: 1100003f                 sethi   0xFC00, %o0
F0036EE8: d0162018                 lduh    [%i0+0x18], %o0
F0036EEC: 80a4c008                 cmp     %l3, %o0
F0036EF0: 26800002                 bl,a    loc_F0036EF8
F0036EF4: a6102000                 mov     0, %l3
F0036EF8: 1100003f                 sethi   0xFC00, %o0
F0036EFC: 901223ff                 bset    0x3FF, %o0
F0036F00: 80a4c008                 cmp     %l3, %o0
F0036F04: 34800002                 bg,a    loc_F0036F0C
F0036F08: a6100008                 mov     %o0, %l3
F0036F0C: d206204c                 ld      [%i0+0x4C], %o1
F0036F10: d0062040                 ld      [%i0+0x40], %o0
F0036F14: 92224008                 sub     %o1, %o0, %o1
F0036F18: 80a4c009                 cmp     %l3, %o1
F0036F1C: 26800002                 bl,a    loc_F0036F24
F0036F20: a6100009                 mov     %o1, %l3
F0036F24: e6342022                 sth     %l3, [%l0+0x22]
F0036F28: d206202c                 ld      [%i0+0x2C], %o1
F0036F2C: d0062028                 ld      [%i0+0x28], %o0
F0036F30: 92224008                 sub     %o1, %o0, %o1
F0036F34: 80a26000                 cmp     %o1, 0
F0036F38: 24800007                 ble,a   loc_F0036F54
F0036F3C: d0062024                 ld      [%i0+0x24], %o0
F0036F40: d00c2021                 ldub    [%l0+0x21], %o0
F0036F44: d2342026                 sth     %o1, [%l0+0x26]
F0036F48: 90122020                 bset    0x20, %o0 ! ' '
F0036F4C: 10800003                 ba      loc_F0036F58
F0036F50: d02c2021                 stb     %o0, [%l0+0x21]
F0036F54: d026202c                 st      %o0, [%i0+0x2C]
F0036F58: 90044016                 add     %l1, %l6, %o0
F0036F5C: 80a22000                 cmp     %o0, 0
F0036F60: 02800004                 be      loc_F0036F70
F0036F64: 90046014                 add     %l1, 0x14, %o0
F0036F68: 90058008                 add     %l6, %o0, %o0
F0036F6C: d034200a                 sth     %o0, [%l0+0xA]
F0036F70: 90100012                 mov     %l2, %o0
F0036F74: 400187c5                 call    _in_cksum
F0036F78: 92068011                 add     %i2, %l1, %o1
F0036F7C: d0342024                 sth     %o0, [%l0+0x24]
F0036F80: d04e201a                 ldsb    [%i0+0x1A], %o0
F0036F84: 80a22000                 cmp     %o0, 0
F0036F88: 02800007                 be      loc_F0036FA4
F0036F8C: 808d2003                 btst    3, %l4
F0036F90: d056200c                 ldsh    [%i0+0xC], %o0
F0036F94: 80a22000                 cmp     %o0, 0
F0036F98: 32800035                 bne,a   loc_F003706C
F0036F9C: d2062028                 ld      [%i0+0x28], %o1
F0036FA0: 808d2003                 btst    3, %l4
F0036FA4: 0280000e                 be      loc_F0036FDC
F0036FA8: d4062028                 ld      [%i0+0x28], %o2
F0036FAC: 808d2002                 btst    2, %l4
F0036FB0: 02800003                 be      loc_F0036FBC
F0036FB4: 9002a001                 add     %o2, 1, %o0
F0036FB8: d0262028                 st      %o0, [%i0+0x28]
F0036FBC: 808d2001                 btst    1, %l4
F0036FC0: 02800008                 be      loc_F0036FE0
F0036FC4: d0062028                 ld      [%i0+0x28], %o0
F0036FC8: d20e201b                 ldub    [%i0+0x1B], %o1
F0036FCC: 90022001                 inc     %o0
F0036FD0: d0262028                 st      %o0, [%i0+0x28]
F0036FD4: 92126010                 bset    0x10, %o1
F0036FD8: d22e201b                 stb     %o1, [%i0+0x1B]
F0036FDC: d0062028                 ld      [%i0+0x28], %o0
F0036FE0: 92020011                 add     %o0, %l1, %o1
F0036FE4: d0062050                 ld      [%i0+0x50], %o0
F0036FE8: 90224008                 sub     %o1, %o0, %o0
F0036FEC: 80a22000                 cmp     %o0, 0
F0036FF0: 0480000e                 ble     loc_F0037028
F0036FF4: d2262028                 st      %o1, [%i0+0x28]
F0036FF8: d056205a                 ldsh    [%i0+0x5A], %o0
F0036FFC: 80a22000                 cmp     %o0, 0
F0037000: 1280000a                 bne     loc_F0037028
F0037004: d2262050                 st      %o1, [%i0+0x50]
F0037008: 90102001                 mov     1, %o0
F003700C: d036205a                 sth     %o0, [%i0+0x5A]
F0037010: d426205c                 st      %o2, [%i0+0x5C]
F0037014: 133c04e9921263a0         set     _tcpstat, %o1
F003701C: d0026018                 ld      [%o1+0x18], %o0
F0037020: 90022001                 inc     %o0
F0037024: d0226018                 st      %o0, [%o1+0x18]
F0037028: d056200a                 ldsh    [%i0+0xA], %o0
F003702C: 80a22000                 cmp     %o0, 0
F0037030: 32800016                 bne,a   loc_F0037088
F0037034: d0156002                 lduh    [%l5+2], %o0
F0037038: d2062028                 ld      [%i0+0x28], %o1
F003703C: d0062024                 ld      [%i0+0x24], %o0
F0037040: 80a24008                 cmp     %o1, %o0
F0037044: 22800011                 be,a    loc_F0037088
F0037048: d0156002                 lduh    [%l5+2], %o0
F003704C: d0162014                 lduh    [%i0+0x14], %o0
F0037050: d256200c                 ldsh    [%i0+0xC], %o1
F0037054: 80a26000                 cmp     %o1, 0
F0037058: 0280000b                 be      loc_F0037084
F003705C: d036200a                 sth     %o0, [%i0+0xA]
F0037060: c036200c                 clrh    [%i0+0xC]
F0037064: 10800008                 ba      loc_F0037084
F0037068: c0362012                 clrh    [%i0+0x12]
F003706C: d0062050                 ld      [%i0+0x50], %o0
F0037070: 92024011                 add     %o1, %l1, %o1
F0037074: 90224008                 sub     %o1, %o0, %o0
F0037078: 80a22000                 cmp     %o0, 0
F003707C: 34800002                 bg,a    loc_F0037084
F0037080: d2262050                 st      %o1, [%i0+0x50]
F0037084: d0156002                 lduh    [%l5+2], %o0
F0037088: 808a2001                 btst    1, %o0
F003708C: 02800007                 be      loc_F00370A8
F0037090: 90102001                 mov     1, %o0
F0037094: d2562008                 ldsh    [%i0+8], %o1
F0037098: 94100018                 mov     %i0, %o2
F003709C: 96100010                 mov     %l0, %o3
F00370A0: 7ffff6b8                 call    _tcp_trace
F00370A4: 98102000                 mov     0, %o4
F00370A8: 9005a028                 add     %l6, 0x28, %o0 ! '('
F00370AC: 90020011                 add     %o0, %l1, %o0
F00370B0: d0342002                 sth     %o0, [%l0+2]
F00370B4: 9010203c                 mov     0x3C, %o0 ! '<'
F00370B8: d02c2008                 stb     %o0, [%l0+8]
F00370BC: 90100012                 mov     %l2, %o0
F00370C0: d2062020                 ld      [%i0+0x20], %o1
F00370C4: 98102000                 mov     0, %o4
F00370C8: d6156002                 lduh    [%l5+2], %o3
F00370CC: 94026024                 add     %o1, 0x24, %o2 ! '$'
F00370D0: d2026038                 ld      [%o1+0x38], %o1
F00370D4: 7ffff0eb                 call    _ip_output
F00370D8: 960ae010                 and     %o3, 0x10, %o3
F00370DC: 92920000                 orcc    %o0, %g0, %o1
F00370E0: 02800012                 be      loc_F0037128
F00370E4: 80a26037                 cmp     %o1, 0x37 ! '7'
F00370E8: 12800006                 bne     loc_F0037100
F00370EC: 80a26041                 cmp     %o1, 0x41 ! 'A'
F00370F0: 400001aa                 call    _tcp_quench
F00370F4: d0062020                 ld      [%i0+0x20], %o0
F00370F8: 10800020                 ba      locret_F0037178
F00370FC: b0102000                 mov     0, %i0
F0037100: 02800004                 be      loc_F0037110
F0037104: 80a26032                 cmp     %o1, 0x32 ! '2'
F0037108: 3280001c                 bne,a   locret_F0037178
F003710C: b0100009                 mov     %o1, %i0
F0037110: d0562008                 ldsh    [%i0+8], %o0
F0037114: 80a22002                 cmp     %o0, 2
F0037118: 24800018                 ble,a   locret_F0037178
F003711C: b0100009                 mov     %o1, %i0
F0037120: 10800015                 ba      loc_F0037174
F0037124: d236206a                 sth     %o1, [%i0+0x6A]
F0037128: 133c04e9921263a0         set     _tcpstat, %o1
F0037130: d002603c                 ld      [%o1+0x3C], %o0
F0037134: 80a4e000                 cmp     %l3, 0
F0037138: 90022001                 inc     %o0
F003713C: 04800009                 ble     loc_F0037160
F0037140: d022603c                 st      %o0, [%o1+0x3C]
F0037144: d2062040                 ld      [%i0+0x40], %o1
F0037148: d006204c                 ld      [%i0+0x4C], %o0
F003714C: 92024013                 add     %o1, %l3, %o1
F0037150: 90224008                 sub     %o1, %o0, %o0
F0037154: 80a22000                 cmp     %o0, 0
F0037158: 34800002                 bg,a    loc_F0037160
F003715C: d226204c                 st      %o1, [%i0+0x4C]
F0037160: d00e201b                 ldub    [%i0+0x1B], %o0
F0037164: 80a6e000                 cmp     %i3, 0
F0037168: 900a20fc                 and     %o0, 0xFC, %o0
F003716C: 12bffe16                 bne     loc_F00369C4
F0037170: d02e201b                 stb     %o0, [%i0+0x1B]
F0037174: b0102000                 mov     0, %i0
F0037178: 81c7e008                 ret
F003717C: 81e80000                 restore
