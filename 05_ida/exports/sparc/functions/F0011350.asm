F0011350: 9de3bf98                 save    %sp, -0x68, %sp
F0011354: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0011358: d40421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o2
F001135C: d202a024                 ld      [%o2+0x24], %o1
F0011360: d0026004                 ld      [%o1+4], %o0
F0011364: 80a22020                 cmp     %o0, 0x20 ! ' '
F0011368: 28800005                 bleu,a  loc_F001137C
F001136C: d2024000                 ld      [%o1], %o1
F0011370: 90102016                 mov     0x16, %o0
F0011374: 10800006                 ba      locret_F001138C
F0011378: d02aa038                 stb     %o0, [%o2+0x38]
F001137C: 40000006                 call    _killpg1
F0011380: 94102000                 mov     0, %o2
F0011384: d20421dc                 ld      [%l0+0x1DC], %o1
F0011388: d02a6038                 stb     %o0, [%o1+0x38]
F001138C: 81c7e008                 ret
F0011390: 81e80000                 restore
