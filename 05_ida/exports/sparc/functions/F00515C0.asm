F00515C0: 9de3bf80                 save    %sp, -0x80, %sp
F00515C4: b8102000                 mov     0, %i4
F00515C8: c027bff4                 clr     [%fp+var_C]
F00515CC: c4066014                 ld      [%i1+0x14], %g2
F00515D0: 80a6a001                 cmp     %i2, 1
F00515D4: 08800005                 bleu    loc_F00515E8
F00515D8: c427bfec                 st      %g2, [%fp+var_14]
F00515DC: 113c043c                 sethi   %hi(aRwip), %o0! "rwip"
F00515E0: 7fff0ee4                 call    _panic
F00515E4: 901221f0                 bset    %lo(aRwip), %o0! "rwip"
F00515E8: d0162064                 lduh    [%i0+0x64], %o0
F00515EC: 1300003c                 sethi   0xF000, %o1
F00515F0: ac0a0009                 and     %o0, %o1, %l6
F00515F4: 11000020                 sethi   0x8000, %o0
F00515F8: 80a58008                 cmp     %l6, %o0
F00515FC: 2280000e                 be,a    loc_F0051634
F0051600: d2066008                 ld      [%i1+8], %o1
F0051604: 11000010                 sethi   0x4000, %o0
F0051608: 80a58008                 cmp     %l6, %o0
F005160C: 2280000a                 be,a    loc_F0051634
F0051610: d2066008                 ld      [%i1+8], %o1
F0051614: 11000028                 sethi   0xA000, %o0
F0051618: 80a58008                 cmp     %l6, %o0
F005161C: 22800006                 be,a    loc_F0051634
F0051620: d2066008                 ld      [%i1+8], %o1
F0051624: 113c043c                 sethi   %hi(aRwipType), %o0! "rwip type"
F0051628: 7fff0ed2                 call    _panic
F005162C: 901221f8                 bset    %lo(aRwipType), %o0! "rwip type"
F0051630: d2066008                 ld      [%i1+8], %o1
F0051634: 80a26000                 cmp     %o1, 0
F0051638: 26800144                 bl,a    locret_F0051B48
F005163C: b0102016                 mov     0x16, %i0
F0051640: d0066014                 ld      [%i1+0x14], %o0
F0051644: 94824008                 addcc   %o1, %o0, %o2
F0051648: 1c800004                 bpos    loc_F0051658
F005164C: 80a22000                 cmp     %o0, 0
F0051650: 1080013e                 ba      locret_F0051B48
F0051654: b0102016                 mov     0x16, %i0
F0051658: 12800004                 bne     loc_F0051668
F005165C: 80a6a001                 cmp     %i2, 1
F0051660: 1080013a                 ba      locret_F0051B48
F0051664: b0102000                 mov     0, %i0
F0051668: 32800018                 bne,a   loc_F00516C8
F005166C: d0162044                 lduh    [%i0+0x44], %o0
F0051670: 11000020                 sethi   0x8000, %o0
F0051674: 80a58008                 cmp     %l6, %o0
F0051678: 12800017                 bne     loc_F00516D4
F005167C: 901ea001                 xor     %i2, 1, %o0
F0051680: 113c04cf                 sethi   %hi(_active_u), %o0
F0051684: d20221d8                 ld      [%o0+%lo(_active_u)], %o1! char *
F0051688: d0026268                 ld      [%o1+0x268], %o0
F005168C: 80a28008                 cmp     %o2, %o0
F0051690: 08800011                 bleu    loc_F00516D4
F0051694: 901ea001                 xor     %i2, 1, %o0
F0051698: d0024000                 ld      [%o1], %o0! unsigned int
F005169C: 7ffeffb6                 call    _psignal
F00516A0: 92102019                 mov     0x19, %o1
F00516A4: 10800129                 ba      locret_F0051B48
F00516A8: b010201b                 mov     0x1B, %i0
F00516AC: 10800126                 ba      loc_F0051B44
F00516B0: b8102000                 mov     0, %i4
F00516B4: b8102005                 mov     5, %i4
F00516B8: 7fff4c6c                 call    _brelse
F00516BC: 90100010                 mov     %l0, %o0
F00516C0: 10800122                 ba      locret_F0051B48
F00516C4: b010001c                 mov     %i4, %i0
F00516C8: 90122004                 bset    4, %o0
F00516CC: d0362044                 sth     %o0, [%i0+0x44]
F00516D0: 901ea001                 xor     %i2, 1, %o0
F00516D4: 80a00008                 cmp     %g0, %o0
F00516D8: ee062040                 ld      [%i0+0x40], %l7
F00516DC: 113c04cf                 sethi   -0xFECC400, %o0
F00516E0: e8062050                 ld      [%i0+0x50], %l4
F00516E4: ba100008                 mov     %o0, %i5
F00516E8: d00761dc                 ld      [%i5+0x1DC], %o0
F00516EC: 84402000                 addc    %g0, 0, %g2
F00516F0: ea052030                 ld      [%l4+0x30], %l5
F00516F4: c427bfe4                 st      %g2, [%fp+var_1C]
F00516F8: c02a2038                 clrb    [%o0+0x38]
F00516FC: e0066008                 ld      [%i1+8], %l0
F0051700: 92100015                 mov     %l5, %o1
F0051704: 7ffed3bf                 call    _udiv
F0051708: 90100010                 mov     %l0, %o0
F005170C: a4100008                 mov     %o0, %l2
F0051710: 90100010                 mov     %l0, %o0
F0051714: 7ffed463                 call    _urem
F0051718: 92100015                 mov     %l5, %o1
F005171C: a6100008                 mov     %o0, %l3
F0051720: d0066014                 ld      [%i1+0x14], %o0
F0051724: 92254013                 sub     %l5, %l3, %o1
F0051728: 80a24008                 cmp     %o1, %o0
F005172C: 1a800003                 bcc     loc_F0051738
F0051730: a2100008                 mov     %o0, %l1
F0051734: a2100009                 mov     %o1, %l1
F0051738: 80a6a000                 cmp     %i2, 0
F005173C: 1280000a                 bne     loc_F0051764
F0051740: 808ee004                 btst    4, %i3
F0051744: d0062070                 ld      [%i0+0x70], %o0
F0051748: 90220010                 sub     %o0, %l0, %o0
F005174C: 80a22000                 cmp     %o0, 0
F0051750: 04bfffd7                 ble     loc_F00516AC
F0051754: 80a20011                 cmp     %o0, %l1
F0051758: 26800002                 bl,a    loc_F0051760
F005175C: a2100008                 mov     %o0, %l1
F0051760: 808ee004                 btst    4, %i3
F0051764: 98102000                 mov     0, %o4
F0051768: 02800003                 be      loc_F0051774
F005176C: 9604c011                 add     %l3, %l1, %o3
F0051770: 9807bff4                 add     %fp, var_C, %o4
F0051774: 90100018                 mov     %i0, %o0
F0051778: d407bfe4                 ld      [%fp+var_1C], %o2
F005177C: 7fffe4de                 call    _bmap
F0051780: 92100012                 mov     %l2, %o1
F0051784: d60761dc                 ld      [%i5+0x1DC], %o3
F0051788: d4052064                 ld      [%l4+0x64], %o2
F005178C: d24ae038                 ldsb    [%o3+0x38], %o1
F0051790: 80a2601c                 cmp     %o1, 0x1C
F0051794: 12800014                 bne     loc_F00517E4
F0051798: 992a000a                 sll     %o0, %o2, %o4
F005179C: 80a6a001                 cmp     %i2, 1
F00517A0: 12800012                 bne     loc_F00517E8
F00517A4: d00761dc                 ld      [%i5+0x1DC], %o0
F00517A8: d0066014                 ld      [%i1+0x14], %o0
F00517AC: c407bfec                 ld      [%fp+var_14], %g2
F00517B0: 90208008                 sub     %g2, %o0, %o0
F00517B4: 80a22000                 cmp     %o0, 0
F00517B8: 0480000c                 ble     loc_F00517E8
F00517BC: d00761dc                 ld      [%i5+0x1DC], %o0
F00517C0: 053c04cf8410a1dc         set     dword_F0133DDC, %g2
F00517C8: d000bffc                 ld      [%g2-4], %o0
F00517CC: d0020000                 ld      [%o0], %o0
F00517D0: d0022014                 ld      [%o0+0x14], %o0
F00517D4: 05000010                 sethi   0x4000, %g2
F00517D8: 808a0002                 btst    %g2, %o0
F00517DC: 328000ce                 bne,a   loc_F0051B14
F00517E0: c02ae038                 clrb    [%o3+0x38]
F00517E4: d00761dc                 ld      [%i5+0x1DC], %o0
F00517E8: d04a2038                 ldsb    [%o0+0x38], %o0
F00517EC: 80a22000                 cmp     %o0, 0
F00517F0: 328000d5                 bne,a   loc_F0051B44
F00517F4: b8100008                 mov     %o0, %i4
F00517F8: 80a6a001                 cmp     %i2, 1
F00517FC: 12800026                 bne     loc_F0051894
F0051800: 80a4a00b                 cmp     %l2, 0xB
F0051804: 80a32000                 cmp     %o4, 0
F0051808: 16800004                 bge     loc_F0051818
F005180C: 80a6a001                 cmp     %i2, 1
F0051810: 108000cd                 ba      loc_F0051B44
F0051814: b8100008                 mov     %o0, %i4
F0051818: 1280001f                 bne     loc_F0051894
F005181C: 80a4a00b                 cmp     %l2, 0xB
F0051820: d0066008                 ld      [%i1+8], %o0
F0051824: d2062070                 ld      [%i0+0x70], %o1
F0051828: 90020011                 add     %o0, %l1, %o0
F005182C: 80a20009                 cmp     %o0, %o1
F0051830: 08800019                 bleu    loc_F0051894
F0051834: 80a4a00b                 cmp     %l2, 0xB
F0051838: 05000010                 sethi   0x4000, %g2
F005183C: 80a58002                 cmp     %l6, %g2
F0051840: 02800008                 be      loc_F0051860
F0051844: 11000020                 sethi   0x8000, %o0
F0051848: 80a58008                 cmp     %l6, %o0
F005184C: 02800005                 be      loc_F0051860
F0051850: 11000028                 sethi   0xA000, %o0
F0051854: 80a58008                 cmp     %l6, %o0
F0051858: 1280000f                 bne     loc_F0051894
F005185C: 80a4a00b                 cmp     %l2, 0xB
F0051860: d0066008                 ld      [%i1+8], %o0
F0051864: d406200c                 ld      [%i0+0xC], %o2
F0051868: 92020011                 add     %o0, %l1, %o1
F005186C: d2262070                 st      %o1, [%i0+0x70]
F0051870: d002a014                 ld      [%o2+0x14], %o0
F0051874: 80a24008                 cmp     %o1, %o0
F0051878: 38800002                 bgu,a   loc_F0051880
F005187C: d222a014                 st      %o1, [%o2+0x14]
F0051880: 808ee004                 btst    4, %i3
F0051884: 02800003                 be      loc_F0051890
F0051888: 90102001                 mov     1, %o0
F005188C: d027bff4                 st      %o0, [%fp+var_C]
F0051890: 80a4a00b                 cmp     %l2, 0xB
F0051894: 34800011                 bg,a    loc_F00518D8
F0051898: da052030                 ld      [%l4+0x30], %o5
F005189C: d2052050                 ld      [%l4+0x50], %o1
F00518A0: 9004a001                 add     %l2, 1, %o0
F00518A4: d4062070                 ld      [%i0+0x70], %o2
F00518A8: 912a0009                 sll     %o0, %o1, %o0
F00518AC: 80a28008                 cmp     %o2, %o0
F00518B0: 2a800004                 bcs,a   loc_F00518C0
F00518B4: d0052048                 ld      [%l4+0x48], %o0
F00518B8: 10800008                 ba      loc_F00518D8
F00518BC: da052030                 ld      [%l4+0x30], %o5
F00518C0: d2052034                 ld      [%l4+0x34], %o1
F00518C4: 902a8008                 andn    %o2, %o0, %o0
F00518C8: 90020009                 add     %o0, %o1, %o0
F00518CC: d205204c                 ld      [%l4+0x4C], %o1! size_t
F00518D0: 90023fff                 inc     -1, %o0
F00518D4: 9a0a0009                 and     %o0, %o1, %o5
F00518D8: 80a6a000                 cmp     %i2, 0
F00518DC: 12800020                 bne     loc_F005195C
F00518E0: 80a44015                 cmp     %l1, %l5
F00518E4: 80a32000                 cmp     %o4, 0
F00518E8: 3680000a                 bge,a   loc_F0051910
F00518EC: d0062058                 ld      [%i0+0x58], %o0
F00518F0: 7fff4cd6                 call    _geteblk
F00518F4: 9010000d                 mov     %o5, %o0
F00518F8: a0100008                 mov     %o0, %l0
F00518FC: d0042020                 ld      [%l0+0x20], %o0! void *
F0051900: 40010d56                 call    _bzero
F0051904: d2042014                 ld      [%l0+0x14], %o1
F0051908: 10800013                 ba      loc_F0051954
F005190C: c0242028                 clr     [%l0+0x28]
F0051910: 90022001                 inc     %o0
F0051914: 80a20012                 cmp     %o0, %l2
F0051918: 1280000b                 bne     loc_F0051944
F005191C: 90100017                 mov     %l7, %o0
F0051920: 153c04eb                 sethi   %hi(_rablock), %o2
F0051924: d602a170                 ld      [%o2+%lo(_rablock)], %o3
F0051928: 9210000c                 mov     %o4, %o1
F005192C: 153c04eb                 sethi   %hi(_rasize), %o2
F0051930: d802a178                 ld      [%o2+%lo(_rasize)], %o4
F0051934: 7fff4b29                 call    _breada
F0051938: 9410000d                 mov     %o5, %o2
F005193C: 10800006                 ba      loc_F0051954
F0051940: a0100008                 mov     %o0, %l0
F0051944: 9210000c                 mov     %o4, %o1
F0051948: 7fff4af6                 call    _bread
F005194C: 9410000d                 mov     %o5, %o2
F0051950: a0100008                 mov     %o0, %l0
F0051954: 1080000d                 ba      loc_F0051988
F0051958: e4262058                 st      %l2, [%i0+0x58]
F005195C: 12800007                 bne     loc_F0051978
F0051960: 90100017                 mov     %l7, %o0
F0051964: 9210000c                 mov     %o4, %o1
F0051968: 7fff4c40                 call    _getblk
F005196C: 9410000d                 mov     %o5, %o2
F0051970: 10800006                 ba      loc_F0051988
F0051974: a0100008                 mov     %o0, %l0
F0051978: 9210000c                 mov     %o4, %o1
F005197C: 7fff4ae9                 call    _bread
F0051980: 9410000d                 mov     %o5, %o2
F0051984: a0100008                 mov     %o0, %l0
F0051988: d2042014                 ld      [%l0+0x14], %o1
F005198C: d0042028                 ld      [%l0+0x28], %o0
F0051990: 92224008                 sub     %o1, %o0, %o1
F0051994: 80a44009                 cmp     %l1, %o1
F0051998: 34800002                 bg,a    loc_F00519A0
F005199C: a2100009                 mov     %o1, %l1
F00519A0: d0040000                 ld      [%l0], %o0
F00519A4: 808a2004                 btst    4, %o0
F00519A8: 12bfff43                 bne     loc_F00516B4
F00519AC: 92100011                 mov     %l1, %o1
F00519B0: 9410001a                 mov     %i2, %o2
F00519B4: d0042020                 ld      [%l0+0x20], %o0
F00519B8: 96100019                 mov     %i1, %o3
F00519BC: 7fff0257                 call    _uiomove
F00519C0: 90020013                 add     %o0, %l3, %o0
F00519C4: d20761dc                 ld      [%i5+0x1DC], %o1
F00519C8: 808ee004                 btst    4, %i3
F00519CC: 02800010                 be      loc_F0051A0C
F00519D0: d02a6038                 stb     %o0, [%o1+0x38]
F00519D4: d2162064                 lduh    [%i0+0x64], %o1
F00519D8: 808a6200                 btst    0x200, %o1
F00519DC: 0280000c                 be      loc_F0051A0C
F00519E0: 113c043c                 sethi   %hi(_stickyhack), %o0
F00519E4: d00221ec                 ld      [%o0+%lo(_stickyhack)], %o0
F00519E8: 80a22000                 cmp     %o0, 0
F00519EC: 02800008                 be      loc_F0051A0C
F00519F0: 808a6049                 btst    0x49, %o1 ! 'I'
F00519F4: 12800007                 bne     loc_F0051A10
F00519F8: 80a6a000                 cmp     %i2, 0
F00519FC: d0040000                 ld      [%l0], %o0
F0051A00: 13001000                 sethi   0x400000, %o1
F0051A04: 90120009                 bset    %o1, %o0
F0051A08: d0240000                 st      %o0, [%l0]
F0051A0C: 80a6a000                 cmp     %i2, 0
F0051A10: 12800012                 bne     loc_F0051A58
F0051A14: 808ee004                 btst    4, %i3
F0051A18: 90044013                 add     %l1, %l3, %o0
F0051A1C: 80a20015                 cmp     %o0, %l5
F0051A20: 22800008                 be,a    loc_F0051A40
F0051A24: d0040000                 ld      [%l0], %o0
F0051A28: d2066008                 ld      [%i1+8], %o1
F0051A2C: d0062070                 ld      [%i0+0x70], %o0
F0051A30: 80a24008                 cmp     %o1, %o0
F0051A34: 12800005                 bne     loc_F0051A48
F0051A38: 01000000                 nop
F0051A3C: d0040000                 ld      [%l0], %o0
F0051A40: 90122080                 bset    0x80, %o0
F0051A44: d0240000                 st      %o0, [%l0]
F0051A48: 7fff4b88                 call    _brelse
F0051A4C: 90100010                 mov     %l0, %o0
F0051A50: 10800027                 ba      loc_F0051AEC
F0051A54: d00761dc                 ld      [%i5+0x1DC], %o0
F0051A58: 12800008                 bne     loc_F0051A78
F0051A5C: 1300003c                 sethi   0xF000, %o1
F0051A60: d0162064                 lduh    [%i0+0x64], %o0
F0051A64: 05000010                 sethi   0x4000, %g2
F0051A68: 900a0009                 and     %o0, %o1, %o0
F0051A6C: 80a20002                 cmp     %o0, %g2
F0051A70: 12800006                 bne     loc_F0051A88
F0051A74: 90044013                 add     %l1, %l3, %o0
F0051A78: 7fff4b3c                 call    _bwrite
F0051A7C: 90100010                 mov     %l0, %o0
F0051A80: 1080000e                 ba      loc_F0051AB8
F0051A84: d0162044                 lduh    [%i0+0x44], %o0
F0051A88: 80a20015                 cmp     %o0, %l5
F0051A8C: 12800008                 bne     loc_F0051AAC
F0051A90: 90100010                 mov     %l0, %o0
F0051A94: d2040000                 ld      [%l0], %o1
F0051A98: 92126080                 bset    0x80, %o1
F0051A9C: 7fff4b6b                 call    _bawrite
F0051AA0: d2220000                 st      %o1, [%o0]
F0051AA4: 10800005                 ba      loc_F0051AB8
F0051AA8: d0162044                 lduh    [%i0+0x44], %o0
F0051AAC: 7fff4b56                 call    _bdwrite
F0051AB0: 90100010                 mov     %l0, %o0
F0051AB4: d0162044                 lduh    [%i0+0x44], %o0
F0051AB8: 90122042                 bset    0x42, %o0 ! 'B'
F0051ABC: d0362044                 sth     %o0, [%i0+0x44]
F0051AC0: 113c04cf                 sethi   %hi(_active_u), %o0
F0051AC4: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0051AC8: d002201c                 ld      [%o0+0x1C], %o0
F0051ACC: d0522006                 ldsh    [%o0+6], %o0
F0051AD0: 80a22000                 cmp     %o0, 0
F0051AD4: 02800006                 be      loc_F0051AEC
F0051AD8: d00761dc                 ld      [%i5+0x1DC], %o0
F0051ADC: d0162064                 lduh    [%i0+0x64], %o0
F0051AE0: 900a33ff                 and     %o0, -0xC01, %o0
F0051AE4: d0362064                 sth     %o0, [%i0+0x64]
F0051AE8: d00761dc                 ld      [%i5+0x1DC], %o0
F0051AEC: d04a2038                 ldsb    [%o0+0x38], %o0
F0051AF0: 80a22000                 cmp     %o0, 0
F0051AF4: 12800009                 bne     loc_F0051B18
F0051AF8: d007bff4                 ld      [%fp+var_C], %o0
F0051AFC: d0066014                 ld      [%i1+0x14], %o0
F0051B00: 80a22000                 cmp     %o0, 0
F0051B04: 04800004                 ble     loc_F0051B14
F0051B08: 80a46000                 cmp     %l1, 0
F0051B0C: 32bffefd                 bne,a   loc_F0051700
F0051B10: e0066008                 ld      [%i1+8], %l0
F0051B14: d007bff4                 ld      [%fp+var_C], %o0
F0051B18: 80a22000                 cmp     %o0, 0
F0051B1C: 02800004                 be      loc_F0051B2C
F0051B20: 90100018                 mov     %i0, %o0
F0051B24: 7ffff288                 call    _iupdat
F0051B28: 92102001                 mov     1, %o1
F0051B2C: 80a72000                 cmp     %i4, 0
F0051B30: 12800006                 bne     locret_F0051B48
F0051B34: b010001c                 mov     %i4, %i0
F0051B38: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0051B3C: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0051B40: f84a2038                 ldsb    [%o0+0x38], %i4
F0051B44: b010001c                 mov     %i4, %i0
F0051B48: 81c7e008                 ret
F0051B4C: 81e80000                 restore
