F00C5874: 9de3bf88                 save    %sp, -0x78, %sp
F00C5878: a8102000                 mov     0, %l4
F00C587C: 9010001a                 mov     %i2, %o0
F00C5880: 7ffffbc8                 call    sub_F00C47A0
F00C5884: 9207bfec                 add     %fp, var_14, %o1
F00C5888: 80a22000                 cmp     %o0, 0
F00C588C: 32800005                 bne,a   loc_F00C58A0
F00C5890: 113c0504                 sethi   -0xFEBF000, %o0
F00C5894: d007bfec                 ld      [%fp+var_14], %o0
F00C5898: f6222010                 st      %i3, [%o0+0x10]
F00C589C: 113c0504                 sethi   -0xFEBF000, %o0! id
F00C58A0: d202233c                 ld      [%o0+0x33C], %o1! SEL
F00C58A4: 4000aff3                 call    _objc_msgSend
F00C58A8: 9010001a                 mov     %i2, %o0
F00C58AC: 80a22001                 cmp     %o0, 1
F00C58B0: 22800008                 be,a    loc_F00C58D0
F00C58B4: 113c0504                 sethi   -0xFEBF000, %o0! id
F00C58B8: 0a800048                 bcs     loc_F00C59D8
F00C58BC: 80a22002                 cmp     %o0, 2
F00C58C0: 02800047                 be      loc_F00C59DC
F00C58C4: 133c0504                 sethi   -0xFEBF000, %o1
F00C58C8: 10800062                 ba      loc_F00C5A50
F00C58CC: 80a00014                 cmp     %g0, %l4
F00C58D0: d2022204                 ld      [%o0+0x204], %o1! SEL
F00C58D4: 4000afe7                 call    _objc_msgSend
F00C58D8: 9010001a                 mov     %i2, %o0
F00C58DC: a4920000                 orcc    %o0, %g0, %l2
F00C58E0: 02800007                 be      loc_F00C58FC
F00C58E4: 9010001a                 mov     %i2, %o0
F00C58E8: d0048000                 ld      [%l2], %o0
F00C58EC: 80a22000                 cmp     %o0, 0
F00C58F0: 12800008                 bne     loc_F00C5910
F00C58F4: a2102000                 mov     0, %l1
F00C58F8: 9010001a                 mov     %i2, %o0
F00C58FC: 133c0504                 sethi   %hi(paName), %o1
F00C5900: d2026008                 ld      [%o1+%lo(paName)], %o1
F00C5904: 213c03ea                 sethi   %hi(aLoadedClassSRe), %l0! "Loaded class %s returns nil for +requir"...
F00C5908: 10800043                 ba      loc_F00C5A14
F00C590C: a01421f8                 bset    %lo(aLoadedClassSRe), %l0! "Loaded class %s returns nil for +requir"...
F00C5910: 273c0504                 sethi   -0xFEBF000, %l3
F00C5914: 90100011                 mov     %l1, %o0
F00C5918: 7ffffb53                 call    sub_F00C4664
F00C591C: 9207bfe8                 add     %fp, var_18, %o1
F00C5920: b0100008                 mov     %o0, %i0
F00C5924: 80a63d40                 cmp     %i0, -0x2C0
F00C5928: 02800028                 be      loc_F00C59C8
F00C592C: 01000000                 nop
F00C5930: 04800026                 ble     loc_F00C59C8
F00C5934: 01000000                 nop
F00C5938: 80a62000                 cmp     %i0, 0
F00C593C: 12800023                 bne     loc_F00C59C8
F00C5940: 80a63d40                 cmp     %i0, -0x2C0
F00C5944: d0048000                 ld      [%l2], %o0
F00C5948: 80a22000                 cmp     %o0, 0
F00C594C: 02800011                 be      loc_F00C5990
F00C5950: 113c0506                 sethi   -0xFEBE800, %o0
F00C5954: a0100012                 mov     %l2, %l0
F00C5958: d007bfe8                 ld      [%fp+var_18], %o0! id
F00C595C: d204e018                 ld      [%l3+0x18], %o1! SEL
F00C5960: 4000afc4                 call    _objc_msgSend
F00C5964: d4040000                 ld      [%l0], %o2
F00C5968: 912a2018                 sll     %o0, 24, %o0
F00C596C: 80a22000                 cmp     %o0, 0
F00C5970: 02800016                 be      loc_F00C59C8
F00C5974: 80a63d40                 cmp     %i0, -0x2C0
F00C5978: a0042004                 inc     4, %l0
F00C597C: d0040000                 ld      [%l0], %o0
F00C5980: 80a22000                 cmp     %o0, 0
F00C5984: 32bffff6                 bne,a   loc_F00C595C
F00C5988: d007bfe8                 ld      [%fp+var_18], %o0
F00C598C: 113c0506                 sethi   -0xFEBE800, %o0! id
F00C5990: d20221cc                 ld      [%o0+0x1CC], %o1! SEL
F00C5994: d407bfe8                 ld      [%fp+var_18], %o2
F00C5998: 4000afb6                 call    _objc_msgSend
F00C599C: 9010001b                 mov     %i3, %o0
F00C59A0: 9010001a                 mov     %i2, %o0! id
F00C59A4: 133c0504                 sethi   %hi(paProbe), %o1
F00C59A8: d2026368                 ld      [%o1+%lo(paProbe)], %o1! SEL
F00C59AC: 4000afb1                 call    _objc_msgSend
F00C59B0: 9410001b                 mov     %i3, %o2
F00C59B4: 912a2018                 sll     %o0, 24, %o0
F00C59B8: 80a22000                 cmp     %o0, 0
F00C59BC: 32800002                 bne,a   loc_F00C59C4
F00C59C0: a8102001                 mov     1, %l4
F00C59C4: 80a63d40                 cmp     %i0, -0x2C0
F00C59C8: 12bfffd3                 bne     loc_F00C5914
F00C59CC: a2046001                 inc     %l1
F00C59D0: 10800020                 ba      loc_F00C5A50
F00C59D4: 80a00014                 cmp     %g0, %l4
F00C59D8: 133c0504                 sethi   -0xFEBF000, %o1
F00C59DC: e0026368                 ld      [%o1+0x368], %l0
F00C59E0: 9010001a                 mov     %i2, %o0! id
F00C59E4: 133c0504                 sethi   %hi(paRespondsto), %o1
F00C59E8: d2026270                 ld      [%o1+%lo(paRespondsto)], %o1! SEL
F00C59EC: 4000afa1                 call    _objc_msgSend
F00C59F0: 94100010                 mov     %l0, %o2
F00C59F4: 912a2018                 sll     %o0, 24, %o0
F00C59F8: 80a22000                 cmp     %o0, 0
F00C59FC: 1280000d                 bne     loc_F00C5A30
F00C5A00: 9010001a                 mov     %i2, %o0! id
F00C5A04: 133c0504                 sethi   %hi(paName), %o1
F00C5A08: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C5A0C: 213c03eaa0142230         set     aAddloadedclass, %l0! "addLoadedClass: Class %s does not respo"...
F00C5A14: 4000af97                 call    _objc_msgSend
F00C5A18: 01000000                 nop
F00C5A1C: 92100008                 mov     %o0, %o1
F00C5A20: 400001b5                 call    _IOLog
F00C5A24: 90100010                 mov     %l0, %o0! id
F00C5A28: 1080000a                 ba      loc_F00C5A50
F00C5A2C: 80a00014                 cmp     %g0, %l4
F00C5A30: 92100010                 mov     %l0, %o1! SEL
F00C5A34: 4000af8f                 call    _objc_msgSend
F00C5A38: 9410001b                 mov     %i3, %o2
F00C5A3C: 912a2018                 sll     %o0, 24, %o0
F00C5A40: 80a22000                 cmp     %o0, 0
F00C5A44: 32800002                 bne,a   loc_F00C5A4C
F00C5A48: a8102001                 mov     1, %l4
F00C5A4C: 80a00014                 cmp     %g0, %l4
F00C5A50: b0403fff                 addc    %g0, -1, %i0
F00C5A54: b00e3d40                 and     %i0, -0x2C0, %i0
F00C5A58: 81c7e008                 ret
F00C5A5C: 81e80000                 restore
