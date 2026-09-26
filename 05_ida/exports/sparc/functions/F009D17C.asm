F009D17C: 9de3bf68                 save    %sp, -0x98, %sp
F009D180: ba100018                 mov     %i0, %i5
F009D184: f227bfec                 st      %i1, [%fp+var_14]
F009D188: f427bfe4                 st      %i2, [%fp+var_1C]
F009D18C: c027bfdc                 clr     [%fp+var_24]
F009D190: 80a76000                 cmp     %i5, 0
F009D194: 02800197                 be      locret_F009D7F0
F009D198: c027bfd4                 clr     [%fp+var_2C]
F009D19C: 133c04f792126270         set     _pmap_info, %o1
F009D1A4: d0026054                 ld      [%o1+0x54], %o0
F009D1A8: 90022001                 inc     %o0
F009D1AC: 7fffe6d4                 call    _splvm
F009D1B0: d0226054                 st      %o0, [%o1+0x54]
F009D1B4: 133c04d0                 sethi   %hi(_page_mask), %o1
F009D1B8: d20260d8                 ld      [%o1+%lo(_page_mask)], %o1
F009D1BC: c607bfec                 ld      [%fp+var_14], %g3
F009D1C0: d027bfcc                 st      %o0, [%fp+var_34]
F009D1C4: 9228c009                 andn    %g3, %o1, %o1
F009D1C8: c607bfe4                 ld      [%fp+var_1C], %g3
F009D1CC: 80a24003                 cmp     %o1, %g3
F009D1D0: 1a800181                 bcc     loc_F009D7D4
F009D1D4: d227bff4                 st      %o1, [%fp+var_C]
F009D1D8: b2102001                 mov     1, %i1
F009D1DC: 9010001d                 mov     %i5, %o0
F009D1E0: d207bff4                 ld      [%fp+var_C], %o1
F009D1E4: 7ffffdf5                 call    _pmap_page_table_entry
F009D1E8: 94102000                 mov     0, %o2
F009D1EC: a8920000                 orcc    %o0, %g0, %l4
F009D1F0: 32800009                 bne,a   loc_F009D214
F009D1F4: d00d200d                 ldub    [%l4+0xD], %o0
F009D1F8: d007bff4                 ld      [%fp+var_C], %o0
F009D1FC: 07000100                 sethi   0x40000, %g3
F009D200: 90020003                 add     %o0, %g3, %o0
F009D204: 073fff00                 sethi   -0x40000, %g3
F009D208: 900a0003                 and     %o0, %g3, %o0
F009D20C: 1080016d                 ba      loc_F009D7C0
F009D210: d027bff4                 st      %o0, [%fp+var_C]
F009D214: 80a22003                 cmp     %o0, 3
F009D218: 12800008                 bne     loc_F009D238
F009D21C: 80a22002                 cmp     %o0, 2
F009D220: d007bff4                 ld      [%fp+var_C], %o0
F009D224: 07000100                 sethi   0x40000, %g3
F009D228: 90020003                 add     %o0, %g3, %o0
F009D22C: 073fff00                 sethi   -0x40000, %g3
F009D230: 10800009                 ba      loc_F009D254
F009D234: b40a0003                 and     %o0, %g3, %i2
F009D238: 12800007                 bne     loc_F009D254
F009D23C: 353ffff8                 sethi   -0x2000, %i2
F009D240: d007bff4                 ld      [%fp+var_C], %o0
F009D244: 07004000                 sethi   0x1000000, %g3
F009D248: 90020003                 add     %o0, %g3, %o0
F009D24C: 073fc000                 sethi   -0x1000000, %g3
F009D250: b40a0003                 and     %o0, %g3, %i2
F009D254: c607bfe4                 ld      [%fp+var_1C], %g3
F009D258: 80a68003                 cmp     %i2, %g3
F009D25C: 38800002                 bgu,a   loc_F009D264
F009D260: f407bfe4                 ld      [%fp+var_1C], %i2
F009D264: d007bff4                 ld      [%fp+var_C], %o0
F009D268: 80a2001a                 cmp     %o0, %i2
F009D26C: 3a800150                 bcc,a   loc_F009D7AC
F009D270: d00d200f                 ldub    [%l4+0xF], %o0
F009D274: d20d200d                 ldub    [%l4+0xD], %o1
F009D278: 80a26003                 cmp     %o1, 3
F009D27C: 12800006                 bne     loc_F009D294
F009D280: 80a26002                 cmp     %o1, 2
F009D284: 9132200a                 srl     %o0, 10, %o0
F009D288: d2050000                 ld      [%l4], %o1
F009D28C: 1080000a                 ba      loc_F009D2B4
F009D290: 900a20fc                 and     %o0, 0xFC, %o0
F009D294: 32800006                 bne,a   loc_F009D2AC
F009D298: d00fbff4                 ldub    [%fp+var_C], %o0
F009D29C: d017bff4                 lduh    [%fp+var_C], %o0
F009D2A0: d2050000                 ld      [%l4], %o1
F009D2A4: 10800004                 ba      loc_F009D2B4
F009D2A8: 900a20fc                 and     %o0, 0xFC, %o0
F009D2AC: d2050000                 ld      [%l4], %o1
F009D2B0: 912a2002                 sll     %o0, 2, %o0
F009D2B4: a0024008                 add     %o1, %o0, %l0
F009D2B8: d00d200d                 ldub    [%l4+0xD], %o0
F009D2BC: 80a22003                 cmp     %o0, 3
F009D2C0: 12800006                 bne     loc_F009D2D8
F009D2C4: a2042004                 add     %l0, 4, %l1
F009D2C8: 113c04f7                 sethi   %hi(_pmap_info), %o0
F009D2CC: d0122270                 lduh    [%o0+%lo(_pmap_info)], %o0
F009D2D0: 912a2002                 sll     %o0, 2, %o0
F009D2D4: a2040008                 add     %l0, %o0, %l1
F009D2D8: b8102000                 mov     0, %i4
F009D2DC: d0040000                 ld      [%l0], %o0
F009D2E0: 900a2003                 and     %o0, 3, %o0
F009D2E4: 80a22002                 cmp     %o0, 2
F009D2E8: 12800117                 bne     loc_F009D744
F009D2EC: b6102000                 mov     0, %i3
F009D2F0: c607bfdc                 ld      [%fp+var_24], %g3
F009D2F4: d00d200d                 ldub    [%l4+0xD], %o0
F009D2F8: 8600e001                 inc     %g3
F009D2FC: 80a22003                 cmp     %o0, 3
F009D300: 12800009                 bne     loc_F009D324
F009D304: c627bfdc                 st      %g3, [%fp+var_24]
F009D308: d007bff4                 ld      [%fp+var_C], %o0
F009D30C: 9132200c                 srl     %o0, 12, %o0
F009D310: 93322003                 srl     %o0, 3, %o1
F009D314: 920a6004                 and     %o1, 4, %o1
F009D318: 92024014                 add     %o1, %l4, %o1
F009D31C: 1080000b                 ba      loc_F009D348
F009D320: 900a201e                 and     %o0, 0x1E, %o0
F009D324: 80a22002                 cmp     %o0, 2
F009D328: 1280000f                 bne     loc_F009D364
F009D32C: d00fbff4                 ldub    [%fp+var_C], %o0
F009D330: d007bff4                 ld      [%fp+var_C], %o0
F009D334: 91322012                 srl     %o0, 18, %o0
F009D338: 93322003                 srl     %o0, 3, %o1
F009D33C: 920a6004                 and     %o1, 4, %o1
F009D340: 92024014                 add     %o1, %l4, %o1
F009D344: 900a201f                 and     %o0, 0x1F, %o0
F009D348: d2026010                 ld      [%o1+0x10], %o1
F009D34C: 912e4008                 sll     %i1, %o0, %o0
F009D350: 808a4008                 btst    %o0, %o1
F009D354: 3280000e                 bne,a   loc_F009D38C
F009D358: d00d200d                 ldub    [%l4+0xD], %o0
F009D35C: 10800029                 ba      loc_F009D400
F009D360: d0040000                 ld      [%l0], %o0
F009D364: 93322005                 srl     %o0, 5, %o1
F009D368: 932a6002                 sll     %o1, 2, %o1
F009D36C: 92024014                 add     %o1, %l4, %o1
F009D370: 900a201f                 and     %o0, 0x1F, %o0
F009D374: d2026010                 ld      [%o1+0x10], %o1
F009D378: 912e4008                 sll     %i1, %o0, %o0
F009D37C: 808a4008                 btst    %o0, %o1
F009D380: 22800020                 be,a    loc_F009D400
F009D384: d0040000                 ld      [%l0], %o0
F009D388: d00d200d                 ldub    [%l4+0xD], %o0
F009D38C: 80a22003                 cmp     %o0, 3
F009D390: 12800009                 bne     loc_F009D3B4
F009D394: 80a22002                 cmp     %o0, 2
F009D398: d007bff4                 ld      [%fp+var_C], %o0
F009D39C: 9132200c                 srl     %o0, 12, %o0
F009D3A0: 93322003                 srl     %o0, 3, %o1
F009D3A4: 920a6004                 and     %o1, 4, %o1
F009D3A8: 92024014                 add     %o1, %l4, %o1
F009D3AC: 1080000d                 ba      loc_F009D3E0
F009D3B0: 900a201e                 and     %o0, 0x1E, %o0
F009D3B4: 12800007                 bne     loc_F009D3D0
F009D3B8: d00fbff4                 ldub    [%fp+var_C], %o0
F009D3BC: d007bff4                 ld      [%fp+var_C], %o0
F009D3C0: 91322012                 srl     %o0, 18, %o0
F009D3C4: 93322003                 srl     %o0, 3, %o1
F009D3C8: 10800004                 ba      loc_F009D3D8
F009D3CC: 920a6004                 and     %o1, 4, %o1
F009D3D0: 93322005                 srl     %o0, 5, %o1
F009D3D4: 932a6002                 sll     %o1, 2, %o1
F009D3D8: 92024014                 add     %o1, %l4, %o1
F009D3DC: 900a201f                 and     %o0, 0x1F, %o0
F009D3E0: d4026010                 ld      [%o1+0x10], %o2
F009D3E4: 912e4008                 sll     %i1, %o0, %o0
F009D3E8: 902a8008                 andn    %o2, %o0, %o0
F009D3EC: d0226010                 st      %o0, [%o1+0x10]
F009D3F0: c607bfd4                 ld      [%fp+var_2C], %g3
F009D3F4: 8600e001                 inc     %g3
F009D3F8: c627bfd4                 st      %g3, [%fp+var_2C]
F009D3FC: d0040000                 ld      [%l0], %o0
F009D400: 133c0464                 sethi   %hi(_physmaxpfn), %o1
F009D404: d202638c                 ld      [%o1+%lo(_physmaxpfn)], %o1
F009D408: 91322008                 srl     %o0, 8, %o0
F009D40C: 80a20009                 cmp     %o0, %o1
F009D410: 3a800008                 bcc,a   loc_F009D430
F009D414: e827bff0                 st      %l4, [%fp+var_10]
F009D418: 7fffa3ee                 call    _vm_valid_page
F009D41C: 912a200c                 sll     %o0, 12, %o0
F009D420: 80a22000                 cmp     %o0, 0
F009D424: 32800008                 bne,a   loc_F009D444
F009D428: d00d200d                 ldub    [%l4+0xD], %o0
F009D42C: e827bff0                 st      %l4, [%fp+var_10]
F009D430: d207bff4                 ld      [%fp+var_C], %o1
F009D434: 40001042                 call    _set_invalidpte
F009D438: 9007bff0                 add     %fp, var_10, %o0
F009D43C: 108000c3                 ba      loc_F009D748
F009D440: d00d200d                 ldub    [%l4+0xD], %o0
F009D444: 80a22003                 cmp     %o0, 3
F009D448: 12800007                 bne     loc_F009D464
F009D44C: d0040000                 ld      [%l0], %o0
F009D450: d207bff4                 ld      [%fp+var_C], %o1
F009D454: 91322008                 srl     %o0, 8, %o0
F009D458: 912a200c                 sll     %o0, 12, %o0
F009D45C: 10800007                 ba      loc_F009D478
F009D460: 920a6fff                 and     %o1, 0xFFF, %o1
F009D464: 133fff00                 sethi   -0x40000, %o1
F009D468: d407bff4                 ld      [%fp+var_C], %o2
F009D46C: 91322008                 srl     %o0, 8, %o0
F009D470: 912a200c                 sll     %o0, 12, %o0
F009D474: 922a8009                 andn    %o2, %o1, %o1
F009D478: 80a40011                 cmp     %l0, %l1
F009D47C: 1a800037                 bcc     loc_F009D558
F009D480: b0020009                 add     %o0, %o1, %i0
F009D484: d407bff4                 ld      [%fp+var_C], %o2
F009D488: 9332a00c                 srl     %o2, 12, %o1
F009D48C: 91326003                 srl     %o1, 3, %o0
F009D490: 900a2004                 and     %o0, 4, %o0
F009D494: 84020014                 add     %o0, %l4, %g2
F009D498: 920a601e                 and     %o1, 0x1E, %o1
F009D49C: 9b2e4009                 sll     %i1, %o1, %o5
F009D4A0: 9532a012                 srl     %o2, 18, %o2
F009D4A4: 9132a003                 srl     %o2, 3, %o0
F009D4A8: 900a2004                 and     %o0, 4, %o0
F009D4AC: 98020014                 add     %o0, %l4, %o4
F009D4B0: 940aa01f                 and     %o2, 0x1F, %o2
F009D4B4: d20fbff4                 ldub    [%fp+var_C], %o1
F009D4B8: 972e400a                 sll     %i1, %o2, %o3
F009D4BC: 91326005                 srl     %o1, 5, %o0
F009D4C0: 912a2002                 sll     %o0, 2, %o0
F009D4C4: 94020014                 add     %o0, %l4, %o2
F009D4C8: 920a601f                 and     %o1, 0x1F, %o1
F009D4CC: 932e4009                 sll     %i1, %o1, %o1
F009D4D0: d0040000                 ld      [%l0], %o0
F009D4D4: 808a2040                 btst    0x40, %o0 ! '@'
F009D4D8: 32800019                 bne,a   loc_F009D53C
F009D4DC: b8102001                 mov     1, %i4
F009D4E0: d00d200d                 ldub    [%l4+0xD], %o0
F009D4E4: 80a22003                 cmp     %o0, 3
F009D4E8: 12800008                 bne     loc_F009D508
F009D4EC: 80a22002                 cmp     %o0, 2
F009D4F0: d000a018                 ld      [%g2+0x18], %o0
F009D4F4: 808a000d                 btst    %o5, %o0
F009D4F8: 32800010                 bne,a   loc_F009D538
F009D4FC: b8102001                 mov     1, %i4
F009D500: 1080000f                 ba      loc_F009D53C
F009D504: d0040000                 ld      [%l0], %o0
F009D508: 32800008                 bne,a   loc_F009D528
F009D50C: d002a030                 ld      [%o2+0x30], %o0
F009D510: d0032018                 ld      [%o4+0x18], %o0
F009D514: 808a000b                 btst    %o3, %o0
F009D518: 32800008                 bne,a   loc_F009D538
F009D51C: b8102001                 mov     1, %i4
F009D520: 10800007                 ba      loc_F009D53C
F009D524: d0040000                 ld      [%l0], %o0
F009D528: 808a0009                 btst    %o1, %o0
F009D52C: 22800004                 be,a    loc_F009D53C
F009D530: d0040000                 ld      [%l0], %o0
F009D534: b8102001                 mov     1, %i4
F009D538: d0040000                 ld      [%l0], %o0
F009D53C: 808a2020                 btst    0x20, %o0 ! ' '
F009D540: 32800002                 bne,a   loc_F009D548
F009D544: b6102001                 mov     1, %i3
F009D548: a0042004                 inc     4, %l0
F009D54C: 80a40011                 cmp     %l0, %l1
F009D550: 2abfffe1                 bcs,a   loc_F009D4D4
F009D554: d0040000                 ld      [%l0], %o0
F009D558: e827bff0                 st      %l4, [%fp+var_10]
F009D55C: d207bff4                 ld      [%fp+var_C], %o1
F009D560: 40000ff7                 call    _set_invalidpte
F009D564: 9007bff0                 add     %fp, var_10, %o0
F009D568: d00d200d                 ldub    [%l4+0xD], %o0
F009D56C: 80a22003                 cmp     %o0, 3
F009D570: 1280000a                 bne     loc_F009D598
F009D574: 80a22002                 cmp     %o0, 2
F009D578: 113c04d0                 sethi   %hi(_page_mask), %o0
F009D57C: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F009D580: d207bff4                 ld      [%fp+var_C], %o1
F009D584: 073c0447                 sethi   %hi(_page_size), %g3
F009D588: d400e13c                 ld      [%g3+%lo(_page_size)], %o2
F009D58C: 902a4008                 andn    %o1, %o0, %o0
F009D590: 1080000c                 ba      loc_F009D5C0
F009D594: ac02000a                 add     %o0, %o2, %l6
F009D598: 12800006                 bne     loc_F009D5B0
F009D59C: d007bff4                 ld      [%fp+var_C], %o0
F009D5A0: 073fff00                 sethi   -0x40000, %g3
F009D5A4: 900a0003                 and     %o0, %g3, %o0
F009D5A8: 10800005                 ba      loc_F009D5BC
F009D5AC: 07000100                 sethi   0x40000, %g3
F009D5B0: 073fc000                 sethi   -0x1000000, %g3
F009D5B4: 900a0003                 and     %o0, %g3, %o0
F009D5B8: 07004000                 sethi   0x1000000, %g3
F009D5BC: ac020003                 add     %o0, %g3, %l6
F009D5C0: ea07bff4                 ld      [%fp+var_C], %l5
F009D5C4: 80a54016                 cmp     %l5, %l6
F009D5C8: 1a80005f                 bcc     loc_F009D744
F009D5CC: ae100018                 mov     %i0, %l7
F009D5D0: 7fffa35a                 call    _vm_mem_ppi
F009D5D4: 90100018                 mov     %i0, %o0
F009D5D8: 80a72000                 cmp     %i4, 0
F009D5DC: 932a2002                 sll     %o0, 2, %o1
F009D5E0: 92024008                 add     %o1, %o0, %o1
F009D5E4: 073c04f7                 sethi   %hi(_pg_desc_tbl), %g3
F009D5E8: e600e260                 ld      [%g3+%lo(_pg_desc_tbl)], %l3
F009D5EC: a52a6002                 sll     %o1, 2, %l2
F009D5F0: 0280000a                 be      loc_F009D618
F009D5F4: a004c012                 add     %l3, %l2, %l0
F009D5F8: 7fffa395                 call    _vm_phys_to_vm_page
F009D5FC: 90100017                 mov     %l7, %o0
F009D600: d202201c                 ld      [%o0+0x1C], %o1
F009D604: 920a7bff                 and     %o1, -0x401, %o1
F009D608: d222201c                 st      %o1, [%o0+0x1C]
F009D60C: d00c2010                 ldub    [%l0+0x10], %o0
F009D610: 90122001                 bset    1, %o0
F009D614: d02c2010                 stb     %o0, [%l0+0x10]
F009D618: 80a6e000                 cmp     %i3, 0
F009D61C: 02800005                 be      loc_F009D630
F009D620: a2100010                 mov     %l0, %l1
F009D624: d00c2010                 ldub    [%l0+0x10], %o0
F009D628: 90122002                 bset    2, %o0
F009D62C: d02c2010                 stb     %o0, [%l0+0x10]
F009D630: d0046004                 ld      [%l1+4], %o0
F009D634: 80a22000                 cmp     %o0, 0
F009D638: 32800006                 bne,a   loc_F009D650
F009D63C: d0046008                 ld      [%l1+8], %o0
F009D640: 113c045f                 sethi   %hi(aPmapRemovePmap), %o0! "pmap_remove: pmap null in pg_desc"
F009D644: 7ffddecb                 call    _panic
F009D648: 90122138                 bset    %lo(aPmapRemovePmap), %o0! "pmap_remove: pmap null in pg_desc"
F009D64C: d0046008                 ld      [%l1+8], %o0
F009D650: 91322008                 srl     %o0, 8, %o0
F009D654: 912a200c                 sll     %o0, 12, %o0
F009D658: 80a20015                 cmp     %o0, %l5
F009D65C: 32800015                 bne,a   loc_F009D6B0
F009D660: e0044000                 ld      [%l1], %l0
F009D664: d0046004                 ld      [%l1+4], %o0
F009D668: 80a2001d                 cmp     %o0, %i5
F009D66C: 32800011                 bne,a   loc_F009D6B0
F009D670: e0044000                 ld      [%l1], %l0
F009D674: e004c012                 ld      [%l3+%l2], %l0
F009D678: 80a42000                 cmp     %l0, 0
F009D67C: 0280000b                 be      loc_F009D6A8
F009D680: 92100010                 mov     %l0, %o1
F009D684: d0040000                 ld      [%l0], %o0
F009D688: d024c012                 st      %o0, [%l3+%l2]
F009D68C: d0042004                 ld      [%l0+4], %o0
F009D690: d0246004                 st      %o0, [%l1+4]
F009D694: d4042008                 ld      [%l0+8], %o2
F009D698: 073c04f7                 sethi   %hi(_pv_entry_zone), %g3
F009D69C: d000e388                 ld      [%g3+%lo(_pv_entry_zone)], %o0
F009D6A0: 10800021                 ba      loc_F009D724
F009D6A4: d4246008                 st      %o2, [%l1+8]
F009D6A8: 10800021                 ba      loc_F009D72C
F009D6AC: c0246004                 clr     [%l1+4]
F009D6B0: 80a42000                 cmp     %l0, 0
F009D6B4: 02800012                 be      loc_F009D6FC
F009D6B8: 01000000                 nop
F009D6BC: d0042008                 ld      [%l0+8], %o0
F009D6C0: 91322008                 srl     %o0, 8, %o0
F009D6C4: 912a200c                 sll     %o0, 12, %o0
F009D6C8: 80a20015                 cmp     %o0, %l5
F009D6CC: 32800007                 bne,a   loc_F009D6E8
F009D6D0: a2100010                 mov     %l0, %l1
F009D6D4: d0042004                 ld      [%l0+4], %o0
F009D6D8: 80a2001d                 cmp     %o0, %i5
F009D6DC: 02800008                 be      loc_F009D6FC
F009D6E0: 80a42000                 cmp     %l0, 0
F009D6E4: a2100010                 mov     %l0, %l1
F009D6E8: e0040000                 ld      [%l0], %l0
F009D6EC: 80a42000                 cmp     %l0, 0
F009D6F0: 32bffff4                 bne,a   loc_F009D6C0
F009D6F4: d0042008                 ld      [%l0+8], %o0
F009D6F8: 80a42000                 cmp     %l0, 0
F009D6FC: 12800006                 bne     loc_F009D714
F009D700: 92100010                 mov     %l0, %o1
F009D704: 113c045f                 sethi   %hi(aPmapRemovePmap_0), %o0! "pmap_remove: pmap not found in pv_list"
F009D708: 7ffdde9a                 call    _panic
F009D70C: 90122160                 bset    %lo(aPmapRemovePmap_0), %o0! "pmap_remove: pmap not found in pv_list"
F009D710: 92100010                 mov     %l0, %o1
F009D714: d4040000                 ld      [%l0], %o2
F009D718: 073c04f7                 sethi   %hi(_pv_entry_zone), %g3
F009D71C: d000e388                 ld      [%g3+%lo(_pv_entry_zone)], %o0
F009D720: d4244000                 st      %o2, [%l1]
F009D724: 7fff6eab                 call    _zfree
F009D728: 01000000                 nop
F009D72C: 073c0447                 sethi   %hi(_page_size), %g3
F009D730: d000e13c                 ld      [%g3+%lo(_page_size)], %o0
F009D734: aa054008                 add     %l5, %o0, %l5
F009D738: 80a54016                 cmp     %l5, %l6
F009D73C: 0abfffa5                 bcs     loc_F009D5D0
F009D740: ae05c008                 add     %l7, %o0, %l7
F009D744: d00d200d                 ldub    [%l4+0xD], %o0
F009D748: 80a22003                 cmp     %o0, 3
F009D74C: 1280000a                 bne     loc_F009D774
F009D750: 80a22002                 cmp     %o0, 2
F009D754: 113c04d0                 sethi   %hi(_page_mask), %o0
F009D758: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F009D75C: d207bff4                 ld      [%fp+var_C], %o1
F009D760: 073c0447                 sethi   %hi(_page_size), %g3
F009D764: d400e13c                 ld      [%g3+%lo(_page_size)], %o2
F009D768: 902a4008                 andn    %o1, %o0, %o0
F009D76C: 1080000c                 ba      loc_F009D79C
F009D770: 9002000a                 add     %o0, %o2, %o0
F009D774: 12800006                 bne     loc_F009D78C
F009D778: d007bff4                 ld      [%fp+var_C], %o0
F009D77C: 073fff00                 sethi   -0x40000, %g3
F009D780: 900a0003                 and     %o0, %g3, %o0
F009D784: 10800005                 ba      loc_F009D798
F009D788: 07000100                 sethi   0x40000, %g3
F009D78C: 073fc000                 sethi   -0x1000000, %g3
F009D790: 900a0003                 and     %o0, %g3, %o0
F009D794: 07004000                 sethi   0x1000000, %g3
F009D798: 90020003                 add     %o0, %g3, %o0
F009D79C: 80a2001a                 cmp     %o0, %i2
F009D7A0: 0abffeb5                 bcs     loc_F009D274
F009D7A4: d027bff4                 st      %o0, [%fp+var_C]
F009D7A8: d00d200f                 ldub    [%l4+0xF], %o0
F009D7AC: 80a22000                 cmp     %o0, 0
F009D7B0: 12800005                 bne     loc_F009D7C4
F009D7B4: d007bff4                 ld      [%fp+var_C], %o0
F009D7B8: 40001576                 call    _pmap_dealloc_seg_entry
F009D7BC: 90100014                 mov     %l4, %o0
F009D7C0: d007bff4                 ld      [%fp+var_C], %o0
F009D7C4: c607bfe4                 ld      [%fp+var_1C], %g3
F009D7C8: 80a20003                 cmp     %o0, %g3
F009D7CC: 0abffe85                 bcs     loc_F009D1E0
F009D7D0: 9010001d                 mov     %i5, %o0
F009D7D4: d207bfec                 ld      [%fp+var_14], %o1
F009D7D8: d407bfdc                 ld      [%fp+var_24], %o2
F009D7DC: d607bfd4                 ld      [%fp+var_2C], %o3
F009D7E0: 7ffffa3d                 call    _pmap_deallocate_mappings
F009D7E4: 9010001d                 mov     %i5, %o0
F009D7E8: 7fffe54f                 call    _splx
F009D7EC: d007bfcc                 ld      [%fp+var_34], %o0
F009D7F0: 81c7e008                 ret
F009D7F4: 81e80000                 restore
