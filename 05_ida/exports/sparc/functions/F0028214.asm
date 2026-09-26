F0028214: 9de3bf98                 save    %sp, -0x68, %sp
F0028218: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F002821C: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0028220: d0022024                 ld      [%o0+0x24], %o0
F0028224: 40000010                 call    _stat1
F0028228: 92102001                 mov     1, %o1
F002822C: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0028230: d02a6038                 stb     %o0, [%o1+0x38]
F0028234: 81c7e008                 ret
F0028238: 81e80000                 restore
