F00AAF0C: 9de3bf90                 save    %sp, -0x70, %sp
F00AAF10: c027bff4                 clr     [%fp+var_C]
F00AAF14: 113c04d0                 sethi   %hi(_page_mask), %o0
F00AAF18: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F00AAF1C: a0067fff                 add     %i1, -1, %l0
F00AAF20: 808e4010                 btst    %l0, %i1
F00AAF24: b0060008                 add     %i0, %o0, %i0
F00AAF28: 12800026                 bne     loc_F00AAFC0
F00AAF2C: b02e0008                 bclr    %o0, %i0
F00AAF30: 253c04d1                 sethi   %hi(_kernel_map), %l2
F00AAF34: d004a340                 ld      [%l2+%lo(_kernel_map)], %o0
F00AAF38: 92102000                 mov     0, %o1
F00AAF3C: 94102000                 mov     0, %o2
F00AAF40: a207bff4                 add     %fp, var_C, %l1
F00AAF44: 96100011                 mov     %l1, %o3
F00AAF48: 98100018                 mov     %i0, %o4
F00AAF4C: 7fff65a1                 call    _vm_map_find
F00AAF50: 9a102001                 mov     1, %o5
F00AAF54: 80a22000                 cmp     %o0, 0
F00AAF58: 32800035                 bne,a   locret_F00AB02C
F00AAF5C: b0102000                 mov     0, %i0
F00AAF60: 80a66000                 cmp     %i1, 0
F00AAF64: 02800019                 be      loc_F00AAFC8
F00AAF68: d207bff4                 ld      [%fp+var_C], %o1
F00AAF6C: 808a4010                 btst    %l0, %o1
F00AAF70: 22800017                 be,a    loc_F00AAFCC
F00AAF74: 253c04f4                 sethi   -0xFEC3000, %l2
F00AAF78: d004a340                 ld      [%l2+%lo(_kernel_map)], %o0
F00AAF7C: 7fff68f1                 call    _vm_map_remove
F00AAF80: 94024018                 add     %o1, %i0, %o2
F00AAF84: 92102000                 mov     0, %o1
F00AAF88: 94102000                 mov     0, %o2
F00AAF8C: 96100011                 mov     %l1, %o3
F00AAF90: 98100018                 mov     %i0, %o4
F00AAF94: c407bff4                 ld      [%fp+var_C], %g2
F00AAF98: 9a102000                 mov     0, %o5
F00AAF9C: d004a340                 ld      [%l2+0x340], %o0
F00AAFA0: 8400bfff                 inc     -1, %g2
F00AAFA4: 84008019                 add     %g2, %i1, %g2
F00AAFA8: 84288010                 bclr    %l0, %g2
F00AAFAC: 7fff6589                 call    _vm_map_find
F00AAFB0: c427bff4                 st      %g2, [%fp+var_C]
F00AAFB4: 80a22000                 cmp     %o0, 0
F00AAFB8: 02800005                 be      loc_F00AAFCC
F00AAFBC: 253c04f4                 sethi   -0xFEC3000, %l2
F00AAFC0: 1080001b                 ba      locret_F00AB02C
F00AAFC4: b0102000                 mov     0, %i0
F00AAFC8: 253c04f4                 sethi   -0xFEC3000, %l2
F00AAFCC: e207bff4                 ld      [%fp+var_C], %l1
F00AAFD0: 13040000                 sethi   0x10000000, %o1
F00AAFD4: d004a340                 ld      [%l2+0x340], %o0
F00AAFD8: 7fff6e25                 call    _vm_object_reference
F00AAFDC: a2044009                 add     %l1, %o1, %l1
F00AAFE0: 213c04d1                 sethi   %hi(_kernel_map), %l0
F00AAFE4: 7ffef778                 call    _lock_write
F00AAFE8: d0042340                 ld      [%l0+%lo(_kernel_map)], %o0
F00AAFEC: d0042340                 ld      [%l0+%lo(_kernel_map)], %o0
F00AAFF0: d202204c                 ld      [%o0+0x4C], %o1
F00AAFF4: 92026001                 inc     %o1
F00AAFF8: d222204c                 st      %o1, [%o0+0x4C]
F00AAFFC: d207bff4                 ld      [%fp+var_C], %o1
F00AB000: 7fff6871                 call    _vm_map_delete
F00AB004: 94024018                 add     %o1, %i0, %o2
F00AB008: d0042340                 ld      [%l0+%lo(_kernel_map)], %o0
F00AB00C: d607bff4                 ld      [%fp+var_C], %o3
F00AB010: 94100011                 mov     %l1, %o2
F00AB014: d204a340                 ld      [%l2+0x340], %o1
F00AB018: 7fff64a1                 call    _vm_map_insert
F00AB01C: 9802c018                 add     %o3, %i0, %o4
F00AB020: 7ffef805                 call    _lock_done
F00AB024: d0042340                 ld      [%l0+0x340], %o0
F00AB028: f007bff4                 ld      [%fp+var_C], %i0
F00AB02C: 81c7e008                 ret
F00AB030: 81e80000                 restore
