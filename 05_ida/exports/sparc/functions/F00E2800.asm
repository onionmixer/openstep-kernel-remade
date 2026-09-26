F00E2800: 9de3bf98                 save    %sp, -0x68, %sp
F00E2804: b12e2010                 sll     %i0, 16, %i0
F00E2808: b13e2012                 sra     %i0, 18, %i0
F00E280C: 050000078410a3ff         set     0x1FFF, %g2
F00E2814: 80a60002                 cmp     %i0, %g2
F00E2818: 04800007                 ble     loc_F00E2834
F00E281C: 053c04bb                 sethi   %hi(dword_F012EF60), %g2
F00E2820: 0700000f                 sethi   0x3C00, %g3
F00E2824: c400a360                 ld      [%g2+%lo(dword_F012EF60)], %g2
F00E2828: 8610e3ff                 bset    0x3FF, %g3
F00E282C: 1080000d                 ba      locret_F00E2860
F00E2830: f0088003                 ldub    [%g2+%g3], %i0
F00E2834: 053ffff8                 sethi   -0x2000, %g2
F00E2838: 80a60002                 cmp     %i0, %g2
F00E283C: 06800007                 bl      loc_F00E2858
F00E2840: 053c04bb                 sethi   %hi(dword_F012EF60), %g2
F00E2844: c400a360                 ld      [%g2+%lo(dword_F012EF60)], %g2
F00E2848: 07000008                 sethi   0x2000, %g3
F00E284C: 84060002                 add     %i0, %g2, %g2
F00E2850: 10800004                 ba      locret_F00E2860
F00E2854: f0088003                 ldub    [%g2+%g3], %i0
F00E2858: c400a360                 ld      [%g2+0x360], %g2
F00E285C: f0088000                 ldub    [%g2], %i0
F00E2860: 81c7e008                 ret
F00E2864: 81e80000                 restore
