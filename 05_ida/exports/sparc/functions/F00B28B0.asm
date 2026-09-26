F00B28B0: 9de3bf98                 save    %sp, -0x68, %sp
F00B28B4: 293c0477                 sethi   %hi(dword_F011DD24), %l4
F00B28B8: d0052124                 ld      [%l4+%lo(dword_F011DD24)], %o0
F00B28BC: 80a22000                 cmp     %o0, 0
F00B28C0: 12800008                 bne     loc_F00B28E0
F00B28C4: 90102000                 mov     0, %o0
F00B28C8: 7ffff122                 call    _prom_alloc
F00B28CC: 13000004                 sethi   0x1000, %o1
F00B28D0: d0252124                 st      %o0, [%l4+%lo(dword_F011DD24)]
F00B28D4: 133c04c5                 sethi   %hi(dword_F0131798), %o1
F00B28D8: 11000004                 sethi   0x1000, %o0
F00B28DC: d0226398                 st      %o0, [%o1+%lo(dword_F0131798)]
F00B28E0: 7ffff2e6                 call    _prom_nextnode
F00B28E4: 90102000                 mov     0, %o0
F00B28E8: d4052124                 ld      [%l4+0x124], %o2
F00B28EC: 400000b0                 call    _searchpromtree
F00B28F0: 92100018                 mov     %i0, %o1
F00B28F4: a6920000                 orcc    %o0, %g0, %l3
F00B28F8: 02800014                 be      loc_F00B2948
F00B28FC: 113c0477                 sethi   %hi(dword_F011DD20), %o0
F00B2900: d0022120                 ld      [%o0+%lo(dword_F011DD20)], %o0
F00B2904: 80a22000                 cmp     %o0, 0
F00B2908: 02800007                 be      loc_F00B2924
F00B290C: 113c0477                 sethi   %hi(aFoundSSAtNodeX), %o0! "Found %s:%s at node %x\n"
F00B2910: 90122128                 bset    %lo(aFoundSSAtNodeX), %o0! "Found %s:%s at node %x\n"
F00B2914: 92100018                 mov     %i0, %o1
F00B2918: 94100019                 mov     %i1, %o2
F00B291C: 7ffd874f                 call    _printf
F00B2920: 96100013                 mov     %l3, %o3
F00B2924: 90100013                 mov     %l3, %o0
F00B2928: 7ffff9f6                 call    _getproplen
F00B292C: 92100019                 mov     %i1, %o1
F00B2930: a4100008                 mov     %o0, %l2
F00B2934: 7ffd4f33                 call    _udiv
F00B2938: 9210200c                 mov     0xC, %o1
F00B293C: a2920000                 orcc    %o0, %g0, %l1
F00B2940: 12800004                 bne     loc_F00B2950
F00B2944: 113c04c5                 sethi   -0xFECEC00, %o0
F00B2948: 10800097                 ba      locret_F00B2BA4
F00B294C: b0102000                 mov     0, %i0
F00B2950: 932c6001                 sll     %l1, 1, %o1
F00B2954: 92024011                 add     %o1, %l1, %o1
F00B2958: d0022398                 ld      [%o0+0x398], %o0
F00B295C: a12a6003                 sll     %o1, 3, %l0
F00B2960: 80a20010                 cmp     %o0, %l0
F00B2964: 1a800006                 bcc     loc_F00B297C
F00B2968: 92043fff                 add     %l0, -1, %o1
F00B296C: 113c0477                 sethi   %hi(aMemlistsTooBig), %o0! "memlists too big"
F00B2970: 7ffd8a00                 call    _panic
F00B2974: 90122140                 bset    %lo(aMemlistsTooBig), %o0! "memlists too big"
F00B2978: 92043fff                 add     %l0, -1, %o1
F00B297C: f0052124                 ld      [%l4+0x124], %i0
F00B2980: 80a42000                 cmp     %l0, 0
F00B2984: 04800007                 ble     loc_F00B29A0
F00B2988: 94100018                 mov     %i0, %o2
F00B298C: c02a8000                 clrb    [%o2]
F00B2990: 9402a001                 inc     %o2
F00B2994: 90924000                 orcc    %o1, %g0, %o0
F00B2998: 14bffffd                 bg      loc_F00B298C
F00B299C: 92027fff                 inc     -1, %o1
F00B29A0: 173c04c5                 sethi   %hi(dword_F0131798), %o3
F00B29A4: 932c6001                 sll     %l1, 1, %o1
F00B29A8: 92024011                 add     %o1, %l1, %o1
F00B29AC: 932a6003                 sll     %o1, 3, %o1
F00B29B0: d402e398                 ld      [%o3+%lo(dword_F0131798)], %o2
F00B29B4: 213c0477                 sethi   %hi(dword_F011DD24), %l0
F00B29B8: d0042124                 ld      [%l0+%lo(dword_F011DD24)], %o0
F00B29BC: 94228009                 sub     %o2, %o1, %o2
F00B29C0: d422e398                 st      %o2, [%o3+%lo(dword_F0131798)]
F00B29C4: 90020009                 add     %o0, %o1, %o0
F00B29C8: 80a28012                 cmp     %o2, %l2
F00B29CC: 1a800005                 bcc     loc_F00B29E0
F00B29D0: d0242124                 st      %o0, [%l0+%lo(dword_F011DD24)]
F00B29D4: 113c0477                 sethi   %hi(aMemlistsTooBig_0), %o0! "memlists too big"
F00B29D8: 7ffd89e6                 call    _panic
F00B29DC: 90122158                 bset    %lo(aMemlistsTooBig_0), %o0! "memlists too big"
F00B29E0: 9404bfff                 add     %l2, -1, %o2
F00B29E4: e0042124                 ld      [%l0+0x124], %l0
F00B29E8: 80a4a000                 cmp     %l2, 0
F00B29EC: 04800007                 ble     loc_F00B2A08
F00B29F0: 92100010                 mov     %l0, %o1
F00B29F4: c02a4000                 clrb    [%o1]
F00B29F8: 92026001                 inc     %o1
F00B29FC: 90928000                 orcc    %o2, %g0, %o0
F00B2A00: 14bffffd                 bg      loc_F00B29F4
F00B2A04: 9402bfff                 inc     -1, %o2
F00B2A08: 90100013                 mov     %l3, %o0
F00B2A0C: 92100019                 mov     %i1, %o1
F00B2A10: 94100010                 mov     %l0, %o2
F00B2A14: 053c04c5                 sethi   %hi(dword_F0131798), %g2
F00B2A18: b2102000                 mov     0, %i1
F00B2A1C: d800a398                 ld      [%g2+%lo(dword_F0131798)], %o4
F00B2A20: 1b3c0477                 sethi   %hi(dword_F011DD24), %o5
F00B2A24: d6036124                 ld      [%o5+%lo(dword_F011DD24)], %o3
F00B2A28: 98230012                 sub     %o4, %l2, %o4
F00B2A2C: d820a398                 st      %o4, [%g2+%lo(dword_F0131798)]
F00B2A30: 9602c012                 add     %o3, %l2, %o3
F00B2A34: 7ffff174                 call    _prom_getprop
F00B2A38: d6236124                 st      %o3, [%o5+%lo(dword_F011DD24)]
F00B2A3C: 80a64011                 cmp     %i1, %l1
F00B2A40: 36800049                 bge,a   loc_F00B2B64
F00B2A44: b2102001                 mov     1, %i1
F00B2A48: 113c0477                 sethi   %hi(dword_F011DD20), %o0
F00B2A4C: d0022120                 ld      [%o0+%lo(dword_F011DD20)], %o0
F00B2A50: 80a22000                 cmp     %o0, 0
F00B2A54: 02800008                 be      loc_F00B2A74
F00B2A58: 113c0477                 sethi   %hi(aChunkDAddrXBus), %o0! "Chunk %d: addr %x bustype %x size %x\n"
F00B2A5C: d4042004                 ld      [%l0+4], %o2
F00B2A60: d6040000                 ld      [%l0], %o3
F00B2A64: 90122170                 bset    %lo(aChunkDAddrXBus), %o0! "Chunk %d: addr %x bustype %x size %x\n"
F00B2A68: d8042008                 ld      [%l0+8], %o4
F00B2A6C: 7ffd86fb                 call    _printf
F00B2A70: 92100019                 mov     %i1, %o1
F00B2A74: d0040000                 ld      [%l0], %o0
F00B2A78: 80a22000                 cmp     %o0, 0
F00B2A7C: 32800036                 bne,a   loc_F00B2B54
F00B2A80: b2066001                 inc     %i1
F00B2A84: 9a102000                 mov     0, %o5
F00B2A88: 80a34019                 cmp     %o5, %i1
F00B2A8C: 16800015                 bge     loc_F00B2AE0
F00B2A90: 80a6400d                 cmp     %i1, %o5
F00B2A94: d8042004                 ld      [%l0+4], %o4
F00B2A98: 92100018                 mov     %i0, %o1
F00B2A9C: d0024000                 ld      [%o1], %o0
F00B2AA0: 94102000                 mov     0, %o2
F00B2AA4: 80a2000a                 cmp     %o0, %o2
F00B2AA8: 1880000d                 bgu     loc_F00B2ADC
F00B2AAC: 9610000c                 mov     %o4, %o3
F00B2AB0: 80a2000a                 cmp     %o0, %o2
F00B2AB4: 32800007                 bne,a   loc_F00B2AD0
F00B2AB8: 9a036001                 inc     %o5
F00B2ABC: d0026004                 ld      [%o1+4], %o0
F00B2AC0: 80a2000b                 cmp     %o0, %o3
F00B2AC4: 18800007                 bgu     loc_F00B2AE0
F00B2AC8: 80a6400d                 cmp     %i1, %o5
F00B2ACC: 9a036001                 inc     %o5
F00B2AD0: 80a34019                 cmp     %o5, %i1
F00B2AD4: 06bffff2                 bl      loc_F00B2A9C
F00B2AD8: 92026018                 inc     0x18, %o1
F00B2ADC: 80a6400d                 cmp     %i1, %o5
F00B2AE0: 04800010                 ble     loc_F00B2B20
F00B2AE4: 84100019                 mov     %i1, %g2
F00B2AE8: 912e6001                 sll     %i1, 1, %o0
F00B2AEC: 90020019                 add     %o0, %i1, %o0
F00B2AF0: 912a2003                 sll     %o0, 3, %o0
F00B2AF4: 98020018                 add     %o0, %i0, %o4
F00B2AF8: 8400bfff                 inc     -1, %g2
F00B2AFC: d01b3fe8                 ldd     [%o4-0x18], %o0
F00B2B00: 80a0800d                 cmp     %g2, %o5
F00B2B04: d41b3ff0                 ldd     [%o4-0x10], %o2
F00B2B08: d03b0000                 std     %o0, [%o4]
F00B2B0C: d01b3ff8                 ldd     [%o4-8], %o0
F00B2B10: d43b2008                 std     %o2, [%o4+8]
F00B2B14: d03b2010                 std     %o0, [%o4+0x10]
F00B2B18: 14bffff8                 bg      loc_F00B2AF8
F00B2B1C: 98033fe8                 inc     -0x18, %o4
F00B2B20: d0042004                 ld      [%l0+4], %o0
F00B2B24: 952b6001                 sll     %o5, 1, %o2
F00B2B28: 9402800d                 add     %o2, %o5, %o2
F00B2B2C: 952aa003                 sll     %o2, 3, %o2
F00B2B30: 92100008                 mov     %o0, %o1
F00B2B34: 90102000                 mov     0, %o0
F00B2B38: d03e000a                 std     %o0, [%i0+%o2]
F00B2B3C: d0042008                 ld      [%l0+8], %o0
F00B2B40: 9406000a                 add     %i0, %o2, %o2
F00B2B44: 92100008                 mov     %o0, %o1
F00B2B48: 90102000                 mov     0, %o0
F00B2B4C: d03aa008                 std     %o0, [%o2+8]
F00B2B50: b2066001                 inc     %i1
F00B2B54: 80a64011                 cmp     %i1, %l1
F00B2B58: 06bfffbc                 bl      loc_F00B2A48
F00B2B5C: a004200c                 inc     0xC, %l0
F00B2B60: b2102001                 mov     1, %i1
F00B2B64: 80a64011                 cmp     %i1, %l1
F00B2B68: 1680000f                 bge     locret_F00B2BA4
F00B2B6C: 92062018                 add     %i0, 0x18, %o1
F00B2B70: d0024000                 ld      [%o1], %o0
F00B2B74: 80a22000                 cmp     %o0, 0
F00B2B78: 32800007                 bne,a   loc_F00B2B94
F00B2B7C: d2227ff8                 st      %o1, [%o1-8]
F00B2B80: d0026004                 ld      [%o1+4], %o0
F00B2B84: 80a22000                 cmp     %o0, 0
F00B2B88: 22800004                 be,a    loc_F00B2B98
F00B2B8C: b2066001                 inc     %i1
F00B2B90: d2227ff8                 st      %o1, [%o1-8]
F00B2B94: b2066001                 inc     %i1
F00B2B98: 80a64011                 cmp     %i1, %l1
F00B2B9C: 06bffff5                 bl      loc_F00B2B70
F00B2BA0: 92026018                 inc     0x18, %o1
F00B2BA4: 81c7e008                 ret
F00B2BA8: 81e80000                 restore
