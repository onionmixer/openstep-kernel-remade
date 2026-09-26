F0042C0C: 9de3bf20                 save    %sp, -0xE0, %sp
F0042C10: f227a048                 st      %i1, [%fp+arg_48]
F0042C14: e2062008                 ld      [%i0+8], %l1
F0042C18: 113c04cf                 sethi   %hi(_active_u), %o0
F0042C1C: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F0042C20: 153c04eb                 sethi   %hi(_rcstat), %o2
F0042C24: e407a05c                 ld      [%fp+arg_5C], %l2
F0042C28: f427bfb4                 st      %i2, [%fp+var_4C]
F0042C2C: f407a060                 ld      [%fp+arg_60], %i2
F0042C30: c027bf8c                 clr     [%fp+var_74]
F0042C34: da046010                 ld      [%l1+0x10], %o5
F0042C38: f627bfac                 st      %i3, [%fp+var_54]
F0042C3C: e6046014                 ld      [%l1+0x14], %l3
F0042C40: f827bfa4                 st      %i4, [%fp+var_5C]
F0042C44: d002a040                 ld      [%o2+%lo(_rcstat)], %o0
F0042C48: fa27bf9c                 st      %i5, [%fp+var_64]
F0042C4C: ea024000                 ld      [%o1], %l5
F0042C50: da27bf94                 st      %o5, [%fp+var_6C]
F0042C54: 90022001                 inc     %o0
F0042C58: d022a040                 st      %o0, [%o2+%lo(_rcstat)]
F0042C5C: 9a102002                 mov     2, %o5
F0042C60: d0044000                 ld      [%l1], %o0
F0042C64: 808a2002                 btst    2, %o0
F0042C68: 02800010                 be      loc_F0042CA8
F0042C6C: da27bf84                 st      %o5, [%fp+var_7C]
F0042C70: a012a040                 or      %o2, 0x40, %l0
F0042C74: d2042014                 ld      [%l0+0x14], %o1
F0042C78: 90100018                 mov     %i0, %o0! unsigned int
F0042C7C: 92026001                 inc     %o1
F0042C80: d2242014                 st      %o1, [%l0+0x14]
F0042C84: d4044000                 ld      [%l1], %o2
F0042C88: 92102017                 mov     0x17, %o1
F0042C8C: 9412a004                 bset    4, %o2
F0042C90: 7fff3e7a                 call    _sleep
F0042C94: d4244000                 st      %o2, [%l1]
F0042C98: d0044000                 ld      [%l1], %o0
F0042C9C: 808a2002                 btst    2, %o0
F0042CA0: 32bffff6                 bne,a   loc_F0042C78
F0042CA4: d2042014                 ld      [%l0+0x14], %o1
F0042CA8: d0044000                 ld      [%l1], %o0
F0042CAC: 90122002                 bset    2, %o0
F0042CB0: 808a2020                 btst    0x20, %o0 ! ' '
F0042CB4: 02800004                 be      loc_F0042CC4
F0042CB8: d0244000                 st      %o0, [%l1]
F0042CBC: 9a102001                 mov     1, %o5
F0042CC0: da27bf94                 st      %o5, [%fp+var_6C]
F0042CC4: 213c04cf                 sethi   %hi(_active_u), %l0
F0042CC8: d00421d8                 ld      [%l0+%lo(_active_u)], %o0
F0042CCC: 4000983e                 call    _lock_write
F0042CD0: 90022020                 inc     0x20, %o0 ! ' '
F0042CD4: 133c04eb                 sethi   %hi(_clntkudpxid), %o1
F0042CD8: d6026030                 ld      [%o1+%lo(_clntkudpxid)], %o3
F0042CDC: d40421d8                 ld      [%l0+%lo(_active_u)], %o2
F0042CE0: 9002e001                 add     %o3, 1, %o0
F0042CE4: d0226030                 st      %o0, [%o1+%lo(_clntkudpxid)]
F0042CE8: fa02a01c                 ld      [%o2+0x1C], %i5
F0042CEC: 113c043e                 sethi   %hi(_hz), %o0
F0042CF0: d2046074                 ld      [%l1+0x74], %o1
F0042CF4: b810000b                 mov     %o3, %i4
F0042CF8: e00223e0                 ld      [%o0+%lo(_hz)], %l0
F0042CFC: d222a01c                 st      %o1, [%o2+0x1C]
F0042D00: d0048000                 ld      [%l2], %o0
F0042D04: 7fff0dff                 call    _umul
F0042D08: 92100010                 mov     %l0, %o1
F0042D0C: 92100010                 mov     %l0, %o1
F0042D10: d404a004                 ld      [%l2+4], %o2
F0042D14: a0100008                 mov     %o0, %l0
F0042D18: 7fff0dfa                 call    _umul
F0042D1C: 9010000a                 mov     %o2, %o0! int
F0042D20: 130003d0                 sethi   0xF4000, %o1! int
F0042D24: 7fff0e39                 call    _div
F0042D28: 92126240                 bset    0x240, %o1
F0042D2C: b6040008                 add     %l0, %o0, %i3
F0042D30: 40014fa2                 call    _spltty
F0042D34: 01000000                 nop
F0042D38: d2044000                 ld      [%l1], %o1
F0042D3C: 808a6008                 btst    8, %o1
F0042D40: 02800015                 be      loc_F0042D94
F0042D44: a4100008                 mov     %o0, %l2
F0042D48: 333c004b                 sethi   -0xFFED400, %i1
F0042D4C: a0046068                 add     %l1, 0x68, %l0 ! 'h'
F0042D50: 293c043e                 sethi   -0xFEF0800, %l4
F0042D54: 90126010                 or      %o1, 0x10, %o0
F0042D58: d0244000                 st      %o0, [%l1]
F0042D5C: 901661e8                 or      %i1, 0x1E8, %o0! int
F0042D60: d40523e0                 ld      [%l4+0x3E0], %o2
F0042D64: 7fff1cb1                 call    _timeout
F0042D68: 92100010                 mov     %l0, %o1
F0042D6C: 90100010                 mov     %l0, %o0! unsigned int
F0042D70: 7fff3e42                 call    _sleep
F0042D74: 92102016                 mov     0x16, %o1
F0042D78: 7fff774b                 call    _sbflush
F0042D7C: 9004e024                 add     %l3, 0x24, %o0 ! '$'
F0042D80: d2044000                 ld      [%l1], %o1
F0042D84: 808a6008                 btst    8, %o1
F0042D88: 12bffff4                 bne     loc_F0042D58
F0042D8C: 90126010                 or      %o1, 0x10, %o0
F0042D90: d2044000                 ld      [%l1], %o1
F0042D94: 90100012                 mov     %l2, %o0
F0042D98: 92126008                 bset    8, %o1
F0042D9C: 40014fe2                 call    _splx
F0042DA0: d2244000                 st      %o1, [%l1]
F0042DA4: 113c010a901221b0         set     sub_F00429B0, %o0
F0042DAC: 92100011                 mov     %l1, %o1
F0042DB0: 170000089612e260         set     0x2260, %o3
F0042DB8: d4046068                 ld      [%l1+0x68], %o2
F0042DBC: 7fff6d61                 call    _mclgetx
F0042DC0: 98102001                 mov     1, %o4
F0042DC4: a4920000                 orcc    %o0, %g0, %l2
F0042DC8: 1280000a                 bne     loc_F0042DF0
F0042DCC: a0046034                 add     %l1, 0x34, %l0 ! '4'
F0042DD0: 9010200c                 mov     0xC, %o0
F0042DD4: d0246028                 st      %o0, [%l1+0x28]
F0042DD8: 90102037                 mov     0x37, %o0 ! '7'
F0042DDC: d024602c                 st      %o0, [%l1+0x2C]
F0042DE0: 7ffffef4                 call    sub_F00429B0
F0042DE4: 90100011                 mov     %l1, %o0
F0042DE8: 10800121                 ba      loc_F004326C
F0042DEC: d0046028                 ld      [%l1+0x28], %o0
F0042DF0: 90100010                 mov     %l0, %o0
F0042DF4: 92100012                 mov     %l2, %o1
F0042DF8: d6046068                 ld      [%l1+0x68], %o3
F0042DFC: 94102000                 mov     0, %o2
F0042E00: 40000b8a                 call    _xdrmbuf_init
F0042E04: f822c000                 st      %i4, [%o3]
F0042E08: da07bf8c                 ld      [%fp+var_74], %o5
F0042E0C: 80a36000                 cmp     %o5, 0
F0042E10: 22800009                 be,a    loc_F0042E34
F0042E14: d0046038                 ld      [%l1+0x38], %o0
F0042E18: d2046038                 ld      [%l1+0x38], %o1
F0042E1C: d4026014                 ld      [%o1+0x14], %o2
F0042E20: d207bf8c                 ld      [%fp+var_74], %o1
F0042E24: 9fc28000                 call    %o2
F0042E28: 90100010                 mov     %l0, %o0
F0042E2C: 10800027                 ba      loc_F0042EC8
F0042E30: da17bf8e                 lduh    [%fp+var_74+2], %o5
F0042E34: d4022014                 ld      [%o0+0x14], %o2
F0042E38: d2046064                 ld      [%l1+0x64], %o1
F0042E3C: 9fc28000                 call    %o2
F0042E40: 90100010                 mov     %l0, %o0
F0042E44: d2046038                 ld      [%l1+0x38], %o1
F0042E48: d4026004                 ld      [%o1+4], %o2
F0042E4C: 90100010                 mov     %l0, %o0
F0042E50: 9fc28000                 call    %o2
F0042E54: 9207a048                 add     %fp, arg_48, %o1
F0042E58: 80a22000                 cmp     %o0, 0
F0042E5C: 02800011                 be      loc_F0042EA0
F0042E60: 90102001                 mov     1, %o0
F0042E64: d0060000                 ld      [%i0], %o0
F0042E68: d4022020                 ld      [%o0+0x20], %o2
F0042E6C: d402a004                 ld      [%o2+4], %o2
F0042E70: 9fc28000                 call    %o2
F0042E74: 92100010                 mov     %l0, %o1
F0042E78: 80a22000                 cmp     %o0, 0
F0042E7C: 02800008                 be      loc_F0042E9C
F0042E80: d207bfac                 ld      [%fp+var_54], %o1
F0042E84: da07bfb4                 ld      [%fp+var_4C], %o5
F0042E88: 9fc34000                 call    %o5
F0042E8C: 90100010                 mov     %l0, %o0
F0042E90: 80a22000                 cmp     %o0, 0
F0042E94: 32800008                 bne,a   loc_F0042EB4
F0042E98: d0046038                 ld      [%l1+0x38], %o0
F0042E9C: 90102001                 mov     1, %o0
F0042EA0: d0246028                 st      %o0, [%l1+0x28]
F0042EA4: 90102005                 mov     5, %o0
F0042EA8: d024602c                 st      %o0, [%l1+0x2C]
F0042EAC: 108000ed                 ba      loc_F0043260
F0042EB0: 90100012                 mov     %l2, %o0
F0042EB4: d2022010                 ld      [%o0+0x10], %o1
F0042EB8: 9fc24000                 call    %o1
F0042EBC: 90100010                 mov     %l0, %o0
F0042EC0: d027bf8c                 st      %o0, [%fp+var_74]
F0042EC4: da17bf8e                 lduh    [%fp+var_74+2], %o5
F0042EC8: 90100013                 mov     %l3, %o0
F0042ECC: 92100012                 mov     %l2, %o1
F0042ED0: 94046018                 add     %l1, 0x18, %o2
F0042ED4: 400005db                 call    _ku_sendto_mbuf
F0042ED8: da34a008                 sth     %o5, [%l2+8]
F0042EDC: 80a22000                 cmp     %o0, 0
F0042EE0: 0280000e                 be      loc_F0042F18
F0042EE4: d024602c                 st      %o0, [%l1+0x2C]
F0042EE8: 90102003                 mov     3, %o0
F0042EEC: 108000df                 ba      loc_F0043268
F0042EF0: d0246028                 st      %o0, [%l1+0x28]
F0042EF4: 40014f68                 call    _splnet
F0042EF8: 01000000                 nop
F0042EFC: a4100008                 mov     %o0, %l2
F0042F00: 7fff76e9                 call    _sbflush
F0042F04: 9004e024                 add     %l3, 0x24, %o0 ! '$'
F0042F08: 40014f87                 call    _splx
F0042F0C: 90100012                 mov     %l2, %o0
F0042F10: 10800067                 ba      loc_F00430AC
F0042F14: 80a52000                 cmp     %l4, 0
F0042F18: a8102002                 mov     2, %l4
F0042F1C: 2d3c010d                 sethi   -0xFFBCC00, %l6
F0042F20: 113ffeefae1223fa         set     -0x44006, %l7
F0042F28: 40014f5b                 call    _splnet
F0042F2C: 01000000                 nop
F0042F30: d214e024                 lduh    [%l3+0x24], %o1
F0042F34: 80a26000                 cmp     %o1, 0
F0042F38: 12800029                 bne     loc_F0042FDC
F0042F3C: a4100008                 mov     %o0, %l2
F0042F40: 9015a018                 or      %l6, 0x18, %o0! int
F0042F44: 92100011                 mov     %l1, %o1
F0042F48: 7fff1c38                 call    _timeout
F0042F4C: 9410001b                 mov     %i3, %o2
F0042F50: d014e038                 lduh    [%l3+0x38], %o0
F0042F54: 80a56000                 cmp     %l5, 0
F0042F58: 90122004                 bset    4, %o0
F0042F5C: 0280000e                 be      loc_F0042F94
F0042F60: d034e038                 sth     %o0, [%l3+0x38]
F0042F64: d0044000                 ld      [%l1], %o0
F0042F68: 808a2800                 btst    0x800, %o0
F0042F6C: 0280000a                 be      loc_F0042F94
F0042F70: 9004e024                 add     %l3, 0x24, %o0 ! '$'! unsigned int
F0042F74: e005601c                 ld      [%l5+0x1C], %l0
F0042F78: 9210211a                 mov     0x11A, %o1
F0042F7C: 94140017                 or      %l0, %l7, %o2
F0042F80: 7fff3dbe                 call    _sleep
F0042F84: d425601c                 st      %o2, [%l5+0x1C]
F0042F88: b2100008                 mov     %o0, %i1
F0042F8C: 10800006                 ba      loc_F0042FA4
F0042F90: e025601c                 st      %l0, [%l5+0x1C]
F0042F94: b2102000                 mov     0, %i1
F0042F98: 9004e024                 add     %l3, 0x24, %o0 ! '$'! unsigned int
F0042F9C: 7fff3db7                 call    _sleep
F0042FA0: 92102014                 mov     0x14, %o1
F0042FA4: 9015a018                 or      %l6, 0x18, %o0
F0042FA8: 7fff1c2b                 call    _untimeout
F0042FAC: 92100011                 mov     %l1, %o1
F0042FB0: 80a66000                 cmp     %i1, 0
F0042FB4: 12800092                 bne     loc_F00431FC
F0042FB8: 01000000                 nop
F0042FBC: d0044000                 ld      [%l1], %o0
F0042FC0: 808a2001                 btst    1, %o0
F0042FC4: 12800095                 bne     loc_F0043218
F0042FC8: 900a3ffe                 and     %o0, -2, %o0
F0042FCC: d014e024                 lduh    [%l3+0x24], %o0
F0042FD0: 80a22000                 cmp     %o0, 0
F0042FD4: 02bfffdc                 be      loc_F0042F44
F0042FD8: 9015a018                 or      %l6, 0x18, %o0
F0042FDC: d014e056                 lduh    [%l3+0x56], %o0
F0042FE0: 80a22000                 cmp     %o0, 0
F0042FE4: 02800007                 be      loc_F0043000
F0042FE8: 90100013                 mov     %l3, %o0
F0042FEC: c034e056                 clrh    [%l3+0x56]
F0042FF0: 40014f4d                 call    _splx
F0042FF4: 90100012                 mov     %l2, %o0
F0042FF8: 1080002b                 ba      loc_F00430A4
F0042FFC: a8853fff                 inccc   -1, %l4
F0043000: 40000541                 call    _ku_recvfrom
F0043004: 9207bfe8                 add     %fp, var_18, %o1
F0043008: 80a6a000                 cmp     %i2, 0
F004300C: 0280000a                 be      loc_F0043034
F0043010: d0246070                 st      %o0, [%l1+0x70]
F0043014: d007bfe8                 ld      [%fp+var_18], %o0
F0043018: d0268000                 st      %o0, [%i2]
F004301C: d007bfec                 ld      [%fp+var_14], %o0
F0043020: d026a004                 st      %o0, [%i2+4]
F0043024: d007bff0                 ld      [%fp+var_10], %o0
F0043028: d026a008                 st      %o0, [%i2+8]
F004302C: d007bff4                 ld      [%fp+var_C], %o0
F0043030: d026a00c                 st      %o0, [%i2+0xC]
F0043034: 40014f3c                 call    _splx
F0043038: 90100012                 mov     %l2, %o0
F004303C: d2046070                 ld      [%l1+0x70], %o1
F0043040: 80a26000                 cmp     %o1, 0
F0043044: 22800018                 be,a    loc_F00430A4
F0043048: a8853fff                 inccc   -1, %l4
F004304C: d6026004                 ld      [%o1+4], %o3
F0043050: d4046070                 ld      [%l1+0x70], %o2
F0043054: 9002400b                 add     %o1, %o3, %o0
F0043058: d024606c                 st      %o0, [%l1+0x6C]
F004305C: d012a008                 lduh    [%o2+8], %o0
F0043060: 80a22003                 cmp     %o0, 3
F0043064: 0880000d                 bleu    loc_F0043098
F0043068: 9010000a                 mov     %o2, %o0
F004306C: d0046068                 ld      [%l1+0x68], %o0
F0043070: d202400b                 ld      [%o1+%o3], %o1
F0043074: d0020000                 ld      [%o0], %o0
F0043078: 80a24008                 cmp     %o1, %o0
F004307C: 02bfff9e                 be      loc_F0042EF4
F0043080: 133c04eb                 sethi   %hi(_rcstat), %o1
F0043084: 92126040                 bset    %lo(_rcstat), %o1
F0043088: d002600c                 ld      [%o1+0xC], %o0
F004308C: 90022001                 inc     %o0
F0043090: d022600c                 st      %o0, [%o1+0xC]
F0043094: d0046070                 ld      [%l1+0x70], %o0
F0043098: 7fff6af3                 call    _m_freem
F004309C: 01000000                 nop
F00430A0: a8853fff                 inccc   -1, %l4
F00430A4: 12bfffa1                 bne     loc_F0042F28
F00430A8: 80a52000                 cmp     %l4, 0
F00430AC: 12800007                 bne     loc_F00430C8
F00430B0: a004604c                 add     %l1, 0x4C, %l0 ! 'L'
F00430B4: 90102004                 mov     4, %o0
F00430B8: d0246028                 st      %o0, [%l1+0x28]
F00430BC: 90102005                 mov     5, %o0
F00430C0: 1080006a                 ba      loc_F0043268
F00430C4: d024602c                 st      %o0, [%l1+0x2C]
F00430C8: 90100010                 mov     %l0, %o0
F00430CC: d2046070                 ld      [%l1+0x70], %o1
F00430D0: 40000ad6                 call    _xdrmbuf_init
F00430D4: 94102001                 mov     1, %o2
F00430D8: 90100010                 mov     %l0, %o0! XDR *
F00430DC: da07bf9c                 ld      [%fp+var_64], %o5
F00430E0: 153c04eb                 sethi   %hi(__null_auth), %o2
F00430E4: d602a020                 ld      [%o2+%lo(__null_auth)], %o3
F00430E8: da27bfd4                 st      %o5, [%fp+var_2C]
F00430EC: da07bfa4                 ld      [%fp+var_5C], %o5
F00430F0: 9412a020                 bset    %lo(__null_auth), %o2
F00430F4: da27bfd8                 st      %o5, [%fp+var_28]
F00430F8: d802a004                 ld      [%o2+4], %o4
F00430FC: a407bfb8                 add     %fp, var_48, %l2
F0043100: d627bfc4                 st      %o3, [%fp+var_3C]
F0043104: d402a008                 ld      [%o2+8], %o2
F0043108: 92100012                 mov     %l2, %o1! rpc_err *
F004310C: d827bfc8                 st      %o4, [%fp+var_38]
F0043110: 4000039b                 call    _xdr_replymsg
F0043114: d427bfcc                 st      %o2, [%fp+var_34]
F0043118: 80a22000                 cmp     %o0, 0
F004311C: 0280004c                 be      loc_F004324C
F0043120: 90100012                 mov     %l2, %o0! rpc_msg *
F0043124: 400004c7                 call    __seterr_reply
F0043128: 92046028                 add     %l1, 0x28, %o1 ! '('
F004312C: d0046028                 ld      [%l1+0x28], %o0
F0043130: 80a22000                 cmp     %o0, 0
F0043134: 1280001e                 bne     loc_F00431AC
F0043138: da07bf84                 ld      [%fp+var_7C], %o5
F004313C: d0060000                 ld      [%i0], %o0
F0043140: d4022020                 ld      [%o0+0x20], %o2
F0043144: a407bfc4                 add     %fp, var_3C, %l2
F0043148: d402a008                 ld      [%o2+8], %o2
F004314C: 9fc28000                 call    %o2
F0043150: 92100012                 mov     %l2, %o1
F0043154: 80a22000                 cmp     %o0, 0
F0043158: 1280000c                 bne     loc_F0043188
F004315C: d007bfc8                 ld      [%fp+var_38], %o0
F0043160: 90102007                 mov     7, %o0
F0043164: d0246028                 st      %o0, [%l1+0x28]
F0043168: 90102006                 mov     6, %o0
F004316C: d024602c                 st      %o0, [%l1+0x2C]
F0043170: 133c04eb92126040         set     _rcstat, %o1
F0043178: d002601c                 ld      [%o1+0x1C], %o0
F004317C: 90022001                 inc     %o0
F0043180: d022601c                 st      %o0, [%o1+0x1C]
F0043184: d007bfc8                 ld      [%fp+var_38], %o0
F0043188: 80a22000                 cmp     %o0, 0
F004318C: 02800034                 be      loc_F004325C
F0043190: 90102002                 mov     2, %o0
F0043194: d024604c                 st      %o0, [%l1+0x4C]
F0043198: 90100010                 mov     %l0, %o0
F004319C: 4000031b                 call    _xdr_opaque_auth
F00431A0: 92100012                 mov     %l2, %o1
F00431A4: 1080002f                 ba      loc_F0043260
F00431A8: d0046070                 ld      [%l1+0x70], %o0
F00431AC: 80a36000                 cmp     %o5, 0
F00431B0: 2480002c                 ble,a   loc_F0043260
F00431B4: d0046070                 ld      [%l1+0x70], %o0
F00431B8: d0060000                 ld      [%i0], %o0
F00431BC: d2022020                 ld      [%o0+0x20], %o1
F00431C0: d202600c                 ld      [%o1+0xC], %o1
F00431C4: 9fc24000                 call    %o1
F00431C8: 01000000                 nop
F00431CC: 80a22000                 cmp     %o0, 0
F00431D0: 02800023                 be      loc_F004325C
F00431D4: da07bf84                 ld      [%fp+var_7C], %o5
F00431D8: 9a037fff                 inc     -1, %o5
F00431DC: da27bf84                 st      %o5, [%fp+var_7C]
F00431E0: 133c04eb92126040         set     _rcstat, %o1
F00431E8: d0026018                 ld      [%o1+0x18], %o0
F00431EC: c027bf8c                 clr     [%fp+var_74]
F00431F0: 90022001                 inc     %o0
F00431F4: 1080001a                 ba      loc_F004325C
F00431F8: d0226018                 st      %o0, [%o1+0x18]
F00431FC: 40014eca                 call    _splx
F0043200: 90100012                 mov     %l2, %o0
F0043204: 90102012                 mov     0x12, %o0
F0043208: d0246028                 st      %o0, [%l1+0x28]
F004320C: 90102004                 mov     4, %o0
F0043210: 10800016                 ba      loc_F0043268
F0043214: d024602c                 st      %o0, [%l1+0x2C]
F0043218: d0244000                 st      %o0, [%l1]
F004321C: 40014ec2                 call    _splx
F0043220: 90100012                 mov     %l2, %o0
F0043224: 90102005                 mov     5, %o0
F0043228: d0246028                 st      %o0, [%l1+0x28]
F004322C: 9010203c                 mov     0x3C, %o0 ! '<'
F0043230: d024602c                 st      %o0, [%l1+0x2C]
F0043234: 133c04eb92126040         set     _rcstat, %o1
F004323C: d0026010                 ld      [%o1+0x10], %o0
F0043240: 90022001                 inc     %o0
F0043244: 10800009                 ba      loc_F0043268
F0043248: d0226010                 st      %o0, [%o1+0x10]
F004324C: 90102002                 mov     2, %o0
F0043250: d0246028                 st      %o0, [%l1+0x28]
F0043254: 90102005                 mov     5, %o0
F0043258: d024602c                 st      %o0, [%l1+0x2C]
F004325C: d0046070                 ld      [%l1+0x70], %o0
F0043260: 7fff6a81                 call    _m_freem
F0043264: 01000000                 nop
F0043268: d0046028                 ld      [%l1+0x28], %o0
F004326C: 80a22000                 cmp     %o0, 0
F0043270: 02800024                 be      loc_F0043300
F0043274: 80a22012                 cmp     %o0, 0x12
F0043278: 02800022                 be      loc_F0043300
F004327C: 80a22001                 cmp     %o0, 1
F0043280: 02800020                 be      loc_F0043300
F0043284: da07bf94                 ld      [%fp+var_6C], %o5
F0043288: 9a037fff                 inc     -1, %o5
F004328C: 80a36000                 cmp     %o5, 0
F0043290: 0480001c                 ble     loc_F0043300
F0043294: da27bf94                 st      %o5, [%fp+var_6C]
F0043298: 133c04eb92126040         set     _rcstat, %o1
F00432A0: d0026008                 ld      [%o1+8], %o0
F00432A4: 90022001                 inc     %o0
F00432A8: d0226008                 st      %o0, [%o1+8]
F00432AC: 113c043e                 sethi   %hi(_hz), %o0
F00432B0: d20223e0                 ld      [%o0+%lo(_hz)], %o1
F00432B4: 952ee001                 sll     %i3, 1, %o2
F00432B8: 912a6004                 sll     %o1, 4, %o0
F00432BC: 90220009                 sub     %o0, %o1, %o0
F00432C0: 912a2002                 sll     %o0, 2, %o0
F00432C4: 80a28008                 cmp     %o2, %o0
F00432C8: 24800002                 ble,a   loc_F00432D0
F00432CC: 9010000a                 mov     %o2, %o0
F00432D0: d2046028                 ld      [%l1+0x28], %o1
F00432D4: 80a2600c                 cmp     %o1, 0xC
F00432D8: 02800005                 be      loc_F00432EC
F00432DC: b6100008                 mov     %o0, %i3
F00432E0: 80a26003                 cmp     %o1, 3
F00432E4: 12bffe93                 bne     loc_F0042D30
F00432E8: 01000000                 nop
F00432EC: 113c04d190122350         set     _lbolt, %o0! unsigned int
F00432F4: 7fff3ce1                 call    _sleep
F00432F8: 92102015                 mov     0x15, %o1
F00432FC: 30bffe8d                 ba,a    loc_F0042D30
F0043300: 113c04cf                 sethi   %hi(_active_u), %o0
F0043304: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F0043308: fa22601c                 st      %i5, [%o1+0x1C]
F004330C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0043310: 40009749                 call    _lock_done
F0043314: 90022020                 inc     0x20, %o0 ! ' '
F0043318: 40014e28                 call    _spltty
F004331C: 01000000                 nop
F0043320: d2044000                 ld      [%l1], %o1
F0043324: 808a6008                 btst    8, %o1
F0043328: 02800014                 be      loc_F0043378
F004332C: a4100008                 mov     %o0, %l2
F0043330: 2b3c004b                 sethi   -0xFFED400, %l5
F0043334: a0046068                 add     %l1, 0x68, %l0 ! 'h'
F0043338: 293c043e                 sethi   -0xFEF0800, %l4
F004333C: 90126010                 or      %o1, 0x10, %o0
F0043340: d0244000                 st      %o0, [%l1]
F0043344: 901561e8                 or      %l5, 0x1E8, %o0! int
F0043348: d40523e0                 ld      [%l4+0x3E0], %o2
F004334C: 7fff1b37                 call    _timeout
F0043350: 92100010                 mov     %l0, %o1
F0043354: 90100010                 mov     %l0, %o0! unsigned int
F0043358: 7fff3cc8                 call    _sleep
F004335C: 92102016                 mov     0x16, %o1
F0043360: 7fff75d1                 call    _sbflush
F0043364: 9004e024                 add     %l3, 0x24, %o0 ! '$'
F0043368: d2044000                 ld      [%l1], %o1
F004336C: 808a6008                 btst    8, %o1
F0043370: 12bffff4                 bne     loc_F0043340
F0043374: 90126010                 or      %o1, 0x10, %o0
F0043378: 40014e6b                 call    _splx
F004337C: 90100012                 mov     %l2, %o0
F0043380: d2044000                 ld      [%l1], %o1
F0043384: 900a7ffd                 and     %o1, -3, %o0
F0043388: 808a6004                 btst    4, %o1
F004338C: 02800006                 be      loc_F00433A4
F0043390: d0244000                 st      %o0, [%l1]
F0043394: 900a7ff9                 and     %o1, -7, %o0
F0043398: d0244000                 st      %o0, [%l1]
F004339C: 7fff3e93                 call    _wakeup
F00433A0: 90100018                 mov     %i0, %o0
F00433A4: d0046028                 ld      [%l1+0x28], %o0
F00433A8: 80a22000                 cmp     %o0, 0
F00433AC: 02800006                 be      loc_F00433C4
F00433B0: 133c04eb                 sethi   %hi(_rcstat), %o1
F00433B4: 92126040                 bset    %lo(_rcstat), %o1
F00433B8: d0026004                 ld      [%o1+4], %o0
F00433BC: 90022001                 inc     %o0
F00433C0: d0226004                 st      %o0, [%o1+4]
F00433C4: f0046028                 ld      [%l1+0x28], %i0
F00433C8: 81c7e008                 ret
F00433CC: 81e80000                 restore
