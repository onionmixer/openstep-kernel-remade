F00403A4: 9de3bf40                 save    %sp, -0xC0, %sp
F00403A8: a2100018                 mov     %i0, %l1
F00403AC: 90100019                 mov     %i1, %o0! __s1
F00403B0: 133c0435                 sethi   %hi(unk_F010D708), %o1! __s2
F00403B4: 7fff1f7e                 call    _strcmp
F00403B8: 92126308                 bset    %lo(unk_F010D708), %o1
F00403BC: 80a22000                 cmp     %o0, 0
F00403C0: 02800014                 be      loc_F0040410
F00403C4: 90100019                 mov     %i1, %o0! __s1
F00403C8: 133c0435                 sethi   %hi(unk_F010D710), %o1! __s2
F00403CC: 7fff1f78                 call    _strcmp
F00403D0: 92126310                 bset    %lo(unk_F010D710), %o1
F00403D4: 80a22000                 cmp     %o0, 0
F00403D8: 0280000e                 be      loc_F0040410
F00403DC: 9010001b                 mov     %i3, %o0! __s1
F00403E0: 133c0435                 sethi   %hi(unk_F010D718), %o1! __s2
F00403E4: 7fff1f72                 call    _strcmp
F00403E8: 92126318                 bset    %lo(unk_F010D718), %o1
F00403EC: 80a22000                 cmp     %o0, 0
F00403F0: 02800008                 be      loc_F0040410
F00403F4: 9010001b                 mov     %i3, %o0! __s1
F00403F8: 133c0435                 sethi   %hi(unk_F010D720), %o1! __s2
F00403FC: 7fff1f6c                 call    _strcmp
F0040400: 92126320                 bset    %lo(unk_F010D720), %o1
F0040404: 80a22000                 cmp     %o0, 0
F0040408: 12800004                 bne     loc_F0040418
F004040C: 01000000                 nop
F0040410: 10800041                 ba      locret_F0040514
F0040414: b0102016                 mov     0x16, %i0
F0040418: 7ffff483                 call    _rlock
F004041C: d0046030                 ld      [%l1+0x30], %o0
F0040420: 90100011                 mov     %l1, %o0
F0040424: 7fff9601                 call    _dnlc_remove
F0040428: 92100019                 mov     %i1, %o1
F004042C: 9010001a                 mov     %i2, %o0
F0040430: 7fff95fe                 call    _dnlc_remove
F0040434: 9210001b                 mov     %i3, %o1
F0040438: 80a68011                 cmp     %i2, %l1
F004043C: 02800005                 be      loc_F0040450
F0040440: a007bfb0                 add     %fp, var_50, %l0
F0040444: 7ffff478                 call    _rlock
F0040448: d006a030                 ld      [%i2+0x30], %o0
F004044C: a007bfb0                 add     %fp, var_50, %l0
F0040450: 90100010                 mov     %l0, %o0
F0040454: 92100019                 mov     %i1, %o1
F0040458: 7ffff1e3                 call    _setdiropargs
F004045C: 94100011                 mov     %l1, %o2
F0040460: 9007bfd4                 add     %fp, var_2C, %o0
F0040464: 9210001b                 mov     %i3, %o1
F0040468: 7ffff1df                 call    _setdiropargs
F004046C: 9410001a                 mov     %i2, %o2
F0040470: 9210200b                 mov     0xB, %o1
F0040474: 153c01089412a3a8         set     _xdr_rnmargs, %o2
F004047C: 193c0115                 sethi   %hi(_xdr_enum), %o4
F0040480: 96100010                 mov     %l0, %o3
F0040484: d0046024                 ld      [%l1+0x24], %o0
F0040488: 98132348                 bset    %lo(_xdr_enum), %o4
F004048C: d0022128                 ld      [%o0+0x128], %o0
F0040490: 9a07bfac                 add     %fp, var_54, %o5
F0040494: 7ffff0b8                 call    _rfscall
F0040498: f823a05c                 st      %i4, [%sp+0xC0+var_64]
F004049C: d2046030                 ld      [%l1+0x30], %o1
F00404A0: c02260c0                 clr     [%o1+0xC0]
F00404A4: d206a030                 ld      [%i2+0x30], %o1
F00404A8: b0100008                 mov     %o0, %i0
F00404AC: c02260c0                 clr     [%o1+0xC0]
F00404B0: 7ffff47b                 call    _runlock
F00404B4: d0046030                 ld      [%l1+0x30], %o0
F00404B8: 80a68011                 cmp     %i2, %l1
F00404BC: 02800005                 be      loc_F00404D0
F00404C0: 80a62000                 cmp     %i0, 0
F00404C4: 7ffff476                 call    _runlock
F00404C8: d006a030                 ld      [%i2+0x30], %o0
F00404CC: 80a62000                 cmp     %i0, 0
F00404D0: 12800011                 bne     locret_F0040514
F00404D4: 01000000                 nop
F00404D8: f007bfac                 ld      [%fp+var_54], %i0
F00404DC: 80a62046                 cmp     %i0, 0x46 ! 'F'
F00404E0: 12800007                 bne     loc_F00404FC
F00404E4: 01000000                 nop
F00404E8: 7fff9405                 call    _btrash
F00404EC: 90100011                 mov     %l1, %o0
F00404F0: 7fffe44e                 call    _nfs_invalidate_caches
F00404F4: 90100011                 mov     %l1, %o0
F00404F8: 80a62046                 cmp     %i0, 0x46 ! 'F'
F00404FC: 12800006                 bne     locret_F0040514
F0040500: 01000000                 nop
F0040504: 7fff93fe                 call    _btrash
F0040508: 9010001a                 mov     %i2, %o0
F004050C: 7fffe447                 call    _nfs_invalidate_caches
F0040510: 9010001a                 mov     %i2, %o0
F0040514: 81c7e008                 ret
F0040518: 81e80000                 restore
