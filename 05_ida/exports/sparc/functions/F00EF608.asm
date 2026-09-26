F00EF608: c4022024                 ld      [%o0+0x24], %g2
F00EF60C: 80a08009                 cmp     %g2, %o1
F00EF610: 32800005                 bne,a   loc_F00EF624
F00EF614: d0022024                 ld      [%o0+0x24], %o0
F00EF618: c4024000                 ld      [%o1], %g2
F00EF61C: 1080000e                 ba      locret_F00EF654
F00EF620: c4222024                 st      %g2, [%o0+0x24]
F00EF624: c4020000                 ld      [%o0], %g2
F00EF628: 80a0a000                 cmp     %g2, 0
F00EF62C: 0280000a                 be      locret_F00EF654
F00EF630: 80a08009                 cmp     %g2, %o1
F00EF634: 32800006                 bne,a   loc_F00EF64C
F00EF638: 90100002                 mov     %g2, %o0
F00EF63C: c4008000                 ld      [%g2], %g2
F00EF640: c4220000                 st      %g2, [%o0]
F00EF644: 10bffff9                 ba      loc_F00EF628
F00EF648: 84102000                 mov     0, %g2
F00EF64C: 10bffff7                 ba      loc_F00EF628
F00EF650: c4008000                 ld      [%g2], %g2
F00EF654: 81c3e008                 retl
F00EF658: 01000000                 nop
