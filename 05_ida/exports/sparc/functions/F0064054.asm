F0064054: 9de3bf98                 save    %sp, -0x68, %sp
F0064058: 113c04d0                 sethi   %hi(_active_threads), %o0
F006405C: 10800004                 ba      loc_F006406C
F0064060: e0022260                 ld      [%o0+%lo(_active_threads)], %l0
F0064064: 4000442a                 call    _thread_halt_self
F0064068: 01000000                 nop
F006406C: d004218c                 ld      [%l0+0x18C], %o0! target_task
F0064070: 808a2003                 btst    3, %o0
F0064074: 12bffffc                 bne     loc_F0064064
F0064078: 01000000                 nop
F006407C: 40003c4d                 call    _task_terminate
F0064080: d004200c                 ld      [%l0+0xC], %o0
F0064084: 40004422                 call    _thread_halt_self
F0064088: 01000000                 nop
F006408C: 81c7e008                 ret
F0064090: 81e80000                 restore
