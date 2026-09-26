F0013A54: 9de3bf58                 save    %sp, -0xA8, %sp
F0013A58: 7fffefc5                 call    _suser
F0013A5C: c02fbfb8                 clrb    [%fp+var_48]
F0013A60: 80a22000                 cmp     %o0, 0
F0013A64: 02800018                 be      locret_F0013AC4
F0013A68: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0013A6C: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0013A70: d6022024                 ld      [%o0+0x24], %o3
F0013A74: d202c000                 ld      [%o3], %o1
F0013A78: 11000400                 sethi   0x100000, %o0
F0013A7C: 808a4008                 btst    %o0, %o1
F0013A80: 02800008                 be      loc_F0013AA0
F0013A84: 9207bfb8                 add     %fp, var_48, %o1
F0013A88: d002e004                 ld      [%o3+4], %o0
F0013A8C: 94102040                 mov     0x40, %o2 ! '@'
F0013A90: 400210a5                 call    _copyinstr
F0013A94: 96102000                 mov     0, %o3
F0013A98: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0013A9C: d02a6038                 stb     %o0, [%o1+0x38]
F0013AA0: d20421dc                 ld      [%l0+0x1DC], %o1
F0013AA4: d04a6038                 ldsb    [%o1+0x38], %o0
F0013AA8: 80a22000                 cmp     %o0, 0
F0013AAC: 12800006                 bne     locret_F0013AC4
F0013AB0: 90102001                 mov     1, %o0
F0013AB4: d2026024                 ld      [%o1+0x24], %o1
F0013AB8: d2024000                 ld      [%o1], %o1
F0013ABC: 7ffff272                 call    _boot
F0013AC0: 9407bfb8                 add     %fp, var_48, %o2
F0013AC4: 81c7e008                 ret
F0013AC8: 81e80000                 restore
