F0005598: 9de3bf88                 save    %sp, -0x78, %sp
F000559C: ba10001c                 mov     %i4, %i5
F00055A0: aa10001b                 mov     %i3, %l5
F00055A4: 80a6a000                 cmp     %i2, 0
F00055A8: 1280010b                 bne     loc_F00059D4
F00055AC: b6100019                 mov     %i1, %i3
F00055B0: 80a54018                 cmp     %l5, %i0
F00055B4: 0880005e                 bleu    loc_F000572C
F00055B8: 1100003f                 sethi   0xFC00, %o0
F00055BC: 901223ff                 bset    0x3FF, %o0
F00055C0: 80a54008                 cmp     %l5, %o0
F00055C4: 18800006                 bgu     loc_F00055DC
F00055C8: 92100015                 mov     %l5, %o1
F00055CC: 80a56100                 cmp     %l5, 0x100
F00055D0: 90403fff                 addc    %g0, -1, %o0
F00055D4: 10800008                 ba      loc_F00055F4
F00055D8: 940a2008                 and     %o0, 8, %o2
F00055DC: 11003fff901223ff         set     0xFFFFFF, %o0
F00055E4: 80a54008                 cmp     %l5, %o0
F00055E8: 18800003                 bgu     loc_F00055F4
F00055EC: 94102018                 mov     0x18, %o2
F00055F0: 94102010                 mov     0x10, %o2
F00055F4: 9132400a                 srl     %o1, %o2, %o0
F00055F8: 133c03d292126298         set     unk_F00F4A98, %o1
F0005600: d00a0009                 ldub    [%o0+%o1], %o0
F0005604: 9002000a                 add     %o0, %o2, %o0
F0005608: 94102020                 mov     0x20, %o2 ! ' '
F000560C: aea28008                 subcc   %o2, %o0, %l7
F0005610: 02800007                 be      loc_F000562C
F0005614: 90228017                 sub     %o2, %l7, %o0
F0005618: ab2d4017                 sll     %l5, %l7, %l5
F000561C: 932e0017                 sll     %i0, %l7, %o1
F0005620: 9136c008                 srl     %i3, %o0, %o0
F0005624: b0124008                 or      %o1, %o0, %i0
F0005628: b72ec017                 sll     %i3, %l7, %i3
F000562C: 90100018                 mov     %i0, %o0
F0005630: a7356010                 srl     %l5, 16, %l3
F0005634: 92100013                 mov     %l3, %o1
F0005638: 1500003f9412a3ff         set     0xFFFF, %o2
F0005640: 40000498                 call    _urem
F0005644: a80d400a                 and     %l5, %o2, %l4
F0005648: a0100008                 mov     %o0, %l0
F000564C: 90100018                 mov     %i0, %o0
F0005650: 400003ec                 call    _udiv
F0005654: 92100013                 mov     %l3, %o1
F0005658: a4100008                 mov     %o0, %l2
F000565C: 400003a9                 call    _umul
F0005660: 92100014                 mov     %l4, %o1
F0005664: 94100008                 mov     %o0, %o2
F0005668: 932c2010                 sll     %l0, 16, %o1
F000566C: 9136e010                 srl     %i3, 16, %o0
F0005670: a0124008                 or      %o1, %o0, %l0
F0005674: 80a4000a                 cmp     %l0, %o2
F0005678: 3a80000c                 bcc,a   loc_F00056A8
F000567C: a024000a                 sub     %l0, %o2, %l0
F0005680: a0040015                 add     %l0, %l5, %l0
F0005684: 80a40015                 cmp     %l0, %l5
F0005688: 0a800007                 bcs     loc_F00056A4
F000568C: a404bfff                 inc     -1, %l2
F0005690: 80a4000a                 cmp     %l0, %o2
F0005694: 3a800005                 bcc,a   loc_F00056A8
F0005698: a024000a                 sub     %l0, %o2, %l0
F000569C: a404bfff                 inc     -1, %l2
F00056A0: a0040015                 add     %l0, %l5, %l0
F00056A4: a024000a                 sub     %l0, %o2, %l0
F00056A8: 90100010                 mov     %l0, %o0
F00056AC: 4000047d                 call    _urem
F00056B0: 92100013                 mov     %l3, %o1
F00056B4: a2100008                 mov     %o0, %l1
F00056B8: 90100010                 mov     %l0, %o0
F00056BC: 400003d1                 call    _udiv
F00056C0: 92100013                 mov     %l3, %o1
F00056C4: a0100008                 mov     %o0, %l0
F00056C8: 4000038e                 call    _umul
F00056CC: 92100014                 mov     %l4, %o1
F00056D0: 94100008                 mov     %o0, %o2
F00056D4: 932c6010                 sll     %l1, 16, %o1
F00056D8: 1100003f901223ff         set     0xFFFF, %o0
F00056E0: 900ec008                 and     %i3, %o0, %o0
F00056E4: a2124008                 or      %o1, %o0, %l1
F00056E8: 80a4400a                 cmp     %l1, %o2
F00056EC: 3a80000c                 bcc,a   loc_F000571C
F00056F0: 912ca010                 sll     %l2, 16, %o0
F00056F4: a2044015                 add     %l1, %l5, %l1
F00056F8: 80a44015                 cmp     %l1, %l5
F00056FC: 0a800007                 bcs     loc_F0005718
F0005700: a0043fff                 inc     -1, %l0
F0005704: 80a4400a                 cmp     %l1, %o2
F0005708: 1a800005                 bcc     loc_F000571C
F000570C: 912ca010                 sll     %l2, 16, %o0
F0005710: a0043fff                 inc     -1, %l0
F0005714: a2044015                 add     %l1, %l5, %l1
F0005718: 912ca010                 sll     %l2, 16, %o0
F000571C: b2120010                 or      %o0, %l0, %i1
F0005720: b624400a                 sub     %l1, %o2, %i3
F0005724: 108000a6                 ba      loc_F00059BC
F0005728: ac102000                 mov     0, %l6
F000572C: 80a56000                 cmp     %l5, 0
F0005730: 12800008                 bne     loc_F0005750
F0005734: 901223ff                 bset    0x3FF, %o0
F0005738: 90102001                 mov     1, %o0
F000573C: 400003b1                 call    _udiv
F0005740: 92102000                 mov     0, %o1
F0005744: aa100008                 mov     %o0, %l5
F0005748: 1100003f901223ff         set     0xFFFF, %o0
F0005750: 80a54008                 cmp     %l5, %o0
F0005754: 18800006                 bgu     loc_F000576C
F0005758: 92100015                 mov     %l5, %o1
F000575C: 80a56100                 cmp     %l5, 0x100
F0005760: 90403fff                 addc    %g0, -1, %o0
F0005764: 10800008                 ba      loc_F0005784
F0005768: 940a2008                 and     %o0, 8, %o2
F000576C: 11003fff901223ff         set     0xFFFFFF, %o0
F0005774: 80a54008                 cmp     %l5, %o0
F0005778: 18800003                 bgu     loc_F0005784
F000577C: 94102018                 mov     0x18, %o2
F0005780: 94102010                 mov     0x10, %o2
F0005784: 9132400a                 srl     %o1, %o2, %o0
F0005788: 133c03d292126298         set     unk_F00F4A98, %o1
F0005790: d00a0009                 ldub    [%o0+%o1], %o0
F0005794: 9002000a                 add     %o0, %o2, %o0
F0005798: 92102020                 mov     0x20, %o1 ! ' '
F000579C: aea24008                 subcc   %o1, %o0, %l7
F00057A0: 12800005                 bne     loc_F00057B4
F00057A4: b8224017                 sub     %o1, %l7, %i4
F00057A8: b0260015                 sub     %i0, %l5, %i0
F00057AC: 10800046                 ba      loc_F00058C4
F00057B0: ac102001                 mov     1, %l6
F00057B4: ab2d4017                 sll     %l5, %l7, %l5
F00057B8: a536001c                 srl     %i0, %i4, %l2
F00057BC: 932e0017                 sll     %i0, %l7, %o1
F00057C0: 9136c01c                 srl     %i3, %i4, %o0
F00057C4: b0124008                 or      %o1, %o0, %i0
F00057C8: b72ec017                 sll     %i3, %l7, %i3
F00057CC: a7356010                 srl     %l5, 16, %l3
F00057D0: 90100012                 mov     %l2, %o0
F00057D4: 92100013                 mov     %l3, %o1
F00057D8: 1500003f9412a3ff         set     0xFFFF, %o2
F00057E0: 40000430                 call    _urem
F00057E4: a80d400a                 and     %l5, %o2, %l4
F00057E8: a2100008                 mov     %o0, %l1
F00057EC: 90100012                 mov     %l2, %o0
F00057F0: 40000384                 call    _udiv
F00057F4: 92100013                 mov     %l3, %o1
F00057F8: a4100008                 mov     %o0, %l2
F00057FC: 40000341                 call    _umul
F0005800: 92100014                 mov     %l4, %o1
F0005804: 94100008                 mov     %o0, %o2
F0005808: 932c6010                 sll     %l1, 16, %o1
F000580C: 91362010                 srl     %i0, 16, %o0
F0005810: a2124008                 or      %o1, %o0, %l1
F0005814: 80a4400a                 cmp     %l1, %o2
F0005818: 3a80000c                 bcc,a   loc_F0005848
F000581C: a224400a                 sub     %l1, %o2, %l1
F0005820: a2044015                 add     %l1, %l5, %l1
F0005824: 80a44015                 cmp     %l1, %l5
F0005828: 0a800007                 bcs     loc_F0005844
F000582C: a404bfff                 inc     -1, %l2
F0005830: 80a4400a                 cmp     %l1, %o2
F0005834: 3a800005                 bcc,a   loc_F0005848
F0005838: a224400a                 sub     %l1, %o2, %l1
F000583C: a404bfff                 inc     -1, %l2
F0005840: a2044015                 add     %l1, %l5, %l1
F0005844: a224400a                 sub     %l1, %o2, %l1
F0005848: 90100011                 mov     %l1, %o0
F000584C: 40000415                 call    _urem
F0005850: 92100013                 mov     %l3, %o1
F0005854: a0100008                 mov     %o0, %l0
F0005858: 90100011                 mov     %l1, %o0
F000585C: 40000369                 call    _udiv
F0005860: 92100013                 mov     %l3, %o1
F0005864: a2100008                 mov     %o0, %l1
F0005868: 40000326                 call    _umul
F000586C: 92100014                 mov     %l4, %o1
F0005870: 94100008                 mov     %o0, %o2
F0005874: 932c2010                 sll     %l0, 16, %o1
F0005878: 1100003f901223ff         set     0xFFFF, %o0
F0005880: 900e0008                 and     %i0, %o0, %o0
F0005884: a0124008                 or      %o1, %o0, %l0
F0005888: 80a4000a                 cmp     %l0, %o2
F000588C: 3a80000c                 bcc,a   loc_F00058BC
F0005890: 912ca010                 sll     %l2, 16, %o0
F0005894: a0040015                 add     %l0, %l5, %l0
F0005898: 80a40015                 cmp     %l0, %l5
F000589C: 0a800007                 bcs     loc_F00058B8
F00058A0: a2047fff                 inc     -1, %l1
F00058A4: 80a4000a                 cmp     %l0, %o2
F00058A8: 1a800005                 bcc     loc_F00058BC
F00058AC: 912ca010                 sll     %l2, 16, %o0
F00058B0: a2047fff                 inc     -1, %l1
F00058B4: a0040015                 add     %l0, %l5, %l0
F00058B8: 912ca010                 sll     %l2, 16, %o0
F00058BC: ac120011                 or      %o0, %l1, %l6
F00058C0: b024000a                 sub     %l0, %o2, %i0
F00058C4: 90100018                 mov     %i0, %o0
F00058C8: a7356010                 srl     %l5, 16, %l3
F00058CC: 92100013                 mov     %l3, %o1
F00058D0: 1500003f9412a3ff         set     0xFFFF, %o2
F00058D8: 400003f2                 call    _urem
F00058DC: a80d400a                 and     %l5, %o2, %l4
F00058E0: a0100008                 mov     %o0, %l0
F00058E4: 90100018                 mov     %i0, %o0
F00058E8: 40000346                 call    _udiv
F00058EC: 92100013                 mov     %l3, %o1
F00058F0: a4100008                 mov     %o0, %l2
F00058F4: 40000303                 call    _umul
F00058F8: 92100014                 mov     %l4, %o1
F00058FC: 94100008                 mov     %o0, %o2
F0005900: 932c2010                 sll     %l0, 16, %o1
F0005904: 9136e010                 srl     %i3, 16, %o0
F0005908: a0124008                 or      %o1, %o0, %l0
F000590C: 80a4000a                 cmp     %l0, %o2
F0005910: 3a80000c                 bcc,a   loc_F0005940
F0005914: a024000a                 sub     %l0, %o2, %l0
F0005918: a0040015                 add     %l0, %l5, %l0
F000591C: 80a40015                 cmp     %l0, %l5
F0005920: 0a800007                 bcs     loc_F000593C
F0005924: a404bfff                 inc     -1, %l2
F0005928: 80a4000a                 cmp     %l0, %o2
F000592C: 3a800005                 bcc,a   loc_F0005940
F0005930: a024000a                 sub     %l0, %o2, %l0
F0005934: a404bfff                 inc     -1, %l2
F0005938: a0040015                 add     %l0, %l5, %l0
F000593C: a024000a                 sub     %l0, %o2, %l0
F0005940: 90100010                 mov     %l0, %o0
F0005944: 400003d7                 call    _urem
F0005948: 92100013                 mov     %l3, %o1
F000594C: a2100008                 mov     %o0, %l1
F0005950: 90100010                 mov     %l0, %o0
F0005954: 4000032b                 call    _udiv
F0005958: 92100013                 mov     %l3, %o1
F000595C: a0100008                 mov     %o0, %l0
F0005960: 400002e8                 call    _umul
F0005964: 92100014                 mov     %l4, %o1
F0005968: 94100008                 mov     %o0, %o2
F000596C: 932c6010                 sll     %l1, 16, %o1
F0005970: 1100003f901223ff         set     0xFFFF, %o0
F0005978: 900ec008                 and     %i3, %o0, %o0
F000597C: a2124008                 or      %o1, %o0, %l1
F0005980: 80a4400a                 cmp     %l1, %o2
F0005984: 3a80000c                 bcc,a   loc_F00059B4
F0005988: 912ca010                 sll     %l2, 16, %o0
F000598C: a2044015                 add     %l1, %l5, %l1
F0005990: 80a44015                 cmp     %l1, %l5
F0005994: 0a800007                 bcs     loc_F00059B0
F0005998: a0043fff                 inc     -1, %l0
F000599C: 80a4400a                 cmp     %l1, %o2
F00059A0: 1a800005                 bcc     loc_F00059B4
F00059A4: 912ca010                 sll     %l2, 16, %o0
F00059A8: a0043fff                 inc     -1, %l0
F00059AC: a2044015                 add     %l1, %l5, %l1
F00059B0: 912ca010                 sll     %l2, 16, %o0
F00059B4: b2120010                 or      %o0, %l0, %i1
F00059B8: b624400a                 sub     %l1, %o2, %i3
F00059BC: 80a76000                 cmp     %i5, 0
F00059C0: 028000b9                 be      loc_F0005CA4
F00059C4: b736c017                 srl     %i3, %l7, %i3
F00059C8: f627bfec                 st      %i3, [%fp+var_18+4]
F00059CC: 108000b4                 ba      loc_F0005C9C
F00059D0: c027bfe8                 clr     [%fp+var_18]
F00059D4: 80a68018                 cmp     %i2, %i0
F00059D8: 08800007                 bleu    loc_F00059F4
F00059DC: b2102000                 mov     0, %i1
F00059E0: 80a76000                 cmp     %i5, 0
F00059E4: 028000b0                 be      loc_F0005CA4
F00059E8: ac102000                 mov     0, %l6
F00059EC: 108000ab                 ba      loc_F0005C98
F00059F0: f627bfec                 st      %i3, [%fp+var_18+4]
F00059F4: 1100003f901223ff         set     0xFFFF, %o0
F00059FC: 80a68008                 cmp     %i2, %o0
F0005A00: 18800006                 bgu     loc_F0005A18
F0005A04: 9210001a                 mov     %i2, %o1
F0005A08: 80a6a100                 cmp     %i2, 0x100
F0005A0C: 90403fff                 addc    %g0, -1, %o0
F0005A10: 10800008                 ba      loc_F0005A30
F0005A14: 940a2008                 and     %o0, 8, %o2
F0005A18: 11003fff901223ff         set     0xFFFFFF, %o0
F0005A20: 80a68008                 cmp     %i2, %o0
F0005A24: 18800003                 bgu     loc_F0005A30
F0005A28: 94102018                 mov     0x18, %o2
F0005A2C: 94102010                 mov     0x10, %o2
F0005A30: 9132400a                 srl     %o1, %o2, %o0
F0005A34: 133c03d292126298         set     unk_F00F4A98, %o1
F0005A3C: d00a0009                 ldub    [%o0+%o1], %o0
F0005A40: 9002000a                 add     %o0, %o2, %o0
F0005A44: 92102020                 mov     0x20, %o1 ! ' '
F0005A48: aea24008                 subcc   %o1, %o0, %l7
F0005A4C: 12800011                 bne     loc_F0005A90
F0005A50: b8224017                 sub     %o1, %l7, %i4
F0005A54: 80a6001a                 cmp     %i0, %i2
F0005A58: 18800004                 bgu     loc_F0005A68
F0005A5C: 80a6c015                 cmp     %i3, %l5
F0005A60: 0a800007                 bcs     loc_F0005A7C
F0005A64: b2102000                 mov     0, %i1
F0005A68: b2102001                 mov     1, %i1
F0005A6C: 9026c015                 sub     %i3, %l5, %o0
F0005A70: 80a6c008                 cmp     %i3, %o0
F0005A74: b066001a                 subc    %i0, %i2, %i0
F0005A78: b6100008                 mov     %o0, %i3
F0005A7C: 80a76000                 cmp     %i5, 0
F0005A80: 02800089                 be      loc_F0005CA4
F0005A84: ac102000                 mov     0, %l6
F0005A88: 10800084                 ba      loc_F0005C98
F0005A8C: f627bfec                 st      %i3, [%fp+var_18+4]
F0005A90: 932e8017                 sll     %i2, %l7, %o1
F0005A94: 9135401c                 srl     %l5, %i4, %o0
F0005A98: b4124008                 or      %o1, %o0, %i2
F0005A9C: ab2d4017                 sll     %l5, %l7, %l5
F0005AA0: a536001c                 srl     %i0, %i4, %l2
F0005AA4: 932e0017                 sll     %i0, %l7, %o1
F0005AA8: 9136c01c                 srl     %i3, %i4, %o0
F0005AAC: b0124008                 or      %o1, %o0, %i0
F0005AB0: b72ec017                 sll     %i3, %l7, %i3
F0005AB4: a736a010                 srl     %i2, 16, %l3
F0005AB8: 90100012                 mov     %l2, %o0
F0005ABC: 92100013                 mov     %l3, %o1
F0005AC0: 1500003f9412a3ff         set     0xFFFF, %o2
F0005AC8: 40000376                 call    _urem
F0005ACC: a80e800a                 and     %i2, %o2, %l4
F0005AD0: a0100008                 mov     %o0, %l0
F0005AD4: 90100012                 mov     %l2, %o0
F0005AD8: 400002ca                 call    _udiv
F0005ADC: 92100013                 mov     %l3, %o1
F0005AE0: a4100008                 mov     %o0, %l2
F0005AE4: 40000287                 call    _umul
F0005AE8: 92100014                 mov     %l4, %o1
F0005AEC: 94100008                 mov     %o0, %o2
F0005AF0: 932c2010                 sll     %l0, 16, %o1
F0005AF4: 91362010                 srl     %i0, 16, %o0
F0005AF8: a0124008                 or      %o1, %o0, %l0
F0005AFC: 80a4000a                 cmp     %l0, %o2
F0005B00: 3a80000c                 bcc,a   loc_F0005B30
F0005B04: a024000a                 sub     %l0, %o2, %l0
F0005B08: a004001a                 add     %l0, %i2, %l0
F0005B0C: 80a4001a                 cmp     %l0, %i2
F0005B10: 0a800007                 bcs     loc_F0005B2C
F0005B14: a404bfff                 inc     -1, %l2
F0005B18: 80a4000a                 cmp     %l0, %o2
F0005B1C: 3a800005                 bcc,a   loc_F0005B30
F0005B20: a024000a                 sub     %l0, %o2, %l0
F0005B24: a404bfff                 inc     -1, %l2
F0005B28: a004001a                 add     %l0, %i2, %l0
F0005B2C: a024000a                 sub     %l0, %o2, %l0
F0005B30: 90100010                 mov     %l0, %o0
F0005B34: 4000035b                 call    _urem
F0005B38: 92100013                 mov     %l3, %o1
F0005B3C: a2100008                 mov     %o0, %l1
F0005B40: 90100010                 mov     %l0, %o0
F0005B44: 400002af                 call    _udiv
F0005B48: 92100013                 mov     %l3, %o1
F0005B4C: a0100008                 mov     %o0, %l0
F0005B50: 4000026c                 call    _umul
F0005B54: 92100014                 mov     %l4, %o1
F0005B58: 94100008                 mov     %o0, %o2
F0005B5C: 932c6010                 sll     %l1, 16, %o1
F0005B60: 1100003f901223ff         set     0xFFFF, %o0
F0005B68: 900e0008                 and     %i0, %o0, %o0
F0005B6C: a2124008                 or      %o1, %o0, %l1
F0005B70: 80a4400a                 cmp     %l1, %o2
F0005B74: 3a80000c                 bcc,a   loc_F0005BA4
F0005B78: 912ca010                 sll     %l2, 16, %o0
F0005B7C: a204401a                 add     %l1, %i2, %l1
F0005B80: 80a4401a                 cmp     %l1, %i2
F0005B84: 0a800007                 bcs     loc_F0005BA0
F0005B88: a0043fff                 inc     -1, %l0
F0005B8C: 80a4400a                 cmp     %l1, %o2
F0005B90: 1a800005                 bcc     loc_F0005BA4
F0005B94: 912ca010                 sll     %l2, 16, %o0
F0005B98: a0043fff                 inc     -1, %l0
F0005B9C: a204401a                 add     %l1, %i2, %l1
F0005BA0: 912ca010                 sll     %l2, 16, %o0
F0005BA4: b2120010                 or      %o0, %l0, %i1
F0005BA8: b024400a                 sub     %l1, %o2, %i0
F0005BAC: 1100003fac1223ff         set     0xFFFF, %l6
F0005BB4: a00e4016                 and     %i1, %l6, %l0
F0005BB8: 90100010                 mov     %l0, %o0
F0005BBC: a20d4016                 and     %l5, %l6, %l1
F0005BC0: 40000250                 call    _umul
F0005BC4: 92100011                 mov     %l1, %o1
F0005BC8: a6100008                 mov     %o0, %l3
F0005BCC: 90100010                 mov     %l0, %o0
F0005BD0: a5356010                 srl     %l5, 16, %l2
F0005BD4: 4000024b                 call    _umul
F0005BD8: 92100012                 mov     %l2, %o1
F0005BDC: a8100008                 mov     %o0, %l4
F0005BE0: a1366010                 srl     %i1, 16, %l0
F0005BE4: 90100010                 mov     %l0, %o0
F0005BE8: 40000246                 call    _umul
F0005BEC: 92100011                 mov     %l1, %o1
F0005BF0: a2100008                 mov     %o0, %l1
F0005BF4: 90100010                 mov     %l0, %o0
F0005BF8: 40000242                 call    _umul
F0005BFC: 92100012                 mov     %l2, %o1
F0005C00: 92100008                 mov     %o0, %o1
F0005C04: 9134e010                 srl     %l3, 16, %o0
F0005C08: a8050008                 add     %l4, %o0, %l4
F0005C0C: a8050011                 add     %l4, %l1, %l4
F0005C10: 80a50011                 cmp     %l4, %l1
F0005C14: 1a800003                 bcc     loc_F0005C20
F0005C18: 11000040                 sethi   0x10000, %o0
F0005C1C: 92024008                 add     %o1, %o0, %o1
F0005C20: 91352010                 srl     %l4, 16, %o0
F0005C24: 94024008                 add     %o1, %o0, %o2
F0005C28: 900d0016                 and     %l4, %l6, %o0
F0005C2C: 912a2010                 sll     %o0, 16, %o0
F0005C30: 920cc016                 and     %l3, %l6, %o1
F0005C34: 80a28018                 cmp     %o2, %i0
F0005C38: 18800008                 bgu     loc_F0005C58
F0005C3C: 92020009                 add     %o0, %o1, %o1
F0005C40: 80a28018                 cmp     %o2, %i0
F0005C44: 1280000b                 bne     loc_F0005C70
F0005C48: 80a76000                 cmp     %i5, 0
F0005C4C: 80a2401b                 cmp     %o1, %i3
F0005C50: 08800008                 bleu    loc_F0005C70
F0005C54: 80a76000                 cmp     %i5, 0
F0005C58: b2067fff                 inc     -1, %i1
F0005C5C: 90224015                 sub     %o1, %l5, %o0
F0005C60: 80a24008                 cmp     %o1, %o0
F0005C64: 9462801a                 subc    %o2, %i2, %o2
F0005C68: 92100008                 mov     %o0, %o1
F0005C6C: 80a76000                 cmp     %i5, 0
F0005C70: 0280000d                 be      loc_F0005CA4
F0005C74: ac102000                 mov     0, %l6
F0005C78: 9026c009                 sub     %i3, %o1, %o0
F0005C7C: 80a6c008                 cmp     %i3, %o0
F0005C80: b066000a                 subc    %i0, %o2, %i0
F0005C84: 932e001c                 sll     %i0, %i4, %o1
F0005C88: 91320017                 srl     %o0, %l7, %o0
F0005C8C: 92124008                 bset    %o0, %o1
F0005C90: d227bfec                 st      %o1, [%fp+var_18+4]
F0005C94: b1360017                 srl     %i0, %l7, %i0
F0005C98: f027bfe8                 st      %i0, [%fp+var_18]
F0005C9C: d81fbfe8                 ldd     [%fp+var_18], %o4
F0005CA0: d83f4000                 std     %o4, [%i5]
F0005CA4: f227bff4                 st      %i1, [%fp+var_10+4]
F0005CA8: ec27bff0                 st      %l6, [%fp+var_10]
F0005CAC: f01fbff0                 ldd     [%fp+var_10], %i0
F0005CB0: 81c7e008                 ret
F0005CB4: 81e80000                 restore
