F00F3ACC: 9de3bf98                 save    %sp, -0x68, %sp
F00F3AD0: 7ffff41f                 call    _NXDefaultMallocZone
F00F3AD4: 01000000                 nop
F00F3AD8: 7ffff41d                 call    _NXDefaultMallocZone
F00F3ADC: a0100008                 mov     %o0, %l0
F00F3AE0: d4042004                 ld      [%l0+4], %o2
F00F3AE4: 9fc28000                 call    %o2
F00F3AE8: 9210201c                 mov     0x1C, %o1
F00F3AEC: 94100008                 mov     %o0, %o2
F00F3AF0: f0228000                 st      %i0, [%o2]
F00F3AF4: 90102335                 mov     0x335, %o0
F00F3AF8: d022a004                 st      %o0, [%o2+4]
F00F3AFC: c022a008                 clr     [%o2+8]
F00F3B00: f222a00c                 st      %i1, [%o2+0xC]
F00F3B04: b206401a                 add     %i1, %i2, %i1
F00F3B08: f222a010                 st      %i1, [%o2+0x10]
F00F3B0C: f622a014                 st      %i3, [%o2+0x14]
F00F3B10: 113c04bc9212216c         set     off_F012F16C, %o1
F00F3B18: d002216c                 ld      [%o0+0x16C], %o0
F00F3B1C: 80a22000                 cmp     %o0, 0
F00F3B20: 0280000e                 be      locret_F00F3B58
F00F3B24: 113c04bc                 sethi   %hi(unk_F012F150), %o0
F00F3B28: 96122150                 or      %o0, %lo(unk_F012F150), %o3
F00F3B2C: d0024000                 ld      [%o1], %o0
F00F3B30: 80a2000b                 cmp     %o0, %o3
F00F3B34: 32800005                 bne,a   loc_F00F3B48
F00F3B38: 92022018                 add     %o0, 0x18, %o1
F00F3B3C: d022a018                 st      %o0, [%o2+0x18]
F00F3B40: 10800006                 ba      locret_F00F3B58
F00F3B44: d4224000                 st      %o2, [%o1]
F00F3B48: d0022018                 ld      [%o0+0x18], %o0
F00F3B4C: 80a22000                 cmp     %o0, 0
F00F3B50: 32bffff8                 bne,a   loc_F00F3B30
F00F3B54: d0024000                 ld      [%o1], %o0
F00F3B58: 81c7e008                 ret
F00F3B5C: 81e80000                 restore
