F00138D4: 9de3bf98                 save    %sp, -0x68, %sp! int
F00138D8: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F00138DC: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F00138E0: d2022024                 ld      [%o0+0x24], %o1
F00138E4: 113c04d1                 sethi   %hi(_hostnamelen), %o0
F00138E8: d0022330                 ld      [%o0+%lo(_hostnamelen)], %o0
F00138EC: d4026004                 ld      [%o1+4], %o2
F00138F0: 90022001                 inc     %o0
F00138F4: 80a28008                 cmp     %o2, %o0
F00138F8: 38800002                 bgu,a   loc_F0013900
F00138FC: 94100008                 mov     %o0, %o2! int
F0013900: 113c04d1                 sethi   %hi(_hostname), %o0! int
F0013904: d2024000                 ld      [%o1], %o1! int
F0013908: 400211f1                 call    _copyout
F001390C: 90122230                 bset    %lo(_hostname), %o0
F0013910: d20421dc                 ld      [%l0+0x1DC], %o1
F0013914: d02a6038                 stb     %o0, [%o1+0x38]
F0013918: 81c7e008                 ret
F001391C: 81e80000                 restore
