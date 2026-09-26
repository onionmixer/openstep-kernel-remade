F0097F30: 9de3bf78                 save    %sp, -0x88, %sp
F0097F34: f027a044                 st      %i0, [%fp+arg_44]
F0097F38: f227a048                 st      %i1, [%fp+arg_48]
F0097F3C: f427a04c                 st      %i2, [%fp+arg_4C]
F0097F40: f627a050                 st      %i3, [%fp+arg_50]
F0097F44: f427bfe8                 st      %i2, [%fp+var_18]
F0097F48: f227bfe4                 st      %i1, [%fp+var_1C]
F0097F4C: c027bfd8                 clr     [%fp+var_28]
F0097F50: 7ffffb81                 call    _setjmp
F0097F54: 9007bff0                 add     %fp, var_10, %o0
F0097F58: 80a22000                 cmp     %o0, 0
F0097F5C: 02800004                 be      loc_F0097F6C
F0097F60: 9010200e                 mov     0xE, %o0
F0097F64: 1080002d                 ba      loc_F0098018
F0097F68: d027bfd8                 st      %o0, [%fp+var_28]
F0097F6C: 113c04d0                 sethi   %hi(_active_threads), %o0
F0097F70: d2022260                 ld      [%o0+%lo(_active_threads)], %o1
F0097F74: 313c0447                 sethi   -0xFEEE400, %i0
F0097F78: 9007bff0                 add     %fp, var_10, %o0
F0097F7C: d0226074                 st      %o0, [%o1+0x74]
F0097F80: d407bfe8                 ld      [%fp+var_18], %o2
F0097F84: d206213c                 ld      [%i0+0x13C], %o1
F0097F88: d607a048                 ld      [%fp+arg_48], %o3
F0097F8C: 90027fff                 add     %o1, -1, %o0
F0097F90: 900ac008                 and     %o3, %o0, %o0
F0097F94: 92224008                 sub     %o1, %o0, %o1
F0097F98: 80a28009                 cmp     %o2, %o1
F0097F9C: 08800003                 bleu    loc_F0097FA8
F0097FA0: d427bfec                 st      %o2, [%fp+var_14]
F0097FA4: d227bfec                 st      %o1, [%fp+var_14]
F0097FA8: d007a044                 ld      [%fp+arg_44], %o0
F0097FAC: d407bfec                 ld      [%fp+var_14], %o2
F0097FB0: 7fffff4b                 call    _lbcopytoz
F0097FB4: 9210000b                 mov     %o3, %o1
F0097FB8: 94100008                 mov     %o0, %o2
F0097FBC: d007bfe8                 ld      [%fp+var_18], %o0
F0097FC0: d807a048                 ld      [%fp+arg_48], %o4
F0097FC4: d427bfe0                 st      %o2, [%fp+var_20]
F0097FC8: d207bfec                 ld      [%fp+var_14], %o1
F0097FCC: 9622000a                 sub     %o0, %o2, %o3
F0097FD0: d627bfe8                 st      %o3, [%fp+var_18]
F0097FD4: d007a044                 ld      [%fp+arg_44], %o0
F0097FD8: 80a28009                 cmp     %o2, %o1
F0097FDC: 9002000a                 add     %o0, %o2, %o0
F0097FE0: d027a044                 st      %o0, [%fp+arg_44]
F0097FE4: 9003000a                 add     %o4, %o2, %o0
F0097FE8: 12800005                 bne     loc_F0097FFC
F0097FEC: d027a048                 st      %o0, [%fp+arg_48]
F0097FF0: 80a2e000                 cmp     %o3, 0
F0097FF4: 32bfffe4                 bne,a   loc_F0097F84
F0097FF8: d407bfe8                 ld      [%fp+var_18], %o2
F0097FFC: c02b000a                 clrb    [%o4+%o2]
F0098000: d007a048                 ld      [%fp+arg_48], %o0
F0098004: 133c04d0                 sethi   %hi(_active_threads), %o1
F0098008: d2026260                 ld      [%o1+%lo(_active_threads)], %o1
F009800C: 90022001                 inc     %o0
F0098010: d027a048                 st      %o0, [%fp+arg_48]
F0098014: c0226074                 clr     [%o1+0x74]
F0098018: d007bfe8                 ld      [%fp+var_18], %o0
F009801C: 80a22000                 cmp     %o0, 0
F0098020: 12800005                 bne     loc_F0098034
F0098024: d407a050                 ld      [%fp+arg_50], %o2
F0098028: 90102002                 mov     2, %o0
F009802C: d027bfd8                 st      %o0, [%fp+var_28]
F0098030: d407a050                 ld      [%fp+arg_50], %o2
F0098034: 80a2a000                 cmp     %o2, 0
F0098038: 02800005                 be      loc_F009804C
F009803C: d207bfe4                 ld      [%fp+var_1C], %o1
F0098040: d007a048                 ld      [%fp+arg_48], %o0
F0098044: 90220009                 sub     %o0, %o1, %o0
F0098048: d0228000                 st      %o0, [%o2]
F009804C: f007bfd8                 ld      [%fp+var_28], %i0
F0098050: 81c7e008                 ret
F0098054: 81e80000                 restore
