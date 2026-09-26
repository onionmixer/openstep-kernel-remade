F00EF188: 80a22000                 cmp     %o0, 0
F00EF18C: 22800005                 be,a    loc_F00EF1A0
F00EF190: 113c03f4                 sethi   -0xFF03000, %o0
F00EF194: c4020000                 ld      [%o0], %g2
F00EF198: 10800003                 ba      locret_F00EF1A4
F00EF19C: d000a008                 ld      [%g2+8], %o0
F00EF1A0: 901220b8                 bset    0xB8, %o0
F00EF1A4: 81c3e008                 retl
F00EF1A8: 01000000                 nop
