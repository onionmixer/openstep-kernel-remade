F00E3CB0: 9de3bf98                 save    %sp, -0x68, %sp
F00E3CB4: d2062004                 ld      [%i0+4], %o1
F00E3CB8: 80a26028                 cmp     %o1, 0x28 ! '('
F00E3CBC: 12800005                 bne     loc_F00E3CD0
F00E3CC0: d00e2003                 ldub    [%i0+3], %o0
F00E3CC4: 80a22001                 cmp     %o0, 1
F00E3CC8: 22800005                 be,a    loc_F00E3CDC
F00E3CCC: d0062018                 ld      [%i0+0x18], %o0
F00E3CD0: 90103ed0                 mov     -0x130, %o0
F00E3CD4: 1080001a                 ba      locret_F00E3D3C
F00E3CD8: d026601c                 st      %o0, [%i1+0x1C]
F00E3CDC: 133c03e6                 sethi   %hi(dword_F00F9AC8), %o1
F00E3CE0: d20262c8                 ld      [%o1+%lo(dword_F00F9AC8)], %o1
F00E3CE4: 80a20009                 cmp     %o0, %o1
F00E3CE8: 1280000d                 bne     loc_F00E3D1C
F00E3CEC: 90103ed0                 mov     -0x130, %o0
F00E3CF0: d0062020                 ld      [%i0+0x20], %o0
F00E3CF4: 133c03e6                 sethi   %hi(dword_F00F9ACC), %o1
F00E3CF8: d20262cc                 ld      [%o1+%lo(dword_F00F9ACC)], %o1
F00E3CFC: 80a20009                 cmp     %o0, %o1
F00E3D00: 12800007                 bne     loc_F00E3D1C
F00E3D04: 90103ed0                 mov     -0x130, %o0
F00E3D08: 7fffe8be                 call    _audio_port_to_stream
F00E3D0C: d006200c                 ld      [%i0+0xC], %o0
F00E3D10: d206201c                 ld      [%i0+0x1C], %o1
F00E3D14: 7fffeaa3                 call    __NXAudioSetStreamGain
F00E3D18: d4062024                 ld      [%i0+0x24], %o2
F00E3D1C: d026601c                 st      %o0, [%i1+0x1C]
F00E3D20: d006601c                 ld      [%i1+0x1C], %o0
F00E3D24: 80a22000                 cmp     %o0, 0
F00E3D28: 12800005                 bne     locret_F00E3D3C
F00E3D2C: 92102020                 mov     0x20, %o1 ! ' '
F00E3D30: 90102001                 mov     1, %o0
F00E3D34: d02e6003                 stb     %o0, [%i1+3]
F00E3D38: d2266004                 st      %o1, [%i1+4]
F00E3D3C: 81c7e008                 ret
F00E3D40: 81e80000                 restore
