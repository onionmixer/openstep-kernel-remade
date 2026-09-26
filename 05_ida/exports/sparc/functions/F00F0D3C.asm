F00F0D3C: 9de3bf90                 save    %sp, -0x70, %sp
F00F0D40: a0102000                 mov     0, %l0
F00F0D44: 90100018                 mov     %i0, %o0! mhp
F00F0D48: 133c03f4921260c8         set     aObjc, %o1! "__OBJC"
F00F0D50: 153c03f49412a1d8         set     aModuleInfo, %o2! "__module_info"
F00F0D58: 7ffde4b7                 call    _getsectdatafromheader
F00F0D5C: 9607bff4                 add     %fp, var_C, %o3! size
F00F0D60: aa100008                 mov     %o0, %l5
F00F0D64: ac100015                 mov     %l5, %l6
F00F0D68: d007bff4                 ld      [%fp+var_C], %o0
F00F0D6C: 80a56000                 cmp     %l5, 0
F00F0D70: 02800022                 be      loc_F00F0DF8
F00F0D74: d027bff0                 st      %o0, [%fp+var_10]
F00F0D78: d007bff0                 ld      [%fp+var_10], %o0
F00F0D7C: 80a22000                 cmp     %o0, 0
F00F0D80: 0280001f                 be      loc_F00F0DFC
F00F0D84: 80a42000                 cmp     %l0, 0
F00F0D88: a8102000                 mov     0, %l4
F00F0D8C: d005600c                 ld      [%l5+0xC], %o0
F00F0D90: 92100008                 mov     %o0, %o1
F00F0D94: d0122008                 lduh    [%o0+8], %o0
F00F0D98: 80a50008                 cmp     %l4, %o0
F00F0D9C: 36800010                 bge,a   loc_F00F0DDC
F00F0DA0: d0056004                 ld      [%l5+4], %o0
F00F0DA4: 912d2002                 sll     %l4, 2, %o0
F00F0DA8: 90020009                 add     %o0, %o1, %o0! name
F00F0DAC: 400003ec                 call    _objc_lookUpClass
F00F0DB0: d002200c                 ld      [%o0+0xC], %o0
F00F0DB4: 80a22000                 cmp     %o0, 0
F00F0DB8: 32800002                 bne,a   loc_F00F0DC0
F00F0DBC: a0102001                 mov     1, %l0
F00F0DC0: a8052001                 inc     %l4
F00F0DC4: d205600c                 ld      [%l5+0xC], %o1
F00F0DC8: d0126008                 lduh    [%o1+8], %o0
F00F0DCC: 80a50008                 cmp     %l4, %o0
F00F0DD0: 06bffff6                 bl      loc_F00F0DA8
F00F0DD4: 912d2002                 sll     %l4, 2, %o0
F00F0DD8: d0056004                 ld      [%l5+4], %o0
F00F0DDC: d207bff0                 ld      [%fp+var_10], %o1
F00F0DE0: 92224008                 sub     %o1, %o0, %o1
F00F0DE4: d227bff0                 st      %o1, [%fp+var_10]
F00F0DE8: d0056004                 ld      [%l5+4], %o0
F00F0DEC: aa854008                 addcc   %l5, %o0, %l5
F00F0DF0: 12bfffe3                 bne     loc_F00F0D7C
F00F0DF4: d007bff0                 ld      [%fp+var_10], %o0
F00F0DF8: 80a42000                 cmp     %l0, 0
F00F0DFC: 02800004                 be      loc_F00F0E0C
F00F0E00: 90100018                 mov     %i0, %o0
F00F0E04: 108001f1                 ba      locret_F00F15C8
F00F0E08: b0102001                 mov     1, %i0
F00F0E0C: 40000755                 call    __objc_addHeader
F00F0E10: 92102000                 mov     0, %o1
F00F0E14: 7fffffab                 call    sub_F00F0CC0
F00F0E18: 90100018                 mov     %i0, %o0
F00F0E1C: 90100018                 mov     %i0, %o0! mhp
F00F0E20: 133c03f4921260c8         set     aObjc, %o1! "__OBJC"
F00F0E28: 153c03f49412a1e8         set     aMessageRefs, %o2! "__message_refs"
F00F0E30: 7ffde481                 call    _getsectdatafromheader
F00F0E34: 9607bff0                 add     %fp, var_10, %o3! size
F00F0E38: a4920000                 orcc    %o0, %g0, %l2
F00F0E3C: 02800013                 be      loc_F00F0E88
F00F0E40: d007bff0                 ld      [%fp+var_10], %o0
F00F0E44: a7322002                 srl     %o0, 2, %l3
F00F0E48: a2102000                 mov     0, %l1
F00F0E4C: 80a44013                 cmp     %l1, %l3
F00F0E50: 1a80000f                 bcc     loc_F00F0E8C
F00F0E54: 90100018                 mov     %i0, %o0! str
F00F0E58: a12c6002                 sll     %l1, 2, %l0
F00F0E5C: 40000aa5                 call    _sel_registerName
F00F0E60: d0048010                 ld      [%l2+%l0], %o0
F00F0E64: 92100008                 mov     %o0, %o1
F00F0E68: d0048010                 ld      [%l2+%l0], %o0
F00F0E6C: 80a20009                 cmp     %o0, %o1
F00F0E70: 32800002                 bne,a   loc_F00F0E78
F00F0E74: d2248010                 st      %o1, [%l2+%l0]
F00F0E78: a2046001                 inc     %l1
F00F0E7C: 80a44013                 cmp     %l1, %l3
F00F0E80: 2abffff7                 bcs,a   loc_F00F0E5C
F00F0E84: a12c6002                 sll     %l1, 2, %l0
F00F0E88: 90100018                 mov     %i0, %o0! mhp
F00F0E8C: 133c03f4921260c8         set     aObjc, %o1! "__OBJC"
F00F0E94: 153c03f49412a1f8         set     aProtocol, %o2! "__protocol"
F00F0E9C: 7ffde466                 call    _getsectdatafromheader
F00F0EA0: 9607bff0                 add     %fp, var_10, %o3
F00F0EA4: a8920000                 orcc    %o0, %g0, %l4
F00F0EA8: 02800043                 be      loc_F00F0FB4
F00F0EAC: a6102000                 mov     0, %l3
F00F0EB0: d007bff0                 ld      [%fp+var_10], %o0
F00F0EB4: 7ffc55d3                 call    _udiv
F00F0EB8: 92102014                 mov     0x14, %o1
F00F0EBC: 80a4c008                 cmp     %l3, %o0
F00F0EC0: 1a800033                 bcc     loc_F00F0F8C
F00F0EC4: 912ce002                 sll     %l3, 2, %o0
F00F0EC8: 90020013                 add     %o0, %l3, %o0
F00F0ECC: 912a2002                 sll     %o0, 2, %o0
F00F0ED0: 90050008                 add     %l4, %o0, %o0
F00F0ED4: d002200c                 ld      [%o0+0xC], %o0
F00F0ED8: 80a22000                 cmp     %o0, 0
F00F0EDC: 22800013                 be,a    loc_F00F0F28
F00F0EE0: 912ce002                 sll     %l3, 2, %o0! str
F00F0EE4: a2100008                 mov     %o0, %l1
F00F0EE8: 1080000b                 ba      loc_F00F0F14
F00F0EEC: a4102000                 mov     0, %l2
F00F0EF0: a0022004                 add     %o0, 4, %l0
F00F0EF4: 40000a7f                 call    _sel_registerName
F00F0EF8: d0044010                 ld      [%l1+%l0], %o0
F00F0EFC: 92100008                 mov     %o0, %o1
F00F0F00: d0044010                 ld      [%l1+%l0], %o0
F00F0F04: 80a20009                 cmp     %o0, %o1
F00F0F08: 32800002                 bne,a   loc_F00F0F10
F00F0F0C: d2244010                 st      %o1, [%l1+%l0]
F00F0F10: a404a001                 inc     %l2
F00F0F14: d0044000                 ld      [%l1], %o0
F00F0F18: 80a48008                 cmp     %l2, %o0
F00F0F1C: 0abffff5                 bcs     loc_F00F0EF0
F00F0F20: 912ca003                 sll     %l2, 3, %o0
F00F0F24: 912ce002                 sll     %l3, 2, %o0
F00F0F28: 90020013                 add     %o0, %l3, %o0
F00F0F2C: 912a2002                 sll     %o0, 2, %o0
F00F0F30: 90050008                 add     %l4, %o0, %o0
F00F0F34: d0022010                 ld      [%o0+0x10], %o0! str
F00F0F38: 80a22000                 cmp     %o0, 0
F00F0F3C: 22bfffdd                 be,a    loc_F00F0EB0
F00F0F40: a604e001                 inc     %l3
F00F0F44: a2100008                 mov     %o0, %l1
F00F0F48: 1080000b                 ba      loc_F00F0F74
F00F0F4C: a4102000                 mov     0, %l2
F00F0F50: a0022004                 add     %o0, 4, %l0
F00F0F54: 40000a67                 call    _sel_registerName
F00F0F58: d0044010                 ld      [%l1+%l0], %o0
F00F0F5C: 92100008                 mov     %o0, %o1
F00F0F60: d0044010                 ld      [%l1+%l0], %o0
F00F0F64: 80a20009                 cmp     %o0, %o1
F00F0F68: 32800002                 bne,a   loc_F00F0F70
F00F0F6C: d2244010                 st      %o1, [%l1+%l0]
F00F0F70: a404a001                 inc     %l2
F00F0F74: d0044000                 ld      [%l1], %o0
F00F0F78: 80a48008                 cmp     %l2, %o0
F00F0F7C: 0abffff5                 bcs     loc_F00F0F50
F00F0F80: 912ca003                 sll     %l2, 3, %o0
F00F0F84: 10bfffcb                 ba      loc_F00F0EB0
F00F0F88: a604e001                 inc     %l3
F00F0F8C: 213c0506                 sethi   %hi(paProtocol_0), %l0
F00F0F90: 233c0506                 sethi   %hi(paFixupNumelemen), %l1
F00F0F94: d007bff0                 ld      [%fp+var_10], %o0
F00F0F98: 7ffc559a                 call    _udiv
F00F0F9C: 92102014                 mov     0x14, %o1
F00F0FA0: 96100008                 mov     %o0, %o3! size
F00F0FA4: d00422f8                 ld      [%l0+%lo(paProtocol_0)], %o0! id
F00F0FA8: d20461fc                 ld      [%l1+%lo(paFixupNumelemen)], %o1! SEL
F00F0FAC: 40000231                 call    _objc_msgSend
F00F0FB0: 94100014                 mov     %l4, %o2
F00F0FB4: aa100016                 mov     %l6, %l5
F00F0FB8: d007bff4                 ld      [%fp+var_C], %o0
F00F0FBC: 80a56000                 cmp     %l5, 0
F00F0FC0: 02800020                 be      loc_F00F1040
F00F0FC4: d027bff0                 st      %o0, [%fp+var_10]
F00F0FC8: d007bff0                 ld      [%fp+var_10], %o0
F00F0FCC: 80a22000                 cmp     %o0, 0
F00F0FD0: 2280001c                 be,a    loc_F00F1040
F00F0FD4: aa100016                 mov     %l6, %l5
F00F0FD8: a8102000                 mov     0, %l4
F00F0FDC: d005600c                 ld      [%l5+0xC], %o0
F00F0FE0: 92100008                 mov     %o0, %o1
F00F0FE4: d0122008                 lduh    [%o0+8], %o0
F00F0FE8: 80a50008                 cmp     %l4, %o0
F00F0FEC: 3680000d                 bge,a   loc_F00F1020
F00F0FF0: d007bff0                 ld      [%fp+var_10], %o0
F00F0FF4: 912d2002                 sll     %l4, 2, %o0
F00F0FF8: 90020009                 add     %o0, %o1, %o0! myClass
F00F0FFC: 40000369                 call    _objc_addClass
F00F1000: d002200c                 ld      [%o0+0xC], %o0
F00F1004: a8052001                 inc     %l4
F00F1008: d205600c                 ld      [%l5+0xC], %o1
F00F100C: d0126008                 lduh    [%o1+8], %o0
F00F1010: 80a50008                 cmp     %l4, %o0
F00F1014: 06bffff9                 bl      loc_F00F0FF8
F00F1018: 912d2002                 sll     %l4, 2, %o0
F00F101C: d007bff0                 ld      [%fp+var_10], %o0
F00F1020: d2056004                 ld      [%l5+4], %o1
F00F1024: 90220009                 sub     %o0, %o1, %o0
F00F1028: d027bff0                 st      %o0, [%fp+var_10]
F00F102C: d0056004                 ld      [%l5+4], %o0
F00F1030: aa854008                 addcc   %l5, %o0, %l5
F00F1034: 12bfffe6                 bne     loc_F00F0FCC
F00F1038: d007bff0                 ld      [%fp+var_10], %o0
F00F103C: aa100016                 mov     %l6, %l5
F00F1040: d007bff4                 ld      [%fp+var_C], %o0
F00F1044: 80a56000                 cmp     %l5, 0
F00F1048: 0280006f                 be      loc_F00F1204
F00F104C: d027bff0                 st      %o0, [%fp+var_10]
F00F1050: d007bff0                 ld      [%fp+var_10], %o0
F00F1054: 80a22000                 cmp     %o0, 0
F00F1058: 2280006c                 be,a    loc_F00F1208
F00F105C: aa100016                 mov     %l6, %l5
F00F1060: a8102000                 mov     0, %l4
F00F1064: d005600c                 ld      [%l5+0xC], %o0
F00F1068: 92100008                 mov     %o0, %o1
F00F106C: d0122008                 lduh    [%o0+8], %o0
F00F1070: 80a50008                 cmp     %l4, %o0
F00F1074: 1680005d                 bge     loc_F00F11E8
F00F1078: d007bff0                 ld      [%fp+var_10], %o0
F00F107C: 912d2002                 sll     %l4, 2, %o0
F00F1080: 90020009                 add     %o0, %o1, %o0
F00F1084: e602200c                 ld      [%o0+0xC], %l3
F00F1088: d004e01c                 ld      [%l3+0x1C], %o0
F00F108C: 80a22000                 cmp     %o0, 0
F00F1090: 22800015                 be,a    loc_F00F10E4
F00F1094: d004c000                 ld      [%l3], %o0
F00F1098: a4100008                 mov     %o0, %l2
F00F109C: 1080000d                 ba      loc_F00F10D0
F00F10A0: a2102000                 mov     0, %l1
F00F10A4: 90020011                 add     %o0, %l1, %o0
F00F10A8: 912a2002                 sll     %o0, 2, %o0! str
F00F10AC: a0022008                 add     %o0, 8, %l0
F00F10B0: 40000a10                 call    _sel_registerName
F00F10B4: d0048010                 ld      [%l2+%l0], %o0
F00F10B8: 92100008                 mov     %o0, %o1
F00F10BC: d0048010                 ld      [%l2+%l0], %o0
F00F10C0: 80a20009                 cmp     %o0, %o1
F00F10C4: 32800002                 bne,a   loc_F00F10CC
F00F10C8: d2248010                 st      %o1, [%l2+%l0]
F00F10CC: a2046001                 inc     %l1
F00F10D0: d004a004                 ld      [%l2+4], %o0
F00F10D4: 80a44008                 cmp     %l1, %o0
F00F10D8: 0abffff3                 bcs     loc_F00F10A4
F00F10DC: 912c6001                 sll     %l1, 1, %o0
F00F10E0: d004c000                 ld      [%l3], %o0
F00F10E4: d002201c                 ld      [%o0+0x1C], %o0
F00F10E8: 80a22000                 cmp     %o0, 0
F00F10EC: 22800015                 be,a    loc_F00F1140
F00F10F0: 90100013                 mov     %l3, %o0
F00F10F4: a4100008                 mov     %o0, %l2
F00F10F8: 1080000d                 ba      loc_F00F112C
F00F10FC: a2102000                 mov     0, %l1
F00F1100: 90020011                 add     %o0, %l1, %o0
F00F1104: 912a2002                 sll     %o0, 2, %o0! str
F00F1108: a0022008                 add     %o0, 8, %l0
F00F110C: 400009f9                 call    _sel_registerName
F00F1110: d0048010                 ld      [%l2+%l0], %o0
F00F1114: 92100008                 mov     %o0, %o1
F00F1118: d0048010                 ld      [%l2+%l0], %o0
F00F111C: 80a20009                 cmp     %o0, %o1
F00F1120: 32800002                 bne,a   loc_F00F1128
F00F1124: d2248010                 st      %o1, [%l2+%l0]
F00F1128: a2046001                 inc     %l1
F00F112C: d004a004                 ld      [%l2+4], %o0
F00F1130: 80a44008                 cmp     %l1, %o0
F00F1134: 0abffff3                 bcs     loc_F00F1100
F00F1138: 912c6001                 sll     %l1, 1, %o0
F00F113C: 90100013                 mov     %l3, %o0
F00F1140: 7ffffa65                 call    __class_install_relationships
F00F1144: d2054000                 ld      [%l5], %o1
F00F1148: d004c000                 ld      [%l3], %o0
F00F114C: d002200c                 ld      [%o0+0xC], %o0
F00F1150: 90023ffd                 inc     -3, %o0
F00F1154: 80a22001                 cmp     %o0, 1
F00F1158: 3880000c                 bgu,a   loc_F00F1188
F00F115C: d004c000                 ld      [%l3], %o0
F00F1160: d004e024                 ld      [%l3+0x24], %o0
F00F1164: 80a22000                 cmp     %o0, 0
F00F1168: 02800007                 be      loc_F00F1184
F00F116C: 90023ffc                 inc     -4, %o0
F00F1170: d024e024                 st      %o0, [%l3+0x24]
F00F1174: d204c000                 ld      [%l3], %o1
F00F1178: d0026024                 ld      [%o1+0x24], %o0
F00F117C: 90023ffc                 inc     -4, %o0
F00F1180: d0226024                 st      %o0, [%o1+0x24]
F00F1184: d004c000                 ld      [%l3], %o0
F00F1188: d002200c                 ld      [%o0+0xC], %o0
F00F118C: 80a22003                 cmp     %o0, 3
F00F1190: 32800010                 bne,a   loc_F00F11D0
F00F1194: a8052001                 inc     %l4
F00F1198: d004e024                 ld      [%l3+0x24], %o0
F00F119C: 80a22000                 cmp     %o0, 0
F00F11A0: 0280000b                 be      loc_F00F11CC
F00F11A4: 113c03f3                 sethi   %hi(aUnableToInstal), %o0! "Unable to install protocols by name..."...
F00F11A8: 7ffffe22                 call    __objc_inform
F00F11AC: 901221a8                 bset    %lo(aUnableToInstal), %o0! "Unable to install protocols by name..."...
F00F11B0: 113c03f490122208         set     aClassSMustBeRe, %o0! "Class %s must be recompiled.\n"
F00F11B8: 7ffffe1e                 call    __objc_inform
F00F11BC: d204e008                 ld      [%l3+8], %o1
F00F11C0: c024e024                 clr     [%l3+0x24]
F00F11C4: d004c000                 ld      [%l3], %o0
F00F11C8: c0222024                 clr     [%o0+0x24]
F00F11CC: a8052001                 inc     %l4
F00F11D0: d205600c                 ld      [%l5+0xC], %o1
F00F11D4: d0126008                 lduh    [%o1+8], %o0
F00F11D8: 80a50008                 cmp     %l4, %o0
F00F11DC: 06bfffa9                 bl      loc_F00F1080
F00F11E0: 912d2002                 sll     %l4, 2, %o0
F00F11E4: d007bff0                 ld      [%fp+var_10], %o0
F00F11E8: d2056004                 ld      [%l5+4], %o1
F00F11EC: 90220009                 sub     %o0, %o1, %o0
F00F11F0: d027bff0                 st      %o0, [%fp+var_10]
F00F11F4: d0056004                 ld      [%l5+4], %o0
F00F11F8: aa854008                 addcc   %l5, %o0, %l5
F00F11FC: 12bfff96                 bne     loc_F00F1054
F00F1200: d007bff0                 ld      [%fp+var_10], %o0
F00F1204: aa100016                 mov     %l6, %l5
F00F1208: d007bff4                 ld      [%fp+var_C], %o0
F00F120C: 80a56000                 cmp     %l5, 0
F00F1210: 02800053                 be      loc_F00F135C
F00F1214: d027bff0                 st      %o0, [%fp+var_10]
F00F1218: d007bff0                 ld      [%fp+var_10], %o0
F00F121C: 80a22000                 cmp     %o0, 0
F00F1220: 22800050                 be,a    loc_F00F1360
F00F1224: aa100016                 mov     %l6, %l5
F00F1228: d005600c                 ld      [%l5+0xC], %o0
F00F122C: 94100008                 mov     %o0, %o2
F00F1230: e8122008                 lduh    [%o0+8], %l4
F00F1234: d012200a                 lduh    [%o0+0xA], %o0
F00F1238: 90050008                 add     %l4, %o0, %o0
F00F123C: 80a50008                 cmp     %l4, %o0
F00F1240: 16800040                 bge     loc_F00F1340
F00F1244: d007bff0                 ld      [%fp+var_10], %o0
F00F1248: 912d2002                 sll     %l4, 2, %o0
F00F124C: 9002000a                 add     %o0, %o2, %o0
F00F1250: e602200c                 ld      [%o0+0xC], %l3
F00F1254: d004e008                 ld      [%l3+8], %o0
F00F1258: 80a22000                 cmp     %o0, 0
F00F125C: 22800015                 be,a    loc_F00F12B0
F00F1260: d004e00c                 ld      [%l3+0xC], %o0
F00F1264: a4100008                 mov     %o0, %l2
F00F1268: 1080000d                 ba      loc_F00F129C
F00F126C: a2102000                 mov     0, %l1
F00F1270: 90020011                 add     %o0, %l1, %o0
F00F1274: 912a2002                 sll     %o0, 2, %o0! str
F00F1278: a0022008                 add     %o0, 8, %l0
F00F127C: 4000099d                 call    _sel_registerName
F00F1280: d0048010                 ld      [%l2+%l0], %o0
F00F1284: 92100008                 mov     %o0, %o1
F00F1288: d0048010                 ld      [%l2+%l0], %o0
F00F128C: 80a20009                 cmp     %o0, %o1
F00F1290: 32800002                 bne,a   loc_F00F1298
F00F1294: d2248010                 st      %o1, [%l2+%l0]
F00F1298: a2046001                 inc     %l1
F00F129C: d004a004                 ld      [%l2+4], %o0
F00F12A0: 80a44008                 cmp     %l1, %o0
F00F12A4: 0abffff3                 bcs     loc_F00F1270
F00F12A8: 912c6001                 sll     %l1, 1, %o0
F00F12AC: d004e00c                 ld      [%l3+0xC], %o0
F00F12B0: 80a22000                 cmp     %o0, 0
F00F12B4: 22800015                 be,a    loc_F00F1308
F00F12B8: d205600c                 ld      [%l5+0xC], %o1
F00F12BC: a4100008                 mov     %o0, %l2
F00F12C0: 1080000d                 ba      loc_F00F12F4
F00F12C4: a2102000                 mov     0, %l1
F00F12C8: 90020011                 add     %o0, %l1, %o0
F00F12CC: 912a2002                 sll     %o0, 2, %o0! str
F00F12D0: a0022008                 add     %o0, 8, %l0
F00F12D4: 40000987                 call    _sel_registerName
F00F12D8: d0048010                 ld      [%l2+%l0], %o0
F00F12DC: 92100008                 mov     %o0, %o1
F00F12E0: d0048010                 ld      [%l2+%l0], %o0
F00F12E4: 80a20009                 cmp     %o0, %o1
F00F12E8: 32800002                 bne,a   loc_F00F12F0
F00F12EC: d2248010                 st      %o1, [%l2+%l0]
F00F12F0: a2046001                 inc     %l1
F00F12F4: d004a004                 ld      [%l2+4], %o0
F00F12F8: 80a44008                 cmp     %l1, %o0
F00F12FC: 0abffff3                 bcs     loc_F00F12C8
F00F1300: 912c6001                 sll     %l1, 1, %o0
F00F1304: d205600c                 ld      [%l5+0xC], %o1
F00F1308: 912d2002                 sll     %l4, 2, %o0
F00F130C: 90020009                 add     %o0, %o1, %o0
F00F1310: d002200c                 ld      [%o0+0xC], %o0
F00F1314: 40000376                 call    __objc_add_category
F00F1318: d2054000                 ld      [%l5], %o1
F00F131C: a8052001                 inc     %l4
F00F1320: d405600c                 ld      [%l5+0xC], %o2
F00F1324: d012a008                 lduh    [%o2+8], %o0
F00F1328: d212a00a                 lduh    [%o2+0xA], %o1
F00F132C: 90020009                 add     %o0, %o1, %o0
F00F1330: 80a50008                 cmp     %l4, %o0
F00F1334: 06bfffc6                 bl      loc_F00F124C
F00F1338: 912d2002                 sll     %l4, 2, %o0
F00F133C: d007bff0                 ld      [%fp+var_10], %o0
F00F1340: d2056004                 ld      [%l5+4], %o1
F00F1344: 90220009                 sub     %o0, %o1, %o0
F00F1348: d027bff0                 st      %o0, [%fp+var_10]
F00F134C: d0056004                 ld      [%l5+4], %o0
F00F1350: aa854008                 addcc   %l5, %o0, %l5
F00F1354: 12bfffb2                 bne     loc_F00F121C
F00F1358: d007bff0                 ld      [%fp+var_10], %o0
F00F135C: aa100016                 mov     %l6, %l5
F00F1360: d007bff4                 ld      [%fp+var_C], %o0
F00F1364: 80a56000                 cmp     %l5, 0
F00F1368: 02800024                 be      loc_F00F13F8
F00F136C: d027bff0                 st      %o0, [%fp+var_10]
F00F1370: d007bff0                 ld      [%fp+var_10], %o0
F00F1374: 80a22000                 cmp     %o0, 0
F00F1378: 02800021                 be      loc_F00F13FC
F00F137C: 90100018                 mov     %i0, %o0
F00F1380: d0054000                 ld      [%l5], %o0
F00F1384: 80a22001                 cmp     %o0, 1
F00F1388: 12800015                 bne     loc_F00F13DC
F00F138C: d007bff0                 ld      [%fp+var_10], %o0
F00F1390: d005600c                 ld      [%l5+0xC], %o0! str
F00F1394: e6020000                 ld      [%o0], %l3
F00F1398: a0102000                 mov     0, %l0
F00F139C: 80a40013                 cmp     %l0, %l3
F00F13A0: 1a80000e                 bcc     loc_F00F13D8
F00F13A4: e4022004                 ld      [%o0+4], %l2
F00F13A8: a32c2002                 sll     %l0, 2, %l1
F00F13AC: 40000951                 call    _sel_registerName
F00F13B0: d0048011                 ld      [%l2+%l1], %o0
F00F13B4: 92100008                 mov     %o0, %o1
F00F13B8: d0048011                 ld      [%l2+%l1], %o0
F00F13BC: 80a20009                 cmp     %o0, %o1
F00F13C0: 32800002                 bne,a   loc_F00F13C8
F00F13C4: d2248011                 st      %o1, [%l2+%l1]
F00F13C8: a0042001                 inc     %l0
F00F13CC: 80a40013                 cmp     %l0, %l3
F00F13D0: 2abffff7                 bcs,a   loc_F00F13AC
F00F13D4: a32c2002                 sll     %l0, 2, %l1
F00F13D8: d007bff0                 ld      [%fp+var_10], %o0
F00F13DC: d2056004                 ld      [%l5+4], %o1
F00F13E0: 90220009                 sub     %o0, %o1, %o0
F00F13E4: d027bff0                 st      %o0, [%fp+var_10]
F00F13E8: d0056004                 ld      [%l5+4], %o0
F00F13EC: aa854008                 addcc   %l5, %o0, %l5
F00F13F0: 12bfffe1                 bne     loc_F00F1374
F00F13F4: d007bff0                 ld      [%fp+var_10], %o0
F00F13F8: 90100018                 mov     %i0, %o0! name
F00F13FC: 133c03f4921260c8         set     aObjc, %o1! "__OBJC"
F00F1404: 153c03f49412a0d0         set     aClsRefs, %o2! "__cls_refs"
F00F140C: 7ffde30a                 call    _getsectdatafromheader
F00F1410: 9607bff0                 add     %fp, var_10, %o3
F00F1414: a4920000                 orcc    %o0, %g0, %l2
F00F1418: 0280000e                 be      loc_F00F1450
F00F141C: aa100016                 mov     %l6, %l5
F00F1420: 10800006                 ba      loc_F00F1438
F00F1424: a2102000                 mov     0, %l1
F00F1428: 40000237                 call    _objc_getClass
F00F142C: d0048010                 ld      [%l2+%l0], %o0
F00F1430: d0248010                 st      %o0, [%l2+%l0]
F00F1434: a2046001                 inc     %l1
F00F1438: d007bff0                 ld      [%fp+var_10], %o0
F00F143C: 91322002                 srl     %o0, 2, %o0
F00F1440: 80a44008                 cmp     %l1, %o0
F00F1444: 0abffff9                 bcs     loc_F00F1428
F00F1448: a12c6002                 sll     %l1, 2, %l0
F00F144C: aa100016                 mov     %l6, %l5
F00F1450: d007bff4                 ld      [%fp+var_C], %o0
F00F1454: 80a56000                 cmp     %l5, 0
F00F1458: 02800028                 be      loc_F00F14F8
F00F145C: d027bff0                 st      %o0, [%fp+var_10]
F00F1460: d007bff0                 ld      [%fp+var_10], %o0
F00F1464: 80a22000                 cmp     %o0, 0
F00F1468: 22800025                 be,a    loc_F00F14FC
F00F146C: aa100016                 mov     %l6, %l5
F00F1470: a8102000                 mov     0, %l4
F00F1474: d005600c                 ld      [%l5+0xC], %o0
F00F1478: 92100008                 mov     %o0, %o1
F00F147C: d0122008                 lduh    [%o0+8], %o0
F00F1480: 80a50008                 cmp     %l4, %o0
F00F1484: 16800016                 bge     loc_F00F14DC
F00F1488: d007bff0                 ld      [%fp+var_10], %o0
F00F148C: 80a66000                 cmp     %i1, 0
F00F1490: 02800006                 be      loc_F00F14A8
F00F1494: 912d2002                 sll     %l4, 2, %o0
F00F1498: 90020009                 add     %o0, %o1, %o0
F00F149C: d002200c                 ld      [%o0+0xC], %o0
F00F14A0: 9fc64000                 call    %i1
F00F14A4: 92102000                 mov     0, %o1
F00F14A8: d005600c                 ld      [%l5+0xC], %o0
F00F14AC: 932d2002                 sll     %l4, 2, %o1
F00F14B0: 92024008                 add     %o1, %o0, %o1
F00F14B4: d002600c                 ld      [%o1+0xC], %o0
F00F14B8: 7ffffdc1                 call    sub_F00F0BBC
F00F14BC: 92100018                 mov     %i0, %o1
F00F14C0: a8052001                 inc     %l4
F00F14C4: d205600c                 ld      [%l5+0xC], %o1
F00F14C8: d0126008                 lduh    [%o1+8], %o0
F00F14CC: 80a50008                 cmp     %l4, %o0
F00F14D0: 06bffff0                 bl      loc_F00F1490
F00F14D4: 80a66000                 cmp     %i1, 0
F00F14D8: d007bff0                 ld      [%fp+var_10], %o0
F00F14DC: d2056004                 ld      [%l5+4], %o1
F00F14E0: 90220009                 sub     %o0, %o1, %o0
F00F14E4: d027bff0                 st      %o0, [%fp+var_10]
F00F14E8: d0056004                 ld      [%l5+4], %o0
F00F14EC: aa854008                 addcc   %l5, %o0, %l5
F00F14F0: 12bfffdd                 bne     loc_F00F1464
F00F14F4: d007bff0                 ld      [%fp+var_10], %o0
F00F14F8: aa100016                 mov     %l6, %l5
F00F14FC: d007bff4                 ld      [%fp+var_C], %o0
F00F1500: 80a56000                 cmp     %l5, 0
F00F1504: 02800030                 be      loc_F00F15C4
F00F1508: d027bff0                 st      %o0, [%fp+var_10]
F00F150C: d007bff0                 ld      [%fp+var_10], %o0
F00F1510: 80a22000                 cmp     %o0, 0
F00F1514: 2280002d                 be,a    locret_F00F15C8
F00F1518: b0102000                 mov     0, %i0
F00F151C: d005600c                 ld      [%l5+0xC], %o0
F00F1520: 94100008                 mov     %o0, %o2
F00F1524: e8122008                 lduh    [%o0+8], %l4
F00F1528: d012200a                 lduh    [%o0+0xA], %o0
F00F152C: 90050008                 add     %l4, %o0, %o0
F00F1530: 80a50008                 cmp     %l4, %o0
F00F1534: 1680001d                 bge     loc_F00F15A8
F00F1538: d007bff0                 ld      [%fp+var_10], %o0
F00F153C: 80a66000                 cmp     %i1, 0
F00F1540: 2280000c                 be,a    loc_F00F1570
F00F1544: d205600c                 ld      [%l5+0xC], %o1
F00F1548: a12d2002                 sll     %l4, 2, %l0
F00F154C: 9004000a                 add     %l0, %o2, %o0
F00F1550: d002200c                 ld      [%o0+0xC], %o0! name
F00F1554: 400001ec                 call    _objc_getClass
F00F1558: d0022004                 ld      [%o0+4], %o0
F00F155C: d205600c                 ld      [%l5+0xC], %o1
F00F1560: a0040009                 add     %l0, %o1, %l0
F00F1564: 9fc64000                 call    %i1
F00F1568: d204200c                 ld      [%l0+0xC], %o1
F00F156C: d205600c                 ld      [%l5+0xC], %o1
F00F1570: 912d2002                 sll     %l4, 2, %o0
F00F1574: 90020009                 add     %o0, %o1, %o0
F00F1578: d002200c                 ld      [%o0+0xC], %o0
F00F157C: 7ffffda0                 call    sub_F00F0BFC
F00F1580: 92100018                 mov     %i0, %o1
F00F1584: a8052001                 inc     %l4
F00F1588: d405600c                 ld      [%l5+0xC], %o2
F00F158C: d012a008                 lduh    [%o2+8], %o0
F00F1590: d212a00a                 lduh    [%o2+0xA], %o1
F00F1594: 90020009                 add     %o0, %o1, %o0
F00F1598: 80a50008                 cmp     %l4, %o0
F00F159C: 06bfffe9                 bl      loc_F00F1540
F00F15A0: 80a66000                 cmp     %i1, 0
F00F15A4: d007bff0                 ld      [%fp+var_10], %o0
F00F15A8: d2056004                 ld      [%l5+4], %o1
F00F15AC: 90220009                 sub     %o0, %o1, %o0
F00F15B0: d027bff0                 st      %o0, [%fp+var_10]
F00F15B4: d0056004                 ld      [%l5+4], %o0
F00F15B8: aa854008                 addcc   %l5, %o0, %l5
F00F15BC: 12bfffd5                 bne     loc_F00F1510
F00F15C0: d007bff0                 ld      [%fp+var_10], %o0
F00F15C4: b0102000                 mov     0, %i0
F00F15C8: 81c7e008                 ret
F00F15CC: 81e80000                 restore
