F000B848: 9de3bf98                 save    %sp, -0x68, %sp
F000B84C: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F000B850: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F000B854: d0022024                 ld      [%o0+0x24], %o0! __file
F000B858: 40000006                 call    _execve
F000B85C: c0222008                 clr     [%o0+8]
F000B860: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F000B864: d02a6038                 stb     %o0, [%o1+0x38]
F000B868: 81c7e008                 ret
F000B86C: 81e80000                 restore
