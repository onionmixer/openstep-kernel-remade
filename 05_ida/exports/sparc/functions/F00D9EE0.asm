F00D9EE0: 9de3bf90                 save    %sp, -0x70, %sp
F00D9EE4: a0102000                 mov     0, %l0
F00D9EE8: 233c04bb                 sethi   %hi(dword_F012EF2C), %l1
F00D9EEC: 293c0504                 sethi   -0xFEBF000, %l4
F00D9EF0: 273c0504                 sethi   -0xFEBF000, %l3
F00D9EF4: 253c0505                 sethi   -0xFEBEC00, %l2
F00D9EF8: d004632c                 ld      [%l1+%lo(dword_F012EF2C)], %o0! id
F00D9EFC: 40005e5d                 call    _objc_msgSend
F00D9F00: d20520b8                 ld      [%l4+0xB8], %o1
F00D9F04: 80a40008                 cmp     %l0, %o0
F00D9F08: 1a80000d                 bcc     loc_F00D9F3C
F00D9F0C: d004632c                 ld      [%l1+0x32C], %o0! id
F00D9F10: d204e0c8                 ld      [%l3+0xC8], %o1! SEL
F00D9F14: 40005e57                 call    _objc_msgSend
F00D9F18: 94100010                 mov     %l0, %o2
F00D9F1C: b0100008                 mov     %o0, %i0
F00D9F20: 40005e54                 call    _objc_msgSend
F00D9F24: d204a0b0                 ld      [%l2+0xB0], %o1
F00D9F28: 80a2001a                 cmp     %o0, %i2
F00D9F2C: 02800005                 be      locret_F00D9F40
F00D9F30: a0042001                 inc     %l0
F00D9F34: 10bffff2                 ba      loc_F00D9EFC
F00D9F38: d004632c                 ld      [%l1+0x32C], %o0
F00D9F3C: b0102000                 mov     0, %i0
F00D9F40: 81c7e008                 ret
F00D9F44: 81e80000                 restore
