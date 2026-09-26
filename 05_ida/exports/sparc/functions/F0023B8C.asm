F0023B8C: 9de3bf90                 save    %sp, -0x70, %sp
F0023B90: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F0023B94: 92102000                 mov     0, %o1
F0023B98: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F0023B9C: 94102001                 mov     1, %o2
F0023BA0: d0022024                 ld      [%o0+0x24], %o0
F0023BA4: 96102000                 mov     0, %o3
F0023BA8: d0020000                 ld      [%o0], %o0
F0023BAC: 40000b86                 call    _lookupname
F0023BB0: 9807bff4                 add     %fp, var_C, %o4
F0023BB4: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F0023BB8: d02a6038                 stb     %o0, [%o1+0x38]
F0023BBC: d40461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o2
F0023BC0: d04aa038                 ldsb    [%o2+0x38], %o0
F0023BC4: 80a22000                 cmp     %o0, 0
F0023BC8: 12800025                 bne     locret_F0023C5C
F0023BCC: a41461dc                 or      %l1, %lo(dword_F0133DDC), %l2
F0023BD0: d207bff4                 ld      [%fp+var_C], %o1
F0023BD4: d0126004                 lduh    [%o1+4], %o0
F0023BD8: 808a2001                 btst    1, %o0
F0023BDC: 32800007                 bne,a   loc_F0023BF8
F0023BE0: e0026024                 ld      [%o1+0x24], %l0
F0023BE4: 90102016                 mov     0x16, %o0
F0023BE8: d02aa038                 stb     %o0, [%o2+0x38]
F0023BEC: 400013de                 call    _vn_rele
F0023BF0: d007bff4                 ld      [%fp+var_C], %o0
F0023BF4: 3080001a                 ba,a    locret_F0023C5C
F0023BF8: 400013db                 call    _vn_rele
F0023BFC: 90100009                 mov     %o1, %o0
F0023C00: d004bffc                 ld      [%l2-4], %o0
F0023C04: d002201c                 ld      [%o0+0x1C], %o0
F0023C08: d2522002                 ldsh    [%o0+2], %o1
F0023C0C: d0542124                 ldsh    [%l0+0x124], %o0
F0023C10: 80a24008                 cmp     %o1, %o0
F0023C14: 02800009                 be      loc_F0023C38
F0023C18: 01000000                 nop
F0023C1C: 7fffaf54                 call    _suser
F0023C20: 01000000                 nop
F0023C24: 80a22000                 cmp     %o0, 0
F0023C28: 12800004                 bne     loc_F0023C38
F0023C2C: d20461dc                 ld      [%l1+0x1DC], %o1
F0023C30: 1080000a                 ba      loc_F0023C58
F0023C34: 90102001                 mov     1, %o0
F0023C38: 400123c3                 call    _mfs_cache_clear
F0023C3C: 01000000                 nop
F0023C40: 40018e5c                 call    _vm_object_cache_clear
F0023C44: 01000000                 nop
F0023C48: 40000007                 call    _dounmount
F0023C4C: 90100010                 mov     %l0, %o0
F0023C50: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F0023C54: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F0023C58: d02a6038                 stb     %o0, [%o1+0x38]
F0023C5C: 81c7e008                 ret
F0023C60: 81e80000                 restore
