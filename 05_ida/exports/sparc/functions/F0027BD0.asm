F0027BD0: 9de3bf98                 save    %sp, -0x68, %sp
F0027BD4: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0027BD8: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0027BDC: d0022024                 ld      [%o0+0x24], %o0
F0027BE0: 92102000                 mov     0, %o1
F0027BE4: d0020000                 ld      [%o0], %o0
F0027BE8: 400005ca                 call    _vn_remove
F0027BEC: 94102001                 mov     1, %o2
F0027BF0: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0027BF4: d02a6038                 stb     %o0, [%o1+0x38]
F0027BF8: 81c7e008                 ret
F0027BFC: 81e80000                 restore
