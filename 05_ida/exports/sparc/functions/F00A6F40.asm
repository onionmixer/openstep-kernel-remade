F00A6F40: 9de3bf08                 save    %sp, -0xF8, %sp
F00A6F44: ac102000                 mov     0, %l6
F00A6F48: 113c046c                 sethi   %hi(dword_F011B160), %o0
F00A6F4C: d2022160                 ld      [%o0+%lo(dword_F011B160)], %o1
F00A6F50: 153c04d4                 sethi   %hi(_rootfs), %o2
F00A6F54: 113c046c                 sethi   %hi(_boothowto), %o0
F00A6F58: d0022104                 ld      [%o0+%lo(_boothowto)], %o0
F00A6F5C: 808a2001                 btst    1, %o0
F00A6F60: 12800007                 bne     loc_F00A6F7C
F00A6F64: d222a2e0                 st      %o1, [%o2+%lo(_rootfs)]
F00A6F68: 113c04f8                 sethi   %hi(_rootdevice), %o0
F00A6F6C: d04a2138                 ldsb    [%o0+%lo(_rootdevice)], %o0
F00A6F70: 80a22000                 cmp     %o0, 0
F00A6F74: 028000a9                 be      loc_F00A7218
F00A6F78: 01000000                 nop
F00A6F7C: 113c046c                 sethi   %hi(_boothowto), %o0
F00A6F80: d0022104                 ld      [%o0+%lo(_boothowto)], %o0
F00A6F84: 808a2001                 btst    1, %o0
F00A6F88: 0280000b                 be      loc_F00A6FB4
F00A6F8C: 133c04f8                 sethi   -0xFEC2000, %o1
F00A6F90: 113c046c                 sethi   %hi(aRootDevice), %o0! "root device? "
F00A6F94: 7ffdb5b1                 call    _printf
F00A6F98: 90122168                 bset    %lo(aRootDevice), %o0! "root device? "
F00A6F9C: a007bf78                 add     %fp, var_88, %l0
F00A6FA0: 90100010                 mov     %l0, %o0! char *
F00A6FA4: 400000b1                 call    _gets
F00A6FA8: 92100010                 mov     %l0, %o1
F00A6FAC: 10800018                 ba      loc_F00A700C
F00A6FB0: 113c046c                 sethi   -0xFEE5000, %o0
F00A6FB4: d04a6138                 ldsb    [%o1+0x138], %o0
F00A6FB8: 80a22000                 cmp     %o0, 0
F00A6FBC: 02800004                 be      loc_F00A6FCC
F00A6FC0: 90126138                 or      %o1, 0x138, %o0
F00A6FC4: 10800011                 ba      loc_F00A7008
F00A6FC8: a0100008                 mov     %o0, %l0
F00A6FCC: 7fffffa4                 call    _getDefaultRoot
F00A6FD0: 01000000                 nop
F00A6FD4: a0920000                 orcc    %o0, %g0, %l0
F00A6FD8: 1280000d                 bne     loc_F00A700C
F00A6FDC: 113c046c                 sethi   -0xFEE5000, %o0
F00A6FE0: 400000e8                 call    sub_F00A7380
F00A6FE4: 01000000                 nop
F00A6FE8: 80a22000                 cmp     %o0, 0
F00A6FEC: 22800005                 be,a    loc_F00A7000
F00A6FF0: 113c046c                 sethi   -0xFEE5000, %o0
F00A6FF4: 113c046c                 sethi   %hi(aNoScsiDriveAtD), %o0! "No SCSI drive at default boot target %d"...
F00A6FF8: 10800094                 ba      loc_F00A7248
F00A6FFC: 90122178                 bset    %lo(aNoScsiDriveAtD), %o0! "No SCSI drive at default boot target %d"...
F00A7000: 10800041                 ba      loc_F00A7104
F00A7004: 901221a8                 bset    0x1A8, %o0
F00A7008: 113c046c                 sethi   -0xFEE5000, %o0
F00A700C: 901221c8                 bset    0x1C8, %o0! char *
F00A7010: 7ffdb592                 call    _printf
F00A7014: 92100010                 mov     %l0, %o1
F00A7018: 153c04c5                 sethi   %hi(dword_F0131560), %o2
F00A701C: 113c046c92122108         set     off_F011B108, %o1
F00A7024: d0022108                 ld      [%o0+0x108], %o0
F00A7028: 80a22000                 cmp     %o0, 0
F00A702C: 02800039                 be      loc_F00A7110
F00A7030: d222a160                 st      %o1, [%o2+%lo(dword_F0131560)]
F00A7034: 9810000a                 mov     %o2, %o4
F00A7038: d4032160                 ld      [%o4+0x160], %o2
F00A703C: d04c0000                 ldsb    [%l0], %o0
F00A7040: d6028000                 ld      [%o2], %o3
F00A7044: d24ac000                 ldsb    [%o3], %o1
F00A7048: 80a24008                 cmp     %o1, %o0
F00A704C: 12800007                 bne     loc_F00A7068
F00A7050: 9002a008                 add     %o2, 8, %o0
F00A7054: d24ae001                 ldsb    [%o3+1], %o1
F00A7058: d04c2001                 ldsb    [%l0+1], %o0
F00A705C: 80a24008                 cmp     %o1, %o0
F00A7060: 02800008                 be      loc_F00A7080
F00A7064: 9002a008                 add     %o2, 8, %o0
F00A7068: d202a008                 ld      [%o2+8], %o1
F00A706C: 80a26000                 cmp     %o1, 0
F00A7070: 12bffff2                 bne     loc_F00A7038
F00A7074: d0232160                 st      %o0, [%o4+0x160]
F00A7078: 10800026                 ba      loc_F00A7110
F00A707C: 153c04c5                 sethi   -0xFECEC00, %o2
F00A7080: d052a004                 ldsh    [%o2+4], %o0
F00A7084: 80a23fff                 cmp     %o0, -1
F00A7088: 0280004d                 be      loc_F00A71BC
F00A708C: 113c04c5                 sethi   -0xFECEC00, %o0
F00A7090: d04c2003                 ldsb    [%l0+3], %o0
F00A7094: 80a2202a                 cmp     %o0, 0x2A ! '*'
F00A7098: 32800005                 bne,a   loc_F00A70AC
F00A709C: d00c2002                 ldub    [%l0+2], %o0
F00A70A0: d00c2004                 ldub    [%l0+4], %o0
F00A70A4: d02c2003                 stb     %o0, [%l0+3]
F00A70A8: d00c2002                 ldub    [%l0+2], %o0
F00A70AC: 90023fd0                 inc     -0x30, %o0
F00A70B0: 900a20ff                 and     %o0, 0xFF, %o0
F00A70B4: 80a22007                 cmp     %o0, 7
F00A70B8: 18800012                 bgu     loc_F00A7100
F00A70BC: 113c046c                 sethi   -0xFEE5000, %o0
F00A70C0: d20c2003                 ldub    [%l0+3], %o1
F00A70C4: 90027f9f                 add     %o1, -0x61, %o0
F00A70C8: 900a20ff                 and     %o0, 0xFF, %o0
F00A70CC: 80a22007                 cmp     %o0, 7
F00A70D0: 08800006                 bleu    loc_F00A70E8
F00A70D4: 80a26000                 cmp     %o1, 0
F00A70D8: 02800007                 be      loc_F00A70F4
F00A70DC: 113c046c                 sethi   %hi(aBadPartitionNu), %o0! "bad partition number\n"
F00A70E0: 10800009                 ba      loc_F00A7104
F00A70E4: 901221d8                 bset    %lo(aBadPartitionNu), %o0! "bad partition number\n"
F00A70E8: 912a6018                 sll     %o1, 24, %o0
F00A70EC: 913a2018                 sra     %o0, 24, %o0
F00A70F0: ac023f9f                 add     %o0, -0x61, %l6
F00A70F4: d04c2002                 ldsb    [%l0+2], %o0
F00A70F8: 10800030                 ba      loc_F00A71B8
F00A70FC: b0023fd0                 add     %o0, -0x30, %i0
F00A7100: 901221f0                 bset    0x1F0, %o0! char *
F00A7104: 7ffdb555                 call    _printf
F00A7108: 01000000                 nop
F00A710C: 153c04c5                 sethi   -0xFECEC00, %o2
F00A7110: 113c046c92122108         set     off_F011B108, %o1
F00A7118: d0022108                 ld      [%o0+0x108], %o0
F00A711C: 80a22000                 cmp     %o0, 0
F00A7120: 0280001e                 be      loc_F00A7198
F00A7124: d222a160                 st      %o1, [%o2+0x160]
F00A7128: 113c046caa122210         set     aSSD, %l5! "%s%s%%d"
F00A7130: a8100009                 mov     %o1, %l4
F00A7134: 273c046c                 sethi   -0xFEE5000, %l3
F00A7138: 253c046c                 sethi   -0xFEE5000, %l2
F00A713C: 233c046c                 sethi   -0xFEE5000, %l1
F00A7140: a010000a                 mov     %o2, %l0
F00A7144: d002a160                 ld      [%o2+0x160], %o0
F00A7148: 80a20014                 cmp     %o0, %l4
F00A714C: 02800007                 be      loc_F00A7168
F00A7150: 96146228                 or      %l1, 0x228, %o3
F00A7154: d0022008                 ld      [%o0+8], %o0
F00A7158: 80a22000                 cmp     %o0, 0
F00A715C: 12800003                 bne     loc_F00A7168
F00A7160: 9614e218                 or      %l3, 0x218, %o3
F00A7164: 9614a220                 or      %l2, 0x220, %o3
F00A7168: d2042160                 ld      [%l0+0x160], %o1
F00A716C: d4024000                 ld      [%o1], %o2
F00A7170: 90100015                 mov     %l5, %o0! char *
F00A7174: 7ffdb539                 call    _printf
F00A7178: 9210000b                 mov     %o3, %o1
F00A717C: d0042160                 ld      [%l0+0x160], %o0
F00A7180: 94100010                 mov     %l0, %o2
F00A7184: 92022008                 add     %o0, 8, %o1
F00A7188: d0022008                 ld      [%o0+8], %o0
F00A718C: 80a22000                 cmp     %o0, 0
F00A7190: 12bfffed                 bne     loc_F00A7144
F00A7194: d2242160                 st      %o1, [%l0+0x160]
F00A7198: 113c046c                 sethi   %hi(asc_F011B230), %o0! char *
F00A719C: 7ffdb52f                 call    _printf
F00A71A0: 90122230                 bset    %lo(asc_F011B230), %o0! "\n"
F00A71A4: 133c046c                 sethi   %hi(_boothowto), %o1
F00A71A8: d0026104                 ld      [%o1+%lo(_boothowto)], %o0
F00A71AC: 90122001                 bset    1, %o0
F00A71B0: 10bfff73                 ba      loc_F00A6F7C
F00A71B4: d0226104                 st      %o0, [%o1+%lo(_boothowto)]
F00A71B8: 113c04c5                 sethi   -0xFECEC00, %o0
F00A71BC: d4022160                 ld      [%o0+0x160], %o2
F00A71C0: d052a004                 ldsh    [%o2+4], %o0
F00A71C4: 80a23fff                 cmp     %o0, -1
F00A71C8: 12800007                 bne     loc_F00A71E4
F00A71CC: 113c046c                 sethi   -0xFEE5000, %o0
F00A71D0: 113c046c                 sethi   %hi(dword_F011B238), %o0
F00A71D4: d2022238                 ld      [%o0+%lo(dword_F011B238)], %o1
F00A71D8: 113c04d4                 sethi   %hi(_rootfs), %o0
F00A71DC: 10800021                 ba      locret_F00A7260
F00A71E0: d22222e0                 st      %o1, [%o0+%lo(_rootfs)]
F00A71E4: d2022240                 ld      [%o0+0x240], %o1
F00A71E8: 113c04d4                 sethi   %hi(_rootfs), %o0
F00A71EC: d22222e0                 st      %o1, [%o0+%lo(_rootfs)]
F00A71F0: 912e2003                 sll     %i0, 3, %o0
F00A71F4: d212a004                 lduh    [%o2+4], %o1
F00A71F8: 90020016                 add     %o0, %l6, %o0
F00A71FC: 93326008                 srl     %o1, 8, %o1
F00A7200: 932a6008                 sll     %o1, 8, %o1
F00A7204: 92124008                 bset    %o0, %o1
F00A7208: d232a004                 sth     %o1, [%o2+4]
F00A720C: 113c04d2                 sethi   %hi(_rootdev), %o0
F00A7210: 10800014                 ba      locret_F00A7260
F00A7214: d23221c8                 sth     %o1, [%o0+%lo(_rootdev)]
F00A7218: 7fffff11                 call    _getDefaultRoot
F00A721C: 01000000                 nop
F00A7220: a0920000                 orcc    %o0, %g0, %l0
F00A7224: 12bfff7a                 bne     loc_F00A700C
F00A7228: 113c046c                 sethi   -0xFEE5000, %o0
F00A722C: 40000055                 call    sub_F00A7380
F00A7230: 01000000                 nop
F00A7234: 80a22000                 cmp     %o0, 0
F00A7238: 02800008                 be      loc_F00A7258
F00A723C: 113c046c                 sethi   -0xFEE5000, %o0
F00A7240: 113c046c90122248         set     aNoScsiDriveAtD_0, %o0! "No SCSI drive at default boot target %d"...
F00A7248: 7ffdb504                 call    _printf
F00A724C: 920de0ff                 and     %l7, 0xFF, %o1
F00A7250: 10bfffb0                 ba      loc_F00A7110
F00A7254: 153c04c5                 sethi   -0xFECEC00, %o2
F00A7258: 10bfffab                 ba      loc_F00A7104
F00A725C: 90122278                 bset    0x278, %o0
F00A7260: 81c7e008                 ret
F00A7264: 81e80000                 restore
