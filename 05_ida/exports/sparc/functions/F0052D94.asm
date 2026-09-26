F0052D94: 9de3bf98                 save    %sp, -0x68, %sp
F0052D98: d8064000                 ld      [%i1], %o4
F0052D9C: d0066004                 ld      [%i1+4], %o0
F0052DA0: e0062030                 ld      [%i0+0x30], %l0
F0052DA4: 80a22001                 cmp     %o0, 1
F0052DA8: 12800009                 bne     loc_F0052DCC
F0052DAC: d6032004                 ld      [%o4+4], %o3
F0052DB0: 80a2e3ff                 cmp     %o3, 0x3FF
F0052DB4: 28800032                 bleu,a  locret_F0052E7C
F0052DB8: b0102016                 mov     0x16, %i0
F0052DBC: d0066008                 ld      [%i1+8], %o0
F0052DC0: 808a23ff                 btst    0x3FF, %o0
F0052DC4: 02800004                 be      loc_F0052DD4
F0052DC8: 960afc00                 and     %o3, -0x400, %o3
F0052DCC: 1080002c                 ba      locret_F0052E7C
F0052DD0: b0102016                 mov     0x16, %i0
F0052DD4: d4032004                 ld      [%o4+4], %o2
F0052DD8: 90100010                 mov     %l0, %o0
F0052DDC: d2066014                 ld      [%i1+0x14], %o1
F0052DE0: 9422800b                 sub     %o2, %o3, %o2
F0052DE4: 9222400a                 sub     %o1, %o2, %o1
F0052DE8: d2266014                 st      %o1, [%i1+0x14]
F0052DEC: d6232004                 st      %o3, [%o4+4]
F0052DF0: 92100019                 mov     %i1, %o1
F0052DF4: 94102000                 mov     0, %o2
F0052DF8: 7ffff9f2                 call    sub_F00515C0
F0052DFC: 96102000                 mov     0, %o3
F0052E00: d2142044                 lduh    [%l0+0x44], %o1
F0052E04: 808a6046                 btst    0x46, %o1 ! 'F'
F0052E08: 0280001d                 be      locret_F0052E7C
F0052E0C: b0100008                 mov     %o0, %i0
F0052E10: 90126008                 or      %o1, 8, %o0
F0052E14: d0342044                 sth     %o0, [%l0+0x44]
F0052E18: 333c04d4                 sethi   %hi(_iuniqtime), %i1
F0052E1C: 40006ded                 call    _microtime
F0052E20: 90166148                 or      %i1, %lo(_iuniqtime), %o0
F0052E24: d0142044                 lduh    [%l0+0x44], %o0
F0052E28: 808a2004                 btst    4, %o0
F0052E2C: 02800003                 be      loc_F0052E38
F0052E30: d0066148                 ld      [%i1+%lo(_iuniqtime)], %o0
F0052E34: d0242074                 st      %o0, [%l0+0x74]
F0052E38: d0142044                 lduh    [%l0+0x44], %o0
F0052E3C: 808a2002                 btst    2, %o0
F0052E40: 02800003                 be      loc_F0052E4C
F0052E44: d0066148                 ld      [%i1+0x148], %o0
F0052E48: d024207c                 st      %o0, [%l0+0x7C]
F0052E4C: d0142044                 lduh    [%l0+0x44], %o0
F0052E50: 808a2040                 btst    0x40, %o0 ! '@'
F0052E54: 22800006                 be,a    loc_F0052E6C
F0052E58: d2142044                 lduh    [%l0+0x44], %o1
F0052E5C: c024204c                 clr     [%l0+0x4C]
F0052E60: d0066148                 ld      [%i1+0x148], %o0
F0052E64: d0242084                 st      %o0, [%l0+0x84]
F0052E68: d2142044                 lduh    [%l0+0x44], %o1
F0052E6C: 1100003f901223b9         set     0xFFB9, %o0
F0052E74: 920a4008                 and     %o1, %o0, %o1
F0052E78: d2342044                 sth     %o1, [%l0+0x44]
F0052E7C: 81c7e008                 ret
F0052E80: 81e80000                 restore
