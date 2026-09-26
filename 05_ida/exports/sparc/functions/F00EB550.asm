F00EB550: 9c03bf90                 inc     -0x70, %sp
F00EB554: 84100008                 mov     %o0, %g2
F00EB558: 80a2e000                 cmp     %o3, 0
F00EB55C: 12800004                 bne     loc_F00EB56C
F00EB560: 9010000a                 mov     %o2, %o0
F00EB564: 10800012                 ba      locret_F00EB5AC
F00EB568: 90102000                 mov     0, %o0
F00EB56C: c600a004                 ld      [%g2+4], %g3
F00EB570: c400a008                 ld      [%g2+8], %g2
F00EB574: 8528a002                 sll     %g2, 2, %g2
F00EB578: 92008003                 add     %g2, %g3, %o1
F00EB57C: 80a0c009                 cmp     %g3, %o1
F00EB580: 3a80000b                 bcc,a   locret_F00EB5AC
F00EB584: 90102000                 mov     0, %o0
F00EB588: c400c000                 ld      [%g3], %g2
F00EB58C: 80a08008                 cmp     %g2, %o0
F00EB590: 22800007                 be,a    locret_F00EB5AC
F00EB594: d620c000                 st      %o3, [%g3]
F00EB598: 8600e004                 inc     4, %g3
F00EB59C: 80a0c009                 cmp     %g3, %o1
F00EB5A0: 2abffffb                 bcs,a   loc_F00EB58C
F00EB5A4: c400c000                 ld      [%g3], %g2
F00EB5A8: 90102000                 mov     0, %o0
F00EB5AC: 81c3e008                 retl
F00EB5B0: 9c23bf90                 dec     -0x70, %sp
