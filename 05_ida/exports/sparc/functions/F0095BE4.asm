F0095BE4: 92102600                 mov     0x600, %o1
F0095BE8: d2824080                 lda     [%o1]#ASI_NUCLEUS, %o1
F0095BEC: d2222004                 st      %o1, [%o0+4]
F0095BF0: 92102500                 mov     0x500, %o1
F0095BF4: d2824080                 lda     [%o1]#ASI_NUCLEUS, %o1
F0095BF8: d2220000                 st      %o1, [%o0]
F0095BFC: 92103fff                 mov     -1, %o1
F0095C00: 81c3e008                 retl
F0095C04: d2222008                 st      %o1, [%o0+8]
