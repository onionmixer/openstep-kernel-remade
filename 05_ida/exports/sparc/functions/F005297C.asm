F005297C: 9de3bf88                 save    %sp, -0x78, %sp
F0052980: e0062030                 ld      [%i0+0x30], %l0
F0052984: 92102080                 mov     0x80, %o1
F0052988: f406a030                 ld      [%i2+0x30], %i2
F005298C: 7ffff1df                 call    _iaccess
F0052990: 90100010                 mov     %l0, %o0
F0052994: b0920000                 orcc    %o0, %g0, %i0
F0052998: 1280007e                 bne     locret_F0052B90
F005299C: 90100010                 mov     %l0, %o0
F00529A0: 92100019                 mov     %i1, %o1
F00529A4: 7fffe1d9                 call    _dirlook
F00529A8: 9407bff4                 add     %fp, var_C, %o2
F00529AC: b0920000                 orcc    %o0, %g0, %i0
F00529B0: 12800078                 bne     locret_F0052B90
F00529B4: 01000000                 nop
F00529B8: 7ffff1c4                 call    _iunlock
F00529BC: d007bff4                 ld      [%fp+var_C], %o0
F00529C0: d0142064                 lduh    [%l0+0x64], %o0
F00529C4: 808a2200                 btst    0x200, %o0
F00529C8: 02800010                 be      loc_F0052A08
F00529CC: 113c04cf                 sethi   %hi(_active_u), %o0
F00529D0: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00529D4: d002201c                 ld      [%o0+0x1C], %o0
F00529D8: d2522002                 ldsh    [%o0+2], %o1
F00529DC: 80a26000                 cmp     %o1, 0
F00529E0: 0280000b                 be      loc_F0052A0C
F00529E4: 90100019                 mov     %i1, %o0
F00529E8: d0542068                 ldsh    [%l0+0x68], %o0
F00529EC: 80a24008                 cmp     %o1, %o0
F00529F0: 02800006                 be      loc_F0052A08
F00529F4: d007bff4                 ld      [%fp+var_C], %o0
F00529F8: d0522068                 ldsh    [%o0+0x68], %o0
F00529FC: 80a20009                 cmp     %o0, %o1
F0052A00: 12800026                 bne     loc_F0052A98
F0052A04: b0102001                 mov     1, %i0
F0052A08: 90100019                 mov     %i1, %o0! __s1
F0052A0C: 133c043c                 sethi   %hi(asc_F010F208), %o1! "."
F0052A10: 7ffed5e7                 call    _strcmp
F0052A14: 92126208                 bset    %lo(asc_F010F208), %o1! "."
F0052A18: 80a22000                 cmp     %o0, 0
F0052A1C: 0280000b                 be      loc_F0052A48
F0052A20: 90100019                 mov     %i1, %o0! __s1
F0052A24: 133c043c                 sethi   %hi(asc_F010F210), %o1! ".."
F0052A28: 7ffed5e1                 call    _strcmp
F0052A2C: 92126210                 bset    %lo(asc_F010F210), %o1! ".."
F0052A30: 80a22000                 cmp     %o0, 0
F0052A34: 02800005                 be      loc_F0052A48
F0052A38: d807bff4                 ld      [%fp+var_C], %o4
F0052A3C: 80a4000c                 cmp     %l0, %o4
F0052A40: 32800004                 bne,a   loc_F0052A50
F0052A44: c023a05c                 clr     [%sp+0x78+var_1C]
F0052A48: 10800014                 ba      loc_F0052A98
F0052A4C: b0102016                 mov     0x16, %i0
F0052A50: 9010001a                 mov     %i2, %o0
F0052A54: 9210001b                 mov     %i3, %o1
F0052A58: 94102002                 mov     2, %o2
F0052A5C: 96100010                 mov     %l0, %o3
F0052A60: 7fffe2ad                 call    _direnter
F0052A64: 9a102000                 mov     0, %o5
F0052A68: b0920000                 orcc    %o0, %g0, %i0
F0052A6C: 12800009                 bne     loc_F0052A90
F0052A70: 80a63fff                 cmp     %i0, -1
F0052A74: 90100010                 mov     %l0, %o0
F0052A78: 92100019                 mov     %i1, %o1
F0052A7C: d407bff4                 ld      [%fp+var_C], %o2
F0052A80: 7fffe779                 call    _dirremove
F0052A84: 96102000                 mov     0, %o3
F0052A88: b0100008                 mov     %o0, %i0
F0052A8C: 80a62002                 cmp     %i0, 2
F0052A90: 22800002                 be,a    loc_F0052A98
F0052A94: b0102000                 mov     0, %i0
F0052A98: d0142044                 lduh    [%l0+0x44], %o0
F0052A9C: 808a2046                 btst    0x46, %o0 ! 'F'
F0052AA0: 0280001c                 be      loc_F0052B10
F0052AA4: 90122008                 bset    8, %o0
F0052AA8: d0342044                 sth     %o0, [%l0+0x44]
F0052AAC: 333c04d4                 sethi   %hi(_iuniqtime), %i1
F0052AB0: 40006ec8                 call    _microtime
F0052AB4: 90166148                 or      %i1, %lo(_iuniqtime), %o0
F0052AB8: d0142044                 lduh    [%l0+0x44], %o0
F0052ABC: 808a2004                 btst    4, %o0
F0052AC0: 02800003                 be      loc_F0052ACC
F0052AC4: d0066148                 ld      [%i1+%lo(_iuniqtime)], %o0
F0052AC8: d0242074                 st      %o0, [%l0+0x74]
F0052ACC: d0142044                 lduh    [%l0+0x44], %o0
F0052AD0: 808a2002                 btst    2, %o0
F0052AD4: 02800003                 be      loc_F0052AE0
F0052AD8: d0066148                 ld      [%i1+0x148], %o0
F0052ADC: d024207c                 st      %o0, [%l0+0x7C]
F0052AE0: d0142044                 lduh    [%l0+0x44], %o0
F0052AE4: 808a2040                 btst    0x40, %o0 ! '@'
F0052AE8: 22800006                 be,a    loc_F0052B00
F0052AEC: d2142044                 lduh    [%l0+0x44], %o1
F0052AF0: c024204c                 clr     [%l0+0x4C]
F0052AF4: d0066148                 ld      [%i1+0x148], %o0
F0052AF8: d0242084                 st      %o0, [%l0+0x84]
F0052AFC: d2142044                 lduh    [%l0+0x44], %o1
F0052B00: 1100003f901223b9         set     0xFFB9, %o0
F0052B08: 920a4008                 and     %o1, %o0, %o1
F0052B0C: d2342044                 sth     %o1, [%l0+0x44]
F0052B10: d016a044                 lduh    [%i2+0x44], %o0
F0052B14: 808a2046                 btst    0x46, %o0 ! 'F'
F0052B18: 0280001c                 be      loc_F0052B88
F0052B1C: 90122008                 bset    8, %o0
F0052B20: d036a044                 sth     %o0, [%i2+0x44]
F0052B24: 213c04d4                 sethi   %hi(_iuniqtime), %l0
F0052B28: 40006eaa                 call    _microtime
F0052B2C: 90142148                 or      %l0, %lo(_iuniqtime), %o0
F0052B30: d016a044                 lduh    [%i2+0x44], %o0
F0052B34: 808a2004                 btst    4, %o0
F0052B38: 02800003                 be      loc_F0052B44
F0052B3C: d0042148                 ld      [%l0+%lo(_iuniqtime)], %o0
F0052B40: d026a074                 st      %o0, [%i2+0x74]
F0052B44: d016a044                 lduh    [%i2+0x44], %o0
F0052B48: 808a2002                 btst    2, %o0
F0052B4C: 02800003                 be      loc_F0052B58
F0052B50: d0042148                 ld      [%l0+0x148], %o0
F0052B54: d026a07c                 st      %o0, [%i2+0x7C]
F0052B58: d016a044                 lduh    [%i2+0x44], %o0
F0052B5C: 808a2040                 btst    0x40, %o0 ! '@'
F0052B60: 22800006                 be,a    loc_F0052B78
F0052B64: d216a044                 lduh    [%i2+0x44], %o1
F0052B68: c026a04c                 clr     [%i2+0x4C]
F0052B6C: d0042148                 ld      [%l0+0x148], %o0
F0052B70: d026a084                 st      %o0, [%i2+0x84]
F0052B74: d216a044                 lduh    [%i2+0x44], %o1
F0052B78: 1100003f901223b9         set     0xFFB9, %o0
F0052B80: 920a4008                 and     %o1, %o0, %o1
F0052B84: d236a044                 sth     %o1, [%i2+0x44]
F0052B88: 7fffedbb                 call    _irele
F0052B8C: d007bff4                 ld      [%fp+var_C], %o0
F0052B90: 81c7e008                 ret
F0052B94: 81e80000                 restore
