F0065300: 9de3bf98                 save    %sp, -0x68, %sp
F0065304: 80a62000                 cmp     %i0, 0
F0065308: 02800018                 be      locret_F0065368
F006530C: a0102000                 mov     0, %l0
F0065310: 80a63fff                 cmp     %i0, -1
F0065314: 02800015                 be      locret_F0065368
F0065318: 01000000                 nop
F006531C: d0060000                 ld      [%i0], %o0
F0065320: 80a22000                 cmp     %o0, 0
F0065324: 12bffffe                 bne     loc_F006531C
F0065328: 01000000                 nop
F006532C: 4000c6df                 call    _simple_lock_try
F0065330: 90100018                 mov     %i0, %o0
F0065334: 80a22000                 cmp     %o0, 0
F0065338: 02bffff9                 be      loc_F006531C
F006533C: 01000000                 nop
F0065340: d2062008                 ld      [%i0+8], %o1
F0065344: 80a26000                 cmp     %o1, 0
F0065348: 16800007                 bge     loc_F0065364
F006534C: 1100003f                 sethi   0xFC00, %o0
F0065350: 901223ff                 bset    0x3FF, %o0
F0065354: 900a4008                 and     %o1, %o0, %o0
F0065358: 80a22004                 cmp     %o0, 4
F006535C: 22800002                 be,a    loc_F0065364
F0065360: e0062014                 ld      [%i0+0x14], %l0
F0065364: c0260000                 clr     [%i0]
F0065368: 81c7e008                 ret
F006536C: 91e80010                 restore %g0, %l0, %o0
