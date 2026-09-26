F00D9E54: 9de3bf90                 save    %sp, -0x70, %sp
F00D9E58: 113c04bb                 sethi   %hi(dword_F012EF2C), %o0
F00D9E5C: d002232c                 ld      [%o0+%lo(dword_F012EF2C)], %o0! id
F00D9E60: 133c0504                 sethi   %hi(paRemoveobject), %o1
F00D9E64: d20260ac                 ld      [%o1+%lo(paRemoveobject)], %o1! SEL
F00D9E68: 40005e82                 call    _objc_msgSend
F00D9E6C: 9410001a                 mov     %i2, %o2
F00D9E70: 81c7e008                 ret
F00D9E74: 81e80000                 restore
