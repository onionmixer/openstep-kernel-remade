F00964B4: 90122000                 bset    0, %o0
F00964B8: 9b480000                 rdhpr   %hpstate, %o5
F00964BC: 982b6020                 andn    %o5, 0x20, %o4
F00964C0: 818b0000                 saved
F00964C4: 01000000                 nop
F00964C8: 01000000                 nop
F00964CC: 98102100                 mov     0x100, %o4
F00964D0: d8830080                 lda     [%o4]#ASI_NUCLEUS, %o4
F00964D4: 952a6002                 sll     %o1, 2, %o2
F00964D8: 992b2004                 sll     %o4, 4, %o4
F00964DC: 9803000a                 add     %o4, %o2, %o4
F00964E0: 15000020                 sethi   0x8000, %o2
F00964E4: d6800080                 lda     [%g0]#ASI_NUCLEUS, %o3
F00964E8: 9412c00a                 bset    %o3, %o2
F00964EC: d4a00080                 sta     %o2, [%g0]#ASI_NUCLEUS
F00964F0: d8830400                 lda     [%o4]0x20, %o4
F00964F4: d6a00080                 sta     %o3, [%g0]#ASI_NUCLEUS
F00964F8: 980b2003                 and     %o4, 3, %o4
F00964FC: 80a32001                 cmp     %o4, 1
F0096500: 98102200                 mov     0x200, %o4
F0096504: 12800003                 bne     loc_F0096510
F0096508: d4830080                 lda     [%o4]#ASI_NUCLEUS, %o2
F009650C: d2a30080                 sta     %o1, [%o4]#ASI_NUCLEUS
F0096510: c0a20060                 sta     %g0, [%o0]3
F0096514: d4a30080                 sta     %o2, [%o4]#ASI_NUCLEUS
F0096518: 818b4000                 saved
F009651C: 01000000                 nop
F0096520: 81c3e008                 retl
F0096524: 01000000                 nop
