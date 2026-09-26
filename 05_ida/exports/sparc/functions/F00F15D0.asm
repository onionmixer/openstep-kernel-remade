F00F15D0: 9de3bf90                 save    %sp, -0x70, %sp
F00F15D4: 90100018                 mov     %i0, %o0! mhp
F00F15D8: 133c03f4921260c8         set     aObjc, %o1! "__OBJC"
F00F15E0: 153c03f49412a1d8         set     aModuleInfo, %o2! "__module_info"
F00F15E8: 7ffde293                 call    _getsectdatafromheader
F00F15EC: 9607bff4                 add     %fp, var_C, %o3! size
F00F15F0: a4100008                 mov     %o0, %l2
F00F15F4: a8948000                 orcc    %l2, %g0, %l4
F00F15F8: 02800024                 be      loc_F00F1688
F00F15FC: e607bff4                 ld      [%fp+var_C], %l3
F00F1600: 80a4e000                 cmp     %l3, 0
F00F1604: 22800022                 be,a    loc_F00F168C
F00F1608: a4100014                 mov     %l4, %l2
F00F160C: d004a00c                 ld      [%l2+0xC], %o0
F00F1610: 94100008                 mov     %o0, %o2
F00F1614: e2122008                 lduh    [%o0+8], %l1
F00F1618: d012200a                 lduh    [%o0+0xA], %o0
F00F161C: 90044008                 add     %l1, %o0, %o0
F00F1620: 80a44008                 cmp     %l1, %o0
F00F1624: 36800016                 bge,a   loc_F00F167C
F00F1628: d004a004                 ld      [%l2+4], %o0
F00F162C: 912c6002                 sll     %l1, 2, %o0
F00F1630: 9002000a                 add     %o0, %o2, %o0! name
F00F1634: 80a66000                 cmp     %i1, 0
F00F1638: 02800006                 be      loc_F00F1650
F00F163C: e002200c                 ld      [%o0+0xC], %l0
F00F1640: 400001b1                 call    _objc_getClass
F00F1644: d0042004                 ld      [%l0+4], %o0
F00F1648: 9fc64000                 call    %i1
F00F164C: 92100010                 mov     %l0, %o1
F00F1650: 7ffffd8b                 call    sub_F00F0C7C
F00F1654: 90100010                 mov     %l0, %o0
F00F1658: a2046001                 inc     %l1
F00F165C: d404a00c                 ld      [%l2+0xC], %o2
F00F1660: d012a008                 lduh    [%o2+8], %o0
F00F1664: d212a00a                 lduh    [%o2+0xA], %o1
F00F1668: 90020009                 add     %o0, %o1, %o0
F00F166C: 80a44008                 cmp     %l1, %o0
F00F1670: 06bffff0                 bl      loc_F00F1630
F00F1674: 912c6002                 sll     %l1, 2, %o0
F00F1678: d004a004                 ld      [%l2+4], %o0
F00F167C: a4848008                 addcc   %l2, %o0, %l2
F00F1680: 12bfffe0                 bne     loc_F00F1600
F00F1684: a624c008                 sub     %l3, %o0, %l3
F00F1688: a4100014                 mov     %l4, %l2
F00F168C: 80a4a000                 cmp     %l2, 0
F00F1690: 02800020                 be      loc_F00F1710
F00F1694: e607bff4                 ld      [%fp+var_C], %l3
F00F1698: 80a4e000                 cmp     %l3, 0
F00F169C: 2280001e                 be,a    loc_F00F1714
F00F16A0: a4100014                 mov     %l4, %l2
F00F16A4: a2102000                 mov     0, %l1
F00F16A8: d004a00c                 ld      [%l2+0xC], %o0
F00F16AC: 92100008                 mov     %o0, %o1
F00F16B0: d0122008                 lduh    [%o0+8], %o0
F00F16B4: 80a44008                 cmp     %l1, %o0
F00F16B8: 36800013                 bge,a   loc_F00F1704
F00F16BC: d004a004                 ld      [%l2+4], %o0
F00F16C0: 912c6002                 sll     %l1, 2, %o0
F00F16C4: 90020009                 add     %o0, %o1, %o0
F00F16C8: 80a66000                 cmp     %i1, 0
F00F16CC: 02800005                 be      loc_F00F16E0
F00F16D0: e002200c                 ld      [%o0+0xC], %l0
F00F16D4: 90100010                 mov     %l0, %o0
F00F16D8: 9fc64000                 call    %i1
F00F16DC: 92102000                 mov     0, %o1
F00F16E0: 7ffffd58                 call    sub_F00F0C40
F00F16E4: 90100010                 mov     %l0, %o0
F00F16E8: a2046001                 inc     %l1
F00F16EC: d204a00c                 ld      [%l2+0xC], %o1
F00F16F0: d0126008                 lduh    [%o1+8], %o0
F00F16F4: 80a44008                 cmp     %l1, %o0
F00F16F8: 06bffff3                 bl      loc_F00F16C4
F00F16FC: 912c6002                 sll     %l1, 2, %o0
F00F1700: d004a004                 ld      [%l2+4], %o0
F00F1704: a4848008                 addcc   %l2, %o0, %l2
F00F1708: 12bfffe4                 bne     loc_F00F1698
F00F170C: a624c008                 sub     %l3, %o0, %l3
F00F1710: a4100014                 mov     %l4, %l2
F00F1714: 80a4a000                 cmp     %l2, 0
F00F1718: 0280001e                 be      loc_F00F1790
F00F171C: e607bff4                 ld      [%fp+var_C], %l3
F00F1720: 80a4e000                 cmp     %l3, 0
F00F1724: 2280001c                 be,a    loc_F00F1794
F00F1728: a4100014                 mov     %l4, %l2
F00F172C: d004a00c                 ld      [%l2+0xC], %o0
F00F1730: 94100008                 mov     %o0, %o2
F00F1734: e2122008                 lduh    [%o0+8], %l1
F00F1738: d012200a                 lduh    [%o0+0xA], %o0
F00F173C: 90044008                 add     %l1, %o0, %o0
F00F1740: 80a44008                 cmp     %l1, %o0
F00F1744: 36800010                 bge,a   loc_F00F1784
F00F1748: d004a004                 ld      [%l2+4], %o0
F00F174C: 912c6002                 sll     %l1, 2, %o0
F00F1750: 9002000a                 add     %o0, %o2, %o0
F00F1754: d002200c                 ld      [%o0+0xC], %o0
F00F1758: 40000240                 call    __objc_remove_category
F00F175C: d2048000                 ld      [%l2], %o1
F00F1760: a2046001                 inc     %l1
F00F1764: d404a00c                 ld      [%l2+0xC], %o2
F00F1768: d012a008                 lduh    [%o2+8], %o0
F00F176C: d212a00a                 lduh    [%o2+0xA], %o1
F00F1770: 90020009                 add     %o0, %o1, %o0
F00F1774: 80a44008                 cmp     %l1, %o0
F00F1778: 06bffff6                 bl      loc_F00F1750
F00F177C: 912c6002                 sll     %l1, 2, %o0
F00F1780: d004a004                 ld      [%l2+4], %o0
F00F1784: a4848008                 addcc   %l2, %o0, %l2
F00F1788: 12bfffe6                 bne     loc_F00F1720
F00F178C: a624c008                 sub     %l3, %o0, %l3
F00F1790: a4100014                 mov     %l4, %l2
F00F1794: 80a4a000                 cmp     %l2, 0
F00F1798: 0280001a                 be      loc_F00F1800
F00F179C: e607bff4                 ld      [%fp+var_C], %l3
F00F17A0: 80a4e000                 cmp     %l3, 0
F00F17A4: 02800018                 be      loc_F00F1804
F00F17A8: 90100018                 mov     %i0, %o0
F00F17AC: a2102000                 mov     0, %l1
F00F17B0: d004a00c                 ld      [%l2+0xC], %o0
F00F17B4: 92100008                 mov     %o0, %o1
F00F17B8: d0122008                 lduh    [%o0+8], %o0
F00F17BC: 80a44008                 cmp     %l1, %o0
F00F17C0: 3680000d                 bge,a   loc_F00F17F4
F00F17C4: d004a004                 ld      [%l2+4], %o0
F00F17C8: 912c6002                 sll     %l1, 2, %o0
F00F17CC: 90020009                 add     %o0, %o1, %o0
F00F17D0: 4000018f                 call    __objc_removeClass
F00F17D4: d002200c                 ld      [%o0+0xC], %o0
F00F17D8: a2046001                 inc     %l1
F00F17DC: d204a00c                 ld      [%l2+0xC], %o1
F00F17E0: d0126008                 lduh    [%o1+8], %o0
F00F17E4: 80a44008                 cmp     %l1, %o0
F00F17E8: 06bffff9                 bl      loc_F00F17CC
F00F17EC: 912c6002                 sll     %l1, 2, %o0
F00F17F0: d004a004                 ld      [%l2+4], %o0
F00F17F4: a4848008                 addcc   %l2, %o0, %l2
F00F17F8: 12bfffea                 bne     loc_F00F17A0
F00F17FC: a624c008                 sub     %l3, %o0, %l3
F00F1800: 90100018                 mov     %i0, %o0! mhp
F00F1804: 133c03f4921260c8         set     aObjc, %o1! "__OBJC"
F00F180C: 153c03f49412a228         set     aMethVarNames, %o2! "__meth_var_names"
F00F1814: 7ffde208                 call    _getsectdatafromheader
F00F1818: 9607bff0                 add     %fp, var_10, %o3! size
F00F181C: 94920000                 orcc    %o0, %g0, %o2
F00F1820: 02800004                 be      loc_F00F1830
F00F1824: d207bff0                 ld      [%fp+var_10], %o1
F00F1828: 4000083e                 call    __sel_unloadSelectors
F00F182C: 92028009                 add     %o2, %o1, %o1
F00F1830: 90100018                 mov     %i0, %o0! mhp
F00F1834: 133c03f4921260c8         set     aObjc, %o1! "__OBJC"
F00F183C: 153c03f49412a240         set     aSelectorStrs, %o2! "__selector_strs"
F00F1844: 7ffde1fc                 call    _getsectdatafromheader
F00F1848: 9607bff0                 add     %fp, var_10, %o3
F00F184C: 94920000                 orcc    %o0, %g0, %o2
F00F1850: 02800004                 be      loc_F00F1860
F00F1854: d207bff0                 ld      [%fp+var_10], %o1
F00F1858: 40000832                 call    __sel_unloadSelectors
F00F185C: 92028009                 add     %o2, %o1, %o1
F00F1860: 40000500                 call    __objc_removeHeader
F00F1864: 90100018                 mov     %i0, %o0
F00F1868: 81c7e008                 ret
F00F186C: 81e80000                 restore
