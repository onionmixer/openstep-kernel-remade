F00E4AE0: 9de3bf98                 save    %sp, -0x68, %sp
F00E4AE4: d4062004                 ld      [%i0+4], %o2
F00E4AE8: 9002bfe4                 add     %o2, -0x1C, %o0
F00E4AEC: 80a22400                 cmp     %o0, 0x400
F00E4AF0: 18800005                 bgu     loc_F00E4B04
F00E4AF4: d00e2003                 ldub    [%i0+3], %o0
F00E4AF8: 80a22001                 cmp     %o0, 1
F00E4AFC: 22800005                 be,a    loc_F00E4B10
F00E4B00: d6062018                 ld      [%i0+0x18], %o3
F00E4B04: 90103ed0                 mov     -0x130, %o0
F00E4B08: 10800024                 ba      locret_F00E4B98
F00E4B0C: d026601c                 st      %o0, [%i1+0x1C]
F00E4B10: 133fffc09212600c         set     -0xFFF4, %o1
F00E4B18: 1100880090122008         set     0x2200008, %o0
F00E4B20: 920ac009                 and     %o3, %o1, %o1
F00E4B24: 80a24008                 cmp     %o1, %o0
F00E4B28: 12800011                 bne     loc_F00E4B6C
F00E4B2C: 90103ed0                 mov     -0x130, %o0
F00E4B30: 9132e004                 srl     %o3, 4, %o0
F00E4B34: 900a2fff                 and     %o0, 0xFFF, %o0
F00E4B38: 912a2002                 sll     %o0, 2, %o0
F00E4B3C: 9002201c                 inc     0x1C, %o0
F00E4B40: 80a28008                 cmp     %o2, %o0
F00E4B44: 1280000a                 bne     loc_F00E4B6C
F00E4B48: 90103ed0                 mov     -0x130, %o0
F00E4B4C: 7fffe52d                 call    _audio_port_to_stream
F00E4B50: d006200c                 ld      [%i0+0xC], %o0
F00E4B54: 9206201c                 add     %i0, 0x1C, %o1
F00E4B58: d4062018                 ld      [%i0+0x18], %o2
F00E4B5C: 96066024                 add     %i1, 0x24, %o3 ! '$'
F00E4B60: 9532a004                 srl     %o2, 4, %o2
F00E4B64: 7fffe98a                 call    __NXAudioGetStreamParameters
F00E4B68: 940aafff                 and     %o2, 0xFFF, %o2
F00E4B6C: d026601c                 st      %o0, [%i1+0x1C]
F00E4B70: d006601c                 ld      [%i1+0x1C], %o0
F00E4B74: 80a22000                 cmp     %o0, 0
F00E4B78: 12800008                 bne     locret_F00E4B98
F00E4B7C: 94102424                 mov     0x424, %o2
F00E4B80: 90102001                 mov     1, %o0
F00E4B84: d02e6003                 stb     %o0, [%i1+3]
F00E4B88: 113c03e6                 sethi   %hi(dword_F00F9B84), %o0
F00E4B8C: d0022384                 ld      [%o0+%lo(dword_F00F9B84)], %o0
F00E4B90: d4266004                 st      %o2, [%i1+4]
F00E4B94: d0266020                 st      %o0, [%i1+0x20]
F00E4B98: 81c7e008                 ret
F00E4B9C: 81e80000                 restore
