F0031E50: 9de3bf90                 save    %sp, -0x70, %sp
F0031E54: a6102000                 mov     0, %l3
F0031E58: 40019358                 call    _spltty
F0031E5C: 01000000                 nop
F0031E60: 133c04d9                 sethi   %hi(_ipintrq), %o1
F0031E64: e2026080                 ld      [%o1+%lo(_ipintrq)], %l1
F0031E68: a8100008                 mov     %o0, %l4
F0031E6C: 80a46000                 cmp     %l1, 0
F0031E70: 02800041                 be      loc_F0031F74
F0031E74: 94126080                 or      %o1, %lo(_ipintrq), %o2
F0031E78: d004607c                 ld      [%l1+0x7C], %o0
F0031E7C: 80a22000                 cmp     %o0, 0
F0031E80: 12800003                 bne     loc_F0031E8C
F0031E84: d0226080                 st      %o0, [%o1+%lo(_ipintrq)]
F0031E88: c022a004                 clr     [%o2+4]
F0031E8C: c024607c                 clr     [%l1+0x7C]
F0031E90: d002a008                 ld      [%o2+8], %o0
F0031E94: 90023fff                 inc     -1, %o0
F0031E98: d022a008                 st      %o0, [%o2+8]
F0031E9C: d2146008                 lduh    [%l1+8], %o1
F0031EA0: d0046004                 ld      [%l1+4], %o0
F0031EA4: 92027ffc                 inc     -4, %o1
F0031EA8: 952a6010                 sll     %o1, 16, %o2
F0031EAC: e6044008                 ld      [%l1+%o0], %l3
F0031EB0: 80a2a000                 cmp     %o2, 0
F0031EB4: 90022004                 inc     4, %o0
F0031EB8: d0246004                 st      %o0, [%l1+4]
F0031EBC: 1280002e                 bne     loc_F0031F74
F0031EC0: d2346008                 sth     %o1, [%l1+8]
F0031EC4: 4001933d                 call    _spltty
F0031EC8: 01000000                 nop
F0031ECC: d254600a                 ldsh    [%l1+0xA], %o1
F0031ED0: 80a26000                 cmp     %o1, 0
F0031ED4: 12800005                 bne     loc_F0031EE8
F0031ED8: a4100008                 mov     %o0, %l2
F0031EDC: 113c0431                 sethi   %hi(aMfree_7), %o0! "mfree"
F0031EE0: 7fff8ca4                 call    _panic
F0031EE4: 901223f0                 bset    %lo(aMfree_7), %o0! "mfree"
F0031EE8: 153c04d2                 sethi   %hi(word_F0134B0C), %o2
F0031EEC: d254600a                 ldsh    [%l1+0xA], %o1
F0031EF0: 9612a30c                 or      %o2, %lo(word_F0134B0C), %o3
F0031EF4: 932a6001                 sll     %o1, 1, %o1
F0031EF8: d012400b                 lduh    [%o1+%o3], %o0
F0031EFC: 90023fff                 inc     -1, %o0
F0031F00: d032400b                 sth     %o0, [%o1+%o3]
F0031F04: d012a30c                 lduh    [%o2+%lo(word_F0134B0C)], %o0
F0031F08: 90022001                 inc     %o0
F0031F0C: d032a30c                 sth     %o0, [%o2+%lo(word_F0134B0C)]
F0031F10: d0046004                 ld      [%l1+4], %o0
F0031F14: 80a2207f                 cmp     %o0, 0x7F
F0031F18: 08800004                 bleu    loc_F0031F28
F0031F1C: c034600a                 clrh    [%l1+0xA]
F0031F20: 7fffb13a                 call    _mclput
F0031F24: 90100011                 mov     %l1, %o0
F0031F28: c0246004                 clr     [%l1+4]
F0031F2C: c024607c                 clr     [%l1+0x7C]
F0031F30: e0044000                 ld      [%l1], %l0
F0031F34: 133c04d3                 sethi   %hi(_mfree), %o1
F0031F38: d4026168                 ld      [%o1+%lo(_mfree)], %o2
F0031F3C: 90100012                 mov     %l2, %o0
F0031F40: d4244000                 st      %o2, [%l1]
F0031F44: e2226168                 st      %l1, [%o1+%lo(_mfree)]
F0031F48: 40019377                 call    _splx
F0031F4C: a2126168                 or      %o1, %lo(_mfree), %l1
F0031F50: 133c04d2                 sethi   %hi(_m_want), %o1
F0031F54: d00262e8                 ld      [%o1+%lo(_m_want)], %o0
F0031F58: 80a22000                 cmp     %o0, 0
F0031F5C: 22800006                 be,a    loc_F0031F74
F0031F60: a2100010                 mov     %l0, %l1
F0031F64: c02262e8                 clr     [%o1+%lo(_m_want)]
F0031F68: 7fff83a0                 call    _wakeup
F0031F6C: 90100011                 mov     %l1, %o0
F0031F70: a2100010                 mov     %l0, %l1
F0031F74: 4001936c                 call    _splx
F0031F78: 90100014                 mov     %l4, %o0
F0031F7C: 80a46000                 cmp     %l1, 0
F0031F80: 02800169                 be      locret_F0032524
F0031F84: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F0031F88: d0022070                 ld      [%o0+%lo(_in_ifaddr)], %o0
F0031F8C: 80a22000                 cmp     %o0, 0
F0031F90: 02800162                 be      loc_F0032518
F0031F94: 113c04d9                 sethi   %hi(_ipstat), %o0
F0031F98: d20220d0                 ld      [%o0+%lo(_ipstat)], %o1
F0031F9C: 92026001                 inc     %o1
F0031FA0: d22220d0                 st      %o1, [%o0+%lo(_ipstat)]
F0031FA4: d2046004                 ld      [%l1+4], %o1
F0031FA8: 80a2607c                 cmp     %o1, 0x7C ! '|'
F0031FAC: 18800006                 bgu     loc_F0031FC4
F0031FB0: a01220d0                 or      %o0, %lo(_ipstat), %l0
F0031FB4: d0146008                 lduh    [%l1+8], %o0
F0031FB8: 80a22013                 cmp     %o0, 0x13
F0031FBC: 3880000d                 bgu,a   loc_F0031FF0
F0031FC0: d00c4009                 ldub    [%l1+%o1], %o0
F0031FC4: 90100011                 mov     %l1, %o0
F0031FC8: 7fffb043                 call    _m_pullup
F0031FCC: 92102014                 mov     0x14, %o1
F0031FD0: a2920000                 orcc    %o0, %g0, %l1
F0031FD4: 32800006                 bne,a   loc_F0031FEC
F0031FD8: d2046004                 ld      [%l1+4], %o1
F0031FDC: d004200c                 ld      [%l0+0xC], %o0
F0031FE0: 90022001                 inc     %o0
F0031FE4: 10bfff9d                 ba      loc_F0031E58
F0031FE8: d024200c                 st      %o0, [%l0+0xC]
F0031FEC: d00c4009                 ldub    [%l1+%o1], %o0
F0031FF0: 900a200f                 and     %o0, 0xF, %o0
F0031FF4: a52a2002                 sll     %o0, 2, %l2
F0031FF8: 80a4a013                 cmp     %l2, 0x13
F0031FFC: 18800008                 bgu     loc_F003201C
F0032000: a0044009                 add     %l1, %o1, %l0
F0032004: 133c04d9921260d0         set     _ipstat, %o1
F003200C: d0026010                 ld      [%o1+0x10], %o0
F0032010: 90022001                 inc     %o0
F0032014: 10800141                 ba      loc_F0032518
F0032018: d0226010                 st      %o0, [%o1+0x10]
F003201C: d0546008                 ldsh    [%l1+8], %o0
F0032020: 80a48008                 cmp     %l2, %o0
F0032024: 0480000e                 ble     loc_F003205C
F0032028: 90100011                 mov     %l1, %o0
F003202C: 7fffb02a                 call    _m_pullup
F0032030: 92100012                 mov     %l2, %o1
F0032034: a2920000                 orcc    %o0, %g0, %l1
F0032038: 32800008                 bne,a   loc_F0032058
F003203C: d0046004                 ld      [%l1+4], %o0
F0032040: 133c04d9921260d0         set     _ipstat, %o1
F0032048: d0026010                 ld      [%o1+0x10], %o0
F003204C: 90022001                 inc     %o0
F0032050: 10bfff82                 ba      loc_F0031E58
F0032054: d0226010                 st      %o0, [%o1+0x10]
F0032058: a0044008                 add     %l1, %o0, %l0
F003205C: 113c0431                 sethi   %hi(_ipcksum), %o0
F0032060: d00a23d8                 ldub    [%o0+%lo(_ipcksum)], %o0
F0032064: 80a22000                 cmp     %o0, 0
F0032068: 0280000e                 be      loc_F00320A0
F003206C: 90100011                 mov     %l1, %o0
F0032070: 40019b86                 call    _in_cksum
F0032074: 92100012                 mov     %l2, %o1
F0032078: d034200a                 sth     %o0, [%l0+0xA]
F003207C: 912a2010                 sll     %o0, 16, %o0
F0032080: 80a22000                 cmp     %o0, 0
F0032084: 02800007                 be      loc_F00320A0
F0032088: 133c04d9                 sethi   %hi(_ipstat), %o1
F003208C: 921260d0                 bset    %lo(_ipstat), %o1
F0032090: d0026004                 ld      [%o1+4], %o0
F0032094: 90022001                 inc     %o0
F0032098: 10800120                 ba      loc_F0032518
F003209C: d0226004                 st      %o0, [%o1+4]
F00320A0: d0142002                 lduh    [%l0+2], %o0
F00320A4: d0342002                 sth     %o0, [%l0+2]
F00320A8: 912a2010                 sll     %o0, 16, %o0
F00320AC: 913a2010                 sra     %o0, 16, %o0
F00320B0: 80a20012                 cmp     %o0, %l2
F00320B4: 36800008                 bge,a   loc_F00320D4
F00320B8: d4142002                 lduh    [%l0+2], %o2
F00320BC: 133c04d9921260d0         set     _ipstat, %o1
F00320C4: d0026014                 ld      [%o1+0x14], %o0
F00320C8: 90022001                 inc     %o0
F00320CC: 10800113                 ba      loc_F0032518
F00320D0: d0226014                 st      %o0, [%o1+0x14]
F00320D4: d0142004                 lduh    [%l0+4], %o0
F00320D8: d2142006                 lduh    [%l0+6], %o1
F00320DC: d0342004                 sth     %o0, [%l0+4]
F00320E0: d2342006                 sth     %o1, [%l0+6]
F00320E4: d2546008                 ldsh    [%l1+8], %o1
F00320E8: e227bff4                 st      %l1, [%fp+var_C]
F00320EC: d0044000                 ld      [%l1], %o0
F00320F0: 80a22000                 cmp     %o0, 0
F00320F4: 02800008                 be      loc_F0032114
F00320F8: 9422400a                 sub     %o1, %o2, %o2
F00320FC: e2044000                 ld      [%l1], %l1
F0032100: d0546008                 ldsh    [%l1+8], %o0
F0032104: d2044000                 ld      [%l1], %o1
F0032108: 80a26000                 cmp     %o1, 0
F003210C: 12bffffc                 bne     loc_F00320FC
F0032110: 94028008                 add     %o2, %o0, %o2
F0032114: 80a2a000                 cmp     %o2, 0
F0032118: 22800014                 be,a    loc_F0032168
F003211C: e207bff4                 ld      [%fp+var_C], %l1
F0032120: 36800009                 bge,a   loc_F0032144
F0032124: d0546008                 ldsh    [%l1+8], %o0
F0032128: 133c04d9921260d0         set     _ipstat, %o1
F0032130: d0026008                 ld      [%o1+8], %o0
F0032134: e207bff4                 ld      [%fp+var_C], %l1
F0032138: 90022001                 inc     %o0
F003213C: 108000f7                 ba      loc_F0032518
F0032140: d0226008                 st      %o0, [%o1+8]
F0032144: 80a28008                 cmp     %o2, %o0
F0032148: 34800005                 bg,a    loc_F003215C
F003214C: d007bff4                 ld      [%fp+var_C], %o0
F0032150: 9022000a                 sub     %o0, %o2, %o0
F0032154: 10800004                 ba      loc_F0032164
F0032158: d0346008                 sth     %o0, [%l1+8]
F003215C: 7fffafa1                 call    _m_adj
F0032160: 9220000a                 neg     %o2, %o1
F0032164: e207bff4                 ld      [%fp+var_C], %l1
F0032168: 113c0431                 sethi   %hi(_ip_nhops), %o0
F003216C: 80a4a014                 cmp     %l2, 0x14
F0032170: 08800008                 bleu    loc_F0032190
F0032174: c02223cc                 clr     [%o0+%lo(_ip_nhops)]
F0032178: 90100010                 mov     %l0, %o0
F003217C: 4000020b                 call    _ip_dooptions
F0032180: 92100013                 mov     %l3, %o1
F0032184: 80a22000                 cmp     %o0, 0
F0032188: 12bfff34                 bne     loc_F0031E58
F003218C: 01000000                 nop
F0032190: d214e00c                 lduh    [%l3+0xC], %o1
F0032194: 11000010                 sethi   0x4000, %o0
F0032198: 808a4008                 btst    %o0, %o1
F003219C: 02800019                 be      loc_F0032200
F00321A0: 113c04d9                 sethi   -0xFEC9C00, %o0
F00321A4: d0046004                 ld      [%l1+4], %o0
F00321A8: 80a2207c                 cmp     %o0, 0x7C ! '|'
F00321AC: 18800006                 bgu     loc_F00321C4
F00321B0: 90100011                 mov     %l1, %o0
F00321B4: d0146008                 lduh    [%l1+8], %o0
F00321B8: 80a2201b                 cmp     %o0, 0x1B
F00321BC: 18800007                 bgu     loc_F00321D8
F00321C0: 90100011                 mov     %l1, %o0
F00321C4: 7fffafc4                 call    _m_pullup
F00321C8: 9210201c                 mov     0x1C, %o1
F00321CC: a2920000                 orcc    %o0, %g0, %l1
F00321D0: 0280000c                 be      loc_F0032200
F00321D4: 113c04d9                 sethi   -0xFEC9C00, %o0
F00321D8: d0046004                 ld      [%l1+4], %o0
F00321DC: 92044008                 add     %l1, %o0, %o1
F00321E0: d00a6009                 ldub    [%o1+9], %o0
F00321E4: 80a22011                 cmp     %o0, 0x11
F00321E8: 12800006                 bne     loc_F0032200
F00321EC: 113c04d9                 sethi   -0xFEC9C00, %o0
F00321F0: d0126016                 lduh    [%o1+0x16], %o0
F00321F4: 80a22044                 cmp     %o0, 0x44 ! 'D'
F00321F8: 02800066                 be      loc_F0032390
F00321FC: 113c04d9                 sethi   -0xFEC9C00, %o0
F0032200: d2022070                 ld      [%o0+0x70], %o1
F0032204: 80a26000                 cmp     %o1, 0
F0032208: 02800020                 be      loc_F0032288
F003220C: d4042010                 ld      [%l0+0x10], %o2
F0032210: d0026004                 ld      [%o1+4], %o0
F0032214: 80a2000a                 cmp     %o0, %o2
F0032218: 2280005f                 be,a    loc_F0032394
F003221C: d2142006                 lduh    [%l0+6], %o1
F0032220: d0026020                 ld      [%o1+0x20], %o0
F0032224: d012200c                 lduh    [%o0+0xC], %o0
F0032228: 808a2002                 btst    2, %o0
F003222C: 22800013                 be,a    loc_F0032278
F0032230: d2026040                 ld      [%o1+0x40], %o1
F0032234: d0026014                 ld      [%o1+0x14], %o0
F0032238: 80a2000a                 cmp     %o0, %o2
F003223C: 22800056                 be,a    loc_F0032394
F0032240: d2142006                 lduh    [%l0+6], %o1
F0032244: d0026038                 ld      [%o1+0x38], %o0
F0032248: 80a28008                 cmp     %o2, %o0
F003224C: 22800052                 be,a    loc_F0032394
F0032250: d2142006                 lduh    [%l0+6], %o1
F0032254: d0026030                 ld      [%o1+0x30], %o0
F0032258: 80a28008                 cmp     %o2, %o0
F003225C: 2280004e                 be,a    loc_F0032394
F0032260: d2142006                 lduh    [%l0+6], %o1
F0032264: d0026028                 ld      [%o1+0x28], %o0
F0032268: 80a28008                 cmp     %o2, %o0
F003226C: 2280004a                 be,a    loc_F0032394
F0032270: d2142006                 lduh    [%l0+6], %o1
F0032274: d2026040                 ld      [%o1+0x40], %o1
F0032278: 80a26000                 cmp     %o1, 0
F003227C: 32bfffe6                 bne,a   loc_F0032214
F0032280: d0026004                 ld      [%o1+4], %o0
F0032284: d4042010                 ld      [%l0+0x10], %o2
F0032288: 113c0000                 sethi   -0x10000000, %o0
F003228C: 13380000                 sethi   -0x20000000, %o1
F0032290: 900a8008                 and     %o2, %o0, %o0
F0032294: 80a20009                 cmp     %o0, %o1
F0032298: 12800037                 bne     loc_F0032374
F003229C: 80a2bfff                 cmp     %o2, -1
F00322A0: 113c0432                 sethi   %hi(_ip_mrouter), %o0
F00322A4: d00221e0                 ld      [%o0+%lo(_ip_mrouter)], %o0
F00322A8: 80a22000                 cmp     %o0, 0
F00322AC: 0280000e                 be      loc_F00322E4
F00322B0: 90100010                 mov     %l0, %o0
F00322B4: d4142004                 lduh    [%l0+4], %o2
F00322B8: 92100013                 mov     %l3, %o1
F00322BC: 40001cd0                 call    _ip_mforward
F00322C0: d4342004                 sth     %o2, [%l0+4]
F00322C4: 80a22000                 cmp     %o0, 0
F00322C8: 12800028                 bne     loc_F0032368
F00322CC: 01000000                 nop
F00322D0: d0142004                 lduh    [%l0+4], %o0
F00322D4: d20c2009                 ldub    [%l0+9], %o1
F00322D8: 80a26002                 cmp     %o1, 2
F00322DC: 0280002d                 be      loc_F0032390
F00322E0: d0342004                 sth     %o0, [%l0+4]
F00322E4: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F00322E8: d2022070                 ld      [%o0+%lo(_in_ifaddr)], %o1
F00322EC: 80a26000                 cmp     %o1, 0
F00322F0: 0280000b                 be      loc_F003231C
F00322F4: 01000000                 nop
F00322F8: d0026020                 ld      [%o1+0x20], %o0
F00322FC: 80a20013                 cmp     %o0, %l3
F0032300: 02800007                 be      loc_F003231C
F0032304: 80a26000                 cmp     %o1, 0
F0032308: d2026040                 ld      [%o1+0x40], %o1
F003230C: 80a26000                 cmp     %o1, 0
F0032310: 32bffffb                 bne,a   loc_F00322FC
F0032314: d0026020                 ld      [%o1+0x20], %o0
F0032318: 80a26000                 cmp     %o1, 0
F003231C: 32800004                 bne,a   loc_F003232C
F0032320: d2026044                 ld      [%o1+0x44], %o1
F0032324: 1080000e                 ba      loc_F003235C
F0032328: 92102000                 mov     0, %o1
F003232C: 80a26000                 cmp     %o1, 0
F0032330: 0280000c                 be      loc_F0032360
F0032334: 01000000                 nop
F0032338: d4042010                 ld      [%l0+0x10], %o2
F003233C: d0024000                 ld      [%o1], %o0
F0032340: 80a2000a                 cmp     %o0, %o2
F0032344: 02800007                 be      loc_F0032360
F0032348: 80a26000                 cmp     %o1, 0
F003234C: d2026014                 ld      [%o1+0x14], %o1
F0032350: 80a26000                 cmp     %o1, 0
F0032354: 32bffffb                 bne,a   loc_F0032340
F0032358: d0024000                 ld      [%o1], %o0
F003235C: 80a26000                 cmp     %o1, 0
F0032360: 3280000d                 bne,a   loc_F0032394
F0032364: d2142006                 lduh    [%l0+6], %o1
F0032368: 7fffae3f                 call    _m_freem
F003236C: 900c3f80                 and     %l0, -0x80, %o0
F0032370: 30bffeba                 ba,a    loc_F0031E58
F0032374: 02800007                 be      loc_F0032390
F0032378: 80a2a000                 cmp     %o2, 0
F003237C: 02800005                 be      loc_F0032390
F0032380: 90100010                 mov     %l0, %o0
F0032384: 40000307                 call    _ip_forward
F0032388: 92100013                 mov     %l3, %o1
F003238C: 30bffeb3                 ba,a    loc_F0031E58
F0032390: d2142006                 lduh    [%l0+6], %o1
F0032394: 113fffd0                 sethi   -0xC000, %o0
F0032398: 80aa4008                 andncc  %o1, %o0, %g0
F003239C: 22800049                 be,a    loc_F00324C0
F00323A0: d0142002                 lduh    [%l0+2], %o0
F00323A4: 113c04d9                 sethi   %hi(_ipq), %o0
F00323A8: d80220b0                 ld      [%o0+%lo(_ipq)], %o4
F00323AC: 901220b0                 bset    %lo(_ipq), %o0
F00323B0: 80a30008                 cmp     %o4, %o0
F00323B4: 2280001c                 be,a    loc_F0032424
F00323B8: 98102000                 mov     0, %o4
F00323BC: d4142004                 lduh    [%l0+4], %o2
F00323C0: 96100008                 mov     %o0, %o3
F00323C4: d013200a                 lduh    [%o4+0xA], %o0
F00323C8: 80a28008                 cmp     %o2, %o0
F00323CC: 32800012                 bne,a   loc_F0032414
F00323D0: d8030000                 ld      [%o4], %o4
F00323D4: d204200c                 ld      [%l0+0xC], %o1
F00323D8: d0032014                 ld      [%o4+0x14], %o0
F00323DC: 80a24008                 cmp     %o1, %o0
F00323E0: 3280000d                 bne,a   loc_F0032414
F00323E4: d8030000                 ld      [%o4], %o4
F00323E8: d2042010                 ld      [%l0+0x10], %o1
F00323EC: d0032018                 ld      [%o4+0x18], %o0
F00323F0: 80a24008                 cmp     %o1, %o0
F00323F4: 32800008                 bne,a   loc_F0032414
F00323F8: d8030000                 ld      [%o4], %o4
F00323FC: d20c2009                 ldub    [%l0+9], %o1
F0032400: d00b2009                 ldub    [%o4+9], %o0
F0032404: 80a24008                 cmp     %o1, %o0
F0032408: 22800008                 be,a    loc_F0032428
F003240C: d0142002                 lduh    [%l0+2], %o0
F0032410: d8030000                 ld      [%o4], %o4
F0032414: 80a3000b                 cmp     %o4, %o3
F0032418: 32bfffec                 bne,a   loc_F00323C8
F003241C: d013200a                 lduh    [%o4+0xA], %o0
F0032420: 98102000                 mov     0, %o4
F0032424: d0142002                 lduh    [%l0+2], %o0
F0032428: c02c2001                 clrb    [%l0+1]
F003242C: d2142006                 lduh    [%l0+6], %o1
F0032430: 90220012                 sub     %o0, %l2, %o0
F0032434: d0342002                 sth     %o0, [%l0+2]
F0032438: 11000008                 sethi   0x2000, %o0
F003243C: 808a4008                 btst    %o0, %o1
F0032440: 02800003                 be      loc_F003244C
F0032444: 90102001                 mov     1, %o0
F0032448: d02c2001                 stb     %o0, [%l0+1]
F003244C: d0142006                 lduh    [%l0+6], %o0
F0032450: 932a2003                 sll     %o0, 3, %o1
F0032454: d00c2001                 ldub    [%l0+1], %o0
F0032458: 80a22000                 cmp     %o0, 0
F003245C: 12800006                 bne     loc_F0032474
F0032460: d2342006                 sth     %o1, [%l0+6]
F0032464: 912a6010                 sll     %o1, 16, %o0
F0032468: 80a22000                 cmp     %o0, 0
F003246C: 0280000f                 be      loc_F00324A8
F0032470: 80a32000                 cmp     %o4, 0
F0032474: 90100010                 mov     %l0, %o0
F0032478: 173c04d99612e0d0         set     _ipstat, %o3
F0032480: d402e018                 ld      [%o3+0x18], %o2
F0032484: 9210000c                 mov     %o4, %o1
F0032488: 9402a001                 inc     %o2
F003248C: 40000028                 call    _ip_reass
F0032490: d422e018                 st      %o2, [%o3+0x18]
F0032494: a0920000                 orcc    %o0, %g0, %l0
F0032498: 02bffe70                 be      loc_F0031E58
F003249C: a20c3f80                 and     %l0, -0x80, %l1
F00324A0: 1080000b                 ba      loc_F00324CC
F00324A4: e227bff4                 st      %l1, [%fp+var_C]
F00324A8: 22800009                 be,a    loc_F00324CC
F00324AC: e227bff4                 st      %l1, [%fp+var_C]
F00324B0: 400000db                 call    _ip_freef
F00324B4: 9010000c                 mov     %o4, %o0
F00324B8: 10800005                 ba      loc_F00324CC
F00324BC: e227bff4                 st      %l1, [%fp+var_C]
F00324C0: 90220012                 sub     %o0, %l2, %o0
F00324C4: d0342002                 sth     %o0, [%l0+2]
F00324C8: e227bff4                 st      %l1, [%fp+var_C]
F00324CC: 4000e5f6                 call    _receive_ip_datagram
F00324D0: 9007bff4                 add     %fp, var_C, %o0
F00324D4: 80a22000                 cmp     %o0, 0
F00324D8: 12bffe60                 bne     loc_F0031E58
F00324DC: 113c04d9                 sethi   %hi(_ip_protox), %o0
F00324E0: d20c2009                 ldub    [%l0+9], %o1
F00324E4: 90122220                 bset    %lo(_ip_protox), %o0
F00324E8: d40a4008                 ldub    [%o1+%o0], %o2
F00324EC: 932aa001                 sll     %o2, 1, %o1
F00324F0: 9202400a                 add     %o1, %o2, %o1
F00324F4: 932a6004                 sll     %o1, 4, %o1
F00324F8: 153c04319412a1a0         set     _inetsw, %o2
F0032500: 9202400a                 add     %o1, %o2, %o1
F0032504: d402600c                 ld      [%o1+0xC], %o2
F0032508: d007bff4                 ld      [%fp+var_C], %o0
F003250C: 9fc28000                 call    %o2
F0032510: 92100013                 mov     %l3, %o1
F0032514: 30bffe51                 ba,a    loc_F0031E58
F0032518: 7fffadd3                 call    _m_freem
F003251C: 90100011                 mov     %l1, %o0
F0032520: 30bffe4e                 ba,a    loc_F0031E58
F0032524: 81c7e008                 ret
F0032528: 81e80000                 restore
