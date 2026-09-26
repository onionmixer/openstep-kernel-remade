F006FEFC: 9de3bf98                 save    %sp, -0x68, %sp
F006FF00: c4064000                 ld      [%i1], %g2
F006FF04: 80a0a007                 cmp     %g2, 7
F006FF08: 08800014                 bleu    loc_F006FF58
F006FF0C: b6100018                 mov     %i0, %i3
F006FF10: 84102400                 mov     0x400, %g2
F006FF14: c426e008                 st      %g2, [%i3+8]
F006FF18: c406c000                 ld      [%i3], %g2
F006FF1C: 07004000                 sethi   0x1000000, %g3
F006FF20: 84108003                 bset    %g3, %g2
F006FF24: c426c000                 st      %g2, [%i3]
F006FF28: 8410200c                 mov     0xC, %g2
F006FF2C: c436e002                 sth     %g2, [%i3+2]
F006FF30: 053c04f1                 sethi   %hi(_kdp), %g2
F006FF34: c410a000                 lduh    [%g2+%lo(_kdp)], %g2
F006FF38: b0102001                 mov     1, %i0
F006FF3C: c4368000                 sth     %g2, [%i2]
F006FF40: 0500003f                 sethi   0xFC00, %g2
F006FF44: c606c000                 ld      [%i3], %g3
F006FF48: 8410a3ff                 bset    0x3FF, %g2
F006FF4C: 8608c002                 and     %g3, %g2, %g3
F006FF50: 10800003                 ba      locret_F006FF5C
F006FF54: c6264000                 st      %g3, [%i1]
F006FF58: b0102000                 mov     0, %i0
F006FF5C: 81c7e008                 ret
F006FF60: 81e80000                 restore
