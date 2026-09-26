F00F0C7C: 9de3bf98                 save    %sp, -0x68, %sp
F00F0C80: d006200c                 ld      [%i0+0xC], %o0! name
F00F0C84: 80a22000                 cmp     %o0, 0
F00F0C88: 0280000c                 be      locret_F00F0CB8
F00F0C8C: 233c0506                 sethi   %hi(paStartunloading), %l1
F00F0C90: 7ffffc3f                 call    _class_lookupMethodInMethodList
F00F0C94: d2046200                 ld      [%l1+%lo(paStartunloading)], %o1
F00F0C98: a0100008                 mov     %o0, %l0
F00F0C9C: 4000041a                 call    _objc_getClass
F00F0CA0: d0062004                 ld      [%i0+4], %o0
F00F0CA4: 80a42000                 cmp     %l0, 0
F00F0CA8: 02800004                 be      locret_F00F0CB8
F00F0CAC: 01000000                 nop
F00F0CB0: 9fc40000                 call    %l0
F00F0CB4: d2046200                 ld      [%l1+%lo(paStartunloading)], %o1
F00F0CB8: 81c7e008                 ret
F00F0CBC: 81e80000                 restore
