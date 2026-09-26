F007C7E0: 9de3bf98                 save    %sp, -0x68, %sp
F007C7E4: d0062004                 ld      [%i0+4], %o0
F007C7E8: 80a22018                 cmp     %o0, 0x18
F007C7EC: 12800007                 bne     loc_F007C808
F007C7F0: 90103ed0                 mov     -0x130, %o0
F007C7F4: d0060000                 ld      [%i0], %o0
F007C7F8: 80a22000                 cmp     %o0, 0
F007C7FC: 16800005                 bge     loc_F007C810
F007C800: 01000000                 nop
F007C804: 90103ed0                 mov     -0x130, %o0
F007C808: 10800009                 ba      locret_F007C82C
F007C80C: d026601c                 st      %o0, [%i1+0x1C]
F007C810: 7fffac9b                 call    _convert_port_to_thread
F007C814: d0062008                 ld      [%i0+8], %o0! thread
F007C818: 7fffe4e3                 call    _thread_assign_default
F007C81C: a0100008                 mov     %o0, %l0
F007C820: d026601c                 st      %o0, [%i1+0x1C]
F007C824: 7fffdee2                 call    _thread_deallocate
F007C828: 90100010                 mov     %l0, %o0
F007C82C: 81c7e008                 ret
F007C830: 81e80000                 restore
