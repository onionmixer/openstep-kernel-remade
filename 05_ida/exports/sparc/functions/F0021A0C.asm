F0021A0C: 9de3bf00                 save    %sp, -0x100, %sp! int
F0021A10: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F0021A14: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F0021A18: e0022024                 ld      [%o0+0x24], %l0
F0021A1C: 9207bfe0                 add     %fp, var_20, %o1! int
F0021A20: d0042004                 ld      [%l0+4], %o0! int
F0021A24: 4001d98d                 call    _copyin
F0021A28: 94102018                 mov     0x18, %o2
F0021A2C: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F0021A30: d02a6038                 stb     %o0, [%o1+0x38]
F0021A34: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F0021A38: d04a6038                 ldsb    [%o1+0x38], %o0
F0021A3C: 80a22000                 cmp     %o0, 0
F0021A40: 12800027                 bne     locret_F0021ADC
F0021A44: d407bfec                 ld      [%fp+var_14], %o2! int
F0021A48: 80a2a00f                 cmp     %o2, 0xF
F0021A4C: 08800004                 bleu    loc_F0021A5C
F0021A50: 90102028                 mov     0x28, %o0 ! '('
F0021A54: 10800022                 ba      locret_F0021ADC
F0021A58: d02a6038                 stb     %o0, [%o1+0x38]
F0021A5C: a207bf60                 add     %fp, var_A0, %l1
F0021A60: 92100011                 mov     %l1, %o1! int
F0021A64: d007bfe8                 ld      [%fp+var_18], %o0! int
F0021A68: 4001d97c                 call    _copyin
F0021A6C: 952aa003                 sll     %o2, 3, %o2
F0021A70: d204a1dc                 ld      [%l2+0x1DC], %o1
F0021A74: d02a6038                 stb     %o0, [%o1+0x38]
F0021A78: d004a1dc                 ld      [%l2+0x1DC], %o0
F0021A7C: d04a2038                 ldsb    [%o0+0x38], %o0
F0021A80: 80a22000                 cmp     %o0, 0
F0021A84: 12800016                 bne     locret_F0021ADC
F0021A88: d007bff0                 ld      [%fp+var_10], %o0
F0021A8C: 80a22000                 cmp     %o0, 0
F0021A90: 0280000c                 be      loc_F0021AC0
F0021A94: e227bfe8                 st      %l1, [%fp+var_18]
F0021A98: d207bff4                 ld      [%fp+var_C], %o1
F0021A9C: 4001a0cb                 call    _useracc
F0021AA0: 94102000                 mov     0, %o2
F0021AA4: 80a22000                 cmp     %o0, 0
F0021AA8: 32800007                 bne,a   loc_F0021AC4
F0021AAC: d0040000                 ld      [%l0], %o0
F0021AB0: d204a1dc                 ld      [%l2+0x1DC], %o1
F0021AB4: 9010200e                 mov     0xE, %o0
F0021AB8: 10800009                 ba      locret_F0021ADC
F0021ABC: d02a6038                 stb     %o0, [%o1+0x38]
F0021AC0: d0040000                 ld      [%l0], %o0
F0021AC4: d8042004                 ld      [%l0+4], %o4
F0021AC8: 9207bfe0                 add     %fp, var_20, %o1
F0021ACC: d4042008                 ld      [%l0+8], %o2
F0021AD0: 96032004                 add     %o4, 4, %o3
F0021AD4: 40000004                 call    _recvit
F0021AD8: 98032014                 inc     0x14, %o4
F0021ADC: 81c7e008                 ret
F0021AE0: 81e80000                 restore
