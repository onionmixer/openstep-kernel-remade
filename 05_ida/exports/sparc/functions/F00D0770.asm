F00D0770: 9de3bf90                 save    %sp, -0x70, %sp
F00D0774: c406211c                 ld      [%i0+0x11C], %g2
F00D0778: 07200000                 sethi   0x80000000, %g3
F00D077C: 84108003                 bset    %g3, %g2
F00D0780: c426211c                 st      %g2, [%i0+0x11C]
F00D0784: 81c7e008                 ret
F00D0788: 91e82000                 restore %g0, 0, %o0
