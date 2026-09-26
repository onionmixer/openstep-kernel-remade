F00958A4: 033c0464                 sethi   %hi(_vac), %g1
F00958A8: c2006334                 ld      [%g1+%lo(_vac)], %g1
F00958AC: 80904000                 tst     %g1
F00958B0: 02bfffc2                 be      _vac_noop
F00958B4: 01000000                 nop
F00958B8: 1b3c04d09a136060         set     _flush_cnt, %o5
F00958C0: c2036014                 ld      [%o5+0x14], %g1
F00958C4: 82006001                 inc     %g1
F00958C8: c2236014                 st      %g1, [%o5+0x14]
F00958CC: 91322018                 srl     %o0, 24, %o0
F00958D0: 912a2018                 sll     %o0, 24, %o0
F00958D4: 94100009                 mov     %o1, %o2
F00958D8: 033c045c                 sethi   %hi(_v_vac_rgnflush), %g1
F00958DC: c2006314                 ld      [%g1+%lo(_v_vac_rgnflush)], %g1
F00958E0: 81c04000                 jmp     %g1
F00958E4: 01000000                 nop
