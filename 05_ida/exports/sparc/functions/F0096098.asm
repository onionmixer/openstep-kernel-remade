F0096098: 92102200                 mov     0x200, %o1
F009609C: 94100009                 mov     %o1, %o2
F00960A0: 96028009                 add     %o2, %o1, %o3
F00960A4: 9802c009                 add     %o3, %o1, %o4
F00960A8: 9a030009                 add     %o4, %o1, %o5
F00960AC: 86034009                 add     %o5, %o1, %g3
F00960B0: 8800c009                 add     %g3, %o1, %g4
F00960B4: 8a010009                 add     %g4, %o1, %g5
F00960B8: 92a26010                 deccc   0x10, %o1
F00960BC: c0a20200                 sta     %g0, [%o0]#ASI_AS_IF_USER_PRIMARY
F00960C0: c0a2020a                 sta     %g0, [%o0+%o2]#ASI_AS_IF_USER_PRIMARY
F00960C4: c0a2020b                 sta     %g0, [%o0+%o3]#ASI_AS_IF_USER_PRIMARY
F00960C8: c0a2020c                 sta     %g0, [%o0+%o4]#ASI_AS_IF_USER_PRIMARY
F00960CC: c0a2020d                 sta     %g0, [%o0+%o5]#ASI_AS_IF_USER_PRIMARY
F00960D0: c0a20203                 sta     %g0, [%o0+%g3]#ASI_AS_IF_USER_PRIMARY
F00960D4: c0a20204                 sta     %g0, [%o0+%g4]#ASI_AS_IF_USER_PRIMARY
F00960D8: c0a20205                 sta     %g0, [%o0+%g5]#ASI_AS_IF_USER_PRIMARY
F00960DC: 12bffff7                 bne     loc_F00960B8
F00960E0: 90022010                 inc     0x10, %o0
F00960E4: 81c3e008                 retl
F00960E8: 01000000                 nop
