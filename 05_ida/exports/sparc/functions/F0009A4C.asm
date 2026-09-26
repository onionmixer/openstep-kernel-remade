F0009A4C: 9de3bf48                 save    %sp, -0xB8, %sp
F0009A50: 213c04d2                 sethi   %hi(_savacctp), %l0
F0009A54: d2042220                 ld      [%l0+%lo(_savacctp)], %o1
F0009A58: 113c04d2                 sethi   %hi(_acctbuf), %o0
F0009A5C: 80a26000                 cmp     %o1, 0
F0009A60: 02800017                 be      loc_F0009ABC
F0009A64: a61221f0                 or      %o0, %lo(_acctbuf), %l3
F0009A68: d0026024                 ld      [%o1+0x24], %o0
F0009A6C: d4022004                 ld      [%o0+4], %o2
F0009A70: d402a00c                 ld      [%o2+0xC], %o2
F0009A74: 9fc28000                 call    %o2
F0009A78: 9207bfb8                 add     %fp, var_48, %o1
F0009A7C: 113c042b                 sethi   %hi(_acctresume), %o0
F0009A80: d00221d4                 ld      [%o0+%lo(_acctresume)], %o0! int
F0009A84: 7ffff29f                 call    _umul
F0009A88: d207bfc0                 ld      [%fp+var_40], %o1! int
F0009A8C: 7ffff2df                 call    _div
F0009A90: 92102064                 mov     0x64, %o1 ! 'd'
F0009A94: d207bfc8                 ld      [%fp+var_38], %o1
F0009A98: 80a24008                 cmp     %o1, %o0
F0009A9C: 04800008                 ble     loc_F0009ABC
F0009AA0: 113c042b                 sethi   %hi(aAccountingResu), %o0! "Accounting resumed\n"
F0009AA4: 901221d8                 bset    %lo(aAccountingResu), %o0! "Accounting resumed\n"
F0009AA8: d4042220                 ld      [%l0+0x220], %o2
F0009AAC: 133c04d2                 sethi   %hi(_acctp), %o1
F0009AB0: d4226218                 st      %o2, [%o1+%lo(_acctp)]
F0009AB4: 40002ae9                 call    _printf
F0009AB8: c0242220                 clr     [%l0+0x220]
F0009ABC: 213c04d2                 sethi   %hi(_acctp), %l0
F0009AC0: e8042218                 ld      [%l0+%lo(_acctp)], %l4
F0009AC4: 80a52000                 cmp     %l4, 0
F0009AC8: 0280008d                 be      locret_F0009CFC
F0009ACC: 01000000                 nop
F0009AD0: d2152006                 lduh    [%l4+6], %o1
F0009AD4: d0052024                 ld      [%l4+0x24], %o0
F0009AD8: 92026001                 inc     %o1
F0009ADC: d2352006                 sth     %o1, [%l4+6]
F0009AE0: d4022004                 ld      [%o0+4], %o2
F0009AE4: d402a00c                 ld      [%o2+0xC], %o2
F0009AE8: 9fc28000                 call    %o2
F0009AEC: 9207bfb8                 add     %fp, var_48, %o1
F0009AF0: 113c042b                 sethi   %hi(_acctsuspend), %o0
F0009AF4: d00221d0                 ld      [%o0+%lo(_acctsuspend)], %o0! int
F0009AF8: 7ffff282                 call    _umul
F0009AFC: d207bfc0                 ld      [%fp+var_40], %o1! int
F0009B00: 7ffff2c2                 call    _div
F0009B04: 92102064                 mov     0x64, %o1 ! 'd'
F0009B08: d207bfc8                 ld      [%fp+var_38], %o1
F0009B0C: 80a24008                 cmp     %o1, %o0
F0009B10: 1480000b                 bg      loc_F0009B3C
F0009B14: 92102000                 mov     0, %o1
F0009B18: 113c042b901221f0         set     aAccountingSusp, %o0! "Accounting suspended\n"
F0009B20: d4042218                 ld      [%l0+0x218], %o2
F0009B24: 133c04d2                 sethi   %hi(_savacctp), %o1! destLen
F0009B28: d4226220                 st      %o2, [%o1+%lo(_savacctp)]
F0009B2C: 40002acb                 call    _printf
F0009B30: c0242218                 clr     [%l0+0x218]
F0009B34: 10800070                 ba      loc_F0009CF4
F0009B38: 90100014                 mov     %l4, %o0
F0009B3C: 153c04cf                 sethi   %hi(_active_u), %o2! source
F0009B40: d002a1d8                 ld      [%o2+%lo(_active_u)], %o0
F0009B44: 90020009                 add     %o0, %o1, %o0
F0009B48: d00a2008                 ldub    [%o0+8], %o0
F0009B4C: d02cc009                 stb     %o0, [%l3+%o1]
F0009B50: 92026001                 inc     %o1
F0009B54: 80a26009                 cmp     %o1, 9
F0009B58: 28bffffb                 bleu,a  loc_F0009B44
F0009B5C: d002a1d8                 ld      [%o2+0x1D8], %o0
F0009B60: 213c04cf                 sethi   %hi(_active_u), %l0
F0009B64: e40421d8                 ld      [%l0+%lo(_active_u)], %l2
F0009B68: d004a16c                 ld      [%l2+0x16C], %o0! dest
F0009B6C: 40000066                 call    _compress
F0009B70: d204a170                 ld      [%l2+0x170], %o1! destLen
F0009B74: d034e00a                 sth     %o0, [%l3+0xA]
F0009B78: d004a174                 ld      [%l2+0x174], %o0! dest
F0009B7C: 40000062                 call    _compress
F0009B80: d204a178                 ld      [%l2+0x178], %o1
F0009B84: d034e00c                 sth     %o0, [%l3+0xC]
F0009B88: a207bfb0                 add     %fp, dest, %l1
F0009B8C: 40019291                 call    _microtime
F0009B90: 90100011                 mov     %l1, %o0
F0009B94: d20421d8                 ld      [%l0+%lo(_active_u)], %o1
F0009B98: 90100011                 mov     %l1, %o0
F0009B9C: 400026c5                 call    _timevalsub
F0009BA0: 92026238                 inc     0x238, %o1! destLen
F0009BA4: d007bfb0                 ld      [%fp+dest], %o0! dest
F0009BA8: 40000057                 call    _compress
F0009BAC: d207bfb4                 ld      [%fp+var_4C], %o1
F0009BB0: d20421d8                 ld      [%l0+0x1D8], %o1
F0009BB4: d034e00e                 sth     %o0, [%l3+0xE]
F0009BB8: d0026238                 ld      [%o1+0x238], %o0
F0009BBC: d20421d8                 ld      [%l0+0x1D8], %o1
F0009BC0: d024e010                 st      %o0, [%l3+0x10]
F0009BC4: d002601c                 ld      [%o1+0x1C], %o0
F0009BC8: d0122006                 lduh    [%o0+6], %o0
F0009BCC: d20421d8                 ld      [%l0+0x1D8], %o1
F0009BD0: d034e014                 sth     %o0, [%l3+0x14]
F0009BD4: d002601c                 ld      [%o1+0x1C], %o0
F0009BD8: d0122008                 lduh    [%o0+8], %o0
F0009BDC: d034e016                 sth     %o0, [%l3+0x16]
F0009BE0: 90100011                 mov     %l1, %o0
F0009BE4: d204a174                 ld      [%l2+0x174], %o1
F0009BE8: a204a16c                 add     %l2, 0x16C, %l1
F0009BEC: d227bfb0                 st      %o1, [%fp+dest]
F0009BF0: d404a178                 ld      [%l2+0x178], %o2
F0009BF4: 92100011                 mov     %l1, %o1
F0009BF8: 400026a1                 call    _timevaladd
F0009BFC: d427bfb4                 st      %o2, [%fp+var_4C]
F0009C00: d007bfb0                 ld      [%fp+dest], %o0! int
F0009C04: 133c043e                 sethi   %hi(_hz), %o1
F0009C08: 7ffff23e                 call    _umul
F0009C0C: d20263e0                 ld      [%o1+%lo(_hz)], %o1
F0009C10: 133c043e                 sethi   %hi(_tick), %o1
F0009C14: d407bfb4                 ld      [%fp+var_4C], %o2
F0009C18: a0100008                 mov     %o0, %l0
F0009C1C: d20263e4                 ld      [%o1+%lo(_tick)], %o1! int
F0009C20: 7ffff27a                 call    _div
F0009C24: 9010000a                 mov     %o2, %o0
F0009C28: 92840008                 addcc   %l0, %o0, %o1! int
F0009C2C: 22800009                 be,a    loc_F0009C50
F0009C30: c034e018                 clrh    [%l3+0x18]
F0009C34: d004a180                 ld      [%l2+0x180], %o0
F0009C38: d604a184                 ld      [%l2+0x184], %o3! sourceLen
F0009C3C: d404a188                 ld      [%l2+0x188], %o2
F0009C40: 9002000b                 add     %o0, %o3, %o0! int
F0009C44: 7ffff271                 call    _div
F0009C48: 9002000a                 add     %o0, %o2, %o0
F0009C4C: d034e018                 sth     %o0, [%l3+0x18]
F0009C50: d014e018                 lduh    [%l3+0x18], %o0
F0009C54: d034e018                 sth     %o0, [%l3+0x18]
F0009C58: d404602c                 ld      [%l1+0x2C], %o2! source
F0009C5C: d0046030                 ld      [%l1+0x30], %o0! dest
F0009C60: 92102000                 mov     0, %o1! destLen
F0009C64: 40000028                 call    _compress
F0009C68: 90028008                 add     %o2, %o0, %o0
F0009C6C: 133c04cf                 sethi   %hi(_active_u), %o1
F0009C70: d20261d8                 ld      [%o1+%lo(_active_u)], %o1
F0009C74: d034e01a                 sth     %o0, [%l3+0x1A]
F0009C78: d0026164                 ld      [%o1+0x164], %o0
F0009C7C: 80a22000                 cmp     %o0, 0
F0009C80: 02800003                 be      loc_F0009C8C
F0009C84: 90103fff                 mov     -1, %o0
F0009C88: d0126168                 lduh    [%o1+0x168], %o0
F0009C8C: d034e01c                 sth     %o0, [%l3+0x1C]
F0009C90: 213c04cf                 sethi   %hi(_active_u), %l0
F0009C94: d00421d8                 ld      [%l0+%lo(_active_u)], %o0
F0009C98: d60421d8                 ld      [%l0+%lo(_active_u)], %o3
F0009C9C: 98102000                 mov     0, %o4
F0009CA0: d2122240                 lduh    [%o0+0x240], %o1
F0009CA4: 9a102001                 mov     1, %o5
F0009CA8: d22ce01e                 stb     %o1, [%l3+0x1E]
F0009CAC: 133c04d2                 sethi   %hi(_acctcred), %o1
F0009CB0: d4026210                 ld      [%o1+%lo(_acctcred)], %o2
F0009CB4: 90102001                 mov     1, %o0
F0009CB8: e202e01c                 ld      [%o3+0x1C], %l1
F0009CBC: 92100014                 mov     %l4, %o1
F0009CC0: d422e01c                 st      %o2, [%o3+0x1C]
F0009CC4: 94102003                 mov     3, %o2
F0009CC8: d423a05c                 st      %o2, [%sp+0xB8+var_5C]
F0009CCC: c023a060                 clr     [%sp+0xB8+var_58]
F0009CD0: 94100013                 mov     %l3, %o2
F0009CD4: 40007b60                 call    _vn_rdwr
F0009CD8: 96102020                 mov     0x20, %o3 ! ' '
F0009CDC: 921421d8                 or      %l0, 0x1D8, %o1
F0009CE0: d2026004                 ld      [%o1+4], %o1
F0009CE4: d02a6038                 stb     %o0, [%o1+0x38]
F0009CE8: d20421d8                 ld      [%l0+0x1D8], %o1
F0009CEC: 90100014                 mov     %l4, %o0
F0009CF0: e222601c                 st      %l1, [%o1+0x1C]
F0009CF4: 40007b9c                 call    _vn_rele
F0009CF8: 01000000                 nop
F0009CFC: 81c7e008                 ret
F0009D00: 81e80000                 restore
