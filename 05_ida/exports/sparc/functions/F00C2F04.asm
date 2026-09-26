F00C2F04: 9de3bf98                 save    %sp, -0x68, %sp
F00C2F08: a2100018                 mov     %i0, %l1
F00C2F0C: ac102000                 mov     0, %l6
F00C2F10: a6102000                 mov     0, %l3
F00C2F14: e04c4000                 ldsb    [%l1], %l0
F00C2F18: 94102000                 mov     0, %o2
F00C2F1C: 92100010                 mov     %l0, %o1
F00C2F20: 80a26020                 cmp     %o1, 0x20 ! ' '
F00C2F24: 02800009                 be      loc_F00C2F48
F00C2F28: a2046001                 inc     %l1
F00C2F2C: 90043ff7                 add     %l0, -9, %o0
F00C2F30: 900a20ff                 and     %o0, 0xFF, %o0
F00C2F34: 80a22001                 cmp     %o0, 1
F00C2F38: 08800004                 bleu    loc_F00C2F48
F00C2F3C: 80a2600a                 cmp     %o1, 0xA
F00C2F40: 12800004                 bne     loc_F00C2F50
F00C2F44: 80a2a000                 cmp     %o2, 0
F00C2F48: 94102001                 mov     1, %o2
F00C2F4C: 80a2a000                 cmp     %o2, 0
F00C2F50: 32bffff2                 bne,a   loc_F00C2F18
F00C2F54: e04c4000                 ldsb    [%l1], %l0
F00C2F58: 80a4202d                 cmp     %l0, 0x2D ! '-'
F00C2F5C: 12800005                 bne     loc_F00C2F70
F00C2F60: 80a4202b                 cmp     %l0, 0x2B ! '+'
F00C2F64: e04c4000                 ldsb    [%l1], %l0
F00C2F68: 10800005                 ba      loc_F00C2F7C
F00C2F6C: ac102001                 mov     1, %l6
F00C2F70: 12800005                 bne     loc_F00C2F84
F00C2F74: 80a42030                 cmp     %l0, 0x30 ! '0'
F00C2F78: e04c4000                 ldsb    [%l1], %l0
F00C2F7C: a2046001                 inc     %l1
F00C2F80: 80a42030                 cmp     %l0, 0x30 ! '0'
F00C2F84: 1280000c                 bne     loc_F00C2FB4
F00C2F88: 80a4e000                 cmp     %l3, 0
F00C2F8C: d04c4000                 ldsb    [%l1], %o0
F00C2F90: 80a22078                 cmp     %o0, 0x78 ! 'x'
F00C2F94: 02800004                 be      loc_F00C2FA4
F00C2F98: 80a22058                 cmp     %o0, 0x58 ! 'X'
F00C2F9C: 12800006                 bne     loc_F00C2FB4
F00C2FA0: 80a4e000                 cmp     %l3, 0
F00C2FA4: e04c6001                 ldsb    [%l1+1], %l0
F00C2FA8: a6102010                 mov     0x10, %l3
F00C2FAC: a2046002                 inc     2, %l1
F00C2FB0: 80a4e000                 cmp     %l3, 0
F00C2FB4: 32800007                 bne,a   loc_F00C2FD0
F00C2FB8: 90103fff                 mov     -1, %o0
F00C2FBC: 80a42030                 cmp     %l0, 0x30 ! '0'
F00C2FC0: 12800003                 bne     loc_F00C2FCC
F00C2FC4: a610200a                 mov     0xA, %l3
F00C2FC8: a6102008                 mov     8, %l3
F00C2FCC: 90103fff                 mov     -1, %o0
F00C2FD0: 7ffd0d8c                 call    _udiv
F00C2FD4: 92100013                 mov     %l3, %o1
F00C2FD8: a8100008                 mov     %o0, %l4
F00C2FDC: 90103fff                 mov     -1, %o0
F00C2FE0: 7ffd0e30                 call    _urem
F00C2FE4: 92100013                 mov     %l3, %o1
F00C2FE8: aa100008                 mov     %o0, %l5
F00C2FEC: 94102000                 mov     0, %o2
F00C2FF0: a4102000                 mov     0, %l2
F00C2FF4: 92043fd0                 add     %l0, -0x30, %o1
F00C2FF8: 900a60ff                 and     %o1, 0xFF, %o0
F00C2FFC: 80a22009                 cmp     %o0, 9
F00C3000: 18800004                 bgu     loc_F00C3010
F00C3004: 90043fbf                 add     %l0, -0x41, %o0
F00C3008: 10800015                 ba      loc_F00C305C
F00C300C: a0100009                 mov     %o1, %l0
F00C3010: 900a20ff                 and     %o0, 0xFF, %o0
F00C3014: 80a22019                 cmp     %o0, 0x19
F00C3018: 08800007                 bleu    loc_F00C3034
F00C301C: 92102000                 mov     0, %o1
F00C3020: 90043f9f                 add     %l0, -0x61, %o0
F00C3024: 900a20ff                 and     %o0, 0xFF, %o0
F00C3028: 80a22019                 cmp     %o0, 0x19
F00C302C: 18800004                 bgu     loc_F00C303C
F00C3030: 80a26000                 cmp     %o1, 0
F00C3034: 92102001                 mov     1, %o1
F00C3038: 80a26000                 cmp     %o1, 0
F00C303C: 0280001e                 be      loc_F00C30B4
F00C3040: 90043fbf                 add     %l0, -0x41, %o0
F00C3044: 900a20ff                 and     %o0, 0xFF, %o0
F00C3048: 80a22019                 cmp     %o0, 0x19
F00C304C: 08800003                 bleu    loc_F00C3058
F00C3050: 90043fc9                 add     %l0, -0x37, %o0
F00C3054: 90043fa9                 add     %l0, -0x57, %o0
F00C3058: a0100008                 mov     %o0, %l0
F00C305C: 80a40013                 cmp     %l0, %l3
F00C3060: 16800015                 bge     loc_F00C30B4
F00C3064: 80a4a000                 cmp     %l2, 0
F00C3068: 06800009                 bl      loc_F00C308C
F00C306C: 80a28014                 cmp     %o2, %l4
F00C3070: 3880000e                 bgu,a   loc_F00C30A8
F00C3074: a4103fff                 mov     -1, %l2
F00C3078: 12800007                 bne     loc_F00C3094
F00C307C: a4102001                 mov     1, %l2
F00C3080: 80a40015                 cmp     %l0, %l5
F00C3084: 04800005                 ble     loc_F00C3098
F00C3088: 9010000a                 mov     %o2, %o0
F00C308C: 10800007                 ba      loc_F00C30A8
F00C3090: a4103fff                 mov     -1, %l2
F00C3094: 9010000a                 mov     %o2, %o0
F00C3098: 7ffd0d1a                 call    _umul
F00C309C: 92100013                 mov     %l3, %o1
F00C30A0: 94100008                 mov     %o0, %o2
F00C30A4: 94028010                 add     %o2, %l0, %o2
F00C30A8: e04c4000                 ldsb    [%l1], %l0
F00C30AC: 10bfffd2                 ba      loc_F00C2FF4
F00C30B0: a2046001                 inc     %l1
F00C30B4: 80a4a000                 cmp     %l2, 0
F00C30B8: 16800004                 bge     loc_F00C30C8
F00C30BC: 80a5a000                 cmp     %l6, 0
F00C30C0: 10800004                 ba      loc_F00C30D0
F00C30C4: 94103fff                 mov     -1, %o2
F00C30C8: 32800002                 bne,a   loc_F00C30D0
F00C30CC: 9420000a                 neg     %o2
F00C30D0: 80a66000                 cmp     %i1, 0
F00C30D4: 02800005                 be      loc_F00C30E8
F00C30D8: 80a4a000                 cmp     %l2, 0
F00C30DC: 32800002                 bne,a   loc_F00C30E4
F00C30E0: b0047fff                 add     %l1, -1, %i0
F00C30E4: f0264000                 st      %i0, [%i1]
F00C30E8: 80a6a000                 cmp     %i2, 0
F00C30EC: 32800002                 bne,a   loc_F00C30F4
F00C30F0: d4268000                 st      %o2, [%i2]
F00C30F4: 80a4a000                 cmp     %l2, 0
F00C30F8: 34800003                 bg,a    locret_F00C3104
F00C30FC: b0102001                 mov     1, %i0
F00C3100: b0102000                 mov     0, %i0
F00C3104: 81c7e008                 ret
F00C3108: 81e80000                 restore
