F0050E78: 9de3bf98                 save    %sp, -0x68, %sp
F0050E7C: f0062128                 ld      [%i0+0x128], %i0
F0050E80: 7ffff851                 call    _iflush
F0050E84: d0562004                 ldsh    [%i0+4], %o0
F0050E88: a0920000                 orcc    %o0, %g0, %l0
F0050E8C: 36800009                 bge,a   loc_F0050EB0
F0050E90: d006200c                 ld      [%i0+0xC], %o0
F0050E94: 80a66000                 cmp     %i1, 0
F0050E98: 02800004                 be      loc_F0050EA8
F0050E9C: 80a42000                 cmp     %l0, 0
F0050EA0: 36800004                 bge,a   loc_F0050EB0
F0050EA4: d006200c                 ld      [%i0+0xC], %o0
F0050EA8: 10800040                 ba      locret_F0050FA8
F0050EAC: b0102010                 mov     0x10, %i0
F0050EB0: f2022020                 ld      [%o0+0x20], %i1
F0050EB4: d04e60d2                 ldsb    [%i1+0xD2], %o0
F0050EB8: 80a00008                 cmp     %g0, %o0
F0050EBC: a2603fff                 subc    %g0, -1, %l1
F0050EC0: 80a46000                 cmp     %l1, 0
F0050EC4: 2280000b                 be,a    loc_F0050EF0
F0050EC8: d00662d8                 ld      [%i1+0x2D8], %o0
F0050ECC: d04e60d1                 ldsb    [%i1+0xD1], %o0
F0050ED0: 80a22002                 cmp     %o0, 2
F0050ED4: 32800007                 bne,a   loc_F0050EF0
F0050ED8: d00662d8                 ld      [%i1+0x2D8], %o0
F0050EDC: 90102001                 mov     1, %o0
F0050EE0: d02e60d1                 stb     %o0, [%i1+0xD1]
F0050EE4: 40000086                 call    _sbupdate
F0050EE8: 90100018                 mov     %i0, %o0
F0050EEC: d00662d8                 ld      [%i1+0x2D8], %o0
F0050EF0: 40005cac                 call    _kfree
F0050EF4: d206609c                 ld      [%i1+0x9C], %o1
F0050EF8: 7fff4e5c                 call    _brelse
F0050EFC: d006200c                 ld      [%i0+0xC], %o0
F0050F00: c026200c                 clr     [%i0+0xC]
F0050F04: 80a42000                 cmp     %l0, 0
F0050F08: 12800027                 bne     loc_F0050FA4
F0050F0C: c0362004                 clrh    [%i0+4]
F0050F10: d0062008                 ld      [%i0+8], %o0
F0050F14: 133c04cf                 sethi   %hi(_active_u), %o1
F0050F18: d60261d8                 ld      [%o1+%lo(_active_u)], %o3
F0050F1C: d402201c                 ld      [%o0+0x1C], %o2
F0050F20: d802a004                 ld      [%o2+4], %o4
F0050F24: 92100011                 mov     %l1, %o1
F0050F28: d602e01c                 ld      [%o3+0x1C], %o3
F0050F2C: 9fc30000                 call    %o4
F0050F30: 94102001                 mov     1, %o2
F0050F34: 7fff51a7                 call    _binval
F0050F38: d0062008                 ld      [%i0+8], %o0
F0050F3C: 7fff5f0a                 call    _vn_rele
F0050F40: d0062008                 ld      [%i0+8], %o0
F0050F44: 133c043c                 sethi   %hi(_mounttab), %o1
F0050F48: d00260ac                 ld      [%o1+%lo(_mounttab)], %o0
F0050F4C: 80a60008                 cmp     %i0, %o0
F0050F50: 12800005                 bne     loc_F0050F64
F0050F54: c0262008                 clr     [%i0+8]
F0050F58: d0062020                 ld      [%i0+0x20], %o0
F0050F5C: 1080000f                 ba      loc_F0050F98
F0050F60: d02260ac                 st      %o0, [%o1+%lo(_mounttab)]
F0050F64: 92920000                 orcc    %o0, %g0, %o1
F0050F68: 0280000d                 be      loc_F0050F9C
F0050F6C: 90100018                 mov     %i0, %o0
F0050F70: d0026020                 ld      [%o1+0x20], %o0
F0050F74: 80a20018                 cmp     %o0, %i0
F0050F78: 32800005                 bne,a   loc_F0050F8C
F0050F7C: d2026020                 ld      [%o1+0x20], %o1
F0050F80: d0062020                 ld      [%i0+0x20], %o0
F0050F84: d0226020                 st      %o0, [%o1+0x20]
F0050F88: d2026020                 ld      [%o1+0x20], %o1
F0050F8C: 80a26000                 cmp     %o1, 0
F0050F90: 32bffff9                 bne,a   loc_F0050F74
F0050F94: d0026020                 ld      [%o1+0x20], %o0
F0050F98: 90100018                 mov     %i0, %o0
F0050F9C: 40005c81                 call    _kfree
F0050FA0: 92102024                 mov     0x24, %o1 ! '$'
F0050FA4: b0102000                 mov     0, %i0
F0050FA8: 81c7e008                 ret
F0050FAC: 81e80000                 restore
