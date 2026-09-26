F00D8668: 9de3bf90                 save    %sp, -0x70, %sp
F00D866C: 113c0505                 sethi   %hi(paInputchannel), %o0
F00D8670: d2022220                 ld      [%o0+%lo(paInputchannel)], %o1! SEL
F00D8674: a2100018                 mov     %i0, %l1
F00D8678: 113c0505                 sethi   %hi(paIsequal), %o0! id
F00D867C: e0022150                 ld      [%o0+%lo(paIsequal)], %l0
F00D8680: b0102000                 mov     0, %i0
F00D8684: 4000647b                 call    _objc_msgSend
F00D8688: 90100011                 mov     %l1, %o0
F00D868C: 94100008                 mov     %o0, %o2
F00D8690: 9010001b                 mov     %i3, %o0! id
F00D8694: 40006477                 call    _objc_msgSend
F00D8698: 92100010                 mov     %l0, %o1
F00D869C: 912a2018                 sll     %o0, 24, %o0
F00D86A0: 80a22000                 cmp     %o0, 0
F00D86A4: 02800056                 be      loc_F00D87FC
F00D86A8: 80a6a022                 cmp     %i2, 0x22 ! '"'! switch 35 cases
F00D86AC: 1880013a                 bgu     def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D86B0: 113c0361                 sethi   %hi(jpt_F00D86C0), %o0
F00D86B4: 901222c8                 bset    %lo(jpt_F00D86C0), %o0
F00D86B8: 932ea002                 sll     %i2, 2, %o1
F00D86BC: d0024008                 ld      [%o1+%o0], %o0
F00D86C0: 81c20000                 jmp     %o0! switch jump
F00D86C4: 01000000                 nop
F00D8754: 113c0505                 sethi   %hi(paDescriptorsize), %o0! jumptable F00D86C0 case 0
F00D8758: 10800106                 ba      loc_F00D8B70
F00D875C: d20221a4                 ld      [%o0+%lo(paDescriptorsize)], %o1
F00D8760: 113c0505                 sethi   %hi(paDmacount), %o0! jumptable F00D86C0 case 1
F00D8764: 10800103                 ba      loc_F00D8B70
F00D8768: d20221c4                 ld      [%o0+%lo(paDmacount)], %o1
F00D876C: 113c0505                 sethi   %hi(paAnaloginputsou), %o0! jumptable F00D86C0 case 14
F00D8770: d2022148                 ld      [%o0+%lo(paAnaloginputsou)], %o1
F00D8774: 10800100                 ba      loc_F00D8B74
F00D8778: 90100011                 mov     %l1, %o0
F00D877C: 113c0505                 sethi   %hi(paInputgainleft_0), %o0! jumptable F00D86C0 case 16
F00D8780: d2022164                 ld      [%o0+%lo(paInputgainleft_0)], %o1! SEL
F00D8784: 4000643b                 call    _objc_msgSend
F00D8788: 90100011                 mov     %l1, %o0
F00D878C: 133c0505                 sethi   %hi(paInputgainright_0), %o1
F00D8790: a0100008                 mov     %o0, %l0
F00D8794: d2026160                 ld      [%o1+%lo(paInputgainright_0)], %o1
F00D8798: 108000ec                 ba      loc_F00D8B48
F00D879C: 90100011                 mov     %l1, %o0
F00D87A0: 113c0505                 sethi   %hi(paInputgainleft_0), %o0! jumptable F00D86C0 case 17
F00D87A4: d2022164                 ld      [%o0+%lo(paInputgainleft_0)], %o1
F00D87A8: 108000f3                 ba      loc_F00D8B74
F00D87AC: 90100011                 mov     %l1, %o0
F00D87B0: 113c0505                 sethi   %hi(paInputgainright_0), %o0! jumptable F00D86C0 case 18
F00D87B4: d2022160                 ld      [%o0+%lo(paInputgainright_0)], %o1
F00D87B8: 108000ef                 ba      loc_F00D8B74
F00D87BC: 90100011                 mov     %l1, %o0
F00D87C0: d0046174                 ld      [%l1+0x174], %o0! jumptable F00D86C0 case 30
F00D87C4: 108000f4                 ba      def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D87C8: f04a2010                 ldsb    [%o0+0x10], %i0
F00D87CC: d0046174                 ld      [%l1+0x174], %o0! jumptable F00D86C0 case 31
F00D87D0: 108000f1                 ba      def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D87D4: f04a2011                 ldsb    [%o0+0x11], %i0
F00D87D8: d0046174                 ld      [%l1+0x174], %o0! jumptable F00D86C0 case 32
F00D87DC: 108000ee                 ba      def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D87E0: f04a2012                 ldsb    [%o0+0x12], %i0
F00D87E4: d0046174                 ld      [%l1+0x174], %o0! jumptable F00D86C0 case 33
F00D87E8: 108000eb                 ba      def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D87EC: f04a2013                 ldsb    [%o0+0x13], %i0
F00D87F0: d0046174                 ld      [%l1+0x174], %o0! jumptable F00D86C0 case 34
F00D87F4: 108000e8                 ba      def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D87F8: f04a2014                 ldsb    [%o0+0x14], %i0
F00D87FC: 113c0505                 sethi   %hi(paOutputchannel), %o0! id
F00D8800: d2022218                 ld      [%o0+%lo(paOutputchannel)], %o1! SEL
F00D8804: 4000641b                 call    _objc_msgSend
F00D8808: 90100011                 mov     %l1, %o0
F00D880C: 94100008                 mov     %o0, %o2
F00D8810: 9010001b                 mov     %i3, %o0! id
F00D8814: 40006417                 call    _objc_msgSend
F00D8818: 92100010                 mov     %l0, %o1
F00D881C: 912a2018                 sll     %o0, 24, %o0
F00D8820: 80a22000                 cmp     %o0, 0
F00D8824: 0280005a                 be      loc_F00D898C
F00D8828: 80a6a01d                 cmp     %i2, 0x1D! switch 30 cases
F00D882C: 188000da                 bgu     def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D8830: 113c0362                 sethi   %hi(jpt_F00D8840), %o0
F00D8834: 90122048                 bset    %lo(jpt_F00D8840), %o0
F00D8838: 932ea002                 sll     %i2, 2, %o1
F00D883C: d0024008                 ld      [%o1+%o0], %o0
F00D8840: 81c20000                 jmp     %o0! switch jump
F00D8844: 01000000                 nop
F00D88C0: 113c0505                 sethi   %hi(paDescriptorsize), %o0! jumptable F00D8840 case 0
F00D88C4: 108000ab                 ba      loc_F00D8B70
F00D88C8: d20221a4                 ld      [%o0+%lo(paDescriptorsize)], %o1
F00D88CC: 113c0505                 sethi   %hi(paDmacount), %o0! jumptable F00D8840 case 1
F00D88D0: 108000a8                 ba      loc_F00D8B70
F00D88D4: d20221c4                 ld      [%o0+%lo(paDmacount)], %o1
F00D88D8: 113c0505                 sethi   %hi(paIsoutputmuted_0), %o0! jumptable F00D8840 cases 7-9
F00D88DC: d202217c                 ld      [%o0+%lo(paIsoutputmuted_0)], %o1
F00D88E0: 1080008d                 ba      loc_F00D8B14
F00D88E4: 90100011                 mov     %l1, %o0
F00D88E8: 113c0505                 sethi   %hi(paIsloudnessenha_0), %o0! jumptable F00D8840 case 10
F00D88EC: d2022144                 ld      [%o0+%lo(paIsloudnessenha_0)], %o1
F00D88F0: 10800089                 ba      loc_F00D8B14
F00D88F4: 90100011                 mov     %l1, %o0
F00D88F8: 113c0505                 sethi   %hi(paOutputattenuat_2), %o0! jumptable F00D8840 case 11
F00D88FC: d2022174                 ld      [%o0+%lo(paOutputattenuat_2)], %o1! SEL
F00D8900: 400063dc                 call    _objc_msgSend
F00D8904: 90100011                 mov     %l1, %o0! id
F00D8908: 133c0505                 sethi   %hi(paOutputattenuat_1), %o1
F00D890C: a0100008                 mov     %o0, %l0
F00D8910: d2026170                 ld      [%o1+%lo(paOutputattenuat_1)], %o1! SEL
F00D8914: 400063d7                 call    _objc_msgSend
F00D8918: 90100011                 mov     %l1, %o0
F00D891C: a0040008                 add     %l0, %o0, %l0
F00D8920: 9134201f                 srl     %l0, 31, %o0
F00D8924: a0040008                 add     %l0, %o0, %l0
F00D8928: 1080009b                 ba      def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D892C: b13c2001                 sra     %l0, 1, %i0
F00D8930: 113c0505                 sethi   %hi(paOutputattenuat_2), %o0! jumptable F00D8840 case 12
F00D8934: d2022174                 ld      [%o0+%lo(paOutputattenuat_2)], %o1
F00D8938: 1080008f                 ba      loc_F00D8B74
F00D893C: 90100011                 mov     %l1, %o0
F00D8940: 113c0505                 sethi   %hi(paOutputattenuat_1), %o0! jumptable F00D8840 case 13
F00D8944: d2022170                 ld      [%o0+%lo(paOutputattenuat_1)], %o1
F00D8948: 1080008b                 ba      loc_F00D8B74
F00D894C: 90100011                 mov     %l1, %o0
F00D8950: d0046174                 ld      [%l1+0x174], %o0! jumptable F00D8840 case 26
F00D8954: 10800090                 ba      def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D8958: f04a2015                 ldsb    [%o0+0x15], %i0
F00D895C: d0046174                 ld      [%l1+0x174], %o0! jumptable F00D8840 case 25
F00D8960: 1080008d                 ba      def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D8964: f04a2016                 ldsb    [%o0+0x16], %i0
F00D8968: d0046174                 ld      [%l1+0x174], %o0! jumptable F00D8840 case 27
F00D896C: 1080008a                 ba      def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D8970: f04a2017                 ldsb    [%o0+0x17], %i0
F00D8974: d0046174                 ld      [%l1+0x174], %o0! jumptable F00D8840 case 28
F00D8978: 10800087                 ba      def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D897C: f04a2018                 ldsb    [%o0+0x18], %i0
F00D8980: d0046174                 ld      [%l1+0x174], %o0! jumptable F00D8840 case 29
F00D8984: 10800084                 ba      def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D8988: f04a2019                 ldsb    [%o0+0x19], %i0
F00D898C: 133c0504                 sethi   %hi(paClass), %o1
F00D8990: e0026014                 ld      [%o1+%lo(paClass)], %l0
F00D8994: 133c0504                 sethi   %hi(paIskindof), %o1! SEL
F00D8998: e2026040                 ld      [%o1+%lo(paIskindof)], %l1
F00D899C: 113c0506                 sethi   %hi(paInputstream), %o0
F00D89A0: d00222dc                 ld      [%o0+%lo(paInputstream)], %o0! id
F00D89A4: 400063b3                 call    _objc_msgSend
F00D89A8: 92100010                 mov     %l0, %o1! SEL
F00D89AC: 94100008                 mov     %o0, %o2
F00D89B0: 9010001b                 mov     %i3, %o0! id
F00D89B4: 400063af                 call    _objc_msgSend
F00D89B8: 92100011                 mov     %l1, %o1
F00D89BC: 912a2018                 sll     %o0, 24, %o0
F00D89C0: 80a22000                 cmp     %o0, 0
F00D89C4: 02800021                 be      loc_F00D8A48
F00D89C8: 9206be70                 add     %i2, -0x190, %o1
F00D89CC: 80a26005                 cmp     %o1, 5! switch 6 cases
F00D89D0: 18800071                 bgu     def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D89D4: 113c0362                 sethi   %hi(jpt_F00D89E4), %o0
F00D89D8: 901221ec                 bset    %lo(jpt_F00D89E4), %o0
F00D89DC: 932a6002                 sll     %o1, 2, %o1
F00D89E0: d0024008                 ld      [%o1+%o0], %o0
F00D89E4: 81c20000                 jmp     %o0! switch jump
F00D89E8: 01000000                 nop
F00D8A04: 113c0505                 sethi   %hi(paDataencoding_0), %o0! jumptable F00D89E4 case 0
F00D8A08: 1080005a                 ba      loc_F00D8B70
F00D8A0C: d2022140                 ld      [%o0+%lo(paDataencoding_0)], %o1
F00D8A10: 113c0505                 sethi   %hi(paSamplingrate), %o0! jumptable F00D89E4 case 1
F00D8A14: 10800057                 ba      loc_F00D8B70
F00D8A18: d202213c                 ld      [%o0+%lo(paSamplingrate)], %o1
F00D8A1C: 113c0505                 sethi   %hi(paChannelcount_0), %o0! jumptable F00D89E4 case 2
F00D8A20: 10800054                 ba      loc_F00D8B70
F00D8A24: d20221c8                 ld      [%o0+%lo(paChannelcount_0)], %o1
F00D8A28: 113c0505                 sethi   %hi(paHighwatermark), %o0! jumptable F00D89E4 case 3
F00D8A2C: 10800051                 ba      loc_F00D8B70
F00D8A30: d2022138                 ld      [%o0+%lo(paHighwatermark)], %o1
F00D8A34: 113c0505                 sethi   %hi(paLowwatermark), %o0! jumptable F00D89E4 case 4
F00D8A38: 1080004e                 ba      loc_F00D8B70
F00D8A3C: d2022134                 ld      [%o0+%lo(paLowwatermark)], %o1! SEL
F00D8A40: 10800055                 ba      def_F00D86C0! jumptable F00D89E4 case 5
F00D8A44: b010225d                 mov     0x25D, %i0
F00D8A48: 113c0506                 sethi   %hi(paOutputstream), %o0
F00D8A4C: d00222d8                 ld      [%o0+%lo(paOutputstream)], %o0! id
F00D8A50: 40006388                 call    _objc_msgSend
F00D8A54: 92100010                 mov     %l0, %o1! SEL
F00D8A58: 94100008                 mov     %o0, %o2
F00D8A5C: 9010001b                 mov     %i3, %o0! id
F00D8A60: 40006384                 call    _objc_msgSend
F00D8A64: 92100011                 mov     %l1, %o1
F00D8A68: 912a2018                 sll     %o0, 24, %o0
F00D8A6C: 80a22000                 cmp     %o0, 0
F00D8A70: 02800045                 be      loc_F00D8B84
F00D8A74: 9206be70                 add     %i2, -0x190, %o1
F00D8A78: 80a2600a                 cmp     %o1, 0xA! switch 11 cases
F00D8A7C: 18800046                 bgu     def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D8A80: 113c0362                 sethi   %hi(jpt_F00D8A90), %o0
F00D8A84: 90122298                 bset    %lo(jpt_F00D8A90), %o0
F00D8A88: 932a6002                 sll     %o1, 2, %o1
F00D8A8C: d0024008                 ld      [%o1+%o0], %o0
F00D8A90: 81c20000                 jmp     %o0! switch jump
F00D8A94: 01000000                 nop
F00D8AC4: 113c0505                 sethi   %hi(paDataencoding_0), %o0! jumptable F00D8A90 case 0
F00D8AC8: 1080002a                 ba      loc_F00D8B70
F00D8ACC: d2022140                 ld      [%o0+%lo(paDataencoding_0)], %o1
F00D8AD0: 113c0505                 sethi   %hi(paSamplingrate), %o0! jumptable F00D8A90 case 1
F00D8AD4: 10800027                 ba      loc_F00D8B70
F00D8AD8: d202213c                 ld      [%o0+%lo(paSamplingrate)], %o1
F00D8ADC: 113c0505                 sethi   %hi(paChannelcount_0), %o0! jumptable F00D8A90 case 2
F00D8AE0: 10800024                 ba      loc_F00D8B70
F00D8AE4: d20221c8                 ld      [%o0+%lo(paChannelcount_0)], %o1
F00D8AE8: 113c0505                 sethi   %hi(paHighwatermark), %o0! jumptable F00D8A90 case 3
F00D8AEC: 10800021                 ba      loc_F00D8B70
F00D8AF0: d2022138                 ld      [%o0+%lo(paHighwatermark)], %o1
F00D8AF4: 113c0505                 sethi   %hi(paLowwatermark), %o0! jumptable F00D8A90 case 4
F00D8AF8: 1080001e                 ba      loc_F00D8B70
F00D8AFC: d2022134                 ld      [%o0+%lo(paLowwatermark)], %o1
F00D8B00: 10800025                 ba      def_F00D86C0! jumptable F00D8A90 case 6
F00D8B04: b010225f                 mov     0x25F, %i0
F00D8B08: 113c0505                 sethi   %hi(paIsdetectingpea), %o0! jumptable F00D86C0 case 2
F00D8B0C: d202214c                 ld      [%o0+%lo(paIsdetectingpea)], %o1! SEL
F00D8B10: 9010001b                 mov     %i3, %o0! id
F00D8B14: 40006357                 call    _objc_msgSend
F00D8B18: 01000000                 nop
F00D8B1C: 912a2018                 sll     %o0, 24, %o0
F00D8B20: 1080001d                 ba      def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D8B24: b13a2018                 sra     %o0, 24, %i0
F00D8B28: 113c0505                 sethi   %hi(paGainleft), %o0! jumptable F00D8A90 case 8
F00D8B2C: d2022130                 ld      [%o0+%lo(paGainleft)], %o1! SEL
F00D8B30: 40006350                 call    _objc_msgSend
F00D8B34: 9010001b                 mov     %i3, %o0
F00D8B38: 133c0505                 sethi   %hi(paGainright), %o1
F00D8B3C: a0100008                 mov     %o0, %l0
F00D8B40: d202612c                 ld      [%o1+%lo(paGainright)], %o1! SEL
F00D8B44: 9010001b                 mov     %i3, %o0! id
F00D8B48: 4000634a                 call    _objc_msgSend
F00D8B4C: 01000000                 nop
F00D8B50: a0040008                 add     %l0, %o0, %l0
F00D8B54: 10800010                 ba      def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D8B58: b1342001                 srl     %l0, 1, %i0
F00D8B5C: 113c0505                 sethi   %hi(paGainleft), %o0! jumptable F00D8A90 case 9
F00D8B60: 10800004                 ba      loc_F00D8B70
F00D8B64: d2022130                 ld      [%o0+%lo(paGainleft)], %o1
F00D8B68: 113c0505                 sethi   %hi(paGainright), %o0! jumptable F00D8A90 case 10
F00D8B6C: d202212c                 ld      [%o0+%lo(paGainright)], %o1! SEL
F00D8B70: 9010001b                 mov     %i3, %o0! id
F00D8B74: 4000633f                 call    _objc_msgSend
F00D8B78: 01000000                 nop
F00D8B7C: 10800006                 ba      def_F00D86C0! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D8B80: b0100008                 mov     %o0, %i0
F00D8B84: 113c03f0                 sethi   %hi(aAudioUnknownPa), %o0! "Audio: unknown parameter object\n"
F00D8B88: 7fffb55b                 call    _IOLog
F00D8B8C: 901221e0                 bset    %lo(aAudioUnknownPa), %o0! "Audio: unknown parameter object\n"
F00D8B90: b0102000                 mov     0, %i0! jumptable F00D8840 cases 3-6
F00D8B94: 81c7e008                 ret! jumptable F00D86C0 default case, cases 3-13,15,19-29
F00D8B98: 81e80000                 restore
