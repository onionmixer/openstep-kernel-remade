F0058E34: 9de3bf98                 save    %sp, -0x68, %sp
F0058E38: 052000008410a012         set     -0x7FFFFFEE, %g2
F0058E40: c4260000                 st      %g2, [%i0]
F0058E44: 84102020                 mov     0x20, %g2 ! ' '
F0058E48: c4262004                 st      %g2, [%i0+4]
F0058E4C: 84102001                 mov     1, %g2
F0058E50: c4262010                 st      %g2, [%i0+0x10]
F0058E54: c026200c                 clr     [%i0+0xC]
F0058E58: c0262008                 clr     [%i0+8]
F0058E5C: 84102045                 mov     0x45, %g2 ! 'E'
F0058E60: c4262014                 st      %g2, [%i0+0x14]
F0058E64: 84102010                 mov     0x10, %g2
F0058E68: c42e2018                 stb     %g2, [%i0+0x18]
F0058E6C: 84102020                 mov     0x20, %g2 ! ' '
F0058E70: c42e2019                 stb     %g2, [%i0+0x19]
F0058E74: c026201c                 clr     [%i0+0x1C]
F0058E78: c4062018                 ld      [%i0+0x18], %g2
F0058E7C: 073fffc08610e00f         set     -0xFFF1, %g3
F0058E84: 84088003                 and     %g2, %g3, %g2
F0058E88: 8410a018                 bset    0x18, %g2
F0058E8C: 8408bff8                 and     %g2, -8, %g2
F0058E90: c4262018                 st      %g2, [%i0+0x18]
F0058E94: 81c7e008                 ret
F0058E98: 81e80000                 restore
