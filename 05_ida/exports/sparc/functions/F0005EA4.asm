F0005EA4: 9de3bf98                 save    %sp, -0x68, %sp
F0005EA8: b486bfff                 inccc   -1, %i2
F0005EAC: 0c80000c                 bneg    loc_F0005EDC
F0005EB0: 852e6018                 sll     %i1, 24, %g2
F0005EB4: 8738a018                 sra     %g2, 24, %g3
F0005EB8: c44e0000                 ldsb    [%i0], %g2
F0005EBC: 80a08003                 cmp     %g2, %g3
F0005EC0: 12800004                 bne     loc_F0005ED0
F0005EC4: b0062001                 inc     %i0
F0005EC8: 10800006                 ba      locret_F0005EE0
F0005ECC: b0063fff                 inc     -1, %i0
F0005ED0: b486bfff                 inccc   -1, %i2
F0005ED4: 3cbffffa                 bpos,a  loc_F0005EBC
F0005ED8: c44e0000                 ldsb    [%i0], %g2
F0005EDC: b0102000                 mov     0, %i0
F0005EE0: 81c7e008                 ret
F0005EE4: 81e80000                 restore
