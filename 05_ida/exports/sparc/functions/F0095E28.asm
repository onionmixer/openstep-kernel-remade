F0095E28: 92102800                 mov     0x800, %o1
F0095E2C: 90100000                 clr     %o0
F0095E30: 94020009                 add     %o0, %o1, %o2
F0095E34: 96028009                 add     %o2, %o1, %o3
F0095E38: 9802c009                 add     %o3, %o1, %o4
F0095E3C: 9a030009                 add     %o4, %o1, %o5
F0095E40: 9a036010                 inc     0x10, %o5
F0095E44: 86034009                 add     %o5, %o1, %g3
F0095E48: 8800c009                 add     %g3, %o1, %g4
F0095E4C: 8a010009                 add     %g4, %o1, %g5
F0095E50: 92a26020                 deccc   0x20, %o1 ! ' '
F0095E54: c0a20280                 sta     %g0, [%o0]0x14
F0095E58: c0a2028a                 sta     %g0, [%o0+%o2]0x14
F0095E5C: c0a2028b                 sta     %g0, [%o0+%o3]0x14
F0095E60: c0a2028c                 sta     %g0, [%o0+%o4]0x14
F0095E64: c0a2028d                 sta     %g0, [%o0+%o5]0x14
F0095E68: c0a20283                 sta     %g0, [%o0+%g3]0x14
F0095E6C: c0a20284                 sta     %g0, [%o0+%g4]0x14
F0095E70: c0a20285                 sta     %g0, [%o0+%g5]0x14
F0095E74: 12bffff7                 bne     loc_F0095E50
F0095E78: 90022020                 inc     0x20, %o0 ! ' '
F0095E7C: 81c3e008                 retl
F0095E80: 01000000                 nop
