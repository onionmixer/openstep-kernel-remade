F0028DF4: 9de3bf78                 save    %sp, -0x88, %sp
F0028DF8: c027bfe4                 clr     [%fp+var_1C]
F0028DFC: c0274000                 clr     [%i5]
F0028E00: 90100018                 mov     %i0, %o0
F0028E04: 92100019                 mov     %i1, %o1
F0028E08: b207bfe8                 add     %fp, var_18, %i1
F0028E0C: 7ffff92b                 call    _pn_get
F0028E10: 94100019                 mov     %i1, %o2
F0028E14: b0920000                 orcc    %o0, %g0, %i0
F0028E18: 12800075                 bne     locret_F0028FEC
F0028E1C: 80a6e001                 cmp     %i3, 1
F0028E20: 1280000b                 bne     loc_F0028E4C
F0028E24: 9007bfe8                 add     %fp, var_18, %o0
F0028E28: d0068000                 ld      [%i2], %o0
F0028E2C: 80a22002                 cmp     %o0, 2
F0028E30: 02800006                 be      loc_F0028E48
F0028E34: 90100019                 mov     %i1, %o0
F0028E38: 92102000                 mov     0, %o1
F0028E3C: 9407bfe4                 add     %fp, var_1C, %o2
F0028E40: 10800006                 ba      loc_F0028E58
F0028E44: 96102000                 mov     0, %o3
F0028E48: 9007bfe8                 add     %fp, var_18, %o0
F0028E4C: 92102001                 mov     1, %o1
F0028E50: 9407bfe4                 add     %fp, var_1C, %o2
F0028E54: 9610001d                 mov     %i5, %o3
F0028E58: 7ffff6ed                 call    _lookuppn
F0028E5C: 01000000                 nop
F0028E60: b0920000                 orcc    %o0, %g0, %i0
F0028E64: 22800005                 be,a    loc_F0028E78
F0028E68: d0074000                 ld      [%i5], %o0
F0028E6C: 7ffff99f                 call    _pn_free
F0028E70: 9007bfe8                 add     %fp, var_18, %o0
F0028E74: 3080005e                 ba,a    locret_F0028FEC
F0028E78: 80a22000                 cmp     %o0, 0
F0028E7C: 22800008                 be,a    loc_F0028E9C
F0028E80: d007bfe4                 ld      [%fp+var_1C], %o0
F0028E84: d0022028                 ld      [%o0+0x28], %o0
F0028E88: 80a22006                 cmp     %o0, 6
F0028E8C: 12800004                 bne     loc_F0028E9C
F0028E90: d007bfe4                 ld      [%fp+var_1C], %o0
F0028E94: 10800056                 ba      locret_F0028FEC
F0028E98: b010202d                 mov     0x2D, %i0 ! '-'
F0028E9C: d0022024                 ld      [%o0+0x24], %o0
F0028EA0: d002200c                 ld      [%o0+0xC], %o0
F0028EA4: 808a2001                 btst    1, %o0
F0028EA8: 02800012                 be      loc_F0028EF0
F0028EAC: 80a6e000                 cmp     %i3, 0
F0028EB0: d2074000                 ld      [%i5], %o1
F0028EB4: 80a26000                 cmp     %o1, 0
F0028EB8: 22800023                 be,a    loc_F0028F44
F0028EBC: b010201e                 mov     0x1E, %i0
F0028EC0: d0026028                 ld      [%o1+0x28], %o0
F0028EC4: 90023ffd                 inc     -3, %o0
F0028EC8: 80a22001                 cmp     %o0, 1
F0028ECC: 08800008                 bleu    loc_F0028EEC
F0028ED0: 80a26000                 cmp     %o1, 0
F0028ED4: 0280001c                 be      loc_F0028F44
F0028ED8: b010201e                 mov     0x1E, %i0
F0028EDC: 7fffff22                 call    _vn_rele
F0028EE0: 90100009                 mov     %o1, %o0
F0028EE4: 10800018                 ba      loc_F0028F44
F0028EE8: b010201e                 mov     0x1E, %i0
F0028EEC: 80a6e000                 cmp     %i3, 0
F0028EF0: 12800016                 bne     loc_F0028F48
F0028EF4: 80a62000                 cmp     %i0, 0
F0028EF8: d2074000                 ld      [%i5], %o1
F0028EFC: 80a26000                 cmp     %o1, 0
F0028F00: 02800011                 be      loc_F0028F44
F0028F04: 808f2080                 btst    0x80, %i4
F0028F08: 0280000d                 be      loc_F0028F3C
F0028F0C: 01000000                 nop
F0028F10: d0126004                 lduh    [%o1+4], %o0
F0028F14: 808a2002                 btst    2, %o0
F0028F18: 02800009                 be      loc_F0028F3C
F0028F1C: 01000000                 nop
F0028F20: 40018ca8                 call    _vnode_uncache
F0028F24: 90100009                 mov     %o1, %o0
F0028F28: d0074000                 ld      [%i5], %o0
F0028F2C: d0122004                 lduh    [%o0+4], %o0
F0028F30: 808a2002                 btst    2, %o0
F0028F34: 32800002                 bne,a   loc_F0028F3C
F0028F38: b010201a                 mov     0x1A, %i0
F0028F3C: 7fffff0a                 call    _vn_rele
F0028F40: d0074000                 ld      [%i5], %o0
F0028F44: 80a62000                 cmp     %i0, 0
F0028F48: 12800025                 bne     loc_F0028FDC
F0028F4C: 01000000                 nop
F0028F50: d0068000                 ld      [%i2], %o0
F0028F54: 80a22002                 cmp     %o0, 2
F0028F58: 12800014                 bne     loc_F0028FA8
F0028F5C: d007bfe4                 ld      [%fp+var_1C], %o0
F0028F60: d0074000                 ld      [%i5], %o0
F0028F64: 80a22000                 cmp     %o0, 0
F0028F68: 22800005                 be,a    loc_F0028F7C
F0028F6C: 113c04cf                 sethi   -0xFECC400, %o0
F0028F70: 7ffffefd                 call    _vn_rele
F0028F74: b0102011                 mov     0x11, %i0
F0028F78: 30800019                 ba,a    loc_F0028FDC
F0028F7C: d00221d8                 ld      [%o0+0x1D8], %o0
F0028F80: d207bfec                 ld      [%fp+var_14], %o1
F0028F84: d802201c                 ld      [%o0+0x1C], %o4
F0028F88: d007bfe4                 ld      [%fp+var_1C], %o0
F0028F8C: da02201c                 ld      [%o0+0x1C], %o5
F0028F90: 9410001a                 mov     %i2, %o2
F0028F94: da036034                 ld      [%o5+0x34], %o5
F0028F98: 9fc34000                 call    %o5
F0028F9C: 9610001d                 mov     %i5, %o3
F0028FA0: 1080000f                 ba      loc_F0028FDC
F0028FA4: b0100008                 mov     %o0, %i0
F0028FA8: d207bfec                 ld      [%fp+var_14], %o1
F0028FAC: 1b3c04cf                 sethi   %hi(_active_u), %o5
F0028FB0: da0361d8                 ld      [%o5+%lo(_active_u)], %o5
F0028FB4: 9410001a                 mov     %i2, %o2
F0028FB8: c402201c                 ld      [%o0+0x1C], %g2
F0028FBC: 9610001b                 mov     %i3, %o3
F0028FC0: da03601c                 ld      [%o5+0x1C], %o5
F0028FC4: 9810001c                 mov     %i4, %o4
F0028FC8: da23a05c                 st      %o5, [%sp+0x88+var_2C]
F0028FCC: c400a024                 ld      [%g2+0x24], %g2
F0028FD0: 9fc08000                 call    %g2
F0028FD4: 9a10001d                 mov     %i5, %o5
F0028FD8: b0100008                 mov     %o0, %i0
F0028FDC: 7ffff943                 call    _pn_free
F0028FE0: 9007bfe8                 add     %fp, var_18, %o0
F0028FE4: 7ffffee0                 call    _vn_rele
F0028FE8: d007bfe4                 ld      [%fp+var_1C], %o0
F0028FEC: 81c7e008                 ret
F0028FF0: 81e80000                 restore
