F0038B30: 9de3bf98                 save    %sp, -0x68, %sp
F0038B34: a2100018                 mov     %i0, %l1
F0038B38: b0102000                 mov     0, %i0
F0038B3C: 80a6600b                 cmp     %i1, 0xB
F0038B40: 12800009                 bne     loc_F0038B64
F0038B44: e0046008                 ld      [%l1+8], %l0
F0038B48: 90100011                 mov     %l1, %o0
F0038B4C: 9210001a                 mov     %i2, %o1
F0038B50: 9410001b                 mov     %i3, %o2
F0038B54: 7fffd79e                 call    _in_control
F0038B58: 9610001c                 mov     %i4, %o3
F0038B5C: 1080009e                 ba      locret_F0038DD4
F0038B60: b0100008                 mov     %o0, %i0
F0038B64: 4001784c                 call    _splnet
F0038B68: 01000000                 nop
F0038B6C: 80a72000                 cmp     %i4, 0
F0038B70: 02800006                 be      loc_F0038B88
F0038B74: a4100008                 mov     %o0, %l2
F0038B78: d0572008                 ldsh    [%i4+8], %o0
F0038B7C: 80a22000                 cmp     %o0, 0
F0038B80: 3280008e                 bne,a   loc_F0038DB8
F0038B84: b0102016                 mov     0x16, %i0
F0038B88: 80a42000                 cmp     %l0, 0
F0038B8C: 12800006                 bne     loc_F0038BA4
F0038B90: 80a66015                 cmp     %i1, 0x15
F0038B94: 80a66000                 cmp     %i1, 0
F0038B98: 32800088                 bne,a   loc_F0038DB8
F0038B9C: b0102016                 mov     0x16, %i0
F0038BA0: 80a66015                 cmp     %i1, 0x15! switch 22 cases
F0038BA4: 18800082                 bgu     def_F0038BB8! jumptable F0038BB8 default case, case 11
F0038BA8: 932e6002                 sll     %i1, 2, %o1
F0038BAC: 113c00e2901223c0         set     jpt_F0038BB8, %o0
F0038BB4: d0024008                 ld      [%o1+%o0], %o0
F0038BB8: 81c20000                 jmp     %o0! switch jump
F0038BBC: 01000000                 nop
F0038C18: 80a42000                 cmp     %l0, 0! jumptable F0038BB8 case 0
F0038C1C: 12800067                 bne     loc_F0038DB8
F0038C20: b0102016                 mov     0x16, %i0
F0038C24: 90100011                 mov     %l1, %o0
F0038C28: 133c04d9                 sethi   %hi(_udb), %o1
F0038C2C: 7fffde9c                 call    _in_pcballoc
F0038C30: 92126100                 bset    %lo(_udb), %o1
F0038C34: b0920000                 orcc    %o0, %g0, %i0
F0038C38: 12800060                 bne     loc_F0038DB8
F0038C3C: 113c0432                 sethi   %hi(_udp_sendspace), %o0
F0038C40: d2022190                 ld      [%o0+%lo(_udp_sendspace)], %o1
F0038C44: 113c0432                 sethi   %hi(_udp_recvspace), %o0
F0038C48: d4022194                 ld      [%o0+%lo(_udp_recvspace)], %o2
F0038C4C: 7fff9e0a                 call    _soreserve
F0038C50: 90100011                 mov     %l1, %o0
F0038C54: 10800059                 ba      loc_F0038DB8
F0038C58: b0100008                 mov     %o0, %i0
F0038C5C: 90100010                 mov     %l0, %o0! jumptable F0038BB8 case 2
F0038C60: 7fffdea4                 call    _in_pcbbind
F0038C64: 9210001b                 mov     %i3, %o1
F0038C68: 10800054                 ba      loc_F0038DB8
F0038C6C: b0100008                 mov     %o0, %i0
F0038C70: d004200c                 ld      [%l0+0xC], %o0! jumptable F0038BB8 case 4
F0038C74: 80a22000                 cmp     %o0, 0
F0038C78: 12800050                 bne     loc_F0038DB8
F0038C7C: b0102038                 mov     0x38, %i0 ! '8'
F0038C80: 90100010                 mov     %l0, %o0
F0038C84: 7fffdf18                 call    _in_pcbconnect
F0038C88: 9210001b                 mov     %i3, %o1
F0038C8C: b0920000                 orcc    %o0, %g0, %i0
F0038C90: 1280004a                 bne     loc_F0038DB8
F0038C94: 01000000                 nop
F0038C98: 7fff9ccd                 call    _soisconnected
F0038C9C: 90100011                 mov     %l1, %o0
F0038CA0: 30800046                 ba,a    loc_F0038DB8
F0038CA4: d004200c                 ld      [%l0+0xC], %o0! jumptable F0038BB8 case 6
F0038CA8: 80a22000                 cmp     %o0, 0
F0038CAC: 22800043                 be,a    loc_F0038DB8
F0038CB0: b0102039                 mov     0x39, %i0 ! '9'
F0038CB4: 7fffdfef                 call    _in_pcbdisconnect
F0038CB8: 90100010                 mov     %l0, %o0
F0038CBC: d0146006                 lduh    [%l1+6], %o0
F0038CC0: 900a3ffd                 and     %o0, -3, %o0
F0038CC4: 1080003d                 ba      loc_F0038DB8
F0038CC8: d0346006                 sth     %o0, [%l1+6]
F0038CCC: 7fff9d88                 call    _socantsendmore! jumptable F0038BB8 case 7
F0038CD0: 90100011                 mov     %l1, %o0
F0038CD4: 30800039                 ba,a    loc_F0038DB8
F0038CD8: 80a6e000                 cmp     %i3, 0! jumptable F0038BB8 case 9
F0038CDC: 0280000e                 be      loc_F0038D14
F0038CE0: d004200c                 ld      [%l0+0xC], %o0
F0038CE4: 80a22000                 cmp     %o0, 0
F0038CE8: 02800004                 be      loc_F0038CF8
F0038CEC: e6042014                 ld      [%l0+0x14], %l3
F0038CF0: 10800032                 ba      loc_F0038DB8
F0038CF4: b0102038                 mov     0x38, %i0 ! '8'
F0038CF8: 90100010                 mov     %l0, %o0
F0038CFC: 7fffdefa                 call    _in_pcbconnect
F0038D00: 9210001b                 mov     %i3, %o1
F0038D04: b0920000                 orcc    %o0, %g0, %i0
F0038D08: 1280002c                 bne     loc_F0038DB8
F0038D0C: 90100010                 mov     %l0, %o0
F0038D10: 30800006                 ba,a    loc_F0038D28
F0038D14: 80a22000                 cmp     %o0, 0
F0038D18: 12800004                 bne     loc_F0038D28
F0038D1C: 90100010                 mov     %l0, %o0
F0038D20: 10800026                 ba      loc_F0038DB8
F0038D24: b0102039                 mov     0x39, %i0 ! '9'
F0038D28: 7fffff19                 call    _udp_output
F0038D2C: 9210001a                 mov     %i2, %o1
F0038D30: b0100008                 mov     %o0, %i0
F0038D34: 80a6e000                 cmp     %i3, 0
F0038D38: 02800020                 be      loc_F0038DB8
F0038D3C: b4102000                 mov     0, %i2
F0038D40: 7fffdfcc                 call    _in_pcbdisconnect
F0038D44: 90100010                 mov     %l0, %o0
F0038D48: 1080001c                 ba      loc_F0038DB8
F0038D4C: e6242014                 st      %l3, [%l0+0x14]
F0038D50: 7fff9cd2                 call    _soisdisconnected! jumptable F0038BB8 case 10
F0038D54: 90100011                 mov     %l1, %o0
F0038D58: 7fffdfd2                 call    _in_pcbdetach! jumptable F0038BB8 case 1
F0038D5C: 90100010                 mov     %l0, %o0
F0038D60: 30800016                 ba,a    loc_F0038DB8
F0038D64: 90100010                 mov     %l0, %o0! jumptable F0038BB8 case 15
F0038D68: 7fffdfeb                 call    _in_setsockaddr
F0038D6C: 9210001b                 mov     %i3, %o1
F0038D70: 30800012                 ba,a    loc_F0038DB8
F0038D74: 90100010                 mov     %l0, %o0! jumptable F0038BB8 case 16
F0038D78: 7fffdff7                 call    _in_setpeeraddr
F0038D7C: 9210001b                 mov     %i3, %o1
F0038D80: 3080000e                 ba,a    loc_F0038DB8
F0038D84: 400177e8                 call    _splx! jumptable F0038BB8 case 12
F0038D88: 90100012                 mov     %l2, %o0
F0038D8C: 10800012                 ba      locret_F0038DD4
F0038D90: b0102000                 mov     0, %i0
F0038D94: 10800009                 ba      loc_F0038DB8! jumptable F0038BB8 cases 3,5,14,17-21
F0038D98: b010202d                 mov     0x2D, %i0 ! '-'
F0038D9C: 400177e2                 call    _splx! jumptable F0038BB8 cases 8,13
F0038DA0: 90100012                 mov     %l2, %o0
F0038DA4: 1080000c                 ba      locret_F0038DD4
F0038DA8: b010202d                 mov     0x2D, %i0 ! '-'
F0038DAC: 113c0432                 sethi   %hi(aUdpUsrreq), %o0! jumptable F0038BB8 default case, case 11
F0038DB0: 7fff70f0                 call    _panic
F0038DB4: 90122198                 bset    %lo(aUdpUsrreq), %o0! "udp_usrreq"
F0038DB8: 400177db                 call    _splx
F0038DBC: 90100012                 mov     %l2, %o0
F0038DC0: 80a6a000                 cmp     %i2, 0
F0038DC4: 02800004                 be      locret_F0038DD4
F0038DC8: 01000000                 nop
F0038DCC: 7fff93a6                 call    _m_freem
F0038DD0: 9010001a                 mov     %i2, %o0
F0038DD4: 81c7e008                 ret
F0038DD8: 81e80000                 restore
