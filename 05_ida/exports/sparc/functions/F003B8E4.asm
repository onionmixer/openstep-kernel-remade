F003B8E4: 9de3bf78                 save    %sp, -0x88, %sp
F003B8E8: 90100018                 mov     %i0, %o0
F003B8EC: 400001cd                 call    sub_F003C020
F003B8F0: 9210001a                 mov     %i2, %o1
F003B8F4: a0920000                 orcc    %o0, %g0, %l0
F003B8F8: 32800005                 bne,a   loc_F003B90C
F003B8FC: d0042028                 ld      [%l0+0x28], %o0
F003B900: 90102046                 mov     0x46, %o0 ! 'F'
F003B904: 10800082                 ba      locret_F003BB0C
F003B908: d0266004                 st      %o0, [%i1+4]
F003B90C: 80a22002                 cmp     %o0, 2
F003B910: 02800006                 be      loc_F003B928
F003B914: 113c0432                 sethi   %hi(aRfsReaddirAtte), %o0! "rfs_readdir: attempt to read non-direct"...
F003B918: 7fff6350                 call    _printf
F003B91C: 90122268                 bset    %lo(aRfsReaddirAtte), %o0! "rfs_readdir: attempt to read non-direct"...
F003B920: 10800078                 ba      loc_F003BB00
F003B924: 98102014                 mov     0x14, %o4
F003B928: 113c04cf                 sethi   %hi(_active_u), %o0
F003B92C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F003B930: d204201c                 ld      [%l0+0x1C], %o1
F003B934: d402201c                 ld      [%o0+0x1C], %o2
F003B938: d602601c                 ld      [%o1+0x1C], %o3
F003B93C: 90100010                 mov     %l0, %o0
F003B940: 9fc2c000                 call    %o3
F003B944: 92102100                 mov     0x100, %o1
F003B948: 98920000                 orcc    %o0, %g0, %o4
F003B94C: 3280006e                 bne,a   loc_F003BB04
F003B950: d8266004                 st      %o4, [%i1+4]
F003B954: d0062024                 ld      [%i0+0x24], %o0
F003B958: 80a22000                 cmp     %o0, 0
F003B95C: 12800007                 bne     loc_F003B978
F003B960: 13000008                 sethi   0x2000, %o1
F003B964: c026600c                 clr     [%i1+0xC]
F003B968: c0266010                 clr     [%i1+0x10]
F003B96C: c0266014                 clr     [%i1+0x14]
F003B970: 10800064                 ba      loc_F003BB00
F003B974: c0264000                 clr     [%i1]
F003B978: 80a20009                 cmp     %o0, %o1
F003B97C: 38800002                 bgu,a   loc_F003B984
F003B980: 90100009                 mov     %o1, %o0
F003B984: d0262024                 st      %o0, [%i0+0x24]
F003B988: 4000b1ba                 call    _kalloc
F003B98C: d0062024                 ld      [%i0+0x24], %o0
F003B990: d0266014                 st      %o0, [%i1+0x14]
F003B994: d0062024                 ld      [%i0+0x24], %o0
F003B998: d0267ffc                 st      %o0, [%i1-4]
F003B99C: d0062024                 ld      [%i0+0x24], %o0
F003B9A0: d0264000                 st      %o0, [%i1]
F003B9A4: d0062020                 ld      [%i0+0x20], %o0
F003B9A8: b40a3c00                 and     %o0, -0x400, %i2
F003B9AC: d0066014                 ld      [%i1+0x14], %o0
F003B9B0: f4266008                 st      %i2, [%i1+8]
F003B9B4: d027bff0                 st      %o0, [%fp+var_10]
F003B9B8: d0062024                 ld      [%i0+0x24], %o0
F003B9BC: a2102001                 mov     1, %l1
F003B9C0: d027bff4                 st      %o0, [%fp+var_C]
F003B9C4: 9007bff0                 add     %fp, var_10, %o0
F003B9C8: d027bfd8                 st      %o0, [%fp+var_28]
F003B9CC: e227bfdc                 st      %l1, [%fp+var_24]
F003B9D0: e227bfe4                 st      %l1, [%fp+var_1C]
F003B9D4: f427bfe0                 st      %i2, [%fp+var_20]
F003B9D8: d2062024                 ld      [%i0+0x24], %o1
F003B9DC: 113c04cf                 sethi   %hi(_active_u), %o0
F003B9E0: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F003B9E4: d227bfec                 st      %o1, [%fp+var_14]
F003B9E8: d204201c                 ld      [%l0+0x1C], %o1
F003B9EC: d402201c                 ld      [%o0+0x1C], %o2
F003B9F0: d602603c                 ld      [%o1+0x3C], %o3
F003B9F4: 90100010                 mov     %l0, %o0
F003B9F8: 9fc2c000                 call    %o3
F003B9FC: 9207bfd8                 add     %fp, var_28, %o1
F003BA00: 98920000                 orcc    %o0, %g0, %o4
F003BA04: 02800004                 be      loc_F003BA14
F003BA08: d207bfec                 ld      [%fp+var_14], %o1
F003BA0C: 1080003d                 ba      loc_F003BB00
F003BA10: c026600c                 clr     [%i1+0xC]
F003BA14: 80a26000                 cmp     %o1, 0
F003BA18: 02800006                 be      loc_F003BA30
F003BA1C: d0062024                 ld      [%i0+0x24], %o0
F003BA20: 90220009                 sub     %o0, %o1, %o0
F003BA24: d026600c                 st      %o0, [%i1+0xC]
F003BA28: 10800004                 ba      loc_F003BA38
F003BA2C: e2266010                 st      %l1, [%i1+0x10]
F003BA30: d026600c                 st      %o0, [%i1+0xC]
F003BA34: c0266010                 clr     [%i1+0x10]
F003BA38: d006600c                 ld      [%i1+0xC], %o0
F003BA3C: 96102000                 mov     0, %o3
F003BA40: d4066014                 ld      [%i1+0x14], %o2
F003BA44: 10800007                 ba      loc_F003BA60
F003BA48: 80a2c008                 cmp     %o3, %o0
F003BA4C: d206600c                 ld      [%i1+0xC], %o1
F003BA50: 9602c008                 add     %o3, %o0, %o3
F003BA54: b4068008                 add     %i2, %o0, %i2
F003BA58: 94028008                 add     %o2, %o0, %o2
F003BA5C: 80a2c009                 cmp     %o3, %o1
F003BA60: 1a80000d                 bcc     loc_F003BA94
F003BA64: 80a2e000                 cmp     %o3, 0
F003BA68: d012a004                 lduh    [%o2+4], %o0
F003BA6C: d2062020                 ld      [%i0+0x20], %o1
F003BA70: 90068008                 add     %i2, %o0, %o0
F003BA74: 80a20009                 cmp     %o0, %o1
F003BA78: 28bffff5                 bleu,a  loc_F003BA4C
F003BA7C: d012a004                 lduh    [%o2+4], %o0
F003BA80: d0028000                 ld      [%o2], %o0
F003BA84: 80a22000                 cmp     %o0, 0
F003BA88: 22bffff1                 be,a    loc_F003BA4C
F003BA8C: d012a004                 lduh    [%o2+4], %o0
F003BA90: 80a2e000                 cmp     %o3, 0
F003BA94: 2280001c                 be,a    loc_F003BB04
F003BA98: d8266004                 st      %o4, [%i1+4]
F003BA9C: d006600c                 ld      [%i1+0xC], %o0
F003BAA0: f4266008                 st      %i2, [%i1+8]
F003BAA4: d2064000                 ld      [%i1], %o1
F003BAA8: 9022000b                 sub     %o0, %o3, %o0
F003BAAC: d026600c                 st      %o0, [%i1+0xC]
F003BAB0: 9222400b                 sub     %o1, %o3, %o1
F003BAB4: d0066014                 ld      [%i1+0x14], %o0
F003BAB8: d2264000                 st      %o1, [%i1]
F003BABC: 9402000b                 add     %o0, %o3, %o2
F003BAC0: d006600c                 ld      [%i1+0xC], %o0
F003BAC4: 80a22000                 cmp     %o0, 0
F003BAC8: 1280000e                 bne     loc_F003BB00
F003BACC: d4266014                 st      %o2, [%i1+0x14]
F003BAD0: d0066010                 ld      [%i1+0x10], %o0
F003BAD4: 80a22000                 cmp     %o0, 0
F003BAD8: 3280000b                 bne,a   loc_F003BB04
F003BADC: d8266004                 st      %o4, [%i1+4]
F003BAE0: d0064000                 ld      [%i1], %o0
F003BAE4: d2067ffc                 ld      [%i1-4], %o1
F003BAE8: 90028008                 add     %o2, %o0, %o0
F003BAEC: 4000b1ad                 call    _kfree
F003BAF0: 90220009                 sub     %o0, %o1, %o0
F003BAF4: d0066008                 ld      [%i1+8], %o0
F003BAF8: 10bfffa4                 ba      loc_F003B988
F003BAFC: d0262020                 st      %o0, [%i0+0x20]
F003BB00: d8266004                 st      %o4, [%i1+4]
F003BB04: 7fffb418                 call    _vn_rele
F003BB08: 90100010                 mov     %l0, %o0
F003BB0C: 81c7e008                 ret
F003BB10: 81e80000                 restore
