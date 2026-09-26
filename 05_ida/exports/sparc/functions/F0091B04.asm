F0091B04: 9de3bf98                 save    %sp, -0x68, %sp
F0091B08: d4062004                 ld      [%i0+4], %o2
F0091B0C: 80a2a023                 cmp     %o2, 0x23 ! '#'
F0091B10: 0880001e                 bleu    loc_F0091B88
F0091B14: 90103ed0                 mov     -0x130, %o0
F0091B18: d0060000                 ld      [%i0], %o0
F0091B1C: 80a22000                 cmp     %o0, 0
F0091B20: 36800004                 bge,a   loc_F0091B30
F0091B24: d0062018                 ld      [%i0+0x18], %o0
F0091B28: 10800018                 ba      loc_F0091B88
F0091B2C: 90103ed0                 mov     -0x130, %o0
F0091B30: 900a200c                 and     %o0, 0xC, %o0
F0091B34: 80a2200c                 cmp     %o0, 0xC
F0091B38: 12800014                 bne     loc_F0091B88
F0091B3C: 90103ed0                 mov     -0x130, %o0
F0091B40: d206201c                 ld      [%i0+0x1C], %o1
F0091B44: 1100020090122008         set     0x80008, %o0
F0091B4C: 80a24008                 cmp     %o1, %o0
F0091B50: 1280000e                 bne     loc_F0091B88
F0091B54: 90103ed0                 mov     -0x130, %o0
F0091B58: d0062020                 ld      [%i0+0x20], %o0
F0091B5C: 90022003                 inc     3, %o0
F0091B60: 900a3ffc                 and     %o0, -4, %o0
F0091B64: 90022024                 inc     0x24, %o0 ! '$'
F0091B68: 80a28008                 cmp     %o2, %o0
F0091B6C: 12800007                 bne     loc_F0091B88
F0091B70: 90103ed0                 mov     -0x130, %o0
F0091B74: 7fff4dc6                 call    _convert_port_to_host
F0091B78: d0062008                 ld      [%i0+8], %o0
F0091B7C: d4062020                 ld      [%i0+0x20], %o2
F0091B80: 7ffffc44                 call    _kern_IOUnloadDriver
F0091B84: 92062024                 add     %i0, 0x24, %o1 ! '$'
F0091B88: d026601c                 st      %o0, [%i1+0x1C]
F0091B8C: 81c7e008                 ret
F0091B90: 81e80000                 restore
