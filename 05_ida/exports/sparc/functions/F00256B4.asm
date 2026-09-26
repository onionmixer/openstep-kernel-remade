F00256B4: 9de3bf98                 save    %sp, -0x68, %sp
F00256B8: 053c04d58610a1d0         set     _nc_lru, %g3
F00256C0: c620e008                 st      %g3, [%g3+8]
F00256C4: c620e00c                 st      %g3, [%g3+0xC]
F00256C8: 393c043c                 sethi   %hi(_ncsize), %i4
F00256CC: c4072384                 ld      [%i4+%lo(_ncsize)], %g2
F00256D0: b4102000                 mov     0, %i2
F00256D4: 80a68002                 cmp     %i2, %g2
F00256D8: 16800018                 bge     loc_F0025738
F00256DC: 053c04d4                 sethi   -0xFECB000, %g2
F00256E0: 3b3c04d5                 sethi   -0xFECAC00, %i5
F00256E4: b6100003                 mov     %g3, %i3
F00256E8: b2102000                 mov     0, %i1
F00256EC: f00761e0                 ld      [%i5+0x1E0], %i0
F00256F0: b406a001                 inc     %i2
F00256F4: c606e008                 ld      [%i3+8], %g3
F00256F8: 84060019                 add     %i0, %i1, %g2
F00256FC: c426e008                 st      %g2, [%i3+8]
F0025700: c620a008                 st      %g3, [%g2+8]
F0025704: c420e00c                 st      %g2, [%g3+0xC]
F0025708: f620a00c                 st      %i3, [%g2+0xC]
F002570C: c420a004                 st      %g2, [%g2+4]
F0025710: c4260019                 st      %g2, [%i0+%i1]
F0025714: c020a010                 clr     [%g2+0x10]
F0025718: c020a014                 clr     [%g2+0x14]
F002571C: c028a044                 clrb    [%g2+0x44]
F0025720: c4072384                 ld      [%i4+0x384], %g2
F0025724: 80a68002                 cmp     %i2, %g2
F0025728: 06bffff1                 bl      loc_F00256EC
F002572C: b2066048                 inc     0x48, %i1 ! 'H'
F0025730: b4102000                 mov     0, %i2
F0025734: 053c04d4                 sethi   -0xFECB000, %g2
F0025738: 8410a3d0                 bset    0x3D0, %g2
F002573C: c420a004                 st      %g2, [%g2+4]
F0025740: c4208000                 st      %g2, [%g2]
F0025744: b406a001                 inc     %i2
F0025748: 80a6a03f                 cmp     %i2, 0x3F ! '?'
F002574C: 04bffffc                 ble     loc_F002573C
F0025750: 8400a008                 inc     8, %g2
F0025754: 81c7e008                 ret
F0025758: 81e80000                 restore
