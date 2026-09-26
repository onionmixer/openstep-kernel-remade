F00F0BBC: 9de3bf98                 save    %sp, -0x68, %sp
F00F0BC0: 7ffffff4                 call    sub_F00F0B90
F00F0BC4: d0060000                 ld      [%i0], %o0
F00F0BC8: 80a22000                 cmp     %o0, 0
F00F0BCC: 0280000a                 be      locret_F00F0BF4
F00F0BD0: 213c0506                 sethi   %hi(paFinishloading), %l0
F00F0BD4: 7ffffc6e                 call    _class_lookupMethodInMethodList
F00F0BD8: d2042204                 ld      [%l0+%lo(paFinishloading)], %o1
F00F0BDC: 96920000                 orcc    %o0, %g0, %o3
F00F0BE0: 02800005                 be      locret_F00F0BF4
F00F0BE4: 90100018                 mov     %i0, %o0
F00F0BE8: d2042204                 ld      [%l0+%lo(paFinishloading)], %o1
F00F0BEC: 9fc2c000                 call    %o3
F00F0BF0: 94100019                 mov     %i1, %o2
F00F0BF4: 81c7e008                 ret
F00F0BF8: 81e80000                 restore
