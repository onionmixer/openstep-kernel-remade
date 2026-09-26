F009748C: 15000004                 sethi   0x1000, %o2
F0097490: 90102000                 mov     0, %o0
F0097494: d2820080                 lda     [%o0]#ASI_NUCLEUS, %o1
F0097498: 922a400a                 bclr    %o2, %o1
F009749C: 81c3e008                 retl
F00974A0: d2a20080                 sta     %o1, [%o0]#ASI_NUCLEUS
