F000A78C: 9de3bf98                 save    %sp, -0x68, %sp
F000A790: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F000A794: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F000A798: e2022024                 ld      [%o0+0x24], %l1
F000A79C: d4044000                 ld      [%l1], %o2
F000A7A0: 808abfc0                 btst    -0x40, %o2
F000A7A4: 02800006                 be      loc_F000A7BC
F000A7A8: a614a1dc                 or      %l2, %lo(dword_F0133DDC), %l3
F000A7AC: 900aa03f                 and     %o2, 0x3F, %o0! int
F000A7B0: 4000002c                 call    _dup2
F000A7B4: d0244000                 st      %o0, [%l1]
F000A7B8: 30800028                 ba,a    locret_F000A858
F000A7BC: d204fffc                 ld      [%l3-4], %o1
F000A7C0: d0026158                 ld      [%o1+0x158], %o0
F000A7C4: 80a28008                 cmp     %o2, %o0
F000A7C8: 1a80000a                 bcc     loc_F000A7F0
F000A7CC: 912aa002                 sll     %o2, 2, %o0
F000A7D0: d202614c                 ld      [%o1+0x14C], %o1
F000A7D4: e0024008                 ld      [%o1+%o0], %l0
F000A7D8: 80a42000                 cmp     %l0, 0
F000A7DC: 02800005                 be      loc_F000A7F0
F000A7E0: 113fffc0                 sethi   -0x10000, %o0
F000A7E4: 80a40008                 cmp     %l0, %o0
F000A7E8: 12800005                 bne     loc_F000A7FC
F000A7EC: 01000000                 nop
F000A7F0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000A7F4: 10800011                 ba      loc_F000A838
F000A7F8: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F000A7FC: 400002a5                 call    _ufalloc
F000A800: 90102000                 mov     0, %o0
F000A804: 94920000                 orcc    %o0, %g0, %o2
F000A808: 06800014                 bl      locret_F000A858
F000A80C: 01000000                 nop
F000A810: d604fffc                 ld      [%l3-4], %o3
F000A814: d8044000                 ld      [%l1], %o4
F000A818: d202e14c                 ld      [%o3+0x14C], %o1
F000A81C: 912b2002                 sll     %o4, 2, %o0
F000A820: d0024008                 ld      [%o1+%o0], %o0
F000A824: 80a40008                 cmp     %l0, %o0
F000A828: 02800007                 be      loc_F000A844
F000A82C: 912aa002                 sll     %o2, 2, %o0
F000A830: c0224008                 clr     [%o1+%o0]
F000A834: d204a1dc                 ld      [%l2+0x1DC], %o1
F000A838: 90102009                 mov     9, %o0
F000A83C: 10800007                 ba      locret_F000A858
F000A840: d02a6038                 stb     %o0, [%o1+0x38]
F000A844: d202e150                 ld      [%o3+0x150], %o1
F000A848: 9010000a                 mov     %o2, %o0
F000A84C: d44a400c                 ldsb    [%o1+%o4], %o2
F000A850: 40000062                 call    _dupit
F000A854: 92100010                 mov     %l0, %o1
F000A858: 81c7e008                 ret
F000A85C: 81e80000                 restore
