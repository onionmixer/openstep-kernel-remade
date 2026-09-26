F00E49A4: 9de3bf98                 save    %sp, -0x68, %sp
F00E49A8: d2062004                 ld      [%i0+4], %o1
F00E49AC: 80a26018                 cmp     %o1, 0x18
F00E49B0: 12800005                 bne     loc_F00E49C4
F00E49B4: d00e2003                 ldub    [%i0+3], %o0
F00E49B8: 80a22001                 cmp     %o0, 1
F00E49BC: 02800005                 be      loc_F00E49D0
F00E49C0: 01000000                 nop
F00E49C4: 90103ed0                 mov     -0x130, %o0
F00E49C8: 10800010                 ba      locret_F00E4A08
F00E49CC: d026601c                 st      %o0, [%i1+0x1C]
F00E49D0: 7fffe57c                 call    _audio_port_to_device
F00E49D4: d006200c                 ld      [%i0+0xC], %o0
F00E49D8: 7fffe9c3                 call    __NXAudioGetChannelCountLimit
F00E49DC: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00E49E0: 80a22000                 cmp     %o0, 0
F00E49E4: 12800009                 bne     locret_F00E4A08
F00E49E8: d026601c                 st      %o0, [%i1+0x1C]
F00E49EC: 92102028                 mov     0x28, %o1 ! '('
F00E49F0: 90102001                 mov     1, %o0
F00E49F4: d02e6003                 stb     %o0, [%i1+3]
F00E49F8: 113c03e6                 sethi   %hi(dword_F00F9B7C), %o0
F00E49FC: d002237c                 ld      [%o0+%lo(dword_F00F9B7C)], %o0
F00E4A00: d2266004                 st      %o1, [%i1+4]
F00E4A04: d0266020                 st      %o0, [%i1+0x20]
F00E4A08: 81c7e008                 ret
F00E4A0C: 81e80000                 restore
