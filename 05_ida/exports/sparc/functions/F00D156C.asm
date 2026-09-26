F00D156C: 9de3bf68                 save    %sp, -0x98, %sp
F00D1570: a2103d3e                 mov     -0x2C2, %l1
F00D1574: 9010001b                 mov     %i3, %o0! __s1
F00D1578: 133c03ef                 sethi   %hi(aEvSetscreen), %o1! "Ev_SetScreen"
F00D157C: 7ffcdb0c                 call    _strcmp
F00D1580: 92126010                 bset    %lo(aEvSetscreen), %o1! "Ev_SetScreen"
F00D1584: 80a22000                 cmp     %o0, 0
F00D1588: 3280000b                 bne,a   loc_F00D15B4
F00D158C: 9010001b                 mov     %i3, %o0
F00D1590: 80a72007                 cmp     %i4, 7
F00D1594: 128001a0                 bne     locret_F00D1C14
F00D1598: 90100018                 mov     %i0, %o0! id
F00D159C: 133c0505                 sethi   %hi(paEvsetscreen), %o1
F00D15A0: d2026334                 ld      [%o1+%lo(paEvsetscreen)], %o1! SEL
F00D15A4: 400080b3                 call    _objc_msgSend
F00D15A8: 9410001a                 mov     %i2, %o2
F00D15AC: 1080019a                 ba      locret_F00D1C14
F00D15B0: a2100008                 mov     %o0, %l1
F00D15B4: 133c03ef                 sethi   %hi(aEvStartcursor), %o1! "Ev_StartCursor"
F00D15B8: 7ffcdafd                 call    _strcmp
F00D15BC: 92126020                 bset    %lo(aEvStartcursor), %o1! "Ev_StartCursor"
F00D15C0: 80a22000                 cmp     %o0, 0
F00D15C4: 12800008                 bne     loc_F00D15E4
F00D15C8: 9010001b                 mov     %i3, %o0
F00D15CC: 90100018                 mov     %i0, %o0! id
F00D15D0: 133c0505                 sethi   %hi(paStartcursor), %o1
F00D15D4: d2026330                 ld      [%o1+%lo(paStartcursor)], %o1! SEL
F00D15D8: 400080a6                 call    _objc_msgSend
F00D15DC: a2102000                 mov     0, %l1
F00D15E0: 3080018d                 ba,a    locret_F00D1C14
F00D15E4: 133c03ef                 sethi   %hi(aEvMousepositio), %o1! "Ev_MousePosition"
F00D15E8: 7ffcdaf1                 call    _strcmp
F00D15EC: 92126030                 bset    %lo(aEvMousepositio), %o1! "Ev_MousePosition"
F00D15F0: 80a22000                 cmp     %o0, 0
F00D15F4: 32800014                 bne,a   loc_F00D1644
F00D15F8: 9010001b                 mov     %i3, %o0
F00D15FC: 80a72002                 cmp     %i4, 2
F00D1600: 12800185                 bne     locret_F00D1C14
F00D1604: 01000000                 nop
F00D1608: d0068000                 ld      [%i2], %o0
F00D160C: d037bfe8                 sth     %o0, [%fp+var_18]
F00D1610: d406a004                 ld      [%i2+4], %o2
F00D1614: 113c0504                 sethi   %hi(paLock), %o0! id
F00D1618: d2022000                 ld      [%o0+%lo(paLock)], %o1! SEL
F00D161C: d437bfea                 sth     %o2, [%fp+var_16]
F00D1620: 40008094                 call    _objc_msgSend
F00D1624: d0062110                 ld      [%i0+0x110], %o0
F00D1628: 90100018                 mov     %i0, %o0! id
F00D162C: 133c0505                 sethi   %hi(paSetcursorposit), %o1
F00D1630: d202632c                 ld      [%o1+%lo(paSetcursorposit)], %o1! SEL
F00D1634: 4000808f                 call    _objc_msgSend
F00D1638: 9407bfe8                 add     %fp, var_18, %o2
F00D163C: 10800148                 ba      loc_F00D1B5C
F00D1640: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D1644: 133c03ef                 sethi   %hi(aEvsSetwaitthre), %o1! "Evs_SetWaitThreshold"
F00D1648: 7ffcdad9                 call    _strcmp
F00D164C: 92126048                 bset    %lo(aEvsSetwaitthre), %o1! "Evs_SetWaitThreshold"
F00D1650: 80a22000                 cmp     %o0, 0
F00D1654: 1280001d                 bne     loc_F00D16C8
F00D1658: 9010001b                 mov     %i3, %o0
F00D165C: 9207bfd0                 add     %fp, var_30, %o1
F00D1660: 94102000                 mov     0, %o2
F00D1664: 9607bfd4                 add     %fp, var_30+4, %o3
F00D1668: d002801a                 ld      [%o2+%i2], %o0
F00D166C: d0227ff8                 st      %o0, [%o1-8]
F00D1670: 92026004                 inc     4, %o1
F00D1674: 80a2400b                 cmp     %o1, %o3
F00D1678: 08bffffc                 bleu    loc_F00D1668
F00D167C: 9402a004                 inc     4, %o2
F00D1680: d0062110                 ld      [%i0+0x110], %o0! id
F00D1684: d41fbfc8                 ldd     [%fp+var_38], %o2
F00D1688: 133c0504                 sethi   %hi(paLock), %o1
F00D168C: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D1690: 40008078                 call    _objc_msgSend
F00D1694: d43fbfd0                 std     %o2, [%fp+var_30]
F00D1698: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D169C: 80a22000                 cmp     %o0, 0
F00D16A0: 0280012e                 be      loc_F00D1B58
F00D16A4: d41fbfd0                 ldd     [%fp+var_30], %o2
F00D16A8: 9b2aa008                 sll     %o2, 8, %o5
F00D16AC: 9932e018                 srl     %o3, 24, %o4
F00D16B0: 9213400c                 or      %o5, %o4, %o1
F00D16B4: 9132a018                 srl     %o2, 24, %o0
F00D16B8: d4062168                 ld      [%i0+0x168], %o2
F00D16BC: d232a04c                 sth     %o1, [%o2+0x4C]
F00D16C0: 10800127                 ba      loc_F00D1B5C
F00D16C4: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D16C8: 133c03ef                 sethi   %hi(aEvsSetwaitsust), %o1! "Evs_SetWaitSustain"
F00D16CC: 7ffcdab8                 call    _strcmp
F00D16D0: 92126060                 bset    %lo(aEvsSetwaitsust), %o1! "Evs_SetWaitSustain"
F00D16D4: 80a22000                 cmp     %o0, 0
F00D16D8: 12800016                 bne     loc_F00D1730
F00D16DC: 9010001b                 mov     %i3, %o0
F00D16E0: d0062110                 ld      [%i0+0x110], %o0! id
F00D16E4: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D16E8: 40008062                 call    _objc_msgSend
F00D16EC: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D16F0: 980621d8                 add     %i0, 0x1D8, %o4
F00D16F4: 9207bfd0                 add     %fp, var_30, %o1
F00D16F8: 94102000                 mov     0, %o2
F00D16FC: 9607bfd4                 add     %fp, var_30+4, %o3
F00D1700: d002801a                 ld      [%o2+%i2], %o0
F00D1704: d0227ff8                 st      %o0, [%o1-8]
F00D1708: 92026004                 inc     4, %o1
F00D170C: 80a2400b                 cmp     %o1, %o3
F00D1710: 08bffffc                 bleu    loc_F00D1700
F00D1714: 9402a004                 inc     4, %o2
F00D1718: d41fbfc8                 ldd     [%fp+var_38], %o2
F00D171C: 113c0504                 sethi   %hi(paUnlock), %o0
F00D1720: d2022244                 ld      [%o0+%lo(paUnlock)], %o1
F00D1724: d43b0000                 std     %o2, [%o4]
F00D1728: 1080010f                 ba      loc_F00D1B64
F00D172C: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D1730: 133c03ef                 sethi   %hi(aEvsSetwaitfram), %o1! "Evs_SetWaitFrameInterval"
F00D1734: 7ffcda9e                 call    _strcmp
F00D1738: 92126078                 bset    %lo(aEvsSetwaitfram), %o1! "Evs_SetWaitFrameInterval"
F00D173C: 80a22000                 cmp     %o0, 0
F00D1740: 12800016                 bne     loc_F00D1798
F00D1744: 9010001b                 mov     %i3, %o0
F00D1748: d0062110                 ld      [%i0+0x110], %o0! id
F00D174C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D1750: 40008048                 call    _objc_msgSend
F00D1754: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D1758: 980621e8                 add     %i0, 0x1E8, %o4
F00D175C: 9207bfd0                 add     %fp, var_30, %o1
F00D1760: 94102000                 mov     0, %o2
F00D1764: 9607bfd4                 add     %fp, var_30+4, %o3
F00D1768: d002801a                 ld      [%o2+%i2], %o0
F00D176C: d0227ff8                 st      %o0, [%o1-8]
F00D1770: 92026004                 inc     4, %o1
F00D1774: 80a2400b                 cmp     %o1, %o3
F00D1778: 08bffffc                 bleu    loc_F00D1768
F00D177C: 9402a004                 inc     4, %o2
F00D1780: d41fbfc8                 ldd     [%fp+var_38], %o2
F00D1784: 113c0504                 sethi   %hi(paUnlock), %o0
F00D1788: d2022244                 ld      [%o0+%lo(paUnlock)], %o1
F00D178C: d43b0000                 std     %o2, [%o4]
F00D1790: 108000f5                 ba      loc_F00D1B64
F00D1794: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D1798: 133c03ef                 sethi   %hi(aEvsSetbrightne), %o1! "Evs_SetBrightness"
F00D179C: 7ffcda84                 call    _strcmp
F00D17A0: 92126098                 bset    %lo(aEvsSetbrightne), %o1! "Evs_SetBrightness"
F00D17A4: 80a22000                 cmp     %o0, 0
F00D17A8: 1280000d                 bne     loc_F00D17DC
F00D17AC: 9010001b                 mov     %i3, %o0
F00D17B0: d0062110                 ld      [%i0+0x110], %o0! id
F00D17B4: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D17B8: 4000802e                 call    _objc_msgSend
F00D17BC: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D17C0: 113c0505                 sethi   %hi(paSetbrightness), %o0! id
F00D17C4: d2022328                 ld      [%o0+%lo(paSetbrightness)], %o1! SEL
F00D17C8: d4068000                 ld      [%i2], %o2
F00D17CC: 40008029                 call    _objc_msgSend
F00D17D0: 90100018                 mov     %i0, %o0
F00D17D4: 108000e2                 ba      loc_F00D1B5C
F00D17D8: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D17DC: 133c03ef                 sethi   %hi(aEvsSetattenuat), %o1! "Evs_SetAttenuation"
F00D17E0: 7ffcda73                 call    _strcmp
F00D17E4: 921260b0                 bset    %lo(aEvsSetattenuat), %o1! "Evs_SetAttenuation"
F00D17E8: 80a22000                 cmp     %o0, 0
F00D17EC: 1280000d                 bne     loc_F00D1820
F00D17F0: 9010001b                 mov     %i3, %o0
F00D17F4: d0062110                 ld      [%i0+0x110], %o0! id
F00D17F8: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D17FC: 4000801d                 call    _objc_msgSend
F00D1800: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D1804: 113c0505                 sethi   %hi(paSetuseraudiovo), %o0! id
F00D1808: d2022324                 ld      [%o0+%lo(paSetuseraudiovo)], %o1! SEL
F00D180C: d4068000                 ld      [%i2], %o2
F00D1810: 40008018                 call    _objc_msgSend
F00D1814: 90100018                 mov     %i0, %o0
F00D1818: 108000d1                 ba      loc_F00D1B5C
F00D181C: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D1820: 133c03ef                 sethi   %hi(aEvsSetautodimb), %o1! "Evs_SetAutoDimBrightness"
F00D1824: 7ffcda62                 call    _strcmp
F00D1828: 921260c8                 bset    %lo(aEvsSetautodimb), %o1! "Evs_SetAutoDimBrightness"
F00D182C: 80a22000                 cmp     %o0, 0
F00D1830: 1280000d                 bne     loc_F00D1864
F00D1834: 9010001b                 mov     %i3, %o0
F00D1838: d0062110                 ld      [%i0+0x110], %o0! id
F00D183C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D1840: 4000800c                 call    _objc_msgSend
F00D1844: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D1848: 113c0505                 sethi   %hi(paSetautodimbrig), %o0! id
F00D184C: d2022320                 ld      [%o0+%lo(paSetautodimbrig)], %o1! SEL
F00D1850: d4068000                 ld      [%i2], %o2
F00D1854: 40008007                 call    _objc_msgSend
F00D1858: 90100018                 mov     %i0, %o0
F00D185C: 108000c0                 ba      loc_F00D1B5C
F00D1860: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D1864: 133c03ef                 sethi   %hi(aEvsSetclicktim), %o1! "Evs_SetClickTime"
F00D1868: 7ffcda51                 call    _strcmp
F00D186C: 921260e8                 bset    %lo(aEvsSetclicktim), %o1! "Evs_SetClickTime"
F00D1870: 80a22000                 cmp     %o0, 0
F00D1874: 1280001d                 bne     loc_F00D18E8
F00D1878: 9010001b                 mov     %i3, %o0
F00D187C: 9207bfd0                 add     %fp, var_30, %o1
F00D1880: 94102000                 mov     0, %o2
F00D1884: 9607bfd4                 add     %fp, var_30+4, %o3
F00D1888: d002801a                 ld      [%o2+%i2], %o0
F00D188C: d0227ff8                 st      %o0, [%o1-8]
F00D1890: 92026004                 inc     4, %o1
F00D1894: 80a2400b                 cmp     %o1, %o3
F00D1898: 08bffffc                 bleu    loc_F00D1888
F00D189C: 9402a004                 inc     4, %o2
F00D18A0: d0062110                 ld      [%i0+0x110], %o0! id
F00D18A4: a2102000                 mov     0, %l1
F00D18A8: d41fbfc8                 ldd     [%fp+var_38], %o2
F00D18AC: 133c0504                 sethi   %hi(paLock), %o1
F00D18B0: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D18B4: 40007fef                 call    _objc_msgSend
F00D18B8: d43fbfd0                 std     %o2, [%fp+var_30]
F00D18BC: d0062110                 ld      [%i0+0x110], %o0! id
F00D18C0: d81fbfd0                 ldd     [%fp+var_30], %o4
F00D18C4: 133c0504                 sethi   %hi(paUnlock), %o1
F00D18C8: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00D18CC: 872b2008                 sll     %o4, 8, %g3
F00D18D0: 85336018                 srl     %o5, 24, %g2
F00D18D4: 9610c002                 or      %g3, %g2, %o3
F00D18D8: 95332018                 srl     %o4, 24, %o2
F00D18DC: 40007fe5                 call    _objc_msgSend
F00D18E0: d62621bc                 st      %o3, [%i0+0x1BC]
F00D18E4: 308000cc                 ba,a    locret_F00D1C14
F00D18E8: 133c03ef                 sethi   %hi(aEvsSetclickspa), %o1! "Evs_SetClickSpace"
F00D18EC: 7ffcda30                 call    _strcmp
F00D18F0: 92126100                 bset    %lo(aEvsSetclickspa), %o1! "Evs_SetClickSpace"
F00D18F4: 80a22000                 cmp     %o0, 0
F00D18F8: 12800010                 bne     loc_F00D1938
F00D18FC: 9010001b                 mov     %i3, %o0
F00D1900: d0062110                 ld      [%i0+0x110], %o0! id
F00D1904: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D1908: 40007fda                 call    _objc_msgSend
F00D190C: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D1910: d2068000                 ld      [%i2], %o1
F00D1914: a2102000                 mov     0, %l1
F00D1918: d0062110                 ld      [%i0+0x110], %o0! id
F00D191C: d23621b0                 sth     %o1, [%i0+0x1B0]
F00D1920: d406a004                 ld      [%i2+4], %o2
F00D1924: 133c0504                 sethi   %hi(paUnlock), %o1
F00D1928: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00D192C: 40007fd1                 call    _objc_msgSend
F00D1930: d43621b2                 sth     %o2, [%i0+0x1B2]
F00D1934: 308000b8                 ba,a    locret_F00D1C14
F00D1938: 133c03ef                 sethi   %hi(aEvsSetautodimt), %o1! "Evs_SetAutoDimTime"
F00D193C: 7ffcda1c                 call    _strcmp
F00D1940: 92126118                 bset    %lo(aEvsSetautodimt), %o1! "Evs_SetAutoDimTime"
F00D1944: 80a22000                 cmp     %o0, 0
F00D1948: 12800022                 bne     loc_F00D19D0
F00D194C: 9010001b                 mov     %i3, %o0
F00D1950: 9207bfd0                 add     %fp, var_30, %o1
F00D1954: 94102000                 mov     0, %o2
F00D1958: 9607bfd4                 add     %fp, var_30+4, %o3
F00D195C: d002801a                 ld      [%o2+%i2], %o0
F00D1960: d0227ff8                 st      %o0, [%o1-8]
F00D1964: 92026004                 inc     4, %o1
F00D1968: 80a2400b                 cmp     %o1, %o3
F00D196C: 08bffffc                 bleu    loc_F00D195C
F00D1970: 9402a004                 inc     4, %o2
F00D1974: d0062110                 ld      [%i0+0x110], %o0! id
F00D1978: a2102000                 mov     0, %l1
F00D197C: d41fbfc8                 ldd     [%fp+var_38], %o2
F00D1980: 133c0504                 sethi   %hi(paLock), %o1
F00D1984: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D1988: 40007fba                 call    _objc_msgSend
F00D198C: d43fbfd0                 std     %o2, [%fp+var_30]
F00D1990: d81fbfd0                 ldd     [%fp+var_30], %o4
F00D1994: d0062110                 ld      [%i0+0x110], %o0! id
F00D1998: 872b2008                 sll     %o4, 8, %g3
F00D199C: 85336018                 srl     %o5, 24, %g2
F00D19A0: 9610c002                 or      %g3, %g2, %o3
F00D19A4: c40621a4                 ld      [%i0+0x1A4], %g2
F00D19A8: 95332018                 srl     %o4, 24, %o2
F00D19AC: d80621a0                 ld      [%i0+0x1A0], %o4
F00D19B0: 133c0504                 sethi   %hi(paUnlock), %o1
F00D19B4: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00D19B8: 8420800c                 sub     %g2, %o4, %g2
F00D19BC: 8400800b                 add     %g2, %o3, %g2
F00D19C0: c42621a4                 st      %g2, [%i0+0x1A4]
F00D19C4: 40007fab                 call    _objc_msgSend
F00D19C8: d62621a0                 st      %o3, [%i0+0x1A0]
F00D19CC: 30800092                 ba,a    locret_F00D1C14
F00D19D0: 133c03ef                 sethi   %hi(aEvsSetautodims), %o1! "Evs_SetAutoDimState"
F00D19D4: 7ffcd9f6                 call    _strcmp
F00D19D8: 92126130                 bset    %lo(aEvsSetautodims), %o1! "Evs_SetAutoDimState"
F00D19DC: 80a22000                 cmp     %o0, 0
F00D19E0: 1280000d                 bne     loc_F00D1A14
F00D19E4: 9010001b                 mov     %i3, %o0
F00D19E8: d0062110                 ld      [%i0+0x110], %o0! id
F00D19EC: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D19F0: 40007fa0                 call    _objc_msgSend
F00D19F4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D19F8: 113c0505                 sethi   %hi(paForceautodimst), %o0! id
F00D19FC: d2022350                 ld      [%o0+%lo(paForceautodimst)], %o1! SEL
F00D1A00: d44ea003                 ldsb    [%i2+3], %o2
F00D1A04: 40007f9b                 call    _objc_msgSend
F00D1A08: 90100018                 mov     %i0, %o0
F00D1A0C: 10800054                 ba      loc_F00D1B5C
F00D1A10: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D1A14: 133c03ef                 sethi   %hi(aEvsResetmouse), %o1! "Evs_ResetMouse"
F00D1A18: 7ffcd9e5                 call    _strcmp
F00D1A1C: 92126148                 bset    %lo(aEvsResetmouse), %o1! "Evs_ResetMouse"
F00D1A20: 80a22000                 cmp     %o0, 0
F00D1A24: 12800006                 bne     loc_F00D1A3C
F00D1A28: 9010001b                 mov     %i3, %o0
F00D1A2C: 90100018                 mov     %i0, %o0! __s1
F00D1A30: 133c0505                 sethi   %hi(paResetmousepara), %o1
F00D1A34: 1080004c                 ba      loc_F00D1B64
F00D1A38: d202631c                 ld      [%o1+%lo(paResetmousepara)], %o1
F00D1A3C: 133c03ef                 sethi   %hi(aEvsResetkeyboa), %o1! "Evs_ResetKeyboard"
F00D1A40: 7ffcd9db                 call    _strcmp
F00D1A44: 92126158                 bset    %lo(aEvsResetkeyboa), %o1! "Evs_ResetKeyboard"
F00D1A48: 80a22000                 cmp     %o0, 0
F00D1A4C: 12800006                 bne     loc_F00D1A64
F00D1A50: 9010001b                 mov     %i3, %o0
F00D1A54: 90100018                 mov     %i0, %o0! __s1
F00D1A58: 133c0505                 sethi   %hi(paResetkeyboardp), %o1
F00D1A5C: 10800042                 ba      loc_F00D1B64
F00D1A60: d2026318                 ld      [%o1+%lo(paResetkeyboardp)], %o1
F00D1A64: 133c03ef                 sethi   %hi(aEvLlpostevent), %o1! "Ev_LLPostEvent"
F00D1A68: 7ffcd9d1                 call    _strcmp
F00D1A6C: 92126170                 bset    %lo(aEvLlpostevent), %o1! "Ev_LLPostEvent"
F00D1A70: 80a22000                 cmp     %o0, 0
F00D1A74: 02800008                 be      loc_F00D1A94
F00D1A78: 9010001b                 mov     %i3, %o0! __s1
F00D1A7C: 133c03ef                 sethi   %hi(aEvPointerllpos), %o1! "Ev_PointerLLPostEvent"
F00D1A80: 7ffcd9cb                 call    _strcmp
F00D1A84: 92126180                 bset    %lo(aEvPointerllpos), %o1! "Ev_PointerLLPostEvent"
F00D1A88: 80a22000                 cmp     %o0, 0
F00D1A8C: 32800039                 bne,a   loc_F00D1B70
F00D1A90: d0062170                 ld      [%i0+0x170], %o0
F00D1A94: 80a72006                 cmp     %i4, 6
F00D1A98: 1280005f                 bne     locret_F00D1C14
F00D1A9C: 01000000                 nop
F00D1AA0: d006a004                 ld      [%i2+4], %o0
F00D1AA4: d037bfe8                 sth     %o0, [%fp+var_18]
F00D1AA8: d006a008                 ld      [%i2+8], %o0
F00D1AAC: d037bfea                 sth     %o0, [%fp+var_16]
F00D1AB0: d006a00c                 ld      [%i2+0xC], %o0
F00D1AB4: d027bfd8                 st      %o0, [%fp+var_28]
F00D1AB8: d006a010                 ld      [%i2+0x10], %o0
F00D1ABC: d027bfdc                 st      %o0, [%fp+var_24]
F00D1AC0: d406a014                 ld      [%i2+0x14], %o2
F00D1AC4: 113c0504                 sethi   %hi(paLock), %o0! id
F00D1AC8: d2022000                 ld      [%o0+%lo(paLock)], %o1! SEL
F00D1ACC: d427bfe0                 st      %o2, [%fp+var_20]
F00D1AD0: 40007f68                 call    _objc_msgSend
F00D1AD4: d0062110                 ld      [%i0+0x110], %o0
F00D1AD8: 9010001b                 mov     %i3, %o0! __s1
F00D1ADC: 133c03ef                 sethi   %hi(aEvPointerllpos), %o1! "Ev_PointerLLPostEvent"
F00D1AE0: 7ffcd9b3                 call    _strcmp
F00D1AE4: 92126180                 bset    %lo(aEvPointerllpos), %o1! "Ev_PointerLLPostEvent"
F00D1AE8: 80a22000                 cmp     %o0, 0
F00D1AEC: 32800008                 bne,a   loc_F00D1B0C
F00D1AF0: 113c0505                 sethi   -0xFEBEC00, %o0
F00D1AF4: 90100018                 mov     %i0, %o0! id
F00D1AF8: 133c0505                 sethi   %hi(paSetcursorposit), %o1
F00D1AFC: d202632c                 ld      [%o1+%lo(paSetcursorposit)], %o1! SEL
F00D1B00: 40007f5c                 call    _objc_msgSend
F00D1B04: 9407bfe8                 add     %fp, var_18, %o2
F00D1B08: 113c0505                 sethi   -0xFEBEC00, %o0
F00D1B0C: e2022314                 ld      [%o0+0x314], %l1
F00D1B10: a007bfe8                 add     %fp, var_18, %l0
F00D1B14: f4068000                 ld      [%i2], %i2
F00D1B18: 7fffd171                 call    _IOGetTimestamp
F00D1B1C: 9007bfc8                 add     %fp, var_38, %o0
F00D1B20: d41fbfc8                 ldd     [%fp+var_38], %o2
F00D1B24: 9b2aa008                 sll     %o2, 8, %o5
F00D1B28: 9932e018                 srl     %o3, 24, %o4
F00D1B2C: 9213400c                 or      %o5, %o4, %o1
F00D1B30: 98924000                 orcc    %o1, %g0, %o4
F00D1B34: 12800003                 bne     loc_F00D1B40
F00D1B38: 9132a018                 srl     %o2, 24, %o0
F00D1B3C: 98102001                 mov     1, %o4
F00D1B40: 90100018                 mov     %i0, %o0! id
F00D1B44: 92100011                 mov     %l1, %o1! SEL
F00D1B48: 9410001a                 mov     %i2, %o2
F00D1B4C: 96100010                 mov     %l0, %o3
F00D1B50: 40007f48                 call    _objc_msgSend
F00D1B54: 9a07bfd8                 add     %fp, var_28, %o5
F00D1B58: d0062110                 ld      [%i0+0x110], %o0! id
F00D1B5C: 133c0504                 sethi   %hi(paUnlock), %o1
F00D1B60: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00D1B64: 40007f43                 call    _objc_msgSend
F00D1B68: a2102000                 mov     0, %l1
F00D1B6C: 3080002a                 ba,a    locret_F00D1C14
F00D1B70: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D1B74: 40007f3f                 call    _objc_msgSend
F00D1B78: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D1B7C: e0062174                 ld      [%i0+0x174], %l0
F00D1B80: 90062174                 add     %i0, 0x174, %o0
F00D1B84: 80a20010                 cmp     %o0, %l0
F00D1B88: 22800012                 be,a    loc_F00D1BD0
F00D1B8C: d0062170                 ld      [%i0+0x170], %o0
F00D1B90: 273c0504                 sethi   %hi(paSetintvaluesFo_0), %l3
F00D1B94: a4100008                 mov     %o0, %l2
F00D1B98: d204e280                 ld      [%l3+%lo(paSetintvaluesFo_0)], %o1! SEL
F00D1B9C: 9410001a                 mov     %i2, %o2
F00D1BA0: d0040000                 ld      [%l0], %o0! id
F00D1BA4: 9610001b                 mov     %i3, %o3
F00D1BA8: e0042004                 ld      [%l0+4], %l0
F00D1BAC: 40007f31                 call    _objc_msgSend
F00D1BB0: 9810001c                 mov     %i4, %o4
F00D1BB4: 80a23d3e                 cmp     %o0, -0x2C2
F00D1BB8: 32800002                 bne,a   loc_F00D1BC0
F00D1BBC: a2100008                 mov     %o0, %l1
F00D1BC0: 80a48010                 cmp     %l2, %l0
F00D1BC4: 32bffff6                 bne,a   loc_F00D1B9C
F00D1BC8: d204e280                 ld      [%l3+0x280], %o1
F00D1BCC: d0062170                 ld      [%i0+0x170], %o0! id
F00D1BD0: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D1BD4: 40007f27                 call    _objc_msgSend
F00D1BD8: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D1BDC: 80a47d3e                 cmp     %l1, -0x2C2
F00D1BE0: 1280000d                 bne     locret_F00D1C14
F00D1BE4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00D1BE8: f027bff0                 st      %i0, [%fp+var_10]
F00D1BEC: 9410001a                 mov     %i2, %o2
F00D1BF0: 9610001b                 mov     %i3, %o3
F00D1BF4: 133c0508                 sethi   %hi(stru_F01421DC.super_class), %o1
F00D1BF8: da0261e0                 ld      [%o1+%lo(stru_F01421DC.super_class)], %o5
F00D1BFC: 9810001c                 mov     %i4, %o4
F00D1C00: 133c0504                 sethi   %hi(paSetintvaluesFo_0), %o1
F00D1C04: d2026280                 ld      [%o1+%lo(paSetintvaluesFo_0)], %o1! SEL
F00D1C08: 40007f5d                 call    _objc_msgSendSuper
F00D1C0C: da27bff4                 st      %o5, [%fp+var_C]
F00D1C10: a2100008                 mov     %o0, %l1
F00D1C14: 81c7e008                 ret
F00D1C18: 91e80011                 restore %g0, %l1, %o0
