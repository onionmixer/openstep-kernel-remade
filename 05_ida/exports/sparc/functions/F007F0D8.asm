F007F0D8: 9de3bf98                 save    %sp, -0x68, %sp
F007F0DC: d0062004                 ld      [%i0+4], %o0
F007F0E0: 80a22018                 cmp     %o0, 0x18
F007F0E4: 12800007                 bne     loc_F007F100
F007F0E8: 90103ed0                 mov     -0x130, %o0
F007F0EC: d0060000                 ld      [%i0], %o0
F007F0F0: 80a22000                 cmp     %o0, 0
F007F0F4: 16800005                 bge     loc_F007F108
F007F0F8: 01000000                 nop
F007F0FC: 90103ed0                 mov     -0x130, %o0
F007F100: 10800009                 ba      locret_F007F124
F007F104: d026601c                 st      %o0, [%i1+0x1C]
F007F108: 7fffa25d                 call    _convert_port_to_thread
F007F10C: d0062008                 ld      [%i0+8], %o0! target_act
F007F110: 7fffd8ea                 call    _thread_suspend
F007F114: a0100008                 mov     %o0, %l0
F007F118: d026601c                 st      %o0, [%i1+0x1C]
F007F11C: 7fffd4a4                 call    _thread_deallocate
F007F120: 90100010                 mov     %l0, %o0
F007F124: 81c7e008                 ret
F007F128: 81e80000                 restore
