F00960EC: 85480000                 rdhpr   %hpstate, %g2
F00960F0: 8a28a020                 andn    %g2, 0x20, %g5
F00960F4: 81894000                 saved
F00960F8: 01000000                 nop
F00960FC: 01000000                 nop
F0096100: 8a102100                 mov     0x100, %g5
F0096104: ca814080                 lda     [%g5]#ASI_NUCLEUS, %g5
F0096108: 832aa002                 sll     %o2, 2, %g1
F009610C: 8b296004                 sll     %g5, 4, %g5
F0096110: 8a014001                 add     %g5, %g1, %g5
F0096114: ca814400                 lda     [%g5]0x20, %g5
F0096118: 8a096003                 and     %g5, 3, %g5
F009611C: 80a16001                 cmp     %g5, 1
F0096120: 8a102200                 mov     0x200, %g5
F0096124: 12800003                 bne     loc_F0096130
F0096128: c2814080                 lda     [%g5]#ASI_NUCLEUS, %g1
F009612C: d4a14080                 sta     %o2, [%g5]#ASI_NUCLEUS
F0096130: 92102200                 mov     0x200, %o1
F0096134: 94100009                 mov     %o1, %o2
F0096138: 96028009                 add     %o2, %o1, %o3
F009613C: 9802c009                 add     %o3, %o1, %o4
F0096140: 9a030009                 add     %o4, %o1, %o5
F0096144: 86034009                 add     %o5, %o1, %g3
F0096148: 8800c009                 add     %g3, %o1, %g4
F009614C: 8a010009                 add     %g4, %o1, %g5
F0096150: 92a26010                 deccc   0x10, %o1
F0096154: c0a20200                 sta     %g0, [%o0]#ASI_AS_IF_USER_PRIMARY
F0096158: c0a2020a                 sta     %g0, [%o0+%o2]#ASI_AS_IF_USER_PRIMARY
F009615C: c0a2020b                 sta     %g0, [%o0+%o3]#ASI_AS_IF_USER_PRIMARY
F0096160: c0a2020c                 sta     %g0, [%o0+%o4]#ASI_AS_IF_USER_PRIMARY
F0096164: c0a2020d                 sta     %g0, [%o0+%o5]#ASI_AS_IF_USER_PRIMARY
F0096168: c0a20203                 sta     %g0, [%o0+%g3]#ASI_AS_IF_USER_PRIMARY
F009616C: c0a20204                 sta     %g0, [%o0+%g4]#ASI_AS_IF_USER_PRIMARY
F0096170: c0a20205                 sta     %g0, [%o0+%g5]#ASI_AS_IF_USER_PRIMARY
F0096174: 12bffff7                 bne     loc_F0096150
F0096178: 90022010                 inc     0x10, %o0
F009617C: 8a102200                 mov     0x200, %g5
F0096180: c2a14080                 sta     %g1, [%g5]#ASI_NUCLEUS
F0096184: 81888000                 saved
F0096188: 01000000                 nop
F009618C: 01000000                 nop
F0096190: 81c3e008                 retl
F0096194: 01000000                 nop
