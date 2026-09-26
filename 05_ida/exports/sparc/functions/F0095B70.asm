F0095B70: 90122000                 bset    0, %o0
F0095B74: 9b480000                 rdhpr   %hpstate, %o5
F0095B78: 982b6020                 andn    %o5, 0x20, %o4
F0095B7C: 818b0000                 saved
F0095B80: 01000000                 nop
F0095B84: 01000000                 nop
F0095B88: 98102100                 mov     0x100, %o4
F0095B8C: d8830080                 lda     [%o4]#ASI_NUCLEUS, %o4
F0095B90: 952a6002                 sll     %o1, 2, %o2
F0095B94: 992b2004                 sll     %o4, 4, %o4
F0095B98: 9803000a                 add     %o4, %o2, %o4
F0095B9C: d8830400                 lda     [%o4]0x20, %o4
F0095BA0: 980b2003                 and     %o4, 3, %o4
F0095BA4: 80a32001                 cmp     %o4, 1
F0095BA8: 98102200                 mov     0x200, %o4
F0095BAC: 12800003                 bne     loc_F0095BB8
F0095BB0: d4830080                 lda     [%o4]#ASI_NUCLEUS, %o2
F0095BB4: d2a30080                 sta     %o1, [%o4]#ASI_NUCLEUS
F0095BB8: c0a20060                 sta     %g0, [%o0]3
F0095BBC: d4a30080                 sta     %o2, [%o4]#ASI_NUCLEUS
F0095BC0: 818b4000                 saved
F0095BC4: 01000000                 nop
F0095BC8: 81c3e008                 retl
F0095BCC: 01000000                 nop
