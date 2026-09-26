F00C84B4: 9de3bf80                 save    %sp, -0x80, %sp
F00C84B8: a6102001                 mov     1, %l3
F00C84BC: 113c04ccb01220a0         set     dword_F01330A0, %i0
F00C84C4: 113c03e9ac122128         set     asc_F00FA528, %l6! ""
F00C84CC: 2b3c0506                 sethi   -0xFEBE800, %l5
F00C84D0: 40000095                 call    sub_F00C8724
F00C84D4: 213c04cc                 sethi   %hi(dword_F01330A0), %l0
F00C84D8: 7fff2f5b                 call    _vol_check_manual_poll
F00C84DC: e20420a0                 ld      [%l0+%lo(dword_F01330A0)], %l1
F00C84E0: 80a44018                 cmp     %l1, %i0
F00C84E4: 0280008b                 be      loc_F00C8710
F00C84E8: a8100008                 mov     %o0, %l4
F00C84EC: ae1420a0                 or      %l0, %lo(dword_F01330A0), %l7
F00C84F0: d0044000                 ld      [%l1], %o0! id
F00C84F4: 133c0504                 sethi   %hi(paName), %o1! SEL
F00C84F8: 4000a4de                 call    _objc_msgSend
F00C84FC: d2026008                 ld      [%o1+%lo(paName)], %o1
F00C8500: e4044000                 ld      [%l1], %l2
F00C8504: 113c0506                 sethi   %hi(paLastreadystate_0), %o0! id
F00C8508: d202217c                 ld      [%o0+%lo(paLastreadystate_0)], %o1! SEL
F00C850C: 4000a4d9                 call    _objc_msgSend
F00C8510: 90100012                 mov     %l2, %o0
F00C8514: a0920000                 orcc    %o0, %g0, %l0
F00C8518: 02800013                 be      loc_F00C8564
F00C851C: 133c0506                 sethi   %hi(paNeedsmanualpol), %o1! SEL
F00C8520: d0044000                 ld      [%l1], %o0! id
F00C8524: 4000a4d3                 call    _objc_msgSend
F00C8528: d2026148                 ld      [%o1+%lo(paNeedsmanualpol)], %o1
F00C852C: 912a2018                 sll     %o0, 24, %o0
F00C8530: 80a22000                 cmp     %o0, 0
F00C8534: 02800007                 be      loc_F00C8550
F00C8538: 80a52000                 cmp     %l4, 0
F00C853C: 32800006                 bne,a   loc_F00C8554
F00C8540: 113c0506                 sethi   -0xFEBE800, %o0
F00C8544: 80a42003                 cmp     %l0, 3
F00C8548: 12800007                 bne     loc_F00C8564
F00C854C: a6100010                 mov     %l0, %l3
F00C8550: 113c0506                 sethi   -0xFEBE800, %o0! id
F00C8554: d20221c8                 ld      [%o0+0x1C8], %o1! SEL
F00C8558: 4000a4c6                 call    _objc_msgSend
F00C855C: 90100012                 mov     %l2, %o0
F00C8560: a6100008                 mov     %o0, %l3
F00C8564: 80a42002                 cmp     %l0, 2
F00C8568: 18800006                 bgu     loc_F00C8580
F00C856C: 80a42001                 cmp     %l0, 1
F00C8570: 1a80002f                 bcc     loc_F00C862C
F00C8574: 80a4e000                 cmp     %l3, 0
F00C8578: 10800063                 ba      loc_F00C8704
F00C857C: e2046018                 ld      [%l1+0x18], %l1
F00C8580: 80a42003                 cmp     %l0, 3
F00C8584: 32800060                 bne,a   loc_F00C8704
F00C8588: e2046018                 ld      [%l1+0x18], %l1
F00C858C: 80a4e000                 cmp     %l3, 0
F00C8590: 1280001b                 bne     loc_F00C85FC
F00C8594: 90100012                 mov     %l2, %o0
F00C8598: d0046008                 ld      [%l1+8], %o0
F00C859C: 90023fff                 inc     -1, %o0
F00C85A0: 80a22000                 cmp     %o0, 0
F00C85A4: 12800057                 bne     loc_F00C8700
F00C85A8: d0246008                 st      %o0, [%l1+8]
F00C85AC: 113c0506                 sethi   %hi(paUnit_0), %o0! id
F00C85B0: d2022138                 ld      [%o0+%lo(paUnit_0)], %o1! SEL
F00C85B4: 4000a4af                 call    _objc_msgSend
F00C85B8: 90100012                 mov     %l2, %o0
F00C85BC: 9a100008                 mov     %o0, %o5
F00C85C0: 90102000                 mov     0, %o0
F00C85C4: 92102006                 mov     6, %o1
F00C85C8: 94102001                 mov     1, %o2
F00C85CC: d8046014                 ld      [%l1+0x14], %o4
F00C85D0: 96046010                 add     %l1, 0x10, %o3
F00C85D4: c023a05c                 clr     [%sp+0x80+var_24]
F00C85D8: ec23a060                 st      %l6, [%sp+0x80+var_20]
F00C85DC: ec23a064                 st      %l6, [%sp+0x80+var_1C]
F00C85E0: c023a068                 clr     [%sp+0x80+var_18]
F00C85E4: d623a06c                 st      %o3, [%sp+0x80+var_14]
F00C85E8: 7fff2d61                 call    _vol_panel_request
F00C85EC: 96102000                 mov     0, %o3
F00C85F0: 90102001                 mov     1, %o0! id
F00C85F4: 10800043                 ba      loc_F00C8700
F00C85F8: d02c600c                 stb     %o0, [%l1+0xC]
F00C85FC: d2056178                 ld      [%l5+0x178], %o1! SEL
F00C8600: 4000a49c                 call    _objc_msgSend
F00C8604: 94102002                 mov     2, %o2
F00C8608: d04c600c                 ldsb    [%l1+0xC], %o0
F00C860C: 80a22000                 cmp     %o0, 0
F00C8610: 2280003d                 be,a    loc_F00C8704
F00C8614: e2046018                 ld      [%l1+0x18], %l1
F00C8618: d0046010                 ld      [%l1+0x10], %o0
F00C861C: 7fff2dfa                 call    _vol_panel_remove
F00C8620: c02c600c                 clrb    [%l1+0xC]
F00C8624: 10800038                 ba      loc_F00C8704
F00C8628: e2046018                 ld      [%l1+0x18], %l1
F00C862C: 32800036                 bne,a   loc_F00C8704
F00C8630: e2046018                 ld      [%l1+0x18], %l1
F00C8634: 90100012                 mov     %l2, %o0! id
F00C8638: d2056178                 ld      [%l5+0x178], %o1! SEL
F00C863C: 4000a48d                 call    _objc_msgSend
F00C8640: 94102000                 mov     0, %o2
F00C8644: d04c600d                 ldsb    [%l1+0xD], %o0
F00C8648: 80a22000                 cmp     %o0, 0
F00C864C: 22800005                 be,a    loc_F00C8660
F00C8650: 113c0504                 sethi   -0xFEBF000, %o0
F00C8654: 7fff2dec                 call    _vol_panel_remove
F00C8658: d0046010                 ld      [%l1+0x10], %o0
F00C865C: 113c0504                 sethi   -0xFEBF000, %o0! id
F00C8660: d20221c4                 ld      [%o0+0x1C4], %o1! SEL
F00C8664: 4000a483                 call    _objc_msgSend
F00C8668: 90100012                 mov     %l2, %o0
F00C866C: 113c0506                 sethi   %hi(paDiskbecameread), %o0! id
F00C8670: d2022124                 ld      [%o0+%lo(paDiskbecameread)], %o1! SEL
F00C8674: 4000a47f                 call    _objc_msgSend
F00C8678: 90100012                 mov     %l2, %o0
F00C867C: 113c0506                 sethi   %hi(paIodevicedescri), %o0
F00C8680: d00222b4                 ld      [%o0+%lo(paIodevicedescri)], %o0! id
F00C8684: 133c0504                 sethi   %hi(paNew), %o1! SEL
F00C8688: 4000a47a                 call    _objc_msgSend
F00C868C: d2026238                 ld      [%o1+%lo(paNew)], %o1
F00C8690: a0100008                 mov     %o0, %l0
F00C8694: 133c0506                 sethi   %hi(paSetdirectdevic), %o1
F00C8698: d20261cc                 ld      [%o1+%lo(paSetdirectdevic)], %o1! SEL
F00C869C: 4000a475                 call    _objc_msgSend
F00C86A0: 94100012                 mov     %l2, %o2
F00C86A4: 113c0506                 sethi   %hi(paIodiskpartitio_1), %o0
F00C86A8: d00222f4                 ld      [%o0+%lo(paIodiskpartitio_1)], %o0! id
F00C86AC: 133c0504                 sethi   %hi(paProbe), %o1
F00C86B0: d2026368                 ld      [%o1+%lo(paProbe)], %o1! SEL
F00C86B4: 4000a46f                 call    _objc_msgSend
F00C86B8: 94100010                 mov     %l0, %o2
F00C86BC: 912a2018                 sll     %o0, 24, %o0
F00C86C0: 80a22000                 cmp     %o0, 0
F00C86C4: 32800007                 bne,a   loc_F00C86E0
F00C86C8: d04c600d                 ldsb    [%l1+0xD], %o0
F00C86CC: 113c0503                 sethi   %hi(paFree), %o0! id
F00C86D0: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00C86D4: 4000a467                 call    _objc_msgSend
F00C86D8: 90100010                 mov     %l0, %o0
F00C86DC: d04c600d                 ldsb    [%l1+0xD], %o0
F00C86E0: 80a22000                 cmp     %o0, 0
F00C86E4: 22800004                 be,a    loc_F00C86F4
F00C86E8: d2546004                 ldsh    [%l1+4], %o1
F00C86EC: 10800005                 ba      loc_F00C8700
F00C86F0: c02c600d                 clrb    [%l1+0xD]
F00C86F4: d4546006                 ldsh    [%l1+6], %o2
F00C86F8: 400000eb                 call    sub_F00C8AA4
F00C86FC: 90100012                 mov     %l2, %o0
F00C8700: e2046018                 ld      [%l1+0x18], %l1
F00C8704: 80a44017                 cmp     %l1, %l7
F00C8708: 32bfff7b                 bne,a   loc_F00C84F4
F00C870C: d0044000                 ld      [%l1], %o0
F00C8710: 7ffff61b                 call    _IOSleep
F00C8714: 901023e8                 mov     0x3E8, %o0
F00C8718: 30bfff6e                 ba,a    loc_F00C84D0
