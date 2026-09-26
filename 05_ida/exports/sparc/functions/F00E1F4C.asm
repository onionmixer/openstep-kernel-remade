F00E1F4C: 9de3bf98                 save    %sp, -0x68, %sp
F00E1F50: b406bfff                 inc     -1, %i2
F00E1F54: 80a6bfff                 cmp     %i2, -1
F00E1F58: 0280000a                 be      locret_F00E1F80
F00E1F5C: 01000000                 nop
F00E1F60: b406bfff                 inc     -1, %i2
F00E1F64: c40e0000                 ldub    [%i0], %g2
F00E1F68: 80a6bfff                 cmp     %i2, -1
F00E1F6C: 8528a008                 sll     %g2, 8, %g2
F00E1F70: c4364000                 sth     %g2, [%i1]
F00E1F74: b0062001                 inc     %i0
F00E1F78: 12bffffa                 bne     loc_F00E1F60
F00E1F7C: b2066002                 inc     2, %i1
F00E1F80: 81c7e008                 ret
F00E1F84: 81e80000                 restore
