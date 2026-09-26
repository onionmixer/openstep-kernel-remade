F0006608: 80924008                 orcc    %o1, %o0, %g0
F000660C: 16800008                 bge     loc_F000662C
F0006610: 821a4008                 xor     %o1, %o0, %g1
F0006614: 80924000                 tst     %o1
F0006618: 16800004                 bge     loc_F0006628
F000661C: 80920000                 tst     %o0
F0006620: 16800003                 bge     loc_F000662C
F0006624: 92200009                 neg     %o1
F0006628: 90200008                 neg     %o0
F000662C: 9a924000                 orcc    %o1, %g0, %o5
F0006630: 83d02002                 te      2
F0006634: 96100008                 mov     %o0, %o3
F0006638: 80a2c00d                 cmp     %o3, %o5
F000663C: 0a800094                 bcs     loc_F000688C
F0006640: 94102000                 mov     0, %o2
F0006644: 05020000                 sethi   0x8000000, %g2
F0006648: 80a2c002                 cmp     %o3, %g2
F000664C: 0a800027                 bcs     loc_F00066E8
F0006650: 98102000                 mov     0, %o4
F0006654: 80a34002                 cmp     %o5, %g2
F0006658: 1a80000d                 bcc     loc_F000668C
F000665C: 86102001                 mov     1, %g3
F0006660: 9b2b6004                 sll     %o5, 4, %o5
F0006664: 10bffffc                 ba      loc_F0006654
F0006668: 98032001                 inc     %o4
F000666C: 9a83400d                 addcc   %o5, %o5, %o5
F0006670: 1a800007                 bcc     loc_F000668C
F0006674: 8600e001                 inc     %g3
F0006678: 8528a004                 sll     %g2, 4, %g2
F000667C: 9b336001                 srl     %o5, 1, %o5
F0006680: 9a034002                 add     %o5, %g2, %o5
F0006684: 10800007                 ba      loc_F00066A0
F0006688: 8620e001                 dec     %g3
F000668C: 80a3400b                 cmp     %o5, %o3
F0006690: 0abffff7                 bcs     loc_F000666C
F0006694: 01000000                 nop
F0006698: 02800002                 be      loc_F00066A0
F000669C: 01000000                 nop
F00066A0: 86a0e001                 deccc   %g3
F00066A4: 06800075                 bl      loc_F0006878
F00066A8: 01000000                 nop
F00066AC: 9622c00d                 sub     %o3, %o5, %o3
F00066B0: 94102001                 mov     1, %o2
F00066B4: 30800009                 ba,a    loc_F00066D8
F00066B8: 952aa001                 sll     %o2, 1, %o2
F00066BC: 06800005                 bl      loc_F00066D0
F00066C0: 9b336001                 srl     %o5, 1, %o5
F00066C4: 9622c00d                 sub     %o3, %o5, %o3
F00066C8: 10800004                 ba      loc_F00066D8
F00066CC: 9402a001                 inc     %o2
F00066D0: 9602c00d                 add     %o3, %o5, %o3
F00066D4: 9422a001                 dec     %o2
F00066D8: 86a0e001                 deccc   %g3
F00066DC: 16bffff7                 bge     loc_F00066B8
F00066E0: 8092c000                 tst     %o3
F00066E4: 30800065                 ba,a    loc_F0006878
F00066E8: 9b2b6004                 sll     %o5, 4, %o5
F00066EC: 80a3400b                 cmp     %o5, %o3
F00066F0: 08bffffe                 bleu    loc_F00066E8
F00066F4: 98832001                 inccc   %o4
F00066F8: 02800065                 be      loc_F000688C
F00066FC: 98232001                 dec     %o4
F0006700: 8092c000                 tst     %o3
F0006704: 952aa004                 sll     %o2, 4, %o2
F0006708: 0680002f                 bl      loc_F00067C4
F000670C: 9b336001                 srl     %o5, 1, %o5
F0006710: 96a2c00d                 subcc   %o3, %o5, %o3
F0006714: 06800017                 bl      loc_F0006770
F0006718: 9b336001                 srl     %o5, 1, %o5
F000671C: 96a2c00d                 subcc   %o3, %o5, %o3
F0006720: 0680000b                 bl      loc_F000674C
F0006724: 9b336001                 srl     %o5, 1, %o5
F0006728: 96a2c00d                 subcc   %o3, %o5, %o3
F000672C: 06800005                 bl      loc_F0006740
F0006730: 9b336001                 srl     %o5, 1, %o5
F0006734: 96a2c00d                 subcc   %o3, %o5, %o3
F0006738: 10800050                 ba      loc_F0006878
F000673C: 9402a00f                 inc     0xF, %o2
F0006740: 9682c00d                 addcc   %o3, %o5, %o3
F0006744: 1080004d                 ba      loc_F0006878
F0006748: 9402a00d                 inc     0xD, %o2
F000674C: 9682c00d                 addcc   %o3, %o5, %o3
F0006750: 06800005                 bl      loc_F0006764
F0006754: 9b336001                 srl     %o5, 1, %o5
F0006758: 96a2c00d                 subcc   %o3, %o5, %o3
F000675C: 10800047                 ba      loc_F0006878
F0006760: 9402a00b                 inc     0xB, %o2
F0006764: 9682c00d                 addcc   %o3, %o5, %o3
F0006768: 10800044                 ba      loc_F0006878
F000676C: 9402a009                 inc     9, %o2
F0006770: 9682c00d                 addcc   %o3, %o5, %o3
F0006774: 0680000b                 bl      loc_F00067A0
F0006778: 9b336001                 srl     %o5, 1, %o5
F000677C: 96a2c00d                 subcc   %o3, %o5, %o3
F0006780: 06800005                 bl      loc_F0006794
F0006784: 9b336001                 srl     %o5, 1, %o5
F0006788: 96a2c00d                 subcc   %o3, %o5, %o3
F000678C: 1080003b                 ba      loc_F0006878
F0006790: 9402a007                 inc     7, %o2
F0006794: 9682c00d                 addcc   %o3, %o5, %o3
F0006798: 10800038                 ba      loc_F0006878
F000679C: 9402a005                 inc     5, %o2
F00067A0: 9682c00d                 addcc   %o3, %o5, %o3
F00067A4: 06800005                 bl      loc_F00067B8
F00067A8: 9b336001                 srl     %o5, 1, %o5
F00067AC: 96a2c00d                 subcc   %o3, %o5, %o3
F00067B0: 10800032                 ba      loc_F0006878
F00067B4: 9402a003                 inc     3, %o2
F00067B8: 9682c00d                 addcc   %o3, %o5, %o3
F00067BC: 1080002f                 ba      loc_F0006878
F00067C0: 9402a001                 inc     %o2
F00067C4: 9682c00d                 addcc   %o3, %o5, %o3
F00067C8: 06800017                 bl      loc_F0006824
F00067CC: 9b336001                 srl     %o5, 1, %o5
F00067D0: 96a2c00d                 subcc   %o3, %o5, %o3
F00067D4: 0680000b                 bl      loc_F0006800
F00067D8: 9b336001                 srl     %o5, 1, %o5
F00067DC: 96a2c00d                 subcc   %o3, %o5, %o3
F00067E0: 06800005                 bl      loc_F00067F4
F00067E4: 9b336001                 srl     %o5, 1, %o5
F00067E8: 96a2c00d                 subcc   %o3, %o5, %o3
F00067EC: 10800023                 ba      loc_F0006878
F00067F0: 9402bfff                 inc     -1, %o2
F00067F4: 9682c00d                 addcc   %o3, %o5, %o3
F00067F8: 10800020                 ba      loc_F0006878
F00067FC: 9402bffd                 inc     -3, %o2
F0006800: 9682c00d                 addcc   %o3, %o5, %o3
F0006804: 06800005                 bl      loc_F0006818
F0006808: 9b336001                 srl     %o5, 1, %o5
F000680C: 96a2c00d                 subcc   %o3, %o5, %o3
F0006810: 1080001a                 ba      loc_F0006878
F0006814: 9402bffb                 inc     -5, %o2
F0006818: 9682c00d                 addcc   %o3, %o5, %o3
F000681C: 10800017                 ba      loc_F0006878
F0006820: 9402bff9                 inc     -7, %o2
F0006824: 9682c00d                 addcc   %o3, %o5, %o3
F0006828: 0680000b                 bl      loc_F0006854
F000682C: 9b336001                 srl     %o5, 1, %o5
F0006830: 96a2c00d                 subcc   %o3, %o5, %o3
F0006834: 06800005                 bl      loc_F0006848
F0006838: 9b336001                 srl     %o5, 1, %o5
F000683C: 96a2c00d                 subcc   %o3, %o5, %o3
F0006840: 1080000e                 ba      loc_F0006878
F0006844: 9402bff7                 inc     -9, %o2
F0006848: 9682c00d                 addcc   %o3, %o5, %o3
F000684C: 1080000b                 ba      loc_F0006878
F0006850: 9402bff5                 inc     -0xB, %o2
F0006854: 9682c00d                 addcc   %o3, %o5, %o3
F0006858: 06800005                 bl      loc_F000686C
F000685C: 9b336001                 srl     %o5, 1, %o5
F0006860: 96a2c00d                 subcc   %o3, %o5, %o3
F0006864: 10800005                 ba      loc_F0006878
F0006868: 9402bff3                 inc     -0xD, %o2
F000686C: 9682c00d                 addcc   %o3, %o5, %o3
F0006870: 10800002                 ba      loc_F0006878
F0006874: 9402bff1                 inc     -0xF, %o2
F0006878: 98a32001                 deccc   %o4
F000687C: 16bfffa2                 bge     loc_F0006704
F0006880: 8092c000                 tst     %o3
F0006884: 26800002                 bl,a    loc_F000688C
F0006888: 9422a001                 dec     %o2
F000688C: 80904000                 tst     %g1
F0006890: 26800002                 bl,a    locret_F0006898
F0006894: 9420000a                 neg     %o2
F0006898: 81c3e008                 retl
F000689C: 9010000a                 mov     %o2, %o0
