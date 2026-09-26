F002D68C: 9de3bf80                 save    %sp, -0x80, %sp
F002D690: e807a05c                 ld      [%fp+arg_5C], %l4
F002D694: f4068000                 ld      [%i2], %i2
F002D698: 113c0000                 sethi   -0x10000000, %o0
F002D69C: c0250000                 clr     [%l4]
F002D6A0: d4070000                 ld      [%i4], %o2
F002D6A4: 13380000                 sethi   -0x20000000, %o1
F002D6A8: 900a8008                 and     %o2, %o0, %o0
F002D6AC: 80a20009                 cmp     %o0, %o1
F002D6B0: 32800010                 bne,a   loc_F002D6F0
F002D6B4: d427bfe4                 st      %o2, [%fp+var_1C]
F002D6B8: 90102001                 mov     1, %o0
F002D6BC: d02f4000                 stb     %o0, [%i5]
F002D6C0: c02f6001                 clrb    [%i5+1]
F002D6C4: 9010205e                 mov     0x5E, %o0 ! '^'
F002D6C8: d02f6002                 stb     %o0, [%i5+2]
F002D6CC: d00f2001                 ldub    [%i4+1], %o0
F002D6D0: 900a207f                 and     %o0, 0x7F, %o0
F002D6D4: d02f6003                 stb     %o0, [%i5+3]
F002D6D8: d00f2002                 ldub    [%i4+2], %o0
F002D6DC: d02f6004                 stb     %o0, [%i5+4]
F002D6E0: d00f2003                 ldub    [%i4+3], %o0
F002D6E4: b0102001                 mov     1, %i0
F002D6E8: 1080008a                 ba      locret_F002D910
F002D6EC: d02f6005                 stb     %o0, [%i5+5]
F002D6F0: 40000706                 call    _in_broadcast
F002D6F4: 9007bfe4                 add     %fp, var_1C, %o0
F002D6F8: 80a22000                 cmp     %o0, 0
F002D6FC: 0280000a                 be      loc_F002D724
F002D700: 113c0430                 sethi   %hi(_arpethertempl), %o0
F002D704: 90122354                 bset    %lo(_arpethertempl), %o0
F002D708: d40a2004                 ldub    [%o0+4], %o2
F002D70C: d60a2005                 ldub    [%o0+5], %o3
F002D710: 9210001d                 mov     %i5, %o1
F002D714: 9602800b                 add     %o2, %o3, %o3
F002D718: 9602e008                 inc     8, %o3
F002D71C: 1080001c                 ba      loc_F002D78C
F002D720: 9002c008                 add     %o3, %o0, %o0
F002D724: d2070000                 ld      [%i4], %o1
F002D728: 9007bfe0                 add     %fp, var_20, %o0
F002D72C: 40000437                 call    _in_lnaof
F002D730: d227bfe0                 st      %o1, [%fp+var_20]
F002D734: d2070000                 ld      [%i4], %o1
F002D738: 80a2401a                 cmp     %o1, %i2
F002D73C: 12800017                 bne     loc_F002D798
F002D740: a4100008                 mov     %o0, %l2
F002D744: 113c0430                 sethi   %hi(_useloopback), %o0
F002D748: d0022388                 ld      [%o0+%lo(_useloopback)], %o0
F002D74C: 80a22000                 cmp     %o0, 0
F002D750: 0280000c                 be      loc_F002D780
F002D754: 90102002                 mov     2, %o0
F002D758: d037bfe8                 sth     %o0, [%fp+var_18]
F002D75C: 9210001b                 mov     %i3, %o1
F002D760: 9407bfe8                 add     %fp, var_18, %o2
F002D764: d6070000                 ld      [%i4], %o3
F002D768: 113c04d5                 sethi   %hi(_loifp), %o0
F002D76C: d0022268                 ld      [%o0+%lo(_loifp)], %o0
F002D770: 7ffff255                 call    _looutput
F002D774: d627bfec                 st      %o3, [%fp+var_14]
F002D778: 10800066                 ba      locret_F002D910
F002D77C: b0102000                 mov     0, %i0
F002D780: 90100019                 mov     %i1, %o0! void *
F002D784: 9210001d                 mov     %i5, %o1! void *
F002D788: 94102004                 mov     4, %o2! size_t
F002D78C: 40019ce1                 call    _bcopy
F002D790: b0102001                 mov     1, %i0
F002D794: 3080005f                 ba,a    locret_F002D910
F002D798: 4001a508                 call    _spltty
F002D79C: 01000000                 nop
F002D7A0: 92102013                 mov     0x13, %o1
F002D7A4: e0070000                 ld      [%i4], %l0
F002D7A8: a6100008                 mov     %o0, %l3
F002D7AC: 7fff643d                 call    _urem
F002D7B0: 90100010                 mov     %l0, %o0
F002D7B4: 932a2001                 sll     %o0, 1, %o1
F002D7B8: 92024008                 add     %o1, %o0, %o1
F002D7BC: 952a6004                 sll     %o1, 4, %o2
F002D7C0: 94228009                 sub     %o2, %o1, %o2
F002D7C4: 952aa002                 sll     %o2, 2, %o2! size_t
F002D7C8: 113c04d590122270         set     _arptab, %o0
F002D7D0: a2028008                 add     %o2, %o0, %l1
F002D7D4: 92102000                 mov     0, %o1
F002D7D8: d0044000                 ld      [%l1], %o0
F002D7DC: 80a20010                 cmp     %o0, %l0
F002D7E0: 3280000a                 bne,a   loc_F002D808
F002D7E4: 92026001                 inc     %o1
F002D7E8: 80a62000                 cmp     %i0, 0
F002D7EC: 0280000b                 be      loc_F002D818
F002D7F0: 80a26008                 cmp     %o1, 8
F002D7F4: d0046010                 ld      [%l1+0x10], %o0
F002D7F8: 80a20018                 cmp     %o0, %i0
F002D7FC: 02800007                 be      loc_F002D818
F002D800: 80a26008                 cmp     %o1, 8
F002D804: 92026001                 inc     %o1
F002D808: 80a26008                 cmp     %o1, 8
F002D80C: 04bffff3                 ble     loc_F002D7D8
F002D810: a2046014                 inc     0x14, %l1
F002D814: 80a26008                 cmp     %o1, 8
F002D818: 34800002                 bg,a    loc_F002D820
F002D81C: a2102000                 mov     0, %l1
F002D820: 80a46000                 cmp     %l1, 0
F002D824: 3280001b                 bne,a   loc_F002D890
F002D828: d00c600b                 ldub    [%l1+0xB], %o0
F002D82C: d016200c                 lduh    [%i0+0xC], %o0
F002D830: 808a2080                 btst    0x80, %o0
F002D834: 0280000c                 be      loc_F002D864
F002D838: 90100019                 mov     %i1, %o0! void *
F002D83C: 9210001d                 mov     %i5, %o1! void *
F002D840: 40019cb4                 call    _bcopy
F002D844: 94102003                 mov     3, %o2! size_t
F002D848: 9134a010                 srl     %l2, 16, %o0
F002D84C: 900a207f                 and     %o0, 0x7F, %o0
F002D850: d02f6003                 stb     %o0, [%i5+3]
F002D854: 9134a008                 srl     %l2, 8, %o0
F002D858: d02f6004                 stb     %o0, [%i5+4]
F002D85C: 10800019                 ba      loc_F002D8C0
F002D860: e42f6005                 stb     %l2, [%i5+5]
F002D864: 90100018                 mov     %i0, %o0
F002D868: 400001bc                 call    _arptnew
F002D86C: 9210001c                 mov     %i4, %o1
F002D870: a2920000                 orcc    %o0, %g0, %l1
F002D874: 3280001e                 bne,a   loc_F002D8EC
F002D878: f624600c                 st      %i3, [%l1+0xC]
F002D87C: 113c0430                 sethi   %hi(aArpresolveNoFr), %o0! "arpresolve: no free entry"
F002D880: 7fff9e3c                 call    _panic
F002D884: 90122390                 bset    %lo(aArpresolveNoFr), %o0! "arpresolve: no free entry"
F002D888: 10800019                 ba      loc_F002D8EC
F002D88C: f624600c                 st      %i3, [%l1+0xC]
F002D890: 808a2002                 btst    2, %o0
F002D894: 0280000f                 be      loc_F002D8D0
F002D898: c02c600a                 clrb    [%l1+0xA]
F002D89C: 90046004                 add     %l1, 4, %o0! void *
F002D8A0: 9210001d                 mov     %i5, %o1! void *
F002D8A4: 40019c9b                 call    _bcopy
F002D8A8: 94102006                 mov     6, %o2
F002D8AC: d00c600b                 ldub    [%l1+0xB], %o0
F002D8B0: 808a2010                 btst    0x10, %o0
F002D8B4: 02800003                 be      loc_F002D8C0
F002D8B8: 90102001                 mov     1, %o0
F002D8BC: d0250000                 st      %o0, [%l4]
F002D8C0: 4001a519                 call    _splx
F002D8C4: 90100013                 mov     %l3, %o0
F002D8C8: 10800012                 ba      locret_F002D910
F002D8CC: b0102001                 mov     1, %i0
F002D8D0: d004600c                 ld      [%l1+0xC], %o0
F002D8D4: 80a22000                 cmp     %o0, 0
F002D8D8: 22800005                 be,a    loc_F002D8EC
F002D8DC: f624600c                 st      %i3, [%l1+0xC]
F002D8E0: 7fffc0e1                 call    _m_freem
F002D8E4: 01000000                 nop
F002D8E8: f624600c                 st      %i3, [%l1+0xC]
F002D8EC: f427bfe0                 st      %i2, [%fp+var_20]
F002D8F0: 90100018                 mov     %i0, %o0
F002D8F4: 92100019                 mov     %i1, %o1
F002D8F8: 9407bfe0                 add     %fp, var_20, %o2
F002D8FC: 7fffff1e                 call    _arpwhohas
F002D900: 9610001c                 mov     %i4, %o3
F002D904: 4001a508                 call    _splx
F002D908: 90100013                 mov     %l3, %o0
F002D90C: b0102000                 mov     0, %i0
F002D910: 81c7e008                 ret
F002D914: 81e80000                 restore
