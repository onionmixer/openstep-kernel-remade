F00971D4: 1138000492022004         set     -0x1FFFEFFC, %o1
F00971DC: c08205e0                 lda     [%o0]0x2F, %g0
F00971E0: c08245e0                 lda     [%o1]0x2F, %g0
F00971E4: c0a205e0                 sta     %g0, [%o0]0x2F
F00971E8: 90102008                 mov     8, %o0
F00971EC: c08205e0                 lda     [%o0]0x2F, %g0
F00971F0: c0a205e0                 sta     %g0, [%o0]0x2F
F00971F4: 90102000                 mov     0, %o0
F00971F8: d28205e0                 lda     [%o0]0x2F, %o1
F00971FC: 92126001                 bset    1, %o1
F0097200: 92126002                 bset    2, %o1
F0097204: d2a205e0                 sta     %o1, [%o0]0x2F
F0097208: 1138000490122008         set     -0x1FFFEFF8, %o0
F0097210: d28205e0                 lda     [%o0]0x2F, %o1
F0097214: 03200400                 sethi   -0x7FF00000, %g1
F0097218: 92124001                 bset    %g1, %o1
F009721C: d2a205e0                 sta     %o1, [%o0]0x2F
F0097220: 81c3e008                 retl
F0097224: 01000000                 nop
