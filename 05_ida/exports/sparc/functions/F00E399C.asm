F00E399C: 9de3bf98                 save    %sp, -0x68, %sp
F00E39A0: d2062004                 ld      [%i0+4], %o1
F00E39A4: 80a26018                 cmp     %o1, 0x18
F00E39A8: 12800005                 bne     loc_F00E39BC
F00E39AC: d00e2003                 ldub    [%i0+3], %o0
F00E39B0: 80a22001                 cmp     %o0, 1
F00E39B4: 02800005                 be      loc_F00E39C8
F00E39B8: 01000000                 nop
F00E39BC: 90103ed0                 mov     -0x130, %o0
F00E39C0: 10800014                 ba      locret_F00E3A10
F00E39C4: d026601c                 st      %o0, [%i1+0x1C]
F00E39C8: 7fffe97e                 call    _audio_port_to_device
F00E39CC: d006200c                 ld      [%i0+0xC], %o0
F00E39D0: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00E39D4: 7fffea67                 call    __NXAudioGetDevicePeak
F00E39D8: 9406602c                 add     %i1, 0x2C, %o2 ! ','
F00E39DC: 80a22000                 cmp     %o0, 0
F00E39E0: 1280000c                 bne     locret_F00E3A10
F00E39E4: d026601c                 st      %o0, [%i1+0x1C]
F00E39E8: 92102030                 mov     0x30, %o1 ! '0'
F00E39EC: 90102001                 mov     1, %o0
F00E39F0: d02e6003                 stb     %o0, [%i1+3]
F00E39F4: d2266004                 st      %o1, [%i1+4]
F00E39F8: 113c03e6                 sethi   %hi(dword_F00F9A9C), %o0
F00E39FC: d202229c                 ld      [%o0+%lo(dword_F00F9A9C)], %o1
F00E3A00: 113c03e6                 sethi   %hi(dword_F00F9AA0), %o0
F00E3A04: d00222a0                 ld      [%o0+%lo(dword_F00F9AA0)], %o0
F00E3A08: d2266020                 st      %o1, [%i1+0x20]
F00E3A0C: d0266028                 st      %o0, [%i1+0x28]
F00E3A10: 81c7e008                 ret
F00E3A14: 81e80000                 restore
