F00E3D44: 9de3bf98                 save    %sp, -0x68, %sp
F00E3D48: d2062004                 ld      [%i0+4], %o1
F00E3D4C: 80a26020                 cmp     %o1, 0x20 ! ' '
F00E3D50: 12800005                 bne     loc_F00E3D64
F00E3D54: d00e2003                 ldub    [%i0+3], %o0
F00E3D58: 80a22000                 cmp     %o0, 0
F00E3D5C: 22800005                 be,a    loc_F00E3D70
F00E3D60: d0062018                 ld      [%i0+0x18], %o0
F00E3D64: 90103ed0                 mov     -0x130, %o0
F00E3D68: 10800013                 ba      locret_F00E3DB4
F00E3D6C: d026601c                 st      %o0, [%i1+0x1C]
F00E3D70: 133c03e6                 sethi   %hi(dword_F00F9AD0), %o1
F00E3D74: d20262d0                 ld      [%o1+%lo(dword_F00F9AD0)], %o1
F00E3D78: 80a20009                 cmp     %o0, %o1
F00E3D7C: 12800006                 bne     loc_F00E3D94
F00E3D80: 90103ed0                 mov     -0x130, %o0
F00E3D84: 7fffe89f                 call    _audio_port_to_stream
F00E3D88: d006200c                 ld      [%i0+0xC], %o0
F00E3D8C: 7fffeaa2                 call    __NXAudioChangeStreamOwner
F00E3D90: d206201c                 ld      [%i0+0x1C], %o1
F00E3D94: d026601c                 st      %o0, [%i1+0x1C]
F00E3D98: d006601c                 ld      [%i1+0x1C], %o0
F00E3D9C: 80a22000                 cmp     %o0, 0
F00E3DA0: 12800005                 bne     locret_F00E3DB4
F00E3DA4: 92102020                 mov     0x20, %o1 ! ' '
F00E3DA8: 90102001                 mov     1, %o0
F00E3DAC: d02e6003                 stb     %o0, [%i1+3]
F00E3DB0: d2266004                 st      %o1, [%i1+4]
F00E3DB4: 81c7e008                 ret
F00E3DB8: 81e80000                 restore
