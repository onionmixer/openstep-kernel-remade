F00E625C: 9de3bf90                 save    %sp, -0x70, %sp
F00E6260: d0164000                 lduh    [%i1], %o0
F00E6264: ac100018                 mov     %i0, %l6
F00E6268: d2166002                 lduh    [%i1+2], %o1
F00E626C: 80a5a00f                 cmp     %l6, 0xF
F00E6270: d4166004                 lduh    [%i1+4], %o2
F00E6274: 872a2010                 sll     %o0, 16, %g3
F00E6278: 852a6010                 sll     %o1, 16, %g2
F00E627C: 952aa010                 sll     %o2, 16, %o2
F00E6280: d0166006                 lduh    [%i1+6], %o0
F00E6284: 133c04bb                 sethi   %hi(_sparcfbs), %o1
F00E6288: d6026364                 ld      [%o1+%lo(_sparcfbs)], %o3
F00E628C: 9b2a2010                 sll     %o0, 16, %o5
F00E6290: 912da004                 sll     %l6, 4, %o0
F00E6294: 90020016                 add     %o0, %l6, %o0
F00E6298: 912a2002                 sll     %o0, 2, %o0
F00E629C: 92022008                 add     %o0, 8, %o1
F00E62A0: 18800006                 bgu     loc_F00E62B8
F00E62A4: 9802c009                 add     %o3, %o1, %o4
F00E62A8: d002c009                 ld      [%o3+%o1], %o0
F00E62AC: 80a22000                 cmp     %o0, 0
F00E62B0: 12800004                 bne     loc_F00E62C0
F00E62B4: a332a010                 srl     %o2, 16, %l1
F00E62B8: 10800145                 ba      locret_F00E67CC
F00E62BC: b0103d40                 mov     -0x2C0, %i0
F00E62C0: d002c009                 ld      [%o3+%o1], %o0
F00E62C4: a7336010                 srl     %o5, 16, %l3
F00E62C8: b130e010                 srl     %g3, 16, %i0
F00E62CC: a530a010                 srl     %g2, 16, %l2
F00E62D0: 80a22000                 cmp     %o0, 0
F00E62D4: 12800004                 bne     loc_F00E62E4
F00E62D8: a810000c                 mov     %o4, %l4
F00E62DC: 10800096                 ba      loc_F00E6534
F00E62E0: b0103d40                 mov     -0x2C0, %i0
F00E62E4: d2052034                 ld      [%l4+0x34], %o1
F00E62E8: 7ffc8086                 call    _umul
F00E62EC: 90100011                 mov     %l1, %o0
F00E62F0: 7ffc8084                 call    _umul
F00E62F4: 92100013                 mov     %l3, %o1
F00E62F8: 133c04bb                 sethi   %hi(dword_F012EF6C), %o1
F00E62FC: 96102000                 mov     0, %o3
F00E6300: d202636c                 ld      [%o1+%lo(dword_F012EF6C)], %o1
F00E6304: a0022004                 add     %o0, 4, %l0
F00E6308: 80a26000                 cmp     %o1, 0
F00E630C: 0280000c                 be      loc_F00E633C
F00E6310: d227bff4                 st      %o1, [%fp+var_C]
F00E6314: d207bff4                 ld      [%fp+var_C], %o1
F00E6318: d0026018                 ld      [%o1+0x18], %o0
F00E631C: 80a20010                 cmp     %o0, %l0
F00E6320: 16800008                 bge     loc_F00E6340
F00E6324: d407bff4                 ld      [%fp+var_C], %o2
F00E6328: 96100009                 mov     %o1, %o3
F00E632C: d0026008                 ld      [%o1+8], %o0
F00E6330: 80a22000                 cmp     %o0, 0
F00E6334: 12bffff8                 bne     loc_F00E6314
F00E6338: d027bff4                 st      %o0, [%fp+var_C]
F00E633C: d407bff4                 ld      [%fp+var_C], %o2
F00E6340: 80a2a000                 cmp     %o2, 0
F00E6344: 0280000e                 be      loc_F00E637C
F00E6348: 133c04bb                 sethi   %hi(dword_F012EF74), %o1
F00E634C: d0026374                 ld      [%o1+%lo(dword_F012EF74)], %o0
F00E6350: 80a2e000                 cmp     %o3, 0
F00E6354: 90023fff                 inc     -1, %o0
F00E6358: 02800005                 be      loc_F00E636C
F00E635C: d0226374                 st      %o0, [%o1+%lo(dword_F012EF74)]
F00E6360: d002a008                 ld      [%o2+8], %o0
F00E6364: 10800018                 ba      loc_F00E63C4
F00E6368: d022e008                 st      %o0, [%o3+8]
F00E636C: d202a008                 ld      [%o2+8], %o1
F00E6370: 113c04bb                 sethi   %hi(dword_F012EF6C), %o0
F00E6374: 10800014                 ba      loc_F00E63C4
F00E6378: d222236c                 st      %o1, [%o0+%lo(dword_F012EF6C)]
F00E637C: 133c04bb                 sethi   %hi(dword_F012EF78), %o1
F00E6380: d0026378                 ld      [%o1+%lo(dword_F012EF78)], %o0
F00E6384: 80a40008                 cmp     %l0, %o0
F00E6388: 0480000b                 ble     loc_F00E63B4
F00E638C: 113c04d1                 sethi   %hi(_kernel_map), %o0
F00E6390: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F00E6394: 9207bff4                 add     %fp, var_C, %o1
F00E6398: 7ffe751b                 call    _kmem_alloc_wired
F00E639C: 9404201c                 add     %l0, 0x1C, %o2
F00E63A0: 80a22000                 cmp     %o0, 0
F00E63A4: 02800009                 be      loc_F00E63C8
F00E63A8: 193c04bb                 sethi   -0xFED1400, %o4
F00E63AC: 10800062                 ba      loc_F00E6534
F00E63B0: b0103fff                 mov     -1, %i0
F00E63B4: 113c04cc901220e4         set     unk_F01330E4, %o0
F00E63BC: d027bff4                 st      %o0, [%fp+var_C]
F00E63C0: c0226378                 clr     [%o1+0x378]
F00E63C4: 193c04bb                 sethi   -0xFED1400, %o4
F00E63C8: d4032370                 ld      [%o4+0x370], %o2
F00E63CC: d207bff4                 ld      [%fp+var_C], %o1
F00E63D0: 173c04bb                 sethi   %hi(dword_F012EF68), %o3
F00E63D4: d002e368                 ld      [%o3+%lo(dword_F012EF68)], %o0
F00E63D8: 9402a001                 inc     %o2
F00E63DC: d4224000                 st      %o2, [%o1]
F00E63E0: e0226018                 st      %l0, [%o1+0x18]
F00E63E4: ec226004                 st      %l6, [%o1+4]
F00E63E8: d0226008                 st      %o0, [%o1+8]
F00E63EC: d0052034                 ld      [%l4+0x34], %o0
F00E63F0: d022600c                 st      %o0, [%o1+0xC]
F00E63F4: d0164000                 lduh    [%i1], %o0
F00E63F8: d0326010                 sth     %o0, [%o1+0x10]
F00E63FC: d0166002                 lduh    [%i1+2], %o0
F00E6400: d0326012                 sth     %o0, [%o1+0x12]
F00E6404: d0166004                 lduh    [%i1+4], %o0
F00E6408: d0326014                 sth     %o0, [%o1+0x14]
F00E640C: d0166006                 lduh    [%i1+6], %o0
F00E6410: d0326016                 sth     %o0, [%o1+0x16]
F00E6414: d0052038                 ld      [%l4+0x38], %o0! int
F00E6418: d222e368                 st      %o1, [%o3+0x368]
F00E641C: d2052034                 ld      [%l4+0x34], %o1! int
F00E6420: 7ffc807a                 call    _div
F00E6424: d4232370                 st      %o2, [%o4+0x370]
F00E6428: d2052034                 ld      [%l4+0x34], %o1
F00E642C: 80a26001                 cmp     %o1, 1
F00E6430: 02800007                 be      loc_F00E644C
F00E6434: aa220011                 sub     %o0, %l1, %l5
F00E6438: 80a26004                 cmp     %o1, 4
F00E643C: 02800021                 be      loc_F00E64C0
F00E6440: d407bff4                 ld      [%fp+var_C], %o2
F00E6444: 1080003b                 ba      loc_F00E6530
F00E6448: d007bff4                 ld      [%fp+var_C], %o0
F00E644C: d407bff4                 ld      [%fp+var_C], %o2
F00E6450: 90100012                 mov     %l2, %o0
F00E6454: d2052038                 ld      [%l4+0x38], %o1
F00E6458: 7ffc802a                 call    _umul
F00E645C: a402a01c                 add     %o2, 0x1C, %l2
F00E6460: 94100008                 mov     %o0, %o2
F00E6464: e0052014                 ld      [%l4+0x14], %l0
F00E6468: 90100018                 mov     %i0, %o0
F00E646C: d2052034                 ld      [%l4+0x34], %o1
F00E6470: 7ffc8024                 call    _umul
F00E6474: a004000a                 add     %l0, %o2, %l0
F00E6478: a684ffff                 inccc   -1, %l3
F00E647C: 0c80002c                 bneg    loc_F00E652C
F00E6480: a0040008                 add     %l0, %o0, %l0
F00E6484: e2166004                 lduh    [%i1+4], %l1
F00E6488: a2847fff                 inccc   -1, %l1
F00E648C: 2c800009                 bneg,a  loc_F00E64B0
F00E6490: a684ffff                 inccc   -1, %l3
F00E6494: d00c0000                 ldub    [%l0], %o0
F00E6498: a2847fff                 inccc   -1, %l1
F00E649C: d02c8000                 stb     %o0, [%l2]
F00E64A0: a0042001                 inc     %l0
F00E64A4: 1cbffffc                 bpos    loc_F00E6494
F00E64A8: a404a001                 inc     %l2
F00E64AC: a684ffff                 inccc   -1, %l3
F00E64B0: 1cbffff5                 bpos    loc_F00E6484
F00E64B4: a0040015                 add     %l0, %l5, %l0
F00E64B8: 1080001e                 ba      loc_F00E6530
F00E64BC: d007bff4                 ld      [%fp+var_C], %o0
F00E64C0: 90100012                 mov     %l2, %o0
F00E64C4: d2052038                 ld      [%l4+0x38], %o1
F00E64C8: 7ffc800e                 call    _umul
F00E64CC: a402a01c                 add     %o2, 0x1C, %l2
F00E64D0: 94100008                 mov     %o0, %o2
F00E64D4: e0052018                 ld      [%l4+0x18], %l0
F00E64D8: 90100018                 mov     %i0, %o0
F00E64DC: d2052034                 ld      [%l4+0x34], %o1
F00E64E0: 7ffc8008                 call    _umul
F00E64E4: a004000a                 add     %l0, %o2, %l0
F00E64E8: a684ffff                 inccc   -1, %l3
F00E64EC: 0c800010                 bneg    loc_F00E652C
F00E64F0: a0040008                 add     %l0, %o0, %l0
F00E64F4: 932d6002                 sll     %l5, 2, %o1
F00E64F8: e2166004                 lduh    [%i1+4], %l1
F00E64FC: a2847fff                 inccc   -1, %l1
F00E6500: 2c800009                 bneg,a  loc_F00E6524
F00E6504: a684ffff                 inccc   -1, %l3
F00E6508: d0040000                 ld      [%l0], %o0
F00E650C: a2847fff                 inccc   -1, %l1
F00E6510: d0248000                 st      %o0, [%l2]
F00E6514: a0042004                 inc     4, %l0
F00E6518: 1cbffffc                 bpos    loc_F00E6508
F00E651C: a404a004                 inc     4, %l2
F00E6520: a684ffff                 inccc   -1, %l3
F00E6524: 1cbffff5                 bpos    loc_F00E64F8
F00E6528: a0040009                 add     %l0, %o1, %l0
F00E652C: d007bff4                 ld      [%fp+var_C], %o0
F00E6530: f0020000                 ld      [%o0], %i0
F00E6534: 80a62000                 cmp     %i0, 0
F00E6538: 068000a5                 bl      locret_F00E67CC
F00E653C: 113c04bb                 sethi   %hi(dword_F012EF68), %o0
F00E6540: d2022368                 ld      [%o0+%lo(dword_F012EF68)], %o1
F00E6544: 80a26000                 cmp     %o1, 0
F00E6548: 2280000b                 be,a    loc_F00E6574
F00E654C: d0026018                 ld      [%o1+0x18], %o0
F00E6550: f0024000                 ld      [%o1], %i0
F00E6554: 80a62000                 cmp     %i0, 0
F00E6558: 32800007                 bne,a   loc_F00E6574
F00E655C: d0026018                 ld      [%o1+0x18], %o0
F00E6560: d2026008                 ld      [%o1+8], %o1
F00E6564: 80a26000                 cmp     %o1, 0
F00E6568: 32bffffb                 bne,a   loc_F00E6554
F00E656C: f0024000                 ld      [%o1], %i0
F00E6570: d0026018                 ld      [%o1+0x18], %o0
F00E6574: 9402601c                 add     %o1, 0x1C, %o2
F00E6578: 93322002                 srl     %o0, 2, %o1
F00E657C: 92827fff                 inccc   -1, %o1
F00E6580: 0c800009                 bneg    loc_F00E65A4
F00E6584: 80a5a00f                 cmp     %l6, 0xF
F00E6588: d0028000                 ld      [%o2], %o0
F00E658C: 92827fff                 inccc   -1, %o1
F00E6590: 90380008                 xnor    %g0, %o0, %o0
F00E6594: d0228000                 st      %o0, [%o2]
F00E6598: 1cbffffc                 bpos    loc_F00E6588
F00E659C: 9402a004                 inc     4, %o2
F00E65A0: 80a5a00f                 cmp     %l6, 0xF
F00E65A4: 133c04bb                 sethi   %hi(_sparcfbs), %o1
F00E65A8: 912da004                 sll     %l6, 4, %o0
F00E65AC: 90020016                 add     %o0, %l6, %o0
F00E65B0: 912a2002                 sll     %o0, 2, %o0
F00E65B4: d2026364                 ld      [%o1+%lo(_sparcfbs)], %o1
F00E65B8: 90022008                 inc     8, %o0
F00E65BC: 18800006                 bgu     loc_F00E65D4
F00E65C0: a6024008                 add     %o1, %o0, %l3
F00E65C4: d0024008                 ld      [%o1+%o0], %o0
F00E65C8: 80a22000                 cmp     %o0, 0
F00E65CC: 12800004                 bne     loc_F00E65DC
F00E65D0: 113c04bb                 sethi   -0xFED1400, %o0
F00E65D4: 1080007e                 ba      locret_F00E67CC
F00E65D8: b0103d40                 mov     -0x2C0, %i0
F00E65DC: f2022368                 ld      [%o0+0x368], %i1
F00E65E0: 80a66000                 cmp     %i1, 0
F00E65E4: 0280000c                 be      loc_F00E6614
F00E65E8: ac102000                 mov     0, %l6
F00E65EC: d0064000                 ld      [%i1], %o0
F00E65F0: 80a22000                 cmp     %o0, 0
F00E65F4: 12800008                 bne     loc_F00E6614
F00E65F8: 80a66000                 cmp     %i1, 0
F00E65FC: ac100019                 mov     %i1, %l6
F00E6600: f2066008                 ld      [%i1+8], %i1
F00E6604: 80a66000                 cmp     %i1, 0
F00E6608: 32bffffa                 bne,a   loc_F00E65F0
F00E660C: d0064000                 ld      [%i1], %o0
F00E6610: 80a66000                 cmp     %i1, 0
F00E6614: 0280006e                 be      locret_F00E67CC
F00E6618: b0103d3e                 mov     -0x2C2, %i0
F00E661C: d206600c                 ld      [%i1+0xC], %o1
F00E6620: d004e034                 ld      [%l3+0x34], %o0
F00E6624: 80a24008                 cmp     %o1, %o0
F00E6628: 22800003                 be,a    loc_F00E6634
F00E662C: f0166014                 lduh    [%i1+0x14], %i0
F00E6630: 30800067                 ba,a    locret_F00E67CC
F00E6634: e4166016                 lduh    [%i1+0x16], %l2
F00E6638: d004e038                 ld      [%l3+0x38], %o0! int
F00E663C: e0166012                 lduh    [%i1+0x12], %l0
F00E6640: d204e034                 ld      [%l3+0x34], %o1! int
F00E6644: 7ffc7ff1                 call    _div
F00E6648: ea166010                 lduh    [%i1+0x10], %l5
F00E664C: d204e034                 ld      [%l3+0x34], %o1
F00E6650: 80a26001                 cmp     %o1, 1
F00E6654: 02800007                 be      loc_F00E6670
F00E6658: a8220018                 sub     %o0, %i0, %l4
F00E665C: 80a26004                 cmp     %o1, 4
F00E6660: 02800020                 be      loc_F00E66E0
F00E6664: a206601c                 add     %i1, 0x1C, %l1
F00E6668: 10800039                 ba      loc_F00E674C
F00E666C: 80a5a000                 cmp     %l6, 0
F00E6670: a206601c                 add     %i1, 0x1C, %l1
F00E6674: d204e038                 ld      [%l3+0x38], %o1
F00E6678: 7ffc7fa2                 call    _umul
F00E667C: 90100010                 mov     %l0, %o0
F00E6680: 94100008                 mov     %o0, %o2
F00E6684: e004e014                 ld      [%l3+0x14], %l0
F00E6688: 90100015                 mov     %l5, %o0
F00E668C: d204e034                 ld      [%l3+0x34], %o1
F00E6690: 7ffc7f9c                 call    _umul
F00E6694: a004000a                 add     %l0, %o2, %l0
F00E6698: a484bfff                 inccc   -1, %l2
F00E669C: 0c80002b                 bneg    loc_F00E6748
F00E66A0: a0040008                 add     %l0, %o0, %l0
F00E66A4: f0166014                 lduh    [%i1+0x14], %i0
F00E66A8: b0863fff                 inccc   -1, %i0
F00E66AC: 2c800009                 bneg,a  loc_F00E66D0
F00E66B0: a484bfff                 inccc   -1, %l2
F00E66B4: d00c4000                 ldub    [%l1], %o0
F00E66B8: b0863fff                 inccc   -1, %i0
F00E66BC: d02c0000                 stb     %o0, [%l0]
F00E66C0: a2046001                 inc     %l1
F00E66C4: 1cbffffc                 bpos    loc_F00E66B4
F00E66C8: a0042001                 inc     %l0
F00E66CC: a484bfff                 inccc   -1, %l2
F00E66D0: 1cbffff5                 bpos    loc_F00E66A4
F00E66D4: a0040014                 add     %l0, %l4, %l0
F00E66D8: 1080001d                 ba      loc_F00E674C
F00E66DC: 80a5a000                 cmp     %l6, 0
F00E66E0: d204e038                 ld      [%l3+0x38], %o1
F00E66E4: 7ffc7f87                 call    _umul
F00E66E8: 90100010                 mov     %l0, %o0
F00E66EC: 94100008                 mov     %o0, %o2
F00E66F0: e004e018                 ld      [%l3+0x18], %l0
F00E66F4: 90100015                 mov     %l5, %o0
F00E66F8: d204e034                 ld      [%l3+0x34], %o1
F00E66FC: 7ffc7f81                 call    _umul
F00E6700: a004000a                 add     %l0, %o2, %l0
F00E6704: a484bfff                 inccc   -1, %l2
F00E6708: 0c800010                 bneg    loc_F00E6748
F00E670C: a0040008                 add     %l0, %o0, %l0
F00E6710: 932d2002                 sll     %l4, 2, %o1
F00E6714: f0166014                 lduh    [%i1+0x14], %i0
F00E6718: b0863fff                 inccc   -1, %i0
F00E671C: 2c800009                 bneg,a  loc_F00E6740
F00E6720: a484bfff                 inccc   -1, %l2
F00E6724: d0044000                 ld      [%l1], %o0
F00E6728: b0863fff                 inccc   -1, %i0
F00E672C: d0240000                 st      %o0, [%l0]
F00E6730: a2046004                 inc     4, %l1
F00E6734: 1cbffffc                 bpos    loc_F00E6724
F00E6738: a0042004                 inc     4, %l0
F00E673C: a484bfff                 inccc   -1, %l2
F00E6740: 1cbffff5                 bpos    loc_F00E6714
F00E6744: a0040009                 add     %l0, %o1, %l0
F00E6748: 80a5a000                 cmp     %l6, 0
F00E674C: 22800005                 be,a    loc_F00E6760
F00E6750: d2066008                 ld      [%i1+8], %o1
F00E6754: d0066008                 ld      [%i1+8], %o0
F00E6758: 10800004                 ba      loc_F00E6768
F00E675C: d025a008                 st      %o0, [%l6+8]
F00E6760: 113c04bb                 sethi   %hi(dword_F012EF68), %o0
F00E6764: d2222368                 st      %o1, [%o0+%lo(dword_F012EF68)]
F00E6768: 173c04bb                 sethi   %hi(dword_F012EF74), %o3
F00E676C: d002e374                 ld      [%o3+%lo(dword_F012EF74)], %o0
F00E6770: 80a22009                 cmp     %o0, 9
F00E6774: 04800010                 ble     loc_F00E67B4
F00E6778: 153c04bb                 sethi   -0xFED1400, %o2
F00E677C: 113c04cc901220e4         set     unk_F01330E4, %o0
F00E6784: 80a64008                 cmp     %i1, %o0
F00E6788: 12800006                 bne     loc_F00E67A0
F00E678C: 113c04d1                 sethi   -0xFECBC00, %o0
F00E6790: 133c04bb                 sethi   %hi(dword_F012EF78), %o1
F00E6794: 90102c04                 mov     0xC04, %o0
F00E6798: 1080000c                 ba      loc_F00E67C8
F00E679C: d0226378                 st      %o0, [%o1+%lo(dword_F012EF78)]
F00E67A0: d0022340                 ld      [%o0+0x340], %o0
F00E67A4: 7ffe7438                 call    _kmem_free
F00E67A8: 92100019                 mov     %i1, %o1
F00E67AC: 10800008                 ba      locret_F00E67CC
F00E67B0: b0102000                 mov     0, %i0
F00E67B4: d202a36c                 ld      [%o2+0x36C], %o1
F00E67B8: 90022001                 inc     %o0
F00E67BC: d022e374                 st      %o0, [%o3+0x374]
F00E67C0: d2266008                 st      %o1, [%i1+8]
F00E67C4: f222a36c                 st      %i1, [%o2+0x36C]
F00E67C8: b0102000                 mov     0, %i0
F00E67CC: 81c7e008                 ret
F00E67D0: 81e80000                 restore
