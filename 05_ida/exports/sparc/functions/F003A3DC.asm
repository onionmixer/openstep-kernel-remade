F003A3DC: 9de3bf98                 save    %sp, -0x68, %sp! int
F003A3E0: d0060000                 ld      [%i0], %o0
F003A3E4: 80a22400                 cmp     %o0, 0x400
F003A3E8: 08800004                 bleu    loc_F003A3F8
F003A3EC: a12a2004                 sll     %o0, 4, %l0
F003A3F0: 10800016                 ba      locret_F003A448
F003A3F4: b0102016                 mov     0x16, %i0
F003A3F8: 80a42000                 cmp     %l0, 0
F003A3FC: 12800005                 bne     loc_F003A410
F003A400: e2062004                 ld      [%i0+4], %l1
F003A404: c0262004                 clr     [%i0+4]
F003A408: 10800010                 ba      locret_F003A448
F003A40C: b0102000                 mov     0, %i0
F003A410: 4000b718                 call    _kalloc
F003A414: 90100010                 mov     %l0, %o0
F003A418: 92100008                 mov     %o0, %o1! int
F003A41C: d2262004                 st      %o1, [%i0+4]
F003A420: 90100011                 mov     %l1, %o0! int
F003A424: 4001770d                 call    _copyin
F003A428: 94100010                 mov     %l0, %o2
F003A42C: a2920000                 orcc    %o0, %g0, %l1
F003A430: 22800006                 be,a    locret_F003A448
F003A434: b0100011                 mov     %l1, %i0
F003A438: d0062004                 ld      [%i0+4], %o0
F003A43C: 4000b759                 call    _kfree
F003A440: 92100010                 mov     %l0, %o1
F003A444: b0100011                 mov     %l1, %i0
F003A448: 81c7e008                 ret
F003A44C: 81e80000                 restore
