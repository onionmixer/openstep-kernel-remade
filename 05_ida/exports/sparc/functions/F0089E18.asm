F0089E18: 9de3bf98                 save    %sp, -0x68, %sp
F0089E1C: 113c04d0                 sethi   %hi(_active_threads), %o0
F0089E20: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0089E24: d402200c                 ld      [%o0+0xC], %o2
F0089E28: 113c04d0                 sethi   %hi(_page_mask), %o0
F0089E2C: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F0089E30: d002a00c                 ld      [%o2+0xC], %o0
F0089E34: 96380009                 xnor    %g0, %o1, %o3
F0089E38: 94060019                 add     %i0, %i1, %o2
F0089E3C: 94028009                 add     %o2, %o1, %o2
F0089E40: 920e000b                 and     %i0, %o3, %o1
F0089E44: 940a800b                 and     %o2, %o3, %o2
F0089E48: 7fffebe9                 call    _vm_map_pageable
F0089E4C: 96102000                 mov     0, %o3
F0089E50: 81c7e008                 ret
F0089E54: 81e80000                 restore
