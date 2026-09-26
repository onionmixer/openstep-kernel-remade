F0031A74: 9de3bf90                 save    %sp, -0x70, %sp
F0031A78: 4000f2d6                 call    _microtime
F0031A7C: 9007bff0                 add     %fp, var_10, %o0
F0031A80: 13000054                 sethi   0x15000, %o1
F0031A84: d007bff0                 ld      [%fp+var_10], %o0! int
F0031A88: 7fff5388                 call    _rem
F0031A8C: 92126180                 bset    0x180, %o1
F0031A90: 921023e8                 mov     0x3E8, %o1! int
F0031A94: 94100008                 mov     %o0, %o2
F0031A98: b12aa005                 sll     %o2, 5, %i0
F0031A9C: b026000a                 sub     %i0, %o2, %i0
F0031AA0: b12e2002                 sll     %i0, 2, %i0
F0031AA4: b006000a                 add     %i0, %o2, %i0
F0031AA8: d607bff4                 ld      [%fp+var_C], %o3
F0031AAC: b12e2003                 sll     %i0, 3, %i0
F0031AB0: 7fff52d6                 call    _div
F0031AB4: 9010000b                 mov     %o3, %o0
F0031AB8: 81c7e008                 ret
F0031ABC: 91ee0008                 restore %i0, %o0, %o0
