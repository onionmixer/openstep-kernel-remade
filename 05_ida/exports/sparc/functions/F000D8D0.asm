F000D8D0: 9de3bf98                 save    %sp, -0x68, %sp
F000D8D4: 113c04d3                 sethi   %hi(_mpid), %o0
F000D8D8: d2022280                 ld      [%o0+%lo(_mpid)], %o1
F000D8DC: d4062068                 ld      [%i0+0x68], %o2
F000D8E0: 92026001                 inc     %o1
F000D8E4: d2222280                 st      %o1, [%o0+%lo(_mpid)]
F000D8E8: e402a038                 ld      [%o2+0x38], %l2
F000D8EC: 153c04d3                 sethi   %hi(_mpid), %o2
F000D8F0: d202a280                 ld      [%o2+%lo(_mpid)], %o1
F000D8F4: 1100001d9012212f         set     0x752F, %o0
F000D8FC: 80a24008                 cmp     %o1, %o0
F000D900: 04800006                 ble     loc_F000D918
F000D904: 90102064                 mov     0x64, %o0 ! 'd'
F000D908: d022a280                 st      %o0, [%o2+%lo(_mpid)]
F000D90C: 113c042c                 sethi   %hi(dword_F010B080), %o0
F000D910: c0222080                 clr     [%o0+%lo(dword_F010B080)]
F000D914: d202a280                 ld      [%o2+%lo(_mpid)], %o1
F000D918: 153c042c                 sethi   %hi(dword_F010B080), %o2
F000D91C: d002a080                 ld      [%o2+%lo(dword_F010B080)], %o0
F000D920: 80a24008                 cmp     %o1, %o0
F000D924: 06800036                 bl      loc_F000D9FC
F000D928: 98102000                 mov     0, %o4
F000D92C: 1100001d90122130         set     0x7530, %o0
F000D934: d022a080                 st      %o0, [%o2+%lo(dword_F010B080)]
F000D938: 113c04d3                 sethi   %hi(_allproc), %o0
F000D93C: e0022278                 ld      [%o0+%lo(_allproc)], %l0
F000D940: 80a42000                 cmp     %l0, 0
F000D944: 02800028                 be      loc_F000D9E4
F000D948: 80a32000                 cmp     %o4, 0
F000D94C: 173c04d3                 sethi   -0xFECB400, %o3
F000D950: 153c042c                 sethi   -0xFEF5000, %o2
F000D954: d0542030                 ldsh    [%l0+0x30], %o0
F000D958: d202e280                 ld      [%o3+0x280], %o1
F000D95C: 80a20009                 cmp     %o0, %o1
F000D960: 02800007                 be      loc_F000D97C
F000D964: 90026001                 add     %o1, 1, %o0
F000D968: d054202e                 ldsh    [%l0+0x2E], %o0
F000D96C: 80a20009                 cmp     %o0, %o1
F000D970: 32800008                 bne,a   loc_F000D990
F000D974: d2542030                 ldsh    [%l0+0x30], %o1
F000D978: 90026001                 add     %o1, 1, %o0
F000D97C: d202a080                 ld      [%o2+0x80], %o1
F000D980: 80a20009                 cmp     %o0, %o1
F000D984: 16bfffda                 bge     loc_F000D8EC
F000D988: d022e280                 st      %o0, [%o3+0x280]
F000D98C: d2542030                 ldsh    [%l0+0x30], %o1
F000D990: d002e280                 ld      [%o3+0x280], %o0
F000D994: 80a24008                 cmp     %o1, %o0
F000D998: 04800005                 ble     loc_F000D9AC
F000D99C: d002a080                 ld      [%o2+0x80], %o0
F000D9A0: 80a20009                 cmp     %o0, %o1
F000D9A4: 34800002                 bg,a    loc_F000D9AC
F000D9A8: d222a080                 st      %o1, [%o2+0x80]
F000D9AC: d254202e                 ldsh    [%l0+0x2E], %o1
F000D9B0: d002e280                 ld      [%o3+0x280], %o0
F000D9B4: 80a24008                 cmp     %o1, %o0
F000D9B8: 24800007                 ble,a   loc_F000D9D4
F000D9BC: e0042008                 ld      [%l0+8], %l0
F000D9C0: d002a080                 ld      [%o2+0x80], %o0
F000D9C4: 80a20009                 cmp     %o0, %o1
F000D9C8: 34800002                 bg,a    loc_F000D9D0
F000D9CC: d222a080                 st      %o1, [%o2+0x80]
F000D9D0: e0042008                 ld      [%l0+8], %l0
F000D9D4: 80a42000                 cmp     %l0, 0
F000D9D8: 32bfffe0                 bne,a   loc_F000D958
F000D9DC: d0542030                 ldsh    [%l0+0x30], %o0
F000D9E0: 80a32000                 cmp     %o4, 0
F000D9E4: 12800007                 bne     loc_F000DA00
F000D9E8: 213c04d3                 sethi   -0xFECB400, %l0
F000D9EC: 113c04d3                 sethi   %hi(_zombproc), %o0
F000D9F0: e0022270                 ld      [%o0+%lo(_zombproc)], %l0
F000D9F4: 10bfffd3                 ba      loc_F000D940
F000D9F8: 98102001                 mov     1, %o4
F000D9FC: 213c04d3                 sethi   -0xFECB400, %l0
F000DA00: d2042280                 ld      [%l0+0x280], %o1
F000DA04: 40000472                 call    _insert_posix_proc
F000DA08: 9010001a                 mov     %i2, %o0
F000DA0C: 80a22000                 cmp     %o0, 0
F000DA10: 12800006                 bne     loc_F000DA28
F000DA14: 233c04d2                 sethi   -0xFECB800, %l1
F000DA18: d0042280                 ld      [%l0+0x280], %o0
F000DA1C: 90022001                 inc     %o0
F000DA20: 10bfffb3                 ba      loc_F000D8EC
F000DA24: d0242280                 st      %o0, [%l0+0x280]
F000DA28: e00462e0                 ld      [%l1+0x2E0], %l0
F000DA2C: 80a42000                 cmp     %l0, 0
F000DA30: 3280000e                 bne,a   loc_F000DA68
F000DA34: c0242060                 clr     [%l0+0x60]
F000DA38: 400002c2                 call    _getproc
F000DA3C: 01000000                 nop
F000DA40: a0920000                 orcc    %o0, %g0, %l0
F000DA44: 32800006                 bne,a   loc_F000DA5C
F000DA48: d00462e0                 ld      [%l1+0x2E0], %o0
F000DA4C: 113c042c                 sethi   %hi(aNoProcs), %o0! "no procs"
F000DA50: 40001dc8                 call    _panic
F000DA54: 90122088                 bset    %lo(aNoProcs), %o0! "no procs"
F000DA58: d00462e0                 ld      [%l1+0x2E0], %o0
F000DA5C: d0242008                 st      %o0, [%l0+8]
F000DA60: e02462e0                 st      %l0, [%l1+0x2E0]
F000DA64: c0242060                 clr     [%l0+0x60]
F000DA68: c024205c                 clr     [%l0+0x5C]
F000DA6C: 113c04d2                 sethi   %hi(_freeproc), %o0
F000DA70: d2042008                 ld      [%l0+8], %o1
F000DA74: 17000010                 sethi   0x4000, %o3
F000DA78: d22222e0                 st      %o1, [%o0+%lo(_freeproc)]
F000DA7C: 90102004                 mov     4, %o0
F000DA80: d02c2013                 stb     %o0, [%l0+0x13]
F000DA84: d0062028                 ld      [%i0+0x28], %o0
F000DA88: 13008420                 sethi   0x2108000, %o1
F000DA8C: 900a0009                 and     %o0, %o1, %o0
F000DA90: 90122001                 bset    1, %o0
F000DA94: d2042014                 ld      [%l0+0x14], %o1
F000DA98: d0242028                 st      %o0, [%l0+0x28]
F000DA9C: d016202c                 lduh    [%i0+0x2C], %o0
F000DAA0: 962a400b                 andn    %o1, %o3, %o3
F000DAA4: d034202c                 sth     %o0, [%l0+0x2C]
F000DAA8: d2062028                 ld      [%i0+0x28], %o1
F000DAAC: 15100000                 sethi   0x40000000, %o2
F000DAB0: d0042028                 ld      [%l0+0x28], %o0
F000DAB4: 920a400a                 and     %o1, %o2, %o1
F000DAB8: 90120009                 bset    %o1, %o0
F000DABC: d0242028                 st      %o0, [%l0+0x28]
F000DAC0: d0062014                 ld      [%i0+0x14], %o0
F000DAC4: 13000010                 sethi   0x4000, %o1
F000DAC8: 900a0009                 and     %o0, %o1, %o0
F000DACC: 9612c008                 bset    %o0, %o3
F000DAD0: d6242014                 st      %o3, [%l0+0x14]
F000DAD4: 40000413                 call    _get_posix_proc
F000DAD8: d0562030                 ldsh    [%i0+0x30], %o0
F000DADC: a2100008                 mov     %o0, %l1
F000DAE0: d0146004                 lduh    [%l1+4], %o0
F000DAE4: d036a004                 sth     %o0, [%i2+4]
F000DAE8: d0146006                 lduh    [%l1+6], %o0
F000DAEC: d036a006                 sth     %o0, [%i2+6]
F000DAF0: d0146008                 lduh    [%l1+8], %o0
F000DAF4: d036a008                 sth     %o0, [%i2+8]
F000DAF8: d0046010                 ld      [%l1+0x10], %o0
F000DAFC: 13200000                 sethi   0x80000000, %o1
F000DB00: d026a010                 st      %o0, [%i2+0x10]
F000DB04: d006a018                 ld      [%i2+0x18], %o0
F000DB08: c026a014                 clr     [%i2+0x14]
F000DB0C: 922a0009                 andn    %o0, %o1, %o1
F000DB10: 11100000                 sethi   0x40000000, %o0
F000DB14: 902a4008                 andn    %o1, %o0, %o0
F000DB18: d026a018                 st      %o0, [%i2+0x18]
F000DB1C: d016202e                 lduh    [%i0+0x2E], %o0
F000DB20: d034202e                 sth     %o0, [%l0+0x2E]
F000DB24: d00e2015                 ldub    [%i0+0x15], %o0
F000DB28: d02c2015                 stb     %o0, [%l0+0x15]
F000DB2C: d0068000                 ld      [%i2], %o0
F000DB30: d0342030                 sth     %o0, [%l0+0x30]
F000DB34: d0162030                 lduh    [%i0+0x30], %o0
F000DB38: d0342032                 sth     %o0, [%l0+0x32]
F000DB3C: f0242044                 st      %i0, [%l0+0x44]
F000DB40: d0062048                 ld      [%i0+0x48], %o0
F000DB44: d024204c                 st      %o0, [%l0+0x4C]
F000DB48: d0062048                 ld      [%i0+0x48], %o0
F000DB4C: 80a22000                 cmp     %o0, 0
F000DB50: 32800002                 bne,a   loc_F000DB58
F000DB54: e0222050                 st      %l0, [%o0+0x50]
F000DB58: c0242050                 clr     [%l0+0x50]
F000DB5C: c0242048                 clr     [%l0+0x48]
F000DB60: e0262048                 st      %l0, [%i0+0x48]
F000DB64: c02c2014                 clrb    [%l0+0x14]
F000DB68: c02c2012                 clrb    [%l0+0x12]
F000DB6C: d006201c                 ld      [%i0+0x1C], %o0
F000DB70: d024201c                 st      %o0, [%l0+0x1C]
F000DB74: d0062024                 ld      [%i0+0x24], %o0
F000DB78: d0242024                 st      %o0, [%l0+0x24]
F000DB7C: d2062020                 ld      [%i0+0x20], %o1
F000DB80: 90100010                 mov     %l0, %o0
F000DB84: d2242020                 st      %o1, [%l0+0x20]
F000DB88: c024207c                 clr     [%l0+0x7C]
F000DB8C: c0242080                 clr     [%l0+0x80]
F000DB90: c0342034                 clrh    [%l0+0x34]
F000DB94: c0242018                 clr     [%l0+0x18]
F000DB98: c02c2017                 clrb    [%l0+0x17]
F000DB9C: d4042014                 ld      [%l0+0x14], %o2
F000DBA0: 13000020                 sethi   0x8000, %o1
F000DBA4: 922a8009                 andn    %o2, %o1, %o1
F000DBA8: 4000025b                 call    _pidhash_enter
F000DBAC: d2242014                 st      %o1, [%l0+0x14]
F000DBB0: d204a15c                 ld      [%l2+0x15C], %o1
F000DBB4: 80a26000                 cmp     %o1, 0
F000DBB8: 22800006                 be,a    loc_F000DBD0
F000DBBC: d204a160                 ld      [%l2+0x160], %o1
F000DBC0: d0126006                 lduh    [%o1+6], %o0
F000DBC4: 90022001                 inc     %o0
F000DBC8: d0326006                 sth     %o0, [%o1+6]
F000DBCC: d204a160                 ld      [%l2+0x160], %o1
F000DBD0: 80a26000                 cmp     %o1, 0
F000DBD4: 22800006                 be,a    loc_F000DBEC
F000DBD8: d404a01c                 ld      [%l2+0x1C], %o2
F000DBDC: d0126006                 lduh    [%o1+6], %o0
F000DBE0: 90022001                 inc     %o0
F000DBE4: d0326006                 sth     %o0, [%o1+6]
F000DBE8: d404a01c                 ld      [%l2+0x1C], %o2
F000DBEC: d2128000                 lduh    [%o2], %o1
F000DBF0: 90100010                 mov     %l0, %o0
F000DBF4: 92026001                 inc     %o1
F000DBF8: d2328000                 sth     %o1, [%o2]
F000DBFC: d4062028                 ld      [%i0+0x28], %o2
F000DC00: 92100018                 mov     %i0, %o1
F000DC04: 9412a100                 bset    0x100, %o2
F000DC08: d4262028                 st      %o2, [%i0+0x28]
F000DC0C: c0242070                 clr     [%l0+0x70]
F000DC10: c0242074                 clr     [%l0+0x74]
F000DC14: 4001f11b                 call    _procdup
F000DC18: c0242078                 clr     [%l0+0x78]
F000DC1C: d4042068                 ld      [%l0+0x68], %o2
F000DC20: d202a038                 ld      [%o2+0x38], %o1
F000DC24: 96102000                 mov     0, %o3
F000DC28: d2026154                 ld      [%o1+0x154], %o1
F000DC2C: 80a2c009                 cmp     %o3, %o1
F000DC30: 14800018                 bg      loc_F000DC90
F000DC34: a4100008                 mov     %o0, %l2
F000DC38: 193fffc0                 sethi   -0x10000, %o4
F000DC3C: d002a038                 ld      [%o2+0x38], %o0
F000DC40: d402214c                 ld      [%o0+0x14C], %o2
F000DC44: 912ae002                 sll     %o3, 2, %o0
F000DC48: d2028008                 ld      [%o2+%o0], %o1
F000DC4C: 80a26000                 cmp     %o1, 0
F000DC50: 2280000a                 be,a    loc_F000DC78
F000DC54: d4042068                 ld      [%l0+0x68], %o2
F000DC58: 80a2400c                 cmp     %o1, %o4
F000DC5C: 32800004                 bne,a   loc_F000DC6C
F000DC60: d012600e                 lduh    [%o1+0xE], %o0
F000DC64: 10800004                 ba      loc_F000DC74
F000DC68: c0228008                 clr     [%o2+%o0]
F000DC6C: 90022001                 inc     %o0
F000DC70: d032600e                 sth     %o0, [%o1+0xE]
F000DC74: d4042068                 ld      [%l0+0x68], %o2
F000DC78: d002a038                 ld      [%o2+0x38], %o0
F000DC7C: d0022154                 ld      [%o0+0x154], %o0
F000DC80: 9602e001                 inc     %o3
F000DC84: 80a2c008                 cmp     %o3, %o0
F000DC88: 24bfffee                 ble,a   loc_F000DC40
F000DC8C: d002a038                 ld      [%o2+0x38], %o0
F000DC90: d0042068                 ld      [%l0+0x68], %o0
F000DC94: d0022038                 ld      [%o0+0x38], %o0
F000DC98: 92102001                 mov     1, %o1
F000DC9C: 40016c1b                 call    _lock_init
F000DCA0: 90022020                 inc     0x20, %o0 ! ' '
F000DCA4: 40000045                 call    _uarea_init
F000DCA8: 90100012                 mov     %l2, %o0
F000DCAC: d004600c                 ld      [%l1+0xC], %o0
F000DCB0: 133c04d3                 sethi   %hi(_allproc), %o1
F000DCB4: d4026278                 ld      [%o1+%lo(_allproc)], %o2
F000DCB8: d026a00c                 st      %o0, [%i2+0xC]
F000DCBC: e024600c                 st      %l0, [%l1+0xC]
F000DCC0: d4242008                 st      %o2, [%l0+8]
F000DCC4: 90042008                 add     %l0, 8, %o0
F000DCC8: d022a00c                 st      %o0, [%o2+0xC]
F000DCCC: 90126278                 or      %o1, %lo(_allproc), %o0
F000DCD0: d024200c                 st      %o0, [%l0+0xC]
F000DCD4: e0226278                 st      %l0, [%o1+%lo(_allproc)]
F000DCD8: 90102003                 mov     3, %o0
F000DCDC: 40022401                 call    _spl0
F000DCE0: d02c2013                 stb     %o0, [%l0+0x13]
F000DCE4: d0062028                 ld      [%i0+0x28], %o0
F000DCE8: 900a3eff                 and     %o0, -0x101, %o0
F000DCEC: d0262028                 st      %o0, [%i0+0x28]
F000DCF0: 81c7e008                 ret
F000DCF4: 91e80012                 restore %g0, %l2, %o0
