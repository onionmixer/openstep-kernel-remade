F00BCA68: 9de3bf90                 save    %sp, -0x70, %sp
F00BCA6C: d0062114                 ld      [%i0+0x114], %o0
F00BCA70: 80a22003                 cmp     %o0, 3
F00BCA74: 0280000b                 be      loc_F00BCAA0
F00BCA78: 9210001a                 mov     %i2, %o1
F00BCA7C: 80a22002                 cmp     %o0, 2
F00BCA80: 32800009                 bne,a   locret_F00BCAA4
F00BCA84: b0102010                 mov     0x10, %i0
F00BCA88: d006210c                 ld      [%i0+0x10C], %o0
F00BCA8C: d4022010                 ld      [%o0+0x10], %o2
F00BCA90: 9fc28000                 call    %o2
F00BCA94: 01000000                 nop
F00BCA98: 10800003                 ba      locret_F00BCAA4
F00BCA9C: b0100008                 mov     %o0, %i0
F00BCAA0: b0102010                 mov     0x10, %i0
F00BCAA4: 81c7e008                 ret
F00BCAA8: 81e80000                 restore
