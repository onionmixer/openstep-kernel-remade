F00ECE00: 9de3bf98                 save    %sp, -0x68, %sp
F00ECE04: 113c04bb                 sethi   %hi(off_F012EF84), %o0
F00ECE08: d6022384                 ld      [%o0+%lo(off_F012EF84)], %o3
F00ECE0C: 90100018                 mov     %i0, %o0
F00ECE10: 92100019                 mov     %i1, %o1
F00ECE14: 9fc2c000                 call    %o3
F00ECE18: 9410001a                 mov     %i2, %o2
F00ECE1C: 7ffe7d55                 call    _abort
