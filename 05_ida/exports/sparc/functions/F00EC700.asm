F00EC700: 94920000                 orcc    %o0, %g0, %o2
F00EC704: 02800015                 be      locret_F00EC758
F00EC708: 90102000                 mov     0, %o0
F00EC70C: 86102000                 mov     0, %g3
F00EC710: c4028000                 ld      [%o2], %g2
F00EC714: 80a0c002                 cmp     %g3, %g2
F00EC718: 16800010                 bge     locret_F00EC758
F00EC71C: 01000000                 nop
F00EC720: d6028000                 ld      [%o2], %o3
F00EC724: 9128e003                 sll     %g3, 3, %o0
F00EC728: 84028008                 add     %o2, %o0, %g2
F00EC72C: c400a004                 ld      [%g2+4], %g2
F00EC730: 80a08009                 cmp     %g2, %o1
F00EC734: 12800005                 bne     loc_F00EC748
F00EC738: 8600e001                 inc     %g3
F00EC73C: 90022004                 inc     4, %o0
F00EC740: 10800006                 ba      locret_F00EC758
F00EC744: 90028008                 add     %o2, %o0, %o0
F00EC748: 80a0c00b                 cmp     %g3, %o3
F00EC74C: 06bffff7                 bl      loc_F00EC728
F00EC750: 9128e003                 sll     %g3, 3, %o0
F00EC754: 90102000                 mov     0, %o0
F00EC758: 81c3e008                 retl
F00EC75C: 01000000                 nop
