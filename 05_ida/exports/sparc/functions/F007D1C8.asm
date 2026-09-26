F007D1C8: 9de3bf98                 save    %sp, -0x68, %sp
F007D1CC: d0062004                 ld      [%i0+4], %o0
F007D1D0: 80a22018                 cmp     %o0, 0x18
F007D1D4: 12800007                 bne     loc_F007D1F0
F007D1D8: 90103ed0                 mov     -0x130, %o0
F007D1DC: d0060000                 ld      [%i0], %o0
F007D1E0: 80a22000                 cmp     %o0, 0
F007D1E4: 16800005                 bge     loc_F007D1F8
F007D1E8: 01000000                 nop
F007D1EC: 90103ed0                 mov     -0x130, %o0
F007D1F0: 10800009                 ba      locret_F007D214
F007D1F4: d026601c                 st      %o0, [%i1+0x1C]
F007D1F8: 7fffaa21                 call    _convert_port_to_thread
F007D1FC: d0062008                 ld      [%i0+8], %o0! thread
F007D200: 7fffd655                 call    _thread_depress_abort
F007D204: a0100008                 mov     %o0, %l0
F007D208: d026601c                 st      %o0, [%i1+0x1C]
F007D20C: 7fffdc68                 call    _thread_deallocate
F007D210: 90100010                 mov     %l0, %o0
F007D214: 81c7e008                 ret
F007D218: 81e80000                 restore
