F0033C1C: 9de3bf98                 save    %sp, -0x68, %sp
F0033C20: d2066004                 ld      [%i1+4], %o1
F0033C24: d0062004                 ld      [%i0+4], %o0
F0033C28: d4064009                 ld      [%i1+%o1], %o2
F0033C2C: a2060008                 add     %i0, %o0, %l1
F0033C30: d0566008                 ldsh    [%i1+8], %o0
F0033C34: 80a2a000                 cmp     %o2, 0
F0033C38: b2064009                 add     %i1, %o1, %i1
F0033C3C: 02800003                 be      loc_F0033C48
F0033C40: a4023ffc                 add     %o0, -4, %l2
F0033C44: d4246010                 st      %o2, [%l1+0x10]
F0033C48: d2062004                 ld      [%i0+4], %o1
F0033C4C: 80a2607b                 cmp     %o1, 0x7B ! '{'
F0033C50: 18800005                 bgu     loc_F0033C64
F0033C54: 90022008                 inc     8, %o0
F0033C58: 80a20009                 cmp     %o0, %o1
F0033C5C: 0880003a                 bleu    loc_F0033D44
F0033C60: 90224012                 sub     %o1, %l2, %o0
F0033C64: 40018bd5                 call    _spltty
F0033C68: 293c04d3                 sethi   %hi(_mfree), %l4
F0033C6C: e0052168                 ld      [%l4+%lo(_mfree)], %l0
F0033C70: 80a42000                 cmp     %l0, 0
F0033C74: 02800018                 be      loc_F0033CD4
F0033C78: a6100008                 mov     %o0, %l3
F0033C7C: d054200a                 ldsh    [%l0+0xA], %o0
F0033C80: 80a22000                 cmp     %o0, 0
F0033C84: 02800004                 be      loc_F0033C94
F0033C88: 113c0432                 sethi   %hi(aMget_9), %o0! "mget"
F0033C8C: 7fff8539                 call    _panic
F0033C90: 90122070                 bset    %lo(aMget_9), %o0! "mget"
F0033C94: 90102002                 mov     2, %o0
F0033C98: d034200a                 sth     %o0, [%l0+0xA]
F0033C9C: 153c04d29412a2f0         set     _mbstat, %o2
F0033CA4: d012a01c                 lduh    [%o2+0x1C], %o0
F0033CA8: d212a020                 lduh    [%o2+0x20], %o1
F0033CAC: 90023fff                 inc     -1, %o0
F0033CB0: d032a01c                 sth     %o0, [%o2+0x1C]
F0033CB4: 92026001                 inc     %o1
F0033CB8: d232a020                 sth     %o1, [%o2+0x20]
F0033CBC: 9010200c                 mov     0xC, %o0
F0033CC0: d2040000                 ld      [%l0], %o1
F0033CC4: d0242004                 st      %o0, [%l0+4]
F0033CC8: d2252168                 st      %o1, [%l4+0x168]
F0033CCC: 10800006                 ba      loc_F0033CE4
F0033CD0: c0240000                 clr     [%l0]
F0033CD4: 90102000                 mov     0, %o0
F0033CD8: 7fffa7a5                 call    _m_more
F0033CDC: 92102002                 mov     2, %o1
F0033CE0: a0100008                 mov     %o0, %l0
F0033CE4: 40018c10                 call    _splx
F0033CE8: 90100013                 mov     %l3, %o0
F0033CEC: 80a42000                 cmp     %l0, 0
F0033CF0: 02800029                 be      locret_F0033D94
F0033CF4: 90100011                 mov     %l1, %o0! void *
F0033CF8: d6162008                 lduh    [%i0+8], %o3
F0033CFC: 94102014                 mov     0x14, %o2! size_t
F0033D00: d2062004                 ld      [%i0+4], %o1
F0033D04: 9602ffec                 inc     -0x14, %o3
F0033D08: d6362008                 sth     %o3, [%i0+8]
F0033D0C: 92026014                 inc     0x14, %o1
F0033D10: d2262004                 st      %o1, [%i0+4]
F0033D14: f0240000                 st      %i0, [%l0]
F0033D18: b0100010                 mov     %l0, %i0
F0033D1C: 92102068                 mov     0x68, %o1 ! 'h'
F0033D20: 92224012                 sub     %o1, %l2, %o1
F0033D24: d2262004                 st      %o1, [%i0+4]
F0033D28: 9604a014                 add     %l2, 0x14, %o3
F0033D2C: d2062004                 ld      [%i0+4], %o1! void *
F0033D30: d6362008                 sth     %o3, [%i0+8]
F0033D34: 40018377                 call    _bcopy
F0033D38: 92060009                 add     %i0, %o1, %o1
F0033D3C: 1080000c                 ba      loc_F0033D6C
F0033D40: 90066004                 add     %i1, 4, %o0
F0033D44: d0262004                 st      %o0, [%i0+4]
F0033D48: 90100011                 mov     %l1, %o0
F0033D4C: d6162008                 lduh    [%i0+8], %o3
F0033D50: 94102014                 mov     0x14, %o2
F0033D54: d2062004                 ld      [%i0+4], %o1
F0033D58: 9602c012                 add     %o3, %l2, %o3
F0033D5C: d6362008                 sth     %o3, [%i0+8]
F0033D60: 40018424                 call    _ovbcopy
F0033D64: 92060009                 add     %i0, %o1, %o1
F0033D68: 90066004                 add     %i1, 4, %o0! void *
F0033D6C: d2062004                 ld      [%i0+4], %o1! void *
F0033D70: 94100012                 mov     %l2, %o2! size_t
F0033D74: a2060009                 add     %i0, %o1, %l1
F0033D78: 40018366                 call    _bcopy
F0033D7C: 92046014                 add     %l1, 0x14, %o1
F0033D80: 9004a014                 add     %l2, 0x14, %o0
F0033D84: d0268000                 st      %o0, [%i2]
F0033D88: d0146002                 lduh    [%l1+2], %o0
F0033D8C: 90020012                 add     %o0, %l2, %o0
F0033D90: d0346002                 sth     %o0, [%l1+2]
F0033D94: 81c7e008                 ret
F0033D98: 81e80000                 restore
