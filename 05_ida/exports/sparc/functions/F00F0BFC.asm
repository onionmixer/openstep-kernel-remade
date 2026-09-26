F00F0BFC: 9de3bf98                 save    %sp, -0x68, %sp
F00F0C00: d006200c                 ld      [%i0+0xC], %o0! name
F00F0C04: 80a22000                 cmp     %o0, 0
F00F0C08: 0280000c                 be      locret_F00F0C38
F00F0C0C: 233c0506                 sethi   %hi(paFinishloading), %l1
F00F0C10: 7ffffc5f                 call    _class_lookupMethodInMethodList
F00F0C14: d2046204                 ld      [%l1+%lo(paFinishloading)], %o1
F00F0C18: a0100008                 mov     %o0, %l0
F00F0C1C: 4000043a                 call    _objc_getClass
F00F0C20: d0062004                 ld      [%i0+4], %o0
F00F0C24: 80a42000                 cmp     %l0, 0
F00F0C28: 02800004                 be      locret_F00F0C38
F00F0C2C: d2046204                 ld      [%l1+%lo(paFinishloading)], %o1
F00F0C30: 9fc40000                 call    %l0
F00F0C34: 94100019                 mov     %i1, %o2
F00F0C38: 81c7e008                 ret
F00F0C3C: 81e80000                 restore
