F00EC4BC: 9de3bf98                 save    %sp, -0x68, %sp
F00EC4C0: a0100018                 mov     %i0, %l0
F00EC4C4: 92100019                 mov     %i1, %o1! name
F00EC4C8: 80a42000                 cmp     %l0, 0
F00EC4CC: 0280000d                 be      locret_F00EC500
F00EC4D0: b0102000                 mov     0, %i0
F00EC4D4: 80a26000                 cmp     %o1, 0
F00EC4D8: 0280000a                 be      locret_F00EC500
F00EC4DC: 01000000                 nop
F00EC4E0: 40000bd4                 call    _class_getInstanceVariable
F00EC4E4: d0040000                 ld      [%l0], %o0
F00EC4E8: b0920000                 orcc    %o0, %g0, %i0
F00EC4EC: 22800005                 be,a    locret_F00EC500
F00EC4F0: c0268000                 clr     [%i2]
F00EC4F4: d0062008                 ld      [%i0+8], %o0
F00EC4F8: d0040008                 ld      [%l0+%o0], %o0
F00EC4FC: d0268000                 st      %o0, [%i2]
F00EC500: 81c7e008                 ret
F00EC504: 81e80000                 restore
