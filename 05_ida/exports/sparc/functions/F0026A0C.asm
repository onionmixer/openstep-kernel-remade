F0026A0C: 9de3be80                 save    %sp, -0x180, %sp
F0026A10: a6100018                 mov     %i0, %l3
F0026A14: 113c04cf                 sethi   %hi(_active_u), %o0
F0026A18: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0026A1C: a8102000                 mov     0, %l4
F0026A20: e202215c                 ld      [%o0+0x15C], %l1
F0026A24: a4102000                 mov     0, %l2
F0026A28: d0146006                 lduh    [%l1+6], %o0
F0026A2C: aa102000                 mov     0, %l5
F0026A30: 90022001                 inc     %o0
F0026A34: d0346006                 sth     %o0, [%l1+6]
F0026A38: c02fbef8                 clrb    [%fp+var_108]
F0026A3C: d004e008                 ld      [%l3+8], %o0
F0026A40: 80a22000                 cmp     %o0, 0
F0026A44: 02800020                 be      loc_F0026AC4
F0026A48: 113c04cf                 sethi   -0xFECC400, %o0
F0026A4C: d004e004                 ld      [%l3+4], %o0
F0026A50: d04a0000                 ldsb    [%o0], %o0
F0026A54: 80a2202f                 cmp     %o0, 0x2F ! '/'
F0026A58: 32800012                 bne,a   loc_F0026AA0
F0026A5C: d004e008                 ld      [%l3+8], %o0
F0026A60: 40000841                 call    _vn_rele
F0026A64: 90100011                 mov     %l1, %o0
F0026A68: 4000028e                 call    _pn_skipslash
F0026A6C: 90100013                 mov     %l3, %o0
F0026A70: 113c04cf                 sethi   %hi(_active_u), %o0
F0026A74: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0026A78: d0022160                 ld      [%o0+0x160], %o0
F0026A7C: 80a22000                 cmp     %o0, 0
F0026A80: 12800004                 bne     loc_F0026A90
F0026A84: a2100008                 mov     %o0, %l1
F0026A88: 113c04d4                 sethi   %hi(_rootdir), %o0
F0026A8C: e2022158                 ld      [%o0+%lo(_rootdir)], %l1
F0026A90: d0146006                 lduh    [%l1+6], %o0
F0026A94: 90022001                 inc     %o0
F0026A98: 10800012                 ba      loc_F0026AE0
F0026A9C: d0346006                 sth     %o0, [%l1+6]
F0026AA0: 80a22000                 cmp     %o0, 0
F0026AA4: 02800008                 be      loc_F0026AC4
F0026AA8: 113c04cf                 sethi   -0xFECC400, %o0
F0026AAC: d004e004                 ld      [%l3+4], %o0
F0026AB0: d04a0000                 ldsb    [%o0], %o0
F0026AB4: 80a22000                 cmp     %o0, 0
F0026AB8: 3280000b                 bne,a   loc_F0026AE4
F0026ABC: d0046028                 ld      [%l1+0x28], %o0
F0026AC0: 113c04cf                 sethi   -0xFECC400, %o0
F0026AC4: d00221d8                 ld      [%o0+0x1D8], %o0
F0026AC8: d0020000                 ld      [%o0], %o0
F0026ACC: d2022014                 ld      [%o0+0x14], %o1
F0026AD0: 11000010                 sethi   0x4000, %o0
F0026AD4: 808a4008                 btst    %o0, %o1
F0026AD8: 1280014c                 bne     locret_F0027008
F0026ADC: b0102002                 mov     2, %i0
F0026AE0: d0046028                 ld      [%l1+0x28], %o0
F0026AE4: 80a22002                 cmp     %o0, 2
F0026AE8: 12800141                 bne     loc_F0026FEC
F0026AEC: b0102014                 mov     0x14, %i0
F0026AF0: 90100013                 mov     %l3, %o0
F0026AF4: a007bef8                 add     %fp, var_108, %l0
F0026AF8: 92100010                 mov     %l0, %o1
F0026AFC: 4000024f                 call    _pn_getcomponent
F0026B00: 94102000                 mov     0, %o2
F0026B04: b0920000                 orcc    %o0, %g0, %i0
F0026B08: 1280013a                 bne     loc_F0026FF0
F0026B0C: 80a4a000                 cmp     %l2, 0
F0026B10: d04fbef8                 ldsb    [%fp+var_108], %o0
F0026B14: 80a22000                 cmp     %o0, 0
F0026B18: 3280000e                 bne,a   loc_F0026B50
F0026B1C: 90100010                 mov     %l0, %o0
F0026B20: 80a6a000                 cmp     %i2, 0
F0026B24: 1280011b                 bne     loc_F0026F90
F0026B28: 90100011                 mov     %l1, %o0
F0026B2C: 90100013                 mov     %l3, %o0
F0026B30: 133c0430                 sethi   %hi(unk_F010C128), %o1
F0026B34: 40000206                 call    _pn_set
F0026B38: 92126128                 bset    %lo(unk_F010C128), %o1
F0026B3C: 80a6e000                 cmp     %i3, 0
F0026B40: 02800120                 be      loc_F0026FC0
F0026B44: 90100011                 mov     %l1, %o0! __s1
F0026B48: 10800120                 ba      loc_F0026FC8
F0026B4C: e226c000                 st      %l1, [%i3]
F0026B50: 133c0430                 sethi   %hi(unk_F010C130), %o1! __s2
F0026B54: 7fff8596                 call    _strcmp
F0026B58: 92126130                 bset    %lo(unk_F010C130), %o1
F0026B5C: 80a22000                 cmp     %o0, 0
F0026B60: 32800040                 bne,a   loc_F0026C60
F0026B64: d0046010                 ld      [%l1+0x10], %o0
F0026B68: 113c04cf                 sethi   %hi(_active_u), %o0
F0026B6C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0026B70: d2022160                 ld      [%o0+0x160], %o1
F0026B74: 80a44009                 cmp     %l1, %o1
F0026B78: 02800035                 be      loc_F0026C4C
F0026B7C: 80a46000                 cmp     %l1, 0
F0026B80: 0280000f                 be      loc_F0026BBC
F0026B84: 80a26000                 cmp     %o1, 0
F0026B88: 0280000e                 be      loc_F0026BC0
F0026B8C: 113c04d4                 sethi   -0xFECB000, %o0
F0026B90: d404601c                 ld      [%l1+0x1C], %o2
F0026B94: d002601c                 ld      [%o1+0x1C], %o0
F0026B98: 80a28008                 cmp     %o2, %o0
F0026B9C: 12800009                 bne     loc_F0026BC0
F0026BA0: 113c04d4                 sethi   -0xFECB000, %o0
F0026BA4: d402a06c                 ld      [%o2+0x6C], %o2
F0026BA8: 9fc28000                 call    %o2
F0026BAC: 90100011                 mov     %l1, %o0
F0026BB0: 80a22000                 cmp     %o0, 0
F0026BB4: 32800027                 bne,a   loc_F0026C50
F0026BB8: d0146006                 lduh    [%l1+6], %o0
F0026BBC: 113c04d4                 sethi   -0xFECB000, %o0
F0026BC0: d2022158                 ld      [%o0+0x158], %o1
F0026BC4: 80a44009                 cmp     %l1, %o1
F0026BC8: 02800021                 be      loc_F0026C4C
F0026BCC: 80a46000                 cmp     %l1, 0
F0026BD0: 0280000f                 be      loc_F0026C0C
F0026BD4: 80a26000                 cmp     %o1, 0
F0026BD8: 2280000e                 be,a    loc_F0026C10
F0026BDC: d0146004                 lduh    [%l1+4], %o0
F0026BE0: d404601c                 ld      [%l1+0x1C], %o2
F0026BE4: d002601c                 ld      [%o1+0x1C], %o0
F0026BE8: 80a28008                 cmp     %o2, %o0
F0026BEC: 32800009                 bne,a   loc_F0026C10
F0026BF0: d0146004                 lduh    [%l1+4], %o0
F0026BF4: d402a06c                 ld      [%o2+0x6C], %o2
F0026BF8: 9fc28000                 call    %o2
F0026BFC: 90100011                 mov     %l1, %o0
F0026C00: 80a22000                 cmp     %o0, 0
F0026C04: 32800013                 bne,a   loc_F0026C50
F0026C08: d0146006                 lduh    [%l1+6], %o0
F0026C0C: d0146004                 lduh    [%l1+4], %o0
F0026C10: 808a2001                 btst    1, %o0
F0026C14: 22800013                 be,a    loc_F0026C60
F0026C18: d0046010                 ld      [%l1+0x10], %o0
F0026C1C: d0046024                 ld      [%l1+0x24], %o0
F0026C20: a4100011                 mov     %l1, %l2
F0026C24: e2022008                 ld      [%o0+8], %l1
F0026C28: d2146006                 lduh    [%l1+6], %o1
F0026C2C: 90100012                 mov     %l2, %o0
F0026C30: 92026001                 inc     %o1
F0026C34: 400007cc                 call    _vn_rele
F0026C38: d2346006                 sth     %o1, [%l1+6]
F0026C3C: d004600c                 ld      [%l1+0xC], %o0
F0026C40: 80a22000                 cmp     %o0, 0
F0026C44: 12bfffc9                 bne     loc_F0026B68
F0026C48: a4102000                 mov     0, %l2
F0026C4C: d0146006                 lduh    [%l1+6], %o0
F0026C50: a4100011                 mov     %l1, %l2
F0026C54: 90022001                 inc     %o0
F0026C58: 10800095                 ba      loc_F0026EAC
F0026C5C: d0346006                 sth     %o0, [%l1+6]
F0026C60: 80a22000                 cmp     %o0, 0
F0026C64: 0280002e                 be      loc_F0026D1C
F0026C68: 113c04cf                 sethi   %hi(_active_u), %o0
F0026C6C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0026C70: d204601c                 ld      [%l1+0x1C], %o1
F0026C74: d402201c                 ld      [%o0+0x1C], %o2! __n
F0026C78: d602601c                 ld      [%o1+0x1C], %o3
F0026C7C: 90100011                 mov     %l1, %o0
F0026C80: 9fc2c000                 call    %o3
F0026C84: 92102040                 mov     0x40, %o1 ! '@'
F0026C88: b0920000                 orcc    %o0, %g0, %i0
F0026C8C: 128000d9                 bne     loc_F0026FF0
F0026C90: 80a4a000                 cmp     %l2, 0
F0026C94: e0046010                 ld      [%l1+0x10], %l0
F0026C98: 80a42000                 cmp     %l0, 0
F0026C9C: 02800021                 be      loc_F0026D20
F0026CA0: 90100011                 mov     %l1, %o0
F0026CA4: 90042020                 add     %l0, 0x20, %o0 ! ' '! __s1
F0026CA8: 9207bef8                 add     %fp, var_108, %o1! __s2
F0026CAC: 7fff860f                 call    _strncmp
F0026CB0: 941020ff                 mov     0xFF, %o2
F0026CB4: 80a22000                 cmp     %o0, 0
F0026CB8: 32800016                 bne,a   loc_F0026D10
F0026CBC: e0042120                 ld      [%l0+0x120], %l0
F0026CC0: d004200c                 ld      [%l0+0xC], %o0
F0026CC4: 808a2002                 btst    2, %o0
F0026CC8: 02800008                 be      loc_F0026CE8
F0026CCC: 90122004                 bset    4, %o0
F0026CD0: d024200c                 st      %o0, [%l0+0xC]
F0026CD4: 90100010                 mov     %l0, %o0! unsigned int
F0026CD8: 7fffae68                 call    _sleep
F0026CDC: 9210201b                 mov     0x1B, %o1
F0026CE0: 10bfffe0                 ba      loc_F0026C60
F0026CE4: d0046010                 ld      [%l1+0x10], %o0
F0026CE8: d2042004                 ld      [%l0+4], %o1
F0026CEC: d4026008                 ld      [%o1+8], %o2
F0026CF0: 90100010                 mov     %l0, %o0
F0026CF4: 9fc28000                 call    %o2
F0026CF8: 9207bef4                 add     %fp, var_10C, %o1
F0026CFC: b0920000                 orcc    %o0, %g0, %i0
F0026D00: 128000bc                 bne     loc_F0026FF0
F0026D04: 80a4a000                 cmp     %l2, 0
F0026D08: 10800069                 ba      loc_F0026EAC
F0026D0C: e407bef4                 ld      [%fp+var_10C], %l2
F0026D10: 80a42000                 cmp     %l0, 0
F0026D14: 12bfffe5                 bne     loc_F0026CA8
F0026D18: 90042020                 add     %l0, 0x20, %o0 ! ' '
F0026D1C: 90100011                 mov     %l1, %o0
F0026D20: 133c04cf                 sethi   %hi(_active_u), %o1
F0026D24: d40261d8                 ld      [%o1+%lo(_active_u)], %o2
F0026D28: a007bef8                 add     %fp, var_108, %l0
F0026D2C: da04601c                 ld      [%l1+0x1C], %o5
F0026D30: 98100013                 mov     %l3, %o4
F0026D34: d602a01c                 ld      [%o2+0x1C], %o3
F0026D38: 92100010                 mov     %l0, %o1
F0026D3C: c4036020                 ld      [%o5+0x20], %g2
F0026D40: 9407bef4                 add     %fp, var_10C, %o2
F0026D44: 9fc08000                 call    %g2
F0026D48: 9a100015                 mov     %l5, %o5
F0026D4C: b0920000                 orcc    %o0, %g0, %i0
F0026D50: 02800026                 be      loc_F0026DE8
F0026D54: e407bef4                 ld      [%fp+var_10C], %l2
F0026D58: d004e008                 ld      [%l3+8], %o0
F0026D5C: 80a22000                 cmp     %o0, 0
F0026D60: 128000a3                 bne     loc_F0026FEC
F0026D64: a4102000                 mov     0, %l2
F0026D68: 80a6a000                 cmp     %i2, 0
F0026D6C: 028000a0                 be      loc_F0026FEC
F0026D70: 80a6200d                 cmp     %i0, 0xD
F0026D74: 0280009e                 be      loc_F0026FEC
F0026D78: 90100013                 mov     %l3, %o0
F0026D7C: 40000174                 call    _pn_set
F0026D80: 92100010                 mov     %l0, %o1
F0026D84: 80a6e000                 cmp     %i3, 0
F0026D88: 02800090                 be      loc_F0026FC8
F0026D8C: e2268000                 st      %l1, [%i2]
F0026D90: 1080008e                 ba      loc_F0026FC8
F0026D94: c026c000                 clr     [%i3]
F0026D98: 808a2002                 btst    2, %o0
F0026D9C: 02800008                 be      loc_F0026DBC
F0026DA0: 90122004                 bset    4, %o0
F0026DA4: d024200c                 st      %o0, [%l0+0xC]
F0026DA8: 90100010                 mov     %l0, %o0! unsigned int
F0026DAC: 7fffae33                 call    _sleep
F0026DB0: 9210201b                 mov     0x1B, %o1
F0026DB4: 1080000e                 ba      loc_F0026DEC
F0026DB8: e004a00c                 ld      [%l2+0xC], %l0
F0026DBC: d004a00c                 ld      [%l2+0xC], %o0
F0026DC0: d4022004                 ld      [%o0+4], %o2
F0026DC4: d402a008                 ld      [%o2+8], %o2
F0026DC8: 9fc28000                 call    %o2
F0026DCC: 9207bef4                 add     %fp, var_10C, %o1
F0026DD0: b0920000                 orcc    %o0, %g0, %i0
F0026DD4: 12800087                 bne     loc_F0026FF0
F0026DD8: 80a4a000                 cmp     %l2, 0
F0026DDC: 40000762                 call    _vn_rele
F0026DE0: 90100012                 mov     %l2, %o0
F0026DE4: e407bef4                 ld      [%fp+var_10C], %l2
F0026DE8: e004a00c                 ld      [%l2+0xC], %l0
F0026DEC: 80a42000                 cmp     %l0, 0
F0026DF0: 32bfffea                 bne,a   loc_F0026D98
F0026DF4: d004200c                 ld      [%l0+0xC], %o0
F0026DF8: d004a028                 ld      [%l2+0x28], %o0
F0026DFC: 80a22005                 cmp     %o0, 5
F0026E00: 3280002c                 bne,a   loc_F0026EB0
F0026E04: d004e008                 ld      [%l3+8], %o0
F0026E08: 80a66001                 cmp     %i1, 1
F0026E0C: 22800007                 be,a    loc_F0026E28
F0026E10: a8052001                 inc     %l4
F0026E14: d004e008                 ld      [%l3+8], %o0
F0026E18: 80a22000                 cmp     %o0, 0
F0026E1C: 0280003f                 be      loc_F0026F18
F0026E20: 113c04cf                 sethi   -0xFECC400, %o0
F0026E24: a8052001                 inc     %l4
F0026E28: 80a52014                 cmp     %l4, 0x14
F0026E2C: 14800070                 bg      loc_F0026FEC
F0026E30: b010203e                 mov     0x3E, %i0 ! '>'
F0026E34: 90100012                 mov     %l2, %o0
F0026E38: 9207bef8                 add     %fp, var_108, %o1
F0026E3C: 94100011                 mov     %l1, %o2
F0026E40: a007bee0                 add     %fp, var_120, %l0
F0026E44: 40000073                 call    sub_F0027010
F0026E48: 96100010                 mov     %l0, %o3
F0026E4C: b0920000                 orcc    %o0, %g0, %i0
F0026E50: 12800068                 bne     loc_F0026FF0
F0026E54: 80a4a000                 cmp     %l2, 0
F0026E58: d007bee8                 ld      [%fp+var_118], %o0
F0026E5C: 80a22000                 cmp     %o0, 0
F0026E60: 32800007                 bne,a   loc_F0026E7C
F0026E64: 90100013                 mov     %l3, %o0
F0026E68: 90100010                 mov     %l0, %o0
F0026E6C: 133c0430                 sethi   %hi(unk_F010C138), %o1
F0026E70: 40000137                 call    _pn_set
F0026E74: 92126138                 bset    %lo(unk_F010C138), %o1
F0026E78: 90100013                 mov     %l3, %o0
F0026E7C: 40000140                 call    _pn_combine
F0026E80: 92100010                 mov     %l0, %o1
F0026E84: b0100008                 mov     %o0, %i0
F0026E88: 40000198                 call    _pn_free
F0026E8C: 90100010                 mov     %l0, %o0
F0026E90: 80a62000                 cmp     %i0, 0
F0026E94: 12800057                 bne     loc_F0026FF0
F0026E98: 80a4a000                 cmp     %l2, 0
F0026E9C: 40000732                 call    _vn_rele
F0026EA0: 90100012                 mov     %l2, %o0
F0026EA4: 10bffee5                 ba      loc_F0026A38
F0026EA8: a4102000                 mov     0, %l2
F0026EAC: d004e008                 ld      [%l3+8], %o0
F0026EB0: 80a22000                 cmp     %o0, 0
F0026EB4: 02800019                 be      loc_F0026F18
F0026EB8: 113c04cf                 sethi   %hi(_active_u), %o0
F0026EBC: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0026EC0: d0020000                 ld      [%o0], %o0
F0026EC4: d2022014                 ld      [%o0+0x14], %o1
F0026EC8: 11000010                 sethi   0x4000, %o0
F0026ECC: 808a4008                 btst    %o0, %o1
F0026ED0: 22800013                 be,a    loc_F0026F1C
F0026ED4: d004e008                 ld      [%l3+8], %o0
F0026ED8: d204e004                 ld      [%l3+4], %o1
F0026EDC: d04a4000                 ldsb    [%o1], %o0
F0026EE0: 80a2202f                 cmp     %o0, 0x2F ! '/'
F0026EE4: 22bffffe                 be,a    loc_F0026EDC
F0026EE8: 92026001                 inc     %o1
F0026EEC: d04a4000                 ldsb    [%o1], %o0
F0026EF0: 80a22000                 cmp     %o0, 0
F0026EF4: 3280000a                 bne,a   loc_F0026F1C
F0026EF8: d004e008                 ld      [%l3+8], %o0
F0026EFC: d004a028                 ld      [%l2+0x28], %o0
F0026F00: 80a22002                 cmp     %o0, 2
F0026F04: 32800006                 bne,a   loc_F0026F1C
F0026F08: d004e008                 ld      [%l3+8], %o0
F0026F0C: d004e004                 ld      [%l3+4], %o0
F0026F10: c02a0000                 clrb    [%o0]
F0026F14: c024e008                 clr     [%l3+8]
F0026F18: d004e008                 ld      [%l3+8], %o0
F0026F1C: 80a22000                 cmp     %o0, 0
F0026F20: 1280002c                 bne     loc_F0026FD0
F0026F24: 90100013                 mov     %l3, %o0
F0026F28: 40000109                 call    _pn_set
F0026F2C: 9207bef8                 add     %fp, var_108, %o1
F0026F30: 80a6a000                 cmp     %i2, 0
F0026F34: 0280001c                 be      loc_F0026FA4
F0026F38: 80a44012                 cmp     %l1, %l2
F0026F3C: 02800012                 be      loc_F0026F84
F0026F40: 80a46000                 cmp     %l1, 0
F0026F44: 02800016                 be      loc_F0026F9C
F0026F48: 80a4a000                 cmp     %l2, 0
F0026F4C: 22800018                 be,a    loc_F0026FAC
F0026F50: e2268000                 st      %l1, [%i2]
F0026F54: d204601c                 ld      [%l1+0x1C], %o1
F0026F58: d004a01c                 ld      [%l2+0x1C], %o0
F0026F5C: 80a24008                 cmp     %o1, %o0
F0026F60: 32800013                 bne,a   loc_F0026FAC
F0026F64: e2268000                 st      %l1, [%i2]
F0026F68: d402606c                 ld      [%o1+0x6C], %o2
F0026F6C: 90100011                 mov     %l1, %o0
F0026F70: 9fc28000                 call    %o2
F0026F74: 92100012                 mov     %l2, %o1
F0026F78: 80a22000                 cmp     %o0, 0
F0026F7C: 2280000c                 be,a    loc_F0026FAC
F0026F80: e2268000                 st      %l1, [%i2]
F0026F84: 400006f8                 call    _vn_rele
F0026F88: 90100011                 mov     %l1, %o0
F0026F8C: 90100012                 mov     %l2, %o0
F0026F90: 400006f5                 call    _vn_rele
F0026F94: b0102011                 mov     0x11, %i0
F0026F98: 3080001c                 ba,a    locret_F0027008
F0026F9C: 10800004                 ba      loc_F0026FAC
F0026FA0: e2268000                 st      %l1, [%i2]
F0026FA4: 400006f0                 call    _vn_rele
F0026FA8: 90100011                 mov     %l1, %o0
F0026FAC: 80a6e000                 cmp     %i3, 0
F0026FB0: 02800004                 be      loc_F0026FC0
F0026FB4: 90100012                 mov     %l2, %o0
F0026FB8: 10800004                 ba      loc_F0026FC8
F0026FBC: e426c000                 st      %l2, [%i3]
F0026FC0: 400006e9                 call    _vn_rele
F0026FC4: 01000000                 nop
F0026FC8: 10800010                 ba      locret_F0027008
F0026FCC: b0102000                 mov     0, %i0
F0026FD0: 40000134                 call    _pn_skipslash
F0026FD4: 90100013                 mov     %l3, %o0
F0026FD8: 400006e3                 call    _vn_rele
F0026FDC: 90100011                 mov     %l1, %o0
F0026FE0: a2100012                 mov     %l2, %l1
F0026FE4: 10bffebf                 ba      loc_F0026AE0
F0026FE8: a4102000                 mov     0, %l2
F0026FEC: 80a4a000                 cmp     %l2, 0
F0026FF0: 02800004                 be      loc_F0027000
F0026FF4: 01000000                 nop
F0026FF8: 400006db                 call    _vn_rele
F0026FFC: 90100012                 mov     %l2, %o0
F0027000: 400006d9                 call    _vn_rele
F0027004: 90100011                 mov     %l1, %o0
F0027008: 81c7e008                 ret
F002700C: 81e80000                 restore
