F001CDBC: 9de3bf98                 save    %sp, -0x68, %sp
F001CDC0: 86100018                 mov     %i0, %g3
F001CDC4: c400c000                 ld      [%g3], %g2
F001CDC8: 80a0a000                 cmp     %g2, 0
F001CDCC: 0280000c                 be      loc_F001CDFC
F001CDD0: b0100019                 mov     %i1, %i0
F001CDD4: c400e008                 ld      [%g3+8], %g2
F001CDD8: b0062001                 inc     %i0
F001CDDC: 80a60002                 cmp     %i0, %g2
F001CDE0: 02800007                 be      loc_F001CDFC
F001CDE4: 808e203f                 btst    0x3F, %i0 ! '?'
F001CDE8: 12800006                 bne     locret_F001CE00
F001CDEC: 01000000                 nop
F001CDF0: f0063fc0                 ld      [%i0-0x40], %i0
F001CDF4: 10800003                 ba      locret_F001CE00
F001CDF8: b006200c                 inc     0xC, %i0
F001CDFC: b0102000                 mov     0, %i0
F001CE00: 81c7e008                 ret
F001CE04: 81e80000                 restore
