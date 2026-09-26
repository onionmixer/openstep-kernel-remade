F006F960: 9de3bf98                 save    %sp, -0x68, %sp
F006F964: 86100018                 mov     %i0, %g3
F006F968: f000c000                 ld      [%g3], %i0
F006F96C: 80a60003                 cmp     %i0, %g3
F006F970: 22800006                 be,a    locret_F006F988
F006F974: b0102000                 mov     0, %i0
F006F978: c4060000                 ld      [%i0], %g2
F006F97C: c620a004                 st      %g3, [%g2+4]
F006F980: c4060000                 ld      [%i0], %g2
F006F984: c420c000                 st      %g2, [%g3]
F006F988: 81c7e008                 ret
F006F98C: 81e80000                 restore
