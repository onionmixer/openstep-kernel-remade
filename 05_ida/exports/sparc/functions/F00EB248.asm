F00EB248: 9c03bf90                 inc     -0x70, %sp
F00EB24C: c4022008                 ld      [%o0+8], %g2
F00EB250: 80a0a000                 cmp     %g2, 0
F00EB254: 02800006                 be      loc_F00EB26C
F00EB258: 8528a002                 sll     %g2, 2, %g2
F00EB25C: c6022004                 ld      [%o0+4], %g3
F00EB260: 84008003                 add     %g2, %g3, %g2
F00EB264: 10800003                 ba      locret_F00EB270
F00EB268: d000bffc                 ld      [%g2-4], %o0
F00EB26C: 90102000                 mov     0, %o0
F00EB270: 81c3e008                 retl
F00EB274: 9c23bf90                 dec     -0x70, %sp
