F00E4178: 9de3bf98                 save    %sp, -0x68, %sp
F00E417C: d2062004                 ld      [%i0+4], %o1
F00E4180: 80a26018                 cmp     %o1, 0x18
F00E4184: 12800005                 bne     loc_F00E4198
F00E4188: d00e2003                 ldub    [%i0+3], %o0
F00E418C: 80a22001                 cmp     %o0, 1
F00E4190: 02800005                 be      loc_F00E41A4
F00E4194: 01000000                 nop
F00E4198: 90103ed0                 mov     -0x130, %o0
F00E419C: 10800014                 ba      locret_F00E41EC
F00E41A0: d026601c                 st      %o0, [%i1+0x1C]
F00E41A4: 7fffe797                 call    _audio_port_to_stream
F00E41A8: d006200c                 ld      [%i0+0xC], %o0
F00E41AC: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00E41B0: 7fffea76                 call    __NXAudioGetStreamPeak
F00E41B4: 9406602c                 add     %i1, 0x2C, %o2 ! ','
F00E41B8: 80a22000                 cmp     %o0, 0
F00E41BC: 1280000c                 bne     locret_F00E41EC
F00E41C0: d026601c                 st      %o0, [%i1+0x1C]
F00E41C4: 92102030                 mov     0x30, %o1 ! '0'
F00E41C8: 90102001                 mov     1, %o0
F00E41CC: d02e6003                 stb     %o0, [%i1+3]
F00E41D0: d2266004                 st      %o1, [%i1+4]
F00E41D4: 113c03e6                 sethi   %hi(dword_F00F9B10), %o0
F00E41D8: d2022310                 ld      [%o0+%lo(dword_F00F9B10)], %o1
F00E41DC: 113c03e6                 sethi   %hi(dword_F00F9B14), %o0
F00E41E0: d0022314                 ld      [%o0+%lo(dword_F00F9B14)], %o0
F00E41E4: d2266020                 st      %o1, [%i1+0x20]
F00E41E8: d0266028                 st      %o0, [%i1+0x28]
F00E41EC: 81c7e008                 ret
F00E41F0: 81e80000                 restore
