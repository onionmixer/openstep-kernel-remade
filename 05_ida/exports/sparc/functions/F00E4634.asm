F00E4634: 9de3bf98                 save    %sp, -0x68, %sp
F00E4638: d4062004                 ld      [%i0+4], %o2
F00E463C: 9002bfe4                 add     %o2, -0x1C, %o0
F00E4640: 80a22400                 cmp     %o0, 0x400
F00E4644: 18800005                 bgu     loc_F00E4658
F00E4648: d00e2003                 ldub    [%i0+3], %o0
F00E464C: 80a22001                 cmp     %o0, 1
F00E4650: 22800005                 be,a    loc_F00E4664
F00E4654: d6062018                 ld      [%i0+0x18], %o3
F00E4658: 90103ed0                 mov     -0x130, %o0
F00E465C: 10800024                 ba      locret_F00E46EC
F00E4660: d026601c                 st      %o0, [%i1+0x1C]
F00E4664: 133fffc09212600c         set     -0xFFF4, %o1
F00E466C: 1100880090122008         set     0x2200008, %o0
F00E4674: 920ac009                 and     %o3, %o1, %o1
F00E4678: 80a24008                 cmp     %o1, %o0
F00E467C: 12800011                 bne     loc_F00E46C0
F00E4680: 90103ed0                 mov     -0x130, %o0
F00E4684: 9132e004                 srl     %o3, 4, %o0
F00E4688: 900a2fff                 and     %o0, 0xFFF, %o0
F00E468C: 912a2002                 sll     %o0, 2, %o0
F00E4690: 9002201c                 inc     0x1C, %o0
F00E4694: 80a28008                 cmp     %o2, %o0
F00E4698: 1280000a                 bne     loc_F00E46C0
F00E469C: 90103ed0                 mov     -0x130, %o0
F00E46A0: 7fffe648                 call    _audio_port_to_device
F00E46A4: d006200c                 ld      [%i0+0xC], %o0
F00E46A8: 9206201c                 add     %i0, 0x1C, %o1
F00E46AC: d4062018                 ld      [%i0+0x18], %o2
F00E46B0: 96066024                 add     %i1, 0x24, %o3 ! '$'
F00E46B4: 9532a004                 srl     %o2, 4, %o2
F00E46B8: 7fffea18                 call    __NXAudioGetDeviceParameters
F00E46BC: 940aafff                 and     %o2, 0xFFF, %o2
F00E46C0: d026601c                 st      %o0, [%i1+0x1C]
F00E46C4: d006601c                 ld      [%i1+0x1C], %o0
F00E46C8: 80a22000                 cmp     %o0, 0
F00E46CC: 12800008                 bne     locret_F00E46EC
F00E46D0: 94102424                 mov     0x424, %o2
F00E46D4: 90102001                 mov     1, %o0
F00E46D8: d02e6003                 stb     %o0, [%i1+3]
F00E46DC: 113c03e6                 sethi   %hi(dword_F00F9B58), %o0
F00E46E0: d0022358                 ld      [%o0+%lo(dword_F00F9B58)], %o0
F00E46E4: d4266004                 st      %o2, [%i1+4]
F00E46E8: d0266020                 st      %o0, [%i1+0x20]
F00E46EC: 81c7e008                 ret
F00E46F0: 81e80000                 restore
