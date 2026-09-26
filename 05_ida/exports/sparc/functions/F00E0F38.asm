F00E0F38: 9de3bf98                 save    %sp, -0x68, %sp
F00E0F3C: d00e0000                 ldub    [%i0], %o0
F00E0F40: d02e4000                 stb     %o0, [%i1]
F00E0F44: d00e2001                 ldub    [%i0+1], %o0
F00E0F48: d02e6001                 stb     %o0, [%i1+1]
F00E0F4C: d00e2002                 ldub    [%i0+2], %o0
F00E0F50: d02e6002                 stb     %o0, [%i1+2]
F00E0F54: d00e2003                 ldub    [%i0+3], %o0
F00E0F58: d02e6003                 stb     %o0, [%i1+3]
F00E0F5C: d00e2004                 ldub    [%i0+4], %o0
F00E0F60: d02e6004                 stb     %o0, [%i1+4]
F00E0F64: d00e2005                 ldub    [%i0+5], %o0
F00E0F68: d02e6005                 stb     %o0, [%i1+5]
F00E0F6C: d00e2006                 ldub    [%i0+6], %o0
F00E0F70: d02e6006                 stb     %o0, [%i1+6]
F00E0F74: d00e2007                 ldub    [%i0+7], %o0
F00E0F78: d02e6007                 stb     %o0, [%i1+7]
F00E0F7C: d00e2008                 ldub    [%i0+8], %o0
F00E0F80: d02e6008                 stb     %o0, [%i1+8]
F00E0F84: d20e2009                 ldub    [%i0+9], %o1
F00E0F88: 9006200c                 add     %i0, 0xC, %o0! void *
F00E0F8C: d22e6009                 stb     %o1, [%i1+9]
F00E0F90: d40e200a                 ldub    [%i0+0xA], %o2
F00E0F94: 9206600c                 add     %i1, 0xC, %o1! void *
F00E0F98: d42e600a                 stb     %o2, [%i1+0xA]
F00E0F9C: d60e200b                 ldub    [%i0+0xB], %o3
F00E0FA0: 94102018                 mov     0x18, %o2! size_t
F00E0FA4: 7ffecedb                 call    _bcopy
F00E0FA8: d62e600b                 stb     %o3, [%i1+0xB]
F00E0FAC: d00e2024                 ldub    [%i0+0x24], %o0
F00E0FB0: d02e6024                 stb     %o0, [%i1+0x24]
F00E0FB4: d00e2025                 ldub    [%i0+0x25], %o0
F00E0FB8: d02e6025                 stb     %o0, [%i1+0x25]
F00E0FBC: d00e2026                 ldub    [%i0+0x26], %o0
F00E0FC0: d02e6026                 stb     %o0, [%i1+0x26]
F00E0FC4: d00e2027                 ldub    [%i0+0x27], %o0
F00E0FC8: ac06202c                 add     %i0, 0x2C, %l6 ! ','
F00E0FCC: d02e6027                 stb     %o0, [%i1+0x27]
F00E0FD0: d00e2028                 ldub    [%i0+0x28], %o0
F00E0FD4: aa06602c                 add     %i1, 0x2C, %l5 ! ','
F00E0FD8: d02e6028                 stb     %o0, [%i1+0x28]
F00E0FDC: d20e2029                 ldub    [%i0+0x29], %o1
F00E0FE0: 90100016                 mov     %l6, %o0! void *
F00E0FE4: d22e6029                 stb     %o1, [%i1+0x29]
F00E0FE8: d40e202a                 ldub    [%i0+0x2A], %o2
F00E0FEC: 92100015                 mov     %l5, %o1! void *
F00E0FF0: d42e602a                 stb     %o2, [%i1+0x2A]
F00E0FF4: d60e202b                 ldub    [%i0+0x2B], %o3
F00E0FF8: 94102018                 mov     0x18, %o2! size_t
F00E0FFC: 7ffecec5                 call    _bcopy
F00E1000: d62e602b                 stb     %o3, [%i1+0x2B]
F00E1004: 90062044                 add     %i0, 0x44, %o0 ! 'D'! void *
F00E1008: 92066044                 add     %i1, 0x44, %o1 ! 'D'! void *
F00E100C: 7ffecec1                 call    _bcopy
F00E1010: 94102018                 mov     0x18, %o2
F00E1014: d00e205c                 ldub    [%i0+0x5C], %o0
F00E1018: d02e605c                 stb     %o0, [%i1+0x5C]
F00E101C: d00e205d                 ldub    [%i0+0x5D], %o0
F00E1020: d02e605d                 stb     %o0, [%i1+0x5D]
F00E1024: d00e205e                 ldub    [%i0+0x5E], %o0
F00E1028: d02e605e                 stb     %o0, [%i1+0x5E]
F00E102C: d00e205f                 ldub    [%i0+0x5F], %o0
F00E1030: d02e605f                 stb     %o0, [%i1+0x5F]
F00E1034: d00e2060                 ldub    [%i0+0x60], %o0
F00E1038: d02e6060                 stb     %o0, [%i1+0x60]
F00E103C: d00e2061                 ldub    [%i0+0x61], %o0
F00E1040: d02e6061                 stb     %o0, [%i1+0x61]
F00E1044: d00e2062                 ldub    [%i0+0x62], %o0
F00E1048: d02e6062                 stb     %o0, [%i1+0x62]
F00E104C: d00e2063                 ldub    [%i0+0x63], %o0
F00E1050: d02e6063                 stb     %o0, [%i1+0x63]
F00E1054: d00e2064                 ldub    [%i0+0x64], %o0
F00E1058: d02e6064                 stb     %o0, [%i1+0x64]
F00E105C: d00e2065                 ldub    [%i0+0x65], %o0
F00E1060: d02e6065                 stb     %o0, [%i1+0x65]
F00E1064: d00e2066                 ldub    [%i0+0x66], %o0
F00E1068: d02e6066                 stb     %o0, [%i1+0x66]
F00E106C: d00e2067                 ldub    [%i0+0x67], %o0
F00E1070: d02e6067                 stb     %o0, [%i1+0x67]
F00E1074: d00e2068                 ldub    [%i0+0x68], %o0
F00E1078: d02e6068                 stb     %o0, [%i1+0x68]
F00E107C: d00e2069                 ldub    [%i0+0x69], %o0
F00E1080: d02e6069                 stb     %o0, [%i1+0x69]
F00E1084: d00e206a                 ldub    [%i0+0x6A], %o0
F00E1088: d02e606a                 stb     %o0, [%i1+0x6A]
F00E108C: d00e206b                 ldub    [%i0+0x6B], %o0
F00E1090: d02e606b                 stb     %o0, [%i1+0x6B]
F00E1094: d00e206c                 ldub    [%i0+0x6C], %o0
F00E1098: d02e606c                 stb     %o0, [%i1+0x6C]
F00E109C: d00e206d                 ldub    [%i0+0x6D], %o0
F00E10A0: d02e606d                 stb     %o0, [%i1+0x6D]
F00E10A4: d00e206e                 ldub    [%i0+0x6E], %o0
F00E10A8: d02e606e                 stb     %o0, [%i1+0x6E]
F00E10AC: d00e206f                 ldub    [%i0+0x6F], %o0
F00E10B0: d02e606f                 stb     %o0, [%i1+0x6F]
F00E10B4: d00e2070                 ldub    [%i0+0x70], %o0
F00E10B8: d02e6070                 stb     %o0, [%i1+0x70]
F00E10BC: d00e2071                 ldub    [%i0+0x71], %o0
F00E10C0: d02e6071                 stb     %o0, [%i1+0x71]
F00E10C4: d00e2072                 ldub    [%i0+0x72], %o0
F00E10C8: d02e6072                 stb     %o0, [%i1+0x72]
F00E10CC: d00e2073                 ldub    [%i0+0x73], %o0
F00E10D0: d02e6073                 stb     %o0, [%i1+0x73]
F00E10D4: d00e2074                 ldub    [%i0+0x74], %o0
F00E10D8: d02e6074                 stb     %o0, [%i1+0x74]
F00E10DC: d00e2075                 ldub    [%i0+0x75], %o0
F00E10E0: d02e6075                 stb     %o0, [%i1+0x75]
F00E10E4: d00e2076                 ldub    [%i0+0x76], %o0
F00E10E8: d02e6076                 stb     %o0, [%i1+0x76]
F00E10EC: d00e2077                 ldub    [%i0+0x77], %o0
F00E10F0: 9a06607c                 add     %i1, 0x7C, %o5 ! '|'
F00E10F4: d02e6077                 stb     %o0, [%i1+0x77]
F00E10F8: d00e2078                 ldub    [%i0+0x78], %o0
F00E10FC: 9806207c                 add     %i0, 0x7C, %o4 ! '|'
F00E1100: d02e6078                 stb     %o0, [%i1+0x78]
F00E1104: d00e2079                 ldub    [%i0+0x79], %o0
F00E1108: 96102000                 mov     0, %o3
F00E110C: d02e6079                 stb     %o0, [%i1+0x79]
F00E1110: d00e207a                 ldub    [%i0+0x7A], %o0
F00E1114: 9406607f                 add     %i1, 0x7F, %o2
F00E1118: d02e607a                 stb     %o0, [%i1+0x7A]
F00E111C: d00e207b                 ldub    [%i0+0x7B], %o0
F00E1120: 9206207f                 add     %i0, 0x7F, %o1
F00E1124: d02e607b                 stb     %o0, [%i1+0x7B]
F00E1128: d00b0000                 ldub    [%o4], %o0
F00E112C: 9602e001                 inc     %o3
F00E1130: d02b4000                 stb     %o0, [%o5]
F00E1134: d00a7ffe                 ldub    [%o1-2], %o0
F00E1138: 80a2e001                 cmp     %o3, 1
F00E113C: d02abffe                 stb     %o0, [%o2-2]
F00E1140: d00a7fff                 ldub    [%o1-1], %o0
F00E1144: 98032004                 inc     4, %o4
F00E1148: d02abfff                 stb     %o0, [%o2-1]
F00E114C: d00a4000                 ldub    [%o1], %o0
F00E1150: 9a036004                 inc     4, %o5
F00E1154: d02a8000                 stb     %o0, [%o2]
F00E1158: 92026004                 inc     4, %o1
F00E115C: 04bffff3                 ble     loc_F00E1128
F00E1160: 9402a004                 inc     4, %o2! size_t
F00E1164: 9005a058                 add     %l6, 0x58, %o0 ! 'X'! void *
F00E1168: 92056058                 add     %l5, 0x58, %o1 ! 'X'! void *
F00E116C: 7ffece69                 call    _bcopy
F00E1170: 94102018                 mov     0x18, %o2! size_t
F00E1174: 9005a070                 add     %l6, 0x70, %o0 ! 'p'! void *
F00E1178: 92056070                 add     %l5, 0x70, %o1 ! 'p'! void *
F00E117C: 7ffece65                 call    _bcopy
F00E1180: 94102020                 mov     0x20, %o2 ! ' '
F00E1184: a8102000                 mov     0, %l4
F00E1188: d00da090                 ldub    [%l6+0x90], %o0
F00E118C: a6102000                 mov     0, %l3
F00E1190: d02d6090                 stb     %o0, [%l5+0x90]
F00E1194: d00da091                 ldub    [%l6+0x91], %o0
F00E1198: a4102000                 mov     0, %l2
F00E119C: d02d6091                 stb     %o0, [%l5+0x91]
F00E11A0: a0048016                 add     %l2, %l6, %l0
F00E11A4: a0042094                 inc     0x94, %l0
F00E11A8: a204c015                 add     %l3, %l5, %l1
F00E11AC: d00c0000                 ldub    [%l0], %o0
F00E11B0: a2046092                 inc     0x92, %l1
F00E11B4: d02c4000                 stb     %o0, [%l1]
F00E11B8: d00c2001                 ldub    [%l0+1], %o0
F00E11BC: d02c6001                 stb     %o0, [%l1+1]
F00E11C0: d00c2002                 ldub    [%l0+2], %o0
F00E11C4: d02c6002                 stb     %o0, [%l1+2]
F00E11C8: d00c2003                 ldub    [%l0+3], %o0
F00E11CC: d02c6003                 stb     %o0, [%l1+3]
F00E11D0: d00c2004                 ldub    [%l0+4], %o0
F00E11D4: d02c6004                 stb     %o0, [%l1+4]
F00E11D8: d00c2005                 ldub    [%l0+5], %o0
F00E11DC: d02c6005                 stb     %o0, [%l1+5]
F00E11E0: d00c2006                 ldub    [%l0+6], %o0
F00E11E4: d02c6006                 stb     %o0, [%l1+6]
F00E11E8: d00c2007                 ldub    [%l0+7], %o0
F00E11EC: d02c6007                 stb     %o0, [%l1+7]
F00E11F0: d00c2008                 ldub    [%l0+8], %o0
F00E11F4: d02c6008                 stb     %o0, [%l1+8]
F00E11F8: d00c2009                 ldub    [%l0+9], %o0
F00E11FC: d02c6009                 stb     %o0, [%l1+9]
F00E1200: d00c200a                 ldub    [%l0+0xA], %o0
F00E1204: d02c600a                 stb     %o0, [%l1+0xA]
F00E1208: d00c200b                 ldub    [%l0+0xB], %o0
F00E120C: d02c600b                 stb     %o0, [%l1+0xB]
F00E1210: d00c200c                 ldub    [%l0+0xC], %o0
F00E1214: d02c600c                 stb     %o0, [%l1+0xC]
F00E1218: d20c200e                 ldub    [%l0+0xE], %o1
F00E121C: a604e02e                 inc     0x2E, %l3 ! '.'
F00E1220: d22c600e                 stb     %o1, [%l1+0xE]
F00E1224: d40c200f                 ldub    [%l0+0xF], %o2
F00E1228: a404a030                 inc     0x30, %l2 ! '0'
F00E122C: d42c600f                 stb     %o2, [%l1+0xF]
F00E1230: d60c2010                 ldub    [%l0+0x10], %o3
F00E1234: a8052001                 inc     %l4
F00E1238: d62c6010                 stb     %o3, [%l1+0x10]
F00E123C: d60c2011                 ldub    [%l0+0x11], %o3
F00E1240: 90042014                 add     %l0, 0x14, %o0! void *
F00E1244: d62c6011                 stb     %o3, [%l1+0x11]
F00E1248: d60c2012                 ldub    [%l0+0x12], %o3
F00E124C: 92046014                 add     %l1, 0x14, %o1! void *
F00E1250: d62c6012                 stb     %o3, [%l1+0x12]
F00E1254: d60c2013                 ldub    [%l0+0x13], %o3
F00E1258: 94102010                 mov     0x10, %o2! size_t
F00E125C: 7ffece2d                 call    _bcopy
F00E1260: d62c6013                 stb     %o3, [%l1+0x13]
F00E1264: 90042025                 add     %l0, 0x25, %o0 ! '%'! void *
F00E1268: 92046025                 add     %l1, 0x25, %o1 ! '%'! void *
F00E126C: d60c2024                 ldub    [%l0+0x24], %o3
F00E1270: 94102008                 mov     8, %o2! size_t
F00E1274: 7ffece27                 call    _bcopy
F00E1278: d62c6024                 stb     %o3, [%l1+0x24]
F00E127C: 80a52007                 cmp     %l4, 7
F00E1280: 04bfffc9                 ble     loc_F00E11A4
F00E1284: a0048016                 add     %l2, %l6, %l0
F00E1288: 9806622e                 add     %i1, 0x22E, %o4
F00E128C: 96102000                 mov     0, %o3
F00E1290: 92062240                 add     %i0, 0x240, %o1
F00E1294: 94066231                 add     %i1, 0x231, %o2
F00E1298: d00a4000                 ldub    [%o1], %o0
F00E129C: d02b0000                 stb     %o0, [%o4]
F00E12A0: d00a6001                 ldub    [%o1+1], %o0
F00E12A4: 9602e001                 inc     %o3
F00E12A8: d02abffe                 stb     %o0, [%o2-2]
F00E12AC: d00a6002                 ldub    [%o1+2], %o0
F00E12B0: 80a2e685                 cmp     %o3, 0x685
F00E12B4: d02abfff                 stb     %o0, [%o2-1]
F00E12B8: d00a6003                 ldub    [%o1+3], %o0
F00E12BC: 98032004                 inc     4, %o4
F00E12C0: d02a8000                 stb     %o0, [%o2]
F00E12C4: 9402a004                 inc     4, %o2
F00E12C8: 04bffff4                 ble     loc_F00E1298
F00E12CC: 92026004                 inc     4, %o1
F00E12D0: 1100000790122058         set     0x1C58, %o0
F00E12D8: 13000007                 sethi   0x1C00, %o1
F00E12DC: d40e0008                 ldub    [%i0+%o0], %o2
F00E12E0: 92126046                 bset    0x46, %o1 ! 'F'
F00E12E4: d42e4009                 stb     %o2, [%i1+%o1]
F00E12E8: 90060008                 add     %i0, %o0, %o0
F00E12EC: d00a2001                 ldub    [%o0+1], %o0
F00E12F0: 92064009                 add     %i1, %o1, %o1
F00E12F4: d02a6001                 stb     %o0, [%o1+1]
F00E12F8: d00e2240                 ldub    [%i0+0x240], %o0
F00E12FC: d02e622e                 stb     %o0, [%i1+0x22E]
F00E1300: d00e2241                 ldub    [%i0+0x241], %o0
F00E1304: d02e622f                 stb     %o0, [%i1+0x22F]
F00E1308: 81c7e008                 ret
F00E130C: 81e80000                 restore
