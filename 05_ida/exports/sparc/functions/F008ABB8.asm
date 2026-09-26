F008ABB8: 9de3bf90                 save    %sp, -0x70, %sp
F008ABBC: 113c04d0                 sethi   %hi(_page_mask), %o0
F008ABC0: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F008ABC4: 90064009                 add     %i1, %o1, %o0
F008ABC8: 96380009                 xnor    %g0, %o1, %o3
F008ABCC: 980a000b                 and     %o0, %o3, %o4
F008ABD0: 80a30019                 cmp     %o4, %i1
F008ABD4: 32800013                 bne,a   locret_F008AC20
F008ABD8: b0102004                 mov     4, %i0
F008ABDC: 9006c009                 add     %i3, %o1, %o0
F008ABE0: 940a000b                 and     %o0, %o3, %o2
F008ABE4: 80a2801b                 cmp     %o2, %i3
F008ABE8: 3280000e                 bne,a   locret_F008AC20
F008ABEC: b0102004                 mov     4, %i0
F008ABF0: 90068009                 add     %i2, %o1, %o0
F008ABF4: 960a000b                 and     %o0, %o3, %o3
F008ABF8: 80a2c01a                 cmp     %o3, %i2
F008ABFC: 22800004                 be,a    loc_F008AC0C
F008AC00: c023a05c                 clr     [%sp+0x70+var_14]
F008AC04: 10800007                 ba      locret_F008AC20
F008AC08: b0102004                 mov     4, %i0
F008AC0C: 90100018                 mov     %i0, %o0
F008AC10: 92100008                 mov     %o0, %o1
F008AC14: 7fffea87                 call    _vm_map_copy
F008AC18: 9a102000                 mov     0, %o5
F008AC1C: b0100008                 mov     %o0, %i0
F008AC20: 81c7e008                 ret
F008AC24: 81e80000                 restore
