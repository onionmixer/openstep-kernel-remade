F00E38EC: 9de3bf98                 save    %sp, -0x68, %sp
F00E38F0: d2062004                 ld      [%i0+4], %o1
F00E38F4: 80a26030                 cmp     %o1, 0x30 ! '0'
F00E38F8: 12800005                 bne     loc_F00E390C
F00E38FC: d00e2003                 ldub    [%i0+3], %o0
F00E3900: 80a22000                 cmp     %o0, 0
F00E3904: 22800005                 be,a    loc_F00E3918
F00E3908: d0062018                 ld      [%i0+0x18], %o0
F00E390C: 90103ed0                 mov     -0x130, %o0
F00E3910: 10800021                 ba      locret_F00E3994
F00E3914: d026601c                 st      %o0, [%i1+0x1C]
F00E3918: 133c03e6                 sethi   %hi(dword_F00F9A90), %o1
F00E391C: d2026290                 ld      [%o1+%lo(dword_F00F9A90)], %o1
F00E3920: 80a20009                 cmp     %o0, %o1
F00E3924: 12800014                 bne     loc_F00E3974
F00E3928: 90103ed0                 mov     -0x130, %o0
F00E392C: d0062020                 ld      [%i0+0x20], %o0
F00E3930: 133c03e6                 sethi   %hi(dword_F00F9A94), %o1
F00E3934: d2026294                 ld      [%o1+%lo(dword_F00F9A94)], %o1
F00E3938: 80a20009                 cmp     %o0, %o1
F00E393C: 1280000e                 bne     loc_F00E3974
F00E3940: 90103ed0                 mov     -0x130, %o0
F00E3944: d0062028                 ld      [%i0+0x28], %o0
F00E3948: 133c03e6                 sethi   %hi(dword_F00F9A98), %o1
F00E394C: d2026298                 ld      [%o1+%lo(dword_F00F9A98)], %o1
F00E3950: 80a20009                 cmp     %o0, %o1
F00E3954: 12800008                 bne     loc_F00E3974
F00E3958: 90103ed0                 mov     -0x130, %o0
F00E395C: 7fffe999                 call    _audio_port_to_device
F00E3960: d006200c                 ld      [%i0+0xC], %o0
F00E3964: d206201c                 ld      [%i0+0x1C], %o1
F00E3968: d4062024                 ld      [%i0+0x24], %o2
F00E396C: 7fffea64                 call    __NXAudioSetDevicePeakOptions
F00E3970: d606202c                 ld      [%i0+0x2C], %o3
F00E3974: d026601c                 st      %o0, [%i1+0x1C]
F00E3978: d006601c                 ld      [%i1+0x1C], %o0
F00E397C: 80a22000                 cmp     %o0, 0
F00E3980: 12800005                 bne     locret_F00E3994
F00E3984: 92102020                 mov     0x20, %o1 ! ' '
F00E3988: 90102001                 mov     1, %o0
F00E398C: d02e6003                 stb     %o0, [%i1+3]
F00E3990: d2266004                 st      %o1, [%i1+4]
F00E3994: 81c7e008                 ret
F00E3998: 81e80000                 restore
