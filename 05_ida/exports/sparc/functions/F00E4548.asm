F00E4548: 9de3bf98                 save    %sp, -0x68, %sp
F00E454C: d4062004                 ld      [%i0+4], %o2
F00E4550: 9002bbd8                 add     %o2, -0x428, %o0
F00E4554: 80a22400                 cmp     %o0, 0x400
F00E4558: 18800005                 bgu     loc_F00E456C
F00E455C: d00e2003                 ldub    [%i0+3], %o0
F00E4560: 80a22000                 cmp     %o0, 0
F00E4564: 22800005                 be,a    loc_F00E4578
F00E4568: d0062018                 ld      [%i0+0x18], %o0
F00E456C: 90103ed0                 mov     -0x130, %o0
F00E4570: 1080002f                 ba      locret_F00E462C
F00E4574: d026601c                 st      %o0, [%i1+0x1C]
F00E4578: 133c03e6                 sethi   %hi(dword_F00F9B50), %o1
F00E457C: d2026350                 ld      [%o1+%lo(dword_F00F9B50)], %o1
F00E4580: 80a20009                 cmp     %o0, %o1
F00E4584: 12800022                 bne     loc_F00E460C
F00E4588: 90103ed0                 mov     -0x130, %o0
F00E458C: d6062020                 ld      [%i0+0x20], %o3
F00E4590: 133fffc09212600c         set     -0xFFF4, %o1
F00E4598: 1100880090122008         set     0x2200008, %o0
F00E45A0: 920ac009                 and     %o3, %o1, %o1
F00E45A4: 80a24008                 cmp     %o1, %o0
F00E45A8: 12800019                 bne     loc_F00E460C
F00E45AC: 90103ed0                 mov     -0x130, %o0
F00E45B0: 9132e004                 srl     %o3, 4, %o0
F00E45B4: 900a2fff                 and     %o0, 0xFFF, %o0
F00E45B8: 992a2002                 sll     %o0, 2, %o4
F00E45BC: 90032428                 add     %o4, 0x428, %o0
F00E45C0: 80a28008                 cmp     %o2, %o0
F00E45C4: 12800012                 bne     loc_F00E460C
F00E45C8: 90103ed0                 mov     -0x130, %o0
F00E45CC: a006000c                 add     %i0, %o4, %l0
F00E45D0: d0042024                 ld      [%l0+0x24], %o0
F00E45D4: 133c03e6                 sethi   %hi(dword_F00F9B54), %o1
F00E45D8: d2026354                 ld      [%o1+%lo(dword_F00F9B54)], %o1
F00E45DC: 80a20009                 cmp     %o0, %o1
F00E45E0: 1280000b                 bne     loc_F00E460C
F00E45E4: 90103ed0                 mov     -0x130, %o0
F00E45E8: 7fffe676                 call    _audio_port_to_device
F00E45EC: d006200c                 ld      [%i0+0xC], %o0
F00E45F0: 94062024                 add     %i0, 0x24, %o2 ! '$'
F00E45F4: d6062020                 ld      [%i0+0x20], %o3
F00E45F8: 98042028                 add     %l0, 0x28, %o4 ! '('
F00E45FC: d206201c                 ld      [%i0+0x1C], %o1
F00E4600: 9732e004                 srl     %o3, 4, %o3
F00E4604: 7fffea25                 call    __NXAudioSetDeviceParameters
F00E4608: 960aefff                 and     %o3, 0xFFF, %o3
F00E460C: d026601c                 st      %o0, [%i1+0x1C]
F00E4610: d006601c                 ld      [%i1+0x1C], %o0
F00E4614: 80a22000                 cmp     %o0, 0
F00E4618: 12800005                 bne     locret_F00E462C
F00E461C: 94102020                 mov     0x20, %o2 ! ' '
F00E4620: 90102001                 mov     1, %o0
F00E4624: d02e6003                 stb     %o0, [%i1+3]
F00E4628: d4266004                 st      %o2, [%i1+4]
F00E462C: 81c7e008                 ret
F00E4630: 81e80000                 restore
