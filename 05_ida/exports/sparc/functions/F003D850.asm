F003D850: 9de3be20                 save    %sp, -0x1E0, %sp
F003D854: a8100018                 mov     %i0, %l4
F003D858: 113c0434901220f8         set     aRoot, %o0! "root"
F003D860: 4001a6b9                 call    _getfsname
F003D864: 9210001a                 mov     %i2, %o1
F003D868: 7fffa68c                 call    _pn_alloc
F003D86C: 9007beb0                 add     %fp, var_150, %o0
F003D870: e207beb4                 ld      [%fp+__src], %l1
F003D874: a0102000                 mov     0, %l0
F003D878: 2b3c0434                 sethi   -0xFEF3000, %l5
F003D87C: 273c0434                 sethi   -0xFEF3000, %l3
F003D880: 253c0434                 sethi   -0xFEF3000, %l2
F003D884: d04e8000                 ldsb    [%i2], %o0
F003D888: 80a22000                 cmp     %o0, 0
F003D88C: 12800003                 bne     loc_F003D898
F003D890: 9010001a                 mov     %i2, %o0
F003D894: 90156100                 or      %l5, 0x100, %o0
F003D898: 9207bee0                 add     %fp, var_120, %o1
F003D89C: 9407bfe8                 add     %fp, var_18, %o2
F003D8A0: 4000024d                 call    sub_F003E1D4
F003D8A4: 96100011                 mov     %l1, %o3
F003D8A8: b0100008                 mov     %o0, %i0
F003D8AC: 80a6203c                 cmp     %i0, 0x3C ! '<'
F003D8B0: 12800010                 bne     loc_F003D8F0
F003D8B4: 01000000                 nop
F003D8B8: 80a42000                 cmp     %l0, 0
F003D8BC: 1280000d                 bne     loc_F003D8F0
F003D8C0: 80a6203c                 cmp     %i0, 0x3C ! '<'
F003D8C4: d04e8000                 ldsb    [%i2], %o0! char *
F003D8C8: 80a22000                 cmp     %o0, 0
F003D8CC: 02800004                 be      loc_F003D8DC
F003D8D0: d404e0f0                 ld      [%l3+0xF0], %o2
F003D8D4: 10800003                 ba      loc_F003D8E0
F003D8D8: 9210001a                 mov     %i2, %o1
F003D8DC: 9214a108                 or      %l2, 0x108, %o1
F003D8E0: 7fff5b5e                 call    _printf
F003D8E4: 9010000a                 mov     %o2, %o0
F003D8E8: a0102001                 mov     1, %l0
F003D8EC: 80a6203c                 cmp     %i0, 0x3C ! '<'
F003D8F0: 22bfffe6                 be,a    loc_F003D888
F003D8F4: d04e8000                 ldsb    [%i2], %o0
F003D8F8: 80a62000                 cmp     %i0, 0
F003D8FC: 02800006                 be      loc_F003D914
F003D900: 113c0434                 sethi   %hi(aRpcErrorDuring), %o0! "RPC error during bootparam request: %d"...
F003D904: 90122110                 bset    %lo(aRpcErrorDuring), %o0! "RPC error during bootparam request: %d"...
F003D908: 7fff5b54                 call    _printf
F003D90C: 92100018                 mov     %i0, %o1
F003D910: 308000c5                 ba,a    loc_F003DC24
F003D914: 80a42000                 cmp     %l0, 0
F003D918: 02800004                 be      loc_F003D928
F003D91C: 113c0434                 sethi   %hi(aBootparamRespo), %o0! "Bootparam response received\n"
F003D920: 7fff5b4e                 call    _printf
F003D924: 90122138                 bset    %lo(aBootparamRespo), %o0! "Bootparam response received\n"
F003D928: a407bfe8                 add     %fp, var_18, %l2
F003D92C: 90100012                 mov     %l2, %o0
F003D930: a607bee0                 add     %fp, var_120, %l3
F003D934: 92100013                 mov     %l3, %o1
F003D938: 94100011                 mov     %l1, %o2
F003D93C: a007bec0                 add     %fp, var_140, %l0
F003D940: 4000029b                 call    sub_F003E3AC
F003D944: 96100010                 mov     %l0, %o3
F003D948: b0920000                 orcc    %o0, %g0, %i0
F003D94C: 02800008                 be      loc_F003D96C
F003D950: 90103fff                 mov     -1, %o0
F003D954: 7fffa6e5                 call    _pn_free
F003D958: 9007beb0                 add     %fp, var_150, %o0
F003D95C: 113c043490122158         set     aMountRootSSFai, %o0! "mount root %s:%s failed, rpc status %d"...
F003D964: 10800083                 ba      loc_F003DB70
F003D968: 92100013                 mov     %l3, %o1
F003D96C: d023a05c                 st      %o0, [%sp+0x1E0+var_184]
F003D970: c023a060                 clr     [%sp+0x1E0+var_180]
F003D974: 9007be8c                 add     %fp, var_174, %o0
F003D978: 92100014                 mov     %l4, %o1
F003D97C: 94100012                 mov     %l2, %o2
F003D980: 96100010                 mov     %l0, %o3
F003D984: 98100013                 mov     %l3, %o4
F003D988: 400003bd                 call    sub_F003E87C
F003D98C: 9a102000                 mov     0, %o5
F003D990: b0920000                 orcc    %o0, %g0, %i0
F003D994: 128000a4                 bne     loc_F003DC24
F003D998: 90102000                 mov     0, %o0
F003D99C: 92100014                 mov     %l4, %o1
F003D9A0: 7fff997d                 call    _vfs_add
F003D9A4: 94102000                 mov     0, %o2
F003D9A8: b0920000                 orcc    %o0, %g0, %i0
F003D9AC: 1280009e                 bne     loc_F003DC24
F003D9B0: 94102e10                 mov     0xE10, %o2
F003D9B4: d0052128                 ld      [%l4+0x128], %o0
F003D9B8: d4222060                 st      %o2, [%o0+0x60]
F003D9BC: 11000023                 sethi   0x8C00, %o0
F003D9C0: d2052128                 ld      [%l4+0x128], %o1
F003D9C4: 901220a0                 bset    0xA0, %o0
F003D9C8: d0226064                 st      %o0, [%o1+0x64]
F003D9CC: d2052128                 ld      [%l4+0x128], %o1
F003D9D0: a0102000                 mov     0, %l0
F003D9D4: d4226068                 st      %o2, [%o1+0x68]
F003D9D8: d2052128                 ld      [%l4+0x128], %o1
F003D9DC: 2d3c0434                 sethi   -0xFEF3000, %l6
F003D9E0: d022606c                 st      %o0, [%o1+0x6C]
F003D9E4: d4052128                 ld      [%l4+0x128], %o2
F003D9E8: 2b3c0434                 sethi   -0xFEF3000, %l5
F003D9EC: d002a014                 ld      [%o2+0x14], %o0
F003D9F0: 13010000                 sethi   0x4000000, %o1
F003D9F4: 90120009                 bset    %o1, %o0
F003D9F8: d207be8c                 ld      [%fp+var_174], %o1
F003D9FC: d022a014                 st      %o0, [%o2+0x14]
F003DA00: d0026024                 ld      [%o1+0x24], %o0
F003DA04: 7fff99f2                 call    _vfs_unlock
F003DA08: 253c0434                 sethi   -0xFEF3000, %l2
F003DA0C: 9010001a                 mov     %i2, %o0! __dst
F003DA10: d407be8c                 ld      [%fp+var_174], %o2
F003DA14: 92100013                 mov     %l3, %o1! __src
F003DA18: 7fff26c4                 call    _strcpy
F003DA1C: d4264000                 st      %o2, [%i1]
F003DA20: 9210203a                 mov     0x3A, %o1! __src
F003DA24: d22a0000                 stb     %o1, [%o0]
F003DA28: 90022001                 inc     %o0
F003DA2C: 7fff26bf                 call    _strcpy
F003DA30: 92100011                 mov     %l1, %o1
F003DA34: c02fbe90                 clrb    [%fp+var_170]
F003DA38: 113c043490122180         set     aPrivate_2, %o0! "private"
F003DA40: 4001a641                 call    _getfsname
F003DA44: 9207be90                 add     %fp, var_170, %o1
F003DA48: d04fbe90                 ldsb    [%fp+var_170], %o0
F003DA4C: 80a22000                 cmp     %o0, 0
F003DA50: 12800003                 bne     loc_F003DA5C
F003DA54: 9007be90                 add     %fp, var_170, %o0
F003DA58: 9015a188                 or      %l6, 0x188, %o0
F003DA5C: 9207bee0                 add     %fp, var_120, %o1
F003DA60: 9407bfe8                 add     %fp, var_18, %o2
F003DA64: 400001dc                 call    sub_F003E1D4
F003DA68: 96100011                 mov     %l1, %o3
F003DA6C: b0100008                 mov     %o0, %i0
F003DA70: 80a6203c                 cmp     %i0, 0x3C ! '<'
F003DA74: 12800010                 bne     loc_F003DAB4
F003DA78: 01000000                 nop
F003DA7C: 80a42000                 cmp     %l0, 0
F003DA80: 1280000d                 bne     loc_F003DAB4
F003DA84: 80a6203c                 cmp     %i0, 0x3C ! '<'
F003DA88: d04fbe90                 ldsb    [%fp+var_170], %o0! char *
F003DA8C: 80a22000                 cmp     %o0, 0
F003DA90: 02800004                 be      loc_F003DAA0
F003DA94: d40560f0                 ld      [%l5+0xF0], %o2
F003DA98: 10800003                 ba      loc_F003DAA4
F003DA9C: 9207be90                 add     %fp, var_170, %o1
F003DAA0: 9214a190                 or      %l2, 0x190, %o1
F003DAA4: 7fff5aed                 call    _printf
F003DAA8: 9010000a                 mov     %o2, %o0
F003DAAC: a0102001                 mov     1, %l0
F003DAB0: 80a6203c                 cmp     %i0, 0x3C ! '<'
F003DAB4: 22bfffe6                 be,a    loc_F003DA4C
F003DAB8: d04fbe90                 ldsb    [%fp+var_170], %o0
F003DABC: 80a62000                 cmp     %i0, 0
F003DAC0: 0280000d                 be      loc_F003DAF4
F003DAC4: 80a62016                 cmp     %i0, 0x16
F003DAC8: 12800007                 bne     loc_F003DAE4
F003DACC: 113c0434                 sethi   -0xFEF3000, %o0
F003DAD0: 113c0434                 sethi   %hi(aUsingPrivateFr), %o0! "Using /private from root mount point\n"
F003DAD4: 7fff5ae1                 call    _printf
F003DAD8: 90122198                 bset    %lo(aUsingPrivateFr), %o0! "Using /private from root mount point\n"
F003DADC: 10800052                 ba      loc_F003DC24
F003DAE0: b0102000                 mov     0, %i0
F003DAE4: 901221c0                 bset    0x1C0, %o0! char *
F003DAE8: 7fff5adc                 call    _printf
F003DAEC: 92100018                 mov     %i0, %o1! int
F003DAF0: 3080004d                 ba,a    loc_F003DC24
F003DAF4: 80a42000                 cmp     %l0, 0
F003DAF8: 02800004                 be      loc_F003DB08
F003DAFC: 113c0434                 sethi   %hi(aBootparamRespo_0), %o0! "Bootparam response received\n"
F003DB00: 7fff5ad6                 call    _printf
F003DB04: 901221e8                 bset    %lo(aBootparamRespo_0), %o0! "Bootparam response received\n"
F003DB08: 90100011                 mov     %l1, %o0! char *
F003DB0C: 7fff1dcf                 call    _index
F003DB10: 92102040                 mov     0x40, %o1 ! '@'
F003DB14: a0920000                 orcc    %o0, %g0, %l0
F003DB18: 02800005                 be      loc_F003DB2C
F003DB1C: 113c0434                 sethi   -0xFEF3000, %o0
F003DB20: c02c0000                 clrb    [%l0]
F003DB24: 10800003                 ba      loc_F003DB30
F003DB28: a0042001                 inc     %l0
F003DB2C: a0122208                 or      %o0, 0x208, %l0
F003DB30: b407bfe8                 add     %fp, var_18, %i2
F003DB34: 9010001a                 mov     %i2, %o0
F003DB38: a407bee0                 add     %fp, var_120, %l2
F003DB3C: 92100012                 mov     %l2, %o1
F003DB40: 94100011                 mov     %l1, %o2
F003DB44: aa07bec0                 add     %fp, var_140, %l5
F003DB48: 40000219                 call    sub_F003E3AC
F003DB4C: 96100015                 mov     %l5, %o3
F003DB50: b0920000                 orcc    %o0, %g0, %i0
F003DB54: 0280000b                 be      loc_F003DB80
F003DB58: 113c04d4                 sethi   -0xFECB000, %o0
F003DB5C: 7fffa663                 call    _pn_free
F003DB60: 9007beb0                 add     %fp, var_150, %o0
F003DB64: 113c043490122218         set     aMountPrivateSS, %o0! "mount private %s:%s failed, rpc status "...
F003DB6C: 92100012                 mov     %l2, %o1
F003DB70: 94100011                 mov     %l1, %o2
F003DB74: 7fff5ab9                 call    _printf
F003DB78: 96100018                 mov     %i0, %o3
F003DB7C: 3080006e                 ba,a    locret_F003DD34
F003DB80: d0022160                 ld      [%o0+0x160], %o0
F003DB84: d4022004                 ld      [%o0+4], %o2
F003DB88: 273c04d4                 sethi   %hi(_rootdir), %l3
F003DB8C: d402a008                 ld      [%o2+8], %o2
F003DB90: 9fc28000                 call    %o2
F003DB94: 9214e158                 or      %l3, %lo(_rootdir), %o1
F003DB98: 80a22000                 cmp     %o0, 0
F003DB9C: 02800004                 be      loc_F003DBAC
F003DBA0: 113c0434                 sethi   %hi(aNfsMountrootCa), %o0! "nfs_mountroot: can't find root vnode"
F003DBA4: 7fff5d73                 call    _panic
F003DBA8: 90122248                 bset    %lo(aNfsMountrootCa), %o0! "nfs_mountroot: can't find root vnode"
F003DBAC: 233c04cf                 sethi   %hi(_active_u), %l1
F003DBB0: d40461d8                 ld      [%l1+%lo(_active_u)], %o2
F003DBB4: d204e158                 ld      [%l3+0x158], %o1
F003DBB8: 90100010                 mov     %l0, %o0
F003DBBC: d222a15c                 st      %o1, [%o2+0x15C]
F003DBC0: d40461d8                 ld      [%l1+%lo(_active_u)], %o2
F003DBC4: 96102000                 mov     0, %o3
F003DBC8: da02a15c                 ld      [%o2+0x15C], %o5
F003DBCC: 92102001                 mov     1, %o1
F003DBD0: d8136006                 lduh    [%o5+6], %o4
F003DBD4: 94102001                 mov     1, %o2
F003DBD8: 98032001                 inc     %o4
F003DBDC: d8336006                 sth     %o4, [%o5+6]
F003DBE0: da0461d8                 ld      [%l1+%lo(_active_u)], %o5
F003DBE4: 9807be88                 add     %fp, var_178, %o4
F003DBE8: 7fffa377                 call    _lookupname
F003DBEC: c0236160                 clr     [%o5+0x160]
F003DBF0: b0920000                 orcc    %o0, %g0, %i0
F003DBF4: 12800007                 bne     loc_F003DC10
F003DBF8: 113c0434                 sethi   -0xFEF3000, %o0
F003DBFC: d007be88                 ld      [%fp+var_178], %o0
F003DC00: 80a22000                 cmp     %o0, 0
F003DC04: 1280000b                 bne     loc_F003DC30
F003DC08: d00461d8                 ld      [%l1+0x1D8], %o0
F003DC0C: 113c0434                 sethi   -0xFEF3000, %o0! char *
F003DC10: 7fff5a92                 call    _printf
F003DC14: 90122270                 bset    0x270, %o0
F003DC18: d00461d8                 ld      [%l1+0x1D8], %o0
F003DC1C: 7fffabd2                 call    _vn_rele
F003DC20: d002215c                 ld      [%o0+0x15C], %o0
F003DC24: 7fffa631                 call    _pn_free
F003DC28: 9007beb0                 add     %fp, var_150, %o0
F003DC2C: 30800042                 ba,a    locret_F003DD34
F003DC30: 7fffabcd                 call    _vn_rele
F003DC34: d002215c                 ld      [%o0+0x15C], %o0
F003DC38: 7fffabcb                 call    _vn_rele
F003DC3C: d004e158                 ld      [%l3+0x158], %o0
F003DC40: 7fffa016                 call    _dnlc_purge
F003DC44: 01000000                 nop
F003DC48: 4000a90a                 call    _kalloc
F003DC4C: 9010212c                 mov     0x12C, %o0
F003DC50: b2100008                 mov     %o0, %i1
F003DC54: c0264000                 clr     [%i1]
F003DC58: 113c043490122090         set     _nfs_vfsops, %o0
F003DC60: d0266004                 st      %o0, [%i1+4]
F003DC64: c026600c                 clr     [%i1+0xC]
F003DC68: c026601c                 clr     [%i1+0x1C]
F003DC6C: c0266128                 clr     [%i1+0x128]
F003DC70: c0266120                 clr     [%i1+0x120]
F003DC74: 9007be8c                 add     %fp, var_174, %o0
F003DC78: 92100019                 mov     %i1, %o1
F003DC7C: d80461d8                 ld      [%l1+0x1D8], %o4
F003DC80: 9410001a                 mov     %i2, %o2
F003DC84: da03201c                 ld      [%o4+0x1C], %o5
F003DC88: 96100015                 mov     %l5, %o3
F003DC8C: c4136002                 lduh    [%o5+2], %g2
F003DC90: 98100012                 mov     %l2, %o4
F003DC94: 9a102000                 mov     0, %o5
F003DC98: c4366124                 sth     %g2, [%i1+0x124]
F003DC9C: 84103fff                 mov     -1, %g2
F003DCA0: c423a05c                 st      %g2, [%sp+0x1E0+var_184]
F003DCA4: 400002f6                 call    sub_F003E87C
F003DCA8: c023a060                 clr     [%sp+0x1E0+var_180]
F003DCAC: b0920000                 orcc    %o0, %g0, %i0
F003DCB0: 1280001c                 bne     loc_F003DD20
F003DCB4: d007be88                 ld      [%fp+var_178], %o0
F003DCB8: 92100019                 mov     %i1, %o1
F003DCBC: 7fff98b6                 call    _vfs_add
F003DCC0: 94102000                 mov     0, %o2
F003DCC4: b0920000                 orcc    %o0, %g0, %i0
F003DCC8: 12800014                 bne     loc_F003DD18
F003DCCC: 13000005                 sethi   0x1400, %o1
F003DCD0: d0052128                 ld      [%l4+0x128], %o0
F003DCD4: 92126370                 bset    0x370, %o1
F003DCD8: d2222064                 st      %o1, [%o0+0x64]
F003DCDC: d4052128                 ld      [%l4+0x128], %o2! __n
F003DCE0: 90052020                 add     %l4, 0x20, %o0 ! ' '! __dst
F003DCE4: d222a06c                 st      %o1, [%o2+0x6C]
F003DCE8: d207beb4                 ld      [%fp+__src], %o1! __src
F003DCEC: 7fff270c                 call    _strncpy
F003DCF0: 941020ff                 mov     0xFF, %o2
F003DCF4: d007be8c                 ld      [%fp+var_174], %o0
F003DCF8: 7fff9935                 call    _vfs_unlock
F003DCFC: d0022024                 ld      [%o0+0x24], %o0
F003DD00: 7ffffa36                 call    _nfs_netboot_prealloc
F003DD04: d0052128                 ld      [%l4+0x128], %o0
F003DD08: 7fffa5f8                 call    _pn_free
F003DD0C: 9007beb0                 add     %fp, var_150, %o0
F003DD10: 10800009                 ba      locret_F003DD34
F003DD14: b0102000                 mov     0, %i0
F003DD18: 40000376                 call    sub_F003EAF0
F003DD1C: 90100019                 mov     %i1, %o0
F003DD20: 7fffa5f2                 call    _pn_free
F003DD24: 9007beb0                 add     %fp, var_150, %o0
F003DD28: 90100019                 mov     %i1, %o0
F003DD2C: 4000a91d                 call    _kfree
F003DD30: 9210212c                 mov     0x12C, %o1
F003DD34: 81c7e008                 ret
F003DD38: 81e80000                 restore
