F0058D6C: 9de3bf98                 save    %sp, -0x68, %sp
F0058D70: 84102012                 mov     0x12, %g2
F0058D74: c4260000                 st      %g2, [%i0]
F0058D78: 84102020                 mov     0x20, %g2 ! ' '
F0058D7C: c4262004                 st      %g2, [%i0+4]
F0058D80: 84102001                 mov     1, %g2
F0058D84: c4262010                 st      %g2, [%i0+0x10]
F0058D88: c026200c                 clr     [%i0+0xC]
F0058D8C: c0262008                 clr     [%i0+8]
F0058D90: 84102041                 mov     0x41, %g2 ! 'A'
F0058D94: c4262014                 st      %g2, [%i0+0x14]
F0058D98: 8410200f                 mov     0xF, %g2
F0058D9C: c42e2018                 stb     %g2, [%i0+0x18]
F0058DA0: 84102020                 mov     0x20, %g2 ! ' '
F0058DA4: c42e2019                 stb     %g2, [%i0+0x19]
F0058DA8: c026201c                 clr     [%i0+0x1C]
F0058DAC: c4062018                 ld      [%i0+0x18], %g2
F0058DB0: 073fffc08610e00f         set     -0xFFF1, %g3
F0058DB8: 84088003                 and     %g2, %g3, %g2
F0058DBC: 8410a018                 bset    0x18, %g2
F0058DC0: 8408bff8                 and     %g2, -8, %g2
F0058DC4: c4262018                 st      %g2, [%i0+0x18]
F0058DC8: 81c7e008                 ret
F0058DCC: 81e80000                 restore
