F0081058: 9de3bf98                 save    %sp, -0x68, %sp
F008105C: 153c04c3                 sethi   %hi(dword_F0130F5C), %o2
F0081060: c022a35c                 clr     [%o2+%lo(dword_F0130F5C)]
F0081064: 113c04d2                 sethi   %hi(_ux_exception_port), %o0
F0081068: c02221e0                 clr     [%o0+%lo(_ux_exception_port)]
F008106C: 113c0442                 sethi   %hi(_kernel_task), %o0
F0081070: d0022250                 ld      [%o0+%lo(_kernel_task)], %o0
F0081074: 92102000                 mov     0, %o1
F0081078: 9412a35c                 bset    %lo(dword_F0130F5C), %o2
F008107C: 7fffc778                 call    _kernel_task_create
F0081080: a010000a                 mov     %o2, %l0
F0081084: 133c0203921262a4         set     sub_F0080EA4, %o1
F008108C: 7fffd26a                 call    _kernel_thread
F0081090: 94102000                 mov     0, %o2
F0081094: d0040000                 ld      [%l0], %o0
F0081098: 80a22000                 cmp     %o0, 0
F008109C: 12bffffe                 bne     loc_F0081094
F00810A0: 01000000                 nop
F00810A4: 40005781                 call    _simple_lock_try
F00810A8: 90100010                 mov     %l0, %o0
F00810AC: 80a22000                 cmp     %o0, 0
F00810B0: 02bffff9                 be      loc_F0081094
F00810B4: 133c04d2                 sethi   %hi(_ux_exception_port), %o1
F00810B8: d00261e0                 ld      [%o1+%lo(_ux_exception_port)], %o0
F00810BC: 80a22000                 cmp     %o0, 0
F00810C0: 12800007                 bne     loc_F00810DC
F00810C4: 901261e0                 or      %o1, %lo(_ux_exception_port), %o0
F00810C8: 133c04c39212635c         set     dword_F0130F5C, %o1
F00810D0: 7fffc03b                 call    _thread_sleep
F00810D4: 94102000                 mov     0, %o2
F00810D8: 30800003                 ba,a    locret_F00810E4
F00810DC: 113c04c3                 sethi   %hi(dword_F0130F5C), %o0
F00810E0: c022235c                 clr     [%o0+%lo(dword_F0130F5C)]
F00810E4: 81c7e008                 ret
F00810E8: 81e80000                 restore
