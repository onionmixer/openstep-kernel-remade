F00C0EF4: 9de3bf98                 save    %sp, -0x68, %sp
F00C0EF8: 86102000                 mov     0, %g3
F00C0EFC: f2060000                 ld      [%i0], %i1
F00C0F00: 053c04fdb010a280         set     _kbddata, %i0
F00C0F08: c406201c                 ld      [%i0+0x1C], %g2
F00C0F0C: 80a08019                 cmp     %g2, %i1
F00C0F10: 02800007                 be      locret_F00C0F2C
F00C0F14: 8600e001                 inc     %g3
F00C0F18: 80a0e003                 cmp     %g3, 3
F00C0F1C: 04bffffb                 ble     loc_F00C0F08
F00C0F20: b006202c                 inc     0x2C, %i0 ! ','
F00C0F24: 313c04fdb0162280         set     _kbddata, %i0
F00C0F2C: 81c7e008                 ret
F00C0F30: 81e80000                 restore
