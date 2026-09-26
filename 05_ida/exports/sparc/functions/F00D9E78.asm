F00D9E78: 9de3bf90                 save    %sp, -0x70, %sp
F00D9E7C: a0102000                 mov     0, %l0
F00D9E80: 233c04bb                 sethi   %hi(dword_F012EF2C), %l1
F00D9E84: 293c0504                 sethi   -0xFEBF000, %l4
F00D9E88: 273c0504                 sethi   -0xFEBF000, %l3
F00D9E8C: 253c0505                 sethi   -0xFEBEC00, %l2
F00D9E90: d004632c                 ld      [%l1+%lo(dword_F012EF2C)], %o0! id
F00D9E94: 40005e77                 call    _objc_msgSend
F00D9E98: d20520b8                 ld      [%l4+0xB8], %o1
F00D9E9C: 80a40008                 cmp     %l0, %o0
F00D9EA0: 1a80000d                 bcc     loc_F00D9ED4
F00D9EA4: d004632c                 ld      [%l1+0x32C], %o0! id
F00D9EA8: d204e0c8                 ld      [%l3+0xC8], %o1! SEL
F00D9EAC: 40005e71                 call    _objc_msgSend
F00D9EB0: 94100010                 mov     %l0, %o2
F00D9EB4: b0100008                 mov     %o0, %i0
F00D9EB8: 40005e6e                 call    _objc_msgSend
F00D9EBC: d204a0b4                 ld      [%l2+0xB4], %o1
F00D9EC0: 80a2001a                 cmp     %o0, %i2
F00D9EC4: 02800005                 be      locret_F00D9ED8
F00D9EC8: a0042001                 inc     %l0
F00D9ECC: 10bffff2                 ba      loc_F00D9E94
F00D9ED0: d004632c                 ld      [%l1+0x32C], %o0
F00D9ED4: b0102000                 mov     0, %i0
F00D9ED8: 81c7e008                 ret
F00D9EDC: 81e80000                 restore
