F0004EFC: 0b3c04288a116024         set     _active_pcb, %g5
F0004F04: ca014000                 ld      [%g5], %g5
F0004F08: c201600c                 ld      [%g5+0xC], %g1
F0004F0C: 80904000                 tst     %g1
F0004F10: 0280000d                 be      locret_F0004F44
F0004F14: 84100000                 clr     %g2
F0004F18: 9de3bfc0                 save    %sp, -0x40, %sp
F0004F1C: 0b3c04288a116024         set     _active_pcb, %g5
F0004F24: ca014000                 ld      [%g5], %g5
F0004F28: c201600c                 ld      [%g5+0xC], %g1
F0004F2C: 80904000                 tst     %g1
F0004F30: 12bffffa                 bne     loc_F0004F18
F0004F34: 8400a001                 inc     %g2
F0004F38: 84a0a001                 deccc   %g2
F0004F3C: 12bfffff                 bne     loc_F0004F38
F0004F40: 81e80000                 restore
F0004F44: 81c3e008                 retl
F0004F48: 01000000                 nop
