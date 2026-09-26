F0012F8C: 9de3bf90                 save    %sp, -0x70, %sp
F0012F90: 053c043f                 sethi   %hi(_mtime), %g2
F0012F94: c600a000                 ld      [%g2+%lo(_mtime)], %g3
F0012F98: f200c000                 ld      [%g3], %i1
F0012F9C: f227bff0                 st      %i1, [%fp+var_10]
F0012FA0: c400e004                 ld      [%g3+4], %g2
F0012FA4: c427bff4                 st      %g2, [%fp+var_C]
F0012FA8: c400e008                 ld      [%g3+8], %g2
F0012FAC: 80a64002                 cmp     %i1, %g2
F0012FB0: 12bffffa                 bne     loc_F0012F98
F0012FB4: 01000000                 nop
F0012FB8: f2260000                 st      %i1, [%i0]
F0012FBC: c407bff4                 ld      [%fp+var_C], %g2
F0012FC0: c4262004                 st      %g2, [%i0+4]
F0012FC4: 81c7e008                 ret
F0012FC8: 81e80000                 restore
