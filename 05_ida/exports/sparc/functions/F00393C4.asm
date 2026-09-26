F00393C4: 9de3bf98                 save    %sp, -0x68, %sp
F00393C8: 400175fc                 call    _spltty
F00393CC: 253c04d3                 sethi   %hi(_mfree), %l2
F00393D0: e204a168                 ld      [%l2+%lo(_mfree)], %l1
F00393D4: 80a46000                 cmp     %l1, 0
F00393D8: 02800018                 be      loc_F0039438
F00393DC: a0100008                 mov     %o0, %l0
F00393E0: d054600a                 ldsh    [%l1+0xA], %o0
F00393E4: 80a22000                 cmp     %o0, 0
F00393E8: 02800004                 be      loc_F00393F8
F00393EC: 113c0432                 sethi   %hi(aMget_13), %o0! "mget"
F00393F0: 7fff6f60                 call    _panic
F00393F4: 901221d0                 bset    %lo(aMget_13), %o0! "mget"
F00393F8: 90102002                 mov     2, %o0
F00393FC: d034600a                 sth     %o0, [%l1+0xA]
F0039400: 153c04d29412a2f0         set     _mbstat, %o2
F0039408: d012a01c                 lduh    [%o2+0x1C], %o0
F003940C: d212a020                 lduh    [%o2+0x20], %o1
F0039410: 90023fff                 inc     -1, %o0
F0039414: d032a01c                 sth     %o0, [%o2+0x1C]
F0039418: 92026001                 inc     %o1
F003941C: d232a020                 sth     %o1, [%o2+0x20]
F0039420: 9010200c                 mov     0xC, %o0
F0039424: d2044000                 ld      [%l1], %o1
F0039428: d0246004                 st      %o0, [%l1+4]
F003942C: d224a168                 st      %o1, [%l2+0x168]
F0039430: 10800006                 ba      loc_F0039448
F0039434: c0244000                 clr     [%l1]
F0039438: 90102000                 mov     0, %o0
F003943C: 7fff91cc                 call    _m_more
F0039440: 92102002                 mov     2, %o1
F0039444: a2100008                 mov     %o0, %l1
F0039448: 40017637                 call    _splx
F003944C: 90100010                 mov     %l0, %o0
F0039450: 80a46000                 cmp     %l1, 0
F0039454: 02800062                 be      locret_F00395DC
F0039458: 01000000                 nop
F003945C: 400175d7                 call    _spltty
F0039460: 273c04d3                 sethi   %hi(_mfree), %l3
F0039464: e404e168                 ld      [%l3+%lo(_mfree)], %l2
F0039468: 80a4a000                 cmp     %l2, 0
F003946C: 02800018                 be      loc_F00394CC
F0039470: a0100008                 mov     %o0, %l0
F0039474: d054a00a                 ldsh    [%l2+0xA], %o0
F0039478: 80a22000                 cmp     %o0, 0
F003947C: 02800004                 be      loc_F003948C
F0039480: 113c0432                 sethi   %hi(aMget_14), %o0! "mget"
F0039484: 7fff6f3b                 call    _panic
F0039488: 901221d8                 bset    %lo(aMget_14), %o0! "mget"
F003948C: 9010200e                 mov     0xE, %o0
F0039490: d034a00a                 sth     %o0, [%l2+0xA]
F0039494: 153c04d29412a2f0         set     _mbstat, %o2
F003949C: d012a01c                 lduh    [%o2+0x1C], %o0
F00394A0: d212a038                 lduh    [%o2+0x38], %o1
F00394A4: 90023fff                 inc     -1, %o0
F00394A8: d032a01c                 sth     %o0, [%o2+0x1C]
F00394AC: 92026001                 inc     %o1
F00394B0: d232a038                 sth     %o1, [%o2+0x38]
F00394B4: 9010200c                 mov     0xC, %o0
F00394B8: d2048000                 ld      [%l2], %o1
F00394BC: d024a004                 st      %o0, [%l2+4]
F00394C0: d224e168                 st      %o1, [%l3+0x168]
F00394C4: 10800006                 ba      loc_F00394DC
F00394C8: c0248000                 clr     [%l2]
F00394CC: 90102000                 mov     0, %o0
F00394D0: 7fff91a7                 call    _m_more
F00394D4: 9210200e                 mov     0xE, %o1
F00394D8: a4100008                 mov     %o0, %l2
F00394DC: 40017612                 call    _splx
F00394E0: 90100010                 mov     %l0, %o0
F00394E4: 80a4a000                 cmp     %l2, 0
F00394E8: 12800005                 bne     loc_F00394FC
F00394EC: 90102074                 mov     0x74, %o0 ! 't'
F00394F0: 7fff9171                 call    _m_free
F00394F4: 90100011                 mov     %l1, %o0
F00394F8: 30800039                 ba,a    locret_F00395DC
F00394FC: d0246004                 st      %o0, [%l1+4]
F0039500: 90102008                 mov     8, %o0
F0039504: d0346008                 sth     %o0, [%l1+8]
F0039508: 90100011                 mov     %l1, %o0
F003950C: e0046004                 ld      [%l1+4], %l0
F0039510: 92102012                 mov     0x12, %o1
F0039514: d22c4010                 stb     %o1, [%l1+%l0]
F0039518: a0044010                 add     %l1, %l0, %l0
F003951C: c02c2001                 clrb    [%l0+1]
F0039520: d4060000                 ld      [%i0], %o2
F0039524: 92102008                 mov     8, %o1
F0039528: d4242004                 st      %o2, [%l0+4]
F003952C: 40017e57                 call    _in_cksum
F0039530: c0342002                 clrh    [%l0+2]
F0039534: d0342002                 sth     %o0, [%l0+2]
F0039538: d0046004                 ld      [%l1+4], %o0
F003953C: d2146008                 lduh    [%l1+8], %o1
F0039540: 90023fec                 inc     -0x14, %o0
F0039544: d0246004                 st      %o0, [%l1+4]
F0039548: 92026014                 inc     0x14, %o1
F003954C: d2346008                 sth     %o1, [%l1+8]
F0039550: d0046004                 ld      [%l1+4], %o0
F0039554: 9210201c                 mov     0x1C, %o1
F0039558: 90044008                 add     %l1, %o0, %o0
F003955C: c02a2001                 clrb    [%o0+1]
F0039560: d2322002                 sth     %o1, [%o0+2]
F0039564: c0322006                 clrh    [%o0+6]
F0039568: 92102002                 mov     2, %o1
F003956C: d22a2009                 stb     %o1, [%o0+9]
F0039570: c022200c                 clr     [%o0+0xC]
F0039574: d2042004                 ld      [%l0+4], %o1
F0039578: d2222010                 st      %o1, [%o0+0x10]
F003957C: d604a004                 ld      [%l2+4], %o3
F0039580: d2062004                 ld      [%i0+4], %o1
F0039584: 98100012                 mov     %l2, %o4
F0039588: d224800b                 st      %o1, [%l2+%o3]
F003958C: 9604800b                 add     %l2, %o3, %o3
F0039590: 92102001                 mov     1, %o1
F0039594: d22ae004                 stb     %o1, [%o3+4]
F0039598: 133c0432                 sethi   %hi(_ip_mrouter), %o1
F003959C: d40261e0                 ld      [%o1+%lo(_ip_mrouter)], %o2
F00395A0: 90100011                 mov     %l1, %o0
F00395A4: 92102000                 mov     0, %o1
F00395A8: 80a0000a                 cmp     %g0, %o2
F00395AC: 94402000                 addc    %g0, 0, %o2
F00395B0: d42ae005                 stb     %o2, [%o3+5]
F00395B4: 94102000                 mov     0, %o2
F00395B8: 7fffe7b2                 call    _ip_output
F00395BC: 96102002                 mov     2, %o3
F00395C0: 7fff913d                 call    _m_free
F00395C4: 90100012                 mov     %l2, %o0
F00395C8: 133c04ea921260a0         set     _igmpstat, %o1
F00395D0: d0026020                 ld      [%o1+0x20], %o0
F00395D4: 90022001                 inc     %o0
F00395D8: d0226020                 st      %o0, [%o1+0x20]
F00395DC: 81c7e008                 ret
F00395E0: 81e80000                 restore
