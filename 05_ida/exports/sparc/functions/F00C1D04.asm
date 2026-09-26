F00C1D04: 9de3bf98                 save    %sp, -0x68, %sp
F00C1D08: 7fffe5de                 call    _zsstealkey
F00C1D0C: 01000000                 nop
F00C1D10: 133c0483                 sethi   %hi(_kbddev+1), %o1
F00C1D14: d20a6225                 ldub    [%o1+%lo(_kbddev+1)], %o1
F00C1D18: a00a20ff                 and     %o0, 0xFF, %l0
F00C1D1C: 90100010                 mov     %l0, %o0
F00C1D20: 952a6004                 sll     %o1, 4, %o2
F00C1D24: 94028009                 add     %o2, %o1, %o2
F00C1D28: 952aa003                 sll     %o2, 3, %o2
F00C1D2C: 133c04fb92126260         set     _zs_tty, %o1
F00C1D34: 7ffffcd3                 call    sub_F00C1080
F00C1D38: 92028009                 add     %o2, %o1, %o1
F00C1D3C: 80a22000                 cmp     %o0, 0
F00C1D40: 02800018                 be      loc_F00C1DA0
F00C1D44: 113c04cb                 sethi   %hi(unk_F0132F88), %o0
F00C1D48: b0122388                 or      %o0, %lo(unk_F0132F88), %i0
F00C1D4C: 900c3f7f                 and     %l0, -0x81, %o0
F00C1D50: d0262008                 st      %o0, [%i0+8]
F00C1D54: 400010e2                 call    _IOGetTimestamp
F00C1D58: 90100018                 mov     %i0, %o0
F00C1D5C: 91342007                 srl     %l0, 7, %o0
F00C1D60: 901a2001                 btog    1, %o0
F00C1D64: 80a22000                 cmp     %o0, 0
F00C1D68: 02800012                 be      loc_F00C1DB0
F00C1D6C: d02e200c                 stb     %o0, [%i0+0xC]
F00C1D70: 113c04cb981223f8         set     unk_F0132FF8, %o4
F00C1D78: d2062008                 ld      [%i0+8], %o1
F00C1D7C: 90102001                 mov     1, %o0
F00C1D80: 95326005                 srl     %o1, 5, %o2
F00C1D84: 952aa002                 sll     %o2, 2, %o2
F00C1D88: 920a601f                 and     %o1, 0x1F, %o1
F00C1D8C: d602800c                 ld      [%o2+%o4], %o3
F00C1D90: 912a0009                 sll     %o0, %o1, %o0
F00C1D94: 808ac008                 btst    %o0, %o3
F00C1D98: 02800004                 be      loc_F00C1DA8
F00C1D9C: 9012c008                 bset    %o3, %o0
F00C1DA0: 10800011                 ba      locret_F00C1DE4
F00C1DA4: b0102000                 mov     0, %i0
F00C1DA8: 1080000d                 ba      loc_F00C1DDC
F00C1DAC: d022800c                 st      %o0, [%o2+%o4]
F00C1DB0: 153c04cb9412a3f8         set     unk_F0132FF8, %o2
F00C1DB8: d2062008                 ld      [%i0+8], %o1
F00C1DBC: 90102001                 mov     1, %o0
F00C1DC0: 97326005                 srl     %o1, 5, %o3
F00C1DC4: 972ae002                 sll     %o3, 2, %o3
F00C1DC8: 920a601f                 and     %o1, 0x1F, %o1
F00C1DCC: d802c00a                 ld      [%o3+%o2], %o4
F00C1DD0: 912a0009                 sll     %o0, %o1, %o0
F00C1DD4: 902b0008                 andn    %o4, %o0, %o0
F00C1DD8: d022c00a                 st      %o0, [%o3+%o2]
F00C1DDC: 113c04cbb0122388         set     unk_F0132F88, %i0
F00C1DE4: 81c7e008                 ret
F00C1DE8: 81e80000                 restore
