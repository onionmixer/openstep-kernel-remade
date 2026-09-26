F007E200: 9de3bf98                 save    %sp, -0x68, %sp
F007E204: d0062004                 ld      [%i0+4], %o0
F007E208: 80a22018                 cmp     %o0, 0x18
F007E20C: 12800007                 bne     loc_F007E228
F007E210: 90103ed0                 mov     -0x130, %o0
F007E214: d0060000                 ld      [%i0], %o0
F007E218: 80a22000                 cmp     %o0, 0
F007E21C: 16800005                 bge     loc_F007E230
F007E220: 01000000                 nop
F007E224: 90103ed0                 mov     -0x130, %o0
F007E228: 10800009                 ba      locret_F007E24C
F007E22C: d026601c                 st      %o0, [%i1+0x1C]
F007E230: 7fffa5b1                 call    _convert_port_to_task
F007E234: d0062008                 ld      [%i0+8], %o0! target_task
F007E238: 7fffd3de                 call    _task_terminate
F007E23C: a0100008                 mov     %o0, %l0
F007E240: d026601c                 st      %o0, [%i1+0x1C]
F007E244: 7fffd399                 call    _task_deallocate
F007E248: 90100010                 mov     %l0, %o0
F007E24C: 81c7e008                 ret
F007E250: 81e80000                 restore
