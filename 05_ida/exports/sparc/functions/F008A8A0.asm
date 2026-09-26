F008A8A0: 9de3bf98                 save    %sp, -0x68, %sp
F008A8A4: 80a62000                 cmp     %i0, 0
F008A8A8: 12800004                 bne     loc_F008A8B8
F008A8AC: 80a6a000                 cmp     %i2, 0
F008A8B0: 1080000f                 ba      locret_F008A8EC
F008A8B4: b0102004                 mov     4, %i0
F008A8B8: 0280000c                 be      loc_F008A8E8
F008A8BC: 113c04d0                 sethi   %hi(_page_mask), %o0
F008A8C0: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F008A8C4: 9406401a                 add     %i1, %i2, %o2
F008A8C8: 90100018                 mov     %i0, %o0
F008A8CC: 96380009                 xnor    %g0, %o1, %o3
F008A8D0: 94028009                 add     %o2, %o1, %o2
F008A8D4: 920e400b                 and     %i1, %o3, %o1
F008A8D8: 7fffea9a                 call    _vm_map_remove
F008A8DC: 940a800b                 and     %o2, %o3, %o2
F008A8E0: 10800003                 ba      locret_F008A8EC
F008A8E4: b0100008                 mov     %o0, %i0
F008A8E8: b0102000                 mov     0, %i0
F008A8EC: 81c7e008                 ret
F008A8F0: 81e80000                 restore
