F00959F0: 033c0464                 sethi   %hi(_vac), %g1
F00959F4: c2006334                 ld      [%g1+%lo(_vac)], %g1
F00959F8: 80904000                 tst     %g1
F00959FC: 02bfff71                 be      _vac_inoop
F0095A00: 01000000                 nop
F0095A04: 1b3c045c                 sethi   %hi(_v_vac_parity_chk_dis), %o5
F0095A08: da036330                 ld      [%o5+%lo(_v_vac_parity_chk_dis)], %o5
F0095A0C: 81c34000                 jmp     %o5
F0095A10: 01000000                 nop
