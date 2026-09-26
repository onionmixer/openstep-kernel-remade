F00966FC: 96100000                 clr     %o3
F0096700: 80a2601f                 cmp     %o1, 0x1F
F0096704: 26800023                 bl,a    loc_F0096790
F0096708: 80924000                 tst     %o1
F009670C: 808a201f                 btst    0x1F, %o0
F0096710: 02800008                 be      loc_F0096730
F0096714: 01000000                 nop
F0096718: c4120000                 lduh    [%o0], %g2
F009671C: 90022002                 inc     2, %o0
F0096720: 9602c002                 add     %o3, %g2, %o3
F0096724: 808a201f                 btst    0x1F, %o0
F0096728: 12bffffc                 bne     loc_F0096718
F009672C: 92226001                 dec     %o1
F0096730: 92226010                 dec     0x10, %o1
F0096734: c41a0000                 ldd     [%o0], %g2
F0096738: d81a2008                 ldd     [%o0+8], %o4
F009673C: 9682c002                 addcc   %o3, %g2, %o3
F0096740: 96c2c003                 addccc  %o3, %g3, %o3
F0096744: c41a2010                 ldd     [%o0+0x10], %g2
F0096748: 96c2c00c                 addccc  %o3, %o4, %o3
F009674C: 96c2c00d                 addccc  %o3, %o5, %o3
F0096750: d81a2018                 ldd     [%o0+0x18], %o4
F0096754: 96c2c002                 addccc  %o3, %g2, %o3
F0096758: 96c2c003                 addccc  %o3, %g3, %o3
F009675C: 96c2c00c                 addccc  %o3, %o4, %o3
F0096760: 96c2c00d                 addccc  %o3, %o5, %o3
F0096764: 96c2e000                 addccc  %o3, 0, %o3
F0096768: 92a26010                 deccc   0x10, %o1
F009676C: 16bffff2                 bge     loc_F0096734
F0096770: 90022020                 inc     0x20, %o0 ! ' '
F0096774: 92026010                 inc     0x10, %o1
F0096778: 10800006                 ba      loc_F0096790
F009677C: 80924000                 tst     %o1
F0096780: 90022002                 inc     2, %o0
F0096784: 9682c002                 addcc   %o3, %g2, %o3
F0096788: 96c2e000                 addccc  %o3, 0, %o3
F009678C: 92a26001                 deccc   %o1
F0096790: 34bffffc                 bg,a    loc_F0096780
F0096794: c4120000                 lduh    [%o0], %g2
F0096798: 992ae010                 sll     %o3, 16, %o4
F009679C: 9683000b                 addcc   %o4, %o3, %o3
F00967A0: 9732e010                 srl     %o3, 16, %o3
F00967A4: 81c3e008                 retl
F00967A8: 90c2e000                 addccc  %o3, 0, %o0
