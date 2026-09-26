F00E3AF0: 9de3bf98                 save    %sp, -0x68, %sp
F00E3AF4: d2062004                 ld      [%i0+4], %o1
F00E3AF8: 80a26028                 cmp     %o1, 0x28 ! '('
F00E3AFC: 12800005                 bne     loc_F00E3B10
F00E3B00: d00e2003                 ldub    [%i0+3], %o0
F00E3B04: 80a22000                 cmp     %o0, 0
F00E3B08: 22800005                 be,a    loc_F00E3B1C
F00E3B0C: d0062018                 ld      [%i0+0x18], %o0
F00E3B10: 90103ed0                 mov     -0x130, %o0
F00E3B14: 1080001a                 ba      locret_F00E3B7C
F00E3B18: d026601c                 st      %o0, [%i1+0x1C]
F00E3B1C: 133c03e6                 sethi   %hi(dword_F00F9AAC), %o1
F00E3B20: d20262ac                 ld      [%o1+%lo(dword_F00F9AAC)], %o1
F00E3B24: 80a20009                 cmp     %o0, %o1
F00E3B28: 1280000d                 bne     loc_F00E3B5C
F00E3B2C: 90103ed0                 mov     -0x130, %o0
F00E3B30: d0062020                 ld      [%i0+0x20], %o0
F00E3B34: 133c03e6                 sethi   %hi(dword_F00F9AB0), %o1
F00E3B38: d20262b0                 ld      [%o1+%lo(dword_F00F9AB0)], %o1
F00E3B3C: 80a20009                 cmp     %o0, %o1
F00E3B40: 12800007                 bne     loc_F00E3B5C
F00E3B44: 90103ed0                 mov     -0x130, %o0
F00E3B48: 7fffe91e                 call    _audio_port_to_device
F00E3B4C: d006200c                 ld      [%i0+0xC], %o0
F00E3B50: d206201c                 ld      [%i0+0x1C], %o1
F00E3B54: 7fffea74                 call    __NXAudioSetSndoutOptions
F00E3B58: d4062024                 ld      [%i0+0x24], %o2
F00E3B5C: d026601c                 st      %o0, [%i1+0x1C]
F00E3B60: d006601c                 ld      [%i1+0x1C], %o0
F00E3B64: 80a22000                 cmp     %o0, 0
F00E3B68: 12800005                 bne     locret_F00E3B7C
F00E3B6C: 92102020                 mov     0x20, %o1 ! ' '
F00E3B70: 90102001                 mov     1, %o0
F00E3B74: d02e6003                 stb     %o0, [%i1+3]
F00E3B78: d2266004                 st      %o1, [%i1+4]
F00E3B7C: 81c7e008                 ret
F00E3B80: 81e80000                 restore
