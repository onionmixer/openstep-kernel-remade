F00D0E74: 9de3bf68                 save    %sp, -0x98, %sp
F00D0E78: a4103d3e                 mov     -0x2C2, %l2
F00D0E7C: e2070000                 ld      [%i4], %l1
F00D0E80: 9010001b                 mov     %i3, %o0! __s1
F00D0E84: 133c03ee92126318         set     aEvButtoneventn, %o1! "Ev_ButtonEventNums"
F00D0E8C: 7ffcdcc8                 call    _strcmp
F00D0E90: c027bfc8                 clr     [%fp+var_38]
F00D0E94: 80a22000                 cmp     %o0, 0
F00D0E98: 32800012                 bne,a   loc_F00D0EE0
F00D0E9C: 9010001b                 mov     %i3, %o0
F00D0EA0: 80a46001                 cmp     %l1, 1
F00D0EA4: 088001ae                 bleu    loc_F00D155C
F00D0EA8: 133c0504                 sethi   %hi(paLock), %o1
F00D0EAC: d0062110                 ld      [%i0+0x110], %o0! id
F00D0EB0: 94102002                 mov     2, %o2
F00D0EB4: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D0EB8: 4000826e                 call    _objc_msgSend
F00D0EBC: d427bfc8                 st      %o2, [%fp+var_38]
F00D0EC0: d05621f8                 ldsh    [%i0+0x1F8], %o0
F00D0EC4: d0268000                 st      %o0, [%i2]
F00D0EC8: d45621fa                 ldsh    [%i0+0x1FA], %o2
F00D0ECC: 113c0504                 sethi   %hi(paUnlock), %o0
F00D0ED0: d2022244                 ld      [%o0+%lo(paUnlock)], %o1
F00D0ED4: d426a004                 st      %o2, [%i2+4]
F00D0ED8: 10800170                 ba      loc_F00D1498
F00D0EDC: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D0EE0: 133c03ee                 sethi   %hi(aEvShmemsize), %o1! "Ev_ShmemSize"
F00D0EE4: 7ffcdcb2                 call    _strcmp
F00D0EE8: 92126330                 bset    %lo(aEvShmemsize), %o1! "Ev_ShmemSize"
F00D0EEC: 80a22000                 cmp     %o0, 0
F00D0EF0: 3280000a                 bne,a   loc_F00D0F18
F00D0EF4: 9010001b                 mov     %i3, %o0
F00D0EF8: 80a46000                 cmp     %l1, 0
F00D0EFC: 02800198                 be      loc_F00D155C
F00D0F00: 90102001                 mov     1, %o0
F00D0F04: d027bfc8                 st      %o0, [%fp+var_38]
F00D0F08: d0062160                 ld      [%i0+0x160], %o0! __s1
F00D0F0C: a4102000                 mov     0, %l2
F00D0F10: 10800193                 ba      loc_F00D155C
F00D0F14: d0268000                 st      %o0, [%i2]
F00D0F18: 133c03ee                 sethi   %hi(aEvsCurrentwait), %o1! "Evs_CurrentWaitCursorInfo"
F00D0F1C: 7ffcdca4                 call    _strcmp
F00D0F20: 92126340                 bset    %lo(aEvsCurrentwait), %o1! "Evs_CurrentWaitCursorInfo"
F00D0F24: 80a22000                 cmp     %o0, 0
F00D0F28: 32800042                 bne,a   loc_F00D1030
F00D0F2C: 9010001b                 mov     %i3, %o0
F00D0F30: 80a46005                 cmp     %l1, 5
F00D0F34: 0880018a                 bleu    loc_F00D155C
F00D0F38: 133c0504                 sethi   %hi(paLock), %o1
F00D0F3C: d0062110                 ld      [%i0+0x110], %o0! id
F00D0F40: 94102006                 mov     6, %o2
F00D0F44: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D0F48: 4000824a                 call    _objc_msgSend
F00D0F4C: d427bfc8                 st      %o2, [%fp+var_38]
F00D0F50: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D0F54: 80a22001                 cmp     %o0, 1
F00D0F58: 1280000e                 bne     loc_F00D0F90
F00D0F5C: 01000000                 nop
F00D0F60: d0062168                 ld      [%i0+0x168], %o0
F00D0F64: d412204c                 lduh    [%o0+0x4C], %o2
F00D0F68: 952aa010                 sll     %o2, 16, %o2
F00D0F6C: 933aa010                 sra     %o2, 16, %o1
F00D0F70: 913aa01f                 sra     %o2, 31, %o0
F00D0F74: 95326008                 srl     %o1, 8, %o2
F00D0F78: 972a2018                 sll     %o0, 24, %o3
F00D0F7C: 9412800b                 bset    %o3, %o2
F00D0F80: d427bfe8                 st      %o2, [%fp+var_18]
F00D0F84: 912a6018                 sll     %o1, 24, %o0
F00D0F88: 10800005                 ba      loc_F00D0F9C
F00D0F8C: d027bfec                 st      %o0, [%fp+var_18+4]
F00D0F90: a8102000                 mov     0, %l4
F00D0F94: aa102000                 mov     0, %l5
F00D0F98: e83fbfe8                 std     %l4, [%fp+var_18]
F00D0F9C: 9407bfe8                 add     %fp, var_18, %o2
F00D0FA0: 96102000                 mov     0, %o3
F00D0FA4: d01fbfe8                 ldd     [%fp+var_18], %o0
F00D0FA8: 9807bfec                 add     %fp, var_18+4, %o4
F00D0FAC: d03fbfe0                 std     %o0, [%fp+var_20]
F00D0FB0: d002bff8                 ld      [%o2-8], %o0
F00D0FB4: d022c01a                 st      %o0, [%o3+%i2]
F00D0FB8: 9402a004                 inc     4, %o2
F00D0FBC: 80a2800c                 cmp     %o2, %o4
F00D0FC0: 08bffffc                 bleu    loc_F00D0FB0
F00D0FC4: 9602e004                 inc     4, %o3
F00D0FC8: 9a06a008                 add     %i2, 8, %o5
F00D0FCC: 9407bfe8                 add     %fp, var_18, %o2
F00D0FD0: 96102000                 mov     0, %o3
F00D0FD4: d01e21d8                 ldd     [%i0+0x1D8], %o0
F00D0FD8: 9807bfec                 add     %fp, var_18+4, %o4
F00D0FDC: d03fbfe0                 std     %o0, [%fp+var_20]
F00D0FE0: d002bff8                 ld      [%o2-8], %o0
F00D0FE4: d022c00d                 st      %o0, [%o3+%o5]
F00D0FE8: 9402a004                 inc     4, %o2
F00D0FEC: 80a2800c                 cmp     %o2, %o4
F00D0FF0: 08bffffc                 bleu    loc_F00D0FE0
F00D0FF4: 9602e004                 inc     4, %o3
F00D0FF8: 9406a010                 add     %i2, 0x10, %o2
F00D0FFC: 9607bfe8                 add     %fp, var_18, %o3
F00D1000: 98102000                 mov     0, %o4
F00D1004: d01e21e8                 ldd     [%i0+0x1E8], %o0
F00D1008: 9a07bfec                 add     %fp, var_18+4, %o5
F00D100C: d03fbfe0                 std     %o0, [%fp+var_20]
F00D1010: d002fff8                 ld      [%o3-8], %o0
F00D1014: d023000a                 st      %o0, [%o4+%o2]
F00D1018: 9602e004                 inc     4, %o3
F00D101C: 80a2c00d                 cmp     %o3, %o5
F00D1020: 08bffffc                 bleu    loc_F00D1010
F00D1024: 98032004                 inc     4, %o4
F00D1028: 1080011a                 ba      loc_F00D1490
F00D102C: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D1030: 133c03ee                 sethi   %hi(aEvsDevicecontr), %o1! "Evs_DeviceControlInfo"
F00D1034: 7ffcdc5e                 call    _strcmp
F00D1038: 92126360                 bset    %lo(aEvsDevicecontr), %o1! "Evs_DeviceControlInfo"
F00D103C: 80a22000                 cmp     %o0, 0
F00D1040: 32800018                 bne,a   loc_F00D10A0
F00D1044: 9010001b                 mov     %i3, %o0
F00D1048: 80a46002                 cmp     %l1, 2
F00D104C: 08800144                 bleu    loc_F00D155C
F00D1050: 133c0504                 sethi   %hi(paLock), %o1
F00D1054: d0062110                 ld      [%i0+0x110], %o0! id
F00D1058: 94102003                 mov     3, %o2
F00D105C: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D1060: 40008204                 call    _objc_msgSend
F00D1064: d427bfc8                 st      %o2, [%fp+var_38]
F00D1068: 113c0505                 sethi   %hi(paBrightness), %o0! id
F00D106C: d202233c                 ld      [%o0+%lo(paBrightness)], %o1! SEL
F00D1070: 40008200                 call    _objc_msgSend
F00D1074: 90100018                 mov     %i0, %o0
F00D1078: d0268000                 st      %o0, [%i2]
F00D107C: 90100018                 mov     %i0, %o0! id
F00D1080: d40621c4                 ld      [%i0+0x1C4], %o2
F00D1084: 133c0505                 sethi   %hi(paAutodimbrightn), %o1
F00D1088: d2026338                 ld      [%o1+%lo(paAutodimbrightn)], %o1! SEL
F00D108C: 400081f9                 call    _objc_msgSend
F00D1090: d426a004                 st      %o2, [%i2+4]
F00D1094: d026a008                 st      %o0, [%i2+8]
F00D1098: 108000fe                 ba      loc_F00D1490
F00D109C: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D10A0: 133c03ee                 sethi   %hi(aEvsCurrentclic), %o1! "Evs_CurrentClickTime"
F00D10A4: 7ffcdc42                 call    _strcmp
F00D10A8: 92126378                 bset    %lo(aEvsCurrentclic), %o1! "Evs_CurrentClickTime"
F00D10AC: 80a22000                 cmp     %o0, 0
F00D10B0: 3280001e                 bne,a   loc_F00D1128
F00D10B4: 9010001b                 mov     %i3, %o0
F00D10B8: 80a46001                 cmp     %l1, 1
F00D10BC: 08800128                 bleu    loc_F00D155C
F00D10C0: 133c0504                 sethi   %hi(paLock), %o1
F00D10C4: d0062110                 ld      [%i0+0x110], %o0! id
F00D10C8: 94102002                 mov     2, %o2
F00D10CC: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D10D0: 400081e8                 call    _objc_msgSend
F00D10D4: d427bfc8                 st      %o2, [%fp+var_38]
F00D10D8: 8407bfe8                 add     %fp, var_18, %g2
F00D10DC: 86102000                 mov     0, %g3
F00D10E0: d80621bc                 ld      [%i0+0x1BC], %o4
F00D10E4: 9e07bfec                 add     %fp, var_18+4, %o7
F00D10E8: 9210000c                 mov     %o4, %o1
F00D10EC: 90102000                 mov     0, %o0
F00D10F0: 9b326008                 srl     %o1, 8, %o5
F00D10F4: 992a2018                 sll     %o0, 24, %o4
F00D10F8: 9413400c                 or      %o5, %o4, %o2
F00D10FC: 972a6018                 sll     %o1, 24, %o3
F00D1100: d43fbfe8                 std     %o2, [%fp+var_18]
F00D1104: d43fbfe0                 std     %o2, [%fp+var_20]
F00D1108: d000bff8                 ld      [%g2-8], %o0
F00D110C: d020c01a                 st      %o0, [%g3+%i2]
F00D1110: 8400a004                 inc     4, %g2
F00D1114: 80a0800f                 cmp     %g2, %o7
F00D1118: 08bffffc                 bleu    loc_F00D1108
F00D111C: 8600e004                 inc     4, %g3
F00D1120: 108000dc                 ba      loc_F00D1490
F00D1124: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D1128: 133c03ee                 sethi   %hi(aEvsCurrentauto), %o1! "Evs_CurrentAutoDimTime"
F00D112C: 7ffcdc20                 call    _strcmp
F00D1130: 92126390                 bset    %lo(aEvsCurrentauto), %o1! "Evs_CurrentAutoDimTime"
F00D1134: 80a22000                 cmp     %o0, 0
F00D1138: 3280001e                 bne,a   loc_F00D11B0
F00D113C: 9010001b                 mov     %i3, %o0
F00D1140: 80a46001                 cmp     %l1, 1
F00D1144: 08800106                 bleu    loc_F00D155C
F00D1148: 133c0504                 sethi   %hi(paLock), %o1
F00D114C: d0062110                 ld      [%i0+0x110], %o0! id
F00D1150: 94102002                 mov     2, %o2
F00D1154: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D1158: 400081c6                 call    _objc_msgSend
F00D115C: d427bfc8                 st      %o2, [%fp+var_38]
F00D1160: 8407bfe8                 add     %fp, var_18, %g2
F00D1164: 86102000                 mov     0, %g3
F00D1168: d80621a0                 ld      [%i0+0x1A0], %o4
F00D116C: 9e07bfec                 add     %fp, var_18+4, %o7
F00D1170: 9210000c                 mov     %o4, %o1
F00D1174: 90102000                 mov     0, %o0
F00D1178: 9b326008                 srl     %o1, 8, %o5
F00D117C: 992a2018                 sll     %o0, 24, %o4
F00D1180: 9413400c                 or      %o5, %o4, %o2
F00D1184: 972a6018                 sll     %o1, 24, %o3
F00D1188: d43fbfe8                 std     %o2, [%fp+var_18]
F00D118C: d43fbfe0                 std     %o2, [%fp+var_20]
F00D1190: d000bff8                 ld      [%g2-8], %o0
F00D1194: d020c01a                 st      %o0, [%g3+%i2]
F00D1198: 8400a004                 inc     4, %g2
F00D119C: 80a0800f                 cmp     %g2, %o7
F00D11A0: 08bffffc                 bleu    loc_F00D1190
F00D11A4: 8600e004                 inc     4, %g3
F00D11A8: 108000ba                 ba      loc_F00D1490
F00D11AC: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D11B0: 133c03ee                 sethi   %hi(aEvsGetdeltaaut), %o1! "Evs_GetDeltaAutoDimTime"
F00D11B4: 7ffcdbfe                 call    _strcmp
F00D11B8: 921263a8                 bset    %lo(aEvsGetdeltaaut), %o1! "Evs_GetDeltaAutoDimTime"
F00D11BC: 80a22000                 cmp     %o0, 0
F00D11C0: 3280002d                 bne,a   loc_F00D1274
F00D11C4: 9010001b                 mov     %i3, %o0
F00D11C8: 80a46001                 cmp     %l1, 1
F00D11CC: 088000e4                 bleu    loc_F00D155C
F00D11D0: 133c0504                 sethi   %hi(paLock), %o1
F00D11D4: d0062110                 ld      [%i0+0x110], %o0! id
F00D11D8: 94102002                 mov     2, %o2
F00D11DC: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D11E0: 400081a4                 call    _objc_msgSend
F00D11E4: d427bfc8                 st      %o2, [%fp+var_38]
F00D11E8: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D11EC: 80a22001                 cmp     %o0, 1
F00D11F0: 3280000d                 bne,a   loc_F00D1224
F00D11F4: d80621a0                 ld      [%i0+0x1A0], %o4
F00D11F8: d04e21d3                 ldsb    [%i0+0x1D3], %o0
F00D11FC: 80a22000                 cmp     %o0, 0
F00D1200: 22800006                 be,a    loc_F00D1218
F00D1204: d4062168                 ld      [%i0+0x168], %o2
F00D1208: a8102000                 mov     0, %l4
F00D120C: aa102000                 mov     0, %l5
F00D1210: 1080000c                 ba      loc_F00D1240
F00D1214: e83fbfe8                 std     %l4, [%fp+var_18]
F00D1218: d80621a4                 ld      [%i0+0x1A4], %o4
F00D121C: da02a010                 ld      [%o2+0x10], %o5
F00D1220: 9823000d                 sub     %o4, %o5, %o4
F00D1224: 9210000c                 mov     %o4, %o1
F00D1228: 90102000                 mov     0, %o0
F00D122C: 9b326008                 srl     %o1, 8, %o5
F00D1230: 992a2018                 sll     %o0, 24, %o4
F00D1234: 9413400c                 or      %o5, %o4, %o2
F00D1238: 972a6018                 sll     %o1, 24, %o3
F00D123C: d43fbfe8                 std     %o2, [%fp+var_18]
F00D1240: 9407bfe8                 add     %fp, var_18, %o2
F00D1244: 96102000                 mov     0, %o3
F00D1248: d01fbfe8                 ldd     [%fp+var_18], %o0
F00D124C: 9807bfec                 add     %fp, var_18+4, %o4
F00D1250: d03fbfe0                 std     %o0, [%fp+var_20]
F00D1254: d002bff8                 ld      [%o2-8], %o0
F00D1258: d022c01a                 st      %o0, [%o3+%i2]
F00D125C: 9402a004                 inc     4, %o2
F00D1260: 80a2800c                 cmp     %o2, %o4
F00D1264: 08bffffc                 bleu    loc_F00D1254
F00D1268: 9602e004                 inc     4, %o3
F00D126C: 10800089                 ba      loc_F00D1490
F00D1270: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D1274: 133c03ee                 sethi   %hi(aEvsGetidletime), %o1! "Evs_GetIdleTime"
F00D1278: 7ffcdbcd                 call    _strcmp
F00D127C: 921263c0                 bset    %lo(aEvsGetidletime), %o1! "Evs_GetIdleTime"
F00D1280: 80a22000                 cmp     %o0, 0
F00D1284: 32800034                 bne,a   loc_F00D1354
F00D1288: 9010001b                 mov     %i3, %o0
F00D128C: 80a46001                 cmp     %l1, 1
F00D1290: 088000b3                 bleu    loc_F00D155C
F00D1294: 133c0504                 sethi   %hi(paLock), %o1
F00D1298: d0062110                 ld      [%i0+0x110], %o0! id
F00D129C: 94102002                 mov     2, %o2
F00D12A0: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D12A4: 40008173                 call    _objc_msgSend
F00D12A8: d427bfc8                 st      %o2, [%fp+var_38]
F00D12AC: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D12B0: 80a22001                 cmp     %o0, 1
F00D12B4: 12800018                 bne     loc_F00D1314
F00D12B8: 01000000                 nop
F00D12BC: d04e21d3                 ldsb    [%i0+0x1D3], %o0
F00D12C0: 80a22000                 cmp     %o0, 0
F00D12C4: 22800007                 be,a    loc_F00D12E0
F00D12C8: d4062168                 ld      [%i0+0x168], %o2
F00D12CC: d8062168                 ld      [%i0+0x168], %o4
F00D12D0: c40621a0                 ld      [%i0+0x1A0], %g2
F00D12D4: d8032010                 ld      [%o4+0x10], %o4
F00D12D8: 10800005                 ba      loc_F00D12EC
F00D12DC: da0621a4                 ld      [%i0+0x1A4], %o5
F00D12E0: da0621a4                 ld      [%i0+0x1A4], %o5
F00D12E4: d80621a0                 ld      [%i0+0x1A0], %o4
F00D12E8: c402a010                 ld      [%o2+0x10], %g2
F00D12EC: 9a234002                 sub     %o5, %g2, %o5
F00D12F0: 9823000d                 sub     %o4, %o5, %o4
F00D12F4: 9210000c                 mov     %o4, %o1
F00D12F8: 90102000                 mov     0, %o0
F00D12FC: 9b326008                 srl     %o1, 8, %o5
F00D1300: 992a2018                 sll     %o0, 24, %o4
F00D1304: 9413400c                 or      %o5, %o4, %o2
F00D1308: 972a6018                 sll     %o1, 24, %o3
F00D130C: 10800005                 ba      loc_F00D1320
F00D1310: d43fbfe8                 std     %o2, [%fp+var_18]
F00D1314: a8102000                 mov     0, %l4
F00D1318: aa102000                 mov     0, %l5
F00D131C: e83fbfe8                 std     %l4, [%fp+var_18]
F00D1320: 9407bfe8                 add     %fp, var_18, %o2
F00D1324: 96102000                 mov     0, %o3
F00D1328: d01fbfe8                 ldd     [%fp+var_18], %o0
F00D132C: 9807bfec                 add     %fp, var_18+4, %o4
F00D1330: d03fbfe0                 std     %o0, [%fp+var_20]
F00D1334: d002bff8                 ld      [%o2-8], %o0
F00D1338: d022c01a                 st      %o0, [%o3+%i2]
F00D133C: 9402a004                 inc     4, %o2
F00D1340: 80a2800c                 cmp     %o2, %o4
F00D1344: 08bffffc                 bleu    loc_F00D1334
F00D1348: 9602e004                 inc     4, %o3
F00D134C: 10800051                 ba      loc_F00D1490
F00D1350: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D1354: 133c03ee                 sethi   %hi(aEvsCurrentclic_0), %o1! "Evs_CurrentClickSpace"
F00D1358: 7ffcdb95                 call    _strcmp
F00D135C: 921263d0                 bset    %lo(aEvsCurrentclic_0), %o1! "Evs_CurrentClickSpace"
F00D1360: 80a22000                 cmp     %o0, 0
F00D1364: 32800012                 bne,a   loc_F00D13AC
F00D1368: 9010001b                 mov     %i3, %o0
F00D136C: 80a46001                 cmp     %l1, 1
F00D1370: 0880007b                 bleu    loc_F00D155C
F00D1374: 133c0504                 sethi   %hi(paLock), %o1
F00D1378: d0062110                 ld      [%i0+0x110], %o0! id
F00D137C: 94102002                 mov     2, %o2
F00D1380: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D1384: 4000813b                 call    _objc_msgSend
F00D1388: d427bfc8                 st      %o2, [%fp+var_38]
F00D138C: d05621b0                 ldsh    [%i0+0x1B0], %o0
F00D1390: d0268000                 st      %o0, [%i2]
F00D1394: d45621b2                 ldsh    [%i0+0x1B2], %o2
F00D1398: 113c0504                 sethi   %hi(paUnlock), %o0
F00D139C: d2022244                 ld      [%o0+%lo(paUnlock)], %o1
F00D13A0: d426a004                 st      %o2, [%i2+4]
F00D13A4: 1080003d                 ba      loc_F00D1498
F00D13A8: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D13AC: 133c03ee                 sethi   %hi(aEvsAutodimmed), %o1! "Evs_AutoDimmed"
F00D13B0: 7ffcdb7f                 call    _strcmp
F00D13B4: 921263e8                 bset    %lo(aEvsAutodimmed), %o1! "Evs_AutoDimmed"
F00D13B8: 80a22000                 cmp     %o0, 0
F00D13BC: 32800010                 bne,a   loc_F00D13FC
F00D13C0: 9010001b                 mov     %i3, %o0
F00D13C4: 80a46000                 cmp     %l1, 0
F00D13C8: 02800065                 be      loc_F00D155C
F00D13CC: 133c0504                 sethi   %hi(paLock), %o1
F00D13D0: d0062110                 ld      [%i0+0x110], %o0! id
F00D13D4: 94102001                 mov     1, %o2
F00D13D8: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D13DC: 40008125                 call    _objc_msgSend
F00D13E0: d427bfc8                 st      %o2, [%fp+var_38]
F00D13E4: d44e21d3                 ldsb    [%i0+0x1D3], %o2
F00D13E8: 113c0504                 sethi   %hi(paUnlock), %o0
F00D13EC: d2022244                 ld      [%o0+%lo(paUnlock)], %o1
F00D13F0: d4268000                 st      %o2, [%i2]
F00D13F4: 10800029                 ba      loc_F00D1498
F00D13F8: d0062110                 ld      [%i0+0x110], %o0! __s1
F00D13FC: 133c03ee                 sethi   %hi(aEvsEventdevice), %o1! "Evs_EventDeviceInfo"
F00D1400: 7ffcdb6b                 call    _strcmp
F00D1404: 921263f8                 bset    %lo(aEvsEventdevice), %o1! "Evs_EventDeviceInfo"
F00D1408: 80a22000                 cmp     %o0, 0
F00D140C: 12800029                 bne     loc_F00D14B0
F00D1410: d0062170                 ld      [%i0+0x170], %o0! id
F00D1414: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D1418: 40008116                 call    _objc_msgSend
F00D141C: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D1420: e0062174                 ld      [%i0+0x174], %l0
F00D1424: 90062174                 add     %i0, 0x174, %o0
F00D1428: 80a20010                 cmp     %o0, %l0
F00D142C: 02800018                 be      loc_F00D148C
F00D1430: a4100008                 mov     %o0, %l2
F00D1434: 273c0504                 sethi   -0xFEBF000, %l3
F00D1438: 80a46003                 cmp     %l1, 3
F00D143C: 08800014                 bleu    loc_F00D148C
F00D1440: 9610001b                 mov     %i3, %o3
F00D1444: c027bfcc                 clr     [%fp+var_38+4]
F00D1448: d0040000                 ld      [%l0], %o0! id
F00D144C: d407bfc8                 ld      [%fp+var_38], %o2
F00D1450: 9807bfcc                 add     %fp, var_38+4, %o4
F00D1454: d204e2c8                 ld      [%l3+0x2C8], %o1! SEL
F00D1458: 952aa002                 sll     %o2, 2, %o2
F00D145C: e0042004                 ld      [%l0+4], %l0
F00D1460: 40008104                 call    _objc_msgSend
F00D1464: 9406800a                 add     %i2, %o2, %o2
F00D1468: 80a22000                 cmp     %o0, 0
F00D146C: 12800006                 bne     loc_F00D1484
F00D1470: 80a48010                 cmp     %l2, %l0
F00D1474: d01fbfc8                 ldd     [%fp+var_38], %o0
F00D1478: a2244009                 sub     %l1, %o1, %l1
F00D147C: 90020009                 add     %o0, %o1, %o0
F00D1480: d027bfc8                 st      %o0, [%fp+var_38]
F00D1484: 12bfffee                 bne     loc_F00D143C
F00D1488: 80a46003                 cmp     %l1, 3
F00D148C: d0062170                 ld      [%i0+0x170], %o0! id
F00D1490: 133c0504                 sethi   %hi(paUnlock), %o1
F00D1494: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00D1498: 400080f6                 call    _objc_msgSend
F00D149C: a4102000                 mov     0, %l2
F00D14A0: 10800030                 ba      loc_F00D1560
F00D14A4: d007bfc8                 ld      [%fp+var_38], %o0! id
F00D14A8: 1080001a                 ba      loc_F00D1510
F00D14AC: a4100008                 mov     %o0, %l2
F00D14B0: d4070000                 ld      [%i4], %o2
F00D14B4: 133c0504                 sethi   %hi(paLock), %o1
F00D14B8: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D14BC: 400080ed                 call    _objc_msgSend
F00D14C0: d427bfc8                 st      %o2, [%fp+var_38]
F00D14C4: e0062174                 ld      [%i0+0x174], %l0
F00D14C8: 90062174                 add     %i0, 0x174, %o0
F00D14CC: 80a20010                 cmp     %o0, %l0
F00D14D0: 22800011                 be,a    loc_F00D1514
F00D14D4: d0062170                 ld      [%i0+0x170], %o0
F00D14D8: 273c0504                 sethi   -0xFEBF000, %l3
F00D14DC: a2100008                 mov     %o0, %l1
F00D14E0: d0040000                 ld      [%l0], %o0! id
F00D14E4: 9410001a                 mov     %i2, %o2
F00D14E8: d204e2c8                 ld      [%l3+0x2C8], %o1! SEL
F00D14EC: 9610001b                 mov     %i3, %o3
F00D14F0: e0042004                 ld      [%l0+4], %l0
F00D14F4: 400080df                 call    _objc_msgSend
F00D14F8: 9807bfc8                 add     %fp, var_38, %o4
F00D14FC: 80a23d3e                 cmp     %o0, -0x2C2
F00D1500: 12bfffea                 bne     loc_F00D14A8
F00D1504: 80a44010                 cmp     %l1, %l0
F00D1508: 32bffff7                 bne,a   loc_F00D14E4
F00D150C: d0040000                 ld      [%l0], %o0
F00D1510: d0062170                 ld      [%i0+0x170], %o0! id
F00D1514: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D1518: 400080d6                 call    _objc_msgSend
F00D151C: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D1520: 80a4bd3e                 cmp     %l2, -0x2C2
F00D1524: 1280000f                 bne     loc_F00D1560
F00D1528: d007bfc8                 ld      [%fp+var_38], %o0
F00D152C: f027bff0                 st      %i0, [%fp+var_10]
F00D1530: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00D1534: 9410001a                 mov     %i2, %o2
F00D1538: 9610001b                 mov     %i3, %o3
F00D153C: 133c0508                 sethi   %hi(stru_F01421DC.super_class), %o1
F00D1540: da0261e0                 ld      [%o1+%lo(stru_F01421DC.super_class)], %o5
F00D1544: 9807bfc8                 add     %fp, var_38, %o4
F00D1548: 133c0504                 sethi   %hi(paGetintvaluesFo_0), %o1
F00D154C: d20262c8                 ld      [%o1+%lo(paGetintvaluesFo_0)], %o1! SEL
F00D1550: 4000810b                 call    _objc_msgSendSuper
F00D1554: da27bff4                 st      %o5, [%fp+var_C]
F00D1558: a4100008                 mov     %o0, %l2
F00D155C: d007bfc8                 ld      [%fp+var_38], %o0
F00D1560: d0270000                 st      %o0, [%i4]
F00D1564: 81c7e008                 ret
F00D1568: 91e80012                 restore %g0, %l2, %o0
