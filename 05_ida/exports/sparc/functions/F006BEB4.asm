F006BEB4: 9de3bf98                 save    %sp, -0x68, %sp
F006BEB8: 80a66000                 cmp     %i1, 0
F006BEBC: 06800018                 bl      locret_F006BF1C
F006BEC0: b0102004                 mov     4, %i0
F006BEC4: 14800016                 bg      locret_F006BF1C
F006BEC8: 073c04d1                 sethi   %hi(_machine_slot), %g3
F006BECC: 8610e360                 bset    %lo(_machine_slot), %g3
F006BED0: 852e6005                 sll     %i1, 5, %g2
F006BED4: f0008003                 ld      [%g2+%g3], %i0
F006BED8: f0268000                 st      %i0, [%i2]
F006BEDC: 84008003                 add     %g2, %g3, %g2
F006BEE0: c600a004                 ld      [%g2+4], %g3
F006BEE4: c626a004                 st      %g3, [%i2+4]
F006BEE8: c600a008                 ld      [%g2+8], %g3
F006BEEC: c626a008                 st      %g3, [%i2+8]
F006BEF0: c600a00c                 ld      [%g2+0xC], %g3
F006BEF4: c626a00c                 st      %g3, [%i2+0xC]
F006BEF8: c600a010                 ld      [%g2+0x10], %g3
F006BEFC: c626a010                 st      %g3, [%i2+0x10]
F006BF00: c600a014                 ld      [%g2+0x14], %g3
F006BF04: c626a014                 st      %g3, [%i2+0x14]
F006BF08: c600a018                 ld      [%g2+0x18], %g3
F006BF0C: c626a018                 st      %g3, [%i2+0x18]
F006BF10: c400a01c                 ld      [%g2+0x1C], %g2
F006BF14: b0102000                 mov     0, %i0
F006BF18: c426a01c                 st      %g2, [%i2+0x1C]
F006BF1C: 81c7e008                 ret
F006BF20: 81e80000                 restore
