F0095964: 033c0464                 sethi   %hi(_vac), %g1
F0095968: c2006334                 ld      [%g1+%lo(_vac)], %g1
F009596C: 80904000                 tst     %g1
F0095970: 02bfff92                 be      _vac_noop
F0095974: 01000000                 nop
F0095978: 033c04d082106060         set     _flush_cnt, %g1
F0095980: da006008                 ld      [%g1+8], %o5
F0095984: 9a036001                 inc     %o5
F0095988: da206008                 st      %o5, [%g1+8]
F009598C: 94100009                 mov     %o1, %o2
F0095990: 9132200c                 srl     %o0, 12, %o0
F0095994: 912a200c                 sll     %o0, 12, %o0
F0095998: 033c045c                 sethi   %hi(_v_vac_pagectxflush), %g1
F009599C: c2006320                 ld      [%g1+%lo(_v_vac_pagectxflush)], %g1
F00959A0: 81c04000                 jmp     %g1
F00959A4: 01000000                 nop
