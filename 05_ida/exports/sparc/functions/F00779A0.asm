F00779A0: 9de3bf90                 save    %sp, -0x70, %sp
F00779A4: e2062004                 ld      [%i0+4], %l1
F00779A8: e227bff4                 st      %l1, [%fp+var_C]
F00779AC: d2060000                 ld      [%i0], %o1
F00779B0: d227bff0                 st      %o1, [%fp+var_10]
F00779B4: d0062008                 ld      [%i0+8], %o0
F00779B8: 80a44008                 cmp     %l1, %o0
F00779BC: 32bffffb                 bne,a   loc_F00779A8
F00779C0: e2062004                 ld      [%i0+4], %l1
F00779C4: 90100009                 mov     %o1, %o0
F00779C8: 210003d0                 sethi   0xF4000, %l0
F00779CC: 7ffe3b0d                 call    _udiv
F00779D0: 92142240                 or      %l0, 0x240, %o1
F00779D4: 90044008                 add     %l1, %o0, %o0
F00779D8: d0264000                 st      %o0, [%i1]
F00779DC: d007bff0                 ld      [%fp+var_10], %o0
F00779E0: 7ffe3bb0                 call    _urem
F00779E4: 92142240                 or      %l0, 0x240, %o1
F00779E8: d0266004                 st      %o0, [%i1+4]
F00779EC: 81c7e008                 ret
F00779F0: 81e80000                 restore
