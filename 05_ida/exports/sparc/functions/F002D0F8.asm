F002D0F8: 9de3bf90                 save    %sp, -0x70, %sp
F002D0FC: ac100018                 mov     %i0, %l6
F002D100: a2102000                 mov     0, %l1
F002D104: e0166004                 lduh    [%i1+4], %l0
F002D108: 80a42010                 cmp     %l0, 0x10
F002D10C: 08800004                 bleu    loc_F002D11C
F002D110: b0102000                 mov     0, %i0
F002D114: 108000c1                 ba      locret_F002D418
F002D118: b010202f                 mov     0x2F, %i0 ! '/'
F002D11C: 952c2003                 sll     %l0, 3, %o2
F002D120: 133c043092126150         set     _afswitch, %o1
F002D128: d4028009                 ld      [%o2+%o1], %o2! size_t
F002D12C: 90066004                 add     %i1, 4, %o0
F002D130: 9fc28000                 call    %o2
F002D134: 9207bff0                 add     %fp, var_10, %o1
F002D138: d0166024                 lduh    [%i1+0x24], %o0
F002D13C: 808a2004                 btst    4, %o0
F002D140: 02800005                 be      loc_F002D154
F002D144: e607bff0                 ld      [%fp+var_10], %l3
F002D148: 113c04d4                 sethi   %hi(_rthost), %o0
F002D14C: 10800005                 ba      loc_F002D160
F002D150: 90122240                 bset    %lo(_rthost), %o0
F002D154: e607bff4                 ld      [%fp+var_C], %l3
F002D158: 113c04d490122260         set     _rtnet, %o0
F002D160: 920ce007                 and     %l3, 7, %o1
F002D164: 932a6002                 sll     %o1, 2, %o1
F002D168: a4024008                 add     %o1, %o0, %l2
F002D16C: 932c2003                 sll     %l0, 3, %o1
F002D170: 113c043090122150         set     _afswitch, %o0
F002D178: 92024008                 add     %o1, %o0, %o1
F002D17C: 4001a68f                 call    _spltty
F002D180: ea026004                 ld      [%o1+4], %l5
F002D184: a8100012                 mov     %l2, %l4
F002D188: e0050000                 ld      [%l4], %l0
F002D18C: 80a42000                 cmp     %l0, 0
F002D190: 0280002a                 be      loc_F002D238
F002D194: ae100008                 mov     %o0, %l7
F002D198: d0042004                 ld      [%l0+4], %o0
F002D19C: d2040008                 ld      [%l0+%o0], %o1
F002D1A0: 80a24013                 cmp     %o1, %l3
F002D1A4: 12800020                 bne     loc_F002D224
F002D1A8: a2040008                 add     %l0, %o0, %l1
F002D1AC: d0166024                 lduh    [%i1+0x24], %o0
F002D1B0: 808a2004                 btst    4, %o0
F002D1B4: 1280000f                 bne     loc_F002D1F0
F002D1B8: 90046004                 add     %l1, 4, %o0
F002D1BC: d2146004                 lduh    [%l1+4], %o1
F002D1C0: d0166004                 lduh    [%i1+4], %o0
F002D1C4: 80a24008                 cmp     %o1, %o0
F002D1C8: 32800018                 bne,a   loc_F002D228
F002D1CC: a4100010                 mov     %l0, %l2
F002D1D0: 90046004                 add     %l1, 4, %o0
F002D1D4: 9fc54000                 call    %l5
F002D1D8: 92066004                 add     %i1, 4, %o1
F002D1DC: 80a22000                 cmp     %o0, 0
F002D1E0: 1280000b                 bne     loc_F002D20C
F002D1E4: 90046014                 add     %l1, 0x14, %o0! void *
F002D1E8: 10800010                 ba      loc_F002D228
F002D1EC: a4100010                 mov     %l0, %l2
F002D1F0: 92066004                 add     %i1, 4, %o1! void *
F002D1F4: 7fff635a                 call    _bcmp
F002D1F8: 94102010                 mov     0x10, %o2! size_t
F002D1FC: 80a22000                 cmp     %o0, 0
F002D200: 3280000a                 bne,a   loc_F002D228
F002D204: a4100010                 mov     %l0, %l2
F002D208: 90046014                 add     %l1, 0x14, %o0! void *
F002D20C: 92066014                 add     %i1, 0x14, %o1! void *
F002D210: 7fff6353                 call    _bcmp
F002D214: 94102010                 mov     0x10, %o2
F002D218: 80a22000                 cmp     %o0, 0
F002D21C: 02800008                 be      loc_F002D23C
F002D220: 11200c1c                 sethi   -0x7FCF9000, %o0
F002D224: a4100010                 mov     %l0, %l2
F002D228: e0040000                 ld      [%l0], %l0
F002D22C: 80a42000                 cmp     %l0, 0
F002D230: 32bfffdb                 bne,a   loc_F002D19C
F002D234: d0042004                 ld      [%l0+4], %o0
F002D238: 11200c1c                 sethi   -0x7FCF9000, %o0
F002D23C: 9012220a                 bset    0x20A, %o0
F002D240: 80a58008                 cmp     %l6, %o0
F002D244: 0280001a                 be      loc_F002D2AC
F002D248: 11200c1c                 sethi   -0x7FCF9000, %o0
F002D24C: 9012220b                 bset    0x20B, %o0
F002D250: 80a58008                 cmp     %l6, %o0
F002D254: 1280006f                 bne     loc_F002D410
F002D258: 80a42000                 cmp     %l0, 0
F002D25C: 32800004                 bne,a   loc_F002D26C
F002D260: d0040000                 ld      [%l0], %o0
F002D264: 1080006b                 ba      loc_F002D410
F002D268: b0102003                 mov     3, %i0
F002D26C: d0248000                 st      %o0, [%l2]
F002D270: d0546026                 ldsh    [%l1+0x26], %o0
F002D274: 80a22000                 cmp     %o0, 0
F002D278: 0480000a                 ble     loc_F002D2A0
F002D27C: 153c04d9                 sethi   %hi(_rttrash), %o2
F002D280: d0146024                 lduh    [%l1+0x24], %o0
F002D284: d202a050                 ld      [%o2+%lo(_rttrash)], %o1
F002D288: 900a3ffe                 and     %o0, -2, %o0
F002D28C: d0346024                 sth     %o0, [%l1+0x24]
F002D290: 92026001                 inc     %o1
F002D294: d222a050                 st      %o1, [%o2+%lo(_rttrash)]
F002D298: 1080005e                 ba      loc_F002D410
F002D29C: c0240000                 clr     [%l0]
F002D2A0: 7fffc205                 call    _m_free
F002D2A4: 90100010                 mov     %l0, %o0
F002D2A8: 3080005a                 ba,a    loc_F002D410
F002D2AC: 80a42000                 cmp     %l0, 0
F002D2B0: 22800004                 be,a    loc_F002D2C0
F002D2B4: d0166024                 lduh    [%i1+0x24], %o0
F002D2B8: 10800056                 ba      loc_F002D410
F002D2BC: b0102011                 mov     0x11, %i0
F002D2C0: 808a2002                 btst    2, %o0
F002D2C4: 1280000e                 bne     loc_F002D2FC
F002D2C8: 808a2004                 btst    4, %o0
F002D2CC: 02800005                 be      loc_F002D2E0
F002D2D0: a4102000                 mov     0, %l2
F002D2D4: 7ffff1aa                 call    _ifa_ifwithdstaddr
F002D2D8: 90066004                 add     %i1, 4, %o0
F002D2DC: a4100008                 mov     %o0, %l2
F002D2E0: 80a4a000                 cmp     %l2, 0
F002D2E4: 12800013                 bne     loc_F002D330
F002D2E8: 90102000                 mov     0, %o0
F002D2EC: 7ffff177                 call    _ifa_ifwithaddr
F002D2F0: 90066014                 add     %i1, 0x14, %o0
F002D2F4: 10800005                 ba      loc_F002D308
F002D2F8: a4100008                 mov     %o0, %l2
F002D2FC: 7ffff1a0                 call    _ifa_ifwithdstaddr
F002D300: 90066014                 add     %i1, 0x14, %o0
F002D304: a4100008                 mov     %o0, %l2
F002D308: 80a4a000                 cmp     %l2, 0
F002D30C: 12800009                 bne     loc_F002D330
F002D310: 90102000                 mov     0, %o0
F002D314: 7ffff1bf                 call    _ifa_ifwithnet
F002D318: 90066014                 add     %i1, 0x14, %o0
F002D31C: a4920000                 orcc    %o0, %g0, %l2
F002D320: 12800004                 bne     loc_F002D330
F002D324: 90102000                 mov     0, %o0
F002D328: 1080003a                 ba      loc_F002D410
F002D32C: b0102033                 mov     0x33, %i0 ! '3'
F002D330: 7fffc18b                 call    _m_get
F002D334: 92102005                 mov     5, %o1
F002D338: a0920000                 orcc    %o0, %g0, %l0
F002D33C: 32800004                 bne,a   loc_F002D34C
F002D340: d0050000                 ld      [%l4], %o0
F002D344: 10800033                 ba      loc_F002D410
F002D348: b0102037                 mov     0x37, %i0 ! '7'
F002D34C: d0240000                 st      %o0, [%l0]
F002D350: e0250000                 st      %l0, [%l4]
F002D354: 9010200c                 mov     0xC, %o0
F002D358: d0242004                 st      %o0, [%l0+4]
F002D35C: 90102030                 mov     0x30, %o0 ! '0'
F002D360: d2042004                 ld      [%l0+4], %o1
F002D364: d0342008                 sth     %o0, [%l0+8]
F002D368: e6240009                 st      %l3, [%l0+%o1]
F002D36C: d0166004                 lduh    [%i1+4], %o0
F002D370: a2040009                 add     %l0, %o1, %l1
F002D374: d0346004                 sth     %o0, [%l1+4]
F002D378: d0166006                 lduh    [%i1+6], %o0
F002D37C: d0346006                 sth     %o0, [%l1+6]
F002D380: d0166008                 lduh    [%i1+8], %o0
F002D384: d0346008                 sth     %o0, [%l1+8]
F002D388: d016600a                 lduh    [%i1+0xA], %o0
F002D38C: d034600a                 sth     %o0, [%l1+0xA]
F002D390: d016600c                 lduh    [%i1+0xC], %o0
F002D394: d034600c                 sth     %o0, [%l1+0xC]
F002D398: d016600e                 lduh    [%i1+0xE], %o0
F002D39C: d034600e                 sth     %o0, [%l1+0xE]
F002D3A0: d0166010                 lduh    [%i1+0x10], %o0
F002D3A4: d0346010                 sth     %o0, [%l1+0x10]
F002D3A8: d0166012                 lduh    [%i1+0x12], %o0
F002D3AC: d0346012                 sth     %o0, [%l1+0x12]
F002D3B0: d0166014                 lduh    [%i1+0x14], %o0
F002D3B4: d0346014                 sth     %o0, [%l1+0x14]
F002D3B8: d0166016                 lduh    [%i1+0x16], %o0
F002D3BC: d0346016                 sth     %o0, [%l1+0x16]
F002D3C0: d0166018                 lduh    [%i1+0x18], %o0
F002D3C4: d0346018                 sth     %o0, [%l1+0x18]
F002D3C8: d016601a                 lduh    [%i1+0x1A], %o0
F002D3CC: d034601a                 sth     %o0, [%l1+0x1A]
F002D3D0: d016601c                 lduh    [%i1+0x1C], %o0
F002D3D4: d034601c                 sth     %o0, [%l1+0x1C]
F002D3D8: d016601e                 lduh    [%i1+0x1E], %o0
F002D3DC: d034601e                 sth     %o0, [%l1+0x1E]
F002D3E0: d0166020                 lduh    [%i1+0x20], %o0
F002D3E4: d0346020                 sth     %o0, [%l1+0x20]
F002D3E8: d0166022                 lduh    [%i1+0x22], %o0
F002D3EC: d0346022                 sth     %o0, [%l1+0x22]
F002D3F0: d0166024                 lduh    [%i1+0x24], %o0
F002D3F4: 900a2016                 and     %o0, 0x16, %o0
F002D3F8: 90122001                 bset    1, %o0
F002D3FC: d0346024                 sth     %o0, [%l1+0x24]
F002D400: c0346026                 clrh    [%l1+0x26]
F002D404: c0246028                 clr     [%l1+0x28]
F002D408: d004a020                 ld      [%l2+0x20], %o0
F002D40C: d024602c                 st      %o0, [%l1+0x2C]
F002D410: 4001a645                 call    _splx
F002D414: 90100017                 mov     %l7, %o0
F002D418: 81c7e008                 ret
F002D41C: 81e80000                 restore
