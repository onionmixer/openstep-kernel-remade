F009580C: 033c0464                 sethi   %hi(_vac), %g1
F0095810: c2006334                 ld      [%g1+%lo(_vac)], %g1
F0095814: 80904000                 tst     %g1
F0095818: 02bfffe8                 be      _vac_noop
F009581C: 01000000                 nop
F0095820: 1b3c04d09a136060         set     _flush_cnt, %o5
F0095828: c2036010                 ld      [%o5+0x10], %g1
F009582C: 82006001                 inc     %g1
F0095830: c2236010                 st      %g1, [%o5+0x10]
F0095834: 033c045c                 sethi   %hi(_v_vac_usrflush), %g1
F0095838: c200630c                 ld      [%g1+%lo(_v_vac_usrflush)], %g1
F009583C: 81c04000                 jmp     %g1
F0095840: 01000000                 nop
