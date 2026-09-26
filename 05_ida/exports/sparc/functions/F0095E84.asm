F0095E84: 85480000                 rdhpr   %hpstate, %g2
F0095E88: 8a28a020                 andn    %g2, 0x20, %g5
F0095E8C: 81894000                 saved
F0095E90: 01000000                 nop
F0095E94: 01000000                 nop
F0095E98: 8a102100                 mov     0x100, %g5
F0095E9C: ca814080                 lda     [%g5]#ASI_NUCLEUS, %g5
F0095EA0: 832aa002                 sll     %o2, 2, %g1
F0095EA4: 8b296004                 sll     %g5, 4, %g5
F0095EA8: 8a014001                 add     %g5, %g1, %g5
F0095EAC: ca814400                 lda     [%g5]0x20, %g5
F0095EB0: 8a096003                 and     %g5, 3, %g5
F0095EB4: 80a16001                 cmp     %g5, 1
F0095EB8: 8a102200                 mov     0x200, %g5
F0095EBC: 12800003                 bne     loc_F0095EC8
F0095EC0: c2814080                 lda     [%g5]#ASI_NUCLEUS, %g1
F0095EC4: d4a14080                 sta     %o2, [%g5]#ASI_NUCLEUS
F0095EC8: 92102800                 mov     0x800, %o1
F0095ECC: 90100000                 clr     %o0
F0095ED0: 94020009                 add     %o0, %o1, %o2
F0095ED4: 96028009                 add     %o2, %o1, %o3
F0095ED8: 9802c009                 add     %o3, %o1, %o4
F0095EDC: 9a030009                 add     %o4, %o1, %o5
F0095EE0: 9a036010                 inc     0x10, %o5
F0095EE4: 86034009                 add     %o5, %o1, %g3
F0095EE8: 8800c009                 add     %g3, %o1, %g4
F0095EEC: 8a010009                 add     %g4, %o1, %g5
F0095EF0: 92a26020                 deccc   0x20, %o1 ! ' '
F0095EF4: c0a20260                 sta     %g0, [%o0]0x13
F0095EF8: c0a2026a                 sta     %g0, [%o0+%o2]0x13
F0095EFC: c0a2026b                 sta     %g0, [%o0+%o3]0x13
F0095F00: c0a2026c                 sta     %g0, [%o0+%o4]0x13
F0095F04: c0a2026d                 sta     %g0, [%o0+%o5]0x13
F0095F08: c0a20263                 sta     %g0, [%o0+%g3]0x13
F0095F0C: c0a20264                 sta     %g0, [%o0+%g4]0x13
F0095F10: c0a20265                 sta     %g0, [%o0+%g5]0x13
F0095F14: 12bffff7                 bne     loc_F0095EF0
F0095F18: 90022020                 inc     0x20, %o0 ! ' '
F0095F1C: 8a102200                 mov     0x200, %g5
F0095F20: c2a14080                 sta     %g1, [%g5]#ASI_NUCLEUS
F0095F24: 81888000                 saved
F0095F28: 01000000                 nop
F0095F2C: 01000000                 nop
F0095F30: 81c3e008                 retl
F0095F34: 01000000                 nop
