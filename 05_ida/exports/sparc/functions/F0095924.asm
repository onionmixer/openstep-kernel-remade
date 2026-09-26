F0095924: 033c0464                 sethi   %hi(_vac), %g1
F0095928: c2006334                 ld      [%g1+%lo(_vac)], %g1
F009592C: 80904000                 tst     %g1
F0095930: 02bfffa2                 be      _vac_noop
F0095934: 01000000                 nop
F0095938: 033c04d082106060         set     _flush_cnt, %g1
F0095940: da006008                 ld      [%g1+8], %o5
F0095944: 9a036001                 inc     %o5
F0095948: da206008                 st      %o5, [%g1+8]
F009594C: 9132200c                 srl     %o0, 12, %o0
F0095950: 912a200c                 sll     %o0, 12, %o0
F0095954: 033c045c                 sethi   %hi(_v_vac_pageflush), %g1
F0095958: c200631c                 ld      [%g1+%lo(_v_vac_pageflush)], %g1
F009595C: 81c04000                 jmp     %g1
F0095960: 01000000                 nop
