F007EE00: 9de3bf98                 save    %sp, -0x68, %sp
F007EE04: d0062004                 ld      [%i0+4], %o0
F007EE08: 80a22018                 cmp     %o0, 0x18
F007EE0C: 12800007                 bne     loc_F007EE28
F007EE10: 90103ed0                 mov     -0x130, %o0
F007EE14: d0060000                 ld      [%i0], %o0
F007EE18: 80a22000                 cmp     %o0, 0
F007EE1C: 16800005                 bge     loc_F007EE30
F007EE20: 01000000                 nop
F007EE24: 90103ed0                 mov     -0x130, %o0
F007EE28: 10800009                 ba      locret_F007EE4C
F007EE2C: d026601c                 st      %o0, [%i1+0x1C]
F007EE30: 7fffa2b1                 call    _convert_port_to_task
F007EE34: d0062008                 ld      [%i0+8], %o0! target_task
F007EE38: 7fffd338                 call    _task_resume
F007EE3C: a0100008                 mov     %o0, %l0
F007EE40: d026601c                 st      %o0, [%i1+0x1C]
F007EE44: 7fffd099                 call    _task_deallocate
F007EE48: 90100010                 mov     %l0, %o0
F007EE4C: 81c7e008                 ret
F007EE50: 81e80000                 restore
