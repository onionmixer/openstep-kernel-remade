F0095AF0: 90102300                 mov     0x300, %o0
F0095AF4: 9b480000                 rdhpr   %hpstate, %o5
F0095AF8: 982b6020                 andn    %o5, 0x20, %o4
F0095AFC: 818b0000                 saved
F0095B00: 01000000                 nop
F0095B04: 01000000                 nop
F0095B08: 98102100                 mov     0x100, %o4
F0095B0C: d8830080                 lda     [%o4]#ASI_NUCLEUS, %o4
F0095B10: 952a6002                 sll     %o1, 2, %o2
F0095B14: 992b2004                 sll     %o4, 4, %o4
F0095B18: 9803000a                 add     %o4, %o2, %o4
F0095B1C: d8830400                 lda     [%o4]0x20, %o4
F0095B20: 980b2003                 and     %o4, 3, %o4
F0095B24: 80a32001                 cmp     %o4, 1
F0095B28: 98102200                 mov     0x200, %o4
F0095B2C: 12800003                 bne     loc_F0095B38
F0095B30: d4830080                 lda     [%o4]#ASI_NUCLEUS, %o2
F0095B34: d2a30080                 sta     %o1, [%o4]#ASI_NUCLEUS
F0095B38: c0a20060                 sta     %g0, [%o0]3
F0095B3C: d4a30080                 sta     %o2, [%o4]#ASI_NUCLEUS
F0095B40: 818b4000                 saved
F0095B44: 01000000                 nop
F0095B48: 81c3e008                 retl
F0095B4C: 01000000                 nop
