F0048474: 9de3bf98                 save    %sp, -0x68, %sp
F0048478: d0062030                 ld      [%i0+0x30], %o0
F004847C: d0022038                 ld      [%o0+0x38], %o0
F0048480: 80a22000                 cmp     %o0, 0
F0048484: 12800004                 bne     loc_F0048494
F0048488: 92100019                 mov     %i1, %o1
F004848C: 10800007                 ba      locret_F00484A8
F0048490: b0102000                 mov     0, %i0
F0048494: d402201c                 ld      [%o0+0x1C], %o2
F0048498: d602a01c                 ld      [%o2+0x1C], %o3
F004849C: 9fc2c000                 call    %o3
F00484A0: 9410001a                 mov     %i2, %o2
F00484A4: b0100008                 mov     %o0, %i0
F00484A8: 81c7e008                 ret
F00484AC: 81e80000                 restore
