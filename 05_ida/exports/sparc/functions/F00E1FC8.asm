F00E1FC8: 9de3bf98                 save    %sp, -0x68, %sp
F00E1FCC: b406bfff                 inc     -1, %i2
F00E1FD0: 80a6bfff                 cmp     %i2, -1
F00E1FD4: 0280000a                 be      locret_F00E1FFC
F00E1FD8: 01000000                 nop
F00E1FDC: b406bfff                 inc     -1, %i2
F00E1FE0: c4160000                 lduh    [%i0], %g2
F00E1FE4: 80a6bfff                 cmp     %i2, -1
F00E1FE8: 8530a008                 srl     %g2, 8, %g2
F00E1FEC: c42e4000                 stb     %g2, [%i1]
F00E1FF0: b0062002                 inc     2, %i0
F00E1FF4: 12bffffa                 bne     loc_F00E1FDC
F00E1FF8: b2066001                 inc     %i1
F00E1FFC: 81c7e008                 ret
F00E2000: 81e80000                 restore
