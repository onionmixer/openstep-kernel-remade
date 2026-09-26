F0023A78: 9de3bf90                 save    %sp, -0x70, %sp
F0023A7C: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0023A80: 92102000                 mov     0, %o1
F0023A84: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0023A88: 94102001                 mov     1, %o2
F0023A8C: e2022024                 ld      [%o0+0x24], %l1
F0023A90: 96102000                 mov     0, %o3
F0023A94: d0044000                 ld      [%l1], %o0
F0023A98: 40000bcb                 call    _lookupname
F0023A9C: 9807bff4                 add     %fp, var_C, %o4
F0023AA0: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0023AA4: d02a6038                 stb     %o0, [%o1+0x38]
F0023AA8: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0023AAC: d04a2038                 ldsb    [%o0+0x38], %o0
F0023AB0: 80a22000                 cmp     %o0, 0
F0023AB4: 12800007                 bne     locret_F0023AD0
F0023AB8: d007bff4                 ld      [%fp+var_C], %o0
F0023ABC: d2046004                 ld      [%l1+4], %o1
F0023AC0: 4000001a                 call    _cstatfs
F0023AC4: d0022024                 ld      [%o0+0x24], %o0
F0023AC8: 40001427                 call    _vn_rele
F0023ACC: d007bff4                 ld      [%fp+var_C], %o0
F0023AD0: 81c7e008                 ret
F0023AD4: 81e80000                 restore
