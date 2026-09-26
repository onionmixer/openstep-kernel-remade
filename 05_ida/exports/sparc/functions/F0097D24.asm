F0097D24: 9de3bf78                 save    %sp, -0x88, %sp
F0097D28: f027a044                 st      %i0, [%fp+arg_44]
F0097D2C: f227a048                 st      %i1, [%fp+arg_48]
F0097D30: f427a04c                 st      %i2, [%fp+arg_4C]
F0097D34: f627a050                 st      %i3, [%fp+arg_50]
F0097D38: f427bfe8                 st      %i2, [%fp+var_18]
F0097D3C: f227bfe4                 st      %i1, [%fp+var_1C]
F0097D40: c027bfd8                 clr     [%fp+var_28]
F0097D44: 7ffffc04                 call    _setjmp
F0097D48: 9007bff0                 add     %fp, var_10, %o0
F0097D4C: 80a22000                 cmp     %o0, 0
F0097D50: 02800004                 be      loc_F0097D60
F0097D54: 9010200e                 mov     0xE, %o0
F0097D58: 10800028                 ba      loc_F0097DF8
F0097D5C: d027bfd8                 st      %o0, [%fp+var_28]
F0097D60: 113c04d0                 sethi   %hi(_active_threads), %o0
F0097D64: d2022260                 ld      [%o0+%lo(_active_threads)], %o1
F0097D68: 313c0447                 sethi   -0xFEEE400, %i0
F0097D6C: 9007bff0                 add     %fp, var_10, %o0
F0097D70: d0226074                 st      %o0, [%o1+0x74]
F0097D74: d407bfe8                 ld      [%fp+var_18], %o2
F0097D78: d206213c                 ld      [%i0+0x13C], %o1
F0097D7C: d607a044                 ld      [%fp+arg_44], %o3
F0097D80: 90027fff                 add     %o1, -1, %o0
F0097D84: 900ac008                 and     %o3, %o0, %o0
F0097D88: 92224008                 sub     %o1, %o0, %o1
F0097D8C: 80a28009                 cmp     %o2, %o1
F0097D90: 08800003                 bleu    loc_F0097D9C
F0097D94: d427bfec                 st      %o2, [%fp+var_14]
F0097D98: d227bfec                 st      %o1, [%fp+var_14]
F0097D9C: d207a048                 ld      [%fp+arg_48], %o1
F0097DA0: d407bfec                 ld      [%fp+var_14], %o2
F0097DA4: 7fffffce                 call    _lbcopytoz
F0097DA8: 9010000b                 mov     %o3, %o0
F0097DAC: d207bfe8                 ld      [%fp+var_18], %o1
F0097DB0: d027bfe0                 st      %o0, [%fp+var_20]
F0097DB4: d407a048                 ld      [%fp+arg_48], %o2
F0097DB8: 96224008                 sub     %o1, %o0, %o3
F0097DBC: d627bfe8                 st      %o3, [%fp+var_18]
F0097DC0: d207a044                 ld      [%fp+arg_44], %o1
F0097DC4: 94028008                 add     %o2, %o0, %o2
F0097DC8: 92024008                 add     %o1, %o0, %o1
F0097DCC: d227a044                 st      %o1, [%fp+arg_44]
F0097DD0: d207bfec                 ld      [%fp+var_14], %o1
F0097DD4: 80a20009                 cmp     %o0, %o1
F0097DD8: 12800005                 bne     loc_F0097DEC
F0097DDC: d427a048                 st      %o2, [%fp+arg_48]
F0097DE0: 80a2e000                 cmp     %o3, 0
F0097DE4: 32bfffe5                 bne,a   loc_F0097D78
F0097DE8: d407bfe8                 ld      [%fp+var_18], %o2
F0097DEC: 113c04d0                 sethi   %hi(_active_threads), %o0
F0097DF0: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0097DF4: c0222074                 clr     [%o0+0x74]
F0097DF8: d007bfe8                 ld      [%fp+var_18], %o0
F0097DFC: 80a22000                 cmp     %o0, 0
F0097E00: 12800005                 bne     loc_F0097E14
F0097E04: d007bfd8                 ld      [%fp+var_28], %o0
F0097E08: 90102002                 mov     2, %o0
F0097E0C: d027bfd8                 st      %o0, [%fp+var_28]
F0097E10: d007bfd8                 ld      [%fp+var_28], %o0
F0097E14: 80a22000                 cmp     %o0, 0
F0097E18: 12800008                 bne     loc_F0097E38
F0097E1C: d407a050                 ld      [%fp+arg_50], %o2
F0097E20: d007a048                 ld      [%fp+arg_48], %o0
F0097E24: c02a0000                 clrb    [%o0]
F0097E28: d007a048                 ld      [%fp+arg_48], %o0
F0097E2C: 90022001                 inc     %o0
F0097E30: d027a048                 st      %o0, [%fp+arg_48]
F0097E34: d407a050                 ld      [%fp+arg_50], %o2
F0097E38: 80a2a000                 cmp     %o2, 0
F0097E3C: 02800005                 be      loc_F0097E50
F0097E40: d207bfe4                 ld      [%fp+var_1C], %o1
F0097E44: d007a048                 ld      [%fp+arg_48], %o0
F0097E48: 90220009                 sub     %o0, %o1, %o0
F0097E4C: d0228000                 st      %o0, [%o2]
F0097E50: f007bfd8                 ld      [%fp+var_28], %i0
F0097E54: 81c7e008                 ret
F0097E58: 81e80000                 restore
