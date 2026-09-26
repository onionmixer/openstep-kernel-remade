F0089DC8: 9de3bf98                 save    %sp, -0x68, %sp
F0089DCC: 96102002                 mov     2, %o3
F0089DD0: 113c04d0                 sethi   %hi(_page_mask), %o0
F0089DD4: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F0089DD8: 80a6a001                 cmp     %i2, 1
F0089DDC: 113c04d0                 sethi   %hi(_active_threads), %o0
F0089DE0: 94380009                 xnor    %g0, %o1, %o2
F0089DE4: 980e000a                 and     %i0, %o2, %o4
F0089DE8: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0089DEC: b0060019                 add     %i0, %i1, %i0
F0089DF0: d002200c                 ld      [%o0+0xC], %o0
F0089DF4: b0060009                 add     %i0, %o1, %i0
F0089DF8: d002200c                 ld      [%o0+0xC], %o0
F0089DFC: 12800003                 bne     loc_F0089E08
F0089E00: 940e000a                 and     %i0, %o2, %o2
F0089E04: 96102001                 mov     1, %o3
F0089E08: 7fffed69                 call    _vm_map_check_protection
F0089E0C: 9210000c                 mov     %o4, %o1
F0089E10: 81c7e008                 ret
F0089E14: 91e80008                 restore %g0, %o0, %o0
