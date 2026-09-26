F0094F74: 1b3c0464                 sethi   %hi(_bcopy_res), %o5
F0094F78: d86b6300                 ldstub  [%o5+%lo(_bcopy_res)], %o4
F0094F7C: 80930000                 tst     %o4
F0094F80: 1280001f                 bne     locret_F0094FFC
F0094F84: 1b3c0447                 sethi   %hi(_page_size), %o5
F0094F88: d803613c                 ld      [%o5+%lo(_page_size)], %o4
F0094F8C: 1b0070009a136100         set     0x1C00100, %o5
F0094F94: 0300700082106200         set     0x1C00200, %g1
F0094F9C: d0bb4040                 stda    %o0, [%o5]2
F0094FA0: d4b84040                 stda    %o2, [%g1]2
F0094FA4: 92026020                 inc     0x20, %o1 ! ' '
F0094FA8: 98a32020                 deccc   0x20, %o4 ! ' '
F0094FAC: 12bffffc                 bne     loc_F0094F9C
F0094FB0: 9602e020                 inc     0x20, %o3 ! ' '
F0094FB4: 1b0070039a136200         set     0x1C00E00, %o5
F0094FBC: d09b4040                 ldda    [%o5]2, %o0
F0094FC0: 15010000                 sethi   0x4000000, %o2
F0094FC4: 808a8008                 btst    %o0, %o2
F0094FC8: 02800006                 be      loc_F0094FE0
F0094FCC: 1b3c0464                 sethi   -0xFEE7000, %o5
F0094FD0: 15008000                 sethi   0x2000000, %o2
F0094FD4: 808a8008                 btst    %o0, %o2
F0094FD8: 32800005                 bne,a   loc_F0094FEC
F0094FDC: 01000000                 nop
F0094FE0: c0236300                 clr     [%o5+0x300]
F0094FE4: 81c3e008                 retl
F0094FE8: 90102000                 mov     0, %o0
F0094FEC: 113c025490122004         set     aHwBcopyStreamO, %o0! "hw bcopy stream operation failed; using"...
F0094FF4: 7ffe005f                 call    _panic
F0094FF8: 01000000                 nop
F0094FFC: 81c3e008                 retl
F0095000: 90102001                 mov     1, %o0
