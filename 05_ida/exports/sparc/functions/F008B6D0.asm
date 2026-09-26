F008B6D0: 9de3bf90                 save    %sp, -0x70, %sp
F008B6D4: a0100018                 mov     %i0, %l0
F008B6D8: d0042014                 ld      [%l0+0x14], %o0
F008B6DC: e2022028                 ld      [%o0+0x28], %l1
F008B6E0: 7ffffd65                 call    _vnode_pager_vget
F008B6E4: 90100011                 mov     %l1, %o0
F008B6E8: 133c0447                 sethi   %hi(_page_size), %o1
F008B6EC: f002613c                 ld      [%o1+%lo(_page_size)], %i0
F008B6F0: d4042014                 ld      [%l0+0x14], %o2
F008B6F4: d6042018                 ld      [%l0+0x18], %o3
F008B6F8: d204600c                 ld      [%l1+0xC], %o1
F008B6FC: 98100008                 mov     %o0, %o4
F008B700: d002a02c                 ld      [%o2+0x2C], %o0
F008B704: 80a26000                 cmp     %o1, 0
F008B708: 0680000b                 bl      loc_F008B734
F008B70C: 9a02c008                 add     %o3, %o0, %o5
F008B710: d0030000                 ld      [%o4], %o0
F008B714: d2022014                 ld      [%o0+0x14], %o1
F008B718: 90034018                 add     %o5, %i0, %o0
F008B71C: 80a20009                 cmp     %o0, %o1
F008B720: 08800005                 bleu    loc_F008B734
F008B724: 80a34009                 cmp     %o5, %o1
F008B728: 18800003                 bgu     loc_F008B734
F008B72C: b0102000                 mov     0, %i0
F008B730: b022400d                 sub     %o1, %o5, %i0
F008B734: d004600c                 ld      [%l1+0xC], %o0
F008B738: 80a22000                 cmp     %o0, 0
F008B73C: 16800020                 bge     loc_F008B7BC
F008B740: 80a62000                 cmp     %i0, 0
F008B744: 90100011                 mov     %l1, %o0
F008B748: 9210000d                 mov     %o5, %o1
F008B74C: 94102000                 mov     0, %o2
F008B750: 7ffffe7a                 call    sub_F008B138
F008B754: 9607bff4                 add     %fp, var_C, %o3
F008B758: 80a22005                 cmp     %o0, 5
F008B75C: 12800006                 bne     loc_F008B774
F008B760: 133c04c3                 sethi   -0xFECF400, %o1
F008B764: 7ffffd31                 call    _vnode_pager_vput
F008B768: 90100011                 mov     %l1, %o0
F008B76C: 1080002c                 ba      locret_F008B81C
F008B770: b0102002                 mov     2, %i0
F008B774: d00fbff4                 ldub    [%fp+var_C], %o0
F008B778: 92126370                 bset    0x370, %o1
F008B77C: d407bff4                 ld      [%fp+var_C], %o2
F008B780: 912a2002                 sll     %o0, 2, %o0
F008B784: d0020009                 ld      [%o0+%o1], %o0
F008B788: d8022008                 ld      [%o0+8], %o4
F008B78C: 133fc000                 sethi   -0x1000000, %o1
F008B790: 113c04f4                 sethi   %hi(_page_shift), %o0
F008B794: d0022348                 ld      [%o0+%lo(_page_shift)], %o0
F008B798: 922a8009                 andn    %o2, %o1, %o1
F008B79C: d4030000                 ld      [%o4], %o2
F008B7A0: 9b2a4008                 sll     %o1, %o0, %o5
F008B7A4: d002a014                 ld      [%o2+0x14], %o0
F008B7A8: 92034018                 add     %o5, %i0, %o1
F008B7AC: 80a24008                 cmp     %o1, %o0
F008B7B0: 38800002                 bgu,a   loc_F008B7B8
F008B7B4: d222a014                 st      %o1, [%o2+0x14]
F008B7B8: 80a62000                 cmp     %i0, 0
F008B7BC: 0280000a                 be      loc_F008B7E4
F008B7C0: 9010000c                 mov     %o4, %o0
F008B7C4: d602201c                 ld      [%o0+0x1C], %o3
F008B7C8: d802e078                 ld      [%o3+0x78], %o4
F008B7CC: 94100018                 mov     %i0, %o2
F008B7D0: d2042024                 ld      [%l0+0x24], %o1
F008B7D4: 9fc30000                 call    %o4
F008B7D8: 9610000d                 mov     %o5, %o3
F008B7DC: 10800003                 ba      loc_F008B7E8
F008B7E0: b0100008                 mov     %o0, %i0
F008B7E4: b0102000                 mov     0, %i0
F008B7E8: 80a62000                 cmp     %i0, 0
F008B7EC: 12800008                 bne     loc_F008B80C
F008B7F0: 113c0447                 sethi   -0xFEEE400, %o0
F008B7F4: d204201c                 ld      [%l0+0x1C], %o1
F008B7F8: d0042024                 ld      [%l0+0x24], %o0! char *
F008B7FC: 92126400                 bset    0x400, %o1
F008B800: 40004f2c                 call    _pmap_clear_modify
F008B804: d224201c                 st      %o1, [%l0+0x1C]
F008B808: 30800003                 ba,a    loc_F008B814
F008B80C: 7ffe2393                 call    _printf
F008B810: 901222e0                 bset    0x2E0, %o0
F008B814: 7ffffd05                 call    _vnode_pager_vput
F008B818: 90100011                 mov     %l1, %o0
F008B81C: 81c7e008                 ret
F008B820: 81e80000                 restore
