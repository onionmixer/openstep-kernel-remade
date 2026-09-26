F00273E0: 9de3bf98                 save    %sp, -0x68, %sp
F00273E4: a2100018                 mov     %i0, %l1
F00273E8: 7fff8014                 call    _strlen
F00273EC: 90100019                 mov     %i1, %o0
F00273F0: d4046008                 ld      [%l1+8], %o2! size_t
F00273F4: a0100008                 mov     %o0, %l0
F00273F8: 90028010                 add     %o2, %l0, %o0
F00273FC: 80a223ff                 cmp     %o0, 0x3FF
F0027400: 1880000b                 bgu     loc_F002742C
F0027404: 90100019                 mov     %i1, %o0! void *
F0027408: d2046004                 ld      [%l1+4], %o1
F002740C: 9202400a                 add     %o1, %o2, %o1! void *
F0027410: 4001b5c0                 call    _bcopy
F0027414: 94042001                 add     %l0, 1, %o2
F0027418: d0046008                 ld      [%l1+8], %o0
F002741C: b0102000                 mov     0, %i0
F0027420: 90020010                 add     %o0, %l0, %o0
F0027424: 10800003                 ba      locret_F0027430
F0027428: d0246008                 st      %o0, [%l1+8]
F002742C: b010203f                 mov     0x3F, %i0 ! '?'
F0027430: 81c7e008                 ret
F0027434: 81e80000                 restore
