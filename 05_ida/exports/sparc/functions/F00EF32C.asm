F00EF32C: 80a22000                 cmp     %o0, 0
F00EF330: 0280001f                 be      loc_F00EF3AC
F00EF334: 80a26000                 cmp     %o1, 0
F00EF338: 2280001e                 be,a    locret_F00EF3B0
F00EF33C: 90102000                 mov     0, %o0
F00EF340: c4022010                 ld      [%o0+0x10], %g2
F00EF344: 8088a002                 btst    2, %g2
F00EF348: 22800002                 be,a    loc_F00EF350
F00EF34C: d0020000                 ld      [%o0], %o0
F00EF350: 96100008                 mov     %o0, %o3
F00EF354: d402e01c                 ld      [%o3+0x1C], %o2
F00EF358: 80a2a000                 cmp     %o2, 0
F00EF35C: 22800011                 be,a    loc_F00EF3A0
F00EF360: d602e004                 ld      [%o3+4], %o3
F00EF364: c602a004                 ld      [%o2+4], %g3
F00EF368: 8680ffff                 inccc   -1, %g3
F00EF36C: 0c800008                 bneg    loc_F00EF38C
F00EF370: 9002a008                 add     %o2, 8, %o0
F00EF374: c4020000                 ld      [%o0], %g2
F00EF378: 80a24002                 cmp     %o1, %g2
F00EF37C: 0280000d                 be      locret_F00EF3B0
F00EF380: 8680ffff                 inccc   -1, %g3
F00EF384: 1cbffffc                 bpos    loc_F00EF374
F00EF388: 9002200c                 inc     0xC, %o0
F00EF38C: d4028000                 ld      [%o2], %o2
F00EF390: 80a2a000                 cmp     %o2, 0
F00EF394: 32bffff5                 bne,a   loc_F00EF368
F00EF398: c602a004                 ld      [%o2+4], %g3
F00EF39C: d602e004                 ld      [%o3+4], %o3
F00EF3A0: 80a2e000                 cmp     %o3, 0
F00EF3A4: 32bfffed                 bne,a   loc_F00EF358
F00EF3A8: d402e01c                 ld      [%o3+0x1C], %o2
F00EF3AC: 90102000                 mov     0, %o0
F00EF3B0: 81c3e008                 retl
F00EF3B4: 01000000                 nop
