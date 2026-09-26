F00C61FC: 9de3bf98                 save    %sp, -0x68, %sp
F00C6200: 84102001                 mov     1, %g2
F00C6204: 07200000                 sethi   0x80000000, %g3
F00C6208: b2102020                 mov     0x20, %i1 ! ' '
F00C620C: 808e0003                 btst    %g3, %i0
F00C6210: 22800004                 be,a    loc_F00C6220
F00C6214: 8400a001                 inc     %g2
F00C6218: 10800006                 ba      locret_F00C6230
F00C621C: b0264002                 sub     %i1, %g2, %i0
F00C6220: 80a0a01f                 cmp     %g2, 0x1F
F00C6224: 04bffffa                 ble     loc_F00C620C
F00C6228: b12e2001                 sll     %i0, 1, %i0
F00C622C: b0102000                 mov     0, %i0
F00C6230: 81c7e008                 ret
F00C6234: 81e80000                 restore
