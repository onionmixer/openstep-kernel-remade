F00961DC: 85480000                 rdhpr   %hpstate, %g2
F00961E0: 8228a020                 andn    %g2, 0x20, %g1
F00961E4: 81884000                 saved
F00961E8: 01000000                 nop
F00961EC: 01000000                 nop
F00961F0: 01000000                 nop
F00961F4: da020000                 ld      [%o0], %o5
F00961F8: 9a2b4009                 bclr    %o1, %o5
F00961FC: 9a13400a                 bset    %o2, %o5
F0096200: da7a0000                 swap    [%o0], %o5
F0096204: 81888000                 saved
F0096208: 01000000                 nop
F009620C: 01000000                 nop
F0096210: 01000000                 nop
F0096214: 81c3e008                 retl
F0096218: 9010000d                 mov     %o5, %o0
