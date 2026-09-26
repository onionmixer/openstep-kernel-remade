F0033480: 9de3bf50                 save    %sp, -0xB0, %sp
F0033484: f027bfbc                 st      %i0, [%fp+var_44]
F0033488: 92100019                 mov     %i1, %o1
F003348C: f627bfb4                 st      %i3, [%fp+var_4C]
F0033490: ac102014                 mov     0x14, %l6
F0033494: a0102000                 mov     0, %l0
F0033498: e807bfbc                 ld      [%fp+var_44], %l4
F003349C: 80a26000                 cmp     %o1, 0
F00334A0: 02800007                 be      loc_F00334BC
F00334A4: b0102000                 mov     0, %i0
F00334A8: d007bfbc                 ld      [%fp+var_44], %o0
F00334AC: 400001dc                 call    _ip_insertoptions
F00334B0: 9407bfc4                 add     %fp, var_3C, %o2
F00334B4: a8100008                 mov     %o0, %l4
F00334B8: ec07bfc4                 ld      [%fp+var_3C], %l6
F00334BC: da07bfb4                 ld      [%fp+var_4C], %o5
F00334C0: d6052004                 ld      [%l4+4], %o3
F00334C4: 808b6001                 btst    1, %o5
F00334C8: 1280001a                 bne     loc_F0033530
F00334CC: b205000b                 add     %l4, %o3, %i1
F00334D0: d205000b                 ld      [%l4+%o3], %o1
F00334D4: 113c0000                 sethi   -0x10000000, %o0
F00334D8: 902a4008                 andn    %o1, %o0, %o0
F00334DC: 13100000                 sethi   0x40000000, %o1
F00334E0: 90120009                 bset    %o1, %o0
F00334E4: 133c04d9                 sethi   %hi(_ip_id), %o1
F00334E8: d41260a0                 lduh    [%o1+%lo(_ip_id)], %o2
F00334EC: d025000b                 st      %o0, [%l4+%o3]
F00334F0: 9002a001                 add     %o2, 1, %o0
F00334F4: d03260a0                 sth     %o0, [%o1+%lo(_ip_id)]
F00334F8: d4366004                 sth     %o2, [%i1+4]
F00334FC: d0166006                 lduh    [%i1+6], %o0
F0033500: 13000010                 sethi   0x4000, %o1
F0033504: 900a0009                 and     %o0, %o1, %o0
F0033508: d0366006                 sth     %o0, [%i1+6]
F003350C: d005000b                 ld      [%l4+%o3], %o0
F0033510: 1303c000                 sethi   0xF000000, %o1
F0033514: 922a0009                 andn    %o0, %o1, %o1
F0033518: 913da002                 sra     %l6, 2, %o0
F003351C: 900a200f                 and     %o0, 0xF, %o0
F0033520: 912a2018                 sll     %o0, 24, %o0
F0033524: 92124008                 bset    %o0, %o1! size_t
F0033528: 10800005                 ba      loc_F003353C
F003352C: d225000b                 st      %o1, [%l4+%o3]
F0033530: d00d000b                 ldub    [%l4+%o3], %o0
F0033534: 900a200f                 and     %o0, 0xF, %o0
F0033538: ad2a2002                 sll     %o0, 2, %l6
F003353C: 80a6a000                 cmp     %i2, 0
F0033540: 32800007                 bne,a   loc_F003355C
F0033544: d4068000                 ld      [%i2], %o2
F0033548: b407bfe0                 add     %fp, var_20, %i2
F003354C: 9010001a                 mov     %i2, %o0! void *
F0033550: 40018642                 call    _bzero
F0033554: 92102014                 mov     0x14, %o1
F0033558: d4068000                 ld      [%i2], %o2
F003355C: 80a2a000                 cmp     %o2, 0
F0033560: 02800015                 be      loc_F00335B4
F0033564: ae06a004                 add     %i2, 4, %l7
F0033568: d012a024                 lduh    [%o2+0x24], %o0
F003356C: 808a2001                 btst    1, %o0
F0033570: 22800008                 be,a    loc_F0033590
F0033574: d052a026                 ldsh    [%o2+0x26], %o0
F0033578: d206a008                 ld      [%i2+8], %o1
F003357C: d0066010                 ld      [%i1+0x10], %o0
F0033580: 80a24008                 cmp     %o1, %o0
F0033584: 2280000d                 be,a    loc_F00335B8
F0033588: d0068000                 ld      [%i2], %o0
F003358C: d052a026                 ldsh    [%o2+0x26], %o0
F0033590: 80a22001                 cmp     %o0, 1
F0033594: 12800006                 bne     loc_F00335AC
F0033598: 90023fff                 inc     -1, %o0
F003359C: 7fffe622                 call    _rtfree
F00335A0: 9010000a                 mov     %o2, %o0
F00335A4: 10800004                 ba      loc_F00335B4
F00335A8: c0268000                 clr     [%i2]
F00335AC: d032a026                 sth     %o0, [%o2+0x26]
F00335B0: c0268000                 clr     [%i2]
F00335B4: d0068000                 ld      [%i2], %o0
F00335B8: 80a22000                 cmp     %o0, 0
F00335BC: 12800007                 bne     loc_F00335D8
F00335C0: da07bfb4                 ld      [%fp+var_4C], %o5
F00335C4: 90102002                 mov     2, %o0
F00335C8: d035c000                 sth     %o0, [%l7]
F00335CC: d0066010                 ld      [%i1+0x10], %o0
F00335D0: d025e004                 st      %o0, [%l7+4]
F00335D4: da07bfb4                 ld      [%fp+var_4C], %o5
F00335D8: 808b6010                 btst    0x10, %o5
F00335DC: 22800011                 be,a    loc_F0033620
F00335E0: d0068000                 ld      [%i2], %o0
F00335E4: 7fffd8e6                 call    _ifa_ifwithdstaddr
F00335E8: 90100017                 mov     %l7, %o0
F00335EC: a0920000                 orcc    %o0, %g0, %l0
F00335F0: 12800008                 bne     loc_F0033610
F00335F4: 9007bfc0                 add     %fp, var_40, %o0
F00335F8: d2066010                 ld      [%i1+0x10], %o1
F00335FC: 7fffec56                 call    _in_netof
F0033600: d227bfc0                 st      %o1, [%fp+var_40]
F0033604: 7fffef2f                 call    _in_iaonnetof
F0033608: 01000000                 nop
F003360C: a0920000                 orcc    %o0, %g0, %l0
F0033610: 32800022                 bne,a   loc_F0033698
F0033614: e4042020                 ld      [%l0+0x20], %l2
F0033618: 1080016a                 ba      loc_F0033BC0
F003361C: b0102033                 mov     0x33, %i0 ! '3'
F0033620: 80a22000                 cmp     %o0, 0
F0033624: 32800005                 bne,a   loc_F0033638
F0033628: d2068000                 ld      [%i2], %o1
F003362C: 7fffe58b                 call    _rtalloc
F0033630: 9010001a                 mov     %i2, %o0
F0033634: d2068000                 ld      [%i2], %o1
F0033638: 80a26000                 cmp     %o1, 0
F003363C: 22800007                 be,a    loc_F0033658
F0033640: 9007bfc0                 add     %fp, var_40, %o0
F0033644: e402602c                 ld      [%o1+0x2C], %l2
F0033648: 80a4a000                 cmp     %l2, 0
F003364C: 3280000c                 bne,a   loc_F003367C
F0033650: d0026028                 ld      [%o1+0x28], %o0
F0033654: 9007bfc0                 add     %fp, var_40, %o0
F0033658: d2066010                 ld      [%i1+0x10], %o1
F003365C: b0102033                 mov     0x33, %i0 ! '3'
F0033660: 7fffec9f                 call    _in_localaddr
F0033664: d227bfc0                 st      %o1, [%fp+var_40]
F0033668: 80a22000                 cmp     %o0, 0
F003366C: 32800155                 bne,a   loc_F0033BC0
F0033670: b0102041                 mov     0x41, %i0 ! 'A'
F0033674: 10800154                 ba      loc_F0033BC4
F0033678: d007bfbc                 ld      [%fp+var_44], %o0
F003367C: 90022001                 inc     %o0
F0033680: d0226028                 st      %o0, [%o1+0x28]
F0033684: d2068000                 ld      [%i2], %o1
F0033688: d0126024                 lduh    [%o1+0x24], %o0
F003368C: 808a2002                 btst    2, %o0
F0033690: 32800002                 bne,a   loc_F0033698
F0033694: ae026014                 add     %o1, 0x14, %l7
F0033698: d0066010                 ld      [%i1+0x10], %o0
F003369C: 133c0000                 sethi   -0x10000000, %o1
F00336A0: 900a0009                 and     %o0, %o1, %o0
F00336A4: 13380000                 sethi   -0x20000000, %o1
F00336A8: 80a20009                 cmp     %o0, %o1
F00336AC: 32800062                 bne,a   loc_F0033834
F00336B0: d006600c                 ld      [%i1+0xC], %o0
F00336B4: da07bfb4                 ld      [%fp+var_4C], %o5
F00336B8: 808b6002                 btst    2, %o5
F00336BC: 02800011                 be      loc_F0033700
F00336C0: ae06a004                 add     %i2, 4, %l7
F00336C4: 80a72000                 cmp     %i4, 0
F00336C8: 0280000f                 be      loc_F0033704
F00336CC: 96102000                 mov     0, %o3
F00336D0: d2072004                 ld      [%i4+4], %o1
F00336D4: 96070009                 add     %i4, %o1, %o3
F00336D8: d00ae004                 ldub    [%o3+4], %o0
F00336DC: d02e6008                 stb     %o0, [%i1+8]
F00336E0: f8070009                 ld      [%i4+%o1], %i4
F00336E4: 80a72000                 cmp     %i4, 0
F00336E8: 32800009                 bne,a   loc_F003370C
F00336EC: a410001c                 mov     %i4, %l2
F00336F0: 10800008                 ba      loc_F0033710
F00336F4: d006600c                 ld      [%i1+0xC], %o0
F00336F8: 10800016                 ba      loc_F0033750
F00336FC: d026600c                 st      %o0, [%i1+0xC]
F0033700: 96102000                 mov     0, %o3
F0033704: 90102001                 mov     1, %o0
F0033708: d02e6008                 stb     %o0, [%i1+8]
F003370C: d006600c                 ld      [%i1+0xC], %o0
F0033710: 80a22000                 cmp     %o0, 0
F0033714: 12800010                 bne     loc_F0033754
F0033718: 80a42000                 cmp     %l0, 0
F003371C: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F0033720: e0022070                 ld      [%o0+%lo(_in_ifaddr)], %l0
F0033724: 80a42000                 cmp     %l0, 0
F0033728: 0280000b                 be      loc_F0033754
F003372C: 01000000                 nop
F0033730: d0042020                 ld      [%l0+0x20], %o0
F0033734: 80a20012                 cmp     %o0, %l2
F0033738: 22bffff0                 be,a    loc_F00336F8
F003373C: d0042004                 ld      [%l0+4], %o0
F0033740: e0042040                 ld      [%l0+0x40], %l0
F0033744: 80a42000                 cmp     %l0, 0
F0033748: 32bffffb                 bne,a   loc_F0033734
F003374C: d0042020                 ld      [%l0+0x20], %o0
F0033750: 80a42000                 cmp     %l0, 0
F0033754: 32800004                 bne,a   loc_F0033764
F0033758: d2042044                 ld      [%l0+0x44], %o1
F003375C: 1080000e                 ba      loc_F0033794
F0033760: 92102000                 mov     0, %o1
F0033764: 80a26000                 cmp     %o1, 0
F0033768: 02800019                 be      loc_F00337CC
F003376C: 80a2e000                 cmp     %o3, 0
F0033770: d4066010                 ld      [%i1+0x10], %o2
F0033774: d0024000                 ld      [%o1], %o0
F0033778: 80a2000a                 cmp     %o0, %o2
F003377C: 02800007                 be      loc_F0033798
F0033780: 80a26000                 cmp     %o1, 0
F0033784: d2026014                 ld      [%o1+0x14], %o1
F0033788: 80a26000                 cmp     %o1, 0
F003378C: 32bffffb                 bne,a   loc_F0033778
F0033790: d0024000                 ld      [%o1], %o0
F0033794: 80a26000                 cmp     %o1, 0
F0033798: 0280000d                 be      loc_F00337CC
F003379C: 80a2e000                 cmp     %o3, 0
F00337A0: 02800006                 be      loc_F00337B8
F00337A4: 90100012                 mov     %l2, %o0
F00337A8: d00ae005                 ldub    [%o3+5], %o0
F00337AC: 80a22000                 cmp     %o0, 0
F00337B0: 02800007                 be      loc_F00337CC
F00337B4: 90100012                 mov     %l2, %o0
F00337B8: 92100014                 mov     %l4, %o1
F00337BC: 40000409                 call    _ip_mloopback
F00337C0: 94100017                 mov     %l7, %o2
F00337C4: 10800011                 ba      loc_F0033808
F00337C8: d00e6008                 ldub    [%i1+8], %o0
F00337CC: 113c0432                 sethi   %hi(_ip_mrouter), %o0
F00337D0: d00221e0                 ld      [%o0+%lo(_ip_mrouter)], %o0
F00337D4: 80a22000                 cmp     %o0, 0
F00337D8: 0280000b                 be      loc_F0033804
F00337DC: da07bfb4                 ld      [%fp+var_4C], %o5
F00337E0: 808b6001                 btst    1, %o5
F00337E4: 32800009                 bne,a   loc_F0033808
F00337E8: d00e6008                 ldub    [%i1+8], %o0
F00337EC: 90100019                 mov     %i1, %o0
F00337F0: 40001783                 call    _ip_mforward
F00337F4: 92100012                 mov     %l2, %o1
F00337F8: 80a22000                 cmp     %o0, 0
F00337FC: 128000f2                 bne     loc_F0033BC4
F0033800: 90100014                 mov     %l4, %o0
F0033804: d00e6008                 ldub    [%i1+8], %o0
F0033808: 80a22000                 cmp     %o0, 0
F003380C: 02800006                 be      loc_F0033824
F0033810: 113c04d5                 sethi   %hi(_loifp), %o0
F0033814: d0022268                 ld      [%o0+%lo(_loifp)], %o0
F0033818: 80a48008                 cmp     %l2, %o0
F003381C: 3280002d                 bne,a   loc_F00338D0
F0033820: d0566002                 ldsh    [%i1+2], %o0
F0033824: 108000e8                 ba      loc_F0033BC4
F0033828: 90100014                 mov     %l4, %o0
F003382C: 10800012                 ba      loc_F0033874
F0033830: d026600c                 st      %o0, [%i1+0xC]
F0033834: 80a22000                 cmp     %o0, 0
F0033838: 32800010                 bne,a   loc_F0033878
F003383C: d205e004                 ld      [%l7+4], %o1
F0033840: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F0033844: e0022070                 ld      [%o0+%lo(_in_ifaddr)], %l0
F0033848: 80a42000                 cmp     %l0, 0
F003384C: 2280000b                 be,a    loc_F0033878
F0033850: d205e004                 ld      [%l7+4], %o1
F0033854: d0042020                 ld      [%l0+0x20], %o0
F0033858: 80a20012                 cmp     %o0, %l2
F003385C: 22bffff4                 be,a    loc_F003382C
F0033860: d0042004                 ld      [%l0+4], %o0
F0033864: e0042040                 ld      [%l0+0x40], %l0
F0033868: 80a42000                 cmp     %l0, 0
F003386C: 32bffffb                 bne,a   loc_F0033858
F0033870: d0042020                 ld      [%l0+0x20], %o0
F0033874: d205e004                 ld      [%l7+4], %o1
F0033878: 9007bfc0                 add     %fp, var_40, %o0
F003387C: 7fffeea3                 call    _in_broadcast
F0033880: d227bfc0                 st      %o1, [%fp+var_40]
F0033884: 80a22000                 cmp     %o0, 0
F0033888: 22800012                 be,a    loc_F00338D0
F003388C: d0566002                 ldsh    [%i1+2], %o0
F0033890: d014a00c                 lduh    [%l2+0xC], %o0
F0033894: 808a2002                 btst    2, %o0
F0033898: 12800004                 bne     loc_F00338A8
F003389C: da07bfb4                 ld      [%fp+var_4C], %o5
F00338A0: 108000c8                 ba      loc_F0033BC0
F00338A4: b0102031                 mov     0x31, %i0 ! '1'
F00338A8: 808b6020                 btst    0x20, %o5 ! ' '
F00338AC: 32800004                 bne,a   loc_F00338BC
F00338B0: d2566002                 ldsh    [%i1+2], %o1
F00338B4: 108000c3                 ba      loc_F0033BC0
F00338B8: b010200d                 mov     0xD, %i0
F00338BC: d054a00a                 ldsh    [%l2+0xA], %o0
F00338C0: 80a24008                 cmp     %o1, %o0
F00338C4: 148000bf                 bg      loc_F0033BC0
F00338C8: b0102028                 mov     0x28, %i0 ! '('
F00338CC: d0566002                 ldsh    [%i1+2], %o0
F00338D0: d454a00a                 ldsh    [%l2+0xA], %o2
F00338D4: 80a2000a                 cmp     %o0, %o2
F00338D8: 34800010                 bg,a    loc_F0033918
F00338DC: d2166006                 lduh    [%i1+6], %o1
F00338E0: d0366002                 sth     %o0, [%i1+2]
F00338E4: c036600a                 clrh    [%i1+0xA]
F00338E8: 90100014                 mov     %l4, %o0
F00338EC: d4166006                 lduh    [%i1+6], %o2
F00338F0: 92100016                 mov     %l6, %o1
F00338F4: 40019565                 call    _in_cksum
F00338F8: d4366006                 sth     %o2, [%i1+6]
F00338FC: d036600a                 sth     %o0, [%i1+0xA]
F0033900: 90100012                 mov     %l2, %o0
F0033904: 92100014                 mov     %l4, %o1
F0033908: 7fffe270                 call    _if_output_mbuf
F003390C: 94100017                 mov     %l7, %o2
F0033910: 108000af                 ba      loc_F0033BCC
F0033914: b0100008                 mov     %o0, %i0
F0033918: 11000010                 sethi   0x4000, %o0
F003391C: 808a4008                 btst    %o0, %o1
F0033920: 128000a8                 bne     loc_F0033BC0
F0033924: b0102028                 mov     0x28, %i0 ! '('
F0033928: 90228016                 sub     %o2, %l6, %o0
F003392C: 900a3ff8                 and     %o0, -8, %o0
F0033930: 80a22007                 cmp     %o0, 7
F0033934: 14800004                 bg      loc_F0033944
F0033938: d027bfc4                 st      %o0, [%fp+var_3C]
F003393C: 108000a2                 ba      loc_F0033BC4
F0033940: d007bfbc                 ld      [%fp+var_44], %o0
F0033944: d204a040                 ld      [%l2+0x40], %o1
F0033948: 9fc24000                 call    %o1
F003394C: 90100012                 mov     %l2, %o0
F0033950: a2920000                 orcc    %o0, %g0, %l1
F0033954: 0280009b                 be      loc_F0033BC0
F0033958: b0102037                 mov     0x37, %i0 ! '7'
F003395C: 7fffe04e                 call    _nb_map
F0033960: 90100011                 mov     %l1, %o0
F0033964: a0100008                 mov     %o0, %l0
F0033968: 90100014                 mov     %l4, %o0
F003396C: 92100010                 mov     %l0, %o1
F0033970: d607bfc4                 ld      [%fp+var_3C], %o3
F0033974: 94102000                 mov     0, %o2
F0033978: 7fffe230                 call    _mbuf_read
F003397C: 9605800b                 add     %l6, %o3, %o3
F0033980: d0064000                 ld      [%i1], %o0
F0033984: d027bfc8                 st      %o0, [%fp+var_38]
F0033988: d0066004                 ld      [%i1+4], %o0
F003398C: 2b000008                 sethi   0x2000, %l5
F0033990: d607bfc4                 ld      [%fp+var_3C], %o3
F0033994: d027bfcc                 st      %o0, [%fp+var_34]
F0033998: d2066008                 ld      [%i1+8], %o1
F003399C: 9605800b                 add     %l6, %o3, %o3
F00339A0: d227bfd0                 st      %o1, [%fp+var_30]
F00339A4: d406600c                 ld      [%i1+0xC], %o2
F00339A8: 9007bfc8                 add     %fp, var_38, %o0! void *
F00339AC: d427bfd4                 st      %o2, [%fp+var_2C]
F00339B0: d8066010                 ld      [%i1+0x10], %o4
F00339B4: 92100010                 mov     %l0, %o1! void *
F00339B8: d827bfd8                 st      %o4, [%fp+var_28]
F00339BC: d637bfca                 sth     %o3, [%fp+var_38+2]
F00339C0: d6166006                 lduh    [%i1+6], %o3
F00339C4: 94102014                 mov     0x14, %o2! size_t
F00339C8: 9612c015                 bset    %l5, %o3
F00339CC: d637bfce                 sth     %o3, [%fp+var_34+2]
F00339D0: 40018450                 call    _bcopy
F00339D4: c037bfd2                 clrh    [%fp+var_30+2]
F00339D8: 90100011                 mov     %l1, %o0
F00339DC: 4001952b                 call    _in_cksum
F00339E0: 92100016                 mov     %l6, %o1
F00339E4: d037bfd2                 sth     %o0, [%fp+var_30+2]
F00339E8: d20fbfd2                 ldub    [%fp+var_30+2], %o1
F00339EC: 90100012                 mov     %l2, %o0
F00339F0: d22c200a                 stb     %o1, [%l0+0xA]
F00339F4: d40fbfd3                 ldub    [%fp+var_30+3], %o2
F00339F8: 92100011                 mov     %l1, %o1
F00339FC: d42c200b                 stb     %o2, [%l0+0xB]
F0033A00: d604a034                 ld      [%l2+0x34], %o3
F0033A04: 9fc2c000                 call    %o3
F0033A08: 94100017                 mov     %l7, %o2
F0033A0C: b0920000                 orcc    %o0, %g0, %i0
F0033A10: 1280006c                 bne     loc_F0033BC0
F0033A14: ba10200a                 mov     0xA, %i5
F0033A18: d207bfc4                 ld      [%fp+var_3C], %o1
F0033A1C: d0566002                 ldsh    [%i1+2], %o0
F0033A20: b8058009                 add     %l6, %o1, %i4
F0033A24: 80a70008                 cmp     %i4, %o0
F0033A28: 16800066                 bge     loc_F0033BC0
F0033A2C: a6102014                 mov     0x14, %l3
F0033A30: b6100015                 mov     %l5, %i3
F0033A34: d204a040                 ld      [%l2+0x40], %o1
F0033A38: 9fc24000                 call    %o1
F0033A3C: 90100012                 mov     %l2, %o0
F0033A40: a2920000                 orcc    %o0, %g0, %l1
F0033A44: 2280005f                 be,a    loc_F0033BC0
F0033A48: b0102037                 mov     0x37, %i0 ! '7'
F0033A4C: 7fffe012                 call    _nb_map
F0033A50: 01000000                 nop
F0033A54: d2064000                 ld      [%i1], %o1
F0033A58: d227bfc8                 st      %o1, [%fp+var_38]
F0033A5C: d2066004                 ld      [%i1+4], %o1
F0033A60: d227bfcc                 st      %o1, [%fp+var_34]
F0033A64: d2066008                 ld      [%i1+8], %o1
F0033A68: a0100008                 mov     %o0, %l0
F0033A6C: d227bfd0                 st      %o1, [%fp+var_30]
F0033A70: d206600c                 ld      [%i1+0xC], %o1
F0033A74: 80a5a014                 cmp     %l6, 0x14
F0033A78: d227bfd4                 st      %o1, [%fp+var_2C]
F0033A7C: d0066010                 ld      [%i1+0x10], %o0
F0033A80: aa100010                 mov     %l0, %l5
F0033A84: 0880000f                 bleu    loc_F0033AC0
F0033A88: d027bfd8                 st      %o0, [%fp+var_28]
F0033A8C: 90100019                 mov     %i1, %o0
F0033A90: 400000c3                 call    _ip_optcopy
F0033A94: 92100010                 mov     %l0, %o1
F0033A98: d207bfc8                 ld      [%fp+var_38], %o1
F0033A9C: a6022014                 add     %o0, 0x14, %l3
F0033AA0: 1b3c3fff9a1363ff         set     -0xF000001, %o5
F0033AA8: 913ce002                 sra     %l3, 2, %o0
F0033AAC: 900a200f                 and     %o0, 0xF, %o0
F0033AB0: 912a2018                 sll     %o0, 24, %o0
F0033AB4: 920a400d                 and     %o1, %o5, %o1
F0033AB8: 92124008                 bset    %o0, %o1
F0033ABC: d227bfc8                 st      %o1, [%fp+var_38]
F0033AC0: 90270016                 sub     %i4, %l6, %o0
F0033AC4: 913a2003                 sra     %o0, 3, %o0
F0033AC8: 1b3ffff7                 sethi   -0x2400, %o5
F0033ACC: d2166006                 lduh    [%i1+6], %o1
F0033AD0: 9a1363ff                 bset    0x3FF, %o5
F0033AD4: 920a400d                 and     %o1, %o5, %o1
F0033AD8: 92020009                 add     %o0, %o1, %o1
F0033ADC: d237bfce                 sth     %o1, [%fp+var_34+2]
F0033AE0: d0166006                 lduh    [%i1+6], %o0
F0033AE4: 808a001b                 btst    %i3, %o0
F0033AE8: 02800003                 be      loc_F0033AF4
F0033AEC: 9012401b                 or      %o1, %i3, %o0
F0033AF0: d037bfce                 sth     %o0, [%fp+var_34+2]
F0033AF4: d007bfc4                 ld      [%fp+var_3C], %o0
F0033AF8: d4566002                 ldsh    [%i1+2], %o2
F0033AFC: 92070008                 add     %i4, %o0, %o1
F0033B00: 80a2400a                 cmp     %o1, %o2
F0033B04: 06800008                 bl      loc_F0033B24
F0033B08: 90100011                 mov     %l1, %o0
F0033B0C: 7fffe029                 call    _nb_shrink_bot
F0033B10: 9222400a                 sub     %o1, %o2, %o1
F0033B14: d0566002                 ldsh    [%i1+2], %o0
F0033B18: 9022001c                 sub     %o0, %i4, %o0
F0033B1C: 10800005                 ba      loc_F0033B30
F0033B20: d027bfc4                 st      %o0, [%fp+var_3C]
F0033B24: d017bfce                 lduh    [%fp+var_34+2], %o0
F0033B28: 9012001b                 bset    %i3, %o0
F0033B2C: d037bfce                 sth     %o0, [%fp+var_34+2]
F0033B30: 90100014                 mov     %l4, %o0
F0033B34: 92040013                 add     %l0, %l3, %o1
F0033B38: d607bfc4                 ld      [%fp+var_3C], %o3
F0033B3C: 9410001c                 mov     %i4, %o2
F0033B40: 9802c013                 add     %o3, %l3, %o4
F0033B44: 7fffe1bd                 call    _mbuf_read
F0033B48: d837bfca                 sth     %o4, [%fp+var_38+2]
F0033B4C: c037bfd2                 clrh    [%fp+var_30+2]
F0033B50: 9007bfc8                 add     %fp, var_38, %o0! void *
F0033B54: 92100015                 mov     %l5, %o1! void *
F0033B58: d617bfce                 lduh    [%fp+var_34+2], %o3
F0033B5C: 94102014                 mov     0x14, %o2! size_t
F0033B60: 400183ec                 call    _bcopy
F0033B64: d637bfce                 sth     %o3, [%fp+var_34+2]
F0033B68: 90100011                 mov     %l1, %o0
F0033B6C: 400194c7                 call    _in_cksum
F0033B70: 92100013                 mov     %l3, %o1
F0033B74: d037bfd2                 sth     %o0, [%fp+var_30+2]
F0033B78: 90100012                 mov     %l2, %o0
F0033B7C: d40fbfd2                 ldub    [%fp+var_30+2], %o2
F0033B80: 92100011                 mov     %l1, %o1
F0033B84: d42c001d                 stb     %o2, [%l0+%i5]
F0033B88: d60fbfd3                 ldub    [%fp+var_30+3], %o3
F0033B8C: 9404001d                 add     %l0, %i5, %o2
F0033B90: d62aa001                 stb     %o3, [%o2+1]
F0033B94: d604a034                 ld      [%l2+0x34], %o3
F0033B98: 9fc2c000                 call    %o3
F0033B9C: 94100017                 mov     %l7, %o2
F0033BA0: b0920000                 orcc    %o0, %g0, %i0
F0033BA4: 12800007                 bne     loc_F0033BC0
F0033BA8: d007bfc4                 ld      [%fp+var_3C], %o0
F0033BAC: d2566002                 ldsh    [%i1+2], %o1
F0033BB0: b8070008                 add     %i4, %o0, %i4
F0033BB4: 80a70009                 cmp     %i4, %o1
F0033BB8: 26bfffa0                 bl,a    loc_F0033A38
F0033BBC: d204a040                 ld      [%l2+0x40], %o1
F0033BC0: d007bfbc                 ld      [%fp+var_44], %o0
F0033BC4: 7fffa828                 call    _m_freem
F0033BC8: 01000000                 nop
F0033BCC: 9007bfe0                 add     %fp, var_20, %o0
F0033BD0: 80a68008                 cmp     %i2, %o0
F0033BD4: 12800010                 bne     locret_F0033C14
F0033BD8: da07bfb4                 ld      [%fp+var_4C], %o5
F0033BDC: 808b6010                 btst    0x10, %o5
F0033BE0: 1280000d                 bne     locret_F0033C14
F0033BE4: d207bfe0                 ld      [%fp+var_20], %o1
F0033BE8: 80a26000                 cmp     %o1, 0
F0033BEC: 0280000a                 be      locret_F0033C14
F0033BF0: 01000000                 nop
F0033BF4: d0526026                 ldsh    [%o1+0x26], %o0
F0033BF8: 80a22001                 cmp     %o0, 1
F0033BFC: 12800005                 bne     loc_F0033C10
F0033C00: 90023fff                 inc     -1, %o0
F0033C04: 7fffe488                 call    _rtfree
F0033C08: 90100009                 mov     %o1, %o0
F0033C0C: 30800002                 ba,a    locret_F0033C14
F0033C10: d0326026                 sth     %o0, [%o1+0x26]
F0033C14: 81c7e008                 ret
F0033C18: 81e80000                 restore
