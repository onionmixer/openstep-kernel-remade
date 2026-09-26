F0005248: 9de3bf98                 save    %sp, -0x68, %sp
F000524C: b32e6018                 sll     %i1, 24, %i1
F0005250: b33e6018                 sra     %i1, 24, %i1
F0005254: c44e0000                 ldsb    [%i0], %g2
F0005258: 80a08019                 cmp     %g2, %i1
F000525C: 02800005                 be      locret_F0005270
F0005260: 80a0a000                 cmp     %g2, 0
F0005264: 12bffffc                 bne     loc_F0005254
F0005268: b0062001                 inc     %i0
F000526C: b0102000                 mov     0, %i0
F0005270: 81c7e008                 ret
F0005274: 81e80000                 restore
