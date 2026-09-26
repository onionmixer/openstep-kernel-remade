F0073EE0: 9de3bf98                 save    %sp, -0x68, %sp
F0073EE4: 80a62000                 cmp     %i0, 0
F0073EE8: 02800005                 be      loc_F0073EFC
F0073EEC: a2102000                 mov     0, %l1
F0073EF0: 80a6601f                 cmp     %i1, 0x1F
F0073EF4: 08800004                 bleu    loc_F0073F04
F0073EF8: 01000000                 nop
F0073EFC: 1080001e                 ba      locret_F0073F74
F0073F00: b0102004                 mov     4, %i0
F0073F04: d0060000                 ld      [%i0], %o0
F0073F08: 80a22000                 cmp     %o0, 0
F0073F0C: 12bffffe                 bne     loc_F0073F04
F0073F10: 01000000                 nop
F0073F14: 40008be5                 call    _simple_lock_try
F0073F18: 90100018                 mov     %i0, %o0
F0073F1C: 80a22000                 cmp     %o0, 0
F0073F20: 02bffff9                 be      loc_F0073F04
F0073F24: 80a6a000                 cmp     %i2, 0
F0073F28: 02800011                 be      loc_F0073F6C
F0073F2C: f2262048                 st      %i1, [%i0+0x48]
F0073F30: f406201c                 ld      [%i0+0x1C], %i2
F0073F34: a006201c                 add     %i0, 0x1C, %l0
F0073F38: 80a4001a                 cmp     %l0, %i2
F0073F3C: 0280000c                 be      loc_F0073F6C
F0073F40: 9010001a                 mov     %i2, %o0
F0073F44: 92100019                 mov     %i1, %o1
F0073F48: 40000724                 call    _thread_priority
F0073F4C: 94102000                 mov     0, %o2
F0073F50: 80a22000                 cmp     %o0, 0
F0073F54: 32800002                 bne,a   loc_F0073F5C
F0073F58: a2102005                 mov     5, %l1
F0073F5C: f406a010                 ld      [%i2+0x10], %i2
F0073F60: 80a4001a                 cmp     %l0, %i2
F0073F64: 12bffff8                 bne     loc_F0073F44
F0073F68: 9010001a                 mov     %i2, %o0
F0073F6C: c0260000                 clr     [%i0]
F0073F70: b0100011                 mov     %l1, %i0
F0073F74: 81c7e008                 ret
F0073F78: 81e80000                 restore
