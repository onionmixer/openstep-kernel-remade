F00E3E64: 9de3bf98                 save    %sp, -0x68, %sp
F00E3E68: d2062004                 ld      [%i0+4], %o1
F00E3E6C: 80a26018                 cmp     %o1, 0x18
F00E3E70: 12800005                 bne     loc_F00E3E84
F00E3E74: d00e2003                 ldub    [%i0+3], %o0
F00E3E78: 80a22001                 cmp     %o0, 1
F00E3E7C: 02800005                 be      loc_F00E3E90
F00E3E80: 01000000                 nop
F00E3E84: 90103ed0                 mov     -0x130, %o0
F00E3E88: 10800014                 ba      locret_F00E3ED8
F00E3E8C: d026601c                 st      %o0, [%i1+0x1C]
F00E3E90: 7fffe85c                 call    _audio_port_to_stream
F00E3E94: d006200c                 ld      [%i0+0xC], %o0
F00E3E98: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00E3E9C: 7fffeaac                 call    __NXAudioStreamInfo
F00E3EA0: 9406602c                 add     %i1, 0x2C, %o2 ! ','
F00E3EA4: 80a22000                 cmp     %o0, 0
F00E3EA8: 1280000c                 bne     locret_F00E3ED8
F00E3EAC: d026601c                 st      %o0, [%i1+0x1C]
F00E3EB0: 92102030                 mov     0x30, %o1 ! '0'
F00E3EB4: 90102001                 mov     1, %o0
F00E3EB8: d02e6003                 stb     %o0, [%i1+3]
F00E3EBC: d2266004                 st      %o1, [%i1+4]
F00E3EC0: 113c03e6                 sethi   %hi(dword_F00F9ADC), %o0
F00E3EC4: d20222dc                 ld      [%o0+%lo(dword_F00F9ADC)], %o1
F00E3EC8: 113c03e6                 sethi   %hi(dword_F00F9AE0), %o0
F00E3ECC: d00222e0                 ld      [%o0+%lo(dword_F00F9AE0)], %o0
F00E3ED0: d2266020                 st      %o1, [%i1+0x20]
F00E3ED4: d0266028                 st      %o0, [%i1+0x28]
F00E3ED8: 81c7e008                 ret
F00E3EDC: 81e80000                 restore
