F00276D4: 9de3bf98                 save    %sp, -0x68, %sp
F00276D8: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F00276DC: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F00276E0: d2022024                 ld      [%o0+0x24], %o1
F00276E4: d0024000                 ld      [%o1], %o0
F00276E8: d4026004                 ld      [%o1+4], %o2
F00276EC: 40000006                 call    _copen
F00276F0: 92102602                 mov     0x602, %o1
F00276F4: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F00276F8: d02a6038                 stb     %o0, [%o1+0x38]
F00276FC: 81c7e008                 ret
F0027700: 81e80000                 restore
