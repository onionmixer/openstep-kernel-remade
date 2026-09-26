F00E3EE0: 9de3bf98                 save    %sp, -0x68, %sp
F00E3EE4: d2062004                 ld      [%i0+4], %o1
F00E3EE8: 80a26018                 cmp     %o1, 0x18
F00E3EEC: 12800005                 bne     loc_F00E3F00
F00E3EF0: d00e2003                 ldub    [%i0+3], %o0
F00E3EF4: 80a22001                 cmp     %o0, 1
F00E3EF8: 02800005                 be      loc_F00E3F0C
F00E3EFC: 01000000                 nop
F00E3F00: 90103ed0                 mov     -0x130, %o0
F00E3F04: 1080000d                 ba      locret_F00E3F38
F00E3F08: d026601c                 st      %o0, [%i1+0x1C]
F00E3F0C: 7fffe83d                 call    _audio_port_to_stream
F00E3F10: d006200c                 ld      [%i0+0xC], %o0
F00E3F14: 7fffea9c                 call    __NXAudioRemoveStream
F00E3F18: 01000000                 nop
F00E3F1C: 80a22000                 cmp     %o0, 0
F00E3F20: 12800006                 bne     locret_F00E3F38
F00E3F24: d026601c                 st      %o0, [%i1+0x1C]
F00E3F28: 92102020                 mov     0x20, %o1 ! ' '
F00E3F2C: 90102001                 mov     1, %o0
F00E3F30: d02e6003                 stb     %o0, [%i1+3]
F00E3F34: d2266004                 st      %o1, [%i1+4]
F00E3F38: 81c7e008                 ret
F00E3F3C: 81e80000                 restore
