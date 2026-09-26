F00110D8: 9de3bf90                 save    %sp, -0x70, %sp! int
F00110DC: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F00110E0: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F00110E4: e2022024                 ld      [%o0+0x24], %l1
F00110E8: d2046004                 ld      [%l1+4], %o1! int
F00110EC: 80a26000                 cmp     %o1, 0
F00110F0: 0280000d                 be      loc_F0011124
F00110F4: a41421dc                 or      %l0, %lo(dword_F0133DDC), %l2
F00110F8: d004bffc                 ld      [%l2-4], %o0! int
F00110FC: 94102008                 mov     8, %o2! int
F0011100: 40021bf3                 call    _copyout
F0011104: 90022144                 inc     0x144, %o0
F0011108: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F001110C: d02a6038                 stb     %o0, [%o1+0x38]
F0011110: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0011114: d04a2038                 ldsb    [%o0+0x38], %o0
F0011118: 80a22000                 cmp     %o0, 0
F001111C: 12800013                 bne     locret_F0011168
F0011120: 01000000                 nop
F0011124: d0044000                 ld      [%l1], %o0! int
F0011128: 80a22000                 cmp     %o0, 0
F001112C: 0280000f                 be      locret_F0011168
F0011130: 9207bff0                 add     %fp, var_10, %o1! int
F0011134: 40021bc9                 call    _copyin
F0011138: 94102008                 mov     8, %o2
F001113C: d20421dc                 ld      [%l0+0x1DC], %o1
F0011140: d02a6038                 stb     %o0, [%o1+0x38]
F0011144: d00421dc                 ld      [%l0+0x1DC], %o0
F0011148: d04a2038                 ldsb    [%o0+0x38], %o0
F001114C: 80a22000                 cmp     %o0, 0
F0011150: 12800006                 bne     locret_F0011168
F0011154: d207bff0                 ld      [%fp+var_10], %o1
F0011158: d004bffc                 ld      [%l2-4], %o0
F001115C: d2222144                 st      %o1, [%o0+0x144]
F0011160: d207bff4                 ld      [%fp+var_C], %o1
F0011164: d2222148                 st      %o1, [%o0+0x148]
F0011168: 81c7e008                 ret
F001116C: 81e80000                 restore
