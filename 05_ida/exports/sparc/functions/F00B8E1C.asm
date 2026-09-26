F00B8E1C: 9de3bf98                 save    %sp, -0x68, %sp
F00B8E20: b4102000                 mov     0, %i2
F00B8E24: 86100018                 mov     %i0, %g3
F00B8E28: c400e014                 ld      [%g3+0x14], %g2
F00B8E2C: 80a08019                 cmp     %g2, %i1
F00B8E30: 02800013                 be      locret_F00B8E7C
F00B8E34: b406a001                 inc     %i2
F00B8E38: 80a6a007                 cmp     %i2, 7
F00B8E3C: 04bffffb                 ble     loc_F00B8E28
F00B8E40: 8600e004                 inc     4, %g3
F00B8E44: c406200c                 ld      [%i0+0xC], %g2
F00B8E48: c6060000                 ld      [%i0], %g3
F00B8E4C: 8400a001                 inc     %g2
F00B8E50: c426200c                 st      %g2, [%i0+0xC]
F00B8E54: 8600e001                 inc     %g3
F00B8E58: c4062004                 ld      [%i0+4], %g2
F00B8E5C: c6260000                 st      %g3, [%i0]
F00B8E60: 8528a002                 sll     %g2, 2, %g2
F00B8E64: 84008018                 add     %g2, %i0, %g2
F00B8E68: f220a014                 st      %i1, [%g2+0x14]
F00B8E6C: c4062004                 ld      [%i0+4], %g2
F00B8E70: 8400a001                 inc     %g2
F00B8E74: 8408a007                 and     %g2, 7, %g2
F00B8E78: c4262004                 st      %g2, [%i0+4]
F00B8E7C: 81c7e008                 ret
F00B8E80: 81e80000                 restore
