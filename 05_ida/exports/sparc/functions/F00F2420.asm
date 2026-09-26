F00F2420: 86102000                 mov     0, %g3
F00F2424: 053c04bc                 sethi   %hi(dword_F012F128), %g2
F00F2428: c400a128                 ld      [%g2+%lo(dword_F012F128)], %g2
F00F242C: 80a0c002                 cmp     %g3, %g2
F00F2430: 1a800010                 bcc     loc_F00F2470
F00F2434: 053c04bc                 sethi   %hi(dword_F012F124), %g2
F00F2438: d400a124                 ld      [%g2+%lo(dword_F012F124)], %o2
F00F243C: 053c04bc                 sethi   %hi(dword_F012F128), %g2
F00F2440: d200a128                 ld      [%g2+%lo(dword_F012F128)], %o1
F00F2444: 8528e001                 sll     %g3, 1, %g2
F00F2448: 84008003                 add     %g2, %g3, %g2
F00F244C: 8528a003                 sll     %g2, 3, %g2
F00F2450: d0028002                 ld      [%o2+%g2], %o0
F00F2454: c402200c                 ld      [%o0+0xC], %g2
F00F2458: 80a0a003                 cmp     %g2, 3
F00F245C: 12800006                 bne     locret_F00F2474
F00F2460: 8600e001                 inc     %g3
F00F2464: 80a0c009                 cmp     %g3, %o1
F00F2468: 0abffff8                 bcs     loc_F00F2448
F00F246C: 8528e001                 sll     %g3, 1, %g2
F00F2470: 90102000                 mov     0, %o0
F00F2474: 81c3e008                 retl
F00F2478: 01000000                 nop
