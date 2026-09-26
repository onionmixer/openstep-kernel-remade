F0004F4C: 0b3c04288a116024         set     _active_pcb, %g5
F0004F54: ca014000                 ld      [%g5], %g5
F0004F58: c201600c                 ld      [%g5+0xC], %g1
F0004F5C: 80904000                 tst     %g1
F0004F60: 0280001a                 be      loc_F0004FC8
F0004F64: 01000000                 nop
F0004F68: 89480000                 rdhpr   %hpstate, %g4
F0004F6C: 82112f00                 or      %g4, 0xF00, %g1
F0004F70: 81884000                 saved
F0004F74: 01000000                 nop
F0004F78: 01000000                 nop
F0004F7C: 01000000                 nop
F0004F80: c201600c                 ld      [%g5+0xC], %g1
F0004F84: c021600c                 clr     [%g5+0xC]
F0004F88: 0b3c000c                 sethi   %hi(_nwindows), %g5
F0004F8C: ca01603c                 ld      [%g5+%lo(_nwindows)], %g5
F0004F90: 10800007                 ba      loc_F0004FAC
F0004F94: 8a216001                 dec     %g5
F0004F98: 8730a001                 srl     %g2, 1, %g3
F0004F9C: 85288005                 sll     %g2, %g5, %g2
F0004FA0: 84108003                 bset    %g3, %g2
F0004FA4: 81908000                 wrpr    %g2, %g0, %tpc
F0004FA8: 82284002                 bclr    %g2, %g1
F0004FAC: 80904000                 tst     %g1
F0004FB0: 32bffffa                 bne,a   loc_F0004F98
F0004FB4: 85500000                 rdpr    %tpc, %g2
F0004FB8: 81890000                 saved
F0004FBC: 01000000                 nop
F0004FC0: 01000000                 nop
F0004FC4: 01000000                 nop
F0004FC8: 0b3c04288a116024         set     _active_pcb, %g5
F0004FD0: ca014000                 ld      [%g5], %g5
F0004FD4: 81c3e008                 retl
F0004FD8: c0216230                 clr     [%g5+0x230]
