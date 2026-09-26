F0097474: 15000004                 sethi   0x1000, %o2
F0097478: 90102000                 mov     0, %o0
F009747C: d2820080                 lda     [%o0]#ASI_NUCLEUS, %o1
F0097480: 9212400a                 bset    %o2, %o1
F0097484: 81c3e008                 retl
F0097488: d2a20080                 sta     %o1, [%o0]#ASI_NUCLEUS
