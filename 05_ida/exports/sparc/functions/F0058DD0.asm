F0058DD0: 9de3bf98                 save    %sp, -0x68, %sp
F0058DD4: 84102012                 mov     0x12, %g2
F0058DD8: c4260000                 st      %g2, [%i0]
F0058DDC: 84102020                 mov     0x20, %g2 ! ' '
F0058DE0: c4262004                 st      %g2, [%i0+4]
F0058DE4: 84102001                 mov     1, %g2
F0058DE8: c4262010                 st      %g2, [%i0+0x10]
F0058DEC: c026200c                 clr     [%i0+0xC]
F0058DF0: c0262008                 clr     [%i0+8]
F0058DF4: 84102042                 mov     0x42, %g2 ! 'B'
F0058DF8: c4262014                 st      %g2, [%i0+0x14]
F0058DFC: 8410200f                 mov     0xF, %g2
F0058E00: c42e2018                 stb     %g2, [%i0+0x18]
F0058E04: 84102020                 mov     0x20, %g2 ! ' '
F0058E08: c42e2019                 stb     %g2, [%i0+0x19]
F0058E0C: c026201c                 clr     [%i0+0x1C]
F0058E10: c4062018                 ld      [%i0+0x18], %g2
F0058E14: 073fffc08610e00f         set     -0xFFF1, %g3
F0058E1C: 84088003                 and     %g2, %g3, %g2
F0058E20: 8410a018                 bset    0x18, %g2
F0058E24: 8408bff8                 and     %g2, -8, %g2
F0058E28: c4262018                 st      %g2, [%i0+0x18]
F0058E2C: 81c7e008                 ret
F0058E30: 81e80000                 restore
