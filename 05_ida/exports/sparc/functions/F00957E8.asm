F00957E8: 033c0464                 sethi   %hi(_vac), %g1
F00957EC: c2006334                 ld      [%g1+%lo(_vac)], %g1
F00957F0: 80904000                 tst     %g1
F00957F4: 02bffff1                 be      _vac_noop
F00957F8: 01000000                 nop
F00957FC: 033c045c                 sethi   %hi(_v_vac_flushall), %g1
F0095800: c2006308                 ld      [%g1+%lo(_v_vac_flushall)], %g1
F0095804: 81c04000                 jmp     %g1
F0095808: 01000000                 nop
