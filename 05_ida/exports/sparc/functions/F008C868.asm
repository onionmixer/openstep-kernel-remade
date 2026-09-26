F008C868: 9de3bf90                 save    %sp, -0x70, %sp
F008C86C: 80a6a000                 cmp     %i2, 0
F008C870: 22800004                 be,a    loc_F008C880
F008C874: f027bff0                 st      %i0, [%fp+var_10]
F008C878: 1080000a                 ba      locret_F008C8A0
F008C87C: f4262008                 st      %i2, [%i0+8]
F008C880: 133c0506                 sethi   %hi(stru_F0141AFC.super_class), %o1
F008C884: d4026300                 ld      [%o1+%lo(stru_F0141AFC.super_class)], %o2
F008C888: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008C88C: 133c0503                 sethi   %hi(paFree), %o1
F008C890: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F008C894: 4001943a                 call    _objc_msgSendSuper
F008C898: d427bff4                 st      %o2, [%fp+var_C]
F008C89C: b0100008                 mov     %o0, %i0
F008C8A0: 81c7e008                 ret
F008C8A4: 81e80000                 restore
