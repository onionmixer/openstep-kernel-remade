F00E266C: 9de3bf98                 save    %sp, -0x68, %sp
F00E2670: 10800006                 ba      loc_F00E2688
F00E2674: 86102000                 mov     0, %g3
F00E2678: 80a08003                 cmp     %g2, %g3
F00E267C: 08800003                 bleu    loc_F00E2688
F00E2680: b0062004                 inc     4, %i0
F00E2684: 86100002                 mov     %g2, %g3
F00E2688: b2067fff                 inc     -1, %i1
F00E268C: 80a67fff                 cmp     %i1, -1
F00E2690: 32bffffa                 bne,a   loc_F00E2678
F00E2694: c4060000                 ld      [%i0], %g2
F00E2698: 81c7e008                 ret
F00E269C: 91e80003                 restore %g0, %g3, %o0
