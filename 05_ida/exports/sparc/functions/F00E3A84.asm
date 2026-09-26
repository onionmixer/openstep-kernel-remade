F00E3A84: 9de3bf98                 save    %sp, -0x68, %sp
F00E3A88: d2062004                 ld      [%i0+4], %o1
F00E3A8C: 80a26018                 cmp     %o1, 0x18
F00E3A90: 12800005                 bne     loc_F00E3AA4
F00E3A94: d00e2003                 ldub    [%i0+3], %o0
F00E3A98: 80a22001                 cmp     %o0, 1
F00E3A9C: 02800005                 be      loc_F00E3AB0
F00E3AA0: 01000000                 nop
F00E3AA4: 90103ed0                 mov     -0x130, %o0
F00E3AA8: 10800010                 ba      locret_F00E3AE8
F00E3AAC: d026601c                 st      %o0, [%i1+0x1C]
F00E3AB0: 7fffe944                 call    _audio_port_to_device
F00E3AB4: d006200c                 ld      [%i0+0xC], %o0
F00E3AB8: 7fffea56                 call    __NXAudioGetSndoutOptions
F00E3ABC: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00E3AC0: 80a22000                 cmp     %o0, 0
F00E3AC4: 12800009                 bne     locret_F00E3AE8
F00E3AC8: d026601c                 st      %o0, [%i1+0x1C]
F00E3ACC: 92102028                 mov     0x28, %o1 ! '('
F00E3AD0: 90102001                 mov     1, %o0
F00E3AD4: d02e6003                 stb     %o0, [%i1+3]
F00E3AD8: 113c03e6                 sethi   %hi(dword_F00F9AA8), %o0
F00E3ADC: d00222a8                 ld      [%o0+%lo(dword_F00F9AA8)], %o0
F00E3AE0: d2266004                 st      %o1, [%i1+4]
F00E3AE4: d0266020                 st      %o0, [%i1+0x20]
F00E3AE8: 81c7e008                 ret
F00E3AEC: 81e80000                 restore
