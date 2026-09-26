F00963BC: 17000008                 sethi   0x2000, %o3
F00963C0: 808ac008                 btst    %o0, %o3
F00963C4: 1280000a                 bne     loc_F00963EC
F00963C8: 19000010                 sethi   0x4000, %o4
F00963CC: 808b0008                 btst    %o0, %o4
F00963D0: 12800007                 bne     loc_F00963EC
F00963D4: 1b020000                 sethi   0x8000000, %o5
F00963D8: 808b4009                 btst    %o1, %o5
F00963DC: 12800004                 bne     loc_F00963EC
F00963E0: 01000000                 nop
F00963E4: 81c3e008                 retl
F00963E8: 90100000                 clr     %o0
F00963EC: 1300700292126204         set     0x1C00A04, %o1
F00963F4: d4824040                 lda     [%o1]2, %o2
F00963F8: 96102008                 mov     8, %o3
F00963FC: 942ac00a                 andn    %o3, %o2, %o2
F0096400: 96102000                 mov     0, %o3
F0096404: d882c080                 lda     [%o3]#ASI_NUCLEUS, %o4
F0096408: 1b000004                 sethi   0x1000, %o5
F009640C: 982b400c                 andn    %o5, %o4, %o4
F0096410: d4a24040                 sta     %o2, [%o1]2
F0096414: d8a2c080                 sta     %o4, [%o3]#ASI_NUCLEUS
F0096418: 81c3e008                 retl
F009641C: 90102001                 mov     1, %o0
