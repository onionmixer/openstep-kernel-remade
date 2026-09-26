F00CA358: 9de3bf98                 save    %sp, -0x68, %sp
F00CA35C: d2060000                 ld      [%i0], %o1
F00CA360: 1101000090122010         set     0x4000010, %o0
F00CA368: 920a4008                 and     %o1, %o0, %o1
F00CA36C: 80a26010                 cmp     %o1, 0x10
F00CA370: 22800004                 be,a    loc_F00CA380
F00CA374: d006202c                 ld      [%i0+0x2C], %o0
F00CA378: 7fff0868                 call    __io_vm_task_self
F00CA37C: 9e03e008                 inc     8, %o7
F00CA380: 7fff0873                 call    __io_vm_task
F00CA384: d0022068                 ld      [%o0+0x68], %o0
F00CA388: 81c7e008                 ret
F00CA38C: 91e80008                 restore %g0, %o0, %o0
