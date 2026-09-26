F00E4A10: 9de3bf98                 save    %sp, -0x68, %sp
F00E4A14: d4062004                 ld      [%i0+4], %o2
F00E4A18: 9002bbe0                 add     %o2, -0x420, %o0
F00E4A1C: 80a22400                 cmp     %o0, 0x400
F00E4A20: 18800005                 bgu     loc_F00E4A34
F00E4A24: d00e2003                 ldub    [%i0+3], %o0
F00E4A28: 80a22001                 cmp     %o0, 1
F00E4A2C: 22800005                 be,a    loc_F00E4A40
F00E4A30: d6062018                 ld      [%i0+0x18], %o3
F00E4A34: 90103ed0                 mov     -0x130, %o0
F00E4A38: 10800028                 ba      locret_F00E4AD8
F00E4A3C: d026601c                 st      %o0, [%i1+0x1C]
F00E4A40: 133fffc09212600c         set     -0xFFF4, %o1
F00E4A48: 1100880090122008         set     0x2200008, %o0
F00E4A50: 920ac009                 and     %o3, %o1, %o1
F00E4A54: 80a24008                 cmp     %o1, %o0
F00E4A58: 12800018                 bne     loc_F00E4AB8
F00E4A5C: 90103ed0                 mov     -0x130, %o0
F00E4A60: 9132e004                 srl     %o3, 4, %o0
F00E4A64: 900a2fff                 and     %o0, 0xFFF, %o0
F00E4A68: 972a2002                 sll     %o0, 2, %o3
F00E4A6C: 9002e420                 add     %o3, 0x420, %o0
F00E4A70: 80a28008                 cmp     %o2, %o0
F00E4A74: 12800011                 bne     loc_F00E4AB8
F00E4A78: 90103ed0                 mov     -0x130, %o0
F00E4A7C: a006000b                 add     %i0, %o3, %l0
F00E4A80: d004201c                 ld      [%l0+0x1C], %o0
F00E4A84: 133c03e6                 sethi   %hi(dword_F00F9B80), %o1
F00E4A88: d2026380                 ld      [%o1+%lo(dword_F00F9B80)], %o1
F00E4A8C: 80a20009                 cmp     %o0, %o1
F00E4A90: 1280000a                 bne     loc_F00E4AB8
F00E4A94: 90103ed0                 mov     -0x130, %o0
F00E4A98: 7fffe55a                 call    _audio_port_to_stream
F00E4A9C: d006200c                 ld      [%i0+0xC], %o0
F00E4AA0: 9206201c                 add     %i0, 0x1C, %o1
F00E4AA4: d4062018                 ld      [%i0+0x18], %o2
F00E4AA8: 96042020                 add     %l0, 0x20, %o3 ! ' '
F00E4AAC: 9532a004                 srl     %o2, 4, %o2
F00E4AB0: 7fffe99e                 call    __NXAudioSetStreamParameters
F00E4AB4: 940aafff                 and     %o2, 0xFFF, %o2
F00E4AB8: d026601c                 st      %o0, [%i1+0x1C]
F00E4ABC: d006601c                 ld      [%i1+0x1C], %o0
F00E4AC0: 80a22000                 cmp     %o0, 0
F00E4AC4: 12800005                 bne     locret_F00E4AD8
F00E4AC8: 94102020                 mov     0x20, %o2 ! ' '
F00E4ACC: 90102001                 mov     1, %o0
F00E4AD0: d02e6003                 stb     %o0, [%i1+3]
F00E4AD4: d4266004                 st      %o2, [%i1+4]
F00E4AD8: 81c7e008                 ret
F00E4ADC: 81e80000                 restore
