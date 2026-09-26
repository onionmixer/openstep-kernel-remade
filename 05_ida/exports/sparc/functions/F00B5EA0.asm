F00B5EA0: 9de3bf98                 save    %sp, -0x68, %sp
F00B5EA4: a0100018                 mov     %i0, %l0
F00B5EA8: d05420b2                 ldsh    [%l0+0xB2], %o0
F00B5EAC: 912a2002                 sll     %o0, 2, %o0
F00B5EB0: 90020010                 add     %o0, %l0, %o0
F00B5EB4: e60220b8                 ld      [%o0+0xB8], %l3
F00B5EB8: d00c2042                 ldub    [%l0+0x42], %o0
F00B5EBC: b0102000                 mov     0, %i0
F00B5EC0: 80a2200b                 cmp     %o0, 0xB
F00B5EC4: 02800042                 be      loc_F00B5FCC
F00B5EC8: e404209c                 ld      [%l0+0x9C], %l2
F00B5ECC: d00c2044                 ldub    [%l0+0x44], %o0
F00B5ED0: 808a2020                 btst    0x20, %o0 ! ' '
F00B5ED4: 0280000c                 be      loc_F00B5F04
F00B5ED8: 90100010                 mov     %l0, %o0
F00B5EDC: 92102003                 mov     3, %o1
F00B5EE0: 153c0479                 sethi   %hi(aPrematureEndOf_0), %o2! "premature end of input message"
F00B5EE4: 40000742                 call    _esplog
F00B5EE8: 9412a398                 bset    %lo(aPrematureEndOf_0), %o2! "premature end of input message"
F00B5EEC: d00c2041                 ldub    [%l0+0x41], %o0
F00B5EF0: b0102002                 mov     2, %i0
F00B5EF4: d02c2042                 stb     %o0, [%l0+0x42]
F00B5EF8: 9010201a                 mov     0x1A, %o0
F00B5EFC: 10800086                 ba      locret_F00B6114
F00B5F00: d02c2041                 stb     %o0, [%l0+0x41]
F00B5F04: d00c205c                 ldub    [%l0+0x5C], %o0
F00B5F08: 80a22000                 cmp     %o0, 0
F00B5F0C: 22800012                 be,a    loc_F00B5F54
F00B5F10: d00ca01c                 ldub    [%l2+0x1C], %o0
F00B5F14: d00c2043                 ldub    [%l0+0x43], %o0
F00B5F18: 808a2020                 btst    0x20, %o0 ! ' '
F00B5F1C: 0280000d                 be      loc_F00B5F50
F00B5F20: 133c0478                 sethi   %hi(_msginperr), %o1
F00B5F24: d4026278                 ld      [%o1+%lo(_msginperr)], %o2
F00B5F28: 90100010                 mov     %l0, %o0
F00B5F2C: 40000730                 call    _esplog
F00B5F30: 92102003                 mov     3, %o1
F00B5F34: d00ce02a                 ldub    [%l3+0x2A], %o0
F00B5F38: b0102009                 mov     9, %i0
F00B5F3C: 90122004                 bset    4, %o0
F00B5F40: d02ce02a                 stb     %o0, [%l3+0x2A]
F00B5F44: 90102001                 mov     1, %o0
F00B5F48: 10800022                 ba      loc_F00B5FD0
F00B5F4C: d02ca00c                 stb     %o0, [%l2+0xC]
F00B5F50: d00ca01c                 ldub    [%l2+0x1C], %o0
F00B5F54: 900a201f                 and     %o0, 0x1F, %o0
F00B5F58: 80a22001                 cmp     %o0, 1
F00B5F5C: 0280000c                 be      loc_F00B5F8C
F00B5F60: a2100008                 mov     %o0, %l1
F00B5F64: b0102005                 mov     5, %i0
F00B5F68: 90102001                 mov     1, %o0
F00B5F6C: d02ca00c                 stb     %o0, [%l2+0xC]
F00B5F70: 90100010                 mov     %l0, %o0
F00B5F74: 92102003                 mov     3, %o1
F00B5F78: 153c0479                 sethi   %hi(aInputMessageBo), %o2! "input message botch"
F00B5F7C: 4000071c                 call    _esplog
F00B5F80: 9412a3b8                 bset    %lo(aInputMessageBo), %o2! "input message botch"
F00B5F84: 10800014                 ba      loc_F00B5FD4
F00B5F88: 80a62000                 cmp     %i0, 0
F00B5F8C: d00c205c                 ldub    [%l0+0x5C], %o0
F00B5F90: 80a22000                 cmp     %o0, 0
F00B5F94: 32800008                 bne,a   loc_F00B5FB4
F00B5F98: d00c205d                 ldub    [%l0+0x5D], %o0
F00B5F9C: d00c2041                 ldub    [%l0+0x41], %o0
F00B5FA0: e20ca008                 ldub    [%l2+8], %l1
F00B5FA4: d02c2042                 stb     %o0, [%l0+0x42]
F00B5FA8: 90102006                 mov     6, %o0
F00B5FAC: 10800009                 ba      loc_F00B5FD0
F00B5FB0: d02c2041                 stb     %o0, [%l0+0x41]
F00B5FB4: 92022001                 add     %o0, 1, %o1
F00B5FB8: d22c205d                 stb     %o1, [%l0+0x5D]
F00B5FBC: e20ca008                 ldub    [%l2+8], %l1
F00B5FC0: 90020010                 add     %o0, %l0, %o0
F00B5FC4: 10800003                 ba      loc_F00B5FD0
F00B5FC8: e22a2054                 stb     %l1, [%o0+0x54]
F00B5FCC: e20c2054                 ldub    [%l0+0x54], %l1
F00B5FD0: 80a62000                 cmp     %i0, 0
F00B5FD4: 12800036                 bne     loc_F00B60AC
F00B5FD8: 80a62000                 cmp     %i0, 0
F00B5FDC: d20c205c                 ldub    [%l0+0x5C], %o1
F00B5FE0: 80a26000                 cmp     %o1, 0
F00B5FE4: 02800032                 be      loc_F00B60AC
F00B5FE8: 80a62000                 cmp     %i0, 0
F00B5FEC: d00c205d                 ldub    [%l0+0x5D], %o0
F00B5FF0: 80a20009                 cmp     %o0, %o1
F00B5FF4: 1a800007                 bcc     loc_F00B6010
F00B5FF8: 80a26001                 cmp     %o1, 1
F00B5FFC: d00c2041                 ldub    [%l0+0x41], %o0
F00B6000: d02c2042                 stb     %o0, [%l0+0x42]
F00B6004: 90102006                 mov     6, %o0
F00B6008: 10800028                 ba      loc_F00B60A8
F00B600C: d02c2041                 stb     %o0, [%l0+0x41]
F00B6010: 12800006                 bne     loc_F00B6028
F00B6014: 80a26002                 cmp     %o1, 2
F00B6018: 40000041                 call    _esp_onebyte_msg
F00B601C: 90100010                 mov     %l0, %o0
F00B6020: 10800022                 ba      loc_F00B60A8
F00B6024: b0100008                 mov     %o0, %i0
F00B6028: 1280001d                 bne     loc_F00B609C
F00B602C: 01000000                 nop
F00B6030: d00c2054                 ldub    [%l0+0x54], %o0
F00B6034: 80a22001                 cmp     %o0, 1
F00B6038: 12800015                 bne     loc_F00B608C
F00B603C: 900c60ff                 and     %l1, 0xFF, %o0
F00B6040: 90022002                 inc     2, %o0
F00B6044: 80a22008                 cmp     %o0, 8
F00B6048: 0480000a                 ble     loc_F00B6070
F00B604C: 90100010                 mov     %l0, %o0
F00B6050: 92102003                 mov     3, %o1
F00B6054: 153c0479                 sethi   %hi(off_F011E7F4), %o2! "Extended message 0x%x is too long"
F00B6058: d402a3f4                 ld      [%o2+%lo(off_F011E7F4)], %o2! "Extended message 0x%x is too long"
F00B605C: b0102007                 mov     7, %i0
F00B6060: 400006e3                 call    _esplog
F00B6064: 96102001                 mov     1, %o3
F00B6068: 10800011                 ba      loc_F00B60AC
F00B606C: 80a62000                 cmp     %i0, 0
F00B6070: 90046002                 add     %l1, 2, %o0
F00B6074: d20c2041                 ldub    [%l0+0x41], %o1
F00B6078: d02c205c                 stb     %o0, [%l0+0x5C]
F00B607C: 90102006                 mov     6, %o0
F00B6080: d22c2042                 stb     %o1, [%l0+0x42]
F00B6084: 10800009                 ba      loc_F00B60A8
F00B6088: d02c2041                 stb     %o0, [%l0+0x41]
F00B608C: 400000dd                 call    _esp_twobyte_msg
F00B6090: 90100010                 mov     %l0, %o0
F00B6094: 10800005                 ba      loc_F00B60A8
F00B6098: b0100008                 mov     %o0, %i0
F00B609C: 400000e6                 call    _esp_multibyte_msg
F00B60A0: 90100010                 mov     %l0, %o0
F00B60A4: b0100008                 mov     %o0, %i0
F00B60A8: 80a62000                 cmp     %i0, 0
F00B60AC: 16800004                 bge     loc_F00B60BC
F00B60B0: 80a62000                 cmp     %i0, 0
F00B60B4: 10800018                 ba      locret_F00B6114
F00B60B8: b0200018                 neg     %i0
F00B60BC: 04800013                 ble     loc_F00B6108
F00B60C0: 80a62001                 cmp     %i0, 1
F00B60C4: 02800009                 be      loc_F00B60E8
F00B60C8: 808e20f0                 btst    0xF0, %i0
F00B60CC: 02800005                 be      loc_F00B60E0
F00B60D0: 900e2098                 and     %i0, 0x98, %o0
F00B60D4: 80a22080                 cmp     %o0, 0x80
F00B60D8: 32800005                 bne,a   loc_F00B60EC
F00B60DC: f02c204c                 stb     %i0, [%l0+0x4C]
F00B60E0: 90102001                 mov     1, %o0
F00B60E4: d02c2053                 stb     %o0, [%l0+0x53]
F00B60E8: f02c204c                 stb     %i0, [%l0+0x4C]
F00B60EC: 9010201a                 mov     0x1A, %o0
F00B60F0: d02ca00c                 stb     %o0, [%l2+0xC]
F00B60F4: d00c2041                 ldub    [%l0+0x41], %o0
F00B60F8: c02c205c                 clrb    [%l0+0x5C]
F00B60FC: d02c2042                 stb     %o0, [%l0+0x42]
F00B6100: 90102006                 mov     6, %o0
F00B6104: d02c2041                 stb     %o0, [%l0+0x41]
F00B6108: 90102012                 mov     0x12, %o0
F00B610C: d02ca00c                 stb     %o0, [%l2+0xC]
F00B6110: b0103fff                 mov     -1, %i0
F00B6114: 81c7e008                 ret
F00B6118: 81e80000                 restore
