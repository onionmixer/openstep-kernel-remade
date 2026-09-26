F007B360: 9de3bf90                 save    %sp, -0x70, %sp
F007B364: 92102000                 mov     0, %o1! child_act
F007B368: 113c0442                 sethi   %hi(_kernel_task), %o0
F007B36C: d0022250                 ld      [%o0+%lo(_kernel_task)], %o0! target_task
F007B370: 7fffdeda                 call    _task_create
F007B374: 9407bff4                 add     %fp, parent_task, %o2
F007B378: 7fffdf4c                 call    _task_deallocate
F007B37C: d007bff4                 ld      [%fp+parent_task], %o0
F007B380: d007bff4                 ld      [%fp+parent_task], %o0! parent_task
F007B384: 7fffe360                 call    _thread_create
F007B388: 9207bff0                 add     %fp, target_act, %o1
F007B38C: 7fffe408                 call    _thread_deallocate
F007B390: d007bff0                 ld      [%fp+target_act], %o0
F007B394: 133c01eb                 sethi   %hi(_notify_server_loop), %o1
F007B398: d007bff0                 ld      [%fp+target_act], %o0! target_act
F007B39C: 7fffe9a2                 call    _thread_start
F007B3A0: 921262e4                 bset    %lo(_notify_server_loop), %o1
F007B3A4: 7fffe87d                 call    _thread_resume
F007B3A8: d007bff0                 ld      [%fp+target_act], %o0
F007B3AC: 81c7e008                 ret
F007B3B0: 81e80000                 restore
