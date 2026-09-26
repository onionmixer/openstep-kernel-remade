F0075BD8: 9de3bf98                 save    %sp, -0x68, %sp
F0075BDC: 80a62000                 cmp     %i0, 0
F0075BE0: 02800005                 be      loc_F0075BF4
F0075BE4: a2102000                 mov     0, %l1
F0075BE8: 80a6601f                 cmp     %i1, 0x1F
F0075BEC: 08800004                 bleu    loc_F0075BFC
F0075BF0: 01000000                 nop
F0075BF4: 10800023                 ba      locret_F0075C80
F0075BF8: b0102004                 mov     4, %i0
F0075BFC: 400083e3                 call    _splusclock
F0075C00: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0075C04: a4100008                 mov     %o0, %l2
F0075C08: d0040000                 ld      [%l0], %o0
F0075C0C: 80a22000                 cmp     %o0, 0
F0075C10: 12bffffe                 bne     loc_F0075C08
F0075C14: 01000000                 nop
F0075C18: 400084a4                 call    _simple_lock_try
F0075C1C: 90100010                 mov     %l0, %o0
F0075C20: 80a22000                 cmp     %o0, 0
F0075C24: 02bffff9                 be      loc_F0075C08
F0075C28: 01000000                 nop
F0075C2C: d0062054                 ld      [%i0+0x54], %o0
F0075C30: 80a64008                 cmp     %i1, %o0
F0075C34: 24800004                 ble,a   loc_F0075C44
F0075C38: d0062064                 ld      [%i0+0x64], %o0
F0075C3C: 1080000d                 ba      loc_F0075C70
F0075C40: a2102005                 mov     5, %l1
F0075C44: 80a22000                 cmp     %o0, 0
F0075C48: 26800004                 bl,a    loc_F0075C58
F0075C4C: f2262050                 st      %i1, [%i0+0x50]
F0075C50: 10800005                 ba      loc_F0075C64
F0075C54: f2262064                 st      %i1, [%i0+0x64]
F0075C58: 90100018                 mov     %i0, %o0
F0075C5C: 7fffef3a                 call    _compute_priority
F0075C60: 92102001                 mov     1, %o1
F0075C64: 80a6a000                 cmp     %i2, 0
F0075C68: 32800002                 bne,a   loc_F0075C70
F0075C6C: f2262054                 st      %i1, [%i0+0x54]
F0075C70: c0262020                 clr     [%i0+0x20]
F0075C74: 4000842c                 call    _splx
F0075C78: 90100012                 mov     %l2, %o0
F0075C7C: b0100011                 mov     %l1, %i0
F0075C80: 81c7e008                 ret
F0075C84: 81e80000                 restore
