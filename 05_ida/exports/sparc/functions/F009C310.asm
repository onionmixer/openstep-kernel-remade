F009C310: 9de3bf90                 save    %sp, -0x70, %sp
F009C314: f027a044                 st      %i0, [%fp+arg_44]
F009C318: 153c04f79412a270         set     _pmap_info, %o2
F009C320: d002a034                 ld      [%o2+0x34], %o0
F009C324: 133c0463                 sethi   %hi(_pmap_initialized), %o1
F009C328: d2026190                 ld      [%o1+%lo(_pmap_initialized)], %o1
F009C32C: 90022001                 inc     %o0
F009C330: 80a26000                 cmp     %o1, 0
F009C334: 02800005                 be      loc_F009C348
F009C338: d022a034                 st      %o0, [%o2+0x34]
F009C33C: 113c045e                 sethi   %hi(aPmapMapPmapIni), %o0! "pmap_map: pmap initialized"
F009C340: 7ffde38c                 call    _panic
F009C344: 90122330                 bset    %lo(aPmapMapPmapIni), %o0! "pmap_map: pmap initialized"
F009C348: 960ea00f                 and     %i2, 0xF, %o3
F009C34C: 972ae014                 sll     %o3, 20, %o3
F009C350: 9536600c                 srl     %i1, 12, %o2
F009C354: 110003ff981223ff         set     0xFFFFF, %o4
F009C35C: 940a800c                 and     %o2, %o4, %o2
F009C360: d207a044                 ld      [%fp+arg_44], %o1
F009C364: a012c00a                 or      %o3, %o2, %l0
F009C368: b002401b                 add     %o1, %i3, %i0
F009C36C: 920a7000                 and     %o1, -0x1000, %o1
F009C370: 90062fff                 add     %i0, 0xFFF, %o0
F009C374: b00a3000                 and     %o0, -0x1000, %i0
F009C378: 80a24018                 cmp     %o1, %i0
F009C37C: 1a800090                 bcc     locret_F009C5BC
F009C380: d227a044                 st      %o1, [%fp+arg_44]
F009C384: 233c04f0                 sethi   -0xFEC4000, %l1
F009C388: b610000c                 mov     %o4, %i3
F009C38C: 900f6001                 and     %i5, 1, %o0
F009C390: a52a2007                 sll     %o0, 7, %l2
F009C394: d0046100                 ld      [%l1+0x100], %o0
F009C398: d207a044                 ld      [%fp+arg_44], %o1
F009C39C: 40000187                 call    _pmap_page_table_entry
F009C3A0: 94102000                 mov     0, %o2
F009C3A4: ba920000                 orcc    %o0, %g0, %i5
F009C3A8: 12800007                 bne     loc_F009C3C4
F009C3AC: d0046100                 ld      [%l1+0x100], %o0
F009C3B0: d207a044                 ld      [%fp+arg_44], %o1
F009C3B4: 40000631                 call    _pmap_expand
F009C3B8: 94102003                 mov     3, %o2
F009C3BC: 10bffff7                 ba      loc_F009C398
F009C3C0: d0046100                 ld      [%l1+0x100], %o0
F009C3C4: d00f600d                 ldub    [%i5+0xD], %o0
F009C3C8: 80a22003                 cmp     %o0, 3
F009C3CC: 12800007                 bne     loc_F009C3E8
F009C3D0: 80a22002                 cmp     %o0, 2
F009C3D4: d007a044                 ld      [%fp+arg_44], %o0
F009C3D8: d2074000                 ld      [%i5], %o1
F009C3DC: 9132200a                 srl     %o0, 10, %o0
F009C3E0: 1080000a                 ba      loc_F009C408
F009C3E4: 900a20fc                 and     %o0, 0xFC, %o0
F009C3E8: 32800006                 bne,a   loc_F009C400
F009C3EC: d00fa044                 ldub    [%fp+arg_44], %o0
F009C3F0: d017a044                 lduh    [%fp+arg_44], %o0
F009C3F4: d2074000                 ld      [%i5], %o1
F009C3F8: 10800004                 ba      loc_F009C408
F009C3FC: 900a20fc                 and     %o0, 0xFC, %o0
F009C400: d2074000                 ld      [%i5], %o1
F009C404: 912a2002                 sll     %o0, 2, %o0
F009C408: b4024008                 add     %o1, %o0, %i2
F009C40C: d2068000                 ld      [%i2], %o1
F009C410: 900a6003                 and     %o1, 3, %o0
F009C414: 80a22002                 cmp     %o0, 2
F009C418: 12800023                 bne     loc_F009C4A4
F009C41C: d407a044                 ld      [%fp+arg_44], %o2
F009C420: d00f600d                 ldub    [%i5+0xD], %o0
F009C424: 80a22003                 cmp     %o0, 3
F009C428: 12800008                 bne     loc_F009C448
F009C42C: 80a22002                 cmp     %o0, 2
F009C430: 91326008                 srl     %o1, 8, %o0
F009C434: 80a20010                 cmp     %o0, %l0
F009C438: 12800017                 bne     loc_F009C494
F009C43C: 113c045e                 sethi   -0xFEE8800, %o0
F009C440: 10800058                 ba      loc_F009C5A0
F009C444: 13000004                 sethi   0x1000, %o1
F009C448: 1280000b                 bne     loc_F009C474
F009C44C: 93326008                 srl     %o1, 8, %o1
F009C450: 113fff00                 sethi   -0x40000, %o0
F009C454: 900e4008                 and     %i1, %o0, %o0
F009C458: 9132200c                 srl     %o0, 12, %o0
F009C45C: 900a001b                 and     %o0, %i3, %o0
F009C460: 80a24008                 cmp     %o1, %o0
F009C464: 1280000c                 bne     loc_F009C494
F009C468: 113c045e                 sethi   -0xFEE8800, %o0
F009C46C: 1080004d                 ba      loc_F009C5A0
F009C470: 13000004                 sethi   0x1000, %o1
F009C474: 113fc000                 sethi   -0x1000000, %o0
F009C478: 900e4008                 and     %i1, %o0, %o0
F009C47C: 9132200c                 srl     %o0, 12, %o0
F009C480: 900a001b                 and     %o0, %i3, %o0
F009C484: 80a24008                 cmp     %o1, %o0
F009C488: 02800046                 be      loc_F009C5A0
F009C48C: 13000004                 sethi   0x1000, %o1
F009C490: 113c045e                 sethi   -0xFEE8800, %o0! char *
F009C494: 7ffde337                 call    _panic
F009C498: 90122350                 bset    0x350, %o0
F009C49C: 10800041                 ba      loc_F009C5A0
F009C4A0: 13000004                 sethi   0x1000, %o1
F009C4A4: d0046100                 ld      [%l1+0x100], %o0
F009C4A8: 9210001c                 mov     %i4, %o1
F009C4AC: d6074000                 ld      [%i5], %o3
F009C4B0: 9532a00a                 srl     %o2, 10, %o2
F009C4B4: 940aa0fc                 and     %o2, 0xFC, %o2
F009C4B8: b402c00a                 add     %o3, %o2, %i2
F009C4BC: 952c2008                 sll     %l0, 8, %o2
F009C4C0: 400013fa                 call    _vm_to_srmmu_prot
F009C4C4: d427bff4                 st      %o2, [%fp+var_C]
F009C4C8: 9210001a                 mov     %i2, %o1
F009C4CC: 960a2007                 and     %o0, 7, %o3
F009C4D0: 972ae002                 sll     %o3, 2, %o3
F009C4D4: d007bff4                 ld      [%fp+var_C], %o0
F009C4D8: 98102000                 mov     0, %o4
F009C4DC: d407a044                 ld      [%fp+arg_44], %o2
F009C4E0: 900a3f63                 and     %o0, -0x9D, %o0
F009C4E4: 9012000b                 bset    %o3, %o0
F009C4E8: 90120012                 bset    %l2, %o0
F009C4EC: 900a3ffc                 and     %o0, -4, %o0
F009C4F0: 90122002                 bset    2, %o0
F009C4F4: d027bff4                 st      %o0, [%fp+var_C]
F009C4F8: 7fffe4a4                 call    _mmu_writepte
F009C4FC: 96102003                 mov     3, %o3
F009C500: d407a044                 ld      [%fp+arg_44], %o2
F009C504: 113c04d0                 sethi   %hi(_page_mask), %o0
F009C508: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F009C50C: 92028008                 add     %o2, %o0, %o1
F009C510: 902a4008                 andn    %o1, %o0, %o0
F009C514: 80a28008                 cmp     %o2, %o0
F009C518: 12800018                 bne     loc_F009C578
F009C51C: 113c045e                 sethi   -0xFEE8800, %o0
F009C520: d00f600f                 ldub    [%i5+0xF], %o0
F009C524: 90022001                 inc     %o0
F009C528: d02f600f                 stb     %o0, [%i5+0xF]
F009C52C: d407a044                 ld      [%fp+arg_44], %o2
F009C530: 90102001                 mov     1, %o0
F009C534: 9532a00c                 srl     %o2, 12, %o2
F009C538: 9732a003                 srl     %o2, 3, %o3
F009C53C: 960ae004                 and     %o3, 4, %o3
F009C540: 9602c01d                 add     %o3, %i5, %o3
F009C544: 940aa01e                 and     %o2, 0x1E, %o2
F009C548: d202e010                 ld      [%o3+0x10], %o1
F009C54C: 912a000a                 sll     %o0, %o2, %o0
F009C550: d4046100                 ld      [%l1+0x100], %o2
F009C554: 92124008                 bset    %o0, %o1
F009C558: d222e010                 st      %o1, [%o3+0x10]
F009C55C: d002a020                 ld      [%o2+0x20], %o0
F009C560: d202a024                 ld      [%o2+0x24], %o1
F009C564: 90022001                 inc     %o0
F009C568: d022a020                 st      %o0, [%o2+0x20]
F009C56C: 92026001                 inc     %o1
F009C570: d222a024                 st      %o1, [%o2+0x24]
F009C574: 113c045e                 sethi   -0xFEE8800, %o0
F009C578: d0022308                 ld      [%o0+0x308], %o0
F009C57C: 80a22000                 cmp     %o0, 0
F009C580: 12800008                 bne     loc_F009C5A0
F009C584: 13000004                 sethi   0x1000, %o1
F009C588: d0046100                 ld      [%l1+0x100], %o0
F009C58C: fa27bff0                 st      %i5, [%fp+var_10]
F009C590: d407a044                 ld      [%fp+arg_44], %o2
F009C594: 40000264                 call    _pmap_gather_pte
F009C598: 9207bff0                 add     %fp, var_10, %o1
F009C59C: 13000004                 sethi   0x1000, %o1
F009C5A0: b2064009                 add     %i1, %o1, %i1
F009C5A4: d007a044                 ld      [%fp+arg_44], %o0
F009C5A8: a0042001                 inc     %l0
F009C5AC: 90020009                 add     %o0, %o1, %o0
F009C5B0: 80a20018                 cmp     %o0, %i0
F009C5B4: 0abfff78                 bcs     loc_F009C394
F009C5B8: d027a044                 st      %o0, [%fp+arg_44]
F009C5BC: 81c7e008                 ret
F009C5C0: 81e80000                 restore
