F007EDAC: 9de3bf98                 save    %sp, -0x68, %sp
F007EDB0: d0062004                 ld      [%i0+4], %o0
F007EDB4: 80a22018                 cmp     %o0, 0x18
F007EDB8: 12800007                 bne     loc_F007EDD4
F007EDBC: 90103ed0                 mov     -0x130, %o0
F007EDC0: d0060000                 ld      [%i0], %o0
F007EDC4: 80a22000                 cmp     %o0, 0
F007EDC8: 16800005                 bge     loc_F007EDDC
F007EDCC: 01000000                 nop
F007EDD0: 90103ed0                 mov     -0x130, %o0
F007EDD4: 10800009                 ba      locret_F007EDF8
F007EDD8: d026601c                 st      %o0, [%i1+0x1C]
F007EDDC: 7fffa2c6                 call    _convert_port_to_task
F007EDE0: d0062008                 ld      [%i0+8], %o0! target_task
F007EDE4: 7fffd315                 call    _task_suspend
F007EDE8: a0100008                 mov     %o0, %l0
F007EDEC: d026601c                 st      %o0, [%i1+0x1C]
F007EDF0: 7fffd0ae                 call    _task_deallocate
F007EDF4: 90100010                 mov     %l0, %o0
F007EDF8: 81c7e008                 ret
F007EDFC: 81e80000                 restore
