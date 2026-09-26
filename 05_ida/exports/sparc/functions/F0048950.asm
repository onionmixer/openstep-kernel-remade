F0048950: 9de3bf98                 save    %sp, -0x68, %sp
F0048954: 808e6001                 btst    1, %i1
F0048958: 02800006                 be      loc_F0048970
F004895C: 113c0439                 sethi   %hi(aFileSystemFull), %o0! "file system full"
F0048960: a0122108                 or      %o0, %lo(aFileSystemFull), %l0! "file system full"
F0048964: 113c0439                 sethi   %hi(aWriteFailedFil), %o0! "write failed, file system is full"
F0048968: 1080000e                 ba      loc_F00489A0
F004896C: a2122120                 or      %o0, %lo(aWriteFailedFil), %l1! "write failed, file system is full"
F0048970: 808e6002                 btst    2, %i1
F0048974: 02800007                 be      loc_F0048990
F0048978: a2102000                 mov     0, %l1
F004897C: 113c0439a0122148         set     aOutOfInodes, %l0! "out of inodes"
F0048984: 113c0439                 sethi   %hi(aCreateSymlinkF), %o0! "create/symlink failed, no inodes free"
F0048988: 10800006                 ba      loc_F00489A0
F004898C: a2122158                 or      %o0, %lo(aCreateSymlinkF), %l1! "create/symlink failed, no inodes free"
F0048990: a0102000                 mov     0, %l0
F0048994: 113c0439                 sethi   %hi(aFsfull), %o0! "fsfull"
F0048998: 7fff31f6                 call    _panic
F004899C: 90122180                 bset    %lo(aFsfull), %o0! "fsfull"
F00489A0: d04e20d3                 ldsb    [%i0+0xD3], %o0
F00489A4: 808a0019                 btst    %i1, %o0
F00489A8: 32800006                 bne,a   loc_F00489C0
F00489AC: d00e20d3                 ldub    [%i0+0xD3], %o0
F00489B0: 90100018                 mov     %i0, %o0
F00489B4: 40000847                 call    _fserr
F00489B8: 92100010                 mov     %l0, %o1
F00489BC: d00e20d3                 ldub    [%i0+0xD3], %o0
F00489C0: 133c04cf                 sethi   %hi(_active_u), %o1
F00489C4: 90120019                 bset    %i1, %o0
F00489C8: d02e20d3                 stb     %o0, [%i0+0xD3]
F00489CC: d00261d8                 ld      [%o1+%lo(_active_u)], %o0
F00489D0: d00a225c                 ldub    [%o0+0x25C], %o0
F00489D4: 808a2008                 btst    8, %o0
F00489D8: 12800007                 bne     loc_F00489F4
F00489DC: a01261d8                 or      %o1, %lo(_active_u), %l0
F00489E0: 113c043990122188         set     aSS_1, %o0! "\n%s: %s\n"
F00489E8: 920620d4                 add     %i0, 0xD4, %o1
F00489EC: 7fff2f2d                 call    _uprintf
F00489F0: 94100011                 mov     %l1, %o2
F00489F4: d2042004                 ld      [%l0+4], %o1
F00489F8: d002603c                 ld      [%o1+0x3C], %o0
F00489FC: 80a22000                 cmp     %o0, 0
F0048A00: 12800007                 bne     loc_F0048A1C
F0048A04: 9010201c                 mov     0x1C, %o0
F0048A08: f022603c                 st      %i0, [%o1+0x3C]
F0048A0C: d0042004                 ld      [%l0+4], %o0
F0048A10: f22a2040                 stb     %i1, [%o0+0x40]
F0048A14: d2042004                 ld      [%l0+4], %o1
F0048A18: 9010201c                 mov     0x1C, %o0
F0048A1C: d02a6038                 stb     %o0, [%o1+0x38]
F0048A20: 81c7e008                 ret
F0048A24: 81e80000                 restore
