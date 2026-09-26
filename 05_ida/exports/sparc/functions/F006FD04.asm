F006FD04: 9de3bf98                 save    %sp, -0x68, %sp
F006FD08: b8100019                 mov     %i1, %i4
F006FD0C: c4070000                 ld      [%i4], %g2
F006FD10: 80a0a007                 cmp     %g2, 7
F006FD14: 08800015                 bleu    loc_F006FD68
F006FD18: b6100018                 mov     %i0, %i3
F006FD1C: b0102001                 mov     1, %i0
F006FD20: c406c000                 ld      [%i3], %g2
F006FD24: 07004000                 sethi   0x1000000, %g3
F006FD28: 84108003                 bset    %g3, %g2
F006FD2C: c426c000                 st      %g2, [%i3]
F006FD30: 84102008                 mov     8, %g2
F006FD34: c436e002                 sth     %g2, [%i3+2]
F006FD38: 053c04f1b210a000         set     _kdp, %i1
F006FD40: c410a000                 lduh    [%g2], %g2
F006FD44: 86102001                 mov     1, %g3
F006FD48: c6266010                 st      %g3, [%i1+0x10]
F006FD4C: c4368000                 sth     %g2, [%i2]
F006FD50: 0500003f                 sethi   0xFC00, %g2
F006FD54: c606c000                 ld      [%i3], %g3
F006FD58: 8410a3ff                 bset    0x3FF, %g2
F006FD5C: 8608c002                 and     %g3, %g2, %g3
F006FD60: 10800003                 ba      locret_F006FD6C
F006FD64: c6270000                 st      %g3, [%i4]
F006FD68: b0102000                 mov     0, %i0
F006FD6C: 81c7e008                 ret
F006FD70: 81e80000                 restore
