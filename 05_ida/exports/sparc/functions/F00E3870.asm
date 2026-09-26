F00E3870: 9de3bf98                 save    %sp, -0x68, %sp
F00E3874: d2062004                 ld      [%i0+4], %o1
F00E3878: 80a26018                 cmp     %o1, 0x18
F00E387C: 12800005                 bne     loc_F00E3890
F00E3880: d00e2003                 ldub    [%i0+3], %o0
F00E3884: 80a22001                 cmp     %o0, 1
F00E3888: 02800005                 be      loc_F00E389C
F00E388C: 01000000                 nop
F00E3890: 90103ed0                 mov     -0x130, %o0
F00E3894: 10800014                 ba      locret_F00E38E4
F00E3898: d026601c                 st      %o0, [%i1+0x1C]
F00E389C: 7fffe9c9                 call    _audio_port_to_device
F00E38A0: d006200c                 ld      [%i0+0xC], %o0
F00E38A4: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00E38A8: 7fffea81                 call    __NXAudioGetDevicePeakOptions
F00E38AC: 9406602c                 add     %i1, 0x2C, %o2 ! ','
F00E38B0: 80a22000                 cmp     %o0, 0
F00E38B4: 1280000c                 bne     locret_F00E38E4
F00E38B8: d026601c                 st      %o0, [%i1+0x1C]
F00E38BC: 92102030                 mov     0x30, %o1 ! '0'
F00E38C0: 90102001                 mov     1, %o0
F00E38C4: d02e6003                 stb     %o0, [%i1+3]
F00E38C8: d2266004                 st      %o1, [%i1+4]
F00E38CC: 113c03e6                 sethi   %hi(dword_F00F9A88), %o0
F00E38D0: d2022288                 ld      [%o0+%lo(dword_F00F9A88)], %o1
F00E38D4: 113c03e6                 sethi   %hi(dword_F00F9A8C), %o0
F00E38D8: d002228c                 ld      [%o0+%lo(dword_F00F9A8C)], %o0
F00E38DC: d2266020                 st      %o1, [%i1+0x20]
F00E38E0: d0266028                 st      %o0, [%i1+0x28]
F00E38E4: 81c7e008                 ret
F00E38E8: 81e80000                 restore
