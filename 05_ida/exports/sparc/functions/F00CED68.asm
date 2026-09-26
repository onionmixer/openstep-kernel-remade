F00CED68: 9de3bf30                 save    %sp, -0xD0, %sp
F00CED6C: a6100018                 mov     %i0, %l3
F00CED70: a207bf90                 add     %fp, var_70, %l1
F00CED74: 90100011                 mov     %l1, %o0! void *
F00CED78: 7fff1838                 call    _bzero
F00CED7C: 92102060                 mov     0x60, %o1 ! '`'
F00CED80: 90100013                 mov     %l3, %o0! id
F00CED84: d20ce188                 ldub    [%l3+0x188], %o1
F00CED88: 94102000                 mov     0, %o2
F00CED8C: d22fbf90                 stb     %o1, [%fp+var_70]
F00CED90: d60ce189                 ldub    [%l3+0x189], %o3
F00CED94: 21200000                 sethi   0x80000000, %l0
F00CED98: d62fbf91                 stb     %o3, [%fp+var_6F]
F00CED9C: 96102014                 mov     0x14, %o3
F00CEDA0: d627bfa8                 st      %o3, [%fp+var_58]
F00CEDA4: d607bfac                 ld      [%fp+var_54], %o3
F00CEDA8: 133c0505                 sethi   %hi(paAllocsdbuf), %o1
F00CEDAC: d20263d4                 ld      [%o1+%lo(paAllocsdbuf)], %o1! SEL
F00CEDB0: 9612c010                 bset    %l0, %o3
F00CEDB4: 40008aaf                 call    _objc_msgSend
F00CEDB8: d627bfac                 st      %o3, [%fp+var_54]
F00CEDBC: a4100008                 mov     %o0, %l2
F00CEDC0: e224a014                 st      %l1, [%l2+0x14]
F00CEDC4: b72ee018                 sll     %i3, 24, %i3
F00CEDC8: 80a0001b                 cmp     %g0, %i3
F00CEDCC: 92402000                 addc    %g0, 0, %o1
F00CEDD0: 80a6a001                 cmp     %i2, 1
F00CEDD4: 11100000                 sethi   0x40000000, %o0
F00CEDD8: d404a020                 ld      [%l2+0x20], %o2
F00CEDDC: 932a601e                 sll     %o1, 30, %o1
F00CEDE0: 902a8008                 andn    %o2, %o0, %o0
F00CEDE4: 90120009                 bset    %o1, %o0
F00CEDE8: 90120010                 bset    %l0, %o0
F00CEDEC: d024a020                 st      %o0, [%l2+0x20]
F00CEDF0: 9010201b                 mov     0x1B, %o0
F00CEDF4: d02fbf94                 stb     %o0, [%fp+var_6C]
F00CEDF8: d407bf94                 ld      [%fp+var_6C], %o2
F00CEDFC: 13003800                 sethi   0xE00000, %o1
F00CEE00: d00ce189                 ldub    [%l3+0x189], %o0
F00CEE04: 922a8009                 andn    %o2, %o1, %o1
F00CEE08: 900a2007                 and     %o0, 7, %o0
F00CEE0C: 912a2015                 sll     %o0, 21, %o0
F00CEE10: 92124008                 bset    %o0, %o1
F00CEE14: 0280000b                 be      loc_F00CEE40
F00CEE18: d227bf94                 st      %o1, [%fp+var_6C]
F00CEE1C: 80a6a001                 cmp     %i2, 1
F00CEE20: 0a80000a                 bcs     loc_F00CEE48
F00CEE24: 80a6a002                 cmp     %i2, 2
F00CEE28: 3280000d                 bne,a   loc_F00CEE5C
F00CEE2C: 90100013                 mov     %l3, %o0
F00CEE30: 90102002                 mov     2, %o0
F00CEE34: d02fbf98                 stb     %o0, [%fp+var_68]
F00CEE38: 10800007                 ba      loc_F00CEE54
F00CEE3C: 90102004                 mov     4, %o0
F00CEE40: 10800004                 ba      loc_F00CEE50
F00CEE44: c02fbf98                 clrb    [%fp+var_68]
F00CEE48: 90102001                 mov     1, %o0
F00CEE4C: d02fbf98                 stb     %o0, [%fp+var_68]
F00CEE50: 90102003                 mov     3, %o0
F00CEE54: d0248000                 st      %o0, [%l2]
F00CEE58: 90100013                 mov     %l3, %o0! id
F00CEE5C: 133c0505                 sethi   %hi(paEnqueuesdbuf), %o1
F00CEE60: d20263d0                 ld      [%o1+%lo(paEnqueuesdbuf)], %o1! SEL
F00CEE64: 40008a83                 call    _objc_msgSend
F00CEE68: 94100012                 mov     %l2, %o2
F00CEE6C: b0100008                 mov     %o0, %i0
F00CEE70: 90100013                 mov     %l3, %o0! id
F00CEE74: 133c0505                 sethi   %hi(paFreesdbuf), %o1
F00CEE78: d20263cc                 ld      [%o1+%lo(paFreesdbuf)], %o1! SEL
F00CEE7C: 40008a7d                 call    _objc_msgSend
F00CEE80: 94100012                 mov     %l2, %o2
F00CEE84: 81c7e008                 ret
F00CEE88: 81e80000                 restore
