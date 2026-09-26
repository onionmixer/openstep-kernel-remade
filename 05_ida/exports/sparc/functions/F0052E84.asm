F0052E84: 9de3bf88                 save    %sp, -0x78, %sp
F0052E88: c027bff4                 clr     [%fp+var_C]
F0052E8C: 9a10001a                 mov     %i2, %o5
F0052E90: 90102005                 mov     5, %o0
F0052E94: d0234000                 st      %o0, [%o5]
F0052E98: c0336038                 clrh    [%o5+0x38]
F0052E9C: 92100019                 mov     %i1, %o1
F0052EA0: 94102000                 mov     0, %o2
F0052EA4: 96102000                 mov     0, %o3
F0052EA8: 98102000                 mov     0, %o4
F0052EAC: d0062030                 ld      [%i0+0x30], %o0! __s
F0052EB0: 8407bff4                 add     %fp, var_C, %g2
F0052EB4: 7fffe198                 call    _direnter
F0052EB8: c423a05c                 st      %g2, [%sp+0x78+var_1C]
F0052EBC: b4920000                 orcc    %o0, %g0, %i2
F0052EC0: 12800025                 bne     loc_F0052F54
F0052EC4: 80a6a011                 cmp     %i2, 0x11
F0052EC8: 7ffed15c                 call    _strlen
F0052ECC: 9010001b                 mov     %i3, %o0
F0052ED0: b2100008                 mov     %o0, %i1
F0052ED4: 80a6603b                 cmp     %i1, 0x3B ! ';'
F0052ED8: 18800015                 bgu     loc_F0052F2C
F0052EDC: 113c043c                 sethi   %hi(_dosymlink), %o0
F0052EE0: d0022214                 ld      [%o0+%lo(_dosymlink)], %o0
F0052EE4: 80a22000                 cmp     %o0, 0
F0052EE8: 02800011                 be      loc_F0052F2C
F0052EEC: 9010001b                 mov     %i3, %o0! void *
F0052EF0: d207bff4                 ld      [%fp+var_C], %o1! void *
F0052EF4: 94100019                 mov     %i1, %o2! size_t
F0052EF8: 40010706                 call    _bcopy
F0052EFC: 9202608c                 inc     0x8C, %o1
F0052F00: d207bff4                 ld      [%fp+var_C], %o1
F0052F04: d00260c8                 ld      [%o1+0xC8], %o0
F0052F08: d402600c                 ld      [%o1+0xC], %o2
F0052F0C: 90122001                 bset    1, %o0
F0052F10: d02260c8                 st      %o0, [%o1+0xC8]
F0052F14: f222a014                 st      %i1, [%o2+0x14]
F0052F18: d0126044                 lduh    [%o1+0x44], %o0
F0052F1C: f2226070                 st      %i1, [%o1+0x70]
F0052F20: 90122042                 bset    0x42, %o0 ! 'B'
F0052F24: 1080000e                 ba      loc_F0052F5C
F0052F28: d0326044                 sth     %o0, [%o1+0x44]
F0052F2C: 90102001                 mov     1, %o0
F0052F30: 9410001b                 mov     %i3, %o2
F0052F34: 96100019                 mov     %i1, %o3
F0052F38: 98102000                 mov     0, %o4
F0052F3C: d207bff4                 ld      [%fp+var_C], %o1
F0052F40: 9a102001                 mov     1, %o5
F0052F44: 4000002e                 call    _rdwri
F0052F48: c023a05c                 clr     [%sp+0x78+var_1C]
F0052F4C: 10800004                 ba      loc_F0052F5C
F0052F50: b4100008                 mov     %o0, %i2
F0052F54: 32800005                 bne,a   loc_F0052F68
F0052F58: d2062030                 ld      [%i0+0x30], %o1
F0052F5C: 7fffec8f                 call    _iput
F0052F60: d007bff4                 ld      [%fp+var_C], %o0
F0052F64: d2062030                 ld      [%i0+0x30], %o1
F0052F68: d0126044                 lduh    [%o1+0x44], %o0
F0052F6C: 808a2046                 btst    0x46, %o0 ! 'F'
F0052F70: 02800021                 be      locret_F0052FF4
F0052F74: 90122008                 bset    8, %o0
F0052F78: d0326044                 sth     %o0, [%o1+0x44]
F0052F7C: 333c04d4                 sethi   %hi(_iuniqtime), %i1
F0052F80: 40006d94                 call    _microtime
F0052F84: 90166148                 or      %i1, %lo(_iuniqtime), %o0
F0052F88: d2062030                 ld      [%i0+0x30], %o1
F0052F8C: d0126044                 lduh    [%o1+0x44], %o0
F0052F90: 808a2004                 btst    4, %o0
F0052F94: 02800004                 be      loc_F0052FA4
F0052F98: d0066148                 ld      [%i1+%lo(_iuniqtime)], %o0
F0052F9C: d0226074                 st      %o0, [%o1+0x74]
F0052FA0: d2062030                 ld      [%i0+0x30], %o1
F0052FA4: d0126044                 lduh    [%o1+0x44], %o0
F0052FA8: 808a2002                 btst    2, %o0
F0052FAC: 02800003                 be      loc_F0052FB8
F0052FB0: d0066148                 ld      [%i1+0x148], %o0
F0052FB4: d022607c                 st      %o0, [%o1+0x7C]
F0052FB8: d2062030                 ld      [%i0+0x30], %o1
F0052FBC: d0126044                 lduh    [%o1+0x44], %o0
F0052FC0: 808a2040                 btst    0x40, %o0 ! '@'
F0052FC4: 22800007                 be,a    loc_F0052FE0
F0052FC8: d0062030                 ld      [%i0+0x30], %o0
F0052FCC: c022604c                 clr     [%o1+0x4C]
F0052FD0: d2062030                 ld      [%i0+0x30], %o1
F0052FD4: d0066148                 ld      [%i1+0x148], %o0
F0052FD8: d0226084                 st      %o0, [%o1+0x84]
F0052FDC: d0062030                 ld      [%i0+0x30], %o0
F0052FE0: 1300003f                 sethi   0xFC00, %o1
F0052FE4: d4122044                 lduh    [%o0+0x44], %o2
F0052FE8: 921263b9                 bset    0x3B9, %o1
F0052FEC: 940a8009                 and     %o2, %o1, %o2
F0052FF0: d4322044                 sth     %o2, [%o0+0x44]
F0052FF4: 81c7e008                 ret
F0052FF8: 91e8001a                 restore %g0, %i2, %o0
