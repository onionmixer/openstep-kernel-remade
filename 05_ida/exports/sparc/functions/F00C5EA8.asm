F00C5EA8: 9de3bf90                 save    %sp, -0x70, %sp
F00C5EAC: 113c0506                 sethi   %hi(paIoconfigtable), %o0
F00C5EB0: d0022298                 ld      [%o0+%lo(paIoconfigtable)], %o0! id
F00C5EB4: 133c0504                 sethi   %hi(paFreestring), %o1
F00C5EB8: d20260f4                 ld      [%o1+%lo(paFreestring)], %o1! SEL
F00C5EBC: 4000ae6d                 call    _objc_msgSend
F00C5EC0: 9410001a                 mov     %i2, %o2
F00C5EC4: 81c7e008                 ret
F00C5EC8: 81e80000                 restore
