F00727C4: 9de3bf98                 save    %sp, -0x68, %sp
F00727C8: 113c04d0                 sethi   %hi(_active_threads), %o0
F00727CC: f0022260                 ld      [%o0+%lo(_active_threads)], %i0
F00727D0: 113c04f0                 sethi   %hi(_min_quantum), %o0
F00727D4: d2022290                 ld      [%o0+%lo(_min_quantum)], %o1
F00727D8: 4000009a                 call    _thread_depress_priority
F00727DC: 90100018                 mov     %i0, %o0
F00727E0: 113c01c9                 sethi   %hi(_swtch_pri_continue), %o0
F00727E4: 7ffffbd7                 call    _thread_block_with_continuation
F00727E8: 90122360                 bset    %lo(_swtch_pri_continue), %o0
F00727EC: d0062064                 ld      [%i0+0x64], %o0
F00727F0: 80a22000                 cmp     %o0, 0
F00727F4: 06800005                 bl      loc_F0072808
F00727F8: 113c04d2                 sethi   -0xFECB800, %o0! thread
F00727FC: 400000d6                 call    _thread_depress_abort
F0072800: 90100018                 mov     %i0, %o0
F0072804: 113c04d2                 sethi   -0xFECB800, %o0
F0072808: d20221b0                 ld      [%o0+0x1B0], %o1
F007280C: d0026108                 ld      [%o1+0x108], %o0
F0072810: 80a22000                 cmp     %o0, 0
F0072814: 14800007                 bg      loc_F0072830
F0072818: b0102000                 mov     0, %i0
F007281C: d002612c                 ld      [%o1+0x12C], %o0
F0072820: d0022108                 ld      [%o0+0x108], %o0
F0072824: 80a22000                 cmp     %o0, 0
F0072828: 04800003                 ble     locret_F0072834
F007282C: 01000000                 nop
F0072830: b0102001                 mov     1, %i0
F0072834: 81c7e008                 ret
F0072838: 81e80000                 restore
