F007F180: 9de3bf98                 save    %sp, -0x68, %sp
F007F184: d0062004                 ld      [%i0+4], %o0
F007F188: 80a22018                 cmp     %o0, 0x18
F007F18C: 12800007                 bne     loc_F007F1A8
F007F190: 90103ed0                 mov     -0x130, %o0
F007F194: d0060000                 ld      [%i0], %o0
F007F198: 80a22000                 cmp     %o0, 0
F007F19C: 16800005                 bge     loc_F007F1B0
F007F1A0: 01000000                 nop
F007F1A4: 90103ed0                 mov     -0x130, %o0
F007F1A8: 10800009                 ba      locret_F007F1CC
F007F1AC: d026601c                 st      %o0, [%i1+0x1C]
F007F1B0: 7fffa233                 call    _convert_port_to_thread
F007F1B4: d0062008                 ld      [%i0+8], %o0! target_act
F007F1B8: 7fffd9fd                 call    _thread_abort
F007F1BC: a0100008                 mov     %o0, %l0
F007F1C0: d026601c                 st      %o0, [%i1+0x1C]
F007F1C4: 7fffd47a                 call    _thread_deallocate
F007F1C8: 90100010                 mov     %l0, %o0
F007F1CC: 81c7e008                 ret
F007F1D0: 81e80000                 restore
