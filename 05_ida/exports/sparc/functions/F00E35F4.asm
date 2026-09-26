F00E35F4: 9de3bf98                 save    %sp, -0x68, %sp
F00E35F8: d2062004                 ld      [%i0+4], %o1
F00E35FC: 80a26018                 cmp     %o1, 0x18
F00E3600: 12800005                 bne     loc_F00E3614
F00E3604: d00e2003                 ldub    [%i0+3], %o0
F00E3608: 80a22001                 cmp     %o0, 1
F00E360C: 02800005                 be      loc_F00E3620
F00E3610: 01000000                 nop
F00E3614: 90103ed0                 mov     -0x130, %o0
F00E3618: 10800014                 ba      locret_F00E3668
F00E361C: d026601c                 st      %o0, [%i1+0x1C]
F00E3620: 7fffea68                 call    _audio_port_to_device
F00E3624: d006200c                 ld      [%i0+0xC], %o0
F00E3628: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00E362C: 7fffea9e                 call    __NXAudioGetBufferOptions
F00E3630: 9406602c                 add     %i1, 0x2C, %o2 ! ','
F00E3634: 80a22000                 cmp     %o0, 0
F00E3638: 1280000c                 bne     locret_F00E3668
F00E363C: d026601c                 st      %o0, [%i1+0x1C]
F00E3640: 92102030                 mov     0x30, %o1 ! '0'
F00E3644: 90102001                 mov     1, %o0
F00E3648: d02e6003                 stb     %o0, [%i1+3]
F00E364C: d2266004                 st      %o1, [%i1+4]
F00E3650: 113c03e6                 sethi   %hi(dword_F00F9A5C), %o0
F00E3654: d202225c                 ld      [%o0+%lo(dword_F00F9A5C)], %o1
F00E3658: 113c03e6                 sethi   %hi(dword_F00F9A60), %o0
F00E365C: d0022260                 ld      [%o0+%lo(dword_F00F9A60)], %o0
F00E3660: d2266020                 st      %o1, [%i1+0x20]
F00E3664: d0266028                 st      %o0, [%i1+0x28]
F00E3668: 81c7e008                 ret
F00E366C: 81e80000                 restore
