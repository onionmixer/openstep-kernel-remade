F00779F4: 9de3bf90                 save    %sp, -0x70, %sp
F00779F8: 920620e0                 add     %i0, 0xE0, %o1
F00779FC: e2026004                 ld      [%o1+4], %l1
F0077A00: e227bff4                 st      %l1, [%fp+var_C]
F0077A04: d4024000                 ld      [%o1], %o2
F0077A08: d427bff0                 st      %o2, [%fp+var_10]
F0077A0C: d0026008                 ld      [%o1+8], %o0
F0077A10: 80a44008                 cmp     %l1, %o0
F0077A14: 32bffffb                 bne,a   loc_F0077A00
F0077A18: e2026004                 ld      [%o1+4], %l1
F0077A1C: 9010000a                 mov     %o2, %o0
F0077A20: 210003d0                 sethi   0xF4000, %l0
F0077A24: 7ffe3af7                 call    _udiv
F0077A28: 92142240                 or      %l0, 0x240, %o1
F0077A2C: 90044008                 add     %l1, %o0, %o0
F0077A30: d0264000                 st      %o0, [%i1]
F0077A34: d007bff0                 ld      [%fp+var_10], %o0
F0077A38: 7ffe3b9a                 call    _urem
F0077A3C: 92142240                 or      %l0, 0x240, %o1
F0077A40: d0266004                 st      %o0, [%i1+4]
F0077A44: 920620f0                 add     %i0, 0xF0, %o1
F0077A48: e2026004                 ld      [%o1+4], %l1
F0077A4C: e227bff4                 st      %l1, [%fp+var_C]
F0077A50: d4024000                 ld      [%o1], %o2
F0077A54: d427bff0                 st      %o2, [%fp+var_10]
F0077A58: d0026008                 ld      [%o1+8], %o0
F0077A5C: 80a44008                 cmp     %l1, %o0
F0077A60: 32bffffb                 bne,a   loc_F0077A4C
F0077A64: e2026004                 ld      [%o1+4], %l1
F0077A68: 9010000a                 mov     %o2, %o0
F0077A6C: 210003d0                 sethi   0xF4000, %l0
F0077A70: 7ffe3ae4                 call    _udiv
F0077A74: 92142240                 or      %l0, 0x240, %o1
F0077A78: 90044008                 add     %l1, %o0, %o0
F0077A7C: d0268000                 st      %o0, [%i2]
F0077A80: d007bff0                 ld      [%fp+var_10], %o0
F0077A84: 7ffe3b87                 call    _urem
F0077A88: 92142240                 or      %l0, 0x240, %o1
F0077A8C: d026a004                 st      %o0, [%i2+4]
F0077A90: 81c7e008                 ret
F0077A94: 81e80000                 restore
