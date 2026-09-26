F0048AD8: 9de3bf98                 save    %sp, -0x68, %sp
F0048ADC: 173c04cf                 sethi   %hi(dword_F0133DDC), %o3
F0048AE0: d002e1dc                 ld      [%o3+%lo(dword_F0133DDC)], %o0
F0048AE4: d202203c                 ld      [%o0+0x3C], %o1
F0048AE8: 9812e1dc                 or      %o3, %lo(dword_F0133DDC), %o4
F0048AEC: d44a2040                 ldsb    [%o0+0x40], %o2
F0048AF0: c022203c                 clr     [%o0+0x3C]
F0048AF4: d002e1dc                 ld      [%o3+%lo(dword_F0133DDC)], %o0
F0048AF8: 80a26000                 cmp     %o1, 0
F0048AFC: 02800010                 be      loc_F0048B3C
F0048B00: c02a2040                 clrb    [%o0+0x40]
F0048B04: 80a2a000                 cmp     %o2, 0
F0048B08: 0280000d                 be      loc_F0048B3C
F0048B0C: d602e1dc                 ld      [%o3+%lo(dword_F0133DDC)], %o3
F0048B10: d04ae038                 ldsb    [%o3+0x38], %o0
F0048B14: 80a2201c                 cmp     %o0, 0x1C
F0048B18: 3280001f                 bne,a   locret_F0048B94
F0048B1C: b0102000                 mov     0, %i0
F0048B20: d0033ffc                 ld      [%o4-4], %o0
F0048B24: d00a225c                 ldub    [%o0+0x25C], %o0
F0048B28: 808a2008                 btst    8, %o0
F0048B2C: 02800004                 be      loc_F0048B3C
F0048B30: 80a62000                 cmp     %i0, 0
F0048B34: 22800004                 be,a    loc_F0048B44
F0048B38: c02ae038                 clrb    [%o3+0x38]
F0048B3C: 10800016                 ba      locret_F0048B94
F0048B40: b0102000                 mov     0, %i0
F0048B44: 808aa001                 btst    1, %o2
F0048B48: 113c01229a122228         set     _fssleep, %o5
F0048B50: 12800005                 bne     loc_F0048B64
F0048B54: 960260d4                 add     %o1, 0xD4, %o3
F0048B58: 113c0439                 sethi   %hi(aOutOfInodes_0), %o0! " out of inodes"
F0048B5C: 10800004                 ba      loc_F0048B6C
F0048B60: 981221a0                 or      %o0, %lo(aOutOfInodes_0), %o4! " out of inodes"
F0048B64: 113c0439981221b0         set     aFileSystemIsFu, %o4! " file system is full"
F0048B6C: 7fff285b                 call    _rpsleep
F0048B70: 9010000d                 mov     %o5, %o0
F0048B74: 80a22000                 cmp     %o0, 0
F0048B78: 12800007                 bne     locret_F0048B94
F0048B7C: b0102001                 mov     1, %i0
F0048B80: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0048B84: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F0048B88: b0102000                 mov     0, %i0
F0048B8C: 9010201c                 mov     0x1C, %o0
F0048B90: d02a6038                 stb     %o0, [%o1+0x38]
F0048B94: 81c7e008                 ret
F0048B98: 81e80000                 restore
