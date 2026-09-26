F000E408: 9de3bf98                 save    %sp, -0x68, %sp
F000E40C: b4100018                 mov     %i0, %i2
F000E410: b0102000                 mov     0, %i0
F000E414: 8610001a                 mov     %i2, %g3
F000E418: 053ff37fb610a3ff         set     -0x320001, %i3
F000E420: c400e018                 ld      [%g3+0x18], %g2
F000E424: b0062001                 inc     %i0
F000E428: f200e048                 ld      [%g3+0x48], %i1
F000E42C: 8408801b                 and     %g2, %i3, %g2
F000E430: 80a66000                 cmp     %i1, 0
F000E434: 02800004                 be      loc_F000E444
F000E438: c420e018                 st      %g2, [%g3+0x18]
F000E43C: 10bffff9                 ba      loc_F000E420
F000E440: 86100019                 mov     %i1, %g3
F000E444: 80a0c01a                 cmp     %g3, %i2
F000E448: 02800008                 be      locret_F000E468
F000E44C: 01000000                 nop
F000E450: c400e04c                 ld      [%g3+0x4C], %g2
F000E454: 80a0a000                 cmp     %g2, 0
F000E458: 22bffffb                 be,a    loc_F000E444
F000E45C: c600e044                 ld      [%g3+0x44], %g3
F000E460: 10bffff0                 ba      loc_F000E420
F000E464: 86100002                 mov     %g2, %g3
F000E468: 81c7e008                 ret
F000E46C: 81e80000                 restore
