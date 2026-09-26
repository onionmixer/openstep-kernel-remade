F007E830: 9de3bf88                 save    %sp, -0x78, %sp! object_name
F007E834: d0062004                 ld      [%i0+4], %o0
F007E838: 80a22020                 cmp     %o0, 0x20 ! ' '
F007E83C: 1280000e                 bne     loc_F007E874
F007E840: 90103ed0                 mov     -0x130, %o0
F007E844: d0060000                 ld      [%i0], %o0
F007E848: 23200000                 sethi   0x80000000, %l1
F007E84C: 808a0011                 btst    %l1, %o0
F007E850: 12800009                 bne     loc_F007E874
F007E854: 90103ed0                 mov     -0x130, %o0
F007E858: d0062018                 ld      [%i0+0x18], %o0
F007E85C: 133c0444                 sethi   %hi(dword_F0111358), %o1
F007E860: d2026358                 ld      [%o1+%lo(dword_F0111358)], %o1
F007E864: 80a20009                 cmp     %o0, %o1
F007E868: 02800005                 be      loc_F007E87C
F007E86C: 01000000                 nop
F007E870: 90103ed0                 mov     -0x130, %o0
F007E874: 10800036                 ba      locret_F007E94C
F007E878: d026601c                 st      %o0, [%i1+0x1C]
F007E87C: 7fffa45f                 call    _convert_port_to_map
F007E880: d0062008                 ld      [%i0+8], %o0! target_task
F007E884: 9206604c                 add     %i1, 0x4C, %o1 ! 'L'
F007E888: d223a05c                 st      %o1, [%sp+0x78+var_1C]
F007E88C: 92066054                 add     %i1, 0x54, %o1 ! 'T'
F007E890: d223a060                 st      %o1, [%sp+0x78+var_18]
F007E894: 9206605c                 add     %i1, 0x5C, %o1 ! '\'
F007E898: d223a064                 st      %o1, [%sp+0x78+var_14]
F007E89C: a0100008                 mov     %o0, %l0
F007E8A0: 9206201c                 add     %i0, 0x1C, %o1! address
F007E8A4: 9406602c                 add     %i1, 0x2C, %o2 ! ','! size
F007E8A8: 96066034                 add     %i1, 0x34, %o3 ! '4'! flavor
F007E8AC: 9806603c                 add     %i1, 0x3C, %o4 ! '<'! info
F007E8B0: 40001e18                 call    _vm_region
F007E8B4: 9a066044                 add     %i1, 0x44, %o5 ! 'D'
F007E8B8: d026601c                 st      %o0, [%i1+0x1C]
F007E8BC: 40001654                 call    _vm_map_deallocate
F007E8C0: 90100010                 mov     %l0, %o0
F007E8C4: d006601c                 ld      [%i1+0x1C], %o0
F007E8C8: 80a22000                 cmp     %o0, 0
F007E8CC: 12800020                 bne     locret_F007E94C
F007E8D0: 92102060                 mov     0x60, %o1 ! '`'
F007E8D4: d0064000                 ld      [%i1], %o0
F007E8D8: d2266004                 st      %o1, [%i1+4]
F007E8DC: 90120011                 bset    %l1, %o0
F007E8E0: d0264000                 st      %o0, [%i1]
F007E8E4: 113c0444                 sethi   %hi(dword_F011135C), %o0
F007E8E8: d002235c                 ld      [%o0+%lo(dword_F011135C)], %o0
F007E8EC: d0266020                 st      %o0, [%i1+0x20]
F007E8F0: d006201c                 ld      [%i0+0x1C], %o0
F007E8F4: d0266024                 st      %o0, [%i1+0x24]
F007E8F8: 113c0444                 sethi   %hi(dword_F0111360), %o0
F007E8FC: d0022360                 ld      [%o0+%lo(dword_F0111360)], %o0
F007E900: d0266028                 st      %o0, [%i1+0x28]
F007E904: 113c0444                 sethi   %hi(dword_F0111364), %o0
F007E908: d0022364                 ld      [%o0+%lo(dword_F0111364)], %o0
F007E90C: d0266030                 st      %o0, [%i1+0x30]
F007E910: 113c0444                 sethi   %hi(dword_F0111368), %o0
F007E914: d0022368                 ld      [%o0+%lo(dword_F0111368)], %o0
F007E918: d0266038                 st      %o0, [%i1+0x38]
F007E91C: 113c0444                 sethi   %hi(dword_F011136C), %o0
F007E920: d002236c                 ld      [%o0+%lo(dword_F011136C)], %o0
F007E924: d0266040                 st      %o0, [%i1+0x40]
F007E928: 113c0444                 sethi   %hi(dword_F0111370), %o0
F007E92C: d0022370                 ld      [%o0+%lo(dword_F0111370)], %o0
F007E930: d0266048                 st      %o0, [%i1+0x48]
F007E934: 113c0444                 sethi   %hi(dword_F0111374), %o0
F007E938: d0022374                 ld      [%o0+%lo(dword_F0111374)], %o0
F007E93C: d0266050                 st      %o0, [%i1+0x50]
F007E940: 113c0444                 sethi   %hi(dword_F0111378), %o0
F007E944: d0022378                 ld      [%o0+%lo(dword_F0111378)], %o0
F007E948: d0266058                 st      %o0, [%i1+0x58]
F007E94C: 81c7e008                 ret
F007E950: 81e80000                 restore
