F0046098: 9de3bf98                 save    %sp, -0x68, %sp
F004609C: f4062014                 ld      [%i0+0x14], %i2
F00460A0: 80a68019                 cmp     %i2, %i1
F00460A4: 0680000c                 bl      loc_F00460D4
F00460A8: 86102000                 mov     0, %g3
F00460AC: c406200c                 ld      [%i0+0xC], %g2
F00460B0: 8088a003                 btst    3, %g2
F00460B4: 22800004                 be,a    loc_F00460C4
F00460B8: c606200c                 ld      [%i0+0xC], %g3
F00460BC: 10800007                 ba      locret_F00460D8
F00460C0: b0102000                 mov     0, %i0
F00460C4: 84268019                 sub     %i2, %i1, %g2
F00460C8: c4262014                 st      %g2, [%i0+0x14]
F00460CC: 8400c019                 add     %g3, %i1, %g2
F00460D0: c426200c                 st      %g2, [%i0+0xC]
F00460D4: b0100003                 mov     %g3, %i0
F00460D8: 81c7e008                 ret
F00460DC: 81e80000                 restore
