F00068A8: 80924008                 orcc    %o1, %o0, %g0
F00068AC: 16800008                 bge     loc_F00068CC
F00068B0: 82100008                 mov     %o0, %g1
F00068B4: 80924000                 tst     %o1
F00068B8: 16800004                 bge     loc_F00068C8
F00068BC: 80920000                 tst     %o0
F00068C0: 16800003                 bge     loc_F00068CC
F00068C4: 92200009                 neg     %o1
F00068C8: 90200008                 neg     %o0
F00068CC: 9a924000                 orcc    %o1, %g0, %o5
F00068D0: 83d02002                 te      2
F00068D4: 96100008                 mov     %o0, %o3
F00068D8: 80a2c00d                 cmp     %o3, %o5
F00068DC: 0a800094                 bcs     loc_F0006B2C
F00068E0: 94102000                 mov     0, %o2
F00068E4: 05020000                 sethi   0x8000000, %g2
F00068E8: 80a2c002                 cmp     %o3, %g2
F00068EC: 0a800027                 bcs     loc_F0006988
F00068F0: 98102000                 mov     0, %o4
F00068F4: 80a34002                 cmp     %o5, %g2
F00068F8: 1a80000d                 bcc     loc_F000692C
F00068FC: 86102001                 mov     1, %g3
F0006900: 9b2b6004                 sll     %o5, 4, %o5
F0006904: 10bffffc                 ba      loc_F00068F4
F0006908: 98032001                 inc     %o4
F000690C: 9a83400d                 addcc   %o5, %o5, %o5
F0006910: 1a800007                 bcc     loc_F000692C
F0006914: 8600e001                 inc     %g3
F0006918: 8528a004                 sll     %g2, 4, %g2
F000691C: 9b336001                 srl     %o5, 1, %o5
F0006920: 9a034002                 add     %o5, %g2, %o5
F0006924: 10800007                 ba      loc_F0006940
F0006928: 8620e001                 dec     %g3
F000692C: 80a3400b                 cmp     %o5, %o3
F0006930: 0abffff7                 bcs     loc_F000690C
F0006934: 01000000                 nop
F0006938: 02800002                 be      loc_F0006940
F000693C: 01000000                 nop
F0006940: 86a0e001                 deccc   %g3
F0006944: 06800075                 bl      loc_F0006B18
F0006948: 01000000                 nop
F000694C: 9622c00d                 sub     %o3, %o5, %o3
F0006950: 94102001                 mov     1, %o2
F0006954: 30800009                 ba,a    loc_F0006978
F0006958: 952aa001                 sll     %o2, 1, %o2
F000695C: 06800005                 bl      loc_F0006970
F0006960: 9b336001                 srl     %o5, 1, %o5
F0006964: 9622c00d                 sub     %o3, %o5, %o3
F0006968: 10800004                 ba      loc_F0006978
F000696C: 9402a001                 inc     %o2
F0006970: 9602c00d                 add     %o3, %o5, %o3
F0006974: 9422a001                 dec     %o2
F0006978: 86a0e001                 deccc   %g3
F000697C: 16bffff7                 bge     loc_F0006958
F0006980: 8092c000                 tst     %o3
F0006984: 30800065                 ba,a    loc_F0006B18
F0006988: 9b2b6004                 sll     %o5, 4, %o5
F000698C: 80a3400b                 cmp     %o5, %o3
F0006990: 08bffffe                 bleu    loc_F0006988
F0006994: 98832001                 inccc   %o4
F0006998: 02800065                 be      loc_F0006B2C
F000699C: 98232001                 dec     %o4
F00069A0: 8092c000                 tst     %o3
F00069A4: 952aa004                 sll     %o2, 4, %o2
F00069A8: 0680002f                 bl      loc_F0006A64
F00069AC: 9b336001                 srl     %o5, 1, %o5
F00069B0: 96a2c00d                 subcc   %o3, %o5, %o3
F00069B4: 06800017                 bl      loc_F0006A10
F00069B8: 9b336001                 srl     %o5, 1, %o5
F00069BC: 96a2c00d                 subcc   %o3, %o5, %o3
F00069C0: 0680000b                 bl      loc_F00069EC
F00069C4: 9b336001                 srl     %o5, 1, %o5
F00069C8: 96a2c00d                 subcc   %o3, %o5, %o3
F00069CC: 06800005                 bl      loc_F00069E0
F00069D0: 9b336001                 srl     %o5, 1, %o5
F00069D4: 96a2c00d                 subcc   %o3, %o5, %o3
F00069D8: 10800050                 ba      loc_F0006B18
F00069DC: 9402a00f                 inc     0xF, %o2
F00069E0: 9682c00d                 addcc   %o3, %o5, %o3
F00069E4: 1080004d                 ba      loc_F0006B18
F00069E8: 9402a00d                 inc     0xD, %o2
F00069EC: 9682c00d                 addcc   %o3, %o5, %o3
F00069F0: 06800005                 bl      loc_F0006A04
F00069F4: 9b336001                 srl     %o5, 1, %o5
F00069F8: 96a2c00d                 subcc   %o3, %o5, %o3
F00069FC: 10800047                 ba      loc_F0006B18
F0006A00: 9402a00b                 inc     0xB, %o2
F0006A04: 9682c00d                 addcc   %o3, %o5, %o3
F0006A08: 10800044                 ba      loc_F0006B18
F0006A0C: 9402a009                 inc     9, %o2
F0006A10: 9682c00d                 addcc   %o3, %o5, %o3
F0006A14: 0680000b                 bl      loc_F0006A40
F0006A18: 9b336001                 srl     %o5, 1, %o5
F0006A1C: 96a2c00d                 subcc   %o3, %o5, %o3
F0006A20: 06800005                 bl      loc_F0006A34
F0006A24: 9b336001                 srl     %o5, 1, %o5
F0006A28: 96a2c00d                 subcc   %o3, %o5, %o3
F0006A2C: 1080003b                 ba      loc_F0006B18
F0006A30: 9402a007                 inc     7, %o2
F0006A34: 9682c00d                 addcc   %o3, %o5, %o3
F0006A38: 10800038                 ba      loc_F0006B18
F0006A3C: 9402a005                 inc     5, %o2
F0006A40: 9682c00d                 addcc   %o3, %o5, %o3
F0006A44: 06800005                 bl      loc_F0006A58
F0006A48: 9b336001                 srl     %o5, 1, %o5
F0006A4C: 96a2c00d                 subcc   %o3, %o5, %o3
F0006A50: 10800032                 ba      loc_F0006B18
F0006A54: 9402a003                 inc     3, %o2
F0006A58: 9682c00d                 addcc   %o3, %o5, %o3
F0006A5C: 1080002f                 ba      loc_F0006B18
F0006A60: 9402a001                 inc     %o2
F0006A64: 9682c00d                 addcc   %o3, %o5, %o3
F0006A68: 06800017                 bl      loc_F0006AC4
F0006A6C: 9b336001                 srl     %o5, 1, %o5
F0006A70: 96a2c00d                 subcc   %o3, %o5, %o3
F0006A74: 0680000b                 bl      loc_F0006AA0
F0006A78: 9b336001                 srl     %o5, 1, %o5
F0006A7C: 96a2c00d                 subcc   %o3, %o5, %o3
F0006A80: 06800005                 bl      loc_F0006A94
F0006A84: 9b336001                 srl     %o5, 1, %o5
F0006A88: 96a2c00d                 subcc   %o3, %o5, %o3
F0006A8C: 10800023                 ba      loc_F0006B18
F0006A90: 9402bfff                 inc     -1, %o2
F0006A94: 9682c00d                 addcc   %o3, %o5, %o3
F0006A98: 10800020                 ba      loc_F0006B18
F0006A9C: 9402bffd                 inc     -3, %o2
F0006AA0: 9682c00d                 addcc   %o3, %o5, %o3
F0006AA4: 06800005                 bl      loc_F0006AB8
F0006AA8: 9b336001                 srl     %o5, 1, %o5
F0006AAC: 96a2c00d                 subcc   %o3, %o5, %o3
F0006AB0: 1080001a                 ba      loc_F0006B18
F0006AB4: 9402bffb                 inc     -5, %o2
F0006AB8: 9682c00d                 addcc   %o3, %o5, %o3
F0006ABC: 10800017                 ba      loc_F0006B18
F0006AC0: 9402bff9                 inc     -7, %o2
F0006AC4: 9682c00d                 addcc   %o3, %o5, %o3
F0006AC8: 0680000b                 bl      loc_F0006AF4
F0006ACC: 9b336001                 srl     %o5, 1, %o5
F0006AD0: 96a2c00d                 subcc   %o3, %o5, %o3
F0006AD4: 06800005                 bl      loc_F0006AE8
F0006AD8: 9b336001                 srl     %o5, 1, %o5
F0006ADC: 96a2c00d                 subcc   %o3, %o5, %o3
F0006AE0: 1080000e                 ba      loc_F0006B18
F0006AE4: 9402bff7                 inc     -9, %o2
F0006AE8: 9682c00d                 addcc   %o3, %o5, %o3
F0006AEC: 1080000b                 ba      loc_F0006B18
F0006AF0: 9402bff5                 inc     -0xB, %o2
F0006AF4: 9682c00d                 addcc   %o3, %o5, %o3
F0006AF8: 06800005                 bl      loc_F0006B0C
F0006AFC: 9b336001                 srl     %o5, 1, %o5
F0006B00: 96a2c00d                 subcc   %o3, %o5, %o3
F0006B04: 10800005                 ba      loc_F0006B18
F0006B08: 9402bff3                 inc     -0xD, %o2
F0006B0C: 9682c00d                 addcc   %o3, %o5, %o3
F0006B10: 10800002                 ba      loc_F0006B18
F0006B14: 9402bff1                 inc     -0xF, %o2
F0006B18: 98a32001                 deccc   %o4
F0006B1C: 16bfffa2                 bge     loc_F00069A4
F0006B20: 8092c000                 tst     %o3
F0006B24: 26800002                 bl,a    loc_F0006B2C
F0006B28: 9602c009                 add     %o3, %o1, %o3
F0006B2C: 80904000                 tst     %g1
F0006B30: 26800002                 bl,a    locret_F0006B38
F0006B34: 9620000b                 neg     %o3
F0006B38: 81c3e008                 retl
F0006B3C: 9010000b                 mov     %o3, %o0
