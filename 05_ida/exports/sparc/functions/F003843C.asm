F003843C: 9de3bf70                 save    %sp, -0x90, %sp
F0038440: d0062004                 ld      [%i0+4], %o0
F0038444: 80a2207c                 cmp     %o0, 0x7C ! '|'
F0038448: 18800006                 bgu     loc_F0038460
F003844C: 90100018                 mov     %i0, %o0
F0038450: d0162008                 lduh    [%i0+8], %o0
F0038454: 80a2201b                 cmp     %o0, 0x1B
F0038458: 1880000c                 bgu     loc_F0038488
F003845C: 90100018                 mov     %i0, %o0
F0038460: 7fff971d                 call    _m_pullup
F0038464: 9210201c                 mov     0x1C, %o1
F0038468: b0920000                 orcc    %o0, %g0, %i0
F003846C: 32800008                 bne,a   loc_F003848C
F0038470: d2062004                 ld      [%i0+4], %o1
F0038474: 133c04d9                 sethi   %hi(_udpstat), %o1
F0038478: d0026140                 ld      [%o1+%lo(_udpstat)], %o0
F003847C: 90022001                 inc     %o0
F0038480: 1080010e                 ba      locret_F00388B8
F0038484: d0226140                 st      %o0, [%o1+%lo(_udpstat)]
F0038488: d2062004                 ld      [%i0+4], %o1
F003848C: d00e0009                 ldub    [%i0+%o1], %o0
F0038490: 900a200f                 and     %o0, 0xF, %o0
F0038494: 80a22005                 cmp     %o0, 5
F0038498: 08800005                 bleu    loc_F00384AC
F003849C: a4060009                 add     %i0, %o1, %l2
F00384A0: 90100012                 mov     %l2, %o0
F00384A4: 7fffea9c                 call    _ip_stripoptions
F00384A8: 92102000                 mov     0, %o1
F00384AC: e014a018                 lduh    [%l2+0x18], %l0
F00384B0: d254a002                 ldsh    [%l2+2], %o1
F00384B4: 80a24010                 cmp     %o1, %l0
F00384B8: 0280000c                 be      loc_F00384E8
F00384BC: 80a40009                 cmp     %l0, %o1
F00384C0: 04800008                 ble     loc_F00384E0
F00384C4: 90100018                 mov     %i0, %o0
F00384C8: 133c04d992126140         set     _udpstat, %o1
F00384D0: d0026008                 ld      [%o1+8], %o0
F00384D4: 90022001                 inc     %o0
F00384D8: 108000f5                 ba      loc_F00388AC
F00384DC: d0226008                 st      %o0, [%o1+8]
F00384E0: 7fff96c0                 call    _m_adj
F00384E4: 92240009                 sub     %l0, %o1, %o1
F00384E8: d0048000                 ld      [%l2], %o0
F00384EC: d027bfe0                 st      %o0, [%fp+var_20]
F00384F0: d004a004                 ld      [%l2+4], %o0
F00384F4: d027bfe4                 st      %o0, [%fp+var_1C]
F00384F8: d004a008                 ld      [%l2+8], %o0
F00384FC: d027bfe8                 st      %o0, [%fp+var_18]
F0038500: d204a00c                 ld      [%l2+0xC], %o1
F0038504: 113c0432                 sethi   %hi(_udpcksum), %o0
F0038508: d4022170                 ld      [%o0+%lo(_udpcksum)], %o2
F003850C: d227bfec                 st      %o1, [%fp+var_14]
F0038510: d004a010                 ld      [%l2+0x10], %o0
F0038514: 80a2a000                 cmp     %o2, 0
F0038518: 02800018                 be      loc_F0038578
F003851C: d027bff0                 st      %o0, [%fp+var_10]
F0038520: d014a01a                 lduh    [%l2+0x1A], %o0
F0038524: 80a22000                 cmp     %o0, 0
F0038528: 02800014                 be      loc_F0038578
F003852C: 90100018                 mov     %i0, %o0
F0038530: c024a004                 clr     [%l2+4]
F0038534: c0248000                 clr     [%l2]
F0038538: c02ca008                 clrb    [%l2+8]
F003853C: d414a018                 lduh    [%l2+0x18], %o2
F0038540: 92042014                 add     %l0, 0x14, %o1
F0038544: 40018251                 call    _in_cksum
F0038548: d434a00a                 sth     %o2, [%l2+0xA]
F003854C: d034a01a                 sth     %o0, [%l2+0x1A]
F0038550: 912a2010                 sll     %o0, 16, %o0
F0038554: 80a22000                 cmp     %o0, 0
F0038558: 02800008                 be      loc_F0038578
F003855C: 153c04d9                 sethi   %hi(_udpstat), %o2
F0038560: 9412a140                 bset    %lo(_udpstat), %o2
F0038564: d202a004                 ld      [%o2+4], %o1
F0038568: 90100018                 mov     %i0, %o0
F003856C: 92026001                 inc     %o1
F0038570: 108000d0                 ba      loc_F00388B0
F0038574: d222a004                 st      %o1, [%o2+4]
F0038578: d404a010                 ld      [%l2+0x10], %o2
F003857C: 113c0000                 sethi   -0x10000000, %o0
F0038580: 13380000                 sethi   -0x20000000, %o1
F0038584: 900a8008                 and     %o2, %o0, %o0
F0038588: 80a20009                 cmp     %o0, %o1
F003858C: 02800008                 be      loc_F00385AC
F0038590: 113c0432                 sethi   -0xFEF3800, %o0
F0038594: d427bfdc                 st      %o2, [%fp+var_24]
F0038598: 7fffdb5c                 call    _in_broadcast
F003859C: 9007bfdc                 add     %fp, var_24, %o0
F00385A0: 80a22000                 cmp     %o0, 0
F00385A4: 0280005f                 be      loc_F0038720
F00385A8: 113c0432                 sethi   -0xFEF3800, %o0
F00385AC: d214a014                 lduh    [%l2+0x14], %o1
F00385B0: 90122178                 bset    0x178, %o0
F00385B4: d2322002                 sth     %o1, [%o0+2]
F00385B8: d204a00c                 ld      [%l2+0xC], %o1
F00385BC: d2222004                 st      %o1, [%o0+4]
F00385C0: d2162008                 lduh    [%i0+8], %o1
F00385C4: d0062004                 ld      [%i0+4], %o0
F00385C8: 92027fe4                 inc     -0x1C, %o1
F00385CC: d2362008                 sth     %o1, [%i0+8]
F00385D0: 9002201c                 inc     0x1C, %o0
F00385D4: d0262004                 st      %o0, [%i0+4]
F00385D8: 113c04d9                 sethi   %hi(_udb), %o0
F00385DC: e2022100                 ld      [%o0+%lo(_udb)], %l1
F00385E0: 90122100                 bset    %lo(_udb), %o0
F00385E4: 80a44008                 cmp     %l1, %o0
F00385E8: 0280003f                 be      loc_F00386E4
F00385EC: a6102000                 mov     0, %l3
F00385F0: a8100008                 mov     %o0, %l4
F00385F4: d2146018                 lduh    [%l1+0x18], %o1
F00385F8: d014a016                 lduh    [%l2+0x16], %o0
F00385FC: 80a24008                 cmp     %o1, %o0
F0038600: 32800036                 bne,a   loc_F00386D8
F0038604: e2044000                 ld      [%l1], %l1
F0038608: d2046014                 ld      [%l1+0x14], %o1
F003860C: 80a26000                 cmp     %o1, 0
F0038610: 22800007                 be,a    loc_F003862C
F0038614: d204600c                 ld      [%l1+0xC], %o1
F0038618: d004a010                 ld      [%l2+0x10], %o0
F003861C: 80a24008                 cmp     %o1, %o0
F0038620: 3280002e                 bne,a   loc_F00386D8
F0038624: e2044000                 ld      [%l1], %l1
F0038628: d204600c                 ld      [%l1+0xC], %o1
F003862C: 80a26000                 cmp     %o1, 0
F0038630: 0280000c                 be      loc_F0038660
F0038634: 80a4e000                 cmp     %l3, 0
F0038638: d004a00c                 ld      [%l2+0xC], %o0
F003863C: 80a24008                 cmp     %o1, %o0
F0038640: 32800026                 bne,a   loc_F00386D8
F0038644: e2044000                 ld      [%l1], %l1
F0038648: d2146010                 lduh    [%l1+0x10], %o1
F003864C: d014a014                 lduh    [%l2+0x14], %o0
F0038650: 80a24008                 cmp     %o1, %o0
F0038654: 32800021                 bne,a   loc_F00386D8
F0038658: e2044000                 ld      [%l1], %l1
F003865C: 80a4e000                 cmp     %l3, 0
F0038660: 02800018                 be      loc_F00386C0
F0038664: 90100018                 mov     %i0, %o0
F0038668: 92102000                 mov     0, %o1
F003866C: 150ee6b2                 sethi   0x3B9AC800, %o2
F0038670: 7fff95b5                 call    _m_copy
F0038674: 9412a200                 bset    0x200, %o2
F0038678: b2920000                 orcc    %o0, %g0, %i1
F003867C: 02800011                 be      loc_F00386C0
F0038680: 94100019                 mov     %i1, %o2
F0038684: a004e024                 add     %l3, 0x24, %l0 ! '$'
F0038688: 90100010                 mov     %l0, %o0
F003868C: 133c043292126178         set     _udp_in, %o1
F0038694: 7fff9fea                 call    _sbappendaddr
F0038698: 96102000                 mov     0, %o3
F003869C: 80a22000                 cmp     %o0, 0
F00386A0: 12800006                 bne     loc_F00386B8
F00386A4: 90100013                 mov     %l3, %o0
F00386A8: 7fff956f                 call    _m_freem
F00386AC: 90100019                 mov     %i1, %o0
F00386B0: 10800005                 ba      loc_F00386C4
F00386B4: e604601c                 ld      [%l1+0x1C], %l3
F00386B8: 7fff9f55                 call    _sowakeup
F00386BC: 92100010                 mov     %l0, %o1
F00386C0: e604601c                 ld      [%l1+0x1C], %l3
F00386C4: d014e002                 lduh    [%l3+2], %o0
F00386C8: 808a2004                 btst    4, %o0
F00386CC: 02800007                 be      loc_F00386E8
F00386D0: 80a4e000                 cmp     %l3, 0
F00386D4: e2044000                 ld      [%l1], %l1
F00386D8: 80a44014                 cmp     %l1, %l4
F00386DC: 32bfffc7                 bne,a   loc_F00385F8
F00386E0: d2146018                 lduh    [%l1+0x18], %o1
F00386E4: 80a4e000                 cmp     %l3, 0
F00386E8: 02800071                 be      loc_F00388AC
F00386EC: a004e024                 add     %l3, 0x24, %l0 ! '$'
F00386F0: 90100010                 mov     %l0, %o0
F00386F4: 133c043292126178         set     _udp_in, %o1
F00386FC: 94100018                 mov     %i0, %o2
F0038700: 7fff9fcf                 call    _sbappendaddr
F0038704: 96102000                 mov     0, %o3
F0038708: 80a22000                 cmp     %o0, 0
F003870C: 02800068                 be      loc_F00388AC
F0038710: 90100013                 mov     %l3, %o0
F0038714: 7fff9f3e                 call    _sowakeup
F0038718: 92100010                 mov     %l0, %o1
F003871C: 30800067                 ba,a    locret_F00388B8
F0038720: 113c04d9                 sethi   %hi(_udb), %o0
F0038724: d204a00c                 ld      [%l2+0xC], %o1
F0038728: 90122100                 bset    %lo(_udb), %o0
F003872C: d227bfd8                 st      %o1, [%fp+var_28]
F0038730: d404a010                 ld      [%l2+0x10], %o2
F0038734: 9607bfd4                 add     %fp, var_2C, %o3
F0038738: d427bfd4                 st      %o2, [%fp+var_2C]
F003873C: d414a014                 lduh    [%l2+0x14], %o2
F0038740: 9a102001                 mov     1, %o5
F0038744: d814a016                 lduh    [%l2+0x16], %o4
F0038748: 7fffe200                 call    _in_pcblookup
F003874C: 9207bfd8                 add     %fp, var_28, %o1
F0038750: a2920000                 orcc    %o0, %g0, %l1
F0038754: 3280003f                 bne,a   loc_F0038850
F0038758: 133c0432                 sethi   -0xFEF3800, %o1
F003875C: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F0038760: d4022070                 ld      [%o0+%lo(_in_ifaddr)], %o2
F0038764: 80a2a000                 cmp     %o2, 0
F0038768: 0280001d                 be      loc_F00387DC
F003876C: d604a010                 ld      [%l2+0x10], %o3
F0038770: d002a020                 ld      [%o2+0x20], %o0
F0038774: d012200c                 lduh    [%o0+0xC], %o0
F0038778: 808a2002                 btst    2, %o0
F003877C: 22800015                 be,a    loc_F00387D0
F0038780: d402a040                 ld      [%o2+0x40], %o2
F0038784: d202a028                 ld      [%o2+0x28], %o1
F0038788: d002a02c                 ld      [%o2+0x2C], %o0
F003878C: 921a400b                 btog    %o3, %o1
F0038790: 90380008                 xnor    %g0, %o0, %o0
F0038794: 80a24008                 cmp     %o1, %o0
F0038798: 02800045                 be      loc_F00388AC
F003879C: 80a26000                 cmp     %o1, 0
F00387A0: 02800044                 be      loc_F00388B0
F00387A4: 90100018                 mov     %i0, %o0
F00387A8: d202a030                 ld      [%o2+0x30], %o1
F00387AC: d002a034                 ld      [%o2+0x34], %o0
F00387B0: 921a400b                 btog    %o3, %o1
F00387B4: 90380008                 xnor    %g0, %o0, %o0
F00387B8: 80a24008                 cmp     %o1, %o0
F00387BC: 0280003c                 be      loc_F00388AC
F00387C0: 80a26000                 cmp     %o1, 0
F00387C4: 0280003b                 be      loc_F00388B0
F00387C8: 90100018                 mov     %i0, %o0
F00387CC: d402a040                 ld      [%o2+0x40], %o2
F00387D0: 80a2a000                 cmp     %o2, 0
F00387D4: 32bfffe8                 bne,a   loc_F0038774
F00387D8: d002a020                 ld      [%o2+0x20], %o0
F00387DC: d004a010                 ld      [%l2+0x10], %o0
F00387E0: 80a23fff                 cmp     %o0, -1
F00387E4: 02800032                 be      loc_F00388AC
F00387E8: 80a22000                 cmp     %o0, 0
F00387EC: 22800031                 be,a    loc_F00388B0
F00387F0: 90100018                 mov     %i0, %o0
F00387F4: d027bfd4                 st      %o0, [%fp+var_2C]
F00387F8: 7fffdac4                 call    _in_broadcast
F00387FC: 9007bfd4                 add     %fp, var_2C, %o0
F0038800: 80a22000                 cmp     %o0, 0
F0038804: 1280002b                 bne     loc_F00388B0
F0038808: 90100018                 mov     %i0, %o0
F003880C: d207bfe0                 ld      [%fp+var_20], %o1
F0038810: 90100012                 mov     %l2, %o0
F0038814: d2220000                 st      %o1, [%o0]
F0038818: d407bfe4                 ld      [%fp+var_1C], %o2
F003881C: 92102003                 mov     3, %o1
F0038820: d4222004                 st      %o2, [%o0+4]
F0038824: d607bfe8                 ld      [%fp+var_18], %o3
F0038828: 94102003                 mov     3, %o2
F003882C: d6222008                 st      %o3, [%o0+8]
F0038830: d807bfec                 ld      [%fp+var_14], %o4
F0038834: 96100019                 mov     %i1, %o3
F0038838: d822200c                 st      %o4, [%o0+0xC]
F003883C: da07bff0                 ld      [%fp+var_10], %o5
F0038840: 98102000                 mov     0, %o4
F0038844: 7fffe20a                 call    _icmp_error
F0038848: da222010                 st      %o5, [%o0+0x10]
F003884C: 3080001b                 ba,a    locret_F00388B8
F0038850: d014a014                 lduh    [%l2+0x14], %o0
F0038854: 92126178                 bset    0x178, %o1
F0038858: d0326002                 sth     %o0, [%o1+2]
F003885C: d004a00c                 ld      [%l2+0xC], %o0
F0038860: d0226004                 st      %o0, [%o1+4]
F0038864: d6162008                 lduh    [%i0+8], %o3
F0038868: 94100018                 mov     %i0, %o2
F003886C: d0062004                 ld      [%i0+4], %o0
F0038870: 9602ffe4                 inc     -0x1C, %o3
F0038874: d6362008                 sth     %o3, [%i0+8]
F0038878: 9002201c                 inc     0x1C, %o0
F003887C: d0262004                 st      %o0, [%i0+4]
F0038880: d004601c                 ld      [%l1+0x1C], %o0
F0038884: 96102000                 mov     0, %o3
F0038888: 7fff9f6d                 call    _sbappendaddr
F003888C: 90022024                 inc     0x24, %o0 ! '$'
F0038890: 80a22000                 cmp     %o0, 0
F0038894: 02800007                 be      loc_F00388B0
F0038898: 90100018                 mov     %i0, %o0
F003889C: d004601c                 ld      [%l1+0x1C], %o0
F00388A0: 7fff9edb                 call    _sowakeup
F00388A4: 92022024                 add     %o0, 0x24, %o1 ! '$'
F00388A8: 30800004                 ba,a    locret_F00388B8
F00388AC: 90100018                 mov     %i0, %o0
F00388B0: 7fff94ed                 call    _m_freem
F00388B4: 01000000                 nop
F00388B8: 81c7e008                 ret
F00388BC: 81e80000                 restore
