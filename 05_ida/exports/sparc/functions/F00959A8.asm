F00959A8: 033c0464                 sethi   %hi(_vac), %g1
F00959AC: c2006334                 ld      [%g1+%lo(_vac)], %g1
F00959B0: 80904000                 tst     %g1
F00959B4: 02bfff81                 be      _vac_noop
F00959B8: 01000000                 nop
F00959BC: 033c04d082106060         set     _flush_cnt, %g1
F00959C4: da00600c                 ld      [%g1+0xC], %o5
F00959C8: 9a036001                 inc     %o5
F00959CC: da20600c                 st      %o5, [%g1+0xC]
F00959D0: 033c045c                 sethi   %hi(_v_vac_flush), %g1
F00959D4: c2006324                 ld      [%g1+%lo(_v_vac_flush)], %g1
F00959D8: 81c04000                 jmp     %g1
F00959DC: 01000000                 nop
