F006FF64: 9de3bf98                 save    %sp, -0x68, %sp
F006FF68: c4064000                 ld      [%i1], %g2
F006FF6C: 80a0a007                 cmp     %g2, 7
F006FF70: 08800022                 bleu    loc_F006FFF8
F006FF74: b6100018                 mov     %i0, %i3
F006FF78: c026e008                 clr     [%i3+8]
F006FF7C: 053c0000                 sethi   -0x10000000, %g2
F006FF80: c426e00c                 st      %g2, [%i3+0xC]
F006FF84: 0503c000                 sethi   0xF000000, %g2
F006FF88: c426e010                 st      %g2, [%i3+0x10]
F006FF8C: 84102007                 mov     7, %g2
F006FF90: c426e014                 st      %g2, [%i3+0x14]
F006FF94: c406c000                 ld      [%i3], %g2
F006FF98: 07004000                 sethi   0x1000000, %g3
F006FF9C: 84108003                 bset    %g3, %g2
F006FFA0: c426c000                 st      %g2, [%i3]
F006FFA4: 8410200c                 mov     0xC, %g2
F006FFA8: c606e008                 ld      [%i3+8], %g3
F006FFAC: c436e002                 sth     %g2, [%i3+2]
F006FFB0: 8600e001                 inc     %g3
F006FFB4: c626e008                 st      %g3, [%i3+8]
F006FFB8: 8528e001                 sll     %g3, 1, %g2
F006FFBC: 84008003                 add     %g2, %g3, %g2
F006FFC0: c616e002                 lduh    [%i3+2], %g3
F006FFC4: 8528a002                 sll     %g2, 2, %g2
F006FFC8: 8600c002                 add     %g3, %g2, %g3
F006FFCC: c636e002                 sth     %g3, [%i3+2]
F006FFD0: 053c04f1                 sethi   %hi(_kdp), %g2
F006FFD4: c410a000                 lduh    [%g2+%lo(_kdp)], %g2
F006FFD8: b0102001                 mov     1, %i0
F006FFDC: c4368000                 sth     %g2, [%i2]
F006FFE0: 0500003f                 sethi   0xFC00, %g2
F006FFE4: c606c000                 ld      [%i3], %g3
F006FFE8: 8410a3ff                 bset    0x3FF, %g2
F006FFEC: 8608c002                 and     %g3, %g2, %g3
F006FFF0: 10800003                 ba      locret_F006FFFC
F006FFF4: c6264000                 st      %g3, [%i1]
F006FFF8: b0102000                 mov     0, %i0
F006FFFC: 81c7e008                 ret
F0070000: 81e80000                 restore
