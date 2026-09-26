F00CA614: 9de3bf90                 save    %sp, -0x70, %sp
F00CA618: 9410001a                 mov     %i2, %o2
F00CA61C: 80a2bcdf                 cmp     %o2, -0x321
F00CA620: 02800006                 be      loc_F00CA638
F00CA624: 80a2bce0                 cmp     %o2, -0x320
F00CA628: 12800006                 bne     loc_F00CA640
F00CA62C: 113c0508                 sethi   -0xFEBE000, %o0! objc_super *
F00CA630: 1080000c                 ba      locret_F00CA660
F00CA634: b010203a                 mov     0x3A, %i0 ! ':'
F00CA638: 1080000a                 ba      locret_F00CA660
F00CA63C: b0102001                 mov     1, %i0
F00CA640: d2022028                 ld      [%o0+0x28], %o1
F00CA644: f027bff0                 st      %i0, [%fp+var_10]
F00CA648: d227bff4                 st      %o1, [%fp+var_C]
F00CA64C: 133c0504                 sethi   %hi(paErrnofromretur), %o1
F00CA650: d2026194                 ld      [%o1+%lo(paErrnofromretur)], %o1! SEL
F00CA654: 40009cca                 call    _objc_msgSendSuper
F00CA658: 9007bff0                 add     %fp, var_10, %o0
F00CA65C: b0100008                 mov     %o0, %i0
F00CA660: 81c7e008                 ret
F00CA664: 81e80000                 restore
