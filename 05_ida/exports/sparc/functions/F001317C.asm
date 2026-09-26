F001317C: 9de3bf80                 save    %sp, -0x80, %sp! int
F0013180: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F0013184: d40261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o2
F0013188: e002a024                 ld      [%o2+0x24], %l0
F001318C: d0040000                 ld      [%l0], %o0
F0013190: 80a22002                 cmp     %o0, 2
F0013194: 08800005                 bleu    loc_F00131A8
F0013198: a21261dc                 or      %o1, %lo(dword_F0133DDC), %l1
F001319C: 90102016                 mov     0x16, %o0
F00131A0: 1080003d                 ba      locret_F0013294
F00131A4: d02aa038                 stb     %o0, [%o2+0x38]
F00131A8: 40020e84                 call    _spltty
F00131AC: 01000000                 nop
F00131B0: d2040000                 ld      [%l0], %o1
F00131B4: 80a26000                 cmp     %o1, 0
F00131B8: 12800023                 bne     loc_F0013244
F00131BC: a4100008                 mov     %o0, %l2
F00131C0: 7fffff73                 call    _getthetime
F00131C4: 9007bfe0                 add     %fp, var_20, %o0
F00131C8: d0047ffc                 ld      [%l1-4], %o0
F00131CC: d2020000                 ld      [%o0], %o1
F00131D0: d0026054                 ld      [%o1+0x54], %o0
F00131D4: d027bfe8                 st      %o0, [%fp+var_18]
F00131D8: d0026058                 ld      [%o1+0x58], %o0
F00131DC: d027bfec                 st      %o0, [%fp+var_14]
F00131E0: d002605c                 ld      [%o1+0x5C], %o0
F00131E4: d027bff0                 st      %o0, [%fp+var_10]
F00131E8: d4026060                 ld      [%o1+0x60], %o2! int
F00131EC: 80a22000                 cmp     %o0, 0
F00131F0: 12800005                 bne     loc_F0013204
F00131F4: d427bff4                 st      %o2, [%fp+var_C]
F00131F8: 80a2a000                 cmp     %o2, 0
F00131FC: 0280001d                 be      loc_F0013270
F0013200: 01000000                 nop
F0013204: d207bfe0                 ld      [%fp+var_20], %o1
F0013208: 80a20009                 cmp     %o0, %o1
F001320C: 26800009                 bl,a    loc_F0013230
F0013210: c027bff4                 clr     [%fp+var_C]
F0013214: 12800009                 bne     loc_F0013238
F0013218: 9007bff0                 add     %fp, var_10, %o0
F001321C: d007bfe4                 ld      [%fp+var_1C], %o0
F0013220: 80a28008                 cmp     %o2, %o0
F0013224: 16800005                 bge     loc_F0013238
F0013228: 9007bff0                 add     %fp, var_10, %o0
F001322C: c027bff4                 clr     [%fp+var_C]
F0013230: 10800010                 ba      loc_F0013270
F0013234: c027bff0                 clr     [%fp+var_10]
F0013238: 4000011e                 call    _timevalsub
F001323C: 9207bfe0                 add     %fp, var_20, %o1
F0013240: 3080000c                 ba,a    loc_F0013270
F0013244: d0047ffc                 ld      [%l1-4], %o0
F0013248: 932a6004                 sll     %o1, 4, %o1
F001324C: 92024008                 add     %o1, %o0, %o1
F0013250: d00261fc                 ld      [%o1+0x1FC], %o0
F0013254: d027bfe8                 st      %o0, [%fp+var_18]
F0013258: d0026200                 ld      [%o1+0x200], %o0
F001325C: d027bfec                 st      %o0, [%fp+var_14]
F0013260: d0026204                 ld      [%o1+0x204], %o0
F0013264: d027bff0                 st      %o0, [%fp+var_10]
F0013268: d0026208                 ld      [%o1+0x208], %o0
F001326C: d027bff4                 st      %o0, [%fp+var_C]
F0013270: 40020ead                 call    _splx
F0013274: 90100012                 mov     %l2, %o0
F0013278: 9007bfe8                 add     %fp, var_18, %o0! int
F001327C: d2042004                 ld      [%l0+4], %o1! int
F0013280: 40021393                 call    _copyout
F0013284: 94102010                 mov     0x10, %o2
F0013288: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F001328C: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F0013290: d02a6038                 stb     %o0, [%o1+0x38]
F0013294: 81c7e008                 ret
F0013298: 81e80000                 restore
