F00EF2B0: 80a22000                 cmp     %o0, 0
F00EF2B4: 0280001b                 be      loc_F00EF320
F00EF2B8: 80a26000                 cmp     %o1, 0
F00EF2BC: 2280001a                 be,a    locret_F00EF324
F00EF2C0: 90102000                 mov     0, %o0
F00EF2C4: 96100008                 mov     %o0, %o3
F00EF2C8: d402e01c                 ld      [%o3+0x1C], %o2
F00EF2CC: 80a2a000                 cmp     %o2, 0
F00EF2D0: 22800011                 be,a    loc_F00EF314
F00EF2D4: d602e004                 ld      [%o3+4], %o3
F00EF2D8: c602a004                 ld      [%o2+4], %g3
F00EF2DC: 8680ffff                 inccc   -1, %g3
F00EF2E0: 0c800008                 bneg    loc_F00EF300
F00EF2E4: 9002a008                 add     %o2, 8, %o0
F00EF2E8: c4020000                 ld      [%o0], %g2
F00EF2EC: 80a24002                 cmp     %o1, %g2
F00EF2F0: 0280000d                 be      locret_F00EF324
F00EF2F4: 8680ffff                 inccc   -1, %g3
F00EF2F8: 1cbffffc                 bpos    loc_F00EF2E8
F00EF2FC: 9002200c                 inc     0xC, %o0
F00EF300: d4028000                 ld      [%o2], %o2
F00EF304: 80a2a000                 cmp     %o2, 0
F00EF308: 32bffff5                 bne,a   loc_F00EF2DC
F00EF30C: c602a004                 ld      [%o2+4], %g3
F00EF310: d602e004                 ld      [%o3+4], %o3
F00EF314: 80a2e000                 cmp     %o3, 0
F00EF318: 32bfffed                 bne,a   loc_F00EF2CC
F00EF31C: d402e01c                 ld      [%o3+0x1C], %o2
F00EF320: 90102000                 mov     0, %o0
F00EF324: 81c3e008                 retl
F00EF328: 01000000                 nop
