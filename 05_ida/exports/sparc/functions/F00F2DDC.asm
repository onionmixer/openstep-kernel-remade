F00F2DDC: 9de3bf90                 save    %sp, -0x70, %sp
F00F2DE0: ec062004                 ld      [%i0+4], %l6
F00F2DE4: 90100018                 mov     %i0, %o0
F00F2DE8: 133c03f4921260c8         set     aObjc, %o1! "__OBJC"
F00F2DF0: 153c03f49412a1e8         set     aMessageRefs, %o2! "__message_refs"
F00F2DF8: 7ffffb7b                 call    _getsectdatafromheaderinfo
F00F2DFC: 9607bff4                 add     %fp, var_C, %o3
F00F2E00: a4920000                 orcc    %o0, %g0, %l2
F00F2E04: 02800013                 be      loc_F00F2E50
F00F2E08: d007bff4                 ld      [%fp+var_C], %o0
F00F2E0C: a7322002                 srl     %o0, 2, %l3
F00F2E10: a2102000                 mov     0, %l1
F00F2E14: 80a44013                 cmp     %l1, %l3
F00F2E18: 1a80009f                 bcc     loc_F00F3094
F00F2E1C: aa102000                 mov     0, %l5
F00F2E20: a12c6002                 sll     %l1, 2, %l0
F00F2E24: 40000230                 call    __sel_registerName
F00F2E28: d0048010                 ld      [%l2+%l0], %o0
F00F2E2C: 92100008                 mov     %o0, %o1
F00F2E30: d0048010                 ld      [%l2+%l0], %o0
F00F2E34: 80a20009                 cmp     %o0, %o1
F00F2E38: 32800002                 bne,a   loc_F00F2E40
F00F2E3C: d2248010                 st      %o1, [%l2+%l0]
F00F2E40: a2046001                 inc     %l1
F00F2E44: 80a44013                 cmp     %l1, %l3
F00F2E48: 2abffff7                 bcs,a   loc_F00F2E24
F00F2E4C: a12c6002                 sll     %l1, 2, %l0
F00F2E50: 10800091                 ba      loc_F00F3094
F00F2E54: aa102000                 mov     0, %l5
F00F2E58: 92100008                 mov     %o0, %o1
F00F2E5C: 90058008                 add     %l6, %o0, %o0
F00F2E60: d002200c                 ld      [%o0+0xC], %o0
F00F2E64: 80a22000                 cmp     %o0, 0
F00F2E68: 2280008b                 be,a    loc_F00F3094
F00F2E6C: aa056001                 inc     %l5
F00F2E70: 1080003f                 ba      loc_F00F2F6C
F00F2E74: a6102000                 mov     0, %l3
F00F2E78: d202200c                 ld      [%o0+0xC], %o1
F00F2E7C: 912ce002                 sll     %l3, 2, %o0
F00F2E80: 90020009                 add     %o0, %o1, %o0
F00F2E84: e802200c                 ld      [%o0+0xC], %l4
F00F2E88: d005201c                 ld      [%l4+0x1C], %o0
F00F2E8C: 80a22000                 cmp     %o0, 0
F00F2E90: 22800019                 be,a    loc_F00F2EF4
F00F2E94: d0050000                 ld      [%l4], %o0
F00F2E98: a0100008                 mov     %o0, %l0
F00F2E9C: d0040000                 ld      [%l0], %o0
F00F2EA0: 80a22000                 cmp     %o0, 0
F00F2EA4: 32bffffe                 bne,a   loc_F00F2E9C
F00F2EA8: e0040000                 ld      [%l0], %l0
F00F2EAC: 1080000d                 ba      loc_F00F2EE0
F00F2EB0: a4102000                 mov     0, %l2
F00F2EB4: 90020012                 add     %o0, %l2, %o0
F00F2EB8: 912a2002                 sll     %o0, 2, %o0
F00F2EBC: a2022008                 add     %o0, 8, %l1
F00F2EC0: 40000209                 call    __sel_registerName
F00F2EC4: d0040011                 ld      [%l0+%l1], %o0
F00F2EC8: 92100008                 mov     %o0, %o1
F00F2ECC: d0040011                 ld      [%l0+%l1], %o0
F00F2ED0: 80a20009                 cmp     %o0, %o1
F00F2ED4: 32800002                 bne,a   loc_F00F2EDC
F00F2ED8: d2240011                 st      %o1, [%l0+%l1]
F00F2EDC: a404a001                 inc     %l2
F00F2EE0: d0042004                 ld      [%l0+4], %o0
F00F2EE4: 80a48008                 cmp     %l2, %o0
F00F2EE8: 0abffff3                 bcs     loc_F00F2EB4
F00F2EEC: 912ca001                 sll     %l2, 1, %o0
F00F2EF0: d0050000                 ld      [%l4], %o0
F00F2EF4: d002201c                 ld      [%o0+0x1C], %o0
F00F2EF8: 80a22000                 cmp     %o0, 0
F00F2EFC: 22800019                 be,a    loc_F00F2F60
F00F2F00: a604e001                 inc     %l3
F00F2F04: a0100008                 mov     %o0, %l0
F00F2F08: d0040000                 ld      [%l0], %o0
F00F2F0C: 80a22000                 cmp     %o0, 0
F00F2F10: 32bffffe                 bne,a   loc_F00F2F08
F00F2F14: e0040000                 ld      [%l0], %l0
F00F2F18: 1080000d                 ba      loc_F00F2F4C
F00F2F1C: a4102000                 mov     0, %l2
F00F2F20: 90020012                 add     %o0, %l2, %o0
F00F2F24: 912a2002                 sll     %o0, 2, %o0
F00F2F28: a2022008                 add     %o0, 8, %l1
F00F2F2C: 400001ee                 call    __sel_registerName
F00F2F30: d0040011                 ld      [%l0+%l1], %o0
F00F2F34: 92100008                 mov     %o0, %o1
F00F2F38: d0040011                 ld      [%l0+%l1], %o0
F00F2F3C: 80a20009                 cmp     %o0, %o1
F00F2F40: 32800002                 bne,a   loc_F00F2F48
F00F2F44: d2240011                 st      %o1, [%l0+%l1]
F00F2F48: a404a001                 inc     %l2
F00F2F4C: d0042004                 ld      [%l0+4], %o0
F00F2F50: 80a48008                 cmp     %l2, %o0
F00F2F54: 0abffff3                 bcs     loc_F00F2F20
F00F2F58: 912ca001                 sll     %l2, 1, %o0
F00F2F5C: a604e001                 inc     %l3
F00F2F60: 932d6004                 sll     %l5, 4, %o1
F00F2F64: 90058009                 add     %l6, %o1, %o0
F00F2F68: d002200c                 ld      [%o0+0xC], %o0
F00F2F6C: d0122008                 lduh    [%o0+8], %o0
F00F2F70: 80a4c008                 cmp     %l3, %o0
F00F2F74: 0abfffc1                 bcs     loc_F00F2E78
F00F2F78: 90058009                 add     %l6, %o1, %o0
F00F2F7C: 912d6004                 sll     %l5, 4, %o0
F00F2F80: 94100008                 mov     %o0, %o2
F00F2F84: 90058008                 add     %l6, %o0, %o0
F00F2F88: d002200c                 ld      [%o0+0xC], %o0
F00F2F8C: e6122008                 lduh    [%o0+8], %l3
F00F2F90: d012200a                 lduh    [%o0+0xA], %o0
F00F2F94: 9004c008                 add     %l3, %o0, %o0
F00F2F98: 80a4c008                 cmp     %l3, %o0
F00F2F9C: 3a80003e                 bcc,a   loc_F00F3094
F00F2FA0: aa056001                 inc     %l5
F00F2FA4: 9005800a                 add     %l6, %o2, %o0
F00F2FA8: d202200c                 ld      [%o0+0xC], %o1
F00F2FAC: 912ce002                 sll     %l3, 2, %o0
F00F2FB0: 90020009                 add     %o0, %o1, %o0
F00F2FB4: e802200c                 ld      [%o0+0xC], %l4
F00F2FB8: d0052008                 ld      [%l4+8], %o0
F00F2FBC: 80a22000                 cmp     %o0, 0
F00F2FC0: 22800015                 be,a    loc_F00F3014
F00F2FC4: d005200c                 ld      [%l4+0xC], %o0
F00F2FC8: a4100008                 mov     %o0, %l2
F00F2FCC: 1080000d                 ba      loc_F00F3000
F00F2FD0: a2102000                 mov     0, %l1
F00F2FD4: 90020011                 add     %o0, %l1, %o0
F00F2FD8: 912a2002                 sll     %o0, 2, %o0
F00F2FDC: a0022008                 add     %o0, 8, %l0
F00F2FE0: 400001c1                 call    __sel_registerName
F00F2FE4: d0048010                 ld      [%l2+%l0], %o0
F00F2FE8: 92100008                 mov     %o0, %o1
F00F2FEC: d0048010                 ld      [%l2+%l0], %o0
F00F2FF0: 80a20009                 cmp     %o0, %o1
F00F2FF4: 32800002                 bne,a   loc_F00F2FFC
F00F2FF8: d2248010                 st      %o1, [%l2+%l0]
F00F2FFC: a2046001                 inc     %l1
F00F3000: d004a004                 ld      [%l2+4], %o0
F00F3004: 80a44008                 cmp     %l1, %o0
F00F3008: 0abffff3                 bcs     loc_F00F2FD4
F00F300C: 912c6001                 sll     %l1, 1, %o0
F00F3010: d005200c                 ld      [%l4+0xC], %o0
F00F3014: 80a22000                 cmp     %o0, 0
F00F3018: 22800015                 be,a    loc_F00F306C
F00F301C: a604e001                 inc     %l3
F00F3020: a4100008                 mov     %o0, %l2
F00F3024: 1080000d                 ba      loc_F00F3058
F00F3028: a2102000                 mov     0, %l1
F00F302C: 90020011                 add     %o0, %l1, %o0
F00F3030: 912a2002                 sll     %o0, 2, %o0
F00F3034: a0022008                 add     %o0, 8, %l0
F00F3038: 400001ab                 call    __sel_registerName
F00F303C: d0048010                 ld      [%l2+%l0], %o0
F00F3040: 92100008                 mov     %o0, %o1
F00F3044: d0048010                 ld      [%l2+%l0], %o0
F00F3048: 80a20009                 cmp     %o0, %o1
F00F304C: 32800002                 bne,a   loc_F00F3054
F00F3050: d2248010                 st      %o1, [%l2+%l0]
F00F3054: a2046001                 inc     %l1
F00F3058: d004a004                 ld      [%l2+4], %o0
F00F305C: 80a44008                 cmp     %l1, %o0
F00F3060: 0abffff3                 bcs     loc_F00F302C
F00F3064: 912c6001                 sll     %l1, 1, %o0
F00F3068: a604e001                 inc     %l3
F00F306C: 952d6004                 sll     %l5, 4, %o2
F00F3070: 9005800a                 add     %l6, %o2, %o0
F00F3074: d002200c                 ld      [%o0+0xC], %o0
F00F3078: d2122008                 lduh    [%o0+8], %o1
F00F307C: d012200a                 lduh    [%o0+0xA], %o0
F00F3080: 92024008                 add     %o1, %o0, %o1
F00F3084: 80a4c009                 cmp     %l3, %o1
F00F3088: 0abfffc8                 bcs     loc_F00F2FA8
F00F308C: 9005800a                 add     %l6, %o2, %o0
F00F3090: aa056001                 inc     %l5
F00F3094: d0062008                 ld      [%i0+8], %o0
F00F3098: 80a54008                 cmp     %l5, %o0
F00F309C: 0abfff6f                 bcs     loc_F00F2E58
F00F30A0: 912d6004                 sll     %l5, 4, %o0
F00F30A4: 90100018                 mov     %i0, %o0
F00F30A8: 133c03f4921260c8         set     aObjc, %o1! "__OBJC"
F00F30B0: 153c03f49412a1f8         set     aProtocol, %o2! "__protocol"
F00F30B8: 7ffffacb                 call    _getsectdatafromheaderinfo
F00F30BC: 9607bff4                 add     %fp, var_C, %o3
F00F30C0: a8920000                 orcc    %o0, %g0, %l4
F00F30C4: 02800039                 be      locret_F00F31A8
F00F30C8: a6102000                 mov     0, %l3
F00F30CC: d007bff4                 ld      [%fp+var_C], %o0
F00F30D0: 7ffc4d4c                 call    _udiv
F00F30D4: 92102014                 mov     0x14, %o1
F00F30D8: 80a4c008                 cmp     %l3, %o0
F00F30DC: 1a800033                 bcc     locret_F00F31A8
F00F30E0: 912ce002                 sll     %l3, 2, %o0
F00F30E4: 90020013                 add     %o0, %l3, %o0
F00F30E8: 912a2002                 sll     %o0, 2, %o0
F00F30EC: 90050008                 add     %l4, %o0, %o0
F00F30F0: d002200c                 ld      [%o0+0xC], %o0
F00F30F4: 80a22000                 cmp     %o0, 0
F00F30F8: 22800013                 be,a    loc_F00F3144
F00F30FC: 912ce002                 sll     %l3, 2, %o0
F00F3100: a2100008                 mov     %o0, %l1
F00F3104: 1080000b                 ba      loc_F00F3130
F00F3108: a4102000                 mov     0, %l2
F00F310C: a0022004                 add     %o0, 4, %l0
F00F3110: 40000175                 call    __sel_registerName
F00F3114: d0044010                 ld      [%l1+%l0], %o0
F00F3118: 92100008                 mov     %o0, %o1
F00F311C: d0044010                 ld      [%l1+%l0], %o0
F00F3120: 80a20009                 cmp     %o0, %o1
F00F3124: 32800002                 bne,a   loc_F00F312C
F00F3128: d2244010                 st      %o1, [%l1+%l0]
F00F312C: a404a001                 inc     %l2
F00F3130: d0044000                 ld      [%l1], %o0
F00F3134: 80a48008                 cmp     %l2, %o0
F00F3138: 0abffff5                 bcs     loc_F00F310C
F00F313C: 912ca003                 sll     %l2, 3, %o0
F00F3140: 912ce002                 sll     %l3, 2, %o0
F00F3144: 90020013                 add     %o0, %l3, %o0
F00F3148: 912a2002                 sll     %o0, 2, %o0
F00F314C: 90050008                 add     %l4, %o0, %o0
F00F3150: d0022010                 ld      [%o0+0x10], %o0
F00F3154: 80a22000                 cmp     %o0, 0
F00F3158: 22bfffdd                 be,a    loc_F00F30CC
F00F315C: a604e001                 inc     %l3
F00F3160: a2100008                 mov     %o0, %l1
F00F3164: 1080000b                 ba      loc_F00F3190
F00F3168: a4102000                 mov     0, %l2
F00F316C: a0022004                 add     %o0, 4, %l0
F00F3170: 4000015d                 call    __sel_registerName
F00F3174: d0044010                 ld      [%l1+%l0], %o0
F00F3178: 92100008                 mov     %o0, %o1
F00F317C: d0044010                 ld      [%l1+%l0], %o0
F00F3180: 80a20009                 cmp     %o0, %o1
F00F3184: 32800002                 bne,a   loc_F00F318C
F00F3188: d2244010                 st      %o1, [%l1+%l0]
F00F318C: a404a001                 inc     %l2
F00F3190: d0044000                 ld      [%l1], %o0
F00F3194: 80a48008                 cmp     %l2, %o0
F00F3198: 0abffff5                 bcs     loc_F00F316C
F00F319C: 912ca003                 sll     %l2, 3, %o0
F00F31A0: 10bfffcb                 ba      loc_F00F30CC
F00F31A4: a604e001                 inc     %l3
F00F31A8: 81c7e008                 ret
F00F31AC: 81e80000                 restore
