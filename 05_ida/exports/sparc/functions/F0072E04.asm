F0072E04: 9de3bf98                 save    %sp, -0x68, %sp
F0072E08: 9010208c                 mov     0x8C, %o0
F0072E0C: 13000046                 sethi   0x11800, %o1
F0072E10: 150000089412a300         set     0x2300, %o2! ledgersCnt
F0072E18: 193c0442                 sethi   %hi(aTasks), %o4! "tasks"
F0072E1C: 96102000                 mov     0, %o3! inherit_memory
F0072E20: 40001446                 call    _zinit
F0072E24: 98132258                 bset    %lo(aTasks), %o4! "tasks"
F0072E28: 133c04f2                 sethi   %hi(_task_zone), %o1
F0072E2C: d0226158                 st      %o0, [%o1+%lo(_task_zone)]
F0072E30: 90102000                 mov     0, %o0! target_task
F0072E34: 92102000                 mov     0, %o1! ledgers
F0072E38: 213c0442                 sethi   %hi(_kernel_task), %l0
F0072E3C: 40000027                 call    _task_create
F0072E40: 94142250                 or      %l0, %lo(_kernel_task), %o2
F0072E44: d2042250                 ld      [%l0+%lo(_kernel_task)], %o1
F0072E48: 90102001                 mov     1, %o0
F0072E4C: d022604c                 st      %o0, [%o1+0x4C]
F0072E50: d0226050                 st      %o0, [%o1+0x50]
F0072E54: 81c7e008                 ret
F0072E58: 81e80000                 restore
