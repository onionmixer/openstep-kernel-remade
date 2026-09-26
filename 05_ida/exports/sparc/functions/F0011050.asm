F0011050: 9de3bf98                 save    %sp, -0x68, %sp
F0011054: 113c04cf961221dc         set     dword_F0133DDC, %o3
F001105C: d402fffc                 ld      [%o3-4], %o2
F0011060: d00221dc                 ld      [%o0+0x1DC], %o0
F0011064: da028000                 ld      [%o2], %o5
F0011068: d8022024                 ld      [%o0+0x24], %o4
F001106C: d203601c                 ld      [%o5+0x1C], %o1
F0011070: d222a140                 st      %o1, [%o2+0x140]
F0011074: d0036028                 ld      [%o5+0x28], %o0
F0011078: 90122200                 bset    0x200, %o0
F001107C: d0236028                 st      %o0, [%o5+0x28]
F0011080: d002fffc                 ld      [%o3-4], %o0
F0011084: d0020000                 ld      [%o0], %o0
F0011088: d2022014                 ld      [%o0+0x14], %o1
F001108C: 11000010                 sethi   0x4000, %o0
F0011090: 808a4008                 btst    %o0, %o1
F0011094: 02800005                 be      loc_F00110A8
F0011098: d8030000                 ld      [%o4], %o4
F001109C: 113fffbf                 sethi   -0x10400, %o0
F00110A0: 10800004                 ba      loc_F00110B0
F00110A4: 901222ff                 bset    0x2FF, %o0
F00110A8: 113ffebf901222ff         set     -0x50101, %o0
F00110B0: 980b0008                 and     %o4, %o0, %o4
F00110B4: d823601c                 st      %o4, [%o5+0x1C]
F00110B8: 113c04cf901221d8         set     _active_u, %o0
F00110C0: 153c0044                 sethi   %hi(_sigcont), %o2
F00110C4: 92102028                 mov     0x28, %o1 ! '('
F00110C8: 400005ec                 call    _sleep_with_continuation
F00110CC: 9412a03c                 bset    %lo(_sigcont), %o2
F00110D0: 81c7e008                 ret
F00110D4: 81e80000                 restore
