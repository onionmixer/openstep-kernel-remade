F00648E8: 9de3bf88                 save    %sp, -0x78, %sp
F00648EC: 92102000                 mov     0, %o1
F00648F0: 113c04d0                 sethi   %hi(_active_threads), %o0
F00648F4: 94103fff                 mov     -1, %o2
F00648F8: 9607bff4                 add     %fp, var_C, %o3
F00648FC: 1b3c0192                 sethi   %hi(_exception_raise_continue), %o5
F0064900: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0064904: 98102001                 mov     1, %o4
F0064908: d00220c4                 ld      [%o0+0xC4], %o0
F006490C: 9a1360e8                 bset    %lo(_exception_raise_continue), %o5
F0064910: d623a05c                 st      %o3, [%sp+0x78+var_1C]
F0064914: 9607bff0                 add     %fp, var_10, %o3
F0064918: d623a060                 st      %o3, [%sp+0x78+var_18]
F006491C: 90022040                 inc     0x40, %o0 ! '@'
F0064920: 7fffd066                 call    _ipc_mqueue_receive
F0064924: 96102000                 mov     0, %o3
F0064928: d207bff4                 ld      [%fp+var_C], %o1
F006492C: 40000004                 call    _exception_raise_continue_slow
F0064930: d407bff0                 ld      [%fp+var_10], %o2
F0064934: 81c7e008                 ret
F0064938: 81e80000                 restore
