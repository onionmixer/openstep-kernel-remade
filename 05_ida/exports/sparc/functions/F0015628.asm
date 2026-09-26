F0015628: 9de3bf00                 save    %sp, -0x100, %sp! int
F001562C: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0015630: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0015634: d6026024                 ld      [%o1+0x24], %o3! int
F0015638: d002e008                 ld      [%o3+8], %o0
F001563C: 80a22010                 cmp     %o0, 0x10
F0015640: 08800004                 bleu    loc_F0015650
F0015644: 90102016                 mov     0x16, %o0
F0015648: 10800013                 ba      locret_F0015694
F001564C: d02a6038                 stb     %o0, [%o1+0x38]
F0015650: 9207bf60                 add     %fp, var_A0, %o1! int
F0015654: d227bfe0                 st      %o1, [%fp+var_20]
F0015658: d002e008                 ld      [%o3+8], %o0
F001565C: d027bfe4                 st      %o0, [%fp+var_1C]
F0015660: d402e008                 ld      [%o3+8], %o2! int
F0015664: d002e004                 ld      [%o3+4], %o0! int
F0015668: 40020a7c                 call    _copyin
F001566C: 952aa003                 sll     %o2, 3, %o2
F0015670: d20421dc                 ld      [%l0+0x1DC], %o1
F0015674: d02a6038                 stb     %o0, [%o1+0x38]
F0015678: d00421dc                 ld      [%l0+0x1DC], %o0
F001567C: d04a2038                 ldsb    [%o0+0x38], %o0
F0015680: 80a22000                 cmp     %o0, 0
F0015684: 12800004                 bne     locret_F0015694
F0015688: 9007bfe0                 add     %fp, var_20, %o0
F001568C: 40000004                 call    _rwuio
F0015690: 92102001                 mov     1, %o1
F0015694: 81c7e008                 ret
F0015698: 81e80000                 restore
