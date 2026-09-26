F002E6BC: 9de3bf90                 save    %sp, -0x70, %sp
F002E6C0: b8100018                 mov     %i0, %i4
F002E6C4: 07200000                 sethi   0x80000000, %g3
F002E6C8: 808f0003                 btst    %g3, %i4
F002E6CC: 12800005                 bne     loc_F002E6E0
F002E6D0: 05300000                 sethi   -0x40000000, %g2
F002E6D4: 05003fff                 sethi   0xFFFC00, %g2
F002E6D8: 1080000b                 ba      loc_F002E704
F002E6DC: b610a3ff                 or      %g2, 0x3FF, %i3
F002E6E0: 840f0002                 and     %i4, %g2, %g2
F002E6E4: 80a08003                 cmp     %g2, %g3
F002E6E8: 12800007                 bne     loc_F002E704
F002E6EC: b61020ff                 mov     0xFF, %i3
F002E6F0: 0500003f                 sethi   0xFC00, %g2
F002E6F4: 10800004                 ba      loc_F002E704
F002E6F8: b610a3ff                 or      %g2, 0x3FF, %i3
F002E6FC: 10800011                 ba      loc_F002E740
F002E700: b6380002                 xnor    %g0, %g2, %i3
F002E704: 053c04d9                 sethi   %hi(_in_ifaddr), %g2
F002E708: f400a070                 ld      [%g2+%lo(_in_ifaddr)], %i2
F002E70C: 80a6a000                 cmp     %i2, 0
F002E710: 0280000d                 be      loc_F002E744
F002E714: b00e401b                 and     %i1, %i3, %i0
F002E718: c406a02c                 ld      [%i2+0x2C], %g2
F002E71C: c606a028                 ld      [%i2+0x28], %g3
F002E720: 8408801c                 and     %g2, %i4, %g2
F002E724: 80a08003                 cmp     %g2, %g3
F002E728: 22bffff5                 be,a    loc_F002E6FC
F002E72C: c406a034                 ld      [%i2+0x34], %g2
F002E730: f406a040                 ld      [%i2+0x40], %i2
F002E734: 80a6a000                 cmp     %i2, 0
F002E738: 32bffff9                 bne,a   loc_F002E71C
F002E73C: c406a02c                 ld      [%i2+0x2C], %g2
F002E740: b00e401b                 and     %i1, %i3, %i0
F002E744: b0170018                 bset    %i4, %i0
F002E748: f027bff4                 st      %i0, [%fp+var_C]
F002E74C: 81c7e008                 ret
F002E750: 81e80000                 restore
