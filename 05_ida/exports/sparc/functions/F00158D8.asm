F00158D8: 9de3bf18                 save    %sp, -0xE8, %sp! int
F00158DC: 273c04cf                 sethi   %hi(dword_F0133DDC), %l3
F00158E0: d804e1dc                 ld      [%l3+%lo(dword_F0133DDC)], %o4! int
F00158E4: 9014e1dc                 or      %l3, %lo(dword_F0133DDC), %o0
F00158E8: d6023ffc                 ld      [%o0-4], %o3! int
F00158EC: e8032024                 ld      [%o4+0x24], %l4
F00158F0: d002e158                 ld      [%o3+0x158], %o0
F00158F4: d4050000                 ld      [%l4], %o2! int
F00158F8: 80a28008                 cmp     %o2, %o0
F00158FC: 1a80000d                 bcc     loc_F0015930
F0015900: 113c04cf                 sethi   -0xFECC400, %o0
F0015904: d202e14c                 ld      [%o3+0x14C], %o1
F0015908: 912aa002                 sll     %o2, 2, %o0
F001590C: e2024008                 ld      [%o1+%o0], %l1
F0015910: 80a46000                 cmp     %l1, 0
F0015914: 02800007                 be      loc_F0015930
F0015918: 113c04cf                 sethi   -0xFECC400, %o0
F001591C: 113fffc0                 sethi   -0x10000, %o0
F0015920: 80a44008                 cmp     %l1, %o0
F0015924: 32800006                 bne,a   loc_F001593C
F0015928: d0046008                 ld      [%l1+8], %o0
F001592C: 113c04cf                 sethi   -0xFECC400, %o0
F0015930: d20221dc                 ld      [%o0+0x1DC], %o1
F0015934: 10800087                 ba      loc_F0015B50
F0015938: 90102009                 mov     9, %o0
F001593C: 808a2003                 btst    3, %o0
F0015940: 32800005                 bne,a   loc_F0015954
F0015944: e0052004                 ld      [%l4+4], %l0
F0015948: 90102009                 mov     9, %o0
F001594C: 10800082                 ba      locret_F0015B54
F0015950: d02b2038                 stb     %o0, [%o4+0x38]
F0015954: 1108001990122201         set     0x20006601, %o0
F001595C: 80a40008                 cmp     %l0, %o0
F0015960: 12800007                 bne     loc_F001597C
F0015964: 11080019                 sethi   0x20006400, %o0
F0015968: d202e150                 ld      [%o3+0x150], %o1
F001596C: d00a400a                 ldub    [%o1+%o2], %o0
F0015970: 90122001                 bset    1, %o0
F0015974: 10800078                 ba      locret_F0015B54
F0015978: d02a400a                 stb     %o0, [%o1+%o2]
F001597C: 90122202                 bset    0x202, %o0
F0015980: 80a40008                 cmp     %l0, %o0
F0015984: 12800007                 bne     loc_F00159A0
F0015988: 912c2003                 sll     %l0, 3, %o0
F001598C: d202e150                 ld      [%o3+0x150], %o1
F0015990: d00a400a                 ldub    [%o1+%o2], %o0
F0015994: 900a3ffe                 and     %o0, -2, %o0
F0015998: 1080006f                 ba      locret_F0015B54
F001599C: d02a400a                 stb     %o0, [%o1+%o2]
F00159A0: a5322013                 srl     %o0, 19, %l2
F00159A4: 80a4a080                 cmp     %l2, 0x80
F00159A8: 08800004                 bleu    loc_F00159B8
F00159AC: 9010200e                 mov     0xE, %o0
F00159B0: 10800069                 ba      locret_F0015B54
F00159B4: d02b2038                 stb     %o0, [%o4+0x38]
F00159B8: 80a42000                 cmp     %l0, 0
F00159BC: 16800010                 bge     loc_F00159FC
F00159C0: 11100000                 sethi   0x40000000, %o0
F00159C4: 80a4a000                 cmp     %l2, 0
F00159C8: 0280001a                 be      loc_F0015A30
F00159CC: 9207bf78                 add     %fp, var_88, %o1! int
F00159D0: d0052008                 ld      [%l4+8], %o0! int
F00159D4: 400209a1                 call    _copyin
F00159D8: 94100012                 mov     %l2, %o2
F00159DC: d204e1dc                 ld      [%l3+0x1DC], %o1! size_t
F00159E0: d02a6038                 stb     %o0, [%o1+0x38]
F00159E4: d004e1dc                 ld      [%l3+0x1DC], %o0
F00159E8: d04a2038                 ldsb    [%o0+0x38], %o0
F00159EC: 80a22000                 cmp     %o0, 0
F00159F0: 12800059                 bne     locret_F0015B54
F00159F4: 11200119                 sethi   -0x7FFB9C00, %o0
F00159F8: 30800011                 ba,a    loc_F0015A3C
F00159FC: 808c0008                 btst    %o0, %l0
F0015A00: 02800008                 be      loc_F0015A20
F0015A04: 80a4a000                 cmp     %l2, 0
F0015A08: 02800006                 be      loc_F0015A20
F0015A0C: 9007bf78                 add     %fp, var_88, %o0! void *
F0015A10: 4001fd12                 call    _bzero
F0015A14: 92100012                 mov     %l2, %o1
F0015A18: 10800009                 ba      loc_F0015A3C
F0015A1C: 11200119                 sethi   -0x7FFB9C00, %o0
F0015A20: 11080000                 sethi   0x20000000, %o0
F0015A24: 808c0008                 btst    %o0, %l0
F0015A28: 02800005                 be      loc_F0015A3C
F0015A2C: 11200119                 sethi   -0x7FFB9C00, %o0
F0015A30: d0052008                 ld      [%l4+8], %o0
F0015A34: d027bf78                 st      %o0, [%fp+var_88]
F0015A38: 11200119                 sethi   -0x7FFB9C00, %o0
F0015A3C: 9012227d                 bset    0x27D, %o0
F0015A40: 80a40008                 cmp     %l0, %o0
F0015A44: 2280001c                 be,a    loc_F0015AB4
F0015A48: 90100011                 mov     %l1, %o0
F0015A4C: 14800009                 bg      loc_F0015A70
F0015A50: 11200119                 sethi   -0x7FFB9C00, %o0
F0015A54: 112001199012227c         set     -0x7FFB9984, %o0
F0015A5C: 80a40008                 cmp     %l0, %o0
F0015A60: 0280001b                 be      loc_F0015ACC
F0015A64: d207bf78                 ld      [%fp+var_88], %o1
F0015A68: 10800023                 ba      loc_F0015AF4
F0015A6C: 90100011                 mov     %l1, %o0
F0015A70: 9012227e                 bset    0x27E, %o0
F0015A74: 80a40008                 cmp     %l0, %o0
F0015A78: 02800008                 be      loc_F0015A98
F0015A7C: 11100119                 sethi   0x40046400, %o0
F0015A80: 9012227b                 bset    0x27B, %o0
F0015A84: 80a40008                 cmp     %l0, %o0
F0015A88: 02800016                 be      loc_F0015AE0
F0015A8C: 90100011                 mov     %l1, %o0
F0015A90: 1080001a                 ba      loc_F0015AF8
F0015A94: d4022014                 ld      [%o0+0x14], %o2
F0015A98: 90100011                 mov     %l1, %o0
F0015A9C: d407bf78                 ld      [%fp+var_88], %o2
F0015AA0: 7fffd51e                 call    _fset
F0015AA4: 92102004                 mov     4, %o1
F0015AA8: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F0015AAC: 10800029                 ba      loc_F0015B50
F0015AB0: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F0015AB4: d407bf78                 ld      [%fp+var_88], %o2
F0015AB8: 7fffd518                 call    _fset
F0015ABC: 92102040                 mov     0x40, %o1 ! '@'
F0015AC0: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F0015AC4: 10800023                 ba      loc_F0015B50
F0015AC8: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F0015ACC: 7fffd53d                 call    _fsetown
F0015AD0: 90100011                 mov     %l1, %o0
F0015AD4: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F0015AD8: 1080001e                 ba      loc_F0015B50
F0015ADC: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F0015AE0: 7fffd524                 call    _fgetown
F0015AE4: 9207bf78                 add     %fp, var_88, %o1
F0015AE8: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F0015AEC: 10800019                 ba      loc_F0015B50
F0015AF0: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F0015AF4: d4022014                 ld      [%o0+0x14], %o2
F0015AF8: 92100010                 mov     %l0, %o1
F0015AFC: d602a004                 ld      [%o2+4], %o3! int
F0015B00: a607bf78                 add     %fp, var_88, %l3
F0015B04: 9fc2c000                 call    %o3
F0015B08: 94100013                 mov     %l3, %o2! int
F0015B0C: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F0015B10: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F0015B14: d02a6038                 stb     %o0, [%o1+0x38]
F0015B18: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F0015B1C: d04a2038                 ldsb    [%o0+0x38], %o0
F0015B20: 80a22000                 cmp     %o0, 0
F0015B24: 1280000c                 bne     locret_F0015B54
F0015B28: 11100000                 sethi   0x40000000, %o0
F0015B2C: 808c0008                 btst    %o0, %l0
F0015B30: 02800009                 be      locret_F0015B54
F0015B34: 80a4a000                 cmp     %l2, 0
F0015B38: 02800007                 be      locret_F0015B54
F0015B3C: 90100013                 mov     %l3, %o0! int
F0015B40: d2052008                 ld      [%l4+8], %o1! int
F0015B44: 40020962                 call    _copyout
F0015B48: 94100012                 mov     %l2, %o2
F0015B4C: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F0015B50: d02a6038                 stb     %o0, [%o1+0x38]
F0015B54: 81c7e008                 ret
F0015B58: 81e80000                 restore
