F0083884: 9de3bf98                 save    %sp, -0x68, %sp
F0083888: 113c04d0                 sethi   %hi(_page_mask), %o0
F008388C: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F0083890: 9406401a                 add     %i1, %i2, %o2
F0083894: 90100018                 mov     %i0, %o0
F0083898: 96380009                 xnor    %g0, %o1, %o3
F008389C: 94028009                 add     %o2, %o1, %o2
F00838A0: 920e400b                 and     %i1, %o3, %o1
F00838A4: 400006a7                 call    _vm_map_remove
F00838A8: 940a800b                 and     %o2, %o3, %o2
F00838AC: 81c7e008                 ret
F00838B0: 81e80000                 restore
