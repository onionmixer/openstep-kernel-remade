F0090898: 9de3bf90                 save    %sp, -0x70, %sp
F009089C: 90100018                 mov     %i0, %o0! id
F00908A0: 133c0504                 sethi   %hi(paDevicedescript_1), %o1
F00908A4: d2026158                 ld      [%o1+%lo(paDevicedescript_1)], %o1! SEL
F00908A8: 400183f2                 call    _objc_msgSend
F00908AC: b0102000                 mov     0, %i0
F00908B0: 133c0504                 sethi   %hi(paResourcesforke), %o1
F00908B4: 153c0448                 sethi   %hi(aIOPorts_0), %o2! "I/O Ports"
F00908B8: d2026124                 ld      [%o1+%lo(paResourcesforke)], %o1! SEL
F00908BC: 400183ed                 call    _objc_msgSend
F00908C0: 9412a1a0                 bset    %lo(aIOPorts_0), %o2! "I/O Ports"
F00908C4: 133c0504                 sethi   %hi(paCount_0), %o1! SEL
F00908C8: a2100008                 mov     %o0, %l1
F00908CC: 400183e9                 call    _objc_msgSend
F00908D0: d20260b8                 ld      [%o1+%lo(paCount_0)], %o1
F00908D4: a0100008                 mov     %o0, %l0
F00908D8: 80a60010                 cmp     %i0, %l0
F00908DC: 16800016                 bge     locret_F0090934
F00908E0: 293c0504                 sethi   -0xFEBF000, %l4
F00908E4: 273c0504                 sethi   -0xFEBF000, %l3
F00908E8: a407bff0                 add     %fp, var_10, %l2
F00908EC: 90100011                 mov     %l1, %o0! id
F00908F0: d20520c8                 ld      [%l4+0xC8], %o1! SEL
F00908F4: 400183df                 call    _objc_msgSend
F00908F8: 94100018                 mov     %i0, %o2
F00908FC: d204e058                 ld      [%l3+0x58], %o1! SEL
F0090900: e423a040                 st      %l2, [%sp+0x70+var_30]
F0090904: 400183db                 call    _objc_msgSend
F0090908: 01000000                 nop
F009090C: 00000008                 illtrap
F0090910: d006600c                 ld      [%i1+0xC], %o0
F0090914: d207bff0                 ld      [%fp+var_10], %o1
F0090918: b0062001                 inc     %i0
F009091C: d407bff4                 ld      [%fp+var_C], %o2
F0090920: 40002ddf                 call    _task_map_io_ports
F0090924: 9610001a                 mov     %i2, %o3
F0090928: 80a60010                 cmp     %i0, %l0
F009092C: 06bffff1                 bl      loc_F00908F0
F0090930: 90100011                 mov     %l1, %o0
F0090934: 81c7e008                 ret
F0090938: 91e82000                 restore %g0, 0, %o0
