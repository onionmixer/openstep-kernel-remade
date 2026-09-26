F0058E9C: 9de3bf98                 save    %sp, -0x68, %sp
F0058EA0: 84102012                 mov     0x12, %g2
F0058EA4: c4260000                 st      %g2, [%i0]
F0058EA8: 84102020                 mov     0x20, %g2 ! ' '
F0058EAC: c4262004                 st      %g2, [%i0+4]
F0058EB0: 84102001                 mov     1, %g2
F0058EB4: c4262010                 st      %g2, [%i0+0x10]
F0058EB8: c026200c                 clr     [%i0+0xC]
F0058EBC: c0262008                 clr     [%i0+8]
F0058EC0: 84102046                 mov     0x46, %g2 ! 'F'
F0058EC4: c4262014                 st      %g2, [%i0+0x14]
F0058EC8: 84102002                 mov     2, %g2
F0058ECC: c42e2018                 stb     %g2, [%i0+0x18]
F0058ED0: 84102020                 mov     0x20, %g2 ! ' '
F0058ED4: c42e2019                 stb     %g2, [%i0+0x19]
F0058ED8: c026201c                 clr     [%i0+0x1C]
F0058EDC: c4062018                 ld      [%i0+0x18], %g2
F0058EE0: 073fffc08610e00f         set     -0xFFF1, %g3
F0058EE8: 84088003                 and     %g2, %g3, %g2
F0058EEC: 8410a018                 bset    0x18, %g2
F0058EF0: 8408bff8                 and     %g2, -8, %g2
F0058EF4: c4262018                 st      %g2, [%i0+0x18]
F0058EF8: 81c7e008                 ret
F0058EFC: 81e80000                 restore
