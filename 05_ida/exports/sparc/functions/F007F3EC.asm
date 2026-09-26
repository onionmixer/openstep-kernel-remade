F007F3EC: 9de3bf98                 save    %sp, -0x68, %sp
F007F3F0: d0062004                 ld      [%i0+4], %o0
F007F3F4: 80a22028                 cmp     %o0, 0x28 ! '('
F007F3F8: 12800014                 bne     loc_F007F448
F007F3FC: 90103ed0                 mov     -0x130, %o0
F007F400: d0060000                 ld      [%i0], %o0
F007F404: 80a22000                 cmp     %o0, 0
F007F408: 16800010                 bge     loc_F007F448
F007F40C: 90103ed0                 mov     -0x130, %o0
F007F410: d0062018                 ld      [%i0+0x18], %o0
F007F414: 133c0444                 sethi   %hi(dword_F01113F0), %o1
F007F418: d20263f0                 ld      [%o1+%lo(dword_F01113F0)], %o1
F007F41C: 80a20009                 cmp     %o0, %o1
F007F420: 1280000a                 bne     loc_F007F448
F007F424: 90103ed0                 mov     -0x130, %o0
F007F428: d2062020                 ld      [%i0+0x20], %o1
F007F42C: 1104480090122018         set     0x11200018, %o0
F007F434: 920a7ffc                 and     %o1, -4, %o1
F007F438: 80a24008                 cmp     %o1, %o0
F007F43C: 02800005                 be      loc_F007F450
F007F440: 01000000                 nop
F007F444: 90103ed0                 mov     -0x130, %o0
F007F448: 1080000b                 ba      locret_F007F474
F007F44C: d026601c                 st      %o0, [%i1+0x1C]
F007F450: 7fffa18b                 call    _convert_port_to_thread
F007F454: d0062008                 ld      [%i0+8], %o0! thr_act
F007F458: d206201c                 ld      [%i0+0x1C], %o1! which_port
F007F45C: a0100008                 mov     %o0, %l0
F007F460: 7fffa073                 call    _thread_set_special_port
F007F464: d4062024                 ld      [%i0+0x24], %o2
F007F468: d026601c                 st      %o0, [%i1+0x1C]
F007F46C: 7fffd3d0                 call    _thread_deallocate
F007F470: 90100010                 mov     %l0, %o0
F007F474: 81c7e008                 ret
F007F478: 81e80000                 restore
