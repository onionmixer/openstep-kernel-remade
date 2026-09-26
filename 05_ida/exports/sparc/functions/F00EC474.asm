F00EC474: 9de3bf98                 save    %sp, -0x68, %sp
F00EC478: a0100018                 mov     %i0, %l0
F00EC47C: 92100019                 mov     %i1, %o1! name
F00EC480: 80a42000                 cmp     %l0, 0
F00EC484: 0280000c                 be      locret_F00EC4B4
F00EC488: b0102000                 mov     0, %i0
F00EC48C: 80a26000                 cmp     %o1, 0
F00EC490: 02800009                 be      locret_F00EC4B4
F00EC494: 01000000                 nop
F00EC498: 40000be6                 call    _class_getInstanceVariable
F00EC49C: d0040000                 ld      [%l0], %o0
F00EC4A0: b0920000                 orcc    %o0, %g0, %i0
F00EC4A4: 02800004                 be      locret_F00EC4B4
F00EC4A8: 01000000                 nop
F00EC4AC: d0062008                 ld      [%i0+8], %o0
F00EC4B0: f4240008                 st      %i2, [%l0+%o0]
F00EC4B4: 81c7e008                 ret
F00EC4B8: 81e80000                 restore
