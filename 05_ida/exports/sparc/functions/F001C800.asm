F001C800: 9de3bf98                 save    %sp, -0x68, %sp
F001C804: 80a6a000                 cmp     %i2, 0
F001C808: 14800004                 bg      loc_F001C818
F001C80C: 01000000                 nop
F001C810: 10800057                 ba      locret_F001C96C
F001C814: b0102000                 mov     0, %i0
F001C818: 4001e8e8                 call    _spltty
F001C81C: 01000000                 nop
F001C820: d2060000                 ld      [%i0], %o1
F001C824: 80a26000                 cmp     %o1, 0
F001C828: 14800008                 bg      loc_F001C848
F001C82C: a8100008                 mov     %o0, %l4
F001C830: c0260000                 clr     [%i0]
F001C834: c0262008                 clr     [%i0+8]
F001C838: 4001e93b                 call    _splx
F001C83C: c0262004                 clr     [%i0+4]
F001C840: 1080004b                 ba      locret_F001C96C
F001C844: b0102000                 mov     0, %i0
F001C848: aa100019                 mov     %i1, %l5
F001C84C: 253c043c                 sethi   -0xFEF1000, %l2
F001C850: 273c043c                 sethi   -0xFEF1000, %l3
F001C854: 233c04d4                 sethi   -0xFECB000, %l1
F001C858: d4062004                 ld      [%i0+4], %o2! size_t
F001C85C: 90102040                 mov     0x40, %o0 ! '@'
F001C860: 920aa03f                 and     %o2, 0x3F, %o1
F001C864: a0220009                 sub     %o0, %o1, %l0
F001C868: 80a4001a                 cmp     %l0, %i2
F001C86C: 34800002                 bg,a    loc_F001C874
F001C870: a010001a                 mov     %i2, %l0
F001C874: d0060000                 ld      [%i0], %o0
F001C878: 80a40008                 cmp     %l0, %o0
F001C87C: 34800002                 bg,a    loc_F001C884
F001C880: a0100008                 mov     %o0, %l0
F001C884: 9010000a                 mov     %o2, %o0! void *
F001C888: 92100019                 mov     %i1, %o1! void *
F001C88C: 4001e0a1                 call    _bcopy
F001C890: 94100010                 mov     %l0, %o2
F001C894: b4268010                 sub     %i2, %l0, %i2
F001C898: d2062004                 ld      [%i0+4], %o1
F001C89C: b2064010                 add     %i1, %l0, %i1
F001C8A0: d0060000                 ld      [%i0], %o0
F001C8A4: 92024010                 add     %o1, %l0, %o1
F001C8A8: d2262004                 st      %o1, [%i0+4]
F001C8AC: 90220010                 sub     %o0, %l0, %o0
F001C8B0: 80a22000                 cmp     %o0, 0
F001C8B4: 14800014                 bg      loc_F001C904
F001C8B8: d0260000                 st      %o0, [%i0]
F001C8BC: d0062004                 ld      [%i0+4], %o0
F001C8C0: c0262008                 clr     [%i0+8]
F001C8C4: d24c62b0                 ldsb    [%l1+0x2B0], %o1
F001C8C8: 94023fff                 add     %o0, -1, %o2
F001C8CC: 940abfc0                 and     %o2, -0x40, %o2
F001C8D0: c0262004                 clr     [%i0+4]
F001C8D4: d004a38c                 ld      [%l2+0x38C], %o0
F001C8D8: 80a26000                 cmp     %o1, 0
F001C8DC: d0228000                 st      %o0, [%o2]
F001C8E0: d004e390                 ld      [%l3+0x390], %o0
F001C8E4: d424a38c                 st      %o2, [%l2+0x38C]
F001C8E8: 90022034                 inc     0x34, %o0 ! '4'
F001C8EC: 0280001d                 be      loc_F001C960
F001C8F0: d024e390                 st      %o0, [%l3+0x390]
F001C8F4: 7fffd93d                 call    _wakeup
F001C8F8: 901462b0                 or      %l1, 0x2B0, %o0
F001C8FC: 10800019                 ba      loc_F001C960
F001C900: c02c62b0                 clrb    [%l1+0x2B0]
F001C904: d6062004                 ld      [%i0+4], %o3
F001C908: 808ae03f                 btst    0x3F, %o3 ! '?'
F001C90C: 12800013                 bne     loc_F001C958
F001C910: 80a6a000                 cmp     %i2, 0
F001C914: d002ffc0                 ld      [%o3-0x40], %o0
F001C918: 9402ffc0                 add     %o3, -0x40, %o2
F001C91C: d204a38c                 ld      [%l2+0x38C], %o1
F001C920: 9002200c                 inc     0xC, %o0
F001C924: d0262004                 st      %o0, [%i0+4]
F001C928: d222ffc0                 st      %o1, [%o3-0x40]
F001C92C: d004e390                 ld      [%l3+0x390], %o0
F001C930: d424a38c                 st      %o2, [%l2+0x38C]
F001C934: d24c62b0                 ldsb    [%l1+0x2B0], %o1
F001C938: 90022034                 inc     0x34, %o0 ! '4'
F001C93C: 80a26000                 cmp     %o1, 0
F001C940: 02800005                 be      loc_F001C954
F001C944: d024e390                 st      %o0, [%l3+0x390]
F001C948: 7fffd928                 call    _wakeup
F001C94C: 901462b0                 or      %l1, 0x2B0, %o0
F001C950: c02c62b0                 clrb    [%l1+0x2B0]
F001C954: 80a6a000                 cmp     %i2, 0
F001C958: 32bfffc1                 bne,a   loc_F001C85C
F001C95C: d4062004                 ld      [%i0+4], %o2
F001C960: 4001e8f1                 call    _splx
F001C964: 90100014                 mov     %l4, %o0
F001C968: b0264015                 sub     %i1, %l5, %i0
F001C96C: 81c7e008                 ret
F001C970: 81e80000                 restore
