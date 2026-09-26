F0068828: 9de3bf98                 save    %sp, -0x68, %sp
F006882C: 053c04d0                 sethi   %hi(_page_mask), %g2
F0068830: c600a0d8                 ld      [%g2+%lo(_page_mask)], %g3
F0068834: b2102000                 mov     0, %i1
F0068838: 053c04bd                 sethi   %hi(dword_F012F67C), %g2
F006883C: f400a27c                 ld      [%g2+%lo(dword_F012F67C)], %i2
F0068840: 80a6401a                 cmp     %i1, %i2
F0068844: 1680000e                 bge     loc_F006887C
F0068848: 862e0003                 andn    %i0, %g3, %g3
F006884C: 053c04bd                 sethi   %hi(dword_F012F678), %g2
F0068850: f600a278                 ld      [%g2+%lo(dword_F012F678)], %i3
F0068854: b010001a                 mov     %i2, %i0
F0068858: c400e008                 ld      [%g3+8], %g2
F006885C: 80a0a002                 cmp     %g2, 2
F0068860: 12800004                 bne     loc_F0068870
F0068864: b2066001                 inc     %i1
F0068868: 10800006                 ba      locret_F0068880
F006886C: b0102000                 mov     0, %i0
F0068870: 80a64018                 cmp     %i1, %i0
F0068874: 06bffff9                 bl      loc_F0068858
F0068878: 8600c01b                 add     %g3, %i3, %g3
F006887C: b0102001                 mov     1, %i0
F0068880: 81c7e008                 ret
F0068884: 81e80000                 restore
