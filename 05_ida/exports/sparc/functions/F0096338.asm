F0096338: 9a102000                 mov     0, %o5
F009633C: d8834080                 lda     [%o5]#ASI_NUCLEUS, %o4
F0096340: 982b0008                 bclr    %o0, %o4
F0096344: 98130009                 bset    %o1, %o4
F0096348: d8a34080                 sta     %o4, [%o5]#ASI_NUCLEUS
F009634C: 81c3e008                 retl
F0096350: 01000000                 nop
