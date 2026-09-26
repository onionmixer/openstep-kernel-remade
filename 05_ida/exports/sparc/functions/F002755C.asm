F002755C: 9de3bf90                 save    %sp, -0x70, %sp
F0027560: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0027564: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0027568: 7fffa101                 call    _suser
F002756C: e2022024                 ld      [%o0+0x24], %l1
F0027570: 80a22000                 cmp     %o0, 0
F0027574: 02800016                 be      locret_F00275CC
F0027578: a41421dc                 or      %l0, %lo(dword_F0133DDC), %l2
F002757C: d0044000                 ld      [%l1], %o0
F0027580: 40000015                 call    _chdirec
F0027584: 9207bff4                 add     %fp, var_C, %o1
F0027588: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F002758C: d02a6038                 stb     %o0, [%o1+0x38]
F0027590: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0027594: d04a2038                 ldsb    [%o0+0x38], %o0
F0027598: 80a22000                 cmp     %o0, 0
F002759C: 1280000c                 bne     locret_F00275CC
F00275A0: 01000000                 nop
F00275A4: d004bffc                 ld      [%l2-4], %o0
F00275A8: d0022160                 ld      [%o0+0x160], %o0
F00275AC: 80a22000                 cmp     %o0, 0
F00275B0: 22800005                 be,a    loc_F00275C4
F00275B4: d204bffc                 ld      [%l2-4], %o1
F00275B8: 4000056b                 call    _vn_rele
F00275BC: 01000000                 nop
F00275C0: d204bffc                 ld      [%l2-4], %o1
F00275C4: d007bff4                 ld      [%fp+var_C], %o0
F00275C8: d0226160                 st      %o0, [%o1+0x160]
F00275CC: 81c7e008                 ret
F00275D0: 81e80000                 restore
