F002D9D0: 9de3bf50                 save    %sp, -0xB0, %sp
F002D9D4: aa102000                 mov     0, %l5
F002D9D8: a007bfd8                 add     %fp, var_28, %l0
F002D9DC: 92100010                 mov     %l0, %o1! void *
F002D9E0: d006e004                 ld      [%i3+4], %o0! void *
F002D9E4: 9410201c                 mov     0x1C, %o2! size_t
F002D9E8: f4068000                 ld      [%i2], %i2
F002D9EC: 40019c49                 call    _bcopy
F002D9F0: 9006c008                 add     %i3, %o0, %o0
F002D9F4: 90102806                 mov     0x806, %o0
F002D9F8: d037bfb8                 sth     %o0, [%fp+var_48]
F002D9FC: 113c0430a6122354         set     _arpethertempl, %l3
F002DA04: d417bfdc                 lduh    [%fp+var_24], %o2
F002DA08: 1100003f                 sethi   0xFC00, %o0
F002DA0C: d214e004                 lduh    [%l3+4], %o1
F002DA10: 901223ff                 bset    0x3FF, %o0
F002DA14: ec17bfda                 lduh    [%fp+var_26], %l6
F002DA18: a4100010                 mov     %l0, %l2
F002DA1C: 940a8008                 and     %o2, %o0, %o2
F002DA20: 920a4008                 and     %o1, %o0, %o1
F002DA24: 80a28009                 cmp     %o2, %o1
F002DA28: 12800137                 bne     loc_F002DF04
F002DA2C: e817bfde                 lduh    [%fp+var_22], %l4
F002DA30: 9207bfb4                 add     %fp, var_4C, %o1! void *
F002DA34: d00ce004                 ldub    [%l3+4], %o0
F002DA38: 94102004                 mov     4, %o2! size_t
F002DA3C: 90022008                 inc     8, %o0! void *
F002DA40: 40019c34                 call    _bcopy
F002DA44: 90048008                 add     %l2, %o0, %o0
F002DA48: 9207bfb0                 add     %fp, var_50, %o1! void *
F002DA4C: d00ce004                 ldub    [%l3+4], %o0
F002DA50: 94102004                 mov     4, %o2! size_t
F002DA54: d60ce005                 ldub    [%l3+5], %o3
F002DA58: 912a2001                 sll     %o0, 1, %o0
F002DA5C: 9002000b                 add     %o0, %o3, %o0
F002DA60: 90022008                 inc     8, %o0! void *
F002DA64: 40019c2b                 call    _bcopy
F002DA68: 90048008                 add     %l2, %o0, %o0
F002DA6C: a007bfe0                 add     %fp, var_20, %l0
F002DA70: 90100010                 mov     %l0, %o0! void *
F002DA74: d40ce004                 ldub    [%l3+4], %o2! size_t
F002DA78: 7fff6139                 call    _bcmp
F002DA7C: 92100019                 mov     %i1, %o1
F002DA80: 80a22000                 cmp     %o0, 0
F002DA84: 02800120                 be      loc_F002DF04
F002DA88: 90100010                 mov     %l0, %o0! void *
F002DA8C: 133c043092126370         set     _etherbroadcastaddr, %o1! void *
F002DA94: 7fff6132                 call    _bcmp
F002DA98: 94102006                 mov     6, %o2
F002DA9C: 80a22000                 cmp     %o0, 0
F002DAA0: 12800008                 bne     loc_F002DAC0
F002DAA4: d007bfb4                 ld      [%fp+var_4C], %o0
F002DAA8: 90102003                 mov     3, %o0! __x
F002DAAC: d407bfb4                 ld      [%fp+var_4C], %o2
F002DAB0: 133c0430                 sethi   %hi(aArpEtherAddres), %o1! "arp: ether address is broadcast for IP "...
F002DAB4: 7fff9b40                 call    _log
F002DAB8: 921263b0                 bset    %lo(aArpEtherAddres), %o1! "arp: ether address is broadcast for IP "...
F002DABC: 30800112                 ba,a    loc_F002DF04
F002DAC0: 80a2001a                 cmp     %o0, %i2
F002DAC4: 12800011                 bne     loc_F002DB08
F002DAC8: 233c0430                 sethi   %hi(aDuplicateIpAdd), %l1! "duplicate IP address!! sent from ethern"...
F002DACC: 90100010                 mov     %l0, %o0
F002DAD0: 213c0430a01423e8         set     aSS_0, %l0! "%s: %s\n"
F002DAD8: 400002bb                 call    _ether_sprintf
F002DADC: a21463f0                 bset    %lo(aDuplicateIpAdd), %l1! "duplicate IP address!! sent from ethern"...
F002DAE0: 96100008                 mov     %o0, %o3
F002DAE4: 90102003                 mov     3, %o0! __x
F002DAE8: 92100010                 mov     %l0, %o1
F002DAEC: 7fff9b32                 call    _log
F002DAF0: 94100011                 mov     %l1, %o2
F002DAF4: 80a52001                 cmp     %l4, 1
F002DAF8: 12800103                 bne     loc_F002DF04
F002DAFC: f427bfb0                 st      %i2, [%fp+var_50]
F002DB00: 1080005b                 ba      loc_F002DC6C
F002DB04: a2102000                 mov     0, %l1
F002DB08: 4001a42c                 call    _spltty
F002DB0C: 01000000                 nop
F002DB10: 92102013                 mov     0x13, %o1
F002DB14: e007bfb4                 ld      [%fp+var_4C], %l0
F002DB18: ae100008                 mov     %o0, %l7
F002DB1C: 7fff6361                 call    _urem
F002DB20: 90100010                 mov     %l0, %o0
F002DB24: 932a2001                 sll     %o0, 1, %o1
F002DB28: 92024008                 add     %o1, %o0, %o1
F002DB2C: 952a6004                 sll     %o1, 4, %o2
F002DB30: 94228009                 sub     %o2, %o1, %o2
F002DB34: 952aa002                 sll     %o2, 2, %o2
F002DB38: 113c04d590122270         set     _arptab, %o0
F002DB40: a2028008                 add     %o2, %o0, %l1
F002DB44: 92102000                 mov     0, %o1! void *
F002DB48: d0044000                 ld      [%l1], %o0
F002DB4C: 80a20010                 cmp     %o0, %l0
F002DB50: 3280000a                 bne,a   loc_F002DB78
F002DB54: 92026001                 inc     %o1
F002DB58: 80a62000                 cmp     %i0, 0
F002DB5C: 0280000b                 be      loc_F002DB88
F002DB60: 80a26008                 cmp     %o1, 8
F002DB64: d0046010                 ld      [%l1+0x10], %o0
F002DB68: 80a20018                 cmp     %o0, %i0
F002DB6C: 02800007                 be      loc_F002DB88
F002DB70: 80a26008                 cmp     %o1, 8
F002DB74: 92026001                 inc     %o1
F002DB78: 80a26008                 cmp     %o1, 8
F002DB7C: 04bffff3                 ble     loc_F002DB48
F002DB80: a2046014                 inc     0x14, %l1
F002DB84: 80a26008                 cmp     %o1, 8
F002DB88: 34800002                 bg,a    loc_F002DB90
F002DB8C: a2102000                 mov     0, %l1
F002DB90: 80a46000                 cmp     %l1, 0
F002DB94: 0280001d                 be      loc_F002DC08
F002DB98: 9004a008                 add     %l2, 8, %o0! void *
F002DB9C: d40ce004                 ldub    [%l3+4], %o2! size_t
F002DBA0: 40019bdc                 call    _bcopy
F002DBA4: 92046004                 add     %l1, 4, %o1
F002DBA8: d40ce004                 ldub    [%l3+4], %o2
F002DBAC: 80a2a005                 cmp     %o2, 5
F002DBB0: 18800006                 bgu     loc_F002DBC8
F002DBB4: 9002a004                 add     %o2, 4, %o0
F002DBB8: 90044008                 add     %l1, %o0, %o0! void *
F002DBBC: 92102006                 mov     6, %o1! size_t
F002DBC0: 40019ca6                 call    _bzero
F002DBC4: 9222400a                 sub     %o1, %o2, %o1
F002DBC8: d00c600b                 ldub    [%l1+0xB], %o0
F002DBCC: d204600c                 ld      [%l1+0xC], %o1
F002DBD0: 90122002                 bset    2, %o0
F002DBD4: 80a26000                 cmp     %o1, 0
F002DBD8: 0280000b                 be      loc_F002DC04
F002DBDC: d02c600b                 stb     %o0, [%l1+0xB]
F002DBE0: 90102002                 mov     2, %o0
F002DBE4: d037bfc8                 sth     %o0, [%fp+var_38]
F002DBE8: d207bfb4                 ld      [%fp+var_4C], %o1
F002DBEC: 90100018                 mov     %i0, %o0
F002DBF0: d227bfcc                 st      %o1, [%fp+var_34]
F002DBF4: d204600c                 ld      [%l1+0xC], %o1
F002DBF8: 7ffff9b4                 call    _if_output_mbuf
F002DBFC: 9407bfc8                 add     %fp, var_38, %o2
F002DC00: c024600c                 clr     [%l1+0xC]
F002DC04: 80a46000                 cmp     %l1, 0
F002DC08: 12800017                 bne     loc_F002DC64
F002DC0C: d007bfb0                 ld      [%fp+var_50], %o0
F002DC10: 80a2001a                 cmp     %o0, %i2
F002DC14: 12800014                 bne     loc_F002DC64
F002DC18: 90100018                 mov     %i0, %o0
F002DC1C: 400000cf                 call    _arptnew
F002DC20: 9207bfb4                 add     %fp, var_4C, %o1! void *
F002DC24: a2100008                 mov     %o0, %l1
F002DC28: 9004a008                 add     %l2, 8, %o0! void *
F002DC2C: d40ce004                 ldub    [%l3+4], %o2! size_t
F002DC30: 40019bb8                 call    _bcopy
F002DC34: 92046004                 add     %l1, 4, %o1
F002DC38: d40ce004                 ldub    [%l3+4], %o2
F002DC3C: 80a2a005                 cmp     %o2, 5
F002DC40: 18800006                 bgu     loc_F002DC58
F002DC44: 92102006                 mov     6, %o1! size_t
F002DC48: 9002a004                 add     %o2, 4, %o0
F002DC4C: 90044008                 add     %l1, %o0, %o0! void *
F002DC50: 40019c82                 call    _bzero
F002DC54: 9222400a                 sub     %o1, %o2, %o1
F002DC58: d00c600b                 ldub    [%l1+0xB], %o0
F002DC5C: 90122002                 bset    2, %o0
F002DC60: d02c600b                 stb     %o0, [%l1+0xB]
F002DC64: 4001a430                 call    _splx
F002DC68: 90100017                 mov     %l7, %o0
F002DC6C: 80a5a800                 cmp     %l6, 0x800
F002DC70: 0280000f                 be      loc_F002DCAC
F002DC74: 11000004                 sethi   0x1000, %o0
F002DC78: 80a58008                 cmp     %l6, %o0
F002DC7C: 32800013                 bne,a   loc_F002DCC8
F002DC80: e007bfb0                 ld      [%fp+var_50], %l0
F002DC84: 80a46000                 cmp     %l1, 0
F002DC88: 02800005                 be      loc_F002DC9C
F002DC8C: 80a52001                 cmp     %l4, 1
F002DC90: d00c600b                 ldub    [%l1+0xB], %o0
F002DC94: 90122010                 bset    0x10, %o0
F002DC98: d02c600b                 stb     %o0, [%l1+0xB]
F002DC9C: 1280009a                 bne     loc_F002DF04
F002DCA0: 01000000                 nop
F002DCA4: 10800006                 ba      loc_F002DCBC
F002DCA8: d016200c                 lduh    [%i0+0xC], %o0
F002DCAC: 80a52001                 cmp     %l4, 1
F002DCB0: 02800006                 be      loc_F002DCC8
F002DCB4: e007bfb0                 ld      [%fp+var_50], %l0
F002DCB8: d016200c                 lduh    [%i0+0xC], %o0
F002DCBC: 808a2020                 btst    0x20, %o0 ! ' '
F002DCC0: 12800091                 bne     loc_F002DF04
F002DCC4: e007bfb0                 ld      [%fp+var_50], %l0
F002DCC8: 80a4001a                 cmp     %l0, %i2
F002DCCC: 3280000c                 bne,a   loc_F002DCFC
F002DCD0: 90100010                 mov     %l0, %o0
F002DCD4: d40ce004                 ldub    [%l3+4], %o2! size_t
F002DCD8: a004a008                 add     %l2, 8, %l0
F002DCDC: d20ce005                 ldub    [%l3+5], %o1
F002DCE0: 90100010                 mov     %l0, %o0! void *
F002DCE4: 92028009                 add     %o2, %o1, %o1
F002DCE8: 92026008                 inc     8, %o1! void *
F002DCEC: 40019b89                 call    _bcopy
F002DCF0: 92048009                 add     %l2, %o1, %o1
F002DCF4: 1080002f                 ba      loc_F002DDB0
F002DCF8: 90100019                 mov     %i1, %o0
F002DCFC: 7fff62e9                 call    _urem
F002DD00: 92102013                 mov     0x13, %o1
F002DD04: 932a2001                 sll     %o0, 1, %o1
F002DD08: 92024008                 add     %o1, %o0, %o1
F002DD0C: 952a6004                 sll     %o1, 4, %o2
F002DD10: 94228009                 sub     %o2, %o1, %o2
F002DD14: 952aa002                 sll     %o2, 2, %o2
F002DD18: 113c04d590122270         set     _arptab, %o0
F002DD20: a2028008                 add     %o2, %o0, %l1
F002DD24: 92102000                 mov     0, %o1
F002DD28: 94100010                 mov     %l0, %o2
F002DD2C: d0044000                 ld      [%l1], %o0
F002DD30: 80a2000a                 cmp     %o0, %o2
F002DD34: 3280000a                 bne,a   loc_F002DD5C
F002DD38: 92026001                 inc     %o1
F002DD3C: 80a62000                 cmp     %i0, 0
F002DD40: 0280000b                 be      loc_F002DD6C
F002DD44: 80a26008                 cmp     %o1, 8
F002DD48: d0046010                 ld      [%l1+0x10], %o0
F002DD4C: 80a20018                 cmp     %o0, %i0
F002DD50: 02800007                 be      loc_F002DD6C
F002DD54: 80a26008                 cmp     %o1, 8
F002DD58: 92026001                 inc     %o1
F002DD5C: 80a26008                 cmp     %o1, 8
F002DD60: 04bffff3                 ble     loc_F002DD2C
F002DD64: a2046014                 inc     0x14, %l1
F002DD68: 80a26008                 cmp     %o1, 8
F002DD6C: 34800002                 bg,a    loc_F002DD74
F002DD70: a2102000                 mov     0, %l1
F002DD74: 80a46000                 cmp     %l1, 0
F002DD78: 02800063                 be      loc_F002DF04
F002DD7C: 01000000                 nop
F002DD80: d00c600b                 ldub    [%l1+0xB], %o0
F002DD84: 808a2008                 btst    8, %o0
F002DD88: 0280005f                 be      loc_F002DF04
F002DD8C: a004a008                 add     %l2, 8, %l0
F002DD90: d40ce004                 ldub    [%l3+4], %o2! size_t
F002DD94: d20ce005                 ldub    [%l3+5], %o1
F002DD98: 90100010                 mov     %l0, %o0! void *
F002DD9C: 92028009                 add     %o2, %o1, %o1
F002DDA0: 92026008                 inc     8, %o1! void *
F002DDA4: 40019b5b                 call    _bcopy
F002DDA8: 92048009                 add     %l2, %o1, %o1! void *
F002DDAC: 90046004                 add     %l1, 4, %o0! void *
F002DDB0: d40ce004                 ldub    [%l3+4], %o2! size_t
F002DDB4: 40019b57                 call    _bcopy
F002DDB8: 92100010                 mov     %l0, %o1
F002DDBC: d20ce004                 ldub    [%l3+4], %o1
F002DDC0: d40ce005                 ldub    [%l3+5], %o2! size_t
F002DDC4: 90026008                 add     %o1, 8, %o0
F002DDC8: 90048008                 add     %l2, %o0, %o0! void *
F002DDCC: 932a6001                 sll     %o1, 1, %o1
F002DDD0: 9202400a                 add     %o1, %o2, %o1
F002DDD4: 92026008                 inc     8, %o1! void *
F002DDD8: 40019b4e                 call    _bcopy
F002DDDC: 92048009                 add     %l2, %o1, %o1
F002DDE0: d20ce004                 ldub    [%l3+4], %o1
F002DDE4: 9007bfb0                 add     %fp, var_50, %o0! void *
F002DDE8: d40ce005                 ldub    [%l3+5], %o2! size_t
F002DDEC: 92026008                 inc     8, %o1! void *
F002DDF0: 40019b48                 call    _bcopy
F002DDF4: 92048009                 add     %l2, %o1, %o1
F002DDF8: 90102002                 mov     2, %o0
F002DDFC: d40ce004                 ldub    [%l3+4], %o2! size_t
F002DE00: 9207bfba                 add     %fp, var_46, %o1! void *
F002DE04: d034a006                 sth     %o0, [%l2+6]
F002DE08: d00ce005                 ldub    [%l3+5], %o0
F002DE0C: a007bfb8                 add     %fp, var_48, %l0
F002DE10: 90028008                 add     %o2, %o0, %o0
F002DE14: 90022008                 inc     8, %o0! void *
F002DE18: 40019b3e                 call    _bcopy
F002DE1C: 90048008                 add     %l2, %o0, %o0
F002DE20: 90100010                 mov     %l0, %o0! void *
F002DE24: d20ce004                 ldub    [%l3+4], %o1
F002DE28: 94102002                 mov     2, %o2! size_t
F002DE2C: 932a6001                 sll     %o1, 1, %o1
F002DE30: 92026002                 inc     2, %o1! void *
F002DE34: 40019b37                 call    _bcopy
F002DE38: 92020009                 add     %o0, %o1, %o1
F002DE3C: 80a52002                 cmp     %l4, 2
F002DE40: 12800005                 bne     loc_F002DE54
F002DE44: 80a5a800                 cmp     %l6, 0x800
F002DE48: 11000004                 sethi   0x1000, %o0
F002DE4C: 1080000e                 ba      loc_F002DE84
F002DE50: d034a002                 sth     %o0, [%l2+2]
F002DE54: 1280000d                 bne     loc_F002DE88
F002DE58: 113c0430                 sethi   -0xFEF4000, %o0
F002DE5C: d016200c                 lduh    [%i0+0xC], %o0
F002DE60: 808a2020                 btst    0x20, %o0 ! ' '
F002DE64: 12800009                 bne     loc_F002DE88
F002DE68: 113c0430                 sethi   -0xFEF4000, %o0
F002DE6C: 9010001b                 mov     %i3, %o0
F002DE70: 92102000                 mov     0, %o1
F002DE74: 150ee6b2                 sethi   0x3B9AC800, %o2
F002DE78: 7fffbfb3                 call    _m_copy
F002DE7C: 9412a200                 bset    0x200, %o2
F002DE80: aa100008                 mov     %o0, %l5
F002DE84: 113c0430                 sethi   -0xFEF4000, %o0
F002DE88: 90122354                 bset    0x354, %o0
F002DE8C: 80a4c008                 cmp     %l3, %o0
F002DE90: 12800005                 bne     loc_F002DEA4
F002DE94: 90100012                 mov     %l2, %o0
F002DE98: d014a006                 lduh    [%l2+6], %o0
F002DE9C: d034a006                 sth     %o0, [%l2+6]
F002DEA0: 90100012                 mov     %l2, %o0! void *
F002DEA4: d206e004                 ld      [%i3+4], %o1! void *
F002DEA8: 9410201c                 mov     0x1C, %o2! size_t
F002DEAC: 40019b19                 call    _bcopy
F002DEB0: 9206c009                 add     %i3, %o1, %o1
F002DEB4: c037bfb8                 clrh    [%fp+var_48]
F002DEB8: 90100018                 mov     %i0, %o0
F002DEBC: 9210001b                 mov     %i3, %o1
F002DEC0: a007bfb8                 add     %fp, var_48, %l0
F002DEC4: 7ffff901                 call    _if_output_mbuf
F002DEC8: 94100010                 mov     %l0, %o2
F002DECC: 80a56000                 cmp     %l5, 0
F002DED0: 0280000f                 be      locret_F002DF0C
F002DED4: 11000004                 sethi   0x1000, %o0
F002DED8: d034a002                 sth     %o0, [%l2+2]
F002DEDC: 90100012                 mov     %l2, %o0! void *
F002DEE0: d2056004                 ld      [%l5+4], %o1! void *
F002DEE4: 9410201c                 mov     0x1C, %o2! size_t
F002DEE8: 40019b0a                 call    _bcopy
F002DEEC: 92054009                 add     %l5, %o1, %o1
F002DEF0: 90100018                 mov     %i0, %o0
F002DEF4: 92100015                 mov     %l5, %o1
F002DEF8: 7ffff8f4                 call    _if_output_mbuf
F002DEFC: 94100010                 mov     %l0, %o2
F002DF00: 30800003                 ba,a    locret_F002DF0C
F002DF04: 7fffbf58                 call    _m_freem
F002DF08: 9010001b                 mov     %i3, %o0
F002DF0C: 81c7e008                 ret
F002DF10: 81e80000                 restore
