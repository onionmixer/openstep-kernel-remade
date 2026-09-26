F00F197C: 9de3bf88                 save    %sp, -0x78, %sp
F00F1980: e0062000                 ld      [%i0], %l0
F00F1984: 80940000                 tst     %l0
F00F1988: 1280000b                 bne     loc_F00F19B4
F00F198C: e027a044                 st      %l0, [%fp+arg_44]
F00F1990: c607e008                 ld      [%i7+8], %g3
F00F1994: 053ff000                 sethi   -0x400000, %g2
F00F1998: 8088c002                 btst    %g2, %g3
F00F199C: 02800004                 be      loc_F00F19AC
F00F19A0: 01000000                 nop
F00F19A4: 81c7e008                 ret
F00F19A8: 81e80000                 restore
F00F19AC: 81c7e00c                 jmp     %i7+0xC
F00F19B0: 81e80000                 restore
F00F19B4: 233c04bc                 sethi   %hi(__objc_multithread_mask), %l1
F00F19B8: e2046130                 ld      [%l1+%lo(__objc_multithread_mask)], %l1
F00F19BC: 80944000                 tst     %l1
F00F19C0: 0280001b                 be      loc_F00F1A2C
F00F19C4: d0062004                 ld      [%i0+4], %o0
F00F19C8: e8022020                 ld      [%o0+0x20], %l4
F00F19CC: e6052000                 ld      [%l4], %l3
F00F19D0: a4052008                 add     %l4, 8, %l2
F00F19D4: a20e4013                 and     %i1, %l3, %l1
F00F19D8: ad2c6002                 sll     %l1, 2, %l6
F00F19DC: e8048016                 ld      [%l2+%l6], %l4
F00F19E0: 80950000                 tst     %l4
F00F19E4: 22800009                 be,a    loc_F00F1A08
F00F19E8: 92100019                 mov     %i1, %o1
F00F19EC: ea052000                 ld      [%l4], %l5
F00F19F0: 80a54019                 cmp     %l5, %i1
F00F19F4: 0280000b                 be      loc_F00F1A20
F00F19F8: c2052008                 ld      [%l4+8], %g1
F00F19FC: a2046001                 inc     %l1
F00F1A00: 10bffff6                 ba      loc_F00F19D8
F00F1A04: a20c4013                 and     %l1, %l3, %l1
F00F1A08: 7ffffa0f                 call    __class_lookupMethodAndLoadCache
F00F1A0C: 01000000                 nop
F00F1A10: 82100008                 mov     %o0, %g1
F00F1A14: 81e80000                 restore
F00F1A18: 81c04000                 jmp     %g1
F00F1A1C: d003a044                 ld      [%sp+0x78+var_34], %o0
F00F1A20: 81e80000                 restore
F00F1A24: 81c04000                 jmp     %g1
F00F1A28: d003a044                 ld      [%sp+0x78+var_34], %o0
F00F1A2C: 233c04bcae1460d8         set     _messageLock, %l7
F00F1A34: e26dc000                 ldstub  [%l7], %l1
F00F1A38: 80944000                 tst     %l1
F00F1A3C: 12bffffe                 bne     loc_F00F1A34
F00F1A40: 01000000                 nop
F00F1A44: e8022020                 ld      [%o0+0x20], %l4
F00F1A48: e6052000                 ld      [%l4], %l3
F00F1A4C: a4052008                 add     %l4, 8, %l2
F00F1A50: a20e4013                 and     %i1, %l3, %l1
F00F1A54: ad2c6002                 sll     %l1, 2, %l6
F00F1A58: e8048016                 ld      [%l2+%l6], %l4
F00F1A5C: 80950000                 tst     %l4
F00F1A60: 22800009                 be,a    loc_F00F1A84
F00F1A64: 92100019                 mov     %i1, %o1
F00F1A68: ea052000                 ld      [%l4], %l5
F00F1A6C: 80a54019                 cmp     %l5, %i1
F00F1A70: 0280000c                 be      loc_F00F1AA0
F00F1A74: c2052008                 ld      [%l4+8], %g1
F00F1A78: a2046001                 inc     %l1
F00F1A7C: 10bffff6                 ba      loc_F00F1A54
F00F1A80: a20c4013                 and     %l1, %l3, %l1
F00F1A84: 7ffff9f0                 call    __class_lookupMethodAndLoadCache
F00F1A88: 01000000                 nop
F00F1A8C: 82100008                 mov     %o0, %g1
F00F1A90: c025c000                 clr     [%l7]
F00F1A94: 81e80000                 restore
F00F1A98: 81c04000                 jmp     %g1
F00F1A9C: d003a044                 ld      [%sp+0x78+var_34], %o0
F00F1AA0: c025c000                 clr     [%l7]
F00F1AA4: 81e80000                 restore
F00F1AA8: 81c04000                 jmp     %g1
F00F1AAC: d003a044                 ld      [%sp+0x78+var_34], %o0
