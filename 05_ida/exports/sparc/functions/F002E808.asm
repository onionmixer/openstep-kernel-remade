F002E808: 9de3bf98                 save    %sp, -0x68, %sp
F002E80C: f0060000                 ld      [%i0], %i0
F002E810: 07200000                 sethi   0x80000000, %g3
F002E814: 808e0003                 btst    %g3, %i0
F002E818: 12800006                 bne     loc_F002E830
F002E81C: b6100018                 mov     %i0, %i3
F002E820: 053fc000                 sethi   -0x1000000, %g2
F002E824: b40e0002                 and     %i0, %g2, %i2
F002E828: 1080001d                 ba      loc_F002E89C
F002E82C: b22e0002                 andn    %i0, %g2, %i1
F002E830: 33300000                 sethi   -0x40000000, %i1
F002E834: 840e0019                 and     %i0, %i1, %g2
F002E838: 80a08003                 cmp     %g2, %g3
F002E83C: 12800008                 bne     loc_F002E85C
F002E840: 07380000                 sethi   -0x20000000, %g3
F002E844: 053fffc0                 sethi   -0x10000, %g2
F002E848: b40e0002                 and     %i0, %g2, %i2
F002E84C: 0500003f8410a3ff         set     0xFFFF, %g2
F002E854: 10800012                 ba      loc_F002E89C
F002E858: b20e0002                 and     %i0, %g2, %i1
F002E85C: 840e0003                 and     %i0, %g3, %g2
F002E860: 80a08019                 cmp     %g2, %i1
F002E864: 12800005                 bne     loc_F002E878
F002E868: 053c0000                 sethi   -0x10000000, %g2
F002E86C: b40e3f00                 and     %i0, -0x100, %i2
F002E870: 1080000b                 ba      loc_F002E89C
F002E874: b20e20ff                 and     %i0, 0xFF, %i1
F002E878: 840e0002                 and     %i0, %g2, %g2
F002E87C: 80a08003                 cmp     %g2, %g3
F002E880: 02800005                 be      loc_F002E894
F002E884: b4100002                 mov     %g2, %i2
F002E888: 30800013                 ba,a    locret_F002E8D4
F002E88C: 10800012                 ba      locret_F002E8D4
F002E890: b02e4018                 andn    %i1, %i0, %i0
F002E894: 053c0000                 sethi   -0x10000000, %g2
F002E898: b22ec002                 andn    %i3, %g2, %i1
F002E89C: 053c04d9                 sethi   %hi(_in_ifaddr), %g2
F002E8A0: c600a070                 ld      [%g2+%lo(_in_ifaddr)], %g3
F002E8A4: 80a0e000                 cmp     %g3, 0
F002E8A8: 0280000b                 be      locret_F002E8D4
F002E8AC: b0100019                 mov     %i1, %i0
F002E8B0: c400e028                 ld      [%g3+0x28], %g2
F002E8B4: 80a68002                 cmp     %i2, %g2
F002E8B8: 22bffff5                 be,a    loc_F002E88C
F002E8BC: f000e034                 ld      [%g3+0x34], %i0
F002E8C0: c600e040                 ld      [%g3+0x40], %g3
F002E8C4: 80a0e000                 cmp     %g3, 0
F002E8C8: 32bffffb                 bne,a   loc_F002E8B4
F002E8CC: c400e028                 ld      [%g3+0x28], %g2
F002E8D0: b0100019                 mov     %i1, %i0
F002E8D4: 81c7e008                 ret
F002E8D8: 81e80000                 restore
