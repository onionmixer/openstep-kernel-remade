F00E3720: 9de3bf98                 save    %sp, -0x68, %sp
F00E3724: d2062004                 ld      [%i0+4], %o1
F00E3728: 80a26028                 cmp     %o1, 0x28 ! '('
F00E372C: 12800005                 bne     loc_F00E3740
F00E3730: d00e2003                 ldub    [%i0+3], %o0
F00E3734: 80a22000                 cmp     %o0, 0
F00E3738: 22800005                 be,a    loc_F00E374C
F00E373C: d0062018                 ld      [%i0+0x18], %o0
F00E3740: 90103ed0                 mov     -0x130, %o0
F00E3744: 1080001a                 ba      locret_F00E37AC
F00E3748: d026601c                 st      %o0, [%i1+0x1C]
F00E374C: 133c03e6                 sethi   %hi(dword_F00F9A70), %o1
F00E3750: d2026270                 ld      [%o1+%lo(dword_F00F9A70)], %o1
F00E3754: 80a20009                 cmp     %o0, %o1
F00E3758: 1280000d                 bne     loc_F00E378C
F00E375C: 90103ed0                 mov     -0x130, %o0
F00E3760: d0062020                 ld      [%i0+0x20], %o0
F00E3764: 133c03e6                 sethi   %hi(dword_F00F9A74), %o1
F00E3768: d2026274                 ld      [%o1+%lo(dword_F00F9A74)], %o1
F00E376C: 80a20009                 cmp     %o0, %o1
F00E3770: 12800007                 bne     loc_F00E378C
F00E3774: 90103ed0                 mov     -0x130, %o0
F00E3778: 7fffea12                 call    _audio_port_to_device
F00E377C: d006200c                 ld      [%i0+0xC], %o0
F00E3780: d206201c                 ld      [%i0+0x1C], %o1
F00E3784: 7fffea8a                 call    __NXAudioControlStreams
F00E3788: d4062024                 ld      [%i0+0x24], %o2
F00E378C: d026601c                 st      %o0, [%i1+0x1C]
F00E3790: d006601c                 ld      [%i1+0x1C], %o0
F00E3794: 80a22000                 cmp     %o0, 0
F00E3798: 12800005                 bne     locret_F00E37AC
F00E379C: 92102020                 mov     0x20, %o1 ! ' '
F00E37A0: 90102001                 mov     1, %o0
F00E37A4: d02e6003                 stb     %o0, [%i1+3]
F00E37A8: d2266004                 st      %o1, [%i1+4]
F00E37AC: 81c7e008                 ret
F00E37B0: 81e80000                 restore
