F002E754: 9de3bf98                 save    %sp, -0x68, %sp
F002E758: f2060000                 ld      [%i0], %i1
F002E75C: 07200000                 sethi   0x80000000, %g3
F002E760: 808e4003                 btst    %g3, %i1
F002E764: 12800005                 bne     loc_F002E778
F002E768: 31300000                 sethi   -0x40000000, %i0
F002E76C: 053fc000                 sethi   -0x1000000, %g2
F002E770: 10800017                 ba      loc_F002E7CC
F002E774: b00e4002                 and     %i1, %g2, %i0
F002E778: 840e4018                 and     %i1, %i0, %g2
F002E77C: 80a08003                 cmp     %g2, %g3
F002E780: 12800005                 bne     loc_F002E794
F002E784: 07380000                 sethi   -0x20000000, %g3
F002E788: 053fffc0                 sethi   -0x10000, %g2
F002E78C: 10800010                 ba      loc_F002E7CC
F002E790: b00e4002                 and     %i1, %g2, %i0
F002E794: 840e4003                 and     %i1, %g3, %g2
F002E798: 80a08018                 cmp     %g2, %i0
F002E79C: 12800004                 bne     loc_F002E7AC
F002E7A0: 053c0000                 sethi   -0x10000000, %g2
F002E7A4: 1080000a                 ba      loc_F002E7CC
F002E7A8: b00e7f00                 and     %i1, -0x100, %i0
F002E7AC: b00e4002                 and     %i1, %g2, %i0
F002E7B0: 80a60003                 cmp     %i0, %g3
F002E7B4: 02800007                 be      loc_F002E7D0
F002E7B8: 053c04d9                 sethi   -0xFEC9C00, %g2
F002E7BC: 10800011                 ba      locret_F002E800
F002E7C0: b0102000                 mov     0, %i0
F002E7C4: 1080000f                 ba      locret_F002E800
F002E7C8: b00e4018                 and     %i1, %i0, %i0
F002E7CC: 053c04d9                 sethi   -0xFEC9C00, %g2
F002E7D0: c600a070                 ld      [%g2+0x70], %g3
F002E7D4: 80a0e000                 cmp     %g3, 0
F002E7D8: 0280000a                 be      locret_F002E800
F002E7DC: 01000000                 nop
F002E7E0: c400e028                 ld      [%g3+0x28], %g2
F002E7E4: 80a60002                 cmp     %i0, %g2
F002E7E8: 22bffff7                 be,a    loc_F002E7C4
F002E7EC: f000e034                 ld      [%g3+0x34], %i0
F002E7F0: c600e040                 ld      [%g3+0x40], %g3
F002E7F4: 80a0e000                 cmp     %g3, 0
F002E7F8: 32bffffb                 bne,a   loc_F002E7E4
F002E7FC: c400e028                 ld      [%g3+0x28], %g2
F002E800: 81c7e008                 ret
F002E804: 81e80000                 restore
