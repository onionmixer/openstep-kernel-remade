F00A4B74: 9de3bf98                 save    %sp, -0x68, %sp
F00A4B78: 053c04f4                 sethi   %hi(_econtig), %g2
F00A4B7C: c400a390                 ld      [%g2+%lo(_econtig)], %g2
F00A4B80: 86100018                 mov     %i0, %g3
F00A4B84: 80a0c002                 cmp     %g3, %g2
F00A4B88: 1a80000e                 bcc     loc_F00A4BC0
F00A4B8C: 053c04f6                 sethi   %hi(_contexts), %g2
F00A4B90: c400a1d8                 ld      [%g2+%lo(_contexts)], %g2
F00A4B94: 80a0c002                 cmp     %g3, %g2
F00A4B98: 0a80000c                 bcs     loc_F00A4BC8
F00A4B9C: 053c04f8                 sethi   %hi(_kernel_seg_pools), %g2
F00A4BA0: c400a0e8                 ld      [%g2+%lo(_kernel_seg_pools)], %g2
F00A4BA4: 80a0c002                 cmp     %g3, %g2
F00A4BA8: 18800008                 bgu     loc_F00A4BC8
F00A4BAC: 053c045d                 sethi   %hi(_mxcc), %g2
F00A4BB0: c400a2d4                 ld      [%g2+%lo(_mxcc)], %g2
F00A4BB4: 80a0a000                 cmp     %g2, 0
F00A4BB8: 12800005                 bne     loc_F00A4BCC
F00A4BBC: 053bffff                 sethi   -0x10000400, %g2
F00A4BC0: 1080000b                 ba      locret_F00A4BEC
F00A4BC4: b0102000                 mov     0, %i0
F00A4BC8: 053bffff                 sethi   -0x10000400, %g2
F00A4BCC: 8410a3ff                 bset    0x3FF, %g2
F00A4BD0: 80a0c002                 cmp     %g3, %g2
F00A4BD4: 08800006                 bleu    locret_F00A4BEC
F00A4BD8: b0102000                 mov     0, %i0
F00A4BDC: 053c04f4                 sethi   %hi(_econtig), %g2
F00A4BE0: c400a390                 ld      [%g2+%lo(_econtig)], %g2
F00A4BE4: 80a08003                 cmp     %g2, %g3
F00A4BE8: b0603fff                 subc    %g0, -1, %i0
F00A4BEC: 81c7e008                 ret
F00A4BF0: 81e80000                 restore
