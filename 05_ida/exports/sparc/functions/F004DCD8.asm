F004DCD8: 9de3bf98                 save    %sp, -0x68, %sp
F004DCDC: a4100018                 mov     %i0, %l2
F004DCE0: 912ca010                 sll     %l2, 16, %o0
F004DCE4: a13a2010                 sra     %o0, 16, %l0
F004DCE8: 400009c9                 call    _getmp
F004DCEC: 90100010                 mov     %l0, %o0
F004DCF0: a6920000                 orcc    %o0, %g0, %l3
F004DCF4: 32800006                 bne,a   loc_F004DD0C
F004DCF8: d004e00c                 ld      [%l3+0xC], %o0
F004DCFC: 113c043b                 sethi   %hi(aIgetBadDev), %o0! "iget: bad dev"
F004DD00: 7fff1d1c                 call    _panic
F004DD04: 90122030                 bset    %lo(aIgetBadDev), %o0! "iget: bad dev"
F004DD08: d004e00c                 ld      [%l3+0xC], %o0
F004DD0C: d0022020                 ld      [%o0+0x20], %o0
F004DD10: 80a20019                 cmp     %o0, %i1
F004DD14: 02800004                 be      loc_F004DD24
F004DD18: 113c043b                 sethi   %hi(aIgetBadFs), %o0! "iget: bad fs"
F004DD1C: 7fff1d15                 call    _panic
F004DD20: 90122040                 bset    %lo(aIgetBadFs), %o0! "iget: bad fs"
F004DD24: 9204001a                 add     %l0, %i2, %o1
F004DD28: 920a61ff                 and     %o1, 0x1FF, %o1
F004DD2C: 932a6003                 sll     %o1, 3, %o1
F004DD30: 113c04eb901221b0         set     _ihead, %o0
F004DD38: f0024008                 ld      [%o1+%o0], %i0
F004DD3C: a2024008                 add     %o1, %o0, %l1
F004DD40: 80a60011                 cmp     %i0, %l1
F004DD44: 22800039                 be,a    loc_F004DE28
F004DD48: 213c04eb                 sethi   -0xFEC5400, %l0
F004DD4C: 92100010                 mov     %l0, %o1
F004DD50: 153c04eb                 sethi   -0xFEC5400, %o2
F004DD54: d0062048                 ld      [%i0+0x48], %o0
F004DD58: 80a68008                 cmp     %i2, %o0
F004DD5C: 3280002f                 bne,a   loc_F004DE18
F004DD60: f0060000                 ld      [%i0], %i0
F004DD64: d0562046                 ldsh    [%i0+0x46], %o0
F004DD68: 80a24008                 cmp     %o1, %o0
F004DD6C: 3280002b                 bne,a   loc_F004DE18
F004DD70: f0060000                 ld      [%i0], %i0
F004DD74: d0162044                 lduh    [%i0+0x44], %o0
F004DD78: 808a2001                 btst    1, %o0
F004DD7C: 12800048                 bne     loc_F004DE9C
F004DD80: 808a2100                 btst    0x100, %o0
F004DD84: 32800011                 bne,a   loc_F004DDC8
F004DD88: 90122100                 bset    0x100, %o0
F004DD8C: d206205c                 ld      [%i0+0x5C], %o1
F004DD90: 80a26000                 cmp     %o1, 0
F004DD94: 02800004                 be      loc_F004DDA4
F004DD98: d0062060                 ld      [%i0+0x60], %o0
F004DD9C: 10800003                 ba      loc_F004DDA8
F004DDA0: d0226060                 st      %o0, [%o1+0x60]
F004DDA4: d022a1a8                 st      %o0, [%o2+0x1A8]
F004DDA8: d0062060                 ld      [%i0+0x60], %o0
F004DDAC: d2220000                 st      %o1, [%o0]
F004DDB0: c026205c                 clr     [%i0+0x5C]
F004DDB4: d006200c                 ld      [%i0+0xC], %o0
F004DDB8: c0262060                 clr     [%i0+0x60]
F004DDBC: c0220000                 clr     [%o0]
F004DDC0: d0162044                 lduh    [%i0+0x44], %o0
F004DDC4: 90122100                 bset    0x100, %o0
F004DDC8: 808a2001                 btst    1, %o0
F004DDCC: 0280000c                 be      loc_F004DDFC
F004DDD0: d0362044                 sth     %o0, [%i0+0x44]
F004DDD4: 90100018                 mov     %i0, %o0! unsigned int
F004DDD8: d4162044                 lduh    [%i0+0x44], %o2
F004DDDC: 9210200a                 mov     0xA, %o1
F004DDE0: 9412a010                 bset    0x10, %o2
F004DDE4: 7fff1225                 call    _sleep
F004DDE8: d4362044                 sth     %o2, [%i0+0x44]
F004DDEC: d0162044                 lduh    [%i0+0x44], %o0
F004DDF0: 808a2001                 btst    1, %o0
F004DDF4: 12bffff9                 bne     loc_F004DDD8
F004DDF8: 90100018                 mov     %i0, %o0
F004DDFC: d2162044                 lduh    [%i0+0x44], %o1
F004DE00: d0162012                 lduh    [%i0+0x12], %o0
F004DE04: 92126001                 bset    1, %o1
F004DE08: d2362044                 sth     %o1, [%i0+0x44]
F004DE0C: 90022001                 inc     %o0
F004DE10: 108000e0                 ba      locret_F004E190
F004DE14: d0362012                 sth     %o0, [%i0+0x12]
F004DE18: 80a60011                 cmp     %i0, %l1
F004DE1C: 32bfffcf                 bne,a   loc_F004DD58
F004DE20: d0062048                 ld      [%i0+0x48], %o0
F004DE24: 213c04eb                 sethi   -0xFEC5400, %l0
F004DE28: f00421a0                 ld      [%l0+0x1A0], %i0
F004DE2C: 80a62000                 cmp     %i0, 0
F004DE30: 32800024                 bne,a   loc_F004DEC0
F004DE34: d206205c                 ld      [%i0+0x5C], %o1
F004DE38: 7fffff23                 call    _new_inode
F004DE3C: 01000000                 nop
F004DE40: b0920000                 orcc    %o0, %g0, %i0
F004DE44: 1280001d                 bne     loc_F004DEB8
F004DE48: d00421a0                 ld      [%l0+0x1A0], %o0
F004DE4C: 10800008                 ba      loc_F004DE6C
F004DE50: 80a22000                 cmp     %o0, 0
F004DE54: 7fff5fd2                 call    _dnlc_purge1
F004DE58: 01000000                 nop
F004DE5C: 80a22001                 cmp     %o0, 1
F004DE60: 12800005                 bne     loc_F004DE74
F004DE64: d00421a0                 ld      [%l0+0x1A0], %o0
F004DE68: 80a22000                 cmp     %o0, 0
F004DE6C: 02bffffa                 be      loc_F004DE54
F004DE70: 01000000                 nop
F004DE74: 113c04eb                 sethi   %hi(_ifreeh), %o0
F004DE78: f00221a0                 ld      [%o0+%lo(_ifreeh)], %i0
F004DE7C: 80a62000                 cmp     %i0, 0
F004DE80: 12bfff99                 bne     loc_F004DCE4
F004DE84: 912ca010                 sll     %l2, 16, %o0
F004DE88: 113c043b                 sethi   %hi(aIgetOutOfInode), %o0! "iget: out of inode space\n"
F004DE8C: 7fff1cb9                 call    _panic
F004DE90: 90122050                 bset    %lo(aIgetOutOfInode), %o0! "iget: out of inode space\n"
F004DE94: 1080000b                 ba      loc_F004DEC0
F004DE98: d206205c                 ld      [%i0+0x5C], %o1
F004DE9C: 90122010                 bset    0x10, %o0
F004DEA0: d0362044                 sth     %o0, [%i0+0x44]
F004DEA4: 90100018                 mov     %i0, %o0! unsigned int
F004DEA8: 7fff11f4                 call    _sleep
F004DEAC: 9210200a                 mov     0xA, %o1
F004DEB0: 10bfff8d                 ba      loc_F004DCE4
F004DEB4: 912ca010                 sll     %l2, 16, %o0
F004DEB8: d026205c                 st      %o0, [%i0+0x5C]
F004DEBC: d206205c                 ld      [%i0+0x5C], %o1
F004DEC0: 80a26000                 cmp     %o1, 0
F004DEC4: 02800005                 be      loc_F004DED8
F004DEC8: 113c04eb                 sethi   %hi(_ifreeh), %o0
F004DECC: 901221a0                 bset    %lo(_ifreeh), %o0
F004DED0: d0226060                 st      %o0, [%o1+0x60]
F004DED4: 113c04eb                 sethi   -0xFEC5400, %o0
F004DED8: d22221a0                 st      %o1, [%o0+0x1A0]
F004DEDC: c026205c                 clr     [%i0+0x5C]
F004DEE0: c0262060                 clr     [%i0+0x60]
F004DEE4: 40007ab0                 call    _mfs_uncache
F004DEE8: 9006200c                 add     %i0, 0xC, %o0
F004DEEC: 90102100                 mov     0x100, %o0
F004DEF0: d0362044                 sth     %o0, [%i0+0x44]
F004DEF4: d0162044                 lduh    [%i0+0x44], %o0
F004DEF8: d2162012                 lduh    [%i0+0x12], %o1
F004DEFC: 90122001                 bset    1, %o0
F004DF00: 80a26000                 cmp     %o1, 0
F004DF04: 02800005                 be      loc_F004DF18
F004DF08: d0362044                 sth     %o0, [%i0+0x44]
F004DF0C: 113c043b                 sethi   %hi(aFreeInodeIsnT_0), %o0! "free inode isn't"
F004DF10: 7fff1c98                 call    _panic
F004DF14: 90122070                 bset    %lo(aFreeInodeIsnT_0), %o0! "free inode isn't"
F004DF18: d2060000                 ld      [%i0], %o1
F004DF1C: d0062004                 ld      [%i0+4], %o0
F004DF20: d0226004                 st      %o0, [%o1+4]
F004DF24: d2062004                 ld      [%i0+4], %o1
F004DF28: d0060000                 ld      [%i0], %o0
F004DF2C: d0224000                 st      %o0, [%o1]
F004DF30: d0044000                 ld      [%l1], %o0
F004DF34: d0260000                 st      %o0, [%i0]
F004DF38: e2262004                 st      %l1, [%i0+4]
F004DF3C: d0044000                 ld      [%l1], %o0
F004DF40: f0222004                 st      %i0, [%o0+4]
F004DF44: f0244000                 st      %i0, [%l1]
F004DF48: e4362046                 sth     %l2, [%i0+0x46]
F004DF4C: d004e008                 ld      [%l3+8], %o0
F004DF50: d0262040                 st      %o0, [%i0+0x40]
F004DF54: f4262048                 st      %i2, [%i0+0x48]
F004DF58: c026204c                 clr     [%i0+0x4C]
F004DF5C: f2262050                 st      %i1, [%i0+0x50]
F004DF60: c0262058                 clr     [%i0+0x58]
F004DF64: e40660b8                 ld      [%i1+0xB8], %l2
F004DF68: 9010001a                 mov     %i2, %o0
F004DF6C: 7ffee1a5                 call    _udiv
F004DF70: 92100012                 mov     %l2, %o1
F004DF74: a2100008                 mov     %o0, %l1
F004DF78: d00660bc                 ld      [%i1+0xBC], %o0
F004DF7C: 7ffee161                 call    _umul
F004DF80: 92100011                 mov     %l1, %o1
F004DF84: d4066018                 ld      [%i1+0x18], %o2
F004DF88: a0100008                 mov     %o0, %l0
F004DF8C: d206601c                 ld      [%i1+0x1C], %o1
F004DF90: 9010000a                 mov     %o2, %o0
F004DF94: 7ffee15b                 call    _umul
F004DF98: 922c4009                 andn    %l1, %o1, %o1
F004DF9C: 96100008                 mov     %o0, %o3
F004DFA0: 9010001a                 mov     %i2, %o0
F004DFA4: 92100012                 mov     %l2, %o1
F004DFA8: d4066010                 ld      [%i1+0x10], %o2
F004DFAC: a004000b                 add     %l0, %o3, %l0
F004DFB0: 7ffee23c                 call    _urem
F004DFB4: a004000a                 add     %l0, %o2, %l0
F004DFB8: 7ffee192                 call    _udiv
F004DFBC: d2066078                 ld      [%i1+0x78], %o1
F004DFC0: d2062040                 ld      [%i0+0x40], %o1
F004DFC4: d8066060                 ld      [%i1+0x60], %o4
F004DFC8: 96100008                 mov     %o0, %o3
F004DFCC: d4066030                 ld      [%i1+0x30], %o2! __n
F004DFD0: 90100009                 mov     %o1, %o0
F004DFD4: 972ac00c                 sll     %o3, %o4, %o3
F004DFD8: d2066064                 ld      [%i1+0x64], %o1
F004DFDC: a004000b                 add     %l0, %o3, %l0
F004DFE0: 7fff5950                 call    _bread
F004DFE4: 932c0009                 sll     %l0, %o1, %o1
F004DFE8: a2100008                 mov     %o0, %l1
F004DFEC: d0044000                 ld      [%l1], %o0
F004DFF0: 808a2004                 btst    4, %o0
F004DFF4: 2280002e                 be,a    loc_F004E0AC
F004DFF8: d2066078                 ld      [%i1+0x78], %o1
F004DFFC: 7fff5a1b                 call    _brelse
F004E000: 90100011                 mov     %l1, %o0
F004E004: d2060000                 ld      [%i0], %o1
F004E008: d0062004                 ld      [%i0+4], %o0
F004E00C: d0226004                 st      %o0, [%o1+4]
F004E010: d2062004                 ld      [%i0+4], %o1
F004E014: d0060000                 ld      [%i0], %o0
F004E018: d0224000                 st      %o0, [%o1]
F004E01C: f0260000                 st      %i0, [%i0]
F004E020: f0262004                 st      %i0, [%i0+4]
F004E024: c0262048                 clr     [%i0+0x48]
F004E028: c0362012                 clrh    [%i0+0x12]
F004E02C: 1100003f                 sethi   0xFC00, %o0
F004E030: d2162044                 lduh    [%i0+0x44], %o1
F004E034: 901223fe                 bset    0x3FE, %o0
F004E038: 920a4008                 and     %o1, %o0, %o1
F004E03C: 808a6010                 btst    0x10, %o1
F004E040: 02800008                 be      loc_F004E060
F004E044: d2362044                 sth     %o1, [%i0+0x44]
F004E048: 1100003f901223ef         set     0xFFEF, %o0
F004E050: 900a4008                 and     %o1, %o0, %o0
F004E054: d0362044                 sth     %o0, [%i0+0x44]
F004E058: 7fff1364                 call    _wakeup
F004E05C: 90100018                 mov     %i0, %o0
F004E060: 133c04eb                 sethi   %hi(_ifreeh), %o1
F004E064: d00261a0                 ld      [%o1+%lo(_ifreeh)], %o0
F004E068: c0362044                 clrh    [%i0+0x44]
F004E06C: 80a22000                 cmp     %o0, 0
F004E070: 02800007                 be      loc_F004E08C
F004E074: 901261a0                 or      %o1, %lo(_ifreeh), %o0
F004E078: 113c04eb                 sethi   %hi(_ifreet), %o0
F004E07C: d20221a8                 ld      [%o0+%lo(_ifreet)], %o1
F004E080: f0224000                 st      %i0, [%o1]
F004E084: 10800003                 ba      loc_F004E090
F004E088: d00221a8                 ld      [%o0+%lo(_ifreet)], %o0
F004E08C: f02261a0                 st      %i0, [%o1+0x1A0]
F004E090: d0262060                 st      %o0, [%i0+0x60]
F004E094: c026205c                 clr     [%i0+0x5C]
F004E098: 9206205c                 add     %i0, 0x5C, %o1 ! '\'
F004E09C: 113c04eb                 sethi   %hi(_ifreet), %o0
F004E0A0: d22221a8                 st      %o1, [%o0+%lo(_ifreet)]
F004E0A4: 1080003b                 ba      locret_F004E190
F004E0A8: b0102000                 mov     0, %i0
F004E0AC: 9010001a                 mov     %i2, %o0
F004E0B0: 7ffee1fc                 call    _urem
F004E0B4: e0046020                 ld      [%l1+0x20], %l0
F004E0B8: 92100008                 mov     %o0, %o1
F004E0BC: 90062064                 add     %i0, 0x64, %o0 ! 'd'! __dst
F004E0C0: 932a6007                 sll     %o1, 7, %o1
F004E0C4: 92040009                 add     %l0, %o1, %o1! __src
F004E0C8: 7ffee476                 call    _memcpy
F004E0CC: 94102080                 mov     0x80, %o2
F004E0D0: c0362010                 clrh    [%i0+0x10]
F004E0D4: 90102001                 mov     1, %o0
F004E0D8: d0362012                 sth     %o0, [%i0+0x12]
F004E0DC: c0362016                 clrh    [%i0+0x16]
F004E0E0: c0362014                 clrh    [%i0+0x14]
F004E0E4: d004c000                 ld      [%l3], %o0
F004E0E8: d0262030                 st      %o0, [%i0+0x30]
F004E0EC: d0162064                 lduh    [%i0+0x64], %o0
F004E0F0: 1300003c                 sethi   0xF000, %o1
F004E0F4: 900a0009                 and     %o0, %o1, %o0
F004E0F8: 9132200d                 srl     %o0, 13, %o0
F004E0FC: 133c043a921263bc         set     _iftovt_tab, %o1
F004E104: 912a2002                 sll     %o0, 2, %o0
F004E108: d2020009                 ld      [%o0+%o1], %o1
F004E10C: 80a6a002                 cmp     %i2, 2
F004E110: d2262034                 st      %o1, [%i0+0x34]
F004E114: c026202c                 clr     [%i0+0x2C]
F004E118: c0262024                 clr     [%i0+0x24]
F004E11C: d006208c                 ld      [%i0+0x8C], %o0
F004E120: c0262020                 clr     [%i0+0x20]
F004E124: 12800005                 bne     loc_F004E138
F004E128: d0362038                 sth     %o0, [%i0+0x38]
F004E12C: d0162010                 lduh    [%i0+0x10], %o0
F004E130: 90122001                 bset    1, %o0
F004E134: d0362010                 sth     %o0, [%i0+0x10]
F004E138: d0062030                 ld      [%i0+0x30], %o0
F004E13C: d0522124                 ldsh    [%o0+0x124], %o0
F004E140: 80a22000                 cmp     %o0, 0
F004E144: 0280000c                 be      loc_F004E174
F004E148: 01000000                 nop
F004E14C: d0162068                 lduh    [%i0+0x68], %o0
F004E150: d216206a                 lduh    [%i0+0x6A], %o1
F004E154: d03620e4                 sth     %o0, [%i0+0xE4]
F004E158: d0062030                 ld      [%i0+0x30], %o0
F004E15C: d23620e6                 sth     %o1, [%i0+0xE6]
F004E160: d2122124                 lduh    [%o0+0x124], %o1
F004E164: 113c043a                 sethi   %hi(_nogroup), %o0
F004E168: d01223b8                 lduh    [%o0+%lo(_nogroup)], %o0
F004E16C: d2362068                 sth     %o1, [%i0+0x68]
F004E170: d036206a                 sth     %o0, [%i0+0x6A]
F004E174: 7fff59bd                 call    _brelse
F004E178: 90100011                 mov     %l1, %o0
F004E17C: d006200c                 ld      [%i0+0xC], %o0
F004E180: c0220000                 clr     [%o0]
F004E184: d206200c                 ld      [%i0+0xC], %o1
F004E188: d0062070                 ld      [%i0+0x70], %o0
F004E18C: d0226014                 st      %o0, [%o1+0x14]
F004E190: 81c7e008                 ret
F004E194: 81e80000                 restore
