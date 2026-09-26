F00B161C: 9de3bf90                 save    %sp, -0x70, %sp
F00B1620: 9610001a                 mov     %i2, %o3
F00B1624: 80a2ffff                 cmp     %o3, -1
F00B1628: 02800035                 be      locret_F00B16FC
F00B162C: a60e2fff                 and     %i0, 0xFFF, %l3
F00B1630: 7fff9556                 call    _splusclock
F00B1634: b410000b                 mov     %o3, %i2
F00B1638: 92064013                 add     %i1, %l3, %o1
F00B163C: a0100008                 mov     %o0, %l0
F00B1640: 90100009                 mov     %o1, %o0
F00B1644: 7fffe632                 call    _map_alloc
F00B1648: 92102000                 mov     0, %o1
F00B164C: a4100008                 mov     %o0, %l2
F00B1650: 7fff95b5                 call    _splx
F00B1654: 90100010                 mov     %l0, %o0
F00B1658: 80a4a000                 cmp     %l2, 0
F00B165C: 12800006                 bne     loc_F00B1674
F00B1660: 2d3c0447                 sethi   -0xFEEE400, %l6
F00B1664: 113c0471                 sethi   %hi(aOutOfKernelMap), %o0! "out of kernel_map for devices"
F00B1668: 7ffd8ec2                 call    _panic
F00B166C: 90122388                 bset    %lo(aOutOfKernelMap), %o0! "out of kernel_map for devices"
F00B1670: 2d3c0447                 sethi   -0xFEEE400, %l6
F00B1674: e005a13c                 ld      [%l6+0x13C], %l0
F00B1678: 90100019                 mov     %i1, %o0
F00B167C: 7ffd53e1                 call    _udiv
F00B1680: 92100010                 mov     %l0, %o1
F00B1684: a2100008                 mov     %o0, %l1
F00B1688: 90100019                 mov     %i1, %o0
F00B168C: 7ffd5485                 call    _urem
F00B1690: 92100010                 mov     %l0, %o1
F00B1694: 80a22000                 cmp     %o0, 0
F00B1698: 02800003                 be      loc_F00B16A4
F00B169C: a4148013                 bset    %l3, %l2
F00B16A0: a2046001                 inc     %l1
F00B16A4: a0102000                 mov     0, %l0
F00B16A8: 80a40011                 cmp     %l0, %l1
F00B16AC: 16800013                 bge     loc_F00B16F8
F00B16B0: b2100012                 mov     %l2, %i1
F00B16B4: 2b3c04f0                 sethi   -0xFEC4000, %l5
F00B16B8: a8102001                 mov     1, %l4
F00B16BC: a6100016                 mov     %l6, %l3
F00B16C0: e823a05c                 st      %l4, [%sp+0x70+var_14]
F00B16C4: 920e7000                 and     %i1, -0x1000, %o1
F00B16C8: a0042001                 inc     %l0
F00B16CC: 94100018                 mov     %i0, %o2
F00B16D0: 9610001a                 mov     %i2, %o3
F00B16D4: 98102003                 mov     3, %o4
F00B16D8: d0056100                 ld      [%l5+0x100], %o0
F00B16DC: 7fffb217                 call    _pmap_enter_dev
F00B16E0: 9a102000                 mov     0, %o5
F00B16E4: d004e13c                 ld      [%l3+0x13C], %o0
F00B16E8: 80a40011                 cmp     %l0, %l1
F00B16EC: b2064008                 add     %i1, %o0, %i1
F00B16F0: 06bffff4                 bl      loc_F00B16C0
F00B16F4: b0060008                 add     %i0, %o0, %i0
F00B16F8: b0100012                 mov     %l2, %i0
F00B16FC: 81c7e008                 ret
F00B1700: 81e80000                 restore
