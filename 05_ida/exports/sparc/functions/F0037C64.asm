F0037C64: 9de3bf98                 save    %sp, -0x68, %sp
F0037C68: a2100018                 mov     %i0, %l1
F0037C6C: 9610001c                 mov     %i4, %o3
F0037C70: 80a6600b                 cmp     %i1, 0xB
F0037C74: 12800008                 bne     loc_F0037C94
F0037C78: b0102000                 mov     0, %i0
F0037C7C: 90100011                 mov     %l1, %o0
F0037C80: 9210001a                 mov     %i2, %o1
F0037C84: 7fffdb52                 call    _in_control
F0037C88: 9410001b                 mov     %i3, %o2
F0037C8C: 10800125                 ba      locret_F0038120
F0037C90: b0100008                 mov     %o0, %i0
F0037C94: 80a2e000                 cmp     %o3, 0
F0037C98: 02800008                 be      loc_F0037CB8
F0037C9C: 01000000                 nop
F0037CA0: d052e008                 ldsh    [%o3+8], %o0
F0037CA4: 80a22000                 cmp     %o0, 0
F0037CA8: 02800004                 be      loc_F0037CB8
F0037CAC: 01000000                 nop
F0037CB0: 1080011c                 ba      locret_F0038120
F0037CB4: b0102016                 mov     0x16, %i0
F0037CB8: 40017bf7                 call    _splnet
F0037CBC: 01000000                 nop
F0037CC0: f8046008                 ld      [%l1+8], %i4
F0037CC4: 80a72000                 cmp     %i4, 0
F0037CC8: 12800008                 bne     loc_F0037CE8
F0037CCC: a4100008                 mov     %o0, %l2
F0037CD0: 80a66000                 cmp     %i1, 0
F0037CD4: 02800005                 be      loc_F0037CE8
F0037CD8: 80a72000                 cmp     %i4, 0
F0037CDC: 40017c12                 call    _splx
F0037CE0: b0102016                 mov     0x16, %i0
F0037CE4: 3080010f                 ba,a    locret_F0038120
F0037CE8: 02800004                 be      loc_F0037CF8
F0037CEC: a6102000                 mov     0, %l3
F0037CF0: e0072020                 ld      [%i4+0x20], %l0
F0037CF4: e6542008                 ldsh    [%l0+8], %l3
F0037CF8: 80a66013                 cmp     %i1, 0x13! switch 20 cases
F0037CFC: 188000f8                 bgu     def_F0037D10! jumptable F0037D10 default case, cases 11,18
F0037D00: 932e6002                 sll     %i1, 2, %o1
F0037D04: 113c00df90122118         set     jpt_F0037D10, %o0
F0037D0C: d0024008                 ld      [%o1+%o0], %o0
F0037D10: 81c20000                 jmp     %o0! switch jump
F0037D14: 01000000                 nop
F0037D68: 80a72000                 cmp     %i4, 0! jumptable F0037D10 case 0
F0037D6C: 128000df                 bne     loc_F00380E8
F0037D70: b0102038                 mov     0x38, %i0 ! '8'
F0037D74: 40000135                 call    _tcp_attach
F0037D78: 90100011                 mov     %l1, %o0
F0037D7C: b0920000                 orcc    %o0, %g0, %i0
F0037D80: 128000db                 bne     loc_F00380EC
F0037D84: 80a42000                 cmp     %l0, 0
F0037D88: d0146002                 lduh    [%l1+2], %o0
F0037D8C: 808a2080                 btst    0x80, %o0
F0037D90: 22800009                 be,a    loc_F0037DB4
F0037D94: d0046008                 ld      [%l1+8], %o0
F0037D98: d0546004                 ldsh    [%l1+4], %o0
F0037D9C: 80a22000                 cmp     %o0, 0
F0037DA0: 32800005                 bne,a   loc_F0037DB4
F0037DA4: d0046008                 ld      [%l1+8], %o0
F0037DA8: 90102078                 mov     0x78, %o0 ! 'x'
F0037DAC: d0346004                 sth     %o0, [%l1+4]
F0037DB0: d0046008                 ld      [%l1+8], %o0
F0037DB4: 108000cd                 ba      loc_F00380E8
F0037DB8: e0022020                 ld      [%o0+0x20], %l0
F0037DBC: d0542008                 ldsh    [%l0+8], %o0! jumptable F0037D10 case 1
F0037DC0: 80a22001                 cmp     %o0, 1
F0037DC4: 1480004a                 bg      loc_F0037EEC! jumptable F0037D10 case 6
F0037DC8: 01000000                 nop
F0037DCC: 7ffffdf8                 call    _tcp_close
F0037DD0: 90100010                 mov     %l0, %o0
F0037DD4: 108000c5                 ba      loc_F00380E8
F0037DD8: a0100008                 mov     %o0, %l0
F0037DDC: 9010001c                 mov     %i4, %o0! jumptable F0037D10 case 2
F0037DE0: 7fffe244                 call    _in_pcbbind
F0037DE4: 9210001b                 mov     %i3, %o1
F0037DE8: 108000c0                 ba      loc_F00380E8
F0037DEC: b0100008                 mov     %o0, %i0
F0037DF0: d0172018                 lduh    [%i4+0x18], %o0! jumptable F0037D10 case 3
F0037DF4: 80a22000                 cmp     %o0, 0
F0037DF8: 12800006                 bne     loc_F0037E10
F0037DFC: 80a62000                 cmp     %i0, 0
F0037E00: 9010001c                 mov     %i4, %o0
F0037E04: 7fffe23b                 call    _in_pcbbind
F0037E08: 92102000                 mov     0, %o1
F0037E0C: b0920000                 orcc    %o0, %g0, %i0
F0037E10: 128000b7                 bne     loc_F00380EC
F0037E14: 80a42000                 cmp     %l0, 0
F0037E18: 90102001                 mov     1, %o0
F0037E1C: 108000b4                 ba      loc_F00380EC
F0037E20: d0342008                 sth     %o0, [%l0+8]
F0037E24: d0172018                 lduh    [%i4+0x18], %o0! jumptable F0037D10 case 4
F0037E28: 80a22000                 cmp     %o0, 0
F0037E2C: 12800008                 bne     loc_F0037E4C
F0037E30: 9010001c                 mov     %i4, %o0
F0037E34: 7fffe22f                 call    _in_pcbbind
F0037E38: 92102000                 mov     0, %o1
F0037E3C: b0920000                 orcc    %o0, %g0, %i0
F0037E40: 128000ab                 bne     loc_F00380EC
F0037E44: 80a42000                 cmp     %l0, 0
F0037E48: 9010001c                 mov     %i4, %o0
F0037E4C: 7fffe2a6                 call    _in_pcbconnect
F0037E50: 9210001b                 mov     %i3, %o1
F0037E54: b0920000                 orcc    %o0, %g0, %i0
F0037E58: 128000a5                 bne     loc_F00380EC
F0037E5C: 80a42000                 cmp     %l0, 0
F0037E60: 7ffffcf8                 call    _tcp_template
F0037E64: 90100010                 mov     %l0, %o0
F0037E68: 80a22000                 cmp     %o0, 0
F0037E6C: 12800006                 bne     loc_F0037E84
F0037E70: d024201c                 st      %o0, [%l0+0x1C]
F0037E74: 7fffe37f                 call    _in_pcbdisconnect
F0037E78: 9010001c                 mov     %i4, %o0
F0037E7C: 1080009b                 ba      loc_F00380E8
F0037E80: b0102037                 mov     0x37, %i0 ! '7'
F0037E84: 7fffa049                 call    _soisconnecting
F0037E88: 90100011                 mov     %l1, %o0
F0037E8C: 153c04e9                 sethi   %hi(_tcpstat), %o2
F0037E90: 90100010                 mov     %l0, %o0
F0037E94: d202a3a0                 ld      [%o2+%lo(_tcpstat)], %o1
F0037E98: 173c04e9                 sethi   %hi(_tcp_iss), %o3
F0037E9C: 92026001                 inc     %o1
F0037EA0: d222a3a0                 st      %o1, [%o2+%lo(_tcpstat)]
F0037EA4: 92102002                 mov     2, %o1
F0037EA8: d2342008                 sth     %o1, [%l0+8]
F0037EAC: 92102096                 mov     0x96, %o1
F0037EB0: d234200e                 sth     %o1, [%l0+0xE]
F0037EB4: 1300003e                 sethi   0xF800, %o1
F0037EB8: d402e398                 ld      [%o3+%lo(_tcp_iss)], %o2
F0037EBC: 92126200                 bset    0x200, %o1
F0037EC0: d4242038                 st      %o2, [%l0+0x38]
F0037EC4: 94028009                 add     %o2, %o1, %o2
F0037EC8: d2042038                 ld      [%l0+0x38], %o1
F0037ECC: d422e398                 st      %o2, [%o3+%lo(_tcp_iss)]
F0037ED0: d224202c                 st      %o1, [%l0+0x2C]
F0037ED4: d2242050                 st      %o1, [%l0+0x50]
F0037ED8: d2242028                 st      %o1, [%l0+0x28]
F0037EDC: 10800023                 ba      loc_F0037F68
F0037EE0: d2242024                 st      %o1, [%l0+0x24]
F0037EE4: 10800081                 ba      loc_F00380E8! jumptable F0037D10 case 17
F0037EE8: b010202d                 mov     0x2D, %i0 ! '-'
F0037EEC: 40000105                 call    _tcp_disconnect! jumptable F0037D10 case 6
F0037EF0: 90100010                 mov     %l0, %o0
F0037EF4: 1080007d                 ba      loc_F00380E8
F0037EF8: a0100008                 mov     %o0, %l0
F0037EFC: 90102010                 mov     0x10, %o0! jumptable F0037D10 case 5
F0037F00: d036e008                 sth     %o0, [%i3+8]
F0037F04: d206e004                 ld      [%i3+4], %o1
F0037F08: 90102002                 mov     2, %o0
F0037F0C: d036c009                 sth     %o0, [%i3+%o1]
F0037F10: d0172010                 lduh    [%i4+0x10], %o0
F0037F14: 9206c009                 add     %i3, %o1, %o1
F0037F18: d0326002                 sth     %o0, [%o1+2]
F0037F1C: d007200c                 ld      [%i4+0xC], %o0
F0037F20: 10800072                 ba      loc_F00380E8
F0037F24: d0226004                 st      %o0, [%o1+4]
F0037F28: 7fffa0f1                 call    _socantsendmore! jumptable F0037D10 case 7
F0037F2C: 90100011                 mov     %l1, %o0
F0037F30: 40000117                 call    _tcp_usrclosed
F0037F34: 90100010                 mov     %l0, %o0
F0037F38: a0920000                 orcc    %o0, %g0, %l0
F0037F3C: 0280006c                 be      loc_F00380EC
F0037F40: 01000000                 nop
F0037F44: 30800009                 ba,a    loc_F0037F68
F0037F48: 7ffffa8e                 call    _tcp_output! jumptable F0037D10 case 8
F0037F4C: 90100010                 mov     %l0, %o0
F0037F50: 10800067                 ba      loc_F00380EC
F0037F54: 80a42000                 cmp     %l0, 0
F0037F58: 9004603c                 add     %l1, 0x3C, %o0 ! '<'! jumptable F0037D10 case 9
F0037F5C: 7fffa17b                 call    _sbappend
F0037F60: 9210001a                 mov     %i2, %o1
F0037F64: 90100010                 mov     %l0, %o0
F0037F68: 7ffffa86                 call    _tcp_output
F0037F6C: 01000000                 nop
F0037F70: 1080005e                 ba      loc_F00380E8
F0037F74: b0100008                 mov     %o0, %i0
F0037F78: 90100010                 mov     %l0, %o0! jumptable F0037D10 case 10
F0037F7C: 7ffffd6c                 call    _tcp_drop
F0037F80: 92102035                 mov     0x35, %o1 ! '5'
F0037F84: 10800059                 ba      loc_F00380E8
F0037F88: a0100008                 mov     %o0, %l0
F0037F8C: d214603e                 lduh    [%l1+0x3E], %o1! jumptable F0037D10 case 12
F0037F90: 90100012                 mov     %l2, %o0
F0037F94: 40017b64                 call    _splx
F0037F98: d226a030                 st      %o1, [%i2+0x30]
F0037F9C: 10800061                 ba      locret_F0038120
F0037FA0: b0102000                 mov     0, %i0
F0037FA4: d0146058                 lduh    [%l1+0x58], %o0! jumptable F0037D10 case 13
F0037FA8: 80a22000                 cmp     %o0, 0
F0037FAC: 32800007                 bne,a   loc_F0037FC8
F0037FB0: d0146002                 lduh    [%l1+2], %o0
F0037FB4: d0146006                 lduh    [%l1+6], %o0
F0037FB8: 808a2040                 btst    0x40, %o0 ! '@'
F0037FBC: 2280004b                 be,a    loc_F00380E8
F0037FC0: b0102016                 mov     0x16, %i0
F0037FC4: d0146002                 lduh    [%l1+2], %o0
F0037FC8: 808a2100                 btst    0x100, %o0
F0037FCC: 32800047                 bne,a   loc_F00380E8
F0037FD0: b0102016                 mov     0x16, %i0
F0037FD4: d00c2068                 ldub    [%l0+0x68], %o0
F0037FD8: 808a2002                 btst    2, %o0
F0037FDC: 02800004                 be      loc_F0037FEC
F0037FE0: 808a2001                 btst    1, %o0
F0037FE4: 10800041                 ba      loc_F00380E8
F0037FE8: b0102016                 mov     0x16, %i0
F0037FEC: 32800004                 bne,a   loc_F0037FFC
F0037FF0: 90102001                 mov     1, %o0
F0037FF4: 1080003d                 ba      loc_F00380E8
F0037FF8: b0102023                 mov     0x23, %i0 ! '#'
F0037FFC: d206a004                 ld      [%i2+4], %o1
F0038000: d036a008                 sth     %o0, [%i2+8]
F0038004: d00c2069                 ldub    [%l0+0x69], %o0
F0038008: 808ee002                 btst    2, %i3
F003800C: 12800037                 bne     loc_F00380E8
F0038010: d02e8009                 stb     %o0, [%i2+%o1]
F0038014: d00c2068                 ldub    [%l0+0x68], %o0
F0038018: 901a2003                 btog    3, %o0
F003801C: 10800033                 ba      loc_F00380E8
F0038020: d02c2068                 stb     %o0, [%l0+0x68]
F0038024: d6146042                 lduh    [%l1+0x42], %o3! jumptable F0037D10 case 14
F0038028: d414603e                 lduh    [%l1+0x3E], %o2
F003802C: d014603c                 lduh    [%l1+0x3C], %o0
F0038030: d2146040                 lduh    [%l1+0x40], %o1
F0038034: 94228008                 sub     %o2, %o0, %o2
F0038038: 9622c009                 sub     %o3, %o1, %o3
F003803C: 80a2800b                 cmp     %o2, %o3
F0038040: 34800002                 bg,a    loc_F0038048
F0038044: 9410000b                 mov     %o3, %o2
F0038048: 80a2be00                 cmp     %o2, -0x200
F003804C: 16800006                 bge     loc_F0038064
F0038050: 9004603c                 add     %l1, 0x3C, %o0 ! '<'
F0038054: 7fff9704                 call    _m_freem
F0038058: 9010001a                 mov     %i2, %o0
F003805C: 10800023                 ba      loc_F00380E8
F0038060: b0102037                 mov     0x37, %i0 ! '7'
F0038064: 7fffa139                 call    _sbappend
F0038068: 9210001a                 mov     %i2, %o1
F003806C: d214603c                 lduh    [%l1+0x3C], %o1
F0038070: d4042024                 ld      [%l0+0x24], %o2
F0038074: 90100010                 mov     %l0, %o0
F0038078: 94028009                 add     %o2, %o1, %o2
F003807C: d424202c                 st      %o2, [%l0+0x2C]
F0038080: 92102001                 mov     1, %o1
F0038084: 7ffffa3f                 call    _tcp_output
F0038088: d22c201a                 stb     %o1, [%l0+0x1A]
F003808C: b0100008                 mov     %o0, %i0
F0038090: 10800016                 ba      loc_F00380E8
F0038094: c02c201a                 clrb    [%l0+0x1A]
F0038098: 9010001c                 mov     %i4, %o0! jumptable F0037D10 case 15
F003809C: 7fffe31e                 call    _in_setsockaddr
F00380A0: 9210001b                 mov     %i3, %o1
F00380A4: 10800012                 ba      loc_F00380EC
F00380A8: 80a42000                 cmp     %l0, 0
F00380AC: 9010001c                 mov     %i4, %o0! jumptable F0037D10 case 16
F00380B0: 7fffe329                 call    _in_setpeeraddr
F00380B4: 9210001b                 mov     %i3, %o1
F00380B8: 1080000d                 ba      loc_F00380EC
F00380BC: 80a42000                 cmp     %l0, 0
F00380C0: 90100010                 mov     %l0, %o0! jumptable F0037D10 case 19
F00380C4: 7ffffe36                 call    _tcp_timers
F00380C8: 9210001b                 mov     %i3, %o1
F00380CC: a0100008                 mov     %o0, %l0
F00380D0: 912ee008                 sll     %i3, 8, %o0
F00380D4: 10800005                 ba      loc_F00380E8
F00380D8: b2164008                 bset    %o0, %i1
F00380DC: 113c0432                 sethi   %hi(aTcpUsrreq), %o0! jumptable F0037D10 default case, cases 11,18
F00380E0: 7fff7424                 call    _panic
F00380E4: 90122158                 bset    %lo(aTcpUsrreq), %o0! "tcp_usrreq"
F00380E8: 80a42000                 cmp     %l0, 0
F00380EC: 0280000b                 be      loc_F0038118
F00380F0: 01000000                 nop
F00380F4: d0146002                 lduh    [%l1+2], %o0
F00380F8: 808a2001                 btst    1, %o0
F00380FC: 02800007                 be      loc_F0038118
F0038100: 90102002                 mov     2, %o0
F0038104: 92100013                 mov     %l3, %o1
F0038108: 94100010                 mov     %l0, %o2
F003810C: 96102000                 mov     0, %o3
F0038110: 7ffff29c                 call    _tcp_trace
F0038114: 98100019                 mov     %i1, %o4
F0038118: 40017b03                 call    _splx
F003811C: 90100012                 mov     %l2, %o0
F0038120: 81c7e008                 ret
F0038124: 81e80000                 restore
