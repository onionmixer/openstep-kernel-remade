F00958E8: 033c0464                 sethi   %hi(_vac), %g1
F00958EC: c2006334                 ld      [%g1+%lo(_vac)], %g1
F00958F0: 80904000                 tst     %g1
F00958F4: 02bfffb1                 be      _vac_noop
F00958F8: 01000000                 nop
F00958FC: 1b3c04d09a136060         set     _flush_cnt, %o5
F0095904: c2036004                 ld      [%o5+4], %g1
F0095908: 82006001                 inc     %g1
F009590C: c2236004                 st      %g1, [%o5+4]
F0095910: 94100009                 mov     %o1, %o2
F0095914: 033c045c                 sethi   %hi(_v_vac_segflush), %g1
F0095918: c2006318                 ld      [%g1+%lo(_v_vac_segflush)], %g1
F009591C: 81c04000                 jmp     %g1
F0095920: 01000000                 nop
