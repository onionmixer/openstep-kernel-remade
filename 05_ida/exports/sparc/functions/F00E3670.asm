F00E3670: 9de3bf98                 save    %sp, -0x68, %sp
F00E3674: d2062004                 ld      [%i0+4], %o1
F00E3678: 80a26030                 cmp     %o1, 0x30 ! '0'
F00E367C: 12800005                 bne     loc_F00E3690
F00E3680: d00e2003                 ldub    [%i0+3], %o0
F00E3684: 80a22000                 cmp     %o0, 0
F00E3688: 22800005                 be,a    loc_F00E369C
F00E368C: d0062018                 ld      [%i0+0x18], %o0
F00E3690: 90103ed0                 mov     -0x130, %o0
F00E3694: 10800021                 ba      locret_F00E3718
F00E3698: d026601c                 st      %o0, [%i1+0x1C]
F00E369C: 133c03e6                 sethi   %hi(dword_F00F9A64), %o1
F00E36A0: d2026264                 ld      [%o1+%lo(dword_F00F9A64)], %o1
F00E36A4: 80a20009                 cmp     %o0, %o1
F00E36A8: 12800014                 bne     loc_F00E36F8
F00E36AC: 90103ed0                 mov     -0x130, %o0
F00E36B0: d0062020                 ld      [%i0+0x20], %o0
F00E36B4: 133c03e6                 sethi   %hi(dword_F00F9A68), %o1
F00E36B8: d2026268                 ld      [%o1+%lo(dword_F00F9A68)], %o1
F00E36BC: 80a20009                 cmp     %o0, %o1
F00E36C0: 1280000e                 bne     loc_F00E36F8
F00E36C4: 90103ed0                 mov     -0x130, %o0
F00E36C8: d0062028                 ld      [%i0+0x28], %o0
F00E36CC: 133c03e6                 sethi   %hi(dword_F00F9A6C), %o1
F00E36D0: d202626c                 ld      [%o1+%lo(dword_F00F9A6C)], %o1
F00E36D4: 80a20009                 cmp     %o0, %o1
F00E36D8: 12800008                 bne     loc_F00E36F8
F00E36DC: 90103ed0                 mov     -0x130, %o0
F00E36E0: 7fffea38                 call    _audio_port_to_device
F00E36E4: d006200c                 ld      [%i0+0xC], %o0
F00E36E8: d206201c                 ld      [%i0+0x1C], %o1
F00E36EC: d4062024                 ld      [%i0+0x24], %o2
F00E36F0: 7fffea89                 call    __NXAudioSetBufferOptions
F00E36F4: d606202c                 ld      [%i0+0x2C], %o3
F00E36F8: d026601c                 st      %o0, [%i1+0x1C]
F00E36FC: d006601c                 ld      [%i1+0x1C], %o0
F00E3700: 80a22000                 cmp     %o0, 0
F00E3704: 12800005                 bne     locret_F00E3718
F00E3708: 92102020                 mov     0x20, %o1 ! ' '
F00E370C: 90102001                 mov     1, %o0
F00E3710: d02e6003                 stb     %o0, [%i1+3]
F00E3714: d2266004                 st      %o1, [%i1+4]
F00E3718: 81c7e008                 ret
F00E371C: 81e80000                 restore
