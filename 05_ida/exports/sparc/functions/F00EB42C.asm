F00EB42C: 9c03bf90                 inc     -0x70, %sp
F00EB430: 98100008                 mov     %o0, %o4
F00EB434: c4032008                 ld      [%o4+8], %g2
F00EB438: 80a28002                 cmp     %o2, %g2
F00EB43C: 0a800004                 bcs     loc_F00EB44C
F00EB440: 912aa002                 sll     %o2, 2, %o0
F00EB444: 10800014                 ba      locret_F00EB494
F00EB448: 90102000                 mov     0, %o0
F00EB44C: c6032004                 ld      [%o4+4], %g3
F00EB450: 94020003                 add     %o0, %g3, %o2
F00EB454: c4032008                 ld      [%o4+8], %g2
F00EB458: 8528a002                 sll     %g2, 2, %g2
F00EB45C: 96008003                 add     %g2, %g3, %o3
F00EB460: 9202a004                 add     %o2, 4, %o1
F00EB464: 80a2400b                 cmp     %o1, %o3
F00EB468: 1a800008                 bcc     loc_F00EB488
F00EB46C: d0020003                 ld      [%o0+%g3], %o0
F00EB470: c4024000                 ld      [%o1], %g2
F00EB474: c4228000                 st      %g2, [%o2]
F00EB478: 92026004                 inc     4, %o1
F00EB47C: 80a2400b                 cmp     %o1, %o3
F00EB480: 0abffffc                 bcs     loc_F00EB470
F00EB484: 9402a004                 inc     4, %o2
F00EB488: c4032008                 ld      [%o4+8], %g2
F00EB48C: 8400bfff                 inc     -1, %g2
F00EB490: c4232008                 st      %g2, [%o4+8]
F00EB494: 81c3e008                 retl
F00EB498: 9c23bf90                 dec     -0x70, %sp
