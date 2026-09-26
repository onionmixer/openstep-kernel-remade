F00D8B9C: 9de3bf90                 save    %sp, -0x70, %sp
F00D8BA0: 113c0505                 sethi   %hi(paInputchannel), %o0
F00D8BA4: d2022220                 ld      [%o0+%lo(paInputchannel)], %o1! SEL
F00D8BA8: 113c0505                 sethi   %hi(paIsequal), %o0! id
F00D8BAC: e0022150                 ld      [%o0+%lo(paIsequal)], %l0
F00D8BB0: a4102001                 mov     1, %l2
F00D8BB4: 4000632f                 call    _objc_msgSend
F00D8BB8: 90100018                 mov     %i0, %o0
F00D8BBC: 94100008                 mov     %o0, %o2
F00D8BC0: 9010001c                 mov     %i4, %o0! id
F00D8BC4: 4000632b                 call    _objc_msgSend
F00D8BC8: 92100010                 mov     %l0, %o1
F00D8BCC: 912a2018                 sll     %o0, 24, %o0
F00D8BD0: 80a22000                 cmp     %o0, 0
F00D8BD4: 02800041                 be      loc_F00D8CD8
F00D8BD8: 80a6a022                 cmp     %i2, 0x22 ! '"'! switch 35 cases
F00D8BDC: 1880011b                 bgu     def_F00D8BF0! jumptable F00D8BF0 default case, cases 3-13,15,18-29
F00D8BE0: 932ea002                 sll     %i2, 2, %o1
F00D8BE4: 113c0362901223f8         set     jpt_F00D8BF0, %o0
F00D8BEC: d0024008                 ld      [%o1+%o0], %o0
F00D8BF0: 81c20000                 jmp     %o0! switch jump
F00D8BF4: 01000000                 nop
F00D8C84: 90100018                 mov     %i0, %o0! jumptable F00D8BF0 case 16
F00D8C88: 133c0505                 sethi   %hi(paSetinputgainle), %o1
F00D8C8C: d202615c                 ld      [%o1+%lo(paSetinputgainle)], %o1! SEL
F00D8C90: 400062f8                 call    _objc_msgSend
F00D8C94: 9410001b                 mov     %i3, %o2
F00D8C98: 90100018                 mov     %i0, %o0
F00D8C9C: 133c0505                 sethi   %hi(paSetinputgainri), %o1
F00D8CA0: 108000e4                 ba      loc_F00D9030
F00D8CA4: d2026158                 ld      [%o1+%lo(paSetinputgainri)], %o1
F00D8CA8: 90100018                 mov     %i0, %o0! jumptable F00D8BF0 case 17
F00D8CAC: 133c0505                 sethi   %hi(paSetinputgainle), %o1
F00D8CB0: 108000e0                 ba      loc_F00D9030
F00D8CB4: d202615c                 ld      [%o1+%lo(paSetinputgainle)], %o1
F00D8CB8: 90100018                 mov     %i0, %o0! jumptable F00D8BF0 case 14
F00D8CBC: 133c0505                 sethi   %hi(paSetanaloginput), %o1
F00D8CC0: 108000dc                 ba      loc_F00D9030
F00D8CC4: d2026124                 ld      [%o1+%lo(paSetanaloginput)], %o1
F00D8CC8: 90100018                 mov     %i0, %o0! jumptable F00D8BF0 cases 30-34
F00D8CCC: 133c0505                 sethi   %hi(paSetinputforTo), %o1
F00D8CD0: 1080004f                 ba      loc_F00D8E0C
F00D8CD4: d2026154                 ld      [%o1+%lo(paSetinputforTo)], %o1
F00D8CD8: 113c0505                 sethi   %hi(paOutputchannel), %o0! id
F00D8CDC: d2022218                 ld      [%o0+%lo(paOutputchannel)], %o1! SEL
F00D8CE0: 400062e4                 call    _objc_msgSend
F00D8CE4: 90100018                 mov     %i0, %o0
F00D8CE8: 94100008                 mov     %o0, %o2
F00D8CEC: 9010001c                 mov     %i4, %o0! id
F00D8CF0: 400062e0                 call    _objc_msgSend
F00D8CF4: 92100010                 mov     %l0, %o1
F00D8CF8: 912a2018                 sll     %o0, 24, %o0
F00D8CFC: 80a22000                 cmp     %o0, 0
F00D8D00: 02800048                 be      loc_F00D8E20
F00D8D04: 80a6a01d                 cmp     %i2, 0x1D! switch 30 cases
F00D8D08: 188000d0                 bgu     def_F00D8BF0! jumptable F00D8BF0 default case, cases 3-13,15,18-29
F00D8D0C: 932ea002                 sll     %i2, 2, %o1
F00D8D10: 113c036390122124         set     jpt_F00D8D1C, %o0
F00D8D18: d0024008                 ld      [%o1+%o0], %o0
F00D8D1C: 81c20000                 jmp     %o0! switch jump
F00D8D20: 01000000                 nop
F00D8D9C: 90100018                 mov     %i0, %o0! jumptable F00D8D1C cases 7-9
F00D8DA0: 133c0505                 sethi   %hi(paSetoutputmute), %o1
F00D8DA4: 10800091                 ba      loc_F00D8FE8
F00D8DA8: d2026178                 ld      [%o1+%lo(paSetoutputmute)], %o1
F00D8DAC: 90100018                 mov     %i0, %o0! jumptable F00D8D1C case 10
F00D8DB0: 133c0505                 sethi   %hi(paSetloudnessenh), %o1
F00D8DB4: 1080008d                 ba      loc_F00D8FE8
F00D8DB8: d2026120                 ld      [%o1+%lo(paSetloudnessenh)], %o1
F00D8DBC: 90100018                 mov     %i0, %o0! jumptable F00D8D1C case 11
F00D8DC0: 133c0505                 sethi   %hi(paSetoutputatten_0), %o1
F00D8DC4: d202616c                 ld      [%o1+%lo(paSetoutputatten_0)], %o1! SEL
F00D8DC8: 400062aa                 call    _objc_msgSend
F00D8DCC: 9410001b                 mov     %i3, %o2
F00D8DD0: 90100018                 mov     %i0, %o0
F00D8DD4: 133c0505                 sethi   %hi(paSetoutputatten), %o1
F00D8DD8: 10800096                 ba      loc_F00D9030
F00D8DDC: d2026168                 ld      [%o1+%lo(paSetoutputatten)], %o1
F00D8DE0: 90100018                 mov     %i0, %o0! jumptable F00D8D1C case 12
F00D8DE4: 133c0505                 sethi   %hi(paSetoutputatten_0), %o1
F00D8DE8: 10800092                 ba      loc_F00D9030
F00D8DEC: d202616c                 ld      [%o1+%lo(paSetoutputatten_0)], %o1
F00D8DF0: 90100018                 mov     %i0, %o0! jumptable F00D8D1C case 13
F00D8DF4: 133c0505                 sethi   %hi(paSetoutputatten), %o1
F00D8DF8: 1080008e                 ba      loc_F00D9030
F00D8DFC: d2026168                 ld      [%o1+%lo(paSetoutputatten)], %o1
F00D8E00: 90100018                 mov     %i0, %o0! jumptable F00D8D1C cases 25-29
F00D8E04: 133c0505                 sethi   %hi(paSetoutputforTo), %o1
F00D8E08: d202611c                 ld      [%o1+%lo(paSetoutputforTo)], %o1! SEL
F00D8E0C: 9410001a                 mov     %i2, %o2
F00D8E10: 972ee018                 sll     %i3, 24, %o3
F00D8E14: 40006297                 call    _objc_msgSend
F00D8E18: 973ae018                 sra     %o3, 24, %o3
F00D8E1C: 3080008c                 ba,a    locret_F00D904C! jumptable F00D8BF0 cases 0,1
F00D8E20: 133c0504                 sethi   %hi(paClass), %o1
F00D8E24: e0026014                 ld      [%o1+%lo(paClass)], %l0
F00D8E28: 133c0504                 sethi   %hi(paIskindof), %o1! SEL
F00D8E2C: e2026040                 ld      [%o1+%lo(paIskindof)], %l1
F00D8E30: 113c0506                 sethi   %hi(paInputstream), %o0
F00D8E34: d00222dc                 ld      [%o0+%lo(paInputstream)], %o0! id
F00D8E38: 4000628e                 call    _objc_msgSend
F00D8E3C: 92100010                 mov     %l0, %o1! SEL
F00D8E40: 94100008                 mov     %o0, %o2
F00D8E44: 9010001c                 mov     %i4, %o0! id
F00D8E48: 4000628a                 call    _objc_msgSend
F00D8E4C: 92100011                 mov     %l1, %o1
F00D8E50: 912a2018                 sll     %o0, 24, %o0
F00D8E54: 80a22000                 cmp     %o0, 0
F00D8E58: 02800029                 be      loc_F00D8EFC
F00D8E5C: 9206be70                 add     %i2, -0x190, %o1
F00D8E60: 80a26005                 cmp     %o1, 5! switch 6 cases
F00D8E64: 18800079                 bgu     def_F00D8BF0! jumptable F00D8BF0 default case, cases 3-13,15,18-29
F00D8E68: 932a6002                 sll     %o1, 2, %o1
F00D8E6C: 113c036390122280         set     jpt_F00D8E78, %o0
F00D8E74: d0024008                 ld      [%o1+%o0], %o0
F00D8E78: 81c20000                 jmp     %o0! switch jump
F00D8E7C: 01000000                 nop
F00D8E98: 9010001c                 mov     %i4, %o0! jumptable F00D8E78 case 0
F00D8E9C: 133c0505                 sethi   %hi(paSetdataencodin_0), %o1
F00D8EA0: 10800064                 ba      loc_F00D9030
F00D8EA4: d2026118                 ld      [%o1+%lo(paSetdataencodin_0)], %o1
F00D8EA8: 9010001c                 mov     %i4, %o0! jumptable F00D8E78 case 1
F00D8EAC: 133c0505                 sethi   %hi(paSetsamplingrat), %o1
F00D8EB0: 10800060                 ba      loc_F00D9030
F00D8EB4: d2026114                 ld      [%o1+%lo(paSetsamplingrat)], %o1
F00D8EB8: 9010001c                 mov     %i4, %o0! jumptable F00D8E78 case 2
F00D8EBC: 133c0505                 sethi   %hi(paSetchannelcoun_0), %o1
F00D8EC0: 1080005c                 ba      loc_F00D9030
F00D8EC4: d2026110                 ld      [%o1+%lo(paSetchannelcoun_0)], %o1
F00D8EC8: 9010001c                 mov     %i4, %o0! jumptable F00D8E78 case 3
F00D8ECC: 133c0505                 sethi   %hi(paSethighwaterma), %o1
F00D8ED0: 10800058                 ba      loc_F00D9030
F00D8ED4: d202610c                 ld      [%o1+%lo(paSethighwaterma)], %o1
F00D8ED8: 9010001c                 mov     %i4, %o0! jumptable F00D8E78 case 4
F00D8EDC: 133c0505                 sethi   %hi(paSetlowwatermar), %o1
F00D8EE0: 10800054                 ba      loc_F00D9030
F00D8EE4: d2026108                 ld      [%o1+%lo(paSetlowwatermar)], %o1! SEL
F00D8EE8: 80a6e25d                 cmp     %i3, 0x25D! jumptable F00D8E78 case 5
F00D8EEC: 02800058                 be      locret_F00D904C! jumptable F00D8BF0 cases 0,1
F00D8EF0: 01000000                 nop
F00D8EF4: 10800056                 ba      locret_F00D904C! jumptable F00D8BF0 cases 0,1
F00D8EF8: a4102000                 mov     0, %l2
F00D8EFC: 113c0506                 sethi   %hi(paOutputstream), %o0
F00D8F00: d00222d8                 ld      [%o0+%lo(paOutputstream)], %o0! id
F00D8F04: 4000625b                 call    _objc_msgSend
F00D8F08: 92100010                 mov     %l0, %o1! SEL
F00D8F0C: 94100008                 mov     %o0, %o2
F00D8F10: 9010001c                 mov     %i4, %o0! id
F00D8F14: 40006257                 call    _objc_msgSend
F00D8F18: 92100011                 mov     %l1, %o1
F00D8F1C: 912a2018                 sll     %o0, 24, %o0
F00D8F20: 80a22000                 cmp     %o0, 0
F00D8F24: 02800046                 be      loc_F00D903C
F00D8F28: 9206be70                 add     %i2, -0x190, %o1
F00D8F2C: 80a2600a                 cmp     %o1, 0xA! switch 11 cases
F00D8F30: 18800046                 bgu     def_F00D8BF0! jumptable F00D8BF0 default case, cases 3-13,15,18-29
F00D8F34: 932a6002                 sll     %o1, 2, %o1
F00D8F38: 113c03639012234c         set     jpt_F00D8F44, %o0
F00D8F40: d0024008                 ld      [%o1+%o0], %o0
F00D8F44: 81c20000                 jmp     %o0! switch jump
F00D8F48: 01000000                 nop
F00D8F78: 9010001c                 mov     %i4, %o0! jumptable F00D8F44 case 0
F00D8F7C: 133c0505                 sethi   %hi(paSetdataencodin_0), %o1
F00D8F80: 1080002c                 ba      loc_F00D9030
F00D8F84: d2026118                 ld      [%o1+%lo(paSetdataencodin_0)], %o1
F00D8F88: 9010001c                 mov     %i4, %o0! jumptable F00D8F44 case 1
F00D8F8C: 133c0505                 sethi   %hi(paSetsamplingrat), %o1
F00D8F90: 10800028                 ba      loc_F00D9030
F00D8F94: d2026114                 ld      [%o1+%lo(paSetsamplingrat)], %o1
F00D8F98: 9010001c                 mov     %i4, %o0! jumptable F00D8F44 case 2
F00D8F9C: 133c0505                 sethi   %hi(paSetchannelcoun_0), %o1
F00D8FA0: 10800024                 ba      loc_F00D9030
F00D8FA4: d2026110                 ld      [%o1+%lo(paSetchannelcoun_0)], %o1
F00D8FA8: 9010001c                 mov     %i4, %o0! jumptable F00D8F44 case 3
F00D8FAC: 133c0505                 sethi   %hi(paSethighwaterma), %o1
F00D8FB0: 10800020                 ba      loc_F00D9030
F00D8FB4: d202610c                 ld      [%o1+%lo(paSethighwaterma)], %o1
F00D8FB8: 9010001c                 mov     %i4, %o0! jumptable F00D8F44 case 4
F00D8FBC: 133c0505                 sethi   %hi(paSetlowwatermar), %o1
F00D8FC0: 1080001c                 ba      loc_F00D9030
F00D8FC4: d2026108                 ld      [%o1+%lo(paSetlowwatermar)], %o1
F00D8FC8: 80a6e25f                 cmp     %i3, 0x25F! jumptable F00D8F44 case 6
F00D8FCC: 02800020                 be      locret_F00D904C! jumptable F00D8BF0 cases 0,1
F00D8FD0: 01000000                 nop
F00D8FD4: 1080001e                 ba      locret_F00D904C! jumptable F00D8BF0 cases 0,1
F00D8FD8: a4102000                 mov     0, %l2
F00D8FDC: 9010001c                 mov     %i4, %o0! jumptable F00D8BF0 case 2
F00D8FE0: 133c0505                 sethi   %hi(paSetdetectpeaks), %o1
F00D8FE4: d2026128                 ld      [%o1+%lo(paSetdetectpeaks)], %o1! SEL
F00D8FE8: 952ee018                 sll     %i3, 24, %o2
F00D8FEC: 40006221                 call    _objc_msgSend
F00D8FF0: 953aa018                 sra     %o2, 24, %o2
F00D8FF4: 30800016                 ba,a    locret_F00D904C! jumptable F00D8BF0 cases 0,1
F00D8FF8: 9010001c                 mov     %i4, %o0! jumptable F00D8F44 case 8
F00D8FFC: 133c0505                 sethi   %hi(paSetgainleft), %o1
F00D9000: d2026104                 ld      [%o1+%lo(paSetgainleft)], %o1! SEL
F00D9004: 4000621b                 call    _objc_msgSend
F00D9008: 9410001b                 mov     %i3, %o2
F00D900C: 10800007                 ba      loc_F00D9028
F00D9010: 9010001c                 mov     %i4, %o0
F00D9014: 9010001c                 mov     %i4, %o0! jumptable F00D8F44 case 9
F00D9018: 133c0505                 sethi   %hi(paSetgainleft), %o1
F00D901C: 10800005                 ba      loc_F00D9030
F00D9020: d2026104                 ld      [%o1+%lo(paSetgainleft)], %o1
F00D9024: 9010001c                 mov     %i4, %o0! jumptable F00D8F44 case 10
F00D9028: 133c0505                 sethi   %hi(paSetgainright), %o1
F00D902C: d2026100                 ld      [%o1+%lo(paSetgainright)], %o1! SEL
F00D9030: 40006210                 call    _objc_msgSend
F00D9034: 9410001b                 mov     %i3, %o2
F00D9038: 30800005                 ba,a    locret_F00D904C! jumptable F00D8BF0 cases 0,1
F00D903C: 113c03f0                 sethi   %hi(aAudioUnknownPa), %o0! "Audio: unknown parameter object\n"
F00D9040: 7fffb42d                 call    _IOLog
F00D9044: 901221e0                 bset    %lo(aAudioUnknownPa), %o0! "Audio: unknown parameter object\n"
F00D9048: a4102000                 mov     0, %l2! jumptable F00D8BF0 default case, cases 3-13,15,18-29
F00D904C: 81c7e008                 ret! jumptable F00D8BF0 cases 0,1
F00D9050: 91e80012                 restore %g0, %l2, %o0
