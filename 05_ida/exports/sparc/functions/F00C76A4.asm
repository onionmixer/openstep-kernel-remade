F00C76A4: 9de3bf78                 save    %sp, -0x88, %sp
F00C76A8: a8100018                 mov     %i0, %l4
F00C76AC: ac102000                 mov     0, %l6
F00C76B0: 90100014                 mov     %l4, %o0! id
F00C76B4: a4102000                 mov     0, %l2
F00C76B8: 133c0506                 sethi   %hi(paPhysicaldisk_0), %o1
F00C76BC: d2026164                 ld      [%o1+%lo(paPhysicaldisk_0)], %o1! SEL
F00C76C0: 4000a86c                 call    _objc_msgSend
F00C76C4: b8102000                 mov     0, %i4
F00C76C8: 133c0506                 sethi   %hi(paPhysicalblocks_0), %o1
F00C76CC: b6100008                 mov     %o0, %i3
F00C76D0: d2026160                 ld      [%o1+%lo(paPhysicalblocks_0)], %o1! SEL
F00C76D4: 4000a867                 call    _objc_msgSend
F00C76D8: 90100014                 mov     %l4, %o0
F00C76DC: a2100008                 mov     %o0, %l1
F00C76E0: 90100014                 mov     %l4, %o0! id
F00C76E4: 133c0506                 sethi   %hi(paChecksafeconfi), %o1
F00C76E8: 153c03eb                 sethi   %hi(aWritelabel), %o2! "writeLabel"
F00C76EC: d202615c                 ld      [%o1+%lo(paChecksafeconfi)], %o1! SEL
F00C76F0: 4000a860                 call    _objc_msgSend
F00C76F4: 9412a190                 bset    %lo(aWritelabel), %o2! "writeLabel"
F00C76F8: b0920000                 orcc    %o0, %g0, %i0
F00C76FC: 1280009f                 bne     locret_F00C7978
F00C7700: 113c0506                 sethi   %hi(paLocklogicaldis), %o0! id
F00C7704: d2022158                 ld      [%o0+%lo(paLocklogicaldis)], %o1! SEL
F00C7708: 4000a85a                 call    _objc_msgSend
F00C770C: 9010001b                 mov     %i3, %o0
F00C7710: 113c0504                 sethi   %hi(paIsformatted), %o0! id
F00C7714: d2022178                 ld      [%o0+%lo(paIsformatted)], %o1! SEL
F00C7718: 4000a856                 call    _objc_msgSend
F00C771C: 9010001b                 mov     %i3, %o0
F00C7720: 912a2018                 sll     %o0, 24, %o0
F00C7724: 80a22000                 cmp     %o0, 0
F00C7728: 2280008b                 be,a    loc_F00C7954
F00C772C: b0103d36                 mov     -0x2CA, %i0
F00C7730: 113c0506                 sethi   %hi(paFreepartitions), %o0! id
F00C7734: d2022154                 ld      [%o0+%lo(paFreepartitions)], %o1! SEL
F00C7738: 4000a84e                 call    _objc_msgSend
F00C773C: 90100014                 mov     %l4, %o0
F00C7740: c02d21a8                 clrb    [%l4+0x1A8]
F00C7744: 11139956                 sethi   0x4E655800, %o0
F00C7748: d2068000                 ld      [%i2], %o1
F00C774C: 90122054                 bset    0x54, %o0 ! 'T'
F00C7750: 80a24008                 cmp     %o1, %o0
F00C7754: 02800008                 be      loc_F00C7774
F00C7758: 11000007                 sethi   0x1C00, %o0
F00C775C: 11191b1590122232         set     0x646C5632, %o0
F00C7764: 80a24008                 cmp     %o1, %o0
F00C7768: 3280000a                 bne,a   loc_F00C7790
F00C776C: 11191b15                 sethi   0x646C5400, %o0
F00C7770: 11000007                 sethi   0x1C00, %o0
F00C7774: b2122048                 or      %o0, 0x48, %i1
F00C7778: 1100000790122058         set     0x1C58, %o0
F00C7780: a0068008                 add     %i2, %o0, %l0
F00C7784: 11000007                 sethi   0x1C00, %o0
F00C7788: 10800014                 ba      loc_F00C77D8
F00C778C: ae122046                 or      %o0, 0x46, %l7
F00C7790: 90122233                 bset    0x233, %o0
F00C7794: 80a24008                 cmp     %o1, %o0
F00C7798: 0280000d                 be      loc_F00C77CC
F00C779C: 213c03eb                 sethi   %hi(aSWritelabelBad), %l0! "%s writeLabel: BAD LABEL\n"
F00C77A0: 90100014                 mov     %l4, %o0! id
F00C77A4: 133c0504                 sethi   %hi(paName), %o1
F00C77A8: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C77AC: b0103d3e                 mov     -0x2C2, %i0
F00C77B0: 4000a830                 call    _objc_msgSend
F00C77B4: a01421a0                 bset    %lo(aSWritelabelBad), %l0! "%s writeLabel: BAD LABEL\n"
F00C77B8: 92100008                 mov     %o0, %o1
F00C77BC: 7ffffa4e                 call    _IOLog
F00C77C0: 90100010                 mov     %l0, %o0
F00C77C4: 10800065                 ba      loc_F00C7958
F00C77C8: 113c0506                 sethi   -0xFEBE800, %o0
F00C77CC: b2102230                 mov     0x230, %i1
F00C77D0: a006a240                 add     %i2, 0x240, %l0
F00C77D4: ae10222e                 mov     0x22E, %l7
F00C77D8: 7ffffa41                 call    _IOGetTimestamp
F00C77DC: 9007bfe8                 add     %fp, var_18, %o0
F00C77E0: c026a004                 clr     [%i2+4]
F00C77E4: 1100000790122047         set     0x1C47, %o0
F00C77EC: 90044008                 add     %l1, %o0, %o0
F00C77F0: d41fbfe8                 ldd     [%fp+var_18], %o2
F00C77F4: 92100011                 mov     %l1, %o1
F00C77F8: d626a028                 st      %o3, [%i2+0x28]
F00C77FC: 7ffcfb81                 call    _udiv
F00C7800: c0340000                 clrh    [%l0]
F00C7804: aa100008                 mov     %o0, %l5
F00C7808: 7ffcfb3e                 call    _umul
F00C780C: 92100011                 mov     %l1, %o1
F00C7810: 133c04d0                 sethi   %hi(_page_mask), %o1
F00C7814: d20260d8                 ld      [%o1+%lo(_page_mask)], %o1
F00C7818: a6100008                 mov     %o0, %l3
F00C781C: 9004c009                 add     %l3, %o1, %o0
F00C7820: b82a0009                 andn    %o0, %o1, %i4
F00C7824: 7ffff9c3                 call    _IOMalloc
F00C7828: 9010001c                 mov     %i4, %o0
F00C782C: a4100008                 mov     %o0, %l2
F00C7830: 9010001a                 mov     %i2, %o0
F00C7834: 400065c1                 call    _put_disk_label
F00C7838: 92100012                 mov     %l2, %o1
F00C783C: 90100012                 mov     %l2, %o0
F00C7840: 400066b4                 call    _checksum16
F00C7844: 93366001                 srl     %i1, 1, %o1
F00C7848: d0348017                 sth     %o0, [%l2+%l7]
F00C784C: 90100012                 mov     %l2, %o0
F00C7850: 400066c7                 call    _check_label
F00C7854: 92102000                 mov     0, %o1
F00C7858: a2920000                 orcc    %o0, %g0, %l1
F00C785C: 0280000e                 be      loc_F00C7894
F00C7860: 90100014                 mov     %l4, %o0! id
F00C7864: 133c0504                 sethi   %hi(paName), %o1
F00C7868: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C786C: b0103d3e                 mov     -0x2C2, %i0
F00C7870: 213c03eb                 sethi   %hi(aSWritelabelBad_0), %l0! "%s writeLabel: BAD LABEL : %s\n"
F00C7874: 4000a7ff                 call    _objc_msgSend
F00C7878: a01421c0                 bset    %lo(aSWritelabelBad_0), %l0! "%s writeLabel: BAD LABEL : %s\n"
F00C787C: 92100008                 mov     %o0, %o1
F00C7880: 90100010                 mov     %l0, %o0
F00C7884: 7ffffa1c                 call    _IOLog
F00C7888: 94100011                 mov     %l1, %o2
F00C788C: 10800033                 ba      loc_F00C7958
F00C7890: 113c0506                 sethi   -0xFEBE800, %o0
F00C7894: a2102000                 mov     0, %l1
F00C7898: 80a46003                 cmp     %l1, 3
F00C789C: 14800020                 bg      loc_F00C791C
F00C78A0: 80a5a000                 cmp     %l6, 0
F00C78A4: 2f3c0506                 sethi   -0xFEBE800, %l7
F00C78A8: 90100011                 mov     %l1, %o0
F00C78AC: 7ffcfb15                 call    _umul
F00C78B0: 92100015                 mov     %l5, %o1
F00C78B4: a0100008                 mov     %o0, %l0
F00C78B8: 40000a62                 call    _IOVmTaskSelf
F00C78BC: e024a004                 st      %l0, [%l2+4]
F00C78C0: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F00C78C4: 9010001b                 mov     %i3, %o0! id
F00C78C8: d205e1b8                 ld      [%l7+0x1B8], %o1! SEL
F00C78CC: 94100010                 mov     %l0, %o2
F00C78D0: 96100013                 mov     %l3, %o3
F00C78D4: 98100012                 mov     %l2, %o4
F00C78D8: 4000a7e6                 call    _objc_msgSend
F00C78DC: 9a07bfe4                 add     %fp, var_1C, %o5
F00C78E0: b0920000                 orcc    %o0, %g0, %i0
F00C78E4: 12800007                 bne     loc_F00C7900
F00C78E8: 80a63bb2                 cmp     %i0, -0x44E
F00C78EC: d007bfe4                 ld      [%fp+var_1C], %o0
F00C78F0: 80a20013                 cmp     %o0, %l3
F00C78F4: 22800002                 be,a    loc_F00C78FC
F00C78F8: ac05a001                 inc     %l6
F00C78FC: 80a63bb2                 cmp     %i0, -0x44E
F00C7900: 02800007                 be      loc_F00C791C
F00C7904: 80a5a000                 cmp     %l6, 0
F00C7908: a2046001                 inc     %l1
F00C790C: 80a46003                 cmp     %l1, 3
F00C7910: 04bfffea                 ble     loc_F00C78B8
F00C7914: a0040015                 add     %l0, %l5, %l0
F00C7918: 80a5a000                 cmp     %l6, 0
F00C791C: 12800007                 bne     loc_F00C7938
F00C7920: 90102001                 mov     1, %o0
F00C7924: 80a63bb2                 cmp     %i0, -0x44E
F00C7928: 2280000c                 be,a    loc_F00C7958
F00C792C: 113c0506                 sethi   -0xFEBE800, %o0
F00C7930: 10800009                 ba      loc_F00C7954
F00C7934: b0103d36                 mov     -0x2CA, %i0
F00C7938: d02d21a8                 stb     %o0, [%l4+0x1A8]
F00C793C: b0102000                 mov     0, %i0
F00C7940: 90100014                 mov     %l4, %o0! id
F00C7944: 133c0506                 sethi   %hi(paProbelabel), %o1
F00C7948: d2026168                 ld      [%o1+%lo(paProbelabel)], %o1! SEL
F00C794C: 4000a7c9                 call    _objc_msgSend
F00C7950: 9410001a                 mov     %i2, %o2
F00C7954: 113c0506                 sethi   -0xFEBE800, %o0! id
F00C7958: d2022150                 ld      [%o0+0x150], %o1! SEL
F00C795C: 4000a7c5                 call    _objc_msgSend
F00C7960: 9010001b                 mov     %i3, %o0
F00C7964: 80a4a000                 cmp     %l2, 0
F00C7968: 02800004                 be      locret_F00C7978
F00C796C: 90100012                 mov     %l2, %o0
F00C7970: 7ffff975                 call    _IOFree
F00C7974: 9210001c                 mov     %i4, %o1
F00C7978: 81c7e008                 ret
F00C797C: 81e80000                 restore
