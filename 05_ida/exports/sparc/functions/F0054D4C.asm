F0054D4C: 9de3bf98                 save    %sp, -0x68, %sp
F0054D50: c6060000                 ld      [%i0], %g3
F0054D54: 80a0e000                 cmp     %g3, 0
F0054D58: 32800006                 bne,a   loc_F0054D70
F0054D5C: c400e004                 ld      [%g3+4], %g2
F0054D60: f2260000                 st      %i1, [%i0]
F0054D64: f2264000                 st      %i1, [%i1]
F0054D68: 10800006                 ba      locret_F0054D80
F0054D6C: f2266004                 st      %i1, [%i1+4]
F0054D70: c6264000                 st      %g3, [%i1]
F0054D74: c4266004                 st      %g2, [%i1+4]
F0054D78: f220e004                 st      %i1, [%g3+4]
F0054D7C: f2208000                 st      %i1, [%g2]
F0054D80: 81c7e008                 ret
F0054D84: 81e80000                 restore
