F0054D88: 9de3bf98                 save    %sp, -0x68, %sp
F0054D8C: b2100018                 mov     %i0, %i1
F0054D90: f0064000                 ld      [%i1], %i0
F0054D94: 80a62000                 cmp     %i0, 0
F0054D98: 0280000b                 be      locret_F0054DC4
F0054D9C: 01000000                 nop
F0054DA0: c6060000                 ld      [%i0], %g3
F0054DA4: 80a0c018                 cmp     %g3, %i0
F0054DA8: 32800004                 bne,a   loc_F0054DB8
F0054DAC: c4062004                 ld      [%i0+4], %g2
F0054DB0: 10800005                 ba      locret_F0054DC4
F0054DB4: c0264000                 clr     [%i1]
F0054DB8: c6264000                 st      %g3, [%i1]
F0054DBC: c420e004                 st      %g2, [%g3+4]
F0054DC0: c6208000                 st      %g3, [%g2]
F0054DC4: 81c7e008                 ret
F0054DC8: 81e80000                 restore
