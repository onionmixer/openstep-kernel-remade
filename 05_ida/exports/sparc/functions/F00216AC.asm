F00216AC: 9de3bf00                 save    %sp, -0x100, %sp! int
F00216B0: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F00216B4: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F00216B8: a607bfe0                 add     %fp, var_20, %l3
F00216BC: e0022024                 ld      [%o0+0x24], %l0
F00216C0: 92100013                 mov     %l3, %o1! int
F00216C4: d0042004                 ld      [%l0+4], %o0! int
F00216C8: 4001da64                 call    _copyin
F00216CC: 94102018                 mov     0x18, %o2
F00216D0: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F00216D4: d02a6038                 stb     %o0, [%o1+0x38]
F00216D8: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F00216DC: d04a6038                 ldsb    [%o1+0x38], %o0
F00216E0: 80a22000                 cmp     %o0, 0
F00216E4: 12800018                 bne     locret_F0021744
F00216E8: d407bfec                 ld      [%fp+var_14], %o2! int
F00216EC: 80a2a00f                 cmp     %o2, 0xF
F00216F0: 08800004                 bleu    loc_F0021700
F00216F4: 90102028                 mov     0x28, %o0 ! '('
F00216F8: 10800013                 ba      locret_F0021744
F00216FC: d02a6038                 stb     %o0, [%o1+0x38]
F0021700: a207bf60                 add     %fp, var_A0, %l1
F0021704: 92100011                 mov     %l1, %o1! int
F0021708: d007bfe8                 ld      [%fp+var_18], %o0! int
F002170C: 4001da53                 call    _copyin
F0021710: 952aa003                 sll     %o2, 3, %o2
F0021714: d204a1dc                 ld      [%l2+0x1DC], %o1
F0021718: d02a6038                 stb     %o0, [%o1+0x38]
F002171C: d004a1dc                 ld      [%l2+0x1DC], %o0
F0021720: d04a2038                 ldsb    [%o0+0x38], %o0
F0021724: 80a22000                 cmp     %o0, 0
F0021728: 12800007                 bne     locret_F0021744
F002172C: 01000000                 nop
F0021730: e227bfe8                 st      %l1, [%fp+var_18]
F0021734: d0040000                 ld      [%l0], %o0
F0021738: d4042008                 ld      [%l0+8], %o2
F002173C: 40000004                 call    _sendit
F0021740: 92100013                 mov     %l3, %o1
F0021744: 81c7e008                 ret
F0021748: 81e80000                 restore
