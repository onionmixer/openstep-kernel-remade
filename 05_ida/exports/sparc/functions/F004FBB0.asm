F004FBB0: 9de3bf98                 save    %sp, -0x68, %sp
F004FBB4: f027a044                 st      %i0, [%fp+arg_44]
F004FBB8: 80a62000                 cmp     %i0, 0
F004FBBC: 0280000c                 be      loc_F004FBEC
F004FBC0: b407a044                 add     %fp, arg_44, %i2
F004FBC4: c6068000                 ld      [%i2], %g3
F004FBC8: 80a0c019                 cmp     %g3, %i1
F004FBCC: 12800005                 bne     loc_F004FBE0
F004FBD0: c400e018                 ld      [%g3+0x18], %g2
F004FBD4: b0102001                 mov     1, %i0
F004FBD8: 10800006                 ba      locret_F004FBF0
F004FBDC: c4268000                 st      %g2, [%i2]
F004FBE0: 80a0a000                 cmp     %g2, 0
F004FBE4: 12bffff8                 bne     loc_F004FBC4
F004FBE8: b400e018                 add     %g3, 0x18, %i2
F004FBEC: b0102000                 mov     0, %i0
F004FBF0: 81c7e008                 ret
F004FBF4: 81e80000                 restore
