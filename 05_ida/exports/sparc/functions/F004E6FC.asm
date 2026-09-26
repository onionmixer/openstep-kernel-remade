F004E6FC: 9de3be98                 save    %sp, -0x168, %sp
F004E700: c027befc                 clr     [%fp+var_104]
F004E704: ac102000                 mov     0, %l6
F004E708: d2162044                 lduh    [%i0+0x44], %o1
F004E70C: 1100003f901223fe         set     0xFFFE, %o0
F004E714: 920a4008                 and     %o1, %o0, %o1
F004E718: 808a6010                 btst    0x10, %o1
F004E71C: 02800008                 be      loc_F004E73C
F004E720: d2362044                 sth     %o1, [%i0+0x44]
F004E724: 1100003f901223ef         set     0xFFEF, %o0
F004E72C: 900a4008                 and     %o1, %o0, %o0
F004E730: d0362044                 sth     %o0, [%i0+0x44]
F004E734: 7fff11ad                 call    _wakeup
F004E738: 90100018                 mov     %i0, %o0
F004E73C: 9006200c                 add     %i0, 0xC, %o0
F004E740: 400077ed                 call    _mfs_trunc
F004E744: 92100019                 mov     %i1, %o1
F004E748: d2162044                 lduh    [%i0+0x44], %o1
F004E74C: 808a6001                 btst    1, %o1
F004E750: 0280000b                 be      loc_F004E77C
F004E754: b6100008                 mov     %o0, %i3
F004E758: 90126010                 or      %o1, 0x10, %o0
F004E75C: d0362044                 sth     %o0, [%i0+0x44]
F004E760: 90100018                 mov     %i0, %o0! unsigned int
F004E764: 7fff0fc5                 call    _sleep
F004E768: 9210200a                 mov     0xA, %o1
F004E76C: d2162044                 lduh    [%i0+0x44], %o1
F004E770: 808a6001                 btst    1, %o1
F004E774: 12bffffa                 bne     loc_F004E75C
F004E778: 90126010                 or      %o1, 0x10, %o0
F004E77C: d0162044                 lduh    [%i0+0x44], %o0
F004E780: 90122001                 bset    1, %o0
F004E784: d0362044                 sth     %o0, [%i0+0x44]
F004E788: d0162064                 lduh    [%i0+0x64], %o0
F004E78C: 1300003c                 sethi   0xF000, %o1
F004E790: 900a0009                 and     %o0, %o1, %o0
F004E794: 13000028                 sethi   0xA000, %o1
F004E798: 80a20009                 cmp     %o0, %o1
F004E79C: 3280000f                 bne,a   loc_F004E7D8
F004E7A0: d2062070                 ld      [%i0+0x70], %o1
F004E7A4: d00620c8                 ld      [%i0+0xC8], %o0
F004E7A8: 808a2001                 btst    1, %o0
F004E7AC: 0280000a                 be      loc_F004E7D4
F004E7B0: a010200e                 mov     0xE, %l0
F004E7B4: 90062038                 add     %i0, 0x38, %o0 ! '8'
F004E7B8: c022208c                 clr     [%o0+0x8C]
F004E7BC: a0843fff                 inccc   -1, %l0
F004E7C0: 1cbffffe                 bpos    loc_F004E7B8
F004E7C4: 90023ffc                 inc     -4, %o0
F004E7C8: c02620c8                 clr     [%i0+0xC8]
F004E7CC: 10800006                 ba      loc_F004E7E4
F004E7D0: c0262070                 clr     [%i0+0x70]
F004E7D4: d2062070                 ld      [%i0+0x70], %o1
F004E7D8: 80a64009                 cmp     %i1, %o1
F004E7DC: 3280000a                 bne,a   loc_F004E804
F004E7E0: e8062050                 ld      [%i0+0x50], %l4
F004E7E4: 90100018                 mov     %i0, %o0
F004E7E8: d4122044                 lduh    [%o0+0x44], %o2
F004E7EC: 92102001                 mov     1, %o1
F004E7F0: 9412a042                 bset    0x42, %o2 ! 'B'
F004E7F4: 7fffff54                 call    _iupdat
F004E7F8: d4322044                 sth     %o2, [%o0+0x44]
F004E7FC: 1080017e                 ba      locret_F004EDF4
F004E800: b0102000                 mov     0, %i0
F004E804: d0052048                 ld      [%l4+0x48], %o0
F004E808: 80a64009                 cmp     %i1, %o1
F004E80C: d2052050                 ld      [%l4+0x50], %o1
F004E810: a42e4008                 andn    %i1, %o0, %l2
F004E814: 90067fff                 add     %i1, -1, %o0
F004E818: 08800040                 bleu    loc_F004E918
F004E81C: a3320009                 srl     %o0, %o1, %l1
F004E820: 80a4a000                 cmp     %l2, 0
F004E824: 12800006                 bne     loc_F004E83C
F004E828: 90100018                 mov     %i0, %o0
F004E82C: 92100011                 mov     %l1, %o1
F004E830: 94102000                 mov     0, %o2
F004E834: 10800005                 ba      loc_F004E848
F004E838: d6052030                 ld      [%l4+0x30], %o3
F004E83C: 92100011                 mov     %l1, %o1
F004E840: 94102000                 mov     0, %o2
F004E844: 96100012                 mov     %l2, %o3
F004E848: 7ffff0ab                 call    _bmap
F004E84C: 9807befc                 add     %fp, var_104, %o4
F004E850: a6100008                 mov     %o0, %l3
F004E854: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F004E858: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F004E85C: d04a2038                 ldsb    [%o0+0x38], %o0
F004E860: 80a22000                 cmp     %o0, 0
F004E864: 02800004                 be      loc_F004E874
F004E868: 80a4e000                 cmp     %l3, 0
F004E86C: 06800024                 bl      loc_F004E8FC
F004E870: d007befc                 ld      [%fp+var_104], %o0
F004E874: d0162044                 lduh    [%i0+0x44], %o0
F004E878: f2262070                 st      %i1, [%i0+0x70]
F004E87C: 90122040                 bset    0x40, %o0 ! '@'
F004E880: 808a2046                 btst    0x46, %o0 ! 'F'
F004E884: 0280001d                 be      loc_F004E8F8
F004E888: d0362044                 sth     %o0, [%i0+0x44]
F004E88C: 90122008                 bset    8, %o0
F004E890: d0362044                 sth     %o0, [%i0+0x44]
F004E894: 213c04d4                 sethi   %hi(_iuniqtime), %l0
F004E898: 40007f4e                 call    _microtime
F004E89C: 90142148                 or      %l0, %lo(_iuniqtime), %o0
F004E8A0: d0162044                 lduh    [%i0+0x44], %o0
F004E8A4: 808a2004                 btst    4, %o0
F004E8A8: 02800003                 be      loc_F004E8B4
F004E8AC: d0042148                 ld      [%l0+%lo(_iuniqtime)], %o0
F004E8B0: d0262074                 st      %o0, [%i0+0x74]
F004E8B4: d0162044                 lduh    [%i0+0x44], %o0
F004E8B8: 808a2002                 btst    2, %o0
F004E8BC: 02800003                 be      loc_F004E8C8
F004E8C0: d0042148                 ld      [%l0+0x148], %o0
F004E8C4: d026207c                 st      %o0, [%i0+0x7C]
F004E8C8: d0162044                 lduh    [%i0+0x44], %o0
F004E8CC: 808a2040                 btst    0x40, %o0 ! '@'
F004E8D0: 22800006                 be,a    loc_F004E8E8
F004E8D4: d2162044                 lduh    [%i0+0x44], %o1
F004E8D8: c026204c                 clr     [%i0+0x4C]
F004E8DC: d0042148                 ld      [%l0+0x148], %o0
F004E8E0: d0262084                 st      %o0, [%i0+0x84]
F004E8E4: d2162044                 lduh    [%i0+0x44], %o1
F004E8E8: 1100003f901223b9         set     0xFFB9, %o0
F004E8F0: 920a4008                 and     %o1, %o0, %o1
F004E8F4: d2362044                 sth     %o1, [%i0+0x44]
F004E8F8: d007befc                 ld      [%fp+var_104], %o0
F004E8FC: 80a22000                 cmp     %o0, 0
F004E900: 0280013a                 be      loc_F004EDE8
F004E904: 90100018                 mov     %i0, %o0
F004E908: 7fffff0f                 call    _iupdat
F004E90C: 92102001                 mov     1, %o1
F004E910: 10800137                 ba      loc_F004EDEC
F004E914: 113c04cf                 sethi   -0xFECC400, %o0
F004E918: d4052030                 ld      [%l4+0x30], %o2
F004E91C: 9406400a                 add     %i1, %o2, %o2
F004E920: 9402bfff                 inc     -1, %o2
F004E924: 95328009                 srl     %o2, %o1, %o2
F004E928: a002bff3                 add     %o2, -0xD, %l0
F004E92C: e027bfe8                 st      %l0, [%fp+var_18]
F004E930: d0052074                 ld      [%l4+0x74], %o0
F004E934: a0240008                 sub     %l0, %o0, %l0
F004E938: e027bfec                 st      %l0, [%fp+var_14]
F004E93C: d0052074                 ld      [%l4+0x74], %o0
F004E940: ae02bfff                 add     %o2, -1, %l7
F004E944: 7ffedeef                 call    _umul
F004E948: 92100008                 mov     %o0, %o1
F004E94C: a0240008                 sub     %l0, %o0, %l0
F004E950: e027bff0                 st      %l0, [%fp+var_10]
F004E954: d0062028                 ld      [%i0+0x28], %o0
F004E958: d2022080                 ld      [%o0+0x80], %o1
F004E95C: 9fc24000                 call    %o1
F004E960: 9006200c                 add     %i0, 0xC, %o0! int
F004E964: 92100008                 mov     %o0, %o1! int
F004E968: 7ffedf28                 call    _div
F004E96C: d0052030                 ld      [%l4+0x30], %o0
F004E970: 80a4a000                 cmp     %l2, 0
F004E974: ea062070                 ld      [%i0+0x70], %l5
F004E978: 12800004                 bne     loc_F004E988
F004E97C: b4100008                 mov     %o0, %i2
F004E980: 10800045                 ba      loc_F004EA94
F004E984: f2262070                 st      %i1, [%i0+0x70]
F004E988: 90100018                 mov     %i0, %o0
F004E98C: 92100011                 mov     %l1, %o1
F004E990: 94102000                 mov     0, %o2
F004E994: 96100012                 mov     %l2, %o3
F004E998: 7ffff057                 call    _bmap
F004E99C: 98102000                 mov     0, %o4
F004E9A0: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F004E9A4: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F004E9A8: d4052064                 ld      [%l4+0x64], %o2
F004E9AC: d24a6038                 ldsb    [%o1+0x38], %o1
F004E9B0: 80a26000                 cmp     %o1, 0
F004E9B4: 12800005                 bne     loc_F004E9C8
F004E9B8: a72a000a                 sll     %o0, %o2, %l3
F004E9BC: 80a4e000                 cmp     %l3, 0
F004E9C0: 16800004                 bge     loc_F004E9D0
F004E9C4: 80a4600b                 cmp     %l1, 0xB
F004E9C8: 1080010b                 ba      locret_F004EDF4
F004E9CC: b0100009                 mov     %o1, %i0
F004E9D0: 14800008                 bg      loc_F004E9F0
F004E9D4: f2262070                 st      %i1, [%i0+0x70]
F004E9D8: d2052050                 ld      [%l4+0x50], %o1
F004E9DC: 90046001                 add     %l1, 1, %o0
F004E9E0: 912a0009                 sll     %o0, %o1, %o0
F004E9E4: 80a64008                 cmp     %i1, %o0
F004E9E8: 2a800004                 bcs,a   loc_F004E9F8
F004E9EC: d0052048                 ld      [%l4+0x48], %o0
F004E9F0: 10800008                 ba      loc_F004EA10
F004E9F4: e2052030                 ld      [%l4+0x30], %l1
F004E9F8: d2052034                 ld      [%l4+0x34], %o1
F004E9FC: 902e4008                 andn    %i1, %o0, %o0
F004EA00: 90020009                 add     %o0, %o1, %o0
F004EA04: d205204c                 ld      [%l4+0x4C], %o1
F004EA08: 90023fff                 inc     -1, %o0
F004EA0C: a20a0009                 and     %o0, %o1, %l1
F004EA10: d006200c                 ld      [%i0+0xC], %o0
F004EA14: d0020000                 ld      [%o0], %o0
F004EA18: 80a22000                 cmp     %o0, 0
F004EA1C: 02800004                 be      loc_F004EA2C
F004EA20: e0062040                 ld      [%i0+0x40], %l0
F004EA24: 4000f5e7                 call    _vnode_uncache
F004EA28: 9006200c                 add     %i0, 0xC, %o0
F004EA2C: 80a6e000                 cmp     %i3, 0
F004EA30: 1280001a                 bne     loc_F004EA98
F004EA34: 9007bf00                 add     %fp, var_100, %o0
F004EA38: 90100010                 mov     %l0, %o0
F004EA3C: 92100013                 mov     %l3, %o1
F004EA40: 7fff56b8                 call    _bread
F004EA44: 94100011                 mov     %l1, %o2
F004EA48: a0100008                 mov     %o0, %l0
F004EA4C: d0040000                 ld      [%l0], %o0
F004EA50: 808a2004                 btst    4, %o0
F004EA54: 0280000a                 be      loc_F004EA7C
F004EA58: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F004EA5C: d40261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o2! __n
F004EA60: 90100010                 mov     %l0, %o0
F004EA64: 92102005                 mov     5, %o1
F004EA68: d22aa038                 stb     %o1, [%o2+0x38]
F004EA6C: 7fff577f                 call    _brelse
F004EA70: ea262070                 st      %l5, [%i0+0x70]
F004EA74: 108000e0                 ba      locret_F004EDF4
F004EA78: b0102005                 mov     5, %i0
F004EA7C: d0042020                 ld      [%l0+0x20], %o0! void *
F004EA80: 92244012                 sub     %l1, %l2, %o1! size_t
F004EA84: 400118f5                 call    _bzero
F004EA88: 90020012                 add     %o0, %l2, %o0
F004EA8C: 7fff575e                 call    _bdwrite
F004EA90: 90100010                 mov     %l0, %o0
F004EA94: 9007bf00                 add     %fp, var_100, %o0! __dst
F004EA98: 92100018                 mov     %i0, %o1! __src
F004EA9C: 7ffee201                 call    _memcpy
F004EAA0: 941020e8                 mov     0xE8, %o2
F004EAA4: ea27bf70                 st      %l5, [%fp+var_90]
F004EAA8: a0102002                 mov     2, %l0
F004EAAC: 96103fff                 mov     -1, %o3
F004EAB0: 94062008                 add     %i0, 8, %o2
F004EAB4: 9210001e                 mov     %fp, %o1
F004EAB8: d0027ff0                 ld      [%o1-0x10], %o0
F004EABC: 80a22000                 cmp     %o0, 0
F004EAC0: 36800005                 bge,a   loc_F004EAD4
F004EAC4: 9402bffc                 inc     -4, %o2
F004EAC8: c022a0bc                 clr     [%o2+0xBC]
F004EACC: d6227ff0                 st      %o3, [%o1-0x10]
F004EAD0: 9402bffc                 inc     -4, %o2
F004EAD4: a0843fff                 inccc   -1, %l0
F004EAD8: 1cbffff8                 bpos    loc_F004EAB8
F004EADC: 92027ffc                 inc     -4, %o1
F004EAE0: a010200b                 mov     0xB, %l0
F004EAE4: 80a40017                 cmp     %l0, %l7
F004EAE8: 04800007                 ble     loc_F004EB04
F004EAEC: 9006202c                 add     %i0, 0x2C, %o0 ! ','
F004EAF0: c022208c                 clr     [%o0+0x8C]
F004EAF4: a0043fff                 inc     -1, %l0
F004EAF8: 80a40017                 cmp     %l0, %l7
F004EAFC: 14bffffd                 bg      loc_F004EAF0
F004EB00: 90023ffc                 inc     -4, %o0
F004EB04: f2262070                 st      %i1, [%i0+0x70]
F004EB08: 90100018                 mov     %i0, %o0
F004EB0C: 92102001                 mov     1, %o1
F004EB10: d4162044                 lduh    [%i0+0x44], %o2
F004EB14: a0102002                 mov     2, %l0
F004EB18: 9412a042                 bset    0x42, %o2 ! 'B'
F004EB1C: 7ffffe8a                 call    _iupdat
F004EB20: d4362044                 sth     %o2, [%i0+0x44]
F004EB24: aa07bf00                 add     %fp, var_100, %l5
F004EB28: a210001e                 mov     %fp, %l1
F004EB2C: a407bf08                 add     %fp, var_F8, %l2
F004EB30: e604a0bc                 ld      [%l2+0xBC], %l3
F004EB34: 80a4e000                 cmp     %l3, 0
F004EB38: 02800010                 be      loc_F004EB78
F004EB3C: 90100015                 mov     %l5, %o0
F004EB40: 92100013                 mov     %l3, %o1
F004EB44: d4047ff0                 ld      [%l1-0x10], %o2
F004EB48: 400000ad                 call    _indirtrunc
F004EB4C: 96100010                 mov     %l0, %o3
F004EB50: d2047ff0                 ld      [%l1-0x10], %o1
F004EB54: 80a26000                 cmp     %o1, 0
F004EB58: 16800008                 bge     loc_F004EB78
F004EB5C: ac058008                 add     %l6, %o0, %l6
F004EB60: c024a0bc                 clr     [%l2+0xBC]
F004EB64: 90100015                 mov     %l5, %o0
F004EB68: 92100013                 mov     %l3, %o1
F004EB6C: d4052030                 ld      [%l4+0x30], %o2
F004EB70: 7fffed82                 call    _free_block
F004EB74: ac05801a                 add     %l6, %i2, %l6
F004EB78: d0047ff0                 ld      [%l1-0x10], %o0
F004EB7C: 80a22000                 cmp     %o0, 0
F004EB80: 16800071                 bge     loc_F004ED44
F004EB84: a2047ffc                 inc     -4, %l1
F004EB88: a0843fff                 inccc   -1, %l0
F004EB8C: 1cbfffe9                 bpos    loc_F004EB30
F004EB90: a404bffc                 inc     -4, %l2
F004EB94: a010200b                 mov     0xB, %l0
F004EB98: 80a40017                 cmp     %l0, %l7
F004EB9C: 0480002a                 ble     loc_F004EC44
F004EBA0: 80a5e000                 cmp     %l7, 0
F004EBA4: a405602c                 add     %l5, 0x2C, %l2 ! ','
F004EBA8: e604a08c                 ld      [%l2+0x8C], %l3
F004EBAC: 80a4e000                 cmp     %l3, 0
F004EBB0: 22800021                 be,a    loc_F004EC34
F004EBB4: a0043fff                 inc     -1, %l0
F004EBB8: 80a4200b                 cmp     %l0, 0xB
F004EBBC: 14800009                 bg      loc_F004EBE0
F004EBC0: c024a08c                 clr     [%l2+0x8C]
F004EBC4: d2052050                 ld      [%l4+0x50], %o1
F004EBC8: 90042001                 add     %l0, 1, %o0
F004EBCC: d4056070                 ld      [%l5+0x70], %o2
F004EBD0: 912a0009                 sll     %o0, %o1, %o0
F004EBD4: 80a28008                 cmp     %o2, %o0
F004EBD8: 2a800004                 bcs,a   loc_F004EBE8
F004EBDC: d0052048                 ld      [%l4+0x48], %o0
F004EBE0: 10800008                 ba      loc_F004EC00
F004EBE4: e2052030                 ld      [%l4+0x30], %l1
F004EBE8: d2052034                 ld      [%l4+0x34], %o1
F004EBEC: 902a8008                 andn    %o2, %o0, %o0
F004EBF0: 90020009                 add     %o0, %o1, %o0
F004EBF4: d205204c                 ld      [%l4+0x4C], %o1
F004EBF8: 90023fff                 inc     -1, %o0
F004EBFC: a20a0009                 and     %o0, %o1, %l1
F004EC00: 90100015                 mov     %l5, %o0
F004EC04: 92100013                 mov     %l3, %o1
F004EC08: 7fffed5c                 call    _free_block
F004EC0C: 94100011                 mov     %l1, %o2
F004EC10: d0062028                 ld      [%i0+0x28], %o0
F004EC14: d2022080                 ld      [%o0+0x80], %o1
F004EC18: 9fc24000                 call    %o1
F004EC1C: 9006200c                 add     %i0, 0xC, %o0
F004EC20: 92100008                 mov     %o0, %o1
F004EC24: 7ffede77                 call    _udiv
F004EC28: 90100011                 mov     %l1, %o0
F004EC2C: ac058008                 add     %l6, %o0, %l6
F004EC30: a0043fff                 inc     -1, %l0
F004EC34: 80a40017                 cmp     %l0, %l7
F004EC38: 14bfffdc                 bg      loc_F004EBA8
F004EC3C: a404bffc                 inc     -4, %l2
F004EC40: 80a5e000                 cmp     %l7, 0
F004EC44: 06800040                 bl      loc_F004ED44
F004EC48: 912de002                 sll     %l7, 2, %o0
F004EC4C: 90020015                 add     %o0, %l5, %o0
F004EC50: e602208c                 ld      [%o0+0x8C], %l3
F004EC54: 80a4e000                 cmp     %l3, 0
F004EC58: 0280003b                 be      loc_F004ED44
F004EC5C: 80a5e00b                 cmp     %l7, 0xB
F004EC60: 34800012                 bg,a    loc_F004ECA8
F004EC64: e0052030                 ld      [%l4+0x30], %l0
F004EC68: d2052050                 ld      [%l4+0x50], %o1
F004EC6C: 9005e001                 add     %l7, 1, %o0
F004EC70: d4056070                 ld      [%l5+0x70], %o2
F004EC74: 912a0009                 sll     %o0, %o1, %o0
F004EC78: 80a28008                 cmp     %o2, %o0
F004EC7C: 2a800004                 bcs,a   loc_F004EC8C
F004EC80: d0052048                 ld      [%l4+0x48], %o0
F004EC84: 10800008                 ba      loc_F004ECA4
F004EC88: e0052030                 ld      [%l4+0x30], %l0
F004EC8C: d2052034                 ld      [%l4+0x34], %o1
F004EC90: 902a8008                 andn    %o2, %o0, %o0
F004EC94: 90020009                 add     %o0, %o1, %o0
F004EC98: d205204c                 ld      [%l4+0x4C], %o1
F004EC9C: 90023fff                 inc     -1, %o0
F004ECA0: a00a0009                 and     %o0, %o1, %l0
F004ECA4: 80a5e00b                 cmp     %l7, 0xB
F004ECA8: 14800008                 bg      loc_F004ECC8
F004ECAC: f2256070                 st      %i1, [%l5+0x70]
F004ECB0: d2052050                 ld      [%l4+0x50], %o1
F004ECB4: 9005e001                 add     %l7, 1, %o0
F004ECB8: 912a0009                 sll     %o0, %o1, %o0
F004ECBC: 80a64008                 cmp     %i1, %o0
F004ECC0: 2a800004                 bcs,a   loc_F004ECD0
F004ECC4: d0052048                 ld      [%l4+0x48], %o0
F004ECC8: 10800008                 ba      loc_F004ECE8
F004ECCC: e2052030                 ld      [%l4+0x30], %l1
F004ECD0: d2052034                 ld      [%l4+0x34], %o1
F004ECD4: 902e4008                 andn    %i1, %o0, %o0
F004ECD8: 90020009                 add     %o0, %o1, %o0
F004ECDC: d205204c                 ld      [%l4+0x4C], %o1
F004ECE0: 90023fff                 inc     -1, %o0
F004ECE4: a20a0009                 and     %o0, %o1, %l1
F004ECE8: 80a46000                 cmp     %l1, 0
F004ECEC: 12800006                 bne     loc_F004ED04
F004ECF0: 80a40011                 cmp     %l0, %l1
F004ECF4: 113c043b                 sethi   %hi(aItruncNewspace), %o0! "itrunc: newspace"
F004ECF8: 7fff191e                 call    _panic
F004ECFC: 901220b0                 bset    %lo(aItruncNewspace), %o0! "itrunc: newspace"
F004ED00: 80a40011                 cmp     %l0, %l1
F004ED04: 02800010                 be      loc_F004ED44
F004ED08: 90100015                 mov     %l5, %o0
F004ED0C: a0240011                 sub     %l0, %l1, %l0
F004ED10: d2052054                 ld      [%l4+0x54], %o1
F004ED14: 94100010                 mov     %l0, %o2
F004ED18: 93344009                 srl     %l1, %o1, %o1
F004ED1C: 7fffed17                 call    _free_block
F004ED20: 9204c009                 add     %l3, %o1, %o1
F004ED24: d0062028                 ld      [%i0+0x28], %o0
F004ED28: d2022080                 ld      [%o0+0x80], %o1
F004ED2C: 9fc24000                 call    %o1
F004ED30: 9006200c                 add     %i0, 0xC, %o0
F004ED34: 92100008                 mov     %o0, %o1
F004ED38: 7ffede32                 call    _udiv
F004ED3C: 90100010                 mov     %l0, %o0
F004ED40: ac058008                 add     %l6, %o0, %l6
F004ED44: a0102000                 mov     0, %l0
F004ED48: 253c043b                 sethi   -0xFEF1400, %l2
F004ED4C: b2100018                 mov     %i0, %i1
F004ED50: a2100015                 mov     %l5, %l1
F004ED54: d20460bc                 ld      [%l1+0xBC], %o1
F004ED58: d00660bc                 ld      [%i1+0xBC], %o0! char *
F004ED5C: 80a24008                 cmp     %o1, %o0
F004ED60: 22800005                 be,a    loc_F004ED74
F004ED64: b2066004                 inc     4, %i1
F004ED68: 7fff1902                 call    _panic
F004ED6C: 9014a0c8                 or      %l2, 0xC8, %o0
F004ED70: b2066004                 inc     4, %i1
F004ED74: a0042001                 inc     %l0
F004ED78: 80a42002                 cmp     %l0, 2
F004ED7C: 04bffff6                 ble     loc_F004ED54
F004ED80: a2046004                 inc     4, %l1
F004ED84: a0102000                 mov     0, %l0
F004ED88: 253c043b                 sethi   -0xFEF1400, %l2
F004ED8C: b2100018                 mov     %i0, %i1
F004ED90: a2100015                 mov     %l5, %l1
F004ED94: d204608c                 ld      [%l1+0x8C], %o1
F004ED98: d006608c                 ld      [%i1+0x8C], %o0! char *
F004ED9C: 80a24008                 cmp     %o1, %o0
F004EDA0: 22800005                 be,a    loc_F004EDB4
F004EDA4: b2066004                 inc     4, %i1
F004EDA8: 7fff18f2                 call    _panic
F004EDAC: 9014a0d0                 or      %l2, 0xD0, %o0
F004EDB0: b2066004                 inc     4, %i1
F004EDB4: a0042001                 inc     %l0
F004EDB8: 80a4200b                 cmp     %l0, 0xB
F004EDBC: 04bffff6                 ble     loc_F004ED94
F004EDC0: a2046004                 inc     4, %l1
F004EDC4: d00620cc                 ld      [%i0+0xCC], %o0
F004EDC8: 90220016                 sub     %o0, %l6, %o0
F004EDCC: 80a22000                 cmp     %o0, 0
F004EDD0: 16800003                 bge     loc_F004EDDC
F004EDD4: d02620cc                 st      %o0, [%i0+0xCC]
F004EDD8: c02620cc                 clr     [%i0+0xCC]
F004EDDC: d0162044                 lduh    [%i0+0x44], %o0
F004EDE0: 90122040                 bset    0x40, %o0 ! '@'
F004EDE4: d0362044                 sth     %o0, [%i0+0x44]
F004EDE8: 113c04cf                 sethi   -0xFECC400, %o0
F004EDEC: d00221dc                 ld      [%o0+0x1DC], %o0
F004EDF0: f04a2038                 ldsb    [%o0+0x38], %i0
F004EDF4: 81c7e008                 ret
F004EDF8: 81e80000                 restore
