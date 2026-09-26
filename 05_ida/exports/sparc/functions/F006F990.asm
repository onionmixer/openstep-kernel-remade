F006F990: 9de3bf98                 save    %sp, -0x68, %sp
F006F994: 86100018                 mov     %i0, %g3
F006F998: f000e004                 ld      [%g3+4], %i0
F006F99C: 80a60003                 cmp     %i0, %g3
F006F9A0: 22800006                 be,a    locret_F006F9B8
F006F9A4: b0102000                 mov     0, %i0
F006F9A8: c4062004                 ld      [%i0+4], %g2
F006F9AC: c6208000                 st      %g3, [%g2]
F006F9B0: c4062004                 ld      [%i0+4], %g2
F006F9B4: c420e004                 st      %g2, [%g3+4]
F006F9B8: 81c7e008                 ret
F006F9BC: 81e80000                 restore
