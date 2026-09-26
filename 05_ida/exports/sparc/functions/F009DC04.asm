F009DC04: 9de3bf98                 save    %sp, -0x68, %sp
F009DC08: d2060000                 ld      [%i0], %o1
F009DC0C: 94102000                 mov     0, %o2
F009DC10: 113c045f                 sethi   -0xFEE8400, %o0
F009DC14: 96102000                 mov     0, %o3
F009DC18: d802c009                 ld      [%o3+%o1], %o4
F009DC1C: 80a32000                 cmp     %o4, 0
F009DC20: 22800007                 be,a    loc_F009DC3C
F009DC24: 9402a001                 inc     %o2
F009DC28: 90122210                 bset    0x210, %o0! char *
F009DC2C: 7ffdda8b                 call    _printf
F009DC30: 9610000c                 mov     %o4, %o3
F009DC34: 10800006                 ba      locret_F009DC4C
F009DC38: b0102001                 mov     1, %i0
F009DC3C: 80a2a03f                 cmp     %o2, 0x3F ! '?'
F009DC40: 08bffff6                 bleu    loc_F009DC18
F009DC44: 9602e004                 inc     4, %o3
F009DC48: b0102000                 mov     0, %i0
F009DC4C: 81c7e008                 ret
F009DC50: 81e80000                 restore
