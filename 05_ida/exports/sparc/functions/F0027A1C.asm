F0027A1C: 9de3bf98                 save    %sp, -0x68, %sp
F0027A20: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0027A24: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0027A28: d2022024                 ld      [%o0+0x24], %o1
F0027A2C: d0024000                 ld      [%o1], %o0
F0027A30: d2026004                 ld      [%o1+4], %o1
F0027A34: 400005a0                 call    _vn_link
F0027A38: 94102000                 mov     0, %o2
F0027A3C: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0027A40: d02a6038                 stb     %o0, [%o1+0x38]
F0027A44: 81c7e008                 ret
F0027A48: 81e80000                 restore
