F00D39FC: 9de3bf88                 save    %sp, -0x78, %sp
F00D3A00: 7fffc9b7                 call    _IOGetTimestamp
F00D3A04: 9007bfe8                 add     %fp, var_18, %o0
F00D3A08: d41fbfe8                 ldd     [%fp+var_18], %o2
F00D3A0C: da0621f0                 ld      [%i0+0x1F0], %o5
F00D3A10: 90102000                 mov     0, %o0
F00D3A14: 13028000                 sethi   0xA000000, %o1
F00D3A18: d807bfe8                 ld      [%fp+var_18], %o4
F00D3A1C: 9682c009                 addcc   %o3, %o1, %o3
F00D3A20: 94428008                 addc    %o2, %o0, %o2
F00D3A24: 80a3400c                 cmp     %o5, %o4
F00D3A28: 3880000a                 bgu,a   loc_F00D3A50
F00D3A2C: d00621f0                 ld      [%i0+0x1F0], %o0
F00D3A30: 32800013                 bne,a   loc_F00D3A7C
F00D3A34: d04e2210                 ldsb    [%i0+0x210], %o0
F00D3A38: d20621f4                 ld      [%i0+0x1F4], %o1
F00D3A3C: d007bfec                 ld      [%fp+var_18+4], %o0
F00D3A40: 80a24008                 cmp     %o1, %o0
F00D3A44: 2880000e                 bleu,a  loc_F00D3A7C
F00D3A48: d04e2210                 ldsb    [%i0+0x210], %o0
F00D3A4C: d00621f0                 ld      [%i0+0x1F0], %o0
F00D3A50: 80a28008                 cmp     %o2, %o0
F00D3A54: 38800009                 bgu,a   loc_F00D3A78
F00D3A58: d41e21f0                 ldd     [%i0+0x1F0], %o2
F00D3A5C: 32800008                 bne,a   loc_F00D3A7C
F00D3A60: d04e2210                 ldsb    [%i0+0x210], %o0
F00D3A64: d00621f4                 ld      [%i0+0x1F4], %o0
F00D3A68: 80a2c008                 cmp     %o3, %o0
F00D3A6C: 28800004                 bleu,a  loc_F00D3A7C
F00D3A70: d04e2210                 ldsb    [%i0+0x210], %o0
F00D3A74: d41e21f0                 ldd     [%i0+0x1F0], %o2
F00D3A78: d04e2210                 ldsb    [%i0+0x210], %o0
F00D3A7C: 80a22000                 cmp     %o0, 0
F00D3A80: 22800018                 be,a    loc_F00D3AE0
F00D3A84: d43e2208                 std     %o2, [%i0+0x208]
F00D3A88: d2062208                 ld      [%i0+0x208], %o1
F00D3A8C: 80a2400a                 cmp     %o1, %o2
F00D3A90: 38800014                 bgu,a   loc_F00D3AE0
F00D3A94: d43e2208                 std     %o2, [%i0+0x208]
F00D3A98: 32800007                 bne,a   loc_F00D3AB4
F00D3A9C: d0062200                 ld      [%i0+0x200], %o0
F00D3AA0: d006220c                 ld      [%i0+0x20C], %o0
F00D3AA4: 80a2000b                 cmp     %o0, %o3
F00D3AA8: 3880000e                 bgu,a   loc_F00D3AE0
F00D3AAC: d43e2208                 std     %o2, [%i0+0x208]
F00D3AB0: d0062200                 ld      [%i0+0x200], %o0
F00D3AB4: 80a24008                 cmp     %o1, %o0
F00D3AB8: 1880000e                 bgu     locret_F00D3AF0
F00D3ABC: 01000000                 nop
F00D3AC0: 32800008                 bne,a   loc_F00D3AE0
F00D3AC4: d43e2208                 std     %o2, [%i0+0x208]
F00D3AC8: d206220c                 ld      [%i0+0x20C], %o1
F00D3ACC: d0062204                 ld      [%i0+0x204], %o0! id
F00D3AD0: 80a24008                 cmp     %o1, %o0
F00D3AD4: 18800007                 bgu     locret_F00D3AF0
F00D3AD8: 01000000                 nop
F00D3ADC: d43e2208                 std     %o2, [%i0+0x208]
F00D3AE0: 133c0505                 sethi   %hi(paRunperiodiceve), %o1
F00D3AE4: d20262c4                 ld      [%o1+%lo(paRunperiodiceve)], %o1! SEL
F00D3AE8: 40007762                 call    _objc_msgSend
F00D3AEC: 90100018                 mov     %i0, %o0
F00D3AF0: 81c7e008                 ret
F00D3AF4: 81e80000                 restore
