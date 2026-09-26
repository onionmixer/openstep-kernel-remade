F0071E8C: 9de3bf98                 save    %sp, -0x68, %sp
F0071E90: a4100018                 mov     %i0, %l2
F0071E94: a2100012                 mov     %l2, %l1
F0071E98: a004a100                 add     %l2, 0x100, %l0
F0071E9C: d0040000                 ld      [%l0], %o0
F0071EA0: 80a22000                 cmp     %o0, 0
F0071EA4: 12bffffe                 bne     loc_F0071E9C
F0071EA8: 01000000                 nop
F0071EAC: 400093ff                 call    _simple_lock_try
F0071EB0: 90100010                 mov     %l0, %o0
F0071EB4: 80a22000                 cmp     %o0, 0
F0071EB8: 02bffff9                 be      loc_F0071E9C
F0071EBC: 01000000                 nop
F0071EC0: d0046108                 ld      [%l1+0x108], %o0
F0071EC4: 80a22000                 cmp     %o0, 0
F0071EC8: 0480001f                 ble     loc_F0071F44
F0071ECC: 01000000                 nop
F0071ED0: d2046104                 ld      [%l1+0x104], %o1
F0071ED4: 912a6003                 sll     %o1, 3, %o0
F0071ED8: 80a26000                 cmp     %o1, 0
F0071EDC: 06800017                 bl      loc_F0071F38
F0071EE0: 94044008                 add     %l1, %o0, %o2
F0071EE4: f0028000                 ld      [%o2], %i0
F0071EE8: 80a28018                 cmp     %o2, %i0
F0071EEC: 02800010                 be      loc_F0071F2C
F0071EF0: 80a6000a                 cmp     %i0, %o2
F0071EF4: 32800004                 bne,a   loc_F0071F04
F0071EF8: d0060000                 ld      [%i0], %o0
F0071EFC: 10800005                 ba      loc_F0071F10
F0071F00: b0102000                 mov     0, %i0
F0071F04: d4222004                 st      %o2, [%o0+4]
F0071F08: d0060000                 ld      [%i0], %o0
F0071F0C: d0228000                 st      %o0, [%o2]
F0071F10: c0262008                 clr     [%i0+8]
F0071F14: d2246104                 st      %o1, [%l1+0x104]
F0071F18: d0046108                 ld      [%l1+0x108], %o0
F0071F1C: c0246100                 clr     [%l1+0x100]
F0071F20: 90023fff                 inc     -1, %o0
F0071F24: 10800017                 ba      locret_F0071F80
F0071F28: d0246108                 st      %o0, [%l1+0x108]
F0071F2C: 92827fff                 inccc   -1, %o1
F0071F30: 1cbfffed                 bpos    loc_F0071EE4
F0071F34: 9402bff8                 inc     -8, %o2
F0071F38: 113c0441                 sethi   %hi(aChooseThread), %o0! "choose_thread"
F0071F3C: 7ffe8c8d                 call    _panic
F0071F40: 90122160                 bset    %lo(aChooseThread), %o0! "choose_thread"
F0071F44: c0246100                 clr     [%l1+0x100]
F0071F48: e204a12c                 ld      [%l2+0x12C], %l1
F0071F4C: a0046100                 add     %l1, 0x100, %l0
F0071F50: d0040000                 ld      [%l0], %o0
F0071F54: 80a22000                 cmp     %o0, 0
F0071F58: 12bffffe                 bne     loc_F0071F50
F0071F5C: 01000000                 nop
F0071F60: 400093d2                 call    _simple_lock_try
F0071F64: 90100010                 mov     %l0, %o0
F0071F68: 80a22000                 cmp     %o0, 0
F0071F6C: 02bffff9                 be      loc_F0071F50
F0071F70: 90100012                 mov     %l2, %o0
F0071F74: 40000005                 call    _choose_pset_thread
F0071F78: 92100011                 mov     %l1, %o1
F0071F7C: b0100008                 mov     %o0, %i0
F0071F80: 81c7e008                 ret
F0071F84: 81e80000                 restore
