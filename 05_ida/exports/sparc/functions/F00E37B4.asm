F00E37B4: 9de3bf98                 save    %sp, -0x68, %sp
F00E37B8: d2062004                 ld      [%i0+4], %o1
F00E37BC: 80a26030                 cmp     %o1, 0x30 ! '0'
F00E37C0: 12800005                 bne     loc_F00E37D4
F00E37C4: d00e2003                 ldub    [%i0+3], %o0
F00E37C8: 80a22000                 cmp     %o0, 0
F00E37CC: 22800005                 be,a    loc_F00E37E0
F00E37D0: d0062018                 ld      [%i0+0x18], %o0
F00E37D4: 90103ed0                 mov     -0x130, %o0
F00E37D8: 10800024                 ba      locret_F00E3868
F00E37DC: d026601c                 st      %o0, [%i1+0x1C]
F00E37E0: 133c03e6                 sethi   %hi(dword_F00F9A78), %o1
F00E37E4: d2026278                 ld      [%o1+%lo(dword_F00F9A78)], %o1
F00E37E8: 80a20009                 cmp     %o0, %o1
F00E37EC: 12800015                 bne     loc_F00E3840
F00E37F0: 90103ed0                 mov     -0x130, %o0
F00E37F4: d0062020                 ld      [%i0+0x20], %o0
F00E37F8: 133c03e6                 sethi   %hi(dword_F00F9A7C), %o1
F00E37FC: d202627c                 ld      [%o1+%lo(dword_F00F9A7C)], %o1
F00E3800: 80a20009                 cmp     %o0, %o1
F00E3804: 1280000f                 bne     loc_F00E3840
F00E3808: 90103ed0                 mov     -0x130, %o0
F00E380C: d0062028                 ld      [%i0+0x28], %o0
F00E3810: 133c03e6                 sethi   %hi(dword_F00F9A80), %o1
F00E3814: d2026280                 ld      [%o1+%lo(dword_F00F9A80)], %o1
F00E3818: 80a20009                 cmp     %o0, %o1
F00E381C: 12800009                 bne     loc_F00E3840
F00E3820: 90103ed0                 mov     -0x130, %o0
F00E3824: 7fffe9e7                 call    _audio_port_to_device
F00E3828: d006200c                 ld      [%i0+0xC], %o0
F00E382C: d406201c                 ld      [%i0+0x1C], %o2
F00E3830: d6062024                 ld      [%i0+0x24], %o3
F00E3834: d806202c                 ld      [%i0+0x2C], %o4
F00E3838: 7fffea7e                 call    __NXAudioAddStream
F00E383C: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00E3840: d026601c                 st      %o0, [%i1+0x1C]
F00E3844: d006601c                 ld      [%i1+0x1C], %o0
F00E3848: 80a22000                 cmp     %o0, 0
F00E384C: 12800007                 bne     locret_F00E3868
F00E3850: 92102028                 mov     0x28, %o1 ! '('
F00E3854: c02e6003                 clrb    [%i1+3]
F00E3858: 113c03e6                 sethi   %hi(dword_F00F9A84), %o0
F00E385C: d0022284                 ld      [%o0+%lo(dword_F00F9A84)], %o0
F00E3860: d2266004                 st      %o1, [%i1+4]
F00E3864: d0266020                 st      %o0, [%i1+0x20]
F00E3868: 81c7e008                 ret
F00E386C: 81e80000                 restore
