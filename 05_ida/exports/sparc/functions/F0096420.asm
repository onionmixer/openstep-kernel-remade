F0096420: 90102300                 mov     0x300, %o0
F0096424: 9b480000                 rdhpr   %hpstate, %o5
F0096428: 982b6020                 andn    %o5, 0x20, %o4
F009642C: 818b0000                 saved
F0096430: 01000000                 nop
F0096434: 01000000                 nop
F0096438: 98102100                 mov     0x100, %o4
F009643C: d8830080                 lda     [%o4]#ASI_NUCLEUS, %o4
F0096440: 952a6002                 sll     %o1, 2, %o2
F0096444: 992b2004                 sll     %o4, 4, %o4
F0096448: 9803000a                 add     %o4, %o2, %o4
F009644C: 15000020                 sethi   0x8000, %o2
F0096450: d6800080                 lda     [%g0]#ASI_NUCLEUS, %o3
F0096454: 9412c00a                 bset    %o3, %o2
F0096458: d4a00080                 sta     %o2, [%g0]#ASI_NUCLEUS
F009645C: d8830400                 lda     [%o4]0x20, %o4
F0096460: d6a00080                 sta     %o3, [%g0]#ASI_NUCLEUS
F0096464: 980b2003                 and     %o4, 3, %o4
F0096468: 80a32001                 cmp     %o4, 1
F009646C: 98102200                 mov     0x200, %o4
F0096470: 12800003                 bne     loc_F009647C
F0096474: d4830080                 lda     [%o4]#ASI_NUCLEUS, %o2
F0096478: d2a30080                 sta     %o1, [%o4]#ASI_NUCLEUS
F009647C: c0a20060                 sta     %g0, [%o0]3
F0096480: d4a30080                 sta     %o2, [%o4]#ASI_NUCLEUS
F0096484: 818b4000                 saved
F0096488: 01000000                 nop
F009648C: 81c3e008                 retl
F0096490: 01000000                 nop
