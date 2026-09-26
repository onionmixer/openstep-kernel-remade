F00D7598: 9de3bf90                 save    %sp, -0x70, %sp
F00D759C: a0102000                 mov     0, %l0
F00D75A0: 233c04bb                 sethi   %hi(dword_F012EF0C), %l1
F00D75A4: 293c0504                 sethi   -0xFEBF000, %l4
F00D75A8: 273c0504                 sethi   -0xFEBF000, %l3
F00D75AC: 253c0505                 sethi   -0xFEBEC00, %l2
F00D75B0: d004630c                 ld      [%l1+%lo(dword_F012EF0C)], %o0! id
F00D75B4: 400068af                 call    _objc_msgSend
F00D75B8: d20520b8                 ld      [%l4+0xB8], %o1
F00D75BC: 80a40008                 cmp     %l0, %o0
F00D75C0: 1a80000d                 bcc     loc_F00D75F4
F00D75C4: d004630c                 ld      [%l1+0x30C], %o0! id
F00D75C8: d204e0c8                 ld      [%l3+0xC8], %o1! SEL
F00D75CC: 400068a9                 call    _objc_msgSend
F00D75D0: 94100010                 mov     %l0, %o2
F00D75D4: b0100008                 mov     %o0, %i0
F00D75D8: 400068a6                 call    _objc_msgSend
F00D75DC: d204a22c                 ld      [%l2+0x22C], %o1
F00D75E0: 80a2001a                 cmp     %o0, %i2
F00D75E4: 02800005                 be      locret_F00D75F8
F00D75E8: a0042001                 inc     %l0
F00D75EC: 10bffff2                 ba      loc_F00D75B4
F00D75F0: d004630c                 ld      [%l1+0x30C], %o0
F00D75F4: b0102000                 mov     0, %i0
F00D75F8: 81c7e008                 ret
F00D75FC: 81e80000                 restore
