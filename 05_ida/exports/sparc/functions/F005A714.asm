F005A714: 9de3bf98                 save    %sp, -0x68, %sp
F005A718: c606202c                 ld      [%i0+0x2C], %g3
F005A71C: b32ea003                 sll     %i2, 3, %i1
F005A720: f000c019                 ld      [%g3+%i1], %i0
F005A724: 8400c019                 add     %g3, %i1, %g2
F005A728: c020a004                 clr     [%g2+4]
F005A72C: c400c000                 ld      [%g3], %g2
F005A730: c420c019                 st      %g2, [%g3+%i1]
F005A734: f420c000                 st      %i2, [%g3]
F005A738: 81c7e008                 ret
F005A73C: 81e80000                 restore
