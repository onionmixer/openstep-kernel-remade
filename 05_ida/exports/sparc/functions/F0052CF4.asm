F0052CF4: 9de3bf98                 save    %sp, -0x68, %sp
F0052CF8: 92100019                 mov     %i1, %o1
F0052CFC: 94102000                 mov     0, %o2
F0052D00: e0062030                 ld      [%i0+0x30], %l0
F0052D04: 96102001                 mov     1, %o3
F0052D08: 7fffe6d7                 call    _dirremove
F0052D0C: 90100010                 mov     %l0, %o0
F0052D10: d2142044                 lduh    [%l0+0x44], %o1
F0052D14: 808a6046                 btst    0x46, %o1 ! 'F'
F0052D18: 0280001d                 be      locret_F0052D8C
F0052D1C: b0100008                 mov     %o0, %i0
F0052D20: 90126008                 or      %o1, 8, %o0
F0052D24: d0342044                 sth     %o0, [%l0+0x44]
F0052D28: 333c04d4                 sethi   %hi(_iuniqtime), %i1
F0052D2C: 40006e29                 call    _microtime
F0052D30: 90166148                 or      %i1, %lo(_iuniqtime), %o0
F0052D34: d0142044                 lduh    [%l0+0x44], %o0
F0052D38: 808a2004                 btst    4, %o0
F0052D3C: 02800003                 be      loc_F0052D48
F0052D40: d0066148                 ld      [%i1+%lo(_iuniqtime)], %o0
F0052D44: d0242074                 st      %o0, [%l0+0x74]
F0052D48: d0142044                 lduh    [%l0+0x44], %o0
F0052D4C: 808a2002                 btst    2, %o0
F0052D50: 02800003                 be      loc_F0052D5C
F0052D54: d0066148                 ld      [%i1+0x148], %o0
F0052D58: d024207c                 st      %o0, [%l0+0x7C]
F0052D5C: d0142044                 lduh    [%l0+0x44], %o0
F0052D60: 808a2040                 btst    0x40, %o0 ! '@'
F0052D64: 22800006                 be,a    loc_F0052D7C
F0052D68: d2142044                 lduh    [%l0+0x44], %o1
F0052D6C: c024204c                 clr     [%l0+0x4C]
F0052D70: d0066148                 ld      [%i1+0x148], %o0
F0052D74: d0242084                 st      %o0, [%l0+0x84]
F0052D78: d2142044                 lduh    [%l0+0x44], %o1
F0052D7C: 1100003f901223b9         set     0xFFB9, %o0
F0052D84: 920a4008                 and     %o1, %o0, %o1
F0052D88: d2342044                 sth     %o1, [%l0+0x44]
F0052D8C: 81c7e008                 ret
F0052D90: 81e80000                 restore
