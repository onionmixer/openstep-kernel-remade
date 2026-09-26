F0034F1C: 9de3bf90                 save    %sp, -0x70, %sp
F0034F20: ae102000                 mov     0, %l7
F0034F24: a2102000                 mov     0, %l1
F0034F28: b6102000                 mov     0, %i3
F0034F2C: 113c04e9a01223a0         set     _tcpstat, %l0
F0034F34: d0042064                 ld      [%l0+0x64], %o0
F0034F38: b4102000                 mov     0, %i2
F0034F3C: 90022001                 inc     %o0
F0034F40: d0242064                 st      %o0, [%l0+0x64]
F0034F44: d2062004                 ld      [%i0+4], %o1
F0034F48: b2102000                 mov     0, %i1
F0034F4C: d00e0009                 ldub    [%i0+%o1], %o0
F0034F50: 900a200f                 and     %o0, 0xF, %o0
F0034F54: 80a22005                 cmp     %o0, 5
F0034F58: 08800005                 bleu    loc_F0034F6C
F0034F5C: a4060009                 add     %i0, %o1, %l2
F0034F60: 90100012                 mov     %l2, %o0
F0034F64: 7ffff7ec                 call    _ip_stripoptions
F0034F68: 92102000                 mov     0, %o1
F0034F6C: d0162008                 lduh    [%i0+8], %o0
F0034F70: 80a22027                 cmp     %o0, 0x27 ! '''
F0034F74: 1880000c                 bgu     loc_F0034FA4
F0034F78: 90100018                 mov     %i0, %o0
F0034F7C: 7fffa456                 call    _m_pullup
F0034F80: 92102028                 mov     0x28, %o1 ! '('
F0034F84: b0920000                 orcc    %o0, %g0, %i0
F0034F88: 32800006                 bne,a   loc_F0034FA0
F0034F8C: d0062004                 ld      [%i0+4], %o0
F0034F90: d0042078                 ld      [%l0+0x78], %o0
F0034F94: 90022001                 inc     %o0
F0034F98: 10800588                 ba      locret_F00365B8
F0034F9C: d0242078                 st      %o0, [%l0+0x78]
F0034FA0: a4060008                 add     %i0, %o0, %l2
F0034FA4: e054a002                 ldsh    [%l2+2], %l0
F0034FA8: c024a004                 clr     [%l2+4]
F0034FAC: c02ca008                 clrb    [%l2+8]
F0034FB0: 90100018                 mov     %i0, %o0
F0034FB4: c0248000                 clr     [%l2]
F0034FB8: e034a00a                 sth     %l0, [%l2+0xA]
F0034FBC: 40018fb3                 call    _in_cksum
F0034FC0: 92042014                 add     %l0, 0x14, %o1
F0034FC4: d034a024                 sth     %o0, [%l2+0x24]
F0034FC8: 912a2010                 sll     %o0, 16, %o0
F0034FCC: 80a22000                 cmp     %o0, 0
F0034FD0: 02800007                 be      loc_F0034FEC
F0034FD4: 133c04e9                 sethi   %hi(_tcpstat), %o1
F0034FD8: 921263a0                 bset    %lo(_tcpstat), %o1
F0034FDC: d0026070                 ld      [%o1+0x70], %o0
F0034FE0: 90022001                 inc     %o0
F0034FE4: 10800559                 ba      loc_F0036548
F0034FE8: d0226070                 st      %o0, [%o1+0x70]
F0034FEC: d004a020                 ld      [%l2+0x20], %o0
F0034FF0: 9132201c                 srl     %o0, 28, %o0
F0034FF4: a72a2002                 sll     %o0, 2, %l3
F0034FF8: 80a4e013                 cmp     %l3, 0x13
F0034FFC: 08800004                 bleu    loc_F003500C
F0035000: 80a4c010                 cmp     %l3, %l0
F0035004: 04800008                 ble     loc_F0035024
F0035008: a0240013                 sub     %l0, %l3, %l0
F003500C: 133c04e9921263a0         set     _tcpstat, %o1
F0035014: d0026074                 ld      [%o1+0x74], %o0
F0035018: 90022001                 inc     %o0
F003501C: 1080054b                 ba      loc_F0036548
F0035020: d0226074                 st      %o0, [%o1+0x74]
F0035024: 80a4e014                 cmp     %l3, 0x14
F0035028: 0880002c                 bleu    loc_F00350D8
F003502C: e034a00a                 sth     %l0, [%l2+0xA]
F0035030: d0562008                 ldsh    [%i0+8], %o0
F0035034: 9204e014                 add     %l3, 0x14, %o1
F0035038: 80a20009                 cmp     %o0, %o1
F003503C: 1a80000f                 bcc     loc_F0035078
F0035040: 90102000                 mov     0, %o0
F0035044: 7fffa424                 call    _m_pullup
F0035048: 90100018                 mov     %i0, %o0
F003504C: b0920000                 orcc    %o0, %g0, %i0
F0035050: 32800008                 bne,a   loc_F0035070
F0035054: d0062004                 ld      [%i0+4], %o0
F0035058: 133c04e9921263a0         set     _tcpstat, %o1
F0035060: d0026078                 ld      [%o1+0x78], %o0
F0035064: 90022001                 inc     %o0
F0035068: 10800554                 ba      locret_F00365B8
F003506C: d0226078                 st      %o0, [%o1+0x78]
F0035070: a4060008                 add     %i0, %o0, %l2
F0035074: 90102000                 mov     0, %o0
F0035078: 7fffa239                 call    _m_get
F003507C: 92102001                 mov     1, %o1
F0035080: ae920000                 orcc    %o0, %g0, %l7
F0035084: 02800532                 be      loc_F003654C
F0035088: 9404ffec                 add     %l3, -0x14, %o2! size_t
F003508C: d435e008                 sth     %o2, [%l7+8]
F0035090: e0062004                 ld      [%i0+4], %l0
F0035094: d205e004                 ld      [%l7+4], %o1! void *
F0035098: a0060010                 add     %i0, %l0, %l0
F003509C: a0042028                 inc     0x28, %l0 ! '('
F00350A0: 90100010                 mov     %l0, %o0! void *
F00350A4: 40017e9b                 call    _bcopy
F00350A8: 9205c009                 add     %l7, %o1, %o1
F00350AC: d4162008                 lduh    [%i0+8], %o2
F00350B0: d015e008                 lduh    [%l7+8], %o0
F00350B4: 92100010                 mov     %l0, %o1! void *
F00350B8: 94228008                 sub     %o2, %o0, %o2
F00350BC: d4362008                 sth     %o2, [%i0+8]
F00350C0: 952aa010                 sll     %o2, 16, %o2
F00350C4: 953aa010                 sra     %o2, 16, %o2
F00350C8: d055e008                 ldsh    [%l7+8], %o0! void *
F00350CC: 9402bfd8                 inc     -0x28, %o2! size_t
F00350D0: 40017e90                 call    _bcopy
F00350D4: 90024008                 add     %o1, %o0, %o0
F00350D8: ea0ca021                 ldub    [%l2+0x21], %l5
F00350DC: d004a018                 ld      [%l2+0x18], %o0
F00350E0: d204a01c                 ld      [%l2+0x1C], %o1
F00350E4: d414a022                 lduh    [%l2+0x22], %o2
F00350E8: d024a018                 st      %o0, [%l2+0x18]
F00350EC: d224a01c                 st      %o1, [%l2+0x1C]
F00350F0: d014a026                 lduh    [%l2+0x26], %o0
F00350F4: d434a022                 sth     %o2, [%l2+0x22]
F00350F8: d034a026                 sth     %o0, [%l2+0x26]
F00350FC: 113c0432                 sethi   %hi(_tcp_last_inpcb), %o0
F0035100: e60220ac                 ld      [%o0+%lo(_tcp_last_inpcb)], %l3
F0035104: d214e018                 lduh    [%l3+0x18], %o1
F0035108: d014a016                 lduh    [%l2+0x16], %o0
F003510C: 80a24008                 cmp     %o1, %o0
F0035110: 12800011                 bne     loc_F0035154
F0035114: 113c04d9                 sethi   -0xFEC9C00, %o0
F0035118: d214e010                 lduh    [%l3+0x10], %o1
F003511C: d014a014                 lduh    [%l2+0x14], %o0
F0035120: 80a24008                 cmp     %o1, %o0
F0035124: 1280000c                 bne     loc_F0035154
F0035128: 113c04d9                 sethi   -0xFEC9C00, %o0
F003512C: d204e00c                 ld      [%l3+0xC], %o1
F0035130: d004a00c                 ld      [%l2+0xC], %o0
F0035134: 80a24008                 cmp     %o1, %o0
F0035138: 12800007                 bne     loc_F0035154
F003513C: 113c04d9                 sethi   -0xFEC9C00, %o0
F0035140: d204e014                 ld      [%l3+0x14], %o1
F0035144: d004a010                 ld      [%l2+0x10], %o0
F0035148: 80a24008                 cmp     %o1, %o0
F003514C: 02800015                 be      loc_F00351A0
F0035150: 113c04d9                 sethi   -0xFEC9C00, %o0
F0035154: d204a00c                 ld      [%l2+0xC], %o1
F0035158: 90122340                 bset    0x340, %o0
F003515C: d227bff4                 st      %o1, [%fp+var_C]
F0035160: d404a010                 ld      [%l2+0x10], %o2
F0035164: 9607bff0                 add     %fp, var_10, %o3
F0035168: d427bff0                 st      %o2, [%fp+var_10]
F003516C: d414a014                 lduh    [%l2+0x14], %o2
F0035170: 9a102001                 mov     1, %o5
F0035174: d814a016                 lduh    [%l2+0x16], %o4
F0035178: 7fffef74                 call    _in_pcblookup
F003517C: 9207bff4                 add     %fp, var_C, %o1
F0035180: a6920000                 orcc    %o0, %g0, %l3
F0035184: 02800003                 be      loc_F0035190
F0035188: 113c0432                 sethi   %hi(_tcp_last_inpcb), %o0
F003518C: e62220ac                 st      %l3, [%o0+%lo(_tcp_last_inpcb)]
F0035190: 133c04ea                 sethi   %hi(_tcppcbcachemiss), %o1
F0035194: d0026088                 ld      [%o1+%lo(_tcppcbcachemiss)], %o0
F0035198: 90022001                 inc     %o0
F003519C: d0226088                 st      %o0, [%o1+%lo(_tcppcbcachemiss)]
F00351A0: 80a4e000                 cmp     %l3, 0
F00351A4: 028004c0                 be      loc_F00364A4
F00351A8: 80a5e000                 cmp     %l7, 0
F00351AC: e204e020                 ld      [%l3+0x20], %l1
F00351B0: 80a46000                 cmp     %l1, 0
F00351B4: 028004bc                 be      loc_F00364A4
F00351B8: 80a5e000                 cmp     %l7, 0
F00351BC: d0546008                 ldsh    [%l1+8], %o0
F00351C0: 80a22000                 cmp     %o0, 0
F00351C4: 028004e1                 be      loc_F0036548
F00351C8: 94100008                 mov     %o0, %o2
F00351CC: ec04e01c                 ld      [%l3+0x1C], %l6
F00351D0: d015a002                 lduh    [%l6+2], %o0
F00351D4: 808a2003                 btst    3, %o0
F00351D8: 0280002e                 be      loc_F0035290
F00351DC: 808a2001                 btst    1, %o0
F00351E0: 02800019                 be      loc_F0035244
F00351E4: 133c04ea                 sethi   %hi(_tcp_saveti), %o1
F00351E8: d0048000                 ld      [%l2], %o0
F00351EC: d0226060                 st      %o0, [%o1+%lo(_tcp_saveti)]
F00351F0: d004a004                 ld      [%l2+4], %o0
F00351F4: 92126060                 bset    %lo(_tcp_saveti), %o1
F00351F8: d0226004                 st      %o0, [%o1+4]
F00351FC: d004a008                 ld      [%l2+8], %o0
F0035200: d0226008                 st      %o0, [%o1+8]
F0035204: d004a00c                 ld      [%l2+0xC], %o0
F0035208: d022600c                 st      %o0, [%o1+0xC]
F003520C: d004a010                 ld      [%l2+0x10], %o0
F0035210: d0226010                 st      %o0, [%o1+0x10]
F0035214: d004a014                 ld      [%l2+0x14], %o0
F0035218: d0226014                 st      %o0, [%o1+0x14]
F003521C: d004a018                 ld      [%l2+0x18], %o0
F0035220: d0226018                 st      %o0, [%o1+0x18]
F0035224: d004a01c                 ld      [%l2+0x1C], %o0
F0035228: d022601c                 st      %o0, [%o1+0x1C]
F003522C: d004a020                 ld      [%l2+0x20], %o0
F0035230: d0226020                 st      %o0, [%o1+0x20]
F0035234: d004a024                 ld      [%l2+0x24], %o0
F0035238: b810000a                 mov     %o2, %i4
F003523C: d0226024                 st      %o0, [%o1+0x24]
F0035240: d015a002                 lduh    [%l6+2], %o0
F0035244: 808a2002                 btst    2, %o0
F0035248: 02800012                 be      loc_F0035290
F003524C: 90100016                 mov     %l6, %o0
F0035250: 7fffaba1                 call    _sonewconn
F0035254: 92102000                 mov     0, %o1
F0035258: ac920000                 orcc    %o0, %g0, %l6
F003525C: 028004bc                 be      loc_F003654C
F0035260: 80a5e000                 cmp     %l7, 0
F0035264: e605a008                 ld      [%l6+8], %l3
F0035268: d004a010                 ld      [%l2+0x10], %o0
F003526C: d024e014                 st      %o0, [%l3+0x14]
F0035270: d014a016                 lduh    [%l2+0x16], %o0
F0035274: b406a001                 inc     %i2
F0035278: 7ffff6fa                 call    _ip_srcroute
F003527C: d034e018                 sth     %o0, [%l3+0x18]
F0035280: d024e038                 st      %o0, [%l3+0x38]
F0035284: e204e020                 ld      [%l3+0x20], %l1
F0035288: 90102001                 mov     1, %o0
F003528C: d0346008                 sth     %o0, [%l1+8]
F0035290: c0346058                 clrh    [%l1+0x58]
F0035294: 113c0432                 sethi   %hi(_tcp_keepidle), %o0
F0035298: d002211c                 ld      [%o0+%lo(_tcp_keepidle)], %o0
F003529C: 80a5e000                 cmp     %l7, 0
F00352A0: 0280000a                 be      loc_F00352C8
F00352A4: d034600e                 sth     %o0, [%l1+0xE]
F00352A8: d0546008                 ldsh    [%l1+8], %o0
F00352AC: 80a22001                 cmp     %o0, 1
F00352B0: 02800006                 be      loc_F00352C8
F00352B4: 90100011                 mov     %l1, %o0
F00352B8: 92100017                 mov     %l7, %o1
F00352BC: 400004c1                 call    _tcp_dooptions
F00352C0: 94100012                 mov     %l2, %o2
F00352C4: ae102000                 mov     0, %l7
F00352C8: d0546008                 ldsh    [%l1+8], %o0
F00352CC: 80a22004                 cmp     %o0, 4
F00352D0: 32800098                 bne,a   loc_F0035530
F00352D4: d0062004                 ld      [%i0+4], %o0
F00352D8: 900d6037                 and     %l5, 0x37, %o0
F00352DC: 80a22010                 cmp     %o0, 0x10
F00352E0: 32800094                 bne,a   loc_F0035530
F00352E4: d0062004                 ld      [%i0+4], %o0
F00352E8: d204a018                 ld      [%l2+0x18], %o1
F00352EC: d0046040                 ld      [%l1+0x40], %o0
F00352F0: 80a24008                 cmp     %o1, %o0
F00352F4: 3280008f                 bne,a   loc_F0035530
F00352F8: d0062004                 ld      [%i0+4], %o0
F00352FC: d414a022                 lduh    [%l2+0x22], %o2
F0035300: 80a2a000                 cmp     %o2, 0
F0035304: 2280008b                 be,a    loc_F0035530
F0035308: d0062004                 ld      [%i0+4], %o0
F003530C: d014603c                 lduh    [%l1+0x3C], %o0
F0035310: 80a28008                 cmp     %o2, %o0
F0035314: 32800087                 bne,a   loc_F0035530
F0035318: d0062004                 ld      [%i0+4], %o0
F003531C: d6046028                 ld      [%l1+0x28], %o3
F0035320: d0046050                 ld      [%l1+0x50], %o0
F0035324: 80a2c008                 cmp     %o3, %o0
F0035328: 32800082                 bne,a   loc_F0035530
F003532C: d0062004                 ld      [%i0+4], %o0
F0035330: d854a00a                 ldsh    [%l2+0xA], %o4
F0035334: 80a32000                 cmp     %o4, 0
F0035338: 12800047                 bne     loc_F0035454
F003533C: d204a01c                 ld      [%l2+0x1C], %o1
F0035340: d0046024                 ld      [%l1+0x24], %o0
F0035344: 90224008                 sub     %o1, %o0, %o0
F0035348: 80a22000                 cmp     %o0, 0
F003534C: 04800078                 ble     loc_F003552C
F0035350: 9022400b                 sub     %o1, %o3, %o0
F0035354: 80a22000                 cmp     %o0, 0
F0035358: 34800076                 bg,a    loc_F0035530
F003535C: d0062004                 ld      [%i0+4], %o0
F0035360: d0146054                 lduh    [%l1+0x54], %o0
F0035364: 80a2000a                 cmp     %o0, %o2
F0035368: 0a800071                 bcs     loc_F003552C
F003536C: 113c04ea                 sethi   %hi(_tcppredack), %o0
F0035370: d2022090                 ld      [%o0+%lo(_tcppredack)], %o1
F0035374: d454605a                 ldsh    [%l1+0x5A], %o2
F0035378: 92026001                 inc     %o1
F003537C: 80a2a000                 cmp     %o2, 0
F0035380: 0280000a                 be      loc_F00353A8
F0035384: d2222090                 st      %o1, [%o0+%lo(_tcppredack)]
F0035388: d004a01c                 ld      [%l2+0x1C], %o0
F003538C: d204605c                 ld      [%l1+0x5C], %o1
F0035390: 90220009                 sub     %o0, %o1, %o0
F0035394: 80a22000                 cmp     %o0, 0
F0035398: 04800005                 ble     loc_F00353AC
F003539C: 9005a03c                 add     %l6, 0x3C, %o0 ! '<'
F00353A0: 400004d9                 call    _tcp_xmit_timer
F00353A4: 90100011                 mov     %l1, %o0
F00353A8: 9005a03c                 add     %l6, 0x3C, %o0 ! '<'
F00353AC: d804a01c                 ld      [%l2+0x1C], %o4
F00353B0: 173c04e9                 sethi   %hi(_tcpstat), %o3
F00353B4: d2046024                 ld      [%l1+0x24], %o1
F00353B8: 9612e3a0                 bset    %lo(_tcpstat), %o3
F00353BC: d402e0ac                 ld      [%o3+0xAC], %o2
F00353C0: a6230009                 sub     %o4, %o1, %l3
F00353C4: 9402a001                 inc     %o2
F00353C8: d202e0b0                 ld      [%o3+0xB0], %o1
F00353CC: d422e0ac                 st      %o2, [%o3+0xAC]
F00353D0: 92024013                 add     %o1, %l3, %o1
F00353D4: d222e0b0                 st      %o1, [%o3+0xB0]
F00353D8: 7fffadd2                 call    _sbdrop
F00353DC: 92100013                 mov     %l3, %o1
F00353E0: d204a01c                 ld      [%l2+0x1C], %o1
F00353E4: 90100018                 mov     %i0, %o0
F00353E8: 7fffa21f                 call    _m_freem
F00353EC: d2246024                 st      %o1, [%l1+0x24]
F00353F0: d2046024                 ld      [%l1+0x24], %o1
F00353F4: d0046050                 ld      [%l1+0x50], %o0
F00353F8: 80a24008                 cmp     %o1, %o0
F00353FC: 32800004                 bne,a   loc_F003540C
F0035400: d054600c                 ldsh    [%l1+0xC], %o0
F0035404: 10800007                 ba      loc_F0035420
F0035408: c034600a                 clrh    [%l1+0xA]
F003540C: 80a22000                 cmp     %o0, 0
F0035410: 32800005                 bne,a   loc_F0035424
F0035414: d015a050                 lduh    [%l6+0x50], %o0
F0035418: d0146014                 lduh    [%l1+0x14], %o0
F003541C: d034600a                 sth     %o0, [%l1+0xA]
F0035420: d015a050                 lduh    [%l6+0x50], %o0
F0035424: 808a2004                 btst    4, %o0
F0035428: 12800006                 bne     loc_F0035440
F003542C: 90100016                 mov     %l6, %o0
F0035430: d005a04c                 ld      [%l6+0x4C], %o0
F0035434: 80a22000                 cmp     %o0, 0
F0035438: 02800004                 be      loc_F0035448
F003543C: 90100016                 mov     %l6, %o0
F0035440: 7fffabf3                 call    _sowakeup
F0035444: 9205a03c                 add     %l6, 0x3C, %o1 ! '<'
F0035448: d015a03c                 lduh    [%l6+0x3C], %o0
F003544C: 10800405                 ba      loc_F0036460
F0035450: 80a22000                 cmp     %o0, 0
F0035454: d0046024                 ld      [%l1+0x24], %o0
F0035458: 80a24008                 cmp     %o1, %o0
F003545C: 32800035                 bne,a   loc_F0035530
F0035460: d0062004                 ld      [%i0+4], %o0
F0035464: d0044000                 ld      [%l1], %o0
F0035468: 80a20011                 cmp     %o0, %l1
F003546C: 32800031                 bne,a   loc_F0035530
F0035470: d0062004                 ld      [%i0+4], %o0
F0035474: d615a02a                 lduh    [%l6+0x2A], %o3
F0035478: d415a026                 lduh    [%l6+0x26], %o2
F003547C: d015a024                 lduh    [%l6+0x24], %o0
F0035480: d215a028                 lduh    [%l6+0x28], %o1
F0035484: 94228008                 sub     %o2, %o0, %o2
F0035488: 9622c009                 sub     %o3, %o1, %o3
F003548C: 80a2800b                 cmp     %o2, %o3
F0035490: 34800002                 bg,a    loc_F0035498
F0035494: 9410000b                 mov     %o3, %o2
F0035498: 80a3000a                 cmp     %o4, %o2
F003549C: 34800025                 bg,a    loc_F0035530
F00354A0: d0062004                 ld      [%i0+4], %o0
F00354A4: 193c04e9                 sethi   %hi(_tcpstat), %o4
F00354A8: d254a00a                 ldsh    [%l2+0xA], %o1
F00354AC: 981323a0                 bset    %lo(_tcpstat), %o4
F00354B0: d0046040                 ld      [%l1+0x40], %o0
F00354B4: a005a024                 add     %l6, 0x24, %l0 ! '$'
F00354B8: 90020009                 add     %o0, %o1, %o0
F00354BC: d0246040                 st      %o0, [%l1+0x40]
F00354C0: d2032068                 ld      [%o4+0x68], %o1
F00354C4: 1b3c04ea                 sethi   %hi(_tcppreddat), %o5
F00354C8: d403206c                 ld      [%o4+0x6C], %o2
F00354CC: 92026001                 inc     %o1
F00354D0: d2232068                 st      %o1, [%o4+0x68]
F00354D4: d654a00a                 ldsh    [%l2+0xA], %o3
F00354D8: 92100018                 mov     %i0, %o1
F00354DC: 9402800b                 add     %o2, %o3, %o2
F00354E0: d6036098                 ld      [%o5+%lo(_tcppreddat)], %o3
F00354E4: d423206c                 st      %o2, [%o4+0x6C]
F00354E8: d8026004                 ld      [%o1+4], %o4
F00354EC: 90100010                 mov     %l0, %o0
F00354F0: d4126008                 lduh    [%o1+8], %o2
F00354F4: 9602e001                 inc     %o3
F00354F8: d6236098                 st      %o3, [%o5+%lo(_tcppreddat)]
F00354FC: 98032028                 inc     0x28, %o4 ! '('
F0035500: d8226004                 st      %o4, [%o1+4]
F0035504: 9402bfd8                 inc     -0x28, %o2
F0035508: 7fffac10                 call    _sbappend
F003550C: d4326008                 sth     %o2, [%o1+8]
F0035510: 90100016                 mov     %l6, %o0
F0035514: 7fffabbe                 call    _sowakeup
F0035518: 92100010                 mov     %l0, %o1
F003551C: d00c601b                 ldub    [%l1+0x1B], %o0
F0035520: 90122002                 bset    2, %o0
F0035524: 10800425                 ba      locret_F00365B8
F0035528: d02c601b                 stb     %o0, [%l1+0x1B]
F003552C: d0062004                 ld      [%i0+4], %o0
F0035530: d2162008                 lduh    [%i0+8], %o1
F0035534: 90022028                 inc     0x28, %o0 ! '('
F0035538: d0262004                 st      %o0, [%i0+4]
F003553C: 92027fd8                 inc     -0x28, %o1
F0035540: d2362008                 sth     %o1, [%i0+8]
F0035544: d615a02a                 lduh    [%l6+0x2A], %o3
F0035548: d415a026                 lduh    [%l6+0x26], %o2
F003554C: d015a024                 lduh    [%l6+0x24], %o0
F0035550: d215a028                 lduh    [%l6+0x28], %o1
F0035554: 94228008                 sub     %o2, %o0, %o2
F0035558: 9622c009                 sub     %o3, %o1, %o3
F003555C: 80a2800b                 cmp     %o2, %o3
F0035560: 34800002                 bg,a    loc_F0035568
F0035564: 9410000b                 mov     %o3, %o2
F0035568: 80a2a000                 cmp     %o2, 0
F003556C: 26800002                 bl,a    loc_F0035574
F0035570: 94102000                 mov     0, %o2
F0035574: d204604c                 ld      [%l1+0x4C], %o1
F0035578: d0046040                 ld      [%l1+0x40], %o0
F003557C: 92224008                 sub     %o1, %o0, %o1
F0035580: 80a28009                 cmp     %o2, %o1
F0035584: 14800003                 bg      loc_F0035590
F0035588: 9610000a                 mov     %o2, %o3
F003558C: 96100009                 mov     %o1, %o3
F0035590: d0546008                 ldsh    [%l1+8], %o0
F0035594: 80a22001                 cmp     %o0, 1
F0035598: 02800009                 be      loc_F00355BC
F003559C: d634603e                 sth     %o3, [%l1+0x3E]
F00355A0: 80a22001                 cmp     %o0, 1
F00355A4: 068000d4                 bl      loc_F00358F4
F00355A8: 80a22003                 cmp     %o0, 3
F00355AC: 348000d3                 bg,a    loc_F00358F8
F00355B0: d0046040                 ld      [%l1+0x40], %o0
F00355B4: 10800069                 ba      loc_F0035758
F00355B8: 948d6010                 andcc   %l5, 0x10, %o2
F00355BC: 808d6004                 btst    4, %l5
F00355C0: 128003e3                 bne     loc_F003654C
F00355C4: 80a5e000                 cmp     %l7, 0
F00355C8: 808d6010                 btst    0x10, %l5
F00355CC: 128003b6                 bne     loc_F00364A4
F00355D0: 80a5e000                 cmp     %l7, 0
F00355D4: 808d6002                 btst    2, %l5
F00355D8: 028003dc                 be      loc_F0036548
F00355DC: 9007bff0                 add     %fp, var_10, %o0
F00355E0: d204a010                 ld      [%l2+0x10], %o1
F00355E4: 7fffe749                 call    _in_broadcast
F00355E8: d227bff0                 st      %o1, [%fp+var_10]
F00355EC: 80a22000                 cmp     %o0, 0
F00355F0: 128003d7                 bne     loc_F003654C
F00355F4: 80a5e000                 cmp     %l7, 0
F00355F8: 90102000                 mov     0, %o0
F00355FC: 7fffa0d8                 call    _m_get
F0035600: 92102008                 mov     8, %o1
F0035604: a0920000                 orcc    %o0, %g0, %l0
F0035608: 028003d0                 be      loc_F0036548
F003560C: 90102010                 mov     0x10, %o0
F0035610: d0342008                 sth     %o0, [%l0+8]
F0035614: d2042004                 ld      [%l0+4], %o1
F0035618: 90102002                 mov     2, %o0
F003561C: d0340009                 sth     %o0, [%l0+%o1]
F0035620: d004a00c                 ld      [%l2+0xC], %o0
F0035624: 92040009                 add     %l0, %o1, %o1
F0035628: d0226004                 st      %o0, [%o1+4]
F003562C: d014a014                 lduh    [%l2+0x14], %o0
F0035630: d0326002                 sth     %o0, [%o1+2]
F0035634: e804e014                 ld      [%l3+0x14], %l4
F0035638: 80a52000                 cmp     %l4, 0
F003563C: 12800005                 bne     loc_F0035650
F0035640: 90100013                 mov     %l3, %o0
F0035644: d004a010                 ld      [%l2+0x10], %o0
F0035648: d024e014                 st      %o0, [%l3+0x14]
F003564C: 90100013                 mov     %l3, %o0
F0035650: 7fffeca5                 call    _in_pcbconnect
F0035654: 92100010                 mov     %l0, %o1
F0035658: 80a22000                 cmp     %o0, 0
F003565C: 02800007                 be      loc_F0035678
F0035660: 01000000                 nop
F0035664: e824e014                 st      %l4, [%l3+0x14]
F0035668: 7fffa113                 call    _m_free
F003566C: 90100010                 mov     %l0, %o0
F0035670: 108003b7                 ba      loc_F003654C
F0035674: 80a5e000                 cmp     %l7, 0
F0035678: 7fffa10f                 call    _m_free
F003567C: 90100010                 mov     %l0, %o0
F0035680: 400006f0                 call    _tcp_template
F0035684: 90100011                 mov     %l1, %o0
F0035688: 80a22000                 cmp     %o0, 0
F003568C: 12800008                 bne     loc_F00356AC
F0035690: d024601c                 st      %o0, [%l1+0x1C]
F0035694: 90100011                 mov     %l1, %o0
F0035698: 400007a5                 call    _tcp_drop
F003569C: 92102037                 mov     0x37, %o1 ! '7'
F00356A0: a2100008                 mov     %o0, %l1
F00356A4: 108003a9                 ba      loc_F0036548
F00356A8: b4102000                 mov     0, %i2
F00356AC: 80a5e000                 cmp     %l7, 0
F00356B0: 02800005                 be      loc_F00356C4
F00356B4: 90100011                 mov     %l1, %o0
F00356B8: 92100017                 mov     %l7, %o1
F00356BC: 400003c1                 call    _tcp_dooptions
F00356C0: 94100012                 mov     %l2, %o2
F00356C4: 80a66000                 cmp     %i1, 0
F00356C8: 02800004                 be      loc_F00356D8
F00356CC: 113c04e9                 sethi   -0xFEC5C00, %o0
F00356D0: 10800004                 ba      loc_F00356E0
F00356D4: f2246038                 st      %i1, [%l1+0x38]
F00356D8: d0022398                 ld      [%o0+0x398], %o0
F00356DC: d0246038                 st      %o0, [%l1+0x38]
F00356E0: 173c04e9                 sethi   %hi(_tcp_iss), %o3
F00356E4: 1100003e                 sethi   0xF800, %o0
F00356E8: d202e398                 ld      [%o3+%lo(_tcp_iss)], %o1
F00356EC: 90122200                 bset    0x200, %o0
F00356F0: d404a018                 ld      [%l2+0x18], %o2
F00356F4: 92024008                 add     %o1, %o0, %o1
F00356F8: d222e398                 st      %o1, [%o3+%lo(_tcp_iss)]
F00356FC: d0046038                 ld      [%l1+0x38], %o0
F0035700: d4246048                 st      %o2, [%l1+0x48]
F0035704: d2046048                 ld      [%l1+0x48], %o1
F0035708: d024602c                 st      %o0, [%l1+0x2C]
F003570C: d0246050                 st      %o0, [%l1+0x50]
F0035710: d0246028                 st      %o0, [%l1+0x28]
F0035714: d0246024                 st      %o0, [%l1+0x24]
F0035718: 90102003                 mov     3, %o0
F003571C: d0346008                 sth     %o0, [%l1+8]
F0035720: 90102096                 mov     0x96, %o0
F0035724: d034600e                 sth     %o0, [%l1+0xE]
F0035728: 92026001                 inc     %o1
F003572C: d2246040                 st      %o1, [%l1+0x40]
F0035730: d224604c                 st      %o1, [%l1+0x4C]
F0035734: 133c04e9                 sethi   %hi(_tcpstat), %o1
F0035738: d00c601b                 ldub    [%l1+0x1B], %o0
F003573C: 921263a0                 bset    %lo(_tcpstat), %o1
F0035740: 90122001                 bset    1, %o0
F0035744: d02c601b                 stb     %o0, [%l1+0x1B]
F0035748: d0026004                 ld      [%o1+4], %o0
F003574C: 90022001                 inc     %o0
F0035750: 1080004d                 ba      loc_F0035884
F0035754: d0226004                 st      %o0, [%o1+4]
F0035758: 0280000e                 be      loc_F0035790
F003575C: 808d6004                 btst    4, %l5
F0035760: d204a01c                 ld      [%l2+0x1C], %o1
F0035764: d0046038                 ld      [%l1+0x38], %o0
F0035768: 90224008                 sub     %o1, %o0, %o0
F003576C: 80a22000                 cmp     %o0, 0
F0035770: 0480034d                 ble     loc_F00364A4
F0035774: 80a5e000                 cmp     %l7, 0
F0035778: d0046050                 ld      [%l1+0x50], %o0
F003577C: 90224008                 sub     %o1, %o0, %o0
F0035780: 80a22000                 cmp     %o0, 0
F0035784: 14800348                 bg      loc_F00364A4
F0035788: 80a5e000                 cmp     %l7, 0
F003578C: 808d6004                 btst    4, %l5
F0035790: 02800008                 be      loc_F00357B0
F0035794: 80a2a000                 cmp     %o2, 0
F0035798: 0280036c                 be      loc_F0036548
F003579C: 90100011                 mov     %l1, %o0
F00357A0: 40000763                 call    _tcp_drop
F00357A4: 9210203d                 mov     0x3D, %o1 ! '='
F00357A8: 10800368                 ba      loc_F0036548
F00357AC: a2100008                 mov     %o0, %l1
F00357B0: d0546008                 ldsh    [%l1+8], %o0
F00357B4: 80a22003                 cmp     %o0, 3
F00357B8: 0280004f                 be      loc_F00358F4
F00357BC: 808d6002                 btst    2, %l5
F00357C0: 02800362                 be      loc_F0036548
F00357C4: 80a2a000                 cmp     %o2, 0
F00357C8: 22800009                 be,a    loc_F00357EC
F00357CC: c034600a                 clrh    [%l1+0xA]
F00357D0: d204a01c                 ld      [%l2+0x1C], %o1
F00357D4: d0046028                 ld      [%l1+0x28], %o0
F00357D8: 80a20009                 cmp     %o0, %o1
F00357DC: 1c800003                 bpos    loc_F00357E8
F00357E0: d2246024                 st      %o1, [%l1+0x24]
F00357E4: d2246028                 st      %o1, [%l1+0x28]
F00357E8: c034600a                 clrh    [%l1+0xA]
F00357EC: d204a018                 ld      [%l2+0x18], %o1
F00357F0: 808d6010                 btst    0x10, %l5
F00357F4: d00c601b                 ldub    [%l1+0x1B], %o0
F00357F8: d2246048                 st      %o1, [%l1+0x48]
F00357FC: 92026001                 inc     %o1
F0035800: d2246040                 st      %o1, [%l1+0x40]
F0035804: d224604c                 st      %o1, [%l1+0x4C]
F0035808: 90122001                 bset    1, %o0
F003580C: 0280001c                 be      loc_F003587C
F0035810: d02c601b                 stb     %o0, [%l1+0x1B]
F0035814: d0046024                 ld      [%l1+0x24], %o0
F0035818: d2046038                 ld      [%l1+0x38], %o1
F003581C: 90220009                 sub     %o0, %o1, %o0
F0035820: 80a22000                 cmp     %o0, 0
F0035824: 04800016                 ble     loc_F003587C
F0035828: 153c04e9                 sethi   %hi(_tcpstat), %o2
F003582C: 9412a3a0                 bset    %lo(_tcpstat), %o2
F0035830: d202a008                 ld      [%o2+8], %o1
F0035834: 90100016                 mov     %l6, %o0
F0035838: 92026001                 inc     %o1
F003583C: 7fffa9e4                 call    _soisconnected
F0035840: d222a008                 st      %o1, [%o2+8]
F0035844: 90102004                 mov     4, %o0
F0035848: d0346008                 sth     %o0, [%l1+8]
F003584C: 90100011                 mov     %l1, %o0
F0035850: 92102000                 mov     0, %o1
F0035854: 7ffffd09                 call    _tcp_reass
F0035858: 94102000                 mov     0, %o2
F003585C: d054605a                 ldsh    [%l1+0x5A], %o0
F0035860: 80a22000                 cmp     %o0, 0
F0035864: 22800009                 be,a    loc_F0035888
F0035868: d004a018                 ld      [%l2+0x18], %o0
F003586C: 400003a6                 call    _tcp_xmit_timer
F0035870: 90100011                 mov     %l1, %o0
F0035874: 10800005                 ba      loc_F0035888
F0035878: d004a018                 ld      [%l2+0x18], %o0
F003587C: 90102003                 mov     3, %o0
F0035880: d0346008                 sth     %o0, [%l1+8]
F0035884: d004a018                 ld      [%l2+0x18], %o0
F0035888: d254a00a                 ldsh    [%l2+0xA], %o1
F003588C: 90022001                 inc     %o0
F0035890: d024a018                 st      %o0, [%l2+0x18]
F0035894: d014603e                 lduh    [%l1+0x3E], %o0
F0035898: 80a24008                 cmp     %o1, %o0
F003589C: 04800010                 ble     loc_F00358DC
F00358A0: a0224008                 sub     %o1, %o0, %l0
F00358A4: 90100018                 mov     %i0, %o0
F00358A8: 7fffa1ce                 call    _m_adj
F00358AC: 92200010                 neg     %l0, %o1
F00358B0: 153c04e9                 sethi   %hi(_tcpstat), %o2
F00358B4: d014603e                 lduh    [%l1+0x3E], %o0
F00358B8: 9412a3a0                 bset    %lo(_tcpstat), %o2
F00358BC: d034a00a                 sth     %o0, [%l2+0xA]
F00358C0: d202a094                 ld      [%o2+0x94], %o1
F00358C4: aa0d7ffe                 and     %l5, -2, %l5
F00358C8: d002a098                 ld      [%o2+0x98], %o0
F00358CC: 92026001                 inc     %o1
F00358D0: d222a094                 st      %o1, [%o2+0x94]
F00358D4: 90020010                 add     %o0, %l0, %o0
F00358D8: d022a098                 st      %o0, [%o2+0x98]
F00358DC: d004a018                 ld      [%l2+0x18], %o0
F00358E0: 90023fff                 inc     -1, %o0
F00358E4: d0246030                 st      %o0, [%l1+0x30]
F00358E8: d004a018                 ld      [%l2+0x18], %o0
F00358EC: 108001e5                 ba      loc_F0036080
F00358F0: d0246044                 st      %o0, [%l1+0x44]
F00358F4: d0046040                 ld      [%l1+0x40], %o0
F00358F8: d204a018                 ld      [%l2+0x18], %o1
F00358FC: a0220009                 sub     %o0, %o1, %l0
F0035900: 80a42000                 cmp     %l0, 0
F0035904: 04800046                 ble     loc_F0035A1C
F0035908: 808d6002                 btst    2, %l5
F003590C: 0280000c                 be      loc_F003593C
F0035910: 90026001                 add     %o1, 1, %o0
F0035914: aa0d7ffd                 and     %l5, -3, %l5
F0035918: d214a026                 lduh    [%l2+0x26], %o1
F003591C: 80a26001                 cmp     %o1, 1
F0035920: 08800005                 bleu    loc_F0035934
F0035924: d024a018                 st      %o0, [%l2+0x18]
F0035928: 90027fff                 add     %o1, -1, %o0
F003592C: 10800003                 ba      loc_F0035938
F0035930: d034a026                 sth     %o0, [%l2+0x26]
F0035934: aa0d7fdf                 and     %l5, -0x21, %l5
F0035938: a0043fff                 inc     -1, %l0
F003593C: d054a00a                 ldsh    [%l2+0xA], %o0
F0035940: 80a40008                 cmp     %l0, %o0
F0035944: 14800009                 bg      loc_F0035968
F0035948: 133c04e9                 sethi   -0xFEC5C00, %o1
F003594C: 80a40008                 cmp     %l0, %o0
F0035950: 1280001b                 bne     loc_F00359BC
F0035954: 113c04e9                 sethi   %hi(_tcpstat), %o0
F0035958: 808d6001                 btst    1, %l5
F003595C: 12800019                 bne     loc_F00359C0
F0035960: 901223a0                 bset    %lo(_tcpstat), %o0
F0035964: 133c04e9                 sethi   -0xFEC5C00, %o1
F0035968: 921263a0                 bset    0x3A0, %o1
F003596C: d002607c                 ld      [%o1+0x7C], %o0
F0035970: 90022001                 inc     %o0
F0035974: d022607c                 st      %o0, [%o1+0x7C]
F0035978: d454a00a                 ldsh    [%l2+0xA], %o2
F003597C: d0026080                 ld      [%o1+0x80], %o0
F0035980: 808d6001                 btst    1, %l5
F0035984: 9002000a                 add     %o0, %o2, %o0
F0035988: 028002bb                 be      loc_F0036474
F003598C: d0226080                 st      %o0, [%o1+0x80]
F0035990: d254a00a                 ldsh    [%l2+0xA], %o1
F0035994: 90026001                 add     %o1, 1, %o0
F0035998: 80a40008                 cmp     %l0, %o0
F003599C: 128002b7                 bne     loc_F0036478
F00359A0: 808d6004                 btst    4, %l5
F00359A4: a0100009                 mov     %o1, %l0
F00359A8: d00c601b                 ldub    [%l1+0x1B], %o0
F00359AC: aa0d7ffe                 and     %l5, -2, %l5
F00359B0: 90122001                 bset    1, %o0
F00359B4: 10800009                 ba      loc_F00359D8
F00359B8: d02c601b                 stb     %o0, [%l1+0x1B]
F00359BC: 901223a0                 bset    0x3A0, %o0
F00359C0: d2022084                 ld      [%o0+0x84], %o1
F00359C4: d4022088                 ld      [%o0+0x88], %o2
F00359C8: 92026001                 inc     %o1
F00359CC: d2222084                 st      %o1, [%o0+0x84]
F00359D0: 94028010                 add     %o2, %l0, %o2
F00359D4: d4222088                 st      %o2, [%o0+0x88]
F00359D8: 90100018                 mov     %i0, %o0
F00359DC: 7fffa181                 call    _m_adj
F00359E0: 92100010                 mov     %l0, %o1
F00359E4: d004a018                 ld      [%l2+0x18], %o0
F00359E8: d214a00a                 lduh    [%l2+0xA], %o1
F00359EC: 90020010                 add     %o0, %l0, %o0
F00359F0: d024a018                 st      %o0, [%l2+0x18]
F00359F4: 92224010                 sub     %o1, %l0, %o1
F00359F8: d014a026                 lduh    [%l2+0x26], %o0
F00359FC: 80a20010                 cmp     %o0, %l0
F0035A00: 04800005                 ble     loc_F0035A14
F0035A04: d234a00a                 sth     %o1, [%l2+0xA]
F0035A08: 90220010                 sub     %o0, %l0, %o0
F0035A0C: 10800004                 ba      loc_F0035A1C
F0035A10: d034a026                 sth     %o0, [%l2+0x26]
F0035A14: aa0d7fdf                 and     %l5, -0x21, %l5
F0035A18: c034a026                 clrh    [%l2+0x26]
F0035A1C: d015a006                 lduh    [%l6+6], %o0
F0035A20: 808a2001                 btst    1, %o0
F0035A24: 22800013                 be,a    loc_F0035A70
F0035A28: d654a00a                 ldsh    [%l2+0xA], %o3
F0035A2C: d0546008                 ldsh    [%l1+8], %o0
F0035A30: 80a22005                 cmp     %o0, 5
F0035A34: 2480000f                 ble,a   loc_F0035A70
F0035A38: d654a00a                 ldsh    [%l2+0xA], %o3
F0035A3C: d054a00a                 ldsh    [%l2+0xA], %o0
F0035A40: 80a22000                 cmp     %o0, 0
F0035A44: 2280000b                 be,a    loc_F0035A70
F0035A48: d654a00a                 ldsh    [%l2+0xA], %o3
F0035A4C: 400006d8                 call    _tcp_close
F0035A50: 90100011                 mov     %l1, %o0
F0035A54: 153c04e99412a3a0         set     _tcpstat, %o2
F0035A5C: d202a09c                 ld      [%o2+0x9C], %o1
F0035A60: a2100008                 mov     %o0, %l1
F0035A64: 92026001                 inc     %o1
F0035A68: 1080028e                 ba      loc_F00364A0
F0035A6C: d222a09c                 st      %o1, [%o2+0x9C]
F0035A70: d204a018                 ld      [%l2+0x18], %o1
F0035A74: d414603e                 lduh    [%l1+0x3E], %o2
F0035A78: d0046040                 ld      [%l1+0x40], %o0
F0035A7C: 9202400b                 add     %o1, %o3, %o1
F0035A80: 9002000a                 add     %o0, %o2, %o0
F0035A84: a0224008                 sub     %o1, %o0, %l0
F0035A88: 80a42000                 cmp     %l0, 0
F0035A8C: 04800039                 ble     loc_F0035B70
F0035A90: 113c04e9                 sethi   %hi(_tcpstat), %o0
F0035A94: 921223a0                 or      %o0, %lo(_tcpstat), %o1
F0035A98: d0026094                 ld      [%o1+0x94], %o0
F0035A9C: 90022001                 inc     %o0
F0035AA0: d0226094                 st      %o0, [%o1+0x94]
F0035AA4: d454a00a                 ldsh    [%l2+0xA], %o2
F0035AA8: 80a4000a                 cmp     %l0, %o2
F0035AAC: 06800027                 bl      loc_F0035B48
F0035AB0: 808d6002                 btst    2, %l5
F0035AB4: d0026098                 ld      [%o1+0x98], %o0
F0035AB8: 9002000a                 add     %o0, %o2, %o0
F0035ABC: 02800011                 be      loc_F0035B00
F0035AC0: d0226098                 st      %o0, [%o1+0x98]
F0035AC4: d0546008                 ldsh    [%l1+8], %o0
F0035AC8: 80a2200a                 cmp     %o0, 0xA
F0035ACC: 3280000e                 bne,a   loc_F0035B04
F0035AD0: d014603e                 lduh    [%l1+0x3E], %o0
F0035AD4: d004a018                 ld      [%l2+0x18], %o0
F0035AD8: d2046040                 ld      [%l1+0x40], %o1
F0035ADC: 90220009                 sub     %o0, %o1, %o0
F0035AE0: 80a22000                 cmp     %o0, 0
F0035AE4: 04800007                 ble     loc_F0035B00
F0035AE8: 1100007d                 sethi   0x1F400, %o0
F0035AEC: b2024008                 add     %o1, %o0, %i1
F0035AF0: 400006af                 call    _tcp_close
F0035AF4: 90100011                 mov     %l1, %o0
F0035AF8: 10bffd81                 ba      loc_F00350FC
F0035AFC: a2100008                 mov     %o0, %l1
F0035B00: d014603e                 lduh    [%l1+0x3E], %o0
F0035B04: 80a22000                 cmp     %o0, 0
F0035B08: 1280025c                 bne     loc_F0036478
F0035B0C: 808d6004                 btst    4, %l5
F0035B10: d204a018                 ld      [%l2+0x18], %o1
F0035B14: d0046040                 ld      [%l1+0x40], %o0
F0035B18: 80a24008                 cmp     %o1, %o0
F0035B1C: 12800257                 bne     loc_F0036478
F0035B20: 808d6004                 btst    4, %l5
F0035B24: 133c04e9                 sethi   %hi(_tcpstat), %o1
F0035B28: d00c601b                 ldub    [%l1+0x1B], %o0
F0035B2C: 921263a0                 bset    %lo(_tcpstat), %o1
F0035B30: 90122001                 bset    1, %o0
F0035B34: d02c601b                 stb     %o0, [%l1+0x1B]
F0035B38: d00260a0                 ld      [%o1+0xA0], %o0
F0035B3C: 90022001                 inc     %o0
F0035B40: 10800005                 ba      loc_F0035B54
F0035B44: d02260a0                 st      %o0, [%o1+0xA0]
F0035B48: d0026098                 ld      [%o1+0x98], %o0
F0035B4C: 90020010                 add     %o0, %l0, %o0
F0035B50: d0226098                 st      %o0, [%o1+0x98]
F0035B54: 90100018                 mov     %i0, %o0
F0035B58: 7fffa122                 call    _m_adj
F0035B5C: 92200010                 neg     %l0, %o1
F0035B60: d014a00a                 lduh    [%l2+0xA], %o0
F0035B64: aa0d7ff6                 and     %l5, -0xA, %l5
F0035B68: 90220010                 sub     %o0, %l0, %o0
F0035B6C: d034a00a                 sth     %o0, [%l2+0xA]
F0035B70: 808d6004                 btst    4, %l5
F0035B74: 02800023                 be      loc_F0035C00
F0035B78: 808d6002                 btst    2, %l5
F0035B7C: d0146008                 lduh    [%l1+8], %o0
F0035B80: 90023ffd                 inc     -3, %o0
F0035B84: 912a2010                 sll     %o0, 16, %o0
F0035B88: 933a2010                 sra     %o0, 16, %o1
F0035B8C: 80a26007                 cmp     %o1, 7! switch 8 cases
F0035B90: 1880001b                 bgu     def_F0035BA4! jumptable F0035BA4 default case
F0035B94: 113c00d6                 sethi   %hi(jpt_F0035BA4), %o0
F0035B98: 901223ac                 bset    %lo(jpt_F0035BA4), %o0
F0035B9C: 932a6002                 sll     %o1, 2, %o1
F0035BA0: d0024008                 ld      [%o1+%o0], %o0
F0035BA4: 81c20000                 jmp     %o0! switch jump
F0035BA8: 01000000                 nop
F0035BCC: 10800003                 ba      loc_F0035BD8! jumptable F0035BA4 case 0
F0035BD0: 9010203d                 mov     0x3D, %o0 ! '='
F0035BD4: 90102036                 mov     0x36, %o0 ! '6'! jumptable F0035BA4 cases 1-3,6
F0035BD8: d035a056                 sth     %o0, [%l6+0x56]
F0035BDC: c0346008                 clrh    [%l1+8]
F0035BE0: 153c04e99412a3a0         set     _tcpstat, %o2
F0035BE8: d202a00c                 ld      [%o2+0xC], %o1
F0035BEC: 90100011                 mov     %l1, %o0
F0035BF0: 92026001                 inc     %o1
F0035BF4: 1080011d                 ba      loc_F0036068
F0035BF8: d222a00c                 st      %o1, [%o2+0xC]
F0035BFC: 808d6002                 btst    2, %l5! jumptable F0035BA4 default case
F0035C00: 02800006                 be      loc_F0035C18
F0035C04: 90100011                 mov     %l1, %o0
F0035C08: 40000649                 call    _tcp_drop
F0035C0C: 92102036                 mov     0x36, %o1 ! '6'
F0035C10: 10800224                 ba      loc_F00364A0
F0035C14: a2100008                 mov     %o0, %l1
F0035C18: 808d6010                 btst    0x10, %l5
F0035C1C: 0280024c                 be      loc_F003654C
F0035C20: 80a5e000                 cmp     %l7, 0
F0035C24: d0546008                 ldsh    [%l1+8], %o0
F0035C28: 80a22003                 cmp     %o0, 3
F0035C2C: 22800008                 be,a    loc_F0035C4C
F0035C30: d0046024                 ld      [%l1+0x24], %o0
F0035C34: 06800113                 bl      loc_F0036080
F0035C38: 80a2200a                 cmp     %o0, 0xA
F0035C3C: 14800112                 bg      loc_F0036084
F0035C40: 808d6010                 btst    0x10, %l5
F0035C44: 1080001d                 ba      loc_F0035CB8
F0035C48: d004a01c                 ld      [%l2+0x1C], %o0
F0035C4C: d204a01c                 ld      [%l2+0x1C], %o1
F0035C50: 90220009                 sub     %o0, %o1, %o0
F0035C54: 80a22000                 cmp     %o0, 0
F0035C58: 14800213                 bg      loc_F00364A4
F0035C5C: 80a5e000                 cmp     %l7, 0
F0035C60: d0046050                 ld      [%l1+0x50], %o0
F0035C64: 90224008                 sub     %o1, %o0, %o0
F0035C68: 80a22000                 cmp     %o0, 0
F0035C6C: 1480020e                 bg      loc_F00364A4
F0035C70: 80a5e000                 cmp     %l7, 0
F0035C74: 153c04e99412a3a0         set     _tcpstat, %o2
F0035C7C: d202a008                 ld      [%o2+8], %o1
F0035C80: 90100016                 mov     %l6, %o0
F0035C84: 92026001                 inc     %o1
F0035C88: 7fffa8d1                 call    _soisconnected
F0035C8C: d222a008                 st      %o1, [%o2+8]
F0035C90: 90102004                 mov     4, %o0
F0035C94: d0346008                 sth     %o0, [%l1+8]
F0035C98: 90100011                 mov     %l1, %o0
F0035C9C: 92102000                 mov     0, %o1
F0035CA0: 7ffffbf6                 call    _tcp_reass
F0035CA4: 94102000                 mov     0, %o2
F0035CA8: d004a018                 ld      [%l2+0x18], %o0
F0035CAC: 90023fff                 inc     -1, %o0
F0035CB0: d0246030                 st      %o0, [%l1+0x30]
F0035CB4: d004a01c                 ld      [%l2+0x1C], %o0
F0035CB8: d2046024                 ld      [%l1+0x24], %o1
F0035CBC: 90220009                 sub     %o0, %o1, %o0
F0035CC0: 80a22000                 cmp     %o0, 0
F0035CC4: 3480004e                 bg,a    loc_F0035DFC
F0035CC8: d0546016                 ldsh    [%l1+0x16], %o0
F0035CCC: d054a00a                 ldsh    [%l2+0xA], %o0
F0035CD0: 80a22000                 cmp     %o0, 0
F0035CD4: 328000eb                 bne,a   loc_F0036080
F0035CD8: c0346016                 clrh    [%l1+0x16]
F0035CDC: d214a022                 lduh    [%l2+0x22], %o1
F0035CE0: d014603c                 lduh    [%l1+0x3C], %o0
F0035CE4: 80a24008                 cmp     %o1, %o0
F0035CE8: 328000e6                 bne,a   loc_F0036080
F0035CEC: c0346016                 clrh    [%l1+0x16]
F0035CF0: 113c04e9901223a0         set     _tcpstat, %o0
F0035CF8: d20220a4                 ld      [%o0+0xA4], %o1
F0035CFC: 92026001                 inc     %o1
F0035D00: d22220a4                 st      %o1, [%o0+0xA4]
F0035D04: d054600a                 ldsh    [%l1+0xA], %o0
F0035D08: 80a22000                 cmp     %o0, 0
F0035D0C: 228000dd                 be,a    loc_F0036080
F0035D10: c0346016                 clrh    [%l1+0x16]
F0035D14: d204a01c                 ld      [%l2+0x1C], %o1
F0035D18: d0046024                 ld      [%l1+0x24], %o0
F0035D1C: 80a24008                 cmp     %o1, %o0
F0035D20: 328000d8                 bne,a   loc_F0036080
F0035D24: c0346016                 clrh    [%l1+0x16]
F0035D28: d0146016                 lduh    [%l1+0x16], %o0
F0035D2C: 133c0432                 sethi   %hi(_tcprexmtthresh), %o1
F0035D30: d20260a8                 ld      [%o1+%lo(_tcprexmtthresh)], %o1
F0035D34: 90022001                 inc     %o0
F0035D38: d0346016                 sth     %o0, [%l1+0x16]
F0035D3C: 912a2010                 sll     %o0, 16, %o0
F0035D40: 913a2010                 sra     %o0, 16, %o0
F0035D44: 80a20009                 cmp     %o0, %o1
F0035D48: 12800024                 bne     loc_F0035DD8
F0035D4C: 01000000                 nop
F0035D50: d014603c                 lduh    [%l1+0x3C], %o0
F0035D54: d2146054                 lduh    [%l1+0x54], %o1
F0035D58: 7fff7de9                 call    _min
F0035D5C: e6046028                 ld      [%l1+0x28], %l3
F0035D60: e0146018                 lduh    [%l1+0x18], %l0
F0035D64: 91322001                 srl     %o0, 1, %o0
F0035D68: 7fff4226                 call    _udiv
F0035D6C: 92100010                 mov     %l0, %o1
F0035D70: 80a22001                 cmp     %o0, 1
F0035D74: 28800002                 bleu,a  loc_F0035D7C
F0035D78: 90102002                 mov     2, %o0
F0035D7C: 7fff41e1                 call    _umul
F0035D80: 92100010                 mov     %l0, %o1
F0035D84: d0346056                 sth     %o0, [%l1+0x56]
F0035D88: c034600a                 clrh    [%l1+0xA]
F0035D8C: c034605a                 clrh    [%l1+0x5A]
F0035D90: d404a01c                 ld      [%l2+0x1C], %o2
F0035D94: 90100011                 mov     %l1, %o0
F0035D98: d2146018                 lduh    [%l1+0x18], %o1
F0035D9C: d4246028                 st      %o2, [%l1+0x28]
F0035DA0: 400002f8                 call    _tcp_output
F0035DA4: d2346054                 sth     %o1, [%l1+0x54]
F0035DA8: d0146018                 lduh    [%l1+0x18], %o0
F0035DAC: 7fff41d5                 call    _umul
F0035DB0: d2546016                 ldsh    [%l1+0x16], %o1
F0035DB4: d2146056                 lduh    [%l1+0x56], %o1
F0035DB8: 92024008                 add     %o1, %o0, %o1
F0035DBC: d0046028                 ld      [%l1+0x28], %o0
F0035DC0: 9024c008                 sub     %l3, %o0, %o0
F0035DC4: 80a22000                 cmp     %o0, 0
F0035DC8: 048001e0                 ble     loc_F0036548
F0035DCC: d2346054                 sth     %o1, [%l1+0x54]
F0035DD0: 108001de                 ba      loc_F0036548
F0035DD4: e6246028                 st      %l3, [%l1+0x28]
F0035DD8: 048000aa                 ble     loc_F0036080
F0035DDC: 90100011                 mov     %l1, %o0
F0035DE0: d2146054                 lduh    [%l1+0x54], %o1
F0035DE4: d4146018                 lduh    [%l1+0x18], %o2
F0035DE8: 9202400a                 add     %o1, %o2, %o1
F0035DEC: 400002e5                 call    _tcp_output
F0035DF0: d2346054                 sth     %o1, [%l1+0x54]
F0035DF4: 108001d6                 ba      loc_F003654C
F0035DF8: 80a5e000                 cmp     %l7, 0
F0035DFC: 133c0432                 sethi   %hi(_tcprexmtthresh), %o1
F0035E00: d20260a8                 ld      [%o1+%lo(_tcprexmtthresh)], %o1
F0035E04: 80a20009                 cmp     %o0, %o1
F0035E08: 24800008                 ble,a   loc_F0035E28
F0035E0C: c0346016                 clrh    [%l1+0x16]
F0035E10: d2146056                 lduh    [%l1+0x56], %o1
F0035E14: d0146054                 lduh    [%l1+0x54], %o0
F0035E18: 80a20009                 cmp     %o0, %o1
F0035E1C: 38800002                 bgu,a   loc_F0035E24
F0035E20: d2346054                 sth     %o1, [%l1+0x54]
F0035E24: c0346016                 clrh    [%l1+0x16]
F0035E28: d804a01c                 ld      [%l2+0x1C], %o4
F0035E2C: d0046050                 ld      [%l1+0x50], %o0
F0035E30: 90230008                 sub     %o4, %o0, %o0
F0035E34: 80a22000                 cmp     %o0, 0
F0035E38: 04800007                 ble     loc_F0035E54
F0035E3C: 133c04e9                 sethi   %hi(_tcpstat), %o1
F0035E40: 921263a0                 bset    %lo(_tcpstat), %o1
F0035E44: d00260a8                 ld      [%o1+0xA8], %o0
F0035E48: 90022001                 inc     %o0
F0035E4C: 1080018a                 ba      loc_F0036474
F0035E50: d02260a8                 st      %o0, [%o1+0xA8]
F0035E54: 153c04e9                 sethi   %hi(_tcpstat), %o2
F0035E58: d0046024                 ld      [%l1+0x24], %o0
F0035E5C: 9412a3a0                 bset    %lo(_tcpstat), %o2
F0035E60: d202a0ac                 ld      [%o2+0xAC], %o1
F0035E64: a6230008                 sub     %o4, %o0, %l3
F0035E68: 92026001                 inc     %o1
F0035E6C: d002a0b0                 ld      [%o2+0xB0], %o0
F0035E70: d222a0ac                 st      %o1, [%o2+0xAC]
F0035E74: 90020013                 add     %o0, %l3, %o0
F0035E78: d022a0b0                 st      %o0, [%o2+0xB0]
F0035E7C: d054605a                 ldsh    [%l1+0x5A], %o0
F0035E80: 80a22000                 cmp     %o0, 0
F0035E84: 2280000b                 be,a    loc_F0035EB0
F0035E88: d204a01c                 ld      [%l2+0x1C], %o1
F0035E8C: d004a01c                 ld      [%l2+0x1C], %o0
F0035E90: d204605c                 ld      [%l1+0x5C], %o1
F0035E94: 90220009                 sub     %o0, %o1, %o0
F0035E98: 80a22000                 cmp     %o0, 0
F0035E9C: 24800005                 ble,a   loc_F0035EB0
F0035EA0: d204a01c                 ld      [%l2+0x1C], %o1
F0035EA4: 40000218                 call    _tcp_xmit_timer
F0035EA8: 90100011                 mov     %l1, %o0
F0035EAC: d204a01c                 ld      [%l2+0x1C], %o1
F0035EB0: d0046050                 ld      [%l1+0x50], %o0
F0035EB4: 80a24008                 cmp     %o1, %o0
F0035EB8: 32800005                 bne,a   loc_F0035ECC
F0035EBC: d054600c                 ldsh    [%l1+0xC], %o0
F0035EC0: c034600a                 clrh    [%l1+0xA]
F0035EC4: 10800007                 ba      loc_F0035EE0
F0035EC8: b6102001                 mov     1, %i3
F0035ECC: 80a22000                 cmp     %o0, 0
F0035ED0: 32800005                 bne,a   loc_F0035EE4
F0035ED4: d0146018                 lduh    [%l1+0x18], %o0
F0035ED8: d0146014                 lduh    [%l1+0x14], %o0
F0035EDC: d034600a                 sth     %o0, [%l1+0xA]
F0035EE0: d0146018                 lduh    [%l1+0x18], %o0
F0035EE4: e0146054                 lduh    [%l1+0x54], %l0
F0035EE8: a92a2010                 sll     %o0, 16, %l4
F0035EEC: d0146056                 lduh    [%l1+0x56], %o0
F0035EF0: 80a40008                 cmp     %l0, %o0
F0035EF4: 08800008                 bleu    loc_F0035F14
F0035EF8: 93352010                 srl     %l4, 16, %o1
F0035EFC: 7fff4181                 call    _umul
F0035F00: 90100009                 mov     %o1, %o0
F0035F04: 7fff41bf                 call    _udiv
F0035F08: 92100010                 mov     %l0, %o1
F0035F0C: 93352013                 srl     %l4, 19, %o1
F0035F10: 92020009                 add     %o0, %o1, %o1
F0035F14: 90040009                 add     %l0, %o1, %o0
F0035F18: 1300003f                 sethi   0xFC00, %o1
F0035F1C: 7fff7d78                 call    _min
F0035F20: 921263ff                 bset    0x3FF, %o1
F0035F24: d0346054                 sth     %o0, [%l1+0x54]
F0035F28: d415a03c                 lduh    [%l6+0x3C], %o2
F0035F2C: 80a4c00a                 cmp     %l3, %o2
F0035F30: 0480000a                 ble     loc_F0035F58
F0035F34: 9005a03c                 add     %l6, 0x3C, %o0 ! '<'
F0035F38: d214603c                 lduh    [%l1+0x3C], %o1
F0035F3C: 9222400a                 sub     %o1, %o2, %o1
F0035F40: d234603c                 sth     %o1, [%l1+0x3C]
F0035F44: d215a03c                 lduh    [%l6+0x3C], %o1
F0035F48: 7fffaaf6                 call    _sbdrop
F0035F4C: a0102001                 mov     1, %l0
F0035F50: 10800009                 ba      loc_F0035F74
F0035F54: d015a050                 lduh    [%l6+0x50], %o0
F0035F58: 7fffaaf2                 call    _sbdrop
F0035F5C: 92100013                 mov     %l3, %o1
F0035F60: d014603c                 lduh    [%l1+0x3C], %o0
F0035F64: a0102000                 mov     0, %l0
F0035F68: 90220013                 sub     %o0, %l3, %o0
F0035F6C: d034603c                 sth     %o0, [%l1+0x3C]
F0035F70: d015a050                 lduh    [%l6+0x50], %o0
F0035F74: 808a2004                 btst    4, %o0
F0035F78: 12800006                 bne     loc_F0035F90
F0035F7C: 90100016                 mov     %l6, %o0
F0035F80: d005a04c                 ld      [%l6+0x4C], %o0
F0035F84: 80a22000                 cmp     %o0, 0
F0035F88: 02800004                 be      loc_F0035F98
F0035F8C: 90100016                 mov     %l6, %o0
F0035F90: 7fffa91f                 call    _sowakeup
F0035F94: 9205a03c                 add     %l6, 0x3C, %o1 ! '<'
F0035F98: d204a01c                 ld      [%l2+0x1C], %o1
F0035F9C: d0046028                 ld      [%l1+0x28], %o0
F0035FA0: 80a20009                 cmp     %o0, %o1
F0035FA4: 1c800003                 bpos    loc_F0035FB0
F0035FA8: d2246024                 st      %o1, [%l1+0x24]
F0035FAC: d2246028                 st      %o1, [%l1+0x28]
F0035FB0: d0546008                 ldsh    [%l1+8], %o0
F0035FB4: 80a22007                 cmp     %o0, 7
F0035FB8: 2280001d                 be,a    loc_F003602C
F0035FBC: 80a42000                 cmp     %l0, 0
F0035FC0: 14800007                 bg      loc_F0035FDC
F0035FC4: 80a22008                 cmp     %o0, 8
F0035FC8: 80a22006                 cmp     %o0, 6
F0035FCC: 0280000a                 be      loc_F0035FF4
F0035FD0: 80a42000                 cmp     %l0, 0
F0035FD4: 1080002c                 ba      loc_F0036084
F0035FD8: 808d6010                 btst    0x10, %l5
F0035FDC: 0280001f                 be      loc_F0036058
F0035FE0: 80a2200a                 cmp     %o0, 0xA
F0035FE4: 02800025                 be      loc_F0036078
F0035FE8: 90102078                 mov     0x78, %o0 ! 'x'
F0035FEC: 10800026                 ba      loc_F0036084
F0035FF0: 808d6010                 btst    0x10, %l5
F0035FF4: 02800024                 be      loc_F0036084
F0035FF8: 808d6010                 btst    0x10, %l5
F0035FFC: d015a006                 lduh    [%l6+6], %o0
F0036000: 808a2020                 btst    0x20, %o0 ! ' '
F0036004: 02800008                 be      loc_F0036024
F0036008: 90102009                 mov     9, %o0
F003600C: 7fffa823                 call    _soisdisconnected
F0036010: 90100016                 mov     %l6, %o0
F0036014: 113c04ea                 sethi   %hi(_tcp_maxidle), %o0
F0036018: d0022058                 ld      [%o0+%lo(_tcp_maxidle)], %o0
F003601C: d0346010                 sth     %o0, [%l1+0x10]
F0036020: 90102009                 mov     9, %o0
F0036024: 10800017                 ba      loc_F0036080
F0036028: d0346008                 sth     %o0, [%l1+8]
F003602C: 02800015                 be      loc_F0036080
F0036030: 9010200a                 mov     0xA, %o0
F0036034: d0346008                 sth     %o0, [%l1+8]
F0036038: 40000650                 call    _tcp_canceltimers
F003603C: 90100011                 mov     %l1, %o0
F0036040: 90102078                 mov     0x78, %o0 ! 'x'
F0036044: d0346010                 sth     %o0, [%l1+0x10]
F0036048: 7fffa814                 call    _soisdisconnected
F003604C: 90100016                 mov     %l6, %o0
F0036050: 1080000d                 ba      loc_F0036084
F0036054: 808d6010                 btst    0x10, %l5
F0036058: 80a42000                 cmp     %l0, 0
F003605C: 0280000a                 be      loc_F0036084
F0036060: 808d6010                 btst    0x10, %l5
F0036064: 90100011                 mov     %l1, %o0! jumptable F0035BA4 cases 4,5,7
F0036068: 40000551                 call    _tcp_close
F003606C: 01000000                 nop
F0036070: 10800136                 ba      loc_F0036548
F0036074: a2100008                 mov     %o0, %l1
F0036078: 108000ff                 ba      loc_F0036474
F003607C: d0346010                 sth     %o0, [%l1+0x10]
F0036080: 808d6010                 btst    0x10, %l5
F0036084: 02800034                 be      loc_F0036154
F0036088: 808d6020                 btst    0x20, %l5 ! ' '
F003608C: d2046030                 ld      [%l1+0x30], %o1
F0036090: d004a018                 ld      [%l2+0x18], %o0
F0036094: 80a24008                 cmp     %o1, %o0
F0036098: 0c800010                 bneg    loc_F00360D8
F003609C: 80a24008                 cmp     %o1, %o0
F00360A0: 1280002d                 bne     loc_F0036154
F00360A4: 808d6020                 btst    0x20, %l5 ! ' '
F00360A8: d2046034                 ld      [%l1+0x34], %o1
F00360AC: d004a01c                 ld      [%l2+0x1C], %o0
F00360B0: 80a24008                 cmp     %o1, %o0
F00360B4: 0c800009                 bneg    loc_F00360D8
F00360B8: 80a24008                 cmp     %o1, %o0
F00360BC: 12800026                 bne     loc_F0036154
F00360C0: 808d6020                 btst    0x20, %l5 ! ' '
F00360C4: d214a022                 lduh    [%l2+0x22], %o1
F00360C8: d014603c                 lduh    [%l1+0x3C], %o0
F00360CC: 80a24008                 cmp     %o1, %o0
F00360D0: 08800021                 bleu    loc_F0036154
F00360D4: 808d6020                 btst    0x20, %l5 ! ' '
F00360D8: d054a00a                 ldsh    [%l2+0xA], %o0
F00360DC: 80a22000                 cmp     %o0, 0
F00360E0: 32800011                 bne,a   loc_F0036124
F00360E4: d014a022                 lduh    [%l2+0x22], %o0
F00360E8: d2046034                 ld      [%l1+0x34], %o1
F00360EC: d004a01c                 ld      [%l2+0x1C], %o0
F00360F0: 80a24008                 cmp     %o1, %o0
F00360F4: 3280000c                 bne,a   loc_F0036124
F00360F8: d014a022                 lduh    [%l2+0x22], %o0
F00360FC: d214a022                 lduh    [%l2+0x22], %o1
F0036100: d014603c                 lduh    [%l1+0x3C], %o0
F0036104: 80a24008                 cmp     %o1, %o0
F0036108: 08800006                 bleu    loc_F0036120
F003610C: 133c04e9                 sethi   %hi(_tcpstat), %o1
F0036110: 921263a0                 bset    %lo(_tcpstat), %o1
F0036114: d00260b4                 ld      [%o1+0xB4], %o0
F0036118: 90022001                 inc     %o0
F003611C: d02260b4                 st      %o0, [%o1+0xB4]
F0036120: d014a022                 lduh    [%l2+0x22], %o0
F0036124: d2146066                 lduh    [%l1+0x66], %o1
F0036128: d034603c                 sth     %o0, [%l1+0x3C]
F003612C: d004a018                 ld      [%l2+0x18], %o0
F0036130: d414603c                 lduh    [%l1+0x3C], %o2
F0036134: d0246030                 st      %o0, [%l1+0x30]
F0036138: d004a01c                 ld      [%l2+0x1C], %o0
F003613C: 80a28009                 cmp     %o2, %o1
F0036140: 08800003                 bleu    loc_F003614C
F0036144: d0246034                 st      %o0, [%l1+0x34]
F0036148: d4346066                 sth     %o2, [%l1+0x66]
F003614C: b6102001                 mov     1, %i3
F0036150: 808d6020                 btst    0x20, %l5 ! ' '
F0036154: 2280003c                 be,a    loc_F0036244
F0036158: d2046040                 ld      [%l1+0x40], %o1
F003615C: d414a026                 lduh    [%l2+0x26], %o2
F0036160: 80a2a000                 cmp     %o2, 0
F0036164: 22800038                 be,a    loc_F0036244
F0036168: d2046040                 ld      [%l1+0x40], %o1
F003616C: d0546008                 ldsh    [%l1+8], %o0
F0036170: 80a22009                 cmp     %o0, 9
F0036174: 34800034                 bg,a    loc_F0036244
F0036178: d2046040                 ld      [%l1+0x40], %o1
F003617C: d215a024                 lduh    [%l6+0x24], %o1
F0036180: 1100003f901223ff         set     0xFFFF, %o0
F0036188: 92028009                 add     %o2, %o1, %o1
F003618C: 80a24008                 cmp     %o1, %o0
F0036190: 24800005                 ble,a   loc_F00361A4
F0036194: d204a018                 ld      [%l2+0x18], %o1
F0036198: c034a026                 clrh    [%l2+0x26]
F003619C: 1080002f                 ba      loc_F0036258
F00361A0: aa0d7fdf                 and     %l5, -0x21, %l5
F00361A4: d0046044                 ld      [%l1+0x44], %o0
F00361A8: 9402400a                 add     %o1, %o2, %o2
F00361AC: 90228008                 sub     %o2, %o0, %o0
F00361B0: 80a22000                 cmp     %o0, 0
F00361B4: 24800016                 ble,a   loc_F003620C
F00361B8: d214a026                 lduh    [%l2+0x26], %o1
F00361BC: d2046040                 ld      [%l1+0x40], %o1
F00361C0: d4246044                 st      %o2, [%l1+0x44]
F00361C4: d015a024                 lduh    [%l6+0x24], %o0
F00361C8: 92228009                 sub     %o2, %o1, %o1
F00361CC: 90020009                 add     %o0, %o1, %o0
F00361D0: 90023fff                 inc     -1, %o0
F00361D4: d035a058                 sth     %o0, [%l6+0x58]
F00361D8: 912a2010                 sll     %o0, 16, %o0
F00361DC: 80a22000                 cmp     %o0, 0
F00361E0: 12800005                 bne     loc_F00361F4
F00361E4: 01000000                 nop
F00361E8: d015a006                 lduh    [%l6+6], %o0
F00361EC: 90122040                 bset    0x40, %o0 ! '@'
F00361F0: d035a006                 sth     %o0, [%l6+6]
F00361F4: 7fffa74c                 call    _sohasoutofband
F00361F8: 90100016                 mov     %l6, %o0
F00361FC: d00c6068                 ldub    [%l1+0x68], %o0
F0036200: 900a3ffc                 and     %o0, -4, %o0
F0036204: d02c6068                 stb     %o0, [%l1+0x68]
F0036208: d214a026                 lduh    [%l2+0x26], %o1
F003620C: d054a00a                 ldsh    [%l2+0xA], %o0
F0036210: 80a24008                 cmp     %o1, %o0
F0036214: 14800013                 bg      loc_F0036260
F0036218: 80a22000                 cmp     %o0, 0
F003621C: d015a002                 lduh    [%l6+2], %o0
F0036220: 808a2100                 btst    0x100, %o0
F0036224: 3280000e                 bne,a   loc_F003625C
F0036228: d054a00a                 ldsh    [%l2+0xA], %o0
F003622C: 90100016                 mov     %l6, %o0
F0036230: 92100012                 mov     %l2, %o1
F0036234: 4000010d                 call    _tcp_pulloutofband
F0036238: 94100018                 mov     %i0, %o2
F003623C: 10800008                 ba      loc_F003625C
F0036240: d054a00a                 ldsh    [%l2+0xA], %o0
F0036244: d0046044                 ld      [%l1+0x44], %o0
F0036248: 90224008                 sub     %o1, %o0, %o0
F003624C: 80a22000                 cmp     %o0, 0
F0036250: 34800002                 bg,a    loc_F0036258
F0036254: d2246044                 st      %o1, [%l1+0x44]
F0036258: d054a00a                 ldsh    [%l2+0xA], %o0
F003625C: 80a22000                 cmp     %o0, 0
F0036260: 32800006                 bne,a   loc_F0036278
F0036264: d4546008                 ldsh    [%l1+8], %o2
F0036268: 808d6001                 btst    1, %l5
F003626C: 02800035                 be      loc_F0036340
F0036270: 01000000                 nop
F0036274: d4546008                 ldsh    [%l1+8], %o2
F0036278: 80a2a009                 cmp     %o2, 9
F003627C: 14800031                 bg      loc_F0036340
F0036280: 01000000                 nop
F0036284: d204a018                 ld      [%l2+0x18], %o1
F0036288: d0046040                 ld      [%l1+0x40], %o0
F003628C: 80a24008                 cmp     %o1, %o0
F0036290: 12800024                 bne     loc_F0036320
F0036294: 90100011                 mov     %l1, %o0
F0036298: d0044000                 ld      [%l1], %o0
F003629C: 80a20011                 cmp     %o0, %l1
F00362A0: 12800020                 bne     loc_F0036320
F00362A4: 90100011                 mov     %l1, %o0
F00362A8: 80a2a004                 cmp     %o2, 4
F00362AC: 1280001e                 bne     loc_F0036324
F00362B0: 92100012                 mov     %l2, %o1
F00362B4: d00c601b                 ldub    [%l1+0x1B], %o0
F00362B8: 90122002                 bset    2, %o0
F00362BC: d02c601b                 stb     %o0, [%l1+0x1B]
F00362C0: d254a00a                 ldsh    [%l2+0xA], %o1
F00362C4: 173c04e9                 sethi   %hi(_tcpstat), %o3
F00362C8: d0046040                 ld      [%l1+0x40], %o0
F00362CC: 9612e3a0                 bset    %lo(_tcpstat), %o3
F00362D0: 90020009                 add     %o0, %o1, %o0
F00362D4: d0246040                 st      %o0, [%l1+0x40]
F00362D8: d202e068                 ld      [%o3+0x68], %o1
F00362DC: a005a024                 add     %l6, 0x24, %l0 ! '$'
F00362E0: da0ca021                 ldub    [%l2+0x21], %o5
F00362E4: 90100010                 mov     %l0, %o0
F00362E8: d402e06c                 ld      [%o3+0x6C], %o2
F00362EC: 92026001                 inc     %o1
F00362F0: d222e068                 st      %o1, [%o3+0x68]
F00362F4: 92100018                 mov     %i0, %o1
F00362F8: d854a00a                 ldsh    [%l2+0xA], %o4
F00362FC: aa0b6001                 and     %o5, 1, %l5
F0036300: 9402800c                 add     %o2, %o4, %o2
F0036304: 7fffa891                 call    _sbappend
F0036308: d422e06c                 st      %o2, [%o3+0x6C]
F003630C: 90100016                 mov     %l6, %o0
F0036310: 7fffa83f                 call    _sowakeup
F0036314: 92100010                 mov     %l0, %o1
F0036318: 1080000e                 ba      loc_F0036350
F003631C: 808d6001                 btst    1, %l5
F0036320: 92100012                 mov     %l2, %o1
F0036324: 7ffffa55                 call    _tcp_reass
F0036328: 94100018                 mov     %i0, %o2
F003632C: d20c601b                 ldub    [%l1+0x1B], %o1
F0036330: aa100008                 mov     %o0, %l5
F0036334: 92126001                 bset    1, %o1
F0036338: 10800005                 ba      loc_F003634C
F003633C: d22c601b                 stb     %o1, [%l1+0x1B]
F0036340: 7fff9e49                 call    _m_freem
F0036344: 90100018                 mov     %i0, %o0
F0036348: aa0d7ffe                 and     %l5, -2, %l5
F003634C: 808d6001                 btst    1, %l5
F0036350: 22800035                 be,a    loc_F0036424
F0036354: d015a002                 lduh    [%l6+2], %o0
F0036358: d0546008                 ldsh    [%l1+8], %o0
F003635C: 80a22009                 cmp     %o0, 9
F0036360: 3480000b                 bg,a    loc_F003638C
F0036364: d0146008                 lduh    [%l1+8], %o0
F0036368: 7fffa7ea                 call    _socantrcvmore
F003636C: 90100016                 mov     %l6, %o0
F0036370: d00c601b                 ldub    [%l1+0x1B], %o0
F0036374: d2046040                 ld      [%l1+0x40], %o1
F0036378: 90122001                 bset    1, %o0
F003637C: d02c601b                 stb     %o0, [%l1+0x1B]
F0036380: 92026001                 inc     %o1
F0036384: d2246040                 st      %o1, [%l1+0x40]
F0036388: d0146008                 lduh    [%l1+8], %o0
F003638C: 90023ffd                 inc     -3, %o0
F0036390: 912a2010                 sll     %o0, 16, %o0
F0036394: 933a2010                 sra     %o0, 16, %o1
F0036398: 80a26007                 cmp     %o1, 7! switch 8 cases
F003639C: 18800021                 bgu     def_F00363B0! jumptable F00363B0 default case, cases 2,4,5
F00363A0: 113c00d8                 sethi   %hi(jpt_F00363B0), %o0
F00363A4: 901223b8                 bset    %lo(jpt_F00363B0), %o0
F00363A8: 932a6002                 sll     %o1, 2, %o1
F00363AC: d0024008                 ld      [%o1+%o0], %o0
F00363B0: 81c20000                 jmp     %o0! switch jump
F00363B4: 01000000                 nop
F00363D8: 90102005                 mov     5, %o0! jumptable F00363B0 cases 0,1
F00363DC: 10800011                 ba      def_F00363B0! jumptable F00363B0 default case, cases 2,4,5
F00363E0: d0346008                 sth     %o0, [%l1+8]
F00363E4: 90102007                 mov     7, %o0! jumptable F00363B0 case 3
F00363E8: 1080000e                 ba      def_F00363B0! jumptable F00363B0 default case, cases 2,4,5
F00363EC: d0346008                 sth     %o0, [%l1+8]
F00363F0: 9010200a                 mov     0xA, %o0! jumptable F00363B0 case 6
F00363F4: d0346008                 sth     %o0, [%l1+8]
F00363F8: 40000560                 call    _tcp_canceltimers
F00363FC: 90100011                 mov     %l1, %o0
F0036400: 90102078                 mov     0x78, %o0 ! 'x'
F0036404: d0346010                 sth     %o0, [%l1+0x10]
F0036408: 7fffa724                 call    _soisdisconnected
F003640C: 90100016                 mov     %l6, %o0
F0036410: 10800005                 ba      loc_F0036424
F0036414: d015a002                 lduh    [%l6+2], %o0
F0036418: 90102078                 mov     0x78, %o0 ! 'x'! jumptable F00363B0 case 7
F003641C: d0346010                 sth     %o0, [%l1+0x10]
F0036420: d015a002                 lduh    [%l6+2], %o0! jumptable F00363B0 default case, cases 2,4,5
F0036424: 808a2001                 btst    1, %o0
F0036428: 02800009                 be      loc_F003644C
F003642C: 90102000                 mov     0, %o0
F0036430: 932f2010                 sll     %i4, 16, %o1
F0036434: 933a6010                 sra     %o1, 16, %o1
F0036438: 94100011                 mov     %l1, %o2
F003643C: 173c04ea9612e060         set     _tcp_saveti, %o3
F0036444: 7ffff9cf                 call    _tcp_trace
F0036448: 98102000                 mov     0, %o4
F003644C: 80a6e000                 cmp     %i3, 0
F0036450: 12800006                 bne     loc_F0036468
F0036454: 01000000                 nop
F0036458: d00c601b                 ldub    [%l1+0x1B], %o0
F003645C: 808a2001                 btst    1, %o0
F0036460: 02800056                 be      locret_F00365B8
F0036464: 01000000                 nop
F0036468: 40000146                 call    _tcp_output
F003646C: 90100011                 mov     %l1, %o0
F0036470: 30800052                 ba,a    locret_F00365B8
F0036474: 808d6004                 btst    4, %l5
F0036478: 12800035                 bne     loc_F003654C
F003647C: 80a5e000                 cmp     %l7, 0
F0036480: 7fff9df9                 call    _m_freem
F0036484: 90100018                 mov     %i0, %o0
F0036488: d20c601b                 ldub    [%l1+0x1B], %o1
F003648C: 90100011                 mov     %l1, %o0
F0036490: 92126001                 bset    1, %o1
F0036494: 4000013b                 call    _tcp_output
F0036498: d22a201b                 stb     %o1, [%o0+0x1B]
F003649C: 30800047                 ba,a    locret_F00365B8
F00364A0: 80a5e000                 cmp     %l7, 0
F00364A4: 02800006                 be      loc_F00364BC
F00364A8: 808d6004                 btst    4, %l5
F00364AC: 7fff9d82                 call    _m_free
F00364B0: 90100017                 mov     %l7, %o0
F00364B4: ae102000                 mov     0, %l7
F00364B8: 808d6004                 btst    4, %l5
F00364BC: 12800024                 bne     loc_F003654C
F00364C0: 80a5e000                 cmp     %l7, 0
F00364C4: d204a010                 ld      [%l2+0x10], %o1
F00364C8: 9007bff0                 add     %fp, var_10, %o0
F00364CC: 7fffe38f                 call    _in_broadcast
F00364D0: d227bff0                 st      %o1, [%fp+var_10]
F00364D4: 80a22000                 cmp     %o0, 0
F00364D8: 1280001d                 bne     loc_F003654C
F00364DC: 80a5e000                 cmp     %l7, 0
F00364E0: 808d6010                 btst    0x10, %l5
F00364E4: 02800008                 be      loc_F0036504
F00364E8: 90100011                 mov     %l1, %o0
F00364EC: 92100012                 mov     %l2, %o1
F00364F0: 94100018                 mov     %i0, %o2
F00364F4: 96102000                 mov     0, %o3
F00364F8: d802601c                 ld      [%o1+0x1C], %o4
F00364FC: 1080000f                 ba      loc_F0036538
F0036500: 9a102004                 mov     4, %o5
F0036504: 808d6002                 btst    2, %l5
F0036508: 02800006                 be      loc_F0036520
F003650C: 92100012                 mov     %l2, %o1
F0036510: d014a00a                 lduh    [%l2+0xA], %o0
F0036514: 90022001                 inc     %o0
F0036518: d034a00a                 sth     %o0, [%l2+0xA]
F003651C: 90100011                 mov     %l1, %o0
F0036520: 94100018                 mov     %i0, %o2
F0036524: c452600a                 ldsh    [%o1+0xA], %g2
F0036528: 98102000                 mov     0, %o4
F003652C: d6026018                 ld      [%o1+0x18], %o3
F0036530: 9a102014                 mov     0x14, %o5
F0036534: 9602c002                 add     %o3, %g2, %o3
F0036538: 40000374                 call    _tcp_respond
F003653C: 01000000                 nop
F0036540: 1080001a                 ba      loc_F00365A8
F0036544: 80a6a000                 cmp     %i2, 0
F0036548: 80a5e000                 cmp     %l7, 0
F003654C: 02800005                 be      loc_F0036560
F0036550: 80a46000                 cmp     %l1, 0
F0036554: 7fff9d58                 call    _m_free
F0036558: 90100017                 mov     %l7, %o0
F003655C: 80a46000                 cmp     %l1, 0
F0036560: 0280000f                 be      loc_F003659C
F0036564: 01000000                 nop
F0036568: d0046020                 ld      [%l1+0x20], %o0
F003656C: d002201c                 ld      [%o0+0x1C], %o0
F0036570: d0122002                 lduh    [%o0+2], %o0
F0036574: 808a2001                 btst    1, %o0
F0036578: 02800009                 be      loc_F003659C
F003657C: 90102004                 mov     4, %o0
F0036580: 932f2010                 sll     %i4, 16, %o1
F0036584: 933a6010                 sra     %o1, 16, %o1
F0036588: 94100011                 mov     %l1, %o2
F003658C: 173c04ea9612e060         set     _tcp_saveti, %o3
F0036594: 7ffff97b                 call    _tcp_trace
F0036598: 98102000                 mov     0, %o4
F003659C: 7fff9db2                 call    _m_freem
F00365A0: 90100018                 mov     %i0, %o0
F00365A4: 80a6a000                 cmp     %i2, 0
F00365A8: 02800004                 be      locret_F00365B8
F00365AC: 01000000                 nop
F00365B0: 7fffa0f9                 call    _soabort
F00365B4: 90100016                 mov     %l6, %o0
F00365B8: 81c7e008                 ret
F00365BC: 81e80000                 restore
