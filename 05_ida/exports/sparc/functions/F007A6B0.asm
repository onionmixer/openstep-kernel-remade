F007A6B0: 9de3bf98                 save    %sp, -0x68, %sp
F007A6B4: 113c0442                 sethi   %hi(_kernel_task), %o0
F007A6B8: d4022250                 ld      [%o0+%lo(_kernel_task)], %o2
F007A6BC: 113c04d0                 sethi   %hi(_page_mask), %o0
F007A6C0: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F007A6C4: d002a00c                 ld      [%o2+0xC], %o0
F007A6C8: 96380009                 xnor    %g0, %o1, %o3
F007A6CC: 9406401a                 add     %i1, %i2, %o2
F007A6D0: 94028009                 add     %o2, %o1, %o2
F007A6D4: 920e400b                 and     %i1, %o3, %o1
F007A6D8: 940a800b                 and     %o2, %o3, %o2
F007A6DC: 400029c4                 call    _vm_map_pageable
F007A6E0: 96102001                 mov     1, %o3
F007A6E4: 81c7e008                 ret
F007A6E8: 91e80008                 restore %g0, %o0, %o0
