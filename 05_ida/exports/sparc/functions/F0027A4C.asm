F0027A4C: 9de3bf98                 save    %sp, -0x68, %sp
F0027A50: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0027A54: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0027A58: d2022024                 ld      [%o0+0x24], %o1
F0027A5C: d0024000                 ld      [%o1], %o0
F0027A60: d2026004                 ld      [%o1+4], %o1
F0027A64: 400005d3                 call    _vn_rename
F0027A68: 94102000                 mov     0, %o2
F0027A6C: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0027A70: d02a6038                 stb     %o0, [%o1+0x38]
F0027A74: 81c7e008                 ret
F0027A78: 81e80000                 restore
