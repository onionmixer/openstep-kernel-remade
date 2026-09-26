F007283C: 9de3bf98                 save    %sp, -0x68, %sp
F0072840: 113c04d0                 sethi   %hi(_active_threads), %o0
F0072844: d2022260                 ld      [%o0+%lo(_active_threads)], %o1
F0072848: d0026064                 ld      [%o1+0x64], %o0! thread
F007284C: 80a22000                 cmp     %o0, 0
F0072850: 06800004                 bl      loc_F0072860
F0072854: 01000000                 nop
F0072858: 400000bf                 call    _thread_depress_abort
F007285C: 90100009                 mov     %o1, %o0
F0072860: 4000a5eb                 call    _thread_syscall_return
F0072864: 90102000                 mov     0, %o0
F0072868: 81c7e008                 ret
F007286C: 81e80000                 restore
