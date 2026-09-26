F00122DC: 9de3bf98                 save    %sp, -0x68, %sp! int
F00122E0: 213c04cf901421dc         set     dword_F0133DDC, %o0
F00122E8: d0023ffc                 ld      [%o0-4], %o0
F00122EC: d20421dc                 ld      [%l0+0x1DC], %o1
F00122F0: d0020000                 ld      [%o0], %o0! int
F00122F4: d2026024                 ld      [%o1+0x24], %o1
F00122F8: 94102004                 mov     4, %o2! int
F00122FC: d2024000                 ld      [%o1], %o1! int
F0012300: 40021773                 call    _copyout
F0012304: 90022018                 inc     0x18, %o0
F0012308: d20421dc                 ld      [%l0+0x1DC], %o1
F001230C: d02a6038                 stb     %o0, [%o1+0x38]
F0012310: 81c7e008                 ret
F0012314: 81e80000                 restore
