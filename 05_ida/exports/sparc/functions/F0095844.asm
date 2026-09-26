F0095844: 033c0464                 sethi   %hi(_vac), %g1
F0095848: c2006334                 ld      [%g1+%lo(_vac)], %g1
F009584C: 80904000                 tst     %g1
F0095850: 02bfffda                 be      _vac_noop
F0095854: 01000000                 nop
F0095858: 133c04f6                 sethi   %hi(_contexts), %o1
F009585C: d20261d8                 ld      [%o1+%lo(_contexts)], %o1
F0095860: 952a2002                 sll     %o0, 2, %o2
F0095864: 9202400a                 add     %o1, %o2, %o1
F0095868: d2024000                 ld      [%o1], %o1
F009586C: 920a6003                 and     %o1, 3, %o1
F0095870: 80a26001                 cmp     %o1, 1
F0095874: 12bfffd1                 bne     _vac_noop
F0095878: 01000000                 nop
F009587C: 1b3c04d09a136060         set     _flush_cnt, %o5
F0095884: c2036000                 ld      [%o5], %g1
F0095888: 82006001                 inc     %g1
F009588C: c2236000                 st      %g1, [%o5]
F0095890: 94100008                 mov     %o0, %o2
F0095894: 033c045c                 sethi   %hi(_v_vac_ctxflush), %g1
F0095898: c2006310                 ld      [%g1+%lo(_v_vac_ctxflush)], %g1
F009589C: 81c04000                 jmp     %g1
F00958A0: 01000000                 nop
