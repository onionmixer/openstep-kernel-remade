F00E26A0: 9de3bf98                 save    %sp, -0x68, %sp
F00E26A4: 80a6e000                 cmp     %i3, 0
F00E26A8: 0280000b                 be      locret_F00E26D4
F00E26AC: 01000000                 nop
F00E26B0: c4068000                 ld      [%i2], %g2
F00E26B4: 8528a002                 sll     %g2, 2, %g2
F00E26B8: f2260002                 st      %i1, [%i0+%g2]
F00E26BC: c4068000                 ld      [%i2], %g2
F00E26C0: 8400a001                 inc     %g2
F00E26C4: 80a0801b                 cmp     %g2, %i3
F00E26C8: 12800003                 bne     locret_F00E26D4
F00E26CC: c4268000                 st      %g2, [%i2]
F00E26D0: c0268000                 clr     [%i2]
F00E26D4: 81c7e008                 ret
F00E26D8: 81e80000                 restore
