F00863D0: 9de3bf98                 save    %sp, -0x68, %sp
F00863D4: b2100018                 mov     %i0, %i1
F00863D8: 313c04f3                 sethi   %hi(_mem_region), %i0
F00863DC: 053c04f4                 sethi   %hi(_num_regions), %g2
F00863E0: c600a330                 ld      [%g2+%lo(_num_regions)], %g3
F00863E4: b0162030                 bset    %lo(_mem_region), %i0
F00863E8: 8528e003                 sll     %g3, 3, %g2
F00863EC: 84208003                 sub     %g2, %g3, %g2
F00863F0: 8528a002                 sll     %g2, 2, %g2
F00863F4: 84008018                 add     %g2, %i0, %g2
F00863F8: 80a60002                 cmp     %i0, %g2
F00863FC: 3a800012                 bcc,a   locret_F0086444
F0086400: b0102000                 mov     0, %i0
F0086404: b4100002                 mov     %g2, %i2
F0086408: 86062018                 add     %i0, 0x18, %g3
F008640C: c400fffc                 ld      [%g3-4], %g2
F0086410: 80a64002                 cmp     %i1, %g2
F0086414: 0a800008                 bcs     loc_F0086434
F0086418: b006201c                 inc     0x1C, %i0
F008641C: c400c000                 ld      [%g3], %g2
F0086420: 80a64002                 cmp     %i1, %g2
F0086424: 1a800005                 bcc     loc_F0086438
F0086428: 80a6001a                 cmp     %i0, %i2
F008642C: 10800006                 ba      locret_F0086444
F0086430: b0102001                 mov     1, %i0
F0086434: 80a6001a                 cmp     %i0, %i2
F0086438: 0abffff5                 bcs     loc_F008640C
F008643C: 8600e01c                 inc     0x1C, %g3
F0086440: b0102000                 mov     0, %i0
F0086444: 81c7e008                 ret
F0086448: 81e80000                 restore
