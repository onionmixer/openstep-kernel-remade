F007F12C: 9de3bf98                 save    %sp, -0x68, %sp
F007F130: d0062004                 ld      [%i0+4], %o0
F007F134: 80a22018                 cmp     %o0, 0x18
F007F138: 12800007                 bne     loc_F007F154
F007F13C: 90103ed0                 mov     -0x130, %o0
F007F140: d0060000                 ld      [%i0], %o0
F007F144: 80a22000                 cmp     %o0, 0
F007F148: 16800005                 bge     loc_F007F15C
F007F14C: 01000000                 nop
F007F150: 90103ed0                 mov     -0x130, %o0
F007F154: 10800009                 ba      locret_F007F178
F007F158: d026601c                 st      %o0, [%i1+0x1C]
F007F15C: 7fffa248                 call    _convert_port_to_thread
F007F160: d0062008                 ld      [%i0+8], %o0! target_act
F007F164: 7fffd90d                 call    _thread_resume
F007F168: a0100008                 mov     %o0, %l0
F007F16C: d026601c                 st      %o0, [%i1+0x1C]
F007F170: 7fffd48f                 call    _thread_deallocate
F007F174: 90100010                 mov     %l0, %o0
F007F178: 81c7e008                 ret
F007F17C: 81e80000                 restore
