F006FD74: 9de3bf98                 save    %sp, -0x68, %sp
F006FD78: c4064000                 ld      [%i1], %g2
F006FD7C: 80a0a00b                 cmp     %g2, 0xB
F006FD80: 08800014                 bleu    loc_F006FDD0
F006FD84: b6100018                 mov     %i0, %i3
F006FD88: c406c000                 ld      [%i3], %g2
F006FD8C: 07004000                 sethi   0x1000000, %g3
F006FD90: 84108003                 bset    %g3, %g2
F006FD94: c426c000                 st      %g2, [%i3]
F006FD98: 84102008                 mov     8, %g2
F006FD9C: c436e002                 sth     %g2, [%i3+2]
F006FDA0: 053c04f18610a000         set     _kdp, %g3
F006FDA8: c410a000                 lduh    [%g2], %g2
F006FDAC: b0102001                 mov     1, %i0
F006FDB0: c020e010                 clr     [%g3+0x10]
F006FDB4: c4368000                 sth     %g2, [%i2]
F006FDB8: 0500003f                 sethi   0xFC00, %g2
F006FDBC: c606c000                 ld      [%i3], %g3
F006FDC0: 8410a3ff                 bset    0x3FF, %g2
F006FDC4: 8608c002                 and     %g3, %g2, %g3
F006FDC8: 10800003                 ba      locret_F006FDD4
F006FDCC: c6264000                 st      %g3, [%i1]
F006FDD0: b0102000                 mov     0, %i0
F006FDD4: 81c7e008                 ret
F006FDD8: 81e80000                 restore
