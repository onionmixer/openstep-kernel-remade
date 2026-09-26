F0034C78: 9de3bf98                 save    %sp, -0x68, %sp
F0034C7C: d0062020                 ld      [%i0+0x20], %o0
F0034C80: 80a66000                 cmp     %i1, 0
F0034C84: 0280006c                 be      loc_F0034E34
F0034C88: e402201c                 ld      [%o0+0x1C], %l2
F0034C8C: e0060000                 ld      [%i0], %l0
F0034C90: 80a40018                 cmp     %l0, %i0
F0034C94: 2280000d                 be,a    loc_F0034CC8
F0034C98: d0042004                 ld      [%l0+4], %o0
F0034C9C: d2066018                 ld      [%i1+0x18], %o1
F0034CA0: d0042018                 ld      [%l0+0x18], %o0
F0034CA4: 90220009                 sub     %o0, %o1, %o0
F0034CA8: 80a22000                 cmp     %o0, 0
F0034CAC: 34800007                 bg,a    loc_F0034CC8
F0034CB0: d0042004                 ld      [%l0+4], %o0
F0034CB4: e0040000                 ld      [%l0], %l0
F0034CB8: 80a40018                 cmp     %l0, %i0
F0034CBC: 32bffffa                 bne,a   loc_F0034CA4
F0034CC0: d0042018                 ld      [%l0+0x18], %o0
F0034CC4: d0042004                 ld      [%l0+4], %o0
F0034CC8: 80a20018                 cmp     %o0, %i0
F0034CCC: 0280002e                 be      loc_F0034D84
F0034CD0: 133c04e9                 sethi   -0xFEC5C00, %o1
F0034CD4: a0100008                 mov     %o0, %l0
F0034CD8: d054200a                 ldsh    [%l0+0xA], %o0
F0034CDC: d2042018                 ld      [%l0+0x18], %o1
F0034CE0: d4066018                 ld      [%i1+0x18], %o2
F0034CE4: 92024008                 add     %o1, %o0, %o1
F0034CE8: a222400a                 sub     %o1, %o2, %l1
F0034CEC: 80a46000                 cmp     %l1, 0
F0034CF0: 24800024                 ble,a   loc_F0034D80
F0034CF4: e0040000                 ld      [%l0], %l0
F0034CF8: d056600a                 ldsh    [%i1+0xA], %o0
F0034CFC: 80a44008                 cmp     %l1, %o0
F0034D00: 06800016                 bl      loc_F0034D58
F0034D04: 153c04e9                 sethi   %hi(_tcpstat), %o2
F0034D08: 9412a3a0                 bset    %lo(_tcpstat), %o2
F0034D0C: d002a07c                 ld      [%o2+0x7C], %o0
F0034D10: d202a080                 ld      [%o2+0x80], %o1
F0034D14: 90022001                 inc     %o0
F0034D18: d022a07c                 st      %o0, [%o2+0x7C]
F0034D1C: d656600a                 ldsh    [%i1+0xA], %o3
F0034D20: 9010001a                 mov     %i2, %o0
F0034D24: 9202400b                 add     %o1, %o3, %o1
F0034D28: 7fffa3cf                 call    _m_freem
F0034D2C: d222a080                 st      %o1, [%o2+0x80]
F0034D30: 10800079                 ba      locret_F0034F14
F0034D34: b0102000                 mov     0, %i0
F0034D38: d414200a                 lduh    [%l0+0xA], %o2
F0034D3C: d0242018                 st      %o0, [%l0+0x18]
F0034D40: d0042014                 ld      [%l0+0x14], %o0
F0034D44: 94228009                 sub     %o2, %o1, %o2
F0034D48: 7fffa4a6                 call    _m_adj
F0034D4C: d434200a                 sth     %o2, [%l0+0xA]
F0034D50: 10800033                 ba      loc_F0034E1C
F0034D54: d0042004                 ld      [%l0+4], %o0
F0034D58: 9010001a                 mov     %i2, %o0
F0034D5C: 7fffa4a1                 call    _m_adj
F0034D60: 92100011                 mov     %l1, %o1
F0034D64: d016600a                 lduh    [%i1+0xA], %o0
F0034D68: d2066018                 ld      [%i1+0x18], %o1
F0034D6C: 90220011                 sub     %o0, %l1, %o0
F0034D70: d036600a                 sth     %o0, [%i1+0xA]
F0034D74: 92024011                 add     %o1, %l1, %o1
F0034D78: d2266018                 st      %o1, [%i1+0x18]
F0034D7C: e0040000                 ld      [%l0], %l0
F0034D80: 133c04e9                 sethi   -0xFEC5C00, %o1
F0034D84: 921263a0                 bset    0x3A0, %o1
F0034D88: d002608c                 ld      [%o1+0x8C], %o0
F0034D8C: 90022001                 inc     %o0
F0034D90: d022608c                 st      %o0, [%o1+0x8C]
F0034D94: d456600a                 ldsh    [%i1+0xA], %o2
F0034D98: d0026090                 ld      [%o1+0x90], %o0
F0034D9C: 80a40018                 cmp     %l0, %i0
F0034DA0: 9002000a                 add     %o0, %o2, %o0
F0034DA4: d0226090                 st      %o0, [%o1+0x90]
F0034DA8: 0280001c                 be      loc_F0034E18
F0034DAC: f4266014                 st      %i2, [%i1+0x14]
F0034DB0: d256600a                 ldsh    [%i1+0xA], %o1
F0034DB4: d0066018                 ld      [%i1+0x18], %o0
F0034DB8: d4042018                 ld      [%l0+0x18], %o2
F0034DBC: 90020009                 add     %o0, %o1, %o0
F0034DC0: 9222000a                 sub     %o0, %o2, %o1
F0034DC4: 80a26000                 cmp     %o1, 0
F0034DC8: 24800015                 ble,a   loc_F0034E1C
F0034DCC: d0042004                 ld      [%l0+4], %o0
F0034DD0: d054200a                 ldsh    [%l0+0xA], %o0
F0034DD4: 80a24008                 cmp     %o1, %o0
F0034DD8: 06bfffd8                 bl      loc_F0034D38
F0034DDC: 90028009                 add     %o2, %o1, %o0
F0034DE0: e0040000                 ld      [%l0], %l0
F0034DE4: d2042004                 ld      [%l0+4], %o1
F0034DE8: d4024000                 ld      [%o1], %o2
F0034DEC: d0026004                 ld      [%o1+4], %o0
F0034DF0: f4026014                 ld      [%o1+0x14], %i2
F0034DF4: d022a004                 st      %o0, [%o2+4]
F0034DF8: d4026004                 ld      [%o1+4], %o2
F0034DFC: d2024000                 ld      [%o1], %o1
F0034E00: 9010001a                 mov     %i2, %o0
F0034E04: 7fffa398                 call    _m_freem
F0034E08: d2228000                 st      %o1, [%o2]
F0034E0C: 80a40018                 cmp     %l0, %i0
F0034E10: 32bfffe9                 bne,a   loc_F0034DB4
F0034E14: d256600a                 ldsh    [%i1+0xA], %o1
F0034E18: d0042004                 ld      [%l0+4], %o0
F0034E1C: d2020000                 ld      [%o0], %o1
F0034E20: d2264000                 st      %o1, [%i1]
F0034E24: d0266004                 st      %o0, [%i1+4]
F0034E28: d2020000                 ld      [%o0], %o1
F0034E2C: f2226004                 st      %i1, [%o1+4]
F0034E30: f2220000                 st      %i1, [%o0]
F0034E34: d4562008                 ldsh    [%i0+8], %o2
F0034E38: 80a2a002                 cmp     %o2, 2
F0034E3C: 24800036                 ble,a   locret_F0034F14
F0034E40: b0102000                 mov     0, %i0
F0034E44: f2060000                 ld      [%i0], %i1
F0034E48: 80a64018                 cmp     %i1, %i0
F0034E4C: 22800032                 be,a    locret_F0034F14
F0034E50: b0102000                 mov     0, %i0
F0034E54: d2066018                 ld      [%i1+0x18], %o1
F0034E58: d0062040                 ld      [%i0+0x40], %o0
F0034E5C: 80a24008                 cmp     %o1, %o0
F0034E60: 3280002d                 bne,a   locret_F0034F14
F0034E64: b0102000                 mov     0, %i0
F0034E68: 80a2a003                 cmp     %o2, 3
F0034E6C: 32800008                 bne,a   loc_F0034E8C
F0034E70: d256600a                 ldsh    [%i1+0xA], %o1
F0034E74: d056600a                 ldsh    [%i1+0xA], %o0
F0034E78: 80a22000                 cmp     %o0, 0
F0034E7C: 32800026                 bne,a   locret_F0034F14
F0034E80: b0102000                 mov     0, %i0
F0034E84: d256600a                 ldsh    [%i1+0xA], %o1
F0034E88: d0062040                 ld      [%i0+0x40], %o0
F0034E8C: 90020009                 add     %o0, %o1, %o0
F0034E90: d0262040                 st      %o0, [%i0+0x40]
F0034E94: d2064000                 ld      [%i1], %o1
F0034E98: d0066004                 ld      [%i1+4], %o0
F0034E9C: d40e6021                 ldub    [%i1+0x21], %o2
F0034EA0: d0226004                 st      %o0, [%o1+4]
F0034EA4: d2066004                 ld      [%i1+4], %o1
F0034EA8: d0064000                 ld      [%i1], %o0
F0034EAC: d0224000                 st      %o0, [%o1]
F0034EB0: d014a006                 lduh    [%l2+6], %o0
F0034EB4: f4066014                 ld      [%i1+0x14], %i2
F0034EB8: a00aa001                 and     %o2, 1, %l0
F0034EBC: 808a2020                 btst    0x20, %o0 ! ' '
F0034EC0: 02800006                 be      loc_F0034ED8
F0034EC4: f2064000                 ld      [%i1], %i1
F0034EC8: 7fffa367                 call    _m_freem
F0034ECC: 9010001a                 mov     %i2, %o0
F0034ED0: 10800006                 ba      loc_F0034EE8
F0034ED4: 80a64018                 cmp     %i1, %i0
F0034ED8: 9004a024                 add     %l2, 0x24, %o0 ! '$'
F0034EDC: 7fffad9b                 call    _sbappend
F0034EE0: 9210001a                 mov     %i2, %o1
F0034EE4: 80a64018                 cmp     %i1, %i0
F0034EE8: 02800008                 be      loc_F0034F08
F0034EEC: 90100012                 mov     %l2, %o0
F0034EF0: d2066018                 ld      [%i1+0x18], %o1
F0034EF4: d0062040                 ld      [%i0+0x40], %o0
F0034EF8: 80a24008                 cmp     %o1, %o0
F0034EFC: 22bfffe4                 be,a    loc_F0034E8C
F0034F00: d256600a                 ldsh    [%i1+0xA], %o1
F0034F04: 90100012                 mov     %l2, %o0
F0034F08: 7fffad41                 call    _sowakeup
F0034F0C: 92022024                 add     %o0, 0x24, %o1 ! '$'
F0034F10: b0100010                 mov     %l0, %i0
F0034F14: 81c7e008                 ret
F0034F18: 81e80000                 restore
