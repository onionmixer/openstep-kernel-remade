F00CDA00: 9de3bf70                 save    %sp, -0x90, %sp
F00CDA04: 7fff11b6                 call    _sd_idmap
F00CDA08: a2102000                 mov     0, %l1
F00CDA0C: b8100008                 mov     %o0, %i4
F00CDA10: 9010001a                 mov     %i2, %o0! id
F00CDA14: 133c0506                 sethi   %hi(paDirectdevice), %o1
F00CDA18: d2026190                 ld      [%o1+%lo(paDirectdevice)], %o1! SEL
F00CDA1C: b6102000                 mov     0, %i3
F00CDA20: ac102000                 mov     0, %l6
F00CDA24: 313c04bb                 sethi   -0xFED1400, %i0
F00CDA28: 40008f92                 call    _objc_msgSend
F00CDA2C: 3b3c03ec                 sethi   -0xFF05000, %i5
F00CDA30: aa100008                 mov     %o0, %l5
F00CDA34: b207bff8                 add     %fp, var_8, %i1
F00CDA38: 90100015                 mov     %l5, %o0! id
F00CDA3C: 133c0504                 sethi   %hi(paNumberoftarget), %o1
F00CDA40: d20261f0                 ld      [%o1+%lo(paNumberoftarget)], %o1! SEL
F00CDA44: a12da018                 sll     %l6, 24, %l0
F00CDA48: 40008f8a                 call    _objc_msgSend
F00CDA4C: a13c2018                 sra     %l0, 24, %l0
F00CDA50: 80a40008                 cmp     %l0, %o0
F00CDA54: 16800073                 bge     loc_F00CDC20
F00CDA58: a6102000                 mov     0, %l3
F00CDA5C: a4102000                 mov     0, %l2
F00CDA60: a80da0ff                 and     %l6, 0xFF, %l4
F00CDA64: 80a46000                 cmp     %l1, 0
F00CDA68: 3280001a                 bne,a   loc_F00CDAD0
F00CDA6C: 90100015                 mov     %l5, %o0
F00CDA70: 113c0506                 sethi   %hi(paScsidisk_0), %o0
F00CDA74: d002229c                 ld      [%o0+%lo(paScsidisk_0)], %o0! id
F00CDA78: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00CDA7C: 40008f7d                 call    _objc_msgSend
F00CDA80: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00CDA84: a2100008                 mov     %o0, %l1
F00CDA88: 133c0504                 sethi   %hi(paSetname), %o1
F00CDA8C: d202624c                 ld      [%o1+%lo(paSetname)], %o1! SEL
F00CDA90: 40008f78                 call    _objc_msgSend
F00CDA94: 94176360                 or      %i5, 0x360, %o2
F00CDA98: 113c0505                 sethi   %hi(paInitresources), %o0! id
F00CDA9C: d20223e8                 ld      [%o0+%lo(paInitresources)], %o1! SEL
F00CDAA0: 40008f74                 call    _objc_msgSend
F00CDAA4: 90100011                 mov     %l1, %o0
F00CDAA8: 90100011                 mov     %l1, %o0! id
F00CDAAC: d60620ec                 ld      [%i0+0xEC], %o3
F00CDAB0: 133c0506                 sethi   %hi(paSetdevandidinf), %o1
F00CDAB4: d202619c                 ld      [%o1+%lo(paSetdevandidinf)], %o1! SEL
F00CDAB8: 952ae003                 sll     %o3, 3, %o2
F00CDABC: 9402800b                 add     %o2, %o3, %o2
F00CDAC0: 952aa002                 sll     %o2, 2, %o2
F00CDAC4: 40008f6b                 call    _objc_msgSend
F00CDAC8: 9407000a                 add     %i4, %o2, %o2
F00CDACC: 90100015                 mov     %l5, %o0! id
F00CDAD0: 133c0505                 sethi   %hi(paReservetargetL), %o1
F00CDAD4: d20263e4                 ld      [%o1+%lo(paReservetargetL)], %o1! SEL
F00CDAD8: 94100014                 mov     %l4, %o2
F00CDADC: b40ca0ff                 and     %l2, 0xFF, %i2
F00CDAE0: 9610001a                 mov     %i2, %o3
F00CDAE4: 40008f63                 call    _objc_msgSend
F00CDAE8: 98100011                 mov     %l1, %o4
F00CDAEC: 80a22000                 cmp     %o0, 0
F00CDAF0: 12800021                 bne     loc_F00CDB74
F00CDAF4: 9004a001                 add     %l2, 1, %o0
F00CDAF8: 90100011                 mov     %l1, %o0! id
F00CDAFC: 96100014                 mov     %l4, %o3
F00CDB00: 133c0505                 sethi   %hi(paScsidiskinitTa), %o1
F00CDB04: d20263e0                 ld      [%o1+%lo(paScsidiskinitTa)], %o1! SEL
F00CDB08: 9810001a                 mov     %i2, %o4
F00CDB0C: d40620ec                 ld      [%i0+0xEC], %o2
F00CDB10: 40008f58                 call    _objc_msgSend
F00CDB14: 9a100015                 mov     %l5, %o5
F00CDB18: a0920000                 orcc    %o0, %g0, %l0
F00CDB1C: 1280000c                 bne     loc_F00CDB4C
F00CDB20: 90100015                 mov     %l5, %o0
F00CDB24: 912ce002                 sll     %l3, 2, %o0
F00CDB28: 90020019                 add     %o0, %i1, %o0
F00CDB2C: e2223fd8                 st      %l1, [%o0-0x28]
F00CDB30: a604e001                 inc     %l3
F00CDB34: a2102000                 mov     0, %l1
F00CDB38: d00620ec                 ld      [%i0+0xEC], %o0! id
F00CDB3C: b6102001                 mov     1, %i3
F00CDB40: 90022001                 inc     %o0
F00CDB44: 1080000b                 ba      loc_F00CDB70
F00CDB48: d02620ec                 st      %o0, [%i0+0xEC]
F00CDB4C: 133c0505                 sethi   %hi(paReleasetargetL), %o1
F00CDB50: d20263dc                 ld      [%o1+%lo(paReleasetargetL)], %o1! SEL
F00CDB54: 94100014                 mov     %l4, %o2
F00CDB58: 9610001a                 mov     %i2, %o3
F00CDB5C: 40008f45                 call    _objc_msgSend
F00CDB60: 98100011                 mov     %l1, %o4
F00CDB64: 80a42002                 cmp     %l0, 2
F00CDB68: 0280000a                 be      loc_F00CDB90
F00CDB6C: 80a4e000                 cmp     %l3, 0
F00CDB70: 9004a001                 add     %l2, 1, %o0
F00CDB74: a4100008                 mov     %o0, %l2
F00CDB78: 912a2018                 sll     %o0, 24, %o0
F00CDB7C: 913a2018                 sra     %o0, 24, %o0
F00CDB80: 80a22007                 cmp     %o0, 7
F00CDB84: 04bfffb9                 ble     loc_F00CDA68
F00CDB88: 80a46000                 cmp     %l1, 0
F00CDB8C: 80a4e000                 cmp     %l3, 0
F00CDB90: 04800022                 ble     loc_F00CDC18
F00CDB94: a4102000                 mov     0, %l2
F00CDB98: 2f3c0506                 sethi   -0xFEBE800, %l7
F00CDB9C: 353c0504                 sethi   -0xFEBF000, %i2
F00CDBA0: 29000010                 sethi   0x4000, %l4
F00CDBA4: 053c0504                 sethi   %hi(paSetdevicekind), %g2
F00CDBA8: 912ca018                 sll     %l2, 24, %o0
F00CDBAC: 913a2016                 sra     %o0, 22, %o0
F00CDBB0: 90020019                 add     %o0, %i1, %o0
F00CDBB4: e0023fd8                 ld      [%o0-0x28], %l0
F00CDBB8: 94176360                 or      %i5, 0x360, %o2
F00CDBBC: d200a250                 ld      [%g2+%lo(paSetdevicekind)], %o1! SEL
F00CDBC0: 90100010                 mov     %l0, %o0! id
F00CDBC4: d6042188                 ld      [%l0+0x188], %o3
F00CDBC8: 05000020                 sethi   0x8000, %g2
F00CDBCC: 9612c002                 bset    %g2, %o3
F00CDBD0: 40008f28                 call    _objc_msgSend
F00CDBD4: d6242188                 st      %o3, [%l0+0x188]
F00CDBD8: 90100010                 mov     %l0, %o0! id
F00CDBDC: d205e1b4                 ld      [%l7+0x1B4], %o1! SEL
F00CDBE0: 40008f24                 call    _objc_msgSend
F00CDBE4: 94102001                 mov     1, %o2
F00CDBE8: d206a25c                 ld      [%i2+0x25C], %o1! SEL
F00CDBEC: 40008f21                 call    _objc_msgSend
F00CDBF0: 90100010                 mov     %l0, %o0
F00CDBF4: 9004a001                 add     %l2, 1, %o0
F00CDBF8: a4100008                 mov     %o0, %l2
F00CDBFC: 912a2018                 sll     %o0, 24, %o0
F00CDC00: 913a2018                 sra     %o0, 24, %o0
F00CDC04: d2042188                 ld      [%l0+0x188], %o1
F00CDC08: 80a20013                 cmp     %o0, %l3
F00CDC0C: 92124014                 bset    %l4, %o1
F00CDC10: 06bfffe5                 bl      loc_F00CDBA4
F00CDC14: d2242188                 st      %o1, [%l0+0x188]
F00CDC18: 10bfff88                 ba      loc_F00CDA38
F00CDC1C: ac05a001                 inc     %l6
F00CDC20: 80a46000                 cmp     %l1, 0
F00CDC24: 02800005                 be      locret_F00CDC38
F00CDC28: 113c0503                 sethi   %hi(paFree), %o0! id
F00CDC2C: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00CDC30: 40008f10                 call    _objc_msgSend
F00CDC34: 90100011                 mov     %l1, %o0
F00CDC38: 81c7e008                 ret
F00CDC3C: 91e8001b                 restore %g0, %i3, %o0
