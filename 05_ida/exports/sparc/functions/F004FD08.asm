F004FD08: 9de3bf90                 save    %sp, -0x70, %sp
F004FD0C: 113c043b                 sethi   %hi(_syncprt), %o0
F004FD10: d0022128                 ld      [%o0+%lo(_syncprt)], %o0
F004FD14: 80a22000                 cmp     %o0, 0
F004FD18: 02800004                 be      loc_F004FD28
F004FD1C: a8100018                 mov     %i0, %l4
F004FD20: 400001df                 call    _bufstats
F004FD24: 01000000                 nop
F004FD28: 133c043b                 sethi   %hi(_updlock), %o1
F004FD2C: d002612c                 ld      [%o1+%lo(_updlock)], %o0
F004FD30: 80a22000                 cmp     %o0, 0
F004FD34: 12800074                 bne     locret_F004FF04
F004FD38: 113c043c                 sethi   %hi(_mounttab), %o0
F004FD3C: e00220ac                 ld      [%o0+%lo(_mounttab)], %l0
F004FD40: 90102001                 mov     1, %o0
F004FD44: 80a42000                 cmp     %l0, 0
F004FD48: 02800030                 be      loc_F004FE08
F004FD4C: d022612c                 st      %o0, [%o1+%lo(_updlock)]
F004FD50: 912e2010                 sll     %i0, 16, %o0
F004FD54: a33a2010                 sra     %o0, 16, %l1
F004FD58: 273c043b                 sethi   -0xFEF1400, %l3
F004FD5C: 253c043b                 sethi   -0xFEF1400, %l2
F004FD60: 80a47fff                 cmp     %l1, -1
F004FD64: 2280000a                 be,a    loc_F004FD8C
F004FD68: d204200c                 ld      [%l0+0xC], %o1
F004FD6C: d0142004                 lduh    [%l0+4], %o0
F004FD70: 900a0019                 and     %o0, %i1, %o0
F004FD74: 912a2010                 sll     %o0, 16, %o0
F004FD78: 913a2010                 sra     %o0, 16, %o0
F004FD7C: 80a44008                 cmp     %l1, %o0
F004FD80: 3280001f                 bne,a   loc_F004FDFC
F004FD84: e0042020                 ld      [%l0+0x20], %l0
F004FD88: d204200c                 ld      [%l0+0xC], %o1
F004FD8C: 80a26000                 cmp     %o1, 0
F004FD90: 2280001b                 be,a    loc_F004FDFC
F004FD94: e0042020                 ld      [%l0+0x20], %l0
F004FD98: d0542004                 ldsh    [%l0+4], %o0
F004FD9C: 80a23fff                 cmp     %o0, -1
F004FDA0: 22800017                 be,a    loc_F004FDFC
F004FDA4: e0042020                 ld      [%l0+0x20], %l0
F004FDA8: f0026020                 ld      [%o1+0x20], %i0
F004FDAC: d04e20d0                 ldsb    [%i0+0xD0], %o0
F004FDB0: 80a22000                 cmp     %o0, 0
F004FDB4: 22800012                 be,a    loc_F004FDFC
F004FDB8: e0042020                 ld      [%l0+0x20], %l0
F004FDBC: d04e20d2                 ldsb    [%i0+0xD2], %o0
F004FDC0: 80a22000                 cmp     %o0, 0
F004FDC4: 02800006                 be      loc_F004FDDC
F004FDC8: 9014e130                 or      %l3, 0x130, %o0! char *
F004FDCC: 7fff1223                 call    _printf
F004FDD0: 920620d4                 add     %i0, 0xD4, %o1
F004FDD4: 7fff14e7                 call    _panic
F004FDD8: 9014a140                 or      %l2, 0x140, %o0
F004FDDC: c02e20d0                 clrb    [%i0+0xD0]
F004FDE0: 7fff0c6b                 call    _getthetime
F004FDE4: 9007bff0                 add     %fp, var_10, %o0
F004FDE8: d207bff0                 ld      [%fp+var_10], %o1
F004FDEC: 90100010                 mov     %l0, %o0
F004FDF0: 400004c3                 call    _sbupdate
F004FDF4: d2262020                 st      %o1, [%i0+0x20]
F004FDF8: e0042020                 ld      [%l0+0x20], %l0
F004FDFC: 80a42000                 cmp     %l0, 0
F004FE00: 12bfffd9                 bne     loc_F004FD64
F004FE04: 80a47fff                 cmp     %l1, -1
F004FE08: 113c04d4                 sethi   %hi(_inode_list), %o0
F004FE0C: f0022140                 ld      [%o0+%lo(_inode_list)], %i0
F004FE10: 80a62000                 cmp     %i0, 0
F004FE14: 02800034                 be      loc_F004FEE4
F004FE18: 912d2010                 sll     %l4, 16, %o0
F004FE1C: a33a2010                 sra     %o0, 16, %l1
F004FE20: 80a47fff                 cmp     %l1, -1
F004FE24: 22800018                 be,a    loc_F004FE84
F004FE28: d0162044                 lduh    [%i0+0x44], %o0
F004FE2C: d0162046                 lduh    [%i0+0x46], %o0
F004FE30: 900a0019                 and     %o0, %i1, %o0
F004FE34: 912a2010                 sll     %o0, 16, %o0
F004FE38: 913a2010                 sra     %o0, 16, %o0
F004FE3C: 80a44008                 cmp     %l1, %o0
F004FE40: 32800026                 bne,a   loc_F004FED8
F004FE44: f0062008                 ld      [%i0+8], %i0
F004FE48: 80a47fff                 cmp     %l1, -1
F004FE4C: 2280000e                 be,a    loc_F004FE84
F004FE50: d0162044                 lduh    [%i0+0x44], %o0
F004FE54: d006200c                 ld      [%i0+0xC], %o0
F004FE58: a0022018                 add     %o0, 0x18, %l0
F004FE5C: 40006598                 call    _lock_try_write
F004FE60: 90100010                 mov     %l0, %o0
F004FE64: 80a22001                 cmp     %o0, 1
F004FE68: 32800007                 bne,a   loc_F004FE84
F004FE6C: d0162044                 lduh    [%i0+0x44], %o0
F004FE70: 40006471                 call    _lock_done
F004FE74: 90100010                 mov     %l0, %o0
F004FE78: 400074b0                 call    _mfs_fsync
F004FE7C: 9006200c                 add     %i0, 0xC, %o0
F004FE80: d0162044                 lduh    [%i0+0x44], %o0
F004FE84: 808a2001                 btst    1, %o0
F004FE88: 32800014                 bne,a   loc_F004FED8
F004FE8C: f0062008                 ld      [%i0+8], %i0
F004FE90: 808a2100                 btst    0x100, %o0
F004FE94: 22800011                 be,a    loc_F004FED8
F004FE98: f0062008                 ld      [%i0+8], %i0
F004FE9C: 808a204e                 btst    0x4E, %o0 ! 'N'
F004FEA0: 2280000e                 be,a    loc_F004FED8
F004FEA4: f0062008                 ld      [%i0+8], %i0
F004FEA8: 90100018                 mov     %i0, %o0
F004FEAC: d6162044                 lduh    [%i0+0x44], %o3
F004FEB0: 92102000                 mov     0, %o1
F004FEB4: d4162012                 lduh    [%i0+0x12], %o2
F004FEB8: 9612e001                 bset    1, %o3
F004FEBC: d6362044                 sth     %o3, [%i0+0x44]
F004FEC0: 9402a001                 inc     %o2
F004FEC4: 7ffff9a0                 call    _iupdat
F004FEC8: d4362012                 sth     %o2, [%i0+0x12]
F004FECC: 7ffff8b3                 call    _iput
F004FED0: 90100018                 mov     %i0, %o0
F004FED4: f0062008                 ld      [%i0+8], %i0
F004FED8: 80a62000                 cmp     %i0, 0
F004FEDC: 12bfffd2                 bne     loc_F004FE24
F004FEE0: 80a47fff                 cmp     %l1, -1
F004FEE4: 113c043b                 sethi   %hi(_updlock), %o0
F004FEE8: c022212c                 clr     [%o0+%lo(_updlock)]
F004FEEC: 90102000                 mov     0, %o0
F004FEF0: 932d2010                 sll     %l4, 16, %o1
F004FEF4: 933a6010                 sra     %o1, 16, %o1
F004FEF8: 952e6010                 sll     %i1, 16, %o2
F004FEFC: 7fff54f6                 call    _bflush
F004FF00: 953aa010                 sra     %o2, 16, %o2
F004FF04: 81c7e008                 ret
F004FF08: 81e80000                 restore
