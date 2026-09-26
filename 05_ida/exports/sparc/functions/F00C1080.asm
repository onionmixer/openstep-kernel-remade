F00C1080: 9de3bf98                 save    %sp, -0x68, %sp! int
F00C1084: f227a048                 st      %i1, [%fp+arg_48]
F00C1088: 7fffff9b                 call    sub_F00C0EF4
F00C108C: 9007a048                 add     %fp, arg_48, %o0
F00C1090: b2102000                 mov     0, %i1
F00C1094: 94920000                 orcc    %o0, %g0, %o2
F00C1098: 12800004                 bne     loc_F00C10A8
F00C109C: a2100018                 mov     %i0, %l1
F00C10A0: 108000d5                 ba      locret_F00C13F4
F00C10A4: b0102000                 mov     0, %i0
F00C10A8: a010000a                 mov     %o2, %l0
F00C10AC: d00c2001                 ldub    [%l0+1], %o0
F00C10B0: 80a22001                 cmp     %o0, 1
F00C10B4: 22800026                 be,a    loc_F00C114C
F00C10B8: 900c60ff                 and     %l1, 0xFF, %o0
F00C10BC: 14800007                 bg      loc_F00C10D8
F00C10C0: 80a22002                 cmp     %o0, 2
F00C10C4: 80a22000                 cmp     %o0, 0
F00C10C8: 0280000a                 be      loc_F00C10F0
F00C10CC: 900c60ff                 and     %l1, 0xFF, %o0
F00C10D0: 1080006b                 ba      loc_F00C127C
F00C10D4: d20c2002                 ldub    [%l0+2], %o1
F00C10D8: 02800035                 be      loc_F00C11AC
F00C10DC: 80a22003                 cmp     %o0, 3
F00C10E0: 0280005a                 be      loc_F00C1248
F00C10E4: 920c60ff                 and     %l1, 0xFF, %o1
F00C10E8: 10800065                 ba      loc_F00C127C
F00C10EC: d20c2002                 ldub    [%l0+2], %o1
F00C10F0: 80a2207f                 cmp     %o0, 0x7F
F00C10F4: 12800011                 bne     loc_F00C1138
F00C10F8: 80a220ff                 cmp     %o0, 0xFF
F00C10FC: 90102001                 mov     1, %o0
F00C1100: d02c2001                 stb     %o0, [%l0+1]
F00C1104: 113c043e                 sethi   %hi(_hz), %o0
F00C1108: 9210200a                 mov     0xA, %o1! int
F00C110C: d00223e0                 ld      [%o0+%lo(_hz)], %o0! int
F00C1110: 213c0304                 sethi   %hi(_kbdidletimeout), %l0
F00C1114: e207a048                 ld      [%fp+arg_48], %l1
F00C1118: 7ffd153c                 call    _div
F00C111C: a0142030                 bset    %lo(_kbdidletimeout), %l0
F00C1120: 94100008                 mov     %o0, %o2! int
F00C1124: 90100010                 mov     %l0, %o0! int
F00C1128: 7ffd23c0                 call    _timeout
F00C112C: 92100011                 mov     %l1, %o1
F00C1130: 108000b1                 ba      locret_F00C13F4
F00C1134: b0102000                 mov     0, %i0
F00C1138: 128000af                 bne     locret_F00C13F4
F00C113C: b0102000                 mov     0, %i0
F00C1140: 90102002                 mov     2, %o0
F00C1144: 108000ac                 ba      locret_F00C13F4
F00C1148: d02c2001                 stb     %o0, [%l0+1]
F00C114C: 80a2207f                 cmp     %o0, 0x7F
F00C1150: 12800007                 bne     loc_F00C116C
F00C1154: 80a220ff                 cmp     %o0, 0xFF
F00C1158: d007a048                 ld      [%fp+arg_48], %o0
F00C115C: 400000a8                 call    sub_F00C13FC
F00C1160: 92102000                 mov     0, %o1
F00C1164: 108000a4                 ba      locret_F00C13F4
F00C1168: b0102000                 mov     0, %i0
F00C116C: 12800005                 bne     loc_F00C1180
F00C1170: 808e2080                 btst    0x80, %i0
F00C1174: 90102002                 mov     2, %o0
F00C1178: 10bfffca                 ba      loc_F00C10A0
F00C117C: d02c2001                 stb     %o0, [%l0+1]
F00C1180: 02800007                 be      loc_F00C119C
F00C1184: d007a048                 ld      [%fp+arg_48], %o0! int
F00C1188: 920e2040                 and     %i0, 0x40, %o1
F00C118C: 4000009c                 call    sub_F00C13FC
F00C1190: 92126001                 bset    1, %o1! int
F00C1194: 10800098                 ba      locret_F00C13F4
F00C1198: b0102000                 mov     0, %i0
F00C119C: 7fffff8c                 call    _kbdreset
F00C11A0: d007a048                 ld      [%fp+arg_48], %o0
F00C11A4: 10800094                 ba      locret_F00C13F4
F00C11A8: b0102000                 mov     0, %i0
F00C11AC: 900c60ff                 and     %l1, 0xFF, %o0
F00C11B0: 80a22004                 cmp     %o0, 4
F00C11B4: 02800005                 be      loc_F00C11C8
F00C11B8: 80a22081                 cmp     %o0, 0x81
F00C11BC: 02800007                 be      loc_F00C11D8
F00C11C0: d007a048                 ld      [%fp+arg_48], %o0
F00C11C4: 3080001d                 ba,a    loc_F00C1238
F00C11C8: d007a048                 ld      [%fp+arg_48], %o0
F00C11CC: 7fffff60                 call    _kbdcmd
F00C11D0: 9210200f                 mov     0xF, %o1
F00C11D4: d007a048                 ld      [%fp+arg_48], %o0
F00C11D8: 40000089                 call    sub_F00C13FC
F00C11DC: 920c60ff                 and     %l1, 0xFF, %o1
F00C11E0: 113c0483                 sethi   %hi(_kbdclick), %o0
F00C11E4: d0022288                 ld      [%o0+%lo(_kbdclick)], %o0
F00C11E8: 80a22000                 cmp     %o0, 0
F00C11EC: 2280000f                 be,a    loc_F00C1228
F00C11F0: d007a048                 ld      [%fp+arg_48], %o0
F00C11F4: 04800004                 ble     loc_F00C1204
F00C11F8: 80a22001                 cmp     %o0, 1
F00C11FC: 02800007                 be      loc_F00C1218
F00C1200: d007a048                 ld      [%fp+arg_48], %o0
F00C1204: 113c04fb                 sethi   %hi(_keyclick), %o0
F00C1208: d0022250                 ld      [%o0+%lo(_keyclick)], %o0
F00C120C: 80a22000                 cmp     %o0, 0
F00C1210: 02800006                 be      loc_F00C1228
F00C1214: d007a048                 ld      [%fp+arg_48], %o0! int
F00C1218: 7fffff4d                 call    _kbdcmd
F00C121C: 9210200a                 mov     0xA, %o1
F00C1220: 10800075                 ba      locret_F00C13F4
F00C1224: b0102000                 mov     0, %i0
F00C1228: 7fffff49                 call    _kbdcmd
F00C122C: 9210200b                 mov     0xB, %o1! int
F00C1230: 10800071                 ba      locret_F00C13F4
F00C1234: b0102000                 mov     0, %i0
F00C1238: 7fffff65                 call    _kbdreset
F00C123C: d007a048                 ld      [%fp+arg_48], %o0
F00C1240: 1080006d                 ba      locret_F00C13F4
F00C1244: b0102000                 mov     0, %i0
F00C1248: 80a26000                 cmp     %o1, 0
F00C124C: 12800006                 bne     loc_F00C1264
F00C1250: 80a260ff                 cmp     %o1, 0xFF
F00C1254: d00c2002                 ldub    [%l0+2], %o0! int
F00C1258: 80a22004                 cmp     %o0, 4
F00C125C: 12800004                 bne     loc_F00C126C
F00C1260: 80a260ff                 cmp     %o1, 0xFF
F00C1264: 32800006                 bne,a   loc_F00C127C
F00C1268: d20c2002                 ldub    [%l0+2], %o1! int
F00C126C: 7fffff58                 call    _kbdreset
F00C1270: d007a048                 ld      [%fp+arg_48], %o0
F00C1274: 10800060                 ba      locret_F00C13F4
F00C1278: b0102000                 mov     0, %i0
F00C127C: 80a26007                 cmp     %o1, 7! switch 8 cases
F00C1280: 1880005c                 bgu     def_F00C1294! jumptable F00C1294 default case
F00C1284: 113c0304                 sethi   %hi(jpt_F00C1294), %o0
F00C1288: 9012229c                 bset    %lo(jpt_F00C1294), %o0
F00C128C: 932a6002                 sll     %o1, 2, %o1
F00C1290: d0024008                 ld      [%o1+%o0], %o0
F00C1294: 81c20000                 jmp     %o0! switch jump
F00C1298: 01000000                 nop
F00C12BC: c02c2002                 clrb    [%l0+2]
F00C12C0: d004200c                 ld      [%l0+0xC], %o0! jumptable F00C1294 case 0
F00C12C4: 80a22000                 cmp     %o0, 0
F00C12C8: 2280000a                 be,a    loc_F00C12F0
F00C12CC: 900c60ff                 and     %l1, 0xFF, %o0
F00C12D0: d20a2024                 ldub    [%o0+0x24], %o1! int
F00C12D4: 900c60ff                 and     %l1, 0xFF, %o0
F00C12D8: 80a20009                 cmp     %o0, %o1
F00C12DC: 12800006                 bne     loc_F00C12F4
F00C12E0: 80a220fe                 cmp     %o0, 0xFE
F00C12E4: 90102001                 mov     1, %o0
F00C12E8: 10800042                 ba      def_F00C1294! jumptable F00C1294 default case
F00C12EC: d02c2002                 stb     %o0, [%l0+2]
F00C12F0: 80a220fe                 cmp     %o0, 0xFE
F00C12F4: 02800014                 be      loc_F00C1344
F00C12F8: 80a2207f                 cmp     %o0, 0x7F
F00C12FC: 1280003d                 bne     def_F00C1294! jumptable F00C1294 default case
F00C1300: b2102001                 mov     1, %i1
F00C1304: 90102002                 mov     2, %o0
F00C1308: 10800039                 ba      loc_F00C13EC
F00C130C: d02c2002                 stb     %o0, [%l0+2]
F00C1310: 808c6080                 btst    0x80, %l1! jumptable F00C1294 case 2
F00C1314: 02800013                 be      loc_F00C1360
F00C1318: 900c60ff                 and     %l1, 0xFF, %o0
F00C131C: d00c0000                 ldub    [%l0], %o0
F00C1320: 80a22001                 cmp     %o0, 1
F00C1324: 12800005                 bne     loc_F00C1338
F00C1328: 900c60ff                 and     %l1, 0xFF, %o0
F00C132C: 90102003                 mov     3, %o0
F00C1330: 10800030                 ba      def_F00C1294! jumptable F00C1294 default case
F00C1334: d02c2002                 stb     %o0, [%l0+2]
F00C1338: 80a220fe                 cmp     %o0, 0xFE
F00C133C: 12800005                 bne     loc_F00C1350
F00C1340: 01000000                 nop
F00C1344: 90102004                 mov     4, %o0! int
F00C1348: 1080002a                 ba      def_F00C1294! jumptable F00C1294 default case
F00C134C: d02c2002                 stb     %o0, [%l0+2]
F00C1350: 7fffff1f                 call    _kbdreset
F00C1354: d007a048                 ld      [%fp+arg_48], %o0
F00C1358: 10800027                 ba      locret_F00C13F4
F00C135C: b0100019                 mov     %i1, %i0
F00C1360: 80a2207f                 cmp     %o0, 0x7F
F00C1364: 32bfffd7                 bne,a   loc_F00C12C0! jumptable F00C1294 case 0
F00C1368: c02c2002                 clrb    [%l0+2]
F00C136C: 10800022                 ba      locret_F00C13F4
F00C1370: b0100019                 mov     %i1, %i0
F00C1374: 900c60ff                 and     %l1, 0xFF, %o0! jumptable F00C1294 case 3
F00C1378: 80a2207f                 cmp     %o0, 0x7F
F00C137C: 32bfffd1                 bne,a   loc_F00C12C0! jumptable F00C1294 case 0
F00C1380: c02c2002                 clrb    [%l0+2]
F00C1384: 90102002                 mov     2, %o0
F00C1388: 1080001a                 ba      def_F00C1294! jumptable F00C1294 default case
F00C138C: d02c2002                 stb     %o0, [%l0+2]
F00C1390: e22aa02b                 stb     %l1, [%o2+0x2B]! jumptable F00C1294 case 4
F00C1394: 10800017                 ba      def_F00C1294! jumptable F00C1294 default case
F00C1398: c02c2002                 clrb    [%l0+2]
F00C139C: d004200c                 ld      [%l0+0xC], %o0! jumptable F00C1294 case 1
F00C13A0: 80a22000                 cmp     %o0, 0
F00C13A4: 02800014                 be      locret_F00C13F4
F00C13A8: b0100019                 mov     %i1, %i0
F00C13AC: d20a2025                 ldub    [%o0+0x25], %o1
F00C13B0: 900c60ff                 and     %l1, 0xFF, %o0
F00C13B4: 80a20009                 cmp     %o0, %o1
F00C13B8: 12bfffc1                 bne     loc_F00C12BC
F00C13BC: b2102000                 mov     0, %i1
F00C13C0: 11000061                 sethi   0x18400, %o0
F00C13C4: 7fff5927                 call    _us_spin
F00C13C8: 901222a0                 bset    0x2A0, %o0
F00C13CC: 7fffb6be                 call    _prom_enter_mon
F00C13D0: b2102000                 mov     0, %i1
F00C13D4: 10800007                 ba      def_F00C1294! jumptable F00C1294 default case
F00C13D8: c02c2002                 clrb    [%l0+2]
F00C13DC: 900c60ff                 and     %l1, 0xFF, %o0! jumptable F00C1294 cases 5-7
F00C13E0: 80a2207f                 cmp     %o0, 0x7F
F00C13E4: 02800004                 be      locret_F00C13F4
F00C13E8: b0100019                 mov     %i1, %i0
F00C13EC: b2102000                 mov     0, %i1
F00C13F0: b0100019                 mov     %i1, %i0! jumptable F00C1294 default case
F00C13F4: 81c7e008                 ret
F00C13F8: 81e80000                 restore
