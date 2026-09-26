F007DE2C: 9de3bf90                 save    %sp, -0x70, %sp
F007DE30: e2062004                 ld      [%i0+4], %l1
F007DE34: 80a46028                 cmp     %l1, 0x28 ! '('
F007DE38: 12800012                 bne     loc_F007DE80
F007DE3C: 90103ed0                 mov     -0x130, %o0
F007DE40: d0060000                 ld      [%i0], %o0
F007DE44: 80a22000                 cmp     %o0, 0
F007DE48: 0680000d                 bl      loc_F007DE7C
F007DE4C: 133c0444                 sethi   %hi(dword_F0111280), %o1
F007DE50: d0062018                 ld      [%i0+0x18], %o0
F007DE54: d2026280                 ld      [%o1+%lo(dword_F0111280)], %o1
F007DE58: 80a20009                 cmp     %o0, %o1
F007DE5C: 12800009                 bne     loc_F007DE80
F007DE60: 90103ed0                 mov     -0x130, %o0
F007DE64: d0062020                 ld      [%i0+0x20], %o0
F007DE68: 133c0444                 sethi   %hi(dword_F0111284), %o1
F007DE6C: d2026284                 ld      [%o1+%lo(dword_F0111284)], %o1
F007DE70: 80a20009                 cmp     %o0, %o1
F007DE74: 02800005                 be      loc_F007DE88
F007DE78: 01000000                 nop
F007DE7C: 90103ed0                 mov     -0x130, %o0
F007DE80: 10800038                 ba      locret_F007DF60
F007DE84: d026601c                 st      %o0, [%i1+0x1C]
F007DE88: 7fffa6bb                 call    _convert_port_to_space
F007DE8C: d0062008                 ld      [%i0+8], %o0! task
F007DE90: a0100008                 mov     %o0, %l0
F007DE94: d206201c                 ld      [%i0+0x1C], %o1! name
F007DE98: 96066024                 add     %i1, 0x24, %o3 ! '$'! poly
F007DE9C: d4062024                 ld      [%i0+0x24], %o2! msgt_name
F007DEA0: 7fff9378                 call    _mach_port_extract_right
F007DEA4: 9807bff4                 add     %fp, var_C, %o4
F007DEA8: d026601c                 st      %o0, [%i1+0x1C]
F007DEAC: 7fffa742                 call    _space_deallocate
F007DEB0: 90100010                 mov     %l0, %o0
F007DEB4: d006601c                 ld      [%i1+0x1C], %o0
F007DEB8: 80a22000                 cmp     %o0, 0
F007DEBC: 12800029                 bne     locret_F007DF60
F007DEC0: 113c0444                 sethi   %hi(dword_F0111288), %o0
F007DEC4: e2266004                 st      %l1, [%i1+4]
F007DEC8: d2022288                 ld      [%o0+%lo(dword_F0111288)], %o1
F007DECC: a0102001                 mov     1, %l0
F007DED0: d007bff4                 ld      [%fp+var_C], %o0
F007DED4: 80a22010                 cmp     %o0, 0x10
F007DED8: 12800016                 bne     loc_F007DF30
F007DEDC: d2266020                 st      %o1, [%i1+0x20]
F007DEE0: d206200c                 ld      [%i0+0xC], %o1
F007DEE4: 80a26000                 cmp     %o1, 0
F007DEE8: 02800012                 be      loc_F007DF30
F007DEEC: 80a27fff                 cmp     %o1, -1
F007DEF0: 22800011                 be,a    loc_F007DF34
F007DEF4: d207bff4                 ld      [%fp+var_C], %o1
F007DEF8: d0066024                 ld      [%i1+0x24], %o0
F007DEFC: 80a22000                 cmp     %o0, 0
F007DF00: 0280000c                 be      loc_F007DF30
F007DF04: 80a23fff                 cmp     %o0, -1
F007DF08: 2280000b                 be,a    loc_F007DF34
F007DF0C: d207bff4                 ld      [%fp+var_C], %o1
F007DF10: 7fff73ad                 call    _ipc_port_check_circularity
F007DF14: 01000000                 nop
F007DF18: 80a22000                 cmp     %o0, 0
F007DF1C: 02800005                 be      loc_F007DF30
F007DF20: 13100000                 sethi   0x40000000, %o1
F007DF24: d0064000                 ld      [%i1], %o0
F007DF28: 90120009                 bset    %o1, %o0
F007DF2C: d0264000                 st      %o0, [%i1]
F007DF30: d207bff4                 ld      [%fp+var_C], %o1
F007DF34: 90027ff0                 add     %o1, -0x10, %o0
F007DF38: 80a22005                 cmp     %o0, 5
F007DF3C: 28800002                 bleu,a  loc_F007DF44
F007DF40: a0102000                 mov     0, %l0
F007DF44: 80a42000                 cmp     %l0, 0
F007DF48: 12800006                 bne     locret_F007DF60
F007DF4C: d22e6020                 stb     %o1, [%i1+0x20]
F007DF50: d0064000                 ld      [%i1], %o0
F007DF54: 13200000                 sethi   0x80000000, %o1
F007DF58: 90120009                 bset    %o1, %o0
F007DF5C: d0264000                 st      %o0, [%i1]
F007DF60: 81c7e008                 ret
F007DF64: 81e80000                 restore
