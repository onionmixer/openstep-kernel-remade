F00EF430: 9de3bf98                 save    %sp, -0x68, %sp
F00EF434: 90960000                 orcc    %i0, %g0, %o0
F00EF438: 02800009                 be      loc_F00EF45C
F00EF43C: 92100019                 mov     %i1, %o1
F00EF440: 80a26000                 cmp     %o1, 0
F00EF444: 02800007                 be      locret_F00EF460
F00EF448: b0102000                 mov     0, %i0
F00EF44C: 7fffffdb                 call    sub_F00EF3B8
F00EF450: 01000000                 nop
F00EF454: 10800003                 ba      locret_F00EF460
F00EF458: b0100008                 mov     %o0, %i0
F00EF45C: b0102000                 mov     0, %i0
F00EF460: 81c7e008                 ret
F00EF464: 81e80000                 restore
