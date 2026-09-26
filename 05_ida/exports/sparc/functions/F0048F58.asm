F0048F58: 9de3bf98                 save    %sp, -0x68, %sp
F0048F5C: 113c04cf                 sethi   %hi(_active_u), %o0
F0048F60: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0048F64: d002201c                 ld      [%o0+0x1C], %o0
F0048F68: d0522002                 ldsh    [%o0+2], %o0
F0048F6C: a4100018                 mov     %i0, %l2
F0048F70: 80a22000                 cmp     %o0, 0
F0048F74: 02800007                 be      loc_F0048F90
F0048F78: e004a050                 ld      [%l2+0x50], %l0
F0048F7C: d20420c8                 ld      [%l0+0xC8], %o1
F0048F80: d0042094                 ld      [%l0+0x94], %o0
F0048F84: 80a24008                 cmp     %o1, %o0
F0048F88: 0480003d                 ble     loc_F004907C
F0048F8C: 90100010                 mov     %l0, %o0
F0048F90: d00420c8                 ld      [%l0+0xC8], %o0
F0048F94: 80a22000                 cmp     %o0, 0
F0048F98: 02800039                 be      loc_F004907C
F0048F9C: 90100010                 mov     %l0, %o0
F0048FA0: e20420b8                 ld      [%l0+0xB8], %l1
F0048FA4: d004202c                 ld      [%l0+0x2C], %o0
F0048FA8: 7ffef556                 call    _umul
F0048FAC: 92100011                 mov     %l1, %o1
F0048FB0: 80a64008                 cmp     %i1, %o0
F0048FB4: 3a800002                 bcc,a   loc_F0048FBC
F0048FB8: b2102000                 mov     0, %i1
F0048FBC: 90100019                 mov     %i1, %o0
F0048FC0: 7ffef590                 call    _udiv
F0048FC4: 92100011                 mov     %l1, %o1
F0048FC8: 92100008                 mov     %o0, %o1
F0048FCC: 90100012                 mov     %l2, %o0
F0048FD0: 94100019                 mov     %i1, %o2
F0048FD4: 9610001a                 mov     %i2, %o3
F0048FD8: 193c0127                 sethi   %hi(_ialloccg), %o4
F0048FDC: 400000ec                 call    _hashalloc
F0048FE0: 98132260                 bset    %lo(_ialloccg), %o4
F0048FE4: b2920000                 orcc    %o0, %g0, %i1
F0048FE8: 02800025                 be      loc_F004907C
F0048FEC: 90100010                 mov     %l0, %o0
F0048FF0: d054a046                 ldsh    [%l2+0x46], %o0
F0048FF4: d204a050                 ld      [%l2+0x50], %o1
F0048FF8: 40001338                 call    _iget
F0048FFC: 94100019                 mov     %i1, %o2
F0049000: b0920000                 orcc    %o0, %g0, %i0
F0049004: 32800008                 bne,a   loc_F0049024
F0049008: d2162064                 lduh    [%i0+0x64], %o1
F004900C: 90100012                 mov     %l2, %o0
F0049010: 92100019                 mov     %i1, %o1
F0049014: 40000598                 call    _ifree
F0049018: 94102000                 mov     0, %o2
F004901C: 1080001b                 ba      locret_F0049088
F0049020: b0102000                 mov     0, %i0
F0049024: 80a26000                 cmp     %o1, 0
F0049028: 2280000b                 be,a    loc_F0049054
F004902C: d60620cc                 ld      [%i0+0xCC], %o3
F0049030: 113c0439901222c8         set     aMode0OInumDFsS, %o0! "mode = 0%o, inum = %d, fs = %s\n"
F0049038: d4062048                 ld      [%i0+0x48], %o2
F004903C: 7fff2d87                 call    _printf
F0049040: 960420d4                 add     %l0, 0xD4, %o3
F0049044: 113c0439                 sethi   %hi(aIallocDupAlloc), %o0! "ialloc: dup alloc"
F0049048: 7fff304a                 call    _panic
F004904C: 901222e8                 bset    %lo(aIallocDupAlloc), %o0! "ialloc: dup alloc"
F0049050: d60620cc                 ld      [%i0+0xCC], %o3
F0049054: 80a2e000                 cmp     %o3, 0
F0049058: 02800007                 be      loc_F0049074
F004905C: 113c0439                 sethi   %hi(aFreeInodeSDHad), %o0! "free inode %s/%d had %d blocks\n"
F0049060: 90122300                 bset    %lo(aFreeInodeSDHad), %o0! "free inode %s/%d had %d blocks\n"
F0049064: 920420d4                 add     %l0, 0xD4, %o1
F0049068: 7fff2d7c                 call    _printf
F004906C: 94100019                 mov     %i1, %o2
F0049070: c02620cc                 clr     [%i0+0xCC]
F0049074: 10800005                 ba      locret_F0049088
F0049078: c02620c8                 clr     [%i0+0xC8]
F004907C: 7ffffe35                 call    _fsfull
F0049080: 92102002                 mov     2, %o1
F0049084: b0102000                 mov     0, %i0
F0049088: 81c7e008                 ret
F004908C: 81e80000                 restore
