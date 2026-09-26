F001D420: 9de3bf98                 save    %sp, -0x68, %sp
F001D424: 80a62000                 cmp     %i0, 0
F001D428: 0280000f                 be      loc_F001D464
F001D42C: b6102000                 mov     0, %i3
F001D430: 053c04d4                 sethi   %hi(_domains), %g2
F001D434: c600a2b8                 ld      [%g2+%lo(_domains)], %g3
F001D438: 80a0e000                 cmp     %g3, 0
F001D43C: 2280002a                 be,a    locret_F001D4E4
F001D440: b0102000                 mov     0, %i0
F001D444: c400c000                 ld      [%g3], %g2
F001D448: 80a08018                 cmp     %g2, %i0
F001D44C: 22800008                 be,a    loc_F001D46C
F001D450: f000e014                 ld      [%g3+0x14], %i0
F001D454: c600e01c                 ld      [%g3+0x1C], %g3
F001D458: 80a0e000                 cmp     %g3, 0
F001D45C: 32bffffb                 bne,a   loc_F001D448
F001D460: c400c000                 ld      [%g3], %g2
F001D464: 10800020                 ba      locret_F001D4E4
F001D468: b0102000                 mov     0, %i0
F001D46C: c400e018                 ld      [%g3+0x18], %g2
F001D470: 80a60002                 cmp     %i0, %g2
F001D474: 3a80001c                 bcc,a   locret_F001D4E4
F001D478: b010001b                 mov     %i3, %i0
F001D47C: b8100002                 mov     %g2, %i4
F001D480: c6562008                 ldsh    [%i0+8], %g3
F001D484: 80a0c019                 cmp     %g3, %i1
F001D488: 12800006                 bne     loc_F001D4A0
F001D48C: 80a6a003                 cmp     %i2, 3
F001D490: c4560000                 ldsh    [%i0], %g2
F001D494: 80a0801a                 cmp     %g2, %i2
F001D498: 02800013                 be      locret_F001D4E4
F001D49C: 80a6a003                 cmp     %i2, 3
F001D4A0: 3280000d                 bne,a   loc_F001D4D4
F001D4A4: b0062030                 inc     0x30, %i0 ! '0'
F001D4A8: c4560000                 ldsh    [%i0], %g2
F001D4AC: 80a0a003                 cmp     %g2, 3
F001D4B0: 32800009                 bne,a   loc_F001D4D4
F001D4B4: b0062030                 inc     0x30, %i0 ! '0'
F001D4B8: 80a0e000                 cmp     %g3, 0
F001D4BC: 32800006                 bne,a   loc_F001D4D4
F001D4C0: b0062030                 inc     0x30, %i0 ! '0'
F001D4C4: 80a6e000                 cmp     %i3, 0
F001D4C8: 22800002                 be,a    loc_F001D4D0
F001D4CC: b6100018                 mov     %i0, %i3
F001D4D0: b0062030                 inc     0x30, %i0 ! '0'
F001D4D4: 80a6001c                 cmp     %i0, %i4
F001D4D8: 2abfffeb                 bcs,a   loc_F001D484
F001D4DC: c6562008                 ldsh    [%i0+8], %g3
F001D4E0: b010001b                 mov     %i3, %i0
F001D4E4: 81c7e008                 ret
F001D4E8: 81e80000                 restore
