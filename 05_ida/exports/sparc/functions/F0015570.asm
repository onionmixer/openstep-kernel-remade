F0015570: 9de3bf00                 save    %sp, -0x100, %sp! int
F0015574: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0015578: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F001557C: d6026024                 ld      [%o1+0x24], %o3! int
F0015580: d002e008                 ld      [%o3+8], %o0
F0015584: 80a22010                 cmp     %o0, 0x10
F0015588: 08800004                 bleu    loc_F0015598
F001558C: 90102016                 mov     0x16, %o0
F0015590: 10800013                 ba      locret_F00155DC
F0015594: d02a6038                 stb     %o0, [%o1+0x38]
F0015598: 9207bf60                 add     %fp, var_A0, %o1! int
F001559C: d227bfe0                 st      %o1, [%fp+var_20]
F00155A0: d002e008                 ld      [%o3+8], %o0
F00155A4: d027bfe4                 st      %o0, [%fp+var_1C]
F00155A8: d402e008                 ld      [%o3+8], %o2! int
F00155AC: d002e004                 ld      [%o3+4], %o0! int
F00155B0: 40020aaa                 call    _copyin
F00155B4: 952aa003                 sll     %o2, 3, %o2
F00155B8: d20421dc                 ld      [%l0+0x1DC], %o1
F00155BC: d02a6038                 stb     %o0, [%o1+0x38]
F00155C0: d00421dc                 ld      [%l0+0x1DC], %o0
F00155C4: d04a2038                 ldsb    [%o0+0x38], %o0
F00155C8: 80a22000                 cmp     %o0, 0
F00155CC: 12800004                 bne     locret_F00155DC
F00155D0: 9007bfe0                 add     %fp, var_20, %o0
F00155D4: 40000032                 call    _rwuio
F00155D8: 92102000                 mov     0, %o1
F00155DC: 81c7e008                 ret
F00155E0: 81e80000                 restore
