F00EB1F0: 9c03bf90                 inc     -0x70, %sp
F00EB1F4: c6022004                 ld      [%o0+4], %g3
F00EB1F8: c4022008                 ld      [%o0+8], %g2
F00EB1FC: 8528a002                 sll     %g2, 2, %g2
F00EB200: 9200c002                 add     %g3, %g2, %o1
F00EB204: 80a0c009                 cmp     %g3, %o1
F00EB208: 3a80000e                 bcc,a   locret_F00EB240
F00EB20C: 90103fff                 mov     -1, %o0
F00EB210: c400c000                 ld      [%g3], %g2
F00EB214: 80a0800a                 cmp     %g2, %o2
F00EB218: 32800006                 bne,a   loc_F00EB230
F00EB21C: 8600e004                 inc     4, %g3
F00EB220: d0022004                 ld      [%o0+4], %o0
F00EB224: 9020c008                 sub     %g3, %o0, %o0
F00EB228: 10800006                 ba      locret_F00EB240
F00EB22C: 913a2002                 sra     %o0, 2, %o0
F00EB230: 80a0c009                 cmp     %g3, %o1
F00EB234: 2abffff8                 bcs,a   loc_F00EB214
F00EB238: c400c000                 ld      [%g3], %g2
F00EB23C: 90103fff                 mov     -1, %o0
F00EB240: 81c3e008                 retl
F00EB244: 9c23bf90                 dec     -0x70, %sp
