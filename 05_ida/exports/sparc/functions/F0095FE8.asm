F0095FE8: 85480000                 rdhpr   %hpstate, %g2
F0095FEC: 8a28a020                 andn    %g2, 0x20, %g5
F0095FF0: 81894000                 saved
F0095FF4: 01000000                 nop
F0095FF8: 01000000                 nop
F0095FFC: 8a102100                 mov     0x100, %g5
F0096000: ca814080                 lda     [%g5]#ASI_NUCLEUS, %g5
F0096004: 832aa002                 sll     %o2, 2, %g1
F0096008: 8b296004                 sll     %g5, 4, %g5
F009600C: 8a014001                 add     %g5, %g1, %g5
F0096010: ca814400                 lda     [%g5]0x20, %g5
F0096014: 8a096003                 and     %g5, 3, %g5
F0096018: 80a16001                 cmp     %g5, 1
F009601C: 8a102200                 mov     0x200, %g5
F0096020: 12800003                 bne     loc_F009602C
F0096024: c2814080                 lda     [%g5]#ASI_NUCLEUS, %g1
F0096028: d4a14080                 sta     %o2, [%g5]#ASI_NUCLEUS
F009602C: 92102800                 mov     0x800, %o1
F0096030: 94100009                 mov     %o1, %o2
F0096034: 96028009                 add     %o2, %o1, %o3
F0096038: 9802c009                 add     %o3, %o1, %o4
F009603C: 9a030009                 add     %o4, %o1, %o5
F0096040: 9a036010                 inc     0x10, %o5
F0096044: 86034009                 add     %o5, %o1, %g3
F0096048: 8800c009                 add     %g3, %o1, %g4
F009604C: 8a010009                 add     %g4, %o1, %g5
F0096050: 92a26020                 deccc   0x20, %o1 ! ' '
F0096054: c0a20220                 sta     %g0, [%o0]#ASI_AS_IF_USER_SECONDARY
F0096058: c0a2022a                 sta     %g0, [%o0+%o2]#ASI_AS_IF_USER_SECONDARY
F009605C: c0a2022b                 sta     %g0, [%o0+%o3]#ASI_AS_IF_USER_SECONDARY
F0096060: c0a2022c                 sta     %g0, [%o0+%o4]#ASI_AS_IF_USER_SECONDARY
F0096064: c0a2022d                 sta     %g0, [%o0+%o5]#ASI_AS_IF_USER_SECONDARY
F0096068: c0a20223                 sta     %g0, [%o0+%g3]#ASI_AS_IF_USER_SECONDARY
F009606C: c0a20224                 sta     %g0, [%o0+%g4]#ASI_AS_IF_USER_SECONDARY
F0096070: c0a20225                 sta     %g0, [%o0+%g5]#ASI_AS_IF_USER_SECONDARY
F0096074: 12bffff7                 bne     loc_F0096050
F0096078: 90022020                 inc     0x20, %o0 ! ' '
F009607C: 8a102200                 mov     0x200, %g5
F0096080: c2a14080                 sta     %g1, [%g5]#ASI_NUCLEUS
F0096084: 81888000                 saved
F0096088: 01000000                 nop
F009608C: 01000000                 nop
F0096090: 81c3e008                 retl
F0096094: 01000000                 nop
