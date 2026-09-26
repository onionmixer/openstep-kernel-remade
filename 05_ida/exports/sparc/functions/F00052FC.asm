F00052FC: 9de3bf98                 save    %sp, -0x68, %sp
F0005300: b32e6018                 sll     %i1, 24, %i1
F0005304: b33e6018                 sra     %i1, 24, %i1
F0005308: c44e0000                 ldsb    [%i0], %g2
F000530C: 80a08019                 cmp     %g2, %i1
F0005310: 02800005                 be      locret_F0005324
F0005314: 80a0a000                 cmp     %g2, 0
F0005318: 12bffffc                 bne     loc_F0005308
F000531C: b0062001                 inc     %i0
F0005320: b0102000                 mov     0, %i0
F0005324: 81c7e008                 ret
F0005328: 81e80000                 restore
