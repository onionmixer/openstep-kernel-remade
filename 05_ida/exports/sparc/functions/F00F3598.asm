F00F3598: 86102000                 mov     0, %g3
F00F359C: c40a0000                 ldub    [%o0], %g2
F00F35A0: 80a0a000                 cmp     %g2, 0
F00F35A4: 02800017                 be      locret_F00F3600
F00F35A8: 01000000                 nop
F00F35AC: 8618c002                 btog    %g2, %g3
F00F35B0: 90022001                 inc     %o0
F00F35B4: c40a0000                 ldub    [%o0], %g2
F00F35B8: 80a0a000                 cmp     %g2, 0
F00F35BC: 02800011                 be      locret_F00F3600
F00F35C0: 8528a008                 sll     %g2, 8, %g2
F00F35C4: 8618c002                 btog    %g2, %g3
F00F35C8: 90022001                 inc     %o0
F00F35CC: c40a0000                 ldub    [%o0], %g2
F00F35D0: 80a0a000                 cmp     %g2, 0
F00F35D4: 0280000b                 be      locret_F00F3600
F00F35D8: 8528a010                 sll     %g2, 16, %g2
F00F35DC: 8618c002                 btog    %g2, %g3
F00F35E0: 90022001                 inc     %o0
F00F35E4: c40a0000                 ldub    [%o0], %g2
F00F35E8: 80a0a000                 cmp     %g2, 0
F00F35EC: 02800005                 be      locret_F00F3600
F00F35F0: 8528a018                 sll     %g2, 24, %g2
F00F35F4: 8618c002                 btog    %g2, %g3
F00F35F8: 10bfffe9                 ba      loc_F00F359C
F00F35FC: 90022001                 inc     %o0
F00F3600: 81c3e008                 retl
F00F3604: 90100003                 mov     %g3, %o0
