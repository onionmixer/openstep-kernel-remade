F008644C: 9de3bf98                 save    %sp, -0x68, %sp
F0086450: b4100018                 mov     %i0, %i2
F0086454: 313c04f3                 sethi   %hi(_mem_region), %i0
F0086458: 053c04f4                 sethi   %hi(_num_regions), %g2
F008645C: c600a330                 ld      [%g2+%lo(_num_regions)], %g3
F0086460: b2162030                 or      %i0, %lo(_mem_region), %i1
F0086464: 8528e003                 sll     %g3, 3, %g2
F0086468: 84208003                 sub     %g2, %g3, %g2
F008646C: 8528a002                 sll     %g2, 2, %g2
F0086470: 84008019                 add     %g2, %i1, %g2
F0086474: 80a64002                 cmp     %i1, %g2
F0086478: 1a80001b                 bcc     locret_F00864E4
F008647C: b0102000                 mov     0, %i0
F0086480: b6100002                 mov     %g2, %i3
F0086484: 053c04f4                 sethi   %hi(_page_shift), %g2
F0086488: c400a348                 ld      [%g2+%lo(_page_shift)], %g2
F008648C: 86066004                 add     %i1, 4, %g3
F0086490: b1368002                 srl     %i2, %g2, %i0
F0086494: c400e010                 ld      [%g3+0x10], %g2
F0086498: 80a68002                 cmp     %i2, %g2
F008649C: 2a80000e                 bcs,a   loc_F00864D4
F00864A0: b206601c                 inc     0x1C, %i1
F00864A4: c400e014                 ld      [%g3+0x14], %g2
F00864A8: 80a68002                 cmp     %i2, %g2
F00864AC: 3a80000a                 bcc,a   loc_F00864D4
F00864B0: b206601c                 inc     0x1C, %i1
F00864B4: c400c000                 ld      [%g3], %g2
F00864B8: 84260002                 sub     %i0, %g2, %g2
F00864BC: b128a001                 sll     %g2, 1, %i0
F00864C0: b0060002                 add     %i0, %g2, %i0
F00864C4: c4064000                 ld      [%i1], %g2
F00864C8: b12e2004                 sll     %i0, 4, %i0
F00864CC: 10800006                 ba      locret_F00864E4
F00864D0: b0008018                 add     %g2, %i0, %i0
F00864D4: 80a6401b                 cmp     %i1, %i3
F00864D8: 0abfffef                 bcs     loc_F0086494
F00864DC: 8600e01c                 inc     0x1C, %g3
F00864E0: b0102000                 mov     0, %i0
F00864E4: 81c7e008                 ret
F00864E8: 81e80000                 restore
