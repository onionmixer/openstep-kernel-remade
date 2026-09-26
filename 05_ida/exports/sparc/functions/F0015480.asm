F0015480: 9de3bf98                 save    %sp, -0x68, %sp
F0015484: 133c04cf                 sethi   %hi(_active_u), %o1
F0015488: d00261d8                 ld      [%o1+%lo(_active_u)], %o0
F001548C: d0022060                 ld      [%o0+0x60], %o0
F0015490: 80a22001                 cmp     %o0, 1
F0015494: 02800005                 be      loc_F00154A8
F0015498: 921261d8                 bset    %lo(_active_u), %o1
F001549C: 80a22003                 cmp     %o0, 3
F00154A0: 12800006                 bne     loc_F00154B8
F00154A4: 90102005                 mov     5, %o0
F00154A8: d2026004                 ld      [%o1+4], %o1
F00154AC: 90102016                 mov     0x16, %o0
F00154B0: d02a6038                 stb     %o0, [%o1+0x38]
F00154B4: 90102005                 mov     5, %o0
F00154B8: 13000040                 sethi   0x10000, %o1
F00154BC: 40013a58                 call    _exception_from_kernel
F00154C0: 94102000                 mov     0, %o2
F00154C4: 81c7e008                 ret
F00154C8: 81e80000                 restore
