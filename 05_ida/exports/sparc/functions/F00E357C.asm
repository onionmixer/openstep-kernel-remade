F00E357C: 9de3bf98                 save    %sp, -0x68, %sp
F00E3580: d2062004                 ld      [%i0+4], %o1
F00E3584: 80a26020                 cmp     %o1, 0x20 ! ' '
F00E3588: 12800005                 bne     loc_F00E359C
F00E358C: d00e2003                 ldub    [%i0+3], %o0
F00E3590: 80a22000                 cmp     %o0, 0
F00E3594: 22800005                 be,a    loc_F00E35A8
F00E3598: d0062018                 ld      [%i0+0x18], %o0
F00E359C: 90103ed0                 mov     -0x130, %o0
F00E35A0: 10800013                 ba      locret_F00E35EC
F00E35A4: d026601c                 st      %o0, [%i1+0x1C]
F00E35A8: 133c03e6                 sethi   %hi(dword_F00F9A58), %o1
F00E35AC: d2026258                 ld      [%o1+%lo(dword_F00F9A58)], %o1
F00E35B0: 80a20009                 cmp     %o0, %o1
F00E35B4: 12800006                 bne     loc_F00E35CC
F00E35B8: 90103ed0                 mov     -0x130, %o0
F00E35BC: 7fffea81                 call    _audio_port_to_device
F00E35C0: d006200c                 ld      [%i0+0xC], %o0
F00E35C4: 7fffeaac                 call    __NXAudioSetExclusiveUser
F00E35C8: d206201c                 ld      [%i0+0x1C], %o1
F00E35CC: d026601c                 st      %o0, [%i1+0x1C]
F00E35D0: d006601c                 ld      [%i1+0x1C], %o0
F00E35D4: 80a22000                 cmp     %o0, 0
F00E35D8: 12800005                 bne     locret_F00E35EC
F00E35DC: 92102020                 mov     0x20, %o1 ! ' '
F00E35E0: 90102001                 mov     1, %o0
F00E35E4: d02e6003                 stb     %o0, [%i1+3]
F00E35E8: d2266004                 st      %o1, [%i1+4]
F00E35EC: 81c7e008                 ret
F00E35F0: 81e80000                 restore
