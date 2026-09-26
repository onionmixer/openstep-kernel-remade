F008AB54: 9de3bf90                 save    %sp, -0x70, %sp
F008AB58: 113c04d0                 sethi   %hi(_page_mask), %o0
F008AB5C: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F008AB60: 90064009                 add     %i1, %o1, %o0
F008AB64: 96380009                 xnor    %g0, %o1, %o3
F008AB68: 940a000b                 and     %o0, %o3, %o2
F008AB6C: 80a28019                 cmp     %o2, %i1
F008AB70: 12800007                 bne     loc_F008AB8C
F008AB74: 9810001a                 mov     %i2, %o4
F008AB78: 9006c009                 add     %i3, %o1, %o0
F008AB7C: 960a000b                 and     %o0, %o3, %o3
F008AB80: 80a2c01b                 cmp     %o3, %i3
F008AB84: 02800004                 be      loc_F008AB94
F008AB88: 90102001                 mov     1, %o0
F008AB8C: 10800009                 ba      locret_F008ABB0
F008AB90: b0102004                 mov     4, %i0
F008AB94: d023a05c                 st      %o0, [%sp+0x70+var_14]
F008AB98: 113c04ef                 sethi   %hi(_ipc_soft_map), %o0
F008AB9C: d2022320                 ld      [%o0+%lo(_ipc_soft_map)], %o1
F008ABA0: 9a102000                 mov     0, %o5
F008ABA4: 7fffeaa3                 call    _vm_map_copy
F008ABA8: 90100018                 mov     %i0, %o0
F008ABAC: b0100008                 mov     %o0, %i0
F008ABB0: 81c7e008                 ret
F008ABB4: 81e80000                 restore
