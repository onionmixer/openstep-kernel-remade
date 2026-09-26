F00F27CC: 9de3bf90                 save    %sp, -0x70, %sp
F00F27D0: 90100018                 mov     %i0, %o0
F00F27D4: 133c03f4921260c8         set     aObjc, %o1! "__OBJC"
F00F27DC: 153c03f49412a1f8         set     aProtocol, %o2! "__protocol"
F00F27E4: 7ffffd00                 call    _getsectdatafromheaderinfo
F00F27E8: 9607bff4                 add     %fp, var_C, %o3
F00F27EC: a6920000                 orcc    %o0, %g0, %l3
F00F27F0: 02800042                 be      locret_F00F28F8
F00F27F4: a4102000                 mov     0, %l2
F00F27F8: d007bff4                 ld      [%fp+var_C], %o0
F00F27FC: 7ffc4f81                 call    _udiv
F00F2800: 92102014                 mov     0x14, %o1
F00F2804: 80a48008                 cmp     %l2, %o0
F00F2808: 1a800032                 bcc     loc_F00F28D0
F00F280C: 912ca002                 sll     %l2, 2, %o0
F00F2810: 90020012                 add     %o0, %l2, %o0
F00F2814: 912a2002                 sll     %o0, 2, %o0
F00F2818: 9004c008                 add     %l3, %o0, %o0
F00F281C: d002200c                 ld      [%o0+0xC], %o0
F00F2820: 80a22000                 cmp     %o0, 0
F00F2824: 22800013                 be,a    loc_F00F2870
F00F2828: 912ca002                 sll     %l2, 2, %o0
F00F282C: a2100008                 mov     %o0, %l1
F00F2830: 1080000b                 ba      loc_F00F285C
F00F2834: b0102000                 mov     0, %i0
F00F2838: a0022004                 add     %o0, 4, %l0
F00F283C: 400003aa                 call    __sel_registerName
F00F2840: d0044010                 ld      [%l1+%l0], %o0
F00F2844: 92100008                 mov     %o0, %o1
F00F2848: d0044010                 ld      [%l1+%l0], %o0
F00F284C: 80a20009                 cmp     %o0, %o1
F00F2850: 32800002                 bne,a   loc_F00F2858
F00F2854: d2244010                 st      %o1, [%l1+%l0]
F00F2858: b0062001                 inc     %i0
F00F285C: d0044000                 ld      [%l1], %o0
F00F2860: 80a60008                 cmp     %i0, %o0
F00F2864: 0abffff5                 bcs     loc_F00F2838
F00F2868: 912e2003                 sll     %i0, 3, %o0
F00F286C: 912ca002                 sll     %l2, 2, %o0
F00F2870: 90020012                 add     %o0, %l2, %o0
F00F2874: 912a2002                 sll     %o0, 2, %o0
F00F2878: 9004c008                 add     %l3, %o0, %o0
F00F287C: d0022010                 ld      [%o0+0x10], %o0
F00F2880: 80a22000                 cmp     %o0, 0
F00F2884: 02800011                 be      loc_F00F28C8
F00F2888: a2100008                 mov     %o0, %l1
F00F288C: 1080000b                 ba      loc_F00F28B8
F00F2890: b0102000                 mov     0, %i0
F00F2894: a0022004                 add     %o0, 4, %l0
F00F2898: 40000393                 call    __sel_registerName
F00F289C: d0044010                 ld      [%l1+%l0], %o0
F00F28A0: 92100008                 mov     %o0, %o1
F00F28A4: d0044010                 ld      [%l1+%l0], %o0
F00F28A8: 80a20009                 cmp     %o0, %o1
F00F28AC: 32800002                 bne,a   loc_F00F28B4
F00F28B0: d2244010                 st      %o1, [%l1+%l0]
F00F28B4: b0062001                 inc     %i0
F00F28B8: d0044000                 ld      [%l1], %o0
F00F28BC: 80a60008                 cmp     %i0, %o0
F00F28C0: 0abffff5                 bcs     loc_F00F2894
F00F28C4: 912e2003                 sll     %i0, 3, %o0
F00F28C8: 10bfffcc                 ba      loc_F00F27F8
F00F28CC: a404a001                 inc     %l2
F00F28D0: 213c0506                 sethi   -0xFEBE800, %l0
F00F28D4: 233c0506                 sethi   -0xFEBE800, %l1
F00F28D8: d007bff4                 ld      [%fp+var_C], %o0
F00F28DC: 7ffc4f49                 call    _udiv
F00F28E0: 92102014                 mov     0x14, %o1
F00F28E4: 96100008                 mov     %o0, %o3
F00F28E8: d00422f8                 ld      [%l0+0x2F8], %o0! id
F00F28EC: d20461fc                 ld      [%l1+0x1FC], %o1! SEL
F00F28F0: 7ffffbe0                 call    _objc_msgSend
F00F28F4: 94100013                 mov     %l3, %o2
F00F28F8: 81c7e008                 ret
F00F28FC: 81e80000                 restore
