F008D420: 9de3bf90                 save    %sp, -0x70, %sp
F008D424: 94100018                 mov     %i0, %o2
F008D428: d002a01c                 ld      [%o2+0x1C], %o0
F008D42C: 80a22000                 cmp     %o0, 0
F008D430: 1480000e                 bg      locret_F008D468
F008D434: 01000000                 nop
F008D438: d002a014                 ld      [%o2+0x14], %o0
F008D43C: 90023fff                 inc     -1, %o0
F008D440: 80a22000                 cmp     %o0, 0
F008D444: 14800008                 bg      loc_F008D464
F008D448: d022a014                 st      %o0, [%o2+0x14]
F008D44C: d002a008                 ld      [%o2+8], %o0! id
F008D450: 133c0504                 sethi   %hi(paDestroyrange), %o1! SEL
F008D454: 40019107                 call    _objc_msgSend
F008D458: d2026054                 ld      [%o1+%lo(paDestroyrange)], %o1
F008D45C: 10800003                 ba      locret_F008D468
F008D460: b0100008                 mov     %o0, %i0
F008D464: b0102000                 mov     0, %i0
F008D468: 81c7e008                 ret
F008D46C: 81e80000                 restore
