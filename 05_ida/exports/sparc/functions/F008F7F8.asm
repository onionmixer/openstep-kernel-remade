F008F7F8: 9de3bf78                 save    %sp, -0x88, %sp
F008F7FC: 90100018                 mov     %i0, %o0! id
F008F800: 133c0504                 sethi   %hi(paIsshared), %o1
F008F804: d2026120                 ld      [%o1+%lo(paIsshared)], %o1! SEL
F008F808: 4001881a                 call    _objc_msgSend
F008F80C: 9410001c                 mov     %i4, %o2
F008F810: ae100008                 mov     %o0, %l7
F008F814: 90100018                 mov     %i0, %o0! id
F008F818: 133c0504                 sethi   %hi(paResourcesforke), %o1
F008F81C: d2026124                 ld      [%o1+%lo(paResourcesforke)], %o1! SEL
F008F820: 40018814                 call    _objc_msgSend
F008F824: 9410001c                 mov     %i4, %o2
F008F828: aa100008                 mov     %o0, %l5
F008F82C: 113c0506                 sethi   %hi(paList), %o0
F008F830: e4022288                 ld      [%o0+%lo(paList)], %l2
F008F834: 113c0503                 sethi   %hi(paAlloc), %o0
F008F838: e20223f0                 ld      [%o0+%lo(paAlloc)], %l1
F008F83C: 90100012                 mov     %l2, %o0! id
F008F840: 4001880c                 call    _objc_msgSend
F008F844: 92100011                 mov     %l1, %o1
F008F848: 133c0504                 sethi   %hi(paInit), %o1! SEL
F008F84C: e002602c                 ld      [%o1+%lo(paInit)], %l0
F008F850: a6102000                 mov     0, %l3
F008F854: 40018807                 call    _objc_msgSend
F008F858: 92100010                 mov     %l0, %o1! SEL
F008F85C: a8100008                 mov     %o0, %l4
F008F860: 90100012                 mov     %l2, %o0! id
F008F864: 40018803                 call    _objc_msgSend
F008F868: 92100011                 mov     %l1, %o1! SEL
F008F86C: 40018801                 call    _objc_msgSend
F008F870: 92100010                 mov     %l0, %o1
F008F874: 80a4c01b                 cmp     %l3, %i3
F008F878: 1a800040                 bcc     loc_F008F978
F008F87C: ac100008                 mov     %o0, %l6
F008F880: a407bfe0                 add     %fp, var_20, %l2
F008F884: 912de018                 sll     %l7, 24, %o0
F008F888: b33a2018                 sra     %o0, 24, %i1
F008F88C: 2f3c0504                 sethi   %hi(paAddobject), %l7
F008F890: e205e0a4                 ld      [%l7+%lo(paAddobject)], %l1
F008F894: d6068000                 ld      [%i2], %o3
F008F898: 90100015                 mov     %l5, %o0
F008F89C: d627bfe8                 st      %o3, [%fp+var_18]
F008F8A0: d406a004                 ld      [%i2+4], %o2
F008F8A4: 92100012                 mov     %l2, %o1
F008F8A8: d427bfec                 st      %o2, [%fp+var_14]
F008F8AC: d627bfe0                 st      %o3, [%fp+var_20]
F008F8B0: 7fffffae                 call    sub_F008F768
F008F8B4: d427bfe4                 st      %o2, [%fp+var_1C]
F008F8B8: a0920000                 orcc    %o0, %g0, %l0
F008F8BC: 02800004                 be      loc_F008F8CC
F008F8C0: 90100014                 mov     %l4, %o0
F008F8C4: 10800027                 ba      loc_F008F960
F008F8C8: d205e0a4                 ld      [%l7+0xA4], %o1
F008F8CC: d006201c                 ld      [%i0+0x1C], %o0! id
F008F8D0: 133c0504                 sethi   %hi(paLookupresource), %o1
F008F8D4: d2026128                 ld      [%o1+%lo(paLookupresource)], %o1! SEL
F008F8D8: 400187e6                 call    _objc_msgSend
F008F8DC: 9410001c                 mov     %i4, %o2
F008F8E0: 94920000                 orcc    %o0, %g0, %o2
F008F8E4: 0280004f                 be      loc_F008FA20
F008F8E8: 80a66000                 cmp     %i1, 0
F008F8EC: 0280000a                 be      loc_F008F914
F008F8F0: 113c0504                 sethi   %hi(paSharerange), %o0
F008F8F4: d2022134                 ld      [%o0+%lo(paSharerange)], %o1
F008F8F8: d807bfe8                 ld      [%fp+var_18], %o4
F008F8FC: d607bfec                 ld      [%fp+var_14], %o3
F008F900: 9010000a                 mov     %o2, %o0
F008F904: 94100012                 mov     %l2, %o2
F008F908: d827bfe0                 st      %o4, [%fp+var_20]
F008F90C: 1080000a                 ba      loc_F008F934
F008F910: d627bfe4                 st      %o3, [%fp+var_1C]
F008F914: 113c0504                 sethi   %hi(paReserverange), %o0
F008F918: d2022138                 ld      [%o0+%lo(paReserverange)], %o1! SEL
F008F91C: d807bfe8                 ld      [%fp+var_18], %o4
F008F920: d607bfec                 ld      [%fp+var_14], %o3
F008F924: 9010000a                 mov     %o2, %o0! id
F008F928: 9407bfd8                 add     %fp, var_28, %o2
F008F92C: d827bfd8                 st      %o4, [%fp+var_28]
F008F930: d627bfdc                 st      %o3, [%fp+var_24]
F008F934: 400187cf                 call    _objc_msgSend
F008F938: 01000000                 nop
F008F93C: a0920000                 orcc    %o0, %g0, %l0
F008F940: 02800039                 be      loc_F008FA24
F008F944: 113c0504                 sethi   -0xFEBF000, %o0
F008F948: 90100016                 mov     %l6, %o0! id
F008F94C: 92100011                 mov     %l1, %o1! SEL
F008F950: 400187c8                 call    _objc_msgSend
F008F954: 94100010                 mov     %l0, %o2
F008F958: 90100014                 mov     %l4, %o0! id
F008F95C: 92100011                 mov     %l1, %o1! SEL
F008F960: 400187c4                 call    _objc_msgSend
F008F964: 94100010                 mov     %l0, %o2
F008F968: a604e001                 inc     %l3
F008F96C: 80a4c01b                 cmp     %l3, %i3
F008F970: 0abfffc9                 bcs     loc_F008F894
F008F974: b406a008                 inc     8, %i2
F008F978: a6102000                 mov     0, %l3
F008F97C: 353c0504                 sethi   -0xFEBF000, %i2
F008F980: 2f3c0504                 sethi   -0xFEBF000, %l7
F008F984: 253c0504                 sethi   -0xFEBF000, %l2
F008F988: 233c0503                 sethi   -0xFEBF400, %l1
F008F98C: d206a0b8                 ld      [%i2+0xB8], %o1! SEL
F008F990: 400187b8                 call    _objc_msgSend
F008F994: 90100015                 mov     %l5, %o0
F008F998: 80a4c008                 cmp     %l3, %o0
F008F99C: 1a800012                 bcc     loc_F008F9E4
F008F9A0: 90100015                 mov     %l5, %o0! id
F008F9A4: d205e0c8                 ld      [%l7+0xC8], %o1! SEL
F008F9A8: 400187b2                 call    _objc_msgSend
F008F9AC: 94100013                 mov     %l3, %o2
F008F9B0: a0100008                 mov     %o0, %l0
F008F9B4: 90100014                 mov     %l4, %o0! id
F008F9B8: d204a0a0                 ld      [%l2+0xA0], %o1! SEL
F008F9BC: 400187ad                 call    _objc_msgSend
F008F9C0: 94100010                 mov     %l0, %o2
F008F9C4: 80a23fff                 cmp     %o0, -1
F008F9C8: 32bffff1                 bne,a   loc_F008F98C
F008F9CC: a604e001                 inc     %l3
F008F9D0: d20463fc                 ld      [%l1+0x3FC], %o1! SEL
F008F9D4: 400187a7                 call    _objc_msgSend
F008F9D8: 90100010                 mov     %l0, %o0
F008F9DC: 10bfffec                 ba      loc_F008F98C
F008F9E0: a604e001                 inc     %l3
F008F9E4: 113c0504                 sethi   %hi(paEmpty), %o0! id
F008F9E8: d20220fc                 ld      [%o0+%lo(paEmpty)], %o1! SEL
F008F9EC: 400187a1                 call    _objc_msgSend
F008F9F0: 90100015                 mov     %l5, %o0
F008F9F4: 90100018                 mov     %i0, %o0! id
F008F9F8: 94100014                 mov     %l4, %o2
F008F9FC: 133c0504                 sethi   %hi(paSetresourcesFo), %o1
F008FA00: d2026118                 ld      [%o1+%lo(paSetresourcesFo)], %o1! SEL
F008FA04: 4001879b                 call    _objc_msgSend
F008FA08: 9610001c                 mov     %i4, %o3
F008FA0C: 113c0503                 sethi   %hi(paFree), %o0! id
F008FA10: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F008FA14: 40018797                 call    _objc_msgSend
F008FA18: 90100016                 mov     %l6, %o0
F008FA1C: 3080000d                 ba,a    locret_F008FA50
F008FA20: 113c0504                 sethi   -0xFEBF000, %o0! id
F008FA24: d20220cc                 ld      [%o0+0xCC], %o1! SEL
F008FA28: 40018792                 call    _objc_msgSend
F008FA2C: 90100016                 mov     %l6, %o0! id
F008FA30: 133c0503                 sethi   %hi(paFree), %o1! SEL
F008FA34: e00263fc                 ld      [%o1+%lo(paFree)], %l0
F008FA38: 4001878e                 call    _objc_msgSend
F008FA3C: 92100010                 mov     %l0, %o1! SEL
F008FA40: 90100014                 mov     %l4, %o0! id
F008FA44: 4001878b                 call    _objc_msgSend
F008FA48: 92100010                 mov     %l0, %o1
F008FA4C: b0102000                 mov     0, %i0
F008FA50: 81c7e008                 ret
F008FA54: 81e80000                 restore
