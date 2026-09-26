F003EB88: 9de3bf98                 save    %sp, -0x68, %sp
F003EB8C: c4062128                 ld      [%i0+0x128], %g2
F003EB90: c600a010                 ld      [%g2+0x10], %g3
F003EB94: c6264000                 st      %g3, [%i1]
F003EB98: c410e006                 lduh    [%g3+6], %g2
F003EB9C: 8400a001                 inc     %g2
F003EBA0: c430e006                 sth     %g2, [%g3+6]
F003EBA4: 81c7e008                 ret
F003EBA8: 91e82000                 restore %g0, 0, %o0
