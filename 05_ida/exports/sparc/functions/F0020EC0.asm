F0020EC0: 9de3bf90                 save    %sp, -0x70, %sp
F0020EC4: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F0020EC8: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F0020ECC: 7fffa946                 call    _falloc
F0020ED0: e2022024                 ld      [%o0+0x24], %l1
F0020ED4: a0920000                 orcc    %o0, %g0, %l0
F0020ED8: 02800023                 be      locret_F0020F64
F0020EDC: a614a1dc                 or      %l2, %lo(dword_F0133DDC), %l3
F0020EE0: 90102003                 mov     3, %o0
F0020EE4: d0242008                 st      %o0, [%l0+8]
F0020EE8: 90102002                 mov     2, %o0
F0020EEC: d034200c                 sth     %o0, [%l0+0xC]
F0020EF0: 113c042d90122190         set     _socketops, %o0
F0020EF8: d0242014                 st      %o0, [%l0+0x14]
F0020EFC: d0044000                 ld      [%l1], %o0
F0020F00: d4046004                 ld      [%l1+4], %o2
F0020F04: d6046008                 ld      [%l1+8], %o3
F0020F08: 7ffff5b9                 call    _socreate
F0020F0C: 9207bff4                 add     %fp, var_C, %o1
F0020F10: d204a1dc                 ld      [%l2+0x1DC], %o1
F0020F14: d02a6038                 stb     %o0, [%o1+0x38]
F0020F18: d204a1dc                 ld      [%l2+0x1DC], %o1
F0020F1C: d04a6038                 ldsb    [%o1+0x38], %o0
F0020F20: 80a22000                 cmp     %o0, 0
F0020F24: 3280000b                 bne,a   loc_F0020F50
F0020F28: d004fffc                 ld      [%l3-4], %o0
F0020F2C: d007bff4                 ld      [%fp+var_C], %o0
F0020F30: d0242018                 st      %o0, [%l0+0x18]
F0020F34: d004a1dc                 ld      [%l2+0x1DC], %o0
F0020F38: d204fffc                 ld      [%l3-4], %o1
F0020F3C: d0022030                 ld      [%o0+0x30], %o0
F0020F40: d202614c                 ld      [%o1+0x14C], %o1
F0020F44: 912a2002                 sll     %o0, 2, %o0
F0020F48: 10800007                 ba      locret_F0020F64
F0020F4C: e0224008                 st      %l0, [%o1+%o0]
F0020F50: d2026030                 ld      [%o1+0x30], %o1
F0020F54: d002214c                 ld      [%o0+0x14C], %o0
F0020F58: 932a6002                 sll     %o1, 2, %o1
F0020F5C: c0220009                 clr     [%o0+%o1]
F0020F60: c034200e                 clrh    [%l0+0xE]
F0020F64: 81c7e008                 ret
F0020F68: 81e80000                 restore
