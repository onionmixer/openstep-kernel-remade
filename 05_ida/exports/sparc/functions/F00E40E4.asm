F00E40E4: 9de3bf98                 save    %sp, -0x68, %sp
F00E40E8: d2062004                 ld      [%i0+4], %o1
F00E40EC: 80a26028                 cmp     %o1, 0x28 ! '('
F00E40F0: 12800005                 bne     loc_F00E4104
F00E40F4: d00e2003                 ldub    [%i0+3], %o0
F00E40F8: 80a22001                 cmp     %o0, 1
F00E40FC: 22800005                 be,a    loc_F00E4110
F00E4100: d0062018                 ld      [%i0+0x18], %o0
F00E4104: 90103ed0                 mov     -0x130, %o0
F00E4108: 1080001a                 ba      locret_F00E4170
F00E410C: d026601c                 st      %o0, [%i1+0x1C]
F00E4110: 133c03e6                 sethi   %hi(dword_F00F9B08), %o1
F00E4114: d2026308                 ld      [%o1+%lo(dword_F00F9B08)], %o1
F00E4118: 80a20009                 cmp     %o0, %o1
F00E411C: 1280000d                 bne     loc_F00E4150
F00E4120: 90103ed0                 mov     -0x130, %o0
F00E4124: d0062020                 ld      [%i0+0x20], %o0
F00E4128: 133c03e6                 sethi   %hi(dword_F00F9B0C), %o1
F00E412C: d202630c                 ld      [%o1+%lo(dword_F00F9B0C)], %o1
F00E4130: 80a20009                 cmp     %o0, %o1
F00E4134: 12800007                 bne     loc_F00E4150
F00E4138: 90103ed0                 mov     -0x130, %o0
F00E413C: 7fffe7b1                 call    _audio_port_to_stream
F00E4140: d006200c                 ld      [%i0+0xC], %o0
F00E4144: d206201c                 ld      [%i0+0x1C], %o1
F00E4148: 7fffea7a                 call    __NXAudioSetStreamPeakOptions
F00E414C: d4062024                 ld      [%i0+0x24], %o2
F00E4150: d026601c                 st      %o0, [%i1+0x1C]
F00E4154: d006601c                 ld      [%i1+0x1C], %o0
F00E4158: 80a22000                 cmp     %o0, 0
F00E415C: 12800005                 bne     locret_F00E4170
F00E4160: 92102020                 mov     0x20, %o1 ! ' '
F00E4164: 90102001                 mov     1, %o0
F00E4168: d02e6003                 stb     %o0, [%i1+3]
F00E416C: d2266004                 st      %o1, [%i1+4]
F00E4170: 81c7e008                 ret
F00E4174: 81e80000                 restore
