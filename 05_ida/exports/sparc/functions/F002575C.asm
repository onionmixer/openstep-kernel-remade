F002575C: 9de3bf98                 save    %sp, -0x68, %sp
F0025760: 113c0430                 sethi   %hi(_doingcache), %o0
F0025764: d0022090                 ld      [%o0+%lo(_doingcache)], %o0! __s
F0025768: 80a22000                 cmp     %o0, 0
F002576C: 0280008d                 be      locret_F00259A0
F0025770: 01000000                 nop
F0025774: 7fff8731                 call    _strlen
F0025778: 90100019                 mov     %i1, %o0
F002577C: a2100008                 mov     %o0, %l1
F0025780: 80a46020                 cmp     %l1, 0x20 ! ' '
F0025784: 04800007                 ble     loc_F00257A0
F0025788: 133c04d5                 sethi   %hi(_ncstats), %o1
F002578C: 921261f0                 bset    %lo(_ncstats), %o1
F0025790: d0026010                 ld      [%o1+0x10], %o0
F0025794: 90022001                 inc     %o0
F0025798: 10800082                 ba      locret_F00259A0
F002579C: d0226010                 st      %o0, [%o1+0x10]
F00257A0: 90100018                 mov     %i0, %o0
F00257A4: 94044019                 add     %l1, %i1, %o2
F00257A8: d84abfff                 ldsb    [%o2-1], %o4
F00257AC: 92100019                 mov     %i1, %o1
F00257B0: d64e4000                 ldsb    [%i1], %o3
F00257B4: 94100011                 mov     %l1, %o2
F00257B8: 9602c00c                 add     %o3, %o4, %o3
F00257BC: 9602c011                 add     %o3, %l1, %o3
F00257C0: 9602c018                 add     %o3, %i0, %o3
F00257C4: a40ae03f                 and     %o3, 0x3F, %l2
F00257C8: 96100012                 mov     %l2, %o3
F00257CC: 400001bd                 call    sub_F0025EC0
F00257D0: 9810001b                 mov     %i3, %o4
F00257D4: 80a22000                 cmp     %o0, 0
F00257D8: 02800007                 be      loc_F00257F4
F00257DC: 133c04d5                 sethi   %hi(_ncstats), %o1
F00257E0: 921261f0                 bset    %lo(_ncstats), %o1
F00257E4: d002600c                 ld      [%o1+0xC], %o0
F00257E8: 90022001                 inc     %o0
F00257EC: 1080006d                 ba      locret_F00259A0
F00257F0: d022600c                 st      %o0, [%o1+0xC]
F00257F4: 133c04d5901261d8         set     dword_F01355D8, %o0
F00257FC: e00261d8                 ld      [%o1+0x1D8], %l0
F0025800: 90023ff8                 inc     -8, %o0
F0025804: 80a40008                 cmp     %l0, %o0
F0025808: 32800008                 bne,a   loc_F0025828
F002580C: d204200c                 ld      [%l0+0xC], %o1
F0025810: 133c04d5921261f0         set     _ncstats, %o1
F0025818: d0026018                 ld      [%o1+0x18], %o0
F002581C: 90022001                 inc     %o0
F0025820: 10800060                 ba      locret_F00259A0
F0025824: d0226018                 st      %o0, [%o1+0x18]
F0025828: d0042008                 ld      [%l0+8], %o0
F002582C: d0226008                 st      %o0, [%o1+8]
F0025830: d2042008                 ld      [%l0+8], %o1
F0025834: d004200c                 ld      [%l0+0xC], %o0
F0025838: d022600c                 st      %o0, [%o1+0xC]
F002583C: d2040000                 ld      [%l0], %o1
F0025840: d0042004                 ld      [%l0+4], %o0
F0025844: d0226004                 st      %o0, [%o1+4]
F0025848: d2042004                 ld      [%l0+4], %o1
F002584C: d0040000                 ld      [%l0], %o0
F0025850: d0224000                 st      %o0, [%o1]
F0025854: d0042014                 ld      [%l0+0x14], %o0
F0025858: 80a22000                 cmp     %o0, 0
F002585C: 02800010                 be      loc_F002589C
F0025860: d0042010                 ld      [%l0+0x10], %o0
F0025864: 80a22000                 cmp     %o0, 0
F0025868: 02800006                 be      loc_F0025880
F002586C: 133c04d5                 sethi   %hi(_ncstats), %o1
F0025870: 921261f0                 bset    %lo(_ncstats), %o1
F0025874: d0026020                 ld      [%o1+0x20], %o0
F0025878: 90023fff                 inc     -1, %o0
F002587C: d0226020                 st      %o0, [%o1+0x20]
F0025880: d0042014                 ld      [%l0+0x14], %o0
F0025884: 80a22000                 cmp     %o0, 0
F0025888: 22800005                 be,a    loc_F002589C
F002588C: d0042010                 ld      [%l0+0x10], %o0
F0025890: 40000cb5                 call    _vn_rele
F0025894: 01000000                 nop
F0025898: d0042010                 ld      [%l0+0x10], %o0
F002589C: 80a22000                 cmp     %o0, 0
F00258A0: 22800005                 be,a    loc_F00258B4
F00258A4: d004203c                 ld      [%l0+0x3C], %o0
F00258A8: 40000caf                 call    _vn_rele
F00258AC: 01000000                 nop
F00258B0: d004203c                 ld      [%l0+0x3C], %o0
F00258B4: 80a22000                 cmp     %o0, 0
F00258B8: 22800005                 be,a    loc_F00258CC
F00258BC: d04c2044                 ldsb    [%l0+0x44], %o0
F00258C0: 7fffa856                 call    _crfree
F00258C4: 01000000                 nop
F00258C8: d04c2044                 ldsb    [%l0+0x44], %o0
F00258CC: 80a22000                 cmp     %o0, 0
F00258D0: 22800006                 be,a    loc_F00258E8
F00258D4: f0242014                 st      %i0, [%l0+0x14]
F00258D8: d0042040                 ld      [%l0+0x40], %o0
F00258DC: 40010a31                 call    _kfree
F00258E0: d2542046                 ldsh    [%l0+0x46], %o1
F00258E4: f0242014                 st      %i0, [%l0+0x14]
F00258E8: 90100019                 mov     %i1, %o0! void *
F00258EC: d4162006                 lduh    [%i0+6], %o2
F00258F0: 92042019                 add     %l0, 0x19, %o1! void *
F00258F4: 9402a001                 inc     %o2
F00258F8: d4362006                 sth     %o2, [%i0+6]
F00258FC: f4242010                 st      %i2, [%l0+0x10]
F0025900: d616a006                 lduh    [%i2+6], %o3
F0025904: 94100011                 mov     %l1, %o2! size_t
F0025908: 9602e001                 inc     %o3
F002590C: d636a006                 sth     %o3, [%i2+6]
F0025910: 4001bc80                 call    _bcopy
F0025914: d42c2018                 stb     %o2, [%l0+0x18]
F0025918: c02c2044                 clrb    [%l0+0x44]
F002591C: c0342046                 clrh    [%l0+0x46]
F0025920: c0242040                 clr     [%l0+0x40]
F0025924: 80a6e000                 cmp     %i3, 0
F0025928: 02800005                 be      loc_F002593C
F002592C: f624203c                 st      %i3, [%l0+0x3C]
F0025930: d016c000                 lduh    [%i3], %o0
F0025934: 90022001                 inc     %o0
F0025938: d036c000                 sth     %o0, [%i3]
F002593C: 113c04d5                 sethi   %hi(dword_F01355DC), %o0
F0025940: d00221dc                 ld      [%o0+%lo(dword_F01355DC)], %o0
F0025944: d2022008                 ld      [%o0+8], %o1
F0025948: 952ca003                 sll     %l2, 3, %o2
F002594C: e0222008                 st      %l0, [%o0+8]
F0025950: d2242008                 st      %o1, [%l0+8]
F0025954: e022600c                 st      %l0, [%o1+0xC]
F0025958: d024200c                 st      %o0, [%l0+0xC]
F002595C: 133c04d4921263d0         set     _nc_hash, %o1
F0025964: d0028009                 ld      [%o2+%o1], %o0
F0025968: d0240000                 st      %o0, [%l0]
F002596C: 90028009                 add     %o2, %o1, %o0
F0025970: d0242004                 st      %o0, [%l0+4]
F0025974: d0028009                 ld      [%o2+%o1], %o0
F0025978: e0222004                 st      %l0, [%o0+4]
F002597C: e0228009                 st      %l0, [%o2+%o1]
F0025980: 153c04d59412a1f0         set     _ncstats, %o2
F0025988: d002a020                 ld      [%o2+0x20], %o0
F002598C: d202a008                 ld      [%o2+8], %o1
F0025990: 90022001                 inc     %o0
F0025994: d022a020                 st      %o0, [%o2+0x20]
F0025998: 92026001                 inc     %o1
F002599C: d222a008                 st      %o1, [%o2+8]
F00259A0: 81c7e008                 ret
F00259A4: 81e80000                 restore
