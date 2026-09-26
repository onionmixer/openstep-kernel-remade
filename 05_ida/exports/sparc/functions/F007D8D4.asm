F007D8D4: 9de3bf98                 save    %sp, -0x68, %sp
F007D8D8: d0062004                 ld      [%i0+4], %o0
F007D8DC: 80a22030                 cmp     %o0, 0x30 ! '0'
F007D8E0: 12800018                 bne     loc_F007D940
F007D8E4: 90103ed0                 mov     -0x130, %o0
F007D8E8: d0060000                 ld      [%i0], %o0
F007D8EC: 80a22000                 cmp     %o0, 0
F007D8F0: 06800013                 bl      loc_F007D93C
F007D8F4: 133c0444                 sethi   %hi(dword_F0111230), %o1
F007D8F8: d0062018                 ld      [%i0+0x18], %o0
F007D8FC: d2026230                 ld      [%o1+%lo(dword_F0111230)], %o1
F007D900: 80a20009                 cmp     %o0, %o1
F007D904: 1280000f                 bne     loc_F007D940
F007D908: 90103ed0                 mov     -0x130, %o0
F007D90C: d0062020                 ld      [%i0+0x20], %o0
F007D910: 133c0444                 sethi   %hi(dword_F0111234), %o1
F007D914: d2026234                 ld      [%o1+%lo(dword_F0111234)], %o1
F007D918: 80a20009                 cmp     %o0, %o1
F007D91C: 12800009                 bne     loc_F007D940
F007D920: 90103ed0                 mov     -0x130, %o0
F007D924: d0062028                 ld      [%i0+0x28], %o0
F007D928: 133c0444                 sethi   %hi(dword_F0111238), %o1
F007D92C: d2026238                 ld      [%o1+%lo(dword_F0111238)], %o1
F007D930: 80a20009                 cmp     %o0, %o1
F007D934: 02800005                 be      loc_F007D948
F007D938: 01000000                 nop
F007D93C: 90103ed0                 mov     -0x130, %o0
F007D940: 1080000c                 ba      locret_F007D970
F007D944: d026601c                 st      %o0, [%i1+0x1C]
F007D948: 7fffa80b                 call    _convert_port_to_space
F007D94C: d0062008                 ld      [%i0+8], %o0! task
F007D950: d206201c                 ld      [%i0+0x1C], %o1! name
F007D954: d4062024                 ld      [%i0+0x24], %o2! right
F007D958: a0100008                 mov     %o0, %l0
F007D95C: 7fff9314                 call    _mach_port_mod_refs
F007D960: d606202c                 ld      [%i0+0x2C], %o3
F007D964: d026601c                 st      %o0, [%i1+0x1C]
F007D968: 7fffa893                 call    _space_deallocate
F007D96C: 90100010                 mov     %l0, %o0
F007D970: 81c7e008                 ret
F007D974: 81e80000                 restore
