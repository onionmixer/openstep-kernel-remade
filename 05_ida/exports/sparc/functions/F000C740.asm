F000C740: 9de3bf88                 save    %sp, -0x78, %sp
F000C744: 400008f7                 call    _get_posix_proc
F000C748: d0562030                 ldsh    [%i0+0x30], %o0
F000C74C: 133c04d0                 sethi   %hi(_active_threads), %o1
F000C750: d4026260                 ld      [%o1+%lo(_active_threads)], %o2
F000C754: d2062078                 ld      [%i0+0x78], %o1
F000C758: 80a28009                 cmp     %o2, %o1
F000C75C: 0280003d                 be      loc_F000C850
F000C760: ac100008                 mov     %o0, %l6
F000C764: a0062070                 add     %i0, 0x70, %l0 ! 'p'
F000C768: d0040000                 ld      [%l0], %o0
F000C76C: 80a22000                 cmp     %o0, 0
F000C770: 12bffffe                 bne     loc_F000C768
F000C774: 01000000                 nop
F000C778: 400229cc                 call    _simple_lock_try
F000C77C: 90100010                 mov     %l0, %o0
F000C780: 80a22000                 cmp     %o0, 0
F000C784: 02bffff9                 be      loc_F000C768
F000C788: 01000000                 nop
F000C78C: 1080001f                 ba      loc_F000C808
F000C790: d0062074                 ld      [%i0+0x74], %o0
F000C794: c0262070                 clr     [%i0+0x70]
F000C798: 80a26000                 cmp     %o1, 0
F000C79C: 02800009                 be      loc_F000C7C0
F000C7A0: a0062070                 add     %i0, 0x70, %l0 ! 'p'
F000C7A4: 113c04d0                 sethi   %hi(_active_threads), %o0
F000C7A8: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F000C7AC: 80a20009                 cmp     %o0, %o1
F000C7B0: 0280018a                 be      locret_F000CDD8
F000C7B4: 01000000                 nop
F000C7B8: 4001a2a9                 call    _thread_hold
F000C7BC: 01000000                 nop
F000C7C0: 400197c0                 call    _thread_block
F000C7C4: 01000000                 nop
F000C7C8: 113c04d0                 sethi   %hi(_active_threads), %o0
F000C7CC: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F000C7D0: d002218c                 ld      [%o0+0x18C], %o0
F000C7D4: 808a2003                 btst    3, %o0
F000C7D8: 12800180                 bne     locret_F000CDD8
F000C7DC: 01000000                 nop
F000C7E0: d0040000                 ld      [%l0], %o0
F000C7E4: 80a22000                 cmp     %o0, 0
F000C7E8: 12bffffe                 bne     loc_F000C7E0
F000C7EC: 01000000                 nop
F000C7F0: 400229ae                 call    _simple_lock_try
F000C7F4: 90100010                 mov     %l0, %o0
F000C7F8: 80a22000                 cmp     %o0, 0
F000C7FC: 02bffff9                 be      loc_F000C7E0
F000C800: 01000000                 nop
F000C804: d0062074                 ld      [%i0+0x74], %o0
F000C808: 80a22000                 cmp     %o0, 0
F000C80C: 32bfffe2                 bne,a   loc_F000C794
F000C810: d2062078                 ld      [%i0+0x78], %o1
F000C814: d0062078                 ld      [%i0+0x78], %o0
F000C818: 80a22000                 cmp     %o0, 0
F000C81C: 32bfffde                 bne,a   loc_F000C794
F000C820: d2062078                 ld      [%i0+0x78], %o1
F000C824: 213c04d0                 sethi   %hi(_active_threads), %l0
F000C828: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F000C82C: d0262078                 st      %o0, [%i0+0x78]
F000C830: c0262070                 clr     [%i0+0x70]
F000C834: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F000C838: 40019b53                 call    _task_hold
F000C83C: d002200c                 ld      [%o0+0xC], %o0
F000C840: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F000C844: d002200c                 ld      [%o0+0xC], %o0
F000C848: 40019b75                 call    _task_dowait
F000C84C: 92102000                 mov     0, %o1
F000C850: e8062068                 ld      [%i0+0x68], %l4
F000C854: 40019bd3                 call    _task_halt
F000C858: 90100014                 mov     %l4, %o0
F000C85C: d0062028                 ld      [%i0+0x28], %o0
F000C860: 94102001                 mov     1, %o2
F000C864: e6052038                 ld      [%l4+0x38], %l3
F000C868: 900a3faf                 and     %o0, -0x51, %o0
F000C86C: 90122400                 bset    0x400, %o0
F000C870: d0262028                 st      %o0, [%i0+0x28]
F000C874: 90103fff                 mov     -1, %o0
F000C878: d0262020                 st      %o0, [%i0+0x20]
F000C87C: 9004e07c                 add     %l3, 0x7C, %o0 ! '|'
F000C880: 92100013                 mov     %l3, %o1
F000C884: d4222030                 st      %o2, [%o0+0x30]
F000C888: 90023ffc                 inc     -4, %o0
F000C88C: 80a20009                 cmp     %o0, %o1
F000C890: 36bffffe                 bge,a   loc_F000C888
F000C894: d4222030                 st      %o2, [%o0+0x30]
F000C898: 113c004d9012202c         set     _realitexpire, %o0
F000C8A0: 7ffff5ed                 call    _untimeout
F000C8A4: 92100018                 mov     %i0, %o1
F000C8A8: d004e154                 ld      [%l3+0x154], %o0
F000C8AC: a2102000                 mov     0, %l1
F000C8B0: 80a44008                 cmp     %l1, %o0
F000C8B4: 34800019                 bg,a    loc_F000C918
F000C8B8: d004e15c                 ld      [%l3+0x15C], %o0
F000C8BC: 2b3fffc0                 sethi   -0x10000, %l5
F000C8C0: d004e14c                 ld      [%l3+0x14C], %o0
F000C8C4: a52c6002                 sll     %l1, 2, %l2
F000C8C8: e0020012                 ld      [%o0+%l2], %l0
F000C8CC: 80a42000                 cmp     %l0, 0
F000C8D0: 0280000a                 be      loc_F000C8F8
F000C8D4: 80a40015                 cmp     %l0, %l5
F000C8D8: 22800009                 be,a    loc_F000C8FC
F000C8DC: d004e150                 ld      [%l3+0x150], %o0
F000C8E0: 40006725                 call    _vno_lockrelease
F000C8E4: 90100010                 mov     %l0, %o0
F000C8E8: d204e14c                 ld      [%l3+0x14C], %o1
F000C8EC: 90100010                 mov     %l0, %o0
F000C8F0: 7ffffafc                 call    _closef
F000C8F4: c0224012                 clr     [%o1+%l2]
F000C8F8: d004e150                 ld      [%l3+0x150], %o0
F000C8FC: c02a0011                 clrb    [%o0+%l1]
F000C900: d004e154                 ld      [%l3+0x154], %o0
F000C904: a2046001                 inc     %l1
F000C908: 80a44008                 cmp     %l1, %o0
F000C90C: 24bfffee                 ble,a   loc_F000C8C4
F000C910: d004e14c                 ld      [%l3+0x14C], %o0
F000C914: d004e15c                 ld      [%l3+0x15C], %o0
F000C918: 80a22000                 cmp     %o0, 0
F000C91C: 22800005                 be,a    loc_F000C930
F000C920: d004e160                 ld      [%l3+0x160], %o0
F000C924: 40007090                 call    _vn_rele
F000C928: 01000000                 nop
F000C92C: d004e160                 ld      [%l3+0x160], %o0
F000C930: 80a22000                 cmp     %o0, 0
F000C934: 22800005                 be,a    loc_F000C948
F000C938: 111fffff                 sethi   0x7FFFFC00, %o0
F000C93C: 4000708a                 call    _vn_rele
F000C940: 01000000                 nop
F000C944: 111fffff                 sethi   0x7FFFFC00, %o0
F000C948: 901223ff                 bset    0x3FF, %o0! char *
F000C94C: 7ffff440                 call    _acct
F000C950: d024e268                 st      %o0, [%l3+0x268]
F000C954: 40000c31                 call    _crfree
F000C958: d004e01c                 ld      [%l3+0x1C], %o0
F000C95C: d206200c                 ld      [%i0+0xC], %o1
F000C960: d0062008                 ld      [%i0+8], %o0
F000C964: 80a22000                 cmp     %o0, 0
F000C968: 02800005                 be      loc_F000C97C
F000C96C: d0224000                 st      %o0, [%o1]
F000C970: d2062008                 ld      [%i0+8], %o1
F000C974: d006200c                 ld      [%i0+0xC], %o0
F000C978: d022600c                 st      %o0, [%o1+0xC]
F000C97C: 153c04d3                 sethi   %hi(_zombproc), %o2
F000C980: d202a270                 ld      [%o2+%lo(_zombproc)], %o1
F000C984: 9612a270                 or      %o2, %lo(_zombproc), %o3
F000C988: 80a26000                 cmp     %o1, 0
F000C98C: 02800004                 be      loc_F000C99C
F000C990: d2262008                 st      %o1, [%i0+8]
F000C994: 90062008                 add     %i0, 8, %o0
F000C998: d022600c                 st      %o0, [%o1+0xC]
F000C99C: d626200c                 st      %o3, [%i0+0xC]
F000C9A0: f022a270                 st      %i0, [%o2+0x270]
F000C9A4: 90102005                 mov     5, %o0
F000C9A8: d02e2013                 stb     %o0, [%i0+0x13]
F000C9AC: 113c04d3                 sethi   %hi(_pidhash), %o0
F000C9B0: d2162030                 lduh    [%i0+0x30], %o1
F000C9B4: 96122170                 or      %o0, %lo(_pidhash), %o3
F000C9B8: a20a603f                 and     %o1, 0x3F, %l1
F000C9BC: 932c6002                 sll     %l1, 2, %o1
F000C9C0: d402400b                 ld      [%o1+%o3], %o2
F000C9C4: 80a6000a                 cmp     %i0, %o2
F000C9C8: 1280000c                 bne     loc_F000C9F8
F000C9CC: 80a2a000                 cmp     %o2, 0
F000C9D0: d0062040                 ld      [%i0+0x40], %o0
F000C9D4: 1080000e                 ba      loc_F000CA0C
F000C9D8: d022400b                 st      %o0, [%o1+%o3]
F000C9DC: d0062040                 ld      [%i0+0x40], %o0
F000C9E0: 10800014                 ba      loc_F000CA30
F000C9E4: d022a040                 st      %o0, [%o2+0x40]
F000C9E8: 80a20018                 cmp     %o0, %i0
F000C9EC: 02bffffc                 be      loc_F000C9DC
F000C9F0: 80a22000                 cmp     %o0, 0
F000C9F4: 94100008                 mov     %o0, %o2
F000C9F8: 32bffffc                 bne,a   loc_F000C9E8
F000C9FC: d002a040                 ld      [%o2+0x40], %o0
F000CA00: 113c042c                 sethi   %hi(aExit), %o0! "exit"
F000CA04: 400021db                 call    _panic
F000CA08: 90122058                 bset    %lo(aExit), %o0! "exit"
F000CA0C: d0562030                 ldsh    [%i0+0x30], %o0
F000CA10: 80a22001                 cmp     %o0, 1
F000CA14: 32800008                 bne,a   loc_F000CA34
F000CA18: f2362034                 sth     %i1, [%i0+0x34]
F000CA1C: 113c042c90122060         set     aInitExitedWith, %o0! "init exited with %d\n"
F000CA24: 40001f0d                 call    _printf
F000CA28: 933e6008                 sra     %i1, 8, %o1
F000CA2C: 30800000                 ba,a    loc_F000CA2C
F000CA30: f2362034                 sth     %i1, [%i0+0x34]
F000CA34: a204e16c                 add     %l3, 0x16C, %l1
F000CA38: c024e16c                 clr     [%l3+0x16C]
F000CA3C: c024e170                 clr     [%l3+0x170]
F000CA40: a404e174                 add     %l3, 0x174, %l2
F000CA44: c024e174                 clr     [%l3+0x174]
F000CA48: c024e178                 clr     [%l3+0x178]
F000CA4C: b205201c                 add     %l4, 0x1C, %i1
F000CA50: d0050000                 ld      [%l4], %o0
F000CA54: 80a22000                 cmp     %o0, 0
F000CA58: 12bffffe                 bne     loc_F000CA50
F000CA5C: 01000000                 nop
F000CA60: 40022912                 call    _simple_lock_try
F000CA64: 90100014                 mov     %l4, %o0
F000CA68: 80a22000                 cmp     %o0, 0
F000CA6C: 02bffff9                 be      loc_F000CA50
F000CA70: 01000000                 nop
F000CA74: 40022845                 call    _splusclock
F000CA78: e0064000                 ld      [%i1], %l0
F000CA7C: 80a64010                 cmp     %i1, %l0
F000CA80: 0280001a                 be      loc_F000CAE8
F000CA84: aa100008                 mov     %o0, %l5
F000CA88: 90100010                 mov     %l0, %o0
F000CA8C: 9207bfe8                 add     %fp, var_18, %o1
F000CA90: 4001abd9                 call    _thread_read_times
F000CA94: 9407bff0                 add     %fp, var_10, %o2
F000CA98: d2044000                 ld      [%l1], %o1
F000CA9C: d007bfe8                 ld      [%fp+var_18], %o0
F000CAA0: d4046004                 ld      [%l1+4], %o2
F000CAA4: 92024008                 add     %o1, %o0, %o1
F000CAA8: d2244000                 st      %o1, [%l1]
F000CAAC: d007bfec                 ld      [%fp+var_14], %o0
F000CAB0: 94028008                 add     %o2, %o0, %o2
F000CAB4: d4246004                 st      %o2, [%l1+4]
F000CAB8: d2048000                 ld      [%l2], %o1
F000CABC: d007bff0                 ld      [%fp+var_10], %o0
F000CAC0: d404a004                 ld      [%l2+4], %o2
F000CAC4: 92024008                 add     %o1, %o0, %o1
F000CAC8: d2248000                 st      %o1, [%l2]
F000CACC: d007bff4                 ld      [%fp+var_C], %o0
F000CAD0: 94028008                 add     %o2, %o0, %o2
F000CAD4: d424a004                 st      %o2, [%l2+4]
F000CAD8: e0042010                 ld      [%l0+0x10], %l0
F000CADC: 80a64010                 cmp     %i1, %l0
F000CAE0: 32bfffeb                 bne,a   loc_F000CA8C
F000CAE4: 90100010                 mov     %l0, %o0
F000CAE8: 4002288f                 call    _splx
F000CAEC: 90100015                 mov     %l5, %o0
F000CAF0: d0044000                 ld      [%l1], %o0
F000CAF4: d2052054                 ld      [%l4+0x54], %o1
F000CAF8: 90020009                 add     %o0, %o1, %o0
F000CAFC: d2046004                 ld      [%l1+4], %o1
F000CB00: d0244000                 st      %o0, [%l1]
F000CB04: d0052058                 ld      [%l4+0x58], %o0
F000CB08: 92024008                 add     %o1, %o0, %o1
F000CB0C: d2246004                 st      %o1, [%l1+4]
F000CB10: d0048000                 ld      [%l2], %o0
F000CB14: d205205c                 ld      [%l4+0x5C], %o1
F000CB18: 90020009                 add     %o0, %o1, %o0
F000CB1C: d204a004                 ld      [%l2+4], %o1
F000CB20: d0248000                 st      %o0, [%l2]
F000CB24: d4052060                 ld      [%l4+0x60], %o2
F000CB28: 9202400a                 add     %o1, %o2, %o1
F000CB2C: d224a004                 st      %o1, [%l2+4]
F000CB30: c0250000                 clr     [%l4]
F000CB34: 40016d4f                 call    _kalloc
F000CB38: 90102048                 mov     0x48, %o0! __dst
F000CB3C: d0262038                 st      %o0, [%i0+0x38]
F000CB40: 133c04cf                 sethi   %hi(_active_u), %o1
F000CB44: d20261d8                 ld      [%o1+%lo(_active_u)], %o1! __src
F000CB48: 94102048                 mov     0x48, %o2 ! 'H'! __n
F000CB4C: 7fffe9d5                 call    _memcpy
F000CB50: 9202616c                 inc     0x16C, %o1
F000CB54: d0062038                 ld      [%i0+0x38], %o0
F000CB58: 40000e2f                 call    _ruadd
F000CB5C: 9204e1b4                 add     %l3, 0x1B4, %o1
F000CB60: d0062048                 ld      [%i0+0x48], %o0
F000CB64: 80a22000                 cmp     %o0, 0
F000CB68: 02800004                 be      loc_F000CB78
F000CB6C: 113c04d1                 sethi   %hi(_init_proc), %o0
F000CB70: 4000189e                 call    _wakeup
F000CB74: d0022338                 ld      [%o0+%lo(_init_proc)], %o0
F000CB78: d0062080                 ld      [%i0+0x80], %o0! unsigned int
F000CB7C: 80a22000                 cmp     %o0, 0
F000CB80: 02800009                 be      loc_F000CBA4
F000CB84: 92102009                 mov     9, %o1! char *
F000CB88: a0100008                 mov     %o0, %l0
F000CB8C: c022207c                 clr     [%o0+0x7C]
F000CB90: d4022028                 ld      [%o0+0x28], %o2
F000CB94: 940abfef                 and     %o2, -0x11, %o2
F000CB98: 40001277                 call    _psignal
F000CB9C: d4222028                 st      %o2, [%o0+0x28]
F000CBA0: c0262080                 clr     [%i0+0x80]
F000CBA4: d2062014                 ld      [%i0+0x14], %o1
F000CBA8: 11000010                 sethi   0x4000, %o0
F000CBAC: 808a4008                 btst    %o0, %o1
F000CBB0: 22800029                 be,a    loc_F000CC54
F000CBB4: e0062048                 ld      [%i0+0x48], %l0
F000CBB8: d005a010                 ld      [%l6+0x10], %o0
F000CBBC: d2022008                 ld      [%o0+8], %o1
F000CBC0: d0026004                 ld      [%o1+4], %o0
F000CBC4: 80a20018                 cmp     %o0, %i0
F000CBC8: 32800018                 bne,a   loc_F000CC28
F000CBCC: d2062014                 ld      [%i0+0x14], %o1
F000CBD0: a0100009                 mov     %o1, %l0
F000CBD4: d0042008                 ld      [%l0+8], %o0
F000CBD8: 80a22000                 cmp     %o0, 0
F000CBDC: 22800012                 be,a    loc_F000CC24
F000CBE0: c0242004                 clr     [%l0+4]
F000CBE4: 40003941                 call    _ttynty
F000CBE8: 01000000                 nop
F000CBEC: 92100008                 mov     %o0, %o1
F000CBF0: d0026008                 ld      [%o1+8], %o0
F000CBF4: 80a20010                 cmp     %o0, %l0
F000CBF8: 3280000b                 bne,a   loc_F000CC24
F000CBFC: c0242004                 clr     [%l0+4]
F000CC00: d002600c                 ld      [%o1+0xC], %o0
F000CC04: 80a22000                 cmp     %o0, 0
F000CC08: 02800004                 be      loc_F000CC18
F000CC0C: 92102001                 mov     1, %o1
F000CC10: 40001240                 call    _pgsignal
F000CC14: 94102001                 mov     1, %o2
F000CC18: 4000275e                 call    _ttywait
F000CC1C: d0042008                 ld      [%l0+8], %o0
F000CC20: c0242004                 clr     [%l0+4]
F000CC24: d2062014                 ld      [%i0+0x14], %o1
F000CC28: 11000010                 sethi   0x4000, %o0
F000CC2C: 808a4008                 btst    %o0, %o1
F000CC30: 22800009                 be,a    loc_F000CC54
F000CC34: e0062048                 ld      [%i0+0x48], %l0
F000CC38: 400007ba                 call    _get_posix_proc
F000CC3C: d0562030                 ldsh    [%i0+0x30], %o0
F000CC40: d2022010                 ld      [%o0+0x10], %o1
F000CC44: 94102000                 mov     0, %o2
F000CC48: 40000758                 call    _fixjobc
F000CC4C: 90100018                 mov     %i0, %o0
F000CC50: e0062048                 ld      [%i0+0x48], %l0
F000CC54: 80a42000                 cmp     %l0, 0
F000CC58: 22800031                 be,a    loc_F000CD1C
F000CC5C: d006207c                 ld      [%i0+0x7C], %o0
F000CC60: 253c04d1                 sethi   -0xFECBC00, %l2
F000CC64: a6102001                 mov     1, %l3
F000CC68: e204204c                 ld      [%l0+0x4C], %l1
F000CC6C: 80a46000                 cmp     %l1, 0
F000CC70: 32800002                 bne,a   loc_F000CC78
F000CC74: c0246050                 clr     [%l1+0x50]
F000CC78: d004a338                 ld      [%l2+0x338], %o0
F000CC7C: d0022048                 ld      [%o0+0x48], %o0
F000CC80: 80a22000                 cmp     %o0, 0
F000CC84: 32800002                 bne,a   loc_F000CC8C
F000CC88: e0222050                 st      %l0, [%o0+0x50]
F000CC8C: d204a338                 ld      [%l2+0x338], %o1
F000CC90: d0026048                 ld      [%o1+0x48], %o0
F000CC94: d024204c                 st      %o0, [%l0+0x4C]
F000CC98: c0242050                 clr     [%l0+0x50]
F000CC9C: e0226048                 st      %l0, [%o1+0x48]
F000CCA0: d2242044                 st      %o1, [%l0+0x44]
F000CCA4: d0042028                 ld      [%l0+0x28], %o0
F000CCA8: 808a2010                 btst    0x10, %o0
F000CCAC: 02800008                 be      loc_F000CCCC
F000CCB0: e6342032                 sth     %l3, [%l0+0x32]
F000CCB4: 900a3fef                 and     %o0, -0x11, %o0
F000CCB8: d0242028                 st      %o0, [%l0+0x28]
F000CCBC: c024207c                 clr     [%l0+0x7C]
F000CCC0: 90100010                 mov     %l0, %o0
F000CCC4: 1080000e                 ba      loc_F000CCFC
F000CCC8: 92102009                 mov     9, %o1! char *
F000CCCC: d0042068                 ld      [%l0+0x68], %o0
F000CCD0: 80a22000                 cmp     %o0, 0
F000CCD4: 0280000c                 be      loc_F000CD04
F000CCD8: 01000000                 nop
F000CCDC: d0022044                 ld      [%o0+0x44], %o0
F000CCE0: 80a22000                 cmp     %o0, 0
F000CCE4: 04800008                 ble     loc_F000CD04
F000CCE8: 90100010                 mov     %l0, %o0! unsigned int
F000CCEC: 40001222                 call    _psignal
F000CCF0: 92102001                 mov     1, %o1
F000CCF4: 90100010                 mov     %l0, %o0! unsigned int
F000CCF8: 92102013                 mov     0x13, %o1! char *
F000CCFC: 4000121e                 call    _psignal
F000CD00: 01000000                 nop
F000CD04: 400005c1                 call    _spgrp
F000CD08: 90100010                 mov     %l0, %o0
F000CD0C: a0944000                 orcc    %l1, %g0, %l0
F000CD10: 32bfffd7                 bne,a   loc_F000CC6C
F000CD14: e204204c                 ld      [%l0+0x4C], %l1
F000CD18: d006207c                 ld      [%i0+0x7C], %o0! unsigned int
F000CD1C: 80a22000                 cmp     %o0, 0
F000CD20: 02800008                 be      loc_F000CD40
F000CD24: c0262048                 clr     [%i0+0x48]
F000CD28: 40001213                 call    _psignal
F000CD2C: 92102014                 mov     0x14, %o1
F000CD30: 4000182e                 call    _wakeup
F000CD34: d006207c                 ld      [%i0+0x7C], %o0
F000CD38: d006207c                 ld      [%i0+0x7C], %o0
F000CD3C: c0222080                 clr     [%o0+0x80]
F000CD40: 213c04cf                 sethi   %hi(_active_u), %l0
F000CD44: d20421d8                 ld      [%l0+%lo(_active_u)], %o1
F000CD48: d0026244                 ld      [%o1+0x244], %o0
F000CD4C: 80a22000                 cmp     %o0, 0
F000CD50: 22800007                 be,a    loc_F000CD6C
F000CD54: d00421d8                 ld      [%l0+%lo(_active_u)], %o0
F000CD58: c0226258                 clr     [%o1+0x258]
F000CD5C: d00421d8                 ld      [%l0+%lo(_active_u)], %o0
F000CD60: 40016fd9                 call    _simple_lock_free
F000CD64: d0022244                 ld      [%o0+0x244], %o0
F000CD68: d00421d8                 ld      [%l0+%lo(_active_u)], %o0
F000CD6C: d0022248                 ld      [%o0+0x248], %o0
F000CD70: 80a22000                 cmp     %o0, 0
F000CD74: 22800009                 be,a    loc_F000CD98
F000CD78: d0062044                 ld      [%i0+0x44], %o0
F000CD7C: e0022004                 ld      [%o0+4], %l0
F000CD80: 40016d08                 call    _kfree
F000CD84: 92102018                 mov     0x18, %o1! char *
F000CD88: 90940000                 orcc    %l0, %g0, %o0
F000CD8C: 32bffffd                 bne,a   loc_F000CD80
F000CD90: e0022004                 ld      [%o0+4], %l0
F000CD94: d0062044                 ld      [%i0+0x44], %o0! unsigned int
F000CD98: 400011f7                 call    _psignal
F000CD9C: 92102014                 mov     0x14, %o1
F000CDA0: 40001812                 call    _wakeup
F000CDA4: d0062044                 ld      [%i0+0x44], %o0! target_task
F000CDA8: c0262068                 clr     [%i0+0x68]
F000CDAC: c026206c                 clr     [%i0+0x6C]
F000CDB0: 40019900                 call    _task_terminate
F000CDB4: 90100014                 mov     %l4, %o0
F000CDB8: 113c04d0                 sethi   %hi(_active_threads), %o0
F000CDBC: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F000CDC0: d002200c                 ld      [%o0+0xC], %o0
F000CDC4: 80a20014                 cmp     %o0, %l4
F000CDC8: 12800004                 bne     locret_F000CDD8
F000CDCC: 01000000                 nop
F000CDD0: 4001a0cf                 call    _thread_halt_self
F000CDD4: 01000000                 nop
F000CDD8: 81c7e008                 ret
F000CDDC: 81e80000                 restore
