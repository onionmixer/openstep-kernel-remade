F007D318: 9de3bf98                 save    %sp, -0x68, %sp
F007D31C: d0062004                 ld      [%i0+4], %o0
F007D320: 80a22018                 cmp     %o0, 0x18
F007D324: 12800006                 bne     loc_F007D33C
F007D328: 90103ed0                 mov     -0x130, %o0
F007D32C: d0060000                 ld      [%i0], %o0
F007D330: 80a22000                 cmp     %o0, 0
F007D334: 16800004                 bge     loc_F007D344
F007D338: 90103ed0                 mov     -0x130, %o0
F007D33C: 1080000e                 ba      locret_F007D374
F007D340: d026601c                 st      %o0, [%i1+0x1C]
F007D344: 7fff9fd2                 call    _convert_port_to_host
F007D348: d0062008                 ld      [%i0+8], %o0
F007D34C: 7fffb1ea                 call    _host_get_time
F007D350: 92066024                 add     %i1, 0x24, %o1 ! '$'
F007D354: 80a22000                 cmp     %o0, 0
F007D358: 12800007                 bne     locret_F007D374
F007D35C: d026601c                 st      %o0, [%i1+0x1C]
F007D360: 9010202c                 mov     0x2C, %o0 ! ','
F007D364: d0266004                 st      %o0, [%i1+4]
F007D368: 113c0444                 sethi   %hi(dword_F0111134), %o0
F007D36C: d0022134                 ld      [%o0+%lo(dword_F0111134)], %o0
F007D370: d0266020                 st      %o0, [%i1+0x20]
F007D374: 81c7e008                 ret
F007D378: 81e80000                 restore
