F007A674: 9de3bf98                 save    %sp, -0x68, %sp
F007A678: 113c0442                 sethi   %hi(_kernel_task), %o0
F007A67C: d4022250                 ld      [%o0+%lo(_kernel_task)], %o2
F007A680: 113c04d0                 sethi   %hi(_page_mask), %o0
F007A684: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F007A688: d002a00c                 ld      [%o2+0xC], %o0
F007A68C: 96380009                 xnor    %g0, %o1, %o3
F007A690: 9406401a                 add     %i1, %i2, %o2
F007A694: 94028009                 add     %o2, %o1, %o2
F007A698: 920e400b                 and     %i1, %o3, %o1
F007A69C: 940a800b                 and     %o2, %o3, %o2
F007A6A0: 400029d3                 call    _vm_map_pageable
F007A6A4: 96102000                 mov     0, %o3
F007A6A8: 81c7e008                 ret
F007A6AC: 91e80008                 restore %g0, %o0, %o0
