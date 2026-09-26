F00BB6FC: 9de3bf90                 save    %sp, -0x70, %sp
F00BB700: a2100018                 mov     %i0, %l1
F00BB704: 113c04fd                 sethi   %hi(_kmId), %o0
F00BB708: d0022240                 ld      [%o0+%lo(_kmId)], %o0! id
F00BB70C: 153c04d4                 sethi   %hi(_cons_tp), %o2
F00BB710: e002a290                 ld      [%o2+%lo(_cons_tp)], %l0
F00BB714: 133c0504                 sethi   %hi(paKmopen), %o1
F00BB718: d2026208                 ld      [%o1+%lo(paKmopen)], %o1! SEL
F00BB71C: 4000d855                 call    _objc_msgSend
F00BB720: 94100019                 mov     %i1, %o2
F00BB724: b0920000                 orcc    %o0, %g0, %i0
F00BB728: 12800061                 bne     locret_F00BB8AC
F00BB72C: 113c02ef                 sethi   %hi(sub_F00BBDB4), %o0
F00BB730: c0242034                 clr     [%l0+0x34]
F00BB734: 901221b4                 bset    %lo(sub_F00BBDB4), %o0
F00BB738: d0242024                 st      %o0, [%l0+0x24]
F00BB73C: 90102002                 mov     2, %o0
F00BB740: d2042040                 ld      [%l0+0x40], %o1
F00BB744: 808a6004                 btst    4, %o1
F00BB748: 0280000c                 be      loc_F00BB778
F00BB74C: d02c2047                 stb     %o0, [%l0+0x47]
F00BB750: 808a6080                 btst    0x80, %o1
F00BB754: 02800015                 be      loc_F00BB7A8
F00BB758: 113c04cf                 sethi   %hi(_active_u), %o0
F00BB75C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00BB760: d002201c                 ld      [%o0+0x1C], %o0
F00BB764: d0522002                 ldsh    [%o0+2], %o0
F00BB768: 80a22000                 cmp     %o0, 0
F00BB76C: 0280000f                 be      loc_F00BB7A8
F00BB770: b0102010                 mov     0x10, %i0
F00BB774: 3080004e                 ba,a    locret_F00BB8AC
F00BB778: 7ffd6c55                 call    _ttychars
F00BB77C: 90100010                 mov     %l0, %o0
F00BB780: 110501c0901220d8         set     0x140700D8, %o0
F00BB788: d024203c                 st      %o0, [%l0+0x3C]
F00BB78C: 9010207f                 mov     0x7F, %o0
F00BB790: d02c204d                 stb     %o0, [%l0+0x4D]
F00BB794: 9010200d                 mov     0xD, %o0
F00BB798: d02c204a                 stb     %o0, [%l0+0x4A]
F00BB79C: d02c2049                 stb     %o0, [%l0+0x49]
F00BB7A0: 90102010                 mov     0x10, %o0
F00BB7A4: d0242040                 st      %o0, [%l0+0x40]
F00BB7A8: d24c2047                 ldsb    [%l0+0x47], %o1
F00BB7AC: 912c6010                 sll     %l1, 16, %o0
F00BB7B0: 952a6001                 sll     %o1, 1, %o2
F00BB7B4: 94028009                 add     %o2, %o1, %o2
F00BB7B8: 952aa004                 sll     %o2, 4, %o2
F00BB7BC: 133c042e921260cc         set     _linesw, %o1
F00BB7C4: d4028009                 ld      [%o2+%o1], %o2
F00BB7C8: 913a2010                 sra     %o0, 16, %o0
F00BB7CC: 9fc28000                 call    %o2
F00BB7D0: 92100010                 mov     %l0, %o1
F00BB7D4: b0920000                 orcc    %o0, %g0, %i0
F00BB7D8: 12800035                 bne     locret_F00BB8AC
F00BB7DC: 900c60ff                 and     %l1, 0xFF, %o0
F00BB7E0: 80a22002                 cmp     %o0, 2
F00BB7E4: 1280000d                 bne     loc_F00BB818
F00BB7E8: 80a62000                 cmp     %i0, 0
F00BB7EC: 113c0483                 sethi   %hi(_kbddev), %o0
F00BB7F0: d0522224                 ldsh    [%o0+%lo(_kbddev)], %o0
F00BB7F4: 920a20ff                 and     %o0, 0xFF, %o1
F00BB7F8: 952a6004                 sll     %o1, 4, %o2
F00BB7FC: 94028009                 add     %o2, %o1, %o2
F00BB800: 952aa003                 sll     %o2, 3, %o2
F00BB804: 133c04fb92126260         set     _zs_tty, %o1
F00BB80C: 40001534                 call    _kbdopen
F00BB810: 92028009                 add     %o2, %o1, %o1
F00BB814: b0920000                 orcc    %o0, %g0, %i0
F00BB818: 12800025                 bne     locret_F00BB8AC
F00BB81C: 133fbff8                 sethi   -0x1002000, %o1
F00BB820: c034205c                 clrh    [%l0+0x5C]
F00BB824: c034205e                 clrh    [%l0+0x5E]
F00BB828: c0342060                 clrh    [%l0+0x60]
F00BB82C: c0342062                 clrh    [%l0+0x62]
F00BB830: d00a6016                 ldub    [%o1+0x16], %o0
F00BB834: 80a22013                 cmp     %o0, 0x13
F00BB838: 1280001d                 bne     locret_F00BB8AC
F00BB83C: 01000000                 nop
F00BB840: d00a6050                 ldub    [%o1+0x50], %o0
F00BB844: 912a2018                 sll     %o0, 24, %o0
F00BB848: 933a2018                 sra     %o0, 24, %o1
F00BB84C: 912a6010                 sll     %o1, 16, %o0
F00BB850: 91322010                 srl     %o0, 16, %o0
F00BB854: 80a22009                 cmp     %o0, 9
F00BB858: 18800004                 bgu     loc_F00BB868
F00BB85C: 80a22078                 cmp     %o0, 0x78 ! 'x'
F00BB860: 10800004                 ba      loc_F00BB870
F00BB864: 92102050                 mov     0x50, %o1 ! 'P'
F00BB868: 38800002                 bgu,a   loc_F00BB870
F00BB86C: 92102078                 mov     0x78, %o1 ! 'x'
F00BB870: d234205e                 sth     %o1, [%l0+0x5E]
F00BB874: 113fbff8                 sethi   -0x1002000, %o0
F00BB878: d00a2051                 ldub    [%o0+0x51], %o0
F00BB87C: 912a2018                 sll     %o0, 24, %o0
F00BB880: 933a2018                 sra     %o0, 24, %o1
F00BB884: 912a6010                 sll     %o1, 16, %o0
F00BB888: 91322010                 srl     %o0, 16, %o0
F00BB88C: 80a22009                 cmp     %o0, 9
F00BB890: 18800004                 bgu     loc_F00BB8A0
F00BB894: 80a22030                 cmp     %o0, 0x30 ! '0'
F00BB898: 10800004                 ba      loc_F00BB8A8
F00BB89C: 92102022                 mov     0x22, %o1 ! '"'
F00BB8A0: 38800002                 bgu,a   loc_F00BB8A8
F00BB8A4: 92102030                 mov     0x30, %o1 ! '0'
F00BB8A8: d234205c                 sth     %o1, [%l0+0x5C]
F00BB8AC: 81c7e008                 ret
F00BB8B0: 81e80000                 restore
