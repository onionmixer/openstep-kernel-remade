F00EFD8C: c6022004                 ld      [%o0+4], %g3
F00EFD90: 8680ffff                 inccc   -1, %g3
F00EFD94: 0c80000a                 bneg    loc_F00EFDBC
F00EFD98: 94022008                 add     %o0, 8, %o2
F00EFD9C: c4028000                 ld      [%o2], %g2
F00EFDA0: 80a24002                 cmp     %o1, %g2
F00EFDA4: 12800004                 bne     loc_F00EFDB4
F00EFDA8: 8680ffff                 inccc   -1, %g3
F00EFDAC: 10800005                 ba      locret_F00EFDC0
F00EFDB0: d002a008                 ld      [%o2+8], %o0
F00EFDB4: 1cbffffa                 bpos    loc_F00EFD9C
F00EFDB8: 9402a00c                 inc     0xC, %o2
F00EFDBC: 90102000                 mov     0, %o0
F00EFDC0: 81c3e008                 retl
F00EFDC4: 01000000                 nop
