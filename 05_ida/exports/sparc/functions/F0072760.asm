F0072760: 9de3bf98                 save    %sp, -0x68, %sp
F0072764: 113c04d0                 sethi   %hi(_active_threads), %o0
F0072768: d2022260                 ld      [%o0+%lo(_active_threads)], %o1
F007276C: d0026064                 ld      [%o1+0x64], %o0
F0072770: 80a22000                 cmp     %o0, 0
F0072774: 06800005                 bl      loc_F0072788
F0072778: 113c04d2                 sethi   -0xFECB800, %o0! thread
F007277C: 400000f6                 call    _thread_depress_abort
F0072780: 90100009                 mov     %o1, %o0
F0072784: 113c04d2                 sethi   -0xFECB800, %o0
F0072788: d20221b0                 ld      [%o0+0x1B0], %o1
F007278C: d0026108                 ld      [%o1+0x108], %o0
F0072790: 80a22000                 cmp     %o0, 0
F0072794: 14800007                 bg      loc_F00727B0
F0072798: 94102000                 mov     0, %o2
F007279C: d002612c                 ld      [%o1+0x12C], %o0
F00727A0: d0022108                 ld      [%o0+0x108], %o0
F00727A4: 80a22000                 cmp     %o0, 0
F00727A8: 04800003                 ble     loc_F00727B4
F00727AC: 01000000                 nop
F00727B0: 94102001                 mov     1, %o2
F00727B4: 4000a616                 call    _thread_syscall_return
F00727B8: 9010000a                 mov     %o2, %o0
F00727BC: 81c7e008                 ret
F00727C0: 81e80000                 restore
