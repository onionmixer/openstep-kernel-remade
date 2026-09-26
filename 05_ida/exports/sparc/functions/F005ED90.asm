F005ED90: 9de3bf98                 save    %sp, -0x68, %sp
F005ED94: c6060000                 ld      [%i0], %g3
F005ED98: 80a0e000                 cmp     %g3, 0
F005ED9C: 32800004                 bne,a   loc_F005EDAC
F005EDA0: c400e094                 ld      [%g3+0x94], %g2
F005EDA4: 10800006                 ba      locret_F005EDBC
F005EDA8: f2260000                 st      %i1, [%i0]
F005EDAC: c6266090                 st      %g3, [%i1+0x90]
F005EDB0: c4266094                 st      %g2, [%i1+0x94]
F005EDB4: f220e094                 st      %i1, [%g3+0x94]
F005EDB8: f220a090                 st      %i1, [%g2+0x90]
F005EDBC: 81c7e008                 ret
F005EDC0: 81e80000                 restore
