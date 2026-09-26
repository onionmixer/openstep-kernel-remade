F00308E4: 9de3bf90                 save    %sp, -0x70, %sp
F00308E8: a2100018                 mov     %i0, %l1
F00308EC: d0166008                 lduh    [%i1+8], %o0
F00308F0: a0102000                 mov     0, %l0
F00308F4: d2066004                 ld      [%i1+4], %o1
F00308F8: 80a22010                 cmp     %o0, 0x10
F00308FC: 02800004                 be      loc_F003090C
F0030900: a4064009                 add     %i1, %o1, %l2
F0030904: 108000d9                 ba      locret_F0030C68
F0030908: b0102016                 mov     0x16, %i0
F003090C: d0564009                 ldsh    [%i1+%o1], %o0
F0030910: 80a22002                 cmp     %o0, 2
F0030914: 128000d5                 bne     locret_F0030C68
F0030918: b010202f                 mov     0x2F, %i0 ! '/'
F003091C: d014a002                 lduh    [%l2+2], %o0
F0030920: 80a22000                 cmp     %o0, 0
F0030924: 02800093                 be      loc_F0030B70
F0030928: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F003092C: d2022070                 ld      [%o0+%lo(_in_ifaddr)], %o1
F0030930: 80a26000                 cmp     %o1, 0
F0030934: 22800012                 be,a    loc_F003097C
F0030938: d0046014                 ld      [%l1+0x14], %o0
F003093C: d004a004                 ld      [%l2+4], %o0
F0030940: 80a22000                 cmp     %o0, 0
F0030944: 12800004                 bne     loc_F0030954
F0030948: 80a23fff                 cmp     %o0, -1
F003094C: 1080000a                 ba      loc_F0030974
F0030950: d0026004                 ld      [%o1+4], %o0
F0030954: 3280000a                 bne,a   loc_F003097C
F0030958: d0046014                 ld      [%l1+0x14], %o0
F003095C: d0026020                 ld      [%o1+0x20], %o0
F0030960: d012200c                 lduh    [%o0+0xC], %o0
F0030964: 808a2002                 btst    2, %o0
F0030968: 22800005                 be,a    loc_F003097C
F003096C: d0046014                 ld      [%l1+0x14], %o0
F0030970: d0026014                 ld      [%o1+0x14], %o0
F0030974: d024a004                 st      %o0, [%l2+4]
F0030978: d0046014                 ld      [%l1+0x14], %o0
F003097C: 80a22000                 cmp     %o0, 0
F0030980: 32800080                 bne,a   loc_F0030B80
F0030984: d004a004                 ld      [%l2+4], %o0
F0030988: d4046024                 ld      [%l1+0x24], %o2
F003098C: b0102000                 mov     0, %i0
F0030990: 80a2a000                 cmp     %o2, 0
F0030994: 02800016                 be      loc_F00309EC
F0030998: a0046024                 add     %l1, 0x24, %l0 ! '$'
F003099C: d204602c                 ld      [%l1+0x2C], %o1
F00309A0: d004a004                 ld      [%l2+4], %o0
F00309A4: 80a24008                 cmp     %o1, %o0
F00309A8: 32800008                 bne,a   loc_F00309C8
F00309AC: d052a026                 ldsh    [%o2+0x26], %o0
F00309B0: d004601c                 ld      [%l1+0x1C], %o0
F00309B4: d0122002                 lduh    [%o0+2], %o0
F00309B8: 808a2010                 btst    0x10, %o0
F00309BC: 2280000d                 be,a    loc_F00309F0
F00309C0: d004601c                 ld      [%l1+0x1C], %o0
F00309C4: d052a026                 ldsh    [%o2+0x26], %o0
F00309C8: 80a22001                 cmp     %o0, 1
F00309CC: 12800006                 bne     loc_F00309E4
F00309D0: 90023fff                 inc     -1, %o0
F00309D4: 7ffff114                 call    _rtfree
F00309D8: 9010000a                 mov     %o2, %o0
F00309DC: 10800004                 ba      loc_F00309EC
F00309E0: c0240000                 clr     [%l0]
F00309E4: d032a026                 sth     %o0, [%o2+0x26]
F00309E8: c0240000                 clr     [%l0]
F00309EC: d004601c                 ld      [%l1+0x1C], %o0
F00309F0: d0122002                 lduh    [%o0+2], %o0
F00309F4: 808a2010                 btst    0x10, %o0
F00309F8: 12800010                 bne     loc_F0030A38
F00309FC: d0040000                 ld      [%l0], %o0
F0030A00: 80a22000                 cmp     %o0, 0
F0030A04: 22800007                 be,a    loc_F0030A20
F0030A08: 90102002                 mov     2, %o0
F0030A0C: d002202c                 ld      [%o0+0x2C], %o0
F0030A10: 80a22000                 cmp     %o0, 0
F0030A14: 32800009                 bne,a   loc_F0030A38
F0030A18: d0040000                 ld      [%l0], %o0
F0030A1C: 90102002                 mov     2, %o0
F0030A20: d0342004                 sth     %o0, [%l0+4]
F0030A24: d204a004                 ld      [%l2+4], %o1
F0030A28: 90100010                 mov     %l0, %o0
F0030A2C: 7ffff08b                 call    _rtalloc
F0030A30: d2242008                 st      %o1, [%l0+8]
F0030A34: d0040000                 ld      [%l0], %o0
F0030A38: 80a22000                 cmp     %o0, 0
F0030A3C: 02800018                 be      loc_F0030A9C
F0030A40: 80a62000                 cmp     %i0, 0
F0030A44: d202202c                 ld      [%o0+0x2C], %o1
F0030A48: 80a26000                 cmp     %o1, 0
F0030A4C: 02800014                 be      loc_F0030A9C
F0030A50: 80a62000                 cmp     %i0, 0
F0030A54: d012600c                 lduh    [%o1+0xC], %o0
F0030A58: 808a2008                 btst    8, %o0
F0030A5C: 12800010                 bne     loc_F0030A9C
F0030A60: 80a62000                 cmp     %i0, 0
F0030A64: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F0030A68: f0022070                 ld      [%o0+%lo(_in_ifaddr)], %i0
F0030A6C: 80a62000                 cmp     %i0, 0
F0030A70: 0280000b                 be      loc_F0030A9C
F0030A74: 01000000                 nop
F0030A78: d0062020                 ld      [%i0+0x20], %o0
F0030A7C: 80a20009                 cmp     %o0, %o1
F0030A80: 02800007                 be      loc_F0030A9C
F0030A84: 80a62000                 cmp     %i0, 0
F0030A88: f0062040                 ld      [%i0+0x40], %i0
F0030A8C: 80a62000                 cmp     %i0, 0
F0030A90: 32bffffb                 bne,a   loc_F0030A7C
F0030A94: d0062020                 ld      [%i0+0x20], %o0
F0030A98: 80a62000                 cmp     %i0, 0
F0030A9C: 32800017                 bne,a   loc_F0030AF8
F0030AA0: d004a004                 ld      [%l2+4], %o0
F0030AA4: e014a002                 lduh    [%l2+2], %l0
F0030AA8: 90100012                 mov     %l2, %o0
F0030AAC: 7fffe3b4                 call    _ifa_ifwithdstaddr
F0030AB0: c034a002                 clrh    [%l2+2]
F0030AB4: b0920000                 orcc    %o0, %g0, %i0
F0030AB8: 12800009                 bne     loc_F0030ADC
F0030ABC: e034a002                 sth     %l0, [%l2+2]
F0030AC0: d204a004                 ld      [%l2+4], %o1
F0030AC4: 9007bff4                 add     %fp, var_C, %o0
F0030AC8: 7ffff723                 call    _in_netof
F0030ACC: d227bff4                 st      %o1, [%fp+var_C]
F0030AD0: 7ffff9fc                 call    _in_iaonnetof
F0030AD4: 01000000                 nop
F0030AD8: b0920000                 orcc    %o0, %g0, %i0
F0030ADC: 12800004                 bne     loc_F0030AEC
F0030AE0: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F0030AE4: f0022070                 ld      [%o0+%lo(_in_ifaddr)], %i0
F0030AE8: 80a62000                 cmp     %i0, 0
F0030AEC: 2280005f                 be,a    locret_F0030C68
F0030AF0: b0102031                 mov     0x31, %i0 ! '1'
F0030AF4: d004a004                 ld      [%l2+4], %o0
F0030AF8: 133c0000                 sethi   -0x10000000, %o1
F0030AFC: 900a0009                 and     %o0, %o1, %o0
F0030B00: 13380000                 sethi   -0x20000000, %o1
F0030B04: 80a20009                 cmp     %o0, %o1
F0030B08: 3280001d                 bne,a   loc_F0030B7C
F0030B0C: a0100018                 mov     %i0, %l0
F0030B10: d204603c                 ld      [%l1+0x3C], %o1
F0030B14: 80a26000                 cmp     %o1, 0
F0030B18: 22800019                 be,a    loc_F0030B7C
F0030B1C: a0100018                 mov     %i0, %l0
F0030B20: d0026004                 ld      [%o1+4], %o0
F0030B24: d2024008                 ld      [%o1+%o0], %o1
F0030B28: 80a26000                 cmp     %o1, 0
F0030B2C: 02800013                 be      loc_F0030B78
F0030B30: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F0030B34: f0022070                 ld      [%o0+%lo(_in_ifaddr)], %i0
F0030B38: 80a62000                 cmp     %i0, 0
F0030B3C: 0280000b                 be      loc_F0030B68
F0030B40: 01000000                 nop
F0030B44: d0062020                 ld      [%i0+0x20], %o0
F0030B48: 80a20009                 cmp     %o0, %o1
F0030B4C: 02800007                 be      loc_F0030B68
F0030B50: 80a62000                 cmp     %i0, 0
F0030B54: f0062040                 ld      [%i0+0x40], %i0
F0030B58: 80a62000                 cmp     %i0, 0
F0030B5C: 32bffffb                 bne,a   loc_F0030B48
F0030B60: d0062020                 ld      [%i0+0x20], %o0
F0030B64: 80a62000                 cmp     %i0, 0
F0030B68: 12800005                 bne     loc_F0030B7C
F0030B6C: a0100018                 mov     %i0, %l0
F0030B70: 1080003e                 ba      locret_F0030C68
F0030B74: b0102031                 mov     0x31, %i0 ! '1'
F0030B78: a0100018                 mov     %i0, %l0
F0030B7C: d004a004                 ld      [%l2+4], %o0
F0030B80: d027bff4                 st      %o0, [%fp+var_C]
F0030B84: d0046014                 ld      [%l1+0x14], %o0
F0030B88: 80a22000                 cmp     %o0, 0
F0030B8C: 22800002                 be,a    loc_F0030B94
F0030B90: d0042004                 ld      [%l0+4], %o0
F0030B94: d027bff0                 st      %o0, [%fp+var_10]
F0030B98: d0046008                 ld      [%l1+8], %o0
F0030B9C: 9207bff4                 add     %fp, var_C, %o1
F0030BA0: d414a002                 lduh    [%l2+2], %o2
F0030BA4: 9607bff0                 add     %fp, var_10, %o3
F0030BA8: d8146018                 lduh    [%l1+0x18], %o4
F0030BAC: 400000e7                 call    _in_pcblookup
F0030BB0: 9a102000                 mov     0, %o5
F0030BB4: 80a22000                 cmp     %o0, 0
F0030BB8: 1280002c                 bne     locret_F0030C68
F0030BBC: b0102030                 mov     0x30, %i0 ! '0'
F0030BC0: d004601c                 ld      [%l1+0x1C], %o0
F0030BC4: d002200c                 ld      [%o0+0xC], %o0
F0030BC8: d012200a                 lduh    [%o0+0xA], %o0
F0030BCC: 808a2004                 btst    4, %o0
F0030BD0: 22800015                 be,a    loc_F0030C24
F0030BD4: d0046014                 ld      [%l1+0x14], %o0
F0030BD8: d214a002                 lduh    [%l2+2], %o1
F0030BDC: d0146018                 lduh    [%l1+0x18], %o0
F0030BE0: 80a24008                 cmp     %o1, %o0
F0030BE4: 12800010                 bne     loc_F0030C24
F0030BE8: d0046014                 ld      [%l1+0x14], %o0
F0030BEC: 80a22000                 cmp     %o0, 0
F0030BF0: 02800007                 be      loc_F0030C0C
F0030BF4: d204a004                 ld      [%l2+4], %o1
F0030BF8: 80a20009                 cmp     %o0, %o1
F0030BFC: 0280001b                 be      locret_F0030C68
F0030C00: b010203d                 mov     0x3D, %i0 ! '='
F0030C04: 10800009                 ba      loc_F0030C28
F0030C08: 80a22000                 cmp     %o0, 0
F0030C0C: d0042004                 ld      [%l0+4], %o0
F0030C10: 80a20009                 cmp     %o0, %o1
F0030C14: 32800004                 bne,a   loc_F0030C24
F0030C18: d0046014                 ld      [%l1+0x14], %o0
F0030C1C: 10800013                 ba      locret_F0030C68
F0030C20: b010203d                 mov     0x3D, %i0 ! '='
F0030C24: 80a22000                 cmp     %o0, 0
F0030C28: 3280000c                 bne,a   loc_F0030C58
F0030C2C: d004a004                 ld      [%l2+4], %o0
F0030C30: d0146018                 lduh    [%l1+0x18], %o0
F0030C34: 80a22000                 cmp     %o0, 0
F0030C38: 32800006                 bne,a   loc_F0030C50
F0030C3C: d0042004                 ld      [%l0+4], %o0
F0030C40: 90100011                 mov     %l1, %o0
F0030C44: 7ffffeab                 call    _in_pcbbind
F0030C48: 92102000                 mov     0, %o1
F0030C4C: d0042004                 ld      [%l0+4], %o0
F0030C50: d0246014                 st      %o0, [%l1+0x14]
F0030C54: d004a004                 ld      [%l2+4], %o0
F0030C58: d024600c                 st      %o0, [%l1+0xC]
F0030C5C: d014a002                 lduh    [%l2+2], %o0
F0030C60: b0102000                 mov     0, %i0
F0030C64: d0346010                 sth     %o0, [%l1+0x10]
F0030C68: 81c7e008                 ret
F0030C6C: 81e80000                 restore
