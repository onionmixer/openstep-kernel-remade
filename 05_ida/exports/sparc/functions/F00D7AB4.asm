F00D7AB4: 9de3bf78                 save    %sp, -0x88, %sp
F00D7AB8: c027bfec                 clr     [%fp+var_14]
F00D7ABC: 90103fff                 mov     -1, %o0
F00D7AC0: d027bfe8                 st      %o0, [%fp+var_18]
F00D7AC4: c027bfe4                 clr     [%fp+var_1C]
F00D7AC8: b72ee018                 sll     %i3, 24, %i3
F00D7ACC: 80a6e000                 cmp     %i3, 0
F00D7AD0: 0280000e                 be      loc_F00D7B08
F00D7AD4: a6102000                 mov     0, %l3
F00D7AD8: 113c0505                 sethi   %hi(paSamplerate_0), %o0! id
F00D7ADC: d20221cc                 ld      [%o0+%lo(paSamplerate_0)], %o1! SEL
F00D7AE0: 40006764                 call    _objc_msgSend
F00D7AE4: 90100018                 mov     %i0, %o0
F00D7AE8: d027bfec                 st      %o0, [%fp+var_14]
F00D7AEC: 90100018                 mov     %i0, %o0! id
F00D7AF0: d4062148                 ld      [%i0+0x148], %o2
F00D7AF4: 133c0505                 sethi   %hi(paChannelcount_0), %o1
F00D7AF8: d20261c8                 ld      [%o1+%lo(paChannelcount_0)], %o1! SEL
F00D7AFC: 4000675d                 call    _objc_msgSend
F00D7B00: d427bfe8                 st      %o2, [%fp+var_18]
F00D7B04: d027bfe4                 st      %o0, [%fp+var_1C]
F00D7B08: a0102000                 mov     0, %l0
F00D7B0C: 253c0505                 sethi   -0xFEBEC00, %l2
F00D7B10: 233c0505                 sethi   -0xFEBEC00, %l1
F00D7B14: d204a1c4                 ld      [%l2+0x1C4], %o1! SEL
F00D7B18: 40006756                 call    _objc_msgSend
F00D7B1C: 9010001a                 mov     %i2, %o0
F00D7B20: 91322001                 srl     %o0, 1, %o0
F00D7B24: 80a40008                 cmp     %l0, %o0
F00D7B28: 1a80000b                 bcc     loc_F00D7B54
F00D7B2C: 9010001a                 mov     %i2, %o0! id
F00D7B30: d20461c0                 ld      [%l1+0x1C0], %o1! SEL
F00D7B34: 9407bfec                 add     %fp, var_14, %o2
F00D7B38: 9607bfe8                 add     %fp, var_18, %o3
F00D7B3C: 4000674d                 call    _objc_msgSend
F00D7B40: 9807bfe4                 add     %fp, var_1C, %o4
F00D7B44: 912a2018                 sll     %o0, 24, %o0! id
F00D7B48: 80a22000                 cmp     %o0, 0
F00D7B4C: 12bffff2                 bne     loc_F00D7B14
F00D7B50: a0042001                 inc     %l0
F00D7B54: 293c0505                 sethi   %hi(paEnqueuecount), %l4
F00D7B58: d20521bc                 ld      [%l4+%lo(paEnqueuecount)], %o1! SEL
F00D7B5C: 40006745                 call    _objc_msgSend
F00D7B60: 9010001a                 mov     %i2, %o0
F00D7B64: 80a22000                 cmp     %o0, 0
F00D7B68: 02800080                 be      loc_F00D7D68
F00D7B6C: 113c0505                 sethi   %hi(paSetsamplerate), %o0! id
F00D7B70: d20221b8                 ld      [%o0+%lo(paSetsamplerate)], %o1! SEL
F00D7B74: d407bfec                 ld      [%fp+var_14], %o2
F00D7B78: 4000673e                 call    _objc_msgSend
F00D7B7C: 90100018                 mov     %i0, %o0
F00D7B80: 113c0505                 sethi   %hi(paSetdataencodin), %o0! id
F00D7B84: d20221b4                 ld      [%o0+%lo(paSetdataencodin)], %o1! SEL
F00D7B88: d407bfe8                 ld      [%fp+var_18], %o2
F00D7B8C: 40006739                 call    _objc_msgSend
F00D7B90: 90100018                 mov     %i0, %o0
F00D7B94: 113c0505                 sethi   %hi(paSetchannelcoun), %o0! id
F00D7B98: d20221b0                 ld      [%o0+%lo(paSetchannelcoun)], %o1! SEL
F00D7B9C: d407bfe4                 ld      [%fp+var_1C], %o2
F00D7BA0: 40006734                 call    _objc_msgSend
F00D7BA4: 90100018                 mov     %i0, %o0
F00D7BA8: 113c0505                 sethi   %hi(paChannelbuffer), %o0! id
F00D7BAC: d20221ac                 ld      [%o0+%lo(paChannelbuffer)], %o1! SEL
F00D7BB0: 40006730                 call    _objc_msgSend
F00D7BB4: 9010001a                 mov     %i2, %o0
F00D7BB8: a6100008                 mov     %o0, %l3
F00D7BBC: 113c0505                 sethi   %hi(paStartdmaforcha), %o0! id
F00D7BC0: e40221a0                 ld      [%o0+%lo(paStartdmaforcha)], %l2
F00D7BC4: 133c0505                 sethi   %hi(paLocalchannel), %o1
F00D7BC8: d20261a8                 ld      [%o1+%lo(paLocalchannel)], %o1! SEL
F00D7BCC: 40006729                 call    _objc_msgSend
F00D7BD0: 9010001a                 mov     %i2, %o0
F00D7BD4: a2100008                 mov     %o0, %l1
F00D7BD8: 113c0505                 sethi   %hi(paIsread), %o0
F00D7BDC: f6022214                 ld      [%o0+%lo(paIsread)], %i3
F00D7BE0: 9010001a                 mov     %i2, %o0! id
F00D7BE4: 40006723                 call    _objc_msgSend
F00D7BE8: 9210001b                 mov     %i3, %o1
F00D7BEC: a12a2018                 sll     %o0, 24, %l0
F00D7BF0: 9010001a                 mov     %i2, %o0! id
F00D7BF4: 133c0505                 sethi   %hi(paDescriptorsize), %o1
F00D7BF8: d20261a4                 ld      [%o1+%lo(paDescriptorsize)], %o1! SEL
F00D7BFC: 4000671d                 call    _objc_msgSend
F00D7C00: a13c2018                 sra     %l0, 24, %l0
F00D7C04: 9a100008                 mov     %o0, %o5
F00D7C08: 90100018                 mov     %i0, %o0! id
F00D7C0C: 92100012                 mov     %l2, %o1! SEL
F00D7C10: 94100011                 mov     %l1, %o2
F00D7C14: 96100010                 mov     %l0, %o3
F00D7C18: 40006716                 call    _objc_msgSend
F00D7C1C: 98100013                 mov     %l3, %o4
F00D7C20: a6100008                 mov     %o0, %l3
F00D7C24: 912ce018                 sll     %l3, 24, %o0
F00D7C28: 80a22000                 cmp     %o0, 0
F00D7C2C: 22800029                 be,a    loc_F00D7CD0
F00D7C30: a2100014                 mov     %l4, %l1
F00D7C34: 7fffb92a                 call    _IOGetTimestamp
F00D7C38: 9007bfd8                 add     %fp, var_28, %o0
F00D7C3C: 113c0505                 sethi   %hi(paSetoutputstart), %o0! id
F00D7C40: d202219c                 ld      [%o0+%lo(paSetoutputstart)], %o1! SEL
F00D7C44: d41fbfd8                 ldd     [%fp+var_28], %o2
F00D7C48: 4000670a                 call    _objc_msgSend
F00D7C4C: 90100018                 mov     %i0, %o0
F00D7C50: 9010001a                 mov     %i2, %o0! id
F00D7C54: 40006707                 call    _objc_msgSend
F00D7C58: 9210001b                 mov     %i3, %o1
F00D7C5C: 912a2018                 sll     %o0, 24, %o0
F00D7C60: 80a22000                 cmp     %o0, 0
F00D7C64: 02800005                 be      loc_F00D7C78
F00D7C68: 133c0505                 sethi   %hi(paSetinputactive), %o1
F00D7C6C: 90100018                 mov     %i0, %o0
F00D7C70: 10800005                 ba      loc_F00D7C84
F00D7C74: d2026198                 ld      [%o1+%lo(paSetinputactive)], %o1
F00D7C78: 90100018                 mov     %i0, %o0! id
F00D7C7C: 133c0505                 sethi   %hi(paSetoutputactiv), %o1
F00D7C80: d2026194                 ld      [%o1+%lo(paSetoutputactiv)], %o1! SEL
F00D7C84: 400066fb                 call    _objc_msgSend
F00D7C88: 94102001                 mov     1, %o2
F00D7C8C: 113c0505                 sethi   %hi(paTimeout), %o0! id
F00D7C90: d2022190                 ld      [%o0+%lo(paTimeout)], %o1! SEL
F00D7C94: 400066f7                 call    _objc_msgSend
F00D7C98: 90100018                 mov     %i0, %o0
F00D7C9C: 80a23fff                 cmp     %o0, -1
F00D7CA0: 32800033                 bne,a   loc_F00D7D6C
F00D7CA4: b12ce018                 sll     %l3, 24, %i0
F00D7CA8: 113c0505                 sethi   %hi(paDescriptorsize), %o0
F00D7CAC: d20221a4                 ld      [%o0+%lo(paDescriptorsize)], %o1! SEL
F00D7CB0: 113c0505                 sethi   %hi(paSettimeout), %o0! id
F00D7CB4: e002218c                 ld      [%o0+%lo(paSettimeout)], %l0
F00D7CB8: 400066ee                 call    _objc_msgSend
F00D7CBC: 9010001a                 mov     %i2, %o0
F00D7CC0: 94100008                 mov     %o0, %o2
F00D7CC4: 90100018                 mov     %i0, %o0! id
F00D7CC8: 10800026                 ba      loc_F00D7D60
F00D7CCC: 92100010                 mov     %l0, %o1
F00D7CD0: 213c0505                 sethi   -0xFEBEC00, %l0
F00D7CD4: d20461bc                 ld      [%l1+0x1BC], %o1! SEL
F00D7CD8: 400066e6                 call    _objc_msgSend
F00D7CDC: 9010001a                 mov     %i2, %o0! id
F00D7CE0: 80a22000                 cmp     %o0, 0
F00D7CE4: 02800006                 be      loc_F00D7CFC
F00D7CE8: d2042188                 ld      [%l0+0x188], %o1! SEL
F00D7CEC: 400066e1                 call    _objc_msgSend
F00D7CF0: 9010001a                 mov     %i2, %o0
F00D7CF4: 10bffff9                 ba      loc_F00D7CD8
F00D7CF8: d20461bc                 ld      [%l1+0x1BC], %o1
F00D7CFC: 113c0505                 sethi   %hi(paLocalchannel), %o0
F00D7D00: d20221a8                 ld      [%o0+%lo(paLocalchannel)], %o1! SEL
F00D7D04: 113c0505                 sethi   %hi(paStopdmaforchan), %o0! id
F00D7D08: e2022184                 ld      [%o0+%lo(paStopdmaforchan)], %l1
F00D7D0C: 400066d9                 call    _objc_msgSend
F00D7D10: 9010001a                 mov     %i2, %o0! id
F00D7D14: 133c0505                 sethi   %hi(paIsread), %o1
F00D7D18: a0100008                 mov     %o0, %l0
F00D7D1C: d2026214                 ld      [%o1+%lo(paIsread)], %o1! SEL
F00D7D20: 400066d4                 call    _objc_msgSend
F00D7D24: 9010001a                 mov     %i2, %o0
F00D7D28: 972a2018                 sll     %o0, 24, %o3
F00D7D2C: 90100018                 mov     %i0, %o0! id
F00D7D30: 92100011                 mov     %l1, %o1! SEL
F00D7D34: 94100010                 mov     %l0, %o2
F00D7D38: 400066ce                 call    _objc_msgSend
F00D7D3C: 973ae018                 sra     %o3, 24, %o3
F00D7D40: 113c0505                 sethi   %hi(paFreedescriptor), %o0! id
F00D7D44: d2022180                 ld      [%o0+%lo(paFreedescriptor)], %o1! SEL
F00D7D48: 400066ca                 call    _objc_msgSend
F00D7D4C: 9010001a                 mov     %i2, %o0
F00D7D50: 90100018                 mov     %i0, %o0! id
F00D7D54: 133c0505                 sethi   %hi(paSettimeout), %o1
F00D7D58: d202618c                 ld      [%o1+%lo(paSettimeout)], %o1! SEL
F00D7D5C: 94103fff                 mov     -1, %o2
F00D7D60: 400066c4                 call    _objc_msgSend
F00D7D64: 01000000                 nop
F00D7D68: b12ce018                 sll     %l3, 24, %i0
F00D7D6C: b13e2018                 sra     %i0, 24, %i0
F00D7D70: 81c7e008                 ret
F00D7D74: 81e80000                 restore
