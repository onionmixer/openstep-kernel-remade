F008CE00: 9de3bf90                 save    %sp, -0x70, %sp
F008CE04: 94100018                 mov     %i0, %o2
F008CE08: d002a00c                 ld      [%o2+0xC], %o0
F008CE0C: 90023fff                 inc     -1, %o0
F008CE10: 80a22000                 cmp     %o0, 0
F008CE14: 14800008                 bg      loc_F008CE34
F008CE18: d022a00c                 st      %o0, [%o2+0xC]
F008CE1C: d002a004                 ld      [%o2+4], %o0! id
F008CE20: 133c0504                 sethi   %hi(paDestroyitem), %o1! SEL
F008CE24: 40019293                 call    _objc_msgSend
F008CE28: d202604c                 ld      [%o1+%lo(paDestroyitem)], %o1
F008CE2C: 10800003                 ba      locret_F008CE38
F008CE30: b0100008                 mov     %o0, %i0
F008CE34: b0102000                 mov     0, %i0
F008CE38: 81c7e008                 ret
F008CE3C: 81e80000                 restore
