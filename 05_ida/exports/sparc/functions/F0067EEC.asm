F0067EEC: 9de3bf90                 save    %sp, -0x70, %sp
F0067EF0: 80a66042                 cmp     %i1, 0x42 ! 'B'
F0067EF4: 1280000a                 bne     locret_F0067F1C
F0067EF8: 90100018                 mov     %i0, %o0! task
F0067EFC: 92102002                 mov     2, %o1! which_port
F0067F00: 7ffffd12                 call    _task_get_special_port
F0067F04: 9407bff4                 add     %fp, var_C, %o2
F0067F08: 80a22000                 cmp     %o0, 0
F0067F0C: 12800004                 bne     locret_F0067F1C
F0067F10: d007bff4                 ld      [%fp+var_C], %o0
F0067F14: 7fffc568                 call    _ipc_notify_msg_accepted_compat
F0067F18: 9210001a                 mov     %i2, %o1
F0067F1C: 81c7e008                 ret
F0067F20: 81e80000                 restore
