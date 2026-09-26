F00F0C40: 9de3bf98                 save    %sp, -0x68, %sp
F00F0C44: 7fffffd3                 call    sub_F00F0B90
F00F0C48: d0060000                 ld      [%i0], %o0
F00F0C4C: 80a22000                 cmp     %o0, 0
F00F0C50: 02800009                 be      locret_F00F0C74
F00F0C54: 213c0506                 sethi   %hi(paStartunloading), %l0
F00F0C58: 7ffffc4d                 call    _class_lookupMethodInMethodList
F00F0C5C: d2042200                 ld      [%l0+%lo(paStartunloading)], %o1
F00F0C60: 94920000                 orcc    %o0, %g0, %o2
F00F0C64: 02800004                 be      locret_F00F0C74
F00F0C68: 90100018                 mov     %i0, %o0
F00F0C6C: 9fc28000                 call    %o2
F00F0C70: d2042200                 ld      [%l0+%lo(paStartunloading)], %o1
F00F0C74: 81c7e008                 ret
F00F0C78: 81e80000                 restore
