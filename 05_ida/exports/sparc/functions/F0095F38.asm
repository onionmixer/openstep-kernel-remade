F0095F38: 85480000                 rdhpr   %hpstate, %g2
F0095F3C: 8a28a020                 andn    %g2, 0x20, %g5
F0095F40: 81894000                 saved
F0095F44: 01000000                 nop
F0095F48: 01000000                 nop
F0095F4C: 8a102100                 mov     0x100, %g5
F0095F50: ca814080                 lda     [%g5]#ASI_NUCLEUS, %g5
F0095F54: 832aa002                 sll     %o2, 2, %g1
F0095F58: 8b296004                 sll     %g5, 4, %g5
F0095F5C: 8a014001                 add     %g5, %g1, %g5
F0095F60: ca814400                 lda     [%g5]0x20, %g5
F0095F64: 8a096003                 and     %g5, 3, %g5
F0095F68: 80a16001                 cmp     %g5, 1
F0095F6C: 8a102200                 mov     0x200, %g5
F0095F70: 12800003                 bne     loc_F0095F7C
F0095F74: c2814080                 lda     [%g5]#ASI_NUCLEUS, %g1
F0095F78: d4a14080                 sta     %o2, [%g5]#ASI_NUCLEUS
F0095F7C: 92102800                 mov     0x800, %o1
F0095F80: 94100009                 mov     %o1, %o2
F0095F84: 96028009                 add     %o2, %o1, %o3
F0095F88: 9802c009                 add     %o3, %o1, %o4
F0095F8C: 9a030009                 add     %o4, %o1, %o5
F0095F90: 9a036010                 inc     0x10, %o5
F0095F94: 86034009                 add     %o5, %o1, %g3
F0095F98: 8800c009                 add     %g3, %o1, %g4
F0095F9C: 8a010009                 add     %g4, %o1, %g5
F0095FA0: 92a26020                 deccc   0x20, %o1 ! ' '
F0095FA4: c0a20240                 sta     %g0, [%o0]0x12
F0095FA8: c0a2024a                 sta     %g0, [%o0+%o2]0x12
F0095FAC: c0a2024b                 sta     %g0, [%o0+%o3]0x12
F0095FB0: c0a2024c                 sta     %g0, [%o0+%o4]0x12
F0095FB4: c0a2024d                 sta     %g0, [%o0+%o5]0x12
F0095FB8: c0a20243                 sta     %g0, [%o0+%g3]0x12
F0095FBC: c0a20244                 sta     %g0, [%o0+%g4]0x12
F0095FC0: c0a20245                 sta     %g0, [%o0+%g5]0x12
F0095FC4: 12bffff7                 bne     loc_F0095FA0
F0095FC8: 90022020                 inc     0x20, %o0 ! ' '
F0095FCC: 8a102200                 mov     0x200, %g5
F0095FD0: c2a14080                 sta     %g1, [%g5]#ASI_NUCLEUS
F0095FD4: 81888000                 saved
F0095FD8: 01000000                 nop
F0095FDC: 01000000                 nop
F0095FE0: 81c3e008                 retl
F0095FE4: 01000000                 nop
