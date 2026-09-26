F009BE0C: 9de3bf98                 save    %sp, -0x68, %sp
F009BE10: 113c04d0                 sethi   %hi(_active_threads), %o0
F009BE14: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F009BE18: 80a60008                 cmp     %i0, %o0
F009BE1C: 1280000c                 bne     locret_F009BE4C
F009BE20: e0062028                 ld      [%i0+0x28], %l0
F009BE24: 40002785                 call    _flush_user_windows_to_stack
F009BE28: 01000000                 nop
F009BE2C: d2042234                 ld      [%l0+0x234], %o1
F009BE30: 11000004                 sethi   0x1000, %o0
F009BE34: 808a4008                 btst    %o0, %o1
F009BE38: 02800005                 be      locret_F009BE4C
F009BE3C: 01000000                 nop
F009BE40: d0062028                 ld      [%i0+0x28], %o0
F009BE44: 7fffe512                 call    _fp_dumpregs
F009BE48: d0022284                 ld      [%o0+0x284], %o0
F009BE4C: 81c7e008                 ret
F009BE50: 81e80000                 restore
