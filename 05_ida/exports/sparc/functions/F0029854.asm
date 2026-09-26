F0029854: 9de3bf98                 save    %sp, -0x68, %sp
F0029858: 053c04308610a150         set     _afswitch, %g3
F0029860: b000e088                 add     %g3, 0x88, %i0
F0029864: 80a0c018                 cmp     %g3, %i0
F0029868: 1a80000b                 bcc     locret_F0029894
F002986C: 053c00a6                 sethi   %hi(_null_hash), %g2
F0029870: b210a09c                 or      %g2, %lo(_null_hash), %i1
F0029874: c400c000                 ld      [%g3], %g2
F0029878: 80a0a000                 cmp     %g2, 0
F002987C: 22800002                 be,a    loc_F0029884
F0029880: f220c000                 st      %i1, [%g3]
F0029884: 8600e008                 inc     8, %g3
F0029888: 80a0c018                 cmp     %g3, %i0
F002988C: 2abffffb                 bcs,a   loc_F0029878
F0029890: c400c000                 ld      [%g3], %g2
F0029894: 81c7e008                 ret
F0029898: 81e80000                 restore
